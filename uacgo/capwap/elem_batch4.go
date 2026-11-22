package capwap

// Batch-4 fixed-length private elements. Lengths validated against the
// element table (elements.tsv min/max); field orders from the vendor
// assemble functions (grep'd restore sequences).

// PrivApWireVlan is element 0x30 (min=max=4): one BE32
// (cw_priv_ap_wire_vlan_assemble: single restore32).
type PrivApWireVlan uint32

// AssembleValue writes the 4 bytes.
func (p PrivApWireVlan) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivApWireVlan decodes the 4 bytes.
func ParsePrivApWireVlan(v []byte) (PrivApWireVlan, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivApWireVlan(Uint32BE(v)), nil
}

// PrivApWireVlan2 is element 0x43 (min=max=8): four BE16 VLAN ids
// (cw_priv_ap_wire_vlan_2_assemble @0x5aa8dc, restore16 loop).
type PrivApWireVlan2 struct {
	Vlans [4]uint16
}

// AssembleValue writes the 8 bytes.
func (p PrivApWireVlan2) AssembleValue() []byte {
	var b []byte
	for _, v := range p.Vlans {
		b = AppendUint16BE(b, v)
	}
	return b
}

// ParsePrivApWireVlan2 decodes the 8 bytes.
func ParsePrivApWireVlan2(v []byte) (*PrivApWireVlan2, error) {
	if len(v) != 8 {
		return nil, ErrShortPacket
	}
	var p PrivApWireVlan2
	for i := 0; i < 4; i++ {
		p.Vlans[i] = Uint16BE(v[i*2:])
	}
	return &p, nil
}

// PrivApTrunk is element 0x44 (min=max=4): one BE32
// (cw_priv_ap_trunk_assemble: single restore32).
type PrivApTrunk uint32

// AssembleValue writes the 4 bytes.
func (p PrivApTrunk) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivApTrunk decodes the 4 bytes.
func ParsePrivApTrunk(v []byte) (PrivApTrunk, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivApTrunk(Uint32BE(v)), nil
}

// PrivApSwitchLink is element 0x40 (min=max=4): one BE32
// (cw_priv_ap_switch_link_assemble: single restore32).
type PrivApSwitchLink uint32

// AssembleValue writes the 4 bytes.
func (p PrivApSwitchLink) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivApSwitchLink decodes the 4 bytes.
func ParsePrivApSwitchLink(v []byte) (PrivApSwitchLink, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivApSwitchLink(Uint32BE(v)), nil
}

// PrivWorkingChannelList is element 0x66 (min=max=24): six BE32 words
// (cw_priv_ap_working_channel_list_assemble @0x5aac60, restore32 loop).
type PrivWorkingChannelList struct {
	Words [6]uint32
}

// AssembleValue writes the 24 bytes.
func (p PrivWorkingChannelList) AssembleValue() []byte {
	var b []byte
	for _, w := range p.Words {
		b = AppendUint32BE(b, w)
	}
	return b
}

// ParsePrivWorkingChannelList decodes the 24 bytes.
func ParsePrivWorkingChannelList(v []byte) (*PrivWorkingChannelList, error) {
	if len(v) != 24 {
		return nil, ErrShortPacket
	}
	var p PrivWorkingChannelList
	for i := 0; i < 6; i++ {
		p.Words[i] = Uint32BE(v[i*4:])
	}
	return &p, nil
}

// PrivTelnetConfig is element 0x9f (min=max=3): u8 + BE16
// (cw_priv_telnet_config_assemble: restore8 then restore16).
type PrivTelnetConfig struct {
	Enable uint8
	Port   uint16
}

// AssembleValue writes the 3 bytes.
func (p PrivTelnetConfig) AssembleValue() []byte {
	return AppendUint16BE([]byte{p.Enable}, p.Port)
}

// ParsePrivTelnetConfig decodes the 3 bytes.
func ParsePrivTelnetConfig(v []byte) (*PrivTelnetConfig, error) {
	if len(v) != 3 {
		return nil, ErrShortPacket
	}
	return &PrivTelnetConfig{Enable: v[0], Port: Uint16BE(v[1:])}, nil
}

// PrivConfigChecksum is element 0x41 (min=max=16): 16 raw bytes.
type PrivConfigChecksum [16]byte

// AssembleValue returns the 16 bytes.
func (p PrivConfigChecksum) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParsePrivConfigChecksum decodes the 16 bytes.
func ParsePrivConfigChecksum(v []byte) (PrivConfigChecksum, error) {
	var out PrivConfigChecksum
	if len(v) != 16 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// PrivChecksumResult is element 0x85 (min=max=1): one byte.
type PrivChecksumResult uint8

// AssembleValue writes the byte.
func (p PrivChecksumResult) AssembleValue() []byte { return []byte{byte(p)} }

// ParsePrivChecksumResult decodes the byte.
func ParsePrivChecksumResult(v []byte) (PrivChecksumResult, error) {
	if len(v) != 1 {
		return 0, ErrShortPacket
	}
	return PrivChecksumResult(v[0]), nil
}

// PrivRate2 is element 0xa0 (min=max=4): one BE32
// (cw_priv_rate2_assemble family, single restore32).
type PrivRate2 uint32

// AssembleValue writes the 4 bytes.
func (p PrivRate2) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivRate2 decodes the 4 bytes.
func ParsePrivRate2(v []byte) (PrivRate2, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivRate2(Uint32BE(v)), nil
}
