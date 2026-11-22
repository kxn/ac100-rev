package capwap

import (
	"bytes"
	"testing"
)

func TestBatch19Roundtrips(t *testing.T) {
	// 0x56: count + 17B records (rbytes(6) r8 r8 r8 r32 r32)
	rec := make([]byte, 17)
	rec[0] = 0xaa
	fs := PrivFailStation{Count: 1, Records: [][]byte{rec}}
	wire := fs.AssembleValue()
	if len(wire) != 21 {
		t.Fatalf("fail station wire = %d bytes, want 21", len(wire))
	}
	if v, err := ParsePrivFailStation(wire); err != nil || v.Count != 1 {
		t.Fatalf("fail station: %v", err)
	}

	// 0x58: 26 bytes {u8×3, u32, mac1, u8×4, mac2, u8×3}
	rt := PrivRoamingTrigger{A: 1, B: 2, C: 3, W: 42,
		MAC1: [6]byte{1, 2, 3, 4, 5, 6}, U8a: 7,
		MAC2: [6]byte{8, 9, 10, 11, 12, 13}, Tail: [3]uint8{14, 15, 16}}
	wire = rt.AssembleValue()
	if len(wire) != 26 {
		t.Fatalf("roaming trigger wire = %d bytes, want 26", len(wire))
	}
	v, err := ParsePrivRoamingTrigger(wire)
	if err != nil || v.W != 42 || v.U8a != 7 || v.Tail[0] != 14 ||
		!bytes.Equal(v.MAC2[:], rt.MAC2[:]) {
		t.Fatalf("roaming trigger: %v %+v", err, v)
	}

	rcr := PrivRoamingCalcResult{A: 1, B: 2, Data: []byte{9, 8, 7}}
	if v, err := ParsePrivRoamingCalcResult(rcr.AssembleValue()); err != nil || v.B != 2 {
		t.Fatalf("roaming calc: %v", err)
	}
	if v, err := ParsePrivApMloSwitch(PrivApMloSwitch(1).AssembleValue()); err != nil || v != 1 {
		t.Fatalf("mlo switch: %v", err)
	}
}
