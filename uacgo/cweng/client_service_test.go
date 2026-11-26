package cweng

import (
	"testing"
	"time"
)

func TestClientServiceFactsSurviveSlotReuseAndDisconnect(t *testing.T) {
	table := NewClientTable()
	id, ssid := "old-service", "OldSSID"
	table.ResolveService = func(string, uint8, uint32) (string, string) { _ = table.All(); return id, ssid }
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	now := time.Now()
	table.StationEvent(ClientEvent{Kind: "associate", State: "connected", MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Seen: now})
	id, ssid = "new-service", "NewSSID"
	table.StationEvent(ClientEvent{Kind: "statistics", MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Statistics: &ClientStatistics{}, Seen: now.Add(time.Second)})
	if table.All()[0].SSID != "OldSSID" {
		t.Fatal("late statistics relabeled old client")
	}
	table.StationEvent(ClientEvent{Kind: "disassociate", State: "disconnected", MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Seen: now.Add(2 * time.Second)})
	if table.All()[0].SSID != "OldSSID" {
		t.Fatal("disconnect lost historical SSID")
	}
	table.StationEvent(ClientEvent{Kind: "associate", State: "connected", MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Seen: now.Add(3 * time.Second)})
	if table.All()[0].SSID != "NewSSID" || table.All()[0].ServiceID != "new-service" {
		t.Fatal("new association kept old service")
	}
	h := table.Transitions(0)
	if len(h) != 3 || h[0].SSID != "OldSSID" || h[1].SSID != "OldSSID" || h[2].SSID != "NewSSID" {
		t.Fatal(h)
	}
}

func TestReportedClientVLANIsHistoricalAndNeverDerivedFromNewConfig(t *testing.T) {
	table := NewClientTable()
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	now := time.Now()
	vlan := uint16(101)
	table.WirelessSnapshot("a", now, []ClientEvent{{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, SSID: "Pool", ServiceID: "pool", VLAN: &vlan, IP: "192.0.2.20"}}, map[[6]byte]bool{mac: true})
	snapshot := table.All()
	*snapshot[0].VLAN = 999
	table.StationEvent(ClientEvent{Kind: "disassociate", State: "disconnected", MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Seen: now.Add(time.Second)})
	old := table.All()[0]
	if old.VLAN == nil || *old.VLAN != 101 || old.IP != "192.0.2.20" {
		t.Fatal("disconnect lost observed address facts", old)
	}
	table.StationEvent(ClientEvent{Kind: "associate", State: "connected", MAC: mac, APID: "a", RadioID: 1, WLANID: 1, SSID: "New", ServiceID: "new", Seen: now.Add(2 * time.Second)})
	if table.All()[0].VLAN != nil {
		t.Fatal("new service inherited old VLAN")
	}
	h := table.Transitions(0)
	if h[1].VLAN == nil || *h[1].VLAN != 101 {
		t.Fatal("history relabeled old VLAN", h)
	}
}
