package cweng

import "time"

// WirelessSnapshot reconciles a fresh, complete AP wireless station table.
// Wired hosts never enter this path. Events received after the read started
// take precedence, and a snapshot cannot move a client from another live AP.
func (t *ClientTable) WirelessSnapshot(ap string, started time.Time, rows []ClientEvent, present map[[6]byte]bool) {
	t.mu.Lock()
	defer t.mu.Unlock()
	for _, ev := range rows {
		if ev.RSSI != nil {
			ev.RSSIAt = started
		}
		if ev.MAC == [6]byte{} || ev.MAC[0]&1 != 0 || ev.APID != ap || ev.RadioID == 0 || ev.WLANID == 0 {
			continue
		}
		old, ok := t.m[ev.MAC]
		if ok && (old.Seen.After(started) || old.APID != ap && old.State == "connected") {
			continue
		}
		if ok && old.APID == ap && old.RadioID == ev.RadioID && old.WLANID == ev.WLANID && sameClientService(old, ev) {
			if ev.Statistics == nil {
				ev.Statistics = old.Statistics
			} else if old.Statistics != nil {
				// Native sta_list contains negotiated rate, but no CAPWAP traffic
				// counters or bandwidth. Preserve the last actual counter report.
				merged := *old.Statistics
				merged.NegotiatedMbps = ev.Statistics.NegotiatedMbps
				ev.Statistics = &merged
			}
			ev.IPv6 = old.IPv6
			if ev.IP == "" {
				ev.IP = old.IP
			}
			if ev.VLAN == nil {
				ev.VLAN = old.VLAN
			}
			if ev.ConnectedAt.IsZero() {
				ev.ConnectedAt = old.ConnectedAt
			}
		}
		ev.State = "connected"
		ev.Kind = "wireless_snapshot"
		ev.Seen = started
		if ev.ConnectedAt.IsZero() {
			ev.ConnectedAt = started
		}
		t.recordTransition(old, ok, ev)
		t.m[ev.MAC] = ev
	}
	for mac, old := range t.m {
		if old.APID == ap && old.State == "connected" && old.Seen.Before(started) && !present[mac] {
			old.State = "disconnected"
			old.Kind = "wireless_snapshot"
			old.Seen = started
			previous := t.m[mac]
			t.recordTransition(previous, true, old)
			t.m[mac] = old
		}
	}
}
