package admin

func retargetIDs(ids []string, old, target string) []string {
	out := make([]string, 0, len(ids))
	seen := map[string]bool{}
	for _, id := range ids {
		if id == old {
			id = target
		}
		if !seen[id] {
			out = append(out, id)
			seen[id] = true
		}
	}
	return out
}
func retargetPolicies(cfg *Config, old, target string) {
	if cfg.Mesh != nil {
		cfg.Mesh.Members = retargetMeshMembers(cfg.Mesh.Members, old, target)
	}

	if cfg.Rates != nil {
		cfg.Rates.APs = retargetIDs(cfg.Rates.APs, old, target)
	}
	if cfg.Mobility != nil {
		for i := range cfg.Mobility.Balance {
			cfg.Mobility.Balance[i].APs = retargetIDs(cfg.Mobility.Balance[i].APs, old, target)
		}
		for i := range cfg.Mobility.Roaming {
			cfg.Mobility.Roaming[i].APs = retargetIDs(cfg.Mobility.Roaming[i].APs, old, target)
		}
	}
	if cfg.Protection != nil {
		for i := range cfg.Protection.Rules {
			cfg.Protection.Rules[i].APs = retargetIDs(cfg.Protection.Rules[i].APs, old, target)
		}
	}
	for i := range cfg.RRM {
		cfg.RRM[i].APs = retargetIDs(cfg.RRM[i].APs, old, target)
	}
	for i := range cfg.EDCARules {
		cfg.EDCARules[i].APs = retargetIDs(cfg.EDCARules[i].APs, old, target)
	}
	if label, ok := cfg.Labels[old]; ok {
		cfg.Labels[target] = label
		delete(cfg.Labels, old)
	}
}
