package admin

import (
	"context"
	"encoding/json"
	"net"
	"net/http"
	"strconv"
	"strings"
	"time"
	"uacgo/cweng"
)

func nativeRows(raw json.RawMessage, module, table string) ([]map[string]json.RawMessage, error) {
	if err := modelResult(raw); err != nil {
		return nil, err
	}
	var root map[string]json.RawMessage
	if err := json.Unmarshal(raw, &root); err != nil {
		return nil, err
	}
	var mod map[string]json.RawMessage
	if err := json.Unmarshal(root[module], &mod); err != nil {
		return nil, err
	}
	var entries []map[string]map[string]json.RawMessage
	if err := json.Unmarshal(mod[table], &entries); err != nil {
		return nil, err
	}
	out := []map[string]json.RawMessage{}
	for _, row := range entries {
		for _, v := range row {
			out = append(out, v)
		}
	}
	return out, nil
}
func nativeString(row map[string]json.RawMessage, k string) string {
	var s string
	if json.Unmarshal(row[k], &s) == nil {
		return s
	}
	return string(row[k])
}
func (m *Manager) mergeClientFacts(ap string, stations, hosts json.RawMessage) error {
	rows, err := nativeRows(stations, "wireless", "sta_list")
	if err != nil {
		return err
	}
	hostRows, err := nativeRows(hosts, "hosts_info", "host_info")
	if err != nil {
		return err
	}
	active := map[[6]byte]time.Time{}
	for _, r := range rows {
		mac, e := net.ParseMAC(normalizeMAC(nativeString(r, "mac")))
		if e != nil || len(mac) != 6 {
			continue
		}
		var id [6]byte
		copy(id[:], mac)
		var since time.Time
		if n, e := strconv.ParseUint(nativeString(r, "connect_time"), 10, 32); e == nil {
			since = time.Now().Add(-time.Duration(n) * time.Second)
		}
		active[id] = since
	}
	for _, r := range hostRows {
		mac, e := net.ParseMAC(normalizeMAC(nativeString(r, "mac")))
		if e != nil || len(mac) != 6 {
			continue
		}
		var id [6]byte
		copy(id[:], mac)
		if since, ok := active[id]; ok {
			m.clients.NetworkInfo(ap, id, nativeString(r, "ip"), since)
		}
	}
	return nil
}
func normalizeMAC(s string) string { return strings.ReplaceAll(strings.ToLower(s), "-", ":") }
func (m *Manager) refreshClientFacts(ctx context.Context, ap cweng.APStatus) {
	// A legacy AP can omit the native model. Failure remains retryable and does
	// not prevent its normal CAPWAP association/statistics paths from operating.
	if m.clients == nil {
		return
	}
	if !ap.HasCapability(66) {
		return
	}
	m.mu.Lock()
	last := m.clientRefresh[ap.ID]
	if time.Since(last) < 30*time.Second {
		m.mu.Unlock()
		return
	}
	if m.clientRefresh == nil {
		m.clientRefresh = map[string]time.Time{}
	}
	m.clientRefresh[ap.ID] = time.Now()
	m.mu.Unlock()
	c, cancel := context.WithTimeout(ctx, 8*time.Second)
	defer cancel()
	started := time.Now()
	stations, err := m.engine.RequestJSON(c, ap.ID, json.RawMessage(`{"method":"get","wireless":{"table":"sta_list"}}`))
	if err != nil {
		return
	}
	hosts, err := m.engine.RequestJSON(c, ap.ID, json.RawMessage(`{"method":"get","hosts_info":{"table":"host_info"}}`))
	if err != nil {
		return
	}
	_ = m.mergeWirelessSnapshot(ap, started, stations, hosts)
	_ = m.mergeClientFacts(ap.ID, stations, hosts)
}

// Only public wireless/host tables, over the authenticated AP session. This is
// a diagnostic read; secrets and unrelated native model fields are omitted.
func (m *Manager) clientStateHTTP(w http.ResponseWriter, r *http.Request) {
	ctx, cancel := context.WithTimeout(r.Context(), 15*time.Second)
	defer cancel()
	out := map[string]any{}
	for _, q := range []struct {
		key  string
		body string
	}{{"wireless", `{"method":"get","wireless":{"table":"sta_list"}}`}, {"hosts", `{"method":"get","hosts_info":{"table":"host_info"}}`}} {
		raw, err := m.engine.RequestJSON(ctx, r.PathValue("id"), json.RawMessage(q.body))
		if err != nil {
			out[q.key] = map[string]string{"error": err.Error()}
			continue
		}
		if err = modelResult(raw); err != nil {
			out[q.key] = map[string]string{"error": err.Error()}
			continue
		}
		var v any
		if json.Unmarshal(raw, &v) == nil {
			out[q.key] = v
		}
	}
	jsonReply(w, 200, out)
}
