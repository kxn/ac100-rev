package jcs

import (
	"os"
	"path/filepath"
	"strings"
	"testing"
)

// Deep-inspection detailed queries against the evidenced response contracts
// (deepinspect.go header): chnl usage inline, rssi/density via
// deep_checkup_result files, setting/status/scan-mode inline.
func TestDIQueryHandlers(t *testing.T) {
	oldDir := DeepCheckupFileDir
	DeepCheckupFileDir = t.TempDir()
	defer func() { DeepCheckupFileDir = oldDir }()

	s := NewServer()
	rs := NewRuntimeState(nil)
	tables := NewRuntimeTables(rs)
	rs.RegisterRuntimeHandlers(s, nil)
	tables.RegisterRuntimeQueryHandlers(s)
	di := NewDITables()
	di.RegisterDIQueryHandlers(s)
	path := testServe(t, s)

	call := func(module, kw, method string, params any) string {
		t.Helper()
		resp, err := Call(path, method, module, kw, params)
		if err != nil {
			t.Fatal(err)
		}
		return string(resp)
	}

	// chnl usage list: inline under deep_inspection_chnl_usage_list
	di.SetChnlUsage([]ChnlUsage{
		{Chnl: 6, ApNum: 2, SsidNum: 3, StaNum: 5, WifiUtil: 30, NonWifiUtil: 10, FreeUtil: 60}})
	resp := call("deep_inspection_chnl_usage_list", "get", "get", nil)
	if indexOfStr(resp, "deep_inspection_chnl_usage_list") < 0 ||
		indexOfStr(resp, "non_wifi_util") < 0 || indexOfStr(resp, `"ret":0`) < 0 {
		t.Fatalf("chnl usage = %s", resp)
	}

	// selected chnl usage (0x4d3094)
	resp = call("deep_inspection_selected_chnl_usage", "get", "get", nil)
	if indexOfStr(resp, "deep_inspection_selected_chnl_usage") < 0 ||
		indexOfStr(resp, "wifi_util") < 0 {
		t.Fatalf("selected usage = %s", resp)
	}

	// multi-chnl rssi: file contract (0x4d9164)
	di.SetChnlRssi([]ChnlRssi{
		{BSSID: "aa:bb:cc:dd:ee:f0", SSID: "a", RSSI: -50, PrimaryChnl: 36, CenterChnl: 38, BandWidth: 40},
		{BSSID: "aa:bb:cc:dd:ee:f1", SSID: "b", RSSI: -60, PrimaryChnl: 1, CenterChnl: 3, BandWidth: 40},
		{BSSID: "aa:bb:cc:dd:ee:f2", SSID: "c", RSSI: -70, PrimaryChnl: 6, CenterChnl: 8, BandWidth: 40}})
	resp = call("deep_inspection_multi_chnl_rssi", "get", "get", map[string]any{"start": 1, "end": 3})
	if indexOfStr(resp, "file_name") < 0 || indexOfStr(resp, `"total_num":2`) < 0 {
		t.Fatalf("rssi window = %s", resp)
	}
	b, err := os.ReadFile(filepath.Join(DeepCheckupFileDir, "deep_checkup_result_1"))
	if err != nil || !strings.Contains(string(b), "aa:bb:cc:dd:ee:f1") ||
		strings.Contains(string(b), "ee:f0") {
		t.Fatalf("rssi file = %s err %v", b, err)
	}

	// density: file contract (0x4d34cc)
	di.SetDensity([]int{10, 20, 30, 40, 50}, 30)
	resp = call("deep_inspection_multi_chnl_density", "get", "get", map[string]any{"start": 0, "end": 2})
	if indexOfStr(resp, "file_name") < 0 || indexOfStr(resp, `"total_num":2`) < 0 {
		t.Fatalf("density = %s", resp)
	}
	b, err = os.ReadFile(filepath.Join(DeepCheckupFileDir, "deep_checkup_result_0"))
	if err != nil || !strings.Contains(string(b), `[10,20]`) ||
		!strings.Contains(string(b), `"length":2`) || !strings.Contains(string(b), `"density":30`) {
		t.Fatalf("density file = %s err %v", b, err)
	}

	// status snapshot (0x4d28bc)
	di.SetDIStatus(DIStatus{OffLineSensor: 1, InspectionStatus: 2,
		InspectionRemainTime: 300, CurViewedSensor: 4, LastInspectionTime: 77})
	resp = call("deep_inspection_status", "get", "get", nil)
	if indexOfStr(resp, "off_line_sensor") < 0 || indexOfStr(resp, "inspection_remain_time") < 0 ||
		indexOfStr(resp, "cur_viewed_sensor") < 0 || indexOfStr(resp, "last_inspection_time") < 0 {
		t.Fatalf("status = %s", resp)
	}

	// scan mode query (0x4d2160)
	resp = call("get_deep_inspection_sensor_scan_mode_change", "get", "get",
		map[string]any{"entry_id": 1})
	if indexOfStr(resp, "deep_inspection_scan_mode_change") < 0 ||
		indexOfStr(resp, `"scan_mode":"yes"`) < 0 {
		t.Fatalf("scan mode = %s", resp)
	}

	// setting set/get
	if resp := call("set_deep_inspection_setting", "set", "set", map[string]any{
		"entry_id": 1, "entry_name": "di-1", "inspection_band": "5G",
		"inspection_item": "rssi", "scan_mode": "auto", "chnl": 36}); indexOfStr(resp, `"error_code":0`) < 0 {
		t.Fatalf("setting set = %s", resp)
	}
	resp = call("get_deep_inspection_setting", "get", "get", nil)
	if indexOfStr(resp, "di-1") < 0 || indexOfStr(resp, "5G") < 0 || indexOfStr(resp, `"ret":0`) < 0 {
		t.Fatalf("setting get = %s", resp)
	}
	s.Close()
}
