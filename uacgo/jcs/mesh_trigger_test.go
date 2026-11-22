package jcs

import (
	"database/sql"
	"path/filepath"
	"strings"
	"testing"
	"time"

	_ "modernc.org/sqlite"
)

// mesh triggers drive the discovery state machine; global settings get
// reads back the syscfg values written by the set handler.
func TestMeshTriggers(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "sys.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	path := filepath.Join(dir, "jcs.service.srv.mesh")
	s := NewServer()
	RegisterBatch3Handlers(s, &Batch3Stores{SensorDB: db})
	RegisterMeshGlobalHandler(s, db)
	RegisterRRMHandlers(s, db)
	RegisterLLDPHandlers(s, db)
	rs := NewRuntimeState(db)
	rs.RegisterRuntimeHandlers(s, db)
	rs.RegisterMeshTriggerHandlers(s, db)
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

	if resp := call("ac_mesh_trigger_discover", "set", "set", nil); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("trigger discover = %s", resp)
	}
	if resp := call("ac_mesh_discover_status", "get", "get", nil); !strings.Contains(resp, `"status":"scanning"`) {
		t.Fatalf("status after discover = %s", resp)
	}
	if resp := call("ac_mesh_stop_discover", "set", "set", nil); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("stop discover = %s", resp)
	}
	if resp := call("ac_mesh_discover_status", "get", "get", nil); !strings.Contains(resp, "finished") {
		t.Fatalf("status after stop = %s", resp)
	}

	// mesh global settings set (batch3cfg) → get (trigger handlers)
	if resp := call("ac_mesh_global_settings", "set", "set", map[string]any{
		"enable": 1, "backhaul_ssid": "mesh-bh", "bh_work_mode": 2}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("mesh global set = %s", resp)
	}
	resp := call("ac_mesh_global_settings", "get", "get", nil)
	if !strings.Contains(resp, "mesh-bh") || !strings.Contains(resp, `"bh_work_mode":2`) {
		t.Fatalf("mesh global get = %s", resp)
	}
	s.Close()
}
