package admin

import (
	"context"
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

// PMK failure follows 4e46c0 -> 766fdc -> 754c74 -> 75efec: release
// the station's current DB location and queue msg25/Delete Station there.
// The requesting AP can be a different AP; never substitute its location.
func (m *Manager) queueStationRelease(station cweng.ClientEvent) {
	m.mu.Lock()
	defer m.mu.Unlock()
	ap, ok := m.known[station.APID]
	if !ok || !ap.Online || station.RadioID == 0 || station.Seen.Before(ap.ConnectedAt) || (!station.Connection.IsZero() && !station.Connection.Equal(ap.ConnectedAt)) {
		return
	}
	value := (capwap.DeleteStation{RadioID: station.RadioID, MAC: station.MAC[:]}).AssembleValue()
	ticket, err := m.engine.QueueAP(context.Background(), ap, 25, []capwap.Element{{Type: 0x12, Value: value}})
	finish := func(err error) {
		state := ApplyStatus{AP: ap.ID, Service: "pmk-release", State: "acknowledged", At: time.Now()}
		if err != nil {
			state.State, state.Error = "failed", err.Error()
		}
		if current, ok := m.known[ap.ID]; ok && current.ConnectedAt.Equal(ap.ConnectedAt) {
			m.status[ap.ID+"/pmk-release"] = state
		}
	}
	if err != nil {
		finish(err)
		return
	}
	go func() {
		_, err := ticket.Wait(context.Background())
		m.mu.Lock()
		defer m.mu.Unlock()
		finish(err)
	}()
}
