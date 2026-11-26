package admin

import "uacgo/cweng"

func (m *Manager) configurationSettled(ap cweng.APStatus, cfg Config) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	return m.settled[ap.ID] == configurationKey(cfg, ap.ConnectedAt)
}
