package capwap

// Batch-21: priv 0x5b AP Firmware Id and priv 0x68 lldp_report.
// Layouts from the vendor parse functions' retrieve sequences with
// retrieve_bytes lengths confirmed from the a2 argument.

// PrivAPFirmwareID is 0x5b (min 0x11): rbytes(16) r8 rbytes(16)
// (cw_priv_ap_firmware_id_parse @0x5a4d54). Blocks carried verbatim.
type PrivAPFirmwareID struct {
	Blk1 [16]byte
	A    uint8
	Blk2 [16]byte
	Rest []byte
}

// AssembleValue writes blocks + rest.
func (p PrivAPFirmwareID) AssembleValue() []byte {
	b := append([]byte(nil), p.Blk1[:]...)
	b = append(b, p.A)
	b = append(b, p.Blk2[:]...)
	return append(b, p.Rest...)
}

// ParsePrivAPFirmwareID decodes the 33-byte prefix + rest.
func ParsePrivAPFirmwareID(v []byte) (*PrivAPFirmwareID, error) {
	if len(v) < 33 {
		return nil, ErrShortPacket
	}
	p := &PrivAPFirmwareID{A: v[16], Rest: append([]byte(nil), v[33:]...)}
	copy(p.Blk1[:], v[:16])
	copy(p.Blk2[:], v[17:33])
	return p, nil
}

// PrivLLDPReport is 0x68 (min 4): BE32 + rest raw
// (cw_priv_lldp_report_parse @0x5b524c).
type PrivLLDPReport struct {
	W    uint32
	Rest []byte
}

// AssembleValue writes header + rest.
func (p PrivLLDPReport) AssembleValue() []byte {
	return append(AppendUint32BE(nil, p.W), p.Rest...)
}

// ParsePrivLLDPReport decodes header + rest.
func ParsePrivLLDPReport(v []byte) (*PrivLLDPReport, error) {
	if len(v) < 4 {
		return nil, ErrShortPacket
	}
	return &PrivLLDPReport{W: Uint32BE(v), Rest: append([]byte(nil), v[4:]...)}, nil
}
