package admin

import (
	"fmt"
	"sort"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	firmware "uacgo/rrm"
)

const rrmCollectionTimeout = 90 * time.Second

type rrmEdge struct {
	target             int
	baseline, smoothed int8
}
type rrmMeasurement struct {
	channel        int
	sent, received bool
}
type rrmRun struct {
	nodes            []rrmNode
	edges            [][]rrmEdge
	channels, levels []uint8
	resultLevels     []uint8
	received         []bool
	receivedCount    int
	requests         map[int]*rrmMeasurement
	round, pass      int
	deadline         time.Time
	multi5G          bool
}

func newRRMRun(nodes []rrmNode) *rrmRun {
	r := &rrmRun{nodes: nodes, edges: make([][]rrmEdge, len(nodes)), channels: make([]uint8, len(nodes)), levels: make([]uint8, len(nodes)), resultLevels: make([]uint8, len(nodes)), received: make([]bool, len(nodes)), round: 1}
	counts := map[string]int{}
	for i, n := range nodes {
		// Runtime allocation clears current algorithm channel; NDP initialization
		// @51f4fc explicitly sets level10. These are not the AP's observed settings.
		r.levels[i] = 10
		if n.BandID == 1 {
			counts[n.AP.ID]++
			if counts[n.AP.ID] > 1 {
				r.multi5G = true
			}
		}
	}
	return r
}
func (r *rrmRun) beginPass(rule RRMRule, now time.Time) {
	r.requests = map[int]*rrmMeasurement{}
	r.receivedCount = 0
	for i, n := range r.nodes {
		if r.pass == 0 || n.BandID == 1 {
			r.received[i] = false
		}
	}
	r.deadline = now.Add(rrmCollectionTimeout)
	channel2, channel5 := 0, 0
	for _, ch := range rule.Band2G.Channels {
		if ch >= 1 && ch <= 14 {
			channel2 = ch
			break
		}
	}
	for _, ch := range rule.Band5G.Channels {
		if r.pass == 0 && ch >= 36 && ch <= 64 || r.pass == 1 && ch >= 149 && ch <= 165 {
			channel5 = ch
			break
		}
	}
	for i, n := range r.nodes {
		ch := channel5
		if n.BandID == 0 {
			if r.pass != 0 {
				continue
			}
			ch = channel2
		}
		if ch != 0 && hasInt(rrmAllowed(n.Cap, n.Band), ch) {
			r.requests[i] = &rrmMeasurement{channel: ch}
		}
	}
	if len(r.requests) > 0 {
		r.deadline = time.Time{}
	}
}

// The firmware arms its timer after issuing the whole measurement set,
// not while the AP workers are still waiting to dispatch queued commands.
func (r *rrmRun) markDispatched(index int, request *rrmMeasurement, now time.Time) bool {
	q, ok := r.requests[index]
	if !ok || q != request || q.sent {
		return false
	}
	q.sent = true
	for _, other := range r.requests {
		if !other.sent {
			return true
		}
	}
	r.deadline = now.Add(rrmCollectionTimeout)
	return true
}
func (r *rrmRun) collected(now time.Time) bool {
	if !r.deadline.IsZero() && !now.Before(r.deadline) {
		return true
	}
	// The firmware's early semaphore release comes from a received report;
	// an empty send set has no report callback and waits for the timer.
	if len(r.requests) == 0 {
		return false
	}
	for _, q := range r.requests {
		if !q.sent {
			return false
		}
	}
	return r.receivedCount == len(r.requests)
}

