package capwap

import "encoding/binary"

// Batch-18: remaining private elements (defend/PMK/LDSP/statistics).

// PrivDhcpDefend is 0x47 (min 6): u8 enable + u8 count + BE32 svr_len
// + per-server {u8 id, u8 pad, BE16, 6B mac} entries.
// (cw_priv_dhcp_defend_parse.)
type PrivDhcpDefend struct {
	Enable uint8
	Count  uint8
	SvrLen uint32
	Tail   []byte // server entries verbatim
}

// AssembleValue writes header + tail.
func (p PrivDhcpDefend) AssembleValue() []byte {
	b := []byte{p.Enable, p.Count}
	b = AppendUint32BE(b, p.SvrLen)
	return append(b, p.Tail...)
}

// ParsePrivDhcpDefend decodes header + tail.
func ParsePrivDhcpDefend(v []byte) (*PrivDhcpDefend, error) {
	if len(v) < 6 {
		return nil, ErrShortPacket
	}
	return &PrivDhcpDefend{Enable: v[0], Count: v[1],
		SvrLen: Uint32BE(v[2:]), Tail: append([]byte(nil), v[6:]...)}, nil
}

// PrivArpDefend is 0x48. Wire (cw_priv_arp_defend_parse @0x5ab914 retrieve
// sequence r8 r8 r32 r32 rbytes): u8 enable + u8 count + BE32 + BE32 +
// entry bytes.
type PrivArpDefend struct {
	Enable   uint8
	Count    uint8
	W1       uint32
	EntryLen uint32
	Tail     []byte
}

// AssembleValue writes header + tail.
func (p PrivArpDefend) AssembleValue() []byte {
	b := []byte{p.Enable, p.Count}
	b = AppendUint32BE(b, p.W1)
	b = AppendUint32BE(b, p.EntryLen)
	return append(b, p.Tail...)
}

// ParsePrivArpDefend decodes header + tail.
func ParsePrivArpDefend(v []byte) (*PrivArpDefend, error) {
	if len(v) < 10 {
		return nil, ErrShortPacket
	}
	return &PrivArpDefend{Enable: v[0], Count: v[1],
		W1: Uint32BE(v[2:]), EntryLen: Uint32BE(v[6:]),
		Tail: append([]byte(nil), v[10:]...)}, nil
}

// PrivStaPMKReq is 0x49 (min=max=0x65=101):
// u8 radio + u8 wlan_id + u8 + u8 + BE32 + 0x11B + 0x10B + 6B MAC.
// (cw_priv_sta_pmk_req_parse.)
type PrivStaPMKReq struct {
	Radio      uint8
	WlanID     uint8
	U8a        uint8
	U8b        uint8
	W          uint32
	Data       [0x11]byte
	Salt       [0x10]byte
	MAC        [6]byte
	VendorTail []byte
}

// AssembleValue writes the 0x65-byte value.
func (p PrivStaPMKReq) AssembleValue() []byte {
	b := []byte{p.Radio, p.WlanID, p.U8a, p.U8b}
	b = AppendUint32BE(b, p.W)
	b = append(b, p.Data[:]...)
	b = append(b, p.Salt[:]...)
	b = append(b, p.MAC[:]...)
	b = append(b, p.VendorTail...)
	return b
}

// ParsePrivStaPMKReq decodes the 0x65-byte value.
func ParsePrivStaPMKReq(v []byte) (*PrivStaPMKReq, error) {
	if len(v) < 8 {
		return nil, ErrShortPacket
	}
	p := &PrivStaPMKReq{
		Radio: v[0], WlanID: v[1], U8a: v[2], U8b: v[3], W: Uint32BE(v[4:])}
	// data block: 17 bytes starting at +8
	if len(v) >= 8+0x11 {
		copy(p.Data[:], v[8:8+0x11])
	}
	// salt block: 16 bytes after data
	if len(v) >= 8+0x11+0x10 {
		copy(p.Salt[:], v[8+0x11:8+0x11+0x10])
	}
	// mac block: 6 bytes after salt
	if len(v) >= 8+0x11+0x10+6 {
		copy(p.MAC[:], v[8+0x11+0x10:8+0x11+0x10+6])
	}
	// carry vendor tail verbatim
	if len(v) > 8+0x11+0x10+6 {
		p.VendorTail = append([]byte(nil), v[8+0x11+0x10+6:]...)
	}
	return p, nil
}

// PrivLLDP is 0x67 (min=max=4): 4 raw bytes.
// (cw_priv_lldp_parse: retrieve_bytes 4.)
type PrivLLDP [4]byte

// AssembleValue returns the 4 bytes.
func (p PrivLLDP) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParsePrivLLDP decodes the 4 bytes.
func ParsePrivLLDP(v []byte) (PrivLLDP, error) {
	var out PrivLLDP
	if len(v) != 4 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// AppendWTPRadioStatistics is element 0x002f (20 bytes, from batch12 but
// referenced here for the tx-stat typed codec).
// ApTxStat is priv 0x2e. Wire (cw_priv_ap_tx_stat_parse @0x5a92f8, size
// 0x290): u8 radio + rbytes(3) + 3×u64 + 20×u32 = 108 bytes.
type ApTxStat struct {
	Radio uint8
	Rsvd  [3]byte
	T     [3]uint64
	W     [20]uint32
}

// AssembleValue writes the 108-byte value.
func (p ApTxStat) AssembleValue() []byte {
	b := []byte{p.Radio}
	b = append(b, p.Rsvd[:]...)
	for _, t := range p.T {
		b = AppendUint32BE(b, uint32(t>>32))
		b = AppendUint32BE(b, uint32(t))
	}
	for _, w := range p.W {
		b = AppendUint32BE(b, w)
	}
	return b
}

// ParseApTxStat decodes the 108-byte tx-stat value.
func ParseApTxStat(v []byte) (*ApTxStat, error) {
	if len(v) != 108 {
		return nil, ErrShortPacket
	}
	p := &ApTxStat{Radio: v[0]}
	copy(p.Rsvd[:], v[1:4])
	off := 4
	for i := 0; i < 3; i++ {
		hi := Uint32BE(v[off:])
		lo := Uint32BE(v[off+4:])
		p.T[i] = uint64(hi)<<32 | uint64(lo)
		off += 8
	}
	for i := 0; i < 20; i++ {
		p.W[i] = Uint32BE(v[off:])
		off += 4
	}
	return p, nil
}

var _ = binary.BigEndian
