package mobility

import (
	"testing"
	"time"
)

// Expected transitions are transcribed from V6 4f6f54/4f2ed0/4f263c/4f1a5c,
// not fitted to the behavior of a running AP or to the previous Go policy.
func TestBalanceUsesStationGlobalFailuresAndLastRejectionTime(t *testing.T) {
	now := time.Unix(10000, 0)
	var b Balance
	b.Start(now)
	mac := MAC{2, 1, 2, 3, 4, 5}
	b.Probe(mac, "low", now)
	rule := BalanceRule{Clients: 2, Difference: 2, MaxFailures: 2}
	aps := map[string]APCount{"first": {true, 3}, "second": {true, 4}, "low": {true, 0}}
	if b.Admit(mac, "first", rule, aps, now) || b.Admit(mac, "second", rule, aps, now.Add(50*time.Second)) {
		t.Fatal("first two rejects must share one station counter across APs")
	}
	if !b.Admit(mac, "first", rule, aps, now.Add(65*time.Second)) {
		t.Fatal("counter was reset from first rejection rather than last rejection")
	}
	if b.Admit(mac, "second", rule, aps, now.Add(110*time.Second)) {
		t.Fatal("counter did not reset exactly 60 seconds after last rejection")
	}
}

func TestBalanceDiscoveryLRUAndFiveMinuteExpirySweep(t *testing.T) {
	now := time.Unix(10000, 0)
	var b Balance
	b.Start(now)
	mac := MAC{2, 1, 2, 3, 4, 5}
	rule := BalanceRule{Clients: 2, Difference: 2, MaxFailures: 100}
	aps := map[string]APCount{"busy": {true, 3}, "low": {true, 0}}
	b.Probe(mac, "low", now.Add(100*time.Second))
	b.Tick(now.Add(900 * time.Second))
	// The row is 901 seconds old, but the last sweep at900 couldn't expire it.
	if b.Admit(mac, "busy", rule, aps, now.Add(1001*time.Second)) {
		t.Fatal("900-second expiry was made immediate instead of timer-driven")
	}
	if !b.Admit(mac, "busy", rule, aps, now.Add(1200*time.Second)) {
		t.Fatal("300-second sweep failed to remove old discovery")
	}
	for i := 0; i < 11; i++ {
		b.Probe(mac, string(rune('a'+i)), now.Add(1201*time.Second))
	}
	if len(b.stations[mac].probes) != 10 || b.stations[mac].probes[0].ap != "b" {
		t.Fatal("not a ten-AP LRU")
	}
	b.Probe(mac, "b", now.Add(1202*time.Second))
	if b.stations[mac].probes[9].ap != "b" || len(b.stations[mac].probes) != 10 {
		t.Fatal("refresh did not move to tail")
	}
}

func TestBalanceUnknownCoverageAndOfflinePeerPermitAdmission(t *testing.T) {
	var b Balance
	now := time.Now()
	mac := MAC{2, 1, 2, 3, 4, 5}
	rule := BalanceRule{2, 2, 2}
	aps := map[string]APCount{"busy": {true, 3}, "low": {false, 0}}
	if !b.Admit(mac, "busy", rule, aps, now) {
		t.Fatal("no discovery must permit")
	}
	b.Probe(mac, "low", now)
	if !b.Admit(mac, "busy", rule, aps, now) {
		t.Fatal("offline peer must not reject")
	}
	aps["low"] = APCount{true, 0}
	b.ForgetAP("low")
	if !b.Admit(mac, "busy", rule, aps, now) {
		t.Fatal("reconnected peer inherited old coverage")
	}
}
