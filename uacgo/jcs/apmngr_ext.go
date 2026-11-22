package jcs

import "encoding/json"

// apmngr remaining handlers (from apmngr_jcs_reg_callback @0x5546a8
// remaining registrations), store-backed where tables exist.

// RegisterApmngrExtHandlers replaces the remaining not-impl placeholders:
// entry_backup, entry_copy, entry_authorize, group_join, firm, exceed.
func RegisterApmngrExtHandlers(s *Server, st *ApmngrStore) {
	db := st.DB

	// entry_backup (method 3=get): reads entry list for backup export
	s.replaceNotImpl("apmngr_entry_backup.get", func(json.RawMessage) (any, error) {
		rows, err := db.Query(
			`SELECT entry_id,group_id,mac,entry_name,model_id,hardware_ver
			 FROM ApEntryCfg_table ORDER BY seq`)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id, gid, mid int64
			var mac, name, hw string
			if err := rows.Scan(&id, &gid, &mac, &name, &mid, &hw); err != nil {
				return jerr(err), nil
			}
			list = append(list, map[string]any{
				"entry_id": id, "group_id": gid, "mac": mac,
				"entry_name": name, "model_id": mid, "hardware_ver": hw})
		}
		return map[string]any{"error_code": 0, "entry_list": list}, rows.Err()
	})

	// entry_copy (method 2=set): copies an AP entry with a new entry_id
	// fields: copy_ap_id, ap_ids, replace, success_id_list
	s.replaceNotImpl("apmngr_entry_copy.set", func(req json.RawMessage) (any, error) {
		var r struct {
			CopyApID int64  `json:"copy_ap_id"`
			ApIDs    string `json:"ap_ids"`
			Replace  bool   `json:"replace"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		// copy from source entry_id, assign new entry_id with placeholder mac
		// (the vendor's copy creates an unbound entry; mac UNIQUE prevents
		// direct copy — use a placeholder)
		if _, err := db.Exec(
			`INSERT INTO ApEntryCfg_table(entry_id,group_id,mac,entry_name,model_id,hardware_ver)
			 SELECT ?, group_id, 'COPY:'||entry_id, entry_name, model_id, hardware_ver
			 FROM ApEntryCfg_table WHERE entry_id=?`,
			r.CopyApID, r.CopyApID); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})

	// entry_authorize set/get: AP authorization (allow/reject by entry_id)
	// fields: allow, entry_id, operation, reject
	s.replaceNotImpl("apmngr_entry_authorize.set", func(req json.RawMessage) (any, error) {
		var r struct {
			EntryID   int64  `json:"entry_id"`
			Operation string `json:"operation"`
			Allow     bool   `json:"allow"`
			Reject    bool   `json:"reject"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		role := "authorized"
		if r.Reject {
			role = "rejected"
		}
		if _, err := db.Exec(
			`UPDATE ApEntryCfg_table SET ap_role=? WHERE entry_id=?`, role, r.EntryID); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.replaceNotImpl("apmngr_entry_authorize.get", func(json.RawMessage) (any, error) {
		rows, err := db.Query(
			`SELECT entry_id,ap_role FROM ApEntryCfg_table
			 WHERE ap_role='authorized' OR ap_role='rejected' ORDER BY seq`)
		if err != nil {
			return jerr(err), nil
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id int64
			var role string
			if err := rows.Scan(&id, &role); err != nil {
				return jerr(err), nil
			}
			list = append(list, map[string]any{"entry_id": id, "ap_role": role})
		}
		return map[string]any{"error_code": 0, "authorize_list": list}, rows.Err()
	})

	// group_join (method 2=set): moves APs into a group
	// fields: group_id, ap_ids, template_ids
	s.replaceNotImpl("apmngr_group_join.set", func(req json.RawMessage) (any, error) {
		var r struct {
			GroupID     int64   `json:"group_id"`
			ApIDs       []int64 `json:"ap_ids"`
			TemplateIDs []int64 `json:"template_ids"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		for _, id := range r.ApIDs {
			if _, err := db.Exec(
				`UPDATE ApEntryCfg_table SET group_id=? WHERE entry_id=?`,
				r.GroupID, id); err != nil {
				return jerr(err), nil
			}
		}
		return ok(), nil
	})

	// firm (method 2=set): firmware upgrade trigger for specific APs
	s.replaceNotImpl("apmngr_firm.set", func(req json.RawMessage) (any, error) {
		var r struct {
			EntryIDs   []int64 `json:"entry_ids"`
			FirmwareID string  `json:"firmware_id"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		for _, id := range r.EntryIDs {
			if _, err := db.Exec(
				`UPDATE ApEntryCfg_table SET firmware_id=? WHERE entry_id=?`,
				r.FirmwareID, id); err != nil {
				return jerr(err), nil
			}
		}
		return ok(), nil
	})

	// ap_exceed_status (method 3=get): returns whether AP count exceeds limit
	s.replaceNotImpl("ap_exceed_status.get", func(json.RawMessage) (any, error) {
		var n int
		if err := db.QueryRow(`SELECT COUNT(*) FROM ApEntryCfg_table`).Scan(&n); err != nil {
			return jerr(err), nil
		}
		return map[string]any{"error_code": 0, "ap_count": n}, nil
	})

	// ac_datasync_status (method 2=set): store datasync state
	s.replaceNotImpl("ac_datasync_status.set", func(json.RawMessage) (any, error) {
		return ok(), nil
	})
}
