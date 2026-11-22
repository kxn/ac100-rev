package capwap

import (
	"bytes"
	"testing"
)

func TestBatch23Roundtrips(t *testing.T) {
	sr := PrivSpecRssi(42)
	if v, err := ParsePrivSpecRssi(sr.AssembleValue()); err != nil || v != 42 {
		t.Fatalf("spec rssi: %v", err)
	}
	var cs PrivApConfigChecksum
	cs[0], cs[15] = 1, 2
	if v, err := ParsePrivApConfigChecksum(cs.AssembleValue()); err != nil || v[15] != 2 {
		t.Fatalf("checksum: %v", err)
	}
	wl := PrivWechatIPList{Count: 2, Rest: []byte{1, 2, 3, 4, 5, 6, 7, 8}}
	if v, err := ParsePrivWechatIPList(wl.AssembleValue()); err != nil || v.Count != 2 {
		t.Fatalf("wechat iplist: %v", err)
	}
	bc := PrivBwCtrl{A: 1, W1: 2, W2: 3, B: 4, W3: 5, C: 6, Tail: []byte{7}}
	if v, err := ParsePrivBwCtrl(bc.AssembleValue()); err != nil || v.W3 != 5 || v.C != 6 {
		t.Fatalf("bw ctrl: %v", err)
	}
	si := PrivStaIPList{Count: 1}
	si.Rows = append(si.Rows, PrivStaIPRow{})
	si.Rows[0].MAC[5] = 0x66
	si.Rows[0].IP[0] = 10
	w := si.AssembleValue()
	if len(w) != 14 {
		t.Fatalf("sta ip list wire = %d", len(w))
	}
	if v, err := ParsePrivStaIPList(w); err != nil || v.Rows[0].IP[0] != 10 {
		t.Fatalf("sta ip list: %v", err)
	}
	rs := PrivRssiStatistics{W: 9}
	rs.BSSIDs[0] = 1
	rs.Rates[7] = 8
	w = rs.AssembleValue()
	if len(w) != 34 {
		t.Fatalf("rssi stat wire = %d", len(w))
	}
	if v, err := ParsePrivRssiStatistics(w); err != nil || v.W != 9 || v.BSSIDs[0] != 1 {
		t.Fatalf("rssi stat: %v", err)
	}
	ap := PrivApStatistics{A: 1, D: 2, U16a: 3, I: 4, J: 5}
	ap.Blk8[0] = 0x88
	ap.MAC[5] = 0x99
	ap.W1[6] = 7
	ap.W3[3] = 8
	w = ap.AssembleValue()
	if len(w) != 102 {
		t.Fatalf("ap stat wire = %d", len(w))
	}
	v, err := ParsePrivApStatistics(w)
	if err != nil || v.A != 1 || v.D != 2 || v.U16a != 3 || v.Blk8[0] != 0x88 ||
		v.MAC[5] != 0x99 || v.W1[6] != 7 || v.W3[3] != 8 || !bytes.Equal([]byte{v.I, v.J}, []byte{4, 5}) {
		t.Fatalf("ap stat: %v %+v", err, v)
	}
}
