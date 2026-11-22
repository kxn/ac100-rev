package cweng

import (
	"uacgo/capwap"
)

// Roaming closed-loop wiring: 0x58 trigger in (msg 9 WTP event) → decision
// → 0x59 result out (msg 7 config update). Evidence: wsta_roam_pkt_init
// registers msg 9 event 0x5a (_wsta_roam_pkt_wtp_event_listener
// @0x489380) and _roaming_nbr_packet_create @0x487610 builds one msg 7 +
// 0x59 per AP in the union.

// RoamDecider computes the 0x59 result for one trigger report.
type RoamDecider interface {
	Decide(reportAPID uint16, trig *capwap.PrivRoamingTrigger) *capwap.PrivRoamingCalcResult
}

// APSessionResolver finds the live session of a WTP by MAC (to push 0x59).
type APSessionResolver interface {
	SessionByAPMAC(mac [6]byte) *Session
}

// SendRoamingResult mirrors _roaming_nbr_packet_create's msg 7 push
// (vendor 0x25 envelope + private 0x59).
func (e *Engine) SendRoamingResult(s *Session, r capwap.PrivRoamingCalcResult) error {
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0x59, Value: r.AssembleValue()})
}

// TriggerStatsSink optionally receives the raw trigger content (the
// reporting radio's environment sample and per-station signal) so live
// registries can be refreshed as a side effect of the decision path.
type TriggerStatsSink interface {
	NoteTrigger(reportAPID uint16, trig *capwap.PrivRoamingTrigger)
}

// RegisterRoamHandlers wires the msg 9 listener that reads 0x58 from the
// vendor envelope, runs the decider and pushes 0x59 to every AP in the
// result's union. Priority 50 sits between balance (1) and wstation
// (100) in the vendor dispatch order (notes/00-architecture.md §4).
// If r or d implements TriggerStatsSink they also receive the raw report.
func (e *Engine) RegisterRoamHandlers(d RoamDecider, r APSessionResolver) {
	sink, _ := d.(TriggerStatsSink)
	if sink == nil {
		sink, _ = r.(TriggerStatsSink)
	}
	e.Register(capwap.MsgWTPEventRequest, 50, "wsta_roam_wtp_event",
		func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
			for _, el := range req.Elements {
				if el.Type != 0x0025 || len(el.Value) < 6 {
					continue
				}
				for _, sub := range unpackVendorSubs(el.Value[6:]) {
					if sub.Type != 0x58 {
						continue
					}
					trig, err := capwap.ParsePrivRoamingTrigger(sub.Value)
					if err != nil {
						continue
					}
					if sink != nil {
						sink.NoteTrigger(reportAPID(ctx), trig)
					}
					res := d.Decide(reportAPID(ctx), trig)
					if res == nil || len(res.Stations) == 0 {
						continue // "no nbr selected, skip this station"
					}
					for _, m := range res.APUnion {
						if s := r.SessionByAPMAC(m); s != nil {
							_ = e.SendRoamingResult(s, *res)
						}
					}
				}
			}
			return true
		})
}

// reportAPID is filled by the engine's AP registry when available; the
// decider treats 0 as "unverified reporting AP".
func reportAPID(ctx *Ctx) uint16 {
	if ctx != nil && ctx.Session != nil {
		return ctx.Session.APID
	}
	return 0
}

// unpackVendorSubs walks the {u16 type, u16 len, value} sub-element list
// that follows the 6-byte vendor envelope header.
func unpackVendorSubs(v []byte) []capwap.PrivElementValue {
	var out []capwap.PrivElementValue
	for len(v) >= 4 {
		t := capwap.Uint16BE(v)
		l := capwap.Uint16BE(v[2:])
		if int(l)+4 > len(v) {
			break
		}
		out = append(out, capwap.PrivElementValue{Type: t, Value: v[4 : 4+int(l)]})
		v = v[4+int(l):]
	}
	return out
}
