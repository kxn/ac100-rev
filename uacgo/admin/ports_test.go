package admin

import (
	"testing"
	"uacgo/cweng"
)

func TestPortSettingsUseReportedIdentitiesAndExcludeUplink(t *testing.T) {
	vlan := uint16(100)
	enabled := true
	ap := cweng.APStatus{Ports: []cweng.PortCapability{{ID: 12, Uplink: true}, {ID: 103, LAG: true}}, GeneralCapabilities: []uint32{0, 0, 1 << 7}}
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
