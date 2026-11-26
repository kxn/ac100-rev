package admin

import (
	"time"
	"uacgo/mobility"
)

// Discovery and admission are separate firmware callbacks. Generic RSSI and
// statistics observations must not populate the private0b discovery table.
func (m *Manager) observeBalanceProbe(ap string, connection time.Time, mac [6]byte) {
	m.mu.Lock()
	defer m.mu.Unlock()
	if known, ok := m.known[ap]; ok && known.ConnectedAt.After(connection) {
		return
	}
	rule := balanceFor(m.config.Mobility, ap, m.config)
	if rule == nil || !rule.Enabled {
		return
	}
	m.balance.Probe(mobility.MAC(mac), ap, time.Now())
}

// mu held. The vendor's discovery/count algorithm lives outside the Web layer.
func (m *Manager) balanceAdmission(ap string, mac [6]byte, now time.Time) bool {
	rule := balanceFor(m.config.Mobility, ap, m.config)
	if rule == nil || !rule.Enabled || m.clients == nil {
		return true
	}
	aps := map[string]mobility.APCount{}
	for id, known := range m.known {
		aps[id] = mobility.APCount{Online: known.Online}
	}
	for _, c := range m.clients.All() {
		known, ok := m.known[c.APID]
		if ok && known.Online && c.State == "connected" && !c.Seen.Before(known.ConnectedAt) {
			v := aps[c.APID]
			v.Clients++
			aps[c.APID] = v
		}
	}
	return m.balance.Admit(mobility.MAC(mac), ap, mobility.BalanceRule{Clients: uint32(rule.Clients), Difference: uint32(rule.Difference), MaxFailures: uint32(rule.MaxFailures)}, aps, now)
}
