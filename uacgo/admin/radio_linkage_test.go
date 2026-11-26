package admin

import (
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func linkedAPFixture() cweng.APStatus {
	cap := cweng.RadioCapability{Band: "5 GHz", MaxClients: 128, Modes: []int{7, 9}, Bandwidths: []int{0, 3}, Channels: []int{36, 40, 44, 48}}
	a, b := cap, cap
	a.RadioID = 1
	b.RadioID = 3
	return cweng.APStatus{ID: "ap", Capabilities: []cweng.RadioCapability{a, b}, RadioLinkage: &cweng.RadioLinkage{TableID: 1, Rows: []cweng.RadioLinkageRow{{TableMask: 2, FeatureMask: 1, Regions: []int{0}, Radios: []cweng.RadioLinkageMember{{Radio: 1, StatusMask: 3, Bandwidths: []int{0}, Channels: []int{36, 40}, EqualChannel: true}, {Radio: 3, StatusMask: 3, Bandwidths: []int{0}, Channels: []int{36, 40}, EqualChannel: true}}}}}}
}
func TestRadioLinkagePreservesEditedRadioAndAdjustsPeersAtomically(t *testing.T) {
	ap := linkedAPFixture()
	ch1, ch3 := 40, 36
	advanced := defaultRadioAdvanced(ap.Capabilities[0])
	advanced.Bandwidth = 0
	cfg := Config{Radios: []RadioSetting{{AP: ap.ID, Radio: 1, Channel: &ch1, Advanced: &advanced}, {AP: ap.ID, Radio: 3, Channel: &ch3, Advanced: &advanced}}}
	if validateRadioLinkage(cfg, ap) == nil {
		t.Fatal("illegal unequal pair accepted")
	}
	if err := planRadioLinkage(&cfg, ap, 1); err != nil {
		t.Fatal(err)
	}
	if *cfg.Radios[0].Channel != 40 || *cfg.Radios[1].Channel != 40 || ch3 != 36 {
		t.Fatal("edited or previous configuration was mutated", cfg)
	}
	if err := validateRadioLinkage(cfg, ap); err != nil {
		t.Fatal(err)
	}
	invalid := 48
	cfg.Radios[0].Channel = &invalid
	before := configurationKey(cfg, time.Time{})
	if err := planRadioLinkage(&cfg, ap, 1); err == nil {
		t.Fatal("unsupported edited combination accepted")
	}
	if configurationKey(cfg, time.Time{}) != before {
		t.Fatal("failed plan changed configuration")
	}
}

func TestRRMChoosesLegalLinkedCombinationRatherThanRejectIndependentOptimum(t *testing.T) {
	ap := linkedAPFixture()
	ap.Online = true
	ap.GeneralCapabilities = []uint32{1 << 27}
	ap.RadioStatus = []cweng.RadioStatus{{Radio: 1, Channel: 40, Power: 20}, {Radio: 3, Channel: 36, Power: 20}}
	for _, c := range ap.Capabilities {
		ap.RRMReports = append(ap.RRMReports, cweng.RRMReport{Radio: c.RadioID, ReceivedAt: time.Now()})
	}
	rule := defaultRRMRule()
	rule.Power = false
	rule.Band5G.Bandwidth = 0
	rule.Band5G.Channels = []int{36, 40}
	rule.Band5G.SecondChannels = []int{36, 40}
	plan, err := planRRM(rule, []cweng.APStatus{ap}, Config{}, time.Now().Add(-time.Minute))
	if err != nil || len(plan) != 2 {
		t.Fatal(plan, err)
	}
	if plan[0].Channel != plan[1].Channel {
		t.Fatal("independent optimum violated equal-channel constraint", plan)
	}
	cfg := Config{}
	for _, change := range plan {
		putLinkedRadio(&cfg, change.Setting)
	}
	if err := validateRadioLinkage(cfg, ap); err != nil {
		t.Fatal(err)
	}
	rule.Band5G.Channels = []int{48}
	rule.Band5G.SecondChannels = []int{48}
	if _, err := planRRM(rule, []cweng.APStatus{ap}, Config{}, time.Now().Add(-time.Minute)); err == nil {
		t.Fatal("invented illegal candidate outside linked rows")
	}
}

func TestACSSelectsNextBestLegalCrossBandCombination(t *testing.T) {
	ap := linkedAPFixture()
	ap.Online = true
	ap.Capabilities = ap.Capabilities[:1]
	ap.Capabilities[0].Band = "2.4 GHz"
	ap.Capabilities[0].Channels = []int{1, 6}
	bw := 0
	b := cweng.RadioCapability{RadioID: 2, Band: "5 GHz", Channels: []int{36, 40}, Bandwidths: []int{0}, DefaultBandwidth: &bw}
	ap.Capabilities = append(ap.Capabilities, b)
	ap.Capabilities[0].DefaultBandwidth = &bw
	ap.RadioLinkage.Rows = []cweng.RadioLinkageRow{
		{TableMask: 2, FeatureMask: 1, Radios: []cweng.RadioLinkageMember{{Radio: 1, StatusMask: 1, Bandwidths: []int{0}, Channels: []int{1}}, {Radio: 2, StatusMask: 1, Bandwidths: []int{0}, Channels: []int{40}}}},
		{TableMask: 2, FeatureMask: 1, Radios: []cweng.RadioLinkageMember{{Radio: 1, StatusMask: 1, Bandwidths: []int{0}, Channels: []int{6}}, {Radio: 2, StatusMask: 1, Bandwidths: []int{0}, Channels: []int{36}}}},
	}
	ap.ChannelScan = &cweng.ChannelScanReport{Channels: []capwap.ChannelScanSample{{Channel: 1}, {Channel: 6, BSS: 2}, {Channel: 36}, {Channel: 40, BSS: 1}}}
	plan, err := mobilityChannelPlan([]cweng.APStatus{ap}, Config{})
	if err != nil || len(plan) != 2 || plan[0].Channel != 1 || plan[1].Channel != 40 {
		t.Fatal(plan, err)
	}
	ap.RadioLinkage.Rows = nil
	plan, err = mobilityChannelPlan([]cweng.APStatus{ap}, Config{})
	if err != nil || plan[0].Channel != 1 || plan[1].Channel != 36 {
		t.Fatal(plan, err)
	}
}
