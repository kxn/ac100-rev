package admin

import (
	"context"
	"strconv"
	"time"
	"uacgo/cweng"
)

// AC capability 51 selects deferred configuration on this AP family. The AP
// caches radio/WLAN/rate changes and applies them only after a changed 0x41
// marker (DMS FUN_000bec50 -> effectCacheCfg). Commit the complete batch.
func (m *Manager) commitAP(ctx context.Context, ap cweng.APStatus, cfg Config) {
	m.mu.Lock()
	revision := m.batchRevision[ap.ID]
	m.mu.Unlock()
	snapshot := struct {
		Config     Config
		Connection time.Time
		Revision   uint64
	}{cfg, ap.ConnectedAt, revision}
	version := configurationKey(snapshot, ap.ConnectedAt)
	key := ap.ID + "/configuration-commit"
	m.mu.Lock()
	previous := m.status[key]
	done := m.applied[key] == version && (previous.State != "failed" || time.Since(previous.At) < 30*time.Second)
	bandKey := ap.ID + "/band-navigation"
	failed := cfg.BandNavigation != nil && ap.HasCapability(3) && m.applied[bandKey] == configurationKey(cfg.BandNavigation, ap.ConnectedAt) && m.status[bandKey].State == "failed"
	failed = failed || m.status[ap.ID+"/rates"].State == "failed" || m.status[ap.ID+"/protection"].State == "failed" || m.status[ap.ID+"/storm"].State == "failed"
	failed = failed || m.status[ap.ID+"/balance"].State == "failed" || m.status[ap.ID+"/roaming"].State == "failed"
	failed = failed || m.status[ap.ID+"/roaming-mode"].State == "failed"
	failed = failed || m.status[ap.ID+"/mesh-network"].State == "failed"
	failed = failed || m.status[ap.ID+"/multicast-groups"].State == "failed"
	for _, s := range cfg.Services {
		st, exists := m.status[ap.ID+"/"+s.ID]
		if exists && st.State == "failed" && m.applied[ap.ID+"/"+s.ID] == serviceVersion(s, ap, cfg) {
			failed = true
		}
	}
	for _, p := range cfg.VLANPools {
		if supportsPool(ap) && m.status[ap.ID+"/vlan-pool:"+strconv.Itoa(int(p.ID))].State == "failed" {
			failed = true
		}
	}
	for _, r := range cfg.Radios {
		if r.AP == ap.ID && m.status[ap.ID+"/radio:"+strconv.Itoa(int(r.Radio))].State == "failed" {
			failed = true
		}
	}
	m.mu.Unlock()
	if failed {
		return
	}
	if done {
		m.mu.Lock()
		settlement, exists := m.settling[ap.ID]
		refresh := exists && settlement.Version == version && !time.Now().Before(settlement.Ready)
		m.mu.Unlock()
		if err := m.settleWLANs(ap.ID, version, ap.ConnectedAt, time.Now()); err != nil {
			m.mu.Lock()
			m.status[key] = ApplyStatus{AP: ap.ID, Service: "configuration-commit", State: "failed", Error: err.Error(), At: time.Now()}
			m.mu.Unlock()
			return
		}
		if refresh {
			m.mu.Lock()
			m.settled[ap.ID] = configurationKey(cfg, ap.ConnectedAt)
			if m.settledVersions == nil {
				m.settledVersions = map[string]uint64{}
			}
			m.settledVersions[ap.ID] = cfg.Version
			m.mu.Unlock()
			_ = m.reportAction(ctx, ap.ID, "off", "stop_report")
			_ = m.requestTelemetry(ctx, ap.ID)
		}
		return
	}
	err := m.checkpoint(ctx, ap.ID, snapshot)
	state := ApplyStatus{AP: ap.ID, Service: "configuration-commit", State: "acknowledged", At: time.Now()}
	if err != nil {
		state.State = "failed"
		state.Error = err.Error()
	}
	m.mu.Lock()
	m.applied[key] = version
	m.status[key] = state
	m.mu.Unlock()
	if err == nil {
		m.mu.Lock()
		m.settling[ap.ID] = commitSettlement{version, ap.ConnectedAt, time.Now().Add(12 * time.Second)}
		m.mu.Unlock()
	}
}