// rrm_ops_pkt_ndp_recv @51eccc: first sample only, directed graph,
// initial collection can add neighbors; the second can only smooth existing
// neighbors and keeps their initial baseline RSSI for the library input.
func (r *rrmRun) ingest(index int, neighbors []capwap.RrmNeigh, second bool) {
	for _, heard := range neighbors {
		if len(heard.Samples) == 0 {
			continue
		}
		sample := heard.Samples[0]
		for target, n := range r.nodes {
			if target == index || n.BandID != r.nodes[index].BandID || apMAC(n.AP) != heard.MAC || n.Cap.RadioID != sample.Radio {
				continue
			}
			found := false
			for j := range r.edges[index] {
				edge := &r.edges[index][j]
				if edge.target != target {
					continue
				}
				edge.smoothed = rrmSmooth(edge.smoothed, sample.RSSI)
				if !second {
					edge.baseline = edge.smoothed
				}
				found = true
				break
			}
			if !found && !second {
				r.edges[index] = append(r.edges[index], rrmEdge{target: target, baseline: sample.RSSI, smoothed: sample.RSSI})
			}
			break
		}
	}
}
func rrmSmooth(old, next int8) int8 {
	if old == -127 {
		return next
	}
	return int8((int(old)*4 + int(next)) / 5)
}
func (r *rrmRun) calculate(rule RRMRule, first bool) (bool, error) {
	changed := false
	for band := 0; band < 2; band++ {
		indices := []int{}
		reverse := map[int]int{}
		for i, n := range r.nodes {
			if n.BandID == band {
				reverse[i] = len(indices)
				indices = append(indices, i)
			}
		}
		if len(indices) == 0 {
			continue
		}
		input := make([]firmware.Radio, len(indices))
		for local, index := range indices {
			n := r.nodes[index]
			radio := firmware.Radio{AP: n.AP.ID, Channel: r.channels[index], PowerLevel: r.levels[index], MinPower: uint8(n.Cap.MinPower), MaxPower: uint8(n.Cap.MaxPower)}
			for _, ch := range rrmAllowed(n.Cap, n.Band) {
				radio.Channels = append(radio.Channels, uint8(ch))
			}
			// UAC sorts on smoothed RSSI before copying baseline RSSI to librrm.
			sort.SliceStable(r.edges[index], func(i, j int) bool { return r.edges[index][i].smoothed > r.edges[index][j].smoothed })
			for _, edge := range r.edges[index] {
				if other, ok := reverse[edge.target]; ok {
					radio.Neighbors = append(radio.Neighbors, firmware.Neighbor{Target: other, RSSI: edge.baseline})
				}
			}
			input[local] = radio
		}
		policy := firmware.DefaultConfig()
		settings := r.nodes[indices[0]].Band
		policy.PowerThreshold = int8(settings.PowerThreshold)
		policy.MinPower = uint8(settings.MinPower)
		policy.MaxPower = uint8(settings.MaxPower)
		if first && rule.Channel {
			selected, err := firmware.Channels(input, policy)
			if err != nil {
				return false, err
			}
			for i, ch := range selected {
				r.channels[indices[i]] = ch
				input[i].Channel = ch
				r.resultLevels[indices[i]] = r.levels[indices[i]]
			}
		}
		if rule.Power {
			selected, err := firmware.Powers(input, policy)
			if err != nil {
				return false, err
			}
			for i, level := range selected {
				if level != r.resultLevels[indices[i]] {
					changed = true
				}
				r.levels[indices[i]] = level
				r.resultLevels[indices[i]] = level
			}
		}
	}
	return changed, nil
}
func rrmBandwidth(c cweng.RadioCapability, bandwidth, channel int) int {
	// rrm_ops_get_bw_mode_for_160m_bw_cfg @51bef0 is applied only for
	// requested160MHz. Ordinary80MHz fallback is applied by the RF setter.
	if bandwidth == 5 {
		bandwidth = 3
		if c.Support160 && channel < 149 {
			bandwidth = 5
		}
		if !c.SupportAX && !c.SupportAC {
			bandwidth = 1
		}
	}
	return bandwidth
}

// __rrm_ops_neigh_collect_ndp_parameter_send @522a54 uses a separate
// normalization from the final RF setter. In particular, it does not apply
// the setter's final legacy-mode bandwidth override.
func rrmMeasurementMode(a RadioAdvanced, c cweng.RadioCapability) RadioAdvanced {
	highest := func() int {
		if c.SupportBE {
			if c.Band == "2.4 GHz" {
				return 12
			}
			return 13
		}
		if c.SupportAX {
			if c.Band == "2.4 GHz" {
				return 10
			}
			return 11
		}
		if c.SupportAC && c.Band == "5 GHz" {
			return 9
		}
		if c.Band == "2.4 GHz" {
			return 6
		}
		return 7
	}
	if c.Band == "2.4 GHz" {
		if hasInt([]int{1, 2, 5}, a.Mode) && a.Bandwidth == 1 {
			a.Mode = highest()
		}
	} else if c.Band == "5 GHz" {
		if a.Mode == 0 {
			if a.Bandwidth == 1 {
				a.Mode = highest()
			}
		} else if a.Bandwidth == 3 || a.Bandwidth == 5 {
			a.Mode = highest()
			a.Bandwidth = 3
			if !c.SupportBE && !c.SupportAX && !c.SupportAC {
				a.Bandwidth = 1
			}
		}
	}
	return a
}

