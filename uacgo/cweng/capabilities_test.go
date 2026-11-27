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
	if c.ProductType != 0 || !c.MeshDevice {
		t.Fatal("APDB top-level type12/13 metadata differs", c.ProductType, c.MeshDevice)
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

func TestLegacyAPDBResolvesFiveGHzFirmwareKey(t *testing.T) {
	db, err := LoadAPDB("../data/apdb.json")
	if err != nil {
		t.Fatal(err)
	}
	// Supplied V6 DB names this band "5.0G", not "5G". This AP
	// has no private51 report and needs both radios for roam estimation.
	ap := &APEntry{ModelID: 302042625, HardwareVersion: "1.0"}
	db.ResolveCapabilities(ap)
	if len(ap.Capabilities) != 2 {
		t.Fatal("lost legacy dual-band radio", ap.Capabilities)
	}
	r := ap.Capabilities[1]
	if r.RadioID != 2 || r.Band != "5 GHz" || !r.SupportAC || r.MaxClients != 100 || r.MaxPower != 25 {
		t.Fatal("wrong hardware/band capability", r)
	}
	unknown := &APEntry{ModelID: ap.ModelID, HardwareVersion: "99.0"}
	db.ResolveCapabilities(unknown)
	if len(unknown.Capabilities) != 0 {
		t.Fatal("borrowed another hardware revision")
	}
}

func TestProductMetadataFlowsFromAPReportToStatus(t *testing.T) {
	for _, product := range []byte{0, 1, 2, 3} {
		b := make([]byte, 16)
		b[15] = 2
		b = append(b, 12, 1, 1, 13, 1, product)
		p, _ := capwap.NewParsedPacket(3)
		p.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x51, Value: b}})}}
		entry, err := ParseAPEntry(p)
		if err != nil || entry.ProductType != product || !entry.MeshDevice {
			t.Fatal("lost role metadata", product, entry, err)
		}
		s := resourceSession()
		s.apEntry = entry
		status := s.statusLocked()
		if status.ProductType != product || !status.MeshDevice {
			t.Fatal("status lost role metadata", status)
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
