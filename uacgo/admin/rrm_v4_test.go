package admin

import (
	"context"
	"encoding/json"
	"path/filepath"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/mobility"
)

func v4RRMRule() RRMRule {
	r := defaultRRMRule()
	r.StrategyVersion = "v4"
	r.ID = "v4"
	r.Name = "V4"
	r.Channel = true
	r.Power = true
	r.Band5G.Channels = []int{36, 149}
	return r
}

func TestRoamingAndRRMVersionsAreIndependentAndPersistAcrossRestart(t *testing.T) {
	for _, roam := range []string{v4ModeSource, v6ModeSource} {
		for _, radio := range []string{"v4", "v6"} {
			t.Run(roam+"/"+radio, func(t *testing.T) {
				m, e, _, _, _ := rrmPair(t)
				p := defaultMobility()
				p.ModeSource = roam
				if w := callManagement(t, m, "POST", "mobility", p); w.Code != 202 {
					t.Fatal(w.Code, w.Body.String())
				}
				r := v4RRMRule()
				r.StrategyVersion = radio
				r.Frequency = 1
				if w := callManagement(t, m, "POST", "rrm/rules", []RRMRule{r}); w.Code != 202 {
					t.Fatal(w.Code, w.Body.String())
				}
				restarted, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
				if err != nil {
					t.Fatal(err)
				}
				if restarted.config.Mobility.ModeSource != roam || restarted.config.RRM[0].strategyVersion() != radio {
					t.Fatal("selection lost on restart")
				}
				want := mobility.V6Policy
				if roam == v4ModeSource {
					want = mobility.V4Policy
				}
				if roamingPolicy(restarted.config) != want {
					t.Fatal("RF choice changed roaming")
				}
				backup := callManagement(t, m, "GET", "backup", nil)
				var body map[string]any
				if err = json.Unmarshal(backup.Body.Bytes(), &body); err != nil {
					t.Fatal(err)
				}
				if w := callManagement(t, restarted, "POST", "restore", body); w.Code != 202 {
					t.Fatal(w.Code, w.Body.String())
				}
				if restarted.config.Mobility.ModeSource != roam || restarted.config.RRM[0].strategyVersion() != radio {
					t.Fatal("selection lost on backup/restore")
				}
				settleRRMTargets(m)
				job, err := m.startRRM(r, "")
				if err != nil {
					t.Fatal(err)
				}
				if (m.rrmRuns[job.ID].v4 != nil) != (radio == "v4") {
					t.Fatal("roaming choice changed RF engine")
				}
				w := callManagement(t, m, "GET", "mobility/status", nil)
				var status struct {
					PolicyVersion string `json:"policy_version"`
				}
				if err = json.Unmarshal(w.Body.Bytes(), &status); err != nil {
					t.Fatal(err)
				}
				if status.PolicyVersion != mobilityPolicyVersion(m.config) {
					t.Fatal(status)
				}
			})
		}
	}
}

func TestRoamingVersionSelectionKeepsLegacyConfigAndRejectsInvalidCombinations(t *testing.T) {
	m, _ := testController(t)
	p := defaultMobility()
	p.ModeSource = ""
	if w := callManagement(t, m, "POST", "mobility", p); w.Code != 202 || roamingPolicy(m.config) != mobility.V6Policy {
		t.Fatal("legacy compatibility changed", w.Body.String())
	}
	for _, tc := range []struct {
		source string
		mode   int
	}{{"unknown", 2}, {v6ModeSource, 0}, {v6ModeSource, 1}} {
		p.ModeSource, p.NetworkMode = tc.source, tc.mode
		if w := callManagement(t, m, "POST", "mobility", p); w.Code != 400 {
			t.Fatal("invalid strategy/mode accepted", tc, w.Code)
		}
	}
}

