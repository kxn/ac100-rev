package cweng

import (
	"testing"

	"uacgo/capwap"
	"uacgo/internal/testroot"
)

func TestDetectRCPIMethod(t *testing.T) {
	cases := []struct {
		name string
		rcpi []uint8
		rsni []uint8
		want int
	}{
		{"positive raw is protocol", []uint8{30}, nil, RCPIMethodProtocol},
		{"0xdc marker legacy", []uint8{0xdc}, nil, RCPIMethodLegacy},
		{"0xff legacy", []uint8{0xff}, nil, RCPIMethodLegacy},
		{"odd raw legacy", []uint8{141}, []uint8{80}, RCPIMethodLegacy},
		{"even raw high rsni protocol", []uint8{140}, []uint8{61}, RCPIMethodProtocol},
		{"even raw low rsni legacy", []uint8{140}, []uint8{60}, RCPIMethodLegacy},
		{"mixed inconsistent", []uint8{140, 141}, []uint8{61, 80}, RCPIMethodUnknown},
		{"empty unknown", nil, nil, RCPIMethodUnknown},
	}
	for _, c := range cases {
		if got := DetectRCPIMethod(c.rcpi, c.rsni); got != c.want {
			t.Fatalf("%s: got %d want %d", c.name, got, c.want)
		}
	}
}

func TestNormalizeRCPI(t *testing.T) {
	// protocol: raw/2 − 110 (e.g. raw 40 → −90)
	if got := NormalizeRCPI(40, RCPIMethodProtocol); got != -90 {
		t.Fatalf("protocol 40 = %d, want -90", got)
	}
	// legacy: raw is dBm
	if got := NormalizeRCPI(0xba, RCPIMethodLegacy); got != -70 {
		t.Fatalf("legacy 0xba = %d, want -70", got)
	}
	// smoothing: max(rcpi−10, −95)
	if got := RCPIToRSSI(-50); got != -60 {
		t.Fatalf("rssi(-50) = %d, want -60", got)
	}
	if got := RCPIToRSSI(-90); got != -95 {
		t.Fatalf("rssi(-90) = %d, want -95", got)
	}
}

func TestNbrFilterReject(t *testing.T) {
	cfg := DefaultSteerConfig()
	cfg.RoamingDif = 5
	// 2G floor −75: exactly −75 drops, −74 passes preference vs sta −80
	if !NbrFilterReject(cfg, -80, 0, 0, SteerCandidate{RSSI: -75, ChlLoad: 10}) {
		t.Fatal("floor must drop -75 on 2G")
	}
	if NbrFilterReject(cfg, -80, 0, 0, SteerCandidate{RSSI: -74, ChlLoad: 10}) {
		t.Fatal("-74 must pass on 2G vs sta -80")
	}
	// 5G floor −80
	if !NbrFilterReject(cfg, -85, 0, 1, SteerCandidate{RSSI: -80, ChlLoad: 10}) {
		t.Fatal("floor must drop -80 on 5G")
	}
	// channel load
	cfg.ChlLoadMax2G = 50
	if !NbrFilterReject(cfg, -80, 0, 0, SteerCandidate{RSSI: -60, ChlLoad: 51}) {
		t.Fatal("channel load must drop")
	}
	cfg.ChlLoadMax2G = 0
	// preference: candidate must reach the STA's current rssi
	if !NbrFilterReject(cfg, -60, 0, 1, SteerCandidate{RSSI: -61, ChlLoad: 10}) {
		t.Fatal("weaker than current must drop")
	}
	// 2G pays the 5g→2g bias + roaming dif under policy 1
	cfg.FiveGTo2GFix = 8
	if !NbrFilterReject(cfg, -60, 1, 0, SteerCandidate{RSSI: -55, ChlLoad: 10}) {
		t.Fatal("2G bias must drop a marginal candidate")
	}
	if NbrFilterReject(cfg, -60, 1, 0, SteerCandidate{RSSI: -40, ChlLoad: 10}) {
		t.Fatal("strong 2G candidate must pass the bias")
	}
}

