package admin

import (
	"time"
	"uacgo/cweng"
)

// An AP may report statistics immediately after RUN, before the UI's inventory
// polling tick. Lifecycle facts initialize its session epoch synchronously.
func (m *Manager) observeAPState(ap cweng.APStatus) {
	m.mu.Lock()
	old, exists := m.known[ap.ID]
	if exists && old.ConnectedAt.After(ap.ConnectedAt) {
		m.mu.Unlock()
		return
	}
	if exists && old.ConnectedAt != ap.ConnectedAt {
		m.clearAPSessionLocked(ap.ID, old.ConnectedAt)
	}
	m.known[ap.ID] = ap
	if ap.Online && (!exists || !old.Online || old.ConnectedAt != ap.ConnectedAt) {
		next := m.config
		groupChanged := m.groupAPJoined(&next, ap)
		next, edcaChanged := m.compileEDCARules(next)
		if groupChanged || edcaChanged {
			if err := m.saveAPEventConfig(next); err != nil {
				m.status[ap.ID+"/group-strategy"] = ApplyStatus{AP: ap.ID, Service: "group-strategy", State: "failed", Error: err.Error(), At: time.Now()}
			}
		}
	}
	if !ap.Online {
		m.balance.ForgetAP(ap.ID)
	}
	m.mu.Unlock()
	if m.clients != nil {
		m.clients.APState(ap.ID, ap.ConnectedAt, ap.Online, time.Now())
	}
}
