package admin

import (
	"crypto/rand"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"uacgo/cweng"
)

func decodeManagement(w http.ResponseWriter, r *http.Request, v any) error {
	d := json.NewDecoder(http.MaxBytesReader(w, r.Body, 2<<20))
	d.DisallowUnknownFields()
	if err := d.Decode(v); err != nil {
		return err
	}
	if err := d.Decode(new(any)); err != io.EOF {
		return fmt.Errorf("请求只能包含一个 JSON 对象")
	}
	return nil
}
func keepAccount(next, old APOptions) APOptions {
	if next.Account != nil && next.Account.Password == "" && old.Account != nil {
		a := *next.Account
		a.Password = old.Account.Password
		next.Account = &a
	}
	return next
}
func (m *Manager) saveManagement(next Config) error {
	return m.saveManagementFrom(next, managementUser)
}

type managementWrite uint8

const (
	managementUser managementWrite = iota
	managementRRM
	managementAPEvent
	managementRestore
)

func (m *Manager) saveManagementResult(next Config, rrmResult bool) error {
	if rrmResult {
		return m.saveManagementFrom(next, managementRRM)
	}
	return m.saveManagement(next)
}
func (m *Manager) saveManagementFrom(next Config, source managementWrite) error {
	if err := validateGroupStrategies(next.Groups); err != nil {
		return err
	}
	next = m.compileGroupEdits(next)
	prior := m.config
	if source == managementRestore {
		prior = next
	}
	next, _ = m.compileEDCARulesAgainst(next, prior)
	if next.Mesh != nil && next.Mesh.Members == nil {
		p := *next.Mesh
		if old := m.config.Mesh; old != nil && old.Members != nil {
			p.Members = append([]MeshMemberPolicy{}, old.Members...)
		} else {
			p.Members = m.legacyMeshMembersLocked()
		}
		next.Mesh = &p
	}
	if err := validateManagement(next); err != nil {
		return err
	}
	if err := m.validateRestorableConfig(next); err != nil {
		return err
	}
	next.Version = m.config.Version + 1
	if err := m.persistConfigLocked(next, source == managementRRM || source == managementAPEvent); err != nil {
		return err
	}
	return nil
}
func (m *Manager) managementRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/aps/export", m.exportAPsHTTP)
	mux.HandleFunc("GET /api/aps/{id}/management-state", m.managementStateHTTP)
	mux.HandleFunc("GET /api/aps/{id}/client-state", m.clientStateHTTP)
	mux.HandleFunc("GET /api/management", func(w http.ResponseWriter, r *http.Request) {
		aps := m.APs()
		m.mu.Lock()
		cfg := m.config
		m.mu.Unlock()
		effective := map[string]any{}
		for _, ap := range aps {
			o, err := effectiveAPOptions(cfg, ap)
			if err != nil {
				effective[ap.ID] = map[string]string{"error": err.Error()}
			} else {
				effective[ap.ID] = redactAPOptions(o)
			}
		}
		cfg = publicManagement(cfg)
		jsonReply(w, 200, map[string]any{"defaults": cfg.APDefaults, "profiles": cfg.APProfiles, "groups": cfg.Groups, "templates": cfg.Templates, "effective": effective})
	})
	mux.HandleFunc("POST /api/ap-defaults", func(w http.ResponseWriter, r *http.Request) {
		var o APOptions
		if err := decodeManagement(w, r, &o); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.APDefaults = keepAccount(o, next.APDefaults)
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]string{"status": "saved"})
	})
	mux.HandleFunc("POST /api/aps/{id}/settings", func(w http.ResponseWriter, r *http.Request) {
		var p APProfile
		if err := decodeManagement(w, r, &p); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		p.AP = r.PathValue("id")
		aps := m.APs()
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.APProfiles = append([]APProfile{}, next.APProfiles...)
		idx := -1
		for i, old := range next.APProfiles {
			if old.AP == p.AP {
				idx = i
				p.Options = keepAccount(p.Options, old.Options)
			}
		}
		if idx < 0 {
			next.APProfiles = append(next.APProfiles, p)
		} else {
			next.APProfiles[idx] = p
		}
		for _, ap := range aps {
			if ap.ID == p.AP {
				options, err := effectiveAPOptions(next, ap)
				if err == nil {
					_, err = managementElements(options, ap)
				}
				if err != nil {
					jsonReply(w, 400, map[string]string{"error": err.Error()})
					return
				}
			}
		}
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]string{"status": "saved"})
	})
	mux.HandleFunc("POST /api/groups", m.groupHTTP)
	mux.HandleFunc("DELETE /api/groups/{id}", m.groupHTTP)
	mux.HandleFunc("POST /api/templates", m.templateHTTP)
	mux.HandleFunc("DELETE /api/templates/{id}", m.templateHTTP)
	mux.HandleFunc("POST /api/aps/{id}/copy", m.copyAPHTTP)
	mux.HandleFunc("GET /api/backup", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		w.Header().Set("Content-Disposition", `attachment; filename="go-ac-configuration.json"`)
		jsonReply(w, 200, map[string]any{"format": "go-ac-configuration", "schema": 1, "config": m.config})
	})
	mux.HandleFunc("POST /api/restore", m.restoreHTTP)
	mux.HandleFunc("POST /api/aps/{id}/replace", m.replaceAPHTTP)
	mux.HandleFunc("POST /api/aps/{id}/action", m.apActionHTTP)
}

