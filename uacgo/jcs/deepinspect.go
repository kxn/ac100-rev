package jcs

import (
	"encoding/json"
	"fmt"
	"os"
	"sync"
)

// sensor-di deep-inspection detailed query handlers — response contracts
// typed from the binary (this round; string refs extracted per function):
//
//   jcs_deep_inspection_chnl_usage_list @0x4d2bfc: rows {chnl@0x6ab8e0,
//     wifi_util@0x6a9964, non_wifi_util@0x6a9960, free_util@0x6a9970,
//     ap_num@0x6a997c, ssid_num@0x6a9984, sta_num@0x6a1bc0} all "%d";
//     inline wrapper "deep_inspection_chnl_usage_list"@0x6a9990 + ret.
//   jcs_deep_inspection_selected_chnl_usage @0x4d3094: {chnl, time@0x694304,
//     wifi_util, non_wifi_util} → "deep_inspection_selected_chnl_usage"
//     @0x6a9b28 + ret (inline).
//   jcs_deep_inspection_multi_chnl_rssi @0x4d9164: rows {rssi, center_chnl
//     @0x6ab8cc, primary_chnl@0x6ab8d8, band_width@0x6ab8e8, bssid, ssid};
//     FILE "/tmp/deep_checkup_result_%d"@0x6a9d44 ("w+") → resp file_name.
//   jcs_deep_inspection_multi_chnl_density @0x4d34cc: {start, end,
//     density@0x6a9cd0, spectrums@0x6a9cd8, length@0x6d93f0}; FILE
//     "/tmp/deep_checkup_result_%d" → resp file_name.
//   jcs_get_deep_inspection_setting @0x4d24c0: {entry_id@0x6775e0,
//     entry_name@0x6a1ba8, inspection_item@0x6a975c, inspection_band
//     @0x6a976c, scan_mode@0x6a9670, chnl} → "deep_inspection_setting"
//     @0x6abb98 + ret (inline).
//   jcs_deep_inspection_status @0x4d28bc: {off_line_sensor@0x6a9804,
//     inspection_status@0x6a9814, inspection_remain_time@0x6a9828,
//     cur_viewed_sensor@0x6a9840, last_inspection_time@0x6a9854} + ret
//     (inline).
//   jcs_get_deep_inspection_sensor_scan_mode_change @0x4d2160: request
//     {entry_id} → "deep_inspection_scan_mode_change"@0x6abbb4 {scan_mode,
//     chnl} + ret ("yes"/"true" literals).

// ChnlUsage is one channel-usage row.
type ChnlUsage struct {
	Chnl        int `json:"chnl"`
	ApNum       int `json:"ap_num"`
	SsidNum     int `json:"ssid_num"`
	StaNum      int `json:"sta_num"`
	WifiUtil    int `json:"wifi_util"`
	NonWifiUtil int `json:"non_wifi_util"`
	FreeUtil    int `json:"free_util"`
}

// ChnlRssi is one multi-channel RSSI row.
type ChnlRssi struct {
	BSSID       string `json:"bssid"`
	SSID        string `json:"ssid"`
	RSSI        int    `json:"rssi"`
	PrimaryChnl int    `json:"primary_chnl"`
	CenterChnl  int    `json:"center_chnl"`
	BandWidth   int    `json:"band_width"`
}

// DISetting is the deep-inspection configuration.
type DISetting struct {
	EntryID        int64  `json:"entry_id"`
	EntryName      string `json:"entry_name"`
	InspectionBand string `json:"inspection_band"`
	InspectionItem string `json:"inspection_item"`
	ScanMode       string `json:"scan_mode"`
	Chnl           int    `json:"chnl"`
}

// DIStatus is the jcs_deep_inspection_status snapshot.
type DIStatus struct {
	OffLineSensor        int   `json:"off_line_sensor"`
	InspectionStatus     int   `json:"inspection_status"`
	InspectionRemainTime int   `json:"inspection_remain_time"`
	CurViewedSensor      int   `json:"cur_viewed_sensor"`
	LastInspectionTime   int64 `json:"last_inspection_time"`
}

// DITables holds the deep-inspection queryable lists.
type DITables struct {
	mu        sync.Mutex
	usage     []ChnlUsage
	rssi      []ChnlRssi
	density   []int // per-channel density values; start..end window
	densityAv int
	setting   DISetting
	status    DIStatus
	scanMode  string // "yes"/"true" per 0x4d2160
	srv       *Server
}

// DeepCheckupFileDir is where the vendor drops deep_checkup_result files.
var DeepCheckupFileDir = "/tmp"

// NewDITables creates the lists.
func NewDITables() *DITables { return &DITables{} }

// SetChnlUsage replaces the channel-usage rows.
func (d *DITables) SetChnlUsage(rows []ChnlUsage) {
	d.mu.Lock()
	d.usage = rows
	d.mu.Unlock()
}

// SetChnlRssi replaces the RSSI rows.
func (d *DITables) SetChnlRssi(rows []ChnlRssi) {
	d.mu.Lock()
	d.rssi = rows
	d.mu.Unlock()
}

// SetDensity replaces the density spectrum (values + average).
func (d *DITables) SetDensity(values []int, average int) {
	d.mu.Lock()
	d.density = values
	d.densityAv = average
	d.mu.Unlock()
}

// SetDISetting stores the inspection configuration.
func (d *DITables) SetDISetting(s DISetting) {
	d.mu.Lock()
	d.setting = s
	d.mu.Unlock()
}

// SetDIStatus stores the inspection status snapshot.
func (d *DITables) SetDIStatus(st DIStatus) {
	d.mu.Lock()
	d.status = st
	d.mu.Unlock()
}

