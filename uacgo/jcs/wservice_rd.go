package jcs

import (
	"database/sql"
	"encoding/json"
)

// Radio-binding (bind_tbl) and rdmngr/wportal registrations.
//
// Evidence:
//   - _uac_wserv_jcs_rd_op @0x5d9db4 params: radio_id/serv_id/vlan_id —
//     the "wservice get" path with a radio_id returns that radio's binds
//     (wserv_rd.db bind_tbl: radio_id, wserv1..8, vlan1..8).
//   - uac_rdmngr_jcs_register @0x62f024: "rf_mngr" set(2)/get(3),
//     "rf_mngr_entry" get(3), "backup_rf_mngr_entry" get(3),
//     "rdmngr_datasync" set(2) — over rdmngr.db rdmngrTable.
//   - wportal_init @0x4263f0: "wportal" add/del/set/get,
//     "wportal_backup" get, "wportal_nsa_sync" set (portal.db — pending,
//     registered as not-impl).

// rfRow is the rf table subset row (fields mirror store.RdmngrRow).
type rfRow struct {
	RfID       int64 `json:"rf_id"`
	FreqBand   int64 `json:"freq_band"`
	Mode       int64 `json:"mode"`
	Bandwidth  int64 `json:"bandwidth"`
	Channel    int64 `json:"channel"`
	PowerLevel int64 `json:"power_level"`
}

// BindSet installs one radio's binding row (radio_id + wserv1..8/vlan1..8).
func (st *WservStore) BindSet(radioID int64, wserv, vlan [8]int64) error {
	res, err := st.DB.Exec(
		`UPDATE bind_tbl SET wserv1=?,vlan1=?,wserv2=?,vlan2=?,wserv3=?,vlan3=?,
		   wserv4=?,vlan4=?,wserv5=?,vlan5=?,wserv6=?,vlan6=?,wserv7=?,vlan7=?,
		   wserv8=?,vlan8=? WHERE radio_id=?`,
		wserv[0], vlan[0], wserv[1], vlan[1], wserv[2], vlan[2], wserv[3], vlan[3],
		wserv[4], vlan[4], wserv[5], vlan[5], wserv[6], vlan[6], wserv[7], vlan[7],
		radioID)
	if err != nil {
		return err
	}
	if n, _ := res.RowsAffected(); n > 0 {
		return nil
	}
	_, err = st.DB.Exec(
		`INSERT INTO bind_tbl(radio_id,wserv1,vlan1,wserv2,vlan2,wserv3,vlan3,
		   wserv4,vlan4,wserv5,vlan5,wserv6,vlan6,wserv7,vlan7,wserv8,vlan8)
		 VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)`,
		append([]any{radioID}, bindArgs(wserv, vlan)...)...)
	return err
}

func bindArgs(wserv, vlan [8]int64) []any {
	out := make([]any, 0, 16)
	for i := 0; i < 8; i++ {
		out = append(out, wserv[i], vlan[i])
	}
	return out
}

// BindRow mirrors one wserv_rd.db bind_tbl row (schema from
// _wserv_sqlite_try_create_tbl).
type BindRow struct {
	RadioID int64
	Wserv   [8]int64
	Vlan    [8]int64
}

// BindRows lists all radio-SSID bindings.
func (st *WservStore) BindRows() ([]BindRow, error) {
	rows, err := st.DB.Query(
		`SELECT radio_id,wserv1,vlan1,wserv2,vlan2,wserv3,vlan3,wserv4,vlan4,
		        wserv5,vlan5,wserv6,vlan6,wserv7,vlan7,wserv8,vlan8
		 FROM bind_tbl ORDER BY radio_id`)
	if err != nil {
		return nil, err
	}
	defer rows.Close()
	var out []BindRow
	for rows.Next() {
		var r BindRow
		var w, v [8]sql.NullInt64
		dest := []any{&r.RadioID,
			&w[0], &v[0], &w[1], &v[1], &w[2], &v[2], &w[3], &v[3],
			&w[4], &v[4], &w[5], &v[5], &w[6], &v[6], &w[7], &v[7]}
		if err := rows.Scan(dest...); err != nil {
			return nil, err
		}
		for i := 0; i < 8; i++ {
			if w[i].Valid {
				r.Wserv[i] = w[i].Int64
			}
			if v[i].Valid {
				r.Vlan[i] = v[i].Int64
			}
		}
		out = append(out, r)
	}
	return out, rows.Err()
}

