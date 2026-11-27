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
	firmware "uacgo/rrm"
)

type RRMJob struct {
	Phase                   string               `json:"phase,omitempty"`
	PowerSkipped            bool                 `json:"power_skipped,omitempty"`
	ChannelCollectionFailed bool                 `json:"channel_collection_failed,omitempty"`
	PowerCollectionFailed   bool                 `json:"power_collection_failed,omitempty"`
	CommonChannelCancelled  bool                 `json:"common_channel_cancelled,omitempty"`
	CommonChannelPhase      bool                 `json:"common_channel_phase,omitempty"`
	CommonChannel           bool                 `json:"common_channel,omitempty"`
	ACSWaitAttempts         int                  `json:"acs_wait_attempts,omitempty"`
	Round                   int                  `json:"round"`
	Pass                    int                  `json:"pass"`
	CollectUntil            time.Time            `json:"collect_until"`
	ID                      string               `json:"id"`
	Rule                    RRMRule              `json:"rule"`
	State                   string               `json:"state"`
	Error                   string               `json:"error,omitempty"`
	Started                 time.Time            `json:"started"`
	Updated                 time.Time            `json:"updated"`
	BaseSignature           string               `json:"base_signature,omitempty"`
	AppliedSignature        string               `json:"applied_signature,omitempty"`
	BaseVersion             uint64               `json:"base_version"`
	AppliedVersion          uint64               `json:"applied_version,omitempty"`
	Targets                 map[string]time.Time `json:"targets"`
	Scans                   map[string]time.Time `json:"scans"`
	Changes                 []RRMChange          `json:"changes"`
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
	if err := validateRRMRules([]RRMRule{rule}, m.config); err != nil {
		return RRMJob{}, err
	}
	if old, ok := m.rrmJobs[id]; id != "" && ok {
		return old, nil
	}
	if !rule.Channel && !rule.Power {
		return RRMJob{}, fmt.Errorf("请至少选择信道或功率优化")
	}
	for _, j := range m.rrmJobs {
		if j.State == "collecting" || j.State == "applying" {
			return RRMJob{}, fmt.Errorf("已有无线优化任务正在运行")
		}
	}
	if id == "" {
		id = newManagementID("rrm")
	}
	j := RRMJob{ID: id, Rule: rule, State: "collecting", Started: time.Now(), Updated: time.Now(), BaseVersion: m.config.Version, BaseSignature: wirelessConfigKey(m.config), Targets: map[string]time.Time{}, Scans: map[string]time.Time{}}
	if actualMobilityMode(m.config) == 1 && !rule.usesV4() {
		return RRMJob{}, fmt.Errorf("V6射频优化仅适用于兼容网络模式；高性能网络请使用V4共同信道优化")
	}
	if actualMobilityMode(m.config) == 1 && !rule.Channel && rule.Power {
		return RRMJob{}, fmt.Errorf("V4高性能模式不支持功率优化")
	}
	if actualMobilityMode(m.config) == 1 && rule.Channel {
		return m.startHighPerformanceRRMJobLocked(j)
	}
	return m.startRRMMeasurementLocked(j, false)
}

