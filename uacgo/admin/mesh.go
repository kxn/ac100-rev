package admin

import (
	"context"
	"crypto/rand"
	"encoding/binary"
	"encoding/hex"
	"encoding/json"
	"fmt"
	"net"
	"net/http"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"unicode/utf8"
)

type MeshConfig struct {
	Members        []MeshMemberPolicy `json:"members"`
	Enabled        bool               `json:"enabled"`
	AutoAdd        bool               `json:"auto_add"`
	SSID           string             `json:"ssid"`
	Key            string             `json:"key,omitempty"`
	Token          string             `json:"token,omitempty"`
	WebPassword    string             `json:"web_password,omitempty"`
	HasKey         bool               `json:"has_key,omitempty"`
	HasToken       bool               `json:"has_token,omitempty"`
	HasWebPassword bool               `json:"has_web_password,omitempty"`
	BackhaulMode   uint8              `json:"backhaul_mode"`
}
type MeshJob struct {
	ID         string    `json:"id"`
	AP         string    `json:"ap_id"`
	Action     string    `json:"action"`
	MACs       []string  `json:"macs"`
	State      string    `json:"state"`
	Error      string    `json:"error,omitempty"`
	Started    time.Time `json:"started"`
	Updated    time.Time `json:"updated"`
	Connection time.Time `json:"connection"`
}

