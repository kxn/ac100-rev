package cweng

import (
	"encoding/json"
	"testing"
	"uacgo/capwap"
)

func TestRadioModeListUsesReportedIDsAndSeparateRFValues(t *testing.T) {
	// One mode: ID7; name, description, two physical radios, rf_mode0x4003.
	b := []byte{1, 7, 5, 2, 0, 4, 'D', 'u', 'a', 'l', 1, 0, 3, 'A', 'P', 'S', 3, 0, 1, 1, 3, 0, 1, 3, 4, 0, 2, 0x40, 3}
	modes, err := ParseRadioModes(b)
	if err != nil || len(modes) != 1 || modes[0].ID != 7 || modes[0].RFMode != 0x4003 || len(modes[0].Radios) != 2 || modes[0].Radios[1] != 3 || modes[0].Name != "Dual" {
		t.Fatal(modes, err)
	}
	for _, bad := range [][]byte{b[:len(b)-1], append(append([]byte{}, b...), 0), {2, 1, 0, 1, 0}} {
		if _, err := ParseRadioModes(bad); err == nil {
			t.Fatalf("bad mode list accepted %x", bad)
		}
	}
	req, _ := capwap.NewParsedPacket(3)
	req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0xbb, Value: b}, {Type: 0xbc, Value: []byte{1, 7, 0}}})}}
	ap, err := ParseAPEntry(req)
	if err != nil || len(ap.RadioModes) != 1 || ap.RadioMode == nil || ap.RadioMode.ID != 7 || !ap.RadioMode.Enabled {
		t.Fatal(ap, err)
	}
}

func TestReportedRadioIDsAreJSONArray(t *testing.T) {
	b, err := json.Marshal(RadioMode{ID: 7, Radios: []uint8{1, 3}})
	if err != nil {
		t.Fatal(err)
	}
	var v map[string]any
	_ = json.Unmarshal(b, &v)
	if _, ok := v["radios"].([]any); !ok {
		t.Fatal(string(b))
	}
}
