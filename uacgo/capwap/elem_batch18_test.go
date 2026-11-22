package capwap

import (
	"testing"
)

func TestBatch18Roundtrips(t *testing.T) {
	dd := PrivDhcpDefend{Enable: 1, Count: 2, SvrLen: 100, Tail: []byte{1, 2, 3}}
	if v, err := ParsePrivDhcpDefend(dd.AssembleValue()); err != nil || v.Enable != 1 {
		t.Fatalf("dhcp defend: %v", err)
	}

	ad := PrivArpDefend{Enable: 1, Count: 2, EntryLen: 12, Tail: []byte{1, 2, 3}}
	if v, err := ParsePrivArpDefend(ad.AssembleValue()); err != nil || v.Enable != 1 {
		t.Fatalf("arp defend: %v", err)
	}

	pm := PrivStaPMKReq{Type: 1, Result: 0, Radio: 1, WlanID: 2, Pairwise: 42}
	pm.Nonce[0] = 2
	pm.STAMAC[0] = 3
	pm.PMKR0[31] = 9
	pm.PMKR0Name[15] = 7
	w := pm.AssembleValue()
	if len(w) != 0x65 {
		t.Fatalf("pmk wire = %d, want 101", len(w))
	}
	if v, err := ParsePrivStaPMKReq(w); err != nil || *v != pm {
		t.Fatalf("pmk roundtrip: %v %+v", err, v)
	}
	if _, err := ParsePrivStaPMKReq(w[:100]); err == nil {
		t.Fatal("pmk must require exactly 101 bytes")
	}

	var ldp PrivLLDP
	ldp[0] = 1
	if v, err := ParsePrivLLDP(ldp.AssembleValue()); err != nil || v[0] != 1 {
		t.Fatalf("lldp: %v", err)
	}
}
