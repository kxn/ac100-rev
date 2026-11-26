package admin

import (
	"bytes"
	"context"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestAutomaticMobilityModeCapacityAndStickyCompatibility(t *testing.T) {
	m, _ := testController(t)
	p := defaultMobility()
	cfg := Config{Mobility: &p}
	for i := 0; i < 5; i++ {
		id := string(rune('a' + i))
		m.known[id] = cweng.APStatus{ID: id, Online: true}
	}
	if m.effectiveMobilityMode(cfg) != 1 {
		t.Fatal("small installation should use high performance")
	}
	m.known["f"] = cweng.APStatus{ID: "f", Online: true}
	if m.effectiveMobilityMode(cfg) != 2 {
		t.Fatal("six APs should select compatibility")
	}
	delete(m.known, "f")
	if m.effectiveMobilityMode(cfg) != 2 {
		t.Fatal("capacity fluctuations must not repeatedly rescan")
	}
	p.Default.Difference++
	if m.effectiveMobilityMode(cfg) != 1 {
		t.Fatal("manual settings update should reevaluate automatic mode")
	}
	for i := byte(0); i < 31; i++ {
		m.clients.StationEvent(cweng.ClientEvent{MAC: [6]byte{2, 0, 0, 0, 1, i}, APID: "a", RadioID: 1, WLANID: 1, State: "connected", Kind: "associate", Seen: time.Now()})
	}
	if m.effectiveMobilityMode(cfg) != 2 {
		t.Fatal("31 confirmed clients should select compatibility")
	}
	p.NetworkMode = 1
	if m.effectiveMobilityMode(cfg) != 1 {
		t.Fatal("forced high performance ignored")
	}
	p.NetworkMode = 2
	if m.effectiveMobilityMode(cfg) != 2 {
		t.Fatal("forced compatibility ignored")
	}
}

func TestMobilityModeAndRSSIStatisticsActuallyReachAP(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{1 << 25, 0, 1 << 8}
	p := defaultMobility()
	p.NetworkMode = 1
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
	if !bytes.Equal(got[0x9d], []byte{5, 0, 15}) {
		t.Fatalf("missing high-performance silence parameters %x", got[0x9d])
	}
	if !bytes.Equal(got[0x55], []byte{1, 1, 1, 0, 120, 0, 17, 0, 120}) {
		t.Fatalf("RSSI statistics switch/period ignored %x", got[0x55])
	}
	if b := got[0x57]; len(b) != 36 || int8(b[4]) != -65 || int8(b[11]) != -65 {
		t.Fatalf("high-performance RSSI not applied %x", b)
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
