package cweng

import (
	"encoding/hex"
	"net"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestV6LifecycleElementPrecedenceAndBalancePriority(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	table := NewClientTable()
	e.RegisterWstaHandlers(table)
	session := newSession(&net.UDPAddr{}, e.acData)
	session.apEntry = &APEntry{RadioCount: 2}
	assoc, _ := hex.DecodeString("0201020304050607ffffffec00000002aabb")
	req, _ := capwap.NewParsedPacket(9)
	rsp, _ := capwap.NewParsedPacket(10)
	req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 2, Value: assoc}})}, {Type: 0x33, Value: []byte{2, 0, 0, 0, 0}}}
	e.reg.handleMsg(&Ctx{Session: session}, 9, req, rsp)
	if len(table.All()) != 0 {
		t.Fatal("RSSI branch must suppress lower priority association")
	}
	calls := 0
	e.OnStationDiscovery = func(string, time.Time, [6]byte) { calls++ }
	e.CheckAssociation = func(string, uint8, uint8, [6]byte, *int8, *capwap.AssociationMLO) uint32 {
		if calls != 1 {
			t.Error("balance discovery did not run before admission")
		}
		return 0
	}
	req.Elements = req.Elements[:1]
	probe := capwap.StaDiscovery{Radio: 2, WlanID: 1, MAC: [6]byte{2, 3, 4, 5, 6, 7}}
	req.Elements = append(req.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0xb, Value: probe.AssembleValue()}})})
	rsp, _ = capwap.NewParsedPacket(10)
	e.reg.handleMsg(&Ctx{Session: session}, 9, req, rsp)
	if calls != 1 || len(table.All()) != 1 {
		t.Fatal(calls, table.All())
	}
}

func TestMLOMissingLinkSentinelDoesNotForgeRSSISample(t *testing.T) {
	table := NewClientTable()
	root, a, b := [6]byte{2, 0, 0, 0, 0, 1}, [6]byte{2, 0, 0, 0, 0, 2}, [6]byte{2, 0, 0, 0, 0, 3}
	now := time.Unix(2000, 0)
	rssi := int8(-50)
	links := []capwap.AssociationLink{{MAC: a, Radio: 1, WLAN: 1, RSSI: -50}, {MAC: b, Radio: 2, WLAN: 1, RSSI: -60}}
	table.StationEvent(ClientEvent{APID: "ap", MAC: root, MLD: &root, MLOLinks: links, RadioID: 1, WLANID: 1, RSSI: &rssi, Kind: "associate", Seen: now})
	table.MLOStatisticsMissing("ap", time.Time{}, []capwap.StaStatisticsRecord{{MAC: a, Radio: 1, WLAN: 1}})
	for _, ev := range table.All() {
		if ev.MAC == b && (ev.RSSI == nil || *ev.RSSI != -60 || !ev.RSSIAt.Equal(now)) {
			t.Fatal("sentinel became a measured sample", ev)
		}
	}
	shown := table.Display()
	if len(shown) != 1 || shown[0].RSSI == nil || *shown[0].RSSI != -95 || shown[0].LinkStatus[1].RSSI == nil || *shown[0].LinkStatus[1].RSSI != -95 {
		t.Fatal(shown)
	}
	rssi = -55
	table.StationEvent(ClientEvent{APID: "ap", MAC: b, RadioID: 2, WLANID: 1, RSSI: &rssi, Kind: "statistics", Seen: now.Add(time.Second)})
	if *table.Display()[0].LinkStatus[1].RSSI != -55 {
		t.Fatal("real link report did not replace sentinel")
	}
}
func TestMLOPeerDatabaseRadioCountingAndDisplay(t *testing.T) {
	table := NewClientTable()
	mld := [6]byte{2, 0, 0, 0, 0, 1}
	a, b := [6]byte{2, 0, 0, 0, 0, 2}, [6]byte{2, 0, 0, 0, 0, 3}
	links := []capwap.AssociationLink{{MAC: a, Radio: 1, WLAN: 1, RSSI: -45}, {MAC: b, Radio: 2, WLAN: 1, RSSI: -55}}
	now := time.Now()
	table.StationEvent(ClientEvent{APID: "ap", MAC: mld, MLD: &mld, MLOLinks: links, RadioID: 1, WLANID: 1, Kind: "associate", Seen: now})
	if len(table.All()) != 3 || len(table.Display()) != 1 {
		t.Fatal(table.All())
	}
	for _, radio := range []uint8{1, 2} {
		if n, _ := table.RadioCount("ap", radio); n != 1 {
			t.Fatal(radio, n)
		}
	}
	rate := &ClientStatistics{NegotiatedMbps: 1201}
	rssi := int8(-60)
	table.StationEvent(ClientEvent{APID: "ap", MAC: b, RadioID: 2, WLANID: 1, Kind: "statistics", Statistics: rate, RSSI: &rssi, Seen: now.Add(time.Second)})
	display := table.Display()
	if len(display[0].LinkStatus) != 2 || display[0].LinkStatus[1].Statistics.NegotiatedMbps != 1201 || *display[0].LinkStatus[1].RSSI != -60 {
		t.Fatal(display)
	}
	if !table.DisassociateMLO("ap", b, now.Add(2*time.Second)) {
		t.Fatal("peer lookup did not find MLD")
	}
	for _, ev := range table.All() {
		if ev.State != "disconnected" {
			t.Fatal(ev)
		}
	}
}
func TestV6ExtraNormalAssociationAndDeviceMetadata(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	table := NewClientTable()
	e.RegisterWstaHandlers(table)
	session := newSession(&net.UDPAddr{}, e.acData)
	session.apEntry = &APEntry{RadioCount: 2}
	wire, _ := hex.DecodeString("00010203040506070004000900030102b00007000412345678000a00040000003c00010003706164")
	req, _ := capwap.NewParsedPacket(9)
	rsp, _ := capwap.NewParsedPacket(10)
	req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0xc6, Value: wire}})}}
	e.reg.handleMsg(&Ctx{Session: session}, 9, req, rsp)
	rows := table.All()
	if len(rows) != 1 || rows[0].State != "connected" || rows[0].RadioID != 1 || rows[0].WLANID != 2 || rows[0].Device.Hostname != "pad" || *rows[0].Device.Capacity != 0x12345678 || *rows[0].RSSI != -80 {
		t.Fatal(rows)
	}
	age := time.Since(rows[0].ConnectedAt)
	if age < 59*time.Second || age > 61*time.Second {
		t.Fatal(age)
	}
}

