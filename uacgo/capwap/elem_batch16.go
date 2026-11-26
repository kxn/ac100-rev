package capwap

// Batch-16: remaining private station/session elements.
// All field orders from the vendor parse functions (grep'd retrieve sequences).

// StaAuthReq is private 0x01: radio, WLAN, MAC, BE32 backfill length,
// then opaque bytes. V6 cw_priv_sta_auth_req_parse @0x6a9fc8.
type StaAuthReq struct {
	Radio    uint8
	WlanID   uint8
	MAC      [6]byte
	Backfill []byte
}

func (s StaAuthReq) AssembleValue() []byte {
	b := append([]byte{s.Radio, s.WlanID}, s.MAC[:]...)
	b = AppendUint32BE(b, uint32(len(s.Backfill)))
	return append(b, s.Backfill...)
}
func ParseStaAuthReq(v []byte) (*StaAuthReq, error) {
	if len(v) < 12 || v[0] >= 32 || v[1] > 16 {
		return nil, ErrShortPacket
	}
	if uint64(Uint32BE(v[8:])) != uint64(len(v)-12) {
		return nil, ErrLenMismatch
	}
	s := &StaAuthReq{Radio: v[0], WlanID: v[1], Backfill: append([]byte{}, v[12:]...)}
	copy(s.MAC[:], v[2:8])
	return s, nil
}

// StaAssocReq shares the authoritative legacy 0x02 parser. The old CapInfo /
// trailing VLAN interpretation was incorrect: the word is optional RSSI and
// the following word is the length of an opaque backfill.
type StaAssocReq = LegacyAssociation

func ParseStaAssocReq(v []byte) (*StaAssocReq, error) { return ParseLegacyAssociation(v) }

// StaDeassoc is priv 0x03 (min=max=8): radio + wlan_id + MAC
// (cw_priv_sta_deassoc_parse).
type StaDeassoc struct {
	Radio  uint8
	WlanID uint8
	MAC    [6]byte
}

// AssembleValue writes the 8 bytes.
func (s StaDeassoc) AssembleValue() []byte {
	b := []byte{s.Radio, s.WlanID}
	return append(b, s.MAC[:]...)
}

// ParseStaDeassoc decodes the 8 bytes.
func ParseStaDeassoc(v []byte) (*StaDeassoc, error) {
	if len(v) != 8 {
		return nil, ErrShortPacket
	}
	s := &StaDeassoc{Radio: v[0], WlanID: v[1]}
	copy(s.MAC[:], v[2:8])
	return s, nil
}

// StaAuthResult is private 0x04/0x13: radio, WLAN, MAC, BE32 result,
// BE32 backfill length and backfill. V6 cw_priv_sta_auth_rslt_parse @0x6a17a4.
type StaAuthResult struct {
	Radio    uint8
	WlanID   uint8
	MAC      [6]byte
	Result   uint32
	Backfill []byte
}

func (s StaAuthResult) AssembleValue() []byte {
	return (LegacyAssociation{Radio: s.Radio, WLAN: s.WlanID, MAC: s.MAC, Backfill: s.Backfill}).Result(s.Result)
}
func ParseStaAuthResult(v []byte) (*StaAuthResult, error) {
	if len(v) < 16 || v[0] >= 32 || v[1] > 16 {
		return nil, ErrShortPacket
	}
	if uint64(Uint32BE(v[12:])) != uint64(len(v)-16) {
		return nil, ErrLenMismatch
	}
	s := &StaAuthResult{Radio: v[0], WlanID: v[1], Result: Uint32BE(v[8:]), Backfill: append([]byte{}, v[16:]...)}
	copy(s.MAC[:], v[2:8])
	return s, nil
}

// ChnlState is priv 0x06 (min=max=2): radio + state
// (cw_priv_ch_state_parse: retrieve8×2).
type ChnlState struct {
	Radio uint8
	State uint8
}

// AssembleValue writes the 2 bytes.
func (c ChnlState) AssembleValue() []byte { return []byte{c.Radio, c.State} }

// ParseChnlState decodes the 2 bytes.
func ParseChnlState(v []byte) (*ChnlState, error) {
	if len(v) != 2 {
		return nil, ErrShortPacket
	}
	return &ChnlState{Radio: v[0], State: v[1]}, nil
}

// PwrState is priv 0x07 (min=max=2): radio + power state.
type PwrState struct {
	Radio uint8
	State uint8
}

// AssembleValue writes the 2 bytes.
func (p PwrState) AssembleValue() []byte { return []byte{p.Radio, p.State} }

// ParsePwrState decodes the 2 bytes.
func ParsePwrState(v []byte) (*PwrState, error) {
	if len(v) != 2 {
		return nil, ErrShortPacket
	}
	return &PwrState{Radio: v[0], State: v[1]}, nil
}

