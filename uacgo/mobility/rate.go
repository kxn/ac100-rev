package mobility

// PHY is the capability tuple used by _sta_caps_calculate/_wlan_caps_calculate:
// bandwidth 0/1/2/3 means 20/40/80/160 MHz; mode0..4 is legacy/HT/VHT/HE/EHT.
type PHY struct{ Bandwidth, NSS, Mode, MCS uint8 }

func DefaultStationPHY(band int) PHY {
	if band == 1 {
		return PHY{3, 2, 4, 9}
	}
	return PHY{1, 1, 4, 7}
}

// Capabilities are accumulated component-wise in _stats_sta_support_cal. A
// station's greatest reported width is kept separately for each frequency.
func StationPHY(word uint32, bandwidth int8, band int) PHY {
	nss, mode, mcs := uint8(word&15), uint8((word>>4)&15), uint8(word>>8)
	if nss < 1 || nss > 16 || mode > 4 || mcs > 13 {
		return DefaultStationPHY(band)
	}
	bw := uint8(0)
	switch bandwidth {
	case 0:
		bw = 0
	case 1:
		bw = 1
	case 2, 3:
		bw = 2
	case 5:
		bw = 3
	default:
		if band == 1 {
			bw = 2
		}
	}
	return PHY{bw, nss, mode, mcs}
}

// RadioBandwidth is the WLAN decoder in _wlan_caps_calculate @4ea84c,
// after configured auto(2) has been replaced by the observed width. Unlike
// StationPHY, an observed2 is still unknown and falls back by frequency.
func RadioBandwidth(width, band int) uint8 {
	switch width {
	case 0:
		return 0
	case 1:
		return 1
	case 3:
		return 2
	case 5:
		return 3
	default:
		if band == 1 {
			return 2
		}
		return 0
	}
}

// CandidatePHY uses the station's MCS and min(width, streams, PHY mode),
// exactly as _steer_candidate_caps_calculate @0x004ea4c0.
func CandidatePHY(station, radio PHY) PHY {
	return PHY{min(station.Bandwidth, radio.Bandwidth), min(station.NSS, radio.NSS), min(station.Mode, radio.Mode), station.MCS}
}

// EstimateRate is estimate_rate_from_snr @0x004eab48. Integer interpolation
// truncates the slope before multiplying; floating-point interpolation would
// change the firmware's ranking near a rate boundary. MCS isn't consumed by
// this firmware function even though it is carried in the input tuple.
func EstimateRate(snr uint8, phy PHY, band int) int {
	if snr == 0 || band < 0 || band > 1 {
		return 0
	}
	mode, bw, nss := min(int(phy.Mode), 4), min(int(phy.Bandwidth), 3), min(max(int(phy.NSS), 1), 16)
	switch mode {
	case 0:
		nss, bw = 1, 0
	case 1:
		nss, bw = min(nss, 4), min(bw, 1)
	case 2, 3:
		nss = min(nss, 8)
	}
	rows := snrRates[band][mode]
	i := 0
	for rows[i].threshold <= int(snr) && rows[i].threshold != 255 && i < 13 {
		i++
	}
	rate := rows[i].rate
	if i != 13 && rows[i].threshold != 255 {
		if i == 0 {
			rate = rows[0].rate * int(snr) / rows[0].threshold
		} else {
			lo, hi := rows[i-1], rows[i]
			slope := 0
			if hi.threshold != lo.threshold {
				slope = (hi.rate - lo.rate) / (hi.threshold - lo.threshold)
			}
			rate = (slope*(int(snr)-lo.threshold) + lo.rate) & 0xffff
		}
	}
	return (rate * nss * bandwidthMultipliers[mode][bw] / bandwidthMultipliers[mode][0]) & 0xffff
}

// CandidateRate follows wss_steer_candidate_rate_estimate @0x004eb314. Signal
// conversion and the separate -10dB neighbor margin happen before selection;
// rate estimation uses the unadjusted RSSI, normalized with a fixed -85dBm.
func CandidateRate(rssi int8, station, radio PHY, band int, mesh bool, backhaulMbps int) int {
	if rssi < -84 {
		return 0
	}
	rate := EstimateRate(uint8(int(rssi)+85), CandidatePHY(station, radio), band)
	if !mesh {
		return rate
	}
	if backhaulMbps <= 0 || rate == 0 {
		return 0
	}
	return int(int32(rate) * int32(backhaulMbps) / (int32(rate) + int32(backhaulMbps)))
}
