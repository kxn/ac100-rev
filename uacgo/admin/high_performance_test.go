package admin

import (
	"context"
	"encoding/binary"
	"path/filepath"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/mobility"
)

func highPerformanceTestConfig() Config {
	p := defaultMobility()
	p.NetworkMode = 1
	p.ModeSource = v4ModeSource
	return Config{Mobility: &p}
}
func highPerformanceTestAP(id string, count int) cweng.APStatus {
	a := cweng.APStatus{ID: id, Online: true, Radios: count, ConnectedAt: time.Now(), GeneralCapabilities: []uint32{1 << 25, 0, 1 << 8}}
	for i := 1; i <= count; i++ {
		band, mode := "5 GHz", 9
		if i == 1 {
			band, mode = "2.4 GHz", 6
		}
		a.Capabilities = append(a.Capabilities, cweng.RadioCapability{RadioID: uint8(i), Band: band, Modes: []int{mode}, Bandwidths: []int{0, 1, 2, 3}, Channels: []int{0, 1, 6, 11, 36, 40, 44, 48, 149, 153, 157, 161}, MaxClients: 128, MaxSSID: 8, MinPower: 1, MaxPower: 20})
	}
	return a
}
func settleHighPerformanceMode(m *Manager, ap cweng.APStatus) {
	m.applied[ap.ID+"/roaming-mode"] = configurationKey(struct {
		Mode    int
		Silence RoamSilence
	}{1, effectiveRoamSilence(m.config.Mobility)}, ap.ConnectedAt)
	m.applied[ap.ID+"/roaming"] = configurationKey(roamingParametersFor(ap.ID, m.config), ap.ConnectedAt)
}

func highPerformanceTestRadio(t *testing.T, cfg Config, ap cweng.APStatus, radio uint8) RadioSetting {
	t.Helper()
	for _, r := range effectiveRadioConfig(cfg, ap).Radios {
		if r.AP == ap.ID && r.Radio == radio {
			return r
		}
	}
	t.Fatal("missing radio", ap.ID, radio)
	return RadioSetting{}
}

func TestV4HighPerformanceDifferentEntriesAndInheritedBandwidth(t *testing.T) {
	m, _ := testController(t)
	a := highPerformanceTestAP("02:00:00:00:01:01", 2)
	b := highPerformanceTestAP("02:00:00:00:01:02", 3)
	m.known = map[string]cweng.APStatus{a.ID: a, b.ID: b}
	m.config = highPerformanceTestConfig()
	advanced := defaultRadioAdvanced(a.Capabilities[1])
	advanced.Beacon = 200
	m.config.APDefaults.Radios = []RadioSetting{{Radio: 2, Advanced: &advanced}}
	s := mobility.V4ChannelSelection{Channels: mobility.CommonChannels{6, 40, 157}, Best5: 157}
	next := m.withHighPerformanceSelectionLocked(m.config, s, 0, true)
	if *highPerformanceTestRadio(t, next, a, 2).Channel != 157 || *highPerformanceTestRadio(t, next, b, 2).Channel != 40 || *highPerformanceTestRadio(t, next, b, 3).Channel != 157 {
		t.Fatal("ACS downlink entry collapsed")
	}
	if r := highPerformanceTestRadio(t, next, a, 2); r.Advanced.Bandwidth != 2 || r.Advanced.Beacon != 200 {
		t.Fatal("coordinator changed unrelated RF settings", r)
	}
	advanced.Beacon = 300
	if r := highPerformanceTestRadio(t, next, a, 2); r.Advanced.Beacon != 300 {
		t.Fatal("bandwidth override froze inherited parameters")
	}
	next = m.withHighPerformanceChannelsLocked(next, s.Channels, 0)
	if *highPerformanceTestRadio(t, next, a, 2).Channel != 40 {
		t.Fatal("join entry must use low5 slot")
	}
	next = m.withHighPerformanceChannelsLocked(next, s.Channels, 3)
	if *highPerformanceTestRadio(t, next, a, 2).Channel != 157 || *highPerformanceTestRadio(t, next, b, 2).Channel != 40 {
		t.Fatal("manual band filter lost")
	}
}

