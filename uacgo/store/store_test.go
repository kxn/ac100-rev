package store

import (
	"database/sql"
	"path/filepath"
	"testing"
)

// Every CREATE TABLE string is applied verbatim from the binary; opening all
// databases must succeed and ApEntryCfg_table must accept a row.
func TestOpenAll(t *testing.T) {
	dir := t.TempDir()
	s, err := OpenAll(filepath.Join(dir, "dbs"))
	if err != nil {
		t.Fatal(err)
	}
	defer s.CloseAll()

	res, err := s.Apmngr.db.Exec(
		`INSERT INTO ApEntryCfg_table(entry_id,mac,entry_name,model_id,hardware_ver)
		 VALUES (1,'aa:bb:cc:dd:ee:ff','AP-1',12345,'1.0')`)
	if err != nil {
		t.Fatal(err)
	}
	if n, _ := res.RowsAffected(); n != 1 {
		t.Fatalf("insert affected %d", n)
	}
	var name string
	err = s.Apmngr.db.QueryRow(
		`SELECT entry_name FROM ApEntryCfg_table WHERE mac=?`, "aa:bb:cc:dd:ee:ff").Scan(&name)
	if err != nil || name != "AP-1" {
		t.Fatalf("query: %v name=%q", err, name)
	}
}

// bind_tbl round-trip: radio → wserv/vlan slots survive the store.
func TestBindRows(t *testing.T) {
	dir := t.TempDir()
	s, err := OpenAll(filepath.Join(dir, "dbs"))
	if err != nil {
		t.Fatal(err)
	}
	defer s.CloseAll()
	_, err = s.WservRd.db.Exec(
		`INSERT INTO bind_tbl(radio_id,wserv1,vlan1,wserv2,vlan2) VALUES(1,10,100,20,200)`)
	if err != nil {
		t.Fatal(err)
	}
	rows, err := s.WservRd.BindRows()
	if err != nil {
		t.Fatal(err)
	}
	if len(rows) != 1 || rows[0].RadioID != 1 || rows[0].Wserv[0] != 10 ||
		rows[0].Vlan[1] != 200 {
		t.Fatalf("bind rows = %+v", rows)
	}
}

// wportal authed-user CRUD roundtrip.
func TestAuthedUserCRUD(t *testing.T) {
	dir := t.TempDir()
	s, err := OpenAll(filepath.Join(dir, "dbs"))
	if err != nil {
		t.Fatal(err)
	}
	defer s.CloseAll()

	db, err := sql.Open("sqlite", filepath.Join(dir, "portal.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	if _, err := db.Exec(PortalAuthedUserTableSchema); err != nil {
		t.Fatal(err)
	}

	if _, err := db.Exec(
		`INSERT INTO authed_users(mac,user,ip,ssid,auth_time,online)
		 VALUES('aa:bb:cc:dd:ee:ff','alice','10.0.0.1','office',1700000000,1)`); err != nil {
		t.Fatal(err)
	}

	var mac, user string
	var online int
	err = db.QueryRow(
		`SELECT mac,user,online FROM authed_users WHERE mac='aa:bb:cc:dd:ee:ff'`,
	).Scan(&mac, &user, &online)
	if err != nil || mac != "aa:bb:cc:dd:ee:ff" || user != "alice" || online != 1 {
		t.Fatalf("authed user: %v %s %d", err, mac, online)
	}
}
