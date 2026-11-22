package jcs

import (
	"database/sql"
	"encoding/json"
	"os"
	"sort"
	"strings"
	"sync"
	"time"

	_ "modernc.org/sqlite"
)

// wportal semantic layer.
//
// Evidence (notes §21): _wportal_jcs_get_callback @0x415b40 fields
// search/search_arg/start/size/type/mac/is_online/ret over the authed-user
// list; the wportal DB is in-memory rbtree/hash structures
// (wportal_db_dm_* @0x42afec+) snapshotted to portal.db. This port keeps an
// in-memory map keyed by MAC and snapshots to a portal.db SQL table.

// AuthedUser is one authenticated portal user record.
type AuthedUser struct {
	MAC      string `json:"mac"`
	User     string `json:"user"`
	IP       string `json:"ip"`
	SSID     string `json:"ssid"`
	AuthTime int64  `json:"auth_time"`
	Online   bool   `json:"is_online"`
}

// AuthedUserTable is the in-memory user table with portal.db snapshotting.
type AuthedUserTable struct {
	mu   sync.Mutex
	m    map[string]*AuthedUser
	path string // portal.db snapshot file ("" = memory only)
}

// NewAuthedUserTable creates the table, loading a prior snapshot when path
// is set (table authed_users; created on first save).
func NewAuthedUserTable(path string) (*AuthedUserTable, error) {
	t := &AuthedUserTable{m: make(map[string]*AuthedUser), path: path}
	if path == "" {
		return t, nil
	}
	db, err := sql.Open("sqlite", path)
	if err != nil {
		return nil, err
	}
	defer db.Close()
	if _, err := db.Exec(
		`CREATE TABLE IF NOT EXISTS authed_users(
		   mac TEXT PRIMARY KEY, user TEXT, ip TEXT, ssid TEXT,
		   auth_time INTEGER, online INTEGER)`); err != nil {
		return nil, err
	}
	rows, err := db.Query(
		`SELECT mac,user,ip,ssid,auth_time,online FROM authed_users`)
	if err != nil {
		return t, nil // fresh snapshot file
	}
	defer rows.Close()
	for rows.Next() {
		var u AuthedUser
		var online int
		if err := rows.Scan(&u.MAC, &u.User, &u.IP, &u.SSID, &u.AuthTime, &online); err == nil {
			u.Online = online != 0
			t.m[u.MAC] = &u
		}
	}
	return t, nil
}

// Snapshot writes the in-memory table to portal.db.
func (t *AuthedUserTable) Snapshot() error {
	if t.path == "" {
		return nil
	}
	t.mu.Lock()
	users := make([]*AuthedUser, 0, len(t.m))
	for _, u := range t.m {
		users = append(users, u)
	}
	t.mu.Unlock()
	db, err := sql.Open("sqlite", t.path)
	if err != nil {
		return err
	}
	defer db.Close()
	if _, err := db.Exec(
		`CREATE TABLE IF NOT EXISTS authed_users(
		   mac TEXT PRIMARY KEY, user TEXT, ip TEXT, ssid TEXT,
		   auth_time INTEGER, online INTEGER)`); err != nil {
		return err
	}
	if _, err := db.Exec(`DELETE FROM authed_users`); err != nil {
		return err
	}
	for _, u := range users {
		online := 0
		if u.Online {
			online = 1
		}
		if _, err := db.Exec(
			`INSERT OR REPLACE INTO authed_users
			   (mac,user,ip,ssid,auth_time,online) VALUES(?,?,?,?,?,?)`,
			u.MAC, u.User, u.IP, u.SSID, u.AuthTime, online); err != nil {
			return err
		}
	}
	return nil
}

// Put inserts/updates one user (used by auth flows and the add/set verbs).
func (t *AuthedUserTable) Put(u *AuthedUser) {
	t.mu.Lock()
	t.m[u.MAC] = u
	t.mu.Unlock()
}

// Delete removes a user by MAC.
func (t *AuthedUserTable) Delete(mac string) {
	t.mu.Lock()
	delete(t.m, mac)
	t.mu.Unlock()
}

// GetIsOnline mirrors _wportal_get_is_online_by_mac.
func (t *AuthedUserTable) GetIsOnline(mac string) bool {
	t.mu.Lock()
	defer t.mu.Unlock()
	u := t.m[mac]
	return u != nil && u.Online
}

