package admin

import (
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/mobility"
)

type bssidLocation struct {
	AP          string
	Connection  time.Time
	Radio, WLAN uint8
}

type vapSlot struct {
	AP          string
	Radio, WLAN uint8
}
type radioSlot struct {
	AP    string
	Radio uint8
}
type vapFact struct {
	Connection time.Time
	Statistics capwap.APVAPStatistics
}

// stats_db_ssid_reset @7b1b30 removes the slot's recorded BSSID and ready
// state. A separate privatebd hash entry is not itself a ready SSID record.
func (m *Manager) resetVAPFactsLocked(ap string, radio, wlan uint8) {
	key := vapSlot{ap, radio, wlan}
	if fact, ok := m.vapFacts[key]; ok {
		if loc, exists := m.bssidLocations[fact.Statistics.BSSID]; exists && loc.AP == ap && loc.Radio == radio && loc.WLAN == wlan {
			delete(m.bssidLocations, fact.Statistics.BSSID)
		}
		delete(m.vapFacts, key)
	}
}

// _stats_rd_disable_cb -> stats_db_radio_reset clears readiness and every
// VAP on the radio. Re-enabling needs a new private54, not cached UI facts.
func (m *Manager) resetRoamingRadiosLocked(previous, next Config) {
	for id, ap := range m.known {
		for i := 1; i <= ap.Radios; i++ {
			radio := uint8(i)
			if !radioDisabled(previous, id, radio) && radioDisabled(next, id, radio) {
				if m.roamingRadioReset == nil {
					m.roamingRadioReset = map[radioSlot]bool{}
				}
				m.roamingRadioReset[radioSlot{id, radio}] = true
				for key := range m.vapFacts {
					if key.AP == id && key.Radio == radio {
						m.resetVAPFactsLocked(id, radio, key.WLAN)
					}
				}
			}
		}
	}
}

func (m *Manager) observeBSSIDLocations(ap string, connection time.Time, rows []capwap.BSSIDLocation) {
	m.mu.Lock()
	defer m.mu.Unlock()
	known, ok := m.known[ap]
	if !ok || !known.Online || !known.ConnectedAt.Equal(connection) {
		return
	}
	m.updateBSSIDLocationsLocked(known, rows, false)
}
func (m *Manager) updateBSSIDLocationsLocked(ap cweng.APStatus, rows []capwap.BSSIDLocation, replaceSlot bool) {
	if m.bssidLocations == nil {
		m.bssidLocations = map[[6]byte]bssidLocation{}
	}
	for _, r := range rows {
		if r.Radio > 0 && r.Radio <= 31 && int(r.Radio) <= ap.Radios && r.WLAN > 0 && r.WLAN <= 16 {
			if replaceSlot {
				// stats_db_ssid_update @7b1e44 deletes the previous BSSID of
				// this slot; an omitted VAP is not a slot-removal report.
				if old, ok := m.vapFacts[vapSlot{ap.ID, r.Radio, r.WLAN}]; ok && old.Statistics.BSSID != r.BSSID {
					delete(m.bssidLocations, old.Statistics.BSSID)
				}
			}
			if r.BSSID != [6]byte{} {
				m.bssidLocations[r.BSSID] = bssidLocation{ap.ID, ap.ConnectedAt, r.Radio, r.WLAN}
			}
		}
	}
}

