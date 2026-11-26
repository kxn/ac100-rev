package cweng

import (
	"os"
	"testing"
	"uacgo/capwap"
)

func TestRealV6APCapabilities(t *testing.T) {
	b, err := os.ReadFile("../testdata/v6-apdb-tl7ap5100.bin")
	if err != nil {
		t.Fatal(err)
	}
	c, err := ParseAPCapabilities(b)
	if err != nil {
		t.Fatal(err)
	}
	if c.Model != "TL-7AP5100HC-PoE/DC易展版" || len(c.Radios) != 2 {
		t.Fatalf("capability identity: %+v", c)
	}
	if c.Radios[0].MaxSSID != 7 || c.Radios[0].MinPower != 3 || c.Radios[0].MaxPower != 24 || c.Radios[1].MinPower != 5 || c.Radios[1].MaxPower != 27 || !c.Radios[1].SupportAC || !c.Radios[1].SupportAX {
		t.Fatalf("capabilities differ from vendor JCS readback: %+v", c.Radios)
	}
	for i := 0; i < len(b); i++ {
		if _, err := ParseAPCapabilities(b[:i]); err == nil {
			t.Fatalf("accepted truncated capability %d", i)
		}
	}
}

func TestV6FirstAXDefaultReportAppliesToAllRadios(t *testing.T) {
	b, err := os.ReadFile("../testdata/v6-apdb-tl7ap5100.bin")
	if err != nil {
		t.Fatal(err)
	}
	p, _ := capwap.NewParsedPacket(3)
	p.Elements = []capwap.Element{{Type: 0x32, Value: []byte{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64}},
		{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{
			{Type: 0xb2, Value: []byte{99, 1, 1, 1, 1, 1, 2, 1, 1}},
			{Type: 0x51, Value: b},
			{Type: 0xb2, Value: []byte{1, 0, 0, 0, 0, 0, 0, 0, 0}},
		})}}
	ap, err := ParseAPEntry(p)
	if err != nil {
		t.Fatal(err)
	}
	if len(ap.Capabilities) != 2 {
		t.Fatal(ap)
	}
	for _, c := range ap.Capabilities {
		if c.AXDefaults == nil || c.AXDefaults.Reserved != 99 {
			t.Fatal("first report's leading byte must not select a radio", c)
		}
	}
}
