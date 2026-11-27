package admin

import (
	"fmt"
	"time"
	"uacgo/controllercfg"
)

// radio_or_wserv_cfg_set_check in V6 apmng_rrm.lua protects the RF/WLAN
// database for the entire business operation. All configuration writers go
// through this boundary, including imports and inherited group profiles.
func (m *Manager) persistConfigLocked(next Config, source managementWrite) (err error) {
	priorVersion := m.config.Version
	defer func() {
		m.event("configuration.persist", "source", source, "previous_version", priorVersion, "requested_version", next.Version, "stored_version", m.config.Version, "interface", next.Interface, "services", len(next.Services), "radios", len(next.Radios), "policy", mobilityPolicyVersion(next), "configured_mode", configuredMobilityMode(next), "actual_mode", actualMobilityMode(next), "error", eventError(err))
	}()
	if err := validateConfig(next); err != nil {
		return err
	}
	next = m.prepareV4ModeSelectionLocked(next, source)
	priorKey := wirelessConfigKey(m.config)
	wirelessChanged := wirelessConfigKey(next) != priorKey
	channels := m.highPerformance.Channels
	// Client labels, AP names and program budgets must not expand every
	// AP's RF inheritance just to discover that no radio input changed.
	if wirelessChanged || source == managementRestore {
		next, channels = m.prepareHighPerformanceLocked(next, source)
		if err := validateConfig(next); err != nil {
			return err
		}
		wirelessChanged = wirelessConfigKey(next) != priorKey
	}
	if err := m.validateResourceUsage(next); err != nil {
		return err
	}
	if source != managementRRM && source != managementAPEvent && wirelessChanged {
		for _, job := range m.rrmJobs {
			switch job.State {
			case "preparing", "collecting", "planning", "applying":
				return fmt.Errorf("无线优化正在运行，请完成后修改射频或无线服务")
			}
		}
	}
	if err := atomicJSON(m.path, next); err != nil {
		return err
	}
	resourcesChanged := controllercfg.Effective(next.Resources) != controllercfg.Effective(m.config.Resources)
	if wirelessChanged {
		m.resetRoamingRadiosLocked(m.config, next)
	}
	previousMode := actualMobilityMode(m.config)
	v4Transition := usesV4Modes(m.config) || usesV4Modes(next)
	m.config = next
	m.highPerformance.Channels = channels
	if previousMode != actualMobilityMode(next) || source == managementRestore {
		m.highPerformance.ModeTargets = nil
		if previousMode != actualMobilityMode(next) && v4Transition {
			m.highPerformance.ModeTargets = map[string]time.Time{}
			for id, ap := range m.known {
				if ap.Online {
					m.highPerformance.ModeTargets[id] = ap.ConnectedAt
				}
			}
		}
		m.highPerformance.resetCollection()
		m.highPerformance.State = ""
		m.highPerformance.PendingScan = actualMobilityMode(next) == 1 && source != managementRestore
	}
	if resourcesChanged {
		m.applyControllerResources()
	}
	return nil
}

// Configuration revision also changes for labels and unrelated AP settings.
// Such writes must not cancel an RF operation. Include inherited radio
// profiles and memberships: changing them can change effective RF/WLAN state.
func wirelessConfigKey(cfg Config) string {
	type rfOptions struct {
		Radios []RadioSetting
		Mode   *APRFMode
		Region *uint8
	}
	rf := func(o APOptions) rfOptions { return rfOptions{o.Radios, o.RFMode, o.RegionCode} }
	type profile struct {
		AP, Group, Template string
		RF                  rfOptions
	}
	type group struct {
		ID string
		RF rfOptions
	}
	profiles := []profile{}
	groups, templates := []group{}, []group{}
	for _, p := range cfg.APProfiles {
		profiles = append(profiles, profile{p.AP, p.Group, p.Template, rf(p.Options)})
	}
	for _, g := range cfg.Groups {
		groups = append(groups, group{g.ID, rf(g.Options)})
	}
	for _, t := range cfg.Templates {
		templates = append(templates, group{t.ID, rf(t.Options)})
	}
	return configurationKey(struct {
		Policy            string
		Mode              int
		Services          []Service
		Radios            []RadioSetting
		Defaults          rfOptions
		Profiles          []profile
		Groups, Templates []group
		EDCARules         []EDCARule
		EDCAState         map[string]EDCABindingState
	}{mobilityPolicyVersion(cfg), actualMobilityMode(cfg), cfg.Services, cfg.Radios, rf(cfg.APDefaults), profiles, groups, templates, cfg.EDCARules, cfg.EDCAState}, time.Time{})
}

// Web RF writes are forbidden during RRM, but incoming AP lifecycle facts
// are not Web writes. Original Join still performs automatic group assignment.
// RRM's frozen measurement participants remain unchanged; refresh the config
// guard after this controller-owned mutation instead of aborting the job.
func (m *Manager) saveAPEventConfig(next Config) error {
	if err := m.saveManagementFrom(next, managementAPEvent); err != nil {
		return err
	}
	key := wirelessConfigKey(m.config)
	for id, job := range m.rrmJobs {
		switch job.State {
		case "preparing", "collecting", "planning":
			job.BaseSignature = key
		case "applying":
			job.AppliedSignature = key
		default:
			continue
		}
		m.rrmJobs[id] = job
	}
	return m.saveRRMJobs()
}
