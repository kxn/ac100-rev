package admin

import (
	"context"
	"fmt"
	"net"
	"sort"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

type roamJob struct {
	Connection time.Time
	Received   time.Time
	Report     capwap.PrivRoamingTrigger
	Result     *capwap.PrivRoamingCalcResult
	Targets    []cweng.APStatus
	Delivered  map[string]bool
	Version    uint64
}
type RoamDecision struct {
	At         time.Time `json:"at"`
	AP         string    `json:"ap_id"`
	MAC        string    `json:"mac"`
	Candidates []string  `json:"candidates"`
	Reason     string    `json:"reason"`
}

func (m *Manager) queueRoaming(ap string, connection time.Time, r capwap.PrivRoamingTrigger) {
	m.mu.Lock()
	defer m.mu.Unlock()
	if m.roamJobs == nil {
		m.roamJobs = map[string]roamJob{}
	}
	if len(m.roamJobs) < 128 || m.roamJobs[ap].Received.IsZero() == false {
		m.roamJobs[ap] = roamJob{Connection: connection, Received: time.Now(), Report: r}
	}
}

// V6 accepts both signed RSSI and RCPI. Infer from the whole report rather
// than treating byte values above 127 as negative without checking ambiguity.
func neighborSignals(rows []capwap.RoamNeighborReport) (map[[6]byte]int, bool) {
	method := -1
	for _, n := range rows {
		v := int(n.Signal)
		guess := 0
		if v < 128 {
			method = 1
			break
		}
		if v >= 220 {
			method = 0
			break
		}
		if v%2 == 0 && n.B >= 61 {
			guess = 1
		}
		if method >= 0 && method != guess {
			return nil, false
		}
		method = guess
	}
	out := map[[6]byte]int{}
	for _, n := range rows {
		r := int(int8(n.Signal))
		if method == 1 {
			r = int(n.Signal)/2 - 110
		}
		if r <= 0 && r >= -110 {
			out[n.BSSID] = r
		}
	}
	return out, true
}
func parseMAC6(v string) (out [6]byte, ok bool) {
	mac, err := net.ParseMAC(normalizeMAC(v))
	if err != nil || len(mac) != 6 {
		return out, false
	}
	copy(out[:], mac)
	return out, out != [6]byte{} && out[0]&1 == 0
}

// All locations and signal estimates come from AP reports. Selection never
// changes the client table: only a subsequent AP association confirms a roam.
func (m *Manager) calculateRoaming(ap cweng.APStatus, report capwap.PrivRoamingTrigger, now time.Time) capwap.PrivRoamingCalcResult {
	m.mu.Lock()
	defer m.mu.Unlock()
	out := capwap.PrivRoamingCalcResult{Radio: report.Radio}
	source, ok := parseMAC6(ap.MAC)
	if !ok {
		source, _ = parseMAC6(ap.ID)
	}
	out.APs = append(out.APs, source)
	if m.config.Mobility == nil || !ap.HasCapability(25) || m.clients == nil {
		return out
	}
	s := roamingFor(m.config.Mobility, ap.ID, m.config)
	if m.roamLast == nil {
		m.roamLast = map[[6]byte]time.Time{}
	}
	for mac, t := range m.roamLast {
		if now.Sub(t) > time.Hour {
			delete(m.roamLast, mac)
		}
	}
	clients := map[[6]byte]cweng.ClientEvent{}
	counts := map[string]int{}
	for _, c := range m.clients.All() {
		clients[c.MAC] = c
		if c.State == "connected" && now.Sub(c.Seen) < 6*time.Minute {
			counts[c.APID]++
		}
	}
	for _, sta := range report.Stations {
		c, found := clients[sta.MAC]
		if !found || c.APID != ap.ID || c.RadioID != report.Radio || c.WLANID != uint32(sta.WLAN) || c.State != "connected" {
			continue
		}
		d := RoamDecision{At: now, AP: ap.ID, MAC: net.HardwareAddr(sta.MAC[:]).String(), Candidates: []string{}, Reason: "没有满足信号差值和服务条件的候选 AP"}
		row := capwap.RoamResultStation{MAC: sta.MAC}
		row.APBitmap[0] = 1
		service := Service{}
		for _, v := range m.config.Services {
			if m.assignments[ap.ID][v.ID][report.Radio] == sta.WLAN {
				service = v
				break
			}
		}
		signals, valid := neighborSignals(sta.Neighbors)
		type candidate struct {
			AP                   cweng.APStatus
			Radio, WLAN, Channel uint8
			BSSID                [6]byte
			RSSI                 int
		}
		var candidates []candidate
		if valid && c.RSSI != nil && service.ID != "" && service.Enabled && !service.Deleting && now.Sub(m.roamLast[sta.MAC]) >= time.Duration(s.BlacklistTime)*time.Second {
			for _, target := range m.known {
				if !target.Online || !target.HasCapability(25) || target.Telemetry == nil || !serviceTargets(service, target.ID, m.config) {
					continue
				}
				for _, vap := range target.Telemetry.VAPs {
					bssid, ok := parseMAC6(vap.BSSID)
					if !ok {
						continue
					}
					signal, heard := signals[bssid]
					if !heard || signal < int(*c.RSSI)+s.Difference || signal < -95 {
						continue
					}
					radio := uint8(vap.RadioID)
					slot := m.assignments[target.ID][service.ID][radio]
					if !selectedServiceRadios(service, target)[radio] || slot == 0 || target.ID == ap.ID && radio == report.Radio || radioDisabled(m.config, target.ID, radio) {
						continue
					}
					bound, vlan := binding(service, target.ID, radio)
					_, sourceVLAN := binding(service, ap.ID, report.Radio)
					if !bound || vlan != sourceVLAN {
						continue
					}
					matchingSSID, _ := serviceSSID(service)
					if vap.SSID != service.SSID && vap.SSID != string(matchingSSID) {
						continue
					}
					channel := uint8(0)
					for _, r := range target.RadioStatus {
						if r.Radio == radio {
							channel = uint8(r.Channel)
						}
					}
					if channel == 0 {
						continue
					}
					candidates = append(candidates, candidate{target, radio, slot, channel, bssid, signal})
				}
			}
		}
		sort.Slice(candidates, func(i, j int) bool {
			if candidates[i].RSSI != candidates[j].RSSI {
				return candidates[i].RSSI > candidates[j].RSSI
			}
			if counts[candidates[i].AP.ID] != counts[candidates[j].AP.ID] {
				return counts[candidates[i].AP.ID] < counts[candidates[j].AP.ID]
			}
			return candidates[i].AP.ID < candidates[j].AP.ID
		})
		used := map[[6]byte]bool{}
		for _, v := range candidates {
			if len(row.Candidates) >= 6 {
				break
			}
			if used[v.BSSID] {
				continue
			}
			used[v.BSSID] = true
			mac, ok := parseMAC6(v.AP.MAC)
			if !ok {
				mac, ok = parseMAC6(v.AP.ID)
			}
			if !ok {
				continue
			}
			idx := -1
			for i, a := range out.APs {
				if a == mac {
					idx = i
				}
			}
			if idx < 0 {
				if len(out.APs) >= 128 {
					continue
				}
				idx = len(out.APs)
				out.APs = append(out.APs, mac)
			}
			row.APBitmap[idx/8] |= 1 << uint(idx%8)
			row.Candidates = append(row.Candidates, capwap.RoamCandidate{APIndex: uint8(idx), Radio: v.Radio, WLAN: v.WLAN, BSSID: v.BSSID, Channel: v.Channel})
			d.Candidates = append(d.Candidates, fmt.Sprintf("%s/%d", v.AP.ID, v.Radio))
		}
		if len(row.Candidates) > 0 {
			d.Reason = "候选满足同服务、VLAN 和信号差值条件"
		}
		out.Stations = append(out.Stations, row)
		m.roamHistory = append(m.roamHistory, d)
		if len(m.roamHistory) > 1000 {
			m.roamHistory = append([]RoamDecision{}, m.roamHistory[len(m.roamHistory)-1000:]...)
		}
		if len(out.Stations) >= 128 {
			break
		}
	}
	return out
}
func (m *Manager) applyRoamingJobs(ctx context.Context, ap cweng.APStatus) {
	m.mu.Lock()
	job, ok := m.roamJobs[ap.ID]
	version := m.config.Version
	m.mu.Unlock()
	if !ok {
		return
	}
	clear := func() {
		m.mu.Lock()
		if current, exists := m.roamJobs[ap.ID]; exists && current.Received == job.Received {
			delete(m.roamJobs, ap.ID)
		}
		m.mu.Unlock()
	}
	if job.Connection != ap.ConnectedAt || time.Since(job.Received) > 15*time.Second || job.Result != nil && job.Version != version {
		clear()
		return
	}
	if job.Result == nil {
		result := m.calculateRoaming(ap, job.Report, time.Now())
		if len(result.Stations) == 0 {
			clear()
			return
		}
		job.Result, job.Version, job.Delivered = &result, version, map[string]bool{}
		m.mu.Lock()
		for _, mac := range result.APs {
			id := net.HardwareAddr(mac[:]).String()
			target, exists := m.known[id]
			if exists && target.Online {
				job.Targets = append(job.Targets, target)
			}
		}
		m.mu.Unlock()
		if len(job.Targets) != len(result.APs) {
			clear()
			return
		}
	}
	// Retain the immutable result and successful recipients across transient ACK
	// failures. Never redirect a result computed for an old session to a new one.
	all := true
	for _, target := range job.Targets {
		if job.Delivered[target.ID] {
			continue
		}
		m.mu.Lock()
		current, exists := m.known[target.ID]
		m.mu.Unlock()
		if !exists || !current.Online || current.ConnectedAt != target.ConnectedAt {
			clear()
			return
		}
		c, cancel := context.WithTimeout(cweng.PinAP(ctx, target), 4*time.Second)
		_, err := m.engine.Request(c, target.ID, 7, []capwap.Element{privateSetting(0x59, job.Result.AssembleValue())})
		cancel()
		st := ApplyStatus{AP: target.ID, Service: "roaming-result", State: "acknowledged", At: time.Now()}
		if err != nil {
			st.State = "failed"
			st.Error = err.Error()
			all = false
		} else {
			job.Delivered[target.ID] = true
		}
		m.mu.Lock()
		m.status[target.ID+"/roaming-result"] = st
		m.mu.Unlock()
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	current, exists := m.roamJobs[ap.ID]
	if !exists || current.Received != job.Received {
		return
	}
	if !all {
		m.roamJobs[ap.ID] = job
		return
	}
	if m.roamLast == nil {
		m.roamLast = map[[6]byte]time.Time{}
	}
	for _, sta := range job.Result.Stations {
		if len(sta.Candidates) > 0 {
			m.roamLast[sta.MAC] = time.Now()
		}
	}
	delete(m.roamJobs, ap.ID)
}
