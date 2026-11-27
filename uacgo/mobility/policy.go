package mobility

// Policy selects a complete station-decision family. Mode1/2 alone cannot
// identify it: V4 compatibility also uses a different selector from V6.
type Policy uint8

const (
	V6Policy Policy = iota
	V4Policy
)

func (p Policy) DefaultStationPHY(band int) PHY {
	if p == V4Policy {
		if band == 1 {
			return PHY{2, 2, 2, 9}
		}
		return PHY{0, 1, 1, 7}
	}
	if band == 1 {
		return PHY{3, 2, 4, 9}
	}
	return PHY{1, 1, 4, 7}
}

func (p Policy) StationPHY(word uint32, width int8, band int) PHY {
	nss, mode, mcs := uint8(word&15), uint8(word>>4&15), uint8(word>>8)
	if nss < 1 || nss > 16 || mode > 4 || mcs > 13 {
		return p.DefaultStationPHY(band)
	}
	return PHY{ObservedBandwidth(int(width), band), nss, mode, mcs}
}

// V4's auto mode probes AX then AC; it does not recognize configured BE
// modes12/13. V6 adds that probe and those two explicit mode values.
func (p Policy) RadioMode(configured int, ac, ax, be bool) uint8 {
	switch configured {
	case -1:
		if p == V6Policy && be {
			return 4
		}
		if ax {
			return 3
		}
		if ac {
			return 2
		}
		return 1
	case 0, 1, 2, 5:
		return 0
	case 3, 4, 6, 7:
		return 1
	case 8, 9:
		return 2
	case 10, 11:
		return 3
	case 12, 13:
		if p == V6Policy {
			return 4
		}
	}
	return 1
}

func (p Policy) CandidateRate(rssi int8, station, radio PHY, band int, mesh bool, backhaulMbps int) int {
	base := 85
	if p == V4Policy {
		base = 95
	}
	if int(rssi) <= -base {
		return 0
	}
	// The two images have byte-identical compiled SNR and bandwidth tables.
	rate := EstimateRate(uint8(int(rssi)+base), CandidatePHY(station, radio), band)
	if !mesh {
		return rate
	}
	if backhaulMbps <= 0 || rate == 0 {
		return 0
	}
	return int(int32(rate) * int32(backhaulMbps) / (int32(rate) + int32(backhaulMbps)))
}

func (s StationCapabilities) PHYFor(p Policy, band int) PHY {
	if band < 0 || band > 1 || !s.Ready[band] {
		return p.DefaultStationPHY(band)
	}
	return p.StationPHY(s.Word[band], s.Width[band], band)
}
