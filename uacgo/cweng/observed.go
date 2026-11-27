package cweng

import (
	"encoding/binary"
	"strings"
	"time"
	"uacgo/capwap"
)

// RadioStatus contains AP observations, separate from requested configuration.
// Private 0x25: cw_priv_ap_res_info_parse @0x5a6f6c, radio/mode/channel/power;
// names verified by rdmngr_capwap_callback_wtp_event_request_listen @0x6143f0.
type RadioStatus struct {
	Radio   uint8     `json:"radio_id"`
	Mode    uint8     `json:"mode"`
	Channel uint8     `json:"channel"`
	Power   uint16    `json:"power_dbm"`
	Seen    time.Time `json:"last_seen"`
}
type ReportedSSID struct {
	Radio uint8     `json:"radio_id"`
	SSID  string    `json:"ssid"`
	Seen  time.Time `json:"last_seen"`
}

type ChannelScanReport struct {
	ReceivedAt time.Time                  `json:"received_at"`
	Channels   []capwap.ChannelScanSample `json:"channels"`
}

type RRMReport struct {
	Radio      uint8             `json:"radio_id"`
	Mode       uint8             `json:"mode"`
	ReceivedAt time.Time         `json:"received_at"`
	Neighbors  []capwap.RrmNeigh `json:"neighbors"`
}

func privateElements(p *capwap.ParsedPacket, visit func(uint16, []byte)) {
	for _, el := range p.Elements {
		if el.Type != 0x25 || len(el.Value) < 6 {
			continue
		}
		for b := el.Value[6:]; len(b) >= 4; {
			n := int(binary.BigEndian.Uint16(b[2:]))
			if n > len(b)-4 {
				break
			}
			visit(binary.BigEndian.Uint16(b), b[4:4+n])
			b = b[4+n:]
		}
	}
}

