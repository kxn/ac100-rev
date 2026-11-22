package capwap

// Batch-17: remaining private elements (simple layouts from vendor
// assemble sequences).

// PrivImageUpdateResult is 0x1c (min=max=4): BE32.
type PrivImageUpdateResult uint32

// AssembleValue writes the 4 bytes.
func (p PrivImageUpdateResult) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivImageUpdateResult decodes the 4 bytes.
func ParsePrivImageUpdateResult(v []byte) (PrivImageUpdateResult, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivImageUpdateResult(Uint32BE(v)), nil
}

// PrivDataTunnelMode is 0x1d (min=max=4): BE32.
type PrivDataTunnelMode uint32

// AssembleValue writes the 4 bytes.
func (p PrivDataTunnelMode) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivDataTunnelMode decodes the 4 bytes.
func ParsePrivDataTunnelMode(v []byte) (PrivDataTunnelMode, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivDataTunnelMode(Uint32BE(v)), nil
}

// PrivAp11acRate is 0x2b (min=max=4): u8×4.
type PrivAp11acRate [4]byte

// AssembleValue returns the 4 bytes.
func (p PrivAp11acRate) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParsePrivAp11acRate decodes the 4 bytes.
func ParsePrivAp11acRate(v []byte) (PrivAp11acRate, error) {
	var out PrivAp11acRate
	if len(v) != 4 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// PrivBcastStormCtrl is 0x46 (min=max=5): u8 + BE32.
type PrivBcastStormCtrl struct {
	A     uint8
	Limit uint32
}

// AssembleValue writes the 5 bytes.
func (p PrivBcastStormCtrl) AssembleValue() []byte {
	return AppendUint32BE([]byte{p.A}, p.Limit)
}

// ParsePrivBcastStormCtrl decodes the 5 bytes.
func ParsePrivBcastStormCtrl(v []byte) (*PrivBcastStormCtrl, error) {
	if len(v) != 5 {
		return nil, ErrShortPacket
	}
	return &PrivBcastStormCtrl{A: v[0], Limit: Uint32BE(v[1:])}, nil
}

// PrivWlanRSSIOrient is 0x4c (min=max=8): BE32 + BE16 + u8×2
// (cw_priv_wlan_rssi_orient_parse @0x5cbd78: r32 r16 r8 r8).
type PrivWlanRSSIOrient struct {
	W   uint32
	U16 uint16
	A   uint8
	B   uint8
}

// AssembleValue writes the 8 bytes.
func (p PrivWlanRSSIOrient) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.W)
	b = AppendUint16BE(b, p.U16)
	return append(b, p.A, p.B)
}

// ParsePrivWlanRSSIOrient decodes the 9 bytes.
func ParsePrivWlanRSSIOrient(v []byte) (*PrivWlanRSSIOrient, error) {
	if len(v) != 8 {
		return nil, ErrShortPacket
	}
	return &PrivWlanRSSIOrient{W: Uint32BE(v), U16: Uint16BE(v[4:]), A: v[6], B: v[7]}, nil
}
