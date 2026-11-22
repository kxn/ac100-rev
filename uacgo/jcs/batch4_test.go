package jcs

import (
	"database/sql"
	"encoding/json"
	"os"
	"path/filepath"
	"testing"
	"time"

	_ "modernc.org/sqlite"
	"uacgo/store"
)

// Batch-4: apmngr event setters, apdb_info get, the sensor management
// state machine and the wips event set/detail handlers (the last
// not-impl registrations).
func TestBatch4ApmngrEvents(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "apmngr.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	for _, ddl := range []string{store.SchemaApentrycfgTable, store.SchemaApentryrunTable} {
		if _, err := db.Exec(ddl); err != nil {
			t.Fatal(err)
		}
	}
	db.Exec(`INSERT INTO ApEntryCfg_table(entry_id,led,telnet_status,model_id,entry_name,hardware_ver) VALUES(1,1,0,7,'ap1','1.0')`)
	db.Exec(`INSERT INTO ApEntryRun_table(entry_id,led,telnet_status) VALUES(1,1,0)`)

	var rebooted, resetIDs, telnets []int
	var ledOn bool
	hooks := &ApmngrEvtHooks{
		OnReboot:       func(ids []int) { rebooted = ids },
		OnLED:          func(ids []int, on bool) { ledOn = on },
		OnFactoryReset: func(ids []int) { resetIDs = ids },
		OnTelnet:       func(ids []int, on bool) { telnets = ids },
	}
	apdb := func(modelID, firmwareID string) (map[string]any, bool) {
		if modelID == "7" {
			return map[string]any{"model_name": "XAP", "id": "7",
				"radios": map[string]any{"2.4G1": map[string]any{"max_ssid": 8}}}, true
		}
		return nil, false
	}
	s := NewServer()
	RegisterApmngrHandlers(s, &ApmngrStore{DB: db})
	RegisterApmngrEvtHandlers(s, db, hooks, apdb)
	path := filepath.Join(dir, "jcs.service.srv.evt")
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

	// led_on/off: rows updated + hook
	if resp := call("ap_status_evt", "set", "set",
		map[string]any{"entry_id": []int{1}, "evt": "led_on"}); indexOfStr(resp, `"error_code":0`) < 0 {
		t.Fatalf("led_on = %s", resp)
	}
	if !ledOn {
		t.Fatal("led hook")
	}
	call("ap_status_evt", "set", "set", map[string]any{"entry_id": []int{1}, "evt": "led_off"})
	if ledOn {
		t.Fatal("led off hook")
	}
	var led int
	db.QueryRow(`SELECT led FROM ApEntryCfg_table WHERE entry_id=1`).Scan(&led)
	if led != 2 {
		t.Fatalf("cfg led = %d, want 2", led)
	}
	// reboot
	call("ap_status_evt", "set", "set", map[string]any{"entry_id": []int{1}, "evt": "reboot"})
	if len(rebooted) != 1 {
		t.Fatal("reboot hook")
	}
	// telnet on/off
	call("ap_telnet_status_evt", "set", "set", map[string]any{"entry_id": []int{1}, "evt": "on"})
	var tn int
	db.QueryRow(`SELECT telnet_status FROM ApEntryCfg_table WHERE entry_id=1`).Scan(&tn)
	if tn != 1 || len(telnets) != 1 {
		t.Fatalf("telnet = %d %+v", tn, telnets)
	}
	// apdb_info.get: array request → file + total_num
	resp := call("apmngr_apdb_info", "get", "get",
		[]map[string]any{{"model_id": "7", "firmware_id": "fw"}, {"model_id": "9", "firmware_id": ""}})
	var apdbResp struct {
		FileName string `json:"file_name"`
		Total    int    `json:"total_num"`
	}
	if err := json.Unmarshal([]byte(resp), &apdbResp); err != nil ||
		apdbResp.FileName != ApdbInfoListFile || apdbResp.Total != 1 {
		t.Fatalf("apdb info = %s", resp)
	}
	if body, _ := os.ReadFile(ApdbInfoListFile); indexOfStr(string(body), "XAP") < 0 {
		t.Fatalf("apdb file body = %s", body)
	}
	// reset: rows deleted + hook
	call("ap_status_evt", "set", "set", map[string]any{"entry_id": []int{1}, "evt": "reset"})
	if len(resetIDs) != 1 {
		t.Fatal("reset hook")
	}
	var n int
	db.QueryRow(`SELECT COUNT(*) FROM ApEntryCfg_table`).Scan(&n)
	if n != 0 {
		t.Fatalf("cfg rows left = %d", n)
	}
	s.Close()
}

