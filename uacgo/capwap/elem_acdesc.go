package capwap

import "encoding/binary"

// AC-side element builders for the discovery/join/config-status path.
// Each mirrors the vendor assemble function; fixture cw_dis_rsp validates.

// ACDescriptorSubElement is one vendor sub-entry inside AC Descriptor (0x0001):
// BE32 vendor id + BE16 type (1..0x400) + BE16 len (1..0x400) + data.
// Evidence: cw_ac_descriptor_assemble @0x56d2fc (restore32 node+0xc,
// restore16 node+0x12 type with 1..0x400 check, restore16 node+0x12+2 len).
type ACDescriptorSubElement struct {
	Vendor uint32
	Type   uint16
	Data   []byte
}

// ACDescriptor mirrors the 12-byte header + sub-elements written by
// cw_ac_descriptor_assemble @0x56d2fc. Fixture: 00 00 27 10 00 00 03 e8 02 02
// 00 04 + ("TL-AC1000 v1.0" padded 64) + ("1.0.1 Build..." padded 64).
type ACDescriptor struct {
	Stations    uint16 // puVar8[0]
	StationLim  uint16 // puVar8[1]  (fixture 10000)
	ActiveStas  uint16 // puVar8[2]
	ActiveLim   uint16 // puVar8[3]  (fixture 1000)
	Status      uint8  // byte 8:  (raw & 6) == raw  ⇒ raw ∈ {0,2,4,6}; fixture 0x02
	RStatus     uint8  // byte 9:  value-1 < 2 ⇒ 1 or 2; fixture 0x02
	Reserved    uint8  // byte 10: written as literal 0
	SlaveStatus uint8  // byte 11: (raw & 6) == raw; fixture 0x04
	SubElements []ACDescriptorSubElement
}

// AssembleValue writes the element value bytes.
func (d ACDescriptor) AssembleValue() []byte {
	b := make([]byte, 0, 64)
	b = binary.BigEndian.AppendUint16(b, d.Stations)
	b = binary.BigEndian.AppendUint16(b, d.StationLim)
	b = binary.BigEndian.AppendUint16(b, d.ActiveStas)
	b = binary.BigEndian.AppendUint16(b, d.ActiveLim)
	b = append(b, d.Status, d.RStatus, d.Reserved, d.SlaveStatus)
	for _, s := range d.SubElements {
		b = binary.BigEndian.AppendUint32(b, s.Vendor)
		b = binary.BigEndian.AppendUint16(b, s.Type)
		b = binary.BigEndian.AppendUint16(b, uint16(len(s.Data)))
		b = append(b, s.Data...)
	}
	return b
}

// PaddedString returns data padded/truncated to n bytes with NULs
// (fixtures store fixed 64-byte name/version strings).
func PaddedString(s string, n int) []byte {
	b := make([]byte, n)
	copy(b, s)
	return b
}

// ControlIPv4Address is element 0x000a: BE32 ip + BE16 port
// (cw_capwap_control_ipv4_address_assemble; fixture c0a801fd 0000).
func AppendControlIPv4Address(dst []byte, ip [4]byte, port uint16) []byte {
	v := append([]byte{ip[0], ip[1], ip[2], ip[3]}, byte(port>>8), byte(port))
	return AppendElement(dst, 0x000a, v)
}

// WTPradioInformation is element 0x0418: u8 radio id (<0x20) + BE32 radio type
// (mask 0x3f). Evidence: cw_80211_wtp_radio_information_assemble @0x56c8bc.
func AppendWTPradioInformation(dst []byte, radioID uint8, radioType uint32) []byte {
	v := []byte{radioID, byte(radioType >> 24), byte(radioType >> 16), byte(radioType >> 8), byte(radioType)}
	return AppendElement(dst, 0x0418, v)
}

// Vendor envelope (0x0025): BE32 vendor + BE16 field + private TLVs
// (type BE16 < 0xc1, len BE16, value). Evidence:
// cw_vendor_specific_payload_parse @0x58286c / _assemble @0x5820f8,
// cw_msg_ele_priv_format_parse @0x5a2180 (type<0xc1 check in assemble @0x5a2230).
type PrivElementValue struct {
	Type  uint16
	Value []byte
	Raw   bool // Value is already envelope value bytes (vendor+field+TLVs)
}

// VendorEnvelopeValue builds the 0x25 element VALUE (vendor + field + priv
// TLVs) — callers wrap it with AppendElement(dst, 0x0025, val).
func VendorEnvelopeValue(vendor uint32, field uint16, privs []PrivElementValue) []byte {
	v := binary.BigEndian.AppendUint32(nil, vendor)
	v = binary.BigEndian.AppendUint16(v, field)
	for _, p := range privs {
		v = binary.BigEndian.AppendUint16(v, p.Type)
		v = binary.BigEndian.AppendUint16(v, uint16(len(p.Value)))
		v = append(v, p.Value...)
	}
	return v
}

// AppendACName is element 0x0004 (cw_ac_name_assemble; min 1 max 0x200).
func AppendACName(dst []byte, name string) []byte {
	return AppendElement(dst, 0x0004, []byte(name))
}
