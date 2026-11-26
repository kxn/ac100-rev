package admin

import "uacgo/cweng"

func (m *Manager) configurationSettled(ap cweng.APStatus, cfg Config) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	return m.settled[ap.ID] == configurationKey(cfg, ap.ConnectedAt)
}
func (m *Manager) navigationReason(ap, reason string) {
	m.mu.Lock()
	defer m.mu.Unlock()
	key := ap + "/band-navigation"
	if st, ok := m.status[key]; ok {
		st.Reason = reason
		m.status[key] = st
	}
}

// The global preference is only usable where the same service is present on
// both active bands. Steering toward a disabled radio can strand clients.
func effectiveBandNavigation(ap cweng.APStatus, cfg Config) (*BandNavigation, string) {
	if cfg.BandNavigation == nil {
		return nil, ""
	}
	b := *cfg.BandNavigation
	if !b.Enabled {
		return &b, "全局策略已停用"
	}
	two, five := []uint8{}, []uint8{}
	for _, c := range ap.Capabilities {
		if radioDisabled(cfg, ap.ID, c.RadioID) {
			continue
		}
		switch c.Band {
		case "2.4 GHz":
			two = append(two, c.RadioID)
		case "5 GHz":
			five = append(five, c.RadioID)
		}
	}
	for _, s := range cfg.Services {
		if !s.Enabled || s.Deleting {
			continue
		}
		target := serviceTargets(s, ap.ID, cfg)
		if !target {
			continue
		}
		selected := selectedServiceRadios(s, ap)
		for _, r2 := range two {
			for _, r5 := range five {
				bind2, vlan2 := binding(s, ap.ID, r2)
				bind5, vlan5 := binding(s, ap.ID, r5)
				if selected[r2] && selected[r5] && bind2 && bind5 && vlan2 == vlan5 {
					return &b, "双频同名服务已启用"
				}
			}
		}
	}
	b.Enabled = false
	return &b, "缺少同时启用且 VLAN 一致的双频同名服务"
}