func (e *Engine) RegisterObservationHandlers() {
	e.Register(9, 65, "v6_rrm_neighbors", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		privateElements(privatePacketForTypes(req, []uint16{0x5d}), func(typ uint16, b []byte) {
			if typ != 0x5d {
				return
			}
			if p, err := capwap.ParsePrivRrmNeighsList(b); err == nil {
				if ctx.Session.rrmReports == nil {
					ctx.Session.rrmReports = map[uint8]RRMReport{}
				}
				ctx.Session.rrmReports[p.A] = RRMReport{Radio: p.A, Mode: p.B, ReceivedAt: time.Now(), Neighbors: p.Neighs}
				if e.OnRRMReport != nil {
					e.OnRRMReport(sessionID(ctx.Session), ctx.Session.Created, *p)
				}
			}
		})
		return true
	})
	observe := func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		privateElements(req, func(typ uint16, b []byte) {
			if ctx.Session.apEntry != nil {
				if typ == 0x7f {
					ctx.Session.apEntry.linkageTable = append([]byte{}, b...)
					refreshRadioLinkage(ctx.Session.apEntry)
					return
				}
				if typ == 0x90 {
					ctx.Session.apEntry.linkageControl = append([]byte{}, b...)
					refreshRadioLinkage(ctx.Session.apEntry)
					return
				}
				if typ == 0xbb {
					if modes, err := ParseRadioModes(b); err == nil {
						ctx.Session.apEntry.RadioModes = modes
					}
					return
				}
				if typ == 0xbc {
					if mode, err := parseRadioModeState(b); err == nil {
						ctx.Session.apEntry.RadioMode = mode
					}
					return
				}
			}
			if typ == 0x76 {
				if report, err := updateMeshReport(ctx.Session.meshReport, b); err == nil {
					ctx.Session.meshReport = report
				}
				return
			}
			if typ == 0xc8 && ctx.Session.apEntry != nil {
				if rows, err := capwap.ParseVendorList(b); err == nil {
					for _, r := range rows {
						if r.Type == 12 {
							if ports, err := parsePortCapabilities(r.Value); err == nil {
								ctx.Session.apEntry.Ports = ports
							}
						}
					}
				}
				return
			}
			if typ == 0x9c {
				if rows, err := capwap.ParseChannelScanReport(b); err == nil {
					ctx.Session.channelScan = &ChannelScanReport{ReceivedAt: time.Now(), Channels: rows}
				}
				return
			}
			if typ == 0xca {
				if report, err := parseARPScan(b); err == nil {
					ctx.Session.arpScan = report
				}
				return
			}
			if typ == 0xce && ctx.Session.apEntry != nil {
				if p, err := capwap.ParseEDCAPresets(b); err == nil {
					ctx.Session.apEntry.EDCAPresets = p
				}
				return
			}
			if typ != 0x25 || len(b) != 5 || b[0] == 0 || b[0] >= 32 {
				return
			}
			s := ctx.Session
			if s.radioStatus == nil {
				s.radioStatus = map[uint8]RadioStatus{}
			}
			s.radioStatus[b[0]] = RadioStatus{Radio: b[0], Mode: b[1], Channel: b[2], Power: binary.BigEndian.Uint16(b[3:]), Seen: time.Now()}
			if e.OnRadioObservation != nil {
				e.OnRadioObservation(sessionID(s), s.Created, s.radioStatus[b[0]])
			}
		})
		return true
	}
	e.Register(9, 90, "radio_observations", observe)
	e.Register(8, 90, "configuration_observations", observe)
	e.Register(5, 90, "configure_observations", observe)
	// V4's single roam listener processes PMK, trigger, then the first9c.
	// An explicit priority keeps that policy order independent of which
	// public registration helper an embedding controller calls first.
	e.Register(9, 91, "high_performance_scan", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		if b, ok := firstPrivateElement(req, 0x9c); ok && e.OnChannelScan != nil {
			if rows, err := capwap.ParseChannelScanReport(b); err == nil {
				e.OnChannelScan(sessionID(ctx.Session), ctx.Session.Created, rows)
			}
		}
		return true
	})
	e.Register(5, 101, "reported_ssids", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		privateElements(req, func(typ uint16, b []byte) {
			if typ != 0x1e {
				return
			}
			list, err := capwap.ParsePrivWlanList(b)
			if err != nil || int(list.B) != len(list.Entries) {
				return
			}
			rows := []ReportedSSID{}
			for _, row := range list.Entries {
				rows = append(rows, ReportedSSID{Radio: row.RadioID, SSID: strings.TrimRight(string(row.SSID), "\x00"), Seen: time.Now()})
			}
			ctx.Session.reportedSSIDs = rows
		})
		return true
	})
}

func firstPrivateElement(p *capwap.ParsedPacket, typ uint16) ([]byte, bool) {
	var value []byte
	found := false
	privateElements(p, func(t uint16, b []byte) {
		if t == typ && !found {
			value = b
			found = true
		}
	})
	return value, found
}
func privatePacketForTypes(p *capwap.ParsedPacket, types []uint16) *capwap.ParsedPacket {
	out := *p
	out.Elements = nil
	for _, typ := range types {
		if b, ok := firstPrivateElement(p, typ); ok {
			out.Elements = append(out.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: typ, Value: b}})})
		}
	}
	return &out
}

// _uac_wsta_pkt_wtp_event_listener @74a4b0 chooses a single lifecycle
// element by type priority, independently of its position in the packet.
func stationEventPacket(p *capwap.ParsedPacket) *capwap.ParsedPacket {
	for _, typ := range []uint16{0x33, 0x34} {
		for _, el := range p.Elements {
			if el.Type == typ {
				out := *p
				out.Elements = []capwap.Element{el}
				return &out
			}
		}
	}
	for _, typ := range []uint16{2, 0x8a, 3, 0x4d, 0xc6, 0xbd} {
		if _, ok := firstPrivateElement(p, typ); ok {
			return privatePacketForTypes(p, []uint16{typ})
		}
	}
	out := *p
	out.Elements = nil
	return &out
}
