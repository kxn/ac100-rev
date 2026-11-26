package capwap

import "encoding/binary"

// Batch-18: remaining private elements (defend/PMK/LDSP/statistics).

// PrivDhcpDefend (0x47): enable8, operation8, entry-count32, then
// {address-type8,address[6]}. Operation0 toggles, operation1 replaces the list.
type PrivDhcpDefend struct {
	Enable uint8
	Count  uint8  // operation, retained name for source compatibility
	SvrLen uint32 // number of entries (not a byte length)
	Tail   []byte
}

func (p PrivDhcpDefend) AssembleValue() []byte {
	return append(AppendUint32BE([]byte{p.Enable, p.Count}, p.SvrLen), p.Tail...)
}
func ParsePrivDhcpDefend(v []byte) (*PrivDhcpDefend, error) {
	if !validDefendLength(v, 7) {
		return nil, ErrShortPacket
	}
	return &PrivDhcpDefend{Enable: v[0], Count: v[1], SvrLen: Uint32BE(v[2:]), Tail: append([]byte{}, v[6:]...)}, nil
}
func validDefendLength(v []byte, width int) bool {
	if len(v) < 6 {
		return false
	}
	n := uint64(Uint32BE(v[2:]))
	if v[1] == 0 && width != 10 && width != 22 {
		n = 0
	}
	return uint64(len(v)) == 6+n*uint64(width)
}

// PrivArpDefend (0x48): flags8, operation8, count32, then IPv4[4]/MAC[6].
// The C entry structure is12 bytes; its padding is absent on the wire.
type PrivArpDefend struct {
	Enable uint8
	Count  uint8
	W1     uint32
	Tail   []byte
}

func (p PrivArpDefend) AssembleValue() []byte {
	return append(AppendUint32BE([]byte{p.Enable, p.Count}, p.W1), p.Tail...)
}
func ParsePrivArpDefend(v []byte) (*PrivArpDefend, error) {
	if !validDefendLength(v, 10) {
		return nil, ErrShortPacket
	}
	return &PrivArpDefend{Enable: v[0], Count: v[1], W1: Uint32BE(v[2:]), Tail: append([]byte{}, v[6:]...)}, nil
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
