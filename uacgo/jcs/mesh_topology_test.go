package jcs

import (
	"encoding/json"
	"os"
	"path/filepath"
	"strings"
	"testing"
)

// Node schema and helpers must match the binary evidence
// (_mesh_ap_entry_topology_get @0x4bb32c).
func TestMeshTopologyNodeSchema(t *testing.T) {
	if UplinkTypeStr(1) != "wired" || UplinkTypeStr(2) != "wireless" ||
		UplinkTypeStr(0) != "unknown" || UplinkTypeStr(7) != "unknown" {
		t.Fatal("uplink type map mismatch")
	}
	if Mac2Str([6]byte{0x0A, 0xBB, 0xCC, 0x01, 0x0F, 0xFF}) != "0A-BB-CC-01-0F-FF" {
		t.Fatal("mac2str format mismatch")
	}

	oldFile := MeshTopologyFile
	MeshTopologyFile = filepath.Join(t.TempDir(), "mesh_topology")
	defer func() { MeshTopologyFile = oldFile }()

	rs := NewRuntimeState(nil)
	tables := NewRuntimeTables(rs)
	s := NewServer()
	tables.RegisterRuntimeQueryHandlers(s)
	tables.SetMeshTopology([]MeshTopologyNode{
		// no ParentMAC → key omitted (parent lookup path, +22=0xffff)
		{ApID: 3, ParentApID: -1, CapID: 1, UplinkType: "wired", EstimateRate: 1000},
	})
	path := testServe(t, s)
	defer s.Close()
	resp, err := Call(path, "get", "ac_mesh_topology", "get", nil)
	if err != nil {
		t.Fatal(err)
	}
	if !strings.Contains(string(resp), `"file_name":"`+MeshTopologyFile+`"`) ||
		!strings.Contains(string(resp), `"total_num":1`) {
		t.Fatalf("resp = %s", resp)
	}
	b, err := os.ReadFile(MeshTopologyFile)
	if err != nil {
		t.Fatal(err)
	}
	var nodes []map[string]any
	if err := json.Unmarshal(b, &nodes); err != nil {
		t.Fatalf("file json: %v (%s)", err, b)
	}
	if len(nodes) != 1 {
		t.Fatalf("nodes = %s", b)
	}
	n := nodes[0]
	if _, ok := n["mac"]; ok {
		t.Fatalf("mac key must be omitted when lookup fails: %s", b)
	}
	if _, ok := n["parent_mac"]; ok {
		t.Fatalf("parent_mac key must be omitted: %s", b)
	}
	if n["ap_id"].(float64) != 3 || n["parent_ap_id"].(float64) != -1 ||
		n["cap_id"].(float64) != 1 || n["uplink_type"] != "wired" ||
		n["estimate_rate"].(float64) != 1000 {
		t.Fatalf("node fields = %s", b)
	}
}
