package cweng

import (
	"testing"
)

func TestARPScanReportsUsePackedIPv4MACRows(t *testing.T) {
	b := []byte{1, 0, 2, 192, 0, 2, 10, 2, 3, 4, 5, 6, 7, 192, 0, 2, 11, 2, 3, 4, 5, 6, 8}
	r, err := parseARPScan(b)
	if err != nil || len(r.Entries) != 2 || r.Entries[1].IP != "192.0.2.11" || r.Entries[0].MAC != "02:03:04:05:06:07" {
		t.Fatal(r, err)
	}
	for _, bad := range [][]byte{nil, b[:2], b[:len(b)-1], append(append([]byte{}, b...), 0), {1, 0x10, 1}} {
		if _, err := parseARPScan(bad); err == nil {
			t.Fatal("malformed scan accepted", bad)
		}
	}
}
