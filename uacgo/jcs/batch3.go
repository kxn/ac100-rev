package jcs

import (
	"database/sql"
	"encoding/json"
)

// Batch-3 subsystem registrations (evidence table in
// re/notes/00-architecture.md §23). Store-backed where a schema exists:
// wips whitelist over sensor.db whitelist_table, sensor test cases over
// sensor.db test-case table (SchemaTable6). Others register with explicit
// not-impl markers until their semantics are reversed.

// Batch3Stores carries the SQL handles for the store-backed handlers.
type Batch3Stores struct {
	SensorDB *sql.DB // sensor.db
}

// RegisterBatch3Handlers installs the five subsystems' registrations.
func RegisterBatch3Handlers(s *Server, st *Batch3Stores) {
	// ---- balance ----
	s.Register("ac_balance.set", notImpl("ac_balance set"))
	// ---- rrm ----
	s.Register("ac_rrm_state.get", notImpl("ac_rrm_state get"))
	s.Register("ac_rrmpara.get", notImpl("ac_rrmpara get"))
	s.Register("ac_mesh_global_settings.get", notImpl("ac_mesh_global_settings get"))
	s.Register("ac_rrmpara.set", notImpl("ac_rrmpara set"))
	s.Register("ac_manualrrm.set", notImpl("ac_manualrrm set"))
	// ---- lldp ----
	s.Register("uac_lldp.set", notImpl("uac_lldp set"))
	s.Register("uac_lldp.get", notImpl("uac_lldp get"))
	// ---- mesh ----
	for _, r := range []struct{ k, what string }{
		{"ac_mesh_global_settings.set", "mesh global set"},
		{"ac_mesh_trigger_discover.set", "mesh trigger discover"},
		{"ac_mesh_stop_discover.set", "mesh stop discover"},
		{"ac_mesh_discover_status.get", "mesh discover status"},
		{"ac_mesh_discover_list.get", "mesh discover list"},
		{"ac_mesh_trigger_pair_all.set", "mesh pair all"},
		{"ac_mesh_trigger_pair.set", "mesh pair"},
		{"ac_mesh_topology.get", "mesh topology"},
		{"ac_mesh_wan_status.set", "mesh wan status"},
	} {
		s.Register(r.k, notImpl(r.what))
	}
	// ---- sensor (di / mngt / test) ----
	for _, r := range []struct{ k, what string }{
		{"set_deep_inspection_setting.set", "di setting set"},
		{"get_deep_inspection_setting.get", "di setting get"},
		{"deep_inspection_status.get", "di status"},
		{"deep_inspection_chnl_usage_list.get", "di chnl usage"},
		{"deep_inspection_multi_chnl_rssi.get", "di multi chnl rssi"},
		{"deep_inspection_multi_chnl_density.get", "di multi chnl density"},
		{"deep_checkup_pkt_ssid_list.get", "checkup ssid list"},
		{"deep_checkup_pkt_bssid_list.get", "checkup bssid list"},
		{"deep_checkup_pkt_sta_list.get", "checkup sta list"},
		{"sensor_global.set", "sensor global set"},
		{"sensor_discover_trigger.set", "sensor discover trigger"},
		{"sensor_list_added.get", "sensor list added"},
		{"sensor_manage_status.get", "sensor manage status"},
		{"sensor_test_ssid_list.get", "test ssid list"},
		{"sensor_test_digest.get", "test digest"},
		{"sensor_test_summary.get", "test summary"},
		{"sensor_test_summary_new.get", "test summary new"},
		{"sensor_test_result.get", "test result"},
		{"sensor_test_detail_result.get", "test detail result"},
	} {
		s.Register(r.k, notImpl(r.what))
	}
	if st != nil && st.SensorDB != nil {
		regSensorTestCase(s, st.SensorDB)
	}
	// ---- wips ----
	if st != nil && st.SensorDB != nil {
		regWipsWhitelist(s, st.SensorDB)
	} else {
		s.Register("whitelist.get", notImpl("whitelist get"))
		s.Register("whitelist.add", notImpl("whitelist add"))
		s.Register("whitelist.del", notImpl("whitelist delete"))
	}
	s.Register("wips_event_info.get", notImpl("wips event info get"))
	s.Register("wips_event_info.set", notImpl("wips event info set"))
	s.Register("wips_event_detail.get", notImpl("wips event detail get"))
	s.Register("wips_statistics.get", notImpl("wips statistics get"))
	s.Register("wips_statistics_num.get", notImpl("wips statistics num get"))
}

// regSensorTestCase wires sensor_test_case_list set/add/del over the
// test-case table (SchemaTable6: test_case_id/name/sch_type/sch_period/
// sch_time/change_id/rssi_threshold/group_id/join_test_sensor/ssid_info/service).
func regSensorTestCase(s *Server, db *sql.DB) {
	s.Register("sensor_test_case_list.set", func(req json.RawMessage) (any, error) {
		var r struct {
			ID   int64  `json:"test_case_id"`
			Name string `json:"test_case_name"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := db.Exec(
			`UPDATE testcase_tbl SET test_case_name=? WHERE test_case_id=?`,
			r.Name, r.ID); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.Register("sensor_test_case_list.add", func(req json.RawMessage) (any, error) {
		var r struct {
			ID   int64  `json:"test_case_id"`
			Name string `json:"test_case_name"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := db.Exec(
			`INSERT INTO testcase_tbl(test_case_id,test_case_name) VALUES(?,?)`,
			r.ID, r.Name); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.Register("sensor_test_case_list.del", func(req json.RawMessage) (any, error) {
		var r struct {
			ID int64 `json:"test_case_id"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := db.Exec(
			`DELETE FROM testcase_tbl WHERE test_case_id=?`, r.ID); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
}

// regWipsWhitelist wires whitelist get/add/del over whitelist_table
// (whitelist_id, mac, ssid, ssid_encode, sensor_id, rssi,
// last_discover_time, operation_time + index).
func regWipsWhitelist(s *Server, db *sql.DB) {
	if _, err := db.Exec(
		`CREATE TABLE IF NOT EXISTS whitelist_table(
		   whitelist_id INTEGER, mac VARCHAR(17), ssid VARCHAR(128),
		   ssid_encode INTEGER, sensor_id INTEGER, rssi INTEGER,
		   last_discover_time INTEGER, operation_time INTEGER);
		 CREATE INDEX IF NOT EXISTS whitelist_table_whitelist_id
		   ON whitelist_table (whitelist_id)`); err != nil {
		return
	}
	s.Register("whitelist.add", func(req json.RawMessage) (any, error) {
		var r struct {
			ID  int64  `json:"whitelist_id"`
			MAC string `json:"mac"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := db.Exec(
			`INSERT INTO whitelist_table(whitelist_id,mac) VALUES(?,?)`,
			r.ID, r.MAC); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.Register("whitelist.del", func(req json.RawMessage) (any, error) {
		var r struct {
			MAC string `json:"mac"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := db.Exec(
			`DELETE FROM whitelist_table WHERE mac=?`, r.MAC); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.Register("whitelist.get", func(json.RawMessage) (any, error) {
		rows, err := db.Query(
			`SELECT whitelist_id,mac FROM whitelist_table ORDER BY whitelist_id`)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id int64
			var mac string
			if err := rows.Scan(&id, &mac); err != nil {
				return jerr(err), nil
			}
			list = append(list, map[string]any{"whitelist_id": id, "mac": mac})
		}
		return map[string]any{"error_code": 0, "whitelist": list}, nil
	})
}
