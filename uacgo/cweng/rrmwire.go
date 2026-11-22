package cweng

import (
	"uacgo/capwap"
)

// RRM wire integration: ndp-para collection request (0x5c, AC→AP) and
// chnl-scan delegation (0x9b, AC→AP) on msg 7; neighbor reports (0x5d)
// and scan reports (0x9c) arrive on msg 9 (uac_rrm_init registers
// serv_msg_mngr_register(9, 0x41, _rrm_pkt_wtp_event_listener) — the
// wsta_roam listener handles 0x9c).

// SendNdpPara pushes one AP radio's neighbor-discovery parameters
// (0x5c "private ndp para"; _rrm_ctl_packet_create @0x4aae64).
func (e *Engine) SendNdpPara(s *Session, p capwap.PrivNdpPara) error {
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0x5c, Value: p.AssembleValue()})
}

// SendChnlScan pushes the ACS scan request (0x9b "private chnl_scan";
// _wsta_intelligent_roam_start_acs_send @0x483f7c).
func (e *Engine) SendChnlScan(s *Session, p capwap.PrivChnlScan) error {
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0x9b, Value: p.AssembleValue()})
}

// RrmCollector feeds the RRM engine from the msg 9 reports.
type RrmCollector interface {
	// ReportNeigh ingests one radio's 0x5d neighbor list; true = all
	// registered radios reported.
	ReportNeigh(band, apID, radio int, samples []RrmNeighSample) bool
	// ReportScan ingests one AP's 0x9c channel scan samples.
	ReportScan(apMAC [6]byte, records []capwap.ChnlScanRecord)
}

// rrmNeighSamples converts one 0x5d neighbor row's measurement triples
// ({radio, channel, signed rssi} per cw_priv_rrm_neighs_list_parse
// @0x5be944) into engine samples with the RSSI transform of
// _rrm_pkt_rssi_request applied.
func rrmNeighSamples(apIDOf func([6]byte) int, n capwap.RrmNeigh) []RrmNeighSample {
	out := make([]RrmNeighSample, 0, len(n.Samples))
	for _, s := range n.Samples {
		out = append(out, RrmNeighSample{
			NeighAP: apIDOf(n.MAC),
			Radio:   s.Radio,
			Channel: int(s.Channel),
			RSSI:    RRMRRSITransform(int(s.RSSI)),
		})
	}
	return out
}

// RegisterRRMHandlers wires the msg 9 listeners for 0x5d (rrm neighbor
// list) and 0x9c (chnl scan report) into the collector. The RSSI
// transform of _rrm_pkt_rssi_request is applied on ingest.
func (e *Engine) RegisterRRMHandlers(c RrmCollector, apIDOf func([6]byte) int) {
	e.Register(capwap.MsgWTPEventRequest, 40, "rrm_wtp_event",
		func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
			for _, el := range req.Elements {
				if el.Type != 0x0025 || len(el.Value) < 6 {
					continue
				}
				var apMAC [6]byte
				if ctx != nil && ctx.Session != nil {
					apMAC = ctx.Session.APMAC
				}
				for _, sub := range unpackVendorSubs(el.Value[6:]) {
					switch sub.Type {
					case 0x5d:
						nl, err := capwap.ParsePrivRrmNeighsList(sub.Value)
						if err != nil {
							continue
						}
						var samples []RrmNeighSample
						for _, n := range nl.Neighs {
							samples = append(samples, rrmNeighSamples(apIDOf, n)...)
						}
						c.ReportNeigh(0, apIDOf(apMAC), int(nl.RadioID), samples)
					case 0x9c:
						rep, err := capwap.ParsePrivChnlScanReport(sub.Value)
						if err != nil {
							continue
						}
						c.ReportScan(apMAC, rep.Records)
					}
				}
			}
			return true
		})
}
