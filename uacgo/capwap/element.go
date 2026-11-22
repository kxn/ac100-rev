package capwap

import "encoding/binary"

// Element types extracted from the binary's element manager tables
// (re/notes/elements.tsv — standard @0x6d2db0 types 1..0x36, IEEE802.11
// @0x6d2e88 types 0x400..0x418, private @0x6e6700 types 0..0xc0).
// Dispatch is by TABLE SLOT (cw_msg_ele_mngr_get @0x562890 does table[type-1],
// cw_msg_ele_priv_mngr_get @0x5a22d4 does table[type]); unknown types are
// skipped with the offset advanced (capwap_packet_parse "message element
// doesn't have manager, ignore it" @0x587a94).

const (
	EleVendorSpecificPayload = 0x0025
)

// Private (0x25 envelope) sub-element types seen in the private table —
// names are the vendor's own g_cw_msg_ele_priv_* symbol names.
const (
	PrivCWVerEle            = 0x00
	PrivStationAuthRsltEle  = 0x04
	PrivApBaseParaEle       = 0x05
	PrivAdvRdParaEle        = 0x08
	PrivRateEle             = 0x0a
	PrivDataTunnelModeEle   = 0x1d
	PrivWlanListEle         = 0x1e
	PrivStaListEle          = 0x1f
	PrivResetMaskEle        = 0x23
	PrivConfigTypeEle       = 0x27
	PrivApCapacityEle       = 0x2c
	PrivSpecMsgSwEle        = 0x26
	PrivApLedOpEle          = 0x39
	PrivApLedStatusEle      = 0x38
	PrivApLedModeCtrlEle    = 0x6f
	PrivApConfigChecksumEle = 0x41
	PrivBandwidthCtrlEle    = 0x45
	PrivWsrvParaEle         = 0x09
	PrivWsrvParaNewEle      = 0x63
	PrivApInfoEle           = 0x1b
	PrivApWireVlanEle       = 0x30
	PrivApWireVlan2Ele      = 0x43
	PrivApTrunkEle          = 0x44
	PrivApSwitchLinkEle     = 0x40
	PrivApWorkingChannelEle = 0x66
	PrivStatsCtrlReqEle     = 0x55
	PrivRoamingCtrlReqEle   = 0x57
	PrivTelnetConfigEle     = 0x9f
	PrivConfigExtensionEle  = 0xc0
)

// Element is one parsed TLV. Value points into the packet buffer.
type Element struct {
	Type  uint16
	Len   uint16
	Value []byte
}

// ParseElements walks type/len/value TLVs over exactly n bytes.
//
// Evidence: capwap_packet_parse @0x587a94 element loop (cw_msg_ele_format_parse
// @0x5628ec reads BE16 type + BE16 len at the running offset).
func ParseElements(b []byte, off, n int) ([]Element, error) {
	var out []Element
	end := off + n
	for off < end {
		if off+4 > len(b) {
			return out, ErrShortPacket
		}
		t := binary.BigEndian.Uint16(b[off:])
		l := binary.BigEndian.Uint16(b[off+2:])
		off += 4
		if off+int(l) > len(b) {
			return out, ErrShortPacket
		}
		out = append(out, Element{Type: t, Len: l, Value: b[off : off+int(l)]})
		off += int(l)
	}
	return out, nil
}

// AppendElement appends one TLV.
func AppendElement(dst []byte, t uint16, value []byte) []byte {
	dst = binary.BigEndian.AppendUint16(dst, t)
	dst = binary.BigEndian.AppendUint16(dst, uint16(len(value)))
	dst = append(dst, value...)
	return dst
}
