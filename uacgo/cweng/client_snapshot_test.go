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
	table.WirelessSnapshot("a", time.Time{}, start, []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	if c := table.All(); len(c) != 1 || c[0].State != "connected" {
		t.Fatal(c)
	}
	// A concurrent AP event after the query started wins over its older answer.
	table.StationEvent(ClientEvent{APID: "a", MAC: mac, RadioID: 1, WLANID: 1, State: "disconnected", Kind: "disassociate", Seen: start.Add(time.Second)})
	table.WirelessSnapshot("a", time.Time{}, start, []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	if table.All()[0].State != "disconnected" {
		t.Fatal("stale query resurrected client")
	}
	table.WirelessSnapshot("a", time.Time{}, start.Add(2*time.Second), []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	if table.All()[0].State != "connected" {
		t.Fatal("fresh authoritative wireless membership not restored")
	}
	table.StationEvent(ClientEvent{APID: "b", MAC: mac, RadioID: 2, WLANID: 1, State: "connected", Kind: "associate", Seen: start.Add(3 * time.Second)})
	table.WirelessSnapshot("a", time.Time{}, start.Add(4*time.Second), []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	if table.All()[0].APID != "b" {
		t.Fatal("snapshot stole client from another AP")
	}
	table.WirelessSnapshot("b", time.Time{}, start.Add(5*time.Second), nil, map[[6]byte]bool{})
	if table.All()[0].State != "disconnected" {
		t.Fatal("departed station stayed online")
	}
}

func TestNativeWirelessSnapshotRetainsAPTrafficCounters(t *testing.T) {
	table := NewClientTable()
	at := time.Now()
	mac := [6]byte{2, 1, 2, 3, 4, 5}
	up := uint32(1234)
	table.StationEvent(ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Kind: "associate", Seen: at})
	table.StationEvent(ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, State: "connected", Kind: "statistics", Seen: at, Statistics: &ClientStatistics{NegotiatedMbps: 100, Bandwidth: 3, UpstreamKbps: &up}})
	ev := ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, NativeRates: &ClientNativeRates{TX: "1200", RX: "0", At: at.Add(time.Second)}}
	table.WirelessSnapshot("a", time.Time{}, at.Add(time.Second), []ClientEvent{ev}, map[[6]byte]bool{mac: true})
	got := table.All()[0].Statistics
	if got.NegotiatedMbps != 100 || got.Bandwidth != 3 || got.UpstreamKbps == nil || *got.UpstreamKbps != up {
		t.Fatal("snapshot erased CAPWAP counters", got)
	}
}

func TestWirelessSnapshotRequiresExactSessionEvenForEmptyTable(t *testing.T) {
	table := NewClientTable()
	old := time.Now().Add(-time.Minute)
	current := old.Add(10 * time.Second)
	started := current.Add(time.Second)
	table.APState("a", current, true, current)
	ev := ClientEvent{APID: "a", Connection: current, MAC: [6]byte{2, 1, 2, 3, 4, 5}, RadioID: 1, WLANID: 1, Kind: "associate", Seen: current}
	table.StationEvent(ev)
	// A stale APStatus captured before reconnect can start a read afterward.
	// Wall-clock freshness alone cannot authorize that old session's result.
	table.WirelessSnapshot("a", old, started, nil, map[[6]byte]bool{})
	if rows := table.All(); len(rows) != 1 || rows[0].State != "connected" {
		t.Fatal("old-session empty table disconnected current client", rows)
	}
	table.WirelessSnapshot("a", current, started, nil, map[[6]byte]bool{})
	if table.All()[0].State != "disconnected" {
		t.Fatal("current-session empty table was ignored")
	}
}

func TestWirelessSnapshotNeverCarriesSignalAcrossIdentityOrReconnect(t *testing.T) {
	at := time.Now()
	connection := at.Add(-time.Minute)
	for _, tc := range []string{"same", "radio", "wlan", "service", "session", "disconnected"} {
		t.Run(tc, func(t *testing.T) {
			table := NewClientTable()
			signal := int8(-74)
			mac := [6]byte{2, 1, 2, 3, 4, 5}
			old := ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, ServiceID: "office", Connection: connection, Kind: "associate", Seen: at, RSSI: &signal, Statistics: &ClientStatistics{NegotiatedMbps: 1201}}
			table.StationEvent(old)
			if tc == "disconnected" {
				table.StationEvent(ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, Connection: connection, Kind: "disassociate", Seen: at.Add(time.Second)})
			}
			next := ClientEvent{MAC: mac, APID: "a", RadioID: 1, WLANID: 1, ServiceID: "office", Connection: connection}
			switch tc {
			case "radio":
				next.RadioID = 2
			case "wlan":
				next.WLANID = 2
			case "service":
				next.ServiceID = "guest"
			case "session":
				next.Connection = connection.Add(time.Second)
			}
			table.WirelessSnapshot("a", next.Connection, at.Add(2*time.Second), []ClientEvent{next}, map[[6]byte]bool{mac: true})
			got := table.All()[0]
			if tc == "same" {
				if got.RSSI == nil || *got.RSSI != -74 || !got.RSSIAt.Equal(at) {
					t.Fatal("lost measurement or retimed it", got)
				}
				if got.Statistics == nil || got.Statistics.NegotiatedMbps != 1201 {
					t.Fatal("lost typed statistics", got)
				}
			} else if got.RSSI != nil || !got.RSSIAt.IsZero() || got.Statistics != nil {
				t.Fatal("carried old signal across connection identity", got)
			}
		})
	}
}
