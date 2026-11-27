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

func rssiRoamingFixture(t *testing.T) (*Manager, cweng.APStatus, cweng.APStatus, [6]byte, time.Time) {
	t.Helper()
	m, _ := testController(t)
	now := time.Now()
	source := cweng.APStatus{ID: "02:00:00:00:00:01", MAC: "02:00:00:00:00:01", Online: true, ConnectedAt: now.Add(-time.Second), Radios: 2}
	target := source
	target.ID, target.MAC = "02:00:00:00:00:02", "02:00:00:00:00:02"
	target.Capabilities = []cweng.RadioCapability{{RadioID: 1, Band: "2.4 GHz"}, {RadioID: 2, Band: "5 GHz"}}
	target.RadioStatistics = []cweng.RadioStatistics{{APRadioStatistics: capwap.APRadioStatistics{Radio: 1}}, {APRadioStatistics: capwap.APRadioStatistics{Radio: 2}}}
	m.known[source.ID], m.known[target.ID] = source, target
	p := defaultMobility()
	p.Default.Statistics = true
	s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1, 2}}
	m.config = Config{Mobility: &p, Services: []Service{s}}
	for _, ap := range []string{source.ID, target.ID} {
		for _, radio := range []uint8{1, 2} {
			if _, err := m.allocate(ap, s.ID, radio, 8); err != nil {
				t.Fatal(err)
			}
		}
	}
	mac := [6]byte{2, 1, 2, 3, 4, 5}
	m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: source.ID, Connection: source.ConnectedAt, RadioID: 1, WLANID: 1, Kind: "associate", Seen: now})
	return m, source, target, mac, now
}

func TestNonBSTMPartialVAPReportKeepsFallbackSlotAndOriginalGates(t *testing.T) {
	m, source, target, mac, now := rssiRoamingFixture(t)
	a, b, c := [6]byte{2, 10, 1}, [6]byte{2, 10, 2}, [6]byte{2, 10, 3}
	m.observeAPStatistics(target.ID, target.ConnectedAt, capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: a}, {Radio: 2, WLAN: 1, BSSID: b}}})
	m.observeAPStatistics(target.ID, target.ConnectedAt, capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: c}}})
	m.observeRSSIStatistics(target.ID, target.ConnectedAt, capwap.PrivRssiStatistics{Stations: []capwap.RssiStatisticsStation{{MAC: mac, RSSI: [8]int8{0, -50}}}})
	now = time.Now()
	for _, tc := range []struct {
		name    string
		current int8
		load    uint8
		delta   time.Duration
		offline bool
		want    int
	}{
		{"weak-unknown-rate-high-load", -86, 99, 0, false, 1},
		{"equal-current-threshold", -85, 0, 0, false, 0},
		{"strong-current-unknown-rate", -60, 0, 0, false, 0},
		{"expired-neighbor", -90, 0, 46 * time.Second, false, 0},
		{"offline-target", -90, 0, 0, true, 0},
	} {
		t.Run(tc.name, func(t *testing.T) {
			ap := m.known[target.ID]
			ap.Online = !tc.offline
			ap.RadioStatistics[1].ChannelLoad = tc.load
			m.known[target.ID] = ap
			got := m.calculateRoamingLocked(source, capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: tc.current}}}, now.Add(tc.delta))
			if len(got) != 1 || len(got[0].Stations[0].Candidates) != tc.want {
				t.Fatal(got)
			}
			if tc.want > 0 && got[0].Stations[0].Candidates[0].BSSID != b {
				t.Fatal("omitted slot was lost or guessed", got)
			}
		})
	}
}

func TestRoamingNeverGuessesWLANFromNativeSSIDTelemetry(t *testing.T) {
	m, source, target, mac, now := rssiRoamingFixture(t)
	bssid := [6]byte{2, 10, 1}
	target.Telemetry = &cweng.WirelessTelemetry{VAPs: []cweng.WirelessVAP{{RadioID: 1, SSID: "Office", BSSID: "02:0a:01:00:00:00"}}}
	m.known[target.ID] = target
	m.stationStatistics.UpdateNeighbor(mobility.MAC(mac), mobility.RSSINeighbor{AP: target.ID, Radio: 1, WLAN: 1, RSSI: -50, At: now}, time.Minute)
	for _, neighbors := range [][]capwap.RoamNeighborReport{nil, {{BSSID: bssid, RCPI: 120}}} {
		got := m.calculateRoamingLocked(source, capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -90, Neighbors: neighbors}}}, now)
		if len(got) != 1 || len(got[0].APs) != 1 || len(got[0].Stations[0].Candidates) != 0 {
			t.Fatal("native SSID invented BSSID/slot facts", got)
		}
	}
}