func TestRRMFreezesItsOwnVersionAndBlocksConflictingRoamingSwitch(t *testing.T) {
	m, _, _, _, _ := rrmPair(t)
	r := v4RRMRule()
	r.Frequency = 1
	settleRRMTargets(m)
	job, err := m.startRRM(r, "")
	if err != nil {
		t.Fatal(err)
	}
	next := r
	next.StrategyVersion = "v6"
	if w := callManagement(t, m, "POST", "rrm/rules", []RRMRule{next}); w.Code != 202 {
		t.Fatal(w.Code, w.Body.String())
	}
	if m.rrmJobs[job.ID].Rule.strategyVersion() != "v4" || m.rrmRuns[job.ID].v4 == nil {
		t.Fatal("editing a saved rule changed the active measurement")
	}
	p := defaultMobility()
	p.ModeSource = v4ModeSource
	if w := callManagement(t, m, "POST", "mobility", p); w.Code != 400 {
		t.Fatal("same-mode family switch bypassed RRM guard", w.Code, w.Body.String())
	}
	if roamingPolicy(m.config) != mobility.V6Policy {
		t.Fatal("failed switch mutated controller policy")
	}
}

func TestHighPerformanceNetworkRejectsIncompatibleRRMVersionsAndPowerOnly(t *testing.T) {
	m, _ := testController(t)
	m.config = highPerformanceTestConfig()
	r := v4RRMRule()
	r.StrategyVersion = "v6"
	if _, err := m.startRRM(r, ""); err == nil {
		t.Fatal("V6 RRM has no original high-performance path")
	}
	r.StrategyVersion = "v4"
	r.Channel = false
	if _, err := m.startRRM(r, ""); err == nil {
		t.Fatal("V4 pwr_rrm_start requires actual mode2")
	}
	if len(m.rrmJobs) != 0 {
		t.Fatal("rejected optimization left a task")
	}
}

func TestV4RRMSeparateCollectionsWireAndPowerOnlyPreservesChannelBandwidth(t *testing.T) {
	m, e, f, a, b := rrmPair(t)
	r := v4RRMRule()
	r.Frequency = 1
	m.config.RRM = []RRMRule{r}
	settleRRMTargets(m)
	job, err := m.startRRM(r, "")
	if err != nil {
		t.Fatal(err)
	}
	feed := func() {
		m.observeRRMReport(a.ID, a.ConnectedAt, capwap.PrivRrmNeighsList{A: 1, Neighs: a.RRMReports[0].Neighbors})
		m.observeRRMReport(b.ID, b.ConnectedAt, capwap.PrivRrmNeighsList{A: 1, Neighs: b.RRMReports[0].Neighbors})
	}
	feed()
	m.tickRRM(time.Now())
	run := m.rrmRuns[job.ID]
	if run == nil || run.v4 == nil || run.v4.phase != "power" || run.round != 1 || run.receivedCount != 0 || m.rrmJobs[job.ID].State != "collecting" {
		t.Fatal("channel results must begin a fresh power collection")
	}
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	if _, err = e.Request(ctx, a.ID, 7, nil); err != nil {
		t.Fatal(err)
	}
	f.mu.Lock()
	var requests []*capwap.PrivNdpPara
	for _, packet := range f.packets {
		for _, el := range packet.Elements {
			if el.Type == 0x25 && len(el.Value) > 10 && el.Value[7] == 0x5c {
				p, err := capwap.ParsePrivNdpPara(el.Value[10:])
				if err == nil {
					requests = append(requests, p)
				}
			}
		}
	}
	f.mu.Unlock()
	if len(requests) != 2 || requests[0].W3 != 6 || requests[1].W3 != 6 || requests[1].U8c != 254 || requests[1].U8d != 254 {
		t.Fatal("V4 NDP fields/stages", requests)
	}
	feed()
	m.tickRRM(time.Now())
	if got := m.rrmJobs[job.ID]; got.State != "applying" || len(got.Changes) != 2 || got.Changes[0].Channel == got.Changes[1].Channel {
		t.Fatal(got)
	}
	// A TPC-only run must preserve the selected channel/width. V6's
	// bw_apply=1 even for power-only jobs is intentionally a different path.
	r.Channel = false
	a.Capabilities[0].Bandwidths = []int{0, 1}
	width := 1
	advanced := defaultRadioAdvanced(a.Capabilities[0])
	advanced.Bandwidth = 1
	cfg := Config{Radios: []RadioSetting{{AP: a.ID, Radio: 1, Bandwidth: &width, Advanced: &advanced}}}
	nodes, err := rrmNodes(r, []cweng.APStatus{a}, cfg, time.Time{})
	if err != nil {
		t.Fatal(err)
	}
	power, err := newRRMRunForRule(nodes, r)
	if err != nil {
		t.Fatal(err)
	}
	power.received[0] = true
	power.finishV4Pass(r)
	before, _ := linkageRadioState(cfg, a, 1)
	changes, err := power.changes(r, cfg)
	if err != nil || len(changes) != 1 || changes[0].Bandwidth != 1 || changes[0].Channel != linkageChannel(before, a) {
		t.Fatal("TPC changed channel/bandwidth", changes, err)
	}
}

