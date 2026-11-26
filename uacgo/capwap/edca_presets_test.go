package capwap

import (
	"encoding/binary"
	"testing"
)

func TestEDCAPresetReportForOtherAPModel(t *testing.T) {
	b := []byte{0, 3, 1, 2, 6}
	b = append(b, []byte("Office")...)
	b = append(b, 0, 4)
	b = append(b, []byte("busy")...)
	b = append(b, 1, 2, 2)
	for side := 0; side < 2; side++ {
		b = append(b, 1, 2, 3, 7, 2, 3, 4, 4, 3, 4, 10, 10)
		for _, n := range []uint16{47, 94, 0, 0} {
			b = binary.BigEndian.AppendUint16(b, n)
		}
	}
	p, e := ParseEDCAPresets(b)
	if e != nil {
		t.Fatal(e)
	}
	if p.Version != 3 || p.Scenes[0].Name != "Office" || p.Scenes[0].Bands[0].Band != 2 || p.Scenes[0].Bands[0].Queues[1].TXOP != 94 {
		t.Fatalf("invalid presets %#v", p)
	}
	for i := 0; i < len(b); i++ {
		if _, e := ParseEDCAPresets(b[:i]); e == nil {
			t.Fatalf("accepted truncated preset at %d", i)
		}
	}
	b[len(b)-42] = 99
	if _, e := ParseEDCAPresets(b); e == nil {
		t.Fatal("accepted undeclared scene")
	}
}
