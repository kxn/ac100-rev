package admin

import "time"

// Resolves only a committed AP configuration. Called before ClientTable.mu is
// acquired; it must not call engine/session readers (AP handlers hold a lock).
func (m *Manager) resolveClientService(apID string, radio uint8, wlan uint32) (string, string) {
	m.mu.Lock()
	defer m.mu.Unlock()
	if wlan == 0 || wlan > 255 || m.settled[apID] == "" || m.settledVersions[apID] != m.config.Version {
		return "", ""
	}
	var id, ssid string
	for _, s := range m.config.Services {
		if !s.Enabled || s.Deleting || !serviceOptions(s).Schedule.active(time.Now()) || m.assignments[apID][s.ID][radio] != uint8(wlan) || !m.owned[apID][uint8(wlan)][radio] {
			continue
		}
		if id != "" {
			return "", ""
		}
		id, ssid = s.ID, s.SSID
	}
	return id, ssid
}
