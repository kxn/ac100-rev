package admin

import (
	"sort"
	"time"
	"uacgo/cweng"
	"uacgo/mobility"
)

func automaticLimits(p *MobilityConfig) mobility.V4AutomaticLimits {
	if p != nil && p.AutomaticLimits != nil {
		return *p.AutomaticLimits
	}
	return mobility.V4DefaultAutomaticLimits()
}
func (m *Manager) automaticCountsLocked() (int, int) {
	aps, stations := 0, 0
	for _, ap := range m.known {
		if ap.Online && roamingRole(ap) != 7 {
			aps++
		}
	}
	if m.clients != nil {
		for _, c := range m.clients.All() {
			if c.State == "connected" {
				stations++
			}
		}
	}
	return aps, stations
}

// The actual mode is controller state, not an editor input. A manual change
// to configured0 rechecks both counts; unrelated edits cannot promote a
// sticky compatibility state by posting an old current_network_mode value.
func (m *Manager) prepareV4ModeSelectionLocked(next Config, source managementWrite) Config {
	if !usesV4Modes(next) {
		return next
	}
	p := *next.Mobility
	if p.NetworkMode != 0 {
		p.CurrentMode = 0
	} else if source == managementUser {
		changed := !usesV4Modes(m.config) || configuredMobilityMode(m.config) != 0
		if changed {
			aps, stations := m.automaticCountsLocked()
			p.CurrentMode = mobility.V4CheckMode(0, actualMobilityMode(m.config), true, aps, stations, automaticLimits(&p))
		} else {
			p.CurrentMode = m.config.Mobility.CurrentMode
		}
	} else if source == managementRestore {
		aps, stations := m.automaticCountsLocked()
		p.CurrentMode = mobility.V4CheckMode(0, p.CurrentMode, false, aps, stations, automaticLimits(&p))
	}
	next.Mobility = &p
	return next
}

func (m *Manager) initializeAutomaticMode() bool {
	if !usesV4Modes(m.config) || configuredMobilityMode(m.config) != 0 {
		return false
	}
	p := *m.config.Mobility
	current := mobility.V4CheckMode(0, p.CurrentMode, false, 0, 0, automaticLimits(&p))
	if p.CurrentMode == current {
		return false
	}
	p.CurrentMode = current
	m.config.Mobility = &p
	return true
}

func (m *Manager) automaticAPJoinedLocked(ap cweng.APStatus) {
	if !usesV4Modes(m.config) || configuredMobilityMode(m.config) != 0 || roamingRole(ap) == 7 {
		return
	}
	aps, _ := m.automaticCountsLocked()
	mode := mobility.V4ModeAfterJoin(0, actualMobilityMode(m.config), aps, automaticLimits(m.config.Mobility))
	if mode != actualMobilityMode(m.config) {
		m.changeAutomaticModeLocked(mode, false, time.Now)
	}
}

// intelligent-roam's association callback has priority9, statistics' target
// relocation has priority10. Call this before AssociateAt, not on disconnect
// or on an arbitrary statistics/timer tick.
func (m *Manager) automaticStationAssociatedLocked(ap string, at time.Time) {
	if !usesV4Modes(m.config) || configuredMobilityMode(m.config) != 0 || actualMobilityMode(m.config) != 1 {
		return
	}
	known, ok := m.known[ap]
	if !ok || !known.Online || at.Before(known.ConnectedAt) {
		return
	}
	_, stations := m.automaticCountsLocked()
	mode := mobility.V4ModeAfterAssociation(0, 1, stations, automaticLimits(m.config.Mobility))
	if mode != 1 {
		m.changeAutomaticModeLocked(mode, true, time.Now)
	}
}

