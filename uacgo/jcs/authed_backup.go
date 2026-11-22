package jcs

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"os"
)

// AuthedUserBackup is one entry in the authed-user backup file.
type AuthedUserBackup struct {
	MAC      string `json:"mac"`
	User     string `json:"user"`
	IP       string `json:"ip"`
	SSID     string `json:"ssid"`
	AuthTime int64  `json:"auth_time"`
	Online   int    `json:"online"`
}

// BackupAuthedUsers exports all authed users to a JSON file.
func BackupAuthedUsers(dbPath, outFile string) error {
	db, err := sql.Open("sqlite", dbPath)
	if err != nil {
		return fmt.Errorf("open %s: %w", dbPath, err)
	}
	defer db.Close()
	rows, err := db.Query(`SELECT mac,user,ip,ssid,auth_time,online FROM authed_users`)
	if err != nil {
		return fmt.Errorf("query: %w", err)
	}
	defer rows.Close()
	var list []AuthedUserBackup
	for rows.Next() {
		var u AuthedUserBackup
		if err := rows.Scan(&u.MAC, &u.User, &u.IP, &u.SSID, &u.AuthTime, &u.Online); err != nil {
			return fmt.Errorf("scan: %w", err)
		}
		list = append(list, u)
	}
	b, err := json.MarshalIndent(list, "", "  ")
	if err != nil {
		return err
	}
	return os.WriteFile(outFile, b, 0644)
}

// RestoreAuthedUsers imports authed users from a JSON backup file into
// the portal.db authed_users table.
func RestoreAuthedUsers(dbPath, backupFile string) error {
	b, err := os.ReadFile(backupFile)
	if err != nil {
		return fmt.Errorf("read backup: %w", err)
	}
	var list []AuthedUserBackup
	if err := json.Unmarshal(b, &list); err != nil {
		return fmt.Errorf("parse backup: %w", err)
	}
	db, err := sql.Open("sqlite", dbPath)
	if err != nil {
		return fmt.Errorf("open %s: %w", dbPath, err)
	}
	defer db.Close()
	for _, u := range list {
		if _, err := db.Exec(
			`INSERT OR REPLACE INTO authed_users(mac,user,ip,ssid,auth_time,online)
			 VALUES(?,?,?,?,?,?)`,
			u.MAC, u.User, u.IP, u.SSID, u.AuthTime, u.Online); err != nil {
			return fmt.Errorf("insert %s: %w", u.MAC, err)
		}
	}
	return nil
}