func TestAPSessionEpochReleasesCapacityAndRejectsLateSnapshots(t *testing.T) {
	table := NewClientTable()
	mac := [6]byte{2, 4, 6, 8, 10, 12}
	old := time.Unix(1000, 0)
	newer := old.Add(time.Minute)
	table.APState("ap", old, true, old)
	table.StationEvent(ClientEvent{APID: "ap", Connection: old, MAC: mac, RadioID: 1, WLANID: 1, Kind: "associate", Seen: old.Add(time.Second)})
	table.APState("ap", old, false, old.Add(10*time.Second))
	if n, _ := table.RadioCount("ap", 1); n != 0 {
		t.Fatal("offline station retained radio capacity", n)
	}
	table.WirelessSnapshot("ap", old, old.Add(5*time.Second), []ClientEvent{{APID: "ap", Connection: old, MAC: mac, RadioID: 1, WLANID: 1}}, map[[6]byte]bool{mac: true})
	if table.All()[0].State != "disconnected" {
		t.Fatal("late native read resurrected offline epoch")
	}
	table.APState("ap", newer, true, newer)
	table.StationEvent(ClientEvent{APID: "ap", Connection: newer, MAC: mac, RadioID: 2, WLANID: 1, Kind: "associate", Seen: newer.Add(time.Second)})
	table.APState("ap", old, false, newer.Add(2*time.Second))
	table.StationEvent(ClientEvent{APID: "ap", Connection: old, MAC: mac, RadioID: 1, WLANID: 1, Kind: "associate", Seen: newer.Add(3 * time.Second)})
	got := table.All()[0]
	if got.State != "connected" || got.Connection != newer || got.RadioID != 2 {
		t.Fatal("old epoch overrode current association", got)
	}
}