func TestRoamingSlotReleaseCannotReviveFromDisplayOrReusedWLAN(t *testing.T) {
	m, _, target, _, now := rssiRoamingFixture(t)
	bssid := [6]byte{2, 10, 1}
	report := capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 2, WLAN: 1, BSSID: bssid}}}
	m.observeAPStatistics(target.ID, target.ConnectedAt, report)
	if err := m.stageWLAN(target.ID, "office", 2, 1, false); err != nil {
		t.Fatal(err)
	}
	m.settling[target.ID] = commitSettlement{Version: "delete", Connection: target.ConnectedAt, Ready: now}
	if err := m.settleWLANs(target.ID, "delete", target.ConnectedAt, now); err != nil {
		t.Fatal(err)
	}
	if _, ok := m.bssidLocations[bssid]; ok {
		t.Fatal("released slot retained BSSID hash")
	}
	if _, ok := m.vapFacts[vapSlot{target.ID, 2, 1}]; ok {
		t.Fatal("released slot retained ready SSID statistics")
	}
	// Raw session/display caches can still describe the previous report.
	if len(m.known[target.ID].VAPStatistics) != 1 {
		t.Fatal("fixture lost raw report")
	}
	m.observeAPStatistics(target.ID, target.ConnectedAt, report)
	if _, _, _, ok := m.findBSSIDLocked(bssid); ok {
		t.Fatal("unbound slot was recreated by a late report")
	}
	other := Service{ID: "other", SSID: "Other", Security: "open", Enabled: true, Radios: []uint8{2}}
	m.config.Services = append(m.config.Services, other)
	if slot, err := m.allocate(target.ID, other.ID, 2, 8); err != nil || slot != 1 {
		t.Fatal(slot, err)
	}
	if _, _, _, ok := m.findBSSIDLocked(bssid); ok {
		t.Fatal("slot reuse inherited the previous BSSID")
	}
	m.observeAPStatistics(target.ID, target.ConnectedAt, report)
	if _, _, _, ok := m.findBSSIDLocked(bssid); !ok {
		t.Fatal("fresh valid slot report was not activated")
	}
}

func TestRoamingRadioDisableRequiresFreshAPStatisticsAfterEnable(t *testing.T) {
	m, _, target, mac, _ := rssiRoamingFixture(t)
	bssid := [6]byte{2, 10, 1}
	report := capwap.PrivApStatistics{Radios: []capwap.APRadioStatistics{{Radio: 2, Bandwidth: 3}}, VAPs: []capwap.APVAPStatistics{{Radio: 2, WLAN: 1, BSSID: bssid}}}
	m.observeAPStatistics(target.ID, target.ConnectedAt, report)
	for _, on := range []bool{false, true} {
		on := on
		next := m.config
		next.Radios = []RadioSetting{{AP: target.ID, Radio: 2, Enabled: &on}}
		m.mu.Lock()
		err := m.persistConfigLocked(next, managementUser)
		m.mu.Unlock()
		if err != nil {
			t.Fatal(err)
		}
		if _, ok := m.candidateLocked(mac, m.known[target.ID], 2, 1, bssid, -50, true); ok {
			t.Fatal("disabled or not-ready radio entered candidates", on)
		}
	}
	// 53/58 can refresh noise/load only for an already ready radio; a UI
	// refresh or a late channel-load report cannot replace the missing54.
	m.observeRSSIStatistics(target.ID, target.ConnectedAt, capwap.PrivRssiStatistics{})
	if _, ok := m.candidateLocked(mac, m.known[target.ID], 2, 1, bssid, -50, true); ok {
		t.Fatal("RSSI report resurrected radio readiness")
	}
	m.observeAPStatistics(target.ID, target.ConnectedAt, report)
	if _, ok := m.candidateLocked(mac, m.known[target.ID], 2, 1, bssid, -50, true); !ok {
		t.Fatal("fresh AP statistics failed to restore readiness")
	}
}

