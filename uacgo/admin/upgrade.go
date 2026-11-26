package admin

import (
	"bytes"
	"context"
	"crypto/md5"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"os"
	"path/filepath"
	"sort"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/firmware"
)

type UpgradeJob struct {
	ID         string    `json:"id"`
	AP         string    `json:"ap_id"`
	Image      string    `json:"image_id"`
	State      string    `json:"state"`
	Error      string    `json:"error,omitempty"`
	NotBefore  time.Time `json:"not_before"`
	Started    time.Time `json:"started"`
	Updated    time.Time `json:"updated"`
	Connection time.Time `json:"connection"`
	Bytes      int       `json:"bytes_sent"`
}
type upgradeCatalog struct {
	Images map[string]firmware.Image `json:"images"`
	Jobs   map[string]UpgradeJob     `json:"jobs"`
}
type upgradeRuntime struct {
	Job        string
	Identifier []byte
	Connection time.Time
	Info       capwap.ImageInformation
	Initiated  chan struct{}
	Confirmed  bool
	Expected   uint8
	Await      string
	Actions    chan capwap.PrivSubFirmwareAction
}

func (m *Manager) upgradePath() string {
	return filepath.Join(filepath.Dir(m.path), "ap-upgrades.json")
}
func (m *Manager) imagePath(id string) string {
	return filepath.Join(filepath.Dir(m.path), "firmware", id+".bin")
}
func (m *Manager) saveUpgrades() error { return atomicJSON(m.upgradePath(), m.upgrades) }
func (m *Manager) loadUpgrades() error {
	m.upgrades = upgradeCatalog{Images: map[string]firmware.Image{}, Jobs: map[string]UpgradeJob{}}
	m.upgradeActive = map[string]*upgradeRuntime{}
	b, err := os.ReadFile(m.upgradePath())
	if os.IsNotExist(err) {
		return nil
	}
	if err != nil {
		return err
	}
	if err = json.Unmarshal(b, &m.upgrades); err != nil {
		return err
	}
	if m.upgrades.Images == nil || m.upgrades.Jobs == nil {
		return fmt.Errorf("升级任务库损坏")
	}
	for id, j := range m.upgrades.Jobs {
		if j.State == "transferring" || j.State == "negotiating" || j.State == "verifying" {
			j.State = "interrupted"
			j.Error = "程序在传输期间退出；未自动重发或刷写"
			m.upgrades.Jobs[id] = j
		}
	}
	return nil
}
func upgradeBusy(j UpgradeJob) bool {
	switch j.State {
	case "queued", "negotiating", "transferring", "verifying", "waiting_reconnect":
		return true
	}
	return false
}
func (m *Manager) upgradeBusyLocked(ap string) bool {
	for _, j := range m.upgrades.Jobs {
		if m.upgradeTransportLocked(j.AP) == m.upgradeTransportLocked(ap) && upgradeBusy(j) && (j.State != "queued" || !time.Now().Before(j.NotBefore)) {
			return true
		}
	}
	return false
}
func (m *Manager) queueUpgrades(image string, aps []string, when time.Time) ([]UpgradeJob, error) { // mu held; all-or-nothing batch validation.
	im, ok := m.upgrades.Images[image]
	if !ok {
		return nil, fmt.Errorf("固件不存在")
	}
	if len(aps) == 0 || len(aps) > 1024 {
		return nil, fmt.Errorf("选择 1–1024 台 AP")
	}
	if when.IsZero() {
		when = time.Now()
	}
	if when.After(time.Now().Add(7 * 24 * time.Hour)) {
		return nil, fmt.Errorf("升级计划最多提前七天")
	}
	seen := map[string]bool{}
	var jobs []UpgradeJob
	for _, id := range aps {
		ap, ok := m.known[id]
		if !ok || seen[id] {
			return nil, fmt.Errorf("AP 不存在或重复")
		}
		seen[id] = true
		if err := im.Compatible(ap.Model, ap.HardwareVersion, ap.HardwareID, ap.BlockedFirmware); err != nil {
			return nil, fmt.Errorf("%s: %w", id, err)
		}
		if im.Size > 16<<20 && !ap.HasCapability(81) {
			return nil, fmt.Errorf("AP %s 不支持大固件传输", id)
		}
		for _, j := range m.upgrades.Jobs {
			if j.AP == id && upgradeBusy(j) {
				return nil, fmt.Errorf("AP %s 已有升级任务", id)
			}
		}
		for _, j := range m.operations {
			if m.upgradeTransportLocked(j.AP) == m.upgradeTransportLocked(id) && (j.State == "sending" || j.State == "waiting_reconnect") {
				return nil, fmt.Errorf("AP %s 正在重启/复位", id)
			}
		}
		for _, j := range m.meshJobs {
			if m.upgradeTransportLocked(j.AP) == m.upgradeTransportLocked(id) && (j.State == "sending" || j.State == "waiting_report") {
				return nil, fmt.Errorf("AP %s 所在 Mesh 单元有操作待确认", id)
			}
		}
		for _, j := range m.rrmJobs {
			if j.State == "collecting" || j.State == "planning" || j.State == "applying" {
				for target := range j.Targets {
					if m.upgradeTransportLocked(target) == m.upgradeTransportLocked(id) {
						return nil, fmt.Errorf("AP %s 所在传输单元正在无线优化", id)
					}
				}
			}
		}
		jobs = append(jobs, UpgradeJob{ID: newManagementID("upgrade"), AP: id, Image: image, NotBefore: when, State: "queued", Updated: time.Now()})
	}
	for _, j := range jobs {
		m.upgrades.Jobs[j.ID] = j
	}
	if err := m.saveUpgrades(); err != nil {
		for _, j := range jobs {
			delete(m.upgrades.Jobs, j.ID)
		}
		return nil, err
	}
	return jobs, nil
}
func (m *Manager) importImage(b []byte) (firmware.Image, error) {
	im, err := firmware.Inspect(b)
	if err != nil {
		return im, err
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	if old, ok := m.upgrades.Images[im.ID]; ok {
		return old, nil
	}
	total := len(b)
	for _, row := range m.upgrades.Images {
		total += row.Size
	}
	if len(m.upgrades.Images) >= 16 || total > 256<<20 {
		return im, fmt.Errorf("固件库最多 16 个镜像、256 MiB，请先删除旧镜像")
	}
	if err = os.MkdirAll(filepath.Dir(m.imagePath(im.ID)), 0700); err != nil {
		return im, err
	}
	f, err := os.CreateTemp(filepath.Dir(m.imagePath(im.ID)), ".upload-")
	if err != nil {
		return im, err
	}
	defer os.Remove(f.Name())
	if _, err = f.Write(b); err == nil {
		err = f.Sync()
	}
	closeErr := f.Close()
	if err == nil {
		err = closeErr
	}
	if err == nil {
		err = os.Rename(f.Name(), m.imagePath(im.ID))
	}
	if err != nil {
		return im, err
	}
	m.upgrades.Images[im.ID] = im
	if err = m.saveUpgrades(); err != nil {
		delete(m.upgrades.Images, im.ID)
		os.Remove(m.imagePath(im.ID))
	}
	return im, err
}
func (m *Manager) confirmImage(ap string, conn time.Time, id []byte) (capwap.ImageInformation, error) {
	m.mu.Lock()
	defer m.mu.Unlock()
	rt := m.upgradeActive[ap]
	if rt == nil || !rt.Connection.Equal(conn) || !bytes.Equal(rt.Identifier, id) {
		return capwap.ImageInformation{}, fmt.Errorf("没有授权此 AP/会话/镜像")
	}
	if !rt.Confirmed {
		rt.Confirmed = true
		close(rt.Initiated)
	}
	return rt.Info, nil
}
func (m *Manager) confirmImageAction(ap string, conn time.Time, a capwap.PrivSubFirmwareAction) (*capwap.PrivSubFirmwareAction, error) {
	m.mu.Lock()
	defer m.mu.Unlock()
	rt := m.upgradeActive[ap]
	if rt == nil || !rt.Connection.Equal(conn) {
		// The final permission reply may be lost after the worker has finished.
		// Keep that exact authorization retryable until the AP reconnects.
		for _, j := range m.upgrades.Jobs {
			im := m.upgrades.Images[j.Image]
			if j.AP == ap && j.State == "waiting_reconnect" && j.Connection.Equal(conn) && time.Since(j.Updated) < 8*time.Minute && im.Size > 16<<20 && j.Bytes == im.Size && a.Type == 3 && a.SubType == 255 && a.Action == 0 {
				return &capwap.PrivSubFirmwareAction{Type: 2, SubType: 255}, nil
			}
		}
		return nil, fmt.Errorf("没有此会话的升级任务")
	}
	if a.Type != 1 && a.Type != 3 && a.Type != 5 {
		return nil, fmt.Errorf("意外的升级动作")
	}
	if a.Type == 5 {
		return nil, nil
	}
	if a.SubType != rt.Expected || a.Type == 1 && rt.Await != "sub" || a.Type == 3 && rt.Await != "final" {
		return nil, fmt.Errorf("升级校验顺序或分块不符")
	}
	if a.Type == 3 && a.Action == 0 {
		j := m.upgrades.Jobs[rt.Job]
		j.State = "waiting_reconnect"
		j.Updated = time.Now()
		m.upgrades.Jobs[j.ID] = j
		if err := m.saveUpgrades(); err != nil {
			return nil, err
		}
	}
	select {
	case rt.Actions <- a:
	default:
	}
	if a.Type == 3 && a.Action == 0 {
		return &capwap.PrivSubFirmwareAction{Type: 2, SubType: 255}, nil
	}
	return nil, nil
}
func (m *Manager) updateUpgrade(id, state, why string, sent int) error {
	m.mu.Lock()
	defer m.mu.Unlock()
	j := m.upgrades.Jobs[id]
	j.State = state
	j.Error = why
	j.Bytes = sent
	j.Updated = time.Now()
	m.upgrades.Jobs[id] = j
	return m.saveUpgrades()
}
func (m *Manager) upgradeStep(ctx context.Context, ap cweng.APStatus, cfg Config) bool {
	m.mu.Lock()
	var job UpgradeJob
	for _, j := range m.upgrades.Jobs {
		if j.AP == ap.ID && upgradeBusy(j) && !time.Now().Before(j.NotBefore) {
			job = j
			break
		}
	}
	if job.ID == "" {
		busy := m.upgradeTransportActiveLocked(ap.ID)
		m.mu.Unlock()
		return busy
	}
	if job.State == "queued" && !m.upgradeTurnLocked(job) {
		busy := m.upgradeTransportActiveLocked(ap.ID)
		m.mu.Unlock()
		return busy
	}
	if job.State != "queued" {
		m.mu.Unlock()
		return true
	}
	// Allow initial configuration to finish before pausing normal reconciliation.
	if m.settled[ap.ID] != configurationKey(effectiveRadioConfig(cfg, ap), ap.ConnectedAt) {
		m.mu.Unlock()
		return false
	}
	im := m.upgrades.Images[job.Image]
	if err := im.Compatible(ap.Model, ap.HardwareVersion, ap.HardwareID, ap.BlockedFirmware); err != nil {
		job.State = "failed"
		job.Error = err.Error()
		m.upgrades.Jobs[job.ID] = job
		_ = m.saveUpgrades()
		m.mu.Unlock()
		return false
	}
	job.State = "negotiating"
	job.Connection = ap.ConnectedAt
	job.Started = time.Now()
	job.Updated = time.Now()
	m.upgrades.Jobs[job.ID] = job
	if err := m.saveUpgrades(); err != nil {
		job.State = "failed"
		job.Error = err.Error()
		m.upgrades.Jobs[job.ID] = job
		m.mu.Unlock()
		return false
	}
	m.mu.Unlock()
	err := m.transferImage(ctx, ap, job, im)
	if err != nil {
		m.mu.Lock()
		current := m.upgrades.Jobs[job.ID]
		if current.State != "waiting_reconnect" {
			current.State = "failed"
		}
		current.Error = err.Error()
		current.Updated = time.Now()
		m.upgrades.Jobs[job.ID] = current
		_ = m.saveUpgrades()
		m.mu.Unlock()
	}
	return true
}
func (m *Manager) transferImage(ctx context.Context, ap cweng.APStatus, j UpgradeJob, im firmware.Image) error {
	ctx, cancel := context.WithTimeout(cweng.PinAP(ctx, ap), 15*time.Minute)
	defer cancel()
	b, err := os.ReadFile(m.imagePath(im.ID))
	if err != nil {
		return err
	}
	actual, err := firmware.Inspect(b)
	if err != nil || actual.ID != im.ID {
		return fmt.Errorf("固件文件完整性校验失败")
	}
	hash := md5.Sum(b)
	rt := &upgradeRuntime{Job: j.ID, Identifier: im.Identifier(), Connection: ap.ConnectedAt, Info: capwap.ImageInformation{FileInfo: uint32(len(b)), Info: hash}, Initiated: make(chan struct{}), Actions: make(chan capwap.PrivSubFirmwareAction, 8)}
	m.mu.Lock()
	m.upgradeActive[ap.ID] = rt
	m.mu.Unlock()
	defer func() { m.mu.Lock(); delete(m.upgradeActive, ap.ID); m.mu.Unlock() }()
	request := func(kind uint32, els ...capwap.Element) error {
		_, err := m.engine.Request(ctx, ap.ID, kind, els)
		return err
	}
	large := len(b) > 16<<20
	if large {
		if err = request(7, privateSetting(0xaf, (capwap.PrivLargeFirmwareInfo{Type: 1, TotalSize: uint32(len(b)), SubImages: uint32((len(b) + (16 << 20) - 1) / (16 << 20)), MD5: hash}).AssembleValue())); err != nil {
			return err
		}
	}
	if err = request(7, capwap.Element{Type: 0x19, Value: rt.Identifier}); err != nil {
		return err
	}
	timer := time.NewTimer(30 * time.Second)
	defer timer.Stop()
	select {
	case <-rt.Initiated:
	case <-ctx.Done():
		return ctx.Err()
	case <-timer.C:
		return fmt.Errorf("AP 未发起镜像下载握手")
	}
	if err = m.updateUpgrade(j.ID, "transferring", "", 0); err != nil {
		return err
	}
	for start, index := 0, uint8(0); start < len(b); index++ {
		end := len(b)
		if large && end > start+16<<20 {
			end = start + (16 << 20)
		}
		if large {
			subhash := md5.Sum(b[start:end])
			m.mu.Lock()
			rt.Expected = index
			rt.Await = ""
			drainImageActions(rt)
			m.mu.Unlock()
			if err = request(15, privateSetting(0xb0, (capwap.PrivSubFirmwareInfo{Type: 1, SubType: index, TotalSize: uint32(end - start), MD5: subhash}).AssembleValue())); err != nil {
				return err
			}
		}
		for off := start; off < end; {
			next := min(off+1024, end)
			typ := uint8(1)
			if !large && next == len(b) {
				typ = 2
			}
			els := []capwap.Element{{Type: 0x18, Value: (capwap.ImageData{Type: typ, Data: b[off:next]}).AssembleValue()}}
			if typ == 2 {
				els = append(els, capwap.Element{Type: 0x1a, Value: rt.Info.AssembleValue()})
			}
			if err = request(15, els...); err != nil {
				return fmt.Errorf("偏移 %d: %w", off, err)
			}
			off = next
			j.Bytes = off
			if off == len(b) || off%(64<<10) == 0 {
				if err = m.updateUpgrade(j.ID, "transferring", "", off); err != nil {
					return err
				}
			}
		}
		if large {
			m.mu.Lock()
			rt.Await = "sub"
			m.mu.Unlock()
			if err = request(15, privateSetting(0xb1, (capwap.PrivSubFirmwareAction{Type: 0, SubType: index}).AssembleValue())); err != nil {
				return err
			}
			if err = waitImageAction(ctx, rt, 1, index); err != nil {
				return err
			}
		}
		start = end
	}
	if err = m.updateUpgrade(j.ID, "verifying", "", len(b)); err != nil {
		return err
	}
	if large {
		m.mu.Lock()
		rt.Expected = 255
		rt.Await = "final"
		drainImageActions(rt)
		m.mu.Unlock()
		if err = request(15, capwap.Element{Type: 0x18, Value: []byte{2, 0, 0, 0, 0}}); err != nil {
			return err
		}
		if err = waitImageAction(ctx, rt, 3, 255); err != nil {
			return err
		}
		return nil // Flash permission was returned in response to the AP's final MD5 result.
	}
	// Record reboot intent durably before the irreversible reset request.
	if err = m.updateUpgrade(j.ID, "waiting_reconnect", "", len(b)); err != nil {
		return err
	}
	return request(17, capwap.Element{Type: 0x19, Value: rt.Identifier}, privateSetting(0x23, []byte{0, 0, 0, 1}))
}
func waitImageAction(ctx context.Context, rt *upgradeRuntime, typ, index byte) error {
	timer := time.NewTimer(90 * time.Second)
	defer timer.Stop()
	for {
		select {
		case a := <-rt.Actions:
			if a.Type != typ || a.SubType != index {
				continue
			}
			if a.Action != 0 {
				return fmt.Errorf("AP 固件校验失败: %d", a.Action)
			}
			return nil
		case <-ctx.Done():
			return ctx.Err()
		case <-timer.C:
			return fmt.Errorf("AP 固件校验回报超时")
		}
	}
}
func (m *Manager) observeUpgrades(now time.Time) { // known snapshots already refreshed; mu held here.
	m.mu.Lock()
	defer m.mu.Unlock()
	changed := false
	for id, j := range m.upgrades.Jobs {
		if j.State == "queued" && now.After(j.NotBefore.Add(24*time.Hour)) {
			j.State = "failed"
			j.Error = "AP 未在计划后一天内上线"
			changed = true
		}
		if j.State == "waiting_reconnect" {
			ap := m.known[j.AP]
			if ap.Online && ap.ConnectedAt.After(j.Connection) {
				im := m.upgrades.Images[j.Image]
				confirmed := ap.SoftwareVersion == im.Version
				if ap.FirmwareID != "" && im.FirmwareID != "" {
					confirmed = ap.FirmwareID == im.FirmwareID
				}
				if confirmed {
					j.State = "completed"
					j.Error = ""
				} else {
					j.State = "failed"
					j.Error = "AP 已重连，但上报的固件版本不符"
				}
				changed = true
			} else if now.Sub(j.Updated) > 8*time.Minute {
				j.State = "failed"
				j.Error = "未观察到升级后的 AP 重新接入"
				changed = true
			}
		}
		if changed {
			m.upgrades.Jobs[id] = j
		}
	}
	if changed {
		_ = m.saveUpgrades()
	}
}
func (m *Manager) upgradeRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/upgrades", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		images := []firmware.Image{}
		for _, im := range m.upgrades.Images {
			images = append(images, im)
		}
		sort.Slice(images, func(i, j int) bool { return images[i].ID < images[j].ID })
		jsonReply(w, 200, map[string]any{"images": images, "jobs": m.upgrades.Jobs})
	})
	mux.HandleFunc("POST /api/upgrades/images", func(w http.ResponseWriter, r *http.Request) {
		r.Body = http.MaxBytesReader(w, r.Body, firmware.MaxSize)
		b, err := io.ReadAll(r.Body)
		if err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		im, err := m.importImage(b)
		if err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 201, im)
	})
	mux.HandleFunc("DELETE /api/upgrades/images/{id}", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		id := r.PathValue("id")
		if _, ok := m.upgrades.Images[id]; !ok {
			jsonReply(w, 404, map[string]string{"error": "固件不存在"})
			return
		}
		for _, j := range m.upgrades.Jobs {
			if j.Image == id && upgradeBusy(j) {
				jsonReply(w, 409, map[string]string{"error": "此固件仍被升级任务引用"})
				return
			}
		}
		im := m.upgrades.Images[id]
		delete(m.upgrades.Images, id)
		if err := m.saveUpgrades(); err != nil {
			m.upgrades.Images[id] = im
			jsonReply(w, 500, map[string]string{"error": err.Error()})
			return
		}
		_ = os.Remove(m.imagePath(id))
		jsonReply(w, 200, map[string]bool{"deleted": true})
	})
	mux.HandleFunc("POST /api/upgrades", func(w http.ResponseWriter, r *http.Request) {
		var in struct {
			Image     string    `json:"image_id"`
			APs       []string  `json:"aps"`
			NotBefore time.Time `json:"not_before"`
		}
		if err := decodeManagement(w, r, &in); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.APs()
		m.mu.Lock()
		defer m.mu.Unlock()
		jobs, err := m.queueUpgrades(in.Image, in.APs, in.NotBefore)
		if err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, jobs)
	})
	mux.HandleFunc("DELETE /api/upgrades/{id}", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		j, ok := m.upgrades.Jobs[r.PathValue("id")]
		if !ok {
			jsonReply(w, 404, map[string]string{"error": "任务不存在"})
			return
		}
		if j.State != "queued" {
			jsonReply(w, 409, map[string]string{"error": "只可取消尚未开始的任务"})
			return
		}
		old := j
		j.State = "cancelled"
		j.Updated = time.Now()
		m.upgrades.Jobs[j.ID] = j
		if err := m.saveUpgrades(); err != nil {
			m.upgrades.Jobs[j.ID] = old
			jsonReply(w, 500, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 200, j)
	})
}

