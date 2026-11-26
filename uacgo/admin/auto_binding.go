package admin

import (
	"sort"
	"uacgo/cweng"
)

// Original default_bind_freq is a 16-bit mask: successive 2.4 GHz radios in
// bits0..7 and successive 5 GHz radios in bits8..15, independent of AP-local
// radio IDs. A nil mask preserves older Go configurations using explicit IDs.
func selectedServiceRadios(s Service, ap cweng.APStatus) map[uint8]bool {
	out := map[uint8]bool{}
	if s.AutoBindFrequencies == nil {
		for _, id := range s.Radios {
			valid := len(ap.Capabilities) == 0 && (ap.Radios == 0 || int(id) <= ap.Radios)
			for _, c := range ap.Capabilities {
				if c.RadioID == id && c.FunctionType != 1 {
					valid = true
				}
			}
			if valid {
				out[id] = true
			}
		}
		return out
	}
	bits := frequencyRadioBits(ap)
	for _, r := range ap.Capabilities {
		if r.FunctionType == 1 {
			continue
		}
		if *s.AutoBindFrequencies&bits[r.RadioID] != 0 {
			out[r.RadioID] = true
		}
	}
	return out
}

// get_virtual_freq_band_with_type @729de0 searches every reported mode in
// model order and uses the first nonzero rank for a physical radio. It does
// not use the current mode's rank or renumber by the order of a Web list.
func frequencyRadioBits(ap cweng.APStatus) map[uint8]uint16 {
	caps := append([]cweng.RadioCapability{}, ap.Capabilities...)
	sort.SliceStable(caps, func(i, j int) bool { return caps[i].RadioID < caps[j].RadioID })
	out := map[uint8]uint16{}
	assign := func(members map[uint8]bool) {
		ranks := map[string]uint{}
		for _, r := range caps {
			if members != nil && !members[r.RadioID] {
				continue
			}
			rank := ranks[r.Band]
			ranks[r.Band]++
			if rank >= 8 {
				continue
			}
			if r.Band == "5 GHz" {
				rank += 8
			} else if r.Band != "2.4 GHz" {
				continue
			}
			if out[r.RadioID] == 0 {
				out[r.RadioID] = 1 << rank
			}
		}
	}
	if ap.HasCapability(92) {
		for _, mode := range ap.RadioModes {
			members := map[uint8]bool{}
			for _, id := range mode.Radios {
				members[id] = true
			}
			assign(members)
		}
	} else {
		assign(nil)
	}
	return out
}
