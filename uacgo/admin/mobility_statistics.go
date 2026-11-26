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
		if r.Radio > 0 && int(r.Radio) <= ap.Radios && r.WLAN > 0 && r.WLAN <= 16 {
			if replaceSlot {
				// stats_db_ssid_update @7b1e44 deletes the previous BSSID of
				// this slot; an omitted VAP is not a slot-removal report.
				for mac, loc := range m.bssidLocations {
					if loc.AP == ap.ID && loc.Radio == r.Radio && loc.WLAN == r.WLAN && mac != r.BSSID {
						delete(m.bssidLocations, mac)
					}
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

}
func (m *Manager) observeAPStatistics(ap string, connection time.Time, stats capwap.PrivApStatistics) {
	m.mu.Lock()
	defer m.mu.Unlock()
	known, ok := m.known[ap]
	if !ok || !known.Online || known.ConnectedAt != connection {
		return
	}
	known.VAPStatistics = append([]capwap.APVAPStatistics{}, stats.VAPs...)
	locations := []capwap.BSSIDLocation{}
	for _, v := range stats.VAPs {
		locations = append(locations, capwap.BSSIDLocation{Radio: v.Radio, WLAN: v.WLAN, BSSID: v.BSSID})
	}
	m.updateBSSIDLocationsLocked(known, locations, true)
	for _, r := range stats.Radios {
		if r.Radio == 0 || int(r.Radio) > known.Radios {
			continue
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
		if service == nil || !service.Enabled {
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