func (m *Manager) changeAutomaticModeLocked(mode int, redistribute bool, clock func() time.Time) {
	aps, stations := m.automaticCountsLocked()
	m.event("mode.transition_requested", "previous_mode", actualMobilityMode(m.config), "mode", mode, "redistribute_channels", redistribute, "aps", aps, "stations", stations, "limits", automaticLimits(m.config.Mobility))
	next := m.config
	p := *next.Mobility
	p.CurrentMode = mode
	next.Mobility = &p
	if redistribute {
		next = m.redistributeCompatibilityChannelsLocked(next, clock)
	}
	next.Version = m.config.Version + 1
	err := m.persistConfigLocked(next, managementAPEvent)
	status := ApplyStatus{AP: "controller", Service: "automatic-mode", State: "acknowledged", At: clock()}
	if err != nil {
		status.State, status.Error = "failed", err.Error()
	}
	m.status["controller/automatic-mode"] = status
}

// Only the station-overload entry calls this. AP-count demotion and manual
// mode selection do not redistribute channels. Both per-AP counts must be
// strictly below floor(station_limit/AP_limit); idle statistics still count.
func (m *Manager) redistributeCompatibilityChannelsLocked(cfg Config, clock func() time.Time) Config {
	limits := automaticLimits(cfg.Mobility)
	threshold := limits.Stations / limits.APs
	counts := map[string]int{}
	for _, c := range m.clients.All() {
		if c.State == "connected" {
			counts[c.APID]++
		}
	}
	aps := []cweng.APStatus{}
	for _, ap := range m.known {
		role := roamingRole(ap)
		if ap.Online && (role <= 4 || role == 6 || role == 8) {
			aps = append(aps, ap)
		}
	}
	sort.SliceStable(aps, func(i, j int) bool {
		if aps[i].EntryID != aps[j].EntryID {
			return aps[i].EntryID < aps[j].EntryID
		}
		return aps[i].ID < aps[j].ID
	})
	cfg.Radios = append([]RadioSetting{}, cfg.Radios...)
	for _, ap := range aps {
		if counts[ap.ID] >= threshold || m.stationStatistics.ActiveStationsOnAP(ap.ID, clock()) >= threshold {
			continue
		}
		channel2, channel5 := mobility.V4RedistributionChannels(uint32(clock().Unix()))
		m.event("mode.redistribute", "ap_id", ap.ID, "clients", counts[ap.ID], "threshold", threshold, "channel_2g", channel2, "channel_5g", channel5)
		for _, r := range effectiveRadioConfig(cfg, ap).Radios {
			if r.AP != ap.ID {
				continue
			}
			channel := 0
			for _, c := range ap.Capabilities {
				if c.RadioID == r.Radio {
					if c.Band == "2.4 GHz" {
						channel = channel2
					}
					if c.Band == "5 GHz" {
						channel = channel5
					}
				}
			}
			if channel == 0 {
				continue
			}
			index := -1
			for i, prior := range cfg.Radios {
				if prior.AP == ap.ID && prior.Radio == r.Radio {
					index = i
					break
				}
			}
			if index < 0 {
				cfg.Radios = append(cfg.Radios, RadioSetting{AP: ap.ID, Radio: r.Radio})
				index = len(cfg.Radios) - 1
			}
			setting := cloneRadio(cfg.Radios[index])
			setting.Channel = &channel
			cfg.Radios[index] = setting
		}
	}
	return cfg
}

// A new AP joining automatic mode's compatibility state receives57, not a
// gratuitous9d. Existing transition participants receive9d first. Explicit
// standalone silence overrides are also applied to new compatible APs.
func (m *Manager) modeBlockRequiredLocked(ap cweng.APStatus, cfg Config) bool {
	if !ap.HasCapability(72) {
		return false
	}
	if usesV4Modes(cfg) && actualMobilityMode(cfg) == 2 {
		epoch, member := m.highPerformance.ModeTargets[ap.ID]
		return member && epoch == ap.ConnectedAt || cfg.Mobility.Silence != nil
	}
	return true
}

func (m *Manager) modeBeforeRadio(ap cweng.APStatus) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	epoch, member := m.highPerformance.ModeTargets[ap.ID]
	return member && epoch == ap.ConnectedAt
}
