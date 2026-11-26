package admin

import (
	"context"
	"testing"
	"uacgo/cweng"
)

func TestInheritedRadioAndAPOverrideReachUDPSimulator(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.Capabilities[0].Channels = []int{1, 6}
	on, off := true, false
	ch1, ch6 := 1, 6
	cfg := Config{Templates: []APTemplate{{ID: "t", Name: "T", Options: APOptions{Radios: []RadioSetting{{Radio: 1, Enabled: &on, Channel: &ch1}}}}}, APProfiles: []APProfile{{AP: ap.ID, Template: "t"}}, Radios: []RadioSetting{{AP: ap.ID, Radio: 1, Channel: &ch6}}}
	r := inheritedRadioSettings(cfg, ap.ID)
	if len(r) != 1 || r[0].Enabled == nil || !*r[0].Enabled || *r[0].Channel != 6 {
		t.Fatal(r)
	}
	m.reconcileAP(context.Background(), ap, cfg)
	f.mu.Lock()
	found := false
	for _, p := range f.packets {
		for _, e := range p.Elements {
			if e.Type == 0x404 && e.Value[2] == 6 {
				found = true
			}
		}
	}
	f.mu.Unlock()
	if !found {
		t.Fatal("inherited radio was not sent", m.status, ap.Model, ap.HardwareVersion)
	}
	cfg.Groups = []APGroup{{ID: "g", Name: "G", Options: APOptions{Radios: []RadioSetting{{Radio: 1, Enabled: &off}}}}}
	cfg.APProfiles[0].Group = "g"
	if !radioDisabled(cfg, ap.ID, 1) {
		t.Fatal("admission ignored inherited disable")
	}
}

func TestPowerOverrideClearsInheritedLevel(t *testing.T) {
	level, dbm := 10, 15
	r := mergeRadio(RadioSetting{PowerLevel: &level}, RadioSetting{Power: &dbm})
	if r.PowerLevel != nil || r.Power == nil || *r.Power != 15 {
		t.Fatal(r)
	}
}

func TestMixedHardwareRadioInheritanceFiltersOptionalFeaturesOnly(t *testing.T) {
	cap := cweng.RadioCapability{RadioID: 1, MaxClients: 128, Modes: []int{6}, Bandwidths: []int{0, 1, 2}, Channels: []int{1, 6, 11}}
	ap := cweng.APStatus{ID: "a", Radios: 1, Capabilities: []cweng.RadioCapability{cap}}
	advanced := defaultRadioAdvanced(cap)
	advanced.TWT = true
	advanced.ManagementRate = 12
	cfg := Config{APDefaults: APOptions{Radios: []RadioSetting{{Radio: 1, Advanced: &advanced}, {Radio: 3, Advanced: &advanced}}}}
	got := effectiveRadioConfig(cfg, ap)
	if len(got.Radios) != 1 || got.Radios[0].Advanced.TWT || got.Radios[0].Advanced.ManagementRate != 1 || !advanced.TWT {
		t.Fatal("inheritance leaked/mutated foreign hardware options", got)
	}
	cfg.APProfiles = []APProfile{{AP: "a", Options: APOptions{Radios: []RadioSetting{{Radio: 1, Advanced: &advanced}}}}}
	got = effectiveRadioConfig(cfg, ap)
	if !got.Radios[0].Advanced.TWT {
		t.Fatal("direct AP override silently discarded")
	}
	if validateKnownRadio(got.Radios[0], ap) == nil {
		t.Fatal("unsupported direct setting accepted")
	}
	if validateKnownRadio(RadioSetting{Radio: 3}, ap) == nil {
		t.Fatal("missing radio accepted")
	}
}
