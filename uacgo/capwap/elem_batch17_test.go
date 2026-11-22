package capwap

import (
	"testing"
)

func TestBatch17Roundtrips(t *testing.T) {
	if v, err := ParsePrivImageUpdateResult(AppendUint32BE(nil, 42)); err != nil || v != 42 {
		t.Fatalf("image update result: %v", err)
	}
	if v, err := ParsePrivDataTunnelMode(AppendUint32BE(nil, 2)); err != nil || v != 2 {
		t.Fatalf("data tunnel mode: %v", err)
	}
	ar := PrivAp11acRate{1, 2, 3, 4}
	if v, err := ParsePrivAp11acRate(ar.AssembleValue()); err != nil || v != ar {
		t.Fatalf("11ac rate: %v", err)
	}
	bc := PrivBcastStormCtrl{A: 1, Limit: 500}
	if v, err := ParsePrivBcastStormCtrl(bc.AssembleValue()); err != nil || v.Limit != 500 {
		t.Fatalf("bcast storm: %v", err)
	}
	wo := PrivWlanRSSIOrient{W: 100, U16: 50, A: 1, B: 2}
	if v, err := ParsePrivWlanRSSIOrient(wo.AssembleValue()); err != nil || v.W != 100 || v.A != 1 {
		t.Fatalf("rssi orient: %v", err)
	}
}
