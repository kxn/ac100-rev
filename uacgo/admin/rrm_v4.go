package admin

import (
	"fmt"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	firmware "uacgo/rrm"
)

// The V4 business task has separate channel and power collections. V6's
// two-pass 5GHz scan and shared SCA/TPC iteration are not used here.
type v4RRMRun struct {
	phase                        string
	group, ap, radio             []int
	graphs                       [3]*firmware.V4Graph
	domains                      [3][]int
	powers                       []firmware.V4Power
	channelOK, powerOK           []bool
	channelAborted, powerAborted bool
}

func newRRMRunForRule(nodes []rrmNode, rule RRMRule) (*rrmRun, error) {
	r := newRRMRun(nodes)
	if !rule.usesV4() {
		return r, nil
	}
	v := &v4RRMRun{phase: "power", group: make([]int, len(nodes)), ap: make([]int, len(nodes)), radio: make([]int, len(nodes)), powers: make([]firmware.V4Power, len(nodes)), channelOK: make([]bool, len(nodes)), powerOK: make([]bool, len(nodes))}
	if rule.Channel {
		v.phase = "channel"
	}
	v.domains = [3][]int{rule.Band2G.Channels, rule.Band5G.Channels, v4SecondaryChannels(rule.Band5G)}
	for group := range v.graphs {
		v.graphs[group] = &firmware.V4Graph{Colors: len(v.domains[group])}
	}
	counts := map[string]int{}
	for i, n := range nodes {
		group := 0
		if n.BandID == 1 {
			counts[n.AP.ID]++
			group = counts[n.AP.ID]
			if group > 2 {
				return nil, fmt.Errorf("V4射频优化不支持同一AP超过两个5GHz射频")
			}
		}
		if len(v.domains[group]) == 0 {
			return nil, fmt.Errorf("V4射频组%d没有候选信道", group)
		}
		g := v.graphs[group]
		ap := -1
		for j, a := range g.APs {
			if a.ID == n.AP.ID {
				ap = j
				break
			}
		}
		if ap < 0 {
			ap = g.AddAP(n.AP.ID, 1)
		} else {
			return nil, fmt.Errorf("V4射频优化不支持同一AP多个2.4GHz射频")
		}
		v.group[i], v.ap[i] = group, ap
		// Collector initializes hardware-quantized exclusive bounds and starts
		// at the configured ceiling, not V6's unconditional hardware level10.
		v.powers[i] = firmware.NewV4Power(n.Cap.MaxPower, n.Cap.MinPower, n.Band.MaxPower, n.Band.MinPower)
		r.levels[i] = uint8(firmware.V4LevelForPower(v.powers[i].Current, n.Cap.MaxPower, n.Cap.MinPower))
	}
	for i, n := range nodes {
		physical5 := 0
		for _, c := range n.AP.Capabilities {
			if c.Band == "5 GHz" {
				physical5++
			}
		}
		if v.group[i] != 1 || physical5 != 2 {
			continue
		}
		// rrm_collect_active_ap@4a8fa0 reserves the leading colors for
		// 5G1 on dual-5GHz APs; 5G2 is optimized first in _rrm_task.
		if count := len(v.domains[2]); count == 1 || count == 2 {
			for color := count; color < len(v.graphs[1].APs[v.ap[i]].Forbidden); color++ {
				v.graphs[1].APs[v.ap[i]].Forbidden[color] = true
			}
		}
	}
	r.v4 = v
	r.multi5G = false
	return r, nil
}

func (r *rrmRun) beginV4Pass(rule RRMRule, now time.Time) {
	r.requests = map[int]*rrmMeasurement{}
	r.receivedCount = 0
	r.deadline = now.Add(rrmCollectionTimeout)
	for i := range r.nodes {
		r.received[i] = false
		r.v4.powers[i].Neighbors = nil // reset lists, retain dBm and exclusive bounds
		r.requests[i] = &rrmMeasurement{channel: r.v4.domains[r.v4.group[i]][0]}
	}
	if len(r.requests) > 0 {
		r.deadline = time.Time{}
	}
}

func (r *rrmRun) ingestV4(index int, neighbors []capwap.RrmNeigh) {
	v := r.v4
	group := v.group[index]
	for _, heard := range neighbors {
		for target, n := range r.nodes {
			if v.group[target] != group || apMAC(n.AP) != heard.MAC {
				continue
			}
			samples := []firmware.V4Sample{}
			for _, s := range heard.Samples {
				if s.Radio == n.Cap.RadioID {
					if v.phase == "channel" {
						samples = append(samples, firmware.V4Sample{Radio: v.radio[target], RSSI: s.RSSI})
					} else {
						v.powers[target].Observe(firmware.V4PowerNeighbor{AP: r.nodes[index].AP.ID, Radio: r.nodes[index].Cap.RadioID, RSSI: s.RSSI})
					}
				}
			}
			if v.phase == "channel" {
				v.graphs[group].Observe(v.ap[index], v.radio[index], v.ap[target], samples)
			}
		}
	}
}

