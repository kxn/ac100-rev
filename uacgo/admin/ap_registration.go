package admin

import (
	"fmt"
	"slices"
	"uacgo/cweng"
	"unicode/utf8"
)

// First registration copies a model template once, just as apmngr_ap_add
// does. Reconnects, old inventory rows, and imported AP snapshots never
// become new devices merely because they lack a live session.
func (m *Manager) registerAPJoin(ap cweng.APStatus, first bool) error {
	m.mu.Lock()
	defer m.mu.Unlock()
	next := m.config
	next.APProfiles = append([]APProfile{}, next.APProfiles...)
	exists := false
	for _, p := range next.APProfiles {
		exists = exists || p.AP == ap.ID
	}
	changed := false
	template := ""
	namePrefix := ap.Model
	if !exists && !slices.Contains(next.RetiredAPs, ap.ID) {
		p := APProfile{AP: ap.ID}
		if ap.MeshParent != "" {
			p.Group = apGroup(next, ap.MeshParent)
		}
		if first {
			p.Options = initialTemplateOptions(APOptions{}, ap, next)
			for _, t := range next.Templates {
				if !t.ApplyOnJoin || ap.ModelID == 0 || t.ModelID != ap.ModelID {
					continue
				}
				template = t.ID
				namePrefix = t.Name
				p.InitialTemplate, p.Group = t.ID, t.Group
				p.Options = initialTemplateOptions(t.Options, ap, next)
				break
			}
		}
		if first && ap.Name == "" && namePrefix != "" {
			// Original apmngr_ap_add keeps a provided WTP name; otherwise it
			// appends the assigned ID to template/model name, up to154 bytes.
			suffix := fmt.Sprintf("-%04d", ap.EntryID)
			maxPrefix := 153 - len(suffix)
			if maxPrefix > 148 {
				maxPrefix = 148
			}
			for len(namePrefix) > maxPrefix {
				_, size := utf8.DecodeLastRuneInString(namePrefix)
				namePrefix = namePrefix[:len(namePrefix)-size]
			}
			p.Name = namePrefix + suffix
		}
		next.APProfiles = append(next.APProfiles, p)
		changed = true
		// _apmngr_pkt_re_config_follow_cap inherits the parent's region only
		// when both parent and child advertise that control (capability65).
		if first && ap.MeshParent != "" && ap.HasCapability(65) {
			if parent, ok := m.known[ap.MeshParent]; ok && parent.HasCapability(65) {
				parentOptions, err := effectiveAPOptions(next, parent)
				if err != nil {
					return err
				}
				last := len(next.APProfiles) - 1
				next.APProfiles[last].Options.RegionCode = parentOptions.RegionCode
			}
		}
	}
	// Original Join applies IP strategies after creating/finding the entry.
	// Encapsulated children inherit their parent group and skip that IP pass.
	changed = m.groupAPJoined(&next, ap) || changed
	if changed {
		if err := m.saveAPEventConfig(next); err != nil {
			return err
		}
	}
	m.event("ap.registration", "ap_id", ap.ID, "session", ap.ConnectedAt,
		"first", first && !exists, "model_id", ap.ModelID, "initial_template", template,
		"group", apGroup(next, ap.ID), "encapsulated", ap.Encapsulated)
	return nil
}

// The AP creation path preserves its freshly computed Mesh switch instead of
// copying that byte from the model template (V6 apmngr_ap_add, +0x234).
func initialTemplateOptions(o APOptions, ap cweng.APStatus, cfg Config) APOptions {
	o = inheritedRadioOptions(supportedInheritedOptions(cloneOptions(o), ap), ap)
	// +0x1cc is FIT/FAT button state; creation preserves its capability default.
	o.FitFatButton = nil
	if ap.HasCapability(73) {
		off := false
		o.FitFatButton = &off
	}
	// Region is +0x3c1, outside the copied parameter block.
	o.RegionCode = nil
	// RFMode is the post-Join role selector (+0x3c0), outside the copy.
	o.RFMode = nil
	if ap.HasCapability(44) {
		enabled := cfg.Mesh != nil && cfg.Mesh.Enabled && (roamingRole(ap) == 2 || roamingRole(ap) == 3)
		o.Mesh = &enabled
	} else {
		o.Mesh = nil
	}
	return o
}
