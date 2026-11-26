package admin

import (
	"fmt"
	"net/http"
	"sort"
	"strings"
	"time"
	"uacgo/cweng"
)

// V6 rdmngr_db_init_edca/get_edca_default_value copy eight six-byte rows
// from UAC @8ec530. TXOP is the big-endian uint16 at row offset4.
func defaultEDCAQueues() []EDCAQueue {
	return []EDCAQueue{{AIFS: 1, CWMin: 2, CWMax: 3, TXOP: 47}, {AIFS: 1, CWMin: 3, CWMax: 4, TXOP: 94}, {AIFS: 2, CWMin: 4, CWMax: 6}, {AIFS: 3, CWMin: 4, CWMax: 10}, {AIFS: 2, CWMin: 2, CWMax: 3, TXOP: 47}, {AIFS: 2, CWMin: 3, CWMax: 4, TXOP: 94}, {AIFS: 2, CWMin: 4, CWMax: 10}, {AIFS: 3, CWMin: 4, CWMax: 10}}
}
func validateEDCAQueues(rows []EDCAQueue) error {
	if len(rows) != 8 {
		return fmt.Errorf("EDCA 需要 AP 和客户端的八个队列")
	}
	for i, q := range rows {
		minimum := 1
		if i >= 4 {
			minimum = 2
		}
		if q.AIFS < minimum || q.AIFS > 15 || q.CWMin < 1 || q.CWMin > 10 || q.CWMax < 1 || q.CWMax > 10 || q.TXOP < 0 || q.TXOP > 255 {
			return fmt.Errorf("EDCA 队列参数超出原厂范围")
		}
	}
	return nil
}

type EDCARule struct {
	PolicyTarget
	ID          string     `json:"id"`
	Name        string     `json:"name"`
	Frequencies uint16     `json:"frequency_mask"`
	WMM         bool       `json:"wmm"`
	Custom      bool       `json:"custom"`
	Scene       uint8      `json:"scene"`
	Config      EDCAConfig `json:"configuration"`
}
type EDCABindingState struct {
	Rule       string          `json:"rule"`
	Signature  string          `json:"signature"`
	Applied    EDCARule        `json:"applied"`
	Connection time.Time       `json:"connection"`
	ManualWMM  bool            `json:"manual_wmm,omitempty"`
	ManualEDCA bool            `json:"manual_edca,omitempty"`
	Patch      *EDCARadioPatch `json:"patch,omitempty"`
}

// EDCA owns two fields, not an entire RF profile. Keeping this overlay apart
// from per-AP overrides prevents a rule from freezing inherited channel/power.
type EDCARadioPatch struct {
	WMM  *bool      `json:"wmm,omitempty"`
	EDCA EDCAConfig `json:"edca"`
}

func intentAdvanced(cfg Config, ap string, radio uint8) *RadioAdvanced {
	for _, r := range inheritedRadioSettings(cfg, ap) {
		if r.AP == ap && r.Radio == radio {
			return r.Advanced
		}
	}
	return nil
}
func markManualEDCA(cfg *Config, ap string, radio uint8, advanced *RadioAdvanced) {
	states := map[string]EDCABindingState{}
	for k, v := range cfg.EDCAState {
		states[k] = v
	}
	key := fmt.Sprintf("%s/%d", ap, radio)
	if state, ok := states[key]; ok {
		state.ManualWMM = true
		state.ManualEDCA = state.ManualEDCA || advanced.EDCA != nil
		states[key] = state
	}
	cfg.EDCAState = states
}

func applyEDCAState(r RadioSetting, cfg Config, ap cweng.APStatus) RadioSetting {
	state, ok := cfg.EDCAState[fmt.Sprintf("%s/%d", ap.ID, r.Radio)]
	if !ok || state.Patch == nil || !state.Connection.Equal(ap.ConnectedAt) || r.Advanced == nil {
		return r
	}
	a := *r.Advanced
	if !state.ManualWMM && state.Patch.WMM != nil {
		a.WMM = *state.Patch.WMM || radioNeedsWMM(a.Mode)
	}
	if !state.ManualEDCA {
		ec := state.Patch.EDCA
		ec.Queues = append([]EDCAQueue{}, ec.Queues...)
		a.EDCA = &ec
	}
	r.Advanced = &a
	return r
}

