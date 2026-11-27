package admin

import (
	"context"
	"fmt"
	"net"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/mobility"
)

// Each trigger produces immutable decisions immediately, before transport.
// Jobs never overwrite a previous radio/report and ACKs never change policy.
type roamJob struct {
	ID         uint64
	Connection time.Time
	Received   time.Time
	Result     capwap.PrivRoamingCalcResult
	Targets    []cweng.APStatus
	Pending    int
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
	source, ok := m.known[ap]
	if !ok || !source.Online || source.ConnectedAt != connection {
		return
	}
	for i, stats := range source.RadioStatistics {
		if stats.Radio == r.Radio {
			source.RadioStatistics[i].ChannelLoad = r.ChannelLoad
			source.RadioStatistics[i].NoiseFloor = r.NoiseFloor
		}
	}
	m.known[ap] = source
	if m.roamJobs == nil {
		m.roamJobs = map[string][]*roamJob{}
	}
	now := time.Now()
	for _, result := range m.calculateRoamingLocked(source, r, now) {
		if len(result.Stations) == 0 {
			continue
		}
		m.roamSequence++
		job := &roamJob{ID: m.roamSequence, Connection: connection, Received: now, Result: result}
		for _, mac := range result.APs {
			id := net.HardwareAddr(mac[:]).String()
			if target, ok := m.known[id]; ok && target.Online && target.HasCapability(25) {
				job.Targets = append(job.Targets, target)
			}
		}
		m.roamJobs[ap] = append(m.roamJobs[ap], job)
		m.submitRoamingLocked(ap, job)
	}
}

func parseMAC6(v string) (out [6]byte, ok bool) {
	mac, err := net.ParseMAC(normalizeMAC(v))
	if err != nil || len(mac) != 6 {
		return out, false
	}
	copy(out[:], mac)
	return out, out != [6]byte{} && out[0]&1 == 0
}

// Report-wide RCPI detection from _bstm_ngr_generate, inlined at 4e6564.
func neighborSignals(rows []capwap.RoamNeighborReport) ([]int, bool) {
	method := -1
	for _, n := range rows {
		v := int(n.RCPI)
		guess := 0
		if v < 128 {
			method = 1
			break
		}
		if v >= 220 {
			method = 0
			break
		}
		if v%2 == 0 && n.RSNI >= 61 {
			guess = 1
		}
		if method >= 0 && method != guess {
			return nil, false
		}
		method = guess
	}
	out := []int{}
	for _, n := range rows {
		r := int(int8(n.RCPI))
		if method == 1 {
			r = int(n.RCPI)/2 - 110
		}
		out = append(out, r)
	}
	return out, true
}
func apMAC(ap cweng.APStatus) [6]byte {
	v, ok := parseMAC6(ap.MAC)
	if !ok {
		v, _ = parseMAC6(ap.ID)
	}
	return v
}
func radioStats(ap cweng.APStatus, radio uint8) (cweng.RadioStatistics, bool) {
	for _, r := range ap.RadioStatistics {
		if r.Radio == radio {
			return r, true
		}
	}
	return cweng.RadioStatistics{}, false
}
func (m *Manager) radioPHYLocked(ap cweng.APStatus, r cweng.RadioStatistics, band int) mobility.PHY {
	var cap cweng.RadioCapability
	for _, c := range ap.Capabilities {
		if c.RadioID == r.Radio {
			cap = c
			break
		}
	}
	adv := defaultRadioAdvanced(cap)
	cfg := effectiveRadioConfig(m.config, ap)
	for _, s := range cfg.Radios {
		if s.AP == ap.ID && s.Radio == r.Radio && s.Advanced != nil {
			adv = *s.Advanced
		}
	}
	bw := adv.Bandwidth
	if bw == 2 {
		bw = int(r.Bandwidth)
	}
	// WLAN width decoding differs from station decoding for an unresolved
	// automatic width (2); keep the original WLAN fallback by frequency.
	p := mobility.StationPHY(0x11, int8(bw), band)
	p.Bandwidth = mobility.RadioBandwidth(bw, band)
	p.NSS = uint8(cap.TxStreams)
	if cap.TxStreams < 1 || cap.TxStreams > 16 {
		p.NSS = 2
	}
	switch adv.Mode {
	case -1:
		p.Mode = 1
		if cap.SupportAC {
			p.Mode = 2
		}
		if cap.SupportAX {
			p.Mode = 3
		}
		if cap.SupportBE {
			p.Mode = 4
		}
	case 0, 1, 2, 5:
		p.Mode = 0
	case 3, 4, 6, 7:
		p.Mode = 1
	case 8, 9:
		p.Mode = 2
	case 10, 11:
		p.Mode = 3
	case 12, 13:
		p.Mode = 4
	default:
		p.Mode = 1
	}
	return p
}

