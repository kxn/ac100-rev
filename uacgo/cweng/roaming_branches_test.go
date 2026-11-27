package cweng

import (
	"net"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestV6StatisticsControlGatesFactsButNotBSSIDUpdates(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.RegisterWstaHandlers(NewClientTable())
	s := newSession(&net.UDPAddr{}, e.acData)
	s.apEntry = &APEntry{RadioCount: 1}
	control := capwap.PrivStatisticsControl{}
	e.StatisticsControl = func() capwap.PrivStatisticsControl { return control }
	counts := [4]int{}
	e.OnStationStatistics = func(string, time.Time, capwap.StaStatisticsRecord) { counts[0]++ }
	e.OnAPStatistics = func(string, time.Time, capwap.PrivApStatistics) { counts[1]++ }
	e.OnRSSIStatistics = func(string, time.Time, capwap.PrivRssiStatistics) { counts[2]++ }
	e.OnBSSIDLocations = func(string, time.Time, []capwap.BSSIDLocation) { counts[3]++ }
	sta := capwap.PrivStaStatisticsReq{Count: 1, Records: []capwap.StaStatisticsRecord{{MAC: [6]byte{2, 1}, Radio: 1, WLAN: 1}}}
	aps := capwap.PrivApStatistics{Global: capwap.APStatisticsGlobal{CPUCount: 1}, Radios: []capwap.APRadioStatistics{{Radio: 1, ChannelLoad: 10}}}
	rssi := capwap.PrivRssiStatistics{}
	rssi.ChannelLoad[0] = 90
	// bd subtype2: TLV count16, type16/length16, then count8 and
	// radio8/WLAN8/BSSID6. It is independent of statistics enable bits.
	bd := []byte{0, 1, 0, 2, 0, 9, 1, 1, 1, 2, 2, 0, 0, 0, 0}
	for _, enabled := range []bool{false, true, false} {
		if enabled {
			control.A, control.B, control.C = 1, 1, 1
			rssi.ChannelLoad[0] = 90
		} else {
			control = capwap.PrivStatisticsControl{}
			rssi.ChannelLoad[0] = 99
		}
		req, _ := capwap.NewParsedPacket(9)
		rsp, _ := capwap.NewParsedPacket(10)
		req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{
			{Type: 0x52, Value: sta.AssembleValue()}, {Type: 0x54, Value: aps.AssembleValue()},
			{Type: 0x53, Value: rssi.AssembleValue()}, {Type: 0xbd, Value: bd},
		})}}
		e.reg.handleMsg(&Ctx{Session: s}, 9, req, rsp)
	}
	if counts != [4]int{1, 1, 1, 3} || s.radioStatistics[1].ChannelLoad != 90 {
		t.Fatal("disabled reports changed facts or disabled BSSID lookup", counts, s.radioStatistics)
	}
}

func TestV6PartialAPReportRetainsOtherVAPSlotsInSession(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.RegisterWstaHandlers(NewClientTable())
	s := newSession(&net.UDPAddr{}, e.acData)
	s.apEntry = &APEntry{RadioCount: 2}
	a, b, c := [6]byte{2, 1}, [6]byte{2, 2}, [6]byte{2, 3}
	for _, rows := range [][]capwap.APVAPStatistics{
		{{Radio: 1, WLAN: 1, BSSID: a}, {Radio: 2, WLAN: 1, BSSID: b}},
		{{Radio: 1, WLAN: 1, BSSID: c}},
	} {
		req, _ := capwap.NewParsedPacket(9)
		rsp, _ := capwap.NewParsedPacket(10)
		p := capwap.PrivApStatistics{Global: capwap.APStatisticsGlobal{CPUCount: 1}, VAPs: rows}
		req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x54, Value: p.AssembleValue()}})}}
		e.reg.handleMsg(&Ctx{Session: s}, 9, req, rsp)
	}
	if len(s.vapStatistics) != 2 || s.vapStatistics[0].BSSID != c || s.vapStatistics[1].BSSID != b {
		t.Fatal("partial report removed another slot or retained replaced BSSID", s.vapStatistics)
	}
}
