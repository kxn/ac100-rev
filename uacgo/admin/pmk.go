package admin

import (
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/mobility"
)

func (m *Manager) observePMKTransition(ev cweng.ClientTransition) {
	m.mu.Lock()
	defer m.mu.Unlock()
	if m.pmkTransitions == nil {
		m.pmkTransitions = map[[6]byte]uint64{}
	}
	if ev.Sequence <= m.pmkTransitions[ev.MAC] {
		return
	}
	m.pmkTransitions[ev.MAC] = ev.Sequence
	if ev.Kind == "disconnected" {
		m.pmks.Disconnect(mobility.MAC(ev.MAC), ev.At)
		m.stationStatistics.Disconnect(mobility.MAC(ev.MAC), ev.At)
	} else {
		m.pmks.Associate(mobility.MAC(ev.MAC), ev.ServiceID)
		m.stationStatistics.Associate(mobility.MAC(ev.MAC), ev.At)
	}
}

func (m *Manager) handlePMK(ap string, connection time.Time, special bool, request capwap.PrivStaPMKReq) *capwap.PrivStaPMKReq {
	if request.Operation == 3 && !special {
		return nil
	}
	if request.Operation != 0 && request.Operation != 1 && request.Operation != 3 {
		return nil
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	if known, ok := m.known[ap]; ok && known.ConnectedAt.After(connection) {
		return nil
	}
	service := ""
	if s := m.serviceForSlotLocked(ap, request.Radio, request.WLAN); s != nil {
		service = s.ID
	}
	mac := mobility.MAC(request.MAC)
	now := time.Now()
	if request.Operation == 0 {
		if service == "" {
			return nil
		}
		m.pmks.Inform(mac, mobility.PMK{Service: service, Key: request.PMKR0, Name: request.PMKR0Name}, now)
		return nil
	}
	key, result := m.pmks.Lookup(mac, service, now)
	request.Operation, request.Result = 2, result
	if result == 0 {
		request.PMKR0, request.PMKR0Name = key.Key, key.Name
	}
	return &request
}
