package capwap

import (
	"bytes"
	"encoding/hex"
	"testing"
)

func TestPhysicalClientLegacyAssociationPermit(t *testing.T) {
	b, _ := hex.DecodeString("0201020304050607ffffffec000000020000")
	a, e := ParseLegacyAssociation(b)
	if e != nil || a.RSSI == nil || *a.RSSI != -20 {
		t.Fatal(a, e)
	}
	want, _ := hex.DecodeString("020102030405060700000000000000020000")
	if !bytes.Equal(a.Result(0), want) {
		t.Fatalf("permit %x", a.Result(0))
	}
	for i := 0; i < len(b); i++ {
		if _, e := ParseLegacyAssociation(b[:i]); e == nil {
			t.Fatal("truncation accepted", i)
		}
	}
}
func TestLegacyAssociationWithoutRSSI(t *testing.T) {
	b, _ := hex.DecodeString("010102030405060700000002aabb")
	a, e := ParseLegacyAssociation(b)
	if e != nil || a.RSSI != nil || !bytes.Equal(a.Backfill, []byte{0xaa, 0xbb}) {
		t.Fatal(a, e)
	}
}

func TestAuthenticationBackfillLengthIsNotVLAN(t *testing.T) {
	b, _ := hex.DecodeString("020102030405060700000002aabb")
	a, err := ParseStaAuthReq(b)
	if err != nil || !bytes.Equal(a.Backfill, []byte{0xaa, 0xbb}) {
		t.Fatal(a, err)
	}
	want, _ := hex.DecodeString("02010203040506070000002500000002aabb")
	result := StaAuthResult{Radio: a.Radio, WlanID: a.WlanID, MAC: a.MAC, Result: 0x25, Backfill: a.Backfill}
	if !bytes.Equal(result.AssembleValue(), want) {
		t.Fatalf("auth response %x", result.AssembleValue())
	}
	for _, bad := range [][]byte{b[:12], append(append([]byte{}, b...), 0), want[:16]} {
		if len(bad) >= 16 {
			if _, err := ParseStaAuthResult(bad); err == nil {
				t.Fatal("accepted bad result length")
			}
		} else if _, err := ParseStaAuthReq(bad); err == nil {
			t.Fatal("accepted bad auth length")
		}
	}
}
