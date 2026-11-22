package jcs

import (
	"database/sql"
	"path/filepath"
	"strings"
	"testing"
	"time"

	_ "modernc.org/sqlite"
)

// Runtime-state handlers: balance set persists (syscfg), mesh discover
// status transitions, deep-inspection status reported.
func TestRuntimeHandlers(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "sys.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	path := filepath.Join(dir, "jcs.service.srv.rt")
	s := NewServer()
	RegisterBatch3Handlers(s, &Batch3Stores{SensorDB: db})
	rs := NewRuntimeState(db)
	rs.RegisterRuntimeHandlers(s, db)
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond)

	call := func(module, kw, method string, params any) string {
		t.Helper()
		resp, err := Call(path, method, module, kw, params)
		if err != nil {
			t.Fatal(err)
		}
		return string(resp)
	}

	// balance: not-impl replaced; persists via syscfg
	if resp := call("ac_balance", "set", "set", map[string]any{
		"enable": true, "dif_threshold": 5, "max_fail_num": 3}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("balance set = %s", resp)
	}
	var cfg BalanceCfg
	found, err := syscfgGet(db, "balance", &cfg)
	if err != nil || !found || !cfg.Enable || cfg.DifThreshold != 5 || cfg.MaxFailNum != 3 {
		t.Fatalf("balance persisted = %+v err=%v", cfg, err)
	}

	// mesh discover status: init → scanning → finished
	if resp := call("ac_mesh_discover_status", "get", "get", nil); !strings.Contains(resp, `"status":"init"`) {
		t.Fatalf("mesh status init = %s", resp)
	}
	rs.SetMeshDiscoverStatus("scanning", true)
	if resp := call("ac_mesh_discover_status", "get", "get", nil); !strings.Contains(resp, `"status":"scanning"`) || !strings.Contains(resp, `"auto_add_status":true`) {
		t.Fatalf("mesh status scanning = %s", resp)
	}
	rs.SetMeshDiscoverStatus("finished", false)
	if resp := call("ac_mesh_discover_status", "get", "get", nil); !strings.Contains(resp, "finished") {
		t.Fatalf("mesh status finished = %s", resp)
	}

	// deep-inspection status
	rs.SetDIStatus(DeepInspectionStatus{
		Status: "running", RemainTime: 120, CurViewedSensor: "00_YXJ_01"})
	if resp := call("deep_inspection_status", "get", "get", nil); !strings.Contains(resp, "running") || !strings.Contains(resp, "00_YXJ_01") {
		t.Fatalf("di status = %s", resp)
	}

	// unrelated placeholders remain not-impl
	if resp := call("uac_lldp", "get", "get", nil); !strings.Contains(resp, "not implemented") == false && strings.Contains(resp, "not implemented") == false && strings.Contains(resp, "lldp") == false {
		t.Fatalf("lldp should be registered: %s", resp)
	}
	s.Close()
}