func validateMesh(p *MeshConfig) error {
	if p == nil {
		return nil
	}
	if err := validateMeshMembers(p.Members); err != nil {
		return err
	}
	if !utf8.ValidString(p.SSID) || len(p.SSID) > 32 || strings.ContainsRune(p.SSID, 0) || p.BackhaulMode > 2 {
		return fmt.Errorf("Mesh 名称或回传模式无效")
	}
	if !p.Enabled {
		return nil
	}
	if p.SSID == "" || len(p.Key) < 8 || len(p.Key) > 63 || len(p.Token) < 1 || len(p.Token) > 32 || len(p.WebPassword) < 6 || len(p.WebPassword) > 15 {
		return fmt.Errorf("Mesh 需名称、8–63字节密钥、1–32字节令牌及6–15字节管理密码")
	}
	for _, v := range []string{p.Key, p.Token, p.WebPassword} {
		for _, b := range []byte(v) {
			if b < 32 || b > 126 {
				return fmt.Errorf("Mesh 密钥、令牌、密码仅支持可打印 ASCII")
			}
		}
	}
	return nil
}
func publicMesh(p *MeshConfig) *MeshConfig {
	if p == nil {
		return nil
	}
	q := *p
	q.HasKey = q.Key != ""
	q.HasToken = q.Token != ""
	q.HasWebPassword = q.WebPassword != ""
	q.Key = ""
	q.Token = ""
	q.WebPassword = ""
	return &q
}
func meshSetting(rows ...capwap.VendorRecord) capwap.Element {
	return privateSetting(0x76, capwap.AssembleVendorList(rows))
}
func meshPolicyElements(p *MeshConfig, ap cweng.APStatus, cfg Config) []capwap.Element {
	enabled := p != nil && p.Enabled
	for _, id := range cfg.RetiredAPs {
		if id == ap.ID {
			enabled = false
		}
	}
	if o, err := effectiveAPOptions(cfg, ap); err == nil && o.Mesh != nil {
		enabled = enabled && *o.Mesh
	}
	rows := []capwap.VendorRecord{}
	if enabled {
		bh := make([]byte, 32)
		copy(bh, p.SSID)
		bh = binary.BigEndian.AppendUint16(bh, uint16(len(p.Key)))
		bh = append(bh, p.Key...)
		bh = binary.BigEndian.AppendUint16(bh, uint16(len(p.Token)))
		bh = append(bh, p.Token...)
		pw := binary.BigEndian.AppendUint16(nil, uint16(len(p.WebPassword)))
		pw = append(pw, p.WebPassword...)
		rows = append(rows, capwap.VendorRecord{Type: 10, Value: bh}, capwap.VendorRecord{Type: 15, Value: pw}, capwap.VendorRecord{Type: 14, Value: []byte{boolean(p.AutoAdd), 1}})
		// mesh_pkt_bh_work_mode_send@53f248 selects main44/sub1.
		if ap.SupportsMeshBackhaulMode() {
			rows = append(rows, capwap.VendorRecord{Type: 23, Value: []byte{p.BackhaulMode}})
		}
	}
	rows = append(rows, capwap.VendorRecord{Type: 21, Value: []byte{0, boolean(enabled)}})
	return []capwap.Element{meshSetting(rows...)}
}
func (m *Manager) meshConfigure(ap cweng.APStatus) []capwap.Element {
	m.mu.Lock()
	defer m.mu.Unlock()
	if m.config.Mesh == nil {
		return nil
	}
	els := meshPolicyElements(m.config.Mesh, ap, m.config)
	return append(els, m.meshMemberSettingLocked(ap.ID))
}
func (m *Manager) meshAuthorize(parent string, connection time.Time, child string, kind uint8) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	p := m.config.Mesh
	if p == nil || !p.Enabled {
		return false
	}
	ap, ok := m.known[parent]
	if !ok || ap.ConnectedAt != connection {
		return false
	}
	if o, err := effectiveAPOptions(m.config, ap); err != nil || o.Mesh != nil && !*o.Mesh {
		return false
	}
	for _, id := range m.config.RetiredAPs {
		if id == child || id == parent {
			return false
		}
	}
	// Latest explicit membership intent wins. Completed pairing remains an
	// authorization across program/parent restarts, even before child Join.
	var latest *MeshJob
	for _, j := range m.meshJobs {
		if j.AP != parent || (j.Action != "pair" && j.Action != "add" && j.Action != "unpair" && j.Action != "delete") {
			continue
		}
		legacyCompleted := p.Members == nil && j.State == "completed"
		if !legacyCompleted && !((j.State == "sending" || j.State == "waiting_report") && time.Since(j.Started) < 5*time.Minute) {
			continue
		}
		for _, mac := range j.MACs {
			if mac == child && (latest == nil || j.Started.After(latest.Started)) {
				copy := j
				latest = &copy
			}
		}
	}
	if latest != nil {
		return latest.Action == "pair" || latest.Action == "add"
	}
	for _, member := range p.Members {
		if member.Parent == parent && member.MAC == child {
			return member.Allowed
		}
	}
	// Automatic grants are restricted to previously known AP identities.
	childAP, known := m.known[child]
	return known && (childAP.MeshParent == parent || p.AutoAdd && kind <= 1)
}
func (m *Manager) applyMesh(ctx context.Context, ap cweng.APStatus, cfg Config) {
	if !ap.HasCapability(44) || cfg.Mesh == nil && !m.policyOwned(ap.ID, "mesh-network") {
		return
	}
	m.mu.Lock()
	members := m.meshMembersLocked(ap.ID)
	memberSetting := meshMembersElement(members)
	m.mu.Unlock()
	m.applyPolicy(ctx, ap, "mesh-network", struct {
		Members []string
		Policy  *MeshConfig
		Options APOptions
		Sub     uint32
	}{members, cfg.Mesh, func() APOptions { o, _ := effectiveAPOptions(cfg, ap); return o }(), ap.SubCapabilities[44]}, append(meshPolicyElements(cfg.Mesh, ap, cfg), memberSetting))
}
func (m *Manager) meshJobsPath() string { return filepath.Join(filepath.Dir(m.path), "mesh-jobs.json") }
func (m *Manager) loadMeshJobs() error {
	m.meshJobs = map[string]MeshJob{}
	b, err := os.ReadFile(m.meshJobsPath())
	if err != nil && !os.IsNotExist(err) {
		return err
	}
	if err == nil {
		if err = json.Unmarshal(b, &m.meshJobs); err != nil {
			return err
		}
	}
	if m.meshJobs == nil {
		return fmt.Errorf("Mesh 任务记录为空")
	}
	for id, j := range m.meshJobs {
		if j.State == "sending" || j.State == "waiting_report" {
			j.State = "uncertain"
			j.Error = "程序重启前尚未确认，未自动重发"
			j.Updated = time.Now()
			m.meshJobs[id] = j
		}
	}
	return m.migrateMeshMembersLocked()
}
func meshActionRecords(action string, macs []string) ([]capwap.VendorRecord, error) {
	if action == "discover" {
		return []capwap.VendorRecord{{Type: 0, Value: []byte{1}}}, nil
	}
	if action == "stop-discovery" {
		return []capwap.VendorRecord{{Type: 0, Value: []byte{0}}}, nil
	}
	typ, ok := map[string]uint16{"pair": 2, "unpair": 9, "add": 8, "delete": 19}[action]
	if !ok {
		return nil, fmt.Errorf("未知 Mesh 操作")
	}
	if len(macs) > 50 || len(macs) == 0 {
		return nil, fmt.Errorf("请明确选择1–50个节点")
	}
	b := binary.BigEndian.AppendUint16(nil, uint16(len(macs)))
	seen := map[string]bool{}
	for _, s := range macs {
		mac, err := net.ParseMAC(s)
		if err != nil || len(mac) != 6 || mac[0]&1 != 0 || mac.String() == "00:00:00:00:00:00" || seen[mac.String()] {
			return nil, fmt.Errorf("节点 MAC 无效或重复")
		}
		seen[mac.String()] = true
		b = append(b, mac...)
	}
	return []capwap.VendorRecord{{Type: typ, Value: b}}, nil
}
func (m *Manager) meshAction(ctx context.Context, ap cweng.APStatus, action string, macs []string) (MeshJob, error) {
	rows, err := meshActionRecords(action, macs)
	if err != nil {
		return MeshJob{}, err
	}
	if !ap.Online || !ap.HasCapability(44) {
		return MeshJob{}, fmt.Errorf("AP 未在线或未声明 Mesh 能力")
	}
	for i, s := range macs {
		mac, _ := net.ParseMAC(s)
		macs[i] = mac.String()
		if macs[i] == ap.ID {
			return MeshJob{}, fmt.Errorf("不能选择父 AP 本身")
		}
	}
	m.mu.Lock()
	if m.config.Mesh == nil || !m.config.Mesh.Enabled || m.upgradeBusyLocked(ap.ID) {
		m.mu.Unlock()
		return MeshJob{}, fmt.Errorf("请先启用 Mesh 并等待 AP 升级结束")
	}
	o, e := effectiveAPOptions(m.config, ap)
	if e != nil || o.Mesh != nil && !*o.Mesh {
		m.mu.Unlock()
		return MeshJob{}, fmt.Errorf("此 AP 的 Mesh 已关闭")
	}
	for _, j := range m.meshJobs {
		if j.AP == ap.ID && (j.State == "sending" || j.State == "waiting_report") && !(action == "stop-discovery" && j.Action == "discover" && j.State == "waiting_report") {
			m.mu.Unlock()
			return MeshJob{}, fmt.Errorf("此 AP 已有 Mesh 操作待确认")
		}
	}
	m.pruneMeshJobsLocked()
	if len(m.meshJobs) >= 1000 {
		m.mu.Unlock()
		return MeshJob{}, fmt.Errorf("Mesh 操作记录已满")
	}
	at := time.Now()
	job := MeshJob{ID: fmt.Sprintf("mesh-%d", at.UnixNano()), AP: ap.ID, Action: action, MACs: append([]string{}, macs...), State: "sending", Started: at, Updated: at, Connection: ap.ConnectedAt}
	m.meshJobs[job.ID] = job
	err = atomicJSON(m.meshJobsPath(), m.meshJobs)
	if err != nil {
		delete(m.meshJobs, job.ID)
		m.mu.Unlock()
		return MeshJob{}, err
	}
	m.mu.Unlock()
	_, err = m.engine.Request(cweng.PinAP(ctx, ap), ap.ID, 7, []capwap.Element{meshSetting(rows...)})
	job.Updated = time.Now()
	job.State = "waiting_report"
	if action == "stop-discovery" {
		job.State = "acknowledged"
	}
	if err != nil {
		job.State = "uncertain"
		job.Error = err.Error()
	}
	m.mu.Lock()
	m.meshJobs[job.ID] = job
	if action == "stop-discovery" && err == nil {
		for id, old := range m.meshJobs {
			if old.AP == ap.ID && old.Action == "discover" && old.State == "waiting_report" {
				old.State = "stopped"
				old.Updated = job.Updated
				m.meshJobs[id] = old
			}
		}
	}
	saveErr := atomicJSON(m.meshJobsPath(), m.meshJobs)
	m.mu.Unlock()
	if saveErr != nil {
		return job, saveErr
	}
	return job, err
}
func (m *Manager) observeMeshJobs(aps []cweng.APStatus, now time.Time) {
	byID := map[string]cweng.APStatus{}
	for _, a := range aps {
		byID[a.ID] = a
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	changed := false
	for id, j := range m.meshJobs {
		if j.State != "waiting_report" && j.State != "uncertain" {
			continue
		}
		ap, ok := byID[j.AP]
		complete := false
		if ok && ap.Online && ap.ConnectedAt == j.Connection && ap.Mesh != nil {
			if j.Action == "discover" {
				complete = ap.Mesh.DiscoveryAt.After(j.Started)

			} else if ap.Mesh.TopologyAt.After(j.Started) {
				complete = true
				for _, mac := range j.MACs {
					found := false
					for _, n := range ap.Mesh.Nodes {
						found = found || n.MAC == mac
					}
					remove := j.Action == "unpair" || j.Action == "delete"
					if remove {
						complete = complete && !found && (ap.Mesh.FullTopologyAt.After(j.Started) || ap.Mesh.Removed[mac].After(j.Started))
					} else {
						complete = complete && found
					}
				}
			}
		}
		if complete {
			if err := m.recordMeshMembershipLocked(j); err != nil {
				j.Error = "节点结果已收到，但成员策略尚未持久化：" + err.Error()
				j.Updated = now
				m.meshJobs[id] = j
				changed = true
				continue
			}
			j.State = "completed"
			j.Error = ""
		} else if now.Sub(j.Started) > 5*time.Minute {
			j.State = "timed_out"
			j.Error = "未收到对应节点结果，未自动重发"
		} else {
			continue
		}
		j.Updated = now
		m.meshJobs[id] = j
		changed = true
	}
	if changed {
		_ = atomicJSON(m.meshJobsPath(), m.meshJobs)
	}
}
func (m *Manager) meshRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/mesh", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		jsonReply(w, 200, map[string]any{"config": publicMesh(m.config.Mesh), "jobs": m.meshJobs})
	})
	mux.HandleFunc("POST /api/mesh", func(w http.ResponseWriter, r *http.Request) {
		var p MeshConfig
		if err := decodeManagement(w, r, &p); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		if p.Members == nil {
			if old := m.config.Mesh; old != nil && old.Members != nil {
				p.Members = append([]MeshMemberPolicy{}, old.Members...)
			} else {
				p.Members = m.legacyMeshMembersLocked()
			}
		}
		if old := m.config.Mesh; old != nil {
			if p.Key == "" {
				p.Key = old.Key
			}
			if p.Token == "" {
				p.Token = old.Token
			}
			if p.WebPassword == "" {
				p.WebPassword = old.WebPassword
			}
		}
		if p.Enabled && p.Token == "" {
			var secret [16]byte
			if _, err := rand.Read(secret[:]); err != nil {
				jsonReply(w, 500, map[string]string{"error": err.Error()})
				return
			}
			p.Token = hex.EncodeToString(secret[:])
		}
		next := m.config
		next.Mesh = &p
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]string{"status": "saved"})
	})
	mux.HandleFunc("POST /api/aps/{id}/mesh", func(w http.ResponseWriter, r *http.Request) {
		var in struct {
			Action string   `json:"action"`
			MACs   []string `json:"macs"`
		}
		if err := decodeManagement(w, r, &in); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		var ap cweng.APStatus
		for _, a := range m.APs() {
			if a.ID == r.PathValue("id") {
				ap = a
			}
		}
		ctx, cancel := context.WithTimeout(r.Context(), 15*time.Second)
		defer cancel()
		job, err := m.meshAction(ctx, ap, in.Action, in.MACs)
		if err != nil {
			jsonReply(w, 409, map[string]any{"error": err.Error(), "job": job})
			return
		}
		jsonReply(w, 202, job)
	})
}

