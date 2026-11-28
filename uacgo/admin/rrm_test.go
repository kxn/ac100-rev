package admin

import (
	"bytes"
	"context"
	"path/filepath"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func rrmPair(t *testing.T) (*Manager, *cweng.Engine, *deferredAP, cweng.APStatus, cweng.APStatus) {
	t.Helper()
	m, e := testController(t)
	f, a := newDeferredAP(t, e)
	_, b := newDeferredAP(t, e)
	for _, ap := range []*cweng.APStatus{&a, &b} {
		ap.GeneralCapabilities = []uint32{1 << 27}
		ap.MAC = ap.ID
		ap.Capabilities = []cweng.RadioCapability{{RadioID: 1, Band: "2.4 GHz", Channels: []int{1, 6, 11}, Modes: []int{6}, Bandwidths: []int{0}, MinPower: 3, MaxPower: 24, DefaultPower: 24, MaxClients: 64}}
		ap.RadioStatus = []cweng.RadioStatus{{Radio: 1, Channel: 1, Power: 24}}
	}
	am, _ := parseMAC6(a.ID)
	bm, _ := parseMAC6(b.ID)
	a.RRMReports = []cweng.RRMReport{{Radio: 1, ReceivedAt: time.Now(), Neighbors: []capwap.RrmNeigh{{MAC: bm, Samples: []capwap.RrmRSSI{{Radio: 1, Power: 24, RSSI: -45}}}}}}
	b.RRMReports = []cweng.RRMReport{{Radio: 1, ReceivedAt: time.Now(), Neighbors: []capwap.RrmNeigh{{MAC: am, Samples: []capwap.RrmRSSI{{Radio: 1, Power: 24, RSSI: -45}}}}}}
	m.known = map[string]cweng.APStatus{a.ID: a, b.ID: b}
	return m, e, f, a, b
}
func TestRRMMeasuredGraphSeparatesChannelsAndBoundsPower(t *testing.T) {
	_, _, _, a, b := rrmPair(t)
	r := rrmTestRule()
	r.ID = "r"
	r.Name = "Rule"
	r.Frequency = 1
	plan, err := planRRM(r, []cweng.APStatus{b, a}, Config{}, time.Now().Add(-time.Minute))
	if err != nil {
		t.Fatal(err)
	}
	if len(plan) != 2 || plan[0].Channel == plan[1].Channel || plan[0].Power != 24 || plan[1].Power != 24 {
		t.Fatal(plan)
	}
	if _, err = planRRM(r, []cweng.APStatus{a, b}, Config{}, time.Now().Add(time.Minute)); err != nil {
		t.Fatal("timeout permits a graph without reports", err)
	}
}
func TestRRMScanCommandsAndPersistentConfigPlan(t *testing.T) {
	m, e, f, a, b := rrmPair(t)
	baseVersion := m.config.Version
	r := rrmTestRule()
	r.ID = "r"
	r.Name = "Rule"
	r.Frequency = 1
	m.config.RRM = []RRMRule{r}
	settleRRMTargets(m)
	m.mu.Lock()
	job, err := m.startRRM(r, "")
	m.mu.Unlock()
	if err != nil {
		t.Fatal(err)
	}
	if !m.rrmStep(context.Background(), a) {
		t.Fatal("scan did not hold reconciliation")
	}
	// Wait through the transport FIFO; submission itself does not wait for ACK.
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	if _, err = e.Request(ctx, a.ID, 7, nil); err != nil {
		t.Fatal(err)
	}
	f.mu.Lock()
	var ndps []capwap.Element
	for _, packet := range f.packets {
		for _, el := range packet.Elements {
			if el.Type == 0x25 && len(el.Value) >= 10 && el.Value[6] == 0 && el.Value[7] == 0x5c {
				ndps = append(ndps, el)
			}
		}
	}
	f.mu.Unlock()
	if len(ndps) != 1 {
		t.Fatal("scan command missing or duplicated", len(ndps))
	}
	p := ndps[0]
	if p.Value[7] != 0x5c {
		t.Fatal(p)
	}
	ndp, err := capwap.ParsePrivNdpPara(p.Value[10:])
	if err != nil || ndp.U8b != 0xab || ndp.W2 != 60 || !bytes.Equal(ndp.Tail, []byte{1}) || ndp.U8c != 6 || ndp.U8d != 0 || ndp.U8e != 24 {
		t.Fatal(ndp, err)
	}
	// Acknowledgements do not finish collection. Both requested radios must
	// report, or the independent90-second timer must expire.
	m.mu.Lock()
	run := m.rrmRuns[job.ID]
	for index, q := range run.requests {
		run.markDispatched(index, q, time.Now())
	}
	m.mu.Unlock()
	m.observeRRMReport(a.ID, a.ConnectedAt, capwap.PrivRrmNeighsList{A: 1, Neighs: a.RRMReports[0].Neighbors})
	m.tickRRM(time.Now())
	if m.rrmJobs[job.ID].State != "collecting" {
		t.Fatal("partial reports finished early")
	}
	m.observeRRMReport(b.ID, b.ConnectedAt, capwap.PrivRrmNeighsList{A: 1, Neighs: b.RRMReports[0].Neighbors})
	m.tickRRM(time.Now())
	if j := m.rrmJobs[job.ID]; j.State != "applying" || len(j.Changes) != 2 || m.config.Version != baseVersion+1 || len(m.config.Radios) != 2 {
		t.Fatal(j, m.config)
	}
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if restored.rrmJobs[job.ID].State != "applying" {
		t.Fatal("planned job not recovered")
	}
}
func TestRRMRejectsConfigChangesAndInterruptedMeasurement(t *testing.T) {
	m, e, _, _, _ := rrmPair(t)
	r := rrmTestRule()
	r.ID = "r"
	r.Name = "Rule"
	settleRRMTargets(m)
	m.mu.Lock()
	j, err := m.startRRM(r, "")
	m.mu.Unlock()
	if err != nil {
		t.Fatal(err)
	}
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if restored.rrmJobs[j.ID].State != "failed" {
		t.Fatal("restart falsely continued measurement")
	}
	m.config.Radios = append(m.config.Radios, RadioSetting{AP: "bypass", Radio: 1})
	m.tickRRM(time.Now())
	if m.rrmJobs[j.ID].State != "failed" || len(m.config.Radios) != 1 {
		t.Fatal("changed config overwritten")
	}
}

func settleRRMTargets(m *Manager) {
	for _, ap := range m.known {
		m.settled[ap.ID] = configurationKey(effectiveRadioConfig(m.config, ap), ap.ConnectedAt)
	}
}
func TestRRMCandidateOrderComesFromAPMutexDomain(t *testing.T) {
	c := cweng.RadioCapability{Band: "5 GHz", Channels: []int{36, 149, 165}, MutexChannels: "149 36"}
	got := rrmAllowed(c, RRMBand{Bandwidth: 5, Channels: []int{36, 149, 165}})
	if len(got) != 2 || got[0] != 149 || got[1] != 36 {
		t.Fatal(got)
	}
}
func TestRRMRequiresSettledConfiguration(t *testing.T) {
	m, _, _, _, _ := rrmPair(t)
	r := rrmTestRule()
	r.ID = "r"
	r.Name = "r"
	m.mu.Lock()
	_, err := m.startRRM(r, "")
	m.mu.Unlock()
	if err == nil {
		t.Fatal("started scan while AP was configuring")
	}
}

// Deliberate test inputs, not firmware editor defaults.
func rrmTestRule() RRMRule {
	r := defaultRRMRule()
	r.Enabled, r.Channel, r.Power = true, true, true
	r.Band2G.MinPower, r.Band2G.MaxPower = 3, 24
	r.Band5G.MinPower, r.Band5G.MaxPower, r.Band5G.Bandwidth = 5, 27, 3
	r.Band5G.Channels = []int{36, 40, 44, 48, 149, 153, 157, 161}
	return r
}
