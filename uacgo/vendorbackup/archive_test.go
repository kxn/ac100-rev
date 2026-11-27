package vendorbackup

import (
	"encoding/hex"
	"reflect"
	"testing"
)

func TestDecodeOriginalDESUtilityFixture(t *testing.T) {
	// Created by the supplied des_crypt -e from this public plaintext.
	// This is independent of a Go encrypt/decrypt round trip.
	b, err := hex.DecodeString("f5cac1715a88a24a7616a49136a37499eecc47288183f1c084b099750ac2faf214b95315ed8f9ca1b01ec2acc1f9e4ef")
	if err != nil {
		t.Fatal(err)
	}
	plain, err := Decode(b)
	if err != nil || string(plain) != "go-ac backup codec fixture\n" {
		t.Fatalf("vendor envelope: %q %v", plain, err)
	}
	b[8] ^= 1
	if _, err := Decode(b); err == nil {
		t.Fatal("accepted corrupted checksum")
	}
}

func TestUCIListsQuotesAndEmptyStrings(t *testing.T) {
	sections, err := ParseUCI("config global 'settings'\noption name '办公 Wi-Fi'\noption key 'a'\\''b $literal'\noption empty ''\nlist freq 'rssi'\nlist freq 'rate' # comment\n")
	if err != nil || len(sections) != 1 {
		t.Fatal(sections, err)
	}
	s := sections[0]
	if s.Value("name") != "办公 Wi-Fi" || s.Value("key") != "a'b $literal" || s.Value("empty") != "" || !reflect.DeepEqual(s.Values["freq"], []string{"rssi", "rate"}) {
		t.Fatal(s)
	}
}
