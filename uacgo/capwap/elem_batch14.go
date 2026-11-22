package capwap

// Batch-14: remaining private elements with clear layouts.

// PrivApSpectral is element 0x3a (min=max=4): u8×4
// (cw_priv_ap_spectral_assemble: restore8×4).
type PrivApSpectral [4]byte

// AssembleValue returns the 4 bytes.
func (p PrivApSpectral) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParsePrivApSpectral decodes the 4 bytes.
func ParsePrivApSpectral(v []byte) (PrivApSpectral, error) {
	var out PrivApSpectral
	if len(v) != 4 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// PrivSpecRSSI is element 0x3e (min=max=4): BE32
// (cw_priv_spec_rssi_assemble: single restore32).
type PrivSpecRSSI uint32

// AssembleValue writes the 4 bytes.
func (p PrivSpecRSSI) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivSpecRSSI decodes the 4 bytes.
func ParsePrivSpecRSSI(v []byte) (PrivSpecRSSI, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivSpecRSSI(Uint32BE(v)), nil
}

// PrivMacFilter is element 0x3f (min 8 max 0x2800):
// BE32 count + u8 a + u8 b + BE16 + MAC block (count*6 bytes,
// even-padded). cw_priv_mac_filter_assemble.
type PrivMacFilter struct {
	Count uint32
	A     uint8
	B     uint8
	C     uint16
	MACs  []byte // count*6 bytes (even-padded)
}

// AssembleValue writes header + MAC block.
func (p PrivMacFilter) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.Count)
	b = append(b, p.A, p.B)
	b = AppendUint16BE(b, p.C)
	return append(b, p.MACs...)
}

// ParsePrivMacFilter decodes header + MAC block.
func ParsePrivMacFilter(v []byte) (*PrivMacFilter, error) {
	if len(v) < 8 {
		return nil, ErrShortPacket
	}
	p := &PrivMacFilter{Count: Uint32BE(v), A: v[4], B: v[5], C: Uint16BE(v[6:])}
	off := 8
	macLen := int(p.Count) * 6
	if macLen%2 != 0 {
		macLen++
	}
	if off+macLen > len(v) {
		return nil, ErrShortPacket
	}
	p.MACs = append([]byte(nil), v[off:off+macLen]...)
	return p, nil
}

// PrivSilenceParams is element 0x9d (min=max=3): u8 + BE16
// (cw_priv_set_silence_params_assemble: restore8 + restore16).
type PrivSilenceParams struct {
	A uint8
	B uint16
}

// AssembleValue writes the 3 bytes.
func (p PrivSilenceParams) AssembleValue() []byte {
	return AppendUint16BE([]byte{p.A}, p.B)
}

// ParsePrivSilenceParams decodes the 3 bytes.
func ParsePrivSilenceParams(v []byte) (*PrivSilenceParams, error) {
	if len(v) != 3 {
		return nil, ErrShortPacket
	}
	return &PrivSilenceParams{A: v[0], B: Uint16BE(v[1:])}, nil
}
