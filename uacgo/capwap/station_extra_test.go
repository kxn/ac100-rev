package capwap

import (
	"encoding/hex"
	"testing"
)

func TestV6StationExtraIndependentWire(t *testing.T) {
	// One station, three typed fields: normal location, capacity, uptime.
	b, _ := hex.DecodeString("00010203040506070003000900030102b00007000412345678000a00040000003c")
	rows, err := ParseStationExtra(b)
	if err != nil || len(rows) != 1 || len(rows[0].Fields) != 3 || rows[0].Fields[0].Value[2] != 176 || Uint32BE(rows[0].Fields[1].Value) != 0x12345678 {
		t.Fatal(rows, err)
	}
	for i := 0; i < len(b); i++ {
		if _, err := ParseStationExtra(b[:i]); err == nil {
			t.Fatalf("accepted truncated extra %d", i)
		}
	}
	b[12] = 0xff
	if _, err := ParseStationExtra(b); err == nil {
		t.Fatal("accepted impossible field length")
	}
}
