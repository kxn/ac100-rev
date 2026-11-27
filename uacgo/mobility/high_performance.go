package mobility

import "uacgo/capwap"

// CommonChannels is the V4 high-performance coordinator's three frequency
// slots. They are not the per-AP radio numbers (a dual-band AP has only one
// 5 GHz radio, a tri-band AP has two).
type CommonChannels [3]int

type V4ChannelSelection struct {
	Channels CommonChannels
	Best5    int
}

// ACS completion has a distinct downlink entry: dual-band radio2 receives
// the overall best5 channel, whereas join/manual propagation uses slots.
func V4ACSChannel(s V4ChannelSelection, radio, count int, fiveGHz bool) int {
	channel := 0
	if !fiveGHz {
		channel = s.Channels[0]
	}
	if count == 2 && radio == 2 && s.Best5 != 0 {
		return s.Best5
	}
	if count == 3 {
		for _, ch := range s.Channels[1:] {
			if V4ChannelBand(ch) == radio {
				channel = ch
			}
		}
	}
	return channel
}

// V4ChannelBand follows rdmngr_db_get_band_by_channel@61e4c0 in the official
// V4.0 1.4.3 Build240715 image. In particular channel14 is outside band1.
func V4ChannelBand(channel int) int {
	switch {
	case channel >= 1 && channel <= 13:
		return 1
	case channel >= 36 && channel <= 64:
		return 2
	case channel >= 100 && channel <= 165:
		return 3
	}
	return 0
}

// Update implements update_high_per_ap_chn_info@482dfc. AP reports may seed
// an unset slot; manual writes and completed ACS rounds replace it.
func (c *CommonChannels) Update(band, channel int, force bool) bool {
	if band < 1 || band > 3 || !force && c[band-1] != 0 && c[band-1] != -1 {
		return false
	}
	c[band-1] = channel
	return true
}

// V4CommonChannel follows _wsta_intelligent_roam_set_rd_info@484800.
// V4's dual-band path prefers the low-band slot, falling back to the high
// slot. V6 instead has a fourth, overall-best-5GHz slot; do not mix them.
func V4CommonChannel(c CommonChannels, radio, count int, fiveGHz bool, filterBand int) int {
	if !fiveGHz {
		if filterBand == 0 || filterBand == radio {
			return c[0]
		}
		return 0
	}
	if count == 2 {
		if (filterBand == 0 || filterBand == 2) && c[1] != 0 {
			return c[1]
		}
		if filterBand == 0 || filterBand == 3 {
			return c[2]
		}
	} else if count == 3 && (radio == 2 || radio == 3) && (filterBand == 0 || filterBand == radio) {
		return c[radio-1]
	}
	return 0
}

// V4SelectCommonChannels translates wsta_roam_chnl_handle@486aa8 and its
// worker@4857a8. This ACS is separate from the librrm SCA optimization policy.
// Aggregation is a sum, not an average. Any reject flag chooses the load
// branch for the whole round. Unobserved channels retain the -1 sentinel.
func V4SelectCommonChannels(reports [][]capwap.ChannelScanSample) V4ChannelSelection {
	var bss, load [193]int
	for i := range bss {
		bss[i], load[i] = -1, -1
	}
	rejected := false
	for _, report := range reports {
		for _, row := range report {
			rejected = rejected || row.Rejected == 1
			ch := int(row.Channel)
			if ch >= len(bss) {
				continue
			}
			if bss[ch] == -1 {
				bss[ch], load[ch] = 0, 0
			}
			bss[ch] += int(row.BSS)
			load[ch] += int(row.Load)
		}
	}
	choose := func(start, end, tieEnd, otherBand int) int {
		best := -1
		for ch := start; ch <= end; ch++ {
			if otherBand >= 0 && V4ChannelBand(ch) == otherBand {
				continue
			}
			metric := bss[ch]
			if rejected {
				metric = load[ch]
			}
			if metric < 0 {
				continue
			}
			prior := -1
			if best >= 0 {
				prior = bss[best]
				if rejected {
					prior = load[best]
				}
			}
			if best < 0 || metric < prior {
				best = ch
			}
		}
		if !rejected && best >= 0 {
			for ch := start; ch <= tieEnd; ch++ {
				if otherBand >= 0 && V4ChannelBand(ch) == otherBand {
					continue
				}
				if bss[ch] == bss[best] && load[ch] < load[best] {
					best = ch
				}
			}
		}
		return best
	}
	end2 := 13
	if rejected {
		end2 = 14
	}
	ch2 := choose(1, end2, 14, -1)
	if ch2 < 0 {
		ch2 = 1
	}
	best5 := choose(15, 192, 192, -1)
	if best5 < 0 {
		best5 = 36
	}
	out := CommonChannels{ch2, 36, 149}
	other := -1
	if !rejected {
		other = choose(15, 192, 192, V4ChannelBand(best5))
	}
	// The V4 reject branch deliberately uses the default other-band channel.
	// The non-reject branch independently searches that band. Do not retain
	// the best-band temporary if there is no other-band sample.
	if V4ChannelBand(best5) == 2 {
		out[1] = best5
		if other >= 0 {
			out[2] = other
		}
	} else {
		out[2] = best5
		if other >= 0 {
			out[1] = other
		}
	}
	return V4ChannelSelection{Channels: out, Best5: best5}
}
