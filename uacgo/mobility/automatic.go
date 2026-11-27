package mobility

// V4AutomaticLimits are policy thresholds from _wsta_roam_read_config's
// profile lookup (apmng_roma); they are not the AC hardware capacity limits.
type V4AutomaticLimits struct {
	APs      int `json:"aps"`
	Stations int `json:"stations"`
}

func V4DefaultAutomaticLimits() V4AutomaticLimits { return V4AutomaticLimits{APs: 5, Stations: 30} }

// V4CheckMode is check_cur_wireless_network_mode@486994. Ordinary startup
// checks must not promote an automatic controller already in mode2.
func V4CheckMode(configured, current int, manual bool, aps, stations int, limits V4AutomaticLimits) int {
	if configured == 1 || configured == 2 {
		return configured
	}
	if !manual && current == 2 {
		return 2
	}
	if aps <= limits.APs && stations <= limits.Stations {
		return 1
	}
	return 2
}

// The join callback runs before the firmware increments its active count.
// joinedAPs includes that joining AP; the boundary is strictly greater.
func V4ModeAfterJoin(configured, current, joinedAPs int, limits V4AutomaticLimits) int {
	if configured == 0 && current <= 1 && joinedAPs > limits.APs {
		return 2
	}
	return current
}

func V4ModeAfterAssociation(configured, current, stations int, limits V4AutomaticLimits) int {
	if configured == 0 && current <= 1 && stations > limits.Stations {
		return 2
	}
	return current
}

// V4RedistributionChannels follows srand(time(NULL));rand();rand() in
// _set_rd_info_by_sta@484fd0, including uint32 multiplication and the
// table's +1 indexing. Zero in the2G table means leave that radio unchanged.
// The generator is the image's uClibc type3 (degree31, separation3), not
// Go math/rand and not an invented even-distribution policy.
func V4RedistributionChannels(seed uint32) (int, int) {
	var state [31]uint32
	if seed == 0 {
		seed = 1
	}
	state[0] = seed
	for i := 1; i < len(state); i++ {
		previous := int64(int32(state[i-1]))
		word := uint32((previous%127773)*16807 - (previous/127773)*2836)
		if int32(word) < 0 {
			word += 0x7fffffff
		}
		state[i] = word
	}
	f, r := 3, 0
	next := func() uint32 {
		state[f] += state[r]
		out := state[f] >> 1
		f++
		r++
		if f == 31 {
			f = 0
		}
		if r == 31 {
			r = 0
		}
		return out
	}
	for i := 0; i < 310; i++ {
		next()
	}
	index2 := int(next()*10%3) + 1
	index5 := int(next()*10&7) + 1
	channels2 := [4]int{1, 6, 11, 0}
	channels5 := [8]int{36, 40, 44, 48, 149, 153, 157, 161}
	return channels2[index2], channels5[index5]
}
