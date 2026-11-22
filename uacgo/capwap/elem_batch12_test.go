package capwap

import "testing"

// Batch-12: remaining standard elements with roundtrip + validation.
func TestBatch12Roundtrips(t *testing.T) {
	// capwap control ipv6 address (12B verbatim)
	var c6 CapwapControlIPv6Address
	c6[0] = 1
	if v, err := ParseCapwapControlIPv6Address(c6.AssembleValue()); err != nil || v[0] != 1 {
		t.Fatalf("c6: %v", err)
	}
	if _, err := ParseCapwapControlIPv6Address(make([]byte, 11)); err == nil {
		t.Fatal("c6 len 11 must fail")
	}

	// tunnel mode
	tm := AppendWTPTunnelMode(nil, 1)
	if v, err := ParseWTPTunnelMode(tm[4:]); err != nil || v != 1 {
		t.Fatalf("tunnel mode: %v %d", err, v)
	}

	// wtp radio statistics (20B)
	var rs WTPRadioStatistics
	rs.RadioID = 1
	rs.W[8] = 0xffff
	w := rs.AssembleValue()
	if len(w) != 20 {
		t.Fatalf("radio stats wire = %d", len(w))
	}
	if v, err := ParseWTPRadioStatistics(w); err != nil || v.RadioID != 1 || v.W[8] != 0xffff {
		t.Fatalf("radio stats parse: %v", err)
	}

	// wtp reboot statistics (15B)
	var rb WTPRebootStatistics
	rb.W[0] = 5
	rb.B = 1
	w = rb.AssembleValue()
	if len(w) != 15 {
		t.Fatalf("reboot stats wire = %d", len(w))
	}
	if v, err := ParseWTPRebootStatistics(w); err != nil || v.W[0] != 5 || v.B != 1 {
		t.Fatalf("reboot stats parse: %v", err)
	}

	// wtp static ip info (13B)
	si := WTPStaticIPInfo{IP: 0x0a000001, Netmask: 0xffffff00, Gateway: 0x0a0000fe, Mode: 2}
	w = si.AssembleValue()
	if len(w) != 13 {
		t.Fatalf("static ip wire = %d", len(w))
	}
	if v, err := ParseWTPStaticIPInfo(w); err != nil || v.IP != 0x0a000001 || v.Mode != 2 {
		t.Fatalf("static ip parse: %v", err)
	}

	// capability flag
	cf := AppendWTPCapabilityFlag(nil, 0x1234)
	if v, err := ParseWTPCapabilityFlag(cf[4:]); err != nil || v != 0x1234 {
		t.Fatalf("capability flag: %v", err)
	}

	// sta rssi: header + verbatim body
	r := StaRSSI{RadioID: 1, Count: 1, Body: []byte{0, 0, 0, 1, 0xde, 0xad}}
	if v, err := ParseStaRSSI(r.AssembleValue()); err != nil || v.Count != 1 {
		t.Fatalf("sta rssi: %v", err)
	}
	if _, err := ParseStaRSSI([]byte{0xff}); err == nil {
		t.Fatal("radio >= 0x20 must fail")
	}
}
