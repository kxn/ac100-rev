package capwap

// wsrv para (0x09/0x63) extended-tail variants A and B, typed per the
// retrieve sequences in cw_priv_wsrv_para_parse @0x5ce6f8
// (notes §15/§29; the 9-byte header is already in PrivWsrvPara).

// WsrvParaExtA is variant A (0xc-byte struct):
//
//	u8 a, u8 b, BE32 c, BE16 d, BE16 len, raw[len]
type WsrvParaExtA struct {
	A   uint8
	B   uint8
	C   uint32
	D   uint16
	Raw []byte
}

// AssembleWsrvParaExtA writes the variant-A tail.
func AssembleWsrvParaExtA(e WsrvParaExtA) []byte {
	b := []byte{e.A, e.B}
	b = AppendUint32BE(b, e.C)
	b = AppendUint16BE(b, e.D)
	b = AppendUint16BE(b, uint16(len(e.Raw)))
	return append(b, e.Raw...)
}

// ParseWsrvParaExtA decodes the variant-A tail (exact consumption).
func ParseWsrvParaExtA(v []byte) (*WsrvParaExtA, error) {
	if len(v) < 10 {
		return nil, ErrShortPacket
	}
	e := &WsrvParaExtA{A: v[0], B: v[1],
		C: Uint32BE(v[2:]), D: Uint16BE(v[6:])}
	n := int(Uint16BE(v[8:]))
	off := 10
	if n < 0 || off+n > len(v) {
		return nil, ErrShortPacket
	}
	e.Raw = append([]byte(nil), v[off:off+n]...)
	off += n
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return e, nil
}

// WsrvParaExtB is variant B (0x1f-byte struct):
//
//	u8 a, u8 b, BE32 c, BE32 d, [BE32 e, BE32 f if b != 0],
//	BE16 g, [BE16 h, BE16 i, BE16 j if b != 0], BE16 len, raw[len]
//
// (the optional fields appear when the flag byte b is non-zero, per the
// `puVar4[6] != 0` guards in the parse).
type WsrvParaExtB struct {
	A                uint8
	B                uint8 // flag: 0 = short form
	C, D             uint32
	OptE, OptF       uint32 // present when B != 0
	G                uint16
	OptH, OptI, OptJ uint16 // present when B != 0
	Raw              []byte
}

// AssembleWsrvParaExtB writes the variant-B tail.
func AssembleWsrvParaExtB(e WsrvParaExtB) []byte {
	b := []byte{e.A, e.B}
	b = AppendUint32BE(b, e.C)
	b = AppendUint32BE(b, e.D)
	if e.B != 0 {
		b = AppendUint32BE(b, e.OptE)
		b = AppendUint32BE(b, e.OptF)
	}
	b = AppendUint16BE(b, e.G)
	if e.B != 0 {
		b = AppendUint16BE(b, e.OptH)
		b = AppendUint16BE(b, e.OptI)
		b = AppendUint16BE(b, e.OptJ)
	}
	b = AppendUint16BE(b, uint16(len(e.Raw)))
	return append(b, e.Raw...)
}

// ParseWsrvParaExtB decodes the variant-B tail (exact consumption).
func ParseWsrvParaExtB(v []byte) (*WsrvParaExtB, error) {
	if len(v) < 2 {
		return nil, ErrShortPacket
	}
	e := &WsrvParaExtB{A: v[0], B: v[1]}
	off := 2
	need := func(n int) error {
		if off+n > len(v) {
			return ErrShortPacket
		}
		return nil
	}
	take32 := func() uint32 {
		x := Uint32BE(v[off:])
		off += 4
		return x
	}
	take16 := func() uint16 {
		x := Uint16BE(v[off:])
		off += 2
		return x
	}
	if err := need(8); err != nil {
		return nil, err
	}
	e.C, e.D = take32(), take32()
	if e.B != 0 {
		if err := need(8); err != nil {
			return nil, err
		}
		e.OptE, e.OptF = take32(), take32()
	}
	if err := need(2); err != nil {
		return nil, err
	}
	e.G = take16()
	if e.B != 0 {
		if err := need(6); err != nil {
			return nil, err
		}
		e.OptH, e.OptI, e.OptJ = take16(), take16(), take16()
	}
	if err := need(2); err != nil {
		return nil, err
	}
	n := int(take16())
	if err := need(n); err != nil {
		return nil, err
	}
	e.Raw = append([]byte(nil), v[off:off+n]...)
	off += n
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return e, nil
}