func TestV4RRMConditionalSecondPowerCollectionAndFailurePreservesChannelPlan(t *testing.T) {
	_, _, _, a, b := rrmPair(t)
	c, d := a, b
	c.ID, c.MAC = "02:00:00:00:00:c1", "02:00:00:00:00:c1"
	d.ID, d.MAC = "02:00:00:00:00:d1", "02:00:00:00:00:d1"
	r := v4RRMRule()
	r.Frequency = 1
	nodes, err := rrmNodes(r, []cweng.APStatus{a, b, c, d}, Config{}, time.Time{})
	if err != nil {
		t.Fatal(err)
	}
	run, err := newRRMRunForRule(nodes, r)
	if err != nil {
		t.Fatal(err)
	}
	feed := func() {
		for i := range nodes {
			neighbors := []capwap.RrmNeigh{}
			for j, n := range nodes {
				if i != j {
					neighbors = append(neighbors, capwap.RrmNeigh{MAC: apMAC(n.AP), Samples: []capwap.RrmRSSI{{Radio: 1, RSSI: -40}}})
				}
			}
			run.ingest(i, neighbors, false)
			run.received[i] = true
		}
	}
	run.beginPass(r, time.Now())
	feed()
	if !run.finishV4Pass(r) || run.v4.phase != "power" || run.round != 1 {
		t.Fatal("fresh power stage missing")
	}
	run.beginPass(r, time.Now())
	feed()
	if !run.finishV4Pass(r) || run.round != 2 {
		t.Fatal("changed TPC did not request second round")
	}
	ceiling := run.v4.powers[0].Upper
	run.beginPass(r, time.Now())
	if len(run.v4.powers[0].Neighbors) != 0 || run.v4.powers[0].Upper != ceiling {
		t.Fatal("reset discarded bounds or kept stale neighbors")
	}
	// Timeout with no second-round reports aborts only power application.
	if run.finishV4Pass(r) || !run.v4.powerAborted {
		t.Fatal("inadequate reports must end power stage")
	}
	changes, err := run.changes(r, Config{})
	if err != nil || len(changes) != 4 {
		t.Fatal(changes, err)
	}
	for _, change := range changes {
		if change.Power != 24 || change.Setting.PowerLevel == nil || *change.Setting.PowerLevel != 10 || change.Setting.Channel == nil {
			t.Fatal("failed TPC affected channel result or applied power", change)
		}
	}
}

func TestV4RRMTimeoutMajorityAndIsolatedRadiosPreserveConfiguration(t *testing.T) {
	_, _, _, a, b := rrmPair(t)
	r := v4RRMRule()
	r.Frequency = 1
	r.Power = false
	nodes, err := rrmNodes(r, []cweng.APStatus{a, b}, Config{}, time.Time{})
	if err != nil {
		t.Fatal(err)
	}
	run, err := newRRMRunForRule(nodes, r)
	if err != nil {
		t.Fatal(err)
	}
	run.beginPass(r, time.Now())
	run.deadline = time.Now().Add(-time.Second)
	if !run.collected(time.Now()) {
		t.Fatal("90-second timeout did not release business task")
	}
	run.finishV4Pass(r)
	if !run.v4.channelAborted {
		t.Fatal("no reports passed AP majority")
	}
	changes, err := run.changes(r, Config{})
	if err != nil || len(changes) != 0 {
		t.Fatal("failed collection applied channel/bandwidth", changes, err)
	}
	run, _ = newRRMRunForRule(nodes, r)
	run.received[0] = true
	run.received[1] = true
	run.finishV4Pass(r)
	changes, err = run.changes(r, Config{})
	if err != nil || len(changes) != 0 {
		t.Fatal("isolated vertices must retain channel and bandwidth", changes, err)
	}
}

