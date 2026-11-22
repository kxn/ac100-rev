package capwap

import (
	"bytes"
	"testing"
)

// Batch-10: duplicate ipv6 (typed), statistics-request group (typed head +
// verbatim payload per vendor assemble loops).
func TestBatch10Roundtrips(t *testing.T) {
	// 0x16: status(4)+type(1)+len(1)+16B addr = 22 (inside 18..26)
	e := AppendDuplicateIPv6Address(nil, 2, 6, make([]byte, 16))
	if v, err := ParseDuplicateIPv6Address(e[4:]); err != nil ||
		v.Status != 2 || len(v.Addr) != 16 {
		t.Fatalf("dup ipv6: %v", err)
	}
	short := AppendDuplicateIPv6Address(nil, 2, 6, make([]byte, 4)) // 10B < min 18
	if _, err := ParseDuplicateIPv6Address(short[4:]); err == nil {
		t.Fatal("below min length must fail")
	}

	// 0x52: typed 34-byte records (mac + u8×6 + BE16 + BE32 + BE16 + u8×2 + BE32×3)
	rec := StaStatisticsRecord{}
	for i := range rec.MAC {
		rec.MAC[i] = byte(i + 0x10)
	}
	for i := range rec.U8 {
		rec.U8[i] = byte(i)
	}
	rec.U16a, rec.U32a, rec.U16b = 42, 7, 8
	sta := PrivStaStatisticsReq{Count: 1, Records: []StaStatisticsRecord{rec}}
	if v, err := ParsePrivStaStatisticsReq(sta.AssembleValue()); err != nil ||
		v.Count != 1 || v.Records[0].U16a != 42 || !bytes.Equal(v.Records[0].MAC[:], rec.MAC[:]) {
		t.Fatalf("sta stats: %v", err)
	}
	bad := PrivStaStatisticsReq{Count: 1}
	bad.Records = []StaStatisticsRecord{{}}
	wire := bad.AssembleValue()
	if _, err := ParsePrivStaStatisticsReq(wire[:len(wire)-1]); err == nil {
		t.Fatal("misaligned sta body must fail")
	}

	// 0x53/0x54 typed record tests moved to elem_batch10b_test.go
}
