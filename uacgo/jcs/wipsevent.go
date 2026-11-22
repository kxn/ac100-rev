package jcs

import (
	"database/sql"
	"encoding/json"
)

// wips event set / detail get — the last two wips registrations of
// wips_init @0x4cb710.
//
// Evidence: wips_jcs_callback_wips_event_info_set @0x4cc42c (params
// {wips_info_ids: []int, operation: int}; operation 1 counter /
// 2 discounter / 3 whitelist-add gated on threat class {5,6}) and
// wips_jcs_callback_wips_event_detail_get @0x4c7570 (params
// {wips_info_id, start, size}; response {result, count, ret}).

// WipsEventOps receives the counter side-effects (wips_counter_send to
// the sensor APs). Optional.
type WipsEventOps struct {
	OnCounter    func(devMACs []string)
	OnDiscounter func(devMACs []string)
}

// RegisterWipsEventHandlers installs wips_event_info.set and
// wips_event_detail.get (after RegisterBatch3Handlers). sensorDB enables
// the whitelist persistence (whitelist_table); nil keeps it in memory.
func RegisterWipsEventHandlers(s *Server, t *RuntimeTables, sensorDB *sql.DB, ops *WipsEventOps) {
	if ops == nil {
		ops = &WipsEventOps{}
	}
	// wips_event_info.set: counter / discounter / whitelist
	s.replaceNotImpl("wips_event_info.set", func(req json.RawMessage) (any, error) {
		var q struct {
			IDs       []int `json:"wips_info_ids"`
			Operation int   `json:"operation"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &q); err != nil {
				return nil, err
			}
		}
		t.mu.Lock()
		defer t.mu.Unlock()
		byID := map[int]*WipsEvent{}
		for i := range t.events {
			byID[t.events[i].ID] = &t.events[i]
		}
		switch q.Operation {
		case 1: // counter ("发起对抗"): skip counted/whitelisted devices
			var macs []string
			for _, id := range q.IDs {
				e := byID[id]
				if e == nil || e.CounterStatus == 1 || e.Whitelisted {
					continue
				}
				e.CounterStatus = 1
				macs = append(macs, e.DevMAC)
			}
			if ops.OnCounter != nil && len(macs) > 0 {
				ops.OnCounter(macs)
			}
		case 2: // discounter ("取消对抗")
			var macs []string
			for _, id := range q.IDs {
				e := byID[id]
				if e == nil || e.CounterStatus == 2 {
					continue
				}
				e.CounterStatus = 2
				macs = append(macs, e.DevMAC)
			}
			if ops.OnDiscounter != nil && len(macs) > 0 {
				ops.OnDiscounter(macs)
			}
		case 3: // whitelist (trusted device): threat class 5/6 only
			for _, id := range q.IDs {
				e := byID[id]
				if e == nil {
					continue
				}
				if e.ThreatClass != 5 && e.ThreatClass != 6 {
					return map[string]any{"error_code": 0, "ret": -1}, nil
				}
				if e.Whitelisted {
					return map[string]any{"error_code": 0, "ret": -3}, nil // duplicate
				}
				e.Whitelisted = true
				e.CounterStatus = 0
				if sensorDB != nil {
					var maxID int
					_ = sensorDB.QueryRow(`SELECT COALESCE(MAX(whitelist_id),0) FROM whitelist_table`).Scan(&maxID)
					if _, err := sensorDB.Exec(
						`INSERT INTO whitelist_table(whitelist_id, mac, ssid, ssid_encode, sensor_id, rssi, last_discover_time, operation_time) VALUES(?,?,?,?,?,?,?,?)`,
						maxID+1, e.DevMAC, "", 0, e.Sensor, e.Rssi, e.Time, e.Time); err != nil {
						return jerr(err), nil
					}
				}
			}
		default:
			return map[string]any{"error_code": 0, "ret": -1}, nil
		}
		return map[string]any{"error_code": 0, "ret": 0}, nil
	})

	// wips_event_detail.get: {wips_info_id, start, size} over the event's
	// detail list
	s.replaceNotImpl("wips_event_detail.get", func(req json.RawMessage) (any, error) {
		var q struct {
			ID    int `json:"wips_info_id"`
			Start int `json:"start"`
			Size  int `json:"size"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &q); err != nil {
				return nil, err
			}
		}
		t.mu.Lock()
		defer t.mu.Unlock()
		for i := range t.events {
			if t.events[i].ID != q.ID {
				continue
			}
			rows, total := page(t.events[i].Details, q.Start, q.Size)
			if rows == nil {
				rows = []WipsDetail{}
			}
			return map[string]any{"error_code": 0, "result": rows,
				"count": total, "ret": 0}, nil
		}
		return map[string]any{"error_code": 0, "ret": -1}, nil
	})
}

// NextWipsID allocates the event id (g_wips_id_allocator).
func (t *RuntimeTables) NextWipsID() int {
	t.mu.Lock()
	defer t.mu.Unlock()
	max := 0
	for _, e := range t.events {
		if e.ID > max {
			max = e.ID
		}
	}
	return max + 1
}

// AddWipsDetail appends a detection sample to one event.
func (t *RuntimeTables) AddWipsDetail(id int, d WipsDetail) {
	t.mu.Lock()
	defer t.mu.Unlock()
	for i := range t.events {
		if t.events[i].ID == id {
			t.events[i].Details = append(t.events[i].Details, d)
			return
		}
	}
}
