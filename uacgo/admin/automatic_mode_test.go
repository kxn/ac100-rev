package admin

import (
	"context"
	"encoding/binary"
	"encoding/json"
	"net/http"
	"net/http/httptest"
	"path/filepath"
	"testing"
	"time"
	"uacgo/cweng"
	"uacgo/mobility"
)

func automaticTestConfig(current int) Config {
	c := highPerformanceTestConfig()
	c.Mobility.NetworkMode = 0
	c.Mobility.CurrentMode = current
	return c
}

func TestV4AutomaticAPCountDemotionDoesNotRedistributeOrPromoteOnLeave(t *testing.T) {
	m, _ := testController(t)
	m.config = automaticTestConfig(1)
	for i := 1; i <= 5; i++ {
		ap := highPerformanceTestAP(string(rune('a'+i)), 2)
		m.known[ap.ID] = ap
	}
	ap := highPerformanceTestAP("sixth", 2)
	m.observeAPState(ap)
	if actualMobilityMode(m.config) != 2 || configuredMobilityMode(m.config) != 0 || len(m.config.Radios) != 0 {
		t.Fatal("AP demotion used station redistribution", m.config.Mobility, m.config.Radios)
	}
	ap.Online = false
	m.observeAPState(ap)
	m.tickHighPerformance(time.Now())
	if actualMobilityMode(m.config) != 2 {
		t.Fatal("invented load-drop promotion")
	}
	next := m.config
	p := *next.Mobility
	p.CurrentMode = 1
	next.Mobility = &p
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if actualMobilityMode(m.config) != 2 {
		t.Fatal("editor overwrote controller actual state")
	}
	p = *m.config.Mobility
	p.NetworkMode = 1
	p.CurrentMode = 0
	next = m.config
	next.Mobility = &p
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	p = *m.config.Mobility
	p.NetworkMode = 0
	next = m.config
	next.Mobility = &p
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if actualMobilityMode(m.config) != 1 {
		t.Fatal("manual auto selection failed to recheck low counts")
	}
}

func TestV4AutomaticAPCountUsesRoleInsteadOfRawProductType(t *testing.T) {
	m, _ := testController(t)
	m.config = automaticTestConfig(1)
	for i := 1; i <= 5; i++ {
		ap := highPerformanceTestAP(string(rune('a'+i)), 2)
		m.known[ap.ID] = ap
	}
	sensor := highPerformanceTestAP("sensor", 0)
	sensor.ProductType = 2 // Raw product2 maps to firmware AP-entry role7.
	m.observeAPState(sensor)
	if aps, _ := m.automaticCountsLocked(); aps != 5 || actualMobilityMode(m.config) != 1 {
		t.Fatal("sensor was counted as a normal AP", aps, m.config.Mobility)
	}
	m.observeAPState(highPerformanceTestAP("sixth", 2))
	if actualMobilityMode(m.config) != 2 {
		t.Fatal("real sixth AP did not demote")
	}
}

func TestV4AutomaticStationEntryRespectsCountsIdleStatisticsAndBandwidth(t *testing.T) {
	m, _ := testController(t)
	m.config = automaticTestConfig(1)
	a := highPerformanceTestAP("a", 2)
	b := highPerformanceTestAP("b", 2)
	c := highPerformanceTestAP("c", 2)
	a.EntryID, b.EntryID, c.EntryID = 1, 2, 3
	m.known = map[string]cweng.APStatus{a.ID: a, b.ID: b, c.ID: c}
	limits := mobility.V4AutomaticLimits{APs: 5, Stations: 30}
	m.config.Mobility.AutomaticLimits = &limits
	now := time.Unix(1, 0)
	m.stationStatistics = mobility.StationDB{}
	m.stationStatistics.Start(now)
	// Existing connected records are loaded with the policy fixed while the
	// fixture is constructed; production association callbacks are tested below.
	m.config.Mobility.NetworkMode = 1
	for i := 0; i < 6; i++ {
		m.clients.StationEvent(cweng.ClientEvent{MAC: [6]byte{2, 1, 0, 0, 0, byte(i + 1)}, Kind: "associate", APID: a.ID, RadioID: 1, WLANID: 1, Seen: now})
	}
	for i := 0; i < 6; i++ {
		mac := mobility.MAC{2, 2, 0, 0, 0, byte(i + 1)}
		m.stationStatistics.AssociateAt(mac, b.ID, now)
		m.stationStatistics.ObserveActivity(mac, 2, 0)
		m.stationStatistics.Disconnect(mac, now)
	}
	ch, power, bw, ch5 := 1, 17, 3, 36
	m.config.Radios = []RadioSetting{{AP: c.ID, Radio: 1, Channel: &ch, Power: &power}, {AP: c.ID, Radio: 2, Channel: &ch5, Bandwidth: &bw}}
	m.config.Mobility.NetworkMode = 0
	m.config.Mobility.CurrentMode = 2
	next := m.redistributeCompatibilityChannelsLocked(m.config, func() time.Time { return now })
	if len(next.Radios) != 2 {
		t.Fatal("busy/idle-statistics AP was incorrectly redistributed", next.Radios)
	}
	if *next.Radios[0].Channel != 6 || *next.Radios[0].Power != 17 || *next.Radios[1].Channel != 153 || *next.Radios[1].Bandwidth != 3 {
		t.Fatal("channel-only operation changed unrelated settings", next.Radios)
	}
	keep := m.redistributeCompatibilityChannelsLocked(m.config, func() time.Time { return time.Unix(10, 0) })
	if *keep.Radios[0].Channel != 1 {
		t.Fatal("zero2G lookup must retain prior channel")
	}
}

