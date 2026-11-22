package capwap

import (
	"bytes"
	"testing"
)

// Batch-5 variable-length elements: bandwidth control header+tail roundtrip
// and wsrv-para variant-C sta list (32-byte ssid blocks).
func TestBatch5Roundtrips(t *testing.T) {
	// bandwidth control: 9-byte header + station triples + MAC block
	tail := []byte{
		1, 2, 0, 0, 0, 5, // one per-station triple
		0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, // MAC 1
		0x11, 0x22, 0x33, 0x44, 0x55, 0x66} // MAC 2 (count*6, already even)
	bc := PrivBandwidthCtrl{Count: 2, Up: 512, Down: 1024, Tail: tail}
	if v, err := ParsePrivBandwidthCtrl(bc.AssembleValue()); err != nil {
		t.Fatal(err)
	} else if v.Count != 2 || v.Up != 512 || v.Down != 1024 || !bytes.Equal(v.Tail, tail) {
		t.Fatalf("bw ctrl roundtrip %+v", v)
	}
	if _, err := ParsePrivBandwidthCtrl([]byte{1, 0, 0}); err == nil {
		t.Fatal("short bw ctrl must fail")
	}

	// wsrv para variant-C sta list: two 32-byte ssid blocks
	ssids := [][]byte{PaddedString("one", 32), PaddedString("two", 32)}
	wire := AssembleWsrvParaStaList(1, 2, 3, ssids)
	a, b, radio, got, err := ParseWsrvParaStaList(wire)
	if err != nil || a != 1 || b != 2 || radio != 3 || len(got) != 2 {
		t.Fatalf("sta list a=%d b=%d radio=%d n=%d err=%v", a, b, radio, len(got), err)
	}
	if !bytes.Equal(got[0], ssids[0]) || !bytes.Equal(got[1], ssids[1]) {
		t.Fatal("ssid blocks differ")
	}
	if _, _, _, _, err := ParseWsrvParaStaList([]byte{1, 2, 3, 0}); err == nil {
		t.Fatal("trailing bytes must fail exact consumption")
	}
}
