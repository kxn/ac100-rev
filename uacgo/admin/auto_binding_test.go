package admin

import (
	"context"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestAutomaticBindingFollowsFrequencyRankAcrossAPModels(t *testing.T) {
	mask := uint16(1 << 9)
	s := Service{AutoBindFrequencies: &mask}
	ap := cweng.APStatus{Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "5 GHz"}, {RadioID: 2, Band: "2.4 GHz"}, {RadioID: 3, Band: "5 GHz"}}}
	got := selectedServiceRadios(s, ap)
	if len(got) != 1 || !got[3] {
		t.Fatal("5G2 confused with AP-local radio2", got)
	}
	mask = 1 << 8
	got = selectedServiceRadios(s, ap)
	if len(got) != 1 || !got[1] {
		t.Fatal("5G1 confused with radio2", got)
	}
	mask = 1
	got = selectedServiceRadios(s, ap)
	if len(got) != 1 || !got[2] {
		t.Fatal("2.4G1 confused with radio1", got)
	}
	s.AutoBindFrequencies = nil
	s.Radios = []uint8{1, 3}
	if len(selectedServiceRadios(s, ap)) != 2 {
		t.Fatal("legacy radio selections changed")
	}
}
func TestAutoBoundServiceAdmissionDoesNotAuthorizeOtherBands(t *testing.T) {
	m, _ := testController(t)
	mask := uint16(1 << 8)
	s := Service{ID: "s", SSID: "Office", Security: "open", Enabled: true, AutoBindFrequencies: &mask}
	m.config.Services = []Service{s}
	m.known["a"] = cweng.APStatus{ID: "a", Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "5 GHz"}, {RadioID: 2, Band: "2.4 GHz"}}}
	m.assignments["a"] = map[string]map[uint8]uint8{"s": {1: 1, 2: 1}}
	if !m.admitStation("a", 1, 1) || m.admitStation("a", 2, 1) {
		t.Fatal("admission ignored frequency binding")
	}
	if err := validate(s); err != nil {
		t.Fatal("frequency binding required arbitrary radio IDs", err)
	}
}

func TestAutoFrequencyBindingReconcilesMovesAndCleansWLAN(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.Capabilities = []cweng.RadioCapability{{RadioID: 1, Band: "5 GHz", MaxSSID: 1}, {RadioID: 2, Band: "2.4 GHz", MaxSSID: 1}}
	m.known[ap.ID] = ap
	mask := uint16(1 << 8)
	s := Service{ID: "frequency", SSID: "Frequency", Security: "open", Enabled: true, AutoBindFrequencies: &mask}
	cfg := Config{Services: []Service{s}}
	ctx, cancel := context.WithTimeout(context.Background(), 3*time.Second)
	defer cancel()
	if err := m.apply(ctx, ap, s, cfg); err != nil {
		t.Fatal(err)
	}
	if err := m.checkpoint(ctx, ap.ID, "frequency-first"); err != nil {
		t.Fatal(err)
	}
	f.mu.Lock()
	first := len(f.active) == 1 && f.active[[2]byte{1, 1}] == s.SSID
	f.mu.Unlock()
	if !first {
		t.Fatal("frequency mapping did not install correct VAP")
	}
	mask = 1
	cfg.Services[0] = s
	if err := m.apply(ctx, ap, s, cfg); err != nil {
		t.Fatal(err)
	}
	if err := m.checkpoint(ctx, ap.ID, "frequency-moved"); err != nil {
		t.Fatal(err)
	}
	f.mu.Lock()
	moved := len(f.active) == 1 && f.active[[2]byte{2, 1}] == s.SSID
	f.mu.Unlock()
	if !moved {
		t.Fatal("old frequency VAP not removed / new VAP missing")
	}
	s.Enabled = false
	if err := m.apply(ctx, ap, s, cfg); err != nil {
		t.Fatal(err)
	}
	if err := m.checkpoint(ctx, ap.ID, "frequency-disabled"); err != nil {
		t.Fatal(err)
	}
	f.mu.Lock()
	n := len(f.active)
	f.mu.Unlock()
	if n != 0 {
		t.Fatal("frequency-bound WLAN leaked")
	}
}

func TestSensorRadiosCannotBeWirelessServiceTargets(t *testing.T) {
	ap := cweng.APStatus{Radios: 3, Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "5 GHz"}, {RadioID: 2, Band: "5 GHz", FunctionType: 1}, {RadioID: 3, Band: "5 GHz"}}}
	mask := uint16(1 << 9)
	s := Service{AutoBindFrequencies: &mask}
	if len(selectedServiceRadios(s, ap)) != 0 {
		t.Fatal("sensor radio exposed as WLAN target")
	}
	mask = 1 << 10
	if !selectedServiceRadios(s, ap)[3] {
		t.Fatal("sensor omission shifted physical frequency ranks")
	}
	s.AutoBindFrequencies = nil
	s.Radios = []uint8{1, 2, 4}
	got := selectedServiceRadios(s, ap)
	if len(got) != 1 || !got[1] {
		t.Fatal("invalid explicit WLAN radio targets", got)
	}
}
