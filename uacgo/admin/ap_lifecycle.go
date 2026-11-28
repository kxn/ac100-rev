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
	if !exists || old.Online != ap.Online || old.State != ap.State || !old.ConnectedAt.Equal(ap.ConnectedAt) {
		m.event("ap.lifecycle", "ap_id", ap.ID, "session", ap.ConnectedAt, "online", ap.Online, "state", ap.State, "previous_state", old.State, "model", ap.Model, "hardware", ap.HardwareVersion, "ip", ap.LocalIP, "remote", ap.Address, "entry_id", ap.EntryID, "capabilities", ap.GeneralCapabilities, "sub_capabilities", ap.SubCapabilities, "radios", ap.Capabilities)
	}
	if exists && old.ConnectedAt.After(ap.ConnectedAt) {
		m.mu.Unlock()
		return
	}
	if exists && old.ConnectedAt != ap.ConnectedAt {
		m.clearAPSessionLocked(ap.ID, old.ConnectedAt)
	}
	m.known[ap.ID] = ap
	if ap.Online && (!exists || !old.Online || old.ConnectedAt != ap.ConnectedAt) {
		m.automaticAPJoinedLocked(ap)
	}
	if ap.Online {
		m.seedHighPerformanceLocked(ap)
		if !exists || !old.Online || old.ConnectedAt != ap.ConnectedAt {
			m.commitHighPerformanceChannelsLocked(m.highPerformance.Channels, 0)
		}
	}
	if ap.Online && (!exists || !old.Online || old.ConnectedAt != ap.ConnectedAt) {
		next := m.config
		next, edcaChanged := m.compileEDCARules(next)
		if edcaChanged {
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
