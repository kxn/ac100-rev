package cweng

import (
	"uacgo/capwap"
)

// AP statistics ingestion — the AC's BSS table (stats_db_ssid_update →
// stats_db_bssid_update @0x66ff64) is fed from the 0x54 AP statistics
// report (_stats_pkt_ap_request @0x673b88: ssid rows carry
// {radio_id, wlan_id, bssid}).
//
// RegisterStatsHandlers wires the msg 9 listener that seeds the steering
// registry's BSS rows from those reports.
func (e *Engine) RegisterStatsHandlers(reg *SteerRegistry, apIDOf func([6]byte) uint16) {
	e.Register(capwap.MsgWTPEventRequest, 60, "stats_wtp_event",
		func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
			var apMAC [6]byte
			if ctx != nil && ctx.Session != nil {
				apMAC = ctx.Session.APMAC
			}
			for _, el := range req.Elements {
				if el.Type != 0x0025 || len(el.Value) < 6 {
					continue
				}
				for _, sub := range unpackVendorSubs(el.Value[6:]) {
					if sub.Type != 0x54 {
						continue
					}
					rows, err := capwap.ParsePrivApStatisticsRows(sub.Value)
					if err != nil {
						continue
					}
					apID := apIDOf(apMAC)
					for _, s := range rows.Ssids {
						reg.RegisterBSS(s.BSSID, BSSRow{
							APID: apID, APMAC: apMAC,
							RadioID: s.RadioID, WLANID: s.WLANID,
						})
					}
				}
			}
			return true
		})
}