func TestBatch4SensorMngt(t *testing.T) {
	clk := time.Unix(1_700_000_000, 0)
	var added, purged []UnfinishedSensor
	m := NewSensorMngt(SensorMngtHooks{
		OnSensorAdd:   func(s []UnfinishedSensor) { added = s },
		OnSensorPurge: func(s []UnfinishedSensor) { purged = s },
	})
	m.SetNow(func() time.Time { return clk })

	dir := t.TempDir()
	s := NewServer()
	RegisterBatch3Handlers(s, &Batch3Stores{SensorDB: nil})
	RegisterSensorMngtHandlers(s, m)
	path := filepath.Join(dir, "jcs.service.srv.sm")
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

	// begin → scanning with a 600s remaining window
	call("sensor_discover_trigger", "set", "set",
		map[string]any{"action": "begin", "group_list": []string{"1"}})
	resp := call("sensor_manage_status", "get", "get", nil)
	if indexOfStr(resp, "scanning") < 0 || indexOfStr(resp, `"remain_time":"600"`) < 0 {
		t.Fatalf("scanning status = %s", resp)
	}
	// scan_stop
	call("sensor_discover_trigger", "set", "set", map[string]any{"action": "scan_stop"})
	if resp := call("sensor_manage_status", "get", "get", nil); indexOfStr(resp, "scan_stop") < 0 {
		t.Fatalf("scan_stop status = %s", resp)
	}
	// sensor_add registers the sensors
	call("sensor_discover_trigger", "set", "set", map[string]any{
		"action":      "sensor_add",
		"sensor_list": []string{"101", "102"},
	})
	if len(added) != 2 {
		t.Fatal("sensor_add hook")
	}
	m.AddSensors([]UnfinishedSensor{{ApID: "101", MAC: "aa", Name: "s1", TestStatus: "ok"}})
	// list_added is gated on the managed phase (ret -2 outside state 3)
	if resp := call("sensor_list_added", "get", "get", map[string]any{"start": 0, "end": 10}); indexOfStr(resp, `"-2"`) < 0 {
		t.Fatalf("list_added gate = %s", resp)
	}
	// test_begin → backhaul testing; now list_added answers with the file
	call("sensor_discover_trigger", "set", "set", map[string]any{"action": "test_begin"})
	if resp := call("sensor_manage_status", "get", "get", nil); indexOfStr(resp, "backhaul_testing") < 0 {
		t.Fatalf("backhaul status = %s", resp)
	}
	resp = call("sensor_list_added", "get", "get", map[string]any{"start": 0, "end": 10})
	var la struct {
		Ret      string `json:"ret"`
		TotalNum string `json:"total_num"`
		FileName string `json:"file_name"`
	}
	if err := json.Unmarshal([]byte(resp), &la); err != nil || la.Ret != "0" || la.FileName != SensorListAddedFile {
		t.Fatalf("list_added = %s", resp)
	}
	if body, _ := os.ReadFile(SensorListAddedFile); indexOfStr(string(body), "101") < 0 {
		t.Fatalf("list_added body = %s", body)
	}
	// backhaul result → part_failed
	m.SetBackhaulResult(1, 1)
	if resp := call("sensor_manage_status", "get", "get", nil); indexOfStr(resp, "backhaul_test_part_failed") < 0 {
		t.Fatalf("part_failed status = %s", resp)
	}
	// finish without test → ret -1; with failed sensor → purge hook
	m.Trigger("test_begin", nil, nil)
	m.AddSensors([]UnfinishedSensor{{ApID: "103", TestStatus: "failed"}})
	call("sensor_discover_trigger", "set", "set", map[string]any{"action": "finish"})
	if len(purged) != 1 || purged[0].ApID != "103" {
		t.Fatalf("purge = %+v", purged)
	}
	// unknown action → ret -1
	if resp := call("sensor_discover_trigger", "set", "set", map[string]any{"action": "nope"}); indexOfStr(resp, `"ret":"-1"`) < 0 {
		t.Fatalf("bad action = %s", resp)
	}
	s.Close()
}

