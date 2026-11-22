package jcs

import (
	"database/sql"
	"fmt"
	"path/filepath"
	"testing"
	"time"

	_ "modernc.org/sqlite"
	"uacgo/store"
)

// Batch-3: wips whitelist lifecycle over sensor.db whitelist_table and
// sensor test-case add/del over testcase_tbl (sensor_test_sqlite_init
// table name "testcase_tbl"); the not-impl registrations answer marked
// errors.
func TestBatch3(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "sensor.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	tc := fmt.Sprintf(store.SchemaTable6, "testcase_tbl")
	if _, err := db.Exec(tc); err != nil {
		t.Fatal(err)
	}
	path := filepath.Join(dir, "jcs.service.srv.sensor")
	s := NewServer()
	RegisterBatch3Handlers(s, &Batch3Stores{SensorDB: db})
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
	okCode := func(resp string) bool { return indexOfStr(resp, `"error_code":0`) >= 0 }

	// wips whitelist lifecycle
	if resp := call("whitelist", "add", "add", map[string]any{
		"whitelist_id": 1, "mac": "aa:bb:cc:00:00:09"}); !okCode(resp) {
		t.Fatalf("whitelist add = %s", resp)
	}
	if resp := call("whitelist", "get", "get", nil); indexOfStr(resp, "aa:bb:cc:00:00:09") < 0 {
		t.Fatalf("whitelist get = %s", resp)
	}
	if resp := call("whitelist", "del", "del", map[string]any{
		"mac": "aa:bb:cc:00:00:09"}); !okCode(resp) {
		t.Fatalf("whitelist del = %s", resp)
	}
	if resp := call("whitelist", "get", "get", nil); indexOfStr(resp, "aa:bb:cc:00:00:09") >= 0 {
		t.Fatalf("whitelist row left: %s", resp)
	}

	// sensor test case add/del over testcase_tbl
	if resp := call("sensor_test_case_list", "add", "add", map[string]any{
		"test_case_id": 1, "test_case_name": "case-A"}); !okCode(resp) {
		t.Fatalf("case add = %s", resp)
	}
	if resp := call("sensor_test_case_list", "del", "del", map[string]any{
		"test_case_id": 1}); !okCode(resp) {
		t.Fatalf("case del = %s", resp)
	}

	// not-impl marker
	if resp := call("ac_balance", "set", "set", nil); indexOfStr(resp, "not implemented") < 0 {
		t.Fatalf("ac_balance not-impl marker: %s", resp)
	}
	s.Close()
}
