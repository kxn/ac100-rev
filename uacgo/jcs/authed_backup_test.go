package jcs

import (
	"database/sql"
	"path/filepath"
	"testing"

	_ "modernc.org/sqlite"
)

// Backup authed users to JSON → restore into a fresh DB → verify roundtrip.
func TestAuthedUserBackupRestore(t *testing.T) {
	dir := t.TempDir()
	dbPath := filepath.Join(dir, "portal.db")
	db, err := sql.Open("sqlite", dbPath)
	if err != nil {
		t.Fatal(err)
	}
	db.Exec(`CREATE TABLE IF NOT EXISTS authed_users(
		mac TEXT PRIMARY KEY, user TEXT, ip TEXT, ssid TEXT,
		auth_time INTEGER, online INTEGER)`)
	db.Exec(`INSERT INTO authed_users VALUES('aa:bb:cc:dd:ee:ff','alice','10.0.0.1','office',1700000000,1)`)
	db.Close()

	// Backup
	if err := BackupAuthedUsers(dbPath, filepath.Join(dir, "backup.json")); err != nil {
		t.Fatal(err)
	}

	// Restore into fresh DB
	freshPath := filepath.Join(dir, "fresh.db")
	fdb, err := sql.Open("sqlite", freshPath)
	if err != nil {
		t.Fatal(err)
	}
	defer fdb.Close()
	fdb.Exec(`CREATE TABLE IF NOT EXISTS authed_users(mac TEXT PRIMARY KEY, user TEXT, ip TEXT, ssid TEXT, auth_time INTEGER, online INTEGER)`)

	if err := RestoreAuthedUsers(freshPath, filepath.Join(dir, "backup.json")); err != nil {
		t.Fatal(err)
	}

	var mac string
	if err := fdb.QueryRow(`SELECT mac FROM authed_users LIMIT 1`).Scan(&mac); err != nil || mac != "aa:bb:cc:dd:ee:ff" {
		t.Fatalf("restored mac = %q err = %v", mac, err)
	}
}
