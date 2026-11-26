package admin

import (
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func TestRRMCollectionDeadlineAndSingleLowHighChannels(t *testing.T) {
	ap := linkedAPFixture()
	ap.Online = true
	ap.GeneralCapabilities = []uint32{1 << 27}
	for i := range ap.Capabilities {
		ap.Capabilities[i].Channels = []int{36, 40, 149}
		ap.Capabilities[i].MutexChannels = "36 149"
	}
	rule := rrmTestRule()
	rule.Band5G.Channels = []int{40, 36, 149}
	nodes, err := rrmNodes(rule, []cweng.APStatus{ap}, Config{}, time.Time{})
	if err != nil {
		t.Fatal(err)
	}
	r := newRRMRun(nodes)
	now := time.Unix(100, 0)
	r.beginPass(rule, now)
	if !r.multi5G || len(r.requests) != 0 {
		t.Fatal("first rule channel40 is not in either radio domain", r)
	}
	rule.Band5G.Channels = []int{36, 40, 149}
	r.beginPass(rule, now)
	if len(r.requests) != 2 {
		t.Fatal(r.requests)
	}
	for index, q := range r.requests {
		if q.channel != 36 {
			t.Fatal(q)
		}
		r.markDispatched(index, q, now)
	}
	if r.collected(now.Add(89*time.Second)) || !r.collected(now.Add(90*time.Second)) {
		t.Fatal("wrong original90-second timeout")
	}
	for _, q := range r.requests {
		q.received = true
	}
	r.receivedCount = len(r.requests)
	if !r.collected(now) {
		t.Fatal("all-report completion must not wait for timer")
	}
	r.pass = 1
	r.beginPass(rule, now)
	for _, q := range r.requests {
		if q.channel != 149 || q.received || q.sent {
			t.Fatal(q)
		}
	}
}
func TestRRMSecondCollectionPreservesBaselineAndDoesNotAddNeighbors(t *testing.T) {
	nodes := []rrmNode{}
	for i := byte(1); i <= 3; i++ {
		ap := cweng.APStatus{ID: []string{"", "02:00:00:00:00:01", "02:00:00:00:00:02", "02:00:00:00:00:03"}[i]}
		nodes = append(nodes, rrmNode{AP: ap, Cap: cweng.RadioCapability{RadioID: 1}, BandID: 0})
	}
	r := newRRMRun(nodes)
	heard := func(i int, rssi int8) capwap.RrmNeigh {
		return capwap.RrmNeigh{MAC: apMAC(nodes[i].AP), Samples: []capwap.RrmRSSI{{Radio: 1, RSSI: rssi}, {Radio: 1, RSSI: -1}}}
	}
	r.ingest(0, []capwap.RrmNeigh{heard(1, -50)}, false)
	r.ingest(0, []capwap.RrmNeigh{heard(1, -70)}, false)
	if len(r.edges[0]) != 1 || r.edges[0][0].baseline != -54 {
		t.Fatal(r.edges)
	}
	r.ingest(0, []capwap.RrmNeigh{heard(1, -90), heard(2, -20)}, true)
	if len(r.edges[0]) != 1 || r.edges[0][0].baseline != -54 || r.edges[0][0].smoothed != -61 {
		t.Fatal(r.edges)
	}
}
func TestRRMMeasurementUsesTargetBandwidthAndInitialLevelTen(t *testing.T) {
	c := cweng.RadioCapability{RadioID: 3, Band: "5 GHz", Modes: []int{7, 9, 11}, SupportAX: true, SupportAC: true, Support160: true, MinPower: 3, MaxPower: 24}
	a := defaultRadioAdvanced(c)
	a.Mode = 11
	n := rrmNode{Cap: c, Band: RRMBand{Bandwidth: 5}, Setting: RadioSetting{Advanced: &a}}
	e := ndpElement([6]byte{2, 1, 2, 3, 4, 5}, n, 36, 10)
	p, err := capwap.ParsePrivNdpPara(e.Value[10:])
	if err != nil {
		t.Fatal(err)
	}
	// Requested160 is measured at80MHz in the active11ax path.
	if p.U8c != 11 || p.U8d != 3 || p.U8e != 24 || len(p.Tail) != 1 || p.Tail[0] != 36 {
		t.Fatal(p)
	}
}

func TestTPCOnlyUsesPriorAlgorithmResultForSecondRound(t *testing.T) {
	c := cweng.RadioCapability{RadioID: 1, Band: "2.4 GHz", MinPower: 3, MaxPower: 24, Channels: []int{1, 6, 11}, Bandwidths: []int{0}, Modes: []int{6}, MaxClients: 64}
	ap := cweng.APStatus{ID: "02:00:00:00:00:01"}
	rule := rrmTestRule()
	rule.Channel = false
	rule.Power = true
	r := newRRMRun([]rrmNode{{AP: ap, Cap: c, Band: rule.Band2G}})
	changed, err := r.calculate(rule, true)
	// 527498 compares previous result+a1 (initial0), not NDP level+44
	// (initial10). TPC-only therefore requests another collection here.
	if err != nil || !changed || r.levels[0] != 10 {
		t.Fatal(changed, err, r.levels)
	}
	changed, err = r.calculate(rule, false)
	if err != nil || changed {
		t.Fatal(changed, err)
	}
}
