package capwap

import (
	"bytes"
	"encoding/hex"
	"testing"
)

func TestAdvRadioV6Wire(t *testing.T) {
	// Original V6 controller, rf_mngr radio 1, mode 11be, auto bandwidth.
	b, _ := hex.DecodeString("010c0201010000010100000000000a0000000000030000000000")
	p, err := ParsePrivAdvRdPara(b)
	if err != nil {
		t.Fatal(err)
	}
	if p.Head[0] != 12 || p.BaseFlags != 0 || p.HasByte15 || !bytes.Equal(p.Extra4, []byte{0, 0, 0, 0}) || p.Tail6[0] != 3 {
		t.Fatalf("incorrect field positions: %+v", p)
	}
	if !bytes.Equal(p.AssembleValue(), b) {
		t.Fatal("V6 wire changed")
	}
	// Exercise all vendor length forms with non-default RSSI values.
	for _, n := range []int{16, 17, 20, 21, 22, 23, 26, 27} {
		v := make([]byte, n)
		v[0] = 1
		for i := 1; i < n; i++ {
			v[i] = byte(i)
		}
		p, err := ParsePrivAdvRdPara(v)
		if err != nil || !bytes.Equal(p.AssembleValue(), v) {
			t.Fatalf("length %d: %v", n, err)
		}
	}
	for _, n := range []int{0, 15, 18, 19, 24, 25, 28} {
		if _, err := ParsePrivAdvRdPara(make([]byte, n)); err == nil {
			t.Fatalf("accepted invalid length %d", n)
		}
	}
}

func TestTaggedStationAddresses(t *testing.T) {
	b, _ := hex.DecodeString("0000000202000000000101c0a846640200000000020220010db8000000000000000000000001")
	rows, err := ParseStationAddressList(b)
	if err != nil || len(rows) != 2 || len(rows[1].Address) != 16 {
		t.Fatalf("addresses: %v %+v", err, rows)
	}
	b[10] = 3
	if _, err = ParseStationAddressList(b); err == nil {
		t.Fatal("accepted unknown address family")
	}
}
func TestMLOAssociationBounds(t *testing.T) {
	b, _ := hex.DecodeString("02000000000101010102000000000200000000")
	m, err := ParseAssociationMLO(b)
	if err != nil || len(m.Links) != 1 {
		t.Fatalf("MLO: %+v %v", m, err)
	}
	b[6] = 4
	if _, err = ParseAssociationMLO(b); err == nil {
		t.Fatal("accepted excessive MLO peer count")
	}
}
