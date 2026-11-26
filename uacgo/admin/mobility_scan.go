package admin

import (
	"context"
	"encoding/json"
	"fmt"
	"net/http"
	"os"
	"path/filepath"
	"sort"
	"strconv"
	"strings"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

type MobilityScan struct {
	State          string               `json:"state"`
	Error          string               `json:"error,omitempty"`
	Started        time.Time            `json:"started"`
	Updated        time.Time            `json:"updated"`
	Signature      string               `json:"signature"`
	BaseVersion    uint64               `json:"base_version"`
	AppliedVersion uint64               `json:"applied_version,omitempty"`
	Targets        map[string]time.Time `json:"targets"`
	Requests       map[string]time.Time `json:"requests"`
	Changes        []RRMChange          `json:"changes"`
}

func (m *Manager) mobilityScanPath() string {
	return filepath.Join(filepath.Dir(m.path), "mobility-scan.json")
}
func (m *Manager) loadMobilityScan() error {
	b, err := os.ReadFile(m.mobilityScanPath())
	if os.IsNotExist(err) {
		return nil
	}
	if err != nil {
		return err
	}
	if err = json.Unmarshal(b, &m.mobilityScan); err != nil {
		return err
	}
	if m.mobilityScan.State == "collecting" || m.mobilityScan.State == "planning" {
		m.mobilityScan.State = "interrupted"
		m.mobilityScan.Error = "程序在测量期间重启"
	}
	return nil
}
func scanChannels(cap cweng.RadioCapability) []int {
	defaults := []int{1, 6, 11}
	if cap.Band == "5 GHz" {
		defaults = []int{36, 40, 44, 48, 149, 153, 157, 161}
	} else if cap.Band != "2.4 GHz" {
		return nil
	}
	var out []int
	for _, c := range defaults {
		for _, legal := range cap.Channels {
			if c == legal {
				out = append(out, c)
				break
			}
		}
	}
	return out
}
func mobilityScanRequest(ap cweng.APStatus, cfg Config) []byte {
	p := capwap.ChannelScanRequest{Dwell: 100}
	cfg = effectiveRadioConfig(cfg, ap)
	for _, c := range ap.Capabilities {
		if c.RadioID == 0 || c.FunctionType == 1 || radioDisabled(cfg, ap.ID, c.RadioID) {
			continue
		}
		channels := scanChannels(c)
		if len(channels) == 0 {
			continue
		}
		names := make([]string, len(channels))
		for i, n := range channels {
			names[i] = strconv.Itoa(n)
		}
		p.Radios = append(p.Radios, capwap.ScanRadio{Index: c.RadioID - 1, Channels: strings.Join(names, " ")})
	}
	if len(p.Radios) == 0 {
		return nil
	}
	return p.AssembleValue()
}
func (m *Manager) applyMobilityScan(ctx context.Context, ap cweng.APStatus, cfg Config) {
	m.mu.Lock()
	j := m.mobilityScan
	at, exists := j.Requests[ap.ID]
	connection, member := j.Targets[ap.ID]
	m.mu.Unlock()
	if j.State != "collecting" || !member || exists || connection != ap.ConnectedAt || !m.configurationSettled(ap, cfg) {
		return
	}
	value := mobilityScanRequest(ap, cfg)
	if value == nil {
		return
	}
	at = time.Now()
	c, cancel := context.WithTimeout(ctx, 4*time.Second)
	_, err := m.engine.Request(c, ap.ID, 7, []capwap.Element{privateSetting(0x9b, value)})
	cancel()
	m.mu.Lock()
	defer m.mu.Unlock()
	if m.mobilityScan.Signature != j.Signature || m.mobilityScan.Started != j.Started {
		return
	}
	if err != nil {
		m.mobilityScan.State = "failed"
		m.mobilityScan.Error = err.Error()
	} else {
		m.mobilityScan.Requests[ap.ID] = at
	}
	m.mobilityScan.Updated = time.Now()
	if err := atomicJSON(m.mobilityScanPath(), m.mobilityScan); err != nil {
		m.mobilityScan.State = "failed"
		m.mobilityScan.Error = err.Error()
	}
}

// High-performance roaming deliberately aligns radios on a shared measured
// channel. It is a different policy from interference-spreading global RRM.
func mobilityChannelPlan(aps []cweng.APStatus, cfg Config) ([]RRMChange, error) {
	type candidate struct{ bss, load int }
	scores := map[int]candidate{}
	useLoad := false
	for _, ap := range aps {
		if ap.ChannelScan == nil {
			continue
		}
		for _, r := range ap.ChannelScan.Channels {
			v := scores[int(r.Channel)]
			v.bss += int(r.BSS)
			v.load += int(r.Load)
			scores[int(r.Channel)] = v
			useLoad = useLoad || r.Rejected == 1
		}
	}
	var bands []string
	var choices [][]int
	for _, band := range []string{"2.4 GHz", "5 GHz", "5 GHz 低频段", "5 GHz 高频段"} {
		common := map[int]bool{}
		first := true
		for _, ap := range aps {
			effective := effectiveRadioConfig(cfg, ap)
			for _, cap := range ap.Capabilities {
				if cap.FunctionType == 1 || mobilityRadioGroup(cap) != band || radioDisabled(effective, ap.ID, cap.RadioID) {
					continue
				}
				valid := map[int]bool{}
				for _, ch := range scanChannels(cap) {
					valid[ch] = true
				}
				if first {
					common = valid
					first = false
				} else {
					for ch := range common {
						if !valid[ch] {
							delete(common, ch)
						}
					}
				}
			}
		}
		var candidates []int
		for ch := range common {
			if _, measured := scores[ch]; measured {
				candidates = append(candidates, ch)
			}
		}
		if first {
			continue
		}
		if len(candidates) == 0 {
			return nil, fmt.Errorf("%s 没有共同支持且有测量的信道", band)
		}
		sort.Ints(candidates)
		bands = append(bands, band)
		choices = append(choices, candidates)
	}
	// There are at most four channel groups (3 x 8 x 4 x 4 choices). Check
	// complete combinations so one band's independent optimum cannot make a
	// peer band's RRST settings impossible.
	var best []RRMChange
	bestBSS, bestLoad := int(^uint(0)>>1), int(^uint(0)>>1)
	selected := map[string]int{}
	var choose func(int, int, int)
	choose = func(depth, bss, load int) {
		if depth < len(bands) {
			for _, ch := range choices[depth] {
				selected[bands[depth]] = ch
				choose(depth+1, bss+scores[ch].bss, load+scores[ch].load)
			}
			return
		}
		if best != nil && (useLoad && load >= bestLoad || !useLoad && (bss > bestBSS || bss == bestBSS && load >= bestLoad)) {
			return
		}
		var changes []RRMChange
		for _, ap := range aps {
			effective := effectiveRadioConfig(cfg, ap)
			for _, cap := range ap.Capabilities {
				ch, selectedRadio := selected[mobilityRadioGroup(cap)]
				if !selectedRadio || cap.FunctionType == 1 || radioDisabled(effective, ap.ID, cap.RadioID) {
					continue
				}
				r := RadioSetting{AP: ap.ID, Radio: cap.RadioID}
				for _, old := range effective.Radios {
					if old.AP == ap.ID && old.Radio == cap.RadioID {
						r = old
						break
					}
				}
				v := ch
				r.Channel = &v
				changes = append(changes, RRMChange{AP: ap.ID, Radio: cap.RadioID, Channel: ch, Setting: r})
			}
		}
		next := cfg
		next.Radios = append([]RadioSetting{}, cfg.Radios...)
		for _, c := range changes {
			putLinkedRadio(&next, c.Setting)
		}
		for _, ap := range aps {
			if validateRadioLinkage(next, ap) != nil {
				return
			}
		}
		best, bestBSS, bestLoad = changes, bss, load
	}
	choose(0, 0, 0)
	if best == nil {
		return nil, fmt.Errorf("没有同时满足共同信道和 AP 射频关联约束的方案")
	}
	sort.Slice(best, func(i, j int) bool {
		if best[i].AP != best[j].AP {
			return best[i].AP < best[j].AP
		}
		return best[i].Radio < best[j].Radio
	})
	return best, nil
}
func (m *Manager) tickMobilityScan(now time.Time) {
	cfg := m.snapshot()
	mode := m.effectiveMobilityMode(cfg)
	m.mu.Lock()
	defer m.mu.Unlock()
	fail := func(reason string) {
		m.mobilityScan.State = "failed"
		m.mobilityScan.Error = reason
		m.mobilityScan.Updated = now
		_ = atomicJSON(m.mobilityScanPath(), m.mobilityScan)
	}
	if cfg.Mobility == nil || mode != 1 {
		if m.mobilityScan.State == "collecting" || m.mobilityScan.State == "applying" {
			fail("已退出高性能模式")
		}
		return
	}
	targets := map[string]time.Time{}
	var aps []cweng.APStatus
	for _, ap := range m.known {
		if ap.Online && ap.HasCapability(72) && ap.HasCapability(25) && mobilityScanRequest(ap, effectiveRadioConfig(cfg, ap)) != nil {
			targets[ap.ID] = ap.ConnectedAt
			aps = append(aps, ap)
		}
	}
	if len(targets) == 0 {
		return
	}
	signature := configurationKey(struct {
		Mobility *MobilityConfig
		Targets  map[string]time.Time
	}{cfg.Mobility, targets}, time.Time{})
	if m.mobilityScan.Signature != signature {
		// Both optimizers change RF configuration; do not launch overlapping work.
		for _, j := range m.rrmJobs {
			if j.State == "collecting" || j.State == "applying" || j.State == "planning" {
				return
			}
		}
		for _, ap := range aps {
			if m.upgradeBusyLocked(ap.ID) || m.settled[ap.ID] != configurationKey(effectiveRadioConfig(cfg, ap), ap.ConnectedAt) {
				return
			}
		}
		m.mobilityScan = MobilityScan{State: "collecting", Started: now, Updated: now, Signature: signature, BaseVersion: cfg.Version, Targets: targets, Requests: map[string]time.Time{}, Changes: []RRMChange{}}
		if err := atomicJSON(m.mobilityScanPath(), m.mobilityScan); err != nil {
			fail(err.Error())
		}
		return
	}
	j := m.mobilityScan
	if j.State == "applying" {
		if cfg.Version != j.AppliedVersion {
			fail("配置在应用期间已变更")
			return
		}
		done := true
		for _, ap := range aps {
			done = done && m.settled[ap.ID] == configurationKey(effectiveRadioConfig(cfg, ap), ap.ConnectedAt)
		}
		if done {
			m.mobilityScan.State = "completed"
			m.mobilityScan.Updated = now
			_ = atomicJSON(m.mobilityScanPath(), m.mobilityScan)
		} else if now.Sub(j.Updated) > 2*time.Minute {
			fail("信道计划未能完成确认")
		}
		return
	}
	if j.State != "collecting" {
		return
	}
	if cfg.Version != j.BaseVersion {
		fail("配置在测量期间已变更")
		return
	}
	ready := len(j.Requests) == len(targets)
	for _, ap := range aps {
		at, ok := j.Requests[ap.ID]
		ready = ready && ok && ap.ChannelScan != nil && !ap.ChannelScan.ReceivedAt.Before(at)
	}
	if !ready {
		if now.Sub(j.Started) > 20*time.Second {
			fail("AP 未在期限内完成信道测量，保留原配置")
		}
		return
	}
	changes, err := mobilityChannelPlan(aps, cfg)
	if err != nil {
		fail(err.Error())
		return
	}
	next := m.config
	next.Radios = append([]RadioSetting{}, next.Radios...)
	for _, change := range changes {
		found := false
		for i, r := range next.Radios {
			if r.AP == change.AP && r.Radio == change.Radio {
				next.Radios[i] = change.Setting
				found = true
				break
			}
		}
		if !found {
			next.Radios = append(next.Radios, change.Setting)
		}
	}
	m.mobilityScan.Changes = changes
	m.mobilityScan.State = "planning"
	m.mobilityScan.AppliedVersion = next.Version + 1
	if err = atomicJSON(m.mobilityScanPath(), m.mobilityScan); err != nil {
		fail(err.Error())
		return
	}
	if err = m.saveManagement(next); err != nil {
		fail(err.Error())
		return
	}
	m.mobilityScan.State = "applying"
	m.mobilityScan.AppliedVersion = m.config.Version
	m.mobilityScan.Updated = now
	if err = atomicJSON(m.mobilityScanPath(), m.mobilityScan); err != nil {
		fail(err.Error())
	}
}
func (m *Manager) mobilityScanRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/mobility/scan", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		jsonReply(w, 200, m.mobilityScan)
	})
	mux.HandleFunc("POST /api/mobility/scan", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		if m.config.Mobility == nil || m.config.Mobility.NetworkMode == 2 {
			jsonReply(w, 409, map[string]string{"error": "请先启用自动或高性能漫游模式"})
			return
		}
		if m.mobilityScan.State == "collecting" || m.mobilityScan.State == "applying" {
			jsonReply(w, 409, map[string]string{"error": "信道测量正在运行"})
			return
		}
		m.mobilityScan.Signature = ""
		jsonReply(w, 202, map[string]string{"status": "queued"})
	})
}

