package admin

import (
	"context"
	"net/http"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func (m *Manager) protectionScanRoutes(mux *http.ServeMux) {
	mux.HandleFunc("POST /api/aps/{id}/arp-scan", func(w http.ResponseWriter, r *http.Request) {
		var ap *cweng.APStatus
		for _, a := range m.APs() {
			if a.ID == r.PathValue("id") && a.Online {
				v := a
				ap = &v
			}
		}
		// V6 uac_arp_defend_do_scan@4c4db0 selects main16/sub1.
		// Sub0 is the extended defense mode/scope, not the scan operation.
		if ap == nil || !ap.SupportsARPScan() {
			jsonReply(w, 409, map[string]string{"error": "AP 未在线或未声明 ARP 扫描子能力"})
			return
		}
		m.mu.Lock()
		busy := m.upgradeBusyLocked(ap.ID)
		m.mu.Unlock()
		if busy {
			jsonReply(w, 409, map[string]string{"error": "AP 正在升级"})
			return
		}
		ctx, cancel := context.WithTimeout(cweng.PinAP(r.Context(), *ap), 5*time.Second)
		defer cancel()
		at := time.Now()
		_, err := m.engine.Request(ctx, ap.ID, 7, []capwap.Element{privateSetting(0xca, []byte{0, 0, 0})})
		if err != nil {
			jsonReply(w, 502, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]any{"ap_id": ap.ID, "requested_at": at, "state": "acknowledged"})
	})
	mux.HandleFunc("GET /api/aps/{id}/arp-scan", func(w http.ResponseWriter, r *http.Request) {
		for _, ap := range m.APs() {
			if ap.ID == r.PathValue("id") {
				jsonReply(w, 200, map[string]any{"online": ap.Online, "report": ap.ARPScan})
				return
			}
		}
		jsonReply(w, 404, map[string]string{"error": "AP 不存在"})
	})
}
