package jcs

import (
	"database/sql"
	"encoding/json"
	"fmt"
)

// wserv JCS semantic layer.
//
// Evidence: uac_wservice_init @0x5e01a0 registers via FUN_004084d0
// (= jcs_callback_register, method enum {0:add,1:del,2:set,3:get}):
//   "wservice"     3 get / 0 add / 1 del / 2 set  → _uac_wserv_jcs_* over
//     wserv_tbl (wserv.db; schema in store/schemas.go)
//   "wservice_ip"  0 add / 1 del / 2 set        → _uac_wserv_ip_jcs_* over
//     igmp_ip_tbl
//   "wserv_global" 2 set                        → global config (pending)

// WservStore is the wserv.db surface.
type WservStore struct {
	DB *sql.DB
}

// RegisterWserviceHandlers installs the wserv subsystem's handlers.
func RegisterWserviceHandlers(s *Server, st *WservStore) {
	reg := func(module string, method int, h Handler) {
		s.Register(module+"."+methodNames[method], h)
	}
	reg("wservice", MethodAdd, wservAdd(st))
	reg("wservice", MethodDel, wservDel(st))
	reg("wservice", MethodSet, wservSet(st))
	reg("wservice", MethodGet, wservGet(st))
	// rd_op path (_uac_wserv_jcs_rd_op @0x5d9db4): params radio_id → binds
	s.Register("wservice.rd_bind", func(req json.RawMessage) (any, error) {
		var r struct {
			RadioID int64 `json:"radio_id"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		rows, err := st.BindRowsOf(r.RadioID)
		if err != nil {
			return jerr(err), nil
		}
		list := []any{}
		for _, b := range rows {
			ws := []any{}
			vl := []any{}
			for i := 0; i < 8; i++ {
				if b.Wserv[i] != 0 {
					ws = append(ws, b.Wserv[i])
					vl = append(vl, b.Vlan[i])
				}
			}
			list = append(list, map[string]any{
				"radio_id": b.RadioID, "serv_id": ws, "vlan_id": vl})
		}
		return map[string]any{"error_code": 0, "bind_list": list}, nil
	})
	s.Register("wservice.rd_bind.set", func(req json.RawMessage) (any, error) {
		var r struct {
			RadioID int64   `json:"radio_id"`
			ServID  []int64 `json:"serv_id"`
			VlanID  []int64 `json:"vlan_id"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		var ws, vl [8]int64
		for i := 0; i < len(r.ServID) && i < 8; i++ {
			ws[i] = r.ServID[i]
		}
		for i := 0; i < len(r.VlanID) && i < 8; i++ {
			vl[i] = r.VlanID[i]
		}
		if err := st.BindSet(r.RadioID, ws, vl); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	reg("wservice_ip", MethodAdd, igmpIPAdd(st))
	reg("wservice_ip", MethodDel, igmpIPDel(st))
	reg("wservice_ip", MethodSet, igmpIPSet(st))
	reg("wserv_global", MethodSet, notImpl("wserv_global set"))
}

type wservReq struct {
	ServID int64          `json:"serv_id"`
	Enable string         `json:"enable"`
	Vlan   int64          `json:"default_bind_vlan"`
	SSID   string         `json:"ssid"`
	Extra  map[string]any `json:"-"`
}

func decodeWserv(req json.RawMessage) (*wservReq, error) {
	var r wservReq
	if err := json.Unmarshal(req, &r); err != nil {
		return nil, err
	}
	return &r, nil
}

func wservAdd(st *WservStore) Handler {
	return func(req json.RawMessage) (any, error) {
		r, err := decodeWserv(req)
		if err != nil {
			return nil, err
		}
		if _, err := st.DB.Exec(
			`INSERT INTO wserv_tbl(serv_id,enable,default_bind_vlan,ssid) VALUES(?,?,?,?)`,
			r.ServID, r.Enable, r.Vlan, r.SSID); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	}
}

func wservDel(st *WservStore) Handler {
	return func(req json.RawMessage) (any, error) {
		r, err := decodeWserv(req)
		if err != nil {
			return nil, err
		}
		if _, err := st.DB.Exec(`DELETE FROM wserv_tbl WHERE serv_id=?`, r.ServID); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	}
}

func wservSet(st *WservStore) Handler {
	return func(req json.RawMessage) (any, error) {
		r, err := decodeWserv(req)
		if err != nil {
			return nil, err
		}
		res, err := st.DB.Exec(
			`UPDATE wserv_tbl SET enable=?,default_bind_vlan=?,ssid=? WHERE serv_id=?`,
			r.Enable, r.Vlan, r.SSID, r.ServID)
		if err != nil {
			return jerr(err), nil
		}
		if n, _ := res.RowsAffected(); n == 0 {
			return jerr(fmt.Errorf("serv_id %d not found", r.ServID)), nil
		}
		return ok(), nil
	}
}

func wservGet(st *WservStore) Handler {
	return func(json.RawMessage) (any, error) {
		rows, err := st.DB.Query(
			`SELECT serv_id,enable,default_bind_vlan,ssid FROM wserv_tbl ORDER BY priv_key`)
		if err != nil {
			return nil, err
		}
		defer rows.Close()
		list := []any{}
		for rows.Next() {
			var id, vlan int64
			var enable, ssid string
			if err := rows.Scan(&id, &enable, &vlan, &ssid); err != nil {
				return nil, err
			}
			list = append(list, map[string]any{
				"serv_id": id, "enable": enable,
				"default_bind_vlan": vlan, "ssid": ssid})
		}
		return map[string]any{"error_code": 0, "wserv_list": list}, rows.Err()
	}
}

type igmpIPReq struct {
	ID     int64  `json:"id"`
	IPAddr string `json:"ip_addr"`
	Relay  int64  `json:"relay"`
	Enable string `json:"enable"`
}

func igmpIPAdd(st *WservStore) Handler {
	return func(req json.RawMessage) (any, error) {
		var r igmpIPReq
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := st.DB.Exec(
			`INSERT OR IGNORE INTO igmp_ip_tbl(id,ip_addr,relay,enable) VALUES(?,?,?,?)`,
			r.ID, r.IPAddr, r.Relay, r.Enable); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	}
}

func igmpIPDel(st *WservStore) Handler {
	return func(req json.RawMessage) (any, error) {
		var r igmpIPReq
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := st.DB.Exec(`DELETE FROM igmp_ip_tbl WHERE id=?`, r.ID); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	}
}

func igmpIPSet(st *WservStore) Handler {
	return func(req json.RawMessage) (any, error) {
		var r igmpIPReq
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		if _, err := st.DB.Exec(
			`UPDATE igmp_ip_tbl SET ip_addr=?,relay=?,enable=? WHERE id=?`,
			r.IPAddr, r.Relay, r.Enable, r.ID); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	}
}
