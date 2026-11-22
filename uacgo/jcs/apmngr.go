package jcs

import (
	"database/sql"
	"encoding/json"
	"fmt"
)

// apmngr JCS semantic layer.
//
// Evidence: apmngr_jcs_reg_callback @0x5546a8 registers exactly these
// (module, method, handler) triples via jcs_callback_register @0x529250,
// which stores the handler at entry+0x10+method*4 — method enum
// {0:add, 1:del, 2:set, 3:get}. Method names follow the ds layer's
// get/set/add/delete verbs.

// Method enum (jcs_callback_register slot index).
const (
	MethodAdd = 0
	MethodDel = 1
	MethodSet = 2
	MethodGet = 3
)

var methodNames = map[int]string{
	MethodAdd: "add", MethodDel: "del", MethodSet: "set", MethodGet: "get",
}

// ApmngrStore is the store surface the apmngr handlers need (implemented by
// *sql.DB over apmngr.db — schemas from store/schemas.go).
type ApmngrStore struct {
	DB *sql.DB
}

// RegisterApmngrHandlers installs the apmngr subsystem's handlers with the
// exact (module, method) pairs of apmngr_jcs_reg_callback @0x5546a8.
func RegisterApmngrHandlers(s *Server, st *ApmngrStore) {
	reg := func(module string, method int, h Handler) {
		s.Register(module+"."+methodNames[method], h)
	}
	// entry lifecycle (over ApEntryCfg_table)
	reg("apmngr_entry", MethodAdd, apmngrEntryAdd(st))
	reg("apmngr_entry", MethodDel, apmngrEntryDel(st))
	reg("apmngr_entry", MethodSet, apmngrEntrySet(st))
	reg("apmngr_entry", MethodGet, apmngrEntryGet(st))
	// groups (over Group_table)
	reg("apmngr_group", MethodAdd, apmngrGroupAdd(st))
	reg("apmngr_group", MethodDel, apmngrGroupDel(st))
	reg("apmngr_group", MethodSet, apmngrGroupSet(st))
	reg("apmngr_group", MethodGet, apmngrGroupGet(st))
	// status reads (over ApEntryRun_table)
	reg("ap_status", MethodGet, apmngrApStatus(st))
	// global/aplog/diagnose setters — payload lands in the config store;
	// semantics per-handler pending (marked NOT-IMPL until reversed).
	for _, m := range []struct{ mod string }{{"apmngr_global"}, {"apmngr_aplog"}, {"diagnose_global"}} {
		mod := m.mod
		reg(mod, MethodSet, notImpl(mod+" set"))
	}
	// remaining registrations (same table; semantics pending reversal)
	for _, m := range []struct {
		mod    string
		method int
	}{
		{"apmngr_entry_backup", MethodGet},
		{"apmngr_entry_copy", MethodSet},
		{"apmngr_entry_authorize", MethodSet},
		{"apmngr_entry_authorize", MethodGet},
		{"apmngr_group_join", MethodSet},
		{"apmngr_firm", MethodSet},
		{"apmngr_online_model", MethodGet},
		{"ap_status_evt", MethodSet},
		{"ap_telnet_status_evt", MethodSet},
		{"ap_status_ssid", MethodGet},
		{"ap_vlan_info", MethodGet},
		{"ap_status_radio_info", MethodGet},
		{"ap_exceed_status", MethodGet},
		{"ac_datasync_status", MethodSet},
		{"apmngr_apdb_info", MethodGet},
	} {
		reg(m.mod, m.method, notImpl(m.mod+" "+methodNames[m.method]))
	}
}

func notImpl(what string) Handler {
	return func(json.RawMessage) (any, error) {
		return nil, fmt.Errorf("not implemented: %s", what)
	}
}

// --- entry handlers over ApEntryCfg_table ---

type entryReq struct {
	EntryID int64  `json:"entry_id"`
	MAC     string `json:"mac"`
	Name    string `json:"entry_name"`
	ModelID int64  `json:"model_id"`
	HWVer   string `json:"hardware_ver"`
	GroupID int64  `json:"group_id"`
}

func apmngrEntryAdd(st *ApmngrStore) Handler {
	return func(req json.RawMessage) (any, error) {
		var r entryReq
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		_, err := st.DB.Exec(
			`INSERT INTO ApEntryCfg_table(entry_id,group_id,mac,entry_name,model_id,hardware_ver)
			 VALUES(?,?,?,?,?,?)`,
			r.EntryID, r.GroupID, r.MAC, r.Name, r.ModelID, r.HWVer)
		if err != nil {
			return map[string]any{"error_code": -1, "error": err.Error()}, nil
		}
		return map[string]any{"error_code": 0}, nil
	}
}