// RegisterDIQueryHandlers installs the deep-inspection query handlers
// (must run after RegisterBatch3Handlers to overwrite placeholders).
func (d *DITables) RegisterDIQueryHandlers(s *Server) {
	d.srv = s
	s.replaceNotImpl("deep_inspection_chnl_usage_list.get", func(json.RawMessage) (any, error) {
		d.mu.Lock()
		list := d.usage
		d.mu.Unlock()
		if list == nil {
			list = []ChnlUsage{}
		}
		return map[string]any{"error_code": 0, "ret": 0,
			"deep_inspection_chnl_usage_list": list}, nil
	})
	// selected channel usage (0x4d3094)
	s.replaceNotImpl("deep_inspection_selected_chnl_usage.get", func(json.RawMessage) (any, error) {
		d.mu.Lock()
		list := d.usage
		st := d.status
		d.mu.Unlock()
		if list == nil {
			list = []ChnlUsage{}
		}
		var sel []map[string]any
		for _, u := range list {
			sel = append(sel, map[string]any{"chnl": u.Chnl,
				"time":      st.LastInspectionTime,
				"wifi_util": u.WifiUtil, "non_wifi_util": u.NonWifiUtil})
		}
		return map[string]any{"error_code": 0, "ret": 0,
			"deep_inspection_selected_chnl_usage": sel}, nil
	})
	// multi-chnl rssi: rows → deep_checkup_result file (0x4d9164)
	s.replaceNotImpl("deep_inspection_multi_chnl_rssi.get", func(req json.RawMessage) (any, error) {
		var q struct {
			Start int `json:"start"`
			End   int `json:"end"`
		}
		if len(req) > 0 {
			_ = json.Unmarshal(req, &q)
		}
		d.mu.Lock()
		rows := d.rssi
		d.mu.Unlock()
		if rows == nil {
			rows = []ChnlRssi{}
		}
		start, end := clampWindow(q.Start, q.End, len(rows))
		body, _ := json.Marshal(rows[start:end])
		path := fmt.Sprintf("%s/deep_checkup_result_%d", DeepCheckupFileDir, start)
		if err := os.WriteFile(path, body, 0644); err != nil {
			return jerr(err), nil
		}
		if end-start <= 0 {
			return ok(), nil
		}
		return map[string]any{"error_code": 0, "file_name": path,
			"total_num": end - start}, nil
	})
	// density spectrum → deep_checkup_result file (0x4d34cc)
	s.replaceNotImpl("deep_inspection_multi_chnl_density.get", func(req json.RawMessage) (any, error) {
		var q struct {
			Start int `json:"start"`
			End   int `json:"end"`
		}
		if len(req) > 0 {
			_ = json.Unmarshal(req, &q)
		}
		d.mu.Lock()
		spec := d.density
		d.mu.Unlock()
		start, end := clampWindow(q.Start, q.End, len(spec))
		win := spec[start:end]
		if win == nil {
			win = []int{}
		}
		body, _ := json.Marshal(map[string]any{"start": start, "end": end,
			"density": d.densityAv, "spectrums": win, "length": len(win)})
		path := fmt.Sprintf("%s/deep_checkup_result_%d", DeepCheckupFileDir, start)
		if err := os.WriteFile(path, body, 0644); err != nil {
			return jerr(err), nil
		}
		if len(win) <= 0 {
			return ok(), nil
		}
		return map[string]any{"error_code": 0, "file_name": path,
			"total_num": len(win)}, nil
	})
	s.replaceNotImpl("get_deep_inspection_setting.get", func(json.RawMessage) (any, error) {
		d.mu.Lock()
		set := d.setting
		d.mu.Unlock()
		return map[string]any{"error_code": 0, "ret": 0,
			"deep_inspection_setting": set}, nil
	})
	// inspection status snapshot (0x4d28bc)
	s.replaceNotImpl("deep_inspection_status.get", func(json.RawMessage) (any, error) {
		d.mu.Lock()
		st := d.status
		d.mu.Unlock()
		return map[string]any{"error_code": 0, "ret": 0,
			"off_line_sensor":        st.OffLineSensor,
			"inspection_status":      st.InspectionStatus,
			"inspection_remain_time": st.InspectionRemainTime,
			"cur_viewed_sensor":      st.CurViewedSensor,
			"last_inspection_time":   st.LastInspectionTime,
		}, nil
	})
	// scan mode query (0x4d2160): entry_id → {scan_mode, chnl}
	s.replaceNotImpl("get_deep_inspection_sensor_scan_mode_change.get", func(req json.RawMessage) (any, error) {
		var q struct {
			EntryID int64 `json:"entry_id"`
		}
		if len(req) > 0 {
			_ = json.Unmarshal(req, &q)
		}
		d.mu.Lock()
		set := d.setting
		d.mu.Unlock()
		mode := d.scanMode
		if mode == "" {
			mode = "yes"
		}
		return map[string]any{"error_code": 0, "ret": 0,
			"deep_inspection_scan_mode_change": map[string]any{
				"entry_id": q.EntryID, "scan_mode": mode, "chnl": set.Chnl}}, nil
	})
	s.replaceNotImpl("set_deep_inspection_setting.set", func(req json.RawMessage) (any, error) {
		var set DISetting
		if err := json.Unmarshal(req, &set); err != nil {
			return nil, err
		}
		d.SetDISetting(set)
		return ok(), nil
	})
}

func clampWindow(start, end, n int) (int, int) {
	if start < 0 {
		start = 0
	}
	if start > n {
		start = n
	}
	if end <= 0 || end > n {
		end = n
	}
	if end < start {
		end = start
	}
	return start, end
}