func mobilityRadioGroup(c cweng.RadioCapability) string {
	if c.Band != "5 GHz" {
		return c.Band
	}
	low, high := false, false
	for _, ch := range c.Channels {
		low = low || ch < 100
		high = high || ch >= 100
	}
	if low && !high {
		return "5 GHz 低频段"
	}
	if high && !low {
		return "5 GHz 高频段"
	}
	return "5 GHz"
}

// V6 manual channel changes update the high-performance shared channel and
// its other compatible radios. Preserve each target's power/advanced settings.
func (m *Manager) propagateMobilityChannelLocked(cfg *Config, source cweng.APStatus, cap cweng.RadioCapability, channel int) error {
	if cfg.Mobility == nil || m.effectiveMobilityModeLocked(*cfg) != 1 || !source.HasCapability(72) || channel == 0 {
		return nil
	}
	for _, ap := range m.known {
		if !ap.HasCapability(72) || !serviceTargets(Service{}, ap.ID, *cfg) {
			continue
		}
		for _, c := range ap.Capabilities {
			if c.Band != cap.Band || !hasInt(c.Channels, channel) || ap.ID == source.ID && c.RadioID == cap.RadioID {
				continue
			}
			setting := RadioSetting{AP: ap.ID, Radio: c.RadioID}
			for _, r := range effectiveRadioConfig(*cfg, ap).Radios {
				if r.AP == ap.ID && r.Radio == c.RadioID {
					setting = r
					break
				}
			}
			ch := channel
			setting.Channel = &ch
			if err := validateAdvanced(setting, ap, c); err != nil {
				return fmt.Errorf("高性能模式下 AP %s 射频 %d 不能使用该信道: %w", ap.ID, c.RadioID, err)
			}
			found := false
			for i, r := range cfg.Radios {
				if r.AP == ap.ID && r.Radio == c.RadioID {
					cfg.Radios[i] = setting
					found = true
					break
				}
			}
			if !found {
				cfg.Radios = append(cfg.Radios, setting)
			}
		}
	}
	return nil
}