func TestRoamingEmptyNeighborsNeverReuseAnotherStationCandidates(t *testing.T) {
	m, source, target, mac, now := rssiRoamingFixture(t)
	bssid := [6]byte{2, 10, 1}
	target.VAPStatistics = []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: bssid}}
	m.known[target.ID] = target
	m.observeAPStatistics(target.ID, target.ConnectedAt, capwap.PrivApStatistics{VAPs: target.VAPStatistics})
	m.stationStatistics.UpdateNeighbor(mobility.MAC(mac), mobility.RSSINeighbor{AP: target.ID, Radio: 1, WLAN: 1, RSSI: -50, At: now}, time.Minute)
	other := mac
	other[5]++
	m.clients.StationEvent(cweng.ClientEvent{MAC: other, APID: source.ID, RadioID: 1, WLANID: 1, Kind: "associate", Seen: now})
	second := capwap.RoamTriggerStation{MAC: other, WLAN: 1, RSSI: -30}
	r := capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -90}, second}}
	got := m.calculateRoamingLocked(source, r, now)
	if len(got) != 1 || len(got[0].Stations) != 2 || len(got[0].Stations[0].Candidates) != 1 || len(got[0].Stations[1].Candidates) != 0 {
		t.Fatal("station results are not independent", got)
	}
	if len(m.roamHistory[len(m.roamHistory)-1].Candidates) != 0 || got[0].Stations[1].APBitmap[0] != 1 {
		t.Fatal("history or bitmap retained another station's candidates")
	}
	// A later report must also remain independent.
	r.Stations = []capwap.RoamTriggerStation{second}
	got = m.calculateRoamingLocked(source, r, now)
	if len(got[0].Stations[0].Candidates) != 0 {
		t.Fatal("selection leaked into the next packet", got)
	}
}

func TestRoamingStationResultsStayIsolatedAcrossPacketBoundary(t *testing.T) {
	m, source, target, mac, now := rssiRoamingFixture(t)
	bssid := [6]byte{2, 10, 1}
	m.observeAPStatistics(target.ID, target.ConnectedAt, capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: bssid}}})
	m.stationStatistics.UpdateNeighbor(mobility.MAC(mac), mobility.RSSINeighbor{AP: target.ID, Radio: 1, WLAN: 1, RSSI: -50, At: now}, time.Minute)
	report := capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -90}}}
	for i := 1; i < 130; i++ {
		other := mac
		other[4], other[5] = 0x80, byte(i)
		m.clients.StationEvent(cweng.ClientEvent{MAC: other, APID: source.ID, RadioID: 1, WLANID: 1, Kind: "associate", Seen: now})
		report.Stations = append(report.Stations, capwap.RoamTriggerStation{MAC: other, WLAN: 1, RSSI: -30})
	}
	got := m.calculateRoamingLocked(source, report, now)
	if len(got) != 2 || len(got[0].Stations) != 128 || len(got[1].Stations) != 2 {
		t.Fatal("report truncated or incorrectly chunked", len(got))
	}
	for packet, result := range got {
		for row, station := range result.Stations {
			want := 0
			if packet == 0 && row == 0 {
				want = 1
			}
			if len(station.Candidates) != want {
				t.Fatal("station selection escaped its lifetime", packet, row, station)
			}
		}
	}
}

