package admin

import (
	"sync"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestAdmissionRequiresEnabledBoundServiceAndRadio(t *testing.T) {
	m, _ := testController(t)
	s := Service{ID: "office", Enabled: true, Radios: []uint8{2}, APs: []string{"ap"}}
	m.config.Services = []Service{s}
	if _, err := m.allocate("ap", s.ID, 2, 2); err != nil {
		t.Fatal(err)
	}
	if !m.admitStation("ap", 2, 1) {
		t.Fatal("managed service rejected")
	}
	for _, v := range []struct {
		ap          string
		radio, wlan uint8
	}{{"other", 2, 1}, {"ap", 1, 1}, {"ap", 2, 2}, {"ap", 0, 1}} {
		if m.admitStation(v.ap, v.radio, v.wlan) {
			t.Fatal("unmanaged WLAN admitted", v)
		}
	}
	off := false
	m.config.Radios = []RadioSetting{{AP: "ap", Radio: 2, Enabled: &off}}
	if m.admitStation("ap", 2, 1) {
		t.Fatal("disabled radio admitted")
	}
	m.config.Radios = nil
	m.config.Services[0].Deleting = true
	if m.admitStation("ap", 2, 1) {
		t.Fatal("deleting service admitted")
	}
}

func TestServiceAdmissionAtomicAcrossAPsAndReassociation(t *testing.T) {
	m, _ := testController(t)
	s := Service{ID: "limited", Enabled: true, Radios: []uint8{1, 2}, Options: &WirelessOptions{MaxClients: 1}}
	m.config.Services = []Service{s}
	for _, ap := range []string{"a", "b"} {
		for _, r := range []uint8{1, 2} {
			if _, err := m.allocate(ap, s.ID, r, 2); err != nil {
				t.Fatal(err)
			}
		}
	}
	var wg sync.WaitGroup
	accepted := make(chan [6]byte, 2)
	for i, ap := range []string{"a", "b"} {
		wg.Add(1)
		go func(i int, ap string) {
			defer wg.Done()
			mac := [6]byte{2, 0, 0, 0, 0, byte(i + 1)}
			if m.admitClient(ap, 1, 1, mac, nil) {
				accepted <- mac
			}
		}(i, ap)
	}
	wg.Wait()
	close(accepted)
	var winner [6]byte
	n := 0
	for mac := range accepted {
		winner = mac
		n++
	}
	if n != 1 {
		t.Fatalf("accepted %d simultaneous clients", n)
	}
	if !m.admitClient("b", 2, 1, winner, nil) {
		t.Fatal("same station roaming counted twice")
	}
	m.clients.StationEvent(cweng.ClientEvent{MAC: winner, APID: "b", RadioID: 2, WLANID: 1, Kind: "associate", State: "connected", Seen: time.Now()})
	m.admissions[winner] = admissionReservation{Service: s.ID, Until: time.Now().Add(-time.Minute)}
	other := [6]byte{2, 0, 0, 0, 0, 3}
	if m.admitClient("a", 1, 1, other, nil) {
		t.Fatal("confirmed client ignored after reservation expiry")
	}
	m.clients.StationEvent(cweng.ClientEvent{MAC: winner, APID: "b", RadioID: 2, WLANID: 1, Kind: "disassociate", State: "disconnected", Seen: time.Now()})
	if !m.admitClient("a", 1, 1, other, nil) {
		t.Fatal("disconnected client still occupies slot")
	}
}
