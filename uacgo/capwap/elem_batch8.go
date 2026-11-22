package capwap

// Batch-8 standard elements, validated against the vendor assemble rules.

// MACLen rule shared by MAC-carrying elements: 6 or 8 bytes
// (pbVar[x][1] == 6 || == 8 in the assemble functions).
func validMACLen(n uint8) bool { return n == 6 || n == 8 }

// MACEntry is the {count/flag, len, mac[len]} shape used by several
// elements.
type MACEntry struct {
	Flag uint8 // leading u8 (acl num / radio id)
	MAC  []byte
}

// value writes len + mac (the wire carries len then mac).
func (e MACEntry) value() []byte {
	b := []byte{e.Flag, byte(len(e.MAC))}
	return append(b, e.MAC...)
}

func parseMACEntry(v []byte, minN int) (MACEntry, error) {
	var e MACEntry
	if len(v) < minN+2 {
		return e, ErrShortPacket
	}
	e.Flag = v[0]
	l := int(v[1])
	if !validMACLen(uint8(l)) || 2+l != len(v) {
		return e, ErrShortPacket
	}
	e.MAC = append([]byte(nil), v[2:2+l]...)
	return e, nil
}

// AppendAddMACACLEntry is element 0x0007 (min 8): flag + len(6|8) + mac.
// Vendor rule: leading byte must be 0 in this firmware (assemble guard).
func AppendAddMACACLEntry(dst []byte, mac []byte) []byte {
	return AppendElement(dst, 0x0007, MACEntry{Flag: 0, MAC: mac}.value())
}

// ParseMACACLEntry decodes 0x0007/0x0011 values.
func ParseMACACLEntry(v []byte) (MACEntry, error) { return parseMACEntry(v, 1) }

// AppendDeleteMACACLEntry is element 0x0011, same shape as 0x0007.
func AppendDeleteMACACLEntry(dst []byte, mac []byte) []byte {
	return AppendElement(dst, 0x0011, MACEntry{Flag: 0, MAC: mac}.value())
}

// AppendAddStation is element 0x0008 (min 8): radio id (<0x20) + mac_len
// (6|8) + mac + optional BE32 vlan (present when the value carries it —
// vendor checks pbVar+4 non-zero).
type AddStation struct {
	RadioID uint8
	MAC     []byte
	VLAN    uint32 // optional; HasVLAN selects
	HasVLAN bool
}

// AssembleValue writes the element value.
func (a AddStation) AssembleValue() []byte {
	b := []byte{a.RadioID, byte(len(a.MAC))}
	b = append(b, a.MAC...)
	if a.HasVLAN {
		b = AppendUint32BE(b, a.VLAN)
	}
	return b
}

// ParseAddStation decodes the element value.
func ParseAddStation(v []byte) (*AddStation, error) {
	if len(v) < 2 || v[0] >= 0x20 || !validMACLen(v[1]) {
		return nil, ErrShortPacket
	}
	a := &AddStation{RadioID: v[0]}
	l := int(v[1])
	if 2+l > len(v) {
		return nil, ErrShortPacket
	}
	a.MAC = append([]byte(nil), v[2:2+l]...)
	off := 2 + l
	if rest := len(v) - off; rest == 4 {
		a.HasVLAN = true
		a.VLAN = Uint32BE(v[off:])
	} else if rest != 0 {
		return nil, ErrShortPacket
	}
	return a, nil
}

// AppendDeleteStation is element 0x0012 (min 8): radio id + mac_len (6|8)
// + mac; value length must equal mac_len (vendor check `- 2 == len`).
type DeleteStation struct {
	RadioID uint8
	MAC     []byte
}

// AssembleValue writes the element value.
func (d DeleteStation) AssembleValue() []byte {
	b := []byte{d.RadioID, byte(len(d.MAC))}
	return append(b, d.MAC...)
}

