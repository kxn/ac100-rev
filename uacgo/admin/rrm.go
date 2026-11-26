package admin

import (
	"fmt"
	"sort"
	"time"
	"uacgo/cweng"
)

type RRMBand struct {
	Bandwidth      int   `json:"bandwidth"`
	Channels       []int `json:"channels"`
	SecondChannels []int `json:"second_channels,omitempty"`
	PowerThreshold int   `json:"power_threshold"`
	MinPower       int   `json:"min_power_dbm"`
	MaxPower       int   `json:"max_power_dbm"`
}
type RRMRule struct {
	PolicyTarget
	ID        string           `json:"id"`
	Name      string           `json:"name"`
	Enabled   bool             `json:"enabled"`
	Frequency int              `json:"frequency"`
	Channel   bool             `json:"optimize_channel"`
	Power     bool             `json:"optimize_power"`
	Band2G    RRMBand          `json:"2g"`
	Band5G    RRMBand          `json:"5g"`
	Schedule  *ServiceSchedule `json:"schedule,omitempty"`
}

func defaultRRMRule() RRMRule {
	return RRMRule{Enabled: true, Channel: true, Power: true, Band2G: RRMBand{Bandwidth: 0, Channels: []int{1, 6, 11}, PowerThreshold: -65, MinPower: 3, MaxPower: 24}, Band5G: RRMBand{Bandwidth: 3, Channels: []int{36, 40, 44, 48, 149, 153, 157, 161}, SecondChannels: []int{149, 153, 157, 161}, PowerThreshold: -65, MinPower: 5, MaxPower: 27}}
}
func validateRRMRules(rows []RRMRule, cfg Config) error {
	if len(rows) > 50 {
		return fmt.Errorf("无线优化规则最多 50 项")
	}
	ids, names := map[string]bool{}, map[string]bool{}
	groups := map[string]bool{}
	for _, g := range cfg.Groups {
		groups[g.ID] = true
	}
	for _, r := range rows {
		if r.ID == "" || ids[r.ID] || r.Name == "" || !validLabel(r.Name, 64) || names[r.Name] || r.Frequency < 0 || r.Frequency > 2 || !r.Channel && !r.Power {
			return fmt.Errorf("优化规则无效或重复；至少启用信道或功率优化")
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
			if b.MinPower < 3 || b.MaxPower > 50 || b.MinPower > b.MaxPower || b.PowerThreshold < -80 || b.PowerThreshold > -50 || i == 0 && b.Bandwidth != 0 || i == 1 && !hasInt([]int{0, 1, 3, 5}, b.Bandwidth) {
				return fmt.Errorf("优化带宽或功率门限无效")
			}
			if len(b.Channels) == 0 || len(b.Channels) > 32 || len(b.SecondChannels) > 32 {
				return fmt.Errorf("优化候选信道为 1–32 项")
			}
			seen := map[int]bool{}
			for _, c := range b.Channels {
				if seen[c] || i == 0 && (c < 1 || c > 13) || i == 1 && !hasInt([]int{36, 40, 44, 48, 52, 56, 60, 64, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 149, 153, 157, 161, 165}, c) {
					return fmt.Errorf("优化候选信道无效或重复")
				}
				seen[c] = true
			}
			secondSeen := map[int]bool{}
			for _, c := range b.SecondChannels {
				if secondSeen[c] || !hasInt([]int{149, 153, 157, 161}, c) {
					return fmt.Errorf("第二 5GHz 射频候选信道无效")
				}
				secondSeen[c] = true
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
}

func rrmNodes(rule RRMRule, aps []cweng.APStatus, cfg Config, since time.Time) ([]rrmNode, error) {
	var nodes []rrmNode
	for _, ap := range aps {
		if !ap.Online || !rule.matches(ap.ID, cfg) {
			continue
		}
		five := 0
		effective := effectiveRadioConfig(cfg, ap)
		for _, c := range ap.Capabilities {
			if c.FunctionType == 1 {
				continue
			}
			if c.Band == "5 GHz" {
				five++
			}
			bandID := 0
			b := rule.Band2G
			if c.Band == "5 GHz" {
				bandID = 1
				b = rule.Band5G
				if five > 1 && len(b.SecondChannels) > 0 {
					b.Channels = b.SecondChannels
				}
			} else if c.Band != "2.4 GHz" {
				continue
			}
			if rule.Frequency == 1 && bandID != 0 || rule.Frequency == 2 && bandID != 1 || radioDisabled(effective, ap.ID, c.RadioID) {
				continue
			}
			if !ap.HasCapability(27) {
				return nil, fmt.Errorf("AP %s 未声明全局无线优化能力", ap.ID)
			}
			n := rrmNode{AP: ap, Cap: c, Band: b, BandID: bandID}
			found := false
			for _, r := range ap.RRMReports {
				if r.Radio == c.RadioID && !r.ReceivedAt.Before(since) && time.Since(r.ReceivedAt) < 5*time.Minute {
					n.Report = r
					found = true
				}
			}
			if !found {
				return nil, fmt.Errorf("AP %s 射频 %d 尚无本轮测量报告", ap.ID, c.RadioID)
			}
			for _, r := range ap.RadioStatus {
				if r.Radio == c.RadioID {
					n.CurrentChannel = int(r.Channel)
					n.CurrentPower = int(r.Power)
				}
			}
			if n.CurrentChannel == 0 {
				return nil, fmt.Errorf("AP %s 射频 %d 未上报当前信道", ap.ID, c.RadioID)
			}
			if rule.Channel && !hasInt(c.Bandwidths, b.Bandwidth) {
				return nil, fmt.Errorf("AP %s 不支持所选优化带宽", ap.ID)
			}
			nodes = append(nodes, n)
		}
	}
	sort.Slice(nodes, func(i, j int) bool {
		if nodes[i].AP.ID == nodes[j].AP.ID {
			return nodes[i].Cap.RadioID < nodes[j].Cap.RadioID
		}
		return nodes[i].AP.ID < nodes[j].AP.ID
	})
	if len(nodes) == 0 {
		return nil, fmt.Errorf("没有符合规则的在线射频")
	}
	return nodes, nil
}
func rrmEdge(a, b rrmNode) int {
	maxSignal := -128
	for _, n := range a.Report.Neighbors {
		mac, ok := parseMAC6(b.AP.MAC)
		if !ok {
			mac, _ = parseMAC6(b.AP.ID)
		}
		if n.MAC != mac {
			continue
		}
		for _, r := range n.Samples {
			if r.Radio == b.Cap.RadioID && int(r.RSSI) > maxSignal {
				maxSignal = int(r.RSSI)
			}
		}
	}
	return maxSignal
}
func channelCost(a, b rrmNode, ch, other int) int {
	if a.BandID != b.BandID {
		return 0
	}
	rssi := rrmEdge(a, b)
	if opposite := rrmEdge(b, a); opposite > rssi {
		rssi = opposite
	}
	if rssi < -100 {
		return 0
	}

	overlap := 0
	if a.BandID == 0 {
		distance := ch - other
		if distance < 0 {
			distance = -distance
		}
		overlap = max(0, 5-distance)
	} else {
		aa, bb := occupied5G(ch, a.Band.Bandwidth), occupied5G(other, b.Band.Bandwidth)
		for _, x := range aa {
			if hasInt(bb, x) {
				overlap++
			}
		}
	}
	return (rssi + 101) * overlap
}

// Primary channels within the same bonded block occupy the same spectrum.
// Adjacent 80 MHz blocks (36–48 and 52–64) are disjoint.
func occupied5G(ch, bw int) []int {
	width := 1
	switch bw {
	case 1:
		width = 2
	case 3:
		width = 4
	case 5:
		width = 8
	}
	for _, base := range []int{36, 100, 132, 149} {
		end := base + 7*4
		if base == 132 {
			end = 144
		}
		if base == 149 {
			end = 165
		}
		if ch < base || ch > end || (ch-base)%4 != 0 {
			continue
		}
		if bw == 5 && base >= 132 {
			return nil
		}
		first := base + ((ch-base)/4/width)*width*4
		if first+(width-1)*4 > end {
			return nil
		}
		out := []int{}
		for n := 0; n < width; n++ {
			out = append(out, first+n*4)
		}
		return out
	}
	return nil
}
func rrmAllowed(c cweng.RadioCapability, b RRMBand) []int {
	out := []int{}
	for _, ch := range b.Channels {
		if !hasInt(c.Channels, ch) || c.Band == "5 GHz" && len(occupied5G(ch, b.Bandwidth)) == 0 {
			continue
		}
		out = append(out, ch)
	}
	return out
}
func planRRM(rule RRMRule, aps []cweng.APStatus, cfg Config, since time.Time) ([]RRMChange, error) {
	nodes, err := rrmNodes(rule, aps, cfg, since)
	if err != nil {
		return nil, err
	}
	channels := make([]int, len(nodes))
	for i, n := range nodes {
		channels[i] = n.CurrentChannel
	}
	// Coordinate descent minimizes overlap in the measured AP graph. Ties keep
	// the current channel, avoiding gratuitous channel changes on quiet radios.
	if rule.Channel {
		for pass := 0; pass < 3; pass++ {
			for i, n := range nodes {
				allowed := rrmAllowed(n.Cap, n.Band)
				if len(allowed) == 0 {
					return nil, fmt.Errorf("AP %s 没有可用的候选信道", n.AP.ID)
				}
				best, cost := allowed[0], int(^uint(0)>>1)
				for _, c := range allowed {
					score := 0
					for j, o := range nodes {
						if i != j {
							score += channelCost(n, o, c, channels[j])
						}
					}
					if score < cost || score == cost && c == n.CurrentChannel {
						best, cost = c, score
					}
				}
				channels[i] = best
			}
		}
		channels, err = rrmLinkedChannels(nodes, cfg, channels)
		if err != nil {
			return nil, err
		}
	}
	out := []RRMChange{}
	for i, n := range nodes {
		power := n.CurrentPower
		if rule.Power {
			lo, hi := n.Band.MinPower, n.Band.MaxPower
			if lo < n.Cap.MinPower {
				lo = n.Cap.MinPower
			}
			if hi > n.Cap.MaxPower {
				hi = n.Cap.MaxPower
			}
			if lo > hi {
				return nil, fmt.Errorf("AP %s 没有匹配的优化功率范围", n.AP.ID)
			}
			strongest := -128
			for j, o := range nodes {
				if i != j && n.BandID == o.BandID {
					if v := rrmEdge(o, n); v > strongest {
						strongest = v
					}
				}
			}
			power = hi
			if strongest > n.Band.PowerThreshold {
				power = n.CurrentPower + n.Band.PowerThreshold - strongest
			}
			if power < lo {
				power = lo
			}
			if power > hi {
				power = hi
			}
		}
		setting := RadioSetting{AP: n.AP.ID, Radio: n.Cap.RadioID}
		for _, r := range effectiveRadioConfig(cfg, n.AP).Radios {
			if r.AP == n.AP.ID && r.Radio == n.Cap.RadioID {
				setting = r
			}
		}
		if rule.Channel {
			v := channels[i]
			setting.Channel = &v
			a := defaultRadioAdvanced(n.Cap)
			if setting.Advanced != nil {
				a = *setting.Advanced
			}
			a.Bandwidth = n.Band.Bandwidth
			setting.Advanced = &a
		}
		if rule.Power {
			v := power
			setting.Power = &v
			setting.PowerLevel = nil
		}
		if err := validateAdvanced(setting, n.AP, n.Cap); err != nil {
			return nil, err
		}
		out = append(out, RRMChange{AP: n.AP.ID, Radio: n.Cap.RadioID, OldChannel: n.CurrentChannel, Channel: channels[i], OldPower: n.CurrentPower, Power: power, Bandwidth: n.Band.Bandwidth, Setting: setting})
	}
	return out, nil
}
