// Package cweng — store.go loads the runtime data files extracted from the
// firmware (the Go port never reads the firmware image at runtime; everything
// it depends on lives in data/):
//
//	data/apdb.json    — AP capability database, decrypted from /etc/apdb.bin
//	                    (DES-ECB key @uac 0x71ced0 verified; payload MD5 ok)
//	data/identity.json— AC identity shown in responses (matches the vendor's
//	                    .data fixture values)
//	data/profile.ini  — the "profile" config uac reads via embedded Lua UCI
//	                    (hard runtime dependency, reconstructed; see header)
package cweng

import (
	"encoding/json"
	"fmt"
	"net"
	"os"
	"strconv"
	"strings"
)

// Identity is the AC identity data loaded from identity.json.
type Identity struct {
	ACName      string `json:"ac_name"`
	ACVersion   string `json:"ac_version"`
	ACFirmware  string `json:"ac_firmware"`
	VendorIDHex string `json:"vendor_id"`
	ControlIP   string `json:"control_ipv4"`
	ControlPort uint16 `json:"control_port"`
	Radios      []struct {
		RadioID  uint8 `json:"radio_id"`
		TypeMask uint8 `json:"type_mask"`
	} `json:"radios"`
}

// LoadIdentity reads identity.json.
func LoadIdentity(path string) (*Identity, error) {
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("identity: %w", err)
	}
	var id Identity
	if err := json.Unmarshal(b, &id); err != nil {
		return nil, fmt.Errorf("identity: %w", err)
	}
	return &id, nil
}

// APDB is the AP capability database (apdb.json).
type APDB struct {
	Version string `json:"version"`
	Vendor  int    `json:"vendor"`
	APList  []struct {
		APName string `json:"ap_name"`
		ID     uint64 `json:"id"`
		Models []struct {
			HWVer  string `json:"hwver"`
			Radios map[string]struct {
				MaxSSID     int         `json:"max_ssid"`
				MaxStations int         `json:"max_stations"`
				MaxTxPower  int         `json:"max_tx_power"`
				MinTxPower  int         `json:"min_tx_power"`
				DftTxPower  int         `json:"dft_tx_power"`
				DftBWMode   int         `json:"dft_bw_mode"`
				Support11Ac interface{} `json:"support_11ac"`
			} `json:"radios"`
		} `json:"models"`
	} `json:"ap_list"`
}

// LoadAPDB reads apdb.json (already decrypted + md5-verified at extraction).
func LoadAPDB(path string) (*APDB, error) {
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("apdb: %w", err)
	}
	var db APDB
	if err := json.Unmarshal(b, &db); err != nil {
		return nil, fmt.Errorf("apdb: %w", err)
	}
	return &db, nil
}

// LookupAP finds a model entry by AP name (the binary matches via apdb_init +
// cw_apdb joins; model ids come from the WTP Board Data 0x26 sub-element).
func (db *APDB) LookupAP(name string) *struct {
	APName string
	ID     uint64
} {
	for i := range db.APList {
		if db.APList[i].APName == name {
			a := &db.APList[i]
			return &struct {
				APName string
				ID     uint64
			}{a.APName, a.ID}
		}
	}
	return nil
}

// LoadProfileINI parses the reconstructed profile.ini (subset of INI:
// [section] + key = value lines; comments with #).
func LoadProfileINI(path string) (map[string]map[string]string, error) {
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("profile: %w", err)
	}
	out := map[string]map[string]string{}
	sec := ""
	for _, line := range strings.Split(string(b), "\n") {
		line = strings.TrimSpace(line)
		if line == "" || strings.HasPrefix(line, "#") {
			continue
		}
		if strings.HasPrefix(line, "[") && strings.HasSuffix(line, "]") {
			sec = strings.Trim(line, "[]")
			out[sec] = map[string]string{}
			continue
		}
		k, v, ok := strings.Cut(line, "=")
		if !ok || sec == "" {
			continue
		}
		out[sec][strings.TrimSpace(k)] = strings.TrimSpace(v)
	}
	return out, nil
}

// ProfileInt mirrors uac_profile_get_int: missing → the caller fails init.
func ProfileInt(p map[string]map[string]string, sec, opt string) (int, error) {
	v, ok := p[sec][opt]
	if !ok {
		return 0, fmt.Errorf("profile %s.%s missing", sec, opt)
	}
	return strconv.Atoi(v)
}

// ParseIPv4 helper.
func ParseIPv4(s string) [4]byte {
	ip := net.ParseIP(s).To4()
	var out [4]byte
	if ip != nil {
		copy(out[:], ip)
	}
	return out
}
