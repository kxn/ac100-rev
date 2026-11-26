package capwap

// Batch-20: previously unported private elements. Layouts from the vendor
// parse functions' retrieve sequences (lengths of rbytes confirmed from
// the retrieve_bytes a2 argument; loops confirmed from the loop counters).

// PrivDeleteImplicitlyLeaveStation is 0x5a (min 8 max 10)
// (cw_priv_delete_implicitly_leave_station_parse @0x5af5bc:
// r8 r8 rraw). {u8, u8, rest raw}.
type PrivDeleteImplicitlyLeaveStation struct {
	A    uint8
	B    uint8
	Rest []byte
}

// AssembleValue writes header + rest.
func (p PrivDeleteImplicitlyLeaveStation) AssembleValue() []byte {
	return append([]byte{p.A, p.B}, p.Rest...)
}

// ParsePrivDeleteImplicitlyLeaveStation decodes header + rest.
func ParsePrivDeleteImplicitlyLeaveStation(v []byte) (*PrivDeleteImplicitlyLeaveStation, error) {
	if len(v) < 8 {
		return nil, ErrShortPacket
	}
	return &PrivDeleteImplicitlyLeaveStation{A: v[0], B: v[1],
		Rest: append([]byte(nil), v[2:]...)}, nil
}

// PrivNdpPara is 0x5c (min 0x14 max 0x34) (cw_priv_ndp_para_parse
// @0x5b7c44: rbytes(6) r8 r8 r16 r16 r16 r16 r8 r8 r8 r8 rbytes).
type PrivNdpPara struct {
	MAC  [6]byte
	U8a  uint8
	U8b  uint8
	W1   uint16
	W2   uint16
	W3   uint16
	W4   uint16
	U8c  uint8
	U8d  uint8
	U8e  uint8
	U8f  uint8
	Tail []byte
}

// AssembleValue writes the fixed 20 bytes + tail.
func (p PrivNdpPara) AssembleValue() []byte {
	b := append([]byte(nil), p.MAC[:]...)
	b = append(b, p.U8a, p.U8b)
	b = AppendUint16BE(b, p.W1)
	b = AppendUint16BE(b, p.W2)
	b = AppendUint16BE(b, p.W3)
	b = AppendUint16BE(b, p.W4)
	b = append(b, p.U8c, p.U8d, p.U8e, p.U8f)
	return append(b, p.Tail...)
}

// ParsePrivNdpPara decodes the 20-byte header + tail.
func ParsePrivNdpPara(v []byte) (*PrivNdpPara, error) {
	if len(v) < 20 {
		return nil, ErrShortPacket
	}
	p := &PrivNdpPara{U8a: v[6], U8b: v[7],
		W1: Uint16BE(v[8:]), W2: Uint16BE(v[10:]),
		W3: Uint16BE(v[12:]), W4: Uint16BE(v[14:]),
		U8c: v[16], U8d: v[17], U8e: v[18], U8f: v[19]}
	copy(p.MAC[:], v[:6])
	p.Tail = append([]byte(nil), v[20:]...)
	return p, nil
}

// V6 cw_priv_rrm_neighs_list_parse @0x692d54: a neighbor contains
// an AP MAC, flags, and a counted list of {radio,power,RSSI}. It is not a
// fixed 11-byte record (that only happens for a single RSSI sample).
type RrmRSSI struct {
	Radio uint8 `json:"radio_id"`
	Power int8  `json:"power_dbm"`
	RSSI  int8  `json:"rssi_dbm"`
}
type RrmNeigh struct {
	MAC     [6]byte   `json:"mac"`
	Flags   uint8     `json:"flags"`
	Samples []RrmRSSI `json:"samples"`
}
type PrivRrmNeighsList struct {
	A      uint8
	B      uint8
	Neighs []RrmNeigh
}

func (p PrivRrmNeighsList) AssembleValue() []byte {
	b := AppendUint16BE([]byte{p.A, p.B}, uint16(len(p.Neighs)))
	for _, n := range p.Neighs {
		b = append(b, n.MAC[:]...)
		b = append(b, n.Flags, byte(len(n.Samples)))
		for _, r := range n.Samples {
			b = append(b, r.Radio, byte(r.Power), byte(r.RSSI))
		}
	}
	return b
}
func ParsePrivRrmNeighsList(v []byte) (*PrivRrmNeighsList, error) {
	if len(v) < 4 || v[0] >= 32 {
		return nil, ErrShortPacket
	}
	count := Uint16BE(v[2:])
	if count > 32 {
		return nil, ErrShortPacket
	}
	p := &PrivRrmNeighsList{A: v[0], B: v[1]}
	v = v[4:]
	for i := 0; i < int(count); i++ {
		if len(v) < 8 {
			return nil, ErrShortPacket
		}
		var n RrmNeigh
		copy(n.MAC[:], v)
		n.Flags = v[6]
		samples := int(v[7])
		v = v[8:]
		if len(v) < samples*3 {
			return nil, ErrShortPacket
		}
		for j := 0; j < samples; j++ {
			n.Samples = append(n.Samples, RrmRSSI{Radio: v[0], Power: int8(v[1]), RSSI: int8(v[2])})
			v = v[3:]
		}
		p.Neighs = append(p.Neighs, n)
	}
	if len(v) != 0 {
		return nil, ErrShortPacket
	}
	return p, nil
}

