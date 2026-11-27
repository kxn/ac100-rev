package admin

import (
	"fmt"
	"time"
	"uacgo/controllercfg"
)

// radio_or_wserv_cfg_set_check in V6 apmng_rrm.lua protects the RF/WLAN
// database for the entire business operation. All configuration writers go
// through this boundary, including imports and inherited group profiles.
func (m *Manager) persistConfigLocked(next Config, source managementWrite) error {
	if err := validateConfig(next); err != nil {
		return err
	}
	if err := m.validateResourceUsage(next); err != nil {
		return err
	}
	wirelessChanged := wirelessConfigKey(next) != wirelessConfigKey(m.config)
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
	m.config = next
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
		Services          []Service
		Radios            []RadioSetting
		Defaults          rfOptions
		Profiles          []profile
		Groups, Templates []group
		EDCARules         []EDCARule
		EDCAState         map[string]EDCABindingState
	}{cfg.Services, cfg.Radios, rf(cfg.APDefaults), profiles, groups, templates, cfg.EDCARules, cfg.EDCAState}, time.Time{})
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
