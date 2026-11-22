package capwap

// Batch-23: priv 0x3e/0x41/0x42/0x45/0x4d/0x53/0x54. Layouts from the
// vendor parse functions' retrieve sequences (cw_priv_*_parse addresses
// in the comments; rbytes lengths from the retrieve_bytes a2 argument).

// PrivSpecRssi is 0x3e: BE32 (cw_priv_spec_rssi_parse @0x5c11f8).
type PrivSpecRssi uint32

// AssembleValue writes the 4 bytes.
func (p PrivSpecRssi) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivSpecRssi decodes the 4 bytes.
func ParsePrivSpecRssi(v []byte) (PrivSpecRssi, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivSpecRssi(Uint32BE(v)), nil
}

// PrivApConfigChecksum is 0x41: 16 raw bytes
// (cw_priv_ap_config_checksum_parse @0x5a4870, rbytes(16)).
type PrivApConfigChecksum [16]byte

// AssembleValue returns the 16 bytes.
func (p PrivApConfigChecksum) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParsePrivApConfigChecksum decodes the 16 bytes.
func ParsePrivApConfigChecksum(v []byte) (PrivApConfigChecksum, error) {
	var out PrivApConfigChecksum
	if len(v) != 16 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// PrivWechatIPList is 0x42: BE32 count + raw ip list
// (cw_priv_wechat_iplist_parse @0x5cb378).
type PrivWechatIPList struct {
	Count uint32
	Rest  []byte
}

// AssembleValue writes header + rest.
func (p PrivWechatIPList) AssembleValue() []byte {
	return append(AppendUint32BE(nil, p.Count), p.Rest...)
}

// ParsePrivWechatIPList decodes header + rest.
func ParsePrivWechatIPList(v []byte) (*PrivWechatIPList, error) {
	if len(v) < 4 {
		return nil, ErrShortPacket
	}
	return &PrivWechatIPList{Count: Uint32BE(v), Rest: append([]byte(nil), v[4:]...)}, nil
}

// PrivBwCtrl is 0x45: r8 r32 r32 r8 r32 r8 rbytes = 15-byte header + tail
// (cw_priv_bw_ctrl_parse @0x5ac66c).
type PrivBwCtrl struct {
	A    uint8
	W1   uint32
	W2   uint32
	B    uint8
	W3   uint32
	C    uint8
	Tail []byte
}

// AssembleValue writes header + tail.
func (p PrivBwCtrl) AssembleValue() []byte {
	b := []byte{p.A}
	b = AppendUint32BE(b, p.W1)
	b = AppendUint32BE(b, p.W2)
	b = append(b, p.B)
	b = AppendUint32BE(b, p.W3)
	b = append(b, p.C)
	return append(b, p.Tail...)
}

// ParsePrivBwCtrl decodes header + tail.
func ParsePrivBwCtrl(v []byte) (*PrivBwCtrl, error) {
	if len(v) < 15 {
		return nil, ErrShortPacket
	}
	p := &PrivBwCtrl{A: v[0], W1: Uint32BE(v[1:]), W2: Uint32BE(v[5:]),
		B: v[9], W3: Uint32BE(v[10:]), C: v[14],
		Tail: append([]byte(nil), v[15:]...)}
	return p, nil
}

// PrivStaIPList is 0x4d: BE32 count + per-sta {mac6, ip4}
// (cw_priv_sta_ip_list_parse @0x5c64f4: r32 rbytes(6) rip).
type PrivStaIPList struct {
	Count uint32
	Rows  []PrivStaIPRow
}

// PrivStaIPRow is one 10-byte row.
type PrivStaIPRow struct {
	MAC [6]byte
	IP  [4]byte
}

// AssembleValue writes count + rows.
func (p PrivStaIPList) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.Count)
	for _, r := range p.Rows {
		b = append(b, r.MAC[:]...)
		b = append(b, r.IP[:]...)
	}
	return b
}

