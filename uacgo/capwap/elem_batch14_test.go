package capwap

import (
	"testing"
)

// Batch-14: remaining private elements roundtrip + validation.
func TestBatch14Roundtrips(t *testing.T) {
	// spectral (4B u8×4)
	var sp PrivApSpectral
	sp[0], sp[3] = 1, 4
	w := sp.AssembleValue()
	if v, err := ParsePrivApSpectral(w); err != nil || v != sp {
		t.Fatalf("spectral: %v", err)
	}
	if _, err := ParsePrivApSpectral(make([]byte, 3)); err == nil {
		t.Fatal("spectral len 3 must fail")
	}

	// spec rssi (BE32)
	if v, err := ParsePrivSpecRSSI(AppendUint32BE(nil, 42)); err != nil || v != 42 {
		t.Fatalf("spec rssi: %v", err)
	}

	// mac filter: 2 MACs
	mf := PrivMacFilter{Count: 2, A: 1, B: 0,
		MACs: []byte{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}}
	w2 := mf.AssembleValue()
	if v, err := ParsePrivMacFilter(w2); err != nil || v.Count != 2 || len(v.MACs) != 12 {
		t.Fatalf("mac filter: %v", err)
	}

	// silence params (u8 + BE16)
	sp2 := PrivSilenceParams{A: 1, B: 300}
	if v, err := ParsePrivSilenceParams(sp2.AssembleValue()); err != nil || *v != sp2 {
		t.Fatalf("silence params: %v", err)
	}
	if _, err := ParsePrivSilenceParams(make([]byte, 2)); err == nil {
		t.Fatal("silence len 2 must fail")
	}
}
