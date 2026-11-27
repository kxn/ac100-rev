package admin

import (
	"context"
	"encoding/binary"
	"fmt"
	"net/http"
	"sort"
	"time"
	"uacgo/capwap"
	"uacgo/controllercfg"
	"uacgo/cweng"
	"uacgo/mobility"
)

type PolicyTarget struct {
	APs    []string `json:"aps"`
	Groups []string `json:"groups"`
}

func (p PolicyTarget) matches(ap string, cfg Config) bool {
	return serviceTargets(Service{APs: p.APs, Groups: p.Groups}, ap, cfg)
}

type BalanceRule struct {
	PolicyTarget
	ID          string `json:"id"`
	Name        string `json:"name"`
	Enabled     bool   `json:"enabled"`
	Clients     int    `json:"client_threshold"`
	Difference  int    `json:"difference"`
	MaxFailures int    `json:"max_failures"`
	RSSI        int    `json:"rssi_threshold"`
}
type RoamBand struct {
	Type              int  `json:"threshold_type"`
	RSSI              int  `json:"rssi_trigger"`
	RSSIKick          bool `json:"rssi_kick"`
	RSSIKickThreshold int  `json:"rssi_kick_threshold"`
	Rate              int  `json:"rate_trigger"`
	RateKick          bool `json:"rate_kick"`
	RateKickThreshold int  `json:"rate_kick_threshold"`
}
type RoamSettings struct {
	K                   bool     `json:"11k"`
	V                   bool     `json:"11v"`
	R                   bool     `json:"11r"`
	Band2G              RoamBand `json:"2g"`
	Band5G              RoamBand `json:"5g"`
	CheckInterval       int      `json:"check_interval"`
	Difference          int      `json:"difference"`
	BlacklistTime       int      `json:"blacklist_time"`
	HighPerformanceRSSI int      `json:"high_performance_rssi"`
	Statistics          bool     `json:"statistics"`
	StatisticsInterval  int      `json:"statistics_interval"`
}
type RoamRule struct {
	PolicyTarget
	ID       string       `json:"id"`
	Name     string       `json:"name"`
	Enabled  bool         `json:"enabled"`
	Settings RoamSettings `json:"settings"`
}
type MobilityConfig struct {
	Silence     *RoamSilence  `json:"silence,omitempty"`
	Balance     []BalanceRule `json:"balance"`
	Roaming     []RoamRule    `json:"roaming"`
	Default     RoamSettings  `json:"default_roaming"`
	NetworkMode int           `json:"network_mode"`
}

// Original mode2 reads default_roam_cnt/default_silence_time from UCI.
// Flash values aren't in the upgrade image; these are standalone defaults.
type RoamSilence struct {
	Count   uint8  `json:"count"`
	Seconds uint16 `json:"seconds"`
}

func effectiveRoamSilence(p *MobilityConfig) RoamSilence {
	if p != nil && p.Silence != nil {
		return *p.Silence
	}
	return RoamSilence{Count: 3, Seconds: 30}
}

func defaultRoamSettings() RoamSettings {
	// _wsta_roam_sql_load_db inserts rule0 using the SQL defaults created
	// by _wsta_roam_sql_create_cfg_table @4d8ca8; cfgsync36 has the same schema.
	b2 := RoamBand{Type: 1, RSSI: -75, RSSIKickThreshold: -80, Rate: 20, RateKickThreshold: 10}
	b5 := RoamBand{Type: 1, RSSI: -80, RSSIKickThreshold: -85, Rate: 20, RateKickThreshold: 10}
	return RoamSettings{K: true, V: true, Band2G: b2, Band5G: b5, CheckInterval: 1, Difference: 8, BlacklistTime: 2, HighPerformanceRSSI: -65, StatisticsInterval: 30}
}