func TestV4AutomaticAssociationTriggerPersistsActualModeAndRestart(t *testing.T) {
	m, _ := testController(t)
	m.config = automaticTestConfig(1)
	ap := highPerformanceTestAP("02:00:00:00:40:01", 2)
	m.known = map[string]cweng.APStatus{ap.ID: ap}
	for i := 1; i <= 30; i++ {
		m.clients.StationEvent(cweng.ClientEvent{MAC: [6]byte{2, 3, 0, 0, 0, byte(i)}, Kind: "associate", APID: ap.ID, RadioID: 1, WLANID: 1, Seen: time.Now()})
	}
	if actualMobilityMode(m.config) != 1 {
		t.Fatal("demoted at equal station threshold")
	}
	m.clients.StationEvent(cweng.ClientEvent{MAC: [6]byte{2, 3, 0, 0, 0, 31}, Kind: "associate", APID: ap.ID, RadioID: 1, WLANID: 1, Seen: time.Now()})
	if actualMobilityMode(m.config) != 2 || len(m.config.Radios) != 0 {
		t.Fatal("station overflow or per-AP gate failed")
	}
	mux := http.NewServeMux()
	m.mobilityRoutes(mux)
	w := httptest.NewRecorder()
	mux.ServeHTTP(w, httptest.NewRequest("GET", "/api/mobility/status", nil))
	var status struct {
		Configured int `json:"configured_mode"`
		Actual     int `json:"actual_mode"`
	}
	json.Unmarshal(w.Body.Bytes(), &status)
	if status.Configured != 0 || status.Actual != 2 {
		t.Fatal(status)
	}
	e, err := cweng.NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	restarted, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if actualMobilityMode(restarted.config) != 2 {
		t.Fatal("restart promoted sticky compatibility")
	}
}

func TestV4AutomaticCompatibleJoinAndTransitionUseDifferentModeBlocks(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{1 << 25, 0, 1 << 8}
	m.config = automaticTestConfig(2)
	m.known[ap.ID] = ap
	m.applyMobility(context.Background(), ap, m.config)
	f.mu.Lock()
	first := len(f.packets)
	modeBlocks := 0
	for _, p := range f.packets {
		for _, el := range p.Elements {
			if el.Type == 0x25 && len(el.Value) >= 10 && binary.BigEndian.Uint16(el.Value[6:]) == 0x9d {
				modeBlocks++
			}
		}
	}
	f.mu.Unlock()
	if modeBlocks != 0 {
		t.Fatal("new compatibility-mode AP received an invented mode-change block")
	}
	m.highPerformance.ModeTargets = map[string]time.Time{ap.ID: ap.ConnectedAt}
	delete(m.applied, ap.ID+"/roaming")
	m.applyMobility(context.Background(), ap, m.config)
	f.mu.Lock()
	defer f.mu.Unlock()
	order := []uint16{}
	for _, p := range f.packets[first:] {
		for _, el := range p.Elements {
			if el.Type == 0x25 && len(el.Value) >= 10 {
				typ := binary.BigEndian.Uint16(el.Value[6:])
				if typ == 0x9d || typ == 0x57 {
					order = append(order, typ)
				}
			}
		}
	}
	if len(order) != 2 || order[0] != 0x9d || order[1] != 0x57 {
		t.Fatal("transition ordering", order)
	}
}

func TestV4AutomaticDemotionDuringACSDoesNotRestartChannelOptimization(t *testing.T) {
	for _, test := range []struct {
		name           string
		power, waiting bool
	}{
		{"channel", false, false}, {"channel-and-power", true, false},
		{"waiting-channel", false, true}, {"waiting-channel-and-power", true, true},
	} {
		t.Run(test.name, func(t *testing.T) {
			m, _ := testController(t)
			ap := highPerformanceTestAP("02:00:00:00:40:02", 2)
			ap.GeneralCapabilities[0] |= 1 << 27
			m.known = map[string]cweng.APStatus{ap.ID: ap}
			m.config = automaticTestConfig(1)
			if !test.waiting {
				settleHighPerformanceMode(m, ap)
			}
			r := defaultRRMRule()
			r.StrategyVersion = "v4"
			r.ID, r.Name, r.Channel, r.Power = "auto-rrm", "Auto", true, test.power
			r.Band5G.Channels = []int{36, 149}
			job, err := m.startRRM(r, "")
			if err != nil {
				t.Fatal(err)
			}
			m.changeAutomaticModeLocked(2, false, time.Now)
			if m.highPerformance.Timer != nil || m.highPerformance.State == "collecting" {
				t.Fatal("demotion retained high-performance ACS")
			}
			deadline := job.CollectUntil
			if deadline.IsZero() {
				deadline = job.Started.Add(highPerformanceTimeout(m.config.Mobility) + 5*time.Second)
			}
			m.tickRRM(deadline)
			got := m.rrmJobs[job.ID]
			if !got.CommonChannelCancelled || got.CommonChannelPhase {
				t.Fatal("business wait did not observe demotion", got)
			}
			if test.power {
				if got.State != "collecting" || got.Rule.Channel || !got.Rule.Power || m.rrmRuns[job.ID] == nil {
					t.Fatal("power phase must continue without a new channel pass", got)
				}
			} else if got.State != "completed" || len(got.Changes) != 0 || m.rrmRuns[job.ID] != nil {
				t.Fatal("channel-only job must end without SCA or stale changes", got)
			}
		})
	}
}
