package capwap

import (
	"reflect"
	"testing"
)

// Batch-15: upgrade flow + feature/capability elements roundtrip.
func TestBatch15Roundtrips(t *testing.T) {
	// large firmware info (29B)
	lfi := PrivLargeFirmwareInfo{Type: 1, TotalSize: 1000, SubImages: 200, Flags: 300, MD5: [16]byte{1, 2, 3}}
	w := lfi.AssembleValue()
	if len(w) != 0x1d {
		t.Fatalf("large fw wire = %d", len(w))
	}
	if v, err := ParsePrivLargeFirmwareInfo(w); err != nil || v.TotalSize != 1000 {
		t.Fatalf("large fw parse: %v", err)
	}

	// sub firmware info (26B)
	sfi := PrivSubFirmwareInfo{Type: 1, SubType: 2, TotalSize: 500, Flags: 100, MD5: [16]byte{4, 5, 6}}
	w = sfi.AssembleValue()
	if len(w) != 0x1a {
		t.Fatalf("sub fw wire = %d", len(w))
	}
	if v, err := ParsePrivSubFirmwareInfo(w); err != nil || v.SubType != 2 || v.TotalSize != 500 {
		t.Fatalf("sub fw parse: %v", err)
	}

	// sub firmware action (6B)
	sfa := PrivSubFirmwareAction{Type: 1, SubType: 2, Action: 3}
	w = sfa.AssembleValue()
	if len(w) != 6 {
		t.Fatalf("sub action wire = %d", len(w))
	}
	if v, err := ParsePrivSubFirmwareAction(w); err != nil || v.Action != 3 {
		t.Fatalf("sub action parse: %v", err)
	}

	// web account (header + tail)
	wa := PrivApWebAccount{Algorithm: 1, Username: []byte("admin"), Password: []byte("pass")}
	w = wa.AssembleValue()
	if v, err := ParsePrivApWebAccount(w); err != nil || v.Algorithm != 1 {
		t.Fatalf("web account: %v", err)
	}

	// LAG config (3B)
	lag := PrivLAGConfig{A: 1, B: 0, C: 3, Ports: []byte("1,2")}
	if v, err := ParsePrivLAGConfig(lag.AssembleValue()); err != nil || !reflect.DeepEqual(*v, lag) {
		t.Fatalf("lag: %v", err)
	}

	// fit/fat button (BE32)
	if v, err := ParsePrivFitFatButtonStatus(AppendUint32BE(nil, 1)); err != nil || v != 1 {
		t.Fatalf("fit/fat: %v", err)
	}

	// 11ax defaults (9B)
	var ax Priv11axFeatureDefaults
	ax[0] = 1
	if v, err := ParsePriv11axFeatureDefaults(ax.AssembleValue()); err != nil || v[0] != 1 {
		t.Fatalf("11ax: %v", err)
	}
}
