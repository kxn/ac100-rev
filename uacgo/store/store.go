// Package store implements the SQLite configuration layer of `uac`.
//
// Evidence: the binary opens per-subsystem databases under
// /etc/nouci_config/dbs/ (→ /tmp/etc/nouci_conf/dbs/ at runtime; symbol
// strings: apmngr.db@0x6ccdcc, wserv.db@0x6f82f0, wserv_rd.db@0x6f831c,
// wserv_ip.db@0x6f8340, apdb_nego.db@0x6fc090, rdmngr.db@0x70813c,
// portal.db@0x67d260, auth_server.db@0x67d2e8, mac_auth.db@0x685828,
// dhcpdef_svr.db@0x68f024, dhcpdef_bind.db@0x68f058, arp_defend.db@0x6919ec,
// sensor.db@0x6a8f50, /tmp/apmngr_tmp.db@0x6cce20).
// Table schemas are the binary's own CREATE TABLE strings (schemas.go).
// Driver: modernc.org/sqlite (pure Go — no cgo, per project constraint).
package store

import (
	"database/sql"
	"fmt"
	"os"
	"path/filepath"

	_ "modernc.org/sqlite" // pure-Go driver (no cgo)
)

// DB wraps one SQLite database file.
type DB struct {
	db *sql.DB
}

// Open opens (creating if needed) a SQLite file and applies its schemas.
func Open(path string, schemas ...string) (*DB, error) {
	if err := os.MkdirAll(filepath.Dir(path), 0o755); err != nil {
		return nil, err
	}
	d, err := sql.Open("sqlite", path)
	if err != nil {
		return nil, err
	}
	d.SetMaxOpenConns(1) // uac serialises DB access through worker threads
	for _, s := range schemas {
		if _, err := d.Exec(s); err != nil {
			d.Close()
			return nil, fmt.Errorf("%s: %w", filepath.Base(path), err)
		}
	}
	return &DB{db: d}, nil
}

// Close releases the handle.
func (d *DB) Close() error { return d.db.Close() }

// DB exposes the raw handle.
func (d *DB) DB() *sql.DB { return d.db }

// OpenAll creates every database the binary maintains under dir
// (mirroring /etc/nouci_config/dbs/).
func OpenAll(dir string) (*Stores, error) {
	open := func(file string, schemas ...string) (*DB, error) {
		return Open(filepath.Join(dir, file), schemas...)
	}
	apmngr, err := open("apmngr.db",
		SchemaApentrycfgTable, SchemaApentryrunTable,
		SchemaApentrytmpcfgTable, SchemaAptemplateTable, SchemaGroupTable)
	if err != nil {
		return nil, err
	}
	wserv, err := open("wserv.db", SchemaWservTbl)
	if err != nil {
		apmngr.Close()
		return nil, err
	}
	wservRd, err := open("wserv_rd.db", SchemaBindTbl_wserv)
	if err != nil {
		wserv.Close()
		apmngr.Close()
		return nil, err
	}
	rfSchema := fmt.Sprintf(SchemaTable5, "rdmngrTable")
	rfIndex := "CREATE INDEX IF NOT EXISTS rdmngrTable_rf_id ON rdmngrTable(rf_id)"
	rdmngr, err := open("rdmngr.db", rfSchema, rfIndex)
	if err != nil {
		wservRd.Close()
		wserv.Close()
		apmngr.Close()
		return nil, err
	}
	portal, err := open("portal.db", PortalAuthedUserTableSchema)
	if err != nil {
		rdmngr.Close()
		wservRd.Close()
		wserv.Close()
		apmngr.Close()
		return nil, err
	}
	return &Stores{Apmngr: apmngr, Wserv: wserv, WservRd: wservRd, Rdmngr: rdmngr, Portal: portal}, nil
}

// Stores holds the databases the engine writes.
type Stores struct {
	Apmngr  *DB
	Wserv   *DB
	WservRd *DB
	Rdmngr  *DB
	Portal  *DB
}

// CloseAll closes every database.
func (s *Stores) CloseAll() {
	for _, d := range []*DB{s.Apmngr, s.Wserv, s.WservRd, s.Rdmngr, s.Portal} {
		d.Close()
	}
}

// OpenWportal opens portal.db for wportal authed-user persistence.
func OpenWportal(dir string) (*DB, error) {
	return Open(filepath.Join(dir, "portal.db"))
}

// WservRow mirrors wserv_tbl (schema from _wserv_sqlite_try_create_tbl).
type WservRow struct {
	WservID int64
	Enable  string
	SSID    string
	Vlan    int64 // default_bind_vlan
	RadioID int64 // encoded in bind_tbl; engine groups by radio
}

// SetWserv upserts one wserv_tbl row keyed by serv_id (the binary's schema
// has no UNIQUE on serv_id — update-then-insert like the vendor's SQL).
func (d *DB) SetWserv(r WservRow) error {
	res, err := d.db.Exec(
		`UPDATE wserv_tbl SET enable=?,default_bind_vlan=?,ssid=? WHERE serv_id=?`,
		r.Enable, r.Vlan, r.SSID, r.WservID)
	if err != nil {
		return err
	}
	if n, _ := res.RowsAffected(); n > 0 {
		return nil
	}
	_, err = d.db.Exec(
		`INSERT INTO wserv_tbl(serv_id,enable,default_bind_vlan,ssid) VALUES(?,?,?,?)`,
		r.WservID, r.Enable, r.Vlan, r.SSID)
	return err
}

