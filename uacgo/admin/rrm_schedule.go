package admin

import "fmt"

// time_mngt.check_timeobj_conflict -> ac_validator.check_time_conflict.
// RRM uses 299 seconds (>= 300 apart); AP reboot uses 599 seconds.
// Time objects trigger at the start of a weekly window, not its end.
func triggerConflict(a, b *ServiceSchedule, seconds int) bool {
	if a == nil || b == nil || !a.Enabled || !b.Enabled {
		return false
	}
	for _, x := range a.Windows {
		for _, y := range b.Windows {
			for d := 0; d < 7; d++ {
				if x.Days&(1<<d) == 0 {
					continue
				}
				for delta := -1; delta <= 1; delta++ {
					e := (d + delta + 7) % 7
					if y.Days&(1<<e) == 0 {
						continue
					}
					left, right := x.Start*60, y.Start*60
					forward, backward := (right-left+86400)%86400, (left-right+86400)%86400
					if d == e && (forward <= seconds || backward <= seconds) ||
						e == (d+1)%7 && left > right && forward <= seconds ||
						d == (e+1)%7 && right > left && backward <= seconds {
						return true
					}
				}
			}
		}
	}
	return false
}

func validateRRMTimeConflicts(cfg Config) error {
	for i, r := range cfg.RRM {
		if !r.Enabled {
			continue
		}
		for _, other := range cfg.RRM[:i] {
			if other.Enabled && triggerConflict(r.Schedule, other.Schedule, 299) {
				return fmt.Errorf("无线优化计划 %s 与 %s 间隔须至少 300 秒", r.Name, other.Name)
			}
		}
		options := []APOptions{cfg.APDefaults}
		for _, p := range cfg.APProfiles {
			options = append(options, p.Options)
		}
		for _, g := range cfg.Groups {
			options = append(options, g.Options)
		}
		for _, t := range cfg.Templates {
			options = append(options, t.Options)
		}
		for _, o := range options {
			if triggerConflict(r.Schedule, o.RebootSchedule, 599) {
				return fmt.Errorf("无线优化计划 %s 与 AP 重启计划间隔须至少 600 秒", r.Name)
			}
		}
	}
	return nil
}
