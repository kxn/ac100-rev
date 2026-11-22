package jcs

import (
	"encoding/json"
	"os"
	"strconv"
	"sync"
	"time"
)

// sensor management handlers — sensor_discover_trigger.set /
// sensor_list_added.get / sensor_manage_status.get
// (sensor_mngt_init @0x4e999c; handlers _sensor_jcs_discover_trigger
// @0x4e8bec, _sensor_jcs_sensor_list_added_get @0x4e3afc,
// _sensor_jcs_sensor_manage_status_get @0x4e25c8).
//
// State machine (g_sensor_state): 0 idle / 1 scanning / 2 scan_stop /
// 3 backhaul-test phase; the discovery window is 600 seconds.

// SensorListAddedFile is the vendor's fixed result path.
const SensorListAddedFile = "/tmp/sensor_list_added"

// UnfinishedSensor is one sensor under management (the vendor's
// unfinished_sensor_list entry).
type UnfinishedSensor struct {
	ApID       string `json:"ap_id"`
	MAC        string `json:"mac"`
	Name       string `json:"name"`
	GroupID    string `json:"group_id"`
	ModelName  string `json:"model_name"`
	TestStatus string `json:"test_status"`
}

// SensorMngtHooks receives the apmngr side-effects (sensor_add firms a
// discovered sensor into a managed AP entry — apmngr_ap_firm; finish
// purges the failures — apmngr_ap_delete).
type SensorMngtHooks struct {
	OnSensorAdd   func([]UnfinishedSensor)
	OnSensorPurge func([]UnfinishedSensor)
}

// SensorMngt is the sensor discovery state machine.
type SensorMngt struct {
	mu         sync.Mutex
	now        func() time.Time
	state      int // 0 idle, 1 scanning, 2 scan_stop, 3 backhaul testing
	discStart  time.Time
	groups     []int
	unfinished []UnfinishedSensor
	backhaul   int // 0 wait_for_test, 1 backhaul_testing, 2 finished
	passed     int
	failed     int
	hooks      SensorMngtHooks
}

// NewSensorMngt creates the state machine (optional hooks).
func NewSensorMngt(hooks SensorMngtHooks) *SensorMngt {
	return &SensorMngt{now: time.Now, hooks: hooks}
}

// SetNow injects a clock (tests).
func (m *SensorMngt) SetNow(f func() time.Time) { m.now = f }

// DiscoverWindow is the vendor's 600-second scan window.
const DiscoverWindow = 600 * time.Second

// Trigger runs one sensor_discover_trigger action. Returns the vendor's
// numeric ret code as a string ("%d" contract).
func (m *SensorMngt) Trigger(action string, groups, sensors []UnfinishedSensor) string {
	m.mu.Lock()
	defer m.mu.Unlock()
	switch action {
	case "begin":
		m.groups = groupsToInts(groups)
		m.discStart = m.now()
		m.state = 1
		m.backhaul, m.passed, m.failed = 0, 0, 0
		m.unfinished = nil
		return "0"
	case "scan_stop":
		if m.state == 1 {
			m.state = 2
		}
		return "0"
	case "sensor_add":
		// sensor_add @0x4e7ab4: firm the sensors and track them until the
		// backhaul test result arrives
		for _, s := range sensors {
			m.unfinished = append(m.unfinished, s)
		}
		if m.hooks.OnSensorAdd != nil {
			m.hooks.OnSensorAdd(sensors)
		}
		return "0"
	case "test_begin":
		// sensor_backhaul_test_start @0x4e820c
		m.state = 3
		m.backhaul = 1
		return "0"
	case "finish":
		// sensor_discover_finish @0x4e8818: requires the backhaul test to
		// have run; failed sensors are purged from the managed APs
		if m.backhaul == 0 {
			return "-1"
		}
		var purge []UnfinishedSensor
		kept := m.unfinished[:0]
		for _, s := range m.unfinished {
			if s.TestStatus == "failed" {
				purge = append(purge, s)
			} else {
				kept = append(kept, s)
			}
		}
		m.unfinished = kept
		if m.hooks.OnSensorPurge != nil && len(purge) > 0 {
			m.hooks.OnSensorPurge(purge)
		}
		m.state = 0
		return "0"
	case "exit":
		// sensor_discover_exit @0x4e8b58
		m.state = 0
		m.unfinished = nil
		return "0"
	}
	return "-1"
}

