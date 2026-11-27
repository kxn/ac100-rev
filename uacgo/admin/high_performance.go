package admin

import (
	"context"
	"fmt"
	"net/http"
	"sort"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/mobility"
)

// The V4 mode state machine is explicitly versioned. The default
// compatibility controller continues to use the supplied V6 policy; this
// tag prevents silently reviving values from early Go prototypes.
const v4ModeSource = "tl-ac100-v4-1.4.3"
const v6ModeSource = "tl-ac100-v6-1.0.3"

type highPerformanceState struct {
	Channels    mobility.CommonChannels               `json:"channels"`
	State       string                                `json:"state,omitempty"`
	Error       string                                `json:"error,omitempty"`
	Deadline    time.Time                             `json:"deadline,omitempty"`
	Expected    map[string]time.Time                  `json:"-"`
	Reports     map[string][]capwap.ChannelScanSample `json:"-"`
	Connections map[string]time.Time                  `json:"-"`
	PendingScan bool                                  `json:"-"`
	Timer       *time.Timer                           `json:"-"`
	ModeTargets map[string]time.Time                  `json:"-"`
}

func (h *highPerformanceState) resetCollection() {
	if h.Timer != nil {
		h.Timer.Stop()
		h.Timer = nil
	}
	h.Expected, h.Reports, h.Connections = nil, nil, nil
}

func usesV4Modes(cfg Config) bool {
	return cfg.Mobility != nil && cfg.Mobility.ModeSource == v4ModeSource
}
func configuredMobilityMode(cfg Config) int {
	if usesV4Modes(cfg) {
		return cfg.Mobility.NetworkMode
	}
	return 2
}
func actualMobilityMode(cfg Config) int {
	if usesV4Modes(cfg) {
		if cfg.Mobility.NetworkMode == 1 {
			return 1
		}
		if cfg.Mobility.NetworkMode == 0 && cfg.Mobility.CurrentMode != 2 {
			return 1
		}
	}
	return 2
}

func highPerformanceTimeout(p *MobilityConfig) time.Duration {
	seconds := 5 // get_acs_timeout@483000 returns5 when its UCI byte is0.
	if p != nil && p.ACSTimeout != 0 {
		seconds = int(p.ACSTimeout)
	}
	return time.Duration(seconds+1) * time.Second
}

// Plan shared channel changes at the single configuration write boundary.
// This includes per-radio, inherited template/group, bulk and restore inputs.
// Changes to a disabled mode never propagate shared channels.
func (m *Manager) prepareHighPerformanceLocked(next Config, source managementWrite) (Config, mobility.CommonChannels) {
	channels := m.highPerformance.Channels
	if source == managementRestore {
		return next, mobility.CommonChannels{}
	}
	if source == managementAPEvent || source == managementRRM {
		return next, channels
	}
	if actualMobilityMode(m.config) != 1 && actualMobilityMode(next) == 1 {
		supported := false
		for _, ap := range m.known {
			supported = supported || ap.Online && ap.HasCapability(72)
		}
		if !supported {
			channels = mobility.CommonChannels{}
		}
	}
	ids := make([]string, 0, len(m.known))
	for id := range m.known {
		ids = append(ids, id)
	}
	sort.Strings(ids)
	for _, id := range ids {
		ap := m.known[id]
		old := effectiveRadioConfig(m.config, ap)
		for _, r := range effectiveRadioConfig(next, ap).Radios {
			if r.AP != id || r.Channel == nil {
				continue
			}
			for _, prior := range old.Radios {
				if prior.AP == id && prior.Radio == r.Radio && prior.Channel != nil && *prior.Channel != *r.Channel {
					band := mobility.V4ChannelBand(*r.Channel)
					if channels.Update(band, *r.Channel, true) && actualMobilityMode(next) == 1 {
						next = m.withHighPerformanceChannelsLocked(next, channels, band)
					}
				}
			}
		}
	}
	return next, channels
}

