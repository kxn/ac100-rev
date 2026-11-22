package jcs

import (
	"path/filepath"
	"testing"
	"time"
)

func testServe(t *testing.T, s *Server) string {
	t.Helper()
	path := filepath.Join(t.TempDir(), "jcs.service.srv.rt")
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond)
	return path
}

// Runtime query handlers: wips events (paged + counters + per-sensor
// aggregation), mesh topology/discover paging, deep-checkup lists,
// manual-RRM trigger timestamp.
func TestRuntimeQueryHandlers(t *testing.T) {
	oldFile := MeshTopologyFile
	MeshTopologyFile = filepath.Join(t.TempDir(), "mesh_topology")
	defer func() { MeshTopologyFile = oldFile }()

	s := NewServer()
	rs := NewRuntimeState(nil)
	tables := NewRuntimeTables(rs)
	rs.RegisterRuntimeHandlers(s, nil)
	tables.RegisterRuntimeQueryHandlers(s)
	path := testServe(t, s)

	call := func(module, kw, method string, params any) string {
		t.Helper()
		resp, err := Call(path, method, module, kw, params)
		if err != nil {
			t.Fatal(err)
		}
		return string(resp)
	}

	// feed events of three classes
	tables.AddWipsEvent(WipsEvent{EntryName: "e1", Sensor: "s1", Type: "severe", DevMAC: "aa"})
	tables.AddWipsEvent(WipsEvent{EntryName: "e1", Sensor: "s1", Type: "slight", DevMAC: "bb"})
	tables.AddWipsEvent(WipsEvent{EntryName: "e2", Sensor: "s2", Type: "interfering", DevMAC: "cc"})

	if resp := call("wips_statistics_num", "get", "get", nil); indexOfStr(resp, "illegal") < 0 {
		t.Fatalf("statistics_num = %s", resp)
	}
	resp := call("wips_statistics", "get", "get", nil)
	if indexOfStr(resp, "severe_event_count") < 0 || indexOfStr(resp, "s1") < 0 {
		t.Fatalf("statistics = %s", resp)
	}
	resp = call("wips_event_info", "get", "get", map[string]any{"start": 0, "end": 2})
	if indexOfStr(resp, `"count":2`) < 0 || indexOfStr(resp, `"total":3`) < 0 {
		t.Fatalf("event page = %s", resp)
	}

	// mesh topology: typed nodes → file + total_num (0x4be0c8 contract)
	tables.SetMeshTopology([]MeshTopologyNode{
		{MAC: "AA-BB-CC-DD-EE-01", ApID: 3, ParentApID: -1, CapID: 1,
			UplinkType: "wired", EstimateRate: 1000},
		{MAC: "AA-BB-CC-DD-EE-02", ParentMAC: "AA-BB-CC-DD-EE-01",
			ApID: 4, ParentApID: 3, CapID: 2, UplinkType: "wireless",
			EstimateRate: 200},
	})
	resp = call("ac_mesh_topology", "get", "get", nil)
	if indexOfStr(resp, `"total_num":2`) < 0 || indexOfStr(resp, "file_name") < 0 {
		t.Fatalf("topology resp = %s", resp)
	}
	tables.SetMeshTopology(nil)
	resp = call("ac_mesh_topology", "get", "get", nil)
	if indexOfStr(resp, "total_num") >= 0 {
		t.Fatalf("empty topology resp should omit total_num = %s", resp)
	}
	// wan_status set: ret 0 on numeric field, -1 on missing
	resp = call("ac_mesh_wan_status", "set", "set", map[string]any{"wan_status": 1})
	if indexOfStr(resp, `"ret":0`) < 0 {
		t.Fatalf("wan status set = %s", resp)
	}
	resp = call("ac_mesh_wan_status", "set", "set", nil)
	if indexOfStr(resp, `"ret":-1`) < 0 {
		t.Fatalf("wan status missing = %s", resp)
	}
	tables.SetMeshDiscoverList([]map[string]any{
		{"mac": "m1"}, {"mac": "m2"}, {"mac": "m3"}})
	resp = call("ac_mesh_discover_list", "get", "get", nil)
	if indexOfStr(resp, "mesh_discover_list") < 0 || indexOfStr(resp, `"total_num":3`) < 0 {
		t.Fatalf("discover list = %s", resp)
	}

	// checkup lists
	tables.SetCheckupList("ssid", []map[string]any{{"ssid_id": 1, "name": "n", "percent": 42}})
	resp = call("deep_checkup_pkt_ssid_list", "get", "get", nil)
	if indexOfStr(resp, "percent") < 0 {
		t.Fatalf("checkup ssid = %s", resp)
	}

	// manual rrm trigger
	resp = call("ac_manualrrm", "set", "set", nil)
	if indexOfStr(resp, "trigger_time") < 0 {
		t.Fatalf("manual rrm = %s", resp)
	}
	s.Close()
}
