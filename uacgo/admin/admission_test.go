package admin

import (
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

// Wireless service count was never a V6 global admission quota. The source
// checks the target radio maximum in wsta_db_sta_assoc; probes don't reserve it.
func TestFirmwareRadioCapacityIsLocalAndHasNoAdmissionReservation(t *testing.T) {
	m, _ := testController(t)
	s := Service{ID: "office", Enabled: true, Radios: []uint8{1, 2}}
	m.config.Services = []Service{s}
	for _, ap := range []string{"a", "b"} {
		m.known[ap] = cweng.APStatus{ID: ap, Online: true, Capabilities: []cweng.RadioCapability{{RadioID: 1, MaxClients: 1}, {RadioID: 2, MaxClients: 1}}}
		for _, r := range []uint8{1, 2} {
			if _, err := m.allocate(ap, s.ID, r, 2); err != nil {
				t.Fatal(err)
			}
		}
	}
	one, two := [6]byte{2, 1}, [6]byte{2, 2}
	if m.checkAssociation("a", 1, 1, one, nil, nil) != 0 || m.checkAssociation("a", 1, 1, two, nil, nil) != 0 {
		t.Fatal("permission invented a reservation")
	}
	m.clients.StationEvent(cweng.ClientEvent{MAC: one, APID: "a", RadioID: 1, WLANID: 1, Kind: "associate", Seen: time.Now().Add(-time.Hour)})
	if got := m.checkAssociation("a", 1, 1, two, nil, nil); got != 0x11 {
		t.Fatalf("radio full code %x", got)
	}
	if m.checkAssociation("b", 1, 1, two, nil, nil) != 0 || m.checkAssociation("a", 2, 1, two, nil, nil) != 0 || m.checkAssociation("a", 1, 1, one, nil, nil) != 0 {
		t.Fatal("another radio/AP or reassociation was blocked")
	}
}