func TestSortCandidates(t *testing.T) {
	cfg := DefaultSteerConfig()
	cfg.RoamingDif = 5
	// all estimated: rate descending
	est := []SteerCandidate{{RSSI: -50, EstRate: 30}, {RSSI: -60, EstRate: 72}}
	SortCandidates(cfg, est)
	if est[0].EstRate != 72 || est[1].EstRate != 30 {
		t.Fatalf("rate desc: %+v", est)
	}
	// all unestimated: rssi descending
	un := []SteerCandidate{{RSSI: -70, EstRate: -1}, {RSSI: -40, EstRate: -1}}
	SortCandidates(cfg, un)
	if un[0].RSSI != -40 || un[1].RSSI != -70 {
		t.Fatalf("rssi desc: %+v", un)
	}
	// mixed pair (vendor _rssi_sort_fun): the unestimated candidate leads
	// unless the estimated one's RSSI leads by more than roaming dif.
	mixed := []SteerCandidate{{RSSI: -50, EstRate: 30}, {RSSI: -45, EstRate: -1}}
	SortCandidates(cfg, mixed)
	if mixed[0].EstRate != -1 {
		t.Fatalf("unestimated should lead: %+v", mixed)
	}
	mixed = []SteerCandidate{{RSSI: -40, EstRate: 30}, {RSSI: -55, EstRate: -1}}
	SortCandidates(cfg, mixed)
	if mixed[0].EstRate != 30 {
		t.Fatalf("rated should lead on rssi margin: %+v", mixed)
	}
}

type admDeny5G struct{}

func (admDeny5G) PseudoAssociateOK(_ uint16, radio, _ uint8, _ [6]byte) bool {
	return radio != 2 // pretend radio 2 is full
}

func TestSelectNeighbors(t *testing.T) {
	cfg := DefaultSteerConfig()
	cfg.MaxNbr = 6
	var band5G, band2G []SteerCandidate
	for i := 0; i < 5; i++ {
		band5G = append(band5G, SteerCandidate{RSSI: int8(-50 - i), EstRate: 100 - i, RadioID: 1})
	}
	for i := 0; i < 5; i++ {
		band2G = append(band2G, SteerCandidate{RSSI: int8(-50 - i), EstRate: 50 - i, RadioID: 1})
	}
	keep5G, keep2G := SelectNeighbors(cfg, AdmitAll{}, [6]byte{}, band5G, band2G)
	if len(keep5G) != 5 || len(keep2G) != 1 {
		t.Fatalf("budget shared 5G first: %d %d", len(keep5G), len(keep2G))
	}
	// admission rejection frees budget for the next candidate
	band5G[0].RadioID = 2
	keep5G, keep2G = SelectNeighbors(cfg, admDeny5G{}, [6]byte{}, band5G, band2G)
	if len(keep5G) != 4 || len(keep2G) != 2 {
		t.Fatalf("admission skip: %d %d", len(keep5G), len(keep2G))
	}
}

// fakeSteerLookup feeds the decision with a two-AP topology:
// sta on ap1/radio1 (2G ch 6), candidates ap2 (5G ch 36) and ap3 (2G ch 11).
type fakeSteerLookup struct{}

func (fakeSteerLookup) StaForTrigger(mac [6]byte, reportAPID uint16, radioID, wlanID uint8) (StaContext, bool) {
	sta := StaContext{
		MAC: mac, APID: 1, RadioID: radioID, WLANID: wlanID,
		BSSID: [6]byte{0xaa, 0, 0, 0, 0, 1}, RSSI: -75, Policy: 0,
		Caps: SteerCaps{Mode: 1, NSS: 1, BW: 0, MCS: 7},
	}
	if mac != [6]byte{0x11, 0x22, 0x33, 0x44, 0x55, 0x66} || reportAPID != 1 {
		return StaContext{}, false
	}
	return sta, true
}

func (fakeSteerLookup) APByBSSID(bssid [6]byte) (uint16, [6]byte, uint8, uint8, uint8, uint8, int8, bool) {
	switch bssid {
	case [6]byte{0xaa, 0, 0, 0, 0, 1}: // serving BSS
		return 1, [6]byte{0xaa, 0, 0, 0, 0, 1}, 1, 1, 6, 20, -95, true
	case [6]byte{0xaa, 0, 0, 0, 0, 2}: // ap2 5G strong
		return 2, [6]byte{0xaa, 0, 0, 0, 0, 2}, 1, 1, 36, 10, -92, true
	case [6]byte{0xaa, 0, 0, 0, 0, 3}: // ap3 2G marginal
		return 3, [6]byte{0xaa, 0, 0, 0, 0, 3}, 1, 1, 11, 10, -95, true
	}
	return 0, [6]byte{}, 0, 0, 0, 0, 0, false
}

