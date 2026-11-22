package cweng

import (
	"testing"

	"uacgo/internal/testroot"
)

// TestRateTablesLoad verifies the extracted vendor tables
// (data/estimate-rate-tables.bin, uac_symbol_obj estimate_snr_rate_table_2g
// @0x731668 / _5g @0x731550 / nsdTable @0x731500).
func TestRateTablesLoad(t *testing.T) {
	tbl, err := LoadEstimateRateTables(testroot.Root() + "/uacgo/data/estimate-rate-tables.bin")
	if err != nil {
		t.Fatal(err)
	}
	// 2g legacy mode 0 breakpoints (7,3)…(25,33)
	if tbl.Band2G[0][0] != (RatePoint{SNR: 7, Rate: 3}) || tbl.Band2G[0][7] != (RatePoint{SNR: 25, Rate: 33}) {
		t.Fatalf("2g mode0 head/tail: %+v %+v", tbl.Band2G[0][0], tbl.Band2G[0][7])
	}
	// 2g HT20 mode 1 = MCS0..7 rates 7/14/21/28/43/57/65/72
	want := []uint16{7, 14, 21, 28, 43, 57, 65, 72}
	for i, w := range want {
		if tbl.Band2G[1][i].Rate != w {
			t.Fatalf("2g mode1[%d] = %d, want %d", i, tbl.Band2G[1][i].Rate, w)
		}
	}
	// nsd: legacy row all ones, HT {52,108,108,108}, VHT {52,108,234,468}
	if tbl.NSD[0] != [4]uint32{1, 1, 1, 1} || tbl.NSD[1] != [4]uint32{52, 108, 108, 108} ||
		tbl.NSD[2] != [4]uint32{52, 108, 234, 468} {
		t.Fatalf("nsd rows: %v %v %v", tbl.NSD[0], tbl.NSD[1], tbl.NSD[2])
	}
	// reject short images
	if _, err := ParseEstimateRateTables(make([]byte, 3)); err == nil {
		t.Fatal("short table image must fail")
	}
}

func TestEstimateRateFromSNR(t *testing.T) {
	tbl, err := LoadEstimateRateTables(testroot.Root() + "/uacgo/data/estimate-rate-tables.bin")
	if err != nil {
		t.Fatal(err)
	}
	legacy := SteerCaps{Mode: 0, NSS: 1, BW: 0}
	ht := SteerCaps{Mode: 1, NSS: 1, BW: 0}
	// exact breakpoints
	if got := tbl.EstimateRateFromSNR(7, legacy, 0); got != 3 {
		t.Fatalf("snr7 legacy = %d, want 3", got)
	}
	if got := tbl.EstimateRateFromSNR(25, legacy, 0); got != 33 {
		t.Fatalf("snr25 legacy = %d, want 33", got)
	}
	// past the last breakpoint clamps to the last rate
	if got := tbl.EstimateRateFromSNR(99, legacy, 0); got != 33 {
		t.Fatalf("snr99 legacy = %d, want 33", got)
	}
	// interpolation between (7,3) and (10,6): slope 1 → snr 8 → 4
	if got := tbl.EstimateRateFromSNR(8, legacy, 0); got != 4 {
		t.Fatalf("snr8 legacy = %d, want 4", got)
	}
	// below the first breakpoint: 3*4/7 = 1
	if got := tbl.EstimateRateFromSNR(4, legacy, 0); got != 1 {
		t.Fatalf("snr4 legacy = %d, want 1", got)
	}
	// snr 0 → 0
	if got := tbl.EstimateRateFromSNR(0, legacy, 0); got != 0 {
		t.Fatalf("snr0 = %d, want 0", got)
	}
	// nss scaling: HT20 snr 15 → 28 + 5*(15-13) = 38, ×2 streams = 76
	if got := tbl.EstimateRateFromSNR(15, SteerCaps{Mode: 1, NSS: 2, BW: 0}, 0); got != 76 {
		t.Fatalf("ht nss2 = %d, want 76", got)
	}
	// bw scaling: HT with bw=1 (40MHz): nsd 108/52 → 38*108/52 = 78
	if got := tbl.EstimateRateFromSNR(15, SteerCaps{Mode: 1, NSS: 1, BW: 1}, 0); got != 78 {
		t.Fatalf("ht bw40 = %d, want 78", got)
	}
	// legacy clamps nss/bw regardless of input: snr 15 → interp (14,13)/(18,19) = 14
	if got := tbl.EstimateRateFromSNR(15, SteerCaps{Mode: 0, NSS: 4, BW: 3}, 0); got != 14 {
		t.Fatalf("legacy clamp = %d, want 14", got)
	}
	// 5g HT first point is (15,7); below it the vendor scales proportionally
	if got := tbl.EstimateRateFromSNR(7, ht, 1); got != 3 {
		t.Fatalf("5g snr7 ht below table = %d, want 3", got)
	}
	// unknown band → 0
	if got := tbl.EstimateRateFromSNR(20, ht, 2); got != 0 {
		t.Fatalf("bad band = %d, want 0", got)
	}
}

