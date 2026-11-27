// Package cweng — store.go loads the runtime data files extracted from the
// firmware (the Go port never reads the firmware image at runtime; everything
// it depends on lives in data/):
//
//	data/apdb.json    — complete normal/multi-AP library from /etc/apdb.bin
//	                    (DES-ECB + payload MD5; audit_model_library.go)
//	data/apdb-nego.json— optional firmware-indexed AP negotiation metadata
//	data/identity.json— AC identity shown in responses (matches the vendor's
//	                    .data fixture values)
//	data/profile.ini  — reconstructed profile for research adapters only;
//	                    the standalone daemon uses Go resource defaults.
package cweng

import (
	"encoding/json"
	"fmt"
	"net"
	"os"
	"path/filepath"
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
	Version     string            `json:"version"`
	Vendor      int               `json:"vendor"`
	APList      []APDBModel       `json:"ap_list"`
	MultiAPList []APDBModel       `json:"multi_ap_list"`
	Negotiated  []NegotiatedModel `json:"-"`
}
type APDBModel struct {
	APName       string `json:"ap_name"`
	ID           uint64 `json:"id"`
	HardwareID   string `json:"hardware_id"`
	MeshDevice   bool   `json:"is_mesh_device"`
	SupportTrunk bool   `json:"support_ap_trunk"`
	Models       []struct {
		HWVer  string               `json:"hwver"`
		Radios map[string]APDBRadio `json:"radios"`
	} `json:"models"`
}
type APDBRadio struct {
	MaxSSID          int    `json:"max_ssid"`
	MaxStations      int    `json:"max_stations"`
	MaxTxPower       int    `json:"max_tx_power"`
	MinTxPower       int    `json:"min_tx_power"`
	DftTxPower       int    `json:"dft_tx_power"`
	DftBWMode        *int   `json:"dft_bw_mode"`
	Support11Ac      any    `json:"support_11ac"`
	Support11Ax      any    `json:"support_11ax"`
	Support11Be      any    `json:"support_11be"`
	Support160       any    `json:"support_160M"`
	Support240       any    `json:"support_240M"`
	Support80P80     any    `json:"support_80M_80M"`
	SupportWPA3      any    `json:"support_WPA3"`
	MaxTxStream      int    `json:"max_tx_stream"`
	MaxRxStream      int    `json:"max_rx_stream"`
	MutexChannel     string `json:"mutex_channel"`
	ExtendCapability string `json:"extend_capability"`
	FunctionType     int    `json:"radio_func_type"`
}
type NegotiatedModel struct {
	ID          uint64 `json:"id"`
	APName      string `json:"ap_name"`
	FirmwareIDs []struct {
		FirmwareID string `json:"fwid"`
		Index      int    `json:"ap_index"`
	} `json:"fwid_list"`
	APList []APDBModel `json:"ap_list"`
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
	if data, err := os.ReadFile(filepath.Join(filepath.Dir(path), "apdb-nego.json")); err == nil {
		var cache struct {
			Items []NegotiatedModel `json:"ap_item_list"`
		}
		if err := json.Unmarshal(data, &cache); err != nil {
			return nil, fmt.Errorf("apdb negotiated cache: %w", err)
		}
		db.Negotiated = cache.Items
	} else if !os.IsNotExist(err) {
		return nil, err
	}
	return &db, nil
}

// LookupAP finds a model entry by AP name (the binary matches via apdb_init +
// cw_apdb joins; model ids come from the WTP Board Data 0x26 sub-element).
func (db *APDB) LookupAP(name string) *struct {
	APName string
	ID     uint64
} {
	for _, a := range db.Models() {
		if a.APName == name {
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
