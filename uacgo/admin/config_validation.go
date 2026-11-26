package admin

import (
	"fmt"
	"uacgo/cweng"
)

// Intrinsic configuration constraints apply equally on startup, restore and
// every write. They do not depend on a potentially stale AP capability cache.
func validateConfig(cfg Config) error {
	if err := validateManagement(cfg); err != nil {
		return err
	}
	if err := validateEDCARules(cfg.EDCARules, cfg); err != nil {
		return err
	}
	if err := validateMesh(cfg.Mesh); err != nil {
		return err
	}
	if err := validateStorm(cfg.Storm); err != nil {
		return err
	}
	if err := validateProtection(cfg.Protection, cfg); err != nil {
		return err
	}
	if err := validateRRMTimeConflicts(cfg); err != nil {
		return err
	}
	if err := validateRRMRules(cfg.RRM, cfg); err != nil {
		return err
	}
	if err := validateMulticastGroups(cfg.MulticastGroups); err != nil {
		return err
	}
	if cfg.Mobility != nil {
		if err := cfg.Mobility.validate(cfg); err != nil {
			return err
		}
	}
	if cfg.Rates != nil {
		if err := validateRates(*cfg.Rates); err != nil {
			return err
		}
		for _, id := range cfg.Rates.Groups {
			found := false
			for _, g := range cfg.Groups {
				found = found || g.ID == id
			}
			if !found {
				return fmt.Errorf("速率表引用不存在的分组")
			}
		}
	}
	ids := map[string]bool{}
	for _, s := range cfg.Services {
		if s.ID == "" || ids[s.ID] {
			return fmt.Errorf("无线服务编号为空或重复")
		}
		ids[s.ID] = true
		if err := validate(s); err != nil {
			return err
		}
	}
	pools := map[uint16]bool{}
	for _, p := range cfg.VLANPools {
		if pools[p.ID] {
			return fmt.Errorf("VLAN 池编号重复")
		}
		pools[p.ID] = true
		if err := validatePool(p); err != nil {
			return err
		}
	}
	for _, s := range cfg.Services {
		if id := serviceOptions(s).VLANPool; id != 0 && !pools[id] && !s.Deleting {
			return fmt.Errorf("无线服务引用不存在的 VLAN 池")
		}
	}
	radios := map[string]bool{}
	for _, r := range cfg.Radios {
		key := fmt.Sprintf("%s/%d", r.AP, r.Radio)
		if r.AP == "" || r.Radio == 0 || r.Radio > 31 || radios[key] {
			return fmt.Errorf("射频绑定无效或重复")
		}
		radios[key] = true
		if r.Channel != nil && (*r.Channel < 0 || *r.Channel > 233) || r.Power != nil && (*r.Power < 0 || *r.Power > 100) || r.PowerLevel != nil && (*r.PowerLevel < 1 || *r.PowerLevel > 10) {
			return fmt.Errorf("信道/功率无效")
		}
		if a := r.Advanced; a != nil {
			if a.Antenna != 0 || a.Mode < 0 || a.Mode > 13 || a.Bandwidth < 0 || a.Bandwidth > 7 || a.MaxClients < 1 || a.MaxClients > 65535 || a.Beacon < 40 || a.Beacon > 1000 || a.DTIM < 1 || a.DTIM > 255 || a.RTS < 1 || a.RTS > 2346 || a.Fragmentation < 256 || a.Fragmentation > 2346 {
				return fmt.Errorf("高级射频参数无效")
			}
			if !radioModeBandwidth(a.Mode, a.Bandwidth) || radioNeedsWMM(a.Mode) && !a.WMM {
				return fmt.Errorf("无线模式、带宽与 WMM 组合无效")
			}
		}
	}

	retired := map[string]bool{}
	for _, id := range cfg.RetiredAPs {
		if id == "" || retired[id] {
			return fmt.Errorf("已替换 AP 编号无效或重复")
		}
		retired[id] = true
	}
	return nil
}

// Runs under Manager.mu. Editors additionally validate the effective settings
// against each known model. Reconciliation repeats that check for the live AP.
func (m *Manager) validateConfigForAPs(cfg Config) error {
	for _, profile := range cfg.APProfiles {
		if ap, ok := m.known[profile.AP]; ok {
			o, err := effectiveAPOptions(cfg, ap)
			if err != nil {
				return err
			}
			if _, err = managementElements(o, ap); err != nil {
				return fmt.Errorf("AP %s: %w", profile.AP, err)
			}
		}
	}

	for _, ap := range m.known {
		if err := validateProtectionForAP(cfg.Protection, protectionFor(cfg.Protection, ap.ID, cfg), ap); err != nil {
			return err
		}
		for _, r := range effectiveRadioConfig(cfg, ap).Radios {
			if r.AP == ap.ID {
				if err := validateKnownRadio(r, ap); err != nil {
					return err
				}
			}
		}
	}
	return nil
}

func validateKnownRadio(r RadioSetting, ap cweng.APStatus) error {
	for _, c := range ap.Capabilities {
		if c.RadioID == r.Radio {
			if r.Power != nil && (*r.Power < c.MinPower || *r.Power > c.MaxPower) {
				return fmt.Errorf("AP %s 的射频功率超出能力", ap.ID)
			}
			return validateAdvanced(r, ap, c)
		}
	}
	if len(ap.Capabilities) > 0 || ap.Radios > 0 && int(r.Radio) > ap.Radios {
		return fmt.Errorf("AP %s 未声明射频 %d", ap.ID, r.Radio)
	}
	return nil
}