func radioBand(ap cweng.APStatus, radio uint8) int {
	for _, r := range ap.Capabilities {
		if r.RadioID == radio {
			if r.Band == "5 GHz" {
				return 1
			}
			if r.Band == "2.4 GHz" {
				return 0
			}
		}
	}
	return -1
}
func (m *Manager) observeStationStatistics(ap string, connection time.Time, r capwap.StaStatisticsRecord) {
	m.mu.Lock()
	defer m.mu.Unlock()
	known, ok := m.known[ap]
	if !ok || !known.Online || known.ConnectedAt != connection {
		return
	}
	knownStation := false
	for _, c := range m.clients.All() {
		if c.MAC == r.MAC && c.APID == ap && c.RadioID == r.Radio && c.WLANID == uint32(r.WLAN) && c.State != "disconnected" {
			knownStation = true
			break
		}
	}
	if !knownStation {
		return
	}
	m.stationStatistics.Observe(mobility.MAC(r.MAC), radioBand(known, r.Radio), r.SupportWord, int8(r.Bandwidth))
	m.stationStatistics.ObserveActivity(mobility.MAC(r.MAC), r.UpstreamKbps, r.DownstreamKbps)

}
func (m *Manager) observeAPStatistics(ap string, connection time.Time, stats capwap.PrivApStatistics) {
	m.mu.Lock()
	defer m.mu.Unlock()
	known, ok := m.known[ap]
	if !ok || !known.Online || known.ConnectedAt != connection {
		return
	}
	known.VAPStatistics = cweng.MergeVAPStatistics(known.VAPStatistics, stats.VAPs, known.Radios)
	locations := []capwap.BSSIDLocation{}
	validVAPs := []capwap.APVAPStatistics{}
	for _, v := range stats.VAPs {
		service := m.serviceForSlotLocked(ap, v.Radio, v.WLAN)
		if v.Radio > 0 && v.Radio <= 31 && int(v.Radio) <= known.Radios && v.WLAN > 0 && v.WLAN <= 16 && service != nil && service.Enabled && !service.Deleting && !radioDisabled(m.config, ap, v.Radio) {
			locations = append(locations, capwap.BSSIDLocation{Radio: v.Radio, WLAN: v.WLAN, BSSID: v.BSSID})
			validVAPs = append(validVAPs, v)
		}
	}
	m.updateBSSIDLocationsLocked(known, locations, true)
	if m.vapFacts == nil {
		m.vapFacts = map[vapSlot]vapFact{}
	}
	for _, v := range validVAPs {
		m.vapFacts[vapSlot{ap, v.Radio, v.WLAN}] = vapFact{connection, v}
	}
	for _, r := range stats.Radios {
		if r.Radio == 0 || int(r.Radio) > known.Radios {
			continue
		}
		if !radioDisabled(m.config, ap, r.Radio) {
			delete(m.roamingRadioReset, radioSlot{ap, r.Radio})
		}
		row := cweng.RadioStatistics{APRadioStatistics: r, ReceivedAt: time.Now()}
		found := false
		for i, v := range known.RadioStatistics {
			if v.Radio == r.Radio {
				known.RadioStatistics[i] = row
				found = true
				break
			}
		}
		if !found {
			known.RadioStatistics = append(known.RadioStatistics, row)
		}
	}
	m.known[ap] = known
}
func (m *Manager) observeRSSIStatistics(ap string, connection time.Time, stats capwap.PrivRssiStatistics) {
	m.mu.Lock()
	defer m.mu.Unlock()
	known, ok := m.known[ap]
	if !ok || !known.Online || known.ConnectedAt != connection {
		return
	}
	for i, r := range known.RadioStatistics {
		if r.Radio > 0 && r.Radio <= 8 {
			known.RadioStatistics[i].ChannelLoad = stats.ChannelLoad[r.Radio-1]
			known.RadioStatistics[i].NoiseFloor = stats.NoiseFloor[r.Radio-1]
		}
	}
	m.known[ap] = known
	if m.clients == nil {
		return
	}
	clients := map[[6]byte]cweng.ClientEvent{}
	for _, c := range m.clients.All() {
		clients[c.MAC] = c
	}
	now := time.Now()
	for _, r := range stats.Stations {
		c, ok := clients[r.MAC]
		if !ok || c.State == "disconnected" {
			continue
		}
		service := m.serviceForSlotLocked(c.APID, c.RadioID, uint8(c.WLANID))
		if service == nil || !service.Enabled || service.Deleting {
			continue
		}
		age := mobility.NeighborAge(int(reportingControl(m.config, c.APID).E))
		for i, rssi := range r.RSSI {
			radio := uint8(i + 1)
			if rssi == 0 || int(radio) > known.Radios || (c.APID == ap && c.RadioID == radio) {
				continue
			}
			slot := m.assignments[ap][service.ID][radio]
			if slot == 0 {
				continue
			}
			m.stationStatistics.UpdateNeighbor(mobility.MAC(r.MAC), mobility.RSSINeighbor{AP: ap, Radio: radio, WLAN: slot, RSSI: rssi, At: now}, age)
		}
	}
}
func (m *Manager) serviceForSlotLocked(ap string, radio, wlan uint8) *Service {
	for i := range m.config.Services {
		s := &m.config.Services[i]
		if wlan != 0 && m.assignments[ap][s.ID][radio] == wlan {
			return s
		}
	}
	return nil
}