func defaultMobility() MobilityConfig {
	return MobilityConfig{NetworkMode: 2, Default: defaultRoamSettings(), Balance: []BalanceRule{}, Roaming: []RoamRule{}}
}
func (p MobilityConfig) validate(cfg Config) error {
	if len(p.Balance) > controllercfg.Effective(cfg.Resources).MaxPolicyRules || len(p.Roaming) > controllercfg.Effective(cfg.Resources).MaxPolicyRules || p.NetworkMode != 2 {
		return fmt.Errorf("均衡/漫游规则超过程序容量，或网络模式不是原固件兼容模式（2）")
	}
	groups := map[string]bool{}
	for _, g := range cfg.Groups {
		groups[g.ID] = true
	}
	checkTarget := func(t PolicyTarget) error {
		for _, g := range t.Groups {
			if !groups[g] {
				return fmt.Errorf("策略引用不存在的 AP 分组")
			}
		}
		return nil
	}
	ids := map[string]bool{}
	names := map[string]bool{}
	for _, r := range p.Balance {
		if r.ID == "" || ids[r.ID] || !validLabel(r.Name, 50) || r.Name == "" || names[r.Name] || r.Clients < 1 || r.Clients > 100 || r.Difference < 1 || r.Difference > 15 || r.MaxFailures < 1 || r.MaxFailures > 100 || r.RSSI < -95 || r.RSSI > 0 {
			return fmt.Errorf("均衡规则参数无效或重复")
		}
		ids[r.ID] = true
		names[r.Name] = true
		if err := checkTarget(r.PolicyTarget); err != nil {
			return err
		}
	}
	// Vendor balance DB rejects double binding, including disabled rules.
	for i, a := range p.Balance {
		for _, b := range p.Balance[i+1:] {
			if policyTargetsOverlap(a.PolicyTarget, b.PolicyTarget, cfg) {
				return fmt.Errorf("均衡规则不能重复绑定同一 AP 或分组")
			}
		}
	}
	if err := p.Default.validate(); err != nil {
		return err
	}
	ids = map[string]bool{}
	names = map[string]bool{}
	for _, r := range p.Roaming {
		if r.ID == "" || ids[r.ID] || r.Name == "" || !validLabel(r.Name, 64) || names[r.Name] {
			return fmt.Errorf("漫游规则编号/名称无效或重复")
		}
		ids[r.ID] = true
		names[r.Name] = true
		if err := r.Settings.validate(); err != nil {
			return err
		}
		if err := checkTarget(r.PolicyTarget); err != nil {
			return err
		}
	}
	for i, a := range p.Roaming {
		for _, b := range p.Roaming[i+1:] {
			if policyTargetsOverlap(a.PolicyTarget, b.PolicyTarget, cfg) {
				return fmt.Errorf("漫游规则不能重复绑定同一 AP 或分组")
			}
		}
	}
	return nil
}
func (r RoamSettings) validate() error {
	if r.CheckInterval < 1 || r.CheckInterval > 10 || r.Difference < 5 || r.Difference > 15 || r.BlacklistTime < 0 || r.BlacklistTime > 10 || r.HighPerformanceRSSI < -70 || r.HighPerformanceRSSI > -50 || r.StatisticsInterval < 1 || r.StatisticsInterval > 65535 {
		return fmt.Errorf("漫游检查间隔、差值、黑名单或统计参数无效")
	}
	for _, b := range []RoamBand{r.Band2G, r.Band5G} {
		if b.Type < 1 || b.Type > 3 || b.RSSI < -95 || b.RSSI > -60 || b.RSSIKickThreshold < -95 || b.RSSIKickThreshold > -60 || b.Rate < 1 || b.Rate > 40 || b.RateKickThreshold < 1 || b.RateKickThreshold > 20 || b.RSSIKick && b.Type&1 == 0 || b.RateKick && b.Type&2 == 0 {
			return fmt.Errorf("漫游频段门限无效或与类型不符")
		}
	}
	return nil
}
func (r RoamSettings) wire(mode int) []byte {
	b := make([]byte, 36)
	b[0], b[1], b[2] = boolean(r.K), boolean(r.V), boolean(r.R)
	for i, v := range []RoamBand{r.Band2G, r.Band5G} {
		if mode == 1 {
			v.Type = 1
			v.RSSI = r.HighPerformanceRSSI
		}
		o := 3 + i*7
		b[o], b[o+1], b[o+2], b[o+3], b[o+4], b[o+5], b[o+6] = byte(v.Type), byte(v.RSSI), boolean(v.RSSIKick), byte(v.RSSIKickThreshold), byte(v.Rate), boolean(v.RateKick), byte(v.RateKickThreshold)
	}
	b[17], b[18], b[19] = byte(r.CheckInterval), byte(r.Difference), byte(r.BlacklistTime)
	b[20] = mobility.FirmwareStrategy
	return b
}
func balanceFor(p *MobilityConfig, ap string, cfg Config) *BalanceRule {
	if p != nil {
		for _, r := range p.Balance {
			if r.PolicyTarget.matches(ap, cfg) {
				return &r
			}
		}
	}
	return nil
}
func roamingFor(p *MobilityConfig, ap string, cfg Config) RoamSettings {
	if p == nil {
		return defaultRoamSettings()
	}
	for _, r := range p.Roaming {
		if r.Enabled && r.PolicyTarget.matches(ap, cfg) {
			return r.Settings
		}
	}
	return p.Default
}
func (m *Manager) applyPolicy(ctx context.Context, ap cweng.APStatus, kind string, value any, elements []capwap.Element) {
	key := ap.ID + "/" + kind
	version := configurationKey(value, ap.ConnectedAt)
	m.mu.Lock()
	st := m.status[key]
	done := m.applied[key] == version && (st.State != "failed" || time.Since(st.At) < 30*time.Second)
	m.mu.Unlock()
	if done {
		return
	}
	err := m.touchPolicy(ap.ID, kind)
	if err == nil {
		m.dirtyAP(ap.ID)
		for _, el := range elements {
			if _, err = m.engine.Request(ctx, ap.ID, 7, []capwap.Element{el}); err != nil {
				break
			}
		}
	}
	st = ApplyStatus{AP: ap.ID, Service: kind, State: "acknowledged", At: time.Now()}
	if err != nil {
		st.State = "failed"
		st.Error = err.Error()
	}
	m.mu.Lock()
	m.applied[key] = version
	m.status[key] = st
	m.mu.Unlock()
}
func (m *Manager) applyMobility(ctx context.Context, ap cweng.APStatus, cfg Config) {
	r := balanceFor(cfg.Mobility, ap.ID, cfg)
	enabled := r != nil && r.Enabled
	mask := binary.BigEndian.AppendUint32(nil, 1)
	mask = binary.BigEndian.AppendUint32(mask, uint32(boolean(enabled)))
	els := []capwap.Element{privateSetting(0x26, mask)}
	if enabled {
		els = append(els, privateSetting(0x3e, binary.BigEndian.AppendUint32(nil, uint32(int32(r.RSSI)))))
	}
	m.applyPolicy(ctx, ap, "balance", r, els)
	if ap.HasCapability(25) {
		mode := m.effectiveMobilityMode(cfg)
		s := roamingFor(cfg.Mobility, ap.ID, cfg)
		m.applyPolicy(ctx, ap, "roaming", struct {
			Settings RoamSettings
			Mode     int
		}{s, mode}, []capwap.Element{privateSetting(0x57, s.wire(mode))})
	}
	// 4e1620 filters capability72 independently of the capability25 filter
	// used by 4e9534/4e8e80 for private57. Neither capability implies the other.
	if ap.HasCapability(72) {
		mode := m.effectiveMobilityMode(cfg)
		silence := effectiveRoamSilence(cfg.Mobility)
		m.applyPolicy(ctx, ap, "roaming-mode", struct {
			Mode    int
			Silence RoamSilence
		}{mode, silence}, []capwap.Element{privateSetting(0x9d, capwap.PrivSilenceParams{A: silence.Count, B: silence.Seconds}.AssembleValue())})
	}
}

