package capwap

import (
	"testing"
)

func TestBatch18Roundtrips(t *testing.T) {
	dd := PrivDhcpDefend{Enable: 1, Count: 1, SvrLen: 1, Tail: []byte{1, 2, 3, 4, 5, 6, 7}}
	if v, err := ParsePrivDhcpDefend(dd.AssembleValue()); err != nil || v.Enable != 1 {
		t.Fatalf("dhcp defend: %v", err)
	}

	ad := PrivArpDefend{Enable: 1, Count: 1, W1: 1, Tail: make([]byte, 10)}
	if v, err := ParsePrivArpDefend(ad.AssembleValue()); err != nil || v.Enable != 1 {
		t.Fatalf("arp defend: %v", err)
	}

	pm := PrivStaPMKReq{Operation: 1, Radio: 2, WLAN: 3, Pairwise: 42}
	pm.Interface[0] = 1
	pm.Nonce[0] = 2
	pm.MAC[0] = 3
	pm.PMKR0[0] = 4
	w := pm.AssembleValue()
	if len(w) != 101 || w[0] != 1 || w[2] != 2 || w[3] != 3 || w[53] != 4 {
		t.Fatalf("PMK V6 layout differs: %x", w)
	}
	if v, err := ParsePrivStaPMKReq(w); err != nil || v.Radio != 2 || v.Pairwise != 42 || v.PMKR0[0] != 4 {
		t.Fatalf("PMK parse: %v", err)
	}
	for _, bad := range [][]byte{w[:100], append(append([]byte{}, w...), 0), w[:8]} {
		if _, err := ParsePrivStaPMKReq(bad); err == nil {
			t.Fatal("truncated PMK accepted")
		}
	}

	var ldp PrivLLDP
	ldp[0] = 1
	if v, err := ParsePrivLLDP(ldp.AssembleValue()); err != nil || v[0] != 1 {
		t.Fatalf("lldp: %v", err)
	}
}

func TestDefendCountIsNotAByteLengthOrPaddedCStruct(t *testing.T) {
	arp := []byte{0x35, 1, 0, 0, 0, 1, 192, 0, 2, 1, 2, 3, 4, 5, 6, 7}
	if p, err := ParsePrivArpDefend(arp); err != nil || p.W1 != 1 || len(p.Tail) != 10 {
		t.Fatal(p, err)
	}
	for _, b := range [][]byte{arp[:15], append(arp, 0), {1, 1, 255, 255, 255, 255}} {
		if _, err := ParsePrivArpDefend(b); err == nil {
			t.Fatalf("accepted malformed list %x", b)
		}
	}
	// Unlike DHCP's toggle, ARP always carries count entries even for operation0.
	if _, err := ParsePrivArpDefend([]byte{1, 0, 0, 0, 0, 1}); err == nil {
		t.Fatal("ARP count ignored")
	}
}
