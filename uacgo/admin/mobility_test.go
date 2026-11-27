package admin

import (
	"bytes"
	"reflect"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func TestRoamControlWireAndPolicyReferenceValidation(t *testing.T) {
	p := defaultMobility()
	if err := p.validate(Config{}); err != nil {
		t.Fatal(err)
	}
	r := p.Default
	r.R = true
	r.Band2G.RSSIKick = true
	// Independent field sequence from V6 @0x4e8a94, signed RSSI on the wire.
	want := []byte{1, 1, 1, 1, 181, 1, 176, 20, 0, 10, 1, 176, 0, 171, 20, 0, 10, 1, 8, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	if got := r.wire(0); !bytes.Equal(got, want) {
		t.Fatalf("roam control %x", got)
	}
	p.Balance = []BalanceRule{{ID: "bad", Name: "Bad", Clients: 20, Difference: 4, MaxFailures: 10, RSSI: -75, PolicyTarget: PolicyTarget{Groups: []string{"missing"}}}}
	if p.validate(Config{}) == nil {
		t.Fatal("missing group accepted")
	}
}
func TestBalanceUsesDiscoveredPeerAndBoundedRejections(t *testing.T) {
	m, _ := testController(t)
	s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1}}
	p := defaultMobility()
	p.Balance = []BalanceRule{{ID: "rule", Name: "Rule", Enabled: true, Clients: 2, Difference: 2, MaxFailures: 2, RSSI: -75}}
	m.config = Config{Services: []Service{s}, Mobility: &p}
	m.known = map[string]cweng.APStatus{"a": {ID: "a", Online: true}, "b": {ID: "b", Online: true}}
	for _, ap := range []string{"a", "b"} {
		if _, err := m.allocate(ap, s.ID, 1, 3); err != nil {
			t.Fatal(err)
		}
	}
	for i := byte(1); i <= 2; i++ {
		m.clients.StationEvent(cweng.ClientEvent{MAC: [6]byte{2, 0, 0, 0, 0, i}, APID: "a", RadioID: 1, WLANID: 1, State: "connected", Kind: "associate", Seen: time.Now()})
	}
	mac := [6]byte{2, 0, 0, 0, 1, 1}
	if !m.admitClient("a", 1, 1, mac, nil) {
		t.Fatal("unknown coverage rejected")
	}
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: "b", RadioID: 1, WLANID: 1, Kind: "probe", Seen: time.Now()})
	m.observeBalanceProbe("b", time.Now(), mac)
	for i := 0; i < 2; i++ {
		if m.admitClient("a", 1, 1, mac, nil) {
			t.Fatal("overloaded AP did not yield")
		}
	}
	if !m.admitClient("a", 1, 1, mac, nil) {
		t.Fatal("failure limit blocks client permanently")
	}
	if len(m.clients.All()) != 2 {
		t.Fatal("probe created online client")
	}
	m.known["b"] = cweng.APStatus{ID: "b", Online: false}
	m.balance.ForgetAP("b")
	if !m.admitClient("a", 1, 1, mac, nil) {
		t.Fatal("offline target caused rejection")
	}
}
func TestRoamingTriggerAcrossTwoUDPSimulatedAPs(t *testing.T) {
	m, e := testController(t)
	e.RegisterWstaHandlers(m.clients)
	f, a := newDeferredAP(t, e)
	g, b := newDeferredAP(t, e)
	a.GeneralCapabilities = []uint32{1 << 25}
	b.GeneralCapabilities = []uint32{1 << 25}
	a.MAC = a.ID
	b.MAC = b.ID
	bssid := [6]byte{2, 5, 4, 3, 2, 1}
	b.VAPStatistics = []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: bssid}}
	b.Capabilities = []cweng.RadioCapability{{RadioID: 1, Band: "2.4 GHz", TxStreams: 2, SupportAX: true}}
	b.RadioStatistics = []cweng.RadioStatistics{{APRadioStatistics: capwap.APRadioStatistics{Radio: 1, Channel: 6}}}
	m.known = map[string]cweng.APStatus{a.ID: a, b.ID: b}
	m.observeBSSIDLocations(b.ID, b.ConnectedAt, []capwap.BSSIDLocation{{Radio: 1, WLAN: 1, BSSID: bssid}})
	p := defaultMobility()
	s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1}}
	m.config = Config{Mobility: &p, Services: []Service{s}}
	for _, ap := range []string{a.ID, b.ID} {
		if _, err := m.allocate(ap, s.ID, 1, 2); err != nil {
			t.Fatal(err)
		}
	}
	mac := [6]byte{2, 1, 2, 3, 4, 5}
	rssi := int8(-80)
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: a.ID, RadioID: 1, WLANID: 1, State: "connected", Kind: "associate", RSSI: &rssi, Seen: time.Now()})
	trigger := capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -80, Neighbors: []capwap.RoamNeighborReport{{BSSID: bssid, RCPI: 100}}}}}
	other := mac
	other[5]++
	m.clients.StationEvent(cweng.ClientEvent{MAC: other, APID: a.ID, RadioID: 1, WLANID: 1, Kind: "associate", Seen: time.Now()})
	// Both rows enter the BSTM list. The second row has no resolvable
	// neighbors and must not inherit the first row's selected target.
	trigger.Stations = append(trigger.Stations, capwap.RoamTriggerStation{MAC: other, WLAN: 1, RSSI: -90, Neighbors: []capwap.RoamNeighborReport{{BSSID: [6]byte{2, 99}, RCPI: 100}}})
	pkt, _ := capwap.NewParsedPacket(9)
	pkt.Control.SeqNum = 5
	pkt.Elements = []capwap.Element{privateSetting(0x58, trigger.AssembleValue())}
	g.mu.Lock()
	g.rejectPrivate, g.rejectCount = 0x59, 1
	g.mu.Unlock()
	if _, err := f.conn.Write(pkt.Assemble()); err != nil {
		t.Fatal(err)
	}
	until := time.Now().Add(2 * time.Second)
	for {
		m.mu.Lock()
		_, pending := m.roamJobs[a.ID]
		handled := len(m.roamHistory) > 0 && m.status[a.ID+"/roaming-result"].State == "acknowledged" && m.status[b.ID+"/roaming-result"].State == "failed"
		m.mu.Unlock()
		if handled && !pending {
			break
		}
		if time.Now().After(until) {
			t.Fatal("roam submissions were not completed")
		}
		time.Sleep(time.Millisecond)
	}
	f.mu.Lock()
	deliveries := 0
	for _, p := range f.packets {
		for _, el := range p.Elements {
			if el.Type == 0x25 && len(el.Value) > 10 && el.Value[7] == 0x59 {
				deliveries++
			}
		}
	}
	f.mu.Unlock()
	if deliveries != 1 {
		t.Fatal("already acknowledged recipient was replayed", deliveries)
	}
	for _, fake := range []*deferredAP{f, g} {
		fake.mu.Lock()
		found := false
		for _, pkt := range fake.packets {
			for _, el := range pkt.Elements {
				if el.Type == 0x25 && len(el.Value) > 10 && el.Value[7] == 0x59 {
					v, err := capwap.ParsePrivRoamingCalcResult(el.Value[10:])
					if err != nil || len(v.Stations) != 2 || len(v.Stations[0].Candidates) != 1 || v.Stations[0].Candidates[0].BSSID != bssid || len(v.Stations[1].Candidates) != 0 || v.Stations[1].APBitmap[0] != 1 {
						fake.mu.Unlock()
						t.Fatalf("bad roam result %+v %v", v, err)
					}
					found = true
				}
			}
		}
		fake.mu.Unlock()
		if !found {
			t.Fatal("AP did not receive candidate result")
		}
	}
	if m.clients.All()[0].APID != a.ID {
		t.Fatal("selection fabricated handoff")
	}
	// Transport ACKs do not invent a firmware policy cooldown.
	m.mu.Lock()
	got := m.calculateRoamingLocked(a, trigger, time.Now())
	m.mu.Unlock()
	if len(got) != 1 || len(got[0].Stations) != 2 || len(got[0].Stations[0].Candidates) != 1 || len(got[0].Stations[1].Candidates) != 0 {
		t.Fatal("transport ACK changed candidate selection")
	}
}

