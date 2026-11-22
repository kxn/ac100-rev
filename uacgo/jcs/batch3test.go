package jcs

import (
	"database/sql"
	"encoding/json"
)

// Sensor test read handlers backed by sensor.db testcase_tbl
// (schema from _sensor_test_sqlite_create_table_test_case).

// RegisterSensorTestReadHandlers replaces the not-impl placeholders for the
// sensor test read queries. Must run after RegisterBatch3Handlers.
func RegisterSensorTestReadHandlers(s *Server, db *sql.DB) {
	s.replaceNotImpl("sensor_test_case_list.get", func(req json.RawMessage) (any, error) {
		rows, err := db.Query(
			`SELECT test_case_id, test_case_name, sch_type, sch_period, sch_time,
			        change_id, rssi_threshold, group_id, join_test_sensor, ssid_info, service
			 FROM testcase_tbl ORDER BY key`)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id, stype, period, stime, cid, rssi sql.NullInt64
			var name sql.NullString
			var gid, joinSensor, ssidInfo, service sql.NullString
			if err := rows.Scan(&id, &name, &stype, &period, &stime, &cid, &rssi, &gid, &joinSensor, &ssidInfo, &service); err != nil {
				return jerr(err), nil
			}
			list = append(list, map[string]any{
				"test_case_id": id.Int64, "test_case_name": name.String,
				"sch_type": stype.Int64, "sch_period": period.Int64,
				"sch_time": stime.Int64, "change_id": cid.Int64,
				"rssi_threshold": rssi.Int64, "group_id": gid.String,
				"join_test_sensor": joinSensor.String, "ssid_info": ssidInfo.String,
				"service": service.String,
			})
		}
		return map[string]any{"error_code": 0, "test_case_list": list}, rows.Err()
	})
}
