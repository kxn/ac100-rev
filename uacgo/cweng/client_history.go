package cweng

import "time"

type ClientTransition struct {
	VLAN      *uint16   `json:"vlan_id,omitempty"`
	SSID      string    `json:"ssid,omitempty"`
	ServiceID string    `json:"service_id,omitempty"`
	Sequence  uint64    `json:"sequence"`
	At        time.Time `json:"at"`
	MAC       [6]byte   `json:"mac"`
	Kind      string    `json:"kind"`
	AP        string    `json:"ap_id"`
	Radio     uint8     `json:"radio_id"`
	WLAN      uint32    `json:"wlan_id"`
	FromAP    string    `json:"from_ap,omitempty"`
	FromRadio uint8     `json:"from_radio,omitempty"`
	Source    string    `json:"source"`
}

func (t *ClientTable) unlockAndNotify(after uint64, beforeNotify ...func()) {
	callback := t.OnTransition
	var pending []ClientTransition
	if callback != nil {
		for i := len(t.transitions) - 1; i >= 0 && t.transitions[i].Sequence > after; i-- {
			v := t.transitions[i]
			if v.VLAN != nil {
				n := *v.VLAN
				v.VLAN = &n
			}
			pending = append(pending, v)
		}
	}
	t.mu.Unlock()
	for _, f := range beforeNotify {
		f()
	}
	for i := len(pending) - 1; i >= 0; i-- {
		callback(pending[i])
	}
}

func (t *ClientTable) recordTransition(old ClientEvent, known bool, next ClientEvent) {
	kind := ""
	if next.State == "connected" && (!known || old.State != "connected") {
		kind = "connected"
	}
	if known && old.State == "connected" && next.State == "disconnected" {
		kind = "disconnected"
	}
	if known && old.State == "connected" && next.State == "connected" && clientPosition(old) != clientPosition(next) {
		kind = "roamed"
	}
	if kind == "" && known && old.State == "connected" && next.State == "connected" && !sameClientService(old, next) {
		kind = "service_changed"
	}
	if kind == "" {
		return
	}
	t.transitionSeq++
	v := ClientTransition{VLAN: next.VLAN, SSID: next.SSID, ServiceID: next.ServiceID, Sequence: t.transitionSeq, At: next.Seen, MAC: next.MAC, Kind: kind, AP: next.APID, Radio: next.RadioID, WLAN: next.WLANID, Source: next.Kind}
	if kind == "roamed" {
		v.FromAP = old.APID
		v.FromRadio = old.RadioID
	}
	t.transitions = append(t.transitions, v)
	if len(t.transitions) > 10000 {
		t.transitions = append([]ClientTransition{}, t.transitions[len(t.transitions)-10000:]...)
	}
}
func (t *ClientTable) Transitions(after uint64) []ClientTransition {
	t.mu.Lock()
	defer t.mu.Unlock()
	out := []ClientTransition{}
	for _, v := range t.transitions {
		if v.Sequence > after {
			if v.VLAN != nil {
				vlan := *v.VLAN
				v.VLAN = &vlan
			}
			out = append(out, v)
		}
	}
	return out
}

// Successful operation3 uses the old DB RSSI, or zero if no station exists
// (4e46c0), then calls association directly without an admission check.
func (t *ClientTable) AssociatePMK(event ClientEvent) {
	rssi := int8(0)
	t.mu.Lock()
	if old, ok := t.m[event.MAC]; ok && old.RSSI != nil {
		rssi = *old.RSSI
	}
	t.mu.Unlock()
	event.RSSI = &rssi
	t.StationEvent(event)
}

// uac_wstation_free_sta_by_mac on a failed PMK lookup releases the currently
// associated location, which can be different from the requesting AP.
func (t *ClientTable) DisconnectStation(mac [6]byte, at time.Time) {
	t.mu.Lock()
	old, ok := t.m[mac]
	if !ok || old.State != "connected" {
		t.mu.Unlock()
		return
	}
	after := t.transitionSeq
	if old.MLD != nil {
		t.disconnectMLOLocked(old, at, "pmk_lookup_failed")
	} else {
		next := old
		next.State, next.Seen, next.Kind = "disconnected", at, "pmk_lookup_failed"
		t.m[mac] = next
		t.recordTransition(old, true, next)
	}
	t.unlockAndNotify(after, func() {
		if t.OnRelease != nil {
			t.OnRelease(old)
		}
	})
}

// AP lifecycle, rather than an arbitrary station age cutoff, releases the
// old epoch's DB membership. Newer RUN events and late old teardowns cannot
// delete one another's station records.
func (t *ClientTable) APState(ap string, connection time.Time, online bool, at time.Time) {
	t.mu.Lock()
	after := t.transitionSeq
	if t.epochs == nil {
		t.epochs = map[string]clientEpoch{}
	}
	if epoch := t.epochs[ap]; epoch.Connection.After(connection) {
		t.mu.Unlock()
		return
	}
	t.epochs[ap] = clientEpoch{connection, online}
	for mac, old := range t.m {
		if old.APID != ap || old.State != "connected" {
			continue
		}
		if online {
			if old.Connection == connection || old.Connection.IsZero() && !old.Seen.Before(connection) {
				continue
			}
		} else if !old.Connection.IsZero() && old.Connection != connection {
			continue
		}
		next := old
		next.State = "disconnected"
		next.Kind = "ap_offline"
		next.Seen = at
		t.m[mac] = next
		t.recordTransition(old, true, next)
	}
	t.unlockAndNotify(after)
}

type clientEpoch struct {
	Connection time.Time
	Online     bool
}
