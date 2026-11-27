package mobility

// V4Selection is the active _roaming_nbr_select@4871bc, reached through
// packet_create@487610. The same-named helper is uncalled in the V6 image.
type V4Selection struct {
	CurrentRSSI                      int8
	CurrentBand, ActualMode          int
	ThresholdType2G, ThresholdType5G int
	RSSI2G, RSSI5G                   int8
	Difference                       uint8
}

func (s V4Selection) filtered(n Candidate) bool {
	if s.ActualMode == 2 {
		typ, threshold, load := s.ThresholdType2G, int8(-75), MaxLoad2G
		if n.Band == 1 {
			typ, threshold, load = s.ThresholdType5G, -80, MaxLoad5G
		}
		if typ&1 != 0 {
			threshold = s.RSSI2G
			if n.Band == 1 {
				threshold = s.RSSI5G
			}
		}
		if n.RSSI <= threshold || int(n.Load) > load {
			return true
		}
	}
	adjusted := n.RSSI
	if s.CurrentBand == 0 && n.Band == 1 {
		return adjusted < s.CurrentRSSI
	}
	adjusted = int8(int(n.RSSI) - int(s.Difference))
	if s.CurrentBand == 1 && n.Band == 0 {
		adjusted = int8(int(adjusted) - 5) // DAT7314f0, not the BSTM -10 margin.
	}
	return adjusted < s.CurrentRSSI
}

func (s V4Selection) compare(a, b Candidate) int {
	if a.Rate == -1 {
		if b.Rate == -1 {
			if a.RSSI == b.RSSI {
				return 0
			}
			if a.RSSI > b.RSSI {
				return -1
			}
			return 1
		}
		if a.RSSI < b.RSSI && int(b.RSSI)-int(a.RSSI) > int(s.Difference) {
			return 1
		}
		return -1
	}
	if b.Rate == -1 {
		if a.RSSI > b.RSSI && int(a.RSSI)-int(b.RSSI) > int(s.Difference) {
			return -1
		}
		return 1
	}
	if a.Rate == b.Rate {
		return 0
	}
	if a.Rate > b.Rate {
		return -1
	}
	return 1
}

// Sorting sets exclusion flags through its comparator, including the
// single-neighbor case. Capacity/service/balance pseudo-association follows
// sorting, before consuming one of the four output slots; it is not an
// actual association and must not move the station's recorded location.
func (s V4Selection) Select(neighbors []Candidate, admissible func(Candidate) bool) []Candidate {
	selected := []Candidate{}
	for _, band := range []int{1, 0} {
		if len(selected) == MaxCandidates {
			break
		}
		rows := []Candidate{}
		for _, n := range neighbors {
			if n.Band == band {
				rows = append(rows, n)
			}
		}
		indices, excluded := make([]int, len(rows)), make([]bool, len(rows))
		for i := range indices {
			indices[i] = i
		}
		compare := func(a, b int) int {
			fa, fb := s.filtered(rows[a]), s.filtered(rows[b])
			excluded[a], excluded[b] = fa, fb
			if fa && fb {
				return 0
			}
			if fa {
				return 1
			}
			if fb {
				return -1
			}
			return s.compare(rows[a], rows[b])
		}
		if len(indices) == 1 {
			compare(0, 0)
		} else {
			firmwareQuickSort(indices, 0, len(indices)-1, compare)
		}
		for _, index := range indices {
			if len(selected) >= MaxCandidates || excluded[index] {
				break
			}
			if admissible(rows[index]) {
				selected = append(selected, rows[index])
			}
		}
	}
	return selected
}
