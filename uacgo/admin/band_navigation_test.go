package admin

import (
	"bytes"
	"context"
	"encoding/json"
	"strings"
	"testing"
)

func TestBandNavigationSparseReadbackDoesNotInventMismatch(t *testing.T) {
	for _, tc := range []struct{ name, values, state string }{
		{"sparse", `{"enable":"on"}`, "acknowledged"},
		{"mismatch", `{"enable":"off"}`, "failed"},
		{"complete", `{"enable":"on","5g_threshold":"20","dif_threshold":"4","max_fail_num":"10"}`, "verified"},
	} {
		t.Run(tc.name, func(t *testing.T) {
			m, _, ap := nativeModelAP(t, func(b json.RawMessage) json.RawMessage {
				if strings.Contains(string(b), `"set"`) {
					return json.RawMessage(`{"error_code":0}`)
				}
				return json.RawMessage(`{"error_code":0,"apmng_band_navigation":{"settings":` + tc.values + `}}`)
			})
			m.applyBandNavigation(context.Background(), ap, &BandNavigation{Enabled: true, Threshold5G: 20, Difference: 4, MaxFailures: 10})
			got := m.status[ap.ID+"/band-navigation"]
			if got.State != tc.state {
				t.Fatal(got)
			}
			if tc.name == "sparse" && !strings.Contains(got.Reason, "dif_threshold") {
				t.Fatal("missing coverage not explained", got)
			}
		})
	}
}

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
