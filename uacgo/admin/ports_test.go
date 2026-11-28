package admin

import (
	"bytes"
	"testing"
	"uacgo/cweng"
)

func TestPortVLANSelectsOriginalLegacyAndExtensionFormats(t *testing.T) {
	vlan, zero := uint16(100), uint16(0)
	for _, tc := range []struct {
		count int
		typ   byte
		value []byte
	}{
		{1, 0x30, []byte{0, 0, 0, 100}},
		{2, 0x43, []byte{0, 100, 0, 0, 0, 0, 0, 0}},
		{4, 0x43, []byte{0, 100, 0, 0, 0, 0, 0, 0}},
	} {
		ap := cweng.APStatus{ExtWirePhys: tc.count}
		els, err := managementElements(APOptions{Ports: []APPort{{ID: 1, VLAN: &vlan}}}, ap)
		if err != nil || len(els) != 1 || els[0].Value[7] != tc.typ || !bytes.Equal(els[0].Value[10:], tc.value) {
			t.Fatal(tc.count, els, err)
		}
	}
	ap := cweng.APStatus{Ports: []cweng.PortCapability{{ID: 103}}, SubCapabilities: map[uint16]uint32{98: 2}}
	els, err := managementElements(APOptions{Ports: []APPort{{ID: 103, VLAN: &zero}}}, ap)
	if err != nil || len(els) != 1 || !bytes.Equal(els[0].Value[10:], []byte{0, 1, 0, 1, 0, 4, 1, 103, 0, 0}) {
		t.Fatal("extended VLAN0/physical identity", els, err)
	}
	on := true
	if _, err = managementElements(APOptions{Ports: []APPort{{ID: 103, Enabled: &on}}}, ap); err == nil {
		t.Fatal("VLAN capability enabled port power control")
	}
	ap.SubCapabilities = map[uint16]uint32{98: 1 << 14}
	if _, err = managementElements(APOptions{Ports: []APPort{{ID: 103, VLAN: &vlan}}}, ap); err == nil {
		t.Fatal("enable capability selected extended VLAN format")
	}
	els, err = managementElements(APOptions{Ports: []APPort{{ID: 103, Enabled: &on}}}, ap)
	if err != nil || len(els) != 1 || !bytes.Equal(els[0].Value[10:], []byte{0, 1, 0, 16, 0, 3, 1, 103, 1}) {
		t.Fatal("extended port control", els, err)
	}
}

func TestInheritedPortsProjectCapabilitiesWithoutMutatingExplicitIntent(t *testing.T) {
	vlan := uint16(100)
	on := true
	o := APOptions{Ports: []APPort{{ID: 1, VLAN: &vlan, Enabled: &on}}}
	got := supportedInheritedOptions(o, cweng.APStatus{ExtWirePhys: 1})
	if len(got.Ports) != 1 || got.Ports[0].VLAN == nil || got.Ports[0].Enabled != nil || o.Ports[0].Enabled == nil {
		t.Fatal(got, o)
	}
	if _, err := managementElements(o, cweng.APStatus{ExtWirePhys: 1}); err == nil {
		t.Fatal("explicit unsupported control silently projected away")
	}
}

func TestPortSettingsUseReportedIdentitiesAndExcludeUplink(t *testing.T) {
	vlan := uint16(100)
	enabled := true
	ap := cweng.APStatus{Ports: []cweng.PortCapability{{ID: 12, Uplink: true}, {ID: 103, LAG: true}}, GeneralCapabilities: []uint32{0, 0, 1 << 7}, SubCapabilities: map[uint16]uint32{98: 2 | 1<<14}}
	o := APOptions{Ports: []APPort{{ID: 103, VLAN: &vlan, Enabled: &enabled}}}
	els, err := managementElements(o, ap)
	if err != nil || len(els) != 2 || els[0].Value[len(els[0].Value)-3] != 103 {
		t.Fatal("sparse port not configured", els, err)
	}
	for _, id := range []uint8{1, 12} {
		o.Ports[0].ID = id
		if _, err := managementElements(o, ap); err == nil {
			t.Fatal("unreported or uplink port was configured", id)
		}
	}
	o = APOptions{LAG: &APLAG{Enabled: true, Ports: []uint8{12, 103}}}
	if _, err := managementElements(o, ap); err == nil {
		t.Fatal("LAG accepted incapable uplink")
	}
	ap.Ports = append(ap.Ports, cweng.PortCapability{ID: 104, LAG: true})
	o.LAG.Ports = []uint8{103, 104}
	if _, err := managementElements(o, ap); err != nil {
		t.Fatal(err)
	}
}
