package capwap

// Batch-15: upgrade flow + feature/capability private elements,
// field orders from the vendor assemble functions.

// PrivLargeFirmwareInfo is private 0xaf (min=max=0x1d=29):
//
//	u8 type + BE32 pad + BE32 total_size + BE32 md5_offset
//	(restore8 + restore32@+4 + restore32@+8 + restore32@+0x1c)
type PrivLargeFirmwareInfo struct {
	Type      uint8
	TotalSize uint32
	MD5Offset uint32
	Unknown3  uint32 // +0x1c
}

// AssembleValue writes the 29-byte value (header + padding to min/max).
func (p PrivLargeFirmwareInfo) AssembleValue() []byte {
	b := []byte{p.Type}
	b = AppendUint32BE(b, p.TotalSize)
	b = AppendUint32BE(b, p.MD5Offset)
	for len(b) < 29 {
		b = append(b, 0)
	}
	return b
}

// ParsePrivLargeFirmwareInfo decodes the 29-byte value.
func ParsePrivLargeFirmwareInfo(v []byte) (*PrivLargeFirmwareInfo, error) {
	if len(v) != 29 {
		return nil, ErrShortPacket
	}
	return &PrivLargeFirmwareInfo{
		Type:      v[0],
		TotalSize: Uint32BE(v[1:5]),
		MD5Offset: Uint32BE(v[5:9]),
	}, nil
}

// PrivSubFirmwareInfo is private 0xb0 (min=max=0x1a=26):
//
//	u8 type + u8 sub_type + BE32 total_size + BE32 md5_offset
type PrivSubFirmwareInfo struct {
	Type      uint8
	SubType   uint8
	TotalSize uint32
	MD5Offset uint32
}

// AssembleValue writes the 26-byte value.
// Wire: type(0) + sub_type(1) + BE32 total_size + BE32 md5_offset + pad.
func (p PrivSubFirmwareInfo) AssembleValue() []byte {
	b := []byte{p.Type, p.SubType}
	b = AppendUint32BE(b, p.TotalSize)
	b = AppendUint32BE(b, p.MD5Offset)
	for len(b) < 26 {
		b = append(b, 0)
	}
	return b
}

// ParsePrivSubFirmwareInfo decodes the 26-byte value.
// Wire: type(1) + sub_type(1) + BE32 total_size + BE32 md5_offset + pad.
func ParsePrivSubFirmwareInfo(v []byte) (*PrivSubFirmwareInfo, error) {
	if len(v) != 0x1a {
		return nil, ErrShortPacket
	}
	return &PrivSubFirmwareInfo{
		Type:      v[0],
		SubType:   v[1],
		TotalSize: Uint32BE(v[2:6]),
		MD5Offset: Uint32BE(v[6:10]),
	}, nil
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

// PrivApWebAccount is private 0xa9 (min 4 max 0x84):
//
//	BE16 username_len + u8 enabled + u8 pad + username/password
//
// (restore16 + restore8 + restore8; remaining fields carried in Tail).
type PrivApWebAccount struct {
	UserLen uint16
	Enabled uint8
	Pad     uint8
	Tail    []byte
}

// AssembleValue writes header + tail.
func (p PrivApWebAccount) AssembleValue() []byte {
	b := AppendUint16BE(nil, p.UserLen)
	b = append(b, p.Enabled, p.Pad)
	return append(b, p.Tail...)
}

// ParsePrivApWebAccount decodes the header + tail.
func ParsePrivApWebAccount(v []byte) (*PrivApWebAccount, error) {
	if len(v) < 4 {
		return nil, ErrShortPacket
	}
	p := &PrivApWebAccount{UserLen: Uint16BE(v), Enabled: v[2], Pad: v[3]}
	p.Tail = append([]byte(nil), v[4:]...)
	return p, nil
}

// PrivLAGConfig is private 0xa3 (min 3 max 0x17): u8×3
// (cw_priv_lag_config_assemble: restore8×3).
type PrivLAGConfig struct {
	A, B, C uint8
}

// AssembleValue writes the 3 bytes.
func (p PrivLAGConfig) AssembleValue() []byte {
	return []byte{p.A, p.B, p.C}
}

// ParsePrivLAGConfig decodes the 3 bytes.
func ParsePrivLAGConfig(v []byte) (*PrivLAGConfig, error) {
	if len(v) != 3 {
		return nil, ErrShortPacket
	}
	return &PrivLAGConfig{A: v[0], B: v[1], C: v[2]}, nil
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
