package jcs

import (
	"fmt"
	"strings"
	"time"
)

// wportal_backup.get CSV export.
//
// Evidence (direct from uac binary, this round):
//   - wportal_jcs_backup_callback @0x40e6ac:
//       fopen("/tmp/authedUser.csv","a+")              (0x676fac/0x676fc0)
//       if portalCtrlType@0x759f50 != 1:
//           fwrite("认证方式,用户名,MAC地址,SSID,认证时间,认证剩余时间\r\n", 71, 1, f)
//           (header string @0x67703c, length 71)
//       wportal_db_authed_list_range_handle @0x4305b4(0, count@0x75a0b0,
//           row_cb=0x419a2c, f, ...) — entries with field+332==15 are skipped
//       json_object_object_add(resp, "file_name",
//           json_object_new_string("/tmp/authedUser.csv"))
//       fclose(f)
//   - Row callback _wportal_authed_user_json_backup_callback @0x419a2c,
//     entry field offsets: mac +12(6B), ssid_id +20(u32), deadline +64(u32),
//     remaining +68(u32), auth_type +128(u8), state +129(u8),
//     user +163(C-str), tm {u16 year +264, mon..sec +266..270}.
//     Columns:
//       1  "%s(%s)," (authTypeChinese(type), statePrefix) — or bare "%s,"
//          when state ∉ {0,1,99}; prefixes: 0=本地认证@0x678b54,
//          1=Radius认证@0x678b64, 99=临时放行@0x678b74
//       2  user: quoted+quote-doubled (escape fn @0x419974 writes "" for ")
//          when it contains ',' or '"', else "%s," with "---"@0x6bb290 empty
//       3  "%02X-%02X-%02X-%02X-%02X-%02X," (@0x677254)
//       4  ctrlType==1: ssid_id==4095 → "---," else "%d,"
//          else: wserv_db_get_entry_by_id @0x5ebe20 (517B record copy,
//          name at +304 of the copy); lookup failure → "---,"; names with
//          ',' or '"' are quoted/escaped like column 2
//       5  "%04u/%02u/%02u %02u:%02u:%02u," (@0x677844) from tm block
//       6  remaining: if now < deadline(+64) → breakdown of remaining(+68)
//          else zeros; "%d天%d小时%d分%d秒"@0x678b9c + "\r\n"@0x71e728
//   - authTypeChinese @0x411690: 1=web认证 2=微信认证 4=一键上网 8=短信认证
//     16=远程Portal 32=CMCC认证 64=云认证, else "--"@0x6f4720
//   - portalCtrlType@0x759f50 written by wportal_jcs_set_callback
//     @0x4295f0: key "ssid"→1, "vlan"→2, "interface"→0/-1
//     (strings @0x6eb900/0x6e93f4/0x678aa8)

// AuthedUserCSVPath is the CSV file the backup handler appends to.
var AuthedUserCSVPath = "/tmp/authedUser.csv"

// AuthedUserCSVHeader is the exact 71-byte header the vendor writes.
const AuthedUserCSVHeader = "认证方式,用户名,MAC地址,SSID,认证时间,认证剩余时间\r\n"

// PortalCtrlType mirrors the global at 0x759f50 (1=ssid, 2=vlan, else
// interface). Set by the wportal set verb.
var PortalCtrlType int

// AuthedUserCSV is one backup row with the vendor entry fields the CSV
// renderer consumes.
type AuthedUserCSV struct {
	MAC       [6]byte
	SsidID    uint32 // +20
	SsidName  string // wserv entry name (column 4 when ctrlType != 1)
	Deadline  int64  // +64 absolute expiry (unix seconds)
	Remaining uint32 // +68 seconds left, maintained by the aging timer
	AuthType  uint8  // +128
	State     uint8  // +129 (0 local / 1 radius / 99 temp-pass)
	User      string // +163
	TmYear    uint16 // +264
	TmMon     uint8  // +266
	TmDay     uint8  // +267
	TmHour    uint8  // +268
	TmMin     uint8  // +269
	TmSec     uint8  // +270
}

// authTypeChinese mirrors wportal_auth_type_int2chinesestr @0x411690.
func authTypeChinese(t uint8) string {
	switch t {
	case 1:
		return "web认证"
	case 2:
		return "微信认证"
	case 4:
		return "一键上网"
	case 8:
		return "短信认证"
	case 16:
		return "远程Portal"
	case 32:
		return "CMCC认证"
	case 64:
		return "云认证"
	}
	return "--"
}

// statePrefix mirrors the +129 switch: (prefix, parenthesised).
func statePrefix(s uint8) (string, bool) {
	switch s {
	case 0:
		return "本地认证", true
	case 1:
		return "Radius认证", true
	case 99:
		return "临时放行", true
	}
	return "", false
}

