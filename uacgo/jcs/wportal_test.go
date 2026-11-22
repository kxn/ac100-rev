package jcs

import (
	"path/filepath"
	"strings"
	"testing"
	"time"
)

// wportal verbs over the authed-user table with portal.db snapshot:
// add → get (search/online filter) → set → del, snapshot survives reload.
func TestWportalLifecycle(t *testing.T) {
	dir := t.TempDir()
	snap := filepath.Join(dir, "portal.db")
	table, err := NewAuthedUserTable(snap)
	if err != nil {
		t.Fatal(err)
	}
	path := filepath.Join(dir, "jcs.service.srv.wportal")
	s := NewServer()
	RegisterWportalHandlers(s, table)
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond)

	call := func(method string, params any) string {
		t.Helper()
		resp, err := Call(path, method, "wportal", method, params)
		if err != nil {
			t.Fatal(err)
		}
		return string(resp)
	}
	okCode := func(resp string) bool { return indexOfStr(resp, `"error_code":0`) >= 0 }

	add := func(mac, user string, online bool) {
		t.Helper()
		if resp := call("add", map[string]any{
			"mac": mac, "user": user, "ip": "10.0.0.9", "ssid": "office",
			"auth_time": 1700000000, "is_online": online}); !okCode(resp) {
			t.Fatalf("add %s = %s", mac, resp)
		}
	}
	add("aa:bb:cc:00:00:01", "alice", true)
	add("aa:bb:cc:00:00:02", "bob", false)

	// search filter
	if resp := call("get", map[string]any{"search": "ali"}); indexOfStr(resp, "alice") < 0 ||
		indexOfStr(resp, "bob") >= 0 {
		t.Fatalf("search get = %s", resp)
	}
	// is_online filter
	if resp := call("get", map[string]any{"is_online": false}); indexOfStr(resp, "bob") < 0 ||
		indexOfStr(resp, "alice") >= 0 {
		t.Fatalf("online filter get = %s", resp)
	}
	// is_online query
	if !table.GetIsOnline("aa:bb:cc:00:00:01") || table.GetIsOnline("aa:bb:cc:00:00:02") {
		t.Fatal("is_online judgment wrong")
	}
	// set
	if resp := call("set", map[string]any{
		"mac": "aa:bb:cc:00:00:02", "user": "bob", "ip": "10.0.0.10",
		"ssid": "office", "auth_time": 1700000001, "is_online": true}); !okCode(resp) {
		t.Fatalf("set = %s", resp)
	}
	if !table.GetIsOnline("aa:bb:cc:00:00:02") {
		t.Fatal("set did not apply")
	}
	// snapshot → reload
	if err := table.Snapshot(); err != nil {
		t.Fatal(err)
	}
	table2, err := NewAuthedUserTable(snap)
	if err != nil {
		t.Fatal(err)
	}
	if !table2.GetIsOnline("aa:bb:cc:00:00:02") {
		t.Fatal("snapshot did not survive reload")
	}
	// del
	if resp := call("del", map[string]any{"mac": "aa:bb:cc:00:00:01"}); !okCode(resp) {
		t.Fatalf("del = %s", resp)
	}
	if resp := call("get", map[string]any{}); strings.Contains(resp, "alice") {
		t.Fatalf("row not deleted: %s", resp)
	}
	s.Close()
}
