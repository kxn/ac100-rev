package cweng

import (
	"encoding/binary"
	"encoding/hex"
	"net"
	"uacgo/capwap"
)

// RegisterV6Compatibility advertises the V6 control-protocol dialect. These
// are packet-format versions, distinct from the Web's per-AP feature gates.
// Exact source: V6 decrypted Join response35 and _apmngr_pkt_join_req_listen
// @0x60b040; _apmngr_sub_cap_transfer @0x60a378.
func (e *Engine) RegisterV6Compatibility() {
	// _apmngr_pkt_discover_req_listen advertises table dialect1 and its
	// region/bind/default-parameter capabilities, allowing APs to report RRST.
	e.Register(1, 130, "v6_radio_linkage_dialect", func(_ *Ctx, _, rsp *capwap.ParsedPacket) bool {
		value := []byte{2, 0, 0, 1, 1, 1, 0, 4, 0, 0, 0, 15}
		rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x90, Value: value}})})
		return true
	})
	// V6 _apmngr_pkt_config_status_req_listen @0x60a598 always initializes
	// software control switches. A warm AP may retain these from a previous AC;
	// a cold AP needs the baseline before it can forward client association.
	e.Register(5, 120, "v6_control_switches", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		value := capwap.AppendUint32BE(nil, 0x6f)
		value = capwap.AppendUint32BE(value, 0x2e)
		rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0x26, []capwap.PrivElementValue{{Type: 0x26, Value: value}})})
		return true
	})

	e.Register(3, 120, "v6_protocol_negotiation", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		bitmap, _ := hex.DecodeString("ef67ffdfaf3a1e67980ebfee000000dc")
		rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x32, Value: bitmap})
		versions := []struct {
			key   uint16
			value []byte
		}{
			{0x63, []byte{3}}, {0x64, []byte{1}}, {0x4d, []byte{1}}, {0x66, []byte{1}}, {0x67, []byte{1}},
			{0x62, []byte{0x71, 0x1e}}, {0x1d, []byte{1}}, {4, []byte{3}}, {0xd, []byte{2}}, {0x3d, []byte{3}},
			{0x5f, []byte{0x3a}}, {0x20, []byte{3}}, {0x18, []byte{3, 0xbb}}, {0x11, []byte{0x84, 0, 0, 0}},
			{0x19, []byte{1}}, {2, []byte{0x1b}}, {0x10, []byte{3}}, {0x1f, []byte{1}}, {0x2c, []byte{0x27}},
		}
		value := binary.BigEndian.AppendUint16(nil, uint16(len(versions)))
		for _, v := range versions {
			value = binary.BigEndian.AppendUint16(value, v.key)
			value = binary.BigEndian.AppendUint16(value, uint16(len(v.value)))
			value = append(value, v.value...)
		}
		priv := []capwap.PrivElementValue{{Type: 0x8f, Value: value}, {Type: 0x1d, Value: []byte{0, 0, 0, 2}}}
		if name := e.BoundInterface(); name != "" {
			if nic, err := net.InterfaceByName(name); err == nil && len(nic.HardwareAddr) == 6 {
				priv = append(priv, capwap.PrivElementValue{Type: 0x1b, Value: append([]byte{}, nic.HardwareAddr...)})
			}
		}
		for _, el := range priv {
			rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{el})})
		}
		return true
	})
}