// V6 Join derives roles from product type, Mesh-device flag and transport:
// normal0, CAP1, CAP-XVR2, CAP-router3, RE-AP4, encapsulated-router5,
// Mesh2-router6, sensor7, RE-XVR8. The estimator rejects5/7/unknown.
func roamingRole(ap cweng.APStatus) uint8 {
	if ap.ProductType > 3 {
		return 9
	}
	if ap.Encapsulated {
		switch ap.ProductType {
		case 1:
			return 5
		case 3:
			return 8
		default:
			return 9
		}
	}
	if ap.ProductType == 2 {
		return 7
	}
	if !ap.MeshDevice {
		return 0
	}
	if ap.MeshParent != "" {
		switch ap.ProductType {
		case 1:
			return 6
		case 3:
			return 8
		default:
			return 4
		}
	}
	switch ap.ProductType {
	case 1:
		return 3
	case 3:
		return 2
	default:
		return 1
	}
}

func (m *Manager) candidateLocked(mac [6]byte, ap cweng.APStatus, radio, wlan uint8, bssid [6]byte, rssi int8, rate bool) (mobility.Candidate, bool) {
	stats, ok := radioStats(ap, radio)
	band := radioBand(ap, radio)
	if !ok || !ap.Online || band < 0 {
		return mobility.Candidate{}, false
	}
	n := mobility.Candidate{AP: ap.ID, Radio: radio, WLAN: wlan, BSSID: mobility.MAC(bssid), Channel: stats.Channel, Band: band, RSSI: rssi, Rate: -1, Load: stats.ChannelLoad}
	if rate {
		caps := m.stationStatistics.Capabilities(mobility.MAC(mac))
		role := roamingRole(ap)
		n.RSSI = int8(max(-95, int(rssi)-10))
		if role > 4 && role != 6 && role != 8 {
			// The estimator returns -1. The current BSS retains that value;
			// only the caller's neighbor-insertion branch skips it.
			return n, true
		}
		mesh, backhaul := role == 4 || role == 6 || role == 8, 0
		if mesh {
			if parent, ok := m.known[ap.MeshParent]; ok {
				if parent.Mesh != nil {
					for _, node := range parent.Mesh.Nodes {
						if normalizeMAC(node.MAC) == normalizeMAC(ap.ID) {
							backhaul = int(node.Rate)
						}
					}
				}
			}
		}
		n.Rate = mobility.CandidateRate(rssi, caps.PHY(band), m.radioPHYLocked(ap, stats, band), band, mesh, backhaul)
	}
	return n, true
}
func (m *Manager) findBSSIDLocked(bssid [6]byte) (cweng.APStatus, uint8, uint8, bool) {
	if loc, ok := m.bssidLocations[bssid]; ok {
		if ap, ok := m.known[loc.AP]; ok && ap.ConnectedAt.Equal(loc.Connection) {
			return ap, loc.Radio, loc.WLAN, true
		}
	}
	for _, ap := range m.known {
		for _, v := range ap.VAPStatistics {
			if v.BSSID == bssid {
				return ap, v.Radio, v.WLAN, true
			}
		}
		if ap.Telemetry == nil || len(ap.VAPStatistics) > 0 {
			continue
		}
		for _, vap := range ap.Telemetry.VAPs {
			mac, ok := parseMAC6(vap.BSSID)
			if !ok || mac != bssid {
				continue
			}
			radio := uint8(vap.RadioID)
			for _, s := range m.config.Services {
				slot := m.assignments[ap.ID][s.ID][radio]
				wireSSID, _ := serviceSSID(s)
				if slot != 0 && (vap.SSID == s.SSID || vap.SSID == string(wireSSID)) {
					return ap, radio, slot, true
				}
			}
		}
	}
	return cweng.APStatus{}, 0, 0, false
}
func (m *Manager) calculateRoamingLocked(ap cweng.APStatus, report capwap.PrivRoamingTrigger, now time.Time) []capwap.PrivRoamingCalcResult {
	results := []capwap.PrivRoamingCalcResult{}
	if m.clients == nil {
		return results
	}
	clients := map[[6]byte]cweng.ClientEvent{}
	for _, c := range m.clients.All() {
		clients[c.MAC] = c
	}
	settings := roamingFor(m.config.Mobility, ap.ID, m.config)
	out := capwap.PrivRoamingCalcResult{Radio: report.Radio, APs: [][6]byte{apMAC(ap)}}
	flush := func() {
		if len(out.Stations) > 0 {
			results = append(results, out)
		}
		out = capwap.PrivRoamingCalcResult{Radio: report.Radio, APs: [][6]byte{apMAC(ap)}}
	}
	addAP := func(id string) int {
		mac := apMAC(m.known[id])
		for i, a := range out.APs {
			if a == mac {
				return i
			}
		}
		if len(out.APs) >= 128 {
			return -1
		}
		out.APs = append(out.APs, mac)
		return len(out.APs) - 1
	}
	// V6 builds the non-BSTM list first, then appends the BSTM list.
	stations := append([]capwap.RoamTriggerStation{}, report.Stations...)
	ordered := make([]capwap.RoamTriggerStation, 0, len(stations))
	for _, s := range stations {
		if len(s.Neighbors) == 0 {
			ordered = append(ordered, s)
		}
	}
	for _, s := range stations {
		if len(s.Neighbors) > 0 {
			ordered = append(ordered, s)
		}
	}
	for _, sta := range ordered {
		c, found := clients[sta.MAC]
		if !found || c.State == "disconnected" || c.APID != ap.ID || c.RadioID != report.Radio || c.WLANID != uint32(sta.WLAN) {
			continue
		}
		var neighbors []mobility.Candidate
		currentRSSI, currentRate := sta.RSSI, 0
		if len(sta.Neighbors) > 0 {
			signals, valid := neighborSignals(sta.Neighbors)
			if valid {
				for i, b := range sta.Neighbors {
					target, radio, wlan, ok := m.findBSSIDLocked(b.BSSID)
					if !ok {
						continue
					}
					n, ok := m.candidateLocked(sta.MAC, target, radio, wlan, b.BSSID, int8(signals[i]), true)
					if !ok {
						continue
					}
					if i == 0 && target.ID == ap.ID && radio == report.Radio && wlan == sta.WLAN {
						currentRSSI, currentRate = n.RSSI, n.Rate
						continue
					}
					if n.Rate == -1 {
						continue
					}
					neighbors = append(neighbors, n)
				}
			}
		} else {
			for _, r := range m.stationStatistics.Neighbors(mobility.MAC(sta.MAC), now, mobility.NeighborAge(int(reportingControl(m.config, ap.ID).E))) {
				target, ok := m.known[r.AP]
				if !ok || (r.AP == ap.ID && r.Radio == report.Radio) {
					continue
				}
				var bssid [6]byte
				for _, v := range target.VAPStatistics {
					if v.Radio == r.Radio && v.WLAN == r.WLAN {
						bssid = v.BSSID
						break
					}
				}
				if bssid == [6]byte{} && target.Telemetry != nil {
					for _, vap := range target.Telemetry.VAPs {
						if uint8(vap.RadioID) == r.Radio {
							s := m.serviceForSlotLocked(r.AP, r.Radio, r.WLAN)
							if s != nil && vap.SSID == s.SSID {
								bssid, _ = parseMAC6(vap.BSSID)
								break
							}
						}
					}
				}
				if bssid == [6]byte{} {
					continue
				}
				if n, ok := m.candidateLocked(sta.MAC, target, r.Radio, r.WLAN, bssid, r.RSSI, false); ok {
					neighbors = append(neighbors, n)
				}
			}
		}
		// roam_nbr_select copies 5G (+0x1a8), then 2G (+0x28), before
		// quicksort. Its non-stable ties depend on that initial order.
		grouped := []mobility.Candidate{}
		for _, band := range []int{1, 0} {
			for _, n := range neighbors {
				if n.Band == band {
					grouped = append(grouped, n)
				}
			}
		}
		selected := (mobility.Selection{CurrentRSSI: currentRSSI, CurrentRate: currentRate, ThresholdType2G: settings.Band2G.Type, ThresholdType5G: settings.Band5G.Type}).Select(grouped)
		row := capwap.RoamResultStation{MAC: sta.MAC}
		row.APBitmap[0] = 1
		d := RoamDecision{At: now, AP: ap.ID, MAC: net.HardwareAddr(sta.MAC[:]).String(), Candidates: []string{}, Reason: "原厂速率、负载及 RSSI 门限未选中候选"}
		// Preflight the AP union: a packet cannot address more than128 APs.
		needed := map[[6]byte]bool{}
		for _, a := range out.APs {
			needed[a] = true
		}
		for _, n := range neighbors {
			needed[apMAC(m.known[n.AP])] = true
		}
		if len(out.Stations) >= 128 || len(needed) > 128 {
			flush()
		}
		for _, n := range selected {
			idx := addAP(n.AP)
			if idx < 0 {
				continue
			}
			row.APBitmap[idx/8] |= 1 << uint(idx%8)
			row.Candidates = append(row.Candidates, capwap.RoamCandidate{APIndex: uint8(idx), Radio: n.Radio, WLAN: n.WLAN, BSSID: [6]byte(n.BSSID), Channel: n.Channel})
			d.Candidates = append(d.Candidates, fmt.Sprintf("%s/%d", n.AP, n.Radio))
		}
		// Unselected neighbors also receive the station bitmap, 5G then2G.
		for _, band := range []int{1, 0} {
			for _, n := range neighbors {
				if n.Band != band {
					continue
				}
				if idx := addAP(n.AP); idx >= 0 {
					row.APBitmap[idx/8] |= 1 << uint(idx%8)
				}
			}
		}
		if len(selected) > 0 {
			d.Reason = "原厂 roam_nbr_select 选择结果"
		}
		out.Stations = append(out.Stations, row)
		m.roamHistory = append(m.roamHistory, d)
	}
	flush()
	if len(m.roamHistory) > 1000 {
		m.roamHistory = append([]RoamDecision{}, m.roamHistory[len(m.roamHistory)-1000:]...)
	}
	return results
}

