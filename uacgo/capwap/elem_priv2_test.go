package capwap

import (
	"bytes"
	"testing"
)

// 0x1b ac info: roundtrip the exact payload in the vendor cw_join_rsp
// envelope (085700c21fa0).
func TestPrivAcInfoFixture(t *testing.T) {
	pkt, err := ParsePacket(mustFixtureBytes(t, "cw_join_rsp_0074efe8.bin"))
	if err != nil {
		t.Fatal(err)
	}
	var raw []byte
	for _, e := range pkt.Elements {
		if e.Type == 0x0025 && len(e.Value) >= 8 && Uint16BE(e.Value[6:]) == 0x1b {
			l := Uint16BE(e.Value[8:])
			raw = e.Value[10 : 10+int(l)]
		}
	}
	if raw == nil {
		t.Fatal("join rsp carries no 0x1b")
	}
	v, err := ParsePrivAcInfo(raw)
	if err != nil {
		t.Fatal(err)
	}
	if !bytes.Equal(v.AssembleValue(), raw) || raw[0] != 0x08 {
		t.Fatalf("ac info roundtrip %x", v)
	}
}

// Synthetic roundtrips for the remaining batch-2 codecs.
func TestPrivBatch2Roundtrips(t *testing.T) {
	ps := PrivPortalSyn{Payload: []byte("portal-sync-blob")}
	if v, err := ParsePrivPortalSyn(ps.AssembleValue()); err != nil || !bytes.Equal(v.Payload, ps.Payload) {
		t.Fatalf("portal syn: %v", err)
	}
	if _, err := ParsePrivPortalSyn([]byte{0, 9, 1, 2}); err == nil {
		t.Fatal("portal syn must require exact consumption")
	}

	blob := PrivApdbInfo([]byte{0xde, 0xad, 0xbe, 0xef})
	if v, err := ParsePrivApdbInfo(blob.AssembleValue()); err != nil || !bytes.Equal(v.AssembleValue(), blob) {
		t.Fatalf("apdb info: %v", err)
	}
	if _, err := ParsePrivApdbInfo([]byte{1}); err == nil {
		t.Fatal("apdb info min length 2")
	}

	sc := PrivStatisticsControl{A: 1, B: 2, C: 3, D: 300, E: 0xffff, F: 7}
	if v, err := ParsePrivStatisticsControl(sc.AssembleValue()); err != nil || *v != sc {
		t.Fatalf("stats control: %v %+v", err, v)
	}

	rc := PrivRoamingControl{
		Switch11K: 1, Switch11V: 1, Switch11R: 0,
		Band2G: RoamingControlBand{TriggerType: 3, RssiTriggerThresh: -75,
			RssiKickEnable: 1, RssiKickThresh: -80, RateTriggerThresh: 10,
			RateKickEnable: 1, RateKickThresh: 5},
		Band5G: RoamingControlBand{TriggerType: 1, RssiTriggerThresh: -70,
			RssiKickEnable: 1, RssiKickThresh: -75},
		ThresholdCheckInterval: 30, RoamingDif: 10,
		BlacklistRestrictTime: 60, RoamingStrategy: 1,
	}
	rc.Reserved[14] = 0x5a
	if w := rc.AssembleValue(); len(w) != 36 {
		t.Fatalf("roaming control wire = %d bytes, want 36", len(w))
	}
	if v, err := ParsePrivRoamingControl(rc.AssembleValue()); err != nil || v != rc {
		t.Fatalf("roaming control: %v %+v", err, v)
	}
	if v, err := ParsePrivRoamingControl(rc.AssembleValue()[:35]); err == nil {
		t.Fatalf("roaming control must be exactly 36 bytes: %+v", v)
	}

	sp := PrivStatPrd{A: 60, B: 300}
	if v, err := ParsePrivStatPrd(sp.AssembleValue()); err != nil || *v != sp {
		t.Fatalf("stat prd: %v", err)
	}
}
