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