func TestRoamingInvalidOrMissingNeighborsAreIsolatedAcrossServices(t *testing.T) {
	for _, mode := range []string{"no-rssi-history", "unknown-bssid", "conflicting-signal-encoding"} {
		t.Run(mode, func(t *testing.T) {
			m, source, target, mac, now := rssiRoamingFixture(t)
			bssid := [6]byte{2, 10, 1}
			m.observeAPStatistics(target.ID, target.ConnectedAt, capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: bssid}}})
			m.stationStatistics.UpdateNeighbor(mobility.MAC(mac), mobility.RSSINeighbor{AP: target.ID, Radio: 1, WLAN: 1, RSSI: -50, At: now}, time.Minute)
			guest := Service{ID: "guest", SSID: "Guest", Security: "open", Enabled: true, Radios: []uint8{1}}
			m.config.Services = append(m.config.Services, guest)
			slot, err := m.allocate(source.ID, guest.ID, 1, 8)
			if err != nil {
				t.Fatal(err)
			}
			other := mac
			other[5]++
			m.clients.StationEvent(cweng.ClientEvent{MAC: other, APID: source.ID, RadioID: 1, WLANID: uint32(slot), Kind: "associate", Seen: now})
			second := capwap.RoamTriggerStation{MAC: other, WLAN: slot, RSSI: -90}
			switch mode {
			case "unknown-bssid":
				second.Neighbors = []capwap.RoamNeighborReport{{BSSID: [6]byte{2, 99}, RCPI: 120}}
			case "conflicting-signal-encoding":
				second.Neighbors = []capwap.RoamNeighborReport{{BSSID: bssid, RCPI: 140, RSNI: 61}, {BSSID: bssid, RCPI: 141}}
			}
			got := m.calculateRoamingLocked(source, capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -90}, second}}, now)
			if len(got) != 1 || len(got[0].Stations) != 2 || len(got[0].Stations[0].Candidates) != 1 || len(got[0].Stations[1].Candidates) != 0 || got[0].Stations[1].APBitmap[0] != 1 {
				t.Fatal("invalid/empty guest data inherited office candidates", got)
			}
		})
	}
}

func TestRoamingCapabilities25And72AreIndependent(t *testing.T) {
	for _, mask := range []uint8{0, 1, 2, 3} {
		t.Run(string(rune('0'+mask)), func(t *testing.T) {
			m, e := testController(t)
			fake, ap := newDeferredAP(t, e)
			ap.GeneralCapabilities = []uint32{0, 0, 0}
			if mask&1 != 0 {
				ap.GeneralCapabilities[0] = 1 << 25
			}
			if mask&2 != 0 {
				ap.GeneralCapabilities[2] = 1 << 8
			}
			m.known[ap.ID] = ap
			ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), time.Second)
			defer cancel()
			m.applyMobility(ctx, ap, m.config)
			seen := map[uint16]bool{}
			fake.mu.Lock()
			for _, packet := range fake.packets {
				for _, el := range packet.Elements {
					if el.Type == 0x25 && len(el.Value) >= 10 {
						seen[binary.BigEndian.Uint16(el.Value[6:])] = true
					}
				}
			}
			fake.mu.Unlock()
			if seen[0x57] != (mask&1 != 0) || seen[0x9d] != (mask&2 != 0) {
				t.Fatal("capability gate crossed", mask, seen)
			}
		})
	}
}

func TestRoamingSilenceUsesConfiguredUCIEquivalentValues(t *testing.T) {
	m, e := testController(t)
	fake, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{0, 0, 1 << 8}
	m.known[ap.ID] = ap
	p := defaultMobility()
	m.config.Mobility = &p
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), time.Second)
	defer cancel()
	m.applyMobility(ctx, ap, m.config)
	p.Silence = &RoamSilence{Count: 7, Seconds: 61}
	m.applyMobility(ctx, ap, m.config)
	fake.mu.Lock()
	defer fake.mu.Unlock()
	var values [][]byte
	for _, packet := range fake.packets {
		for _, el := range packet.Elements {
			if el.Type == 0x25 && len(el.Value) >= 10 && binary.BigEndian.Uint16(el.Value[6:]) == 0x9d {
				values = append(values, el.Value[10:])
			}
		}
	}
	if len(values) != 2 || string(values[0]) != string([]byte{3, 0, 30}) || string(values[1]) != string([]byte{7, 0, 61}) {
		t.Fatal("silence change failed to update configuration identity/wire", values)
	}
}

