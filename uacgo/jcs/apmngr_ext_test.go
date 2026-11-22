package jcs

import (
	"database/sql"
	"path/filepath"
	"strings"
	"testing"
	"time"

	_ "modernc.org/sqlite"
)

// apmngr ext handlers: entry_copy/authorize/group_join/firm backed by
// apmngr.db.
func TestApmngrExtHandlers(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "apmngr.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	for _, sc := range []string{
		"CREATE TABLE IF NOT EXISTS ApEntryCfg_table(seq INTEGER PRIMARY KEY AUTOINCREMENT,entry_id INTEGER UNIQUE,group_id INTEGER,ap_role VARCHAR(10),mac VARCHAR(17) UNIQUE,entry_name VARCHAR(52) NOT NULL,model_id INTEGER NOT NULL,hardware_ver VARCHAR(20),firmware_id VARCHAR(33));",
	} {
		if _, err := db.Exec(sc); err != nil {
			t.Fatal(err)
		}
	}
	path := filepath.Join(dir, "jcs.service.srv.apmngr")
	s := NewServer()
	RegisterApmngrExtHandlers(s, &ApmngrStore{DB: db})
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

	// seed: insert a base entry for subsequent operations
	if _, err := db.Exec(
		`INSERT INTO ApEntryCfg_table(entry_id,group_id,mac,entry_name,model_id,hardware_ver)
		 VALUES(1,0,'aa:bb:cc:dd:ee:ff','BaseAP',100,'1.0')`); err != nil {
		t.Fatal(err)
	}

	// entry_copy: copies an entry
	if resp := call("apmngr_entry_copy", "set", "set", map[string]any{
		"copy_ap_id": 2, "ap_ids": "2"}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("entry copy = %s", resp)
	}

	// entry authorize
	if resp := call("apmngr_entry_authorize", "set", "set", map[string]any{
		"entry_id": 1, "allow": true}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("entry authorize = %s", resp)
	}
	if resp := call("apmngr_entry_authorize", "get", "get", nil); !strings.Contains(resp, "authorized") {
		t.Fatalf("authorize get = %s", resp)
	}

	// group_join
	if resp := call("apmngr_group_join", "set", "set", map[string]any{
		"group_id": 1, "ap_ids": []int64{1, 2}}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("group join = %s", resp)
	}

	// firm: assigns firmware_id
	if resp := call("apmngr_firm", "set", "set", map[string]any{
		"entry_ids": []int64{1}, "firmware_id": "fw-1"}); !strings.Contains(resp, `"error_code":0`) {
		t.Fatalf("firm = %s", resp)
	}

	// entry_backup: returns entry list
	if resp := call("apmngr_entry_backup", "get", "get", nil); !strings.Contains(resp, "entry_list") {
		t.Fatalf("entry backup = %s", resp)
	}

	// ap_exceed_status: returns count
	if resp := call("ap_exceed_status", "get", "get", nil); !strings.Contains(resp, "ap_count") {
		t.Fatalf("exceed status = %s", resp)
	}
	s.Close()
}
