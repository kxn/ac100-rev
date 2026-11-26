package admin

import (
	"testing"
	"time"
	"uacgo/cweng"
)

func linkedAPFixture() cweng.APStatus {
	c := cweng.RadioCapability{Band: "5 GHz", MaxClients: 128, Modes: []int{7, 9}, Bandwidths: []int{0, 2, 3}, Channels: []int{36, 40, 44, 48}}
	a, b := c, c
	a.RadioID = 1
	b.RadioID = 3
	return cweng.APStatus{ID: "ap", Capabilities: []cweng.RadioCapability{a, b}, RadioLinkage: &cweng.RadioLinkage{TableID: 1, DefaultBandwidths: cweng.NumberList{0, 0, 0}, DefaultChannels: cweng.NumberList{36, 36, 36}, Rows: []cweng.RadioLinkageRow{{TableMask: 3, FeatureMask: 1, Regions: []int{0}, Radios: []cweng.RadioLinkageMember{{Radio: 1, StatusMask: 3, Bandwidths: []int{0}, Channels: []int{36, 40}, EqualChannel: true}, {Radio: 3, StatusMask: 3, Bandwidths: []int{0}, Channels: []int{36, 40}, EqualChannel: true}}}}}}
}
func linkedConfig(ap cweng.APStatus, ch1, ch3 int) Config {
	a := defaultRadioAdvanced(ap.Capabilities[0])
	a.Bandwidth = 0
	return Config{Radios: []RadioSetting{{AP: ap.ID, Radio: 1, Channel: &ch1, Advanced: &a}, {AP: ap.ID, Radio: 3, Channel: &ch3, Advanced: &a}}}
}
func TestRadioLinkageCopiesEqualChannelAndModeWithoutMutatingInput(t *testing.T) {
	ap := linkedAPFixture()
	cfg := linkedConfig(ap, 40, 36)
	old := *cfg.Radios[1].Channel
	if err := planRadioLinkage(&cfg, ap, 1); err != nil {
		t.Fatal(err)
	}
	if *cfg.Radios[0].Channel != 40 || *cfg.Radios[1].Channel != 40 || old != 36 {
		t.Fatal(cfg)
	}
}
func TestRRSTOrderedRowsAndNoInventedEnableChanges(t *testing.T) {
	ap := linkedAPFixture()
	cfg := linkedConfig(ap, 40, 36)
	first := ap.RadioLinkage.Rows[0]
	first.Radios = append([]cweng.RadioLinkageMember{}, first.Radios...)
	first.Radios[0].EqualChannel = false
	first.Radios[1].EqualChannel = false
	first.Radios[1].Channels = []int{44, 48}
	second := ap.RadioLinkage.Rows[0]
	second.Radios = append([]cweng.RadioLinkageMember{}, second.Radios...)
	second.Radios[0].EqualChannel = false
	second.Radios[1].EqualChannel = false
	ap.RadioLinkage.Rows = []cweng.RadioLinkageRow{first, second}
	if err := planRadioLinkage(&cfg, ap, 1); err != nil {
		t.Fatal(err)
	}
	// First candidate fails pre-match. Later rows cannot reset that flag.
	if *cfg.Radios[1].Channel != 44 {
		t.Fatal(cfg.Radios)
	}
	off := false
	cfg = linkedConfig(ap, 40, 36)
	cfg.Radios[1].Enabled = &off
	ap.RadioLinkage.Rows[0].Radios[1].StatusMask = 1
	ap.RadioLinkage.Rows = ap.RadioLinkage.Rows[:1]
	if err := planRadioLinkage(&cfg, ap, 1); err != nil {
		t.Fatal(err)
	}
	if *cfg.Radios[1].Enabled || *cfg.Radios[1].Channel != 36 {
		t.Fatal("no compatible row must leave peer unchanged", cfg.Radios)
	}
}
func TestRRSTNormalizationUsesTableZeroAndControlDefaults(t *testing.T) {
	ap := linkedAPFixture()
	cfg := linkedConfig(ap, 48, 36)
	normalized := normalizeLinkageRadio(cfg.Radios[0], ap.Capabilities[0], cfg, ap)
	if *normalized.Channel != 36 || normalized.Advanced.Bandwidth != 0 {
		t.Fatal(normalized)
	}
	cfg = linkedConfig(ap, 40, 36)
	wide := *cfg.Radios[0].Advanced
	wide.Bandwidth = 3
	cfg.Radios[0].Advanced = &wide
	normalized = normalizeLinkageRadio(cfg.Radios[0], ap.Capabilities[0], cfg, ap)
	if *normalized.Channel != 40 || normalized.Advanced.Bandwidth != 0 {
		t.Fatal(normalized)
	}
}

func TestInheritedRFNormalizesBeforeExplicitControllerSnapshot(t *testing.T) {
	ap := linkedAPFixture()
	ch := 48
	cfg := Config{Groups: []APGroup{{ID: "g", Name: "G", Options: APOptions{Radios: []RadioSetting{{Radio: 1, Channel: &ch}}}}}, APProfiles: []APProfile{{AP: ap.ID, Group: "g"}}}
	effective := effectiveRadioConfig(cfg, ap)
	if *effective.Radios[0].Channel != 36 {
		t.Fatal("inherited value bypassed table0 normalization", effective.Radios)
	}
	// A stored peer result may be outside table0. Restoring controller RF DB
	// state is not another user setter and must not undo the peer strategy.
	peer := 44
	cfg.Radios = []RadioSetting{{AP: ap.ID, Radio: 1, Channel: &peer}}
	if r := effectiveRadioConfig(cfg, ap).Radios[0]; *r.Channel != 44 {
		t.Fatal("re-normalized explicit controller snapshot", r)
	}
}
func TestRRMNormalizesThenRunsOrderedPeerStrategy(t *testing.T) {
	ap := linkedAPFixture()
	ap.Online = true
	ap.GeneralCapabilities = []uint32{1 << 27}
	ap.RadioStatus = []cweng.RadioStatus{{Radio: 1, Channel: 40, Power: 20}, {Radio: 3, Channel: 36, Power: 20}}
	rule := rrmTestRule()
	rule.Power = false
	rule.Band5G.Bandwidth = 0
	rule.Band5G.Channels = []int{48}
	nodes, err := rrmNodes(rule, []cweng.APStatus{ap}, Config{}, time.Time{})
	if err != nil {
		t.Fatal(err)
	}
	run := newRRMRun(nodes)
	if _, err = run.calculate(rule, true); err != nil {
		t.Fatal(err)
	}
	plan, err := run.changes(rule, Config{})
	if err != nil || len(plan) != 2 {
		t.Fatal(plan, err)
	}
	if plan[0].Channel != 36 || plan[1].Channel != 36 {
		t.Fatal("RF setter must normalize RRST result", plan)
	}
}
