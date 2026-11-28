package cweng

import (
	"time"
	"uacgo/capwap"
)

// WirelessSnapshot reconciles a fresh, complete AP wireless station table.
// Wired hosts never enter this path. Events received after the read started
// take precedence, and a snapshot cannot move a client from another live AP.
func (t *ClientTable) WirelessSnapshot(ap string, connection, started time.Time, rows []ClientEvent, present map[[6]byte]bool) {
	t.mu.Lock()
	defer t.unlockAndNotify(t.transitionSeq)
	if epoch, ok := t.epochs[ap]; ok && (!epoch.Online || !connection.Equal(epoch.Connection) || started.Before(epoch.Connection)) {
		return
	}
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
			// Membership/rate refreshes must not erase a signed CAPWAP signal,
			// or turn that cached measurement into a fresh sample. Never carry
			// it over a reconnect or a disconnected-to-connected transition.
			if ev.RSSI == nil && old.State == "connected" && old.Connection.Equal(ev.Connection) {
				ev.RSSI = old.RSSI
				ev.RSSIAt = old.RSSIAt
				ev.DisplayRSSI = old.DisplayRSSI
			}
			// This membership snapshot carries native rates separately, and
			// cannot replace typed CAPWAP negotiation, traffic or bandwidth.
			if old.State == "connected" && old.Connection.Equal(ev.Connection) {
				ev.Statistics = old.Statistics
			}
			// This native table has no MLO grouping/device fields. Absence of
			// such fields cannot erase the richer typed CAPWAP facts.
			ev.MLD = old.MLD
			ev.MLOPeer = old.MLOPeer
			ev.MLOLinks = append([]capwap.AssociationLink{}, old.MLOLinks...)
			ev.Device = cloneDevice(old.Device)
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
	groupPresent := map[[6]byte]bool{}
	for mac, old := range t.m {
		if old.APID == ap && old.MLD != nil && present[mac] {
			groupPresent[*old.MLD] = true
		}
	}
	for mac, old := range t.m {
		if old.MLD != nil && groupPresent[*old.MLD] {
			continue
		}
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
