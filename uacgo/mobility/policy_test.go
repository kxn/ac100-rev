package mobility

import "testing"

func TestFirmwarePoliciesUseDifferentPHYDefaultsAndSignalBases(t *testing.T) {
	if V4Policy.DefaultStationPHY(0) != (PHY{0, 1, 1, 7}) || V4Policy.DefaultStationPHY(1) != (PHY{2, 2, 2, 9}) || V6Policy.DefaultStationPHY(0) != (PHY{1, 1, 4, 7}) || V6Policy.DefaultStationPHY(1) != (PHY{3, 2, 4, 9}) {
		t.Fatal("default tuples were mixed")
	}
	p := PHY{0, 1, 1, 7}
	// 2G HT: SNR20 ->43+floor(14/3)*2=51; SNR10 ->21.
	if a, b := V4Policy.CandidateRate(-75, p, p, 0, false, 0), V6Policy.CandidateRate(-75, p, p, 0, false, 0); a != 51 || b != 21 {
		t.Fatal("active candidate signal bases are -95 and -85", a, b)
	}
	if V4Policy.CandidateRate(-95, p, p, 0, false, 0) != 0 || V4Policy.CandidateRate(-90, p, p, 0, false, 0) == 0 || V6Policy.CandidateRate(-90, p, p, 0, false, 0) != 0 {
		t.Fatal("low-signal boundary changed")
	}
	if V4Policy.RadioMode(-1, true, true, true) != 3 || V6Policy.RadioMode(-1, true, true, true) != 4 || V4Policy.RadioMode(13, true, true, true) != 1 || V6Policy.RadioMode(13, true, true, true) != 4 {
		t.Fatal("V4 does not recognize BE configuration modes")
	}
	var c StationCapabilities
	if c.PHYFor(V4Policy, 1) != V4Policy.DefaultStationPHY(1) {
		t.Fatal("statistics fallback ignored policy")
	}
	c.Observe(1, 0x942, 3)
	if c.PHYFor(V4Policy, 1) != c.PHYFor(V6Policy, 1) {
		t.Fatal("valid observed tuple should be shared")
	}
}

func v4Selection() V4Selection {
	return V4Selection{CurrentRSSI: -70, CurrentBand: 1, ActualMode: 2, ThresholdType2G: 1, ThresholdType5G: 1, RSSI2G: -75, RSSI5G: -80, Difference: 8}
}

func TestV4SelectionStrictThresholdsDirectionalDeltaAndMode(t *testing.T) {
	for _, tc := range []struct {
		name                 string
		mode, source, target int
		current, neighbor    int8
		load                 uint8
		want                 bool
	}{
		{"same-band-equal-delta", 2, 1, 1, -70, -62, 0, true},
		{"same-band-below-delta", 2, 1, 1, -70, -63, 0, false},
		{"five-to-two-extra-five", 2, 1, 0, -70, -57, 0, true},
		{"five-to-two-below-extra", 2, 1, 0, -70, -58, 0, false},
		{"two-to-five-equal", 2, 0, 1, -60, -60, 0, true},
		{"two-to-five-weaker", 2, 0, 1, -60, -61, 0, false},
		{"strict-rssi-equality", 2, 0, 1, -90, -80, 0, false},
		{"load-equality", 2, 0, 1, -90, -60, 85, true},
		{"load-over", 2, 0, 1, -90, -60, 86, false},
		{"high-mode-skips-absolute-gates", 1, 0, 1, -95, -90, 99, true},
	} {
		t.Run(tc.name, func(t *testing.T) {
			s := v4Selection()
			s.ActualMode, s.CurrentBand, s.CurrentRSSI = tc.mode, tc.source, tc.current
			n := Candidate{Band: tc.target, RSSI: tc.neighbor, Load: tc.load}
			got := s.Select([]Candidate{n}, func(Candidate) bool { return true })
			if (len(got) == 1) != tc.want {
				t.Fatal(got)
			}
		})
	}
}

func TestV4SelectionBandPriorityUnknownRatesAndPseudoAssociation(t *testing.T) {
	s := v4Selection()
	s.CurrentRSSI = -90
	rows := []Candidate{{AP: "fast-two", Band: 0, RSSI: -40, Rate: 1200}, {AP: "zero-five", Band: 1, RSSI: -50, Rate: 0}}
	got := s.Select(rows, func(Candidate) bool { return true })
	if len(got) != 2 || got[0].AP != "zero-five" {
		t.Fatal("V4 must not apply V6's global rate-gain selector", got)
	}
	rows = []Candidate{{AP: "known", Band: 1, RSSI: -49, Rate: 100}, {AP: "unknown", Band: 1, RSSI: -50, Rate: -1}}
	got = s.Select(rows, func(Candidate) bool { return true })
	if len(got) != 2 || got[0].AP != "unknown" {
		t.Fatal("unknown comparator branch changed", got)
	}
	rows[0].RSSI = -40
	got = s.Select(rows, func(n Candidate) bool { return n.AP != "known" })
	if len(got) != 1 || got[0].AP != "unknown" {
		t.Fatal("rejected pseudo-association consumed the next slot", got)
	}
	rows = nil
	for i := 0; i < 6; i++ {
		rows = append(rows, Candidate{Band: 1, RSSI: -40, Rate: 100 + i})
	}
	if got := s.Select(rows, func(Candidate) bool { return true }); len(got) != 4 || got[0].Rate != 105 {
		t.Fatal("compiled four-candidate limit/order changed", got)
	}
}
