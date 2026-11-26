package admin

import (
	"encoding/binary"
	"fmt"
	"net"
	"reflect"
	"slices"
	"uacgo/cweng"
)

// V6 apmng_set.lua exposes only ip_range. Nil preserves existing manual
// groups; an explicitly disabled strategy retains its range and membership.
type APGroupStrategy struct {
	Enabled bool   `json:"enabled"`
	Type    string `json:"type"`
	Start   string `json:"start_ip"`
	End     string `json:"end_ip"`
}

func ipv4Number(s string) (uint32, bool) {
	ip := net.ParseIP(s).To4()
	if ip == nil {
		return 0, false
	}
	return binary.BigEndian.Uint32(ip), true
}

func validateGroupStrategies(groups []APGroup) error {
	for i, g := range groups {
		s := g.Strategy
		if s == nil {
			continue
		}
		if s.Type != "ip_range" {
			return fmt.Errorf("AP 自动分组仅支持 IP 范围")
		}
		if !s.Enabled && s.Start == "" && s.End == "" {
			continue
		}
		lo, a := ipv4Number(s.Start)
		hi, b := ipv4Number(s.End)
		if !a || !b || lo > hi {
			return fmt.Errorf("AP 自动分组的 IPv4 起止范围无效")
		}
		// get_ap_group_strategy_ip selects all nondefault groups, including
		// disabled strategies. Both endpoints are inclusive.
		for _, other := range groups[:i] {
			if p := other.Strategy; p != nil {
				x, okX := ipv4Number(p.Start)
				y, okY := ipv4Number(p.End)
				if okX && okY && lo <= y && x <= hi {
					return fmt.Errorf("AP 自动分组的 IP 范围重叠")
				}
			}
		}
	}
	return nil
}

func apGroup(cfg Config, ap string) string {
	for _, p := range cfg.APProfiles {
		if p.AP == ap {
			return p.Group
		}
	}
	return ""
}
func setAPGroup(cfg *Config, ap, group string) bool {
	if apGroup(*cfg, ap) == group {
		return false
	}
	cfg.APProfiles = append([]APProfile{}, cfg.APProfiles...)
	for i := range cfg.APProfiles {
		if cfg.APProfiles[i].AP == ap {
			cfg.APProfiles[i].Group = group
			return true
		}
	}
	cfg.APProfiles = append(cfg.APProfiles, APProfile{AP: ap, Group: group})
	return true
}

// apmngr_switch_group_handle @5da88c copies the control peer address into
// an AP snapshot, then foreach_group uses that SAME snapshot for every rule.
// The linked list is insertion ordered (group_add @5b96fc), as is Groups.
// Group edits @5f70f0 additionally skip upgrading APs and align Mesh children
// to the parent. These are event operations, never a polling reconciliation.
func (m *Manager) groupStrategyTarget(cfg Config, ap cweng.APStatus, original string, g APGroup, edit bool) (string, bool) {
	if slices.Contains(cfg.RetiredAPs, ap.ID) {
		return "", false
	}
	s := g.Strategy
	if s == nil || !s.Enabled {
		return "", false
	}
	if edit && m.upgradeActive[ap.ID] != nil {
		return "", false
	}
	if ap.MeshParent != "" {
		if _, exists := m.known[ap.MeshParent]; exists && !slices.Contains(cfg.RetiredAPs, ap.MeshParent) {
			parent := apGroup(cfg, ap.MeshParent)
			if original == parent {
				return "", false
			}
			if edit {
				return parent, true
			}
		}
	}
	host, _, err := net.SplitHostPort(ap.Address)
	if err != nil {
		host = ap.Address
	}
	ip, ok := ipv4Number(host)
	lo, a := ipv4Number(s.Start)
	hi, b := ipv4Number(s.End)
	if !ok || !a || !b || s.Type != "ip_range" {
		return "", false
	}
	inside := lo <= ip && ip <= hi
	if original != g.ID && inside {
		return g.ID, true
	}
	if original == g.ID && !inside {
		return "", true
	}
	return "", false
}

func (m *Manager) groupAPJoined(next *Config, ap cweng.APStatus) bool {
	if slices.Contains(next.RetiredAPs, ap.ID) {
		return false
	}
	changed := false
	// New Mesh entries receive the parent's group before the direct-Join
	// strategy callback (60b040: local_1026 = parent's local_c4e).
	if ap.MeshParent != "" {
		if _, exists := m.known[ap.MeshParent]; exists && !slices.Contains(next.RetiredAPs, ap.MeshParent) {
			hasProfile := false
			for _, p := range next.APProfiles {
				hasProfile = hasProfile || p.AP == ap.ID
			}
			if !hasProfile {
				changed = setAPGroup(next, ap.ID, apGroup(*next, ap.MeshParent))
			}
		}
	}
	// Encapsulated child Join bypasses switch_group_handle; creation inherits
	// its parent group rather than using the parent's control IP as its own.
	if ap.Encapsulated {
		return changed
	}
	original := apGroup(*next, ap.ID)
	for _, g := range next.Groups {
		if group, apply := m.groupStrategyTarget(*next, ap, original, g, false); apply {
			changed = setAPGroup(next, ap.ID, group) || changed
		}
	}
	return changed
}

func (m *Manager) compileGroupEdits(next Config) Config {
	for _, g := range next.Groups {
		changed := true
		for _, old := range m.config.Groups {
			if old.ID == g.ID {
				changed = old.Name != g.Name || !reflect.DeepEqual(old.Strategy, g.Strategy)
				break
			}
		}
		if !changed {
			continue
		}
		// Each group operation takes a fresh AP DB snapshot; conditions for
		// this group don't observe another AP callback's mutations.
		before := next
		for _, ap := range m.known {
			if group, apply := m.groupStrategyTarget(before, ap, apGroup(before, ap.ID), g, true); apply {
				setAPGroup(&next, ap.ID, group)
			}
		}
	}
	return next
}
