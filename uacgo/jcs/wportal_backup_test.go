package jcs

import (
	"os"
	"path/filepath"
	"strings"
	"testing"
	"time"
)

// Row rendering must match the vendor byte layout proven from
// _wportal_authed_user_json_backup_callback @0x419a2c.
func TestAuthedUserCSVRow(t *testing.T) {
	old := PortalCtrlType
	defer func() { PortalCtrlType = old }()
	PortalCtrlType = 0

	r := &AuthedUserCSV{
		MAC:       [6]byte{0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF},
		SsidName:  "office",
		Deadline:  1700000100,
		Remaining: 90061, // 1天1小时1分1秒
		AuthType:  1,     // web认证
		State:     1,     // Radius认证
		User:      "alice",
		TmYear:    2023, TmMon: 11, TmDay: 14, TmHour: 8, TmMin: 5, TmSec: 0,
	}
	row := RenderAuthedUserCSVRow(r, 1700000000)
	want := "web认证(Radius认证),alice,AA-BB-CC-DD-EE-FF,office,2023/11/14 08:05:00,1天1小时1分1秒\r\n"
	if row != want {
		t.Fatalf("row = %q want %q", row, want)
	}

	// expired deadline → zero breakdown
	if got := RenderAuthedUserCSVRow(r, 1700000200); !strings.HasSuffix(got, "0天0小时0分0秒\r\n") {
		t.Fatalf("expired row = %q", got)
	}

	// username with comma → quoted; quotes doubled
	r2 := &AuthedUserCSV{User: `a,b"c`, MAC: r.MAC, AuthType: 1, State: 0, TmYear: 2023}
	got := RenderAuthedUserCSVRow(r2, 0)
	if !strings.HasPrefix(got, `web认证(本地认证),"a,b""c",`) {
		t.Fatalf("escaped row = %q", got)
	}

	// empty username → "---"
	r3 := &AuthedUserCSV{AuthType: 1, State: 0, TmYear: 2023}
	if !strings.HasPrefix(RenderAuthedUserCSVRow(r3, 0), "web认证(本地认证),---,") {
		t.Fatalf("empty user row = %q", RenderAuthedUserCSVRow(r3, 0))
	}

	// unknown auth type → "--"; unknown state → bare prefix
	r4 := &AuthedUserCSV{AuthType: 3, State: 7, TmYear: 2023}
	if !strings.HasPrefix(RenderAuthedUserCSVRow(r4, 0), "--,") {
		t.Fatalf("unknown type row = %q", RenderAuthedUserCSVRow(r4, 0))
	}
}

// Header inclusion follows portalCtrlType@0x759f50.
func TestAuthedUserCSVHeader(t *testing.T) {
	old := PortalCtrlType
	defer func() { PortalCtrlType = old }()

	PortalCtrlType = 0
	b := BuildAuthedUserCSV(nil, 0)
	if string(b) != AuthedUserCSVHeader {
		t.Fatalf("header body = %q", b)
	}
	if len(AuthedUserCSVHeader) != 71 {
		t.Fatalf("header len = %d want 71", len(AuthedUserCSVHeader))
	}

	PortalCtrlType = 1 // ssid mode: no header, raw ssid id
	r := &AuthedUserCSV{SsidID: 3, AuthType: 1, State: 0,
		TmYear: 2023, TmMon: 1, TmDay: 1, TmHour: 8}
	if got := string(BuildAuthedUserCSV([]*AuthedUserCSV{r}, 0)); got != "web认证(本地认证),---,00-00-00-00-00-00,3,2023/01/01 08:00:00,0天0小时0分0秒\r\n" {
		t.Fatalf("ssid mode body = %q", got)
	}
	r.SsidID = 4095
	if got := RenderAuthedUserCSVRow(r, 0); !strings.Contains(got, ",---,2023/") {
		t.Fatalf("ssid 4095 row = %q", got)
	}
}

// The handler writes the CSV file and answers file_name (0x40e6ac).
func TestWportalBackupHandler(t *testing.T) {
	old := AuthedUserCSVPath
	defer func() { AuthedUserCSVPath = old }()
	AuthedUserCSVPath = filepath.Join(t.TempDir(), "authedUser.csv")

	s := NewServer()
	tab, err := NewAuthedUserTable("")
	if err != nil {
		t.Fatal(err)
	}
	tab.Put(&AuthedUser{MAC: "aa:bb:cc:dd:ee:ff", User: "alice", SSID: "office", AuthTime: 1700000000})
	RegisterWportalHandlers(s, tab)

	path := filepath.Join(t.TempDir(), "jcs.service.srv.wportal")
	up := make(chan string)
	go func() { up <- "up"; _ = s.Serve(path) }()
	<-up
	time.Sleep(50 * time.Millisecond)
	defer s.Close()

	resp, err := Call(path, "get", "wportal_backup", "get", nil)
	if err != nil {
		t.Fatal(err)
	}
	if !strings.Contains(string(resp), `"file_name":"`+AuthedUserCSVPath+`"`) {
		t.Fatalf("resp = %s", resp)
	}
	b, err := os.ReadFile(AuthedUserCSVPath)
	if err != nil {
		t.Fatal(err)
	}
	if !strings.Contains(string(b), "alice,AA-BB-CC-DD-EE-FF,office,") {
		t.Fatalf("csv = %q", b)
	}
	if !strings.Contains(string(b), "认证方式,用户名,MAC地址,SSID,认证时间,认证剩余时间\r\n") {
		t.Fatalf("csv header missing: %q", b)
	}
}