func (m *Manager) meshMembersLocked(parent string) []string {
	if m.config.Mesh == nil {
		return []string{}
	}
	members := map[string]bool{}
	for _, id := range m.config.RetiredAPs {
		if id == parent {
			return []string{}
		}
	}
	for id, ap := range m.known {
		if ap.MeshParent == parent {
			members[id] = true
		}
	}
	latest := map[string]MeshJob{}
	for _, j := range m.meshJobs {
		if j.AP != parent || j.State != "completed" || m.config.Mesh != nil && m.config.Mesh.Members != nil {
			continue
		}
		for _, mac := range j.MACs {
			if old, ok := latest[mac]; !ok || j.Started.After(old.Started) {
				latest[mac] = j
			}
		}
	}
	if m.config.Mesh != nil {
		for _, p := range m.config.Mesh.Members {
			if p.Parent == parent {
				members[p.MAC] = p.Allowed
			}
		}
	}
	for mac, j := range latest {
		if j.Action == "pair" || j.Action == "add" {
			members[mac] = true
		} else if j.Action == "delete" || j.Action == "unpair" {
			delete(members, mac)
		}
	}
	for _, id := range m.config.RetiredAPs {
		delete(members, id)
	}
	out := []string{}
	for id, allowed := range members {
		if !allowed {
			continue
		}
		if mac, err := net.ParseMAC(id); err == nil && len(mac) == 6 {
			out = append(out, mac.String())
		}
	}
	sort.Strings(out)
	return out
}
func meshMembersElement(members []string) capwap.Element {
	b := binary.BigEndian.AppendUint16(nil, uint16(len(members)))
	for _, id := range members {
		mac, _ := net.ParseMAC(id)
		b = append(b, mac...)
	}
	return meshSetting(capwap.VendorRecord{Type: 11, Value: b})
}
func (m *Manager) meshMemberSettingLocked(parent string) capwap.Element {
	return meshMembersElement(m.meshMembersLocked(parent))
}
