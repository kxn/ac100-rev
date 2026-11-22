package capwap

// Batch-12: remaining standard elements (lengths per elements.tsv; field
// orders from the vendor assemble functions).

// AppendCapwapControlIPv6Address is element 0x000b (min=max=12): verbatim
// 12-byte value (addr-family prefix + 10-byte tail; vendor uses a single
// restore16 in the visible path, full 12B is the table length).
type CapwapControlIPv6Address [12]byte

// AssembleValue returns the 12 bytes.
func (p CapwapControlIPv6Address) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParseCapwapControlIPv6Address decodes the 12 bytes.
func ParseCapwapControlIPv6Address(v []byte) (CapwapControlIPv6Address, error) {
	var out CapwapControlIPv6Address
	if len(v) != 12 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// AppendWTPTunnelMode is element 0x0029 (min=max=1): u8.
func AppendWTPTunnelMode(dst []byte, mode uint8) []byte {
	return AppendElement(dst, 0x0029, []byte{mode})
}

// ParseWTPTunnelMode decodes element 0x0029.
func ParseWTPTunnelMode(v []byte) (uint8, error) {
	if len(v) != 1 {
		return 0, ErrShortPacket
	}
	return v[0], nil
}

// WTPTunnelMode values (cw_wtp_frame_tunnel_mode_dump: "local bridging"
// / "802.3 tunnel" / "802.11 tunnel").
const (
	TunnelModeLocalBridging uint8 = 0
	TunnelMode8023          uint8 = 1
	TunnelMode80211         uint8 = 2
)

// WTPRadioStatistics is element 0x002f (min=max=20):
// u8 radio_id + u8 + BE16×9
// (cw_wtp_radio_statistics_assemble: restore8 + restore8 + restore16×9
// from +2..+0x11 — the 18-byte BE16 block covers the full 20 with the two
// leading u8s).
type WTPRadioStatistics struct {
	RadioID uint8
	B       uint8
	W       [9]uint16
}

// AssembleValue writes the 20 bytes.
func (p WTPRadioStatistics) AssembleValue() []byte {
	b := []byte{p.RadioID, p.B}
	for _, w := range p.W {
		b = AppendUint16BE(b, w)
	}
	return b
}

// ParseWTPRadioStatistics decodes the 20 bytes.
func ParseWTPRadioStatistics(v []byte) (*WTPRadioStatistics, error) {
	if len(v) != 20 {
		return nil, ErrShortPacket
	}
	p := &WTPRadioStatistics{RadioID: v[0], B: v[1]}
	for i := 0; i < 9; i++ {
		p.W[i] = Uint16BE(v[2+i*2:])
	}
	return p, nil
}

// WTPRebootStatistics is element 0x0030 (min=max=15):
// BE16×7 + u8
// (cw_wtp_reboot_statistics_assemble: restore16×7 + restore8).
type WTPRebootStatistics struct {
	W [7]uint16
	B uint8
}

// AssembleValue writes the 15 bytes.
func (p WTPRebootStatistics) AssembleValue() []byte {
	var b []byte
	for _, w := range p.W {
		b = AppendUint16BE(b, w)
	}
	return append(b, p.B)
}

// ParseWTPRebootStatistics decodes the 15 bytes.
func ParseWTPRebootStatistics(v []byte) (*WTPRebootStatistics, error) {
	if len(v) != 15 {
		return nil, ErrShortPacket
	}
	var p WTPRebootStatistics
	for i := 0; i < 7; i++ {
		p.W[i] = Uint16BE(v[i*2:])
	}
	p.B = v[14]
	return &p, nil
}

// WTPStaticIPInfo is element 0x0031 (min=max=13):
// BE32×3 + u8
// (cw_wtp_static_ip_address_information_assemble: restore32×3 + restore8).
type WTPStaticIPInfo struct {
	IP      uint32
	Netmask uint32
	Gateway uint32
	Mode    uint8
}

// AssembleValue writes the 13 bytes.
func (p WTPStaticIPInfo) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.IP)
	b = AppendUint32BE(b, p.Netmask)
	b = AppendUint32BE(b, p.Gateway)
	return append(b, p.Mode)
}

// ParseWTPStaticIPInfo decodes the 13 bytes.
func ParseWTPStaticIPInfo(v []byte) (*WTPStaticIPInfo, error) {
	if len(v) != 13 {
		return nil, ErrShortPacket
	}
	return &WTPStaticIPInfo{
		IP: Uint32BE(v), Netmask: Uint32BE(v[4:]), Gateway: Uint32BE(v[8:]),
		Mode: v[12],
	}, nil
}

// AppendWTPCapabilityFlag is element 0x0032 (min=max=4): BE32
// (cw_wtp_capability_flag_assemble: single restore32).
func AppendWTPCapabilityFlag(dst []byte, flags uint32) []byte {
	return AppendElement(dst, 0x0032, AppendUint32BE(nil, flags))
}

// ParseWTPCapabilityFlag decodes element 0x0032.
func ParseWTPCapabilityFlag(v []byte) (uint32, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return Uint32BE(v), nil
}

// StaRSSI is element 0x0033 (min 5 max 0x400):
// u8 radio_id + BE32 count + count × {BE32 + N × …}
// (cw_sta_rssi_assemble: restore8 radio + restore32 count + per-sta blocks;
// per-sta body is vendor-specific and carried verbatim in the tail).
type StaRSSI struct {
	RadioID uint8
	Count   uint32
	Body    []byte // verbatim per-sta blocks (min = 5 ⇒ header 5 + body)
}

// AssembleValue writes header + body.
func (p StaRSSI) AssembleValue() []byte {
	b := []byte{p.RadioID}
	b = AppendUint32BE(b, p.Count)
	return append(b, p.Body...)
}

// ParseStaRSSI decodes the header; body carried verbatim.
func ParseStaRSSI(v []byte) (*StaRSSI, error) {
	if len(v) < 5 || v[0] >= 0x20 {
		return nil, ErrShortPacket
	}
	p := &StaRSSI{RadioID: v[0], Count: Uint32BE(v[1:])}
	p.Body = append([]byte(nil), v[5:]...)
	return p, nil
}
