package jcs

import (
	"database/sql"
	"path/filepath"
	"strings"
	"testing"
	"time"

	_ "modernc.org/sqlite"
)

// sensor_test_case_list.get returns typed rows from testcase_tbl
// (store-backed, schema from store/schemas.go).
func TestSensorTestCaseList(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "sensor.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	tc := "CREATE TABLE IF NOT EXISTS testcase_tbl(test_case_id INTEGER,test_case_name NVARCHAR(33),sch_type INTEGER,sch_period INTEGER,sch_time INTEGER,change_id INTEGER,rssi_threshold INTEGER,group_id TEXT,join_test_sensor TEXT,ssid_info TEXT,service TEXT,key INTEGER PRIMARY KEY AUTOINCREMENT);"
	if _, err := db.Exec(tc); err != nil {
		t.Fatal(err)
	}
	if _, err := db.Exec(
		`INSERT INTO testcase_tbl(test_case_id,test_case_name,sch_type,sch_period,sch_time)
		 VALUES(1,'case-A',1,60,300)`); err != nil {
		t.Fatal(err)
	}

	path := filepath.Join(dir, "jcs.service.srv.sensor")
	s := NewServer()
	RegisterSensorTestReadHandlers(s, db)
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond)

	resp, err := Call(path, "get", "sensor_test_case_list", "get", nil)
	if err != nil {
		t.Fatal(err)
	}
	if !strings.Contains(string(resp), "case-A") {
		t.Fatalf("test case list = %s", resp)
	}
	s.Close()
}
