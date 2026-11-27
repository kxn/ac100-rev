package admin

import (
	"time"
	"uacgo/mobility"
)

type roamingParameters struct {
	Settings RoamSettings
	Mode     int
	Strategy uint8
}

func roamingParametersFor(ap string, cfg Config) roamingParameters {
	strategy := uint8(mobility.FirmwareStrategy)
	// V4 balance_init registers balance_roam_strategy_get; enabling
	// balancing changes the57 strategy byte from2 to1. V6 removed that
	// registration. Use the same value for delivery and readiness keys.
	if roamingPolicy(cfg) == mobility.V4Policy {
		if rule := balanceFor(cfg.Mobility, ap, cfg); rule != nil && rule.Enabled {
			strategy = 1
		}
	}
	return roamingParameters{roamingFor(cfg.Mobility, ap, cfg), actualMobilityMode(cfg), strategy}
}

func (p roamingParameters) wire() []byte {
	b := p.Settings.wire(p.Mode)
	b[20] = p.Strategy
	return b
}

// A policy family owns both the mode controller and station decisions.
// An automatic V4 controller that demotes to2 remains V4; it must not
// silently acquire V6's rate-gain selector merely because its mode changed.
func roamingPolicy(cfg Config) mobility.Policy {
	if usesV4Modes(cfg) {
		return mobility.V4Policy
	}
	return mobility.V6Policy
}

// mode_source is the persisted policy selector as well as the legacy import
// tag. Keep one authority: a second writable version field could disagree
// with it on restore or on a later edit of a rule.
func mobilityPolicyVersion(cfg Config) string {
	if usesV4Modes(cfg) {
		return "v4"
	}
	return "v6"
}

func mobilityPolicyReference(cfg Config) string {
	if usesV4Modes(cfg) {
		return v4ModeSource
	}
	return v6ModeSource
}

func admissionResultCodes(cfg Config) (unavailable, balanceRejected uint32) {
	if roamingPolicy(cfg) == mobility.V4Policy {
		return 0x25, 0x25
	}
	return 0x26, 0x27
}

func (m *Manager) selectRoamingLocked(ap string, radio uint8, mac [6]byte, currentRSSI int8, currentRate int, settings RoamSettings, neighbors []mobility.Candidate) []mobility.Candidate {
	observer, decision := m.selectionObserver(ap, radio, mac, currentRSSI, currentRate, settings, neighbors)
	finish := func(rows []mobility.Candidate) []mobility.Candidate {
		m.event("roaming.selection_result", "decision_id", decision, "ap_id", ap, "client", eventMAC(mac), "selected_count", len(rows))
		return rows
	}
	if roamingPolicy(m.config) == mobility.V4Policy {
		band := radioBand(m.known[ap], radio)
		if band < 0 {
			band = 0
		}
		selection := mobility.V4Selection{Observe: observer, CurrentRSSI: currentRSSI, CurrentBand: band, ActualMode: actualMobilityMode(m.config), ThresholdType2G: settings.Band2G.Type, ThresholdType5G: settings.Band5G.Type, RSSI2G: int8(settings.Band2G.RSSI), RSSI5G: int8(settings.Band5G.RSSI), Difference: uint8(settings.Difference)}
		return finish(selection.Select(neighbors, func(n mobility.Candidate) bool {
			return m.pseudoAssociationLocked(n, mac)
		}))
	}
	return finish((mobility.Selection{Observe: observer, CurrentRSSI: currentRSSI, CurrentRate: currentRate, ThresholdType2G: settings.Band2G.Type, ThresholdType5G: settings.Band5G.Type}).Select(neighbors))
}

// V4 pseudo-association checks the strict radio count before the service
// and registered balancing callbacks. Unlike a real reassociation, a full
// radio does not exempt this MAC if it already has a row there. Balancing
// can consume a rejection attempt; this call never associates the station.
// Excluded authentication/Portal callbacks are outside this application.
func (m *Manager) pseudoAssociationLocked(n mobility.Candidate, mac [6]byte) bool {
	limit := m.radioCapacityLimitLocked(n.AP, n.Radio)
	count, _ := m.clients.RadioCount(n.AP, n.Radio)
	if limit <= 0 || count >= limit || !m.admitStationLocked(n.AP, n.Radio, n.WLAN) {
		m.event("roaming.pseudo_association", "ap_id", n.AP, "radio", n.Radio, "client", eventMAC(mac), "allowed", false, "reason", "capacity_or_service_unavailable", "radio_clients", count, "radio_limit", limit)
		return false
	}
	role := roamingRole(m.known[n.AP])
	if role > 4 && role != 6 && role != 8 {
		return true // Original balance callback skips non-AP roles.
	}
	return m.balanceAdmission(n.AP, mac, time.Now())
}
