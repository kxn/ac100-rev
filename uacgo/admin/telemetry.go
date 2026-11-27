package admin

import (
	"context"
	"crypto/md5"
	"encoding/binary"
	"encoding/json"
	"fmt"
	"net/http"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func (m *Manager) applyTelemetry(ctx context.Context, ap cweng.APStatus) {
	key := ap.ID + "/wireless-reporting"
	version := ap.ConnectedAt.Format(time.RFC3339Nano)
	m.mu.Lock()
	previous := m.status[key]
	done := m.applied[key] == version && (previous.State != "failed" || time.Since(previous.At) < 30*time.Second)
	m.mu.Unlock()
	if done {
		return
	}
	err := m.requestTelemetry(ctx, ap.ID)

	state := ApplyStatus{AP: ap.ID, Service: "wireless-reporting", State: "acknowledged", At: time.Now()}
	if err != nil {
		state.State = "failed"
		state.Error = err.Error()
	}
	m.mu.Lock()
	m.status[key] = state
	m.applied[key] = version
	m.mu.Unlock()
}

func (m *Manager) requestTelemetry(ctx context.Context, id string) error {
	// Byte-exact V6 baseline frame70, passed directly over authenticated CAPWAP.
	return m.reportAction(ctx, id, "on", "begin_report")
}

func (m *Manager) reportAction(ctx context.Context, id, enable, action string) error {
	ctx = m.itemContext(ctx, "telemetry:"+action)
	body := []byte(fmt.Sprintf(`{"method":"do","nms_report":{"nms_report_action":{"type":"all","enable":"%s","action":"%s"}}}`, enable, action))
	value := binary.BigEndian.AppendUint32(nil, 1)
	value = binary.BigEndian.AppendUint32(value, uint32(len(body)))
	value = append(value, 0)
	value = append(value, body...)
	c, cancel := context.WithTimeout(ctx, 5*time.Second)
	defer cancel()
	_, err := m.engine.Request(c, id, 7, []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0x83, []capwap.PrivElementValue{{Type: 0x83, Value: value}})}})
	return err
}

func (m *Manager) refreshAPHTTP(w http.ResponseWriter, r *http.Request) {
	if err := m.reportAction(r.Context(), r.PathValue("id"), "off", "stop_report"); err != nil {
		jsonReply(w, 502, map[string]string{"error": err.Error()})
		return
	}
	if err := m.requestTelemetry(r.Context(), r.PathValue("id")); err != nil {
		jsonReply(w, 502, map[string]string{"error": err.Error()})
		return
	}
	jsonReply(w, 202, map[string]string{"status": "requested"})
}

// The V6 AC ends configuration synchronization with a 16-byte opaque checksum.
// MD5 here is the vendor's configuration marker, not a security primitive.
func (m *Manager) checkpoint(ctx context.Context, id string, v any) error {
	b, err := json.Marshal(v)
	if err != nil {
		return err
	}
	sum := md5.Sum(b)
	c, cancel := context.WithTimeout(ctx, 4*time.Second)
	defer cancel()
	_, err = m.engine.Request(c, id, 7, []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x41, Value: sum[:]}})}})
	return err
}
