package mobility

import (
	"testing"
	"time"
)

func TestStatisticsFirmwareBoundaries(t *testing.T) {
	if got := SupportWord(0xabcd0932, 0x12340741); got != 0x12340942 {
		t.Fatalf("component maximum %08x", got)
	}
	var caps StationCapabilities
	if caps.PHY(1) != DefaultStationPHY(1) {
		t.Fatal("missing band defaults")
	}
	caps.Observe(0, 0x0731, 1)
	caps.Observe(1, 0x0942, 5)
	caps.Observe(1, 0x0721, 0)
	if p := caps.PHY(1); p.NSS != 2 || p.Mode != 4 || p.Bandwidth != 3 || p.MCS != 9 {
		t.Fatal(p)
	}
	var s RSSINeighbors
	mac := MAC{2, 1}
	now := time.Unix(1000, 0)
	age := NeighborAge(60)
	for i := uint8(1); i <= 12; i++ {
		s.Update(mac, RSSINeighbor{AP: "a", Radio: i, RSSI: -70, At: now}, age)
	}
	s.Update(mac, RSSINeighbor{AP: "b", Radio: 1, RSSI: -71, At: now}, age)
	if len(s.Get(mac, now, age)) != 12 || s.Get(mac, now, age)[0].AP != "a" {
		t.Fatal("weak newcomer displaced entry")
	}
	s.Update(mac, RSSINeighbor{AP: "b", Radio: 1, RSSI: -70, At: now}, age)
	if s.Get(mac, now, age)[0].AP != "b" {
		t.Fatal("equal newcomer rejected")
	}
	if len(s.Get(mac, now.Add(age), age)) != 0 {
		t.Fatal("boundary age")
	}
	s.Update(mac, RSSINeighbor{AP: "c", Radio: 1, RSSI: -90, At: now.Add(age)}, age)
	if len(s.Get(mac, now.Add(age), age)) != 1 {
		t.Fatal("expired slot not replaced")
	}
}

// Policy entrypoints may be idle between timer callbacks. Catching up must
// use the latest scheduled sweep instant, not expire at the next packet time.
func TestTimerCatchupDoesNotInventImmediateExpiry(t *testing.T) {
	start := time.Unix(10000, 0)
	mac := MAC{2, 1}
	var b Balance
	b.Start(start)
	b.Probe(mac, "b", start.Add(100*time.Second))
	aps := map[string]APCount{"a": {Online: true, Clients: 5}, "b": {Online: true}}
	if b.Admit(mac, "a", BalanceRule{Clients: 2, Difference: 2, MaxFailures: 2}, aps, start.Add(1001*time.Second)) {
		t.Fatal("900s cleanup swept at packet time1001 instead of timer900")
	}
	if !b.Admit(mac, "a", BalanceRule{Clients: 2, Difference: 2, MaxFailures: 2}, aps, start.Add(1200*time.Second)) {
		t.Fatal("1200s sweep did not expire probe")
	}
	var cache PMKCache
	cache.Start(start)
	cache.Inform(mac, PMK{Service: "s"}, start)
	cache.Disconnect(mac, start.Add(59*time.Second))
	if _, code := cache.Lookup(mac, "s", start.Add(119*time.Second)); code != 0 {
		t.Fatal("PMK deleted before120s timer")
	}
	if _, code := cache.Lookup(mac, "s", start.Add(120*time.Second)); code != 1 {
		t.Fatal("PMK not deleted at120s timer")
	}
}

func TestFirmwareStationStatisticsRetainedUntil905SecondMinuteSweep(t *testing.T) {
	var db StationDB
	start := time.Unix(20000, 0)
	mac := MAC{2, 9}
	db.Start(start)
	db.Associate(mac, start)
	db.Observe(mac, 1, 0x942, 5)
	db.Disconnect(mac, start)
	db.Tick(start.Add(905 * time.Second))
	if !db.Capabilities(mac).Ready[1] {
		t.Fatal("entry deleted at905 rather than next60-second sweep960")
	}
	db.Associate(mac, start.Add(920*time.Second))
	db.Tick(start.Add(960 * time.Second))
	if !db.Capabilities(mac).Ready[1] {
		t.Fatal("reassociation did not cancel retention timer")
	}
	db.Disconnect(mac, start.Add(1000*time.Second))
	db.Tick(start.Add(1920 * time.Second))
	if db.Capabilities(mac).Ready[1] {
		t.Fatal("expired statistics survived the source sweep")
	}
}