// PrivApLog is 0x5f (min 2): r16 + r8 + r8 + r16 + rest raw
// (cw_priv_ap_log_parse @0x5a5c08).
type PrivApLog struct {
	W    uint16
	A    uint8
	B    uint8
	W2   uint16
	Rest []byte
}

// AssembleValue writes header + rest.
func (p PrivApLog) AssembleValue() []byte {
	b := AppendUint16BE(nil, p.W)
	b = append(b, p.A, p.B)
	b = AppendUint16BE(b, p.W2)
	return append(b, p.Rest...)
}

// ParsePrivApLog decodes header + rest.
func ParsePrivApLog(v []byte) (*PrivApLog, error) {
	if len(v) < 6 {
		return nil, ErrShortPacket
	}
	return &PrivApLog{W: Uint16BE(v), A: v[2], B: v[3], W2: Uint16BE(v[4:]),
		Rest: append([]byte(nil), v[6:]...)}, nil
}

// PrivApLogReportPara is 0x60 (min 0xd max 0x19): r8×4 + rip + r32
// (cw_priv_ap_log_report_para_parse @0x5a64b4).
type PrivApLogReportPara struct {
	A, B, C, D uint8
	IP         [4]byte
	W          uint32
}

// AssembleValue writes the 12-byte header.
func (p PrivApLogReportPara) AssembleValue() []byte {
	return append([]byte{p.A, p.B, p.C, p.D}, append(append([]byte(nil), p.IP[:]...),
		AppendUint32BE(nil, p.W)...)...)
}

// ParsePrivApLogReportPara decodes the 12-byte header.
func ParsePrivApLogReportPara(v []byte) (*PrivApLogReportPara, error) {
	if len(v) < 12 {
		return nil, ErrShortPacket
	}
	p := &PrivApLogReportPara{A: v[0], B: v[1], C: v[2], D: v[3],
		W: Uint32BE(v[8:])}
	copy(p.IP[:], v[4:8])
	return p, nil
}

// PrivDhcpv6Defend is 0x61 (min 6): r8 r8 r32 r8 rbytes — same shape as
// 0x47 dhcp defend (cw_priv_dhcpv6_defend_parse @0x5b036c).
type PrivDhcpv6Defend struct {
	Enable uint8
	Count  uint8
	SvrLen uint32
	Tail   []byte
}

// AssembleValue writes header + tail.
func (p PrivDhcpv6Defend) AssembleValue() []byte {
	b := []byte{p.Enable, p.Count}
	b = AppendUint32BE(b, p.SvrLen)
	return append(b, p.Tail...)
}

// ParsePrivDhcpv6Defend decodes header + tail.
func ParsePrivDhcpv6Defend(v []byte) (*PrivDhcpv6Defend, error) {
	if !validDefendLength(v, 17) {
		return nil, ErrShortPacket
	}
	return &PrivDhcpv6Defend{Enable: v[0], Count: v[1],
		SvrLen: Uint32BE(v[2:]), Tail: append([]byte(nil), v[6:]...)}, nil
}

// PrivNdDefend is 0x62 (min 6): r8 r8 r32 rbytes(16) rbytes(6)
// (cw_priv_nd_defend_parse @0x5b73dc).
type PrivNdDefend struct {
	Enable uint8
	Count  uint8
	W      uint32
	Tail   []byte // entry bytes: 16B block + 6B mac groups
}

// AssembleValue writes header + tail.
func (p PrivNdDefend) AssembleValue() []byte {
	b := []byte{p.Enable, p.Count}
	b = AppendUint32BE(b, p.W)
	return append(b, p.Tail...)
}

// ParsePrivNdDefend decodes header + tail.
func ParsePrivNdDefend(v []byte) (*PrivNdDefend, error) {
	if !validDefendLength(v, 22) {
		return nil, ErrShortPacket
	}
	return &PrivNdDefend{Enable: v[0], Count: v[1],
		W: Uint32BE(v[2:]), Tail: append([]byte(nil), v[6:]...)}, nil
}

// PrivApWorkingChannelList is 0x66 (min=max=0x18): 6×BE32
// (cw_priv_ap_working_channel_list_parse @0x5aadd0; the r32 retrieve sits
// in a loop bounded by the literal 24).
type PrivApWorkingChannelList [6]uint32

// AssembleValue writes the 24 bytes.
func (p PrivApWorkingChannelList) AssembleValue() []byte {
	var b []byte
	for _, w := range p {
		b = AppendUint32BE(b, w)
	}
	return b
}

// ParsePrivApWorkingChannelList decodes the 24 bytes.
func ParsePrivApWorkingChannelList(v []byte) (PrivApWorkingChannelList, error) {
	var out PrivApWorkingChannelList
	if len(v) != 24 {
		return out, ErrShortPacket
	}
	for i := 0; i < 6; i++ {
		out[i] = Uint32BE(v[i*4:])
	}
	return out, nil
}
