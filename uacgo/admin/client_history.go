package admin

import (
	"fmt"
	"net"
	"net/http"
	"slices"
	"strconv"
	"time"
	"uacgo/cweng"
)

type ClientSignalSample struct {
	At      time.Time `json:"at"`
	MAC     string    `json:"mac"`
	AP      string    `json:"ap_id"`
	Radio   uint8     `json:"radio_id"`
	WLAN    uint32    `json:"wlan_id"`
	SSID    string    `json:"ssid"`
	Service string    `json:"service_id"`
	RSSI    int8      `json:"rssi_dbm"`
}

func clientSignalKey(r ClientSignalSample) string {
	return fmt.Sprintf("%s/%s/%d/%d/%s/%s", r.MAC, r.AP, r.Radio, r.WLAN, r.Service, r.SSID)
}

// Captures fresh confirmed-client RSSI reports, not last-known values retimed
// by an unrelated IP update or a poll of the management UI.
func (m *Manager) captureClientSignalsLocked(clients []cweng.ClientEvent, aps []cweng.APStatus, now time.Time) bool {
	if m.historyClientSamples == nil {
		m.historyClientSamples = map[string]time.Time{}
	}
	byAP := map[string]cweng.APStatus{}
	for _, ap := range aps {
		byAP[ap.ID] = ap
	}
	changed := false
	for _, c := range clients {
		ap, ok := byAP[c.APID]
		if !ok || !ap.Online || c.State != "connected" || c.RadioID == 0 || c.WLANID == 0 || c.RSSI == nil || *c.RSSI >= 0 || c.RSSIAt.IsZero() || c.RSSIAt.Before(ap.ConnectedAt) || now.Sub(c.RSSIAt) > 90*time.Second || c.RSSIAt.After(now) {
			continue
		}
		r := ClientSignalSample{At: c.RSSIAt, MAC: net.HardwareAddr(c.MAC[:]).String(), AP: c.APID, Radio: c.RadioID, WLAN: c.WLANID, SSID: c.SSID, Service: c.ServiceID, RSSI: *c.RSSI}
		key := clientSignalKey(r)
		if last := m.historyClientSamples[key]; !r.At.After(last) || r.At.Sub(last) < 30*time.Second {
			continue
		}
		m.history.Clients = append(m.history.Clients, r)
		m.noteHistoryExpiry(r.At, time.Hour)
		m.historyClientSamples[key] = r.At
		changed = true
	}
	return changed
}

func (m *Manager) clientSignalHistoryHTTP(w http.ResponseWriter, r *http.Request) {
	mac, err := net.ParseMAC(r.PathValue("mac"))
	if err != nil || len(mac) != 6 || mac[0]&1 != 0 || mac.String() == "00:00:00:00:00:00" {
		jsonReply(w, 400, map[string]string{"error": "客户端 MAC 无效"})
		return
	}
	duration, limit := 300, 1000
	q := r.URL.Query()
	if q.Get("duration") != "" {
		duration, err = strconv.Atoi(q.Get("duration"))
		if err != nil || duration < 1 || duration > 3600 {
			jsonReply(w, 400, map[string]string{"error": "duration 为1–3600秒"})
			return
		}
	}
	if q.Get("limit") != "" {
		limit, err = strconv.Atoi(q.Get("limit"))
		if err != nil || limit < 1 || limit > 10000 {
			jsonReply(w, 400, map[string]string{"error": "limit 为1–10000"})
			return
		}
	}
	since := time.Now().Add(-time.Duration(duration) * time.Second)
	rows := []ClientSignalSample{}
	macText, ap := mac.String(), q.Get("ap")
	m.mu.Lock()
	for i := len(m.history.Clients) - 1; i >= 0 && len(rows) < limit; i-- {
		s := m.history.Clients[i]
		if s.MAC == macText && !s.At.Before(since) && (ap == "" || s.AP == ap) {
			rows = append(rows, s)
		}
	}
	m.mu.Unlock()
	slices.Reverse(rows)
	jsonReply(w, 200, map[string]any{"samples": rows, "retention_seconds": 3600, "duration": duration})
}
