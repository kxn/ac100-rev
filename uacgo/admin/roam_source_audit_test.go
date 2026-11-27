package admin

import (
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func TestRoamingUsesFiveGHzFirstBeforeFirmwareQuicksort(t *testing.T) {
	m, _ := testController(t)
	now := time.Now()
	mac := [6]byte{2, 1, 2, 3, 4, 5}
	source := cweng.APStatus{ID: "02:00:00:00:00:01", MAC: "02:00:00:00:00:01", Online: true, ConnectedAt: now}
	m.known[source.ID] = source
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: source.ID, RadioID: 1, WLANID: 1, State: "connected", Kind: "associate", Seen: now})
	report := capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -70}}}
	for i, band := range []string{"2.4 GHz", "5 GHz", "5 GHz"} {
		id := []string{"02:00:00:00:00:02", "02:00:00:00:00:03", "02:00:00:00:00:04"}[i]
		bssid := [6]byte{2, 10, 0, 0, 0, byte(i + 1)}
		ap := cweng.APStatus{ID: id, MAC: id, Online: true, Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: band, TxStreams: 2}}, RadioStatistics: []cweng.RadioStatistics{{APRadioStatistics: capwap.APRadioStatistics{Radio: 1}}}, VAPStatistics: []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: bssid}}}
		m.known[id] = ap
		rcpi := uint8(100)
		if i == 0 {
			rcpi = 80
		}
		report.Stations[0].Neighbors = append(report.Stations[0].Neighbors, capwap.RoamNeighborReport{BSSID: bssid, RCPI: rcpi})
	}
	// 4e5638 copies the 5G array at +0x1a8 before 2G at +0x28.
	// A 2G pivot before two equal 5G records reverses those records.
	got := m.calculateRoamingLocked(source, report, now)
	if len(got) != 1 || len(got[0].Stations[0].Candidates) < 2 {
		t.Fatal(got)
	}
	rows := got[0].Stations[0].Candidates
	if rows[0].BSSID[5] != 2 || rows[1].BSSID[5] != 3 {
		t.Fatal("firmware tie order changed", rows)
	}
}

func TestBalanceCountsMLDOnceAndExcludesPeerRows(t *testing.T) {
	m, _ := testController(t)
	now := time.Now()
	p := defaultMobility()
	p.Balance = []BalanceRule{{ID: "r", Name: "r", Enabled: true, Clients: 2, Difference: 1, MaxFailures: 2}}
	m.config.Mobility = &p
	m.known = map[string]cweng.APStatus{"a": {ID: "a", Online: true}, "b": {ID: "b", Online: true}}
	mld := [6]byte{2, 1, 0, 0, 0, 1}
	m.clients.StationEvent(cweng.ClientEvent{MAC: mld, MLD: &mld, APID: "a", RadioID: 1, WLANID: 1, State: "connected", Kind: "associate", Seen: now, MLOLinks: []capwap.AssociationLink{{MAC: [6]byte{2, 1, 0, 0, 0, 2}, Radio: 1, WLAN: 1}, {MAC: [6]byte{2, 1, 0, 0, 0, 3}, Radio: 2, WLAN: 1}}})
	if len(m.clients.All()) != 3 {
		t.Fatal("fixture did not create peer DB records")
	}
	joining := [6]byte{2, 2, 0, 0, 0, 1}
	m.balance.Probe(joining, "b", now)
	// balance callbacks 4ed3e4/4ed520 skip byte +0x91==2; peer
	// creation 766458 sets that byte. One MLD is below threshold2.
	if !m.balanceAdmission("a", joining, now) {
		t.Fatal("MLO peers inflated AP balance count")
	}
}

func TestRadioAutoWidthUsesWLANFallback(t *testing.T) {
	m, _ := testController(t)
	for _, band := range []string{"2.4 GHz", "5 GHz"} {
		ap := cweng.APStatus{ID: "a", Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: band, TxStreams: 2}}}
		b := radioBand(ap, 1)
		for _, tc := range []struct {
			width uint16
			want  uint8
		}{{0, 0}, {1, 1}, {2, 0}, {3, 2}, {5, 3}, {6, 0}} {
			want := tc.want
			if band == "5 GHz" && (tc.width == 2 || tc.width == 6) {
				want = 2
			}
			got := m.radioPHYLocked(ap, cweng.RadioStatistics{APRadioStatistics: capwap.APRadioStatistics{Radio: 1, Bandwidth: tc.width}}, b)
			if got.Bandwidth != want {
				t.Fatalf("%s auto observed width %d: got %d want %d", band, tc.width, got.Bandwidth, want)
			}
		}
	}
}

