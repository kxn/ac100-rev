package mobility

import "testing"

func TestRateUsesFirmwareTableAndTruncatedSlope(t *testing.T) {
	p := PHY{0, 1, 2, 9}
	// 5g VHT at SNR27: slope(65-57)/(28-26)=4 =>61Mbps.
	if got := EstimateRate(27, p, 1); got != 61 {
		t.Fatal(got)
	}
	// HE at SNR18: slope(25-17)/(19-17)=4 =>21Mbps.
	p.Mode = 3
	if got := EstimateRate(18, p, 1); got != 21 {
		t.Fatal(got)
	}
	p = PHY{2, 2, 2, 9}
	if got := EstimateRate(27, p, 1); got != 61*2*234/52 {
		t.Fatal(got)
	}
	if CandidateRate(-85, p, p, 1, false, 0) != 0 {
		t.Fatal("below firmware minimum signal")
	}

}

func TestCapabilitiesAndMeshRateFollowVendorOperations(t *testing.T) {
	p := StationPHY(2|4<<4|11<<8, 3, 1)
	if p != (PHY{2, 2, 4, 11}) {
		t.Fatal(p)
	}
	if StationPHY(0, 0, 1) != DefaultStationPHY(1) {
		t.Fatal("invalid station tuple must use firmware defaults")
	}
	q := CandidatePHY(p, PHY{1, 1, 1, 0})
	if q != (PHY{1, 1, 1, 11}) {
		t.Fatal(q)
	}
	rate := CandidateRate(-50, p, p, 1, false, 0)
	if got := CandidateRate(-50, p, p, 1, true, 100); got != rate*100/(rate+100) {
		t.Fatal(got, rate)
	}
}