func (m *Manager) startRRMMeasurementLocked(j RRMJob, afterCommonChannel bool) (RRMJob, error) {
	rule, id := j.Rule, j.ID
	j.BaseVersion, j.BaseSignature = m.config.Version, wirelessConfigKey(m.config)
	j.Targets = map[string]time.Time{}
	for _, ap := range m.known {
		if !ap.Online || !rule.matches(ap.ID, m.config) {
			continue
		}
		if m.upgradeBusyLocked(ap.ID) {
			return RRMJob{}, fmt.Errorf("AP %s 正在升级", ap.ID)
		}
		if !ap.HasCapability(27) {
			continue
		}
		active := m.config
		active.Services = append([]Service{}, active.Services...)
		for i := range active.Services {
			active.Services[i].Enabled = active.Services[i].Enabled && serviceOptions(active.Services[i]).Schedule.active(time.Now())
		}
		if !afterCommonChannel && m.settled[ap.ID] != configurationKey(effectiveRadioConfig(active, ap), ap.ConnectedAt) {
			return RRMJob{}, fmt.Errorf("AP %s 配置尚未同步完成", ap.ID)
		}
		selected := 0
		effective := effectiveRadioConfig(m.config, ap)
		for _, c := range ap.Capabilities {
			if c.FunctionType == 1 || c.Band != "2.4 GHz" && c.Band != "5 GHz" || rule.Frequency == 1 && c.Band != "2.4 GHz" || rule.Frequency == 2 && c.Band != "5 GHz" || radioDisabled(effective, ap.ID, c.RadioID) {
				continue
			}
			selected++
		}
		if selected == 0 {
			continue
		}
		j.Targets[ap.ID] = ap.ConnectedAt
	}
	if len(j.Targets) == 0 {
		return RRMJob{}, fmt.Errorf("没有符合规则的在线 AP")
	}
	aps := []cweng.APStatus{}
	for ap := range j.Targets {
		aps = append(aps, m.known[ap])
	}
	nodes, err := rrmNodes(rule, aps, m.config, time.Now())
	if err != nil {
		return RRMJob{}, err
	}
	j.Targets = map[string]time.Time{}
	for _, n := range nodes {
		j.Targets[n.AP.ID] = n.AP.ConnectedAt
	}
	run, err := newRRMRunForRule(nodes, rule)
	if err != nil {
		return RRMJob{}, err
	}
	run.beginPass(rule, time.Now())
	if m.rrmRuns == nil {
		m.rrmRuns = map[string]*rrmRun{}
	}
	m.rrmRuns[id] = run
	j.Round = run.round
	if run.v4 != nil {
		j.Phase = run.v4.phase
	}
	j.Pass = run.pass
	j.CollectUntil = run.deadline
	m.rrmJobs[id] = j
	if err := m.saveRRMJobs(); err != nil {
		delete(m.rrmJobs, id)
		delete(m.rrmRuns, id)
		return RRMJob{}, err
	}
	m.dispatchRRMCommandsLocked(&j, run)
	m.rrmJobs[id] = j
	_ = m.saveRRMJobs()
	return j, nil
}
func ndpElement(mac [6]byte, n rrmNode, channel int, level uint8) capwap.Element {
	a := defaultRadioAdvanced(n.Cap)
	if n.Setting.Advanced != nil {
		a = *n.Setting.Advanced
	}
	// RRM measurement uses the current PHY with the requested optimization
	// bandwidth; the FE preserve path is not used by this business entrypoint.
	a.Bandwidth = n.Band.Bandwidth
	a = rrmMeasurementMode(a, n.Cap)
	bw := a.Bandwidth
	if bw == 2 {
		bw = 0
	}
	power := firmware.PowerForLevel(level, uint8(n.Cap.MaxPower), uint8(n.Cap.MinPower))
	// rdmngr_db_get_real_max_tx_pwr @72de04, default profile @8edd28:
	// all38 supported fixed channels have a50dBm upper bound; auto has
	// the hardware bound. The Linux host's region configuration is unrelated.
	if n.Setting.Channel != nil && *n.Setting.Channel != 0 && power > 50 {
		power = 50
	}
	p := capwap.PrivNdpPara{MAC: mac, U8a: n.Cap.RadioID, U8b: 0xab, W1: 1, W2: 60, W3: 16, U8c: byte(a.Mode), U8d: byte(bw), U8e: power, U8f: 1, Tail: []byte{byte(channel)}}
	return privateSetting(0x5c, p.AssembleValue())
}
func (m *Manager) observeRRMReport(ap string, connection time.Time, report capwap.PrivRrmNeighsList) {
	m.mu.Lock()
	defer m.mu.Unlock()
	for id, run := range m.rrmRuns {
		job := m.rrmJobs[id]
		if job.State != "collecting" || !job.Targets[ap].Equal(connection) {
			continue
		}
		for i, n := range run.nodes {
			if n.AP.ID != ap || n.Cap.RadioID != report.A {
				continue
			}
			if !run.received[i] {
				run.received[i] = true
				run.receivedCount++
			}
			if q, ok := run.requests[i]; ok {
				q.received = true
			}
			m.event("rrm.measurement_report", "job_id", id, "policy", job.Rule.strategyVersion(), "ap_id", ap, "session", connection, "radio", report.A, "round", run.round, "neighbors", report.Neighs)
			run.ingest(i, report.Neighs, run.round > 1)
			run.projectV4Mesh(i, report.Neighs, m.config, m.known)
			m.wakeRRMLocked()
		}
	}
}

