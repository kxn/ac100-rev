package admin

import "uacgo/cweng"

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
	ranks := map[string]uint{}
	for _, r := range ap.Capabilities {
		rank := ranks[r.Band]
		ranks[r.Band]++
		if r.FunctionType == 1 {
			continue
		}
		if rank >= 8 {
			continue
		}
		bit := rank
		if r.Band == "5 GHz" {
			bit += 8
		} else if r.Band != "2.4 GHz" {
			continue
		}
		if *s.AutoBindFrequencies&(1<<bit) != 0 {
			out[r.RadioID] = true
		}
	}
	return out
}