func (m *Manager) groupHTTP(w http.ResponseWriter, r *http.Request) {
	var g APGroup
	if r.Method == "DELETE" {
		g.ID = r.PathValue("id")
	} else if err := decodeManagement(w, r, &g); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	next := m.config
	next.Groups = append([]APGroup{}, next.Groups...)
	idx := -1
	for i, old := range next.Groups {
		if old.ID == g.ID {
			idx = i
			g.Options = keepAccount(g.Options, old.Options)
			if g.Strategy == nil {
				g.Strategy = old.Strategy
			}
		}
	}
	if g.ID == "" {
		g.ID = newManagementID("group")
	}
	if r.Method == "DELETE" {
		if idx < 0 {
			jsonReply(w, 404, map[string]string{"error": "分组不存在"})
			return
		}
		next.Groups = append(next.Groups[:idx], next.Groups[idx+1:]...)
	} else if idx < 0 {
		next.Groups = append(next.Groups, g)
	} else {
		next.Groups[idx] = g
	}
	if err := m.saveManagement(next); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	g.Options = redactAPOptions(g.Options)
	jsonReply(w, 202, map[string]any{"status": "saved", "group": g})
}
func (m *Manager) templateHTTP(w http.ResponseWriter, r *http.Request) {
	var t APTemplate
	if r.Method == "DELETE" {
		t.ID = r.PathValue("id")
	} else if err := decodeManagement(w, r, &t); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	next := m.config
	next.Templates = append([]APTemplate{}, next.Templates...)
	idx := -1
	for i, old := range next.Templates {
		if old.ID == t.ID {
			idx = i
			t.Options = keepAccount(t.Options, old.Options)
		}
	}
	if t.ID == "" {
		t.ID = newManagementID("template")
	}
	if r.Method == "DELETE" {
		if idx < 0 {
			jsonReply(w, 404, map[string]string{"error": "模板不存在"})
			return
		}
		next.Templates = append(next.Templates[:idx], next.Templates[idx+1:]...)
	} else if idx < 0 {
		next.Templates = append(next.Templates, t)
	} else {
		next.Templates[idx] = t
	}
	if err := m.saveManagement(next); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	t.Options = redactAPOptions(t.Options)
	jsonReply(w, 202, map[string]any{"status": "saved", "template": t})
}

