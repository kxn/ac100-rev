package capwap

import (
	"bytes"
	"testing"
)

// 0x63 B'/C' tails: B' field-for-field roundtrip (three IPs), C' reuse of
// the sta-list codec.
func TestWsrvParaNewExt(t *testing.T) {
	e := WsrvParaNewExtB{
		A: 1, B: 2, C: 0xcafebabe,
		IP1: [4]byte{10, 0, 0, 1}, IP2: [4]byte{10, 0, 0, 2}, IP3: [4]byte{10, 0, 0, 3},
		G: 1, H: 2, I: 3, Length: 3, Raw: []byte("abc"),
	}
	w := AssembleWsrvParaNewExtB(e)
	v, err := ParseWsrvParaNewExtB(w)
	if err != nil {
		t.Fatal(err)
	}
	if v.C != 0xcafebabe || v.IP1 != e.IP1 || v.IP2 != e.IP2 || v.IP3 != e.IP3 ||
		v.G != 1 || v.H != 2 || v.I != 3 || v.Length != 3 || !bytes.Equal(v.Raw, []byte("abc")) {
		t.Fatalf("B' roundtrip %+v", v)
	}
	if _, err := ParseWsrvParaNewExtB(w[:len(w)-1]); err == nil {
		t.Fatal("truncated B' must fail")
	}

	ssids := [][]byte{PaddedString("mesh-ssid", 32)}
	cw := AssembleWsrvParaNewStaList(7, 8, 2, ssids)
	c, err := ParseWsrvParaNewStaList(cw)
	if err != nil || c.A != 7 || c.B != 8 || c.Radio != 2 || len(c.SSIDs) != 1 ||
		!bytes.Equal(c.SSIDs[0], ssids[0]) {
		t.Fatalf("C' roundtrip: %v", err)
	}
}