// Record only channel and bandwidth overrides. Copying an entire effective
// Advanced struct here would freeze unrelated inherited AP features.
func (m *Manager) withHighPerformanceChannelsLocked(cfg Config, channels mobility.CommonChannels, band int) Config {
	return m.withHighPerformanceSelectionLocked(cfg, mobility.V4ChannelSelection{Channels: channels}, band, false)
}

func (m *Manager) withHighPerformanceSelectionLocked(cfg Config, selection mobility.V4ChannelSelection, band int, acs bool) Config {
	channels := selection.Channels
	cfg.Radios = append([]RadioSetting{}, cfg.Radios...)
	ids := make([]string, 0, len(m.known))
	for id := range m.known {
		ids = append(ids, id)
	}
	sort.Strings(ids)
	for _, id := range ids {
		ap := m.known[id]
		count := ap.Radios
		if count == 0 {
			count = len(ap.Capabilities)
		}
		for _, c := range ap.Capabilities {
			if c.Band != "2.4 GHz" && c.Band != "5 GHz" {
				continue
			}
			channel := mobility.V4CommonChannel(channels, int(c.RadioID), count, c.Band == "5 GHz", band)
			if acs {
				channel = mobility.V4ACSChannel(selection, int(c.RadioID), count, c.Band == "5 GHz")
			}
			if channel <= 0 {
				continue
			}
			index := -1
			for i, r := range cfg.Radios {
				if r.AP == id && r.Radio == c.RadioID {
					index = i
					break
				}
			}
			if index < 0 {
				cfg.Radios = append(cfg.Radios, RadioSetting{AP: id, Radio: c.RadioID})
				index = len(cfg.Radios) - 1
			}
			r := cloneRadio(cfg.Radios[index])
			bandwidth := 2 // _uac_rdmngr_rd_chnl_bw_set(...,channel,2) @6301e8.
			r.Channel, r.Bandwidth = &channel, &bandwidth
			cfg.Radios[index] = r
		}
	}
	return cfg
}

func (m *Manager) commitHighPerformanceChannelsLocked(channels mobility.CommonChannels, band int) {
	if actualMobilityMode(m.config) != 1 {
		m.highPerformance.Channels = channels
		return
	}
	next := m.withHighPerformanceChannelsLocked(m.config, channels, band)
	if wirelessConfigKey(next) != wirelessConfigKey(m.config) {
		next.Version = m.config.Version + 1
		if err := m.persistConfigLocked(next, managementAPEvent); err != nil {
			m.highPerformance.State, m.highPerformance.Error = "failed", err.Error()
			return
		}
	}
	m.highPerformance.Channels = channels
}

// Report seeding uses the old configured-vs-reported channel guard. A later
// AP cannot replace an already seeded slot. No load, RSSI or station-count
// heuristic switches a fixed mode1 controller to mode2.
func (m *Manager) seedHighPerformanceLocked(ap cweng.APStatus) {
	if !ap.Online {
		return
	}
	for _, row := range ap.RadioStatus {
		m.seedHighPerformanceRadioLocked(ap, row)
	}
}

func (m *Manager) seedHighPerformanceRadioLocked(ap cweng.APStatus, row cweng.RadioStatus) {
	if row.Channel == 0 {
		return
	}
	band := mobility.V4ChannelBand(int(row.Channel))
	if band == 0 || m.highPerformance.Channels[band-1] != 0 && m.highPerformance.Channels[band-1] != -1 {
		return
	}
	for _, r := range effectiveRadioConfig(m.config, ap).Radios {
		if r.AP != ap.ID || r.Radio != row.Radio || r.Channel != nil && *r.Channel != 0 && *r.Channel != int(row.Channel) {
			continue
		}
		band := mobility.V4ChannelBand(int(row.Channel))
		channels := m.highPerformance.Channels
		if channels.Update(band, int(row.Channel), false) {
			m.commitHighPerformanceChannelsLocked(channels, band)
		}
		return
	}
}

func (m *Manager) observeHighPerformanceRadio(ap string, connection time.Time, row cweng.RadioStatus) {
	m.mu.Lock()
	defer m.mu.Unlock()
	known, ok := m.known[ap]
	if !ok || !known.Online || known.ConnectedAt != connection {
		return
	}
	m.seedHighPerformanceRadioLocked(known, row)
}

