package jcs

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

// Sensor test read handlers backed by sensor.db testcase_tbl (SchemaTable6)
// + bssid_alloc (SchemaTable2).
//
// Evidence (direct from uac binary, this round; registrations from
// sensor_test_init @0x4f8e8c..0x4f8f24 via jcs_callback_register(key,3,cb)):
//   sensor_test_digest        → jcs_sensor_test_get_digest @0x4f3de4
//   sensor_test_summary       → jcs_sensor_test_get_summary_result @0x4f357c
//   sensor_test_summary_new   → jcs_sensor_test_get_summary_result_new @0x4f2920
//   sensor_test_result        → jcs_sensor_test_get_simple_result @0x4f1844
//   sensor_test_detail_result → jcs_sensor_test_get_detail_result @0x4f0c30
//   sensor_test_ssid_list     → jcs_sensor_test_get_ssid_list @0x4f4c80
//
// Response contracts (string refs extracted per function):
//   digest (inline): ret@0x676a24 + total_test_cnt@0x6b4a54 /
//     success_cnt@0x6b453c / fail_cnt@0x6b4554 / slow_cnt@0x6b4548 /
//     sensor_cnt@0x6b4a6c / offline_sensor_cnt@0x6b4a64, all "%d"@0x7011d4.
//   summary (inline): sensor_test_summary@0x6b491c { sch_start_time@0x6b3ef8
//     (%lld@0x6afcf4), brief_result@0x6b4870, brief_result_list@0x6b48bc };
//     request filters test_case_id@0x6b3a1c / test_type@0x6b2d18 /
//     ser_index@0x6b2c44.
//   summary_new (file): per type rows {test_type, sch_start_time,
//     success_cnt, slow_cnt, fail_cnt, result@0x6e7528} under
//     test_type_summary@0x6b4560; file "/tmp/st_summary_result_%d" then
//     resp {file_name, total_num} (@0x6b458c, "w+", 0x6770b4/0x6e1444).
//   result = simple_result (file): rows {start_time@0x711504 %lld, rssi,
//     snr, ssid_name("--"@0x6f4720 default), fail_stage, freq_type,
//     reason, bssid("%.2X-%.2X-..."@0x68baac), ap_name, up_speed,
//     down_speed, relay, "2.4G"@0x693fd4}; file "/tmp/st_simple_result_%d";
//     request {test_case_id, test_type, ser_index, sch_start_time,
//     start, end, sensor_name, result}.
//   detail (file): rows {bssid, test@0x6c7724, diagnosis@0x6b3b94 {
//     startTime@0x6a7bf8 %lld, details@0x6b3ba0 {stage %d, time@0x694304,
//     data@0x6e1bac}}}; file "/tmp/st_detail_result_%d".
//   ssid_list (file): request {start, end}; body {sensor_list@0x6b1700,
//     group_list@0x6b16f4, rssi_threshold@0x6878a0, serv_id@0x676acc %d,
//     ssid_name, ssid_code_type, freqband, encryption};
//     file "/tmp/st_ssid_list_%d".
// The four file-based getters answer {file_name, total_num} only when the
// row count is non-zero (same pattern proven for mesh topology 0x4be0c8).

// SensorTestFileDir is where the vendor drops the result files.
var SensorTestFileDir = "/tmp"

func sensorTestFile(name string, id int64) string {
	return fmt.Sprintf("%s/%s_%d", SensorTestFileDir, name, id)
}

// writeSensorTestFile writes the serialised body (w+ semantics) and builds
// the file_name/total_num response (fields only when count > 0).
func writeSensorTestFile(path string, body []byte, count int) (any, error) {
	if err := os.WriteFile(path, body, 0644); err != nil {
		return jerr(err), nil
	}
	if count <= 0 {
		return ok(), nil
	}
	return map[string]any{"error_code": 0, "file_name": path,
		"total_num": count}, nil
}