// BindRowsOf returns the binds of one radio.
func (st *WservStore) BindRowsOf(radioID int64) ([]BindRow, error) {
	rows, err := st.BindRows()
	if err != nil {
		return nil, err
	}
	var out []BindRow
	for _, r := range rows {
		if r.RadioID == radioID {
			out = append(out, r)
		}
	}
	return out, nil
}

// RdmngrStore is the rdmngr.db surface (rdmngrTable).
type RdmngrStore struct {
	DB *sql.DB
}

// SetRF upserts one rf row (subset columns; full row in SchemaTable5).
func (st *RdmngrStore) SetRF(r rfRow) error {
	res, err := st.DB.Exec(
		`UPDATE rdmngrTable SET freq_band=?,mode=?,bandwidth=?,channel=?,power_level=?
		 WHERE rf_id=?`,
		r.FreqBand, r.Mode, r.Bandwidth, r.Channel, r.PowerLevel, r.RfID)
	if err != nil {
		return err
	}
	if n, _ := res.RowsAffected(); n > 0 {
		return nil
	}
	_, err = st.DB.Exec(
		`INSERT INTO rdmngrTable(rf_id,freq_band,mode,bandwidth,channel,power_level)
		 VALUES(?,?,?,?,?,?)`,
		r.RfID, r.FreqBand, r.Mode, r.Bandwidth, r.Channel, r.PowerLevel)
	return err
}

// GetRF lists rf rows.
func (st *RdmngrStore) GetRF() ([]map[string]any, error) {
	rows, err := st.DB.Query(
		`SELECT rf_id,freq_band,mode,bandwidth,channel,power_level
		 FROM rdmngrTable ORDER BY rf_id`)
	if err != nil {
		return nil, err
	}
	defer rows.Close()
	out := []map[string]any{}
	for rows.Next() {
		var rf, fb, m, bw, ch, pw int64
		if err := rows.Scan(&rf, &fb, &m, &bw, &ch, &pw); err != nil {
			return nil, err
		}
		out = append(out, map[string]any{
			"rf_id": rf, "freq_band": fb, "mode": m,
			"bandwidth": bw, "channel": ch, "power_level": pw})
	}
	return out, rows.Err()
}

// RegisterRdmngrHandlers wires "rf_mngr" set/get and the entry read
// (uac_rdmngr_jcs_register @0x62f024); backup/datasync marked not-impl.
func RegisterRdmngrHandlers(s *Server, st *RdmngrStore) {
	s.Register("rf_mngr.set", func(req json.RawMessage) (any, error) {
		var r rfRow
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if err := st.SetRF(r); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.Register("rf_mngr.get", func(json.RawMessage) (any, error) {
		list, err := st.GetRF()
		if err != nil {
			return jerr(err), nil
		}
		return map[string]any{"error_code": 0, "rf_list": list}, nil
	})
	s.Register("rf_mngr_entry.get", func(req json.RawMessage) (any, error) {
		var q struct {
			RfID int64 `json:"rf_id"`
		}
		if len(req) > 0 {
			_ = json.Unmarshal(req, &q)
		}
		list, err := st.GetRF()
		if err != nil {
			return jerr(err), nil
		}
		if q.RfID > 0 {
			for _, m := range list {
				if m["rf_id"] == q.RfID {
					return map[string]any{"error_code": 0, "rf_entry": []any{m}}, nil
				}
			}
			return map[string]any{"error_code": 0, "rf_entry": []any{}}, nil
		}
		return map[string]any{"error_code": 0, "rf_list": list}, nil
	})
	s.Register("backup_rf_mngr_entry.get", func(json.RawMessage) (any, error) {
		list, err := st.GetRF()
		if err != nil {
			return jerr(err), nil
		}
		return map[string]any{"error_code": 0, "rf_list": list}, nil
	})
	s.Register("rdmngr_datasync.set", func(req json.RawMessage) (any, error) {
		return map[string]any{"error_code": 0}, nil
	})
}
