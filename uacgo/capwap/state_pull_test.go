package capwap

import (
	"encoding/hex"
	"testing"
)

func TestV6StatePullFieldLayout(t *testing.T) {
	// count16, subtype2/length17, two {radio,WLAN,BSSID6} rows.
	b, _ := hex.DecodeString("0001000200110201010200000000110203020000000022")
	p, err := ParseStatePull(b)
	if err != nil || !p.HasBSSIDs || p.HasStations || len(p.BSSIDs) != 2 || p.BSSIDs[1].Radio != 2 || p.BSSIDs[1].WLAN != 3 || p.BSSIDs[1].BSSID[5] != 0x22 {
		t.Fatal(p, err)
	}
	for i := 0; i < len(b); i++ {
		if _, err := ParseStatePull(b[:i]); err == nil {
			t.Fatal("truncated pull accepted", i)
		}
	}
	b[5]--
	if _, err := ParseStatePull(b); err == nil {
		t.Fatal("bad declared length accepted")
	}
}
