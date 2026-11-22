package jcs

import (
	"database/sql"
	"path/filepath"
	"testing"
	"time"

	_ "modernc.org/sqlite"
	"uacgo/store"
)

// The apmngr registration table (apmngr_jcs_reg_callback @0x5546a8) wired
// over apmngr.db: entry/group lifecycle and ap_status reads.
func TestApmngrHandlers(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "apmngr.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	for _, sc := range []string{store.SchemaApentrycfgTable, store.SchemaApentryrunTable, store.SchemaGroupTable} {
		if _, err := db.Exec(sc); err != nil {
			t.Fatal(err)
		}
	}
	path := filepath.Join(dir, "jcs.service.srv.uac")
	s := NewServer()
	RegisterApmngrHandlers(s, &ApmngrStore{DB: db})
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond)

	call := func(method, module, kw string, params any) string {
		t.Helper()
		resp, err := Call(path, method, module, kw, params)
		if err != nil {
			t.Fatal(err)
		}
		return string(resp)
	}
	okCode := func(resp string) bool {
		return indexOfStr(resp, `"error_code":0`) >= 0 || indexOfStr(resp, `"error_code": 0`) >= 0
	}

	resp := call("add", "apmngr_entry", "add", map[string]any{
		"entry_id": 1, "mac": "aa:bb:cc:dd:ee:ff", "entry_name": "AP-1",
		"model_id": 100716033, "hardware_ver": "1.0"})
	if !okCode(resp) {
		t.Fatalf("add resp = %s", resp)
	}
	if resp = call("get", "apmngr_entry", "get", nil); indexOfStr(resp, "AP-1") < 0 {
		t.Fatalf("get resp = %s", resp)
	}
	resp = call("set", "apmngr_entry", "set", map[string]any{
		"entry_id": 1, "entry_name": "AP-1b"})
	if !okCode(resp) {
		t.Fatalf("set resp = %s", resp)
	}
	if resp = call("get", "apmngr_entry", "get", nil); indexOfStr(resp, "AP-1b") < 0 {
		t.Fatalf("get after set = %s", resp)
	}
	call("del", "apmngr_entry", "del", map[string]any{"entry_id": 1})
	if resp = call("get", "apmngr_entry", "get", nil); indexOfStr(resp, "AP-1b") >= 0 {
		t.Fatalf("row not deleted: %s", resp)
	}

	call("add", "apmngr_group", "add", map[string]any{"group_id": 1, "name": "default"})
	if resp = call("get", "apmngr_group", "get", nil); indexOfStr(resp, "default") < 0 {
		t.Fatalf("group get = %s", resp)
	}
	if resp = call("get", "ap_status", "get", nil); indexOfStr(resp, "status_list") < 0 {
		t.Fatalf("ap_status = %s", resp)
	}

	if resp, err := Call(path, "get", "apmngr_entry_backup", "get", nil); err != nil ||
		indexOf([]byte(resp), "not implemented") < 0 {
		t.Fatalf("not-impl marker: %s %v", resp, err)
	}
	s.Close()
}

func indexOfStr(s, sub string) int {
	for i := 0; i+len(sub) <= len(s); i++ {
		if s[i:i+len(sub)] == sub {
			return i
		}
	}
	return -1
}
