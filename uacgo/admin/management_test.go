package admin

import (
	"bytes"
	"context"
	"encoding/json"
	"net/http"
	"net/http/httptest"
	"os"
	"path/filepath"
	"strings"
	"testing"
	"time"
	"uacgo/cweng"
)

func callManagement(t *testing.T, m *Manager, method, path string, body any) *httptest.ResponseRecorder {
	t.Helper()
	var b []byte
	if body != nil {
		var err error
		b, err = json.Marshal(body)
		if err != nil {
			t.Fatal(err)
		}
	}
	r := httptest.NewRequest(method, "http://localhost/api/"+path, bytes.NewReader(b))
	r.Header.Set("Content-Type", "application/json")
	w := httptest.NewRecorder()
	m.Handler().ServeHTTP(w, r)
	return w
}
func TestAPManagementInheritancePreservesExplicitFalseAndRedactsSecrets(t *testing.T) {
	m, e := testController(t)
	_, ap := newDeferredAP(t, e)
	on, off := true, false
	defaultEcho, templateEcho, groupEcho := uint8(20), uint8(25), uint8(30)
	m.config.APDefaults = APOptions{LED: &on, EchoSeconds: &defaultEcho}
	m.config.Templates = []APTemplate{{ID: "model", Name: "Model", Model: ap.Model, Options: APOptions{EchoSeconds: &templateEcho, Account: &APAccount{Username: "administrator", Password: "private-ap-pass"}}}}
	m.config.Groups = []APGroup{{ID: "floor", Name: "Floor", Options: APOptions{EchoSeconds: &groupEcho}}}
	m.config.APProfiles = []APProfile{{AP: ap.ID, Group: "floor", Template: "model", Options: APOptions{LED: &off}}}
	o, err := effectiveAPOptions(m.config, ap)
	if err != nil || o.EchoSeconds == nil || *o.EchoSeconds != 30 || o.LED == nil || *o.LED {
		t.Fatal(o, err)
	}
	w := callManagement(t, m, "GET", "config", nil)
	if strings.Contains(w.Body.String(), "private-ap-pass") || !strings.Contains(w.Body.String(), "has_password") {
		t.Fatal("AP credential leaked or password flag missing")
	}
	if m.config.Templates[0].Options.Account.Password != "private-ap-pass" {
		t.Fatal("redaction mutated config")
	}
	w = callManagement(t, m, "DELETE", "groups/floor", nil)
	if w.Code != 400 {
		t.Fatal("deleted referenced group", w.Code)
	}
	m.config.Templates[0].Hardware = "other"
	if _, err = effectiveAPOptions(m.config, ap); err == nil {
		t.Fatal("incompatible template accepted")
	}
}

func TestAPManagementWireMatchesIndependentVendorFields(t *testing.T) {
	echo, miss, keep, idle := uint8(17), uint32(4), uint32(45), uint32(600)
	on := true
	els, err := managementElements(APOptions{EchoSeconds: &echo, EchoMisses: &miss, ClientKeepAlive: &keep, ClientIdle: &idle, OfflineSelfManage: &on}, cweng.APStatus{})
	if err != nil {
		t.Fatal(err)
	}
	if !bytes.Equal(els[0].Value, []byte{20, 17}) || !bytes.Equal(els[1].Value[10:], []byte{0, 0, 0, 45, 0, 0, 0, 4}) || !bytes.Equal(els[2].Value, []byte{0, 0, 2, 88}) {
		t.Fatal("timers/keepalive/idle layout differs", els)
	}
	want := []byte{0, 0, 0, 1, 0, 0, 1, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	if !bytes.Equal(els[3].Value[10:], want) {
		t.Fatalf("offline configuration %x", els[3].Value)
	}
}

func TestChangingAPGroupCleansOldServiceBinding(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), time.Second)
	defer cancel()
	cfg := Config{Groups: []APGroup{{ID: "a", Name: "A"}, {ID: "b", Name: "B"}}, APProfiles: []APProfile{{AP: ap.ID, Group: "a"}}, Services: []Service{{ID: "office", SSID: "Office", Security: "open", Enabled: true, Groups: []string{"a"}, Radios: []uint8{1}}}}
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	f.mu.Lock()
	ssid := f.active[[2]byte{1, 1}]
	f.mu.Unlock()
	if ssid != "Office" {
		t.Fatal("group member did not receive service")
	}
	cfg.APProfiles[0].Group = "b"
	cfg.Version++
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	f.mu.Lock()
	_, present := f.active[[2]byte{1, 1}]
	f.mu.Unlock()
	if present {
		t.Fatal("changing group retained unbound WLAN")
	}
	if m.admitStation(ap.ID, 1, 1) {
		t.Fatal("old group still admitted clients")
	}
}