// csvQuote renders a field that contains ',' or '"' the way the vendor does:
// wrapped in quotes with embedded quotes doubled (fn @0x419974).
// needs reports whether quoting applies.
func csvQuote(s string) (out string, needs bool) {
	if strings.ContainsAny(s, ",\"") {
		return "\"" + strings.ReplaceAll(s, "\"", "\"\"") + "\"", true
	}
	return s, false
}

// RemainingString renders "%d天%d小时%d分%d秒" (fmt @0x678b9c) from seconds.
func RemainingString(sec uint32) string {
	d := sec / 86400
	h := sec % 86400 / 3600
	m := sec % 3600 / 60
	s := sec % 60
	return fmt.Sprintf("%d天%d小时%d分%d秒", d, h, m, s)
}

// RenderAuthedUserCSVRow renders one row exactly as the vendor callback
// does. now is the current unix time for the deadline compare.
func RenderAuthedUserCSVRow(r *AuthedUserCSV, now int64) string {
	var sb strings.Builder
	// col 1: auth type (+state when 0/1/99)
	if p, ok := statePrefix(r.State); ok {
		fmt.Fprintf(&sb, "%s(%s),", authTypeChinese(r.AuthType), p)
	} else {
		fmt.Fprintf(&sb, "%s,", authTypeChinese(r.AuthType))
	}
	// col 2: username
	if s, q := csvQuote(r.User); q {
		fmt.Fprintf(&sb, "%s,", s)
	} else {
		if s == "" {
			s = "---"
		}
		fmt.Fprintf(&sb, "%s,", s)
	}
	// col 3: MAC
	fmt.Fprintf(&sb, "%02X-%02X-%02X-%02X-%02X-%02X,",
		r.MAC[0], r.MAC[1], r.MAC[2], r.MAC[3], r.MAC[4], r.MAC[5])
	// col 4: ssid
	if PortalCtrlType == 1 {
		if r.SsidID == 4095 {
			sb.WriteString("---,")
		} else {
			fmt.Fprintf(&sb, "%d,", r.SsidID)
		}
	} else {
		if s, q := csvQuote(r.SsidName); q {
			fmt.Fprintf(&sb, "%s,", s)
		} else {
			if s == "" {
				s = "---"
			}
			fmt.Fprintf(&sb, "%s,", s)
		}
	}
	// col 5: auth time
	fmt.Fprintf(&sb, "%04d/%02d/%02d %02d:%02d:%02d,",
		r.TmYear, r.TmMon, r.TmDay, r.TmHour, r.TmMin, r.TmSec)
	// col 6: remaining time
	var rem uint32
	if now < r.Deadline {
		rem = r.Remaining
	}
	fmt.Fprintf(&sb, "%s\r\n", RemainingString(rem))
	return sb.String()
}

// BuildAuthedUserCSV renders the full backup file body: header when
// PortalCtrlType != 1, then one row per user (entries the vendor skips are
// filtered by the caller). Returns the bytes, matching what the vendor's
// /tmp/authedUser.csv contains for one backup invocation.
func BuildAuthedUserCSV(users []*AuthedUserCSV, now int64) []byte {
	var b strings.Builder
	if PortalCtrlType != 1 {
		b.WriteString(AuthedUserCSVHeader)
	}
	for _, r := range users {
		b.WriteString(RenderAuthedUserCSVRow(r, now))
	}
	return []byte(b.String())
}

// CSVFromAuthedUser converts a store record into the CSV row view. Fields
// the store does not carry (auth type, state, expiry) take the vendor's
// inactive defaults: type/state zero → "本地认证(本地认证)" prefix and a
// zero remaining breakdown, matching deadline <= now.
func CSVFromAuthedUser(u *AuthedUser, now int64) *AuthedUserCSV {
	r := &AuthedUserCSV{User: u.User, SsidName: u.SSID}
	hex := strings.Map(func(c rune) rune {
		if c == ':' || c == '-' || c == '.' {
			return -1
		}
		return c
	}, u.MAC)
	for i := 0; i < 6 && i*2+1 < len(hex); i++ {
		r.MAC[i] = hexPair(hex[i*2], hex[i*2+1])
	}
	t := time.Unix(u.AuthTime, 0)
	r.TmYear = uint16(t.Year())
	r.TmMon = uint8(t.Month())
	r.TmDay = uint8(t.Day())
	r.TmHour = uint8(t.Hour())
	r.TmMin = uint8(t.Minute())
	r.TmSec = uint8(t.Second())
	return r
}

func hexPair(hi, lo byte) byte {
	var v byte
	switch {
	case hi >= '0' && hi <= '9':
		v = hi - '0'
	case hi >= 'a' && hi <= 'f':
		v = hi - 'a' + 10
	case hi >= 'A' && hi <= 'F':
		v = hi - 'A' + 10
	}
	v <<= 4
	switch {
	case lo >= '0' && lo <= '9':
		v |= lo - '0'
	case lo >= 'a' && lo <= 'f':
		v |= lo - 'a' + 10
	case lo >= 'A' && lo <= 'F':
		v |= lo - 'A' + 10
	}
	return v
}
