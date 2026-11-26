package capwap

import (
	"bytes"
	"encoding/hex"
	"testing"
)

func TestStationListVendorLayout(t *testing.T) {
	// Independent literal from cw_sta_info_list_parse/assemble @581148/580f6c:
	// radio=2, WLAN=7, count=1, A=9, B=10, station MAC.
	b, _ := hex.DecodeString("020000000700000001000000090000000a020304050607")
	l, err := ParseStaInfoList(b)
	if err != nil || l.WLANID != 7 || len(l.Entries) != 1 || l.Entries[0].A != 9 || l.Entries[0].MAC != [6]byte{2, 3, 4, 5, 6, 7} {
		t.Fatalf("decoded %+v: %v", l, err)
	}
	if !bytes.Equal(l.AssembleValue(), b) {
		t.Fatal("wire mismatch")
	}
	for i := 0; i < len(b); i++ {
		if _, err := ParseStaInfoList(b[:i]); err == nil {
			t.Fatalf("accepted truncation %d", i)
		}
	}
	if _, err := ParseStaInfoList(append(b, 0)); err == nil {
		t.Fatal("accepted trailing data")
	}
	b[4] = 17
	if _, err := ParseStaInfoList(b); err == nil {
		t.Fatal("accepted invalid WLAN")
	}
}

func TestStationStatisticsCountMustMatch(t *testing.T) {
	for _, b := range [][]byte{{0, 0, 0, 1}, {0, 0, 0, 0, 0}, make([]byte, 42)} {
		if _, err := ParsePrivStaStatisticsReq(b); err == nil {
			t.Fatal("accepted mismatched count")
		}
	}
}