// Called inside the event transaction. Submission is nonblocking, including
// for the source AP whose inbound handler still owns its session lock.
func (m *Manager) submitRoamingLocked(source string, job *roamJob) {
	for _, target := range job.Targets {
		ticket, err := m.engine.QueueAP(context.Background(), target, 7, []capwap.Element{privateSetting(0x59, job.Result.AssembleValue())})
		if err != nil {
			m.status[target.ID+"/roaming-result"] = ApplyStatus{AP: target.ID, Service: "roaming-result", State: "failed", Error: err.Error(), At: time.Now()}
			continue
		}
		job.Pending++
		target := target
		go func() {
			_, err := ticket.Wait(context.Background())
			st := ApplyStatus{AP: target.ID, Service: "roaming-result", State: "acknowledged", At: time.Now()}
			if err != nil {
				st.State = "failed"
				st.Error = err.Error()
			}
			m.mu.Lock()
			defer m.mu.Unlock()
			if current, ok := m.known[target.ID]; ok && current.ConnectedAt.Equal(target.ConnectedAt) {
				m.status[target.ID+"/roaming-result"] = st
			}
			job.Pending--
			if job.Pending == 0 {
				m.finishRoamingLocked(source, job.ID)
			}
		}()
	}
	if job.Pending == 0 {
		m.finishRoamingLocked(source, job.ID)
	}
}
func (m *Manager) finishRoamingLocked(source string, id uint64) {
	rows := m.roamJobs[source]
	for i, v := range rows {
		if v.ID == id {
			rows = append(rows[:i], rows[i+1:]...)
			break
		}
	}
	if len(rows) == 0 {
		delete(m.roamJobs, source)
	} else {
		m.roamJobs[source] = rows
	}
}
