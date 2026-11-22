package cweng

import (
	"database/sql"
	"net"
	"path/filepath"
	"testing"

	_ "modernc.org/sqlite"

	"time"

	"uacgo/store"
)

var (
	schemaApEntryCfg = store.SchemaApentrycfgTable
	schemaApEntryRun = store.SchemaApentryrunTable
)

// Join → RUN stores the AP in apmngr.db (ApEntryCfg_table / ApEntryRun_table).
func TestJoinStoresAPEntry(t *testing.T) {
	dir := t.TempDir()
	dbFile := filepath.Join(dir, "apmngr.db")
	cfgDB, err := sql.Open("sqlite", dbFile)
	if err != nil {
		t.Fatal(err)
	}
	defer cfgDB.Close()
	for _, sc := range []string{schemaApEntryCfg, schemaApEntryRun} {
		if _, err := cfgDB.Exec(sc); err != nil {
			t.Fatal(err)
		}
	}
	st := &SQLiteAPStore{Cfg: cfgDB, Run: cfgDB}

	e, _ := NewEngine(0)
	e.UseStore(st)
	go func() { _ = e.Run() }()

	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	c.Write(withSeq(t, "cw_join_req_0074f150.bin", 2))
	buf := make([]byte, 65536)
	c.SetReadDeadline(time.Now().Add(2 * time.Second))
	if _, err := c.Read(buf); err != nil {
		t.Fatalf("no join response: %v", err)
	}

	var name string
	err = cfgDB.QueryRow(`SELECT entry_name FROM ApEntryCfg_table LIMIT 1`).Scan(&name)
	if err != nil || name != "My WTP 1" {
		t.Fatalf("apmngr.db entry_name = %q err=%v", name, err)
	}
	var status int
	err = cfgDB.QueryRow(`SELECT status FROM ApEntryRun_table LIMIT 1`).Scan(&status)
	if err != nil {
		t.Fatalf("run table: %v", err)
	}
}
