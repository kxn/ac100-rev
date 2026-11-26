package rrm

import "fmt"

// so+db44/db90 use unsigned32 arithmetic and round to ten power levels.
func LevelForPower(dbm, maximum, minimum uint8) uint8 {
	span := uint32(maximum) - uint32(minimum)
	if span == 0 {
		return 10
	}
	level := ((((uint32(dbm)-uint32(minimum))*18)/span + 1) >> 1) + 1
	if level > 10 {
		return 10
	}
	return uint8(level)
}
func PowerForLevel(level, maximum, minimum uint8) uint8 {
	value := (((uint32(maximum)-uint32(minimum))*(uint32(level)-1)*2)/9 + 1) >> 1
	if value > 255 {
		return 255
	}
	return uint8(uint32(minimum) + value)
}

// Powers ports so+677c. Only incoming neighbors on other APs feed TPC;
// librrm_exec_by_param creates that list at +0x74 and sorts it by RSSI.
// Each library call runs one TPC step. The UAC business layer can collect
// neighbors again and invoke a second step with the updated level. Library
// working bounds are not exported by librrm_exec_by_param.
func Powers(radios []Radio, cfg Config) ([]uint8, error) {
	if len(radios) == 0 || cfg.MinPower > cfg.MaxPower {
		return nil, fmt.Errorf("invalid RRM power bounds")
	}
	edges, err := normalize(radios)
	if err != nil {
		return nil, err
	}
	incoming := make([][]Neighbor, len(radios))
	// Source insertion order is the original radio/report order; preprocessing
	// for each receiving list happens after every edge has been constructed.
	for i, r := range radios {
		for _, n := range edges[i] {
			if radios[n.Target].AP != r.AP {
				incoming[n.Target] = append(incoming[n.Target], Neighbor{Target: i, RSSI: n.RSSI})
			}
		}
	}
	for i := range incoming { // Same stable RSSI comparator.
		for j := 1; j < len(incoming[i]); j++ {
			for k := j; k > 0 && incoming[i][k-1].RSSI < incoming[i][k].RSSI; k-- {
				incoming[i][k-1], incoming[i][k] = incoming[i][k], incoming[i][k-1]
			}
		}
	}
	out := make([]uint8, len(radios))
	for i, r := range radios {
		upper, lower := uint32(r.UpperPower), uint32(r.LowerPower)
		maximum, minimum := uint32(r.MaxPower), uint32(r.MinPower)
		if upper == 0 {
			if cfg.MaxPower == 0 || maximum <= uint32(cfg.MaxPower) {
				upper = (maximum + 1) & 255
			} else {
				bound := max(minimum, uint32(cfg.MaxPower))
				level := LevelForPower(uint8(bound), r.MaxPower, r.MinPower)
				p := PowerForLevel(level, r.MaxPower, r.MinPower)
				if bound < uint32(p) {
					p = PowerForLevel(level-1, r.MaxPower, r.MinPower)
				}
				upper = (uint32(p) + 1) & 255
			}
		}
		if lower == 0 {
			if cfg.MinPower == 0 || uint32(cfg.MinPower) <= minimum {
				lower = (minimum - 1) & 255
			} else {
				bound := min(maximum, uint32(cfg.MinPower))
				level := LevelForPower(uint8(bound), r.MaxPower, r.MinPower)
				p := PowerForLevel(level, r.MaxPower, r.MinPower)
				if uint32(p) < bound {
					p = PowerForLevel(level+1, r.MaxPower, r.MinPower)
				}
				lower = (uint32(p) - 1) & 255
			}
		}
		current := uint32(PowerForLevel(r.PowerLevel, r.MaxPower, r.MinPower))
		next := current
		list := incoming[i]
		if len(list) < int(cfg.TargetNeighbors) {
			if len(list) == 0 {
				if int32(current) < int32(upper-1) {
					next = (current + uint32(int32(upper-current)/2)) & 255
				}
			} else if list[0].RSSI < cfg.PowerThreshold && int32(lower) < int32(upper-uint32(cfg.PowerStop)) {
				step := min(uint32(uint8(int(cfg.PowerThreshold)-int(list[0].RSSI))), uint32(cfg.PowerStep))
				lower = max(current, lower) & 255
				if int32(step) < int32(upper-current) {
					next = (current + step) & 255
				} else {
					next = (upper - 1) & 255
				}
			}
		} else if len(list) > 0 {
			idx := int(cfg.TargetNeighbors) - 1
			if idx < 0 {
				idx = 0
			}
			signal := list[idx].RSSI
			if cfg.PowerThreshold < signal && int32(lower) < int32(upper-uint32(cfg.PowerStop)) {
				step := min(uint32(uint8(int(signal)-int(cfg.PowerThreshold))), uint32(cfg.PowerStep))
				if current < upper {
					upper = current
				}
				if int32(step) < int32(current-lower) {
					next = (current - step) & 255
				} else {
					next = (lower + 1) & 255
				}
			}
		}
		out[i] = LevelForPower(uint8(next), r.MaxPower, r.MinPower)
	}
	return out, nil
}
