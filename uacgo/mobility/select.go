package mobility

// Candidate is the 0x20-byte neighbor record consumed by the active
// roam_nbr_select @0x004e5638, not the older unused _roaming_nbr_select helper.
type Candidate struct {
	AP                   string
	Radio, WLAN, Channel uint8
	BSSID                MAC
	Band                 int
	RSSI                 int8
	Rate                 int
	Load                 uint8
}

type Selection struct {
	CurrentRSSI                      int8
	CurrentRate                      int
	ThresholdType2G, ThresholdType5G int
}

func candidateCompare(a, b Candidate) int {
	if a.Rate != b.Rate {
		if a.Rate > b.Rate {
			return -1
		}
		return 1
	}
	if a.Band != b.Band {
		if a.Band > b.Band {
			return -1
		}
		return 1
	}
	if a.RSSI != b.RSSI {
		if a.RSSI > b.RSSI {
			return -1
		}
		return 1
	}
	return 0
}

// The firmware quicksort's tie behavior is part of selection. Do not introduce
// an AP-ID/client-count tiebreaker or replace it with an unrelated sort.
func firmwareSort(rows []Candidate, low, high int) {
	for low < high {
		pivot := rows[low]
		left, right := low, high
		for left < right {
			for candidateCompare(rows[right], pivot) >= 0 && right > left {
				right--
			}
			if left != right {
				rows[left] = rows[right]
				left++
			}
			for candidateCompare(rows[left], pivot) <= 0 && left < right {
				left++
			}
			if left != right {
				rows[right] = rows[left]
				right--
			}
		}
		rows[left] = pivot
		if low < left {
			firmwareSort(rows, low, left-1)
		}
		low = left + 1
	}
}

func (s Selection) threshold(band int) int8 {
	typ, threshold := s.ThresholdType2G, int8(-85)
	if band == 1 {
		typ, threshold = s.ThresholdType5G, -87
	}
	if typ&1 == 0 {
		return -75
	}
	return threshold
}

// Select reproduces the active nbr_cmp/nbr_filter path. The legacy RSSI-delta
// helper is not called here. Back-connect blacklist time is an AP parameter,
// not a controller-side "last successful ACK" cooldown.
func (s Selection) Select(neighbors []Candidate) []Candidate {
	rows := append([]Candidate{}, neighbors...)
	firmwareSort(rows, 0, len(rows)-1)
	selected := []Candidate{}
	current := s.CurrentRate & 0xffff
	lastBand := 0
	for _, n := range rows {
		lastBand = n.Band
		maxLoad := MaxLoad2G
		if n.Band == 1 {
			maxLoad = MaxLoad5G
		}
		if n.RSSI < s.threshold(n.Band) || int(n.Load) > maxLoad || n.Rate == -1 || n.Rate < current+current/5 || n.Rate <= current+19 {
			continue
		}
		if len(selected) >= MaxCandidates {
			break
		}
		selected = append(selected, n)
	}
	// 0x004e5cd4 reads the last radio entry's band. This is intentionally not
	// "corrected" to the first candidate's band; that would differ from V6.
	if len(selected) == 0 && s.CurrentRSSI < -85 && len(rows) > 0 && rows[0].RSSI > s.threshold(lastBand) {
		selected = append(selected, rows[0])
	}
	return selected
}