func TestEstimateCandidateRate(t *testing.T) {
	tbl, err := LoadEstimateRateTables(testroot.Root() + "/uacgo/data/estimate-rate-tables.bin")
	if err != nil {
		t.Fatal(err)
	}
	caps := SteerCaps{Mode: 1, NSS: 1, BW: 0, MCS: 7}
	// AC300 semantics (default): nf fallback −85, gate rcpi < −84.
	// rcpi −50 → snr 35 → HT20 cap 72
	if got := tbl.EstimateCandidateRate(caps, caps, -50, 0, 0, 0); got != 72 {
		t.Fatalf("rate = %d, want 72", got)
	}
	// gate: rcpi −85 is below AC300's estimable floor
	if got := tbl.EstimateCandidateRate(caps, caps, -85, 0, 0, 0); got != 0 {
		t.Fatalf("gate = %d, want 0", got)
	}
	// mesh harmonic cap: 72 and 72 → 36
	if got := tbl.EstimateCandidateRate(caps, caps, -50, 0, 0, 72); got != 36 {
		t.Fatalf("mesh = %d, want 36", got)
	}
	// caps intersection: STA 1ss, WLAN 2ss → 1ss; STA HT, WLAN legacy → legacy
	if got := tbl.EstimateCandidateRate(caps, SteerCaps{Mode: 0, NSS: 2, BW: 1}, -50, 0, 0, 0); got != 33 {
		t.Fatalf("min caps = %d, want 33", got)
	}
}

// TestRateModelSemantics pins the AC100 vs AC300 estimation differences
// (SNR base and gate) and the capability range model.
func TestRateModelSemantics(t *testing.T) {
	tbl, err := LoadEstimateRateTables(testroot.Root() + "/uacgo/data/estimate-rate-tables.bin")
	if err != nil {
		t.Fatal(err)
	}
	caps := SteerCaps{Mode: 1, NSS: 1, BW: 0, MCS: 7}
	// same rcpi, different SNR base: AC300 snr=25 → 67; AC100 snr=35 → 72
	if got := tbl.EstimateCandidateRateModel(AC300RateModel, caps, caps, -60, 0, 0, 0); got != 67 {
		t.Fatalf("AC300 rcpi-60 = %d, want 67", got)
	}
	if got := tbl.EstimateCandidateRateModel(AC100RateModel, caps, caps, -60, 0, 0, 0); got != 72 {
		t.Fatalf("AC100 rcpi-60 = %d, want 72", got)
	}
	// gate: −85 is estimable on AC100 (snr 10 → 21) but not on AC300
	if got := tbl.EstimateCandidateRateModel(AC100RateModel, caps, caps, -85, 0, 0, 0); got != 21 {
		t.Fatalf("AC100 rcpi-85 = %d, want 21", got)
	}
	if got := tbl.EstimateCandidateRateModel(AC300RateModel, caps, caps, -85, 0, 0, 0); got != 0 {
		t.Fatalf("AC300 rcpi-85 = %d, want 0", got)
	}
	// capability ranges: 80MHz bw is within AC300 but out of AC100's
	// 20/40 range → AC100 falls back to the per-band defaults
	wide := SteerCaps{Mode: 2, NSS: 2, BW: 2, MCS: 9}
	if got := AC300RateModel.NormalizeCaps(wide, 1); got != wide {
		t.Fatalf("AC300 normalize = %+v", got)
	}
	if got := AC100RateModel.NormalizeCaps(wide, 1); got != (SteerCaps{BW: 2, NSS: 2, Mode: 2, MCS: 9}) {
		t.Fatalf("AC100 normalize 5G = %+v", got)
	}
	// invalid caps fall back to the per-band defaults on both models
	bad := SteerCaps{Mode: 9, NSS: 0, BW: 0, MCS: 30}
	if got := AC300RateModel.NormalizeCaps(bad, 1); got != (SteerCaps{BW: 2, NSS: 2, Mode: 2, MCS: 9}) {
		t.Fatalf("default 5G = %+v", got)
	}
	if got := AC300RateModel.NormalizeCaps(bad, 0); got != (SteerCaps{BW: 0, NSS: 1, Mode: 1, MCS: 7}) {
		t.Fatalf("default 2G = %+v", got)
	}
}
