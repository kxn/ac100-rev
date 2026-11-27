package admin

import (
	"context"
	"encoding/binary"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/mobility"
)

func TestV4BalanceStrategyCallbackChangesAndResendsRoamingParameters(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{1 << 25}
	m.known[ap.ID] = ap
	p := defaultMobility()
	p.ModeSource = v4ModeSource
	m.config.Mobility = &p
	last := 0
	for _, tc := range []struct {
		family string
		on     bool
		want   byte
	}{{"v4", false, 2}, {"v4", true, 1}, {"v4", false, 2}, {"v6", true, 2}} {
		p.ModeSource = v4ModeSource
		if tc.family == "v6" {
			p.ModeSource = ""
		}
		p.Balance = []BalanceRule{{ID: "b", Name: "b", Enabled: tc.on, Clients: 1, Difference: 1, MaxFailures: 1, RSSI: -75}}
		m.applyMobility(context.Background(), ap, m.config)
		f.mu.Lock()
		strategies := []byte{}
		for _, packet := range f.packets[last:] {
			for _, el := range packet.Elements {
				if el.Type == 0x25 && len(el.Value) >= 46 && binary.BigEndian.Uint16(el.Value[6:]) == 0x57 {
					strategies = append(strategies, el.Value[30])
				}
			}
		}
		last = len(f.packets)
		f.mu.Unlock()
		if tc.family == "v6" {
			// The last V4 state already sent2; V6's balance-on keeps2.
			if len(strategies) != 0 {
				t.Fatal("V6 unnecessarily changed the57 strategy", strategies)
			}
		} else if len(strategies) != 1 || strategies[0] != tc.want {
			t.Fatal("V4 callback/update did not re-send57", tc, strategies)
		}
	}
}

func v4RoamingFixture(t *testing.T) (*Manager, cweng.APStatus, cweng.APStatus, [6]byte, time.Time) {
	t.Helper()
	m, source, target, mac, _ := rssiRoamingFixture(t)
	m.config.Mobility.ModeSource = v4ModeSource
	for _, id := range []string{source.ID, target.ID} {
		ap := m.known[id]
		ap.Capabilities = highPerformanceTestAP(id, 2).Capabilities
		m.known[id] = ap
	}
	source, target = m.known[source.ID], m.known[target.ID]
	bssid := [6]byte{2, 10, 5}
	m.observeAPStatistics(target.ID, target.ConnectedAt, capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 2, WLAN: 1, BSSID: bssid}}})
	m.observeRSSIStatistics(target.ID, target.ConnectedAt, capwap.PrivRssiStatistics{Stations: []capwap.RssiStatisticsStation{{MAC: mac, RSSI: [8]int8{0, -50}}}})
	return m, source, target, mac, time.Now()
}

func TestV4PolicyKeepsLegacySelectionAfterAutomaticDemotion(t *testing.T) {
	m, source, target, mac, now := v4RoamingFixture(t)
	report := capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -60}}}
	for _, mode := range []int{0, 1, 2} {
		m.config.Mobility.NetworkMode, m.config.Mobility.CurrentMode = mode, 2
		got := m.calculateRoamingLocked(source, report, now)
		if len(got) != 1 || len(got[0].Stations[0].Candidates) != 1 {
			t.Fatal("V4 lost unknown-rate candidate", mode, got)
		}
		candidate := got[0].Stations[0].Candidates[0]
		if got[0].APs[candidate.APIndex] != apMAC(target) || candidate.Radio != 2 {
			t.Fatal(got)
		}
	}
	m.config.Mobility.ModeSource = ""
	got := m.calculateRoamingLocked(source, report, now)
	if len(got) != 1 || len(got[0].Stations[0].Candidates) != 0 {
		t.Fatal("V6 must not inherit V4 selection of unknown rates at strong current RSSI", got)
	}
}

func TestV4PseudoAssociationEnforcesCapacityWithoutMovingStation(t *testing.T) {
	m, source, target, mac, now := v4RoamingFixture(t)
	advanced := defaultRadioAdvanced(target.Capabilities[1])
	advanced.MaxClients = 1
	m.config.Radios = []RadioSetting{{AP: target.ID, Radio: 2, Advanced: &advanced}}
	other := [6]byte{2, 9, 9, 9, 9, 9}
	m.clients.StationEvent(cweng.ClientEvent{MAC: other, APID: target.ID, Connection: target.ConnectedAt, RadioID: 2, WLANID: 1, Kind: "associate", Seen: now})
	report := capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -60}}}
	if got := m.calculateRoamingLocked(source, report, now); len(got) != 0 {
		t.Fatal("V4 full target must be rejected and an empty station omitted", got)
	}
	m.clients.StationEvent(cweng.ClientEvent{MAC: other, APID: target.ID, RadioID: 2, WLANID: 1, Kind: "disassociate", Seen: now})
	if got := m.calculateRoamingLocked(source, report, now); len(got) != 1 || len(got[0].Stations[0].Candidates) != 1 {
		t.Fatal("capacity release was not reflected", got)
	}
	for _, c := range m.clients.All() {
		if c.MAC == mac && c.APID != source.ID {
			t.Fatal("pseudo-association moved the station", c)
		}
	}
}

