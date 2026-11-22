package jcs

import (
	"database/sql"
	"path/filepath"
	"testing"
	"time"

	_ "modernc.org/sqlite"
	"uacgo/store"
)

// wserv registrations (uac_wservice_init @0x5e01a0) wired over wserv.db:
// wservice add/get/set/del over wserv_tbl, wservice_ip over igmp_ip_tbl.
func TestWserviceHandlers(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "wserv.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	for _, sc := range []string{store.SchemaWservTbl, store.SchemaIgmpIpTbl} {
		if _, err := db.Exec(sc); err != nil {
			t.Fatal(err)
		}
	}
	path := filepath.Join(dir, "jcs.service.srv.wserv")
	s := NewServer()
	RegisterWserviceHandlers(s, &WservStore{DB: db})
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond)

	call := func(method string, params any) string {
		t.Helper()
		resp, err := Call(path, method, "wservice", method, params)
		if err != nil {
			t.Fatal(err)
		}
		return string(resp)
	}
	okCode := func(resp string) bool {
		return indexOfStr(resp, `"error_code":0`) >= 0 || indexOfStr(resp, `"error_code": 0`) >= 0
	}

	if resp := call("add", map[string]any{
		"serv_id": 1, "enable": "1", "default_bind_vlan": 1,
		"ssid": "00_YXJ_统一技术_GBK"}); !okCode(resp) {
		t.Fatalf("add = %s", resp)
	}
	if resp := call("get", nil); indexOfStr(resp, "00_YXJ_") < 0 {
		t.Fatalf("get = %s", resp)
	}
	if resp := call("set", map[string]any{
		"serv_id": 1, "enable": "1", "default_bind_vlan": 2, "ssid": "ssid2"}); !okCode(resp) {
		t.Fatalf("set = %s", resp)
	}
	if resp := call("get", nil); indexOfStr(resp, "ssid2") < 0 {
		t.Fatalf("get after set = %s", resp)
	}
	if resp := call("del", map[string]any{"serv_id": 1}); !okCode(resp) {
		t.Fatalf("del = %s", resp)
	}
	if resp := call("get", nil); indexOfStr(resp, "ssid2") >= 0 {
		t.Fatalf("row not deleted: %s", resp)
	}

	// wservice_ip over igmp_ip_tbl
	ipCall := func(method string, params any) string {
		t.Helper()
		resp, err := Call(path, method, "wservice_ip", method, params)
		if err != nil {
			t.Fatal(err)
		}
		return string(resp)
	}
	if resp := ipCall("add", map[string]any{
		"id": 1, "ip_addr": "239.1.2.3", "relay": 1, "enable": "1"}); !okCode(resp) {
		t.Fatalf("ip add = %s", resp)
	}
	if resp := ipCall("del", map[string]any{"id": 1}); !okCode(resp) {
		t.Fatalf("ip del = %s", resp)
	}
	s.Close()
}

// rd_op path: radio binds set → get over bind_tbl (wserv_rd.db).
func TestWserviceRdBind(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "wserv_rd.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	if _, err := db.Exec(store.SchemaBindTbl_wserv); err != nil {
		t.Fatal(err)
	}
	path := filepath.Join(dir, "jcs.service.srv.wserv")
	s := NewServer()
	RegisterWserviceHandlers(s, &WservStore{DB: db})
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond)

	setResp, err := Call(path, "set", "wservice", "rd_bind.set", map[string]any{
		"radio_id": 1, "serv_id": []int64{10, 20}, "vlan_id": []int64{100, 200}})
	if err != nil || indexOfStr(string(setResp), `"error_code":0`) < 0 {
		t.Fatalf("rd_bind.set = %s %v", setResp, err)
	}
	getResp, err := Call(path, "get", "wservice", "rd_bind", map[string]any{"radio_id": 1})
	if err != nil || indexOfStr(string(getResp), "200") < 0 {
		t.Fatalf("rd_bind get = %s %v", getResp, err)
	}
	s.Close()
}
