package admin

import (
	"fmt"
	"time"
)

// The vendor's time_switch rules execute in the AC (time_mngt -> wservice
// enable/disable). The standalone controller evaluates the same weekly policy.
type ServiceSchedule struct {
	Enabled  bool           `json:"enabled"`
	Timezone string         `json:"timezone"`
	Action   string         `json:"action"` // on inside windows, or off inside windows
	Windows  []WeeklyWindow `json:"windows"`
	Dates    []DateWindow   `json:"dates,omitempty"`
}
type WeeklyWindow struct {
	Days  uint8 `json:"days"`
	Start int   `json:"start_minute"`
	End   int   `json:"end_minute"`
}
type DateWindow struct {
	Start string `json:"start"`
	End   string `json:"end"`
}

func (s *ServiceSchedule) validate() error {
	if s == nil || !s.Enabled {
		return nil
	}
	if _, err := time.LoadLocation(s.Timezone); err != nil {
		return fmt.Errorf("无线定时规则时区无效")
	}
	if s.Action != "on" && s.Action != "off" || len(s.Windows) == 0 || len(s.Windows) > 64 || len(s.Dates) > 32 {
		return fmt.Errorf("无线定时规则无效")
	}
	for _, w := range s.Windows {
		if w.Days == 0 || w.Days > 127 || w.Start < 0 || w.Start >= 1440 || w.End < 0 || w.End > 1440 || w.Start == w.End {
			return fmt.Errorf("无线定时规则的日期或时段无效")
		}
	}
	for _, d := range s.Dates {
		a, e1 := time.Parse("2006-01-02", d.Start)
		b, e2 := time.Parse("2006-01-02", d.End)
		if e1 != nil || e2 != nil || a.After(b) {
			return fmt.Errorf("无线定时规则的日期范围无效")
		}
	}
	return nil
}
func (s *ServiceSchedule) active(now time.Time) bool {
	if s == nil || !s.Enabled {
		return true
	}
	loc, err := time.LoadLocation(s.Timezone)
	if err != nil {
		return false
	}
	now = now.In(loc)
	day := (int(now.Weekday()) + 6) % 7
	minute := now.Hour()*60 + now.Minute()
	inside := false
	dateOK := len(s.Dates) == 0
	date := now.Format("2006-01-02")
	for _, d := range s.Dates {
		dateOK = dateOK || (date >= d.Start && date <= d.End)
	}
	if dateOK {
		for _, w := range s.Windows {
			if w.Start < w.End {
				inside = inside || w.Days&(1<<day) != 0 && minute >= w.Start && minute < w.End
			} else {
				previous := (day + 6) % 7
				inside = inside || (w.Days&(1<<day) != 0 && minute >= w.Start) || (w.Days&(1<<previous) != 0 && minute < w.End)
			}
		}
	}
	if s.Action == "off" {
		return !inside
	}
	return inside
}