func TestV4RRMThreeRadioGroupsAndSecondPowerRoundDiscoverNewNeighbors(t *testing.T) {
	a := linkedAPFixture()
	a.Online = true
	a.GeneralCapabilities = []uint32{1 << 27}
	r := v4RRMRule()
	r.Frequency = 2
	r.Band5G.Channels = []int{36, 44, 149, 157}
	r.Band5G.SecondaryChannels = []int{149, 157}
	nodes, err := rrmNodes(r, []cweng.APStatus{a}, Config{}, time.Time{})
	if err != nil {
		t.Fatal(err)
	}
	run, err := newRRMRunForRule(nodes, r)
	if err != nil {
		t.Fatal(err)
	}
	run.beginPass(r, time.Now())
	if len(nodes) != 2 || run.multi5G || run.requests[0].channel != 36 || run.requests[1].channel != 149 {
		t.Fatal("V4 must not use V6's two-pass same-channel scheme", run.requests)
	}
	if !run.v4.graphs[1].APs[0].Forbidden[2] || !run.v4.graphs[1].APs[0].Forbidden[3] {
		t.Fatal("dual5G color reservation missing")
	}
	// The second power collection replaces incoming lists, retaining bounds.
	run.v4.phase = "power"
	run.v4.powers[0].Upper = 18
	run.v4.powers[0].Neighbors = nil
	run.beginPass(r, time.Now())
	self := capwap.RrmNeigh{MAC: apMAC(nodes[0].AP), Samples: []capwap.RrmRSSI{{Radio: nodes[0].Cap.RadioID, RSSI: -55}}}
	run.ingest(0, []capwap.RrmNeigh{self}, true)
	if len(run.v4.powers[0].Neighbors) != 1 || run.v4.powers[0].Upper != 18 {
		t.Fatal("TPC fresh lists/bounds", run.v4.powers[0])
	}
}

func TestV4RRMMeshProjectionUsesParentFiveGHzAndSingleSampleGate(t *testing.T) {
	m, _, _, a, b := rrmPair(t)
	for _, ap := range []*cweng.APStatus{&a, &b} {
		ap.MeshDevice = true
		ap.Radios = 2
		five := ap.Capabilities[0]
		five.RadioID = 2
		five.Band = "5 GHz"
		five.Modes = []int{7}
		five.Bandwidths = []int{0, 1, 3}
		five.Channels = []int{36, 149}
		ap.Capabilities = append(ap.Capabilities, five)
	}
	r := v4RRMRule()
	nodes, err := rrmNodes(r, []cweng.APStatus{a, b}, m.config, time.Time{})
	if err != nil {
		t.Fatal(err)
	}
	run, err := newRRMRunForRule(nodes, r)
	if err != nil {
		t.Fatal(err)
	}
	run.beginPass(r, time.Now())
	child := cweng.APStatus{ID: "02:00:00:00:00:ff", MAC: "02:00:00:00:00:ff", Online: true, MeshDevice: true, MeshParent: b.ID, GeneralCapabilities: []uint32{1 << 27}}
	known := map[string]cweng.APStatus{a.ID: a, b.ID: b, child.ID: child}
	cfg := Config{Mesh: &MeshConfig{Enabled: true}}
	index := 0
	for i, n := range nodes {
		if n.AP.ID == a.ID && n.BandID == 0 {
			index = i
		}
	}
	heard := capwap.RrmNeigh{MAC: apMAC(child), Samples: []capwap.RrmRSSI{{Radio: 1, RSSI: -50}}}
	run.projectV4Mesh(index, []capwap.RrmNeigh{heard}, cfg, known)
	graph := run.v4.graphs[1]
	from := -1
	for i, v := range graph.APs {
		if v.ID == a.ID {
			from = i
		}
	}
	if from < 0 || len(graph.Out[from]) != 1 || graph.APs[graph.Out[from][0].To].ID != b.ID || graph.Out[from][0].Weight != 25 {
		t.Fatal("missing parent5G projection", graph)
	}
	heard.Samples = append(heard.Samples, heard.Samples[0])
	run.projectV4Mesh(index, []capwap.RrmNeigh{heard}, cfg, known)
	if graph.Out[from][0].Weight != 25 {
		t.Fatal("multi-sample observation incorrectly projected")
	}
}
