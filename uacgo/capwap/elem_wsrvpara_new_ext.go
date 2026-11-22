package capwap

// 0x63 new wsrv para extended tails, typed per
// cw_priv_wsrv_para_new_parse @0x5cfcb0 (notes §30):

// WsrvParaNewExtB is the B' tail (0x4e-byte struct):
//
//	u8 a, u8 b, BE32 c, IP ip1, IP ip2, IP ip3, BE16×3, BE16 len, raw
//
// (cw_protocol_retrieve_ip ×3 = 4-byte IPv4 addresses in this firmware).
type WsrvParaNewExtB struct {
	A, B   uint8
	C      uint32
	IP1    [4]byte
	IP2    [4]byte
	IP3    [4]byte
	G      uint16
	H      uint16
	I      uint16
	Length uint16
	Raw    []byte
}

// AssembleWsrvParaNewExtB writes the B' tail.
func AssembleWsrvParaNewExtB(e WsrvParaNewExtB) []byte {
	b := []byte{e.A, e.B}
	b = AppendUint32BE(b, e.C)
	b = append(b, e.IP1[:]...)
	b = append(b, e.IP2[:]...)
	b = append(b, e.IP3[:]...)
	b = AppendUint16BE(b, e.G)
	b = AppendUint16BE(b, e.H)
	b = AppendUint16BE(b, e.I)
	b = AppendUint16BE(b, e.Length)
	return append(b, e.Raw...)
}

// ParseWsrvParaNewExtB decodes the B' tail (exact consumption).
func ParseWsrvParaNewExtB(v []byte) (*WsrvParaNewExtB, error) {
	need := 2 + 4 + 12 + 6 + 2
	if len(v) < need {
		return nil, ErrShortPacket
	}
	e := &WsrvParaNewExtB{A: v[0], B: v[1], C: Uint32BE(v[2:])}
	copy(e.IP1[:], v[6:10])
	copy(e.IP2[:], v[10:14])
	copy(e.IP3[:], v[14:18])
	e.G = Uint16BE(v[18:])
	e.H = Uint16BE(v[20:])
	e.I = Uint16BE(v[22:])
	e.Length = Uint16BE(v[24:])
	n := int(e.Length)
	if 26+n != len(v) {
		return nil, ErrShortPacket
	}
	e.Raw = append([]byte(nil), v[26:]...)
	return e, nil
}

// WsrvParaNewStaList decodes the C' tail — same 33-byte blocks as the old
// variant C (u8 a, u8 count, u8 radio, count × 32B ssid).
type WsrvParaNewStaList struct {
	A, B, Radio uint8
	SSIDs       [][]byte
}

// AssembleWsrvParaNewStaList writes the C' tail.
func AssembleWsrvParaNewStaList(a, b, radio uint8, ssids [][]byte) []byte {
	return AssembleWsrvParaStaList(a, b, radio, ssids)
}

// ParseWsrvParaNewStaList decodes the C' tail.
func ParseWsrvParaNewStaList(v []byte) (*WsrvParaNewStaList, error) {
	a, b, radio, ssids, err := ParseWsrvParaStaList(v)
	if err != nil {
		return nil, err
	}
	return &WsrvParaNewStaList{A: a, B: b, Radio: radio, SSIDs: ssids}, nil
}
