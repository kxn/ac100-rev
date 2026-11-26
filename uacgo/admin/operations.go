package admin

import (
	"context"
	"encoding/json"
	"fmt"
	"net/http"
	"os"
	"path/filepath"
	"strings"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

type APOperation struct {
	ID         string    `json:"id"`
	AP         string    `json:"ap_id"`
	Action     string    `json:"action"`
	State      string    `json:"state"`
	Error      string    `json:"error,omitempty"`
	Started    time.Time `json:"started"`
	Connection time.Time `json:"connection"`
	Updated    time.Time `json:"updated"`
}

func (m *Manager) operationPath() string {
	return filepath.Join(filepath.Dir(m.path), "ap-operations.json")
}
func (m *Manager) loadOperations() error {
	b, err := os.ReadFile(m.operationPath())
	if os.IsNotExist(err) {
		return nil
	}
	if err != nil {
		return err
	}
	var jobs map[string]APOperation
	if err := json.Unmarshal(b, &jobs); err != nil {
		return fmt.Errorf("设备操作记录损坏，未自动执行计划: %w", err)
	}
	if jobs == nil {
		return fmt.Errorf("设备操作记录为空，未自动执行计划")
	}
	for id, j := range jobs {
		if j.State == "sending" {
			j.State = "uncertain"
			j.Error = "上次退出前未确认设备应答，未自动重发"
			jobs[id] = j
		}
	}
	m.operations = jobs
	return nil
}
func (m *Manager) observeOperations() {
	aps := m.engine.APs()
	byID := map[string]cweng.APStatus{}
	for _, ap := range aps {
		byID[ap.ID] = ap
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	changed := false
	for id, job := range m.operations {
		if job.State != "waiting_reconnect" && job.State != "sending" && job.State != "uncertain" {
			continue
		}
		if ap, ok := byID[job.AP]; ok && ap.Online && ap.ConnectedAt.After(job.Connection) {
			job.State = "completed"
			job.Updated = time.Now()
			m.operations[id] = job
			changed = true
		} else if time.Since(job.Started) > 5*time.Minute {
			job.State = "failed"
			job.Error = "未在五分钟内观察到 AP 重新接入"
			job.Updated = time.Now()
			m.operations[id] = job
			changed = true
		}
	}
	if changed {
		_ = atomicJSON(m.operationPath(), m.operations)
	}
}
func (m *Manager) apAction(ctx context.Context, ap cweng.APStatus, action, id string) (APOperation, error) {
	if action != "reboot" && action != "factory-reset" && action != "reboot-device" {
		return APOperation{}, fmt.Errorf("未知 AP 操作")
	}
	m.mu.Lock()
	if previous, ok := m.operations[id]; ok {
		m.mu.Unlock()
		return previous, nil
	}
	if m.upgradeBusyLocked(ap.ID) {
		m.mu.Unlock()
		return APOperation{}, fmt.Errorf("AP 正在升级")
	}
	for _, job := range m.operations {
		if job.AP == ap.ID && (job.State == "sending" || job.State == "waiting_reconnect") {
			m.mu.Unlock()
			return APOperation{}, fmt.Errorf("此 AP 已有重启/复位操作进行中")
		}
	}
	job := APOperation{ID: id, AP: ap.ID, Action: action, State: "sending", Started: time.Now(), Updated: time.Now(), Connection: ap.ConnectedAt}
	m.operations[id] = job
	if err := atomicJSON(m.operationPath(), m.operations); err != nil {
		delete(m.operations, id)
		m.mu.Unlock()
		return APOperation{}, err
	}
	m.mu.Unlock()
	var els []capwap.Element
	if action == "factory-reset" {
		els = []capwap.Element{privateSetting(0x23, []byte{0, 0, 0, 1})}
	}
	var err error
	if action == "reboot-device" {
		// Native AP Web uses this exact operation for a full device reboot. The
		// original CAPWAP Reset request only restarts this AP's control state.
		var raw json.RawMessage
		raw, err = m.engine.RequestJSON(cweng.PinAP(ctx, ap), ap.ID, json.RawMessage(`{"method":"do","system":{"reboot":null}}`))
		if err == nil {
			err = modelResult(raw)
		}
	} else {
		_, err = m.engine.Request(cweng.PinAP(ctx, ap), ap.ID, 17, els)
	}
	job.Updated = time.Now()
	job.State = "waiting_reconnect"
	if err != nil {
		job.State = "failed"
		job.Error = err.Error()
		if strings.Contains(err.Error(), "timeout") || strings.Contains(err.Error(), "closed") || ctx.Err() != nil {
			job.State = "uncertain"
		}
	}
	m.mu.Lock()
	m.operations[id] = job
	saveErr := atomicJSON(m.operationPath(), m.operations)
	m.mu.Unlock()
	if err == nil {
		err = saveErr
	}
	return job, err
}
func (m *Manager) apActionHTTP(w http.ResponseWriter, r *http.Request) {
	var body struct {
		Action string `json:"action"`
	}
	if err := decodeManagement(w, r, &body); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	var ap *cweng.APStatus
	for _, a := range m.APs() {
		if a.ID == r.PathValue("id") && a.Online {
			v := a
			ap = &v
		}
	}
	if ap == nil {
		jsonReply(w, 409, map[string]string{"error": "AP 未在线"})
		return
	}
	job, err := m.apAction(r.Context(), *ap, body.Action, newManagementID("operation"))
	if err != nil {
		jsonReply(w, 502, map[string]any{"error": err.Error(), "operation": job})
		return
	}
	jsonReply(w, 202, job)
}
func scheduleOccurrence(s *ServiceSchedule, now time.Time) string {
	if s == nil || !s.Enabled || !s.active(now) {
		return ""
	}
	loc, err := time.LoadLocation(s.Timezone)
	if err != nil {
		return ""
	}
	now = now.In(loc)
	day := (int(now.Weekday()) + 6) % 7
	minute := now.Hour()*60 + now.Minute()
	for i, w := range s.Windows {
		anchor := now
		inside := w.Start < w.End && w.Days&(1<<day) != 0 && minute >= w.Start && minute < w.End
		if w.Start > w.End {
			inside = w.Days&(1<<day) != 0 && minute >= w.Start
			if w.Days&(1<<((day+6)%7)) != 0 && minute < w.End {
				inside = true
				anchor = now.AddDate(0, 0, -1)
			}
		}
		if inside {
			return fmt.Sprintf("%s/%d", anchor.Format("2006-01-02"), i)
		}
	}
	return ""
}
func (m *Manager) runAPSchedules(ctx context.Context, ap cweng.APStatus, o APOptions) error {
	if occurrence := scheduleOccurrence(o.RebootSchedule, time.Now()); occurrence != "" {
		rule := configurationKey(o.RebootSchedule, time.Time{})[:16]
		_, err := m.apAction(ctx, ap, "reboot", ap.ID+"/scheduled-reboot/"+rule+"/"+occurrence)
		return err
	}
	return nil
}
