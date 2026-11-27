package admin

import (
	"time"
	"uacgo/capwap"
)

// Compatibility for protocol-only callers; the real engine path preserves
// the vendor result code and evaluates MLO as one association transaction.
func (m *Manager) admitClient(ap string, radio, wlan uint8, mac [6]byte, rssi *int8) bool {
	return m.checkAssociation(ap, radio, wlan, mac, rssi, nil) == 0
}
func (m *Manager) checkAssociation(ap string, radio, wlan uint8, mac [6]byte, rssi *int8, mlo *capwap.AssociationMLO) uint32 {
	m.mu.Lock()
	defer m.mu.Unlock()
	unavailable, balanceRejected := admissionResultCodes(m.config)
	if mlo != nil && len(mlo.Links) > 0 {
		radio = mlo.Links[0].Radio
		wlan = mlo.Links[0].WLAN
	}
	if !m.admitStationLocked(ap, radio, wlan) {
		return unavailable
	}
	if mac == [6]byte{} || mac[0]&1 != 0 {
		return 0x25
	}
	if mlo != nil {
		for _, link := range mlo.Links {
			if !m.admitStationLocked(ap, link.Radio, link.WLAN) {
				return unavailable
			}
		}
	}
	now := time.Now()
	service := m.serviceForSlotLocked(ap, radio, wlan)
	if service == nil {
		return unavailable
	}
	rejected := false
	if mlo != nil {
		// balance_allow_mlo_sta_conect_wtp @4ef344 evaluates every non-MLD
		// link, then the MLD itself; a rejection doesn't skip later counters.
		for _, link := range mlo.Links {
			if link.MAC != mlo.MAC && !m.balanceAdmission(ap, link.MAC, now) {
				rejected = true
			}
		}
		if !m.balanceAdmission(ap, mlo.MAC, now) {
			rejected = true
		}
	} else if !m.balanceAdmission(ap, mac, now) {
		rejected = true
	}
	if rejected {
		return balanceRejected
	}
	// MLO peer records enforce per-radio capacity. The MLD container is
	// not an extra radio client (wsta_db_sta_assoc @758cf8, flags1/0).
	if mlo != nil {
		for _, link := range mlo.Links {
			if link.MAC != mlo.MAC && !m.radioCapacityLocked(ap, link.Radio, link.MAC) {
				return 0x11
			}
		}
		return 0
	}
	if !m.radioCapacityLocked(ap, radio, mac) {
		return 0x11
	}
	return 0
}
func (m *Manager) radioCapacityLocked(ap string, radio uint8, mac [6]byte) bool {
	limit := m.radioCapacityLimitLocked(ap, radio)
	if m.clients == nil || limit <= 0 {
		return true
	}
	count, associated := m.clients.RadioCount(ap, radio)
	return associated[mac] || count < limit
}

func (m *Manager) radioCapacityLimitLocked(ap string, radio uint8) int {
	known := m.known[ap]
	limit := 0
	for _, c := range known.Capabilities {
		if c.RadioID == radio {
			limit = c.MaxClients
		}
	}
	for _, r := range effectiveRadioConfig(m.config, known).Radios {
		if r.AP == ap && r.Radio == radio && r.Advanced != nil {
			limit = r.Advanced.MaxClients
		}
	}
	return limit
}

// Association authorization follows the configured logical service and its
// AP-local slot. A guessed radio/WLAN pair is not an enabled wireless service.
func (m *Manager) admitStation(ap string, radio, wlan uint8) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	return m.admitStationLocked(ap, radio, wlan)
}
func (m *Manager) admitStationLocked(ap string, radio, wlan uint8) bool {
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

// AP inventory/synchronization reports describe an association already made.
// They still require a bound service and DB capacity, but do not run the
// admission balancing policy again (_uac_wsta_pkt_sta_info_list @74a320).
func (m *Manager) observeAssociation(ap string, radio, wlan uint8, mac [6]byte) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	return m.admitStationLocked(ap, radio, wlan) && m.radioCapacityLocked(ap, radio, mac)
}
