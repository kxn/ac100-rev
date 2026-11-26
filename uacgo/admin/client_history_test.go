package admin

import (
	"encoding/json"
	"net/http/httptest"
	"path/filepath"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestClientSignalHistoryUsesActualRSSITimeAndSurvivesRestart(t *testing.T) {
	m, e := testController(t)
	now := time.Now()
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	rssi := int8(-60)
	ap := cweng.APStatus{ID: "a", Online: true, ConnectedAt: now.Add(-time.Minute)}
	m.clients.StationEvent(cweng.ClientEvent{APID: "a", MAC: mac, RadioID: 1, WLANID: 1, SSID: "Office", ServiceID: "office", Kind: "associate", State: "connected", Seen: now, RSSI: &rssi})
	m.captureHistory([]cweng.APStatus{ap}, now)
	// A later IP report advances general liveness, but isn't a new RSSI sample.
	m.clients.StationEvent(cweng.ClientEvent{APID: "a", MAC: mac, Kind: "ip", IP: "192.0.2.20", Seen: now.Add(time.Minute)})
	m.captureHistory([]cweng.APStatus{ap}, now.Add(time.Minute))
	if len(m.history.Clients) != 1 || m.history.Clients[0].RSSI != -60 {
		t.Fatal("re-timed a cached RSSI value", m.history.Clients)
	}
	rssi2 := int8(-48)
	m.clients.StationEvent(cweng.ClientEvent{APID: "a", MAC: mac, RadioID: 1, WLANID: 1, Kind: "statistics", Seen: now.Add(65 * time.Second), RSSI: &rssi2, Statistics: &cweng.ClientStatistics{}})
	m.captureHistory([]cweng.APStatus{ap}, now.Add(65*time.Second))
	if len(m.history.Clients) != 2 {
		t.Fatal(m.history.Clients)
	}
	m.captureHistory([]cweng.APStatus{ap}, now.Add(100*time.Second)) // Flush the buffered point without inventing another RSSI measurement.
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if len(restored.history.Clients) != 2 {
		t.Fatal("client signal history was not persisted")
	}
	w := httptest.NewRecorder()
	restored.Handler().ServeHTTP(w, httptest.NewRequest("GET", "http://localhost/api/clients/02:03:04:05:06:07/history?duration=3600", nil))
	var response struct {
		Samples []ClientSignalSample `json:"samples"`
	}
	if err = json.Unmarshal(w.Body.Bytes(), &response); err != nil || w.Code != 200 || len(response.Samples) != 2 || response.Samples[0].SSID != "Office" {
		t.Fatal(w.Code, w.Body.String(), err)
	}
}

func TestClientSignalHistoryRejectsUnconfirmedStaleAndWrongSession(t *testing.T) {
	m, _ := testController(t)
	now := time.Now()
	rssi := int8(-60)
	base := cweng.ClientEvent{MAC: [6]byte{2, 3, 4, 5, 6, 7}, APID: "a", RadioID: 1, WLANID: 1, RSSI: &rssi, RSSIAt: now, State: "connected"}
	ap := cweng.APStatus{ID: "a", Online: true, ConnectedAt: now.Add(-time.Minute)}
	for _, c := range []cweng.ClientEvent{func() cweng.ClientEvent { x := base; x.State = "associating"; return x }(), func() cweng.ClientEvent { x := base; x.RSSIAt = now.Add(-2 * time.Minute); return x }(), func() cweng.ClientEvent { x := base; x.RSSI = nil; return x }()} {
		if m.captureClientSignalsLocked([]cweng.ClientEvent{c}, []cweng.APStatus{ap}, now) {
			t.Fatal("invalid signal sample accepted", c)
		}
	}
	ap.ConnectedAt = now.Add(time.Second)
	if m.captureClientSignalsLocked([]cweng.ClientEvent{base}, []cweng.APStatus{ap}, now) {
		t.Fatal("old session sample accepted")
	}
	m.history.Clients = []ClientSignalSample{{At: now.Add(-2 * time.Hour)}, {At: now}}
	m.pruneHistory(now)
	if len(m.history.Clients) != 1 {
		t.Fatal("client signal retention failed")
	}
	for _, url := range []string{"/api/clients/bad/history", "/api/clients/02:03:04:05:06:07/history?duration=-1", "/api/clients/02:03:04:05:06:07/history?duration=3601", "/api/clients/02:03:04:05:06:07/history?limit=0"} {
		w := httptest.NewRecorder()
		m.Handler().ServeHTTP(w, httptest.NewRequest("GET", "http://localhost"+url, nil))
		if w.Code != 400 {
			t.Fatal(url, w.Code)
		}
	}
}
