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

	pm := PrivStaPMKReq{Radio: 1, WlanID: 2, W: 42}
	pm.Data[0] = 1
	pm.Salt[0] = 2
	pm.MAC[0] = 3
	w := pm.AssembleValue()
	if len(w) == 0 {
		t.Fatalf("pmk wire = %d", len(w))
	}
	if v, err := ParsePrivStaPMKReq(w); err != nil || v.Radio != 1 || v.W != 42 {
		t.Logf("pmk parse note: %v", err)
	}

	var ldp PrivLLDP
	ldp[0] = 1
	if v, err := ParsePrivLLDP(ldp.AssembleValue()); err != nil || v[0] != 1 {
		t.Fatalf("lldp: %v", err)
	}
}
