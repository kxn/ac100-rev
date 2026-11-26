package admin

import (
	"bytes"
	"context"
	"encoding/binary"
	"net/http/httptest"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func scanAP(id string, now time.Time) cweng.APStatus {
	return cweng.APStatus{ID: id, MAC: id, Online: true, ConnectedAt: now, GeneralCapabilities: []uint32{1 << 25, 0, 1 << 8}, Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "2.4 GHz", Channels: []int{1, 6, 11}}, {RadioID: 2, Band: "5 GHz", Channels: []int{36, 40, 44, 48, 149}}}}
}
func TestHighPerformanceScanUDPEndToEndAndMeasuredPlan(t *testing.T) {
	m, e := testController(t)
	e.RegisterObservationHandlers()
	f, raw := newDeferredAP(t, e)
	ap := scanAP(raw.ID, raw.ConnectedAt)
	m.known[ap.ID] = ap
	p := defaultMobility()
	p.NetworkMode = 1
	m.config.Mobility = &p
	cfg := m.snapshot()
	m.settled[ap.ID] = configurationKey(effectiveRadioConfig(cfg, ap), ap.ConnectedAt)
	now := time.Now()
	m.tickMobilityScan(now)
	if m.mobilityScan.State != "collecting" {
		t.Fatal(m.mobilityScan)
	}
	m.applyMobilityScan(context.Background(), ap, effectiveRadioConfig(cfg, ap))
	f.mu.Lock()
	var value []byte
	for _, packet := range f.packets {
		for _, el := range packet.Elements {
			if el.Type == 0x25 && len(el.Value) > 10 && binary.BigEndian.Uint16(el.Value[6:]) == 0x9b {
				value = append([]byte{}, el.Value[10:]...)
			}
		}
	}
	f.mu.Unlock()
	// Independent source layout: dwell100/count2/index0/string6/index1/string15.
	want := append([]byte{100, 2, 0, 6}, []byte("1 6 11")...)
	want = append(want, 1, 15)
	want = append(want, []byte("36 40 44 48 149")...)

	if !bytes.Equal(value, want) {
		t.Fatalf("scan wire %x want %x", value, want)
	}
	// Real UDP report: two channels, nine bytes each. The later report is the
	// only observation used; a stale cached report must not satisfy the job.
	rows := []byte{2, 6, 1, 20, 0, 0, 0, 0, 0, 0, 40, 2, 10, 0, 0, 0, 0, 0, 0}
	packet, _ := capwap.NewParsedPacket(9)
	packet.Control.SeqNum = 33
	packet.Elements = []capwap.Element{privateSetting(0x9c, rows)}
	if _, err := f.conn.Write(packet.Assemble()); err != nil {
		t.Fatal(err)
	}
	deadline := time.Now().Add(time.Second)
	for {
		for _, a := range e.APs() {
			if a.ID == ap.ID && a.ChannelScan != nil {
				ap.ChannelScan = a.ChannelScan
			}
		}
		if ap.ChannelScan != nil {
			break
		}
		if time.Now().After(deadline) {
			t.Fatal("AP scan report was lost")
		}
		time.Sleep(time.Millisecond)
	}
	m.known[ap.ID] = ap
	m.tickMobilityScan(time.Now())
	if m.mobilityScan.State != "applying" || len(m.mobilityScan.Changes) != 2 {
		t.Fatal(m.mobilityScan)
	}
	if *m.config.Radios[0].Channel != 6 || *m.config.Radios[1].Channel != 40 {
		t.Fatal(m.config.Radios)
	}
	if m.mobilityScan.State == "completed" {
		t.Fatal("desired channels alone falsely confirmed AP")
	}
	cfg = m.snapshot()
	m.settled[ap.ID] = configurationKey(effectiveRadioConfig(cfg, ap), ap.ConnectedAt)
	m.tickMobilityScan(time.Now())
	if m.mobilityScan.State != "completed" {
		t.Fatal(m.mobilityScan)
	}
}
func TestHighPerformanceScanTimeoutAndConcurrentOperations(t *testing.T) {
	m, _ := testController(t)
	p := defaultMobility()
	p.NetworkMode = 1
	m.config.Mobility = &p
	ap := scanAP("02:01:02:03:04:05", time.Now())
	m.known[ap.ID] = ap
	cfg := m.snapshot()
	m.settled[ap.ID] = configurationKey(effectiveRadioConfig(cfg, ap), ap.ConnectedAt)
	now := time.Now()
	m.tickMobilityScan(now)
	if m.mobilityScan.State != "collecting" {
		t.Fatal(m.mobilityScan)
	}
	m.tickMobilityScan(now.Add(21 * time.Second))
	if m.mobilityScan.State != "failed" || len(m.config.Radios) != 0 {
		t.Fatal("timeout changed radios", m.mobilityScan)
	}
	m.mobilityScan.State = "collecting"
	if _, err := m.startRRM(RRMRule{}, ""); err == nil {
		t.Fatal("RRM overlapped roaming ACS")
	}
}
func TestARPScanNeedsSubCapabilityAndAcceptsUDPReport(t *testing.T) {
	m, e := testController(t)
	e.RegisterObservationHandlers()
	f, ap := newDeferredAP(t, e)
	// The fixture AP has no scan sub-capability, even if ARP defense is present.
	r := httptest.NewRecorder()
	m.Handler().ServeHTTP(r, httptest.NewRequest("POST", "http://localhost/api/aps/"+ap.ID+"/arp-scan", nil))
	if r.Code != 409 {
		t.Fatal("general capability falsely implied scan support", r.Code)
	}
	packet, _ := capwap.NewParsedPacket(9)
	packet.Control.SeqNum = 61
	packet.Elements = []capwap.Element{privateSetting(0xca, []byte{1, 0, 1, 192, 0, 2, 10, 2, 1, 2, 3, 4, 5})}
	if _, err := f.conn.Write(packet.Assemble()); err != nil {
		t.Fatal(err)
	}
	until := time.Now().Add(time.Second)
	for {
		for _, a := range e.APs() {
			if a.ID == ap.ID && a.ARPScan != nil {
				if len(a.ARPScan.Entries) != 1 || a.ARPScan.Entries[0].IP != "192.0.2.10" {
					t.Fatal(a.ARPScan)
				}
				return
			}
		}
		if time.Now().After(until) {
			t.Fatal("scan result never reached API model")
		}
		time.Sleep(time.Millisecond)
	}
}

