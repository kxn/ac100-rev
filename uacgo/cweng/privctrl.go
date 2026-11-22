package cweng

import (
	"uacgo/capwap"
)

// Private control-plane plumbing: apdb negotiation listener and the
// statistics/roaming control senders.

// ApdbSink receives the capability blob an AP self-reports in private
// element 0x51 (registry.tsv: apdb_pkt_init registers msg 1/3 at priority
// 0x100=256 — _apdb_pkt_discover_req_listen/_apdb_pkt_join_req_listen).
type ApdbSink interface {
	ApdbInfo(session *Session, info capwap.PrivApdbInfo)
}

// RegisterApdbHandlers wires the msg 1 and msg 3 listeners that pull 0x51
// out of discovery/join requests. Runs last (priority 256) like the vendor.
func (e *Engine) RegisterApdbHandlers(sink ApdbSink) {
	handler := func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		for _, el := range req.Elements {
			if el.Type != 0x0025 || len(el.Value) < 6 {
				continue
			}
			v := el.Value[6:]
			for len(v) >= 4 {
				t := capwap.Uint16BE(v)
				l := capwap.Uint16BE(v[2:])
				if int(l)+4 > len(v) {
					break
				}
				if t == 0x51 {
					if info, err := capwap.ParsePrivApdbInfo(v[4 : 4+int(l)]); err == nil {
						sink.ApdbInfo(ctx.Session, info)
					}
				}
				v = v[4+int(l):]
			}
		}
		return true
	}
	e.Register(capwap.MsgDiscoveryRequest, 256, "apdb_discover", handler)
	e.Register(MsgJoin, 256, "apdb_join", handler)
}

// SendStatsControl mirrors cw_priv_statistics_control (0x55, 9 bytes):
// u8×3 + BE16×3 — the AC's statistics polling parameters.
func (e *Engine) SendStatsControl(s *Session, c capwap.PrivStatisticsControl) error {
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0x55, Value: c.AssembleValue()})
}

// SendRoamingControl mirrors cw_priv_roaming_control (0x57, 36 bytes):
// 36 raw parameter bytes — the AC's roaming control push.
func (e *Engine) SendRoamingControl(s *Session, c capwap.PrivRoamingControl) error {
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0x57, Value: c.AssembleValue()})
}

// SendStateReportPeriod mirrors cw_priv_stat_prd (0x0c-private, 8 bytes):
// two BE32 report-period words.
func (e *Engine) SendStateReportPeriod(s *Session, c capwap.PrivStatPrd) error {
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0x0c, Value: c.AssembleValue()})
}
