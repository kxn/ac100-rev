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
	rs := PrivRssiStatistics{Stations: []RssiStatisticsStation{{MAC: [6]byte{2, 1, 2, 3, 4, 5}, RSSI: [8]int8{-50, -60}}, {MAC: [6]byte{2, 1, 2, 3, 4, 6}}}}
	rs.ChannelLoad[0] = 1
	rs.NoiseFloor[7] = -95
	w = rs.AssembleValue()
	if len(w) != 48 || Uint32BE(w[16:]) != 2 || w[26] != 206 {
		t.Fatal("V6 RSSI list layout differs")
	}
	if v, err := ParsePrivRssiStatistics(w); err != nil || len(v.Stations) != 2 || v.ChannelLoad[0] != 1 || v.Stations[0].RSSI[0] != -50 {
		t.Fatal(v, err)
	}
	for _, bad := range [][]byte{w[:34], w[:47], append(append([]byte{}, w...), 0)} {
		if _, err := ParsePrivRssiStatistics(bad); err == nil {
			t.Fatal("malformed RSSI count accepted")
		}
	}

	ap := PrivApStatistics{Global: APStatisticsGlobal{CPUCount: 1, CPUUtilization: [8]byte{0x88}, Counters: [7]uint32{0, 0, 0, 0, 0, 0, 7}}, Radios: []APRadioStatistics{{Radio: 1}, {Radio: 2, Counters: [4]uint32{0, 0, 0, 8}}}, VAPs: []APVAPStatistics{{Radio: 1, WLAN: 2, BSSID: [6]byte{2, 0, 0, 0, 0, 0x99}}}}
	w = ap.AssembleValue()
	if len(w) != 134 || w[0] != 2 || w[1] != 1 || w[42] != 1 || w[74] != 2 {
		t.Fatal("V6 AP-stat counts/layout differ")
	}
	v, err := ParsePrivApStatistics(w)
	if err != nil || len(v.Radios) != 2 || len(v.VAPs) != 1 || v.Global.CPUUtilization[0] != 0x88 || v.Global.Counters[6] != 7 || v.Radios[1].Counters[3] != 8 || v.VAPs[0].BSSID[5] != 0x99 || !bytes.Equal(v.AssembleValue(), w) {
		t.Fatal(v, err)
	}
	for _, bad := range [][]byte{w[:102], w[:133], append(append([]byte{}, w...), 0)} {
		if _, err := ParsePrivApStatistics(bad); err == nil {
			t.Fatal("truncated AP counts accepted")
		}
	}
}
