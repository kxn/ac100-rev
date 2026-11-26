package admin

import (
	"context"
	"encoding/binary"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func meshFixture() *MeshConfig {
	return &MeshConfig{Enabled: true, SSID: "Backhaul", Key: "mesh-test-key", Token: "pair-token", WebPassword: "Mesh123456", AutoAdd: true, BackhaulMode: 2}
}
func TestMeshPolicyPackedAndCapabilityGated(t *testing.T) {
	ap := cweng.APStatus{SubCapabilities: map[uint16]uint32{44: 1}}
	p := meshFixture()
	if err := validateMesh(p); err != nil {
		t.Fatal(err)
	}
	els := meshPolicyElements(p, ap, Config{})
	wire := els[0].Value
	rows, err := capwap.ParseVendorList(wire[10:])
	if err != nil || len(rows) != 5 {
		t.Fatal(rows, err)
	}
	bh := rows[0].Value
	if string(bh[:8]) != "Backhaul" || binary.BigEndian.Uint16(bh[32:]) != 13 || string(bh[34:47]) != "mesh-test-key" || string(rows[1].Value[2:]) != "Mesh123456" || rows[2].Value[0] != 1 || rows[2].Value[1] != 1 || rows[3].Type != 23 || rows[3].Value[0] != 2 || rows[4].Type != 21 {
		t.Fatalf("incorrect Mesh wire: %x", wire)
	}
	ap.SubCapabilities = nil
	rows, _ = capwap.ParseVendorList(meshPolicyElements(p, ap, Config{})[0].Value[10:])
	if len(rows) != 4 {
		t.Fatal("unsupported backhaul mode sent")
	}
	pub := publicMesh(p)
	if pub.Key != "" || pub.Token != "" || pub.WebPassword != "" || !pub.HasKey || !pub.HasToken || !pub.HasWebPassword || p.Key == "" {
		t.Fatal(pub)
	}
	if _, err := meshActionRecords("delete", nil); err == nil {
		t.Fatal("empty list must not implicitly delete all")
	}
	if _, err := meshActionRecords("pair", []string{"ff:ff:ff:ff:ff:ff"}); err == nil {
		t.Fatal("broadcast accepted")
	}
}
func TestMeshActionACKIsNotTopologyAndRestartDoesNotReplay(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = make([]uint32, 4)
	ap.GeneralCapabilities[1] = 1 << 12
	m.config.Mesh = meshFixture()
	m.known[ap.ID] = ap
	j, err := m.meshAction(context.Background(), ap, "pair", []string{"02:00:00:00:00:09"})
	if err != nil || j.State != "waiting_report" {
		t.Fatal(j, err)
	}
	f.mu.Lock()
	n := len(f.packets)
	packet := f.packets[n-1]
	f.mu.Unlock()
	rows, _ := capwap.ParseVendorList(packet.Elements[0].Value[10:])
	if len(rows) != 1 || rows[0].Type != 2 || len(rows[0].Value) != 8 {
		t.Fatal(rows)
	}
	m.observeMeshJobs([]cweng.APStatus{ap}, time.Now())
	if m.meshJobs[j.ID].State != "waiting_report" {
		t.Fatal("ACK mistaken for paired")
	}
	if !m.meshAuthorize(ap.ID, ap.ConnectedAt, j.MACs[0], 1) || m.meshAuthorize(ap.ID, ap.ConnectedAt, "02:00:00:00:00:08", 1) {
		t.Fatal("explicit admission policy")
	}
	if m.meshAuthorize(ap.ID, ap.ConnectedAt.Add(time.Second), j.MACs[0], 1) {
		t.Fatal("stale connection admitted")
	}
	restored, err := New(e, cweng.NewClientTable(), m.path[:len(m.path)-len("controller.json")])
	if err != nil {
		t.Fatal(err)
	}
	if restored.meshJobs[j.ID].State != "uncertain" {
		t.Fatal("interrupted job replay")
	}
	ap.Mesh = &cweng.MeshReport{TopologyAt: time.Now(), Nodes: []cweng.MeshNode{{MAC: j.MACs[0]}}}
	m.observeMeshJobs([]cweng.APStatus{ap}, time.Now())
	if m.meshJobs[j.ID].State != "completed" {
		t.Fatal(m.meshJobs[j.ID])
	}
}

func TestMeshMembershipIsPersistentPolicyNotTopologyQuery(t *testing.T) {
	m, _ := testController(t)
	m.config.Mesh = meshFixture()
	now := time.Now()
	parent := cweng.APStatus{ID: "02:00:00:00:00:01", ConnectedAt: now}
	child := "02:00:00:00:00:09"
	m.known[parent.ID] = parent
	m.known[child] = cweng.APStatus{ID: child, MeshParent: parent.ID}
	if !m.meshAuthorize(parent.ID, now, child, 1) {
		t.Fatal("existing child cannot rejoin")
	}
	members := m.meshMembersLocked(parent.ID)
	if len(members) != 1 || members[0] != child {
		t.Fatal(members)
	}
	m.meshJobs["remove"] = MeshJob{ID: "remove", AP: parent.ID, Action: "delete", MACs: []string{child}, State: "completed", Started: now}
	if len(m.meshMembersLocked(parent.ID)) != 0 || m.meshAuthorize(parent.ID, now, child, 1) {
		t.Fatal("removed child readmitted")
	}
	m.meshJobs["add"] = MeshJob{ID: "add", AP: parent.ID, Action: "add", MACs: []string{child}, State: "completed", Started: now.Add(time.Second)}
	if len(m.meshMembersLocked(parent.ID)) != 1 || !m.meshAuthorize(parent.ID, now, child, 1) {
		t.Fatal("explicit re-add did not restore member")
	}
	if _, err := meshActionRecords("refresh", nil); err == nil {
		t.Fatal("RE allowlist mislabeled as harmless topology query")
	}
}
