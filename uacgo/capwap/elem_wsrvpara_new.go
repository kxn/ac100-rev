package capwap

import "encoding/binary"

// Element 0x63 "wsrv para (new)" per cw_priv_wsrv_para_new_parse
// @0x5cfcb0. Header form (0xd-byte struct):
//   u8 a, u8 b, BE16 c, BE16 d, u8 e, u8 f, u8 g   — same 9-byte shape as
//   the old wsrv para, plus:
// Extended variants (after the header, selected by trailing length):
//   A' (0xc struct): u8, u8, BE32, BE16, BE16 len, raw
//   B' (0x4e struct): u8, u8, BE32, IP, IP, IP, BE16×3, BE16 len, raw
//      (three 4-byte IP fields retrieved via cw_protocol_retrieve_ip)
//   C' (sta list): u8, u8, u8 radio, count × 32-byte ssid blocks
// This codec decodes the header and carries the chosen extended tail
// verbatim (the tail selectors mirror the old element's three branches).
// Full vendor retrieve sequence (conditional branches folded):
// r8 r8 r16 r16 r8 r8 r8 r8 r8 r32 rip rip rip r16 r16 r16 r16 rraw
// r8 r8 r32 r16 rraw r8 r8 r8 rbytes — the fixture-backed common form
// consumes the 9-byte head; variants extend the head/tail, which the
// verbatim tail preserves byte-exactly.

// PrivWsrvParaFields is the 9-byte header shared by 0x09/0x63:
// u8 a, u8 b, BE16 c, BE16 d, u8 e, u8 f, u8 g.
type PrivWsrvParaFields struct {
	A       uint8
	B       uint8
	C       uint16
	D       uint16
	E, F, G uint8
}

// PrivWsrvParaNew is element 0x63.
type PrivWsrvParaNew struct {
	Header PrivWsrvParaFields
	Tail   []byte
}

// AssembleValue writes header + tail.
func (p PrivWsrvParaNew) AssembleValue() []byte {
	f := p.Header
	b := []byte{f.A, f.B, byte(f.C >> 8), byte(f.C), byte(f.D >> 8), byte(f.D), f.E, f.F, f.G}
	return append(b, p.Tail...)
}

// ParsePrivWsrvParaNew decodes the 9-byte header and keeps the tail.
func ParsePrivWsrvParaNew(v []byte) (*PrivWsrvParaNew, error) {
	if len(v) < 9 {
		return nil, ErrShortPacket
	}
	p := &PrivWsrvParaNew{Header: PrivWsrvParaFields{
		A: v[0], B: v[1],
		C: binary.BigEndian.Uint16(v[2:]),
		D: binary.BigEndian.Uint16(v[4:]),
		E: v[6], F: v[7], G: v[8],
	}}
	if len(v) > 9 {
		p.Tail = append([]byte(nil), v[9:]...)
	}
	return p, nil
}
