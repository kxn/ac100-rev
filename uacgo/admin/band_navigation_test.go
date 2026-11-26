package admin

import (
	"bytes"
	"testing"
)

func TestBandNavigationIsSeparateFromRSSIOrientation(t *testing.T) {
	b := BandNavigation{Enabled: true, Threshold5G: 20, Difference: 4, MaxFailures: 10}
	if err := b.validate(); err != nil {
		t.Fatal(err)
	}
	e := b.element()
	if e.Value[7] != 0x3a || !bytes.Equal(e.Value[10:], []byte{1, 20, 4, 10}) {
		t.Fatalf("band navigation wire %x", e.Value)
	}
	b.Threshold5G = 1
	if b.validate() == nil {
		t.Fatal("invalid threshold")
	}
}
func TestBandNavigationReadbackRequiresActualModel(t *testing.T) {
	if _, err := bandModel([]byte(`{"error_code":0}`)); err == nil {
		t.Fatal("accepted missing model")
	}
	v, e := bandModel([]byte(`{"error_code":0,"apmng_band_navigation":{"settings":{"enable":"on","5g_threshold":"20"}}}`))
	if e != nil || v["enable"] != "on" {
		t.Fatal(v, e)
	}
}
