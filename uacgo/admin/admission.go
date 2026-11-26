package admin

import "time"

type admissionReservation struct {
	Service string
	Until   time.Time
}

// Reserve admissions atomically across APs/radios. Reassociation of the same
// station does not consume another slot. Permission is not an online report.
func (m *Manager) admitClient(ap string, radio, wlan uint8, mac [6]byte, rssi *int8) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	if mac == [6]byte{} || mac[0]&1 != 0 || radio == 0 || wlan == 0 || radioDisabled(m.config, ap, radio) {
		return false
	}
	now := time.Now()
	for _, s := range m.config.Services {
		if s.Deleting || !s.Enabled || !serviceTargets(s, ap, m.config) || !serviceOptions(s).Schedule.active(now) || m.assignments[ap][s.ID][radio] != wlan {
			continue
		}
		selected := selectedServiceRadios(s, m.known[ap])[radio]
		bound, _ := binding(s, ap, radio)
		if !selected || !bound {
			continue
		}
		limit := serviceOptions(s).MaxClients
		seen := map[[6]byte]bool{}
		if m.clients != nil {
			for _, c := range m.clients.All() {
				if c.State == "connected" && now.Sub(c.Seen) < 6*time.Minute && m.assignments[c.APID][s.ID][c.RadioID] == uint8(c.WLANID) && c.WLANID > 0 {
					seen[c.MAC] = true
				}
			}
		}
		for id, r := range m.admissions {
			if now.After(r.Until) {
				delete(m.admissions, id)
			} else if r.Service == s.ID {
				seen[id] = true
			}
		}
		if limit > 0 && !seen[mac] && len(seen) >= limit {
			return false
		}
		if !m.balanceAdmission(ap, radio, mac, s, now) {
			return false
		}
		if m.admissions == nil {
			m.admissions = map[[6]byte]admissionReservation{}
		}
		m.admissions[mac] = admissionReservation{s.ID, now.Add(30 * time.Second)}
		return true
	}
	return false
}

// Association authorization follows the configured logical service and its
// AP-local slot. A guessed radio/WLAN pair is not an enabled wireless service.
func (m *Manager) admitStation(ap string, radio, wlan uint8) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	if radio == 0 || radio > 31 || wlan == 0 || wlan > 16 || radioDisabled(m.config, ap, radio) {
		return false
	}
	for _, s := range m.config.Services {
		if s.Deleting || !s.Enabled || !serviceOptions(s).Schedule.active(time.Now()) || m.assignments[ap][s.ID][radio] != wlan {
			continue
		}
		target := serviceTargets(s, ap, m.config)
		selected := selectedServiceRadios(s, m.known[ap])[radio]
		bound, _ := binding(s, ap, radio)
		if target && selected && bound {
			return true
		}
	}
	return false
}
