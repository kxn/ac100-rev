package jcs

import (
	"database/sql"
	"path/filepath"
	"strings"
	"testing"
	"time"

	_ "modernc.org/sqlite"
)

// mesh/rrm/lldp store-backed handlers per notes §24 key sets: set persists,
// get returns the stored values (syscfg KV).
func TestBatch3Cfg(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "sys.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	path := filepath.Join(dir, "jcs.service.srv.cfg")
	s := NewServer()
	RegisterBatch3Handlers(s, &Batch3Stores{SensorDB: nil})
	RegisterMeshGlobalHandler(s, db)
	RegisterRRMHandlers(s, db)
	RegisterLLDPHandlers(s, db)
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

	// mesh global set/get roundtrip
	if resp := call("ac_mesh_global_settings", "set", "set", map[string]any{
		"enable": 1, "backhaul_ssid": "bh", "backhaul_key": "k",
		"bh_work_mode": 1}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("mesh set = %s", resp)
	}
	if resp := call("ac_mesh_global_settings", "get", "get", nil); !strings.Contains(resp, "bh") {
		t.Fatalf("mesh get = %s", resp)
	}

	// rrm para + state
	if resp := call("ac_rrmpara", "set", "set", map[string]any{
		"autorrm_enable": 1, "autorrm_date": "mon", "autorrm_time": "03:00",
		"bw_2g": 20, "bw_5g": 80, "chnl_enable": 1, "freq_enable": 0,
		"chnl_2g_set": 6, "chnl_5g1_set": 36, "chnl_5g2_set": 149}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("rrm para set = %s", resp)
	}
	if resp := call("ac_rrmpara", "get", "get", nil); !strings.Contains(resp, "autorrm") {
		t.Fatalf("rrm para get = %s", resp)
	}
	if resp := call("ac_rrm_state", "get", "get", nil); !strings.Contains(resp, "state") {
		t.Fatalf("rrm state get = %s", resp)
	}

	// lldp set/get
	if resp := call("uac_lldp", "set", "set", map[string]any{"is_first": 1, "enable": 1}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("lldp set = %s", resp)
	}
	if resp := call("uac_lldp", "get", "get", nil); !strings.Contains(resp, `"cnt":1`) {
		t.Fatalf("lldp get = %s", resp)
	}

	// untouched registrations stay not-impl
	if resp := call("ac_balance", "set", "set", nil); !strings.Contains(resp, "not implemented") {
		t.Fatalf("ac_balance should remain not-impl: %s", resp)
	}
	s.Close()
}
