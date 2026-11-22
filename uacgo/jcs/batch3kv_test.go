package jcs

import (
	"database/sql"
	"path/filepath"
	"strings"
	"testing"
	"time"

	_ "modernc.org/sqlite"
)

// syscfg-backed setters persist and their paired getters read back.
func TestSyscfgHandlers(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "sys.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	path := filepath.Join(dir, "jcs.service.srv.kv")
	s := NewServer()
	RegisterSyscfgHandlers(s, db)
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

	if resp := call("apmngr_global", "set", "set", map[string]any{
		"log_level": 4, "ap_alive": 60}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("apmngr global set = %s", resp)
	}
	resp := call("apmngr_global", "get", "get", nil)
	if !strings.Contains(resp, `"log_level":4`) || !strings.Contains(resp, `"ap_alive":60`) {
		t.Fatalf("apmngr global get = %s", resp)
	}

	if resp := call("sensor_global", "set", "set", map[string]any{"enable": 1}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("sensor global set = %s", resp)
	}
	resp = call("sensor_global", "get", "get", nil)
	if !strings.Contains(resp, `"enable":1`) {
		t.Fatalf("sensor global get = %s", resp)
	}

	if resp := call("diagnose_global", "set", "set", map[string]any{"mode": "ping"}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("diagnose set = %s", resp)
	}
	resp = call("diagnose_global", "get", "get", nil)
	if !strings.Contains(resp, "ping") {
		t.Fatalf("diagnose get = %s", resp)
	}

	if resp := call("wserv_global", "set", "set", map[string]any{"timeout": 15}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("wserv global set = %s", resp)
	}
	resp = call("wserv_global", "get", "get", nil)
	if !strings.Contains(resp, `"timeout":15`) {
		t.Fatalf("wserv global get = %s", resp)
	}
	s.Close()
}