func rrmRadioMode(a RadioAdvanced, c cweng.RadioCapability, channel, previousBandwidth int) (RadioAdvanced, int) {
	// uac_rdmngr_chnl_pwr_modify_by_rdid @720e2c.
	if a.Bandwidth != previousBandwidth {
		if a.Mode == 9 && !c.SupportAC {
			a.Mode = 7
		}
		highest := func() int {
			if c.SupportBE {
				if c.Band == "2.4 GHz" {
					return 12
				}
				return 13
			}
			if c.SupportAX {
				if c.Band == "2.4 GHz" {
					return 10
				}
				return 11
			}
			if c.SupportAC && c.Band == "5 GHz" {
				return 9
			}
			if c.Band == "2.4 GHz" {
				return 6
			}
			return 7
		}
		if c.Band == "2.4 GHz" {
			if hasInt([]int{1, 2, 5}, a.Mode) {
				if a.Bandwidth == 0 {
					a.Bandwidth = 2
				}
				if a.Bandwidth == 1 {
					a.Mode = highest()
				}
			}
		} else if c.Band == "5 GHz" {
			if a.Mode == 0 {
				if a.Bandwidth == 0 {
					a.Bandwidth = 2
				}
				if a.Bandwidth == 1 {
					a.Mode = highest()
				}
			} else if a.Bandwidth == 3 || a.Bandwidth == 5 {
				if !c.SupportBE && !c.SupportAX && !c.SupportAC {
					a.Bandwidth = 1
					a.Mode = 7
				} else {
					if a.Bandwidth == 5 && !c.Support160 {
						a.Bandwidth = 3
					}
					a.Mode = highest()
				}
			}
			if a.Mode != 0 && a.Bandwidth != 0 && channel == 165 {
				channel = 0
			}
		}
	}
	if !hasInt([]int{3, 4, 6, 7, 8, 9, 10, 11, 12, 13}, a.Mode) {
		a.Bandwidth = 2
	}
	return a, channel
}
func (r *rrmRun) changes(rule RRMRule, cfg Config) ([]RRMChange, error) {
	next := cfg
	next.Radios = append([]RadioSetting{}, cfg.Radios...)
	aps := map[string]cweng.APStatus{}
	applyOrder := []int{}
	for _, band := range []int{0, 1} {
		for i, n := range r.nodes {
			if n.BandID == band {
				applyOrder = append(applyOrder, i)
			}
		}
	}
	selected := map[string]map[uint8]bool{}
	for _, i := range applyOrder {
		n := r.nodes[i]
		if selected[n.AP.ID] == nil {
			selected[n.AP.ID] = map[uint8]bool{}
		}
		selected[n.AP.ID][n.Cap.RadioID] = true
		aps[n.AP.ID] = n.AP
		setting, _ := linkageRadioState(next, n.AP, n.Cap.RadioID)
		previousBandwidth := linkageBandwidth(setting, n.Cap)
		ch := linkageChannel(setting, n.AP)
		if rule.Channel {
			ch = int(r.channels[i])
		}
		setting.Channel = &ch
		a := defaultRadioAdvanced(n.Cap)
		if setting.Advanced != nil {
			a = *setting.Advanced
		}
		// rrm_ops_apply_all_result always sets bw_apply=1, even when
		// chnl_apply=0. The chosen rule bandwidth still applies in TPC-only jobs.
		a.Bandwidth = rrmBandwidth(n.Cap, n.Band.Bandwidth, int(r.channels[i]))
		setting.Advanced = &a
		setting = normalizeLinkageRadio(setting, n.Cap, next, n.AP)
		a, ch = rrmRadioMode(*setting.Advanced, n.Cap, linkageChannel(setting, n.AP), previousBandwidth)
		setting.Advanced = &a
		setting.Channel = &ch
		if rule.Power {
			level := int(r.levels[i])
			power := int(firmware.PowerForLevel(r.levels[i], uint8(n.Cap.MaxPower), uint8(n.Cap.MinPower)))
			setting.Power = &power
			setting.PowerLevel = &level
		}
		putLinkedRadio(&next, setting)
		if err := planRadioLinkage(&next, n.AP, n.Cap.RadioID); err != nil {
			return nil, err
		}
	}
	out := []RRMChange{}
	// Retain DB/radio order, including peer changes caused by each RF setter.
	ordered := []cweng.APStatus{}
	seen := map[string]bool{}
	for _, node := range r.nodes {
		if !seen[node.AP.ID] {
			ordered = append(ordered, aps[node.AP.ID])
			seen[node.AP.ID] = true
		}
	}
	for _, ap := range ordered {
		caps := append([]cweng.RadioCapability{}, ap.Capabilities...)
		sort.SliceStable(caps, func(i, j int) bool { return caps[i].RadioID < caps[j].RadioID })
		for _, c := range caps {
			var explicit bool
			for _, s := range next.Radios {
				if s.AP == ap.ID && s.Radio == c.RadioID {
					explicit = true
					break
				}
			}
			if !explicit {
				continue
			}
			setting, _ := linkageRadioState(next, ap, c.RadioID)
			before, _ := linkageRadioState(cfg, ap, c.RadioID)
			if !selected[ap.ID][c.RadioID] && configurationKey(before, time.Time{}) == configurationKey(setting, time.Time{}) {
				continue
			}
			if err := validateAdvanced(setting, ap, c); err != nil {
				return nil, fmt.Errorf("AP %s 射频 %d: %w", ap.ID, c.RadioID, err)
			}
			oldCh, oldPower := 0, c.DefaultPower
			for _, observed := range ap.RadioStatus {
				if observed.Radio == c.RadioID {
					oldCh = int(observed.Channel)
					oldPower = int(observed.Power)
				}
			}
			ch, power := linkageChannel(setting, ap), oldPower
			if setting.Power != nil {
				power = *setting.Power
			}
			out = append(out, RRMChange{AP: ap.ID, Radio: c.RadioID, OldChannel: oldCh, Channel: ch, OldPower: oldPower, Power: power, Bandwidth: linkageBandwidth(setting, c), Setting: setting})
		}
	}
	return out, nil
}