// _wsta_intelligent_roam_do_acs counts eligible capability72 APs first;
// transport failures don't shrink that report-collection barrier.
func (m *Manager) startHighPerformanceACSLocked(now time.Time) error {
	if actualMobilityMode(m.config) != 1 {
		return fmt.Errorf("共同信道扫描仅适用于V4高性能模式")
	}
	if m.highPerformance.State == "collecting" {
		return nil
	}
	h := &m.highPerformance
	ready, err := m.highPerformanceModeReadyLocked()
	if err != nil {
		return err
	}
	if !ready {
		if h.State != "waiting" {
			m.event("acs.waiting", "reason", "mode_parameters_not_settled")
		}
		h.PendingScan, h.State, h.Error = true, "waiting", ""
		return nil
	}
	h.PendingScan = false
	// All callers, including manual RRM, share the same ordering barrier.
	// Management requests are asynchronous in Go; their scan must not
	// overtake the mode parameters that the original synchronous entry sent.
	jobsChanged := false
	for id, job := range m.rrmJobs {
		if job.State == "collecting" && job.CommonChannelPhase && job.CollectUntil.IsZero() {
			job.CollectUntil = now.Add(highPerformanceTimeout(m.config.Mobility) + 5*time.Second)
			m.rrmJobs[id] = job
			jobsChanged = true
		}
	}
	if jobsChanged {
		_ = m.saveRRMJobs()
		m.wakeRRMLocked()
	}
	h.Error = ""
	h.Expected = map[string]time.Time{}
	h.Reports = map[string][]capwap.ChannelScanSample{}
	h.Connections = map[string]time.Time{}
	for id, ap := range m.known {
		if ap.Online && ap.HasCapability(72) {
			h.Expected[id] = ap.ConnectedAt
		}
	}
	if len(h.Expected) == 0 {
		h.State = "idle"
		return nil
	}
	h.State, h.Error, h.Deadline = "collecting", "", now.Add(highPerformanceTimeout(m.config.Mobility))
	m.event("acs.collection_started", "policy", mobilityPolicyVersion(m.config), "expected", h.Expected, "deadline", h.Deadline)
	deadline := h.Deadline
	if h.Timer != nil {
		h.Timer.Stop()
	}
	h.Timer = time.AfterFunc(highPerformanceTimeout(m.config.Mobility), func() {
		m.mu.Lock()
		defer m.mu.Unlock()
		if m.highPerformance.State == "collecting" && m.highPerformance.Deadline == deadline {
			m.finishHighPerformanceACSLocked()
		}
	})
	for id := range h.Expected {
		ap := m.known[id]
		request := capwap.ChannelScanRequest{Dwell: 100}
		for _, c := range ap.Capabilities {
			channels := ""
			if c.Band == "2.4 GHz" {
				channels = "1 6 11"
			}
			if c.Band == "5 GHz" {
				channels = "36-48 149-161"
			}
			if channels != "" {
				request.Radios = append(request.Radios, capwap.ScanRadio{Index: c.RadioID - 1, Channels: channels})
			}
		}
		ticket, err := m.engine.QueueAP(m.commandContext(context.Background(), ap, m.config.Version, "common_channel_scan"), ap, 7, []capwap.Element{privateSetting(0x9b, request.AssembleValue())})
		if err != nil {
			h.Error = err.Error()
			continue
		}
		go func() {
			_, err := ticket.Wait(context.Background())
			if err != nil {
				m.mu.Lock()
				if m.highPerformance.State == "collecting" && m.highPerformance.Deadline == deadline {
					m.highPerformance.Error = err.Error()
				}
				m.mu.Unlock()
			}
		}()
	}
	return nil
}