func TestV4PseudoAssociationRunsSharedBalanceRejectionCounter(t *testing.T) {
	m, source, target, mac, now := v4RoamingFixture(t)
	low := highPerformanceTestAP("02:00:00:00:00:03", 2)
	m.known[low.ID] = low
	m.config.Mobility.Balance = []BalanceRule{{ID: "b", Name: "b", Enabled: true, Clients: 1, Difference: 1, MaxFailures: 1, RSSI: -75}}
	m.balance.Probe(mobility.MAC(mac), low.ID, now)
	// Occupy target radio1; candidate radio2 still has capacity. Only the
	// balance callback can reject this candidate, and it consumes one try.
	m.clients.StationEvent(cweng.ClientEvent{MAC: [6]byte{2, 9}, APID: target.ID, Connection: target.ConnectedAt, RadioID: 1, WLANID: 1, Kind: "associate", Seen: now})
	report := capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -60}}}
	if got := m.calculateRoamingLocked(source, report, now); len(got) != 0 {
		t.Fatal("pseudo-association bypassed balancing", got)
	}
	if got := m.calculateRoamingLocked(source, report, now); len(got) != 1 {
		t.Fatal("rejection attempt was not shared with association balancing", got)
	}
}

func TestV4BSTMRetainsTriggerRSSIInsteadOfV6MeasuredCurrentBaseline(t *testing.T) {
	m, source, target, mac, now := v4RoamingFixture(t)
	currentBSSID, targetBSSID := [6]byte{2, 10, 1}, [6]byte{2, 10, 5}
	source.RadioStatistics = []cweng.RadioStatistics{{APRadioStatistics: capwap.APRadioStatistics{Radio: 1}}}
	m.known[source.ID] = source
	m.observeAPStatistics(source.ID, source.ConnectedAt, capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: currentBSSID}}})
	report := capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -50, Neighbors: []capwap.RoamNeighborReport{{BSSID: currentBSSID, RCPI: 50}, {BSSID: targetBSSID, RCPI: 100}}}}}
	if got := m.calculateRoamingLocked(source, report, now); len(got) != 0 {
		t.Fatal("V4 must retain triggerRSSI -50, rejecting the corrected -70 neighbor", got)
	}
	m.config.Mobility.ModeSource = ""
	got := m.calculateRoamingLocked(source, report, now)
	if len(got) != 1 || len(got[0].Stations[0].Candidates) != 1 || got[0].APs[got[0].Stations[0].Candidates[0].APIndex] != apMAC(target) {
		t.Fatal("V6 must use the first matching self measurement", got)
	}
}

func TestAssociationResultCodesFollowFirmwarePolicyFamily(t *testing.T) {
	for _, family := range []string{"v4", "v6"} {
		t.Run(family, func(t *testing.T) {
			m, _, target, mac, now := v4RoamingFixture(t)
			unavailable, rejected := uint32(0x25), uint32(0x25)
			if family == "v6" {
				m.config.Mobility.ModeSource = ""
				unavailable, rejected = 0x26, 0x27
			}
			low := highPerformanceTestAP("02:00:00:00:00:03", 2)
			m.known[low.ID] = low
			m.config.Mobility.Balance = []BalanceRule{{ID: "b", Enabled: true, Clients: 1, Difference: 1, MaxFailures: 1, RSSI: -75}}
			m.balance.Probe(mobility.MAC(mac), low.ID, now)
			m.clients.StationEvent(cweng.ClientEvent{MAC: [6]byte{2, 9}, APID: target.ID, Connection: target.ConnectedAt, RadioID: 1, WLANID: 1, Kind: "associate", Seen: now})
			if code := m.checkAssociation(target.ID, 2, 1, mac, nil, nil); code != rejected {
				t.Fatalf("balance result %x, want%x", code, rejected)
			}
			m.config.Services[0].Enabled = false
			if code := m.checkAssociation(target.ID, 2, 1, mac, nil, nil); code != unavailable {
				t.Fatalf("service result %x, want%x", code, unavailable)
			}
		})
	}
}

func TestV4AndV6BalanceUseTheirOwnMLOCountingSemantics(t *testing.T) {
	m, _, target, _, now := v4RoamingFixture(t)
	low := highPerformanceTestAP("02:00:00:00:00:03", 2)
	m.known[low.ID] = low
	m.config.Mobility.Balance = []BalanceRule{{ID: "b", Enabled: true, Clients: 2, Difference: 1, MaxFailures: 3, RSSI: -75}}
	root, peer, joining := [6]byte{2, 8}, [6]byte{2, 9}, [6]byte{2, 10}
	m.clients.StationEvent(cweng.ClientEvent{MAC: root, MLD: &root, MLOLinks: []capwap.AssociationLink{{MAC: root, Radio: 1, WLAN: 1}, {MAC: peer, Radio: 2, WLAN: 1}}, APID: target.ID, Connection: target.ConnectedAt, RadioID: 1, WLANID: 1, Kind: "associate", Seen: now})
	m.balance.Probe(mobility.MAC(joining), low.ID, now)
	if m.balanceAdmission(target.ID, joining, now) {
		t.Fatal("V4 callback counts root and peer DB rows, reaching2")
	}
	m.config.Mobility.ModeSource = ""
	if !m.balanceAdmission(target.ID, joining, now) {
		t.Fatal("V6 callback skips peer rows, leaving1")
	}
}
