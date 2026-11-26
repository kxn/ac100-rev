package admin

import (
	"encoding/json"
	"path/filepath"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestRRMConfigurationBoundary(t *testing.T) {
	m, _, _, _, _ := rrmPair(t)
	r := rrmTestRule()
	r.ID = "r"
	r.Name = "Rule"
	settleRRMTargets(m)
	m.mu.Lock()
	defer m.mu.Unlock()
	j, err := m.startRRM(r, "")
	if err != nil {
		t.Fatal(err)
	}
	next := m.config
	next.Radios = []RadioSetting{{AP: "a", Radio: 1}}
	if m.saveManagement(next) == nil {
		t.Fatal("RF write was accepted during RRM")
	}
	for _, o := range []APOptions{{RegionCode: func() *uint8 { v := uint8(1); return &v }()}, {RFMode: &APRFMode{Enabled: true, ID: 1}}} {
		next = m.config
		next.APDefaults = o
		if m.saveManagement(next) == nil {
			t.Fatal("AP RF mode/region bypassed RRM boundary")
		}
	}
	next = m.config
	next.ClientLabels = map[string]ClientLabel{"02:00:00:00:00:01": {Name: "tablet"}}
	if err = m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if wirelessConfigKey(m.config) != j.BaseSignature {
		t.Fatal("client label changed wireless identity")
	}
	next = m.config
	next.Radios = []RadioSetting{{AP: "a", Radio: 1}}
	if err = m.saveManagementFrom(next, managementRRM); err != nil {
		t.Fatal("RRM cannot save its own result", err)
	}
}

func TestAPJoinGroupAssignmentIsNotBlockedByWebRRMGuard(t *testing.T) {
	m, _, _, _, _ := rrmPair(t)
	r := rrmTestRule()
	r.ID, r.Name = "r", "Rule"
	settleRRMTargets(m)
	m.mu.Lock()
	j, err := m.startRRM(r, "")
	if err != nil {
		m.mu.Unlock()
		t.Fatal(err)
	}
	next := m.config
	next.Groups = []APGroup{ipGroup("floor", "192.0.2.1", "192.0.2.10")}
	// The user rule is saved before the Join event in this fixture.
	m.config.Groups = next.Groups
	m.mu.Unlock()
	ap := cweng.APStatus{ID: "new-ap", Address: "192.0.2.10:5246", ConnectedAt: time.Now(), Online: true}
	m.observeAPState(ap)
	if apGroup(m.config, ap.ID) != "floor" {
		t.Fatal("AP lifecycle was incorrectly treated as Web RF edit")
	}
	if m.rrmJobs[j.ID].BaseSignature != wirelessConfigKey(m.config) {
		t.Fatal("incoming Join invalidated frozen RRM participants")
	}
}

func TestFirmwareScheduledTriggerConflicts(t *testing.T) {
	plan := func(day uint8, minute int) *ServiceSchedule {
		return &ServiceSchedule{Enabled: true, Action: "on", Timezone: "UTC", Windows: []WeeklyWindow{{Days: day, Start: minute, End: minute + 1}}}
	}
	for _, tc := range []struct {
		a, b      *ServiceSchedule
		threshold int
		want      bool
	}{
		{plan(1, 60), plan(1, 64), 299, true},
		{plan(1, 60), plan(1, 65), 299, false},
		{plan(64, 1439), plan(1, 2), 299, true},
		{plan(64, 1439), plan(2, 2), 299, false},
		{plan(1, 60), plan(1, 69), 599, true},
		{plan(1, 60), plan(1, 70), 599, false},
	} {
		if got := triggerConflict(tc.a, tc.b, tc.threshold); got != tc.want {
			t.Fatal(tc, got)
		}
	}
}

func TestStartupAndWritersShareIntrinsicConfigurationValidation(t *testing.T) {
	m, _ := testController(t)
	invalid := Service{ID: "bad", SSID: "Bad", Security: "invented", Radios: []uint8{1}}
	next := m.config
	next.Services = []Service{invalid}
	m.mu.Lock()
	err := m.persistConfigLocked(next, managementUser)
	m.mu.Unlock()
	if err == nil {
		t.Fatal("direct writer accepted invalid wireless configuration")
	}
	dir := t.TempDir()
	if err := atomicJSON(filepath.Join(dir, "controller.json"), next); err != nil {
		t.Fatal(err)
	}
	e, err := cweng.NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	if _, err = New(e, cweng.NewClientTable(), dir); err == nil {
		t.Fatal("startup accepted a configuration rejected by the writer")
	}
}

func TestClientDisplayDoesNotInventDisconnectFromReportSilence(t *testing.T) {
	m, e := testController(t)
	_, ap := newDeferredAP(t, e)
	at := time.Now().Add(-10 * time.Minute)
	m.clients.StationEvent(cweng.ClientEvent{APID: ap.ID, MAC: [6]byte{2, 1, 2, 3, 4, 5}, RadioID: 1, WLANID: 1, Kind: "associate", Seen: at})
	w := callManagement(t, m, "GET", "clients", nil)
	var rows []struct {
		State string `json:"state"`
	}
	if err := json.Unmarshal(w.Body.Bytes(), &rows); err != nil {
		t.Fatal(err)
	}
	if w.Code != 200 || len(rows) != 1 || rows[0].State != "connected" {
		t.Fatal(w.Code, w.Body.String())
	}
}
