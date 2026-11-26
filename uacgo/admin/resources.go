package admin

import (
	"encoding/json"
	"fmt"
	"net/http"
	"uacgo/controllercfg"
)

// An installation created before budgets existed must not lose valid
// configuration merely because its object count exceeds a new Go default.
func initialControllerResources(cfg Config) controllercfg.Resources {
	r := controllercfg.Defaults()
	r.MaxServices = max(r.MaxServices, len(cfg.Services))
	r.MaxGroups = max(r.MaxGroups, len(cfg.Groups))
	r.MaxTemplates = max(r.MaxTemplates, len(cfg.Templates))
	r.MaxPolicyRules = max(r.MaxPolicyRules, len(cfg.RRM), len(cfg.EDCARules))
	if p := cfg.Mobility; p != nil {
		r.MaxPolicyRules = max(r.MaxPolicyRules, len(p.Balance), len(p.Roaming))
	}
	if p := cfg.Protection; p != nil {
		r.MaxTrustedServers = max(r.MaxTrustedServers, len(p.Servers))
		r.MaxAddressBindings = max(r.MaxAddressBindings, len(p.Bindings))
		r.MaxPolicyRules = max(r.MaxPolicyRules, len(p.Rules))
	}
	return r
}

// Controller budgets are independent of AP constraints and policy constants.
// Every config writer, including restore, passes the same capacity boundary.
func validateControllerResources(cfg Config) error {
	r := controllercfg.Effective(cfg.Resources)
	if err := r.Validate(); err != nil {
		return err
	}
	for _, row := range []struct {
		name   string
		n, max int
	}{
		{"无线服务", len(cfg.Services), r.MaxServices}, {"AP 分组", len(cfg.Groups), r.MaxGroups}, {"AP 模板", len(cfg.Templates), r.MaxTemplates},
		{"RRM 规则", len(cfg.RRM), r.MaxPolicyRules}, {"EDCA 规则", len(cfg.EDCARules), r.MaxPolicyRules},
	} {
		if row.n > row.max {
			return fmt.Errorf("%s数量 %d 超过程序容量 %d", row.name, row.n, row.max)
		}
	}
	if p := cfg.Mobility; p != nil && (len(p.Balance) > r.MaxPolicyRules || len(p.Roaming) > r.MaxPolicyRules) {
		return fmt.Errorf("均衡或漫游规则超过程序容量 %d", r.MaxPolicyRules)
	}
	if p := cfg.Protection; p != nil && (len(p.Servers) > r.MaxTrustedServers || len(p.Bindings) > r.MaxAddressBindings || len(p.Rules) > r.MaxPolicyRules) {
		return fmt.Errorf("防护配置超过程序表容量")
	}
	return nil
}
func (m *Manager) validateResourceUsage(cfg Config) error {
	if err := validateControllerResources(cfg); err != nil {
		return err
	}
	r := controllercfg.Effective(cfg.Resources)
	total := int64(0)
	for _, im := range m.upgrades.Images {
		total += int64(im.Size)
	}
	if len(m.upgrades.Images) > r.MaxFirmwareImages || total > int64(r.FirmwareStorageMiB)<<20 {
		return fmt.Errorf("现有固件镜像超过新容量，请先清理固件库")
	}
	return nil
}
func (m *Manager) applyControllerResources() {
	r := controllercfg.Effective(m.config.Resources)
	m.engine.SetResourceLimits(r.MaxAPSessions, r.CommandQueueDepth)
}
func (m *Manager) resourceRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/controller/resources", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		settings := controllercfg.Effective(m.config.Resources)
		m.mu.Unlock()
		jsonReply(w, 200, map[string]any{"settings": settings, "defaults": controllercfg.Defaults(), "fields": controllercfg.Fields()})
	})
	mux.HandleFunc("POST /api/controller/resources", func(w http.ResponseWriter, r *http.Request) {
		var body json.RawMessage
		if err := decodeManagement(w, r, &body); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		value, err := controllercfg.Effective(m.config.Resources).Patch(body)
		if err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		if err := value.Validate(); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		next := m.config
		next.Resources = &value
		if err := m.persistConfigLocked(next, managementUser); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]any{"status": "saved", "settings": value, "restart_required": false})
	})
}
