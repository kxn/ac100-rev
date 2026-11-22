package jcs

import (
	"database/sql"
	"encoding/json"
)

// apmngr read handlers backed by apmngr.db
// (registrations per apmngr_jcs_reg_callback @0x5546a8; note §18).

// RegisterApmngrReadHandlers installs the read-side handlers that replace
// not-impl placeholders registered by RegisterApmngrHandlers.
// Must run after RegisterApmngrHandlers (overwrite map entries).
func RegisterApmngrReadHandlers(s *Server, db *sql.DB, modelList []any) {
	registerAPStatusSSID(s, db)
	registerAPVlanInfo(s, db)
	registerAPRadioInfo(s, db)
	registerAPExceedStatus(s, db)
	registerOnlineModel(s, db, modelList)
}

func registerAPStatusSSID(s *Server, db *sql.DB) {
	s.replaceNotImpl("ap_status_ssid.get", func(json.RawMessage) (any, error) {
		rows, err := db.Query(
			`SELECT entry_id,entry_name FROM ApEntryCfg_table ORDER BY seq`)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id int64
			var name string
			if err := rows.Scan(&id, &name); err != nil {
				return jerr(err), nil
			}
			list = append(list, map[string]any{"entry_id": id, "entry_name": name})
		}
		return map[string]any{"error_code": 0, "ssid_list": list}, nil
	})
}

func registerAPVlanInfo(s *Server, db *sql.DB) {
	s.replaceNotImpl("ap_vlan_info.get", func(json.RawMessage) (any, error) {
		rows, err := db.Query(
			`SELECT entry_id,phy_wire_vlan_1,phy_wire_vlan_2 FROM ApEntryCfg_table ORDER BY seq`)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id, v1, v2 int64
			if err := rows.Scan(&id, &v1, &v2); err != nil {
				return jerr(err), nil
			}
			list = append(list, map[string]any{"entry_id": id, "vlan_1": v1, "vlan_2": v2})
		}
		return map[string]any{"error_code": 0, "vlan_list": list}, nil
	})
}

func registerAPRadioInfo(s *Server, db *sql.DB) {
	s.replaceNotImpl("ap_status_radio_info.get", func(json.RawMessage) (any, error) {
		rows, err := db.Query(
			`SELECT entry_id,model_id,hardware_ver FROM ApEntryCfg_table ORDER BY seq`)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id, mid int64
			var hw string
			if err := rows.Scan(&id, &mid, &hw); err != nil {
				return jerr(err), nil
			}
			list = append(list, map[string]any{"entry_id": id, "model_id": mid, "hardware_ver": hw})
		}
		return map[string]any{"error_code": 0, "radio_info_list": list}, nil
	})
}

func registerAPExceedStatus(s *Server, db *sql.DB) {
	s.replaceNotImpl("ap_exceed_status.get", func(json.RawMessage) (any, error) {
		var n int
		if err := db.QueryRow(`SELECT COUNT(*) FROM ApEntryCfg_table`).Scan(&n); err != nil {
			return jerr(err), nil
		}
		return map[string]any{"error_code": 0, "ap_count": n}, nil
	})
}

func registerOnlineModel(s *Server, db *sql.DB, modelList []any) {
	s.replaceNotImpl("apmngr_online_model.get", func(json.RawMessage) (any, error) {
		if modelList == nil {
			modelList = []any{}
		}
		return map[string]any{"error_code": 0, "model_list": modelList}, nil
	})
}

// RegisterApmngrJCS is the one-call entry for the daemon: registers all
// apmngr JCS handlers (set/del/get + read) on a single server.
func RegisterApmngrJCS(s *Server, db *sql.DB, modelList []any) {
	RegisterApmngrHandlers(s, &ApmngrStore{DB: db})
	RegisterApmngrReadHandlers(s, db, modelList)
}
