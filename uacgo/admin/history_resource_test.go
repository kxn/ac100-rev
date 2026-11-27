package admin

import (
	"bytes"
	"encoding/json"
	"math"
	"net/http/httptest"
	"os"
	"path/filepath"
	"reflect"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestHistoryStreamingKeepsDocumentAndAtomicity(t *testing.T) {
	now := time.Now()
	for _, h := range []WirelessHistory{{}, {APCounts: []APCountSample{}, Radios: []RadioSample{}, Events: []StationTransition{}}, {APCounts: []APCountSample{{At: now, Online: 1}}, Radios: []RadioSample{{At: now, Metrics: map[string]float64{"usage": 20}}}, Clients: []ClientSignalSample{{At: now, SSID: "Office"}}, Events: []StationTransition{{ClientTransition: cweng.ClientTransition{At: now}}}}} {
		var out bytes.Buffer
		if err := writeHistory(&out, h); err != nil {
			t.Fatal(err)
		}
		if !reflect.DeepEqual(jsonValue(h), jsonValue(json.RawMessage(out.Bytes()))) {
			t.Fatal("streaming changed history document")
		}
	}
	dir := t.TempDir()
	m := &Manager{path: filepath.Join(dir, "controller.json"), history: WirelessHistory{APCounts: []APCountSample{{At: now, Online: 1}}}}
	if err := m.saveHistoryLocked(); err != nil {
		t.Fatal(err)
	}
	before, _ := os.ReadFile(m.historyPath())
	m.history.Radios = []RadioSample{{Metrics: map[string]float64{"bad": math.NaN()}}}
	if err := m.saveHistoryLocked(); err == nil {
		t.Fatal("invalid history committed")
	}
	after, _ := os.ReadFile(m.historyPath())
	if !bytes.Equal(before, after) {
		t.Fatal("failed streaming save replaced previous document")
	}
}

func TestHistoryExpiryKeepsOrderAndReleasesRemovedReferences(t *testing.T) {
	now := time.Now()
	rows := []RadioSample{{At: now.Add(-25 * time.Hour), Metrics: map[string]float64{"expired": 1}}, {At: now.Add(-time.Hour)}, {At: now.Add(-2 * time.Hour)}, {At: now}}
	kept, expiry := retainHistory(rows, now, 24*time.Hour, 2, func(r RadioSample) time.Time { return r.At })
	if len(kept) != 2 || kept[0].At != now.Add(-2*time.Hour) || !expiry.Equal(now.Add(22*time.Hour)) {
		t.Fatal("retention changed insertion order or expiry", kept, expiry)
	}
	if !reflect.DeepEqual(rows[2:], []RadioSample{{}, {}}) {
		t.Fatal("removed records remain reachable")
	}
	m := &Manager{historySaved: now, history: WirelessHistory{APCounts: []APCountSample{{At: now}}, Radios: []RadioSample{{At: now.Add(-24*time.Hour + time.Second)}}}}
	m.pruneHistory(now)
	m.captureHistory(nil, now.Add(2*time.Second))
	if len(m.history.Radios) != 0 || !m.historyDirty {
		t.Fatal("idle expiry was skipped")
	}
}

func TestHistoryQueriesFilterBeforeApplyingTailLimit(t *testing.T) {
	m, _ := testController(t)
	now := time.Now()
	for i := range 6 {
		ap := "a"
		if i%2 != 0 {
			ap = "b"
		}
		m.history.Radios = append(m.history.Radios, RadioSample{AP: ap, At: now.Add(-time.Duration(i) * time.Second), Channel: i})
	}
	w := httptest.NewRecorder()
	m.Handler().ServeHTTP(w, httptest.NewRequest("GET", "http://localhost/api/history?ap=a&limit=2", nil))
	var out WirelessHistory
	if err := json.Unmarshal(w.Body.Bytes(), &out); err != nil {
		t.Fatal(err)
	}
	if w.Code != 200 || len(out.Radios) != 2 || out.Radios[0].Channel != 2 || out.Radios[1].Channel != 4 {
		t.Fatal("limit changed query order", w.Code, out)
	}
}

func TestNewHistorySamplesAdvanceExpiryForOutOfOrderReports(t *testing.T) {
	now := time.Now()
	m := &Manager{path: filepath.Join(t.TempDir(), "controller.json"), historySaved: now, history: WirelessHistory{APCounts: []APCountSample{{At: now}}, Radios: []RadioSample{{At: now}}}}
	m.pruneHistory(now)
	observed := now.Add(-4 * time.Minute)
	ap := cweng.APStatus{ID: "a", Online: true, Telemetry: &cweng.WirelessTelemetry{ReceivedAt: now, Radios: []cweng.WirelessRadio{{RadioID: 1, StatisticsAt: observed}}}}
	m.captureHistory([]cweng.APStatus{ap}, now)
	if !m.historyExpiry.Equal(observed.Add(24 * time.Hour)) {
		t.Fatal("new earlier expiry was missed", m.historyExpiry)
	}
	m.captureHistory(nil, now.Add(24*time.Hour-3*time.Minute))
	if len(m.history.Radios) != 1 || !m.history.Radios[0].At.Equal(now) {
		t.Fatal("out of order expiration changed retention", m.history.Radios)
	}
}