func TestV4HighPerformanceModeWireOrderingAndIndependentCapabilities(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{1 << 25, 0, 1 << 8}
	cfg := highPerformanceTestConfig()
	cfg.Mobility.HighPerformanceSilence = &RoamSilence{Count: 7, Seconds: 91}
	cfg.Mobility.Default.HighPerformanceRSSI = -62
	m.config = cfg
	m.known[ap.ID] = ap
	m.applyMobility(context.Background(), ap, cfg)
	f.mu.Lock()
	order := []uint16{}
	wire := map[uint16][]byte{}
	for _, p := range f.packets {
		for _, el := range p.Elements {
			if el.Type == 0x25 && len(el.Value) >= 10 {
				k := binary.BigEndian.Uint16(el.Value[6:])
				if k == 0x9d || k == 0x57 {
					order = append(order, k)
					wire[k] = el.Value[10:]
				}
			}
		}
	}
	if len(order) != 2 || order[0] != 0x9d || order[1] != 0x57 {
		t.Fatal("mode1 transition ordering", order)
	}
	if b := wire[0x9d]; len(b) != 3 || b[0] != 7 || binary.BigEndian.Uint16(b[1:]) != 91 {
		t.Fatal(b)
	}
	if b := wire[0x57]; len(b) != 36 || b[3] != 1 || b[10] != 1 || int8(b[4]) != -62 || int8(b[11]) != -62 {
		t.Fatal(b)
	}
	if ready, err := m.highPerformanceModeReadyLocked(); !ready || err != nil {
		t.Fatal(ready, err)
	}
	firstCount := len(f.packets)
	f.mu.Unlock()
	// Missing capability72 doesn't suppress the separate capability25 path.
	ap.GeneralCapabilities = []uint32{1 << 25}
	m.known[ap.ID] = ap
	delete(m.applied, ap.ID+"/roaming")
	m.applyMobility(context.Background(), ap, cfg)
	f.mu.Lock()
	defer f.mu.Unlock()
	for _, p := range f.packets[firstCount:] {
		for _, el := range p.Elements {
			if el.Type == 0x25 && len(el.Value) >= 10 && binary.BigEndian.Uint16(el.Value[6:]) == 0x9d {
				t.Fatal("capability25 incorrectly implied72")
			}
		}
	}
}

func TestV4HighPerformanceManualEntryRestoreAndReportEpochs(t *testing.T) {
	m, _ := testController(t)
	ap := highPerformanceTestAP("02:00:00:00:02:01", 2)
	m.known = map[string]cweng.APStatus{ap.ID: ap}
	m.config = highPerformanceTestConfig()
	m.highPerformance.Channels = mobility.CommonChannels{6, 40, 149}
	m.config = m.withHighPerformanceChannelsLocked(m.config, m.highPerformance.Channels, 0)
	next := m.config
	next.Radios = append([]RadioSetting{}, next.Radios...)
	ch := 157
	for i, r := range next.Radios {
		if r.Radio == 2 {
			next.Radios[i].Channel = &ch
		}
	}
	next, channels := m.prepareHighPerformanceLocked(next, managementUser)
	if channels[2] != 157 || *highPerformanceTestRadio(t, next, ap, 2).Channel != 157 {
		t.Fatal("manual high band replaced by stale low band", channels)
	}
	_, channels = m.prepareHighPerformanceLocked(next, managementRestore)
	if channels != (mobility.CommonChannels{}) {
		t.Fatal("restore kept prior coordinator cache")
	}
	m.highPerformance.State = "collecting"
	m.highPerformance.Expected = map[string]time.Time{ap.ID: ap.ConnectedAt}
	m.highPerformance.Reports = map[string][]capwap.ChannelScanSample{}
	m.highPerformance.Connections = map[string]time.Time{}
	m.observeHighPerformanceScan(ap.ID, ap.ConnectedAt.Add(-time.Second), []capwap.ChannelScanSample{{Channel: 11}})
	if len(m.highPerformance.Reports) != 0 {
		t.Fatal("stale session report consumed")
	}
	m.observeHighPerformanceScan(ap.ID, ap.ConnectedAt, []capwap.ChannelScanSample{{Channel: 11}, {Channel: 149}})
	if m.highPerformance.State != "completed" || *highPerformanceTestRadio(t, m.config, ap, 2).Channel != 149 {
		t.Fatal("ACS did not use overall5 entry", m.highPerformance)
	}
}

func TestV4HighPerformanceRRMChannelEntryUsesGlobalACS(t *testing.T) {
	m, _ := testController(t)
	ap := highPerformanceTestAP("02:00:00:00:03:01", 2)
	// No capability27 and outside the RRM target selector: the original
	// mode1 channel entry still invokes global capability72 ACS.
	m.known = map[string]cweng.APStatus{ap.ID: ap}
	m.config = highPerformanceTestConfig()
	settleHighPerformanceMode(m, ap)
	r := defaultRRMRule()
	r.StrategyVersion = "v4"
	r.ID, r.Name = "rrm-hp", "HP"
	r.Channel = true
	r.Band5G.Channels = []int{36, 149}
	r.APs = []string{"another-ap"}
	job, err := m.startRRM(r, "")
	if err != nil {
		t.Fatal(err)
	}
	t.Cleanup(func() {
		m.mu.Lock()
		defer m.mu.Unlock()
		if m.highPerformance.Timer != nil {
			m.highPerformance.Timer.Stop()
		}
	})
	if !job.CommonChannelPhase || m.highPerformance.State != "collecting" || !job.CollectUntil.After(m.highPerformance.Deadline) || m.rrmRuns[job.ID] != nil {
		t.Fatal("SCA path was used in fixed mode1", job, m.highPerformance)
	}
	if m.rrmStep(context.Background(), ap) {
		t.Fatal("ACS phase must allow resulting RF configurations to reconcile")
	}
	m.observeHighPerformanceScan(ap.ID, ap.ConnectedAt, []capwap.ChannelScanSample{{Channel: 6}, {Channel: 149}})
	m.tickRRM(job.CollectUntil)
	if got := m.rrmJobs[job.ID]; got.State != "applying" || got.CommonChannelPhase || *highPerformanceTestRadio(t, m.config, ap, 2).Channel != 149 {
		t.Fatal(got)
	}
}

