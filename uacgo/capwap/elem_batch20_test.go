package capwap

import (
	"bytes"
	"testing"
)

func TestBatch20Roundtrips(t *testing.T) {
	d := PrivDeleteImplicitlyLeaveStation{A: 1, B: 2, Rest: bytes.Repeat([]byte{9}, 6)}
	if v, err := ParsePrivDeleteImplicitlyLeaveStation(d.AssembleValue()); err != nil || v.A != 1 || len(v.Rest) != 6 {
		t.Fatalf("delete implicitly: %v", err)
	}

	np := PrivNdpPara{U8a: 1, W1: 2, W3: 3, U8f: 4, Tail: []byte{7, 8}}
	np.MAC[0] = 0xaa
	if v, err := ParsePrivNdpPara(np.AssembleValue()); err != nil || v.W3 != 3 || v.MAC[0] != 0xaa {
		t.Fatalf("ndp para: %v", err)
	}

	rl := PrivRrmNeighsList{A: 1, B: 2}
	rl.Neighs = append(rl.Neighs, RrmNeigh{})
	rl.Neighs[0].MAC[5] = 0x66
	rl.Neighs[0].Samples = []RrmRSSI{{Radio: 1, Power: 20, RSSI: -69}, {Radio: 2, Power: 24, RSSI: -75}}
	if v, err := ParsePrivRrmNeighsList(rl.AssembleValue()); err != nil || len(v.Neighs) != 1 || len(v.Neighs[0].Samples) != 2 || v.Neighs[0].Samples[1].RSSI != -75 {
		t.Fatalf("rrm neighs: %v", err)
	}

	al := PrivApLog{W: 1, A: 2, B: 3, W2: 4, Rest: []byte{5}}
	if v, err := ParsePrivApLog(al.AssembleValue()); err != nil || v.W2 != 4 || len(v.Rest) != 1 {
		t.Fatalf("ap log: %v", err)
	}

	rp := PrivApLogReportPara{A: 1, D: 4, W: 42}
	rp.IP = [4]byte{10, 0, 0, 1}
	if v, err := ParsePrivApLogReportPara(rp.AssembleValue()); err != nil || v.W != 42 || v.IP[0] != 10 {
		t.Fatalf("log report para: %v", err)
	}

	d6 := PrivDhcpv6Defend{Enable: 1, Count: 1, SvrLen: 1, Tail: make([]byte, 17)}
	if v, err := ParsePrivDhcpv6Defend(d6.AssembleValue()); err != nil || v.SvrLen != 1 {
		t.Fatalf("dhcpv6: %v", err)
	}

	nd := PrivNdDefend{Enable: 1, Count: 1, W: 1, Tail: bytes.Repeat([]byte{0}, 22)}
	if v, err := ParsePrivNdDefend(nd.AssembleValue()); err != nil || v.W != 1 {
		t.Fatalf("nd defend: %v", err)
	}

	var wc PrivApWorkingChannelList
	wc[0], wc[5] = 1, 165
	wire := wc.AssembleValue()
	if len(wire) != 24 {
		t.Fatalf("working chnl wire = %d", len(wire))
	}
	if v, err := ParsePrivApWorkingChannelList(wire); err != nil || v[5] != 165 {
		t.Fatalf("working chnl: %v", err)
	}
}
