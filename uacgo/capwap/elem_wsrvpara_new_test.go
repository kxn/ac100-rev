package capwap

import (
	"bytes"
	"testing"
)

// 0x63 new wsrv para: header decodes like the old element, tail carried
// verbatim (extended variants selected by trailing length in the vendor).
func TestWsrvParaNew(t *testing.T) {
	hdr := []byte{1, 2, 0, 1, 0x27, 0x10, 3, 0, 0}
	ext := AssembleWsrvParaExtA(WsrvParaExtA{A: 1, B: 2, C: 5, D: 6, Raw: []byte("z")})
	v := append(append([]byte(nil), hdr...), ext...)

	p, err := ParsePrivWsrvParaNew(v)
	if err != nil {
		t.Fatal(err)
	}
	if p.Header.A != 1 || p.Header.D != 10000 {
		t.Fatalf("header %+v", p.Header)
	}
	if !bytes.Equal(p.Tail, ext) {
		t.Fatalf("tail %x != %x", p.Tail, ext)
	}
	if !bytes.Equal(p.AssembleValue(), v) {
		t.Fatal("roundtrip mismatch")
	}
	if _, err := ParsePrivWsrvParaNew(hdr[:8]); err == nil {
		t.Fatal("short header must fail")
	}
}
