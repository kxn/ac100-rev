package capwap

import (
	"bytes"
	"testing"
)

// Variants A/B of the wsrv-para extended tail: typed roundtrips in both
// flag forms, plus exact-consumption failure on trailing bytes.
func TestWsrvParaExtRoundtrips(t *testing.T) {
	// A
	a := WsrvParaExtA{A: 1, B: 2, C: 0xdeadbeef, D: 42, Raw: []byte("payload")}
	w := AssembleWsrvParaExtA(a)
	v, err := ParseWsrvParaExtA(w)
	if err != nil || v.A != 1 || v.C != 0xdeadbeef || v.D != 42 || !bytes.Equal(v.Raw, a.Raw) {
		t.Fatalf("ext A: %v %+v", err, v)
	}
	if _, err := ParseWsrvParaExtA(append(w, 0)); err == nil {
		t.Fatal("ext A trailing byte must fail")
	}

	// B short form (flag 0)
	b0 := WsrvParaExtB{A: 3, B: 0, C: 1, D: 2, G: 7, Raw: []byte("x")}
	w0 := AssembleWsrvParaExtB(b0)
	v0, err := ParseWsrvParaExtB(w0)
	if err != nil || v0.B != 0 || v0.G != 7 || !bytes.Equal(v0.Raw, []byte("x")) {
		t.Fatalf("ext B short: %v %+v", err, v0)
	}

	// B full form (flag 1)
	b1 := WsrvParaExtB{A: 4, B: 1, C: 1, D: 2, OptE: 3, OptF: 4,
		G: 5, OptH: 6, OptI: 7, OptJ: 8, Raw: []byte("yy")}
	w1 := AssembleWsrvParaExtB(b1)
	v1, err := ParseWsrvParaExtB(w1)
	if err != nil || v1.OptE != 3 || v1.OptJ != 8 || !bytes.Equal(v1.Raw, []byte("yy")) {
		t.Fatalf("ext B full: %v %+v", err, v1)
	}
	if _, err := ParseWsrvParaExtB(w1[:len(w1)-1]); err == nil {
		t.Fatal("ext B truncated must fail")
	}
}