func (m *Manager) copyAPHTTP(w http.ResponseWriter, r *http.Request) {
	var request struct {
		Targets []string `json:"targets"`
		Radios  bool     `json:"radios"`
	}
	if err := decodeManagement(w, r, &request); err != nil || len(request.Targets) == 0 {
		jsonReply(w, 400, map[string]string{"error": "请选择复制目标 AP"})
		return
	}
	aps := m.APs()
	byID := map[string]cweng.APStatus{}
	for _, a := range aps {
		byID[a.ID] = a
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	next := m.config
	next.APProfiles = append([]APProfile{}, next.APProfiles...)
	next.Radios = append([]RadioSetting{}, next.Radios...)
	var source APProfile
	found := false
	for _, p := range next.APProfiles {
		if p.AP == r.PathValue("id") {
			source = p
			found = true
		}
	}
	if !found {
		jsonReply(w, 404, map[string]string{"error": "源 AP 尚无自定义设置"})
		return
	}
	sourceAP, sourceKnown := byID[source.AP]
	if !sourceKnown {
		jsonReply(w, 404, map[string]string{"error": "源 AP 的能力信息未知"})
		return
	}
	sourceOptions, err := effectiveAPOptions(m.config, sourceAP)
	if err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	sourceRadios := effectiveRadioConfig(m.config, sourceAP).Radios
	seenTargets := map[string]bool{}
	for _, id := range request.Targets {
		target, ok := byID[id]
		if !ok || id == source.AP || seenTargets[id] {
			jsonReply(w, 400, map[string]string{"error": "复制目标 AP 无效"})
			return
		}
		seenTargets[id] = true
		p := source
		p.AP = id
		p.Name = ""
		p.Location = ""
		p.Group, p.Template = "", ""
		p.Options = sourceOptions
		if !request.Radios {
			p.Options.Radios = nil
			p.Options.RFMode = nil
			p.Options.RegionCode = nil
		}
		idx := -1
		for i, old := range next.APProfiles {
			if old.AP == id {
				idx = i
				p.Name = old.Name
				p.Location = old.Location
				p.Group, p.Template = old.Group, old.Template
				if !request.Radios {
					p.Options.Radios = old.Options.Radios
					p.Options.RFMode = old.Options.RFMode
					p.Options.RegionCode = old.Options.RegionCode
				}
			}
		}
		if idx < 0 {
			next.APProfiles = append(next.APProfiles, p)
		} else {
			next.APProfiles[idx] = p
		}
		if _, err := effectiveAPOptions(next, target); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		if request.Radios {
			for _, radio := range sourceRadios {
				if radio.AP != source.AP {
					continue
				}
				radio.AP = id
				var capability *cweng.RadioCapability
				for _, c := range target.Capabilities {
					if c.RadioID == radio.Radio {
						copy := c
						capability = &copy
					}
				}
				if capability == nil {
					jsonReply(w, 400, map[string]string{"error": "目标 AP 缺少对应射频能力"})
					return
				}
				if err := validateAdvanced(radio, target, *capability); err != nil {
					jsonReply(w, 400, map[string]string{"error": err.Error()})
					return
				}
				idx := -1
				for i, x := range next.Radios {
					if x.AP == id && x.Radio == radio.Radio {
						idx = i
					}
				}
				if idx < 0 {
					next.Radios = append(next.Radios, radio)
				} else {
					next.Radios[idx] = radio
				}
			}
		}
	}
	if err := m.saveManagement(next); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	jsonReply(w, 202, map[string]string{"status": "saved"})
}

func (m *Manager) restoreHTTP(w http.ResponseWriter, r *http.Request) {
	var backup struct {
		Format string `json:"format"`
		Schema int    `json:"schema"`
		Config Config `json:"config"`
	}
	if err := decodeManagement(w, r, &backup); err != nil || backup.Format != "go-ac-configuration" || backup.Schema != 1 {
		jsonReply(w, 400, map[string]string{"error": "不是支持的 Go AC 配置备份"})
		return
	}
	next := backup.Config
	for _, s := range next.Services {
		if err := validate(s); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	for _, j := range m.meshJobs {
		if j.State == "sending" || j.State == "waiting_report" || j.State == "uncertain" {
			jsonReply(w, 409, map[string]string{"error": "Mesh 操作仍在等待结果，请待其结束后恢复配置"})
			return
		}
	}
	// Preserve deletion intent for owned services absent from the backup.
	ids := map[string]bool{}
	for _, s := range next.Services {
		if s.ID == "" || ids[s.ID] {
			jsonReply(w, 400, map[string]string{"error": "备份服务编号无效"})
			return
		}
		ids[s.ID] = true
	}
	for _, s := range m.config.Services {
		if !ids[s.ID] {
			s.Enabled = false
			s.Deleting = true
			s.Groups = nil
			next.Services = append(next.Services, s)
		}
	}
	if next.Labels == nil {
		next.Labels = map[string]string{}
	}
	if err := m.saveManagementFrom(next, managementRestore); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	jsonReply(w, 202, map[string]string{"status": "saved", "message": "配置已恢复，在线 AP 将同步；接口变更需重启程序"})
}

func (m *Manager) replaceAPHTTP(w http.ResponseWriter, r *http.Request) {
	var v struct {
		Target string `json:"target_ap_id"`
	}
	if err := decodeManagement(w, r, &v); err != nil || v.Target == "" || v.Target == r.PathValue("id") {
		jsonReply(w, 400, map[string]string{"error": "替换 AP 无效"})
		return
	}
	aps := m.APs()
	var old, target *cweng.APStatus
	for i := range aps {
		if aps[i].ID == r.PathValue("id") {
			old = &aps[i]
		}
		if aps[i].ID == v.Target {
			target = &aps[i]
		}
	}
	if old == nil || target == nil || old.Online || old.Model != target.Model || old.HardwareVersion != target.HardwareVersion {
		jsonReply(w, 400, map[string]string{"error": "原 AP 必须离线，替换设备须为相同型号/硬件"})
		return
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	b, _ := json.Marshal(m.config)
	var next Config
	_ = json.Unmarshal(b, &next)
	if next.Mesh != nil && next.Mesh.Members == nil {
		next.Mesh.Members = m.legacyMeshMembersLocked()
	}
	for i, p := range next.APProfiles {
		if p.AP == target.ID {
			jsonReply(w, 400, map[string]string{"error": "替换 AP 已有设置，请先清理或使用复制"})
			return
		}
		if p.AP == old.ID {
			next.APProfiles[i].AP = target.ID
		}
	}
	for i, r := range next.Radios {
		if r.AP == old.ID {
			next.Radios[i].AP = target.ID
		}
	}
	for i := range next.Services {
		s := &next.Services[i]
		for j, id := range s.APs {
			if id == old.ID {
				s.APs[j] = target.ID
			}
		}
		for j, x := range s.Bindings {
			if x.AP == old.ID {
				s.Bindings[j].AP = target.ID
			}
		}
	}
	for _, j := range m.upgrades.Jobs {
		if (j.AP == old.ID || j.AP == target.ID) && upgradeBusy(j) {
			jsonReply(w, 409, map[string]string{"error": "原 AP 或替换 AP 仍有升级任务，请先取消或完成"})
			return
		}
	}
	for _, j := range m.meshJobs {
		if j.State != "sending" && j.State != "waiting_report" && j.State != "uncertain" {
			continue
		}
		involved := j.AP == old.ID || j.AP == target.ID
		for _, mac := range j.MACs {
			involved = involved || mac == old.ID || mac == target.ID
		}
		if involved {
			jsonReply(w, 409, map[string]string{"error": "原 AP 或替换 AP 仍有未确认的 Mesh 操作"})
			return
		}
	}
	retargetPolicies(&next, old.ID, target.ID)
	next.RetiredAPs = append(append([]string{}, next.RetiredAPs...), old.ID)
	if err := m.saveManagement(next); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	jsonReply(w, 202, map[string]string{"status": "saved"})
}

func newManagementID(prefix string) string { return prefix + "-" + rand.Text()[:12] }