// SetBackhaulResult feeds the backhaul-test outcome (the sensor-side test
// result handler _sensor_backhaul_test_result_handle @0x4e33e4).
func (m *SensorMngt) SetBackhaulResult(passed, failed int) {
	m.mu.Lock()
	defer m.mu.Unlock()
	m.passed, m.failed = passed, failed
	switch {
	case failed == 0:
		m.backhaul = 2 // backhaul_test_finished
	case passed == 0:
		m.backhaul = 3 // backhaul_test_failed
	default:
		m.backhaul = 4 // backhaul_test_part_failed
	}
}

// AddSensors records sensors discovered/managed (test status updates).
func (m *SensorMngt) AddSensors(items []UnfinishedSensor) {
	m.mu.Lock()
	defer m.mu.Unlock()
	m.unfinished = append(m.unfinished, items...)
}

func groupsToInts(sensors []UnfinishedSensor) []int {
	out := make([]int, 0, len(sensors))
	for _, s := range sensors {
		id, _ := strconv.Atoi(s.GroupID)
		out = append(out, id)
	}
	return out
}

// RegisterSensorMngtHandlers installs the three sensor-management
// handlers (after RegisterBatch3Handlers).
func RegisterSensorMngtHandlers(s *Server, m *SensorMngt) {
	// sensor_discover_trigger.set: {action, group_list?, sensor_list?}
	s.replaceNotImpl("sensor_discover_trigger.set", func(req json.RawMessage) (any, error) {
		var q struct {
			Action     string   `json:"action"`
			GroupList  []string `json:"group_list"`
			SensorList []string `json:"sensor_list"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &q); err != nil {
				return nil, err
			}
		}
		groups := make([]UnfinishedSensor, 0, len(q.GroupList))
		for _, g := range q.GroupList {
			groups = append(groups, UnfinishedSensor{GroupID: g})
		}
		sensors := make([]UnfinishedSensor, 0, len(q.SensorList))
		for _, id := range q.SensorList {
			sensors = append(sensors, UnfinishedSensor{ApID: id})
		}
		ret := m.Trigger(q.Action, groups, sensors)
		return map[string]any{"error_code": 0, "ret": ret}, nil
	})

	// sensor_list_added.get: {start, end} window over the managed list;
	// answers {ret, total_num, file_name} + the JSON file
	s.replaceNotImpl("sensor_list_added.get", func(req json.RawMessage) (any, error) {
		var q struct {
			Start int `json:"start"`
			End   int `json:"end"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &q); err != nil {
				return nil, err
			}
		}
		m.mu.Lock()
		state := m.state
		all := m.unfinished
		m.mu.Unlock()
		// -2 outside the managed (backhaul test) phase — the binary gates
		// on g_sensor_enable / g_backhaul_wserv_id / g_sensor_state != 3
		if state != 3 {
			return map[string]any{"error_code": 0, "ret": "-2"}, nil
		}
		if q.Start < 0 || q.End < q.Start {
			return map[string]any{"error_code": 0, "ret": "-1"}, nil
		}
		end := q.End
		if end > len(all) {
			end = len(all)
		}
		pageRows := []UnfinishedSensor{}
		if q.Start < end {
			pageRows = all[q.Start:end]
		}
		body, _ := json.Marshal(pageRows)
		if err := os.WriteFile(SensorListAddedFile, body, 0644); err != nil {
			return jerr(err), nil
		}
		return map[string]any{"error_code": 0, "ret": "0",
			"total_num": strconv.Itoa(len(all)), "file_name": SensorListAddedFile}, nil
	})

	// sensor_manage_status.get: {status, remain_time, ret} (all strings)
	s.replaceNotImpl("sensor_manage_status.get", func(json.RawMessage) (any, error) {
		m.mu.Lock()
		state, backhaul := m.state, m.backhaul
		start := m.discStart
		m.mu.Unlock()
		status := "idle"
		switch state {
		case 1:
			status = "scanning"
		case 2:
			status = "scan_stop"
		case 3:
			switch backhaul {
			case 1:
				status = "backhaul_testing"
			case 2:
				status = "backhaul_test_finished"
			case 3:
				status = "backhaul_test_failed"
			case 4:
				status = "backhaul_test_part_failed"
			default:
				status = "wait_for_test"
			}
		}
		remain := int64(0)
		if state == 1 {
			// remain = start + 600 − now (only while scanning)
			remain = int64((start.Add(DiscoverWindow).Sub(m.now()) + time.Second - 1) / time.Second)
			if remain < 0 {
				remain = 0
			}
		}
		return map[string]any{"error_code": 0, "status": status,
			"remain_time": strconv.FormatInt(remain, 10), "ret": "0"}, nil
	})
}
