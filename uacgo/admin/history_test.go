package admin

import (
	"encoding/json"
	"net/http/httptest"
	"path/filepath"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestWirelessHistoryPersistsFreshSamplesAndConfirmedTransitions(t *testing.T) {
	m, e := testController(t)
	now := time.Now()
	mac := [6]byte{2, 1, 2, 3, 4, 5}
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Kind: "probe", Seen: now.Add(-time.Second)})
	if len(m.clients.Transitions(0)) != 0 {
		t.Fatal("admission permission counted as online")
	}
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Kind: "associate", Seen: now})
	ap := cweng.APStatus{ID: "a", Online: true, Telemetry: &cweng.WirelessTelemetry{ReceivedAt: now, Radios: []cweng.WirelessRadio{{RadioID: 1, ReceivedAt: now, StatisticsAt: now, Data: map[string]json.RawMessage{"channelUsage": json.RawMessage(`[10,20,30]`)}}}}}
	m.captureHistory([]cweng.APStatus{ap}, now)
	m.captureHistory([]cweng.APStatus{ap}, now.Add(time.Minute))
	if len(m.history.Radios) != 1 || m.history.Radios[0].Metrics["channelUsage"] != 30 || len(m.history.Events) != 1 {
		t.Fatal(m.history)
	}
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: "b", RadioID: 2, WLANID: 1, Kind: "associate", State: "connected", Seen: now.Add(2 * time.Second)})
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Kind: "disassociate", State: "disconnected", Seen: now.Add(3 * time.Second)})
	m.captureHistory(nil, now.Add(2*time.Minute))
	if len(m.history.Events) != 2 || m.history.Events[1].Kind != "roamed" {
		t.Fatal(m.history.Events)
	}
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if len(restored.history.Events) != 2 || len(restored.history.Radios) != 1 {
		t.Fatal("wireless history not recovered")
	}
	r := httptest.NewRecorder()
	restored.Handler().ServeHTTP(r, httptest.NewRequest("GET", "http://localhost/api/history?ap=b", nil))
	var out WirelessHistory
	if err = json.Unmarshal(r.Body.Bytes(), &out); err != nil || len(out.Events) != 1 || out.Events[0].FromAP != "a" {
		t.Fatal(r.Code, r.Body.String(), err)
	}
}

func TestHistoryRejectsNonFiniteMetricsAndPrunesExpiredData(t *testing.T) {
	for _, raw := range []string{`"NaN"`, `"+Inf"`, `"-Inf"`, `[]`, `{}`} {
		if _, ok := latestMetric(json.RawMessage(raw)); ok {
			t.Fatal("non-numeric AP sample accepted", raw)
		}
	}
	m, _ := testController(t)
	now := time.Now()
	m.history.Radios = []RadioSample{{At: now.Add(-25 * time.Hour)}, {At: now.Add(-time.Minute)}}
	m.history.Events = []StationTransition{{ClientTransition: cweng.ClientTransition{At: now.Add(-8 * 24 * time.Hour)}}, {ClientTransition: cweng.ClientTransition{At: now}}}
	m.pruneHistory(now)
	if len(m.history.Radios) != 1 || len(m.history.Events) != 1 {
		t.Fatal("history retention", m.history)
	}
}

func TestAPInventoryTrendCountsControllerSessionsAndExcludesReplacedDevices(t *testing.T) {
	m, _ := testController(t)
	now := time.Now()
	m.config.RetiredAPs = []string{"retired"}
	aps := []cweng.APStatus{{ID: "online", Online: true}, {ID: "offline"}, {ID: "retired", Online: true}}
	m.captureHistory(aps, now)
	m.captureHistory(aps, now.Add(10*time.Second))
	if len(m.history.APCounts) != 1 {
		t.Fatal("unchanged inventory sampled too frequently")
	}
	first := m.history.APCounts[0]
	if first.Online != 1 || first.Offline != 1 || first.Total != 2 {
		t.Fatal(first)
	}
	aps[0].Online = false
	m.captureHistory(aps, now.Add(15*time.Second))
	if len(m.history.APCounts) != 2 || m.history.APCounts[1].Online != 0 || m.history.APCounts[1].Offline != 2 {
		t.Fatal("session transition not recorded", m.history.APCounts)
	}
	m.captureHistory(aps, now.Add(2*time.Minute))
	if len(m.history.APCounts) != 3 {
		t.Fatal("periodic AC inventory sample absent")
	}
	w := httptest.NewRecorder()
	m.Handler().ServeHTTP(w, httptest.NewRequest("GET", "http://localhost/api/history?limit=1", nil))
	var response WirelessHistory
	if err := json.Unmarshal(w.Body.Bytes(), &response); err != nil || len(response.APCounts) != 1 || response.APCounts[0].Total != 2 {
		t.Fatal(w.Code, w.Body.String(), err)
	}
}
