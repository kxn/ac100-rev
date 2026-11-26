package admin

import (
	"bytes"
	"encoding/hex"
	"testing"
	"uacgo/cweng"
)

func TestVLANPoolWireAndCapabilityGates(t *testing.T) {
	p := VLANPool{ID: 2, Name: "Guest", VLANs: "100-102,200"}
	if err := validatePool(p); err != nil {
		t.Fatal(err)
	}
	want, _ := hex.DecodeString("0001000000120002000c00003130302d3130322c32303000")
	got := poolElement(p).Value[10:]
	if !bytes.Equal(got, want) {
		t.Fatalf("pool wire %x want %x", got, want)
	}
	ap := cweng.APStatus{GeneralCapabilities: []uint32{0, 0, 0, 4}, SubCapabilities: map[uint16]uint32{0x5f: 8}}
	s := Service{Enabled: true, WLAN: 3, SSID: "pool", Security: "open", Options: &WirelessOptions{VLANPool: 2}}
	if validateServiceCapability(s, ap, 1) != nil {
		t.Fatal("capability rejected")
	}
	if validateServiceCapability(s, cweng.APStatus{}, 1) == nil {
		t.Fatal("unsupported pool accepted")
	}
	e := wirelessExtraElements(s, 1, ap)
	want, _ = hex.DecodeString("010000000e0300000009040701010102020002")
	if len(e) != 1 || !bytes.Equal(e[0].Value[10:], want) {
		t.Fatalf("pool binding %x", e)
	}
	w := advancedWLANElements(s, 1, ap)[1].Value
	if !bytes.Equal(w[12:14], []byte{0x13, 0x8a}) {
		t.Fatal("missing vendor pool VLAN marker")
	}
}
func TestVLANRanges(t *testing.T) {
	for _, v := range []string{"", "0", "4095", "1-2,2", "2-1", "10,", "1-2-3"} {
		if validatePool(VLANPool{ID: 1, Name: "test", VLANs: v}) == nil {
			t.Fatalf("accepted invalid range %q", v)
		}
	}
}
