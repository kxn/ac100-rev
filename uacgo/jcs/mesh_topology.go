package jcs

import (
	"encoding/json"
	"fmt"
	"os"
)

// mesh topology node schema and ac_mesh_topology.get / ac_mesh_wan_status.set,
// typed from the binary (this round):
//
//   mesh_jcs_topology_get @0x4be0c8:
//     root = json_object_new_array; area = {flag@+0, remaining@+4 =
//     apmngr_db_get_ap_max() @0x541aa4, count@+8, array@+20}
//     apmngr_db_foreach_proc @0x5382e4(group_mask=0xE0000, cb, &area)
//       → apmngr_db_foreach_proc_by_group @0x537ff4 per AP id:
//         entries with *(entry+12)==0 skipped; cb(entry+16, area);
//         cb return 0=continue, 2=stop
//     mesh_db_ap_entry_child_foreach_proc @0x4b797c(0xffff, 0,
//         _mesh_ap_entry_topology_get @0x4bb32c, &area)
//     s = json_object_to_json_string_ext(root, 0)
//     f = fopen("/tmp/mesh_topology","w+")  (0x6a4338/0x678548)
//     fwrite(s, strlen(s), 1, f); fclose
//     if count > 0:
//         object_add(resp,"file_name", new_string("/tmp/mesh_topology"))
//         object_add(resp,"total_num", new_int(count))  ("total_num"@0x6e1444)
//
//   node builder _mesh_ap_entry_topology_get @0x4bb32c over the mesh child
//   record: self ap_id u16 @+12, cap_id s16 @+20, parent ap_id s16 @+22
//   (0xffff = none), uplink u8 @+24, estimate_rate u32 @+28.
//   apmngr_db_entry_get_by_id @0x5398cc returns 0 on success / -1 on failure
//   and copies the 728-byte AP entry (MAC at +72).
//     lookup(+12) ok → key "mac" = mac2str(copy+72) @0x4bb2d8
//     +22 != 0xffff && lookup(+22) ok → key "parent_mac" = mac2str(copy+72)
//     (failed/absent lookups omit the key — the object_add calls sit on the
//      success branches)
//     then: "ap_id"=%d(lhu +12), "parent_ap_id"=%d(lh +22 → -1 when none),
//     "cap_id"=%d(lh +20), "uplink_type"=mesh_db_uplink_type_str_get(+24)
//     [1=wired 2=wireless else "unknown", fn @0x4b8404],
//     "estimate_rate"=%d(lw +28); node appended to the array.
//   mac2str format "%.2X-%.2X-%.2X-%.2X-%.2X-%.2X" @0x68baac.
//   Key strings: ap_id@0x68bd80 parent_mac@0x6a3b0c parent_ap_id@0x6a3b18
//   cap_id@0x6a3b28 uplink_type@0x6a3b30 estimate_rate@0x6a3b3c mac@0x67768c.
//
//   mesh_jcs_wan_status_set @0x4bb12c:
//     v = json_object_object_get(req, "wan_status") @0x6a4c8c
//     type int → (int8)json_object_get_int; type double →
//     (int8)(json_object_get_double); missing/other → resp["ret"]=-1
//     (@0x676a24, new_int(-1))
//     ok → mesh_db_mesh_wan_status_set(b) @0x4b8cec,
//     mesh_db_mesh_wan_status_get @0x4b8c64,
//     mesh_pkt_wan_status_request_send_to_all(b) @0x4c52f0,
//     resp["ret"] = new_int(0). One global status, not per-MAC.
//
// The vendor serialises the array into the file and returns only
// file_name+total_num; this port keeps that contract. File body formatting
// is encoding/json (json-c spacing is a library detail).

// MeshTopologyNode is one topology entry with the vendor field set.
type MeshTopologyNode struct {
	MAC          string `json:"mac,omitempty"`        // only when AP lookup succeeds
	ParentMAC    string `json:"parent_mac,omitempty"` // only when parent lookup succeeds
	ApID         int    `json:"ap_id"`                // u16 +12
	ParentApID   int    `json:"parent_ap_id"`         // s16 +22, -1 when none
	CapID        int    `json:"cap_id"`               // s16 +20
	UplinkType   string `json:"uplink_type"`          // wired/wireless/unknown
	EstimateRate int    `json:"estimate_rate"`        // u32 +28
}

// UplinkTypeStr mirrors mesh_db_uplink_type_str_get @0x4b8404.
func UplinkTypeStr(t uint8) string {
	switch t {
	case 1:
		return "wired"
	case 2:
		return "wireless"
	}
	return "unknown"
}

// Mac2Str mirrors mac2str @0x4bb2d8.
func Mac2Str(mac [6]byte) string {
	return fmt.Sprintf("%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",
		mac[0], mac[1], mac[2], mac[3], mac[4], mac[5])
}

// MeshTopologyFile is the file the vendor serialises the array into.
var MeshTopologyFile = "/tmp/mesh_topology"

// MeshDiscoverListFile is the discover-list serialisation target
// (mesh_jcs_discover_list_get @0x4be2f8).
var MeshDiscoverListFile = "/tmp/mesh_discover_list"

// SetMeshTopology replaces the topology node list (the RuntimeTables view
// of the vendor's mesh_db children).
func (t *RuntimeTables) SetMeshTopology(nodes []MeshTopologyNode) {
	t.mu.Lock()
	t.topoNodes = nodes
	t.mu.Unlock()
}

// registerMeshTopologyHandlers installs the evidenced ac_mesh_topology.get
// and ac_mesh_wan_status.set. Must run after the batch registrations to
// overwrite their placeholders.
func (t *RuntimeTables) registerMeshTopologyHandlers(s *Server) {
	s.replaceNotImpl("ac_mesh_topology.get", func(json.RawMessage) (any, error) {
		t.mu.Lock()
		nodes := t.topoNodes
		t.mu.Unlock()
		b, err := json.Marshal(nodes)
		if err != nil {
			return jerr(err), nil
		}
		if err := os.WriteFile(MeshTopologyFile, b, 0644); err != nil {
			return jerr(err), nil
		}
		// the vendor adds the response fields only when count > 0 (0x4be1d4)
		if len(nodes) <= 0 {
			return ok(), nil
		}
		return map[string]any{"error_code": 0, "file_name": MeshTopologyFile,
			"total_num": len(nodes)}, nil
	})
	s.replaceNotImpl("ac_mesh_wan_status.set", func(req json.RawMessage) (any, error) {
		var r struct {
			WanStatus *float64 `json:"wan_status"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if r.WanStatus == nil {
			return map[string]any{"error_code": 0, "ret": -1}, nil
		}
		// int8 truncation (sb of the extracted value)
		st := int8(int(*r.WanStatus))
		t.mu.Lock()
		t.wanStatus = st
		t.mu.Unlock()
		return map[string]any{"error_code": 0, "ret": 0}, nil
	})
}
