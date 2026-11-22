package capwap

// Batch-22: priv 0x00 capwap version, 0x26 spec msg switch, 0x2f rpt para.
// Layouts from the vendor parse functions' retrieve sequences.

// PrivCWVer is 0x00: BE32 {u16 hardware ver, u16 software ver}
// (cw_priv_cwver_parse @0x5aecf4: r16 r16).
type PrivCWVer struct {
	HW uint16
	SW uint16
}

// AssembleValue writes the 4 bytes.
func (p PrivCWVer) AssembleValue() []byte {
	b := AppendUint16BE(nil, p.HW)
	return AppendUint16BE(b, p.SW)
}

// ParsePrivCWVer decodes the 4 bytes.
func ParsePrivCWVer(v []byte) (*PrivCWVer, error) {
	if len(v) != 4 {
		return nil, ErrShortPacket
	}
	return &PrivCWVer{HW: Uint16BE(v), SW: Uint16BE(v[2:])}, nil
}

// PrivSpecMsgSw is 0x26: BE32 ×2 (cw_priv_spec_msg_sw_parse @0x5c0f10).
type PrivSpecMsgSw struct {
	A uint32
	B uint32
}

// AssembleValue writes the 8 bytes.
func (p PrivSpecMsgSw) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.A)
	return AppendUint32BE(b, p.B)
}

// ParsePrivSpecMsgSw decodes the 8 bytes.
func ParsePrivSpecMsgSw(v []byte) (*PrivSpecMsgSw, error) {
	if len(v) != 8 {
		return nil, ErrShortPacket
	}
	return &PrivSpecMsgSw{A: Uint32BE(v), B: Uint32BE(v[4:])}, nil
}

// PrivRptPara is 0x2f: r16 r16 r8 r32 r32 = 13 bytes
// (cw_priv_rpt_para_parse @0x5bdf38).
type PrivRptPara struct {
	W1 uint16
	W2 uint16
	A  uint8
	W3 uint32
	W4 uint32
}

// AssembleValue writes the 15 bytes.
func (p PrivRptPara) AssembleValue() []byte {
	b := AppendUint16BE(nil, p.W1)
	b = AppendUint16BE(b, p.W2)
	b = append(b, p.A)
	b = AppendUint32BE(b, p.W3)
	return AppendUint32BE(b, p.W4)
}

// ParsePrivRptPara decodes the 13 bytes.
func ParsePrivRptPara(v []byte) (*PrivRptPara, error) {
	if len(v) != 13 {
		return nil, ErrShortPacket
	}
	return &PrivRptPara{W1: Uint16BE(v), W2: Uint16BE(v[2:]), A: v[4],
		W3: Uint32BE(v[5:]), W4: Uint32BE(v[9:])}, nil
}