func TestRoamingMeshRateUsesRoleAndCurrentParent(t *testing.T) {
	m, _ := testController(t)
	target := cweng.APStatus{ID: "02:00:00:00:00:02", Online: true, MeshDevice: true, MeshParent: "02:00:00:00:00:01", Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "5 GHz", TxStreams: 2}}, RadioStatistics: []cweng.RadioStatistics{{APRadioStatistics: capwap.APRadioStatistics{Radio: 1, Bandwidth: 3}}}}
	mac, bssid := [6]byte{2, 1, 2, 3, 4, 5}, [6]byte{2, 2, 2, 3, 4, 5}
	// 4eb314 requires Mesh DB rate for roles4/6/8. Missing is rate0,
	// rather than silently treating the RE as an ordinary wired AP.
	n, ok := m.candidateLocked(mac, target, 1, 1, bssid, -60, true)
	if !ok || n.Rate != 0 {
		t.Fatal("missing Mesh rate became full WLAN rate", n, ok)
	}
	plain := target
	plain.MeshParent = ""
	base, ok := m.candidateLocked(mac, plain, 1, 1, bssid, -60, true)
	if !ok || base.Rate <= 100 {
		t.Fatal("fixture has no usable WLAN rate", base, ok)
	}
	m.known[target.MeshParent] = cweng.APStatus{ID: target.MeshParent, Mesh: &cweng.MeshReport{Nodes: []cweng.MeshNode{{MAC: target.ID, Rate: 100, Wireless: false}}}}
	m.known["old-parent"] = cweng.APStatus{ID: "old-parent", Mesh: &cweng.MeshReport{Nodes: []cweng.MeshNode{{MAC: target.ID, Rate: 4000, Wireless: true}}}}
	n, ok = m.candidateLocked(mac, target, 1, 1, bssid, -60, true)
	if !ok || n.Rate != base.Rate*100/(base.Rate+100) {
		t.Fatal("Mesh rate used link flag or stale parent", n, base)
	}
	for _, kind := range []uint8{1, 2, 3, 4} {
		ap := plain
		ap.ProductType = kind
		ap.Encapsulated = kind == 1
		n, ok := m.candidateLocked(mac, ap, 1, 1, bssid, -60, true)
		if !ok || (n.Rate != -1) != (kind == 3) {
			t.Fatal("role gate differs from 4eb314", kind, n, ok)
		}
	}
}

func TestRoamingCurrentUnsupportedRoleKeepsUnknownRate(t *testing.T) {
	m, _ := testController(t)
	mac := [6]byte{2, 1, 2, 3, 4, 5}
	now := time.Now()
	source := cweng.APStatus{ID: "02:00:00:00:00:01", MAC: "02:00:00:00:00:01", Online: true, ProductType: 1, Encapsulated: true,
		Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "5 GHz", TxStreams: 2}}, RadioStatistics: []cweng.RadioStatistics{{APRadioStatistics: capwap.APRadioStatistics{Radio: 1}}}}
	target := source
	target.ID, target.MAC, target.ProductType, target.Encapsulated = "02:00:00:00:00:02", "02:00:00:00:00:02", 0, false
	current, other := [6]byte{2, 10, 0, 0, 0, 1}, [6]byte{2, 10, 0, 0, 0, 2}
	source.VAPStatistics = []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: current}}
	target.VAPStatistics = []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: other}}
	m.known[source.ID], m.known[target.ID] = source, target
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: source.ID, RadioID: 1, WLANID: 1, Kind: "associate", Seen: now})
	got := m.calculateRoamingLocked(source, capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -50,
		Neighbors: []capwap.RoamNeighborReport{{BSSID: current, RCPI: 120}, {BSSID: other, RCPI: 140}}}}}, now)
	// 4e6564 stores -1 for the current BSS but skips -1 neighbors.
	// 4e5638 truncates current rate to uint16, so it cannot become zero
	// and spuriously satisfy the absolute/relative rate-gain gates.
	if len(got) != 1 || len(got[0].Stations[0].Candidates) != 0 {
		t.Fatal("unknown current rate became a zero-rate baseline", got)
	}
}

func TestPMKFailureDeletesStationOnItsCurrentAP(t *testing.T) {
	m, e := testController(t)
	e.RegisterWstaHandlers(m.clients)
	oldAP, a := newDeferredAP(t, e)
	requestingAP, b := newDeferredAP(t, e)
	m.known[a.ID], m.known[b.ID] = a, b
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: a.ID, Connection: a.ConnectedAt, RadioID: 2, WLANID: 1, State: "connected", Kind: "associate", Seen: time.Now()})
	request := capwap.PrivStaPMKReq{Operation: 1, Radio: 1, WLAN: 1, MAC: mac}
	p, _ := capwap.NewParsedPacket(9)
	p.Control.SeqNum = 44
	p.Elements = []capwap.Element{privateSetting(0x49, request.AssembleValue())}
	if _, err := requestingAP.conn.Write(p.Assemble()); err != nil {
		t.Fatal(err)
	}
	deadline := time.Now().Add(2 * time.Second)
	for {
		oldAP.mu.Lock()
		found := false
		for _, packet := range oldAP.packets {
			if packet.Control.MsgType != 25 {
				continue
			}
			for _, el := range packet.Elements {
				if el.Type == 0x12 {
					v, err := capwap.ParseDeleteStation(el.Value)
					if err != nil || v.RadioID != 2 || string(v.MAC) != string(mac[:]) {
						oldAP.mu.Unlock()
						t.Fatal("wrong station release", v, err)
					}
					found = true
				}
			}
		}
		oldAP.mu.Unlock()
		if found {
			break
		}
		if time.Now().After(deadline) {
			t.Fatal("PMK failure did not send Delete Station to current AP")
		}
		time.Sleep(time.Millisecond)
	}
	requestingAP.mu.Lock()
	for _, packet := range requestingAP.packets {
		if packet.Control.MsgType == 25 {
			requestingAP.mu.Unlock()
			t.Fatal("deleted station on requesting AP")
		}
	}
	requestingAP.mu.Unlock()
	for _, c := range m.clients.All() {
		if c.MAC == mac && c.State != "disconnected" {
			t.Fatal("PMK failure kept station connected")
		}
	}
}
