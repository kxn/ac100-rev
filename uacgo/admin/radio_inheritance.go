package admin

import (
	"encoding/json"
	"sort"
	"uacgo/cweng"
)

// Only explicit radio fields override the inherited value. Advanced settings
// are an atomic profile; zero enum values are meaningful and never omitted.
func mergeRadio(base, over RadioSetting) RadioSetting {
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
	for _, r := range inheritedRadioSettings(cfg, ap.ID) {
		if r.PowerLevel != nil {
			for _, c := range ap.Capabilities {
				if c.RadioID == r.Radio {
					v := levelPower(*r.PowerLevel, c)
					r.Power = &v
				}
			}
		}
		out = append(out, r)
	}
	cfg.Radios = out
	return cfg
}
