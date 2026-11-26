package admin

import (
	"testing"
	"time"
	"uacgo/cweng"
)

func TestClientRecoveryJoinsConfirmedWirelessMACsOnly(t *testing.T) {
	m, _ := testController(t)
	mac := [6]byte{2, 1, 2, 3, 4, 5}
	wired := [6]byte{2, 1, 2, 3, 4, 6}
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: "ap", RadioID: 2, WLANID: 1, Kind: "associate", Statistics: &cweng.ClientStatistics{}, Seen: time.Now()})
	stations := []byte(`{"error_code":0,"wireless":{"sta_list":[{"sta_list_1":{"mac":"02-01-02-03-04-05","connect_time":"123"}}]}}`)
	hosts := []byte(`{"error_code":0,"hosts_info":{"host_info":[{"host_info_1":{"mac":"02-01-02-03-04-05","ip":"192.0.2.20"}},{"host_info_2":{"mac":"02-01-02-03-04-06","ip":"192.0.2.21"}}]}}`)
	if err := m.mergeClientFacts("other", stations, hosts); err != nil {
		t.Fatal(err)
	}
	if m.clients.All()[0].IP != "" {
		t.Fatal("old AP changed client")
	}
	if err := m.mergeClientFacts("ap", stations, hosts); err != nil {
		t.Fatal(err)
	}
	rows := m.clients.All()
	if len(rows) != 1 || rows[0].MAC == wired || rows[0].IP != "192.0.2.20" || time.Since(rows[0].ConnectedAt) < 120*time.Second {
		t.Fatal(rows)
	}
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: "ap", RadioID: 2, WLANID: 1, Kind: "disassociate", State: "disconnected", Seen: time.Now()})
	_ = m.mergeClientFacts("ap", stations, hosts)
	if m.clients.All()[0].State != "disconnected" {
		t.Fatal("host data resurrected station")
	}
}

func TestAuthoritativeWirelessSnapshotMapsSSIDAndNeverAddsWiredHosts(t *testing.T) {
	m, _ := testController(t)
	ap := cweng.APStatus{ID: "a"}
	m.config.Services = []Service{{ID: "svc", SSID: "GoAC-Lab", Enabled: true, Radios: []uint8{2}}}
	m.assignments["a"] = map[string]map[uint8]uint8{"svc": {2: 1}}
	stations := []byte(`{"error_code":0,"wireless":{"count":{"sta_list":1},"sta_list":[{"sta_list_1":{"mac":"02-01-02-03-04-05","radio_id":"2","ssid":"GoAC%2DLab","vlan_id":"0","connect_time":"123","rssi":"-40"}}]}}`)
	hosts := []byte(`{"error_code":0,"hosts_info":{"host_info":[{"host_info_1":{"mac":"02-01-02-03-04-05","ip":"192.0.2.20"}},{"host_info_2":{"mac":"02-01-02-03-04-06","ip":"192.0.2.21"}}]}}`)
	if err := m.mergeWirelessSnapshot(ap, time.Now(), stations, hosts); err != nil {
		t.Fatal(err)
	}
	rows := m.clients.All()
	if len(rows) != 1 || rows[0].State != "connected" || rows[0].WLANID != 1 || rows[0].RadioID != 2 || rows[0].IP != "192.0.2.20" || rows[0].VLAN == nil || *rows[0].VLAN != 0 {
		t.Fatal(rows)
	}
	truncated := []byte(`{"error_code":0,"wireless":{"count":{"sta_list":1},"sta_list":[]}}`)
	if err := m.mergeWirelessSnapshot(ap, time.Now(), truncated, hosts); err == nil || m.clients.All()[0].State != "connected" {
		t.Fatal("truncated table deleted clients")
	}
}

