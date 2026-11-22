package cweng

import (
	"testing"
	"time"

	"uacgo/capwap"
)

func TestPmkStoreLifecycle(t *testing.T) {
	s := NewPmkStore(50 * time.Millisecond)
	mac := [6]byte{1, 2, 3, 4, 5, 6}
	s.Add(mac, PmkEntry{Req: capwap.PrivStaPMKReq{STAMAC: mac, Result: 0}})
	if _, ok := s.Get(mac); !ok {
		t.Fatal("entry must be live")
	}
	// assoc consumes (wsta_roam_sta_assoc_callback → expiretime_set 0)
	s.Consume(mac)
	if _, ok := s.Get(mac); ok {
		t.Fatal("consumed entry must be gone")
	}
	// idle expiry via Sweep
	s.Add(mac, PmkEntry{})
	time.Sleep(60 * time.Millisecond)
	if n := s.Sweep(time.Now()); n != 1 || s.Len() != 0 {
		t.Fatalf("sweep = %d len = %d", n, s.Len())
	}
}

func TestPmkResponder(t *testing.T) {
	store := NewPmkStore(time.Minute)
	p := &PmkResponder{Store: store}
	mac := [6]byte{1, 2, 3, 4, 5, 6}
	ap := [6]byte{9, 9, 9, 9, 9, 9}
	inform := capwap.PrivStaPMKReq{
		Type: PmkTypeInform, Radio: 1, WlanID: 2,
		STAMAC: mac, APMAC: ap,
	}
	inform.PMKR0[0] = 0xaa

	// inform → stored + inform_suc ack
	out := p.Handle(inform)
	if out == nil || out.Type != PmkTypeInformSuc || out.Result != 0 {
		t.Fatalf("inform ack: %+v", out)
	}
	if store.Len() != 1 {
		t.Fatal("inform must store the key")
	}
	// request_suc → response with the stored material
	out = p.Handle(capwap.PrivStaPMKReq{Type: PmkTypeRequestSuc, STAMAC: mac})
	if out == nil || out.Type != PmkTypeResponse || out.Result != 0 ||
		out.PMKR0[0] != 0xaa || out.APMAC != ap {
		t.Fatalf("pmk response: %+v", out)
	}
	// unknown STA → result 1 ("Can not find roam entry")
	out = p.Handle(capwap.PrivStaPMKReq{Type: PmkTypeRequestSuc, STAMAC: [6]byte{7}})
	if out == nil || out.Result != 1 {
		t.Fatalf("missing entry response: %+v", out)
	}
	// other types → nothing to answer
	if out := p.Handle(capwap.PrivStaPMKReq{Type: PmkTypeResponse}); out != nil {
		t.Fatalf("unexpected answer: %+v", out)
	}
}

func TestPmkWireRoundtrip(t *testing.T) {
	var r capwap.PrivStaPMKReq
	r.Type = PmkTypeInform
	r.Radio, r.WlanID, r.Pairwise = 3, 4, 0x11223344
	r.STAMAC = [6]byte{1, 2, 3, 4, 5, 6}
	r.PMKR0Name[15] = 0xee
	v, err := capwap.ParsePrivStaPMKReq(r.AssembleValue())
	if err != nil || *v != r {
		t.Fatalf("pmk wire: %v %+v", err, v)
	}
}
