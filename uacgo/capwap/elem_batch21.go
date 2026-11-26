package capwap

// Batch-21: priv 0x5b AP Firmware Id and priv 0x68 lldp_report.
// Layouts from the vendor parse functions' retrieve sequences with
// retrieve_bytes lengths confirmed from the a2 argument.

// PrivAPFirmwareID (0x5b): current firmware ID followed by a counted
// blocked-firmware list. V6 cw_priv_ap_firmware_id_parse @0x67fdf8.
type PrivAPFirmwareID struct {
	FirmwareID [16]byte
	Blocked    [][16]byte
}

func (p PrivAPFirmwareID) AssembleValue() []byte {
	if len(p.Blocked) > 255 {
		return nil
	}
	b := append([]byte{}, p.FirmwareID[:]...)
	b = append(b, byte(len(p.Blocked)))
	for _, id := range p.Blocked {
		b = append(b, id[:]...)
	}
	return b
}
func ParsePrivAPFirmwareID(v []byte) (*PrivAPFirmwareID, error) {
	if len(v) < 17 || len(v) != 17+int(v[16])*16 {
		return nil, ErrShortPacket
	}
	p := &PrivAPFirmwareID{}
	copy(p.FirmwareID[:], v[:16])
	for b := v[17:]; len(b) > 0; b = b[16:] {
		var id [16]byte
		copy(id[:], b[:16])
		p.Blocked = append(p.Blocked, id)
	}
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