func TestRoamingCapability25FiltersRecipientsNotCandidateRanking(t *testing.T) {
	for _, receives := range []bool{false, true} {
		t.Run(map[bool]string{false: "no25", true: "with25"}[receives], func(t *testing.T) {
			m, e := testController(t)
			f, a := newDeferredAP(t, e)
			_, b := newDeferredAP(t, e)
			f.mu.Lock()
			f.dropAll = true
			f.mu.Unlock() // keep immutable job available for inspection
			a.GeneralCapabilities = []uint32{1 << 25}
			b.GeneralCapabilities = []uint32{0}
			if receives {
				b.GeneralCapabilities[0] = 1 << 25
			}
			b.Capabilities = []cweng.RadioCapability{{RadioID: 1, Band: "2.4 GHz", TxStreams: 2}}
			b.RadioStatistics = []cweng.RadioStatistics{{APRadioStatistics: capwap.APRadioStatistics{Radio: 1}}}
			m.known[a.ID], m.known[b.ID] = a, b
			bssid := [6]byte{2, 10, 2}
			m.observeBSSIDLocations(b.ID, b.ConnectedAt, []capwap.BSSIDLocation{{Radio: 1, WLAN: 1, BSSID: bssid}})
			mac := [6]byte{2, 1, 2, 3, 4, 5}
			m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: a.ID, RadioID: 1, WLANID: 1, Kind: "associate", Seen: time.Now()})
			m.queueRoaming(a.ID, a.ConnectedAt, capwap.PrivRoamingTrigger{Radio: 1, Stations: []capwap.RoamTriggerStation{{MAC: mac, WLAN: 1, RSSI: -70, Neighbors: []capwap.RoamNeighborReport{{BSSID: bssid, RCPI: 120}}}}})
			m.mu.Lock()
			defer m.mu.Unlock()
			jobs := m.roamJobs[a.ID]
			if len(jobs) != 1 || len(jobs[0].Result.Stations[0].Candidates) != 1 {
				t.Fatal("capability25 changed ranking", jobs)
			}
			found := false
			for _, target := range jobs[0].Targets {
				if target.ID == b.ID {
					found = true
				}
			}
			if found != receives {
				t.Fatal("recipient gate differs from original get_addr_by_capacity", found, receives)
			}
		})
	}
}

func TestBandNavigationModelFailuresCannotMasqueradeAsLegacySuccess(t *testing.T) {
	for _, tc := range []struct {
		name, reply    string
		legacy, failed bool
	}{
		{"unsupported-instruction", `{"error_code":-40106}`, true, false},
		{"unsupported-event", `{"error_code":-40104}`, true, false},
		{"unsupported-operation", `{"error_code":-40105}`, true, false},
		{"busy", `{"error_code":-40109}`, false, true},
		{"forbidden", `{"error_code":-40107}`, false, true},
		{"bad-argument", `{"error_code":-40209}`, false, true},
		{"empty-model", `{"error_code":0,"apmng_band_navigation":{"settings":{}}}`, false, true},
		{"timeout", "", false, true},
	} {
		t.Run(tc.name, func(t *testing.T) {
			m, e := testController(t)
			e.RegisterRPCHandlers()
			fake, ap := newDeferredAP(t, e)
			ap.GeneralCapabilities = []uint32{1 << 3, 0, 1 << 6}
			m.known[ap.ID] = ap
			fake.mu.Lock()
			fake.onCommand = func(packet *capwap.ParsedPacket) {
				if tc.reply == "" {
					return
				}
				for _, el := range packet.Elements {
					if el.Type != 0x25 || len(el.Value) < 19 || binary.BigEndian.Uint16(el.Value[6:]) != 0x83 {
						continue
					}
					v := binary.BigEndian.AppendUint32(nil, binary.BigEndian.Uint32(el.Value[10:]))
					v = binary.BigEndian.AppendUint32(v, uint32(len(tc.reply)))
					v = append(v, 0)
					v = append(v, tc.reply...)
					p, _ := capwap.NewParsedPacket(9)
					p.Control.SeqNum = 80
					p.Elements = []capwap.Element{privateSetting(0x83, v)}
					fake.conn.Write(p.Assemble())
				}
			}
			fake.mu.Unlock()
			ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), time.Second)
			defer cancel()
			m.applyBandNavigation(ctx, ap, &BandNavigation{Enabled: true, Threshold5G: 20, Difference: 4, MaxFailures: 10})
			state := m.status[ap.ID+"/band-navigation"]
			if (state.State == "failed") != tc.failed {
				t.Fatal("model error became successful configuration", state)
			}
			fake.mu.Lock()
			legacy := false
			for _, p := range fake.packets {
				for _, el := range p.Elements {
					if el.Type == 0x25 && len(el.Value) >= 10 && binary.BigEndian.Uint16(el.Value[6:]) == 0x3a {
						legacy = true
					}
				}
			}
			fake.mu.Unlock()
			if legacy != tc.legacy {
				t.Fatal("fallback hid a model failure", state, legacy)
			}
		})
	}
}

