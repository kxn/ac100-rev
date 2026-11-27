package admin

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
	"time"
	"uacgo/controllercfg"
	"uacgo/cweng"
)

type RRMBand struct {
	Bandwidth         int   `json:"bandwidth"`
	Channels          []int `json:"channels"`
	SecondaryChannels []int `json:"secondary_channels,omitempty"` // V4's separate second-5GHz domain
	PowerThreshold    int   `json:"power_threshold"`
	MinPower          int   `json:"min_power_dbm"`
	MaxPower          int   `json:"max_power_dbm"`
}
type RRMRule struct {
	PolicyTarget
	StrategyVersion string           `json:"strategy_version,omitempty"`
	ID              string           `json:"id"`
	Name            string           `json:"name"`
	Enabled         bool             `json:"enabled"`
	Frequency       int              `json:"frequency"`
	Channel         bool             `json:"optimize_channel"`
	Power           bool             `json:"optimize_power"`
	Band2G          RRMBand          `json:"2g"`
	Band5G          RRMBand          `json:"5g"`
	Schedule        *ServiceSchedule `json:"schedule,omitempty"`
}

func (r RRMRule) usesV4() bool { return r.StrategyVersion == "v4" }
func (r RRMRule) strategyVersion() string {
	if r.usesV4() {
		return "v4"
	}
	return "v6"
}

func v4SecondaryChannels(b RRMBand) []int {
	if len(b.SecondaryChannels) > 0 {
		return b.SecondaryChannels
	}
	out := []int{}
	for _, ch := range b.Channels {
		if ch >= 149 {
			out = append(out, ch)
		}
	}
	return out
}

func defaultRRMRule() RRMRule {
	// V6 optimize/ac editDialog model in common.cdfcec...js. This is an
	// editor draft: 5 GHz channels must be selected before it can be saved.
	return RRMRule{StrategyVersion: "v6", Band2G: RRMBand{Bandwidth: 0, Channels: []int{1, 6, 11}, PowerThreshold: -65, MinPower: 10, MaxPower: 50}, Band5G: RRMBand{Bandwidth: 1, Channels: []int{}, PowerThreshold: -65, MinPower: 10, MaxPower: 50}}
}
func validateRRMRules(rows []RRMRule, cfg Config) error {
	if len(rows) > controllercfg.Effective(cfg.Resources).MaxPolicyRules {
		return fmt.Errorf("无线优化规则超过程序容量")
	}
	ids, names := map[string]bool{}, map[string]bool{}
	groups := map[string]bool{}
	for _, g := range cfg.Groups {
		groups[g.ID] = true
	}
	for _, r := range rows {
		if r.StrategyVersion != "" && r.StrategyVersion != "v4" && r.StrategyVersion != "v6" {
			return fmt.Errorf("无线优化策略版本必须为V4或V6")
		}
		if r.ID == "" || ids[r.ID] || r.Name == "" || !validLabel(r.Name, 64) || names[r.Name] || r.Frequency < 0 || r.Frequency > 2 {
			return fmt.Errorf("优化规则无效或重复")
		}
		ids[r.ID] = true
		names[r.Name] = true
		for _, g := range r.Groups {
			if !groups[g] {
				return fmt.Errorf("优化规则引用不存在的 AP 分组")
			}
		}
		if err := r.Schedule.validate(); err != nil {
			return err
		}
		if r.Schedule != nil && r.Schedule.Action != "on" {
			return fmt.Errorf("优化计划的时段操作必须为启用")
		}
		for i, b := range []RRMBand{r.Band2G, r.Band5G} {
			if b.MinPower < 3 || b.MinPower > 30 || b.MaxPower < 10 || b.MaxPower > 50 || b.MinPower > b.MaxPower || b.PowerThreshold < -80 || b.PowerThreshold > -50 || i == 0 && b.Bandwidth != 0 || i == 1 && !hasInt([]int{0, 1, 3, 5}, b.Bandwidth) {
				return fmt.Errorf("优化带宽或功率门限无效")
			}
			if len(b.Channels) == 0 || len(b.Channels) > 16 {
				return fmt.Errorf("优化候选信道为 1–16 项")
			}
			if r.usesV4() && len(b.Channels) > 4 {
				return fmt.Errorf("V4 DCA每个频段使用1–4个候选信道")
			}
			seen := map[int]bool{}
			for _, c := range b.Channels {
				if seen[c] || i == 0 && (c < 1 || c > 13) || i == 1 && !hasInt([]int{36, 40, 44, 48, 149, 153, 157, 161}, c) {
					return fmt.Errorf("优化候选信道无效或重复")
				}
				seen[c] = true
			}
		}
		if r.usesV4() {
			if r.Band2G.MinPower != r.Band5G.MinPower || r.Band2G.MaxPower != r.Band5G.MaxPower || r.Band2G.PowerThreshold != r.Band5G.PowerThreshold {
				return fmt.Errorf("V4 TPC各频段共用功率范围和邻居信号目标")
			}
			seen := map[int]bool{}
			for _, ch := range v4SecondaryChannels(r.Band5G) {
				if !hasInt([]int{149, 153, 157, 161}, ch) || seen[ch] {
					return fmt.Errorf("V4第二5GHz候选信道无效或重复")
				}
				seen[ch] = true
			}
			if len(seen) > 4 {
				return fmt.Errorf("V4第二5GHz候选信道最多4项")
			}
		}
	}
	return nil
}

