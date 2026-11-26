package capwap

import (
	"testing"
)

// Batch-16: remaining private station/session elements roundtrip.
func TestBatch16Roundtrips(t *testing.T) {
	mac := [6]byte{0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff}

	ar := StaAuthReq{Radio: 1, WlanID: 2, Backfill: []byte{0xaa, 0xbb}}
	copy(ar.MAC[:], mac[:])
	w := ar.AssembleValue()
	if len(w) != 14 {
		t.Fatalf("auth req wire = %d", len(w))
	}
	if v, err := ParseStaAuthReq(w); err != nil || len(v.Backfill) != 2 {
		t.Fatalf("auth req parse: %v", err)
	}

	sr := StaAssocReq{Radio: 1, WLAN: 2, Backfill: []byte{0x12, 0x34}}
	copy(sr.MAC[:], mac[:])
	w = sr.AssembleValue()
	if v, err := ParseStaAssocReq(w); err != nil || len(v.Backfill) != 2 {
		t.Fatalf("assoc req parse: %v", err)
	}

	da := StaDeassoc{Radio: 1, WlanID: 2}
	copy(da.MAC[:], mac[:])
	if v, err := ParseStaDeassoc(da.AssembleValue()); err != nil || v.WlanID != 2 {
		t.Fatalf("deassoc: %v", err)
	}

	arr := StaAuthResult{Radio: 1, WlanID: 2, Result: 0, Backfill: []byte{0xaa, 0xbb}}
	copy(arr.MAC[:], mac[:])
	if v, err := ParseStaAuthResult(arr.AssembleValue()); err != nil || v.Result != 0 {
		t.Fatalf("auth result: %v", err)
	}

	if v, err := ParseChnlState([]byte{1, 2}); err != nil || v.Radio != 1 {
		t.Fatalf("chnl state: %v", err)
	}

	if v, err := ParsePwrState([]byte{1, 1}); err != nil || v.State != 1 {
		t.Fatalf("pwr state: %v", err)
	}

	d := StaDiscovery{Radio: 1, WlanID: 2}
	copy(d.MAC[:], mac[:])
	if v, err := ParseStaDiscovery(d.AssembleValue()); err != nil || v.MAC[0] != 0xaa {
		t.Fatalf("discovery: %v", err)
	}

	if v, err := ParseClearState(ClearState(42).AssembleValue()); err != nil || v != 42 {
		t.Fatalf("clear state: %v", err)
	}

	fs := FrameStat{Radio: 1, W: [30]uint32{1, 2, 3, 4, 5, 6}}
	if v, err := ParseFrameStat(fs.AssembleValue()); err != nil || v.W[5] != 6 {
		t.Fatalf("frame stat: %v", err)
	}

	sm := SnMD5{}
	sm.SN[0] = 1
	sm.MD5[15] = 0xff
	if v, err := ParseSnMD5(sm.AssembleValue()); err != nil || v.MD5[15] != 0xff {
		t.Fatalf("sn md5: %v", err)
	}

	td := TransDataRequest{A: 1, B: 2}
	if v, err := ParseTransDataRequest(td.AssembleValue()); err != nil || v.A != 1 {
		t.Fatalf("trans data: %v", err)
	}

	pe := PrivExcept{W1: 1, W2: 2, W3: 3}
	copy(pe.MAC1[:], mac[:])
	copy(pe.MAC2[:], mac[:])
	if v, err := ParsePrivExcept(pe.AssembleValue()); err != nil || v.MAC1[0] != 0xaa {
		t.Fatalf("priv except: %v", err)
	}
}
