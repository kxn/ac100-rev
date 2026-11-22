package capwap

import "testing"

func TestBatch22Roundtrips(t *testing.T) {
	cv := PrivCWVer{HW: 1, SW: 2}
	if v, err := ParsePrivCWVer(cv.AssembleValue()); err != nil || v.SW != 2 {
		t.Fatalf("cwver: %v", err)
	}
	sm := PrivSpecMsgSw{A: 1, B: 2}
	if v, err := ParsePrivSpecMsgSw(sm.AssembleValue()); err != nil || v.B != 2 {
		t.Fatalf("spec msg sw: %v", err)
	}
	rp := PrivRptPara{W1: 1, W2: 2, A: 3, W3: 4, W4: 5}
	if v, err := ParsePrivRptPara(rp.AssembleValue()); err != nil || v.W4 != 5 {
		t.Fatalf("rpt para: %v", err)
	}
}
