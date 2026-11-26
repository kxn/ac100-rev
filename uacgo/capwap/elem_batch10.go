package capwap

// Batch-10: duplicate ipv6 (0x16) and the private statistics-request group
// (0x52/0x53/0x54), layouts from the vendor assemble functions.

// AppendDuplicateIPv6Address is element 0x0016 (min 18 max 26):
// BE32 status + u8 type + u8 addr-len + addr (ipv6 16B, padded ranges).
func AppendDuplicateIPv6Address(dst []byte, status uint32, typ uint8, addr []byte) []byte {
	v := AppendUint32BE(nil, status)
	v = append(v, typ, byte(len(addr)))
	v = append(v, addr...)
	return AppendElement(dst, 0x0016, v)
}

// ParseDuplicateIPv6Address decodes element 0x0016 (exact consumption,
// total length 18..26 per elements.tsv).
func ParseDuplicateIPv6Address(v []byte) (*DuplicateAddr, error) {
	if len(v) < 18 || len(v) > 26 || v[4] > 16 || 6+int(v[5]) != len(v) {
		return nil, ErrShortPacket
	}
	return &DuplicateAddr{Status: Uint32BE(v), Type: v[4],
		Addr: append([]byte(nil), v[6:]...)}, nil
}

// StaStatisticsRecord is one per-station record of element 0x0052,
// wire layout per cw_priv_sta_statistics_assemble (38 bytes):
//
//	6B mac + u8×6 + BE16 + BE32 + BE16 + u8×2 + BE32×4
type StaStatisticsRecord struct {
	MAC  [6]byte
	U8   [6]byte
	U16a uint16
	U32a uint32
	U16b uint16
	U8b  [2]byte
	U32  [4]uint32
}

// AssembleRecord writes the 38 wire bytes.
func (r *StaStatisticsRecord) AssembleRecord() []byte {
	b := append([]byte(nil), r.MAC[:]...)
	b = append(b, r.U8[:]...)
	b = AppendUint16BE(b, r.U16a)
	b = AppendUint32BE(b, r.U32a)
	b = AppendUint16BE(b, r.U16b)
	b = append(b, r.U8b[:]...)
	for _, w := range r.U32 {
		b = AppendUint32BE(b, w)
	}
	return b
}

// ParseStaStatisticsRecord decodes one 38-byte record.
func ParseStaStatisticsRecord(v []byte) (*StaStatisticsRecord, error) {
	if len(v) != 38 {
		return nil, ErrShortPacket
	}
	r := &StaStatisticsRecord{}
	copy(r.MAC[:], v[:6])
	copy(r.U8[:], v[6:12])
	r.U16a = Uint16BE(v[12:])
	r.U32a = Uint32BE(v[14:])
	r.U16b = Uint16BE(v[18:])
	copy(r.U8b[:], v[20:22])
	for i := 0; i < 4; i++ {
		r.U32[i] = Uint32BE(v[22+i*4:])
	}
	return r, nil
}

// PrivStaStatisticsReq is element 0x0052 (min 4 max 0x1db4):
// BE32 record count + count × 38-byte typed records
// (cw_priv_sta_statistics_parse @0x5c7c9c).
type PrivStaStatisticsReq struct {
	Count   uint32
	Records []StaStatisticsRecord
}

// AssembleValue writes count + records.
func (p PrivStaStatisticsReq) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.Count)
	for i := range p.Records {
		b = append(b, p.Records[i].AssembleRecord()...)
	}
	return b
}

// ParsePrivStaStatisticsReq decodes count + typed records (each record is
// exactly 38 bytes per the vendor parse sequence (cw_priv_sta_statistics
// _parse @0x5c7c9c: r32 count + per-record rbytes(6) r8×6 r16 r32 r16
// r8×2 r32×4 = 38 bytes).
func ParsePrivStaStatisticsReq(v []byte) (*PrivStaStatisticsReq, error) {
	if len(v) < 4 {
		return nil, ErrShortPacket
	}
	p := &PrivStaStatisticsReq{Count: Uint32BE(v)}
	if p.Count > 200 || uint64(p.Count)*38+4 != uint64(len(v)) {
		return nil, ErrShortPacket
	}
	for off := 4; off+38 <= len(v); off += 38 {
		r, err := ParseStaStatisticsRecord(v[off : off+38])
		if err != nil {
			return nil, err
		}
		p.Records = append(p.Records, *r)
	}
	return p, nil
}
