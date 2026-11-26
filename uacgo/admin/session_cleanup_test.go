package admin

import (
	"testing"
	"time"
	"uacgo/cweng"
)

func TestReconnectedAPDropsOldPolicyFailureAndKeepsWirelessOwnership(t *testing.T) {
	m, e := testController(t)
	_, ap := newDeferredAP(t, e)
	old := ap
	old.ConnectedAt = time.Now().Add(-time.Hour)
	m.known[ap.ID] = old
	key := ap.ID + "/roaming-mode"
	m.status[key] = ApplyStatus{AP: ap.ID, Service: "roaming-mode", State: "failed", At: old.ConnectedAt}
	m.applied[key] = configurationKey(1, old.ConnectedAt)
	m.assignments[ap.ID] = map[string]map[uint8]uint8{"s": {1: 2}}
	m.APs()
	if _, ok := m.status[key]; ok {
		t.Fatal("new session inherited stale policy failure")
	}
	if m.assignments[ap.ID]["s"][1] != 2 {
		t.Fatal("reconnect prematurely released AP WLAN ownership")
	}
	// An old worker finishing late cannot remove a newer command's status.
	newer := cweng.APStatus{ID: ap.ID, ConnectedAt: time.Now()}
	m.applied[key] = configurationKey(2, newer.ConnectedAt)
	m.status[key] = ApplyStatus{State: "acknowledged"}
	m.clearAPSessionLocked(ap.ID, old.ConnectedAt)
	if m.status[key].State != "acknowledged" {
		t.Fatal("late cleanup removed new session result")
	}
}
