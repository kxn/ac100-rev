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

// PrivStaPMKReq is private0x49, exactly101 bytes in V6 (6b14d8/6b1350).
// The first two bytes are operation/result, not radio/WLAN.
type PrivStaPMKReq struct {
	Operation, Result, Radio, WLAN uint8
	Pairwise                       uint32
	Interface                      [17]byte
	Nonce                          [16]byte
	MAC, APMAC                     [6]byte
	PMKR0                          [32]byte
	PMKR0Name                      [16]byte
}

func (p PrivStaPMKReq) AssembleValue() []byte {
	b := []byte{p.Operation, p.Result, p.Radio, p.WLAN}
	b = AppendUint32BE(b, p.Pairwise)
	b = append(b, p.Interface[:]...)
	b = append(b, p.Nonce[:]...)
	b = append(b, p.MAC[:]...)
	b = append(b, p.APMAC[:]...)
	b = append(b, p.PMKR0[:]...)
	return append(b, p.PMKR0Name[:]...)
}
func ParsePrivStaPMKReq(v []byte) (*PrivStaPMKReq, error) {
	if len(v) != 101 || v[2] >= 32 || v[3] >= 17 {
		return nil, ErrShortPacket
	}
	p := &PrivStaPMKReq{Operation: v[0], Result: v[1], Radio: v[2], WLAN: v[3], Pairwise: Uint32BE(v[4:])}
	copy(p.Interface[:], v[8:25])
	copy(p.Nonce[:], v[25:41])
	copy(p.MAC[:], v[41:47])
	copy(p.APMAC[:], v[47:53])
	copy(p.PMKR0[:], v[53:85])
	copy(p.PMKR0Name[:], v[85:101])
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