// Queue the complete frozen set while holding the business-state lock, just
// as the firmware holds its runtime reference during serv_packet_send calls.
// QueueAP never takes a session lock and never waits for an ACK.
func (m *Manager) dispatchRRMCommandsLocked(job *RRMJob, run *rrmRun) {
	for _, band := range []int{0, 1} {
		for i, n := range run.nodes {
			q, ok := run.requests[i]
			if !ok || q.sent || n.BandID != band {
				continue
			}
			element := run.measurementElement(m.ndpMAC, i, q.channel)
			if p, err := capwap.ParsePrivNdpPara(element.Value[10:]); err == nil {
				run.levels[i] = firmware.LevelForPower(p.U8e, uint8(n.Cap.MaxPower), uint8(n.Cap.MinPower))
			}
			ctx := m.commandContext(context.Background(), n.AP, job.BaseVersion, "rrm_measurement")
			ctx = m.itemContext(ctx, job.ID)
			m.event("rrm.measurement_requested", "job_id", job.ID, "policy", job.Rule.strategyVersion(), "ap_id", n.AP.ID, "radio", n.Cap.RadioID, "round", run.round, "channel", q.channel)
			ticket, err := m.engine.QueueAP(ctx, n.AP, 7, []capwap.Element{element})
			if err != nil {
				delete(run.requests, i) // original count increases only on successful queueing
				m.status[n.AP.ID+"/rrm-measurement"] = ApplyStatus{AP: n.AP.ID, Service: "rrm-measurement", State: "failed", Error: err.Error(), At: time.Now()}
				continue
			}
			run.markDispatched(i, q, time.Now())
			job.Scans[n.AP.ID] = time.Now()
			ap := n.AP
			go func() {
				_, err := ticket.Wait(context.Background())
				if err == nil {
					return
				}
				m.mu.Lock()
				defer m.mu.Unlock()
				if current, ok := m.known[ap.ID]; ok && current.ConnectedAt.Equal(ap.ConnectedAt) {
					m.status[ap.ID+"/rrm-measurement"] = ApplyStatus{AP: ap.ID, Service: "rrm-measurement", State: "failed", Error: err.Error(), At: time.Now()}
				}
			}()
		}
	}
	// @527944 arms the collection timer after queueing, including an empty set.
	run.deadline = time.Now().Add(rrmCollectionTimeout)
	job.CollectUntil = run.deadline
	m.wakeRRMLocked()
}
func (m *Manager) rrmStep(ctx context.Context, ap cweng.APStatus) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	for _, job := range m.rrmJobs {
		if job.State == "collecting" && !job.CommonChannelPhase {
			if connection, ok := job.Targets[ap.ID]; ok && connection.Equal(ap.ConnectedAt) {
				return true
			}
		}
	}
	return false
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
			if j.CommonChannelPhase {
				if j.CollectUntil.IsZero() {
					if actualMobilityMode(m.config) != 1 {
						j.CollectUntil = j.Started.Add(highPerformanceTimeout(m.config.Mobility) + 5*time.Second)
						changed = true
					} else {
						if m.highPerformance.State == "failed" {
							fail(m.highPerformance.Error)
						}
						break
					}
				}
				if now.Before(j.CollectUntil) {
					break
				}
				if m.highPerformance.State == "collecting" && j.ACSWaitAttempts < 10 {
					j.ACSWaitAttempts++
					j.CollectUntil = now.Add(highPerformanceTimeout(m.config.Mobility) + 5*time.Second)
					changed = true
					break
				}
				cancelled := actualMobilityMode(m.config) != 1
				j.CommonChannelCancelled = cancelled
				j.CommonChannelPhase = false
				if j.Rule.Power && actualMobilityMode(m.config) == 2 {
					j.Rule.Channel = false
					continued, err := m.startRRMMeasurementLocked(j, true)
					if err != nil {
						fail(err.Error())
					} else {
						j = continued
						changed = true
					}
					break
				}
				j.PowerSkipped = j.Rule.Power
				if cancelled {
					j.State = "completed"
					j.Changes = nil
				} else {
					j = m.finishHighPerformanceRRMJobLocked(j)
				}
				changed = true
				break
			}
			if j.BaseSignature != wirelessConfigKey(m.config) {
				fail("测量期间配置已更改，取消本轮优化")
				break
			}
			aps := []cweng.APStatus{}
			run := m.rrmRuns[id]
			if run == nil {
				fail("无线优化运行状态已丢失")
				break
			}
			for ap, connection := range j.Targets {
				a := m.known[ap]
				if !a.Online || !a.ConnectedAt.Equal(connection) {
					fail("目标 AP 离线或连接已更换")
					break
				}
				aps = append(aps, a)
			}
			if j.State == "failed" || !run.collected(now) {
				break
			}
			collectAgain, err := run.finishPass(j.Rule)
			if err != nil {
				fail(err.Error())
				break
			}
			if collectAgain {
				run.beginPass(j.Rule, now)
				j.Round = run.round
				if run.v4 != nil {
					j.Phase = run.v4.phase
				}
				j.Pass = run.pass
				j.CollectUntil = run.deadline
				j.Scans = map[string]time.Time{}
				m.dispatchRRMCommandsLocked(&j, run)
				changed = true
				break
			}
			if run.v4 != nil {
				j.ChannelCollectionFailed = run.v4.channelAborted
				j.PowerCollectionFailed = run.v4.powerAborted
			}
			plan, err := run.changes(j.Rule, m.config)
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
			if err = m.saveManagementFrom(next, managementRRM); err != nil {
				fail(err.Error())
				break
			}
			j.Changes = plan
			j.AppliedVersion = m.config.Version
			j.AppliedSignature = wirelessConfigKey(m.config)
			j.State = "applying"
			j.Updated = now
			changed = true
			for ap := range j.Targets {
				m.invalidateRadioSettingsLocked(ap)
			}
		case "applying":
			if j.AppliedSignature != "" && wirelessConfigKey(m.config) != j.AppliedSignature {
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
		if j.State != "collecting" {
			delete(m.rrmRuns, id)
		}
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
		if err := m.saveManagementFrom(next, managementRRM); err != nil {
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

func (m *Manager) wakeRRMLocked() {
	select {
	case m.rrmWake <- struct{}{}:
	default:
	}
}

// Report completion and the vendor90-second deadline wake the business task
// directly. They must not inherit the UI inventory polling interval.
func (m *Manager) runRRM(ctx context.Context) {
	for {
		m.mu.Lock()
		deadline := time.Now().Add(24 * time.Hour)
		for _, job := range m.rrmJobs {
			if job.State == "collecting" && job.CommonChannelPhase && !job.CollectUntil.IsZero() && job.CollectUntil.Before(deadline) {
				deadline = job.CollectUntil
			}
		}
		for id, run := range m.rrmRuns {
			if m.rrmJobs[id].State == "collecting" && !run.deadline.IsZero() && run.deadline.Before(deadline) {
				deadline = run.deadline
			}
		}
		m.mu.Unlock()
		timer := time.NewTimer(max(time.Duration(0), time.Until(deadline)))
		select {
		case <-ctx.Done():
			timer.Stop()
			return
		case <-m.rrmWake:
			timer.Stop()
		case <-timer.C:
		}
		m.tickRRM(time.Now())
	}
}
