package capwap

// Batch-15: upgrade flow + feature/capability private elements,
// field orders from the vendor assemble functions.

// PrivLargeFirmwareInfo (0xaf): type8, total32, sub-image count32,
// MD5[16], flags32. No C structure alignment is present on the wire.
type PrivLargeFirmwareInfo struct {
	Type      uint8
	TotalSize uint32
	SubImages uint32
	MD5       [16]byte
	Flags     uint32
}

func (p PrivLargeFirmwareInfo) AssembleValue() []byte {
	b := AppendUint32BE([]byte{p.Type}, p.TotalSize)
	b = AppendUint32BE(b, p.SubImages)
	b = append(b, p.MD5[:]...)
	return AppendUint32BE(b, p.Flags)
}
func ParsePrivLargeFirmwareInfo(v []byte) (*PrivLargeFirmwareInfo, error) {
	if len(v) != 29 {
		return nil, ErrShortPacket
	}
	p := &PrivLargeFirmwareInfo{Type: v[0], TotalSize: Uint32BE(v[1:]), SubImages: Uint32BE(v[5:]), Flags: Uint32BE(v[25:])}
	copy(p.MD5[:], v[9:25])
	return p, nil
}

// PrivSubFirmwareInfo (0xb0): type8, index8, size32, MD5[16], flags32.
type PrivSubFirmwareInfo struct {
	Type      uint8
	SubType   uint8
	TotalSize uint32
	MD5       [16]byte
	Flags     uint32
}

func (p PrivSubFirmwareInfo) AssembleValue() []byte {
	b := AppendUint32BE([]byte{p.Type, p.SubType}, p.TotalSize)
	b = append(b, p.MD5[:]...)
	return AppendUint32BE(b, p.Flags)
}
func ParsePrivSubFirmwareInfo(v []byte) (*PrivSubFirmwareInfo, error) {
	if len(v) != 26 {
		return nil, ErrShortPacket
	}
	p := &PrivSubFirmwareInfo{Type: v[0], SubType: v[1], TotalSize: Uint32BE(v[2:]), Flags: Uint32BE(v[22:])}
	copy(p.MD5[:], v[6:22])
	return p, nil
}

// PrivSubFirmwareAction is private 0xb1 (min=max=6):
//
//	u8 type + u8 sub_type + BE32 action
type PrivSubFirmwareAction struct {
	Type    uint8
	SubType uint8
	Action  uint32
}

// AssembleValue writes the 6 bytes.
func (p PrivSubFirmwareAction) AssembleValue() []byte {
	b := []byte{p.Type, p.SubType}
	return AppendUint32BE(b, p.Action)
}

// ParsePrivSubFirmwareAction decodes the 6 bytes.
func ParsePrivSubFirmwareAction(v []byte) (*PrivSubFirmwareAction, error) {
	if len(v) != 6 {
		return nil, ErrShortPacket
	}
	return &PrivSubFirmwareAction{
		Type: v[0], SubType: v[1], Action: Uint32BE(v[2:6]),
	}, nil
}

// PrivApWebAccount is private 0xa9: BE16 encryption algorithm, username
// length8, password length8, then both strings. V6 assembler @0x6ae024.
type PrivApWebAccount struct {
	Algorithm uint16
	Username  []byte
	Password  []byte
}

// AssembleValue writes header + tail.
func (p PrivApWebAccount) AssembleValue() []byte {
	b := AppendUint16BE(nil, p.Algorithm)
	b = append(b, byte(len(p.Username)), byte(len(p.Password)))
	b = append(b, p.Username...)
	return append(b, p.Password...)
}

// ParsePrivApWebAccount decodes the header + tail.
func ParsePrivApWebAccount(v []byte) (*PrivApWebAccount, error) {
	if len(v) < 4 || len(v) > 132 || int(v[2])+int(v[3])+4 != len(v) {
		return nil, ErrShortPacket
	}
	p := &PrivApWebAccount{Algorithm: Uint16BE(v), Username: append([]byte{}, v[4:4+int(v[2])]...), Password: append([]byte{}, v[4+int(v[2]):]...)}
	return p, nil
}

// PrivLAGConfig is private 0xa3 (min 3 max 0x17): u8×3
// (cw_priv_lag_config_assemble: restore8×3).
type PrivLAGConfig struct {
	A, B, C uint8
	Ports   []byte
}

// AssembleValue writes the 3 bytes.
func (p PrivLAGConfig) AssembleValue() []byte {
	return append([]byte{p.A, p.B, byte(len(p.Ports))}, p.Ports...)
}

// ParsePrivLAGConfig decodes the 3 bytes.
func ParsePrivLAGConfig(v []byte) (*PrivLAGConfig, error) {
	if len(v) < 3 || len(v) > 23 || int(v[2])+3 != len(v) {
		return nil, ErrShortPacket
	}
	return &PrivLAGConfig{A: v[0], B: v[1], C: v[2], Ports: append([]byte{}, v[3:]...)}, nil
}

// PrivFitFatButtonStatus is private 0xa4 (min=max=4): BE32
// (cw_priv_fit_fat_button_status_assemble: single restore32).
type PrivFitFatButtonStatus uint32

// AssembleValue writes the 4 bytes.
func (p PrivFitFatButtonStatus) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivFitFatButtonStatus decodes the 4 bytes.
func ParsePrivFitFatButtonStatus(v []byte) (PrivFitFatButtonStatus, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivFitFatButtonStatus(Uint32BE(v)), nil
}

// Priv11axFeatureDefaults is private 0xb2 (min=max=9): u8×9
// (cw_priv_11ax_feature_default_value_assemble: restore8×9).
type Priv11axFeatureDefaults [9]byte

// AssembleValue returns the 9 bytes.
func (p Priv11axFeatureDefaults) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParsePriv11axFeatureDefaults decodes the 9 bytes.
func ParsePriv11axFeatureDefaults(v []byte) (Priv11axFeatureDefaults, error) {
	var out Priv11axFeatureDefaults
	if len(v) != 9 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}
