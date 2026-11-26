package admin

import (
	"testing"
	"time"
)

func TestWeeklyScheduleDatesTimezoneAndOvernight(t *testing.T) {
	s := &ServiceSchedule{Enabled: true, Timezone: "Asia/Singapore", Action: "on", Windows: []WeeklyWindow{{Days: 1, Start: 22 * 60, End: 2 * 60}}}
	if err := s.validate(); err != nil {
		t.Fatal(err)
	}
	for _, row := range []struct {
		utc    string
		active bool
	}{{"2026-11-23T13:59:00Z", false}, {"2026-11-23T14:00:00Z", true}, {"2026-11-23T17:59:00Z", true}, {"2026-11-23T18:00:00Z", false}, {"2026-11-24T15:00:00Z", false}} {
		now, _ := time.Parse(time.RFC3339, row.utc)
		if s.active(now) != row.active {
			t.Fatalf("%s: want %v", row.utc, row.active)
		}
	}
	s.Dates = []DateWindow{{Start: "2026-12-01", End: "2026-12-31"}}
	now, _ := time.Parse(time.RFC3339, "2026-11-23T14:00:00Z")
	if s.active(now) {
		t.Fatal("ignored calendar date")
	}
	s.Action = "off"
	if !s.active(now) {
		t.Fatal("off-inside inverted calendar incorrectly")
	}
	s.Timezone = "bad/timezone"
	if s.validate() == nil {
		t.Fatal("invalid timezone accepted")
	}
}
