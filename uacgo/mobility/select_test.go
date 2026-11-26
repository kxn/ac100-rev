package mobility

import "testing"

func TestSelectionUsesVendorRateGainLoadAndFourCandidateLimit(t *testing.T) {
	s := Selection{CurrentRSSI: -70, CurrentRate: 100, ThresholdType2G: 1, ThresholdType5G: 1}
	rows := []Candidate{{AP: "rate-low", Band: 1, RSSI: -50, Rate: 119}, {AP: "load-high", Band: 1, RSSI: -50, Rate: 500, Load: 86}, {AP: "accepted", Band: 1, RSSI: -86, Rate: 120, Load: 85}, {AP: "signal-low", Band: 1, RSSI: -88, Rate: 500}}
	got := s.Select(rows)
	if len(got) != 1 || got[0].AP != "accepted" {
		t.Fatal(got)
	}
	rows = nil
	for i := 0; i < 8; i++ {
		rows = append(rows, Candidate{Radio: uint8(i + 1), Band: 1, RSSI: -60, Rate: 300 - i})
	}
	got = s.Select(rows)
	if len(got) != 4 || got[0].Radio != 1 || got[3].Radio != 4 {
		t.Fatal(got)
	}
	s.CurrentRate = 10
	if len(s.Select([]Candidate{{RSSI: -60, Rate: 29}})) != 0 || len(s.Select([]Candidate{{RSSI: -60, Rate: 30}})) != 1 {
		t.Fatal("20Mbps absolute improvement boundary differs")
	}
}

func TestSelectionBandTieAndWeakFallbackKeepFirmwareQuirks(t *testing.T) {
	s := Selection{CurrentRSSI: -70, ThresholdType2G: 1, ThresholdType5G: 1}
	got := s.Select([]Candidate{{AP: "2g", Band: 0, RSSI: -40, Rate: 100}, {AP: "5g", Band: 1, RSSI: -80, Rate: 100}})
	if len(got) != 2 || got[0].AP != "5g" {
		t.Fatal("band tie differs", got)
	}
	// No own-RSSI delta or invented client-count tiebreaker is consumed.
	s.CurrentRSSI = -86
	got = s.Select([]Candidate{{AP: "strongest-rate", Band: 1, RSSI: -84, Rate: -1, Load: 100}, {AP: "last-band", Band: 0, RSSI: -85, Rate: -1}})
	if len(got) != 1 || got[0].AP != "strongest-rate" {
		t.Fatal("weak fallback must retain the vendor's first sorted candidate", got)
	}
	s.ThresholdType2G = 2
	if len(s.Select([]Candidate{{Band: 1, RSSI: -80, Rate: -1}, {Band: 0, RSSI: -81, Rate: -1}})) != 0 {
		t.Fatal("fallback uses last checked band's threshold type")
	}
}

func TestFirmwareSortPreservesComparatorWithoutInventedTieKey(t *testing.T) {
	rows := []Candidate{{AP: "z", Rate: 100, Band: 1, RSSI: -50}, {AP: "a", Rate: 100, Band: 1, RSSI: -50}, {AP: "higher", Rate: 101, Band: 0, RSSI: -80}}
	firmwareSort(rows, 0, len(rows)-1)
	if rows[0].AP != "higher" || rows[1].AP != "a" || rows[2].AP != "z" {
		t.Fatal("firmware partition order changed", rows)
	}
}
