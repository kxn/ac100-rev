package admin

import (
	"context"
	"encoding/json"
	"fmt"
	"os"
	"path/filepath"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func TestMeshMemberIntentSurvivesHistoryCompactionBackupAndRestart(t *testing.T) {
	m, e := testController(t)
	parent, child := "02:00:00:00:00:01", "02:00:00:00:00:02"
	now := time.Now()
	m.config.Mesh = meshFixture()
	m.known[parent] = cweng.APStatus{ID: parent, ConnectedAt: now}
	m.known[child] = cweng.APStatus{ID: child, MeshParent: parent}
	m.meshJobs["add"] = MeshJob{ID: "add", AP: parent, MACs: []string{child}, Action: "add", State: "completed", Started: now.Add(-time.Minute)}
	m.meshJobs["remove"] = MeshJob{ID: "remove", AP: parent, MACs: []string{child}, Action: "delete", State: "completed", Started: now}
	if err := m.migrateMeshMembersLocked(); err != nil {
		t.Fatal(err)
	}
	if m.meshAuthorize(parent, now, child, 1) || len(m.meshMembersLocked(parent)) != 0 {
		t.Fatal("denied member still granted")
	}
	for i := 0; i < 1000; i++ {
		id := fmt.Sprint(i)
		m.meshJobs[id] = MeshJob{ID: id, Action: "discover", State: "completed", Updated: now.Add(time.Duration(i) * time.Second)}
	}
	m.pruneMeshJobsLocked()
	if len(m.meshJobs) != 800 || m.meshAuthorize(parent, now, child, 1) {
		t.Fatal("compaction lost deny policy")
	}
	backup := callManagement(t, m, "GET", "backup", nil)
	if backup.Code != 200 {
		t.Fatal(backup.Code, backup.Body.String())
	}
	m2, _ := testController(t)
	var b any
	if err := json.Unmarshal(backup.Body.Bytes(), &b); err != nil {
		t.Fatal(err)
	}
	if w := callManagement(t, m2, "POST", "restore", b); w.Code != 202 {
		t.Fatal(w.Code, w.Body.String())
	}
	m2.known[parent] = m.known[parent]
	m2.known[child] = m.known[child]
	if m2.meshAuthorize(parent, now, child, 1) || len(m2.meshMembersLocked(parent)) != 0 {
		t.Fatal("backup lost explicit deny")
	}
	// An old completed journal must not resurrect permission in a backup which
	// now has an authoritative member list.
	if err := atomicJSON(m2.meshJobsPath(), map[string]MeshJob{"old": {ID: "old", AP: parent, MACs: []string{child}, Action: "add", State: "completed", Started: now.Add(time.Hour)}}); err != nil {
		t.Fatal(err)
	}
	restarted, err := New(e, cweng.NewClientTable(), filepath.Dir(m2.path))
	if err != nil {
		t.Fatal(err)
	}
	restarted.known[parent] = m.known[parent]
	restarted.known[child] = m.known[child]
	if restarted.meshAuthorize(parent, now, child, 1) {
		t.Fatal("old journal overrode backed-up policy")
	}
}

func TestMeshResultPersistsBeforeCompletedAndRetriesStorageFailure(t *testing.T) {
	m, _ := testController(t)
	parent, child := "02:00:00:00:00:01", "02:00:00:00:00:02"
	now := time.Now()
	m.config.Mesh = meshFixture()
	m.config.Mesh.Members = []MeshMemberPolicy{}
	j := MeshJob{ID: "pair", AP: parent, MACs: []string{child}, Action: "pair", State: "waiting_report", Started: now.Add(-time.Second), Connection: now}
	m.meshJobs[j.ID] = j
	ap := cweng.APStatus{ID: parent, ConnectedAt: now, Online: true, Mesh: &cweng.MeshReport{TopologyAt: now, Nodes: []cweng.MeshNode{{MAC: child}}}}
	path := m.path
	m.path = filepath.Join(t.TempDir(), "blocked")
	if err := os.Mkdir(m.path, 0700); err != nil {
		t.Fatal(err)
	}
	m.observeMeshJobs([]cweng.APStatus{ap}, now)
	if m.meshJobs[j.ID].State != "waiting_report" || len(m.config.Mesh.Members) != 0 {
		t.Fatal("failed policy write reported completed")
	}
	m.path = path
	m.observeMeshJobs([]cweng.APStatus{ap}, now.Add(time.Second))
	if m.meshJobs[j.ID].State != "completed" || len(m.config.Mesh.Members) != 1 || !m.config.Mesh.Members[0].Allowed {
		t.Fatal(m.meshJobs[j.ID], m.config.Mesh.Members)
	}
}

func TestMeshReplacementMovesParentAndChildIntentAndRetiredParentCannotGrant(t *testing.T) {
	old, target, child := "02:00:00:00:00:01", "02:00:00:00:00:02", "02:00:00:00:00:03"
	cfg := Config{Mesh: meshFixture()}
	cfg.Mesh.Members = []MeshMemberPolicy{{Parent: old, MAC: child, Allowed: false}, {Parent: target, MAC: child, Allowed: true}}
	retargetPolicies(&cfg, old, target)
	if len(cfg.Mesh.Members) != 1 || cfg.Mesh.Members[0].Parent != target || cfg.Mesh.Members[0].Allowed {
		t.Fatal(cfg.Mesh.Members)
	}
	if got := retargetMeshMembers([]MeshMemberPolicy{}, old, target); got == nil {
		t.Fatal("empty authoritative list turned legacy")
	}
	m, _ := testController(t)
	m.config = cfg
	m.config.RetiredAPs = []string{old}
	now := time.Now()
	m.known[old] = cweng.APStatus{ID: old, ConnectedAt: now}
	m.known[child] = cweng.APStatus{ID: child, MeshParent: old}
	if m.meshAuthorize(old, now, child, 1) || len(m.meshMembersLocked(old)) != 0 {
		t.Fatal("retired parent granted old children")
	}
}

func TestMeshJournalCapacityDoesNotBlockNewManagement(t *testing.T) {
	m, e := testController(t)
	_, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{0, 1 << 12}
	m.config.Mesh = meshFixture()
	m.config.Mesh.Members = []MeshMemberPolicy{}
	for i := 0; i < 1000; i++ {
		id := fmt.Sprint(i)
		m.meshJobs[id] = MeshJob{ID: id, Action: "discover", State: "completed"}
	}
	if _, err := m.meshAction(context.Background(), ap, "discover", nil); err != nil {
		t.Fatal(err)
	}
	if len(m.meshJobs) != 801 {
		t.Fatal(len(m.meshJobs))
	}
}

func TestMeshSettingsKeepMemberPolicyAndRestoreRejectsPendingOperation(t *testing.T) {
	m, _ := testController(t)
	m.config.Mesh = meshFixture()
	m.config.Mesh.Members = []MeshMemberPolicy{{Parent: "02:00:00:00:00:01", MAC: "02:00:00:00:00:02", Allowed: false}}
	w := callManagement(t, m, "POST", "mesh", map[string]any{"enabled": true, "ssid": "NewBackhaul", "auto_add": true, "backhaul_mode": 0})
	if w.Code != 202 || len(m.config.Mesh.Members) != 1 || m.config.Mesh.Members[0].Allowed {
		t.Fatal(w.Code, w.Body.String(), m.config.Mesh)
	}
	version := m.config.Version
	m.meshJobs["pending"] = MeshJob{ID: "pending", State: "waiting_report"}
	w = callManagement(t, m, "POST", "restore", map[string]any{"format": "go-ac-configuration", "schema": 1, "config": Config{}})
	if w.Code != 409 || m.config.Version != version {
		t.Fatal("restore raced a pending mesh command", w.Code, w.Body.String())
	}
}

func TestMeshNodeReportThroughUDPCompletesAndPersistsMemberIntent(t *testing.T) {
	m, e := testController(t)
	e.RegisterObservationHandlers()
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{0, 1 << 12}
	m.config.Mesh = meshFixture()
	m.config.Mesh.Members = []MeshMemberPolicy{}
	m.known[ap.ID] = ap
	child := "02:00:00:00:00:09"
	j, err := m.meshAction(context.Background(), ap, "pair", []string{child})
	if err != nil || j.State != "waiting_report" {
		t.Fatal(j, err)
	}
	node := make([]byte, 38)
	copy(node, []byte{2, 0, 0, 0, 0, 9})
	copy(node[6:], []byte{192, 0, 2, 9})
	node[27] = 2
	packet, _ := capwap.NewParsedPacket(9)
	packet.Control.SeqNum = 73
	packet.Elements = []capwap.Element{meshSetting(capwap.VendorRecord{Type: 6, Value: append([]byte{0, 1}, node...)})}
	if _, err = f.conn.Write(packet.Assemble()); err != nil {
		t.Fatal(err)
	}
	end := time.Now().Add(time.Second)
	for time.Now().Before(end) {
		m.observeMeshJobs(e.APs(), time.Now())
		if m.meshJobs[j.ID].State == "completed" {
			break
		}
		time.Sleep(time.Millisecond)
	}
	if m.meshJobs[j.ID].State != "completed" || len(m.config.Mesh.Members) != 1 || !m.config.Mesh.Members[0].Allowed {
		t.Fatal(m.meshJobs[j.ID], m.config.Mesh.Members)
	}
	var saved Config
	b, err := os.ReadFile(m.path)
	if err != nil {
		t.Fatal(err)
	}
	if err = json.Unmarshal(b, &saved); err != nil {
		t.Fatal(err)
	}
	if saved.Mesh == nil || len(saved.Mesh.Members) != 1 || saved.Mesh.Members[0].MAC != child {
		t.Fatal("native UDP result was not persisted")
	}
}

func TestRestoreLegacyMeshBackupKeepsCurrentMemberDenials(t *testing.T) {
	m, _ := testController(t)
	m.config.Mesh = meshFixture()
	deny := MeshMemberPolicy{Parent: "02:00:00:00:00:01", MAC: "02:00:00:00:00:02", Allowed: false}
	m.config.Mesh.Members = []MeshMemberPolicy{deny}
	w := callManagement(t, m, "POST", "restore", map[string]any{"format": "go-ac-configuration", "schema": 1, "config": Config{Mesh: meshFixture()}})
	if w.Code != 202 || len(m.config.Mesh.Members) != 1 || m.config.Mesh.Members[0].Allowed {
		t.Fatal("old backup erased a member denial it cannot represent", w.Code, w.Body.String())
	}
}
