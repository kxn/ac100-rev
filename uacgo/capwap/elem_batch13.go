package capwap

// Batch-13: last remaining standard element + private mesh elements.

// ImageInformation is element 0x001a (min=max=0x14=20):
// BE32 file info + 16B info block
// (apupd_image_information_add @0x661520: restore32 + restore_raw 0x10).
type ImageInformation struct {
	FileInfo uint32
	Info     [16]byte
}

// AssembleValue writes the 20 bytes.
func (p ImageInformation) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.FileInfo)
	return append(b, p.Info[:]...)
}

// ParseImageInformation decodes the 20 bytes.
func ParseImageInformation(v []byte) (*ImageInformation, error) {
	if len(v) != 20 {
		return nil, ErrShortPacket
	}
	p := &ImageInformation{FileInfo: Uint32BE(v)}
	copy(p.Info[:], v[4:])
	return p, nil
}

// AppendImageInformation writes element 0x001a.
func AppendImageInformation(dst []byte, p ImageInformation) []byte {
	return AppendElement(dst, 0x001a, p.AssembleValue())
}

// ImageData is element 0x0018: type8 followed by raw data. The length in
// cw_image_data's C struct is derived from the outer TLV, never on the wire.
// V6 parse @0x63d2e0: types1/2 have 1–1024 bytes; type5 has no data.
type ImageData struct {
	Type uint8
	Data []byte
}

// AssembleValue writes the element value.
func (d ImageData) AssembleValue() []byte {
	b := []byte{d.Type}
	return append(b, d.Data...)
}

// ParseImageData decodes the element value.
func ParseImageData(v []byte) (*ImageData, error) {
	if len(v) < 1 || len(v) > 1025 {
		return nil, ErrShortPacket
	}
	t := v[0]
	if !(t >= 1 && t <= 2) && t != 5 {
		return nil, ErrShortPacket
	}
	if (t == 5 && len(v) != 1) || (t != 5 && len(v) == 1) {
		return nil, ErrShortPacket
	}
	return &ImageData{Type: t, Data: append([]byte(nil), v[1:]...)}, nil
}

// AppendImageData writes element 0x0018.
func AppendImageData(dst []byte, d ImageData) []byte {
	return AppendElement(dst, 0x0018, d.AssembleValue())
}

// PrivMeshControl is private element 0x76 (min 6 max 0xffff): raw payload
// for mesh topology/pairing commands (vendor-specific, no typed fields
// extracted — carried verbatim).
type PrivMeshControl []byte

// AssembleValue returns the payload.
func (p PrivMeshControl) AssembleValue() []byte { return append([]byte(nil), p...) }

// ParsePrivMeshControl keeps the payload verbatim.
func ParsePrivMeshControl(v []byte) (PrivMeshControl, error) {
	return PrivMeshControl(append([]byte(nil), v...)), nil
}

// PrivWtpSubCapability is private element 0x8f (min 2 max 0x400): raw
// capability blob from AP join (cw_priv_wtp_sub_capability_parse).
type PrivWtpSubCapability []byte

// AssembleValue returns the blob.
func (p PrivWtpSubCapability) AssembleValue() []byte { return append([]byte(nil), p...) }

// ParsePrivWtpSubCapability keeps the blob verbatim.
func ParsePrivWtpSubCapability(v []byte) (PrivWtpSubCapability, error) {
	return PrivWtpSubCapability(append([]byte(nil), v...)), nil
}

// PrivIPReport is private element 0x4d (IP report from AP station): raw
// payload (cw_priv_ip_report_parse — vendor-specific format).
type PrivIPReport []byte

// AssembleValue returns the payload.
func (p PrivIPReport) AssembleValue() []byte { return append([]byte(nil), p...) }

// ParsePrivIPReport keeps the payload verbatim.
func ParsePrivIPReport(v []byte) (PrivIPReport, error) {
	return PrivIPReport(append([]byte(nil), v...)), nil
}
