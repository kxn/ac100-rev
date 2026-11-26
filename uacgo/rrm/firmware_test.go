package rrm

import "testing"

func TestActiveSCAKeepsDirectedGraphAndOriginalTieOrder(t *testing.T) {
	cfg := DefaultConfig()
	radios := []Radio{{AP: "a", Channel: 11, Channels: []uint8{1, 6, 11}}, {AP: "b", Channel: 11, Channels: []uint8{1, 6, 11}}}
	got, err := Channels(radios, cfg)
	if err != nil || got[0] != 1 || got[1] != 1 {
		t.Fatal("no firmware preference for retaining old channel", got, err)
	}
	radios[0].Neighbors = []Neighbor{{1, -45}}
	got, err = Channels(radios, cfg)
	if err != nil || got[0] != 1 || got[1] != 6 {
		t.Fatal("first equal-cost local combination", got, err)
	}
	// score-mode1 is equality-only, including2.4GHz. A spectrum-overlap cost
	// or a penalty for switching old channel would choose another result.
	radios[0].Channels = []uint8{1, 11}
	radios[1].Channels = []uint8{2, 6}
	got, err = Channels(radios, cfg)
	if err != nil || got[0] != 1 || got[1] != 2 {
		t.Fatal(got, err)
	}
	if cochannel(1, 1, -85) != 2 || cochannel(1, 1, -86) != 0 || cochannel(1, 2, -40) != 0 {
		t.Fatal("so+4650 threshold/equality")
	}
}
func TestNeighborSmoothingAndIncomingOtherAPTopology(t *testing.T) {
	radios := []Radio{{AP: "a", Neighbors: []Neighbor{{1, -50}, {1, -70}, {2, -55}}}, {AP: "b"}, {AP: "a"}}
	n, err := normalize(radios)
	if err != nil || len(n[0]) != 2 || n[0][0].RSSI != -54 {
		t.Fatal(n, err)
	}
	for i := range radios {
		radios[i].MinPower = 3
		radios[i].MaxPower = 24
		radios[i].PowerLevel = 5
	}
	out, err := Powers(radios, DefaultConfig())
	if err != nil {
		t.Fatal(err)
	}
	// The incoming strong report is below the target neighbor count; it must
	// not trigger the prototype's "reduce to strongest neighbor" formula.
	if out[1] != 5 {
		t.Fatal("one strong incoming neighbor wrongly reduced power", out)
	}
}
func TestTPCThirdNeighborAndTenLevelQuantization(t *testing.T) {
	cfg := DefaultConfig()
	cfg.MinPower = 3
	cfg.MaxPower = 24
	radios := []Radio{{AP: "target", MinPower: 3, MaxPower: 24, PowerLevel: 10}}
	for _, rssi := range []int8{-35, -40, -45} {
		radios = append(radios, Radio{AP: "other", MinPower: 3, MaxPower: 24, PowerLevel: 10, Neighbors: []Neighbor{{0, rssi}}})
	}
	out, err := Powers(radios, cfg)
	if err != nil || out[0] != 1 {
		t.Fatal("third strongest incoming RSSI should reduce/quantize to level1", out, err)
	}
	for level := uint8(1); level <= 10; level++ {
		dbm := PowerForLevel(level, 24, 3)
		if dbm < 3 || dbm > 24 || LevelForPower(dbm, 24, 3) != level {
			t.Fatal(level, dbm)
		}
	}
	// Too few neighbors with the strongest weaker than threshold increases.
	radios = radios[:2]
	radios[0].PowerLevel = 5
	radios[1].Neighbors[0].RSSI = -80
	out, err = Powers(radios, cfg)
	if err != nil || out[0] != 10 {
		t.Fatal("weak incoming neighbor increase", out, err)
	}
}