func validateEDCARules(rows []EDCARule, cfg Config) error {
	ids, names := map[string]bool{}, map[string]bool{}
	for i, r := range rows {
		if r.ID == "" || ids[r.ID] || r.Name == "" || !validLabel(r.Name, 127) || names[r.Name] || r.Frequencies == 0 || r.Scene > 3 || r.Config.Preset != nil || r.Config.Mode != nil && (*r.Config.Mode < 0 || *r.Config.Mode > 1) {
			return fmt.Errorf("EDCA 规则编号、名称、频段或模式无效")
		}
		ids[r.ID], names[r.Name] = true, true
		if err := validateEDCAQueues(r.Config.Queues); err != nil {
			return err
		}
		for _, id := range r.Groups {
			found := false
			for _, g := range cfg.Groups {
				found = found || g.ID == id
			}
			if !found {
				return fmt.Errorf("EDCA 规则引用不存在的分组")
			}
		}
		for _, other := range rows[:i] {
			// check_edca_rule_bind_ap_or_group_conflict @725b88: the
			// bindings occupy frequency slots even when EDCA is disabled.
			if r.Frequencies&other.Frequencies != 0 && policyTargetsOverlap(r.PolicyTarget, other.PolicyTarget, cfg) {
				return fmt.Errorf("EDCA 规则的 AP/分组与频段绑定重叠")
			}
		}
	}
	return nil
}

func edcaRuleFor(cfg Config, ap cweng.APStatus, radio uint8) *EDCARule {
	bits := frequencyRadioBits(ap)
	for i := range cfg.EDCARules {
		r := &cfg.EDCARules[i]
		if r.matches(ap.ID, cfg) && r.Frequencies&bits[radio] != 0 {
			return r
		}
	}
	return nil
}

func applyEDCARule(setting RadioSetting, rule EDCARule, ap cweng.APStatus, c cweng.RadioCapability) RadioSetting {
	a := defaultRadioAdvanced(c)
	if setting.Advanced != nil {
		a = *setting.Advanced
	}
	a.WMM = rule.WMM || radioNeedsWMM(a.Mode)
	e := rule.Config
	e.Queues = append([]EDCAQueue{}, rule.Config.Queues...)
	if ap.SubCapabilities[61]&2 == 0 {
		e.Mode = nil
	}
	if !rule.Custom {
		if ap.SubCapabilities[61]&1 == 0 {
			e.Queues = defaultEDCAQueues()
		} else {
			// Original @74108c leaves the existing queues when the model
			// does not contain the requested scene; it doesn't invent one.
			if a.EDCA != nil {
				e.Queues = append([]EDCAQueue{}, a.EDCA.Queues...)
			} else {
				e.Queues = defaultEDCAQueues()
			}
			scene := rule.Scene
			probe := e
			probe.Preset = &scene
			if resolved, err := resolveEDCA(probe, ap, c); err == nil {
				e.Queues = resolved.Queues
			}
		}
	}
	a.EDCA = &e
	setting.Advanced = &a
	return setting
}