// List implements the get_callback query: search substring over user/mac,
// is_online filter (nil = all), start/size pagination, stable order by
// auth_time then mac.
func (t *AuthedUserTable) List(search string, mac string, online *bool, start, size int) []*AuthedUser {
	t.mu.Lock()
	all := make([]*AuthedUser, 0, len(t.m))
	for _, u := range t.m {
		all = append(all, u)
	}
	t.mu.Unlock()
	sort.Slice(all, func(i, j int) bool {
		if all[i].AuthTime != all[j].AuthTime {
			return all[i].AuthTime < all[j].AuthTime
		}
		return all[i].MAC < all[j].MAC
	})
	out := []*AuthedUser{}
	for _, u := range all {
		if search != "" &&
			!strings.Contains(u.User, search) && !strings.Contains(u.MAC, search) {
			continue
		}
		if mac != "" && u.MAC != mac {
			continue
		}
		if online != nil && u.Online != *online {
			continue
		}
		out = append(out, u)
	}
	if start > len(out) {
		return []*AuthedUser{}
	}
	out = out[start:]
	if size > 0 && size < len(out) {
		out = out[:size]
	}
	return out
}

// RegisterWportalHandlers installs the wportal verbs
// (wportal_init @0x4263f0: wportal add/del/set/get) over the table.
func RegisterWportalHandlers(s *Server, t *AuthedUserTable) {
	s.Register("wportal.get", func(req json.RawMessage) (any, error) {
		var q struct {
			Search string `json:"search"`
			MAC    string `json:"mac"`
			Online *bool  `json:"is_online"`
			Start  int    `json:"start"`
			Size   int    `json:"size"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &q); err != nil {
				return nil, err
			}
		}
		list := t.List(q.Search, q.MAC, q.Online, q.Start, q.Size)
		return map[string]any{"error_code": 0, "authed_user_list": list}, nil
	})
	s.Register("wportal.add", func(req json.RawMessage) (any, error) {
		var u AuthedUser
		if err := json.Unmarshal(req, &u); err != nil {
			return nil, err
		}
		if u.MAC == "" {
			return jerr(errString("mac required")), nil
		}
		t.Put(&u)
		return ok(), nil
	})
	s.Register("wportal.set", func(req json.RawMessage) (any, error) {
		var u AuthedUser
		if err := json.Unmarshal(req, &u); err != nil {
			return nil, err
		}
		t.mu.Lock()
		cur := t.m[u.MAC]
		t.mu.Unlock()
		if cur == nil {
			return jerr(errString("no such user")), nil
		}
		t.Put(&u)
		return ok(), nil
	})
	s.Register("wportal.del", func(req json.RawMessage) (any, error) {
		var r struct {
			MAC string `json:"mac"`
		}
		if err := json.Unmarshal(req, &r); err != nil {
			return nil, err
		}
		t.Delete(r.MAC)
		return ok(), nil
	})
	// backup/nsa_sync: wportal_backup.get per wportal_jcs_backup_callback
	// @0x40e6ac — append CSV rows of the authed users to
	// /tmp/authedUser.csv and answer file_name (see wportal_backup.go for
	// the byte-level format evidence).
	s.Register("wportal_backup.get", func(json.RawMessage) (any, error) {
		users := t.List("", "", nil, 0, 0)
		rows := make([]*AuthedUserCSV, 0, len(users))
		now := time.Now().Unix()
		for _, u := range users {
			rows = append(rows, CSVFromAuthedUser(u, now))
		}
		body := BuildAuthedUserCSV(rows, now)
		f, err := os.OpenFile(AuthedUserCSVPath, os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0644)
		if err != nil {
			return jerr(err), nil
		}
		if _, err := f.Write(body); err != nil {
			f.Close()
			return jerr(err), nil
		}
		f.Close()
		return map[string]any{"error_code": 0, "file_name": AuthedUserCSVPath}, nil
	})
	s.Register("wportal_nsa_sync.set", func(req json.RawMessage) (any, error) {
		// wportal_jcs_nsa_sync_callback @0x415aa8: no request parsing, the
		// body is a single call to wportal_db_nsa_rbtree_sync @0x434998 —
		// flush the in-memory NSA/authed-user table to the store.
		t.Snapshot()
		return ok(), nil
	})
}

type errString string

func (e errString) Error() string { return string(e) }