// ParseDeleteStation decodes the element value.
func ParseDeleteStation(v []byte) (*DeleteStation, error) {
	if len(v) < 2 || v[0] >= 0x20 || !validMACLen(v[1]) {
		return nil, ErrShortPacket
	}
	if 2+int(v[1]) != len(v) {
		return nil, ErrShortPacket
	}
	return &DeleteStation{RadioID: v[0],
		MAC: append([]byte(nil), v[2:]...)}, nil
}

// DecryptionErrorReport is element 0x000f (min 9): radio id (<0x20) +
// N × {u8 bssid idx, BE16 count}.
type DecryptionErrorReport struct {
	RadioID uint8
	Entries []DecryptErrEntry
}

// DecryptErrEntry is one BSSID error count.
type DecryptErrEntry struct {
	BSSIDIdx uint8
	Count    uint16
}

// AssembleValue writes the element value.
func (r DecryptionErrorReport) AssembleValue() []byte {
	b := []byte{r.RadioID}
	for _, e := range r.Entries {
		b = append(b, e.BSSIDIdx, byte(e.Count>>8), byte(e.Count))
	}
	return b
}

// ParseDecryptionErrorReport decodes the element value.
func ParseDecryptionErrorReport(v []byte) (*DecryptionErrorReport, error) {
	if len(v) < 1 || v[0] >= 0x20 {
		return nil, ErrShortPacket
	}
	r := &DecryptionErrorReport{RadioID: v[0]}
	off := 1
	for off+3 <= len(v) {
		r.Entries = append(r.Entries, DecryptErrEntry{
			BSSIDIdx: v[off], Count: Uint16BE(v[off+1:])})
		off += 3
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return r, nil
}

// AppendDataTransferData is element 0x000d (min 5): u8 type + u8 flags +
// BE16 len + raw (cw_data_transfer_data_assemble).
type DataTransferData struct {
	Type  uint8
	Flags uint8
	Data  []byte
}

// AssembleValue writes the element value.
func (d DataTransferData) AssembleValue() []byte {
	b := []byte{d.Type, d.Flags}
	b = AppendUint16BE(b, uint16(len(d.Data)))
	return append(b, d.Data...)
}

// ParseDataTransferData decodes the element value (exact consumption).
func ParseDataTransferData(v []byte) (*DataTransferData, error) {
	if len(v) < 4 {
		return nil, ErrShortPacket
	}
	d := &DataTransferData{Type: v[0], Flags: v[1]}
	n := int(Uint16BE(v[2:]))
	if 4+n != len(v) {
		return nil, ErrShortPacket
	}
	d.Data = append([]byte(nil), v[4:]...)
	return d, nil
}

// AppendDataTransferMode is element 0x000e (min=max=1).
func AppendDataTransferMode(dst []byte, mode uint8) []byte {
	return AppendElement(dst, 0x000e, []byte{mode})
}

// ParseDataTransferMode decodes element 0x000e.
func ParseDataTransferMode(v []byte) (uint8, error) {
	if len(v) != 1 {
		return 0, ErrShortPacket
	}
	return v[0], nil
}

// AppendInitiateDownload is element 0x001b (min=max=0 — empty value).
func AppendInitiateDownload(dst []byte) []byte {
	return AppendElement(dst, 0x001b, nil)
}

// AppendReturnedMessageElement is element 0x0022 (min 3): BE16 element type
// + u8 result (cw_returned_message_element_assemble).
func AppendReturnedMessageElement(dst []byte, elemType uint16, result uint8) []byte {
	v := AppendUint16BE(nil, elemType)
	v = append(v, result)
	return AppendElement(dst, 0x0022, v)
}

// ParseReturnedMessageElement decodes element 0x0022.
func ParseReturnedMessageElement(v []byte) (uint16, uint8, error) {
	if len(v) != 3 {
		return 0, 0, ErrShortPacket
	}
	return Uint16BE(v), v[2], nil
}