// EDCA rules update the RF database on add/change, group changes and AP Join.
// Materialize those events once, rather than overwriting later per-radio
// edits on every reconciliation. Deletion/unbinding disables the old rule's
// outputs, as edca_rule_jcs_del/apmngr_db_entry_check_edca_rule_diff do.
func (m *Manager) compileEDCARules(next Config) (Config, bool) {
	return m.compileEDCARulesAgainst(next, m.config)
}
func (m *Manager) compileEDCARulesAgainst(next, prior Config) (Config, bool) {
	states := map[string]EDCABindingState{}
	for k, v := range prior.EDCAState {
		states[k] = v
	}
	next.EDCAState = states
	aps := []cweng.APStatus{}
	for _, ap := range m.known {
		aps = append(aps, ap)
	}
	sort.SliceStable(aps, func(i, j int) bool { return aps[i].EntryID < aps[j].EntryID })
	changed := false
	for _, ap := range aps {
		retired := false
		for _, id := range next.RetiredAPs {
			retired = retired || id == ap.ID
		}
		if retired {
			for k := range states {
				if strings.HasPrefix(k, ap.ID+"/") {
					delete(states, k)
					changed = true
				}
			}
			continue
		}
		if !ap.HasCapability(61) {
			continue
		}
		for _, c := range ap.Capabilities {
			if !completeRadioCapability(c) {
				continue
			}
			key := fmt.Sprintf("%s/%d", ap.ID, c.RadioID)
			state, had := states[key]
			if had && configurationKey(intentAdvanced(next, ap.ID, c.RadioID), time.Time{}) != configurationKey(intentAdvanced(prior, ap.ID, c.RadioID), time.Time{}) {
				state.ManualWMM = true
				if a := intentAdvanced(next, ap.ID, c.RadioID); a != nil {
					state.ManualEDCA = state.ManualEDCA || a.EDCA != nil
				}
				states[key] = state
			}
			rule := edcaRuleFor(next, ap, c.RadioID)
			signature := configurationKey(struct {
				Unbound bool
				Radio   uint8
			}{true, c.RadioID}, ap.ConnectedAt)
			if rule != nil {
				signature = configurationKey(struct {
					Rule    EDCARule
					Presets any
					Sub     uint32
					Cap     cweng.RadioCapability
				}{*rule, ap.EDCAPresets, ap.SubCapabilities[61], c}, ap.ConnectedAt)
			}
			if signature == state.Signature && state.Patch != nil {
				continue
			}
			setting, _ := linkageRadioState(next, ap, c.RadioID)
			value := state.Applied
			if rule != nil {
				value = *rule
				setting = applyEDCARule(setting, value, ap, c)
			} else if had && state.Rule != "" {
				value.Config.Enabled = false
				setting = applyEDCARule(setting, value, ap, c)
			} else {
				a := defaultRadioAdvanced(c)
				if setting.Advanced != nil {
					a = *setting.Advanced
				}
				ec := EDCAConfig{Queues: defaultEDCAQueues()}
				if a.EDCA != nil {
					ec = *a.EDCA
				}
				ec.Enabled = false
				a.EDCA = &ec
				setting.Advanced = &a
			}
			patch := &EDCARadioPatch{EDCA: *setting.Advanced.EDCA}
			if rule != nil || had && state.Rule != "" {
				v := setting.Advanced.WMM
				patch.WMM = &v
			}
			updated := EDCABindingState{Signature: signature, Connection: ap.ConnectedAt, Patch: patch}
			if rule != nil {
				updated.Rule, updated.Applied = rule.ID, value
			}
			states[key] = updated

			changed = true
		}
	}
	if len(states) == 0 {
		next.EDCAState = nil
	}
	return next, changed
}

func (m *Manager) ensureEDCARules() (bool, error) {
	m.mu.Lock()
	defer m.mu.Unlock()
	next, changed := m.compileEDCARules(m.config)
	if !changed {
		return false, nil
	}
	return true, m.saveAPEventConfig(next)
}

func (m *Manager) edcaRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/edca", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		mode := 0
		jsonReply(w, 200, map[string]any{"rules": m.config.EDCARules, "defaults": EDCARule{Frequencies: 0, WMM: true, Custom: true, Scene: 1, Config: EDCAConfig{Enabled: true, Mode: &mode, Queues: defaultEDCAQueues()}}})
	})
	mux.HandleFunc("POST /api/edca/rules", func(w http.ResponseWriter, r *http.Request) {
		var rows []EDCARule
		if err := decodeManagement(w, r, &rows); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.EDCARules = rows
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]any{"status": "saved", "at": time.Now()})
	})
}
