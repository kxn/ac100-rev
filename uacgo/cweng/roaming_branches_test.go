package cweng

import (
	"net"
	"reflect"
	"testing"
	"time"
	"uacgo/capwap"
)

// 4e89ac looks up the first 49, then the first 58, independently of wire
// order. In particular operation3 association is visible to the trigger.
func TestV6PMKPrecedesRoamingTriggerAndUsesFirstElement(t *testing.T) {
	for _, syncOK := range []bool{false, true} {
		t.Run(map[bool]string{false: "failed-pmk", true: "synced-pmk"}[syncOK], func(t *testing.T) {
			e, err := NewEngine(0)
			if err != nil {
				t.Fatal(err)
			}
			defer e.Close()
			table := NewClientTable()
			e.RegisterWstaHandlers(table)
			s := newSession(&net.UDPAddr{}, e.acData)
			s.apEntry = &APEntry{RadioCount: 1, GeneralCapabilities: []uint32{0, 0, 1 << 2}}
			mac := [6]byte{2, 1, 2, 3, 4, 5}
			var calls []string
			e.OnStationPMK = func(_ string, _ time.Time, _ bool, p capwap.PrivStaPMKReq) *capwap.PrivStaPMKReq {
				calls = append(calls, "pmk")
				p.Operation = 2
				if !syncOK {
					p.Result = 1
				}
				return &p
			}
			e.OnRoamingTrigger = func(_ string, _ time.Time, p capwap.PrivRoamingTrigger) {
				calls = append(calls, "trigger")
				if p.ChannelLoad != 17 || (len(table.All()) == 1) != syncOK {
					t.Error("trigger used duplicate element or preceded PMK outcome", p, table.All())
				}
			}
			a := capwap.PrivRoamingTrigger{Radio: 1, ChannelLoad: 17}
			b := capwap.PrivRoamingTrigger{Radio: 1, ChannelLoad: 99}
			pmk := capwap.PrivStaPMKReq{Operation: 3, MAC: mac, Radio: 1, WLAN: 1}
			req, _ := capwap.NewParsedPacket(9)
			rsp, _ := capwap.NewParsedPacket(10)
			req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{
				{Type: 0x58, Value: a.AssembleValue()}, {Type: 0x49, Value: pmk.AssembleValue()},
				{Type: 0x58, Value: b.AssembleValue()}, {Type: 0x49, Value: pmk.AssembleValue()},
			})}}
			e.reg.handleMsg(&Ctx{Session: s}, 9, req, rsp)
			if !reflect.DeepEqual(calls, []string{"pmk", "trigger"}) {
				t.Fatal("listener did not follow original lookup order", calls)
			}
		})
	}
}

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