// StaDiscovery is priv 0x0b (min=max=8): radio + wlan_id + MAC
// (cw_priv_sta_dis_parse: same shape as deassoc).
type StaDiscovery struct {
	Radio  uint8
	WlanID uint8
	MAC    [6]byte
}

// AssembleValue writes the 8 bytes.
func (s StaDiscovery) AssembleValue() []byte {
	b := []byte{s.Radio, s.WlanID}
	return append(b, s.MAC[:]...)
}

// ParseStaDiscovery decodes the 8 bytes.
func ParseStaDiscovery(v []byte) (*StaDiscovery, error) {
	if len(v) != 8 {
		return nil, ErrShortPacket
	}
	s := &StaDiscovery{Radio: v[0], WlanID: v[1]}
	copy(s.MAC[:], v[2:8])
	return s, nil
}

// ClearState is priv 0x0d (min=max=4): BE32
// (cw_priv_clr_stat_parse: retrieve32).
type ClearState uint32

// AssembleValue writes the 4 bytes.
func (c ClearState) AssembleValue() []byte { return AppendUint32BE(nil, uint32(c)) }

// ParseClearState decodes the 4 bytes.
func ParseClearState(v []byte) (ClearState, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return ClearState(Uint32BE(v)), nil
}

// FrameStat is priv 0x0e (min=max=0x7c): u8 radio + 3B + BE32×30 = 124
// (cw_priv_frame_stat_parse @0x5b1c68: retrieve8 + retrieve_bytes(3) +
// 30×retrieve32).
type FrameStat struct {
	Radio uint8
	Rsvd  [3]byte
	W     [30]uint32
}

// AssembleValue writes the 124 bytes.
func (p FrameStat) AssembleValue() []byte {
	b := []byte{p.Radio}
	b = append(b, p.Rsvd[:]...)
	for _, w := range p.W {
		b = AppendUint32BE(b, w)
	}
	return b
}

// ParseFrameStat decodes the 124 bytes.
func ParseFrameStat(v []byte) (*FrameStat, error) {
	if len(v) != 124 {
		return nil, ErrShortPacket
	}
	p := &FrameStat{Radio: v[0]}
	copy(p.Rsvd[:], v[1:4])
	for i := 0; i < 30; i++ {
		p.W[i] = Uint32BE(v[4+i*4:])
	}
	return p, nil
}

// SnMD5 is priv 0x12 (min=max=0x20): two 16-byte blocks.
// (cw_priv_sn_md5_parse: retrieve_bytes 0x10 + 0x10.)
type SnMD5 struct {
	SN  [16]byte
	MD5 [16]byte
}

// AssembleValue writes the 32 bytes.
func (s SnMD5) AssembleValue() []byte {
	b := append([]byte(nil), s.SN[:]...)
	return append(b, s.MD5[:]...)
}

// ParseSnMD5 decodes the 32 bytes.
func ParseSnMD5(v []byte) (*SnMD5, error) {
	if len(v) != 32 {
		return nil, ErrShortPacket
	}
	s := &SnMD5{}
	copy(s.SN[:], v[:16])
	copy(s.MD5[:], v[16:])
	return s, nil
}

// TransDataRequest is priv 0x14 (min=max=4): BE16 + BE16
// (cw_priv_trans_data_request_parse).
type TransDataRequest struct {
	A uint16
	B uint16
}

// AssembleValue writes the 4 bytes.
func (t TransDataRequest) AssembleValue() []byte {
	b := AppendUint16BE(nil, t.A)
	return AppendUint16BE(b, t.B)
}

// ParseTransDataRequest decodes the 4 bytes.
func ParseTransDataRequest(v []byte) (*TransDataRequest, error) {
	if len(v) != 4 {
		return nil, ErrShortPacket
	}
	return &TransDataRequest{A: Uint16BE(v), B: Uint16BE(v[2:])}, nil
}

// PrivExcept is priv 0x1a (min=max=0x18): BE32 + BE32 + MAC(6) + BE32 + MAC(6)
// (cw_priv_except_parse: retrieve32 + retrieve32 + 6B + retrieve32 + 6B).
type PrivExcept struct {
	W1   uint32
	W2   uint32
	MAC1 [6]byte
	W3   uint32
	MAC2 [6]byte
}

// AssembleValue writes the 24 bytes.
func (p PrivExcept) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.W1)
	b = AppendUint32BE(b, p.W2)
	b = append(b, p.MAC1[:]...)
	b = AppendUint32BE(b, p.W3)
	return append(b, p.MAC2[:]...)
}

// ParsePrivExcept decodes the 24 bytes.
func ParsePrivExcept(v []byte) (*PrivExcept, error) {
	if len(v) != 24 {
		return nil, ErrShortPacket
	}
	p := &PrivExcept{W1: Uint32BE(v), W2: Uint32BE(v[4:]), W3: Uint32BE(v[16:])}
	copy(p.MAC1[:], v[8:14])
	copy(p.MAC2[:], v[18:24])
	return p, nil
}
