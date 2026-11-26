package cweng

import (
	"os"
	"testing"
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
