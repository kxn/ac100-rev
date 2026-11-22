package capwap

// Batch-5 variable-length elements.

// PrivBandwidthCtrl is element 0x45 "private bandwidth control"
// (min 11 max 0x30d), per cw_priv_bw_ctrl_assemble @0x5ac3fc:
//
//	u8 station count
//	BE32 up limit, BE32 down limit
//	per-station { u8, u8, BE32 }   (rate/mode/id triple)
//	raw MAC block: count*6 bytes rounded to even (restore_raw_bytes with
//	count*6 & 0xfffe)
//
// The tail (per-station triples + MAC block) is carried verbatim by this
// codec; the header fields are typed.
type PrivBandwidthCtrl struct {
	Count uint8
	Up    uint32
	Down  uint32
	Tail  []byte // per-station triples + MAC block, verbatim
}

// AssembleValue writes header + tail.
func (p PrivBandwidthCtrl) AssembleValue() []byte {
	b := []byte{p.Count}
	b = AppendUint32BE(b, p.Up)
	b = AppendUint32BE(b, p.Down)
	return append(b, p.Tail...)
}

// ParsePrivBandwidthCtrl decodes header + tail (tail length validated
// against the vendor parity rule when count*6 bytes are available).
func ParsePrivBandwidthCtrl(v []byte) (*PrivBandwidthCtrl, error) {
	if len(v) < 9 {
		return nil, ErrShortPacket
	}
	p := &PrivBandwidthCtrl{Count: v[0],
		Up: Uint32BE(v[1:]), Down: Uint32BE(v[5:])}
	p.Tail = append([]byte(nil), v[9:]...)
	return p, nil
}

// WsrvParaStaEntry is one station block of the wsrv-para variant C tail:
// u8 radio + 32-byte fixed ssid (retrieve_bytes(_, _, 0x20) @0x5ce6f8).
type WsrvParaStaEntry struct {
	Radio uint8
	SSID  [32]byte
}

// ParseWsrvParaStaList decodes the variant-C tail: u8 a, u8 count, u8 radio,
// then count × 32-byte ssid blocks (the third retrieve8 is the radio id,
// blocks follow).
func ParseWsrvParaStaList(v []byte) (a, b, radio uint8, ssids [][]byte, err error) {
	if len(v) < 3 {
		return 0, 0, 0, nil, ErrShortPacket
	}
	a, b, radio = v[0], v[1], v[2]
	off := 3
	for off+0x20 <= len(v) {
		ssids = append(ssids, append([]byte(nil), v[off:off+0x20]...))
		off += 0x20
	}
	if off != len(v) {
		return a, b, radio, nil, ErrShortPacket
	}
	return a, b, radio, ssids, nil
}

// AssembleWsrvParaStaList writes the variant-C tail.
func AssembleWsrvParaStaList(a, b, radio uint8, ssids [][]byte) []byte {
	out := []byte{a, b, radio}
	for _, s := range ssids {
		out = append(out, s...)
	}
	return out
}
