package jcs

import (
	"encoding/json"
	"os"
	"strconv"
	"sync"
	"sync/atomic"
	"time"
)

// Runtime query handlers for the remaining registrations (field sets from
// export/decomp, batch-3 round):
//
//   wips event info get  : count/criterion/entry_name/dev_mac/
//     discover_time_list paging (start/end)
//   wips statistics get  : per-sensor normal/severe/slight event counts
//     (end_ts, group/group_name, sensor, num)
//   wips statistics_num  : dos_attack/illegal_dev/interfering_dev/threat_dev
//   mesh topology / discover list : paged (total_num/start/size)
//   deep checkup pkt lists (ssid/bssid/sta): chnl/name/percent/ssid_id
//   ac_manualrrm set     : manual RRM trigger (timestamp persisted)

// WipsEvent is one intrusion-event record (wips_entry 0xB0B).
type WipsEvent struct {
	ID            int    `json:"id"`
	EntryName     string `json:"entry_name"`
	Sensor        string `json:"sensor"`
	Type          string `json:"type"` // normal / slight / severe / dos…
	ThreatClass   int    `json:"wips_threat_class_id"`
	ThreatName    string `json:"wips_threat_classname"`
	GroupID       string `json:"group_id"`
	DevMAC        string `json:"dev_mac"`
	Rssi          string `json:"rssi"`
	Time          int64  `json:"discover_time"`
	CounterStatus int    `json:"counter_status"` // 0 none / 1 counter / 2 discounter
	Whitelisted   bool   `json:"-"`              // whitelist_entry state (+0xa8==2)
	Details       []WipsDetail
}

// WipsDetail is one detection sample inside an event (entry+0x9c detail
// list; wips_detail_to_json @0x4c62c0 fields).
type WipsDetail struct {
	DiscoveryTime string `json:"discovery_time"`
	LastTime      string `json:"last_time"`
	Duration      string `json:"duration"`
	ThreatType    string `json:"wips_threat_type"`
	ThreatName    string `json:"wips_threat_name"`
	Rssi          string `json:"rssi"`
	EntryName     string `json:"entry_name"`
	GroupID       string `json:"group_id"`
}

// RuntimeTables extends RuntimeState with queryable lists.
type RuntimeTables struct {
	rs         *RuntimeState
	mu         sync.Mutex
	events     []WipsEvent
	statsNum   map[string]int // dos/illegal/interfering/threat
	meshNodes  []map[string]any
	topoNodes  []MeshTopologyNode          // ac_mesh_topology.get node set
	wanStatus  int8                        // mesh wan_status global (0x4bb12c)
	checkup    map[string][]map[string]any // ssid/bssid/sta lists
	lastManual int64                       // last manual-RRM trigger ts
	db         interface {
		Exec(string, ...any) (interface{ RowsAffected() (int64, error) }, error)
	}
}

// NewRuntimeTables wraps a RuntimeState with the queryable lists.
func NewRuntimeTables(rs *RuntimeState) *RuntimeTables {
	return &RuntimeTables{rs: rs, statsNum: map[string]int{},
		checkup: make(map[string][]map[string]any)}
}

// AddWipsEvent appends one event and bumps its class counter.
func (t *RuntimeTables) AddWipsEvent(e WipsEvent) {
	t.mu.Lock()
	t.events = append(t.events, e)
	t.statsNum[e.Type]++
	t.mu.Unlock()
}

// SetMeshDiscoverList replaces the mesh discovery/topology node list.
func (t *RuntimeTables) SetMeshDiscoverList(nodes []map[string]any) {
	t.mu.Lock()
	t.meshNodes = nodes
	t.mu.Unlock()
}

// SetCheckupList replaces one deep-checkup list ("ssid"/"bssid"/"sta").
func (t *RuntimeTables) SetCheckupList(kind string, list []map[string]any) {
	t.mu.Lock()
	t.checkup[kind] = list
	t.mu.Unlock()
}

// TriggerManualRRM records the manual RRM trigger.
func (t *RuntimeTables) TriggerManualRRM() int64 {
	t.mu.Lock()
	t.lastManual = time.Now().Unix()
	ts := t.lastManual
	t.mu.Unlock()
	return ts
}

func page[T any](list []T, start, size int) ([]T, int) {
	if start > len(list) {
		start = len(list)
	}
	out := list[start:]
	if size > 0 && size < len(out) {
		out = out[:size]
	}
	return out, len(list)
}

// checkupFileSeq numbers the /tmp/deep_checkup_result_<n> files
// (the vendor uses a process-local counter).
var checkupFileSeq int64

func nextCheckupFile() string {
	return "/tmp/deep_checkup_result_" + strconv.FormatInt(atomic.AddInt64(&checkupFileSeq, 1), 10)
}

