package cweng

import (
	"testing"
	"time"
)

func mac(a ...byte) [6]byte {
	var m [6]byte
	copy(m[:], a)
	return m
}

func TestMacAuthDecisionTree(t *testing.T) {
	m1, m2 := mac(1, 2, 3, 4, 5, 6), mac(9, 9, 9, 9, 9, 9)
	db := NewMacAuthDB(MacAuthByVLAN)
	db.UpsertMac(MacAuthMac{ID: 1, MAC: m1})

	// no group for the VLAN → pass
	if !db.Check(MacAuthSta{MACs: [][6]byte{m1}, VLAN: "10"}) {
		t.Fatal("no group must pass")
	}

	// white_list group on vlan 10, m1 bound → pass
	db.UpsertGroup(MacAuthGroup{ID: 1, Status: true, BindVLAN: "10", Type: MacAuthWhiteList})
	db.Bind(1, []int{1}, true)
	if !db.Check(MacAuthSta{MACs: [][6]byte{m1}, VLAN: "10"}) {
		t.Fatal("bound white-list mac must pass")
	}
	// m2 not in the table → white_list forbids
	if db.Check(MacAuthSta{MACs: [][6]byte{m2}, VLAN: "10"}) {
		t.Fatal("unknown mac must be forbidden on white list")
	}
	// unbind m1 → forbid
	db.Bind(1, []int{1}, false)
	if db.Check(MacAuthSta{MACs: [][6]byte{m1}, VLAN: "10"}) {
		t.Fatal("unbound white-list mac must be forbidden")
	}

	// black_list group on vlan 20
	db.UpsertGroup(MacAuthGroup{ID: 2, Status: true, BindVLAN: "20", Type: MacAuthBlackList})
	db.Bind(2, []int{1}, true)
	if db.Check(MacAuthSta{MACs: [][6]byte{m1}, VLAN: "20"}) {
		t.Fatal("bound black-list mac must be forbidden")
	}
	if !db.Check(MacAuthSta{MACs: [][6]byte{m2}, VLAN: "20"}) {
		t.Fatal("unknown mac must pass on black list")
	}

	// disabled group → pass everything
	db.UpsertGroup(MacAuthGroup{ID: 2, Status: false, BindVLAN: "20", Type: MacAuthBlackList})
	if !db.Check(MacAuthSta{MACs: [][6]byte{m1}, VLAN: "20"}) {
		t.Fatal("disabled group must pass")
	}

	// SSID mode looks up by wserv id
	db.SetMode(MacAuthBySSID)
	db.UpsertGroup(MacAuthGroup{ID: 3, Status: true, BindVLAN: "srv1", Type: MacAuthWhiteList})
	db.Bind(3, []int{1}, true)
	if !db.Check(MacAuthSta{MACs: [][6]byte{m1}, WServID: "srv1"}) {
		t.Fatal("ssid mode lookup")
	}
	if db.Check(MacAuthSta{MACs: [][6]byte{m2}, WServID: "srv1"}) {
		t.Fatal("ssid mode unknown mac")
	}

	// MLO: any link forbidden → forbid
	if db.Check(MacAuthSta{MACs: [][6]byte{m1, m2}, WServID: "srv1"}) {
		t.Fatal("mlo any-forbid semantics")
	}
}

func TestRRMHelpers(t *testing.T) {
	if got := RRMRRSITransform(-50); got != 25 {
		t.Fatalf("transform(-50) = %d, want 25", got)
	}
	if got := RRMRRSITransform(-100); got != 0 {
		t.Fatalf("transform(-100) = %d", got)
	}
	if got := PwrToLevel(20, 20, 10); got != 10 {
		t.Fatalf("level max = %d", got)
	}
	if got := PwrToLevel(10, 20, 10); got != 1 {
		t.Fatalf("level min = %d", got)
	}
	if got := LevelToPwr(PwrToLevel(15, 20, 10), 20, 10); got != 15 {
		t.Fatalf("level roundtrip = %d", got)
	}
}