func (m *Manager) observeHighPerformanceScan(ap string, connection time.Time, rows []capwap.ChannelScanSample) {
	m.mu.Lock()
	defer m.mu.Unlock()
	h := &m.highPerformance
	if h.State != "collecting" {
		return
	}
	known, ok := m.known[ap]
	if !ok || !known.Online || known.ConnectedAt != connection {
		return
	}
	m.event("acs.scan_report", "ap_id", ap, "session", connection, "samples", rows)
	h.Reports[ap] = append([]capwap.ChannelScanSample{}, rows...)
	h.Connections[ap] = connection
	if len(h.Reports) >= len(h.Expected) {
		m.finishHighPerformanceACSLocked()
	}
}

func (m *Manager) finishHighPerformanceACSLocked() {
	h := &m.highPerformance
	reports := [][]capwap.ChannelScanSample{}
	active := false
	for _, ap := range m.known {
		active = active || ap.Online
	}
	for id, rows := range h.Reports {
		if ap, ok := m.known[id]; ok && ap.Online && ap.ConnectedAt == h.Connections[id] && len(rows) > 0 {
			reports = append(reports, rows)
		}
	}
	m.event("acs.collection_finished", "expected_count", len(h.Expected), "received_count", len(h.Reports), "usable_reports", len(reports), "timed_out", !time.Now().Before(h.Deadline), "active", active)
	h.State = "completed"
	h.resetCollection()
	if !active {
		return
	}
	// The original worker keeps its expected-AP count and applies the fixed
	// defaults on timeout even if no sample survived. It doesn't invent RF
	// scores from other statistics streams.
	selection := mobility.V4SelectCommonChannels(reports)
	m.event("acs.selection", "channels", selection.Channels, "policy", mobilityPolicyVersion(m.config), "config_version", m.config.Version)
	next := m.withHighPerformanceSelectionLocked(m.config, selection, 0, true)
	if wirelessConfigKey(next) != wirelessConfigKey(m.config) {
		next.Version = m.config.Version + 1
		if err := m.persistConfigLocked(next, managementAPEvent); err != nil {
			h.State, h.Error = "failed", err.Error()
			return
		}
	}
	h.Channels = selection.Channels
}

func (m *Manager) tickHighPerformance(now time.Time) {
	m.mu.Lock()
	defer m.mu.Unlock()
	h := &m.highPerformance
	if actualMobilityMode(m.config) != 1 {
		h.resetCollection()
		h.State = ""
		h.PendingScan = false
		return
	}
	if h.PendingScan {
		ready, err := m.highPerformanceModeReadyLocked()
		if err != nil {
			h.PendingScan = false
			h.State, h.Error = "failed", err.Error()
		} else if ready {
			h.PendingScan = false
			_ = m.startHighPerformanceACSLocked(now)
		}
	}
	if h.State == "collecting" && !now.Before(h.Deadline) {
		m.finishHighPerformanceACSLocked()
	}
}

// Mode transition sends the silence block and roam parameters before the
// ACS entry. Reconciliation owns retries; a failed mode write aborts this
// transition's ACS instead of measuring with partially applied parameters.
func (m *Manager) highPerformanceModeReadyLocked() (bool, error) {
	ready := true
	for _, ap := range m.known {
		if !ap.Online {
			continue
		}
		for _, kind := range []string{"roaming-mode", "roaming"} {
			if kind == "roaming-mode" && !ap.HasCapability(72) || kind == "roaming" && !ap.HasCapability(25) {
				continue
			}
			var value any
			if kind == "roaming-mode" {
				value = struct {
					Mode    int
					Silence RoamSilence
				}{1, effectiveRoamSilence(m.config.Mobility)}
			} else {
				value = roamingParametersFor(ap.ID, m.config)
			}
			key := ap.ID + "/" + kind
			if m.applied[key] != configurationKey(value, ap.ConnectedAt) {
				ready = false
				continue
			}
			if s := m.status[key]; s.State == "failed" {
				return false, fmt.Errorf("AP %s 模式参数下发失败：%s", ap.ID, s.Error)
			}
		}
	}
	return ready, nil
}

func (m *Manager) highPerformanceRoutes(mux *http.ServeMux) {
	mux.HandleFunc("POST /api/mobility/scan", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		if err := m.startHighPerformanceACSLocked(time.Now()); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, m.highPerformance)
	})
}