func TestRestoreRetainsPendingDeletesAndRoundtripsPrivateAPAccount(t *testing.T) {
	m, e := testController(t)
	_, ap := newDeferredAP(t, e)
	s := Service{ID: "old", SSID: "Old", Security: "open", Enabled: true, Radios: []uint8{1}}
	m.config.Services = []Service{s}
	m.config.APDefaults.Account = &APAccount{Username: "admin", Password: "private-test"}
	if _, err := m.allocate(ap.ID, s.ID, 1, 1); err != nil {
		t.Fatal(err)
	}
	backup := callManagement(t, m, http.MethodGet, "backup", nil)
	if !strings.Contains(backup.Body.String(), "private-test") {
		t.Fatal("private backup cannot restore account")
	}
	var body struct {
		Format string `json:"format"`
		Schema int    `json:"schema"`
		Config Config `json:"config"`
	}
	if err := json.Unmarshal(backup.Body.Bytes(), &body); err != nil {
		t.Fatal(err)
	}
	body.Config.Services = nil
	w := callManagement(t, m, http.MethodPost, "restore", body)
	if w.Code != 202 {
		t.Fatal(w.Code, w.Body.String())
	}
	if len(m.config.Services) != 1 || !m.config.Services[0].Deleting || m.assigned(ap.ID, s.ID, 1) != 1 {
		t.Fatal("restore discarded deletion intent")
	}
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if restored.config.APDefaults.Account.Password != "private-test" {
		t.Fatal("AP password lost")
	}
}

func TestScheduledRebootIsDurableAndNotRepeatedAfterRestart(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), time.Second)
	defer cancel()
	id := ap.ID + "/scheduled/2026-11-26"
	job, err := m.apAction(ctx, ap, "reboot", id)
	if err != nil || job.State != "waiting_reconnect" {
		t.Fatal(job, err)
	}
	f.mu.Lock()
	count := len(f.packets)
	f.mu.Unlock()
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if _, err = restored.apAction(ctx, ap, "reboot", id); err != nil {
		t.Fatal(err)
	}
	f.mu.Lock()
	defer f.mu.Unlock()
	if len(f.packets) != count {
		t.Fatal("restart repeated scheduled reboot")
	}
	if _, err := os.Stat(restored.operationPath()); err != nil {
		t.Fatal(err)
	}
}

func TestAPSettingsAreSentThroughRealUDPAndRejectedChangesRetry(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	echo := uint8(19)
	off := false
	cfg := Config{APProfiles: []APProfile{{AP: ap.ID, Options: APOptions{EchoSeconds: &echo, OfflineSelfManage: &off}}}}
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), time.Second)
	defer cancel()
	f.mu.Lock()
	f.rejectPrivate = 0x3c
	f.rejectCount = 1
	f.mu.Unlock()
	if err := m.applyAPManagement(ctx, ap, cfg); err == nil {
		t.Fatal("AP rejection reported successful")
	}
	key := ap.ID + "/ap-settings"
	m.mu.Lock()
	st := m.status[key]
	st.At = st.At.Add(-31 * time.Second)
	m.status[key] = st
	m.mu.Unlock()
	if err := m.applyAPManagement(ctx, ap, cfg); err != nil {
		t.Fatal("failed AP settings not retried", err)
	}
	f.mu.Lock()
	defer f.mu.Unlock()
	if len(f.packets) < 3 {
		t.Fatal("no UDP settings commands")
	}
}

