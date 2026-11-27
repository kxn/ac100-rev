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
	Observe                          SelectionObserver
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
	firmwareQuickSort(rows, low, high, candidateCompare)
}

func firmwareQuickSort[T any](rows []T, low, high int, compare func(T, T) int) {
	for low < high {
		pivot := rows[low]
		left, right := low, high
		for left < right {
			for compare(rows[right], pivot) >= 0 && right > left {
				right--
			}
			if left != right {
				rows[left] = rows[right]
				left++
			}
			for compare(rows[left], pivot) <= 0 && left < right {
				left++
			}
			if left != right {
				rows[right] = rows[left]
				right--
			}
		}
		rows[left] = pivot
		if low < left {
			firmwareQuickSort(rows, low, left-1, compare)
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
	for rank, n := range rows {
		lastBand = n.Band
		maxLoad := MaxLoad2G
		if n.Band == 1 {
			maxLoad = MaxLoad5G
		}
		if n.RSSI < s.threshold(n.Band) || int(n.Load) > maxLoad || n.Rate == -1 || n.Rate < current+current/5 || n.Rate <= current+19 {
			if s.Observe != nil {
				reason := "rate_gain_absolute"
				switch {
				case n.RSSI < s.threshold(n.Band):
					reason = "rssi_threshold"
				case int(n.Load) > maxLoad:
					reason = "channel_load"
				case n.Rate == -1:
					reason = "unknown_rate"
				case n.Rate < current+current/5:
					reason = "rate_gain_twenty_percent"
				}
				traceSelection(s.Observe, "rejected", reason, n, rank)
			}
			continue
		}
		if len(selected) >= MaxCandidates {
			traceSelection(s.Observe, "limited", "four_candidate_limit", n, rank)
			break
		}
		selected = append(selected, n)
		traceSelection(s.Observe, "selected", "rate_load_rssi_pass", n, rank)
	}
	// 0x004e5cd4 reads the last radio entry's band. This is intentionally not
	// "corrected" to the first candidate's band; that would differ from V6.
	if len(selected) == 0 && s.CurrentRSSI < -85 && len(rows) > 0 && rows[0].RSSI > s.threshold(lastBand) {
		selected = append(selected, rows[0])
		traceSelection(s.Observe, "selected", "weak_rssi_fallback_uses_last_band", rows[0], 0)
	}
	return selected
}