// RegisterSensorTestReadHandlers2 installs the digest/summary/result
// query handlers (must run after RegisterBatch3Handlers).
func RegisterSensorTestReadHandlers2(s *Server, db *sql.DB) {
	// digest: ret + six "%d" counters (0x4f3de4)
	s.replaceNotImpl("sensor_test_digest.get", func(json.RawMessage) (any, error) {
		var total, success, fail, slow, offline, sensors int
		db.QueryRow(`SELECT COUNT(*) FROM testcase_tbl`).Scan(&total)
		db.QueryRow(`SELECT COUNT(DISTINCT sensor_id) FROM bssid_alloc`).Scan(&sensors)
		db.QueryRow(
			`SELECT
			   SUM(CASE WHEN status = 1 THEN 1 ELSE 0 END),
			   SUM(CASE WHEN status = 2 THEN 1 ELSE 0 END),
			   SUM(CASE WHEN status NOT IN (1, 2) THEN 1 ELSE 0 END)
			 FROM bssid_alloc`).Scan(&success, &fail, &slow)
		return map[string]any{"error_code": 0, "ret": 0,
			"total_test_cnt":     total,
			"success_cnt":        success,
			"fail_cnt":           fail,
			"slow_cnt":           slow,
			"offline_sensor_cnt": offline,
			"sensor_cnt":         sensors,
		}, nil
	})
	// summary: inline sensor_test_summary wrapper (0x4f357c)
	s.replaceNotImpl("sensor_test_summary.get", func(req json.RawMessage) (any, error) {
		var q struct {
			TestCaseID *int64 `json:"test_case_id"`
		}
		if len(req) > 0 {
			json.Unmarshal(req, &q)
		}
		query := `SELECT b.test_case_id, b.status, b.sensor_id, b.rssi, b.key
			 FROM bssid_alloc b ORDER BY b.test_case_id, b.key`
		args := []any{}
		if q.TestCaseID != nil {
			query = `SELECT b.test_case_id, b.status, b.sensor_id, b.rssi, b.key
				 FROM bssid_alloc b WHERE b.test_case_id = ?
				 ORDER BY b.test_case_id, b.key`
			args = append(args, *q.TestCaseID)
		}
		rows, err := db.Query(query, args...)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		list := []any{}
		var schStart int64
		for rows.Next() {
			var id, status, sid, rssi, key sql.NullInt64
			if err := rows.Scan(&id, &status, &sid, &rssi, &key); err != nil {
				return jerr(err), nil
			}
			if key.Int64 > schStart {
				schStart = key.Int64
			}
			list = append(list, map[string]any{
				"test_case_id": id.Int64, "result": status.Int64,
				"sensor_id": sid.Int64, "rssi": rssi.Int64})
		}
		return map[string]any{"error_code": 0, "ret": 0,
			"sensor_test_summary": map[string]any{
				"sch_start_time":    schStart,
				"brief_result":      map[string]any{"test_case_id": 0},
				"brief_result_list": list,
			}}, nil
	})
	// summary_new: per-type rows → file (0x4f2920)
	s.replaceNotImpl("sensor_test_summary_new.get", func(req json.RawMessage) (any, error) {
		var q struct {
			TestCaseID int64 `json:"test_case_id"`
		}
		if len(req) > 0 {
			json.Unmarshal(req, &q)
		}
		rows, err := db.Query(
			`SELECT t.sch_type, b.status, COUNT(*)
			 FROM bssid_alloc b JOIN testcase_tbl t
			   ON b.test_case_id = t.test_case_id
			 GROUP BY t.sch_type, b.status ORDER BY t.sch_type`)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		per := map[int64]*sensorTypeSummary{}
		var order []int64
		for rows.Next() {
			var typ, status, n sql.NullInt64
			if err := rows.Scan(&typ, &status, &n); err != nil {
				return jerr(err), nil
			}
			r := per[typ.Int64]
			if r == nil {
				r = &sensorTypeSummary{TestType: typ.Int64}
				per[typ.Int64] = r
				order = append(order, typ.Int64)
			}
			switch status.Int64 {
			case 1:
				r.SuccessCnt += n.Int64
			case 2:
				r.FailCnt += n.Int64
			default:
				r.SlowCnt += n.Int64
			}
		}
		list := []any{}
		for _, k := range order {
			list = append(list, per[k].toMap())
		}
		body, _ := json.Marshal(map[string]any{
			"test_type_summary": list})
		return writeSensorTestFile(
			sensorTestFile("st_summary_result", q.TestCaseID), body, len(list))
	})
	// result: simple per-station rows → file (0x4f1844)
	s.replaceNotImpl("sensor_test_result.get", func(req json.RawMessage) (any, error) {
		var q struct {
			TestCaseID int64 `json:"test_case_id"`
			Start      int   `json:"start"`
			End        int   `json:"end"`
		}
		if len(req) > 0 {
			json.Unmarshal(req, &q)
		}
		rows, err := db.Query(
			`SELECT b.bssid, b.status, b.sensor_id, b.rssi, b.serv_id,
			        b.freqband, b.key
			 FROM bssid_alloc b WHERE b.test_case_id = ?
			 ORDER BY b.key`, q.TestCaseID)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		type row struct {
			bssid   string
			status  int64
			sid     int64
			rssi    int64
			serv    int64
			freq    int64
			startTs int64
		}
		var all []row
		for rows.Next() {
			var bssid sql.NullString
			var status, sid, rssi, serv, fb, key sql.NullInt64
			if err := rows.Scan(&bssid, &status, &sid, &rssi, &serv, &fb, &key); err != nil {
				return jerr(err), nil
			}
			all = append(all, row{bssid.String, status.Int64, sid.Int64,
				rssi.Int64, serv.Int64, fb.Int64, key.Int64})
		}
		start, end := q.Start, q.End
		if start > len(all) {
			start = len(all)
		}
		if end <= 0 || end > len(all) {
			end = len(all)
		}
		list := []any{}
		for _, r := range all[start:end] {
			ssidName := "--"
			entry := map[string]any{
				"start_time":   r.startTs,
				"rssi":         r.rssi,
				"snr":          0,
				"ssid_name":    ssidName,
				"fail_stage":   r.status,
				"freq_type":    r.freq,
				"reason":       "",
				"bssid":        sensorMacStr(r.bssid),
				"ap_name":      "",
				"up_speed":     0,
				"down_speed":   0,
				"relay":        0,
				"sensor_id":    r.sid,
				"test_case_id": q.TestCaseID,
			}
			if r.freq <= 14 {
				entry["freq_type"] = "2.4G"
			}
			list = append(list, entry)
		}
		body, _ := json.Marshal(list)
		return writeSensorTestFile(
			sensorTestFile("st_simple_result", q.TestCaseID), body, len(list))
	})
	// detail: per-bssid test/diagnosis rows → file (0x4f0c30)
	s.replaceNotImpl("sensor_test_detail_result.get", func(req json.RawMessage) (any, error) {
		var q struct {
			TestCaseID int64 `json:"test_case_id"`
		}
		if len(req) > 0 {
			json.Unmarshal(req, &q)
		}
		rows, err := db.Query(
			`SELECT b.bssid, b.status, b.rssi, b.key
			 FROM bssid_alloc b WHERE b.test_case_id = ? ORDER BY b.key`, q.TestCaseID)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var bssid sql.NullString
			var status, rssi, key sql.NullInt64
			if err := rows.Scan(&bssid, &status, &rssi, &key); err != nil {
				return jerr(err), nil
			}
			list = append(list, map[string]any{
				"bssid": sensorMacStr(bssid.String),
				"test":  map[string]any{"rssi": rssi.Int64, "status": status.Int64},
				"diagnosis": map[string]any{
					"startTime": key.Int64,
					"details": []any{map[string]any{
						"stage": status.Int64, "time": key.Int64, "data": ""}},
				}})
		}
		body, _ := json.Marshal(list)
		return writeSensorTestFile(
			sensorTestFile("st_detail_result", q.TestCaseID), body, len(list))
	})
	// ssid list: per-case ssid/group/rssi-threshold view → file (0x4f4c80)
	s.replaceNotImpl("sensor_test_ssid_list.get", func(req json.RawMessage) (any, error) {
		var q struct {
			Start int `json:"start"`
			End   int `json:"end"`
		}
		if len(req) > 0 {
			json.Unmarshal(req, &q)
		}
		rows, err := db.Query(
			`SELECT test_case_id, test_case_name, sch_time, rssi_threshold,
			        group_id, ssid_info
			 FROM testcase_tbl ORDER BY key`)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		type row struct {
			id   int64
			name sql.NullString
			tm   sql.NullInt64
			rssi sql.NullInt64
			grp  sql.NullString
			ssid sql.NullString
		}
		var all []row
		for rows.Next() {
			var r row
			var id sql.NullInt64
			if err := rows.Scan(&id, &r.name, &r.tm, &r.rssi, &r.grp, &r.ssid); err != nil {
				return jerr(err), nil
			}
			r.id = id.Int64
			all = append(all, r)
		}
		start, end := q.Start, q.End
		if start > len(all) {
			start = len(all)
		}
		if end <= 0 || end > len(all) {
			end = len(all)
		}
		sensorList := []any{}
		groupList := []any{}
		var servIDs []int64
		rssiThr := int64(0)
		if start < len(all) {
			rssiThr = all[start].rssi.Int64
		}
		for _, r := range all[start:end] {
			sensorList = append(sensorList, map[string]any{
				"serv_id": r.id, "ssid_name": r.name.String,
				"ssid_code_type": 0, "freqband": 0, "encryption": ""})
			if r.grp.String != "" {
				groupList = append(groupList, r.grp.String)
			}
			servIDs = append(servIDs, r.id)
		}
		body, _ := json.Marshal(map[string]any{
			"sensor_list":    sensorList,
			"group_list":     groupList,
			"rssi_threshold": rssiThr,
			"serv_id":        servIDs,
		})
		return writeSensorTestFile(
			sensorTestFile("st_ssid_list", 0), body, len(sensorList))
	})

	// write class: the vendor registers one keyword "sensor_test_case_list"
	// (@0x6b5d7c) three times from sensor_test_init with the callback-class
	// argument selecting the method — 0=add @0x4fc2ac, 1=del @0x4fbf8c,
	// 2=set @0x4fc740 (reads use 3). Response objects carry ret@0x676a24 +
	// err_code@0x6acdec; add answers new_case_id@0x6b70e8 and takes
	// join_test_sensor@0x6b308c; del/set take test_case_id@0x6b3a1c.
	s.replaceNotImpl("sensor_test_case_list.add", func(req json.RawMessage) (any, error) {
		var r struct {
			JoinTestSensor string `json:"join_test_sensor"`
		}
		if len(req) > 0 {
			json.Unmarshal(req, &r)
		}
		res, err := db.Exec(
			`INSERT INTO testcase_tbl(join_test_sensor) VALUES(?)`, r.JoinTestSensor)
		if err != nil {
			return map[string]any{"ret": -1, "err_code": -1}, nil
		}
		id, _ := res.LastInsertId()
		return map[string]any{"ret": 0, "err_code": 0, "new_case_id": id}, nil
	})
	s.replaceNotImpl("sensor_test_case_list.del", func(req json.RawMessage) (any, error) {
		var r struct {
			TestCaseID int64 `json:"test_case_id"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := db.Exec(
			`DELETE FROM testcase_tbl WHERE test_case_id = ?`, r.TestCaseID); err != nil {
			return map[string]any{"ret": -1, "err_code": -1}, nil
		}
		db.Exec(`DELETE FROM bssid_alloc WHERE test_case_id = ?`, r.TestCaseID)
		return map[string]any{"ret": 0, "err_code": 0}, nil
	})
	s.replaceNotImpl("sensor_test_case_list.set", func(req json.RawMessage) (any, error) {
		var r struct {
			TestCaseID int64 `json:"test_case_id"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := db.Exec(
			`UPDATE testcase_tbl SET change_id = change_id + 1
			 WHERE test_case_id = ?`, r.TestCaseID); err != nil {
			return map[string]any{"ret": -1, "err_code": -1}, nil
		}
		return map[string]any{"ret": 0, "err_code": 0}, nil
	})
}

