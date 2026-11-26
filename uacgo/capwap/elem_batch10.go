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
	MAC                                                [6]byte
	Radio, WLAN, AuthType, Cipher                      uint8
	RSSI, Bandwidth                                    int8
	NegotiatedMbps                                     uint16
	SupportWord                                        uint32
	Capabilities                                       uint16
	RetryPercent, LossPercent                          uint8
	UpstreamKbps, DownstreamKbps, UploadKB, DownloadKB uint32
}

func (r *StaStatisticsRecord) AssembleRecord() []byte {
	b := append([]byte{}, r.MAC[:]...)
	b = append(b, r.Radio, r.WLAN, r.AuthType, r.Cipher, byte(r.RSSI), byte(r.Bandwidth))
	b = AppendUint16BE(b, r.NegotiatedMbps)
	b = AppendUint32BE(b, r.SupportWord)
	b = AppendUint16BE(b, r.Capabilities)
	b = append(b, r.RetryPercent, r.LossPercent)
	for _, v := range []uint32{r.UpstreamKbps, r.DownstreamKbps, r.UploadKB, r.DownloadKB} {
		b = AppendUint32BE(b, v)
	}
	return b
}
func ParseStaStatisticsRecord(v []byte) (*StaStatisticsRecord, error) {
	if len(v) != 38 {
		return nil, ErrShortPacket
	}
	r := &StaStatisticsRecord{Radio: v[6], WLAN: v[7], AuthType: v[8], Cipher: v[9], RSSI: int8(v[10]), Bandwidth: int8(v[11]), NegotiatedMbps: Uint16BE(v[12:]), SupportWord: Uint32BE(v[14:]), Capabilities: Uint16BE(v[18:]), RetryPercent: v[20], LossPercent: v[21], UpstreamKbps: Uint32BE(v[22:]), DownstreamKbps: Uint32BE(v[26:]), UploadKB: Uint32BE(v[30:]), DownloadKB: Uint32BE(v[34:])}
	copy(r.MAC[:], v[:6])
	return r, nil
}

// PrivStaStatisticsReq is element 0x0052 (min 4 max 0x1db4):
// BE32 record count + count × 38-byte typed records
// (V6 cw_priv_sta_statistics_parse / dump @0x6a1da4).
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
// V6 parse: r32 count + per-record rbytes(6) r8×6 r16 r32 r16
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