// WservRows lists enabled SSID services.
func (d *DB) WservRows() ([]WservRow, error) {
	rows, err := d.db.Query(
		`SELECT serv_id,enable,default_bind_vlan,ssid FROM wserv_tbl ORDER BY priv_key`)
	if err != nil {
		return nil, err
	}
	defer rows.Close()
	var out []WservRow
	for rows.Next() {
		var r WservRow
		if err := rows.Scan(&r.WservID, &r.Enable, &r.Vlan, &r.SSID); err != nil {
			return nil, err
		}
		out = append(out, r)
	}
	return out, rows.Err()
}

// RdmngrRow is the minimal radio-config subset the engine serialises
// (full 50-column row in SchemaTable5/rdmngrTable).
type RdmngrRow struct {
	RfID       int64
	FreqBand   int64
	Mode       int64
	Bandwidth  int64
	Channel    int64
	PowerLevel int64
}

// SetRdmngr upserts one rdmngrTable row keyed by rf_id (update-then-insert;
// rf_id carries no UNIQUE constraint in the binary's schema).
func (d *DB) SetRdmngr(r RdmngrRow) error {
	res, err := d.db.Exec(
		`UPDATE rdmngrTable SET freq_band=?,mode=?,bandwidth=?,channel=?,power_level=?
		 WHERE rf_id=?`,
		r.FreqBand, r.Mode, r.Bandwidth, r.Channel, r.PowerLevel, r.RfID)
	if err != nil {
		return err
	}
	if n, _ := res.RowsAffected(); n > 0 {
		return nil
	}
	_, err = d.db.Exec(
		`INSERT INTO rdmngrTable(rf_id,freq_band,mode,bandwidth,channel,power_level)
		 VALUES(?,?,?,?,?,?)`,
		r.RfID, r.FreqBand, r.Mode, r.Bandwidth, r.Channel, r.PowerLevel)
	return err
}

// RdmngrRows lists configured radios.
func (d *DB) RdmngrRows() ([]RdmngrRow, error) {
	rows, err := d.db.Query(
		`SELECT rf_id,freq_band,mode,bandwidth,channel,power_level
		 FROM rdmngrTable ORDER BY rf_id`)
	if err != nil {
		return nil, err
	}
	defer rows.Close()
	var out []RdmngrRow
	for rows.Next() {
		var r RdmngrRow
		if err := rows.Scan(&r.RfID, &r.FreqBand, &r.Mode, &r.Bandwidth,
			&r.Channel, &r.PowerLevel); err != nil {
			return nil, err
		}
		out = append(out, r)
	}
	return out, rows.Err()
}

// BindRow mirrors one wserv_rd.db bind_tbl row: which wserv ids (and vlans)
// are bound to a radio (schema evidence: _wserv_sqlite_try_create_tbl —
// bind_tbl(radio_id, wserv1..8, vlan1..8, priv_key)).
type BindRow struct {
	RadioID int64
	Wserv   [8]int64
	Vlan    [8]int64
}

// BindRows lists the radio-SSID bindings.
func (d *DB) BindRows() ([]BindRow, error) {
	rows, err := d.db.Query(
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

// AuthedUserRow is one portal authenticated user record.
type AuthedUserRow struct {
	MAC      string
	User     string
	IP       string
	SSID     string
	AuthTime int64
	Online   int
}

// PortalAuthedUserTableSchema is the authed_users table in portal.db
// (the vendor keeps this in memory rbtree + snapshot; the Go port uses SQL).
const PortalAuthedUserTableSchema = `CREATE TABLE IF NOT EXISTS authed_users(
	mac TEXT PRIMARY KEY, user TEXT, ip TEXT, ssid TEXT,
	auth_time INTEGER, online INTEGER)`

// UpsertAuthedUser inserts or updates one authed user.
func (d *DB) UpsertAuthedUser(r AuthedUserRow) error {
	_, err := d.db.Exec(
		`INSERT INTO authed_users(mac,user,ip,ssid,auth_time,online)
		 VALUES(?,?,?,?,?,?)
		 ON CONFLICT(mac) DO UPDATE SET user=excluded.user, ip=excluded.ip,
		   ssid=excluded.ssid, auth_time=excluded.auth_time, online=excluded.online`,
		r.MAC, r.User, r.IP, r.SSID, r.AuthTime, r.Online)
	return err
}

// ListAuthedUsers returns all authed users.
func (d *DB) ListAuthedUsers() ([]AuthedUserRow, error) {
	rows, err := d.db.Query(
		`SELECT mac,user,ip,ssid,auth_time,online FROM authed_users ORDER BY auth_time`)
	if err != nil {
		return nil, err
	}
	defer rows.Close()
	var out []AuthedUserRow
	for rows.Next() {
		var r AuthedUserRow
		if err := rows.Scan(&r.MAC, &r.User, &r.IP, &r.SSID, &r.AuthTime, &r.Online); err != nil {
			return nil, err
		}
		out = append(out, r)
	}
	return out, rows.Err()
}
