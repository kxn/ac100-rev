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
	a, b, c := [6]byte{2, 0, 0, 0, 0, 1}, [6]byte{2, 0, 0, 0, 0, 2}, [6]byte{2, 0, 0, 0, 0, 3}
	m.observeBSSIDLocations("ap", conn, []capwap.BSSIDLocation{{Radio: 1, WLAN: 1, BSSID: a}, {Radio: 2, WLAN: 1, BSSID: b}})
	m.observeAPStatistics("ap", conn, capwap.PrivApStatistics{VAPs: []capwap.APVAPStatistics{{Radio: 1, WLAN: 1, BSSID: c}}})
	m.mu.Lock()
	defer m.mu.Unlock()
	if _, ok := m.bssidLocations[a]; ok {
		t.Fatal("changed slot kept its old BSSID")
	}
	if _, ok := m.bssidLocations[b]; !ok {
		t.Fatal("omitted slot was deleted")
	}
	if ap, radio, wlan, ok := m.findBSSIDLocked(c); !ok || ap.ID != "ap" || radio != 1 || wlan != 1 {
		t.Fatal(ap, radio, wlan, ok)
	}
}
