package capwap

import (
	"testing"
)

// IEEE 802.11 elements: fixture roundtrips from cw_cfg_update_req.
func TestIEEE80211Elements(t *testing.T) {
	// MAC Operation (0x0406): fixture value
	var mo [16]byte
	copy(mo[:], []byte{1, 0, 0x09, 0x2a, 0, 0, 0x09, 0x2a, 0, 0, 0, 0, 0, 0, 0, 0})
	e := AppendMacOperation(nil, mo)
	if len(e[4:]) != 16 || e[4] != 1 {
		t.Fatalf("mac operation framing: %x", e)
	}

	// TX Power (0x0411): fixture value
	tp := AppendTxPower(nil, 1, 20)
	if len(tp[4:]) != 4 || tp[4] != 1 {
		t.Fatalf("tx power framing: %x", tp)
	}
	r, _, _, err := ParseTxPower(tp[4:])
	if err != nil || r != 1 {
		t.Fatalf("tx power parse: %v", err)
	}

	// Radio Config (0x0416): fixture value
	var rc [16]byte
	copy(rc[:], []byte{1, 1, 8, 1, 0, 0, 0, 0, 0, 0, 0x64, 0x43, 0x4e, 0x20, 0, 0})
	e = AppendRadioConfig(nil, rc)
	if len(e[4:]) != 16 {
		t.Fatalf("radio config len = %d", len(e[4:]))
	}

	// Supported Rates (0x0403)
	var rates [8]byte
	rates[0] = 0x82 // 1 Mbps
	e = AppendSupportedRates(nil, rates)
	if len(e[4:]) != 8 {
		t.Fatalf("supported rates len = %d", len(e[4:]))
	}

	// Multi-Domain Capability (0x0404)
	e = AppendMultiDomainCapability(nil, 1, 13)
	if len(e[4:]) != 4 || e[7] != 13 {
		t.Fatalf("multi domain: %x", e)
	}
}
