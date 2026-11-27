package admin

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"math"
	"net"
	"net/http"
	"os"
	"path/filepath"
	"slices"
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

// History dominates persistent state at capacity. Encode one immutable sample
// at a time so a periodic save does not allocate another copy of the full log.
func historyArray[T any](w *bufio.Writer, rows []T) error {
	if rows == nil {
		_, err := w.WriteString("null")
		return err
	}
	if _, err := w.WriteString("["); err != nil {
		return err
	}
	enc := json.NewEncoder(w)
	for i := range rows {
		if i > 0 {
			if err := w.WriteByte(','); err != nil {
				return err
			}
		}
		if err := enc.Encode(&rows[i]); err != nil {
			return err
		}
	}
	return w.WriteByte(']')
}
func writeHistory(w io.Writer, h WirelessHistory) error {
	out := bufio.NewWriterSize(w, 32<<10)
	if _, err := out.WriteString(`{"ap_counts":`); err != nil {
		return err
	}
	if err := historyArray(out, h.APCounts); err != nil {
		return err
	}
	if _, err := out.WriteString(`,"radios":`); err != nil {
		return err
	}
	if err := historyArray(out, h.Radios); err != nil {
		return err
	}
	if _, err := out.WriteString(`,"events":`); err != nil {
		return err
	}
	if err := historyArray(out, h.Events); err != nil {
		return err
	}
	if len(h.Clients) > 0 {
		if _, err := out.WriteString(`,"clients":`); err != nil {
			return err
		}
		if err := historyArray(out, h.Clients); err != nil {
			return err
		}
	}
	if _, err := out.WriteString("}\n"); err != nil {
		return err
	}
	return out.Flush()
}
func (m *Manager) saveHistoryLocked() error {
	return atomicWrite(m.historyPath(), func(w io.Writer) error { return writeHistory(w, m.history) })
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

// Samples can arrive out of timestamp order. Keep their insertion order and
// compute the next actual expiry rather than rescanning every controller tick.
func retainHistory[T any](rows []T, now time.Time, retention time.Duration, limit int, at func(T) time.Time) ([]T, time.Time) {
	kept := rows[:0]
	for _, row := range rows {
		if now.Sub(at(row)) < retention {
			kept = append(kept, row)
		}
	}
	if len(kept) > limit {
		copy(kept, kept[len(kept)-limit:])
		kept = kept[:limit]
	}
	// Expired strings/maps must not remain reachable through slice capacity.
	clear(rows[len(kept):])
	var expiry time.Time
	for _, row := range kept {
		next := at(row).Add(retention)
		if expiry.IsZero() || next.Before(expiry) {
			expiry = next
		}
	}
	if cap(kept) > 2*max(len(kept), 1024) {
		kept = slices.Clone(kept)
	}
	return kept, expiry
}
func (m *Manager) noteHistoryExpiry(at time.Time, retention time.Duration) {
	expiry := at.Add(retention)
	if m.historyExpiry.IsZero() || expiry.Before(m.historyExpiry) {
		m.historyExpiry = expiry
	}
}
func (m *Manager) pruneHistory(now time.Time) { // mu held, except construction.
	m.historyExpiry = time.Time{}
	pruned := false
	track := func(old, current int, expiry time.Time) {
		pruned = pruned || old != current
		if !expiry.IsZero() && (m.historyExpiry.IsZero() || expiry.Before(m.historyExpiry)) {
			m.historyExpiry = expiry
		}
	}
	old := len(m.history.Radios)
	rows, expiry := retainHistory(m.history.Radios, now, 24*time.Hour, 20000, func(r RadioSample) time.Time { return r.At })
	m.history.Radios = rows
	track(old, len(rows), expiry)
	old = len(m.history.Events)
	events, expiry := retainHistory(m.history.Events, now, 7*24*time.Hour, 10000, func(e StationTransition) time.Time { return e.At })
	m.history.Events = events
	track(old, len(events), expiry)
	old = len(m.history.Clients)
	clients, expiry := retainHistory(m.history.Clients, now, time.Hour, 100000, func(c ClientSignalSample) time.Time { return c.At })
	m.history.Clients = clients
	track(old, len(clients), expiry)
	old = len(m.history.APCounts)
	counts, expiry := retainHistory(m.history.APCounts, now, 24*time.Hour, 10000, func(c APCountSample) time.Time { return c.At })
	m.history.APCounts = counts
	track(old, len(counts), expiry)
	for key, at := range m.historyClientSamples {
		if now.Sub(at) >= time.Hour {
			delete(m.historyClientSamples, key)
		} else {
			m.noteHistoryExpiry(at, time.Hour)
		}
	}
	for key, at := range m.historySamples {
		if now.Sub(at) >= 24*time.Hour {
			delete(m.historySamples, key)
		} else {
			m.noteHistoryExpiry(at, 24*time.Hour)
		}
	}
	m.historyDirty = m.historyDirty || pruned
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
	initializeExpiry := m.historyExpiry.IsZero()
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
		m.noteHistoryExpiry(counts.At, 24*time.Hour)
		changed = true
	}
	for _, e := range events {
		m.history.Events = append(m.history.Events, StationTransition{ClientTransition: e, MACString: net.HardwareAddr(e.MAC[:]).String()})
		m.noteHistoryExpiry(e.At, 7*24*time.Hour)
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
				if c.APID == ap.ID && c.RadioID == sample.Radio && c.State == "connected" && !c.Seen.Before(ap.ConnectedAt) {
					sample.Clients++
				}
			}
			for k, v := range radio.Data {
				if n, ok := latestMetric(v); ok {
					sample.Metrics[k] = n
				}
			}
			m.history.Radios = append(m.history.Radios, sample)
			m.noteHistoryExpiry(sample.At, 24*time.Hour)
			m.historySamples[key] = observed
			changed = true
		}
	}
	if changed {
		m.historyDirty = true
	}
	if initializeExpiry || !now.Before(m.historyExpiry) || len(m.history.Radios) > 20000 || len(m.history.Events) > 10000 || len(m.history.Clients) > 100000 || len(m.history.APCounts) > 10000 {
		m.pruneHistory(now)
	}
	if m.historyDirty && now.Sub(m.historySaved) > 30*time.Second {
		if m.saveHistoryLocked() == nil {
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
		ap, mac := q.Get("ap"), normalizeMAC(q.Get("mac"))
		out := WirelessHistory{APCounts: []APCountSample{}, Radios: []RadioSample{}, Events: []StationTransition{}}
		m.mu.Lock()
		for i := len(m.history.APCounts) - 1; i >= 0 && len(out.APCounts) < limit; i-- {
			row := m.history.APCounts[i]
			if !row.At.Before(since) {
				out.APCounts = append(out.APCounts, row)
			}
		}
		for i := len(m.history.Radios) - 1; i >= 0 && len(out.Radios) < limit; i-- {
			row := m.history.Radios[i]
			if row.At.Before(since) || ap != "" && row.AP != ap || radio != "" && strconv.Itoa(int(row.Radio)) != radio {
				continue
			}
			out.Radios = append(out.Radios, row)
		}
		for i := len(m.history.Events) - 1; i >= 0 && len(out.Events) < limit; i-- {
			e := m.history.Events[i]
			if e.At.Before(since) || ap != "" && e.AP != ap || mac != "" && mac != e.MACString {
				continue
			}
			out.Events = append(out.Events, e)
		}
		m.mu.Unlock()
		slices.Reverse(out.APCounts)
		slices.Reverse(out.Radios)
		slices.Reverse(out.Events)
		jsonReply(w, 200, out)
	})
}
