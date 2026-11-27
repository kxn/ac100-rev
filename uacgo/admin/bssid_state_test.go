package admin

import (
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func TestV6BSSIDIndexRetainsOmittedSlotsAndRemovesChangedSlot(t *testing.T) {
	m, _ := testController(t)
	conn := time.Unix(3000, 0)
	ap := cweng.APStatus{ID: "ap", ConnectedAt: conn, Online: true, Radios: 2}
	m.known = map[string]cweng.APStatus{"ap": ap}
	s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1, 2}}
	m.config.Services = []Service{s}
	for _, radio := range []uint8{1, 2} {
		if _, err := m.allocate("ap", s.ID, radio, 8); err != nil {
			t.Fatal(err)
		}
	}
	a, b, c := [6]byte{2, 0, 0, 0, 0, 1}, [6]byte{2, 0, 0, 0, 0, 2}, [6]byte{2, 0, 0, 0, 0, 3}
	m.observeAPStatistics("ap", conn, capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: a}, {Radio: 2, WLAN: 1, BSSID: b}}})
	extra := [6]byte{2, 0, 0, 0, 0, 4}
	m.observeBSSIDLocations("ap", conn, []capwap.BSSIDLocation{{Radio: 1, WLAN: 1, BSSID: extra}})
	m.observeAPStatistics("ap", conn, capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: c}}})
	m.mu.Lock()
	defer m.mu.Unlock()
	if _, ok := m.bssidLocations[a]; ok {
		t.Fatal("changed slot kept its old BSSID")
	}
	if _, ok := m.bssidLocations[b]; !ok {
		t.Fatal("omitted slot was deleted")
	}
	if _, ok := m.bssidLocations[extra]; !ok {
		t.Fatal("SSID update erased an independent privatebd hash record")
	}
	if ap, radio, wlan, ok := m.findBSSIDLocked(c); !ok || ap.ID != "ap" || radio != 1 || wlan != 1 {
		t.Fatal(ap, radio, wlan, ok)
	}
}
