package mobility

import (
	"testing"
	"time"
)

func TestV4AutomaticModeBoundariesAndStickyCompatibility(t *testing.T) {
	l := V4DefaultAutomaticLimits()
	if V4CheckMode(0, 2, false, 0, 0, l) != 2 || V4CheckMode(0, 2, true, 5, 30, l) != 1 {
		t.Fatal("startup/manual distinction lost")
	}
	if V4CheckMode(0, 1, true, 6, 0, l) != 2 || V4CheckMode(0, 1, true, 5, 31, l) != 2 {
		t.Fatal("manual count thresholds")
	}
	if V4ModeAfterJoin(0, 1, 5, l) != 1 || V4ModeAfterJoin(0, 1, 6, l) != 2 || V4ModeAfterAssociation(0, 1, 30, l) != 1 || V4ModeAfterAssociation(0, 1, 31, l) != 2 {
		t.Fatal("strict overflow boundary")
	}
	if V4ModeAfterJoin(1, 1, 500, l) != 1 || V4ModeAfterAssociation(1, 1, 1000, l) != 1 || V4ModeAfterAssociation(0, 2, 0, l) != 2 {
		t.Fatal("fixed/sticky mode changed")
	}
}

func TestV4AutomaticChannelRandomMatchesPinnedLibc(t *testing.T) {
	// Derived from the pinned degree31/separation3 recurrence,310 warmups,
	// uint32 multiplication and actual lookup-table offsets. No firmware run.
	for _, v := range []struct {
		seed      uint32
		two, five int
	}{{0, 6, 153}, {1, 6, 153}, {2, 6, 161}, {3, 11, 48}, {10, 0, 40}, {42, 6, 40}, {1795757329, 6, 161}, {0x80000001, 11, 40}, {0xffffffff, 6, 40}} {
		a, b := V4RedistributionChannels(v.seed)
		if a != v.two || b != v.five {
			t.Fatalf("seed %d: got %d/%d, want %d/%d", v.seed, a, b, v.two, v.five)
		}
	}
}

func TestV4AutomaticActivityIncludesIdleAndUnknownStatistics(t *testing.T) {
	now := time.Unix(0, 0)
	s := StationDB{}
	mac := MAC{2, 1}
	s.AssociateAt(mac, "a", now)
	if s.ActiveStationsOnAP("a", now) != 1 {
		t.Fatal("unknown uint32 sentinel must count as active")
	}
	s.ObserveActivity(mac, 1, 1)
	if s.ActiveStationsOnAP("a", now) != 0 {
		t.Fatal("rate boundary must be >1")
	}
	s.ObserveActivity(mac, 2, 0)
	s.AssociateAt(mac, "b", now)
	s.Disconnect(mac, now)
	if s.ActiveStationsOnAP("a", now) != 0 || s.ActiveStationsOnAP("b", now.Add(905*time.Second)) != 1 {
		t.Fatal("idle/location or sweep lifetime changed")
	}
	if s.ActiveStationsOnAP("b", now.Add(960*time.Second)) != 0 {
		t.Fatal("expired statistics retained")
	}
}
