package capwap

import (
	"bytes"
	"testing"
)

func TestBatch19Roundtrips(t *testing.T) {
	// 0x56: count + 17B records (rbytes(6) r8 r8 r8 r32 r32)
	rec := make([]byte, 17)
	rec[0] = 0xaa
	fs := PrivFailStation{Count: 1, Records: [][]byte{rec}}
	wire := fs.AssembleValue()
	if len(wire) != 21 {
		t.Fatalf("fail station wire = %d bytes, want 21", len(wire))
	}
	if v, err := ParsePrivFailStation(wire); err != nil || v.Count != 1 {
		t.Fatalf("fail station: %v", err)
	}

	// 0x58: header 7B {radio, chload, nf, BE32 cnt} + per-sta 10B
	// {mac6, wlan, rssi, band, neigh_cnt} + 9B neighbors
	rt := PrivRoamingTrigger{RadioID: 1, ChannelLoad: 40, NoiseFloor: -95,
		Stations: []RoamingTriggerSta{{
			MAC: [6]byte{1, 2, 3, 4, 5, 6}, WLANID: 2, RSSI: -70, BandMode: 3,
			Neighbors: []RoamingTriggerNeighbor{{
				BSSID: [6]byte{8, 9, 10, 11, 12, 13}, RCPI: 220, RSNI: 60, Channel: 36,
			}},
		}}}
	wire = rt.AssembleValue()
	if len(wire) != 7+10+9 {
		t.Fatalf("roaming trigger wire = %d bytes, want 26", len(wire))
	}
	v, err := ParsePrivRoamingTrigger(wire)
	if err != nil || v.NoiseFloor != -95 || v.Stations[0].RSSI != -70 ||
		v.Stations[0].Neighbors[0].RCPI != 220 ||
		!bytes.Equal(v.Stations[0].Neighbors[0].BSSID[:], rt.Stations[0].Neighbors[0].BSSID[:]) {
		t.Fatalf("roaming trigger: %v %+v", err, v)
	}

	// 0x59: header 10B + union macs + per-sta {mac6, bitmap16, cnt} + 10B radios
	rcr := PrivRoamingCalcResult{CurrentAP: 1, RadioID: 1,
		APUnion: [][6]byte{{1, 2, 3, 4, 5, 6}},
		Stations: []RoamingCalcSta{{
			MAC: [6]byte{9, 9, 9, 9, 9, 9},
			Radios: []RoamingCalcRadioEntry{{
				APIndex: 0, RadioID: 1, WLANID: 2,
				BSSID: [6]byte{1, 2, 3, 4, 5, 6}, Channel: 36,
			}},
		}}}
	if len(rcr.AssembleValue()) != 10+6+23+10 {
		t.Fatalf("roaming calc wire = %d bytes", len(rcr.AssembleValue()))
	}
	if v, err := ParsePrivRoamingCalcResult(rcr.AssembleValue()); err != nil ||
		v.Stations[0].Radios[0].Channel != 36 || v.APUnion[0] != [6]byte{1, 2, 3, 4, 5, 6} {
		t.Fatalf("roaming calc: %v", err)
	}
	if v, err := ParsePrivApMloSwitch(PrivApMloSwitch(1).AssembleValue()); err != nil || v != 1 {
		t.Fatalf("mlo switch: %v", err)
	}
}