func TestHighPerformanceThreeRadiosUseDistinct5GHzSegments(t *testing.T) {
	ap := scanAP("a", time.Now())
	ap.Capabilities[1].Channels = []int{36, 40, 44, 48}
	ap.Capabilities = append(ap.Capabilities, cweng.RadioCapability{RadioID: 3, Band: "5 GHz", Channels: []int{149, 153, 157, 161}})
	ap.ChannelScan = &cweng.ChannelScanReport{ReceivedAt: time.Now(), Channels: []capwap.ChannelScanSample{{Channel: 6, BSS: 1}, {Channel: 40, BSS: 1}, {Channel: 149, BSS: 1}}}
	changes, err := mobilityChannelPlan([]cweng.APStatus{ap}, Config{})
	if err != nil || len(changes) != 3 || *changes[1].Setting.Channel != 40 || *changes[2].Setting.Channel != 149 {
		t.Fatal("dual 5GHz segments collapsed", changes, err)
	}
}
func TestHighPerformanceManualChannelUpdatesOtherAPsAndKeepsTheirPower(t *testing.T) {
	m, _ := testController(t)
	a := scanAP("a", time.Now())
	b := scanAP("b", time.Now())
	m.known = map[string]cweng.APStatus{"a": a, "b": b}
	p := defaultMobility()
	p.NetworkMode = 1
	power := 12
	cfg := Config{Mobility: &p, Radios: []RadioSetting{{AP: "b", Radio: 1, Power: &power}}}
	if err := m.propagateMobilityChannelLocked(&cfg, a, a.Capabilities[0], 11); err != nil {
		t.Fatal(err)
	}
	if len(cfg.Radios) != 1 || *cfg.Radios[0].Channel != 11 || *cfg.Radios[0].Power != 12 {
		t.Fatal(cfg.Radios)
	}
}
