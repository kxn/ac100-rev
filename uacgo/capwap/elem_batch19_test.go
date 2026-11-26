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

	// Independently constructed V6 variable-count message, two station rows.
	wire = []byte{2, 30, 160, 0, 0, 0, 2, 2, 1, 2, 3, 4, 5, 1, 2, 0, 1, 2, 9, 8, 7, 6, 5, 180, 36, 1, 2, 1, 2, 3, 4, 6, 2, 1, 0, 0}
	v, err := ParsePrivRoamingTrigger(wire)
	if err != nil || len(v.Stations) != 2 || len(v.Stations[0].Neighbors) != 1 || v.Stations[1].WLAN != 2 {
		t.Fatal(v, err)
	}
	if !bytes.Equal(v.AssembleValue(), wire) {
		t.Fatal("trigger changed independent wire")
	}
	for _, bad := range [][]byte{wire[:len(wire)-1], append(append([]byte{}, wire...), 0), {2, 0, 0, 0, 0, 0, 201}} {
		if _, err := ParsePrivRoamingTrigger(bad); err == nil {
			t.Fatal("malformed trigger accepted")
		}
	}
	rcr := PrivRoamingCalcResult{Radio: 2, APs: [][6]byte{{2, 0, 0, 0, 0, 1}}, Stations: []RoamResultStation{{MAC: [6]byte{2, 1, 2, 3, 4, 5}, Candidates: []RoamCandidate{{Radio: 2, WLAN: 1, BSSID: [6]byte{2, 0, 0, 0, 0, 2}, Channel: 40}}}}}
	if v, err := ParsePrivRoamingCalcResult(rcr.AssembleValue()); err != nil || v.Stations[0].Candidates[0].Channel != 40 {
		t.Fatal(v, err)
	}
	if v, err := ParsePrivApMloSwitch(PrivApMloSwitch(1).AssembleValue()); err != nil || v != 1 {
		t.Fatalf("mlo switch: %v", err)
	}
}