// ParsePrivStaIPList decodes count + 10-byte rows.
func ParsePrivStaIPList(v []byte) (*PrivStaIPList, error) {
	if len(v) < 4 {
		return nil, ErrShortPacket
	}
	p := &PrivStaIPList{Count: Uint32BE(v)}
	off := 4
	for off+10 <= len(v) {
		var r PrivStaIPRow
		copy(r.MAC[:], v[off:off+6])
		copy(r.IP[:], v[off+6:off+10])
		p.Rows = append(p.Rows, r)
		off += 10
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return p, nil
}

// PrivRssiStatistics is 0x53: rbytes(8) rbytes(8) r32 rbytes(6) rbytes(8)
// (cw_priv_rssi_statistics_parse @0x5bf28c).
type PrivRssiStatistics struct {
	BSSIDs [8]byte
	SNRs   [8]byte
	W      uint32
	BSSID  [6]byte
	Rates  [8]byte
}

// AssembleValue writes the 34 bytes.
func (p PrivRssiStatistics) AssembleValue() []byte {
	b := append([]byte(nil), p.BSSIDs[:]...)
	b = append(b, p.SNRs[:]...)
	b = AppendUint32BE(b, p.W)
	b = append(b, p.BSSID[:]...)
	return append(b, p.Rates[:]...)
}

// ParsePrivRssiStatistics decodes the 34 bytes.
func ParsePrivRssiStatistics(v []byte) (*PrivRssiStatistics, error) {
	if len(v) != 34 {
		return nil, ErrShortPacket
	}
	p := &PrivRssiStatistics{W: Uint32BE(v[16:])}
	copy(p.BSSIDs[:], v[:8])
	copy(p.SNRs[:], v[8:16])
	copy(p.BSSID[:], v[20:26])
	copy(p.Rates[:], v[26:34])
	return p, nil
}

// PrivApStatistics is 0x54 (cw_priv_ap_statistics_parse @0x5a7f04,
// retrieve sequence r8 r8 r8 rbytes(8) r8 r16 r32×7 r8 r8 r16 r16 r16
// r8×4 r32×4 r8×6 rbytes(6) r16 r8 r8 r32×4 = 102 bytes).
type PrivApStatistics struct {
	A, B, C    uint8
	Blk8       [8]byte
	D          uint8
	U16a       uint16
	W1         [7]uint32
	E, F       uint8
	U16b, U16c uint16
	U16d       uint16
	G          [4]uint8
	W2         [4]uint32
	H          [6]uint8
	MAC        [6]byte
	U16e       uint16
	I, J       uint8
	W3         [4]uint32
}

// AssembleValue writes the 102 bytes.
func (p *PrivApStatistics) AssembleValue() []byte {
	b := []byte{p.A, p.B, p.C}
	b = append(b, p.Blk8[:]...)
	b = append(b, p.D)
	b = AppendUint16BE(b, p.U16a)
	for _, w := range p.W1 {
		b = AppendUint32BE(b, w)
	}
	b = append(b, p.E, p.F)
	for _, u := range []uint16{p.U16b, p.U16c, p.U16d} {
		b = AppendUint16BE(b, u)
	}
	b = append(b, p.G[:]...)
	for _, w := range p.W2 {
		b = AppendUint32BE(b, w)
	}
	b = append(b, p.H[:]...)
	b = append(b, p.MAC[:]...)
	b = AppendUint16BE(b, p.U16e)
	b = append(b, p.I, p.J)
	for _, w := range p.W3 {
		b = AppendUint32BE(b, w)
	}
	return b
}

// ParsePrivApStatistics decodes the 102 bytes.
func ParsePrivApStatistics(v []byte) (*PrivApStatistics, error) {
	if len(v) != 102 {
		return nil, ErrShortPacket
	}
	p := &PrivApStatistics{A: v[0], B: v[1], C: v[2], D: v[11],
		U16a: Uint16BE(v[12:]), E: v[42], F: v[43],
		U16b: Uint16BE(v[44:]), U16c: Uint16BE(v[46:]), U16d: Uint16BE(v[48:]),
		U16e: Uint16BE(v[82:]), I: v[84], J: v[85]}
	copy(p.Blk8[:], v[3:11])
	for i := 0; i < 7; i++ {
		p.W1[i] = Uint32BE(v[14+i*4:])
	}
	copy(p.G[:], v[50:54])
	for i := 0; i < 4; i++ {
		p.W2[i] = Uint32BE(v[54+i*4:])
	}
	copy(p.H[:], v[70:76])
	copy(p.MAC[:], v[76:82])
	for i := 0; i < 4; i++ {
		p.W3[i] = Uint32BE(v[86+i*4:])
	}
	return p, nil
}
