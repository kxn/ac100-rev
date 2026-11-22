package jcs

import (
	"database/sql"
	"os"
	"path/filepath"
	"strings"
	"testing"
	"time"

	_ "modernc.org/sqlite"
)

// Sensor test read handlers backed by sensor.db testcase_tbl + bssid_alloc,
// against the response contracts proven from the binary (see
// batch3senTest.go header).
func TestSensorTestReads(t *testing.T) {
	oldDir := SensorTestFileDir
	SensorTestFileDir = t.TempDir()
	defer func() { SensorTestFileDir = oldDir }()

	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "sensor.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	for _, sc := range []string{
		"CREATE TABLE IF NOT EXISTS testcase_tbl(test_case_id INTEGER,test_case_name NVARCHAR(33),sch_type INTEGER,sch_period INTEGER,sch_time INTEGER,change_id INTEGER,rssi_threshold INTEGER,group_id TEXT,join_test_sensor TEXT,ssid_info TEXT,service TEXT,key INTEGER PRIMARY KEY AUTOINCREMENT);",
		"CREATE TABLE IF NOT EXISTS bssid_alloc(bssid NVARCHAR(20),test_case_id INTEGER,status INTEGER,sensor_id INTEGER,rssi INTEGER,serv_id INTEGER,freqband INTEGER,key INTEGER PRIMARY KEY AUTOINCREMENT);",
	} {
		if _, err := db.Exec(sc); err != nil {
			t.Fatal(err)
		}
	}
	db.Exec(`INSERT INTO testcase_tbl(test_case_id,test_case_name,rssi_threshold,group_id) VALUES(1,'case-A',-75,'g1')`)
	db.Exec(`INSERT INTO bssid_alloc(bssid,test_case_id,status,sensor_id,rssi,freqband) VALUES('aa:bb:cc:dd:ee:01',1,1,2,-50,6)`)
	db.Exec(`INSERT INTO bssid_alloc(bssid,test_case_id,status,sensor_id,rssi,freqband) VALUES('aa:bb:cc:dd:ee:02',1,2,3,-60,36)`)

	path := filepath.Join(dir, "jcs.service.srv.sensor")
	s := NewServer()
	RegisterSensorTestReadHandlers2(s, db)
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond)
	defer s.Close()

	call := func(module, kw, method string, params any) string {
		t.Helper()
		resp, err := Call(path, method, module, kw, params)
		if err != nil {
			t.Fatal(err)
		}
		return string(resp)
	}
	// digest: ret + six counters inline (0x4f3de4)
	if resp := call("sensor_test_digest", "get", "get", nil); !strings.Contains(resp, `"ret":0`) ||
		!strings.Contains(resp, `"total_test_cnt":1`) || !strings.Contains(resp, `"sensor_cnt":2`) {
		t.Fatalf("digest = %s", resp)
	}
	// summary: inline sensor_test_summary wrapper (0x4f357c)
	resp := call("sensor_test_summary", "get", "get", nil)
	if !strings.Contains(resp, "sensor_test_summary") ||
		!strings.Contains(resp, "sch_start_time") || !strings.Contains(resp, "brief_result_list") {
		t.Fatalf("summary = %s", resp)
	}
	// summary_new: file contract (0x4f2920)
	resp = call("sensor_test_summary_new", "get", "get", map[string]any{"test_case_id": 1})
	if !strings.Contains(resp, "st_summary_result_1") || !strings.Contains(resp, `"total_num":1`) {
		t.Fatalf("summary_new = %s", resp)
	}
	b, err := os.ReadFile(filepath.Join(SensorTestFileDir, "st_summary_result_1"))
	if err != nil || !strings.Contains(string(b), "test_type_summary") {
		t.Fatalf("summary_new file = %s err %v", b, err)
	}
	// result: file contract + evidenced row keys (0x4f1844)
	resp = call("sensor_test_result", "get", "get", map[string]any{"test_case_id": 1})
	if !strings.Contains(resp, "st_simple_result_1") || !strings.Contains(resp, `"total_num":2`) {
		t.Fatalf("result = %s", resp)
	}
	b, err = os.ReadFile(filepath.Join(SensorTestFileDir, "st_simple_result_1"))
	if err != nil || !strings.Contains(string(b), `"ssid_name":"--"`) ||
		!strings.Contains(string(b), "AA-BB-CC-DD-EE-01") || !strings.Contains(string(b), "2.4G") {
		t.Fatalf("result file = %s err %v", b, err)
	}
	// detail: file contract + test/diagnosis (0x4f0c30)
	resp = call("sensor_test_detail_result", "get", "get", map[string]any{"test_case_id": 1})
	if !strings.Contains(resp, "st_detail_result_1") || !strings.Contains(resp, `"total_num":2`) {
		t.Fatalf("detail = %s", resp)
	}
	b, err = os.ReadFile(filepath.Join(SensorTestFileDir, "st_detail_result_1"))
	if err != nil || !strings.Contains(string(b), "diagnosis") || !strings.Contains(string(b), "startTime") {
		t.Fatalf("detail file = %s err %v", b, err)
	}
	// ssid list: file contract + sensor_list/group_list (0x4f4c80)
	resp = call("sensor_test_ssid_list", "get", "get", map[string]any{"start": 0, "end": 5})
	if !strings.Contains(resp, "st_ssid_list_0") || !strings.Contains(resp, `"total_num":1`) {
		t.Fatalf("ssid list = %s", resp)
	}
	b, err = os.ReadFile(filepath.Join(SensorTestFileDir, "st_ssid_list_0"))
	if err != nil || !strings.Contains(string(b), "sensor_list") ||
		!strings.Contains(string(b), "group_list") || !strings.Contains(string(b), "rssi_threshold") {
		t.Fatalf("ssid list file = %s err %v", b, err)
	}

	// write class: one keyword, three callback classes (0x4fc2ac/0x4fbf8c/
	// 0x4fc740): add → new_case_id, del/set → ret+err_code
	resp = call("sensor_test_case_list", "add", "add",
		map[string]any{"join_test_sensor": "s1,s2"})
	if !strings.Contains(resp, `"new_case_id":`) || !strings.Contains(resp, `"ret":0`) {
		t.Fatalf("case add = %s", resp)
	}
	resp = call("sensor_test_case_list", "set", "set", map[string]any{"test_case_id": 1})
	if !strings.Contains(resp, `"ret":0`) || !strings.Contains(resp, `"err_code":0`) {
		t.Fatalf("case set = %s", resp)
	}
	resp = call("sensor_test_case_list", "del", "del", map[string]any{"test_case_id": 1})
	if !strings.Contains(resp, `"ret":0`) || !strings.Contains(resp, `"err_code":0`) {
		t.Fatalf("case del = %s", resp)
	}
	var n int
	db.QueryRow(`SELECT COUNT(*) FROM testcase_tbl WHERE test_case_id = 1`).Scan(&n)
	if n != 0 {
		t.Fatalf("del left %d rows", n)
	}
}
