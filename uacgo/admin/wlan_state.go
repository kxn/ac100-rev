package admin

import (
	"encoding/json"
	"fmt"
	"os"
	"path/filepath"
	"time"
)

// Reservations and ownership are one durable record. A crash after a DELETE
// ACK but before commit retains the reservation and repeats the deletion.
type wlanState struct {
	Assignments WLANAssignments                     `json:"assignments"`
	Owned       map[string]map[uint8]map[uint8]bool `json:"owned"`
}

type commitSettlement struct {
	Version    string
	Connection time.Time
	Ready      time.Time
}

func (m *Manager) dirtyAP(ap string) {
	m.mu.Lock()
	defer m.mu.Unlock()
	m.batchRevision[ap]++
	delete(m.applied, ap+"/configuration-commit")
	delete(m.settling, ap)
	delete(m.settled, ap)
}

func (m *Manager) loadWLANState() error {
	b, err := os.ReadFile(filepath.Join(filepath.Dir(m.path), "wlan-state.json"))
	if os.IsNotExist(err) {
		return nil
	}
	if err != nil {
		return err
	}
	var state wlanState
	if err = json.Unmarshal(b, &state); err != nil {
		return fmt.Errorf("WLAN state: %w", err)
	}
	if state.Assignments == nil || state.Owned == nil {
		return fmt.Errorf("incomplete WLAN state")
	}
	m.assignments, m.owned = state.Assignments, state.Owned
	compactWLANState(&state)
	return nil
}

func compactWLANState(state *wlanState) {
	for ap, services := range state.Assignments {
		for id, radios := range services {
			if len(radios) == 0 {
				delete(services, id)
			}
		}
		if len(services) == 0 {
			delete(state.Assignments, ap)
		}
	}
	for ap, slots := range state.Owned {
		for slot, radios := range slots {
			for radio, owned := range radios {
				if !owned {
					delete(radios, radio)
				}
			}
			if len(radios) == 0 {
				delete(slots, slot)
			}
		}
		if len(slots) == 0 {
			delete(state.Owned, ap)
		}
	}
}
func (m *Manager) saveWLANState() error {
	return atomicJSON(filepath.Join(filepath.Dir(m.path), "wlan-state.json"), wlanState{m.assignments, m.owned})
}

func (m *Manager) validateWLANState() error {
	if m.assignments == nil || m.owned == nil {
		return fmt.Errorf("incomplete persisted WLAN state")
	}
	for ap, services := range m.assignments {
		used := map[[2]uint8]string{}
		for sid, radios := range services {
			for radio, slot := range radios {
				if ap == "" || sid == "" || radio == 0 || radio > 31 || slot == 0 || slot > 16 {
					return fmt.Errorf("invalid persisted WLAN reservation")
				}
				k := [2]uint8{radio, slot}
				if other, exists := used[k]; exists && other != sid {
					return fmt.Errorf("duplicate persisted WLAN slot on AP %s radio %d", ap, radio)
				}
				used[k] = sid
			}
		}
	}
	return nil
}
func (m *Manager) stageWLAN(ap, sid string, radio, slot uint8, enabled bool) error {
	m.mu.Lock()
	defer m.mu.Unlock()
	if enabled {
		if m.owned[ap] == nil {
			m.owned[ap] = map[uint8]map[uint8]bool{}
		}
		if m.owned[ap][slot] == nil {
			m.owned[ap][slot] = map[uint8]bool{}
		}
		m.owned[ap][slot][radio] = true
		delete(m.pendingDeletes[ap][sid], radio)
		return m.saveWLANState()
	}
	// Do not free the slot here: the AP has only cached the delete.
	if m.pendingDeletes[ap] == nil {
		m.pendingDeletes[ap] = map[string]map[uint8]uint8{}
	}
	if m.pendingDeletes[ap][sid] == nil {
		m.pendingDeletes[ap][sid] = map[uint8]uint8{}
	}
	m.pendingDeletes[ap][sid][radio] = slot
	return nil
}

// Called only after the matching whole-batch commit ACK and deferred-apply
// interval. Changes/reconnection reset settlement; no goroutine releases slots.
func (m *Manager) settleWLANs(ap, version string, connection time.Time, now time.Time) error {
	m.mu.Lock()
	defer m.mu.Unlock()
	st, ok := m.settling[ap]
	if !ok || st.Version != version || !st.Connection.Equal(connection) || now.Before(st.Ready) {
		return nil
	}
	// Build a new record, so a failed disk write leaves all reservations held.
	b, _ := json.Marshal(wlanState{m.assignments, m.owned})
	var next wlanState
	_ = json.Unmarshal(b, &next)
	for sid, radios := range m.pendingDeletes[ap] {
		for radio, slot := range radios {
			if next.Assignments[ap][sid][radio] != slot {
				continue
			}
			delete(next.Assignments[ap][sid], radio)
			delete(next.Owned[ap][slot], radio)
		}
	}
	compactWLANState(&next)
	if err := atomicJSON(filepath.Join(filepath.Dir(m.path), "wlan-state.json"), next); err != nil {
		return err
	}
	m.assignments, m.owned = next.Assignments, next.Owned
	delete(m.pendingDeletes, ap)
	delete(m.settling, ap)
	return nil
}
