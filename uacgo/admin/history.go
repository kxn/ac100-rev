package admin

import (
	"encoding/json"
	"fmt"
	"math"
	"net"
	"net/http"
	"os"
	"path/filepath"
	"strconv"
	"time"
	"uacgo/cweng"
)

type RadioSample struct {
	At        time.Time          `json:"at"`
	AP        string             `json:"ap_id"`
	Radio     uint8              `json:"radio_id"`
	Channel   int                `json:"channel"`
	Power     int                `json:"power_dbm"`
	Bandwidth string             `json:"bandwidth"`
	Clients   int                `json:"clients"`
	Metrics   map[string]float64 `json:"metrics,omitempty"`
}
type StationTransition struct {
	cweng.ClientTransition
	MACString string `json:"client_mac"`
}
type WirelessHistory struct {
	Clients  []ClientSignalSample `json:"clients,omitempty"`
	APCounts []APCountSample      `json:"ap_counts"`
	Radios   []RadioSample        `json:"radios"`
	Events   []StationTransition  `json:"events"`
}
type APCountSample struct {
	At      time.Time `json:"at"`
	Online  int       `json:"online"`
	Offline int       `json:"offline"`
	Total   int       `json:"total"`
}

func (m *Manager) historyPath() string {
	return filepath.Join(filepath.Dir(m.path), "wireless-history.json")
}
func (m *Manager) loadHistory() error {
	b, err := os.ReadFile(m.historyPath())
	if os.IsNotExist(err) {
		return nil
	}
	if err != nil {
		return err
	}
	if len(b) > 64<<20 {
		return fmt.Errorf("无线历史记录超过容量")
	}
	if err = json.Unmarshal(b, &m.history); err != nil {
		return err
	}
	m.pruneHistory(time.Now())
	m.historySamples = map[string]time.Time{}
	for _, r := range m.history.Radios {
		key := fmt.Sprintf("%s/%d", r.AP, r.Radio)
		if r.At.After(m.historySamples[key]) {
			m.historySamples[key] = r.At
		}
	}
	m.historyClientSamples = map[string]time.Time{}
	for _, r := range m.history.Clients {
		key := clientSignalKey(r)
		if r.At.After(m.historyClientSamples[key]) {
			m.historyClientSamples[key] = r.At
		}
	}
	return nil
}
func (m *Manager) pruneHistory(now time.Time) { // mu held, except construction.
	radios := m.history.Radios[:0]
	for _, r := range m.history.Radios {
		if now.Sub(r.At) < 24*time.Hour {
			radios = append(radios, r)
		}
	}
	m.history.Radios = radios
	events := m.history.Events[:0]
	for _, e := range m.history.Events {
		if now.Sub(e.At) < 7*24*time.Hour {
			events = append(events, e)
		}
	}
	m.history.Events = events
	clients := m.history.Clients[:0]
	for _, c := range m.history.Clients {
		if now.Sub(c.At) < time.Hour {
			clients = append(clients, c)
		}
	}
	m.history.Clients = clients
	counts := m.history.APCounts[:0]
	for _, c := range m.history.APCounts {
		if now.Sub(c.At) < 24*time.Hour {
			counts = append(counts, c)
		}
	}
	m.history.APCounts = counts
	if len(counts) > 10000 {
		m.history.APCounts = append([]APCountSample{}, counts[len(counts)-10000:]...)
	}
	if len(m.history.Clients) > 100000 {
		m.history.Clients = append([]ClientSignalSample{}, m.history.Clients[len(m.history.Clients)-100000:]...)
	}
	for key, at := range m.historyClientSamples {
		if now.Sub(at) >= time.Hour {
			delete(m.historyClientSamples, key)
		}
	}
	if len(m.history.Radios) > 20000 {
		m.history.Radios = append([]RadioSample{}, m.history.Radios[len(m.history.Radios)-20000:]...)
	}
	if len(m.history.Events) > 10000 {
		m.history.Events = append([]StationTransition{}, m.history.Events[len(m.history.Events)-10000:]...)
	}
}
func latestMetric(raw json.RawMessage) (float64, bool) {
	var v any
	if json.Unmarshal(raw, &v) != nil {
		return 0, false
	}
	for {
		xs, ok := v.([]any)
		if !ok {
			break
		}
		if len(xs) == 0 {
			return 0, false
		}
		v = xs[len(xs)-1]
	}
	switch x := v.(type) {
	case float64:
		return x, true
	case string:
		n, err := strconv.ParseFloat(x, 64)
		return n, err == nil && !math.IsNaN(n) && !math.IsInf(n, 0)
	}
	return 0, false
}
func (m *Manager) captureHistory(aps []cweng.APStatus, now time.Time) {
	var clients []cweng.ClientEvent
	var events []cweng.ClientTransition
	if m.clients != nil {
		clients = m.clients.All()
		events = m.clients.Transitions(m.clientHistoryCursor)
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	changed := false
	changed = m.captureClientSignalsLocked(clients, aps, now)
	retired := map[string]bool{}
	for _, id := range m.config.RetiredAPs {
		retired[id] = true
	}
	counts := APCountSample{At: now}
	for _, ap := range aps {
		if retired[ap.ID] {
			continue
		}
		counts.Total++
		if ap.Online {
			counts.Online++
		} else {
			counts.Offline++
		}
	}
	var last APCountSample
	if n := len(m.history.APCounts); n > 0 {
		last = m.history.APCounts[n-1]
	}
	if now.Sub(last.At) >= time.Minute || counts.Online != last.Online || counts.Offline != last.Offline || counts.Total != last.Total {
		m.history.APCounts = append(m.history.APCounts, counts)
		changed = true
	}
	for _, e := range events {
		m.history.Events = append(m.history.Events, StationTransition{ClientTransition: e, MACString: net.HardwareAddr(e.MAC[:]).String()})
		m.clientHistoryCursor = e.Sequence
		changed = true
	}
	if m.historySamples == nil {
		m.historySamples = map[string]time.Time{}
	}
	for _, ap := range aps {
		if !ap.Online || ap.Telemetry == nil || ap.Telemetry.ReceivedAt.IsZero() || now.Sub(ap.Telemetry.ReceivedAt) > 5*time.Minute {
			continue
		}

		for _, radio := range ap.Telemetry.Radios {
			observed := radio.StatisticsAt
			if observed.IsZero() {
				observed = radio.ReceivedAt
			}
			if observed.IsZero() || now.Sub(observed) > 5*time.Minute {
				continue
			}
			key := fmt.Sprintf("%s/%d", ap.ID, radio.RadioID)
			if last := m.historySamples[key]; !observed.After(last) || observed.Sub(last) < time.Minute {
				continue
			}
			sample := RadioSample{At: observed, AP: ap.ID, Radio: uint8(radio.RadioID), Bandwidth: radio.Bandwidth, Metrics: map[string]float64{}}
			if radio.Channel != nil {
				sample.Channel = *radio.Channel
			}
			for _, r := range ap.RadioStatus {
				if r.Radio == sample.Radio {
					sample.Channel = int(r.Channel)
					sample.Power = int(r.Power)
				}
			}
			for _, c := range clients {
				if c.APID == ap.ID && c.RadioID == sample.Radio && c.State == "connected" && now.Sub(c.Seen) < 6*time.Minute {
					sample.Clients++
				}
			}
			for k, v := range radio.Data {
				if n, ok := latestMetric(v); ok {
					sample.Metrics[k] = n
				}
			}
			m.history.Radios = append(m.history.Radios, sample)
			m.historySamples[key] = observed
			changed = true
		}
	}
	if changed {
		m.historyDirty = true
	}
	m.pruneHistory(now)
	if m.historyDirty && now.Sub(m.historySaved) > 30*time.Second {
		if atomicJSON(m.historyPath(), m.history) == nil {
			m.historySaved = now
			m.historyDirty = false
		}
	}
}
func (m *Manager) historyRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/clients/{mac}/history", m.clientSignalHistoryHTTP)
	mux.HandleFunc("GET /api/history", func(w http.ResponseWriter, r *http.Request) {
		q := r.URL.Query()
		limit := 1440
		if q.Get("limit") != "" {
			n, err := strconv.Atoi(q.Get("limit"))
			if err != nil || n < 1 || n > 10000 {
				jsonReply(w, 400, map[string]string{"error": "limit 为 1–10000"})
				return
			}
			limit = n
		}
		var since time.Time
		if q.Get("since") != "" {
			var err error
			since, err = time.Parse(time.RFC3339, q.Get("since"))
			if err != nil {
				jsonReply(w, 400, map[string]string{"error": "since 必须为 RFC3339 时间"})
				return
			}
		}
		radio := q.Get("radio")
		if radio != "" {
			n, err := strconv.Atoi(radio)
			if err != nil || n < 1 || n > 31 {
				jsonReply(w, 400, map[string]string{"error": "射频编号无效"})
				return
			}
		}
		out := WirelessHistory{Radios: []RadioSample{}, Events: []StationTransition{}}
		m.mu.Lock()
		defer m.mu.Unlock()
		out.APCounts = []APCountSample{}
		for _, row := range m.history.APCounts {
			if !row.At.Before(since) {
				out.APCounts = append(out.APCounts, row)
			}
		}
		for _, row := range m.history.Radios {
			if row.At.Before(since) || q.Get("ap") != "" && row.AP != q.Get("ap") || radio != "" && strconv.Itoa(int(row.Radio)) != radio {
				continue
			}
			out.Radios = append(out.Radios, row)
		}
		for _, e := range m.history.Events {
			if e.At.Before(since) || q.Get("ap") != "" && e.AP != q.Get("ap") || q.Get("mac") != "" && normalizeMAC(q.Get("mac")) != e.MACString {
				continue
			}
			out.Events = append(out.Events, e)
		}
		if len(out.Radios) > limit {
			out.Radios = out.Radios[len(out.Radios)-limit:]
		}
		if len(out.Events) > limit {
			out.Events = out.Events[len(out.Events)-limit:]
		}
		if len(out.APCounts) > limit {
			out.APCounts = out.APCounts[len(out.APCounts)-limit:]
		}
		jsonReply(w, 200, out)
	})
}