func TestRRMStateMachine(t *testing.T) {
	cfg := RRMConfig{
		ChnlEnable: true, PwrEnable: true,
		ChnlSets:       [RRMBandCount][]int{{1, 6, 11}, {36, 40}, {149}},
		MaxChangePower: 3, MaxTPCCount: 2,
		TpcNeighSize: 3, HighThreshold: 60, LowThreshold: 20,
		PwrMaxPwr: 20, PwrMinPwr: 10,
	}
	e := NewRRMEngine(cfg)

	// gating
	if got := e.ManualStart(true); got != -2 {
		t.Fatalf("busy = %d", got)
	}
	e.state = RRMCalcChnl
	if got := e.ManualStart(false); got != -1 {
		t.Fatalf("bad state = %d", got)
	}
	e.state = RRMIdle
	e.cfg.ChnlEnable, e.cfg.PwrEnable = false, false
	if got := e.ManualStart(false); got != -4 {
		t.Fatalf("nothing enabled = %d", got)
	}
	e.cfg.ChnlEnable, e.cfg.PwrEnable = true, true

	// manual start → collecting(channel)
	if got := e.ManualStart(false); got != 0 {
		t.Fatalf("manual start = %d", got)
	}
	if e.State() != RRMCollectChnl {
		t.Fatalf("state = %d", e.State())
	}

	// collection: 2 radios of 3 report → not complete; all → complete
	e.AddRadio(RRMBand2G, RrmRadioRec{ApID: 1, Radio: 1, CurChnl: 1})
	e.AddRadio(RRMBand2G, RrmRadioRec{ApID: 2, Radio: 1, CurChnl: 6})
	e.AddRadio(RRMBand2G, RrmRadioRec{ApID: 3, Radio: 1, CurChnl: 11})
	if e.ReportNeigh(RRMBand2G, 1, 1, []RrmNeighSample{{NeighAP: 2, RSSI: 30}}) {
		t.Fatal("must not complete early")
	}
	e.ReportNeigh(RRMBand2G, 2, 1, []RrmNeighSample{{NeighAP: 1, RSSI: 30}})
	if !e.ReportNeigh(RRMBand2G, 3, 1, nil) {
		t.Fatal("all reported must complete")
	}
	e.WaitForCalc()

	// DCA: neighbors on the same candidate channel get separated
	asg := e.CalcChannel()
	if len(asg) == 0 {
		t.Fatal("no assignments")
	}
	// ap1 and ap2 interfere → different channels
	if asg[1][0] == asg[2][0] {
		t.Fatalf("interfering radios share a channel: %v", asg)
	}

	// power phase (PwrEnable) collects again
	if e.State() != RRMCollectPwr {
		t.Fatalf("power phase state = %d", e.State())
	}
	e.AddRadio(RRMBand2G, RrmRadioRec{ApID: 1, Radio: 1, CurPower: 12})
	e.ReportNeigh(RRMBand2G, 1, 1, []RrmNeighSample{{NeighAP: 2, RSSI: 5}}) // weak/lonely
	e.WaitForCalc()
	levels, done := e.CalcPower()
	if done {
		t.Fatal("first TPC round should iterate")
	}
	if levels[101] < 12 {
		t.Fatalf("weak neighbor must raise power: %v", levels)
	}
}

func TestRRMTPCDirections(t *testing.T) {
	cfg := RRMConfig{TpcNeighSize: 3, HighThreshold: 60, LowThreshold: 20,
		PwrMaxPwr: 20, PwrMinPwr: 10, MaxChangePower: 3, MaxTPCCount: 1}
	e := NewRRMEngine(cfg)
	set := &rrmBandCollect{reportedN: 2, recs: []*RrmRadioRec{
		{ApID: 1, Radio: 1, CurPower: 12, // strong neighbor → power down
			Neighs: []RrmNeighSample{{NeighAP: 2, RSSI: 70}}},
		{ApID: 2, Radio: 1, CurPower: 12, // no neighbors → toward midpoint
			Neighs: nil},
		{ApID: 3, Radio: 1, CurPower: 12, // weak + few → power up
			Neighs: []RrmNeighSample{{NeighAP: 1, RSSI: 5}}},
	}}
	e.runTPC(set)
	if set.recs[0].Power != 9 && set.recs[0].Power != 10 {
		t.Fatalf("strong neighbor power = %d, want down to 10", set.recs[0].Power)
	}
	if set.recs[1].Power != 15 {
		t.Fatalf("no-neighbor power = %d, want midpoint 15", set.recs[1].Power)
	}
	if set.recs[2].Power != 15 {
		t.Fatalf("weak neighbor power = %d, want up 15", set.recs[2].Power)
	}
}

func TestACSChannelSelect(t *testing.T) {
	samples := map[int][2]int{
		1: {5, 50}, 6: {2, 80}, 11: {9, 10},
		36: {3, 20}, 40: {7, 5}, 149: {1, 100}, 153: {4, 4},
	}
	// default mode: min sumA, tie by sumB
	ch2, best5, second5 := ACSChannelSelect(false, samples)
	if ch2 != 6 || best5 != 149 {
		t.Fatalf("default pick = %d %d", ch2, best5)
	}
	// 149 is in the low band (15..48)? no — 149 > 48 → second must come
	// from 15..48: min sumA there is 36
	if second5 != 36 {
		t.Fatalf("second5 = %d", second5)
	}
	// load mode: min sumB — 2.4G: ch11 (sumB 10); 5G: 153 (sumB 4),
	// second from the other band = 40 (sumB 5)
	ch2, best5, second5 = ACSChannelSelect(true, samples)
	if ch2 != 11 || best5 != 153 || second5 != 40 {
		t.Fatalf("load pick = %d %d %d", ch2, best5, second5)
	}
	// empty → defaults 1/36/149
	if a, b, c := ACSChannelSelect(false, nil); a != 1 || b != 36 || c != 149 {
		t.Fatalf("defaults = %d %d %d", a, b, c)
	}
}

func TestNextAutoDelay(t *testing.T) {
	now := time.Date(2026, 1, 5, 8, 0, 0, 0, time.UTC) // Monday
	d := NextAutoDelay(now, 7, "10:00:00")
	if d != 2*time.Hour {
		t.Fatalf("daily delay = %v", d)
	}
	d = NextAutoDelay(now, 3, "10:00:00") // Wednesday
	if d != 50*time.Hour {
		t.Fatalf("weekly delay = %v", d)
	}
	// Monday after the target time → next week's Monday
	now = time.Date(2026, 1, 5, 12, 0, 0, 0, time.UTC)
	d = NextAutoDelay(now, 1, "10:00:00")
	if d != 6*24*time.Hour+22*time.Hour {
		t.Fatalf("next-week delay = %v", d)
	}
}
