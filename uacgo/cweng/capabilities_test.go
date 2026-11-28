package cweng

import (
	"encoding/binary"
	"encoding/json"
	"os"
	"testing"
	"uacgo/capwap"
)

func TestReportedAndLibraryCapabilitiesShareAXControlGateAndDefaults(t *testing.T) {
	reported, err := os.ReadFile("../testdata/v6-apdb-tl7ap5100.bin")
	if err != nil {
		t.Fatal(err)
	}
	var db APDB
	if err = json.Unmarshal([]byte(`{"ap_list":[{"id":100,"ap_name":"Generic","models":[{"hwver":"1.0","radios":{"2.4G":{"max_ssid":8,"max_stations":64,"extend_capability":"3f00","support_11ax":true},"5.0G":{"max_ssid":8,"max_stations":64,"extend_capability":"0","support_11ax":true}}}]}]}`), &db); err != nil {
		t.Fatal(err)
	}
	for _, library := range []bool{false, true} {
		for _, ax := range []bool{false, true} {
			bits := make([]byte, 12)
			if ax {
				binary.BigEndian.PutUint32(bits[8:], 1<<6)
			}
			p, _ := capwap.NewParsedPacket(3)
			priv := []capwap.PrivElementValue{{Type: 0xb2, Value: []byte{99, 1, 1, 1, 1, 1, 2, 0, 0}}}
			if !library {
				priv = append(priv, capwap.PrivElementValue{Type: 0x51, Value: reported})
			}
			p.Elements = []capwap.Element{{Type: 0x32, Value: bits}, {Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, priv)}}
			ap, err := ParseAPEntry(p)
			if err != nil {
				t.Fatal(err)
			}
			if library {
				ap.ModelID = 100
				ap.HardwareVersion = "1.0"
				db.ResolveCapabilities(ap)
			}
			if len(ap.Capabilities) != 2 || !ap.Capabilities[0].Features["downlink_mumimo"] {
				t.Fatal("fixture has no raw AX feature", library, ap.Capabilities)
			}
			for _, c := range ap.Capabilities {
				if c.ControlFeatures["downlink_mumimo"] != ax {
					t.Fatal("raw AX or secondary-radio flags bypassed general70", library, ax, c)
				}
				if ax && (c.AXDefaults == nil || c.AXDefaults.Reserved != 99 || c.AXDefaults.TWT != 1) {
					t.Fatal("report defaults lost through library fallback", c)
				}
				if !ax && c.AXDefaults != nil {
					t.Fatal("unsupported AX defaults became controls", c)
				}
			}
		}
	}
}

func TestWideSubCapabilityDoesNotDiscardFollowingKnownCapabilities(t *testing.T) {
	p, _ := capwap.NewParsedPacket(3)
	p.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x8f, Value: []byte{0, 2, 0, 44, 0, 8, 0, 0, 0, 1, 0, 0, 0, 2, 0, 16, 0, 1, 2}}})}}
	ap, err := ParseAPEntry(p)
	if err != nil || ap.SubCapabilities[44] != 2 || ap.SubCapabilities[16] != 2 {
		t.Fatal("wider native entry truncated the capability table", ap, err)
	}
}

func TestPhysicalPowerSubtypesAndCapability38ShareOneUnitView(t *testing.T) {
	for _, physical := range []bool{false, true} {
		radio := []byte{0, 7, 0, 0}
		for _, v := range []struct {
			kind  byte
			value uint16
		}{{1, 8}, {2, 64}, {3, 30}, {4, 3}, {11, 24}, {12, 5}, {13, 20}} {
			radio = append(radio, v.kind, 2, byte(v.value>>8), byte(v.value))
		}
		body := make([]byte, 16)
		body[15] = 1
		body = append(body, 7, byte(len(radio)))
		body = append(body, radio...)
		p, _ := capwap.NewParsedPacket(3)
		general := make([]byte, 8)
		if physical {
			binary.BigEndian.PutUint32(general[4:], 1<<6)
		}
		p.Elements = []capwap.Element{{Type: 0x32, Value: general}, {Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x51, Value: body}})}}
		ap, err := ParseAPEntry(p)
		if err != nil || len(ap.Capabilities) != 1 {
			t.Fatal(ap, err)
		}
		c := ap.Capabilities[0]
		if physical {
			if c.MaxPower != 24 || c.MinPower != 5 || c.DefaultPower != 20 {
				t.Fatal(c)
			}
		} else if c.MaxPower != 30 || c.MinPower != 3 {
			t.Fatal(c)
		}
		c.RealMinPower = 0
		c.MinPower = 3
		if effectiveRadioPower(c, true).MinPower != 3 {
			t.Fatal("zero physical bound must fall back independently")
		}
	}
}

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

func TestAPCapabilityCountUsesPayloadBoundsNotArbitraryLimit(t *testing.T) {
	b := make([]byte, 16)
	binary.BigEndian.PutUint32(b[12:], 131)
	for range 130 {
		b = append(b, 250, 0)
	} // Unknown, structurally valid future records.
	b = append(b, 1, 7)
	b = append(b, "Generic"...)
	got, err := ParseAPCapabilities(b)
	if err != nil || got.Model != "Generic" {
		t.Fatal(got, err)
	}
	if _, err = ParseAPCapabilities(b[:len(b)-1]); err == nil {
		t.Fatal("accepted truncated value")
	}
}
