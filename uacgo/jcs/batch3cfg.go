package jcs

import (
	"database/sql"
	"encoding/json"
)

// Store-backed implementations for the mesh/rrm/lldp config handlers,
// keyed per notes §24 (extracted parameter key sets). Values persist in a
// syscfg KV table on the subsystem's own database.
//
//   - mesh_jcs_global_set: enable/backhaul_ssid/backhaul_key/backhaul_token/
//     bh_work_mode/re_auto_switch/re_recover_flag/web_password/
//     mesh_delete_all_sub_dev
//   - _rrm_jcs_rrm_para_set: autorrm_enable/autorrm_date/autorrm_time/
//     bw_2g/bw_5g/chnl_enable/freq_enable/chnl_2g_set/chnl_5g1_set/
//     chnl_5g2_set  (+ _rrm_jcs_rrm_state_get reads "state")
//   - _uac_lldp_jcs_set: lldp config persisted; get returns it with cnt=1

// EnsureSyscfg creates the KV table.
func EnsureSyscfg(db *sql.DB) error {
	_, err := db.Exec(
		`CREATE TABLE IF NOT EXISTS syscfg(
		   k TEXT PRIMARY KEY, v TEXT)`)
	return err
}

func syscfgSet(db *sql.DB, k string, v any) error {
	b, err := json.Marshal(v)
	if err != nil {
		return err
	}
	if _, err := db.Exec(
		`INSERT INTO syscfg(k,v) VALUES(?,?)
		 ON CONFLICT(k) DO UPDATE SET v=excluded.v`, k, string(b)); err != nil {
		return err
	}
	return nil
}

func syscfgGet(db *sql.DB, k string, out any) (bool, error) {
	var s string
	err := db.QueryRow(`SELECT v FROM syscfg WHERE k=?`, k).Scan(&s)
	if err == sql.ErrNoRows {
		return false, nil
	}
	if err != nil {
		return false, err
	}
	return true, json.Unmarshal([]byte(s), out)
}

// replaceNotImpl swaps a not-impl registration for a real handler
// (re-registering overwrites the map entry).
func (s *Server) replaceNotImpl(key string, h Handler) { s.Register(key, h) }

// RegisterMeshGlobalHandler implements mesh_jcs_global_set per §24 keys.
func RegisterMeshGlobalHandler(s *Server, db *sql.DB) {
	if err := EnsureSyscfg(db); err != nil {
		return
	}
	s.replaceNotImpl("ac_mesh_global_settings.set", func(req json.RawMessage) (any, error) {
		var cfg map[string]any
		if err := json.Unmarshal(req, &cfg); err != nil {
			return nil, err
		}
		if err := syscfgSet(db, "mesh_global", cfg); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.replaceNotImpl("ac_mesh_global_settings.get", func(json.RawMessage) (any, error) {
		var cfg map[string]any
		found, err := syscfgGet(db, "mesh_global", &cfg)
		if err != nil {
			return jerr(err), nil
		}
		if !found {
			cfg = map[string]any{}
		}
		return map[string]any{"error_code": 0, "settings": cfg}, nil
	})
}

// RegisterRRMHandlers implements ac_rrmpara.set (para keys per §24) and
// ac_rrm_state.get (state stored under "rrm_state").
func RegisterRRMHandlers(s *Server, db *sql.DB) {
	if err := EnsureSyscfg(db); err != nil {
		return
	}
	s.replaceNotImpl("ac_rrmpara.set", func(req json.RawMessage) (any, error) {
		var cfg map[string]any
		if err := json.Unmarshal(req, &cfg); err != nil {
			return nil, err
		}
		if err := syscfgSet(db, "rrm_para", cfg); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.replaceNotImpl("ac_rrmpara.get", func(json.RawMessage) (any, error) {
		var cfg map[string]any
		found, err := syscfgGet(db, "rrm_para", &cfg)
		if err != nil {
			return jerr(err), nil
		}
		if !found {
			cfg = map[string]any{}
		}
		return map[string]any{"error_code": 0, "para": cfg}, nil
	})
	s.replaceNotImpl("ac_rrm_state.get", func(json.RawMessage) (any, error) {
		var st string
		found, err := syscfgGet(db, "rrm_state", &st)
		if err != nil {
			return jerr(err), nil
		}
		if !found {
			st = "0"
		}
		return map[string]any{"error_code": 0, "state": st}, nil
	})
}

// RegisterLLDPHandlers implements uac_lldp set (config persisted) and
// get (config + cnt per the get handler's list shape).
func RegisterLLDPHandlers(s *Server, db *sql.DB) {
	if err := EnsureSyscfg(db); err != nil {
		return
	}
	s.replaceNotImpl("uac_lldp.set", func(req json.RawMessage) (any, error) {
		var cfg map[string]any
		if err := json.Unmarshal(req, &cfg); err != nil {
			return nil, err
		}
		if err := syscfgSet(db, "lldp", cfg); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.replaceNotImpl("uac_lldp.get", func(json.RawMessage) (any, error) {
		var cfg map[string]any
		found, err := syscfgGet(db, "lldp", &cfg)
		if err != nil {
			return jerr(err), nil
		}
		if !found {
			cfg = map[string]any{}
		}
		return map[string]any{"error_code": 0, "cnt": 1, "lldp": cfg}, nil
	})
}