func TestV4HighPerformanceRejectsTPCAndKeepsACSWaitLimit(t *testing.T) {
	m, _ := testController(t)
	ap := highPerformanceTestAP("02:00:00:00:03:02", 2)
	ap.GeneralCapabilities[0] |= 1 << 27
	m.known = map[string]cweng.APStatus{ap.ID: ap}
	m.config = highPerformanceTestConfig()
	settleHighPerformanceMode(m, ap)
	r := defaultRRMRule()
	r.StrategyVersion = "v4"
	r.ID, r.Name = "rrm-power", "Power"
	r.Channel, r.Power = true, true
	r.Band5G.Channels = []int{36, 149}
	job, err := m.startRRM(r, "")
	if err != nil {
		t.Fatal(err)
	}
	t.Cleanup(func() {
		m.mu.Lock()
		defer m.mu.Unlock()
		if m.highPerformance.Timer != nil {
			m.highPerformance.Timer.Stop()
		}
	})
	// The business timer waits independently while an ACS round remains live.
	m.tickRRM(job.CollectUntil)
	waiting := m.rrmJobs[job.ID]
	if waiting.ACSWaitAttempts != 1 || !waiting.CommonChannelPhase || m.rrmRuns[job.ID] != nil {
		t.Fatal(waiting)
	}
	m.observeHighPerformanceScan(ap.ID, ap.ConnectedAt, []capwap.ChannelScanSample{{Channel: 6}, {Channel: 149}})
	m.tickRRM(waiting.CollectUntil)
	got := m.rrmJobs[job.ID]
	if got.State != "applying" || got.CommonChannelPhase || !got.PowerSkipped || m.rrmRuns[job.ID] != nil {
		t.Fatal("high-performance mode must not start TPC", got)
	}
}

func TestV4HighPerformanceConfigurationSurvivesStartup(t *testing.T) {
	e, err := cweng.NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	dir := t.TempDir()
	cfg := highPerformanceTestConfig()
	if err = atomicJSON(filepath.Join(dir, "controller.json"), cfg); err != nil {
		t.Fatal(err)
	}
	m, err := New(e, cweng.NewClientTable(), dir)
	if err != nil {
		t.Fatal(err)
	}
	if m.config.Mobility.NetworkMode != 1 || actualMobilityMode(m.config) != 1 || m.highPerformance.PendingScan {
		t.Fatal("startup migrated explicit V4 mode or manufactured a mode-change event")
	}
}

func TestV4HighPerformanceManualAndRRMScansWaitForModeWrites(t *testing.T) {
	m, _ := testController(t)
	ap := highPerformanceTestAP("02:00:00:00:03:03", 2)
	m.known = map[string]cweng.APStatus{ap.ID: ap}
	m.config = highPerformanceTestConfig()
	if err := m.startHighPerformanceACSLocked(time.Now()); err != nil {
		t.Fatal(err)
	}
	if m.highPerformance.State != "waiting" || m.highPerformance.Timer != nil {
		t.Fatal("manual scan overtook unapplied mode parameters")
	}
	r := defaultRRMRule()
	r.StrategyVersion = "v4"
	r.ID, r.Name = "wait-mode", "Wait"
	r.Channel = true
	r.Band5G.Channels = []int{36, 149}
	job, err := m.startRRM(r, "")
	if err != nil {
		t.Fatal(err)
	}
	if !job.CollectUntil.IsZero() {
		t.Fatal("RRM collection timer started before scan dispatch")
	}
	m.tickRRM(time.Now().Add(time.Hour))
	if m.rrmJobs[job.ID].State != "collecting" {
		t.Fatal("undispatched scan expired")
	}
	settleHighPerformanceMode(m, ap)
	now := time.Now()
	m.tickHighPerformance(now)
	t.Cleanup(func() { m.mu.Lock(); defer m.mu.Unlock(); m.highPerformance.resetCollection() })
	if m.highPerformance.State != "collecting" || m.highPerformance.Deadline != now.Add(6*time.Second) || m.rrmJobs[job.ID].CollectUntil != now.Add(11*time.Second) {
		t.Fatal("scan/business deadlines were not armed at dispatch", m.highPerformance, m.rrmJobs[job.ID])
	}
	m.highPerformance.resetCollection()
	m.highPerformance.State = ""
	m.status[ap.ID+"/roaming-mode"] = ApplyStatus{State: "failed", Error: "rejected"}
	if err := m.startHighPerformanceACSLocked(now); err == nil || m.highPerformance.Timer != nil {
		t.Fatal("mode write failure did not abort ACS", err)
	}
}
