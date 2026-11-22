package capwap

// 0x53/0x54 typed record bodies, wire layouts per the complete restore
// sequences of cw_priv_rssi_statistics_assemble and
// cw_priv_ap_statistics_assemble.

// RssiStatisticsReq is element 0x0053 (min 20 max 0x15f4):
//
//	8B head + 8B head2 + BE32 entry count + count × {6B mac, 8B bssid/ssid}
//
// restore sequence: raw(iVar5) [8B], raw(iVar5+8, 8), BE32(+0x10),
// per-entry raw 6B + raw 8B.
type RssiStatisticsReq struct {
	Head    [8]byte
	Head2   [8]byte
	N       uint32
	Entries []RssiEntry
}

// RssiEntry is one 14-byte rssi statistics entry.
type RssiEntry struct {
	MAC       [6]byte
	BSSIDSSID [8]byte
}

// AssembleValue writes head2... wait — wire order: Head, Head2, count, entries.
func (p RssiStatisticsReq) AssembleValue() []byte {
	b := append([]byte(nil), p.Head[:]...)
	b = append(b, p.Head2[:]...)
	b = AppendUint32BE(b, p.N)
	for i := range p.Entries {
		b = append(b, p.Entries[i].MAC[:]...)
		b = append(b, p.Entries[i].BSSIDSSID[:]...)
	}
	return b
}

// ParseRssiStatisticsReq decodes head + count + entries (14B stride).
func ParseRssiStatisticsReq(v []byte) (*RssiStatisticsReq, error) {
	if len(v) < 20 {
		return nil, ErrShortPacket
	}
	p := &RssiStatisticsReq{N: Uint32BE(v[16:])}
	copy(p.Head[:], v[:8])
	copy(p.Head2[:], v[8:16])
	rest := len(v) - 20
	if p.N > 0 && rest != int(p.N)*14 {
		return nil, ErrShortPacket
	}
	off := 20
	for i := uint32(0); i < p.N; i++ {
		var e RssiEntry
		copy(e.MAC[:], v[off:off+6])
		copy(e.BSSIDSSID[:], v[off+6:off+14])
		p.Entries = append(p.Entries, e)
		off += 14
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return p, nil
}

// ApStatisticsReq is element 0x0054 (min 42 max 0x82a):
//
//	header 42 bytes: u8 radio + u8 + u8 + 8B + u8 + BE16 + BE32×7
//	entries: (len-42)/32 × 32-byte records
//
// Entry wire layout (restore seq from +0x2c base):
//
//	u8, u8, BE16, BE16, BE16, u8×4, BE32×4, u8×4 = 32 bytes.
type ApStatisticsReq struct {
	Radio   uint8
	U8a     uint8
	U8b     uint8
	Raw8    [8]byte
	U8c     uint8
	U16     uint16
	W       [7]uint32
	Entries []ApStatEntry
}

// ApStatEntry is one 32-byte per-channel statistics record.
type ApStatEntry struct {
	U8a  [2]byte
	U16a uint16
	U16b uint16
	U16c uint16
	U8b  [4]byte
	U32  [4]uint32
	U8c  [4]byte
}

// AssembleEntry writes the 32-byte record.
func (e *ApStatEntry) AssembleEntry() []byte {
	b := append([]byte(nil), e.U8a[:]...)
	b = AppendUint16BE(b, e.U16a)
	b = AppendUint16BE(b, e.U16b)
	b = AppendUint16BE(b, e.U16c)
	b = append(b, e.U8b[:]...)
	for _, w := range e.U32 {
		b = AppendUint32BE(b, w)
	}
	b = append(b, e.U8c[:]...)
	return b
}

// ParseApStatEntry decodes one 32-byte record.
func ParseApStatEntry(v []byte) (*ApStatEntry, error) {
	if len(v) != 32 {
		return nil, ErrShortPacket
	}
	e := &ApStatEntry{}
	copy(e.U8a[:], v[:2])
	e.U16a = Uint16BE(v[2:])
	e.U16b = Uint16BE(v[4:])
	e.U16c = Uint16BE(v[6:])
	copy(e.U8b[:], v[8:12])
	for i := 0; i < 4; i++ {
		e.U32[i] = Uint32BE(v[12+i*4:])
	}
	copy(e.U8c[:], v[28:32])
	return e, nil
}

// AssembleValue writes header + entries.
func (p ApStatisticsReq) AssembleValue() []byte {
	b := []byte{p.Radio, p.U8a, p.U8b}
	b = append(b, p.Raw8[:]...)
	b = append(b, p.U8c)
	b = AppendUint16BE(b, p.U16)
	for _, w := range p.W {
		b = AppendUint32BE(b, w)
	}
	for i := range p.Entries {
		b = append(b, p.Entries[i].AssembleEntry()...)
	}
	return b
}

// ParseApStatisticsReq decodes the 42-byte header + 32-byte entries
// (entry count implied by value length; the min covers the header alone).
func ParseApStatisticsReq(v []byte) (*ApStatisticsReq, error) {
	if len(v) < 42 {
		return nil, ErrShortPacket
	}
	p := &ApStatisticsReq{Radio: v[0], U8a: v[1], U8b: v[2]}
	copy(p.Raw8[:], v[3:11])
	p.U8c = v[11]
	p.U16 = Uint16BE(v[12:])
	for i := 0; i < 7; i++ {
		p.W[i] = Uint32BE(v[14+i*4:])
	}
	off := 42
	for off+32 <= len(v) {
		e, err := ParseApStatEntry(v[off : off+32])
		if err != nil {
			return nil, err
		}
		p.Entries = append(p.Entries, *e)
		off += 32
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return p, nil
}
