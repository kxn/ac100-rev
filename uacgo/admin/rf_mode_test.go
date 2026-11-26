package admin

import (
	"testing"
	"uacgo/cweng"
)

func TestRFModeSelectionNeverUsesRFValueAsModeID(t *testing.T) {
	ap := cweng.APStatus{GeneralCapabilities: []uint32{0, 0, 1 << 28}, RadioModes: []cweng.RadioMode{{ID: 7, RFMode: 0x4003, Name: "Dual"}}}
	o := APOptions{RFMode: &APRFMode{Enabled: true, ID: 7}}
	els, err := managementElements(o, ap)
	if err != nil || len(els) != 1 || string(els[0].Value[10:]) != string([]byte{1, 7, 0}) {
		t.Fatal(els, err)
	}
	o.RFMode = &APRFMode{Enabled: true, ID: 3}
	if _, err := managementElements(o, ap); err == nil {
		t.Fatal("invented mode ID accepted")
	}
	if supportedInheritedOptions(o, ap).RFMode != nil {
		t.Fatal("foreign mode inherited")
	}
	o.RFMode.Enabled = false
	if _, err := managementElements(o, ap); err != nil {
		t.Fatal("disable erroneously requires selected mode", err)
	}
	ap.GeneralCapabilities = nil
	if _, err := managementElements(o, ap); err == nil {
		t.Fatal("unsupported switch sent")
	}
}