// V6 Web wireless_network_mode_set returns EFORBID; cfgsync.d/36_roam_cfg_sync.sh
// explicitly migrates both configured/actual modes to2. The automatic/high
// performance helpers in UAC are retained binary code, not exposed V6 policy.
func (m *Manager) effectiveMobilityMode(_ Config) int       { return 2 }
func (m *Manager) effectiveMobilityModeLocked(_ Config) int { return 2 }
func (m *Manager) mobilityRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/mobility/status", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		unsupported := []string{}
		for _, ap := range m.known {
			if ap.Online && !ap.HasCapability(72) {
				unsupported = append(unsupported, ap.ID)
			}
		}
		sort.Strings(unsupported)
		jsonReply(w, 200, map[string]any{"configured_mode": 2, "actual_mode": 2, "mode_writable": false, "unsupported_aps": unsupported})
	})

	mux.HandleFunc("GET /api/mobility/events", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		jsonReply(w, 200, append([]RoamDecision{}, m.roamHistory...))
	})
	mux.HandleFunc("GET /api/mobility", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		p := m.config.Mobility
		if p == nil {
			v := defaultMobility()
			p = &v
		}
		jsonReply(w, 200, p)
	})
	mux.HandleFunc("POST /api/mobility", func(w http.ResponseWriter, r *http.Request) {
		var p MobilityConfig
		if err := decodeManagement(w, r, &p); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.Mobility = &p
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]string{"status": "saved"})
	})
}

// Checks both explicit selectors and the current AP→group assignments. Future
// membership changes run the same validation, so they cannot create overlaps.
func policyTargetsOverlap(a, b PolicyTarget, cfg Config) bool {
	if len(a.APs)+len(a.Groups) == 0 || len(b.APs)+len(b.Groups) == 0 {
		return true
	}
	for _, x := range a.Groups {
		for _, y := range b.Groups {
			if x == y {
				return true
			}
		}
	}
	aps := map[string]bool{}
	for _, x := range a.APs {
		aps[x] = true
	}
	for _, x := range b.APs {
		aps[x] = true
	}
	for _, x := range cfg.APProfiles {
		aps[x.AP] = true
	}
	for ap := range aps {
		if a.matches(ap, cfg) && b.matches(ap, cfg) {
			return true
		}
	}
	return false
}
