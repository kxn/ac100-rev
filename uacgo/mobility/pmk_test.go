package mobility

import (
	"testing"
	"time"
)

func TestPMKLookupStatusesAndDisconnectTimerFollowFirmware(t *testing.T) {
	var c PMKCache
	now := time.Unix(10000, 0)
	c.Start(now)
	mac := MAC{2, 1, 2, 3, 4, 5}
	if _, status := c.Lookup(mac, "", now); status != 1 {
		t.Fatal(status)
	}
	p := PMK{Service: "office", Key: [32]byte{1}, Name: [16]byte{2}}
	c.Inform(mac, p, now)
	for service, want := range map[string]uint8{"": 2, "other": 1, "office": 0} {
		if _, got := c.Lookup(mac, service, now); got != want {
			t.Fatal(service, got)
		}
	}
	c.Disconnect(mac, now.Add(10*time.Second))
	// Expires at70, but the minute sweeper at60 cannot delete it yet.
	c.Tick(now.Add(60 * time.Second))
	if got, status := c.Lookup(mac, "office", now.Add(80*time.Second)); status != 0 || got != p {
		t.Fatal(status, got)
	}
	c.Associate(mac, "office")
	if _, status := c.Lookup(mac, "office", now.Add(120*time.Second)); status != 0 {
		t.Fatal("association did not cancel deletion")
	}
	c.Disconnect(mac, now.Add(121*time.Second))
	c.Tick(now.Add(180 * time.Second))
	if _, status := c.Lookup(mac, "office", now.Add(240*time.Second)); status != 1 {
		t.Fatal("disconnected key did not expire")
	}
}