func TestOfflineAPReplacementMovesBindingsAndRetiresOldIdentity(t *testing.T) {
	m, e := testController(t)
	_, target := newDeferredAP(t, e)
	old := target
	old.ID = "02:01:02:03:04:05"
	// Original replacement compares model, allowing different HW revisions;
	// migrated settings still undergo the target's capability validation.
	old.HardwareVersion = "different-hardware-revision"
	old.Online = false
	old.State = "OFFLINE"
	m.known[old.ID] = old
	m.config.APProfiles = []APProfile{{AP: old.ID, Name: "Hall", Location: "First floor"}}
	m.config.Services = []Service{{ID: "office", SSID: "Office", Security: "open", Enabled: true, APs: []string{old.ID}, Radios: []uint8{1}}}
	if _, err := m.allocate(old.ID, "office", 1, 1); err != nil {
		t.Fatal(err)
	}
	w := callManagement(t, m, "POST", "aps/"+old.ID+"/replace", map[string]string{"target_ap_id": target.ID})
	if w.Code != 202 {
		t.Fatal(w.Code, w.Body.String())
	}
	if m.config.APProfiles[0].AP != target.ID || m.config.APProfiles[0].Name != "Hall" || m.config.Services[0].APs[0] != target.ID {
		t.Fatal("replacement lost configuration")
	}
	if serviceTargets(m.config.Services[0], old.ID, m.config) || !serviceTargets(m.config.Services[0], target.ID, m.config) {
		t.Fatal("retired AP remained a service target")
	}
	if m.assigned(target.ID, "office", 1) != 0 {
		t.Fatal("replacement copied another AP's physical WLAN IDs")
	}
	if m.assigned(old.ID, "office", 1) != 1 {
		t.Fatal("replacement discarded old AP cleanup reservation")
	}
}

func TestClientRenameExportAndDisconnectUseRealLocationAndWire(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	m.clients.StationEvent(cweng.ClientEvent{Kind: "associate", State: "connected", APID: ap.ID, MAC: mac, RadioID: 2, WLANID: 1})
	w := callManagement(t, m, "POST", "clients/02:03:04:05:06:07/label", ClientLabel{Name: "=test", Note: "Tablet"})
	if w.Code != 200 {
		t.Fatal(w.Code, w.Body.String())
	}
	w = callManagement(t, m, "GET", "clients/export", nil)
	if w.Code != 200 || !strings.Contains(w.Body.String(), "'=test") {
		t.Fatal("CSV export missing label / formula escaping")
	}
	w = callManagement(t, m, "POST", "clients/02:03:04:05:06:07/disconnect", map[string]any{})
	if w.Code != 202 {
		t.Fatal(w.Code, w.Body.String())
	}
	f.mu.Lock()
	defer f.mu.Unlock()
	last := f.packets[len(f.packets)-1]
	if last.Control.MsgType != 25 || len(last.Elements) != 1 || last.Elements[0].Type != 0x12 || !bytes.Equal(last.Elements[0].Value, []byte{2, 6, 2, 3, 4, 5, 6, 7}) {
		t.Fatal("client disconnect wire differs", last)
	}
	if m.clients.All()[0].State != "connected" {
		t.Fatal("ACK fabricated client disassociation before AP report")
	}
}

func TestManagementProjectionDoesNotExposeNativeCredentials(t *testing.T) {
	fields, err := managementProjection([]byte(`{"error_code":0,"capwap":{"fit_specific":{"echo_interval":19,"client_idle":300,"password":"hidden","account":{"username":"hidden","secret":"hidden"}}}}`))
	if err != nil {
		t.Fatal(err)
	}
	b, _ := json.Marshal(fields)
	if strings.Contains(string(b), "hidden") || len(fields) != 2 {
		t.Fatal("unsafe or incomplete projection", string(b))
	}
}

func TestMixedAPInheritanceFiltersOptionalHardwareButDirectOverrideIsStrict(t *testing.T) {
	yes := true
	cfg := Config{APDefaults: APOptions{USB: &yes, LED: &yes, Ports: []APPort{{ID: 2, Enabled: &yes}}}}
	ap := cweng.APStatus{ID: "a"}
	o, err := effectiveAPOptions(cfg, ap)
	if err != nil || o.USB != nil || len(o.Ports) != 0 || o.LED == nil {
		t.Fatal("heterogeneous defaults blocked ordinary AP", o, err)
	}
	if _, err := managementElements(o, ap); err != nil {
		t.Fatal(err)
	}
	cfg.APProfiles = []APProfile{{AP: "a", Options: APOptions{USB: &yes}}}
	o, err = effectiveAPOptions(cfg, ap)
	if err != nil {
		t.Fatal(err)
	}
	if _, err = managementElements(o, ap); err == nil {
		t.Fatal("direct unsupported override silently filtered")
	}
}
