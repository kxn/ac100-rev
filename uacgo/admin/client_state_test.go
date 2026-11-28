package admin

import (
	"context"
	"encoding/json"
	"fmt"
	"strings"
	"sync/atomic"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestNativeClientRefreshUsesTDCPNotPMKOrAXCapability(t *testing.T) {
	for _, supported := range []bool{true, false} {
		t.Run(fmt.Sprint(supported), func(t *testing.T) {
			var requests atomic.Int32
			m, _, ap := nativeModelAP(t, func(b json.RawMessage) json.RawMessage {
				requests.Add(1)
				if strings.Contains(string(b), "sta_list") {
					return json.RawMessage(`{"error_code":0,"wireless":{"sta_list":[]}}`)
				}
				return json.RawMessage(`{"error_code":0,"hosts_info":{"host_info":[]}}`)
			})
			// With TDCP49 alone, neither PMK66 nor AX70 may suppress reads.
			// Conversely those two bits alone do not announce TDCP support.
			if !supported {
				ap.GeneralCapabilities = []uint32{0, 0, 1<<2 | 1<<6}
			}
			m.refreshClientFacts(context.Background(), ap)
			want := int32(0)
			if supported {
				want = 2
			}
			if requests.Load() != want {
				t.Fatal("incorrect native transport capability gate", requests.Load(), want)
			}
		})
	}
}

func TestNativeSignalNeverInventsDBMOrErasesCAPWAPSample(t *testing.T) {
	for _, raw := range []string{"52", "-52", "0", "200", ""} {
		t.Run(raw, func(t *testing.T) {
			m, _ := testController(t)
			m.config.Services = []Service{{ID: "svc", SSID: "Office", Enabled: true, Radios: []uint8{2}}}
			m.assignments["a"] = map[string]map[uint8]uint8{"svc": {2: 1}}
			at := time.Now().Add(-time.Minute)
			connection := at.Add(-time.Minute)
			signal := int8(-74)
			mac := [6]byte{2, 1, 2, 3, 4, 5}
			m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: "a", RadioID: 2, WLANID: 1, ServiceID: "svc", Connection: connection, RSSI: &signal, Kind: "associate", Seen: at})
			stations := []byte(fmt.Sprintf(`{"error_code":0,"wireless":{"sta_list":[{"sta_list_1":{"mac":"02-01-02-03-04-05","radio_id":"2","ssid":"Office","rssi":%q}}]}}`, raw))
			started := at.Add(30 * time.Second)
			if err := m.mergeWirelessSnapshot(cweng.APStatus{ID: "a", ConnectedAt: connection}, started, stations, json.RawMessage(`{"error_code":0,"hosts_info":{"host_info":[]}}`)); err != nil {
				t.Fatal(err)
			}
			got := m.clients.All()[0]
			if got.RSSI == nil || *got.RSSI != -74 || !got.RSSIAt.Equal(at) {
				t.Fatal("raw native value replaced/erased/retimed CAPWAP measurement", got)
			}
			if raw != "" && (got.NativeSignal == nil || got.NativeSignal.Value != raw || !got.NativeSignal.At.Equal(started)) {
				t.Fatal("raw diagnostics lost", got)
			}
		})
	}
	// With no signed report, the raw native field must not fabricate a sample.
	m, _ := testController(t)
	m.config.Services = []Service{{ID: "svc", SSID: "Office", Enabled: true, Radios: []uint8{2}}}
	m.assignments["a"] = map[string]map[uint8]uint8{"svc": {2: 1}}
	if err := m.mergeWirelessSnapshot(cweng.APStatus{ID: "a"}, time.Now(), []byte(`{"error_code":0,"wireless":{"sta_list":[{"row":{"mac":"02-01-02-03-04-05","radio_id":"2","ssid":"Office","rssi":"52"}}]}}`), json.RawMessage(`{"error_code":0,"hosts_info":{"host_info":[]}}`)); err != nil {
		t.Fatal(err)
	}
	if got := m.clients.All()[0]; got.RSSI != nil || !got.RSSIAt.IsZero() || got.NativeSignal == nil {
		t.Fatal("invented signed measurement", got)
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
