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
	r := defaultRRMRule()
	r.ID = "r"
	r.Name = "Rule"
	r.Frequency = 1
	plan, err := planRRM(r, []cweng.APStatus{b, a}, Config{}, time.Now().Add(-time.Minute))
	if err != nil {
		t.Fatal(err)
	}
	if len(plan) != 2 || plan[0].Channel == plan[1].Channel || plan[0].Power != 4 || plan[1].Power != 4 {
		t.Fatal(plan)
	}
	if _, err = planRRM(r, []cweng.APStatus{a, b}, Config{}, time.Now().Add(time.Minute)); err == nil {
		t.Fatal("stale reports used for optimization")
	}
}
func TestRRMScanCommandsAndPersistentConfigPlan(t *testing.T) {
	m, e, f, a, b := rrmPair(t)
	r := defaultRRMRule()
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
	f.mu.Lock()
	if len(f.packets) != 1 {
		f.mu.Unlock()
		t.Fatal("scan command missing")
	}
	p := f.packets[0].Elements[0]
	f.mu.Unlock()
	if p.Value[7] != 0x5c {
		t.Fatal(p)
	}
	ndp, err := capwap.ParsePrivNdpPara(p.Value[10:])
	if err != nil || ndp.U8b != 0xab || ndp.W2 != 60 || !bytes.Equal(ndp.Tail, []byte{1, 6, 11}) {
		t.Fatal(ndp, err)
	}
	// Advance the durable job's timing, independently from actual AP reports.
	m.mu.Lock()
	job = m.rrmJobs[job.ID]
	job.Started = time.Now().Add(-80 * time.Second)
	job.Scans = map[string]time.Time{a.ID: time.Now().Add(-70 * time.Second), b.ID: time.Now().Add(-70 * time.Second)}
	m.rrmJobs[job.ID] = job
	m.mu.Unlock()
	m.tickRRM(time.Now())
	if j := m.rrmJobs[job.ID]; j.State != "applying" || len(j.Changes) != 2 || m.config.Version != 1 || len(m.config.Radios) != 2 {
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
	r := defaultRRMRule()
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
	m.config.Version++
	m.tickRRM(time.Now())
	if m.rrmJobs[j.ID].State != "failed" || len(m.config.Radios) != 0 {
		t.Fatal("changed config overwritten")
	}
}

func settleRRMTargets(m *Manager) {
	for _, ap := range m.known {
		m.settled[ap.ID] = configurationKey(effectiveRadioConfig(m.config, ap), ap.ConnectedAt)
	}
}
func TestRRMBondedSpectrumAndInvalidCandidates(t *testing.T) {
	_, _, _, a, b := rrmPair(t)
	am, _ := parseMAC6(a.ID)
	bm, _ := parseMAC6(b.ID)
	node := func(ap cweng.APStatus, other [6]byte) rrmNode {
		return rrmNode{AP: ap, Cap: cweng.RadioCapability{RadioID: 1}, BandID: 1, Band: RRMBand{Bandwidth: 3}, Report: cweng.RRMReport{Neighbors: []capwap.RrmNeigh{{MAC: other, Samples: []capwap.RrmRSSI{{Radio: 1, RSSI: -45}}}}}}
	}
	aa, bb := node(a, bm), node(b, am)
	if channelCost(aa, bb, 48, 52) != 0 || channelCost(aa, bb, 36, 48) == 0 {
		t.Fatal("bonded spectrum overlap wrong")
	}
	c := cweng.RadioCapability{Band: "5 GHz", Channels: []int{36, 149, 165}}
	if got := rrmAllowed(c, RRMBand{Bandwidth: 5, Channels: c.Channels}); len(got) != 1 || got[0] != 36 {
		t.Fatal(got)
	}
}
func TestRRMRequiresSettledConfiguration(t *testing.T) {
	m, _, _, _, _ := rrmPair(t)
	r := defaultRRMRule()
	r.ID = "r"
	r.Name = "r"
	m.mu.Lock()
	_, err := m.startRRM(r, "")
	m.mu.Unlock()
	if err == nil {
		t.Fatal("started scan while AP was configuring")
	}
}