func apmngrEntryDel(st *ApmngrStore) Handler {
	return func(req json.RawMessage) (any, error) {
		var r entryReq
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := st.DB.Exec(
			`DELETE FROM ApEntryCfg_table WHERE entry_id=? OR mac=?`,
			r.EntryID, r.MAC); err != nil {
			return map[string]any{"error_code": -1, "error": err.Error()}, nil
		}
		return map[string]any{"error_code": 0}, nil
	}
}

func apmngrEntrySet(st *ApmngrStore) Handler {
	return func(req json.RawMessage) (any, error) {
		var r entryReq
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		_, err := st.DB.Exec(
			`UPDATE ApEntryCfg_table SET entry_name=?,group_id=? WHERE entry_id=?`,
			r.Name, r.GroupID, r.EntryID)
		if err != nil {
			return map[string]any{"error_code": -1, "error": err.Error()}, nil
		}
		return map[string]any{"error_code": 0}, nil
	}
}

func apmngrEntryGet(st *ApmngrStore) Handler {
	return func(json.RawMessage) (any, error) {
		rows, err := st.DB.Query(
			`SELECT entry_id,group_id,mac,entry_name,model_id,hardware_ver
			 FROM ApEntryCfg_table ORDER BY seq`)
		if err != nil {
			return nil, err
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id, gid, mid int64
			var mac, name, hw string
			if err := rows.Scan(&id, &gid, &mac, &name, &mid, &hw); err != nil {
				return nil, err
			}
			list = append(list, map[string]any{
				"entry_id": id, "group_id": gid, "mac": mac,
				"entry_name": name, "model_id": mid, "hardware_ver": hw})
		}
		return map[string]any{"error_code": 0, "entry_list": list}, rows.Err()
	}
}

// --- group handlers over Group_table ---

func apmngrGroupAdd(st *ApmngrStore) Handler {
	return func(req json.RawMessage) (any, error) {
		var r struct {
			GroupID int64  `json:"group_id"`
			Name    string `json:"name"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := st.DB.Exec(
			`INSERT INTO Group_table(group_id,name) VALUES(?,?)`,
			r.GroupID, r.Name); err != nil {
			return map[string]any{"error_code": -1, "error": err.Error()}, nil
		}
		return map[string]any{"error_code": 0}, nil
	}
}

func apmngrGroupDel(st *ApmngrStore) Handler {
	return func(req json.RawMessage) (any, error) {
		var r struct {
			GroupID int64 `json:"group_id"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := st.DB.Exec(
			`DELETE FROM Group_table WHERE group_id=?`, r.GroupID); err != nil {
			return map[string]any{"error_code": -1, "error": err.Error()}, nil
		}
		return map[string]any{"error_code": 0}, nil
	}
}

func apmngrGroupSet(st *ApmngrStore) Handler {
	return func(req json.RawMessage) (any, error) {
		var r struct {
			GroupID int64  `json:"group_id"`
			Name    string `json:"name"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := st.DB.Exec(
			`UPDATE Group_table SET name=? WHERE group_id=?`, r.Name, r.GroupID); err != nil {
			return map[string]any{"error_code": -1, "error": err.Error()}, nil
		}
		return map[string]any{"error_code": 0}, nil
	}
}

func apmngrGroupGet(st *ApmngrStore) Handler {
	return func(json.RawMessage) (any, error) {
		rows, err := st.DB.Query(`SELECT group_id,name FROM Group_table ORDER BY seq`)
		if err != nil {
			return nil, err
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id int64
			var name string
			if err := rows.Scan(&id, &name); err != nil {
				return nil, err
			}
			list = append(list, map[string]any{"group_id": id, "name": name})
		}
		return map[string]any{"error_code": 0, "group_list": list}, rows.Err()
	}
}

func apmngrApStatus(st *ApmngrStore) Handler {
	return func(json.RawMessage) (any, error) {
		rows, err := st.DB.Query(
			`SELECT entry_id,ap_role,software_ver,status,errno FROM ApEntryRun_table ORDER BY seq`)
		if err != nil {
			return nil, err
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id, status, errno int64
			var role, ver sql.NullString
			if err := rows.Scan(&id, &role, &ver, &status, &errno); err != nil {
				return nil, err
			}
			list = append(list, map[string]any{
				"entry_id": id, "ap_role": role.String, "software_ver": ver.String,
				"status": status, "errno": errno})
		}
		return map[string]any{"error_code": 0, "status_list": list}, rows.Err()
	}
}

func ok() map[string]any { return map[string]any{"error_code": 0} }

func jerr(err error) map[string]any {
	return map[string]any{"error_code": -1, "error": err.Error()}
}
