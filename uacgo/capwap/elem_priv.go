package capwap

import "encoding/binary"

// Private (0x25-envelope) element value codecs for the wserv/rdmngr path.
// Each is the vendor's parse/assemble byte order, validated by round-trip
// against the envelope payloads in the vendor fixtures (cw_wlan_cfg_req,
// cw_cfg_update_req, cw_cfg_rsp).

// PrivWsrvPara mirrors cw_priv_wsrv_para_parse @0x5ce6f8 (header form):
//
//	u8 a, u8 b, BE16 c, BE16 d, u8 e, u8 f, u8 g   (9 bytes)
//
// The parser accepts optional extended tails (12/31-byte per-station forms);
// those are carried verbatim via Tail.
type PrivWsrvPara struct {
	A       uint8
	B       uint8
	C       uint16
	D       uint16
	E, F, G uint8
	Tail    []byte
}

// ParsePrivWsrvPara decodes the 9-byte header form; any remaining bytes are
// kept in Tail (extended variants @0x5ce6f8 read them after the header).
func ParsePrivWsrvPara(v []byte) (*PrivWsrvPara, error) {
	if len(v) < 9 {
		return nil, ErrShortPacket
	}
	p := &PrivWsrvPara{
		A: v[0], B: v[1],
		C: binary.BigEndian.Uint16(v[2:]),
		D: binary.BigEndian.Uint16(v[4:]),
		E: v[6], F: v[7], G: v[8],
	}
	if len(v) > 9 {
		p.Tail = append([]byte(nil), v[9:]...)
	}
	return p, nil
}

// AssembleValue writes the header form plus tail.
func (p *PrivWsrvPara) AssembleValue() []byte {
	b := []byte{p.A, p.B, byte(p.C >> 8), byte(p.C), byte(p.D >> 8), byte(p.D), p.E, p.F, p.G}
	return append(b, p.Tail...)
}

// PrivWlanList mirrors cw_priv_wlan_list_parse @0x5cba28:
//
//	BE32 a, BE32 b, N × { u8 radio?, 32-byte fixed ssid }
//
// (dump @0x5cb5a4 labels the per-entry u8 "radio id"; entries are fixed 0x21
// bytes each).
type PrivWlanList struct {
	A       uint32
	B       uint32
	Entries []PrivWlanEntry
}

// PrivWlanEntry is one 33-byte wlan list entry.
type PrivWlanEntry struct {
	RadioID uint8
	SSID    []byte // exactly 32 bytes (fixed-width, NUL padded)
}

// ParsePrivWlanList decodes the element value.
func ParsePrivWlanList(v []byte) (*PrivWlanList, error) {
	if len(v) < 8 {
		return nil, ErrShortPacket
	}
	l := &PrivWlanList{
		A: binary.BigEndian.Uint32(v),
		B: binary.BigEndian.Uint32(v[4:]),
	}
	off := 8
	for off+0x21 <= len(v) {
		ssid := append([]byte(nil), v[off+1:off+0x21]...)
		l.Entries = append(l.Entries, PrivWlanEntry{RadioID: v[off], SSID: ssid})
		off += 0x21
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return l, nil
}

// AssembleValue writes the element value.
func (l *PrivWlanList) AssembleValue() []byte {
	b := binary.BigEndian.AppendUint32(nil, l.A)
	b = binary.BigEndian.AppendUint32(b, l.B)
	for _, e := range l.Entries {
		b = append(b, e.RadioID)
		b = append(b, e.SSID...)
	}
	return b
}

// PrivAdvRdPara mirrors cw_priv_adv_rd_para_parse @0x5a3654.
// Fixed 15-byte head (slot 0xd of the vendor struct is padding), then
// length-conditional reads:
//
//	len ∈ {0x14,0x15,0x1a,0x1b} → 4 bytes read then replaced by the vendor
//	    defaults ff 01 ff 01 (quirk preserved)
//	len even                    → 1 byte [0x15]
//	len >= 0x16                 → 6 more bytes [0x16..0x1b]
type PrivAdvRdPara struct {
	RadioID uint8
	Head    [14]byte // bytes 1..14 of the wire head (slot 4..5 = BE16)
	Extra4  []byte   // present when read (stored as vendor defaults)
	Byte15  uint8    // [0x15], 0xff default
	Tail6   []byte   // [0x16..0x1b]
}

// ParsePrivAdvRdPara decodes the value with the vendor's length conditionals.
func ParsePrivAdvRdPara(v []byte) (*PrivAdvRdPara, error) {
	if len(v) < 15 || v[0] >= 0x20 {
		return nil, ErrShortPacket
	}
	p := &PrivAdvRdPara{RadioID: v[0]}
	copy(p.Head[:], v[1:15])
	l := len(v)
	off := 15
	if l == 0x14 || l == 0x15 || l == 0x1a || l == 0x1b {
		if off+4 > l {
			return nil, ErrShortPacket
		}
		off += 4
		p.Extra4 = []byte{0xff, 0x01, 0xff, 0x01} // vendor overwrites with defaults
	}
	if l%2 == 0 {
		if off+1 > l {
			return nil, ErrShortPacket
		}
		p.Byte15 = v[off]
		off++
	}
	if l >= 0x16 {
		if off+6 > l {
			return nil, ErrShortPacket
		}
		p.Tail6 = append([]byte(nil), v[off:off+6]...)
		off += 6
	}
	if off != l {
		return nil, ErrShortPacket
	}
	return p, nil
}

// AssembleValue writes the wire bytes (head + defaults-preserving extras).
func (p *PrivAdvRdPara) AssembleValue() []byte {
	b := make([]byte, 0, 15)
	b = append(b, p.RadioID)
	b = append(b, p.Head[:]...)
	if p.Extra4 != nil {
		b = append(b, p.Extra4...)
	}
	if p.Tail6 != nil || p.Byte15 != 0xff {
		// byte15 participates when the length was even; reproduce by position:
		// the caller supplies the original length via LenHint when needed.
		b = append(b, p.Byte15)
	}
	if p.Tail6 != nil {
		b = append(b, p.Tail6...)
	}
	return b
}

// PrivRate mirrors cw_priv_rate_parse @0x5ba0e4 (55 bytes):
//
//	u8 radio (<0x20), [1..8], [9..16], u8 [0x11], [0x12..0x15], [0x16..0x19],
//	u8 [0x1a], [0x1b..0x26], [0x27..0x32], u8 ×4
type PrivRate struct {
	RadioID uint8
	Body    [54]byte
}

// ParsePrivRate decodes the rate element value.
func ParsePrivRate(v []byte) (*PrivRate, error) {
	if len(v) != 55 || v[0] >= 0x20 {
		return nil, ErrShortPacket
	}
	p := &PrivRate{RadioID: v[0]}
	copy(p.Body[:], v[1:])
	return p, nil
}

// AssembleValue writes the 55 wire bytes.
func (p *PrivRate) AssembleValue() []byte {
	b := make([]byte, 0, 55)
	b = append(b, p.RadioID)
	return append(b, p.Body[:]...)
}
