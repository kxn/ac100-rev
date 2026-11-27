package mobility

import (
	"reflect"
	"testing"
	"time"
)

func TestObserversPreserveSelectionAndStatefulAdmission(t *testing.T) {
	rows := []Candidate{{AP: "slow", Band: 1, RSSI: -60, Rate: 101}, {AP: "fast", Band: 1, RSSI: -55, Rate: 500}, {AP: "2g", RSSI: -50, Rate: 300}, {AP: "weak", Band: 1, RSSI: -95, Rate: 900}}
	var steps []SelectionStep
	observer := func(s SelectionStep) { steps = append(steps, s) }
	v6 := Selection{CurrentRSSI: -70, CurrentRate: 100, ThresholdType2G: 1, ThresholdType5G: 1}
	want := v6.Select(rows)
	v6.Observe = observer
	if got := v6.Select(rows); !reflect.DeepEqual(want, got) || len(steps) == 0 {
		t.Fatal("V6 observer changed selection", got, want)
	}
	v4 := V4Selection{CurrentRSSI: -70, ActualMode: 2, Difference: 5}
	calls := []string{}
	admit := func(n Candidate) bool { calls = append(calls, n.AP); return n.AP != "fast" }
	want = v4.Select(rows, admit)
	wantCalls := append([]string{}, calls...)
	calls = nil
	steps = nil
	v4.Observe = observer
	if got := v4.Select(rows, admit); !reflect.DeepEqual(want, got) || !reflect.DeepEqual(calls, wantCalls) || len(steps) == 0 {
		t.Fatal("V4 observer changed pseudo-admission traversal", got, calls, wantCalls)
	}
	now := time.Unix(1000, 0)
	mac := MAC{2, 1}
	plain, observed := &Balance{}, &Balance{}
	decisions := 0
	observed.Observe = func(MAC, BalanceDecision) { decisions++ }
	aps := map[string]APCount{"busy": {true, 5}, "low": {true, 0}}
	for _, b := range []*Balance{plain, observed} {
		b.Probe(mac, "low", now)
	}
	for i := 0; i < 5; i++ {
		at := now.Add(time.Duration(i) * time.Second)
		a := plain.Admit(mac, "busy", BalanceRule{2, 2, 2}, aps, at)
		b := observed.Admit(mac, "busy", BalanceRule{2, 2, 2}, aps, at)
		if a != b || !reflect.DeepEqual(plain.stations, observed.stations) {
			t.Fatal("observer changed balance counters")
		}
	}
	if decisions != 5 {
		t.Fatal("missing balance decisions", decisions)
	}
}
