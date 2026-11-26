package admin

import (
	"encoding/json"
	"math"
	"sort"
	"uacgo/cweng"
)

// Only explicit radio fields override the inherited value. Advanced scalar
// values form one profile; optional model features inherit when unspecified.
func mergeRadio(base, over RadioSetting) RadioSetting {
	if base.Advanced != nil && over.Advanced != nil {
		a := *over.Advanced
		if a.EDCA == nil {
			a.EDCA = base.Advanced.EDCA
		}
		if a.DCS == nil {
			a.DCS = base.Advanced.DCS
		}
		if a.Reject == nil {
			a.Reject = base.Advanced.Reject
		}
		over.Advanced = &a
	}
	a, _ := json.Marshal(base)
	b, _ := json.Marshal(over)
	var x, y map[string]json.RawMessage
	_ = json.Unmarshal(a, &x)
	_ = json.Unmarshal(b, &y)
	for k, v := range y {
		x[k] = v
	}
	if over.Power != nil && over.PowerLevel == nil {
		delete(x, "power_level")
	}
	if over.PowerLevel != nil && over.Power == nil {
		delete(x, "power_dbm")
	}
	a, _ = json.Marshal(x)
	var out RadioSetting
	_ = json.Unmarshal(a, &out)
	return out
}
func inheritedRadioSettings(cfg Config, ap string) []RadioSetting {
	options := cfg.APDefaults
	for _, p := range cfg.APProfiles {
		if p.AP != ap {
			continue
		}
		for _, t := range cfg.Templates {
			if t.ID == p.Template {
				options = mergeOptions(options, t.Options)
			}
		}
		for _, g := range cfg.Groups {
			if g.ID == p.Group {
				options = mergeOptions(options, g.Options)
			}
		}
		options = mergeOptions(options, p.Options)
	}
	byID := map[uint8]RadioSetting{}
	for _, r := range options.Radios {
		r.AP = ap
		byID[r.Radio] = r
	}
	for _, r := range cfg.Radios {
		if r.AP == ap {
			byID[r.Radio] = mergeRadio(byID[r.Radio], r)
		}
	}
	out := []RadioSetting{}
	for _, r := range byID {
		out = append(out, r)
	}
	sort.Slice(out, func(i, j int) bool { return out[i].Radio < out[j].Radio })
	return out
}
func effectiveRadioConfig(cfg Config, ap cweng.APStatus) Config {
	// Program budgets don't belong to an AP's desired configuration or
	// commit identity. Resource-only edits must not reconfigure the radios.
	cfg.Resources = nil
	cfg.APDefaults = inheritedRadioOptions(cfg.APDefaults, ap)
	cfg.Templates = append([]APTemplate{}, cfg.Templates...)
	for i := range cfg.Templates {
		cfg.Templates[i].Options = inheritedRadioOptions(cfg.Templates[i].Options, ap)
	}
	cfg.Groups = append([]APGroup{}, cfg.Groups...)
	for i := range cfg.Groups {
		cfg.Groups[i].Options = inheritedRadioOptions(cfg.Groups[i].Options, ap)
	}
	// Keep other AP entries intact for global snapshot semantics.
	out := []RadioSetting{}
	for _, r := range cfg.Radios {
		if r.AP != ap.ID {
			out = append(out, r)
		}
	}
	byID := map[uint8]RadioSetting{}
	for _, c := range ap.Capabilities {
		if completeRadioCapability(c) {
			byID[c.RadioID] = defaultAPRadio(ap, c)
		}
	}
	// Inherited drafts must pass the same per-radio normalization before
	// becoming AP settings. Explicit RF rows are already controller DB state:
	// in particular a peer result may use the current RRST table rather than
	// the normalizer's table0, so do not normalize that snapshot again here.
	inherited := cfg
	inherited.Radios = nil
	for _, r := range inheritedRadioSettings(inherited, ap.ID) {
		byID[r.Radio] = mergeRadio(byID[r.Radio], r)
	}
	for _, c := range ap.Capabilities {
		if r, ok := byID[c.RadioID]; ok {
			byID[c.RadioID] = normalizeLinkageRadio(r, c, cfg, ap)
		}
	}
	for _, r := range cfg.Radios {
		if r.AP == ap.ID {
			byID[r.Radio] = mergeRadio(byID[r.Radio], r)
		}
	}
	ids := []int{}
	for id := range byID {
		ids = append(ids, int(id))
	}
	sort.Ints(ids)
	for _, id := range ids {
		r := byID[uint8(id)]
		if r.PowerLevel != nil {
			for _, c := range ap.Capabilities {
				if c.RadioID == r.Radio {
					v := levelPower(*r.PowerLevel, c)
					r.Power = &v
				}
			}
		}
		out = append(out, applyEDCAState(r, cfg, ap))
	}

	cfg.Radios = out
	return cfg
}

// rdmngr_db_init_comPara @726b98 initializes controller-owned RF state for
// every active radio. A missing override must not mean "keep the AP's old
// configuration" or "pin whichever channel was most recently observed".
func defaultAPRadio(ap cweng.APStatus, c cweng.RadioCapability) RadioSetting {
	on, channel, level := true, 0, 10
	a := defaultRadioAdvanced(c)
	if p := ap.RadioLinkage; p != nil {
		i := int(c.RadioID) - 1
		if i >= 0 && i < len(p.DefaultChannels) {
			channel = int(p.DefaultChannels[i])
		}
		if i >= 0 && i < len(p.DefaultBandwidths) {
			a.Bandwidth = int(p.DefaultBandwidths[i])
		}
	}
	if c.DefaultPower != 0 && c.MaxPower > c.MinPower {
		level = 1 + int(math.Round(float64(c.DefaultPower-c.MinPower)*9/float64(c.MaxPower-c.MinPower)))
		level = max(1, min(10, level))
	}
	if ap.HasCapability(9) {
		a.DCS = &DCSConfig{Mode: 0, Interval: 8, Occupancy: 50, Tolerance: 20}
	}
	if ap.HasCapability(21) {
		a.Reject = &AdmissionControl{Enabled: true, Threshold: -60, Difference: 6}
	}
	if ap.HasCapability(61) {
		a.EDCA = &EDCAConfig{Queues: defaultEDCAQueues()}
		if ap.SubCapabilities[61]&2 != 0 {
			mode := 0
			a.EDCA.Mode = &mode
		}
	}
	power := levelPower(level, c)
	return RadioSetting{AP: ap.ID, Radio: c.RadioID, Enabled: &on, Channel: &channel, Power: &power, PowerLevel: &level, Advanced: &a}
}
func completeRadioCapability(c cweng.RadioCapability) bool {
	return c.RadioID > 0 && c.FunctionType != 1 && c.MaxClients > 0 && len(c.Modes) > 0 && len(c.Bandwidths) > 0 && len(c.Channels) > 0
}