func (fakeSteerLookup) MeshRate2Cap(uint16) int { return 0 }

func (fakeSteerLookup) SteerCapsFor(StaContext, uint16, uint8, uint8, uint8) (SteerCaps, SteerCaps, bool) {
	c := SteerCaps{Mode: 1, NSS: 1, BW: 0, MCS: 7}
	return c, c, true
}

func TestDecideRoamingTrigger(t *testing.T) {
	tbl, err := LoadEstimateRateTables(testroot.Root() + "/uacgo/data/estimate-rate-tables.bin")
	if err != nil {
		t.Fatal(err)
	}
	cfg := DefaultSteerConfig()
	se := &SteerEngine{Tables: tbl, Cfg: cfg, Look: fakeSteerLookup{}}

	mac := [6]byte{0x11, 0x22, 0x33, 0x44, 0x55, 0x66}
	trig := &capwap.PrivRoamingTrigger{
		RadioID: 1, ChannelLoad: 30, NoiseFloor: -95,
		Stations: []capwap.RoamingTriggerSta{{
			MAC: mac, WLANID: 1, RSSI: -75, BandMode: 3,
			Neighbors: []capwap.RoamingTriggerNeighbor{
				// serving BSS → skipped by the build loop
				{BSSID: [6]byte{0xaa, 0, 0, 0, 0, 1}, RCPI: 0xbb, RSNI: 70, Channel: 6},
				// ap2 5G: rcpi −57 → rssi −67 (odd raw → legacy method)
				{BSSID: [6]byte{0xaa, 0, 0, 0, 0, 2}, RCPI: 0xc7, RSNI: 70, Channel: 36},
				// ap3 2G: rcpi −63 → rssi −73
				{BSSID: [6]byte{0xaa, 0, 0, 0, 0, 3}, RCPI: 0xc1, RSNI: 70, Channel: 11},
				// unknown BSS → skipped by the lookup
				{BSSID: [6]byte{0xff, 0, 0, 0, 0, 9}, RCPI: 0xbb, RSNI: 70, Channel: 44},
			},
		}},
	}

	res := se.Decide(1, trig)
	if res == nil || len(res.Stations) != 1 || len(res.APUnion) != 2 {
		t.Fatalf("result: %+v", res)
	}
	// 5G (ap2) must be listed first
	st := res.Stations[0]
	if st.Radios[0].Channel != 36 || st.Radios[1].Channel != 11 {
		t.Fatalf("targets: %+v", st.Radios)
	}
	// wire roundtrip
	v, err := capwap.ParsePrivRoamingCalcResult(res.AssembleValue())
	if err != nil || len(v.Stations) != 1 || v.APUnion[0] != [6]byte{0xaa, 0, 0, 0, 0, 2} {
		t.Fatalf("wire roundtrip: %v %+v", err, v)
	}

	// mismatched reporting AP → no stations
	if res := se.Decide(9, trig); len(res.Stations) != 0 {
		t.Fatalf("mismatch must skip: %+v", res)
	}
}

func TestSteerRegistryPopulation(t *testing.T) {
	r := NewSteerRegistry()
	// wsta 0x34 events populate STA rows; trigger refreshes RSSI
	mac := [6]byte{1, 2, 3, 4, 5, 6}
	FanClientSink{r}.StationEvent(ClientEvent{MAC: mac, RadioID: 2})
	if _, ok := r.StaForTrigger(mac, 0, 2, 0); !ok {
		t.Fatal("station event must populate the registry")
	}
	r.NoteTrigger(0, &capwap.PrivRoamingTrigger{
		Stations: []capwap.RoamingTriggerSta{{MAC: mac, RSSI: -60}},
	})
	sta, _ := r.StaForTrigger(mac, 0, 2, 0)
	if sta.RSSI != -60 {
		t.Fatalf("trigger must refresh rssi: %+v", sta)
	}
	// radio stats land too (NoteTrigger header)
	r.NoteTrigger(7, &capwap.PrivRoamingTrigger{ChannelLoad: 33, NoiseFloor: -90})
	if s := r.radio[7]; s.ChlLoad != 33 || s.NoiseFloor != -90 {
		t.Fatalf("radio stats: %+v", s)
	}
}
