package jcs

import (
	"database/sql"
	"encoding/json"
)

// SyscfgKV handlers for the remaining config-style setters
// (ac_mesh_wan_status.set / sensor_global.set / diagnose_global.set /
// apmngr_global.set / apmngr_aplog.set / wservice_global per their
// registrations in notes §23; each stores its key-set JSON verbatim in the
// syscfg table — the same store-backed pattern as mesh/rrm/lldp).
//
// Handlers with runtime query semantics (mesh topology/discover lists,
// sensor-di reads, wips events/statistics) are already implemented in
// batch3rt.go / batch3rt2.go / deepinspect.go.

// RegisterSyscfgHandlers wires the config-style setters listed below to
// syscfg keys (must run after RegisterBatch3Handlers / RegisterApmngrHandlers
// so the KV handlers overwrite the not-impl placeholders).
func RegisterSyscfgHandlers(s *Server, db *sql.DB) {
	if err := EnsureSyscfg(db); err != nil {
		return
	}
	kv := func(key string) Handler {
		return func(req json.RawMessage) (any, error) {
			var cfg map[string]any
			if err := json.Unmarshal(req, &cfg); err != nil {
				return nil, err
			}
			if err := syscfgSet(db, key, cfg); err != nil {
				return jerr(err), nil
			}
			return ok(), nil
		}
	}
	kvGet := func(key string) Handler {
		return func(json.RawMessage) (any, error) {
			var cfg map[string]any
			found, err := syscfgGet(db, key, &cfg)
			if err != nil {
				return jerr(err), nil
			}
			if !found {
				cfg = map[string]any{}
			}
			return map[string]any{"error_code": 0, key: cfg}, nil
		}
	}
	// setters per §23 registrations
	// (ac_mesh_wan_status.set is the mesh handler in mesh_topology.go —
	// mesh_jcs_wan_status_set @0x4bb12c, not a KV store)
	s.replaceNotImpl("sensor_global.set", kv("sensor_global"))
	s.replaceNotImpl("diagnose_global.set", kv("diagnose_global"))
	s.replaceNotImpl("apmngr_global.set", kv("apmngr_global"))
	s.replaceNotImpl("apmngr_aplog.set", kv("apmngr_aplog"))
	s.replaceNotImpl("wserv_global.set", kv("wserv_global"))
	// apmngr_global get (registered with get in apmngr_jcs_reg_callback —
	// the notImpl placeholder there is replaced here too)
	s.replaceNotImpl("apmngr_global.get", kvGet("apmngr_global"))
	s.replaceNotImpl("diagnose_global.get", kvGet("diagnose_global"))
	s.replaceNotImpl("sensor_global.get", kvGet("sensor_global"))
	s.replaceNotImpl("wserv_global.get", kvGet("wserv_global"))
}