// _rrm_pkt_rssi_request@4adad4 also projects a single 2G Mesh
// observation onto the parents' first5G radios. These are graph facts,
// not an extra candidate-selection heuristic.
func (r *rrmRun) projectV4Mesh(index int, neighbors []capwap.RrmNeigh, cfg Config, known map[string]cweng.APStatus) {
	v := r.v4
	if v == nil || v.phase != "channel" || v.group[index] != 0 || cfg.Mesh == nil || !cfg.Mesh.Enabled {
		return
	}
	source := r.nodes[index].AP
	parent := func(ap cweng.APStatus) string {
		role := roamingRole(ap)
		if role == 4 || role == 6 || role == 8 {
			return ap.MeshParent
		}
		return ap.ID
	}
	first5 := func(id string) int {
		for i, n := range r.nodes {
			if n.AP.ID == id && v.group[i] == 1 {
				return i
			}
		}
		return -1
	}
	from := first5(parent(source))
	if from < 0 {
		return
	}
	role := roamingRole(source)
	if role >= 1 && role <= 3 && !r.received[from] {
		r.received[from] = true
		r.receivedCount++
		if q := r.requests[from]; q != nil {
			q.received = true
		}
	}
	for _, heard := range neighbors {
		if len(heard.Samples) != 1 {
			continue
		}
		for _, ap := range known {
			if !ap.Online || !ap.HasCapability(27) || apMAC(ap) != heard.MAC || role == 0 && roamingRole(ap) == 0 {
				continue
			}
			to := first5(parent(ap))
			if to < 0 || r.nodes[from].AP.ID == r.nodes[to].AP.ID {
				continue
			}
			v.graphs[1].Observe(v.ap[from], 0, v.ap[to], []firmware.V4Sample{{Radio: 0, RSSI: heard.Samples[0].RSSI}})
		}
	}
}

func (r *rrmRun) v4Majority(group int) bool {
	total, received := 0, 0
	for i, g := range r.v4.group {
		if g == group {
			total++
			if r.received[i] {
				received++
			}
		}
	}
	return received >= (total+1)/2
}

// Returns true only when another source-defined collection is required.
func (r *rrmRun) finishV4Pass(rule RRMRule) bool {
	v := r.v4
	if v.phase == "channel" {
		for _, group := range []int{0, 1} {
			if !r.v4Majority(group) {
				v.channelAborted = true
				break
			}
		}
		if !v.channelAborted {
			v.graphs[0].Select()
			// run_DCA(5G2) -> rrm_add_co_chnl_itf -> run_DCA(5G1).
			v.graphs[2].Select()
			for _, ap := range v.graphs[2].APs {
				color := ap.Color[0]
				if color < 0 {
					continue
				}
				ch := v.domains[2][color]
				for first, a := range v.graphs[1].APs {
					if a.ID == ap.ID {
						for c, candidate := range v.domains[1] {
							if candidate == ch {
								v.graphs[1].AddExternal(first, c)
								break
							}
						}
					}
				}
			}
			v.graphs[1].Select()
			for i := range r.nodes {
				color := v.graphs[v.group[i]].APs[v.ap[i]].Color[v.radio[i]]
				if color >= 0 {
					r.channels[i] = uint8(v.domains[v.group[i]][color])
					v.channelOK[i] = true
				}
			}
		}
		if rule.Power {
			v.phase = "power"
			r.round = 1
			return true
		}
		return false
	}
	for group := 0; group < 3; group++ {
		if !r.v4Majority(group) {
			v.powerAborted = true
			return false
		}
	}
	changed := false
	for i, n := range r.nodes {
		p := &v.powers[i]
		changed = p.Step(n.Band.PowerThreshold) || changed
		r.levels[i] = uint8(firmware.V4LevelForPower(p.Current, p.Max, p.Min))
		v.powerOK[i] = true
	}
	if changed && r.round < 2 {
		r.round++
		return true
	}
	return false
}

func (r *rrmRun) finishPass(rule RRMRule) (bool, error) {
	if r.v4 != nil {
		return r.finishV4Pass(rule), nil
	}
	if r.pass == 0 && r.multi5G {
		r.pass = 1
		return true, nil
	}
	changed, err := r.calculate(rule, r.round == 1)
	if err != nil {
		return false, err
	}
	if rule.Power && changed && r.round == 1 {
		r.round = 2
		r.pass = 0
		return true, nil
	}
	return false, nil
}

func (r *rrmRun) measurementElement(mac [6]byte, index int, channel int) capwap.Element {
	n := r.nodes[index]
	if r.v4 == nil {
		return ndpElement(mac, n, channel, r.levels[index])
	}
	if r.v4.phase == "power" {
		return privateSetting(0x5c, (capwap.PrivNdpPara{MAC: mac, U8a: n.Cap.RadioID, U8b: 0xab, W1: 1, W2: 60, W3: 6, U8c: 254, U8d: 254, U8e: uint8(r.v4.powers[index].Current), U8f: 1, Tail: []byte{byte(channel)}}).AssembleValue())
	}
	e := ndpElement(mac, n, channel, 10)
	p, _ := capwap.ParsePrivNdpPara(e.Value[10:])
	p.W3 = 6
	// V4's channel measurement converts legacy20MHz to auto width2.
	a := defaultRadioAdvanced(n.Cap)
	if n.Setting.Advanced != nil {
		a = *n.Setting.Advanced
	}
	if n.Band.Bandwidth == 0 && (n.BandID == 0 && hasInt([]int{1, 2, 5}, a.Mode) || n.BandID == 1 && a.Mode == 0) {
		p.U8d = 2
	}
	return privateSetting(0x5c, p.AssembleValue())
}
