package cweng

import (
	"testing"
	"time"
)

func TestFreshWirelessSnapshotRecoversButDoesNotOverwriteNewerEvents(t *testing.T) {
	table := NewClientTable()
	mac := [6]byte{2, 1, 2, 3, 4, 5}
	start := time.Now()
	ev := ClientEvent{APID: "a", MAC: mac, RadioID: 1, WLANID: 1, ConnectedAt: start.Add(-time.Minute)}
	table.WirelessSnapshot("a", start, []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	if c := table.All(); len(c) != 1 || c[0].State != "connected" {
		t.Fatal(c)
	}
	// A concurrent AP event after the query started wins over its older answer.
	table.StationEvent(ClientEvent{APID: "a", MAC: mac, RadioID: 1, WLANID: 1, State: "disconnected", Kind: "disassociate", Seen: start.Add(time.Second)})
	table.WirelessSnapshot("a", start, []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	if table.All()[0].State != "disconnected" {
		t.Fatal("stale query resurrected client")
	}
	table.WirelessSnapshot("a", start.Add(2*time.Second), []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	if table.All()[0].State != "connected" {
		t.Fatal("fresh authoritative wireless membership not restored")
	}
	table.StationEvent(ClientEvent{APID: "b", MAC: mac, RadioID: 2, WLANID: 1, State: "connected", Kind: "associate", Seen: start.Add(3 * time.Second)})
	table.WirelessSnapshot("a", start.Add(4*time.Second), []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	if table.All()[0].APID != "b" {
		t.Fatal("snapshot stole client from another AP")
	}
	table.WirelessSnapshot("b", start.Add(5*time.Second), nil, map[[6]byte]bool{})
	if table.All()[0].State != "disconnected" {
		t.Fatal("departed station stayed online")
	}
}

func TestNativeWirelessSnapshotRetainsAPTrafficCounters(t *testing.T) {
	table := NewClientTable()
	at := time.Now()
	mac := [6]byte{2, 1, 2, 3, 4, 5}
	up := uint32(1234)
	table.StationEvent(ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, State: "connected", Kind: "statistics", Seen: at, Statistics: &ClientStatistics{NegotiatedMbps: 100, Bandwidth: 3, UpstreamKbps: &up}})
	ev := ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Statistics: &ClientStatistics{NegotiatedMbps: 1200, Bandwidth: -1}}
	table.WirelessSnapshot("a", at.Add(time.Second), []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	got := table.All()[0].Statistics
	if got.NegotiatedMbps != 1200 || got.Bandwidth != 3 || got.UpstreamKbps == nil || *got.UpstreamKbps != up {
		t.Fatal("snapshot erased CAPWAP counters", got)
	}
}
