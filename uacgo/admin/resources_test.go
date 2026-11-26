package admin

import (
	"encoding/json"
	"fmt"
	"net/http"
	"path/filepath"
	"testing"
	"uacgo/controllercfg"
	"uacgo/cweng"
)

func TestControllerCapacityAPIPersistsAndGuardsAllWriters(t *testing.T) {
	m, _ := testController(t)
	w := callManagement(t, m, http.MethodPost, "controller/resources", map[string]int{"max_ap_sessions": 2048, "max_services": 1})
	if w.Code != 202 || m.engine.MaxAPSessions() != 2048 {
		t.Fatal(w.Code, w.Body.String())
	}
	s := Service{SSID: "First", Security: "open", Radios: []uint8{1}, Enabled: true}
	first, err := m.saveService(s)
	if err != nil {
		t.Fatal(err)
	}
	s.SSID = "Second"
	if _, err = m.saveService(s); err == nil || len(m.config.Services) != 1 {
		t.Fatal("service editor bypassed Go budget", err)
	}
	backup := Config{Resources: m.config.Resources, Services: []Service{first, {ID: "other", SSID: "Second", Security: "open", Radios: []uint8{1}}}}
	w = callManagement(t, m, "POST", "restore", map[string]any{"format": "go-ac-configuration", "schema": 1, "config": backup})
	if w.Code != 400 || len(m.config.Services) != 1 {
		t.Fatal("restore bypassed capacity", w.Code, w.Body.String())
	}
	e, err := cweng.NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	t.Cleanup(func() { e.Close() })
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if e.MaxAPSessions() != 2048 || restored.config.Resources.MaxServices != 1 {
		t.Fatal("resource settings were not restored")
	}
	w = callManagement(t, m, "POST", "controller/resources", map[string]int{"max_services": 0})
	if w.Code != 400 || m.config.Resources.MaxServices != 1 {
		t.Fatal("invalid capacity modified config", w.Code)
	}
}

func TestGoBudgetsDoNotChangeFirmwarePolicyOrAPConfiguration(t *testing.T) {
	m, _, _, _, _ := rrmPair(t)
	settleRRMTargets(m)
	r := rrmTestRule()
	r.ID, r.Name = "r", "R"
	m.mu.Lock()
	job, err := m.startRRM(r, "")
	m.mu.Unlock()
	if err != nil {
		t.Fatal(err)
	}
	before := wirelessConfigKey(m.config)
	var ap cweng.APStatus
	for _, v := range m.known {
		if v.Online {
			ap = v
			break
		}
	}
	if ap.ID == "" {
		t.Fatal("missing test AP")
	}
	apBefore, _ := json.Marshal(effectiveRadioConfig(m.config, ap))
	w := callManagement(t, m, "POST", "controller/resources", map[string]int{"max_ap_sessions": 2048})
	if w.Code != 202 || wirelessConfigKey(m.config) != before || m.rrmJobs[job.ID].BaseSignature != before {
		t.Fatal("capacity edit changed/cancelled RRM", w.Code, w.Body.String())
	}
	apAfter, _ := json.Marshal(effectiveRadioConfig(m.config, ap))
	if string(apBefore) != string(apAfter) {
		t.Fatal("capacity edit changed AP desired configuration")
	}
	if got := defaultRoamSettings(); got.CheckInterval != 1 || got.BlacklistTime != 2 || got.StatisticsInterval != 30 || got.Band5G.RSSI != -80 {
		t.Fatal("Go capacities changed firmware defaults", got)
	}
}

func TestRuleBudgetsAreIndependentOfACModelCapacity(t *testing.T) {
	limits := controllercfg.Defaults()
	limits.MaxPolicyRules = 128
	cfg := Config{Resources: &limits}
	p := defaultMobility()
	var rrm []RRMRule
	for i := 0; i < 64; i++ {
		id := fmt.Sprint(i)
		p.Balance = append(p.Balance, BalanceRule{ID: id, Name: id, Clients: 20, Difference: 4, MaxFailures: 10, RSSI: -70, PolicyTarget: PolicyTarget{APs: []string{"ap-" + id}}})
		p.Roaming = append(p.Roaming, RoamRule{ID: id, Name: id, Settings: defaultRoamSettings(), PolicyTarget: PolicyTarget{APs: []string{"ap-" + id}}})
		r := rrmTestRule()
		r.ID, r.Name = id, id
		rrm = append(rrm, r)
	}
	if err := p.validate(cfg); err != nil {
		t.Fatal("copied old 32-rule model cap", err)
	}
	if err := validateRRMRules(rrm, cfg); err != nil {
		t.Fatal("copied old 50-rule model cap", err)
	}
	limits.MaxPolicyRules = 63
	if p.validate(cfg) == nil || validateRRMRules(rrm, cfg) == nil {
		t.Fatal("configured rule budget ignored")
	}
}

func TestStandaloneAPDefaultsRemainEditable(t *testing.T) {
	m, _ := testController(t)
	o := m.config.APDefaults
	if *o.EchoSeconds != 20 || *o.EchoMisses != 5 || *o.ClientKeepAlive != 30 || *o.ClientIdle != 3600 || !*o.OfflineSelfManage {
		t.Fatal(o)
	}
	off := false
	next := m.config
	next.APDefaults.OfflineSelfManage = &off
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if got, _ := effectiveAPOptions(m.config, cweng.APStatus{ID: "new-ap"}); *got.OfflineSelfManage {
		t.Fatal("Go default overwrote explicit disabled setting")
	}
}