// RegisterRuntimeQueryHandlers installs the query/trigger handlers
// (must run after RegisterBatch3Handlers to overwrite placeholders).
func (t *RuntimeTables) RegisterRuntimeQueryHandlers(s *Server) {
	// mesh topology get + wan status set (evidenced handlers,
	// mesh_topology.go)
	t.registerMeshTopologyHandlers(s)
	// wips event info get: paged events (criteria via entry_name/sensor)
	s.replaceNotImpl("wips_event_info.get", func(req json.RawMessage) (any, error) {
		var q struct {
			EntryName string `json:"entry_name"`
			Sensor    string `json:"sensor"`
			Start     int    `json:"start"`
			End       int    `json:"end"`
			Count     int    `json:"count"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &q); err != nil {
				return nil, err
			}
		}
		t.mu.Lock()
		defer t.mu.Unlock()
		filtered := []WipsEvent{}
		for _, e := range t.events {
			if q.EntryName != "" && e.EntryName != q.EntryName {
				continue
			}
			if q.Sensor != "" && e.Sensor != q.Sensor {
				continue
			}
			filtered = append(filtered, e)
		}
		start := q.Start
		if start < 0 {
			start = 0
		}
		end := q.End
		if end <= 0 || end > len(filtered) {
			end = len(filtered)
		}
		if start > end {
			start = end
		}
		pageEvents := filtered[start:end]
		return map[string]any{
			"error_code": 0, "count": len(pageEvents), "total": len(filtered),
			"event_list": pageEvents}, nil
	})
	// wips statistics get: per-sensor counts
	s.replaceNotImpl("wips_statistics.get", func(json.RawMessage) (any, error) {
		t.mu.Lock()
		defer t.mu.Unlock()
		agg := map[string]*statRow{}
		for _, e := range t.events {
			row := agg[e.Sensor]
			if row == nil {
				row = &statRow{Sensor: e.Sensor}
				agg[e.Sensor] = row
			}
			switch e.Type {
			case "severe":
				row.Severe++
			case "slight":
				row.Slight++
			default:
				row.Normal++
			}
		}
		list := []any{}
		for _, r := range agg {
			list = append(list, r)
		}
		return map[string]any{"error_code": 0, "statistics_list": list}, nil
	})
	// wips statistics_num get: the four class counters
	s.replaceNotImpl("wips_statistics_num.get", func(json.RawMessage) (any, error) {
		t.mu.Lock()
		defer t.mu.Unlock()
		return map[string]any{"error_code": 0,
			"dos_attack_num":      t.statsNum["dos"],
			"illegal_dev_num":     t.statsNum["illegal"],
			"interfering_dev_num": t.statsNum["interfering"],
			"threat_dev_num":      t.statsNum["severe"]}, nil
	})
	// mesh discover list: {start,size} → serialize rows to
	// /tmp/mesh_discover_list ("w+") and answer {file_name,total_num}
	// (mesh_jcs_discover_list_get @0x4be2f8: request keys start@0x67851c
	// size@0x710ccc, path@0x6a43d8, response keys 0x6770b4/0x6e1444; row
	// model from mesh_db_discover_entry_dump_all @0x4b815c — 104B entries
	// with mac @+12 and the vendor's own state/type strings
	// Idle/Discovering/Discover Finished, AP/Router/Unknown, Fit/Fat,
	// Wired/Wireless)
	s.replaceNotImpl("ac_mesh_discover_list.get", func(req json.RawMessage) (any, error) {
		var q struct {
			Start int `json:"start"`
			Size  int `json:"size"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &q); err != nil {
				return nil, err
			}
		}
		t.mu.Lock()
		nodes := t.meshNodes
		t.mu.Unlock()
		pageNodes, total := page(nodes, q.Start, q.Size)
		if pageNodes == nil {
			pageNodes = []map[string]any{}
		}
		body, _ := json.Marshal(pageNodes)
		if err := os.WriteFile(MeshDiscoverListFile, body, 0644); err != nil {
			return jerr(err), nil
		}
		if total <= 0 {
			return ok(), nil
		}
		return map[string]any{"error_code": 0, "file_name": MeshDiscoverListFile,
			"total_num": total}, nil
	})
	// deep checkup pkt lists — the vendor file contract
	// (jcs_deep_checkup_pkt_ssid_list @0x4d44b0 / _bssid_list @0x4d87c0 /
	// _sta_list @0x4d7d88): results serialized to
	// /tmp/deep_checkup_result_<counter>, answered as {file_name, ret}
	// plus the list count; bssid/sta take {start,end} windows, ssid takes
	// {entry_id, chnl}.
	for kind, key := range map[string]string{
		"ssid":  "deep_checkup_pkt_ssid_list.get",
		"bssid": "deep_checkup_pkt_bssid_list.get",
		"sta":   "deep_checkup_pkt_sta_list.get",
	} {
		kind, key := kind, key
		s.replaceNotImpl(key, func(req json.RawMessage) (any, error) {
			var q struct {
				Start int `json:"start"`
				End   int `json:"end"`
				Chnl  int `json:"chnl"`
			}
			if len(req) > 0 {
				if err := json.Unmarshal(req, &q); err != nil {
					return nil, err
				}
			}
			t.mu.Lock()
			list := t.checkup[kind]
			t.mu.Unlock()
			if list == nil {
				list = []map[string]any{}
			}
			windowed := list
			if kind != "ssid" {
				start, end := clampWindow(q.Start, q.End, len(list))
				windowed = list[start:end]
			}
			file := nextCheckupFile()
			body, _ := json.Marshal(map[string]any{
				"deep_checkup_pkt_" + kind + "_list": windowed,
			})
			if err := os.WriteFile(file, body, 0644); err != nil {
				return jerr(err), nil
			}
			resp := map[string]any{"error_code": 0, "file_name": file, "ret": 0}
			if kind == "bssid" {
				resp["bssid_list_cnt"] = len(list)
			}
			if kind == "sta" {
				resp["sta_list_cnt"] = len(list)
			}
			return resp, nil
		})
	}
	// ac_manualrrm set: trigger + timestamp persist
	s.replaceNotImpl("ac_manualrrm.set", func(json.RawMessage) (any, error) {
		ts := t.TriggerManualRRM()
		return map[string]any{"error_code": 0, "trigger_time": ts}, nil
	})
}

type statRow struct {
	Sensor string
	Normal int
	Slight int
	Severe int
}

// MarshalJSON flattens statRow per the statistics get fields.
func (r *statRow) MarshalJSON() ([]byte, error) {
	return json.Marshal(map[string]any{
		"sensor": r.Sensor, "normal_event_count": r.Normal,
		"slight_event_count": r.Slight, "severe_event_count": r.Severe})
}