// sensorTypeSummary is one test_type_summary_new row.
type sensorTypeSummary struct {
	TestType   int64 `json:"test_type"`
	SuccessCnt int64 `json:"success_cnt"`
	SlowCnt    int64 `json:"slow_cnt"`
	FailCnt    int64 `json:"fail_cnt"`
	Result     int64 `json:"result"`
}

func (r *sensorTypeSummary) toMap() map[string]any {
	res := int64(1)
	if r.FailCnt > 0 {
		res = 2
	} else if r.SlowCnt > 0 {
		res = 3
	}
	r.Result = res
	return map[string]any{"test_type": r.TestType,
		"sch_start_time": int64(0), "success_cnt": r.SuccessCnt,
		"slow_cnt": r.SlowCnt, "fail_cnt": r.FailCnt, "result": r.Result}
}

// sensorMacStr renders a stored bssid column as the vendor's
// "%.2X-%.2X-%.2X-%.2X-%.2X-%.2X" (mac2str @0x4bb2d8) when parseable;
// verbatim otherwise.
func sensorMacStr(s string) string {
	hex := strings.Map(func(c rune) rune {
		if c == ':' || c == '-' || c == '.' {
			return -1
		}
		return c
	}, s)
	if len(hex) < 12 {
		return s
	}
	var m [6]byte
	for i := 0; i < 6; i++ {
		m[i] = hexPair(hex[i*2], hex[i*2+1])
	}
	return Mac2Str(m)
}
