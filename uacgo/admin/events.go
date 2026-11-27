package admin

import (
	"context"
	"encoding/json"
	"net"
	"net/http"
	"time"
	"uacgo/cweng"
	"uacgo/internal/eventlog"
	"uacgo/mobility"
)

type diagnosticState struct {
	apply map[string]string
	rrm   map[string]string
	high  string
}

func (m *Manager) eventsEnabled() bool { return m.engine != nil && m.engine.Events.Enabled() }
func (m *Manager) event(event string, fields ...any) {
	if m.engine != nil {
		m.engine.Events.Event(event, fields...)
	}
}
func eventError(err error) string {
	if err == nil {
		return ""
	}
	return err.Error()
}
func (m *Manager) commandContext(ctx context.Context, ap cweng.APStatus, version uint64, kind string) context.Context {
	if !m.eventsEnabled() {
		return ctx
	}
	return eventlog.With(ctx, "ap_id", ap.ID, "session", ap.ConnectedAt, "config_version", version, "operation", kind)
}

// State transitions complement transport records. These are controller facts,
// not claims that an ACK proves a configuration or a client roam took effect.
func (m *Manager) captureDiagnostics() {
	if !m.eventsEnabled() {
		return
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	next := map[string]string{}
	for key, s := range m.status {
		signature, _ := json.Marshal([]any{s.AP, s.Service, s.State, s.Error, s.Reason, s.EffectiveEnabled})
		next[key] = string(signature)
		if m.diagnostics.apply[key] != next[key] {
			m.event("configuration.apply_state", "ap_id", s.AP, "item", s.Service, "state", s.State, "error", s.Error, "reason", s.Reason, "effective_enabled", s.EffectiveEnabled, "at", s.At, "observed_config_version", m.config.Version)
		}
	}
	m.diagnostics.apply = next
	jobs := map[string]string{}
	for id, j := range m.rrmJobs {
		signature, _ := json.Marshal([]any{j.State, j.Phase, j.Round, j.Pass, j.Error, j.ChannelCollectionFailed, j.PowerCollectionFailed, j.CommonChannelCancelled, j.PowerSkipped, j.Changes})
		jobs[id] = string(signature)
		if m.diagnostics.rrm[id] != jobs[id] {
			m.event("rrm.state", "job_id", id, "rule_id", j.Rule.ID, "policy", j.Rule.strategyVersion(), "state", j.State, "phase", j.Phase, "round", j.Round, "pass", j.Pass, "targets", j.Targets, "changes", j.Changes, "channel_collection_failed", j.ChannelCollectionFailed, "power_collection_failed", j.PowerCollectionFailed, "common_channel_cancelled", j.CommonChannelCancelled, "power_skipped", j.PowerSkipped, "error", j.Error, "base_version", j.BaseVersion, "applied_version", j.AppliedVersion)
		}
	}
	m.diagnostics.rrm = jobs
	h := m.highPerformance
	signature, _ := json.Marshal([]any{h.State, h.Error, h.Channels, actualMobilityMode(m.config), configuredMobilityMode(m.config)})
	if m.diagnostics.high != string(signature) {
		m.diagnostics.high = string(signature)
		m.event("acs.state", "state", h.State, "error", h.Error, "channels", h.Channels, "deadline", h.Deadline, "expected", h.Expected, "policy", mobilityPolicyVersion(m.config), "configured_mode", configuredMobilityMode(m.config), "actual_mode", actualMobilityMode(m.config))
	}
}

type loggedResponse struct {
	http.ResponseWriter
	status int
}

func (w *loggedResponse) WriteHeader(status int) {
	if w.status == 0 {
		w.status = status
	}
	w.ResponseWriter.WriteHeader(status)
}
func (w *loggedResponse) Write(b []byte) (int, error) {
	if w.status == 0 {
		w.WriteHeader(http.StatusOK)
	}
	return w.ResponseWriter.Write(b)
}
func (w *loggedResponse) Unwrap() http.ResponseWriter { return w.ResponseWriter }
func (m *Manager) observeHTTP(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		if !m.eventsEnabled() || (r.Method == http.MethodGet || r.Method == http.MethodHead || r.Method == http.MethodOptions) {
			next.ServeHTTP(w, r)
			return
		}
		started := time.Now()
		id := newManagementID("http")
		m.event("management.request", "request_id", id, "method", r.Method, "path", r.URL.Path, "remote", r.RemoteAddr)
		result := &loggedResponse{ResponseWriter: w}
		defer func() {
			status := result.status
			if status == 0 {
				status = http.StatusOK
			}
			m.event("management.response", "request_id", id, "status", status, "elapsed_ms", time.Since(started).Milliseconds())
		}()
		next.ServeHTTP(result, r)
	})
}

func eventMAC(mac [6]byte) string { return net.HardwareAddr(mac[:]).String() }
func candidateEvent(n mobility.Candidate) map[string]any {
	return map[string]any{"ap_id": n.AP, "radio": n.Radio, "wlan": n.WLAN, "channel": n.Channel, "bssid": eventMAC(n.BSSID), "band": n.Band, "rssi": n.RSSI, "rate": n.Rate, "load": n.Load}
}
func (m *Manager) selectionObserver(ap string, radio uint8, mac [6]byte, currentRSSI int8, currentRate int, settings RoamSettings, neighbors []mobility.Candidate) (mobility.SelectionObserver, uint64) {
	if !m.eventsEnabled() {
		return nil, 0
	}
	m.eventSequence++
	id := m.eventSequence
	m.event("roaming.decision", "decision_id", id, "ap_id", ap, "session", m.known[ap].ConnectedAt, "radio", radio, "client", eventMAC(mac), "policy", mobilityPolicyVersion(m.config), "actual_mode", actualMobilityMode(m.config), "config_version", m.config.Version, "current_rssi", currentRSSI, "current_rate", currentRate, "settings", settings, "candidate_count", len(neighbors))
	for i, n := range neighbors {
		m.event("roaming.candidate_input", "decision_id", id, "index", i, "candidate", candidateEvent(n))
	}
	return func(step mobility.SelectionStep) {
		m.event("roaming.selection_step", "decision_id", id, "phase", step.Phase, "reason", step.Reason, "rank", step.Rank, "candidate", candidateEvent(step.Candidate))
	}, id
}

func (m *Manager) itemContext(ctx context.Context, item string) context.Context {
	if !m.eventsEnabled() {
		return ctx
	}
	return eventlog.With(ctx, "item", item)
}