func TestPMKWireOperationsCapabilityAndFailureResults(t *testing.T) {
	for _, special := range []bool{false, true} {
		t.Run(map[bool]string{false: "without66", true: "with66"}[special], func(t *testing.T) {
			m, e := testController(t)
			e.RegisterWstaHandlers(m.clients)
			fake, ap := newDeferredAP(t, e, func(p *capwap.ParsedPacket) {
				out := p.Elements[:0]
				for _, el := range p.Elements {
					if el.Type != 0x32 {
						out = append(out, el)
					}
				}
				v := make([]byte, 12)
				if special {
					v[11] = 4
				}
				p.Elements = append(out, capwap.Element{Type: 0x32, Value: v})
			})
			m.known[ap.ID] = ap
			p := defaultMobility()
			s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1}}
			m.config = Config{Mobility: &p, Services: []Service{s}}
			if _, err := m.allocate(ap.ID, s.ID, 1, 8); err != nil {
				t.Fatal(err)
			}
			mac := [6]byte{2, 3, 4, 5, 6, 7}
			seq := uint8(40)
			request := func(v capwap.PrivStaPMKReq) *capwap.PrivStaPMKReq {
				t.Helper()
				seq++
				p, _ := capwap.NewParsedPacket(9)
				p.Control.SeqNum = seq
				p.Elements = []capwap.Element{privateSetting(0x49, v.AssembleValue())}
				if _, err := fake.conn.Write(p.Assemble()); err != nil {
					t.Fatal(err)
				}
				select {
				case response := <-fake.responses:
					for _, el := range response.Elements {
						if el.Type == 0x25 && len(el.Value) >= 10 && binary.BigEndian.Uint16(el.Value[6:]) == 0x49 {
							v, err := capwap.ParsePrivStaPMKReq(el.Value[10:])
							if err != nil {
								t.Fatal(err)
							}
							return v
						}
					}
					return nil
				case <-time.After(time.Second):
					t.Fatal("no PMK event ACK")
					return nil
				}
			}
			v := capwap.PrivStaPMKReq{Operation: 0, Radio: 1, WLAN: 1, MAC: mac}
			v.PMKR0[0], v.PMKR0Name[0] = 42, 43
			if got := request(v); got != nil {
				t.Fatal("inform produced lookup response")
			}
			v.Operation = 1
			v.PMKR0 = [32]byte{}
			v.PMKR0Name = [16]byte{}
			if got := request(v); got == nil || got.Operation != 2 || got.Result != 0 || got.PMKR0[0] != 42 || got.PMKR0Name[0] != 43 {
				t.Fatal("ordinary lookup", got)
			}
			rssi := int8(-55)
			m.clients.StationEvent(cweng.ClientEvent{MAC: mac, APID: "old-ap", RadioID: 2, WLANID: 1, RSSI: &rssi, Kind: "associate", Seen: time.Now()})
			checks := 0
			e.CheckAssociation = func(string, uint8, uint8, [6]byte, *int8, *capwap.AssociationMLO) uint32 { checks++; return 0x27 }
			v.Operation = 3
			got := request(v)
			if (got != nil) != special || checks != 0 {
				t.Fatal("operation3 capability or extra admission policy", got, checks)
			}
			client := m.clients.All()[0]
			if special && (client.APID != ap.ID || client.RSSI == nil || *client.RSSI != -55) {
				t.Fatal("special lookup lost association/RSSI", client)
			}
			if !special && client.APID != "old-ap" {
				t.Fatal("unsupported operation3 moved station")
			}
			v.Operation = 1
			v.WLAN = 2
			if got := request(v); got == nil || got.Result != 2 || got.PMKR0 != [32]byte{} || got.PMKR0Name != [16]byte{} {
				t.Fatal("existing PMK with missing service must return2", got)
			}
			v.MAC[5]++
			if got := request(v); got == nil || got.Result != 1 {
				t.Fatal("missing PMK must precede missing-service result2", got)
			}
		})
	}
}