// Called under Manager.mu before opening the next checksum phase. Old repeated
// reports cannot fill the bounded queue and hide the next sub-image result.
func drainImageActions(rt *upgradeRuntime) {
	for {
		select {
		case <-rt.Actions:
		default:
			return
		}
	}
}

// A CAP and its forwarded children share connectivity; RF changes or another
// flash operation in the same tree must wait until the active flash finishes.
func (m *Manager) upgradeTransportLocked(ap string) string {
	seen := map[string]int{}
	var path []string
	for {
		if start, exists := seen[ap]; exists {
			// Malformed/cyclic role metadata must not produce a different
			// transport identity depending on which member starts the walk.
			root := ap
			for _, id := range path[start:] {
				if id < root {
					root = id
				}
			}
			return root
		}
		seen[ap] = len(path)
		path = append(path, ap)
		parent := m.known[ap].MeshParent
		if parent == "" {
			return ap
		}
		ap = parent
	}
}
func (m *Manager) upgradeTransportActiveLocked(ap string) bool {
	root := m.upgradeTransportLocked(ap)
	for _, j := range m.upgrades.Jobs {
		if m.upgradeTransportLocked(j.AP) == root && upgradeBusy(j) && j.State != "queued" {
			return true
		}
	}
	return false
}
func (m *Manager) upgradeTurnLocked(job UpgradeJob) bool {
	root := m.upgradeTransportLocked(job.AP)
	now := time.Now()
	for _, j := range m.upgrades.Jobs {
		if j.ID == job.ID || !upgradeBusy(j) || m.upgradeTransportLocked(j.AP) != root || now.Before(j.NotBefore) {
			continue
		}
		if j.State != "queued" || j.NotBefore.Before(job.NotBefore) || j.NotBefore.Equal(job.NotBefore) && j.ID < job.ID {
			return false
		}
	}
	return true
}