func TestBatch4WipsEventOps(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "sensor.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	if _, err := db.Exec(store.SchemaWhitelistTable); err != nil {
		t.Fatal(err)
	}
	rs := &RuntimeState{}
	tables := NewRuntimeTables(rs)
	e1 := WipsEvent{ID: tables.NextWipsID(), ThreatClass: 5, DevMAC: "aa:bb:cc:00:00:01", Type: "severe"}
	tables.AddWipsEvent(e1)
	e2 := WipsEvent{ID: tables.NextWipsID(), ThreatClass: 2, DevMAC: "aa:bb:cc:00:00:02"}
	tables.AddWipsEvent(e2)
	tables.AddWipsDetail(1, WipsDetail{DiscoveryTime: "t1", LastTime: "t2", Duration: "5", Rssi: "-60"})
	tables.AddWipsDetail(1, WipsDetail{DiscoveryTime: "t3"})

	var counters, discounters []string
	s := NewServer()
	RegisterBatch3Handlers(s, &Batch3Stores{SensorDB: db})
	tables.RegisterRuntimeQueryHandlers(s)
	RegisterWipsEventHandlers(s, tables, db, &WipsEventOps{
		OnCounter:    func(m []string) { counters = m },
		OnDiscounter: func(m []string) { discounters = m },
	})
	path := filepath.Join(dir, "jcs.service.srv.we")
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

	// counter
	if resp := call("wips_event_info", "set", "set",
		map[string]any{"wips_info_ids": []int{1}, "operation": 1}); indexOfStr(resp, `"ret":0`) < 0 {
		t.Fatalf("counter = %s", resp)
	}
	if len(counters) != 1 {
		t.Fatal("counter hook")
	}
	// discounter
	call("wips_event_info", "set", "set", map[string]any{"wips_info_ids": []int{1}, "operation": 2})
	if len(discounters) != 1 {
		t.Fatal("discounter hook")
	}
	// whitelist: class 5 allowed + persisted
	if resp := call("wips_event_info", "set", "set",
		map[string]any{"wips_info_ids": []int{1}, "operation": 3}); indexOfStr(resp, `"ret":0`) < 0 {
		t.Fatalf("whitelist = %s", resp)
	}
	var wl int
	db.QueryRow(`SELECT COUNT(*) FROM whitelist_table`).Scan(&wl)
	if wl != 1 {
		t.Fatalf("whitelist rows = %d", wl)
	}
	// duplicate → -3
	if resp := call("wips_event_info", "set", "set",
		map[string]any{"wips_info_ids": []int{1}, "operation": 3}); indexOfStr(resp, `"ret":-3`) < 0 {
		t.Fatalf("duplicate = %s", resp)
	}
	// whitelist on class 2 → -1
	if resp := call("wips_event_info", "set", "set",
		map[string]any{"wips_info_ids": []int{2}, "operation": 3}); indexOfStr(resp, `"ret":-1`) < 0 {
		t.Fatalf("class gate = %s", resp)
	}
	// detail paging
	resp := call("wips_event_detail", "get", "get",
		map[string]any{"wips_info_id": 1, "start": 0, "size": 1})
	if indexOfStr(resp, `"count":2`) < 0 || indexOfStr(resp, "t1") < 0 || indexOfStr(resp, "t3") >= 0 {
		t.Fatalf("detail paging = %s", resp)
	}
	// unknown event → ret -1
	if resp := call("wips_event_detail", "get", "get",
		map[string]any{"wips_info_id": 99}); indexOfStr(resp, `"ret":-1`) < 0 {
		t.Fatalf("unknown detail = %s", resp)
	}
	s.Close()
}