func TestRoamingSignalConversionUsesWholeReport(t *testing.T) {
	// _bstm_ngr_generate inlined in 4e6564: unequivocal encodings end
	// detection; ambiguous even RCPI requires RSNI>=61; conflict discards it.
	for _, tc := range []struct {
		rows  []capwap.RoamNeighborReport
		want  []int
		valid bool
	}{
		{[]capwap.RoamNeighborReport{{RCPI: 100}, {RCPI: 170}}, []int{-60, -25}, true},
		{[]capwap.RoamNeighborReport{{RCPI: 220}, {RCPI: 170}}, []int{-36, -86}, true},
		{[]capwap.RoamNeighborReport{{RCPI: 170, RSNI: 61}}, []int{-25}, true},
		{[]capwap.RoamNeighborReport{{RCPI: 170, RSNI: 60}}, []int{-86}, true},
		{[]capwap.RoamNeighborReport{{RCPI: 170, RSNI: 61}, {RCPI: 171, RSNI: 61}}, nil, false},
	} {
		got, valid := neighborSignals(tc.rows)
		if valid != tc.valid || !reflect.DeepEqual(got, tc.want) {
			t.Fatal(tc, got, valid)
		}
	}
	// Candidate conversion uses the raw signal for rate, and a separate
	// -10dB margin (floored at -95) for selection, at the actual adapter.
	m, _ := testController(t)
	ap := cweng.APStatus{ID: "a", Online: true, Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "5 GHz", TxStreams: 2, SupportAC: true}}, RadioStatistics: []cweng.RadioStatistics{{APRadioStatistics: capwap.APRadioStatistics{Radio: 1, Channel: 36}}}}
	for _, tc := range []struct{ raw, want int8 }{{-60, -70}, {-86, -95}} {
		n, ok := m.candidateLocked([6]byte{2, 1, 2, 3, 4, 5}, ap, 1, 1, [6]byte{}, tc.raw, true)
		if !ok || n.RSSI != tc.want {
			t.Fatal(tc, n, ok)
		}
	}
}