type RRMChange struct {
	AP         string       `json:"ap_id"`
	Radio      uint8        `json:"radio_id"`
	OldChannel int          `json:"old_channel"`
	Channel    int          `json:"channel"`
	OldPower   int          `json:"old_power_dbm"`
	Power      int          `json:"power_dbm"`
	Bandwidth  int          `json:"bandwidth"`
	Setting    RadioSetting `json:"setting"`
}
type rrmNode struct {
	AP                           cweng.APStatus
	Cap                          cweng.RadioCapability
	Band                         RRMBand
	BandID                       int
	CurrentChannel, CurrentPower int
	Report                       cweng.RRMReport
	Setting                      RadioSetting
}

func rrmNodes(rule RRMRule, aps []cweng.APStatus, cfg Config, since time.Time) ([]rrmNode, error) {
	var nodes []rrmNode
	for _, ap := range aps {
		if !ap.Online || !rule.matches(ap.ID, cfg) {
			continue
		}
		if rule.usesV4() && roamingRole(ap) > 3 {
			continue
		} // foreach mask0xf0000
		if rule.usesV4() && roamingRole(ap) > 0 && ap.Mesh != nil && len(ap.Mesh.Nodes) > 0 {
			continue
		}
		if rule.usesV4() {
			two, five := 0, 0
			for _, c := range ap.Capabilities {
				if c.Band == "2.4 GHz" {
					two++
				}
				if c.Band == "5 GHz" {
					five++
				}
			}
			if two > 1 || five > 2 {
				continue
			} // V4 collector's supported RF topology
		}
		effective := effectiveRadioConfig(cfg, ap)
		for _, c := range ap.Capabilities {
			if c.FunctionType == 1 {
				continue
			}
			bandID := 0
			b := rule.Band2G
			if c.Band == "5 GHz" {
				bandID = 1
				b = rule.Band5G
			} else if c.Band != "2.4 GHz" {
				continue
			}
			if rule.Frequency == 1 && bandID != 0 || rule.Frequency == 2 && bandID != 1 || radioDisabled(effective, ap.ID, c.RadioID) {
				continue
			}
			if !ap.HasCapability(27) {
				continue
			}
			n := rrmNode{AP: ap, Cap: c, Band: b, BandID: bandID}
			n.Setting, _ = linkageRadioState(cfg, ap, c.RadioID)
			for _, report := range ap.RRMReports {
				if report.Radio == c.RadioID && !report.ReceivedAt.Before(since) {
					n.Report = report
				}
			}
			for _, r := range ap.RadioStatus {
				if r.Radio == c.RadioID {
					n.CurrentChannel = int(r.Channel)
					n.CurrentPower = int(r.Power)
				}
			}
			if !rule.usesV4() && len(rrmAllowed(c, b)) == 0 {
				continue
			}
			nodes = append(nodes, n)
		}
	}
	// The vendor uses the AP DB entry/radio order, not a MAC tie breaker.
	sort.SliceStable(nodes, func(i, j int) bool {
		if nodes[i].AP.EntryID != nodes[j].AP.EntryID {
			return nodes[i].AP.EntryID < nodes[j].AP.EntryID
		}
		if nodes[i].AP.ID == nodes[j].AP.ID {
			return nodes[i].Cap.RadioID < nodes[j].Cap.RadioID
		}
		return false
	})

	if len(nodes) == 0 {
		return nil, fmt.Errorf("没有符合规则的在线射频")
	}
	return nodes, nil
}

func rrmAllowed(c cweng.RadioCapability, b RRMBand) []int {
	domain := append([]int{}, b.Channels...)
	if strings.TrimSpace(c.MutexChannels) != "" {
		domain = nil
		for _, v := range strings.Fields(c.MutexChannels) {
			if ch, err := strconv.Atoi(v); err == nil {
				domain = append(domain, ch)
			}
		}
	}
	out := []int{}
	// UAC__rrm_update_support_channel, then so+c85c retain the AP domain order.
	for _, ch := range domain {
		if hasInt(b.Channels, ch) {
			out = append(out, ch)
			if len(out) == 16 {
				break
			}
		}
	}
	return out
}

// planRRM is a source-vector adapter for one library iteration. Production
// collection uses rrmRun, including the conditional second TPC round.
func planRRM(rule RRMRule, aps []cweng.APStatus, cfg Config, since time.Time) ([]RRMChange, error) {
	nodes, err := rrmNodes(rule, aps, cfg, since)
	if err != nil {
		return nil, err
	}
	run, err := newRRMRunForRule(nodes, rule)
	if err != nil {
		return nil, err
	}
	for i, n := range nodes {
		if !n.Report.ReceivedAt.IsZero() {
			run.ingest(i, n.Report.Neighbors, false)
			run.received[i] = true
		}
	}
	if run.v4 != nil {
		run.finishV4Pass(rule)
	} else if _, err = run.calculate(rule, true); err != nil {
		return nil, err
	}
	return run.changes(rule, cfg)
}
