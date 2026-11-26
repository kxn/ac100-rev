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

	// V6 0x52: exactly38 wire bytes, including all four32-bit counters.
	rec := StaStatisticsRecord{}
	for i := range rec.MAC {
		rec.MAC[i] = byte(i + 0x10)
	}
	rec.Radio, rec.WLAN, rec.RSSI, rec.Bandwidth = 1, 2, -60, 3
	rec.NegotiatedMbps, rec.SupportWord, rec.Capabilities = 42, 7, 8
	sta := PrivStaStatisticsReq{Count: 1, Records: []StaStatisticsRecord{rec}}
	if v, err := ParsePrivStaStatisticsReq(sta.AssembleValue()); err != nil ||
		v.Count != 1 || v.Records[0].NegotiatedMbps != 42 || !bytes.Equal(v.Records[0].MAC[:], rec.MAC[:]) {
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
