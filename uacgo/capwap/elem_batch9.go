package capwap

// Batch-9 standard elements (lengths per elements.tsv; field orders from
// the vendor assemble functions) plus the DTLS record framing parser.

// AppendACNameWithPriority is element 0x0005 (min 2 max 0x201): u8 priority
// + name bytes (cw_ac_name_with_priority_assemble: restore8 + raw).
func AppendACNameWithPriority(dst []byte, priority uint8, name string) []byte {
	v := append([]byte{priority}, name...)
	return AppendElement(dst, 0x0005, v)
}

// ParseACNameWithPriority decodes element 0x0005.
func ParseACNameWithPriority(v []byte) (uint8, string, error) {
	if len(v) < 2 {
		return 0, "", ErrShortPacket
	}
	return v[0], string(v[1:]), nil
}

// DuplicateAddr is the duplicate-address report shape shared by
// 0x0015 (ipv4, min 12 max 14) / 0x0016 (ipv6, min 18 max 26):
//
//	BE32 status + u8 type + u8 length + address bytes
//
// (cw_duplicate_ipv4_address_assemble: restore32 + restore8 + restore8 + raw;
// ipv6 variant stores the 16-byte address).
type DuplicateAddr struct {
	Status uint32
	Type   uint8
	Addr   []byte
}

// AssembleValue writes status + type + len + addr.
func (d DuplicateAddr) AssembleValue() []byte {
	b := AppendUint32BE(nil, d.Status)
	b = append(b, d.Type, byte(len(d.Addr)))
	return append(b, d.Addr...)
}

// ParseDuplicateIPv4Address decodes element 0x0015. The value length is
// 12..14 (min/max): BE32 status + u8 type + u8 addr-len + addr bytes.
func ParseDuplicateIPv4Address(v []byte) (*DuplicateAddr, error) {
	if len(v) < 12 || len(v) > 14 || v[4] > 6 || 6+int(v[5]) != len(v) {
		return nil, ErrShortPacket
	}
	return &DuplicateAddr{Status: Uint32BE(v), Type: v[4],
		Addr: append([]byte(nil), v[6:]...)}, nil
}

// AppendImageIdentifier is element 0x0019 (min 5 max 0x404):
// BE32 vendor + raw version payload
// (cw_image_identifier_assemble: restore32 + raw).
func AppendImageIdentifier(dst []byte, vendor uint32, payload []byte) []byte {
	v := AppendUint32BE(nil, vendor)
	v = append(v, payload...)
	return AppendElement(dst, 0x0019, v)
}

// ParseImageIdentifier decodes element 0x0019 (min 5).
func ParseImageIdentifier(v []byte) (uint32, []byte, error) {
	if len(v) < 5 {
		return 0, nil, ErrShortPacket
	}
	return Uint32BE(v), append([]byte(nil), v[4:]...), nil
}

// --- DTLS record framing ---
//
// DTLSPlaintext record header (RFC 6347): ContentType(1) Version(2)
// Epoch(2) Sequence(6) Length(2) — 13 bytes. The vendor's ClientHello rule
// (buf[4]==0x16 after the 4-byte prefix) aligns with this layout.

// DTLSRecordHeader is the parsed 13-byte record header.
type DTLSRecordHeader struct {
	ContentType uint8
	Version     uint16 // 0xfefc/0xfefd/0xfeff for DTLS 1.0-1.2
	Epoch       uint16
	Sequence    uint64 // 48-bit
	Length      uint16
}

// ParseDTLSRecordHeader decodes the 13-byte record header at b.
func ParseDTLSRecordHeader(b []byte) (*DTLSRecordHeader, error) {
	if len(b) < 13 {
		return nil, ErrShortPacket
	}
	h := &DTLSRecordHeader{
		ContentType: b[0],
		Version:     Uint16BE(b[1:]),
		Epoch:       Uint16BE(b[3:]),
	}
	seq := uint64(b[5])<<40 | uint64(b[6])<<32 | uint64(b[7])<<24 |
		uint64(b[8])<<16 | uint64(b[9])<<8 | uint64(b[10])
	h.Sequence = seq
	h.Length = Uint16BE(b[11:])
	return h, nil
}

// AppendDTLSRecordHeader writes the 13-byte record header.
func AppendDTLSRecordHeader(dst []byte, h DTLSRecordHeader) []byte {
	// header layout: type(1)+ver(2)+epoch(2)+seq(6: 0 pad + 5 bytes)
	//   + length(2) = 13 bytes [0..12]
	head := []byte{h.ContentType, byte(h.Version >> 8), byte(h.Version),
		byte(h.Epoch >> 8), byte(h.Epoch),
		byte(h.Sequence >> 40), byte(h.Sequence >> 32), byte(h.Sequence >> 24),
		byte(h.Sequence >> 16), byte(h.Sequence >> 8), byte(h.Sequence),
		0, 0}
	head[11], head[12] = byte(h.Length>>8), byte(h.Length)
	return append(dst, head...)
}
