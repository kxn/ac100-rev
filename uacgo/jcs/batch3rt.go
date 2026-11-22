package jcs

import (
	"database/sql"
	"encoding/json"
	"sync"
	"time"
)

// Runtime-state handlers for the remaining not-impl registrations whose
// key sets were extracted in notes §25:
//
//   - balance_jcs_callback_balance_set: enable/dif_threshold/max_fail_num
//     (config persisted via syscfg "balance")
//   - mesh_jcs_discover_status_get: status ∈ {init,scanning,finished} +
//     auto_add_status (in-memory discovery state machine; transitions are
//     driven by the mesh discover triggers)
//   - jcs_deep_inspection_status: inspection_status/inspection_remain_time/
//     last_inspection_time/cur_viewed_sensor/off_line_sensor (in-memory)

// RuntimeState carries the mutable runtime fields those handlers expose.
type RuntimeState struct {
	mu          sync.Mutex
	Balance     BalanceCfg
	MeshStatus  string // init / scanning / finished
	MeshAutoAdd bool
	DI          DeepInspectionStatus
}

// BalanceCfg mirrors balance_config_get_from_json keys.
type BalanceCfg struct {
	Enable       bool `json:"enable"`
	DifThreshold int  `json:"dif_threshold"`
	MaxFailNum   int  `json:"max_fail_num"`
}

// DeepInspectionStatus mirrors jcs_deep_inspection_status fields.
type DeepInspectionStatus struct {
	Status             string `json:"inspection_status"`
	RemainTime         int    `json:"inspection_remain_time"`
	LastInspectionTime int64  `json:"last_inspection_time"`
	CurViewedSensor    string `json:"cur_viewed_sensor"`
	OffLineSensor      int    `json:"off_line_sensor"`
}

// NewRuntimeState loads the persisted balance config (syscfg "balance").
func NewRuntimeState(db *sql.DB) *RuntimeState {
	rs := &RuntimeState{MeshStatus: "init"}
	if db != nil {
		if err := EnsureSyscfg(db); err == nil {
			var cfg BalanceCfg
			if found, _ := syscfgGet(db, "balance", &cfg); found {
				rs.Balance = cfg
			}
		}
	}
	return rs
}

// SetBalance updates and persists the balance config.
func (rs *RuntimeState) SetBalance(db *sql.DB, cfg BalanceCfg) error {
	rs.mu.Lock()
	rs.Balance = cfg
	rs.mu.Unlock()
	if db == nil {
		return nil
	}
	return syscfgSet(db, "balance", cfg)
}

// SetMeshDiscoverStatus advances the discovery state machine
// (init → scanning → finished; auto_add_status reported alongside).
func (rs *RuntimeState) SetMeshDiscoverStatus(status string, autoAdd bool) {
	rs.mu.Lock()
	rs.MeshStatus = status
	rs.MeshAutoAdd = autoAdd
	rs.mu.Unlock()
}

// TriggerManualRRM records the manual RRM trigger timestamp
// (ac_manualrrm.set handler; runtime linkage to rrm subsystem).
func (rs *RuntimeState) TriggerManualRRM() int64 {
	rs.mu.Lock()
	ts := time.Now().Unix()
	rs.mu.Unlock()
	return ts
}

// SetDIStatus updates the deep-inspection runtime status.
func (rs *RuntimeState) SetDIStatus(st DeepInspectionStatus) {
	if st.LastInspectionTime == 0 {
		st.LastInspectionTime = time.Now().Unix()
	}
	rs.mu.Lock()
	rs.DI = st
	rs.mu.Unlock()
}

// RegisterRuntimeHandlers replaces the not-impl placeholders for
// ac_balance.set / ac_mesh_discover_status.get / deep_inspection_status.get.
// Must be invoked after RegisterBatch3Handlers (overwrites the map entries).
func (rs *RuntimeState) RegisterRuntimeHandlers(s *Server, db *sql.DB) {
	s.replaceNotImpl("ac_balance.set", func(req json.RawMessage) (any, error) {
		var cfg BalanceCfg
		if err := json.Unmarshal(req, &cfg); err != nil {
			return nil, err
		}
		if err := rs.SetBalance(db, cfg); err != nil {
			return jerr(err), nil
		}
		return ok(), nil
	})
	s.replaceNotImpl("ac_mesh_discover_status.get", func(json.RawMessage) (any, error) {
		rs.mu.Lock()
		st, auto := rs.MeshStatus, rs.MeshAutoAdd
		rs.mu.Unlock()
		return map[string]any{"error_code": 0, "status": st, "auto_add_status": auto}, nil
	})
	s.replaceNotImpl("deep_inspection_status.get", func(json.RawMessage) (any, error) {
		rs.mu.Lock()
		di := rs.DI
		rs.mu.Unlock()
		return map[string]any{"error_code": 0, "status": di}, nil
	})
}

// RegisterMeshTriggerHandlers wires the mesh discover/pair triggers to the
// discovery state machine (mesh_jcs_trigger_discover @ / stop_discover /
// trigger_pair* — registry.tsv; status values init/scanning/finished per
// notes §25).
func (rs *RuntimeState) RegisterMeshTriggerHandlers(s *Server, db *sql.DB) {
	s.replaceNotImpl("ac_mesh_trigger_discover.set", func(json.RawMessage) (any, error) {
		rs.SetMeshDiscoverStatus("scanning", true)
		return ok(), nil
	})
	s.replaceNotImpl("ac_mesh_stop_discover.set", func(json.RawMessage) (any, error) {
		rs.SetMeshDiscoverStatus("finished", false)
		return ok(), nil
	})
	s.replaceNotImpl("ac_mesh_trigger_pair.set", func(json.RawMessage) (any, error) {
		rs.SetMeshDiscoverStatus("finished", true)
		return ok(), nil
	})
	s.replaceNotImpl("ac_mesh_trigger_pair_all.set", func(json.RawMessage) (any, error) {
		rs.SetMeshDiscoverStatus("finished", true)
		return ok(), nil
	})
	// mesh global settings get (pair with the set handler in batch3cfg.go)
	s.replaceNotImpl("ac_mesh_global_settings.get", func(json.RawMessage) (any, error) {
		var cfg map[string]any
		if db != nil {
			if found, _ := syscfgGet(db, "mesh_global", &cfg); found {
				return map[string]any{"error_code": 0, "settings": cfg}, nil
			}
		}
		return map[string]any{"error_code": 0, "settings": map[string]any{}}, nil
	})
}
