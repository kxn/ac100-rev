package admin

import (
	"context"
	"encoding/json"
	"fmt"
	"net/http"
	"os"
	"path/filepath"
	"strconv"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

type RRMJob struct {
	ID             string               `json:"id"`
	Rule           RRMRule              `json:"rule"`
	State          string               `json:"state"`
	Error          string               `json:"error,omitempty"`
	Started        time.Time            `json:"started"`
	Updated        time.Time            `json:"updated"`
	BaseVersion    uint64               `json:"base_version"`
	AppliedVersion uint64               `json:"applied_version,omitempty"`
	Targets        map[string]time.Time `json:"targets"`
	Scans          map[string]time.Time `json:"scans"`
	Changes        []RRMChange          `json:"changes"`
}

func (m *Manager) rrmPath() string    { return filepath.Join(filepath.Dir(m.path), "rrm-jobs.json") }
func (m *Manager) saveRRMJobs() error { return atomicJSON(m.rrmPath(), m.rrmJobs) }
func (m *Manager) loadRRMJobs() error {
	m.rrmJobs = map[string]RRMJob{}
	b, err := os.ReadFile(m.rrmPath())
	if os.IsNotExist(err) {
		return nil
	}
	if err != nil {
		return err
	}
	if err = json.Unmarshal(b, &m.rrmJobs); err != nil {
		return err
	}
	if m.rrmJobs == nil {
		return fmt.Errorf("无线优化任务库损坏")
	}
	for id, j := range m.rrmJobs {
		if j.State == "planning" {
			j.State = "failed"
			j.Error = "计划未完成保存，未重新执行测量"
			if m.config.Version == j.AppliedVersion {
				applied := true
				for _, change := range j.Changes {
					found := false
					for _, r := range m.config.Radios {
						if r.AP == change.AP && r.Radio == change.Radio && configurationKey(r, time.Time{}) == configurationKey(change.Setting, time.Time{}) {
							found = true
						}
					}
					applied = applied && found
				}
				if applied {
					j.State = "applying"
					j.Error = ""
				}
			}
			m.rrmJobs[id] = j
		}
		if j.State == "collecting" || j.State == "preparing" {
			j.State = "failed"
			j.Error = "程序在测量期间重启，保留原射频配置"
			j.Updated = time.Now()
			m.rrmJobs[id] = j
		}
	}
	return nil
}
func (m *Manager) startRRM(rule RRMRule, id string) (RRMJob, error) { // Manager.mu held.
	if m.mobilityScan.State == "collecting" || m.mobilityScan.State == "planning" || m.mobilityScan.State == "applying" {
		return RRMJob{}, fmt.Errorf("高性能漫游信道测量正在运行")
	}
	if err := validateRRMRules([]RRMRule{rule}, m.config); err != nil {
		return RRMJob{}, err
	}
	if old, ok := m.rrmJobs[id]; id != "" && ok {
		return old, nil
	}
	for _, j := range m.rrmJobs {
		if j.State == "collecting" || j.State == "applying" {
			return RRMJob{}, fmt.Errorf("已有无线优化任务正在运行")
		}
	}
	if id == "" {
		id = newManagementID("rrm")
	}
	j := RRMJob{ID: id, Rule: rule, State: "collecting", Started: time.Now(), Updated: time.Now(), BaseVersion: m.config.Version, Targets: map[string]time.Time{}, Scans: map[string]time.Time{}}
	for _, ap := range m.known {
		if !ap.Online || !rule.matches(ap.ID, m.config) {
			continue
		}
		if m.upgradeBusyLocked(ap.ID) {
			return RRMJob{}, fmt.Errorf("AP %s 正在升级", ap.ID)
		}
		if !ap.HasCapability(27) {
			return RRMJob{}, fmt.Errorf("AP %s 不支持全局优化", ap.ID)
		}
		active := m.config
		active.Services = append([]Service{}, active.Services...)
		for i := range active.Services {
			active.Services[i].Enabled = active.Services[i].Enabled && serviceOptions(active.Services[i]).Schedule.active(time.Now())
		}
		if m.settled[ap.ID] != configurationKey(effectiveRadioConfig(active, ap), ap.ConnectedAt) {
			return RRMJob{}, fmt.Errorf("AP %s 配置尚未同步完成", ap.ID)
		}
		selected := 0
		five := 0
		effective := effectiveRadioConfig(m.config, ap)
		for _, c := range ap.Capabilities {
			if c.FunctionType == 1 || c.Band != "2.4 GHz" && c.Band != "5 GHz" || rule.Frequency == 1 && c.Band != "2.4 GHz" || rule.Frequency == 2 && c.Band != "5 GHz" || radioDisabled(effective, ap.ID, c.RadioID) {
				continue
			}
			selected++
			b := rule.Band2G
			if c.Band == "5 GHz" {
				b = rule.Band5G
				five++
				if five > 1 && len(b.SecondChannels) > 0 {
					b.Channels = b.SecondChannels
				}
			}
			if rule.Channel && !hasInt(c.Bandwidths, b.Bandwidth) {
				return RRMJob{}, fmt.Errorf("AP %s 射频 %d 不支持所选带宽", ap.ID, c.RadioID)
			}
			if rule.Channel && len(rrmAllowed(c, b)) == 0 {
				return RRMJob{}, fmt.Errorf("AP %s 射频 %d 没有兼容带宽的候选信道", ap.ID, c.RadioID)
			}
			if rule.Power && (b.MinPower > c.MaxPower || b.MaxPower < c.MinPower) {
				return RRMJob{}, fmt.Errorf("优化功率超出 AP %s 能力", ap.ID)
			}
		}
		if selected == 0 {
			continue
		}
		j.Targets[ap.ID] = ap.ConnectedAt
	}
	if len(j.Targets) == 0 {
		return RRMJob{}, fmt.Errorf("没有符合规则的在线 AP")
	}
	m.rrmJobs[id] = j
	if err := m.saveRRMJobs(); err != nil {
		delete(m.rrmJobs, id)
		return RRMJob{}, err
	}
	return j, nil
}
func ndpElement(mac [6]byte, ap cweng.APStatus, c cweng.RadioCapability, channels []int) capwap.Element {
	power := c.DefaultPower
	for _, r := range ap.RadioStatus {
		if r.Radio == c.RadioID {
			power = int(r.Power)
		}
	}
	tail := []byte{}
	for _, ch := range channels {
		if hasInt(c.Channels, ch) && len(tail) < 32 {
			tail = append(tail, byte(ch))
		}
	}
	// V6 uac_rrm_init: magic AB, NDP counts/period/length 1/60/16,
	// modes FE preserve the AP's current mode and bandwidth during measurement.
	p := capwap.PrivNdpPara{MAC: mac, U8a: c.RadioID, U8b: 0xab, W1: 1, W2: 60, W3: 16, U8c: 0xfe, U8d: 0xfe, U8e: byte(power), U8f: byte(len(tail)), Tail: tail}
	return privateSetting(0x5c, p.AssembleValue())
}
func (m *Manager) rrmStep(ctx context.Context, ap cweng.APStatus) bool {
	m.mu.Lock()
	var job RRMJob
	found := false
	for _, j := range m.rrmJobs {
		if j.State == "collecting" {
			if _, ok := j.Targets[ap.ID]; ok {
				job = j
				found = true
				break
			}
		}
	}
	m.mu.Unlock()
	if !found {
		return false
	}
	if !job.Targets[ap.ID].Equal(ap.ConnectedAt) {
		m.failRRM(job.ID, "AP 在无线测量期间重新接入")
		return false
	}
	if _, sent := job.Scans[ap.ID]; !sent {
		five := 0
		effective := effectiveRadioConfig(m.snapshot(), ap)
		for _, c := range ap.Capabilities {
			if c.FunctionType == 1 {
				continue
			}
			if c.Band == "5 GHz" {
				five++
			}
			channels := job.Rule.Band2G.Channels
			if c.Band == "5 GHz" {
				if job.Rule.Frequency == 1 {
					continue
				}
				channels = job.Rule.Band5G.Channels
				if five > 1 && len(job.Rule.Band5G.SecondChannels) > 0 {
					channels = job.Rule.Band5G.SecondChannels
				}
			} else if c.Band == "2.4 GHz" {
				if job.Rule.Frequency == 2 {
					continue
				}
			} else {
				continue
			}
			if radioDisabled(effective, ap.ID, c.RadioID) {
				continue
			}
			if _, err := m.engine.Request(ctx, ap.ID, 7, []capwap.Element{ndpElement(m.ndpMAC, ap, c, channels)}); err != nil {
				m.failRRM(job.ID, err.Error())
				return false
			}
		}
		m.mu.Lock()
		j := m.rrmJobs[job.ID]
		if j.State == "collecting" {
			j.Scans[ap.ID] = time.Now()
			j.Updated = time.Now()
			m.rrmJobs[j.ID] = j
			if err := m.saveRRMJobs(); err != nil {
				j.State = "failed"
				j.Error = err.Error()
				m.rrmJobs[j.ID] = j
			}
		}
		m.mu.Unlock()
	}
	return true
}
func (m *Manager) failRRM(id, reason string) {
	m.mu.Lock()
	defer m.mu.Unlock()
	j := m.rrmJobs[id]
	j.State = "failed"
	j.Error = reason
	j.Updated = time.Now()
	m.rrmJobs[id] = j
	_ = m.saveRRMJobs()
	for ap := range j.Targets {
		m.invalidateRadioSettingsLocked(ap)
	}
}
func (m *Manager) invalidateRadioSettingsLocked(ap string) {
	for k := range m.applied {
		if len(k) > len(ap) && k[:len(ap)+1] == ap+"/" {
			delete(m.applied, k)
		}
	}
	delete(m.settled, ap)
}
func (m *Manager) tickRRM(now time.Time) { // Called after AP snapshots refresh.
	m.mu.Lock()
	defer m.mu.Unlock()
	for _, r := range m.config.RRM {
		if !r.Enabled || r.Schedule == nil || !r.Schedule.Enabled || !r.Schedule.active(now) {
			continue
		}
		id := "scheduled-rrm/" + r.ID + "/" + scheduleOccurrence(r.Schedule, now)
		if _, exists := m.rrmJobs[id]; !exists {
			_, _ = m.startRRM(r, id)
		}
	}
	changed := false
	for id, j := range m.rrmJobs {
		fail := func(reason string) {
			j.State = "failed"
			j.Error = reason
			j.Updated = now
			for ap := range j.Targets {
				m.invalidateRadioSettingsLocked(ap)
			}
			changed = true
		}
		switch j.State {
		case "collecting":
			if j.BaseVersion != m.config.Version {
				fail("测量期间配置已更改，取消本轮优化")
				break
			}
			aps := []cweng.APStatus{}
			last := j.Started
			ready := true
			for ap, connection := range j.Targets {
				a := m.known[ap]
				if !a.Online || !a.ConnectedAt.Equal(connection) {
					fail("目标 AP 离线或连接已更换")
					ready = false
					break
				}
				aps = append(aps, a)
				sent, ok := j.Scans[ap]
				ready = ready && ok
				if sent.After(last) {
					last = sent
				}
			}
			if j.State == "failed" {
				break
			}
			if !ready || now.Sub(last) < 65*time.Second {
				if now.Sub(j.Started) > 3*time.Minute {
					fail("无线测量超时")
				}
				break
			}
			plan, err := planRRM(j.Rule, aps, m.config, j.Started)
			if err != nil {
				fail(err.Error())
				break
			}
			next := m.config
			next.Radios = append([]RadioSetting{}, next.Radios...)
			for _, c := range plan {
				found := false
				for i, r := range next.Radios {
					if r.AP == c.AP && r.Radio == c.Radio {
						next.Radios[i] = c.Setting
						found = true
					}
				}
				if !found {
					next.Radios = append(next.Radios, c.Setting)
				}
			}
			// Persist the plan before changing controller configuration. Recovery can
			// distinguish a saved configuration from a measurement that never applied.
			j.Changes = plan
			j.AppliedVersion = m.config.Version + 1
			j.State = "planning"
			j.Updated = now
			m.rrmJobs[id] = j
			if err = m.saveRRMJobs(); err != nil {
				fail(err.Error())
				break
			}
			if err = m.saveManagement(next); err != nil {
				fail(err.Error())
				break
			}
			j.Changes = plan
			j.AppliedVersion = m.config.Version
			j.State = "applying"
			j.Updated = now
			changed = true
			for ap := range j.Targets {
				m.invalidateRadioSettingsLocked(ap)
			}
		case "applying":
			if m.config.Version != j.AppliedVersion {
				fail("优化下发期间配置已更改，请核对当前射频设置")
				break
			}
			done := true
			for ap, connection := range j.Targets {
				a := m.known[ap]
				if !a.Online || !a.ConnectedAt.Equal(connection) {
					fail("优化下发期间 AP 连接更换；已保存配置会在重连后继续同步")
					done = false
					break
				}
				if m.status[ap+"/configuration-commit"].State == "failed" {
					fail("AP 拒绝优化配置提交")
					done = false
					break
				}
				for _, c := range j.Changes {
					if c.AP != ap {
						continue
					}
					st := m.status[ap+"/radio:"+strconv.Itoa(int(c.Radio))]
					if st.State == "failed" || st.State == "failed_recovered" {
						fail(st.Error)
						done = false
						break
					}
					done = done && (st.State == "acknowledged" || st.State == "verified") && st.At.After(j.Updated)
				}
				b, _ := json.Marshal(m.config)
				var active Config
				_ = json.Unmarshal(b, &active)
				for i := range active.Services {
					active.Services[i].Enabled = active.Services[i].Enabled && serviceOptions(active.Services[i]).Schedule.active(now)
				}
				done = done && m.settled[ap] == configurationKey(effectiveRadioConfig(active, a), a.ConnectedAt)
			}
			if done {
				j.State = "completed"
				j.Updated = now
				changed = true
			} else if now.Sub(j.Updated) > 3*time.Minute {
				fail("优化配置下发或提交超时")
			}
		}
		m.rrmJobs[id] = j
	}
	if changed {
		_ = m.saveRRMJobs()
	}
}
func (m *Manager) rrmRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/rrm", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		jsonReply(w, 200, map[string]any{"rules": m.config.RRM, "jobs": m.rrmJobs, "defaults": defaultRRMRule()})
	})
	mux.HandleFunc("POST /api/rrm/rules", func(w http.ResponseWriter, r *http.Request) {
		var rows []RRMRule
		if err := decodeManagement(w, r, &rows); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.RRM = rows
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]string{"status": "saved"})
	})
	mux.HandleFunc("POST /api/rrm/run", func(w http.ResponseWriter, r *http.Request) {
		var v struct {
			Rule string `json:"rule_id"`
		}
		if err := decodeManagement(w, r, &v); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		for _, rule := range m.config.RRM {
			if rule.ID == v.Rule {
				j, err := m.startRRM(rule, "")
				if err != nil {
					jsonReply(w, 409, map[string]string{"error": err.Error()})
					return
				}
				jsonReply(w, 202, j)
				return
			}
		}
		jsonReply(w, 404, map[string]string{"error": "无线优化规则不存在"})
	})
}
