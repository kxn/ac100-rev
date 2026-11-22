package capwap

import (
	"testing"
)

// 0x53 rssi statistics: head + head2 + count + 14-byte entries roundtrip,
// stride validation, min-length rule.
func TestRssiStatisticsRoundtrip(t *testing.T) {
	p := RssiStatisticsReq{N: 2}
	p.Head[0] = 7
	for i := range p.Entries {
		_ = i
	}
	p.Entries = append(p.Entries, RssiEntry{})
	p.Entries[0].MAC[0] = 0xaa
	p.Entries = append(p.Entries, RssiEntry{})
	w := p.AssembleValue()
	if len(w) != 8+8+4+2*14 {
		t.Fatalf("wire len = %d", len(w))
	}
	v, err := ParseRssiStatisticsReq(w)
	if err != nil || v.N != 2 || len(v.Entries) != 2 || v.Entries[0].MAC[0] != 0xaa {
		t.Fatalf("parse: %v", err)
	}
	// stride mismatch (count=1 but two entries' worth of bytes)
	bad := append(w[:16], w[16:16+28]...)
	if _, err := ParseRssiStatisticsReq(bad); err == nil {
		t.Fatal("count/body mismatch must fail")
	}
	if _, err := ParseRssiStatisticsReq(w[:12]); err == nil {
		t.Fatal("below min 20 must fail")
	}
}

// 0x54 ap statistics: 42-byte header + 32-byte entries, roundtrip and
// header field assertions.
func TestApStatisticsRoundtrip(t *testing.T) {
	p := ApStatisticsReq{Radio: 1, U16: 100}
	p.W[6] = 7
	e := ApStatEntry{U16a: 5}
	e.U32[0] = 9
	p.Entries = append(p.Entries, e)
	w := p.AssembleValue()
	if len(w) != 42+32 {
		t.Fatalf("wire len = %d", len(w))
	}
	v, err := ParseApStatisticsReq(w)
	if err != nil {
		t.Fatal(err)
	}
	if v.Radio != 1 || v.W[6] != 7 || len(v.Entries) != 1 || v.Entries[0].U32[0] != 9 {
		t.Fatalf("roundtrip %+v", v)
	}
	if _, err := ParseApStatisticsReq(w[:30]); err == nil {
		t.Fatal("below min 42 must fail")
	}
}
