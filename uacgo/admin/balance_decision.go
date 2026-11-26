package admin

import "time"

type balanceFailureKey struct {
	AP, Rule string
	MAC      [6]byte
}
type balanceFailure struct {
	Count   int
	Started time.Time
}

// Called with Manager.mu held. Only APs that have recently heard this station
// and offer its logical service are candidates. Unknown coverage is not a
// reason to reject a client. Original V6 expires failure counts after 60s.
func (m *Manager) balanceAdmission(ap string, radio uint8, mac [6]byte, s Service, now time.Time) bool {
	rule := balanceFor(m.config.Mobility, ap, m.config)
	if rule == nil || !rule.Enabled || m.clients == nil {
		return true
	}
	counts := map[string]int{}
	for _, c := range m.clients.All() {
		if c.State == "connected" && now.Sub(c.Seen) < 6*time.Minute && c.MAC != mac {
			counts[c.APID]++
		}
	}
	if counts[ap] < rule.Clients {
		return true
	}
	candidate := false
	for _, o := range m.clients.Observations(mac) {
		if o.APID == ap || !m.known[o.APID].Online || !rule.PolicyTarget.matches(o.APID, m.config) || !serviceTargets(s, o.APID, m.config) || radioDisabled(m.config, o.APID, o.RadioID) {
			continue
		}
		if o.RSSI != nil && int(*o.RSSI) < rule.RSSI {
			continue
		}
		if m.assignments[o.APID][s.ID][o.RadioID] == 0 {
			continue
		}
		bound, vlan := binding(s, o.APID, o.RadioID)
		_, sourceVLAN := binding(s, ap, radio)
		if !selectedServiceRadios(s, m.known[o.APID])[o.RadioID] || !bound || vlan != sourceVLAN {
			continue
		}
		if counts[ap]-counts[o.APID] >= rule.Difference {
			candidate = true
			break
		}
	}
	if !candidate {
		return true
	}
	if m.balanceFailures == nil {
		m.balanceFailures = map[balanceFailureKey]balanceFailure{}
	}
	for k, v := range m.balanceFailures {
		if now.Sub(v.Started) > time.Minute {
			delete(m.balanceFailures, k)
		}
	}
	key := balanceFailureKey{ap, rule.ID, mac}
	v := m.balanceFailures[key]
	if v.Started.IsZero() {
		v.Started = now
	}
	if v.Count >= rule.MaxFailures {
		return true
	}
	v.Count++
	m.balanceFailures[key] = v
	return false
}
