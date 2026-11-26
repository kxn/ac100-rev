package admin

import (
	"context"
	"encoding/json"
	"fmt"
	"net/http"
	"strings"
	"time"
)

// Read-only diagnostics expose selected management fields, never the AP's
// complete native configuration (which may contain usernames and passwords).
func managementProjection(raw json.RawMessage) (map[string]any, error) {
	if err := modelResult(raw); err != nil {
		return nil, err
	}
	var root any
	if err := json.Unmarshal(raw, &root); err != nil {
		return nil, err
	}
	out := map[string]any{}
	var visit func(string, any)
	visit = func(path string, v any) {
		switch row := v.(type) {
		case map[string]any:
			for key, value := range row {
				lower := strings.ToLower(key)
				if strings.Contains(lower, "password") || strings.Contains(lower, "passwd") || strings.Contains(lower, "secret") || strings.Contains(lower, "token") || strings.Contains(lower, "username") {
					continue
				}
				next := key
				if path != "" {
					next = path + "." + key
				}
				switch value.(type) {
				case map[string]any, []any:
					visit(next, value)
				default:
					for _, part := range []string{"keep_alive", "keepalive", "echo", "heartbeat", "idle", "offline", "fallback", "discovery", "led"} {
						if strings.Contains(lower, part) {
							out[next] = value
							break
						}
					}
				}
			}
		case []any:
			for i, value := range row {
				visit(fmt.Sprintf("%s[%d]", path, i), value)
			}
		}
	}
	visit("", root)
	return out, nil
}
func (m *Manager) managementStateHTTP(w http.ResponseWriter, r *http.Request) {
	ctx, cancel := context.WithTimeout(r.Context(), 8*time.Second)
	defer cancel()
	raw, err := m.engine.RequestJSON(ctx, r.PathValue("id"), json.RawMessage(`{"method":"get","capwap":{"name":"fit_specific"}}`))
	if err != nil {
		jsonReply(w, 502, map[string]string{"error": err.Error()})
		return
	}
	fields, err := managementProjection(raw)
	if err != nil {
		jsonReply(w, 502, map[string]string{"error": err.Error()})
		return
	}
	jsonReply(w, 200, map[string]any{"fields": fields, "received_at": time.Now()})
}
