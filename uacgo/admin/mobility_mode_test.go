package admin

import (
	"bytes"
	"context"
	"testing"
)

func TestV6ModeIsCompatibilityAndLegacyModesCannotBeConfigured(t *testing.T) {
	m, _ := testController(t)
	p := defaultMobility()
	if p.NetworkMode != 2 || m.effectiveMobilityMode(Config{Mobility: &p}) != 2 {
		t.Fatal("V6 shipped mode")
	}
	for _, mode := range []int{0, 1} {
		p.NetworkMode = mode
		if p.validate(Config{}) == nil {
			t.Fatal("V6 Web-forbidden mode accepted", mode)
		}
	}
}
func TestMobilityModeAndRSSIStatisticsActuallyReachAP(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{1<<24 | 1<<25, 0, 1 << 8}
	p := defaultMobility()
	p.NetworkMode = 2
	p.Default.Statistics = true
	p.Default.StatisticsInterval = 17
	cfg := Config{Mobility: &p}
	m.applyMobility(context.Background(), ap, cfg)
	m.applyReporting(context.Background(), ap, cfg)
	f.mu.Lock()
	defer f.mu.Unlock()
	got := map[byte][]byte{}
	for _, pkt := range f.packets {
		for _, el := range pkt.Elements {
			if el.Type == 0x25 && len(el.Value) >= 10 {
				got[el.Value[7]] = el.Value[10:]
			}
		}
	}
	if !bytes.Equal(got[0x9d], []byte{3, 0, 30}) {
		t.Fatalf("missing compatibility silence parameters %x", got[0x9d])
	}
	if !bytes.Equal(got[0x55], []byte{1, 1, 1, 0, 120, 0, 17, 0, 120}) {
		t.Fatalf("RSSI statistics switch/period ignored %x", got[0x55])
	}
	if b := got[0x57]; len(b) != 36 || int8(b[4]) != -75 || int8(b[11]) != -80 {
		t.Fatalf("compatibility RSSI not applied %x", b)
	}
}

func TestReportingDisabledAndLongIntervalsUseOriginalCeiling(t *testing.T) {
	p := defaultMobility()
	cfg := Config{Mobility: &p}
	if got := reportingControl(cfg, "a").AssembleValue(); !bytes.Equal(got, []byte{1, 0, 1, 0, 120, 0, 120, 0, 120}) {
		t.Fatal(got)
	}
	p.Default.Statistics = true
	p.Default.StatisticsInterval = 3600
	if got := reportingControl(cfg, "a"); got.B != 1 || got.E != 120 {
		t.Fatal(got)
	}
}

func TestStatisticsControlRecipientsRequireCapability24(t *testing.T) {
	for _, supported := range []bool{false, true} {
		m, e := testController(t)
		f, ap := newDeferredAP(t, e)
		ap.GeneralCapabilities = []uint32{1 << 25}
		if supported {
			ap.GeneralCapabilities[0] |= 1 << 24
		}
		m.applyReporting(context.Background(), ap, Config{})
		f.mu.Lock()
		commands := f.commands
		f.mu.Unlock()
		want := 0
		if supported {
			want = 1
		}
		if commands != want {
			t.Fatal("roaming capability cannot stand in for statistics", supported, commands)
		}
	}
}