func TestWirelessSnapshotMapsDynamicVLANPoolAndRejectsForeignVLAN(t *testing.T) {
	m, _ := testController(t)
	m.config.Services = []Service{{ID: "svc", SSID: "Pool", Enabled: true, Radios: []uint8{2}, Options: &WirelessOptions{VLANPool: 1}}}
	m.config.VLANPools = []VLANPool{{ID: 1, Name: "Pool", VLANs: "100-102,200"}}
	m.assignments["a"] = map[string]map[uint8]uint8{"svc": {2: 1}}
	stations := []byte(`{"error_code":0,"wireless":{"count":{"sta_list":2},"sta_list":[{"sta_list_1":{"mac":"02-01-02-03-04-05","radio_id":"2","ssid":"Pool","vlan_id":"101"}},{"sta_list_2":{"mac":"02-01-02-03-04-06","radio_id":"2","ssid":"Pool","vlan_id":"201"}}]}}`)
	hosts := []byte(`{"error_code":0,"hosts_info":{"host_info":[]}}`)
	if err := m.mergeWirelessSnapshot(cweng.APStatus{ID: "a"}, time.Now(), stations, hosts); err != nil {
		t.Fatal(err)
	}
	rows := m.clients.All()
	if len(rows) != 1 || rows[0].MAC[5] != 5 || rows[0].WLANID != 1 || rows[0].VLAN == nil || *rows[0].VLAN != 101 {
		t.Fatal("dynamic VLAN incorrectly mapped", rows)
	}
}

func TestWirelessSnapshotWithoutVLANMapsOnlyUnambiguousService(t *testing.T) {
	m, _ := testController(t)
	m.config.Services = []Service{{ID: "svc", SSID: "Legacy", Enabled: true, Radios: []uint8{2}}}
	m.assignments["a"] = map[string]map[uint8]uint8{"svc": {2: 1}}
	stations := []byte(`{"error_code":0,"wireless":{"sta_list":[{"sta_list_1":{"mac":"02-01-02-03-04-05","radio_id":"2","ssid":"Legacy","rssi":"-51"}}]}}`)
	hosts := []byte(`{"error_code":0,"hosts_info":{"host_info":[]}}`)
	if err := m.mergeWirelessSnapshot(cweng.APStatus{ID: "a"}, time.Now(), stations, hosts); err != nil {
		t.Fatal(err)
	}
	rows := m.clients.All()
	if len(rows) != 1 || rows[0].ServiceID != "svc" || rows[0].VLAN != nil || rows[0].State != "connected" {
		t.Fatal("missing VLAN lost a confirmed client or invented an untagged VLAN", rows)
	}
	// The same SSID is also served on another VLAN: missing VLAN must not
	// pick either identity, while an explicit VLAN still disambiguates it.
	m.clients = cweng.NewClientTable()
	m.config.Services = append(m.config.Services, Service{ID: "other", SSID: "Legacy", Enabled: true, Radios: []uint8{2}, Bindings: []ServiceBinding{{AP: "a", Radio: 2, VLAN: 100}}})
	m.assignments["a"]["other"] = map[uint8]uint8{2: 2}
	if err := m.mergeWirelessSnapshot(cweng.APStatus{ID: "a"}, time.Now(), stations, hosts); err != nil || len(m.clients.All()) != 0 {
		t.Fatal("ambiguous SSID was assigned to an arbitrary service", err, m.clients.All())
	}
	stations = []byte(`{"error_code":0,"wireless":{"sta_list":[{"sta_list_1":{"mac":"02-01-02-03-04-05","radio_id":"2","ssid":"Legacy","vlan_id":"100"}}]}}`)
	if err := m.mergeWirelessSnapshot(cweng.APStatus{ID: "a"}, time.Now(), stations, hosts); err != nil {
		t.Fatal(err)
	}
	rows = m.clients.All()
	if len(rows) != 1 || rows[0].ServiceID != "other" || rows[0].VLAN == nil || *rows[0].VLAN != 100 {
		t.Fatal("explicit VLAN did not identify the matching service", rows)
	}
}
