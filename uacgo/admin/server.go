// Package admin is the standalone Go controller's local management interface.
package admin

import (
	"context"
	"crypto/rand"
	"crypto/sha256"
	"embed"
	"encoding/hex"
	"encoding/json"
	"errors"
	"fmt"
	"io/fs"
	"net"
	"net/http"
	"net/url"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"sync"
	"time"
	"uacgo/capwap"
	"uacgo/controllercfg"
	"uacgo/cweng"
	"uacgo/mobility"
	"unicode/utf8"
)

//go:embed assets/*
var assets embed.FS

type Service struct {
	AutoBindFrequencies *uint16          `json:"auto_bind_frequencies,omitempty"`
	Groups              []string         `json:"groups,omitempty"`
	Deleting            bool             `json:"deleting,omitempty"`
	Bindings            []ServiceBinding `json:"bindings,omitempty"`
	Options             *WirelessOptions `json:"options,omitempty"`
	ID                  string           `json:"id"`
	WLAN                uint8            `json:"wlan_id"`
	SSID                string           `json:"ssid"`
	Security            string           `json:"security"`
	Passphrase          string           `json:"passphrase,omitempty"`
	HasPassword         bool             `json:"has_password,omitempty"`
	Enabled             bool             `json:"enabled"`
	Hidden              bool             `json:"hidden"`
	Radios              RadioList        `json:"radios"`
	APs                 []string         `json:"aps"`
}
type RadioList []uint8

func (r RadioList) MarshalJSON() ([]byte, error) {
	v := make([]int, len(r))
	for i, x := range r {
		v[i] = int(x)
	}
	return json.Marshal(v)
}

type Config struct {
	Resources           *controllercfg.Resources    `json:"controller_resources,omitempty"`
	EDCARules           []EDCARule                  `json:"edca_rules"`
	EDCAState           map[string]EDCABindingState `json:"edca_state,omitempty"`
	ReportedClientNames map[string]string           `json:"reported_client_names,omitempty"`
	Mesh                *MeshConfig                 `json:"mesh,omitempty"`
	Storm               *StormConfig                `json:"storm,omitempty"`
	Protection          *ProtectionConfig           `json:"protection,omitempty"`
	RRM                 []RRMRule                   `json:"rrm"`
	MulticastGroups     []MulticastGroup            `json:"multicast_groups"`
	Mobility            *MobilityConfig             `json:"mobility,omitempty"`
	Rates               *RatePolicy                 `json:"rates,omitempty"`
	RetiredAPs          []string                    `json:"retired_aps"`
	ClientLabels        map[string]ClientLabel      `json:"client_labels"`
	APDefaults          APOptions                   `json:"ap_defaults"`
	APProfiles          []APProfile                 `json:"ap_profiles"`
	Groups              []APGroup                   `json:"groups"`
	Templates           []APTemplate                `json:"templates"`
	BandNavigation      *BandNavigation             `json:"band_navigation,omitempty"`
	VLANPools           []VLANPool                  `json:"vlan_pools"`
	Radios              []RadioSetting              `json:"radios"`
	Interface           string                      `json:"interface"`
	Version             uint64                      `json:"version"`
	Services            []Service                   `json:"services"`
	Labels              map[string]string           `json:"labels"`
}
type ApplyStatus struct {
	EffectiveEnabled *bool     `json:"effective_enabled,omitempty"`
	Reason           string    `json:"reason,omitempty"`
	AP               string    `json:"ap_id"`
	Service          string    `json:"service_id"`
	State            string    `json:"state"`
	Error            string    `json:"error,omitempty"`
	At               time.Time `json:"at"`
}
type Manager struct {
	meshJobs             map[string]MeshJob
	history              WirelessHistory
	historySamples       map[string]time.Time
	historyClientSamples map[string]time.Time
	historySaved         time.Time
	historyDirty         bool
	clientHistoryCursor  uint64
	upgrades             upgradeCatalog
	upgradeActive        map[string]*upgradeRuntime
	ndpMAC               [6]byte
	rrmWake              chan struct{}
	rrmRuns              map[string]*rrmRun
	rrmJobs              map[string]RRMJob
	roamJobs             map[string][]*roamJob
	roamHistory          []RoamDecision
	roamSequence         uint64
	balance              mobility.Balance
	pmkTransitions       map[[6]byte]uint64
	pmks                 mobility.PMKCache
	stationStatistics    mobility.StationDB
	bssidLocations       map[[6]byte]bssidLocation
	clientRefresh        map[string]time.Time
	policyOwners         map[string]map[string]bool
	operations           map[string]APOperation
	pendingDeletes       map[string]map[string]map[uint8]uint8
	settling             map[string]commitSettlement
	batchRevision        map[string]uint64
	settledVersions      map[string]uint64
	settled              map[string]string
	assignments          WLANAssignments
	mu                   sync.Mutex
	engine               *cweng.Engine
	clients              *cweng.ClientTable
	path                 string
	config               Config
	known                map[string]cweng.APStatus
	applied              map[string]string
	status               map[string]ApplyStatus
	owned                map[string]map[uint8]map[uint8]bool
}

func New(engine *cweng.Engine, clients *cweng.ClientTable, dataDir string) (*Manager, error) {
	m := &Manager{engine: engine, clients: clients, path: filepath.Join(dataDir, "controller.json"), known: map[string]cweng.APStatus{}, applied: map[string]string{}, status: map[string]ApplyStatus{}, owned: map[string]map[uint8]map[uint8]bool{}}
	m.assignments = WLANAssignments{}
	m.pendingDeletes = map[string]map[string]map[uint8]uint8{}
	m.settling = map[string]commitSettlement{}
	m.batchRevision = map[string]uint64{}
	m.settled = map[string]string{}
	m.settledVersions = map[string]uint64{}
	m.operations = map[string]APOperation{}
	m.policyOwners = map[string]map[string]bool{}
	m.config = Config{Services: []Service{}, Labels: map[string]string{}}
	b, err := os.ReadFile(m.path)
	if err == nil {
		if err = json.Unmarshal(b, &m.config); err != nil {
			return nil, err
		}
	} else if !os.IsNotExist(err) {
		return nil, err
	}
	if m.config.Labels == nil {
		m.config.Labels = map[string]string{}
	}
	if b, err = os.ReadFile(filepath.Join(dataDir, "known-aps.json")); err == nil {
		_ = json.Unmarshal(b, &m.known)
	}
	if _, err := os.Stat(filepath.Join(dataDir, "wlan-state.json")); err == nil {
		if err := m.loadWLANState(); err != nil {
			return nil, err
		}
	} else if !os.IsNotExist(err) {
		return nil, err
	} else {
		if b, err := os.ReadFile(filepath.Join(dataDir, "owned-wlans.json")); err == nil {
			if err = json.Unmarshal(b, &m.owned); err != nil {
				return nil, err
			}
		} else if !os.IsNotExist(err) {
			return nil, err
		}
		migrationNeeded := true
		if b, err := os.ReadFile(filepath.Join(dataDir, "wlan-assignments.json")); err == nil {
			migrationNeeded = false
			if err = json.Unmarshal(b, &m.assignments); err != nil {
				return nil, err
			}
		} else if !os.IsNotExist(err) {
			return nil, err
		}
		// Migrate only the legacy format; subsequent assignments are per AP/radio.
		if migrationNeeded {
			for ap, wlans := range m.owned {
				for _, s := range m.config.Services {
					for radio, owned := range wlans[s.WLAN] {
						if !owned {
							continue
						}
						if m.assignments[ap] == nil {
							m.assignments[ap] = map[string]map[uint8]uint8{}
						}
						if m.assignments[ap][s.ID] == nil {
							m.assignments[ap][s.ID] = map[uint8]uint8{}
						}
						if m.assignments[ap][s.ID][radio] == 0 {
							m.assignments[ap][s.ID][radio] = s.WLAN
						}
					}
				}
			}
		}
	}
	if err := m.validateWLANState(); err != nil {
		return nil, err
	}
	if err := m.loadOperations(); err != nil {
		return nil, err
	}
	if err := m.loadPolicyOwners(); err != nil {
		return nil, err
	}
	if err := m.loadRRMJobs(); err != nil {
		return nil, err
	}
	if err := m.loadMeshJobs(); err != nil {
		return nil, err
	}
	if err := m.loadControllerIdentity(); err != nil {
		return nil, err
	}
	if err := m.loadHistory(); err != nil {
		return nil, err
	}
	if err := m.loadUpgrades(); err != nil {
		return nil, err
	}
	clients.ResolveService = m.resolveClientService
	m.rrmWake = make(chan struct{}, 1)
	m.balance.Start(time.Now())
	m.pmks.Start(time.Now())
	m.stationStatistics.Start(time.Now())
	clients.OnTransition = m.observePMKTransition
	clients.OnDeviceName = m.observeClientName
	engine.RegisterUpdHandlers(m.confirmImage)
	engine.RegisterImageActions(m.confirmImageAction)
	engine.AdmitStation = m.admitStation
	engine.ObserveAssociation = m.observeAssociation
	engine.CheckAssociation = m.checkAssociation
	engine.OnAPState = m.observeAPState
	engine.OnRoamingTrigger = m.queueRoaming
	engine.OnStationDiscovery = m.observeBalanceProbe
	engine.OnStationPMK = m.handlePMK
	engine.OnStationStatistics = m.observeStationStatistics
	engine.OnRSSIStatistics = m.observeRSSIStatistics
	engine.OnAPStatistics = m.observeAPStatistics
	engine.OnBSSIDLocations = m.observeBSSIDLocations
	engine.OnRRMReport = m.observeRRMReport
	engine.RegisterMeshControl(m.meshConfigure, m.meshAuthorize)
	// Same V6 upgrade boundary as36_roam_cfg_sync.sh; old Go prototypes
	// exposed modes which the shipped V6 Web never permits setting.
	if m.config.Mobility != nil && m.config.Mobility.NetworkMode != 2 {
		p := *m.config.Mobility
		p.NetworkMode = 2
		m.config.Mobility = &p
		if err := atomicJSON(m.path, m.config); err != nil {
			return nil, err
		}
	}
	if err := validateManagement(m.config); err != nil {
		return nil, err
	}
	defaults := mergeOptions(standaloneAPDefaults(), m.config.APDefaults)
	defaultsChanged := configurationKey(defaults, time.Time{}) != configurationKey(m.config.APDefaults, time.Time{})
	m.config.APDefaults = defaults
	resourcesMissing := m.config.Resources == nil
	if resourcesMissing {
		initial := initialControllerResources(m.config)
		m.config.Resources = &initial
	}
	if err := m.validateResourceUsage(m.config); err != nil {
		return nil, err
	}
	if resourcesMissing || defaultsChanged {
		if err := atomicJSON(m.path, m.config); err != nil {
			return nil, err
		}
	}
	m.applyControllerResources()
	return m, nil
}
func atomicJSON(path string, v any) error {
	b, err := json.MarshalIndent(v, "", "  ")
	if err != nil {
		return err
	}
	f, err := os.CreateTemp(filepath.Dir(path), ".controller-")
	if err != nil {
		return err
	}
	defer os.Remove(f.Name())
	defer f.Close()
	if err = f.Chmod(0600); err != nil {
		return err
	}
	if _, err = f.Write(b); err != nil {
		return err
	}
	if err = f.Sync(); err != nil {
		return err
	}
	if err = f.Close(); err != nil {
		return err
	}
	return os.Rename(f.Name(), path)
}
func (m *Manager) APs() []cweng.APStatus {
	live := m.engine.APs()
	m.mu.Lock()
	defer m.mu.Unlock()
	wasOnline := map[string]bool{}
	for id, v := range m.known {
		wasOnline[id] = v.Online
		v.Online = false
		v.State = "OFFLINE"
		m.known[id] = v
	}
	for _, v := range live {
		if old, ok := m.known[v.ID]; ok && old.ConnectedAt != v.ConnectedAt {
			m.clearAPSessionLocked(v.ID, old.ConnectedAt)
		}
		m.known[v.ID] = v
	}
	out := []cweng.APStatus{}
	for _, v := range m.known {
		if wasOnline[v.ID] && !v.Online {
			m.balance.ForgetAP(v.ID)

			for _, c := range m.clients.All() {
				if c.APID == v.ID {
					m.pmks.Disconnect(mobility.MAC(c.MAC), time.Now())
				}
			}
		}
		v.ProtectionLimits = protectionLimits(v)
		if name := m.config.Labels[v.ID]; name != "" {
			v.Name = name
		}
		for _, p := range m.config.APProfiles {
			if p.AP == v.ID {
				if p.Name != "" {
					v.Name = p.Name
				}
				if p.Location != "" {
					v.Location = p.Location
				}
			}
		}
		out = append(out, v)
	}
	sort.Slice(out, func(i, j int) bool { return out[i].ID < out[j].ID })
	return out
}

// snapshot evaluates schedules exactly once; HTTP saves replace configuration
// values, and the deep copy isolates nested options from concurrent edits.
func (m *Manager) snapshot() Config {
	m.mu.Lock()
	defer m.mu.Unlock()
	b, _ := json.Marshal(m.config)
	var cfg Config
	_ = json.Unmarshal(b, &cfg)
	now := time.Now()
	for i := range cfg.Services {
		cfg.Services[i].Enabled = cfg.Services[i].Enabled && serviceOptions(cfg.Services[i]).Schedule.active(now)
	}
	return cfg
}

func (m *Manager) Run(ctx context.Context) {
	rrmDone := make(chan struct{})
	go func() { defer close(rrmDone); m.runRRM(ctx) }()
	defer func() {
		<-rrmDone
	}()
	ticker := time.NewTicker(2 * time.Second)
	defer ticker.Stop()
	// One worker per AP; a stalled AP never serializes all other controllers.
	running := map[string]bool{}
	completed := make(chan string)
	var workers sync.WaitGroup
	defer func() {
		workers.Wait()
		m.captureHistory(m.APs(), time.Now())
		m.mu.Lock()
		defer m.mu.Unlock()
		if m.historyDirty {
			if atomicJSON(m.historyPath(), m.history) == nil {
				m.historyDirty = false
			}
		}
	}()
	var lastSave time.Time
	for {
		select {
		case <-ctx.Done():
			return
		case id := <-completed:
			delete(running, id)
		case <-ticker.C:
			m.observeOperations()
			m.finishDeletions()
			aps := m.APs()
			m.captureHistory(aps, time.Now())
			m.observeMeshJobs(aps, time.Now())
			m.observeUpgrades(time.Now())
			m.mu.Lock()
			m.balance.Tick(time.Now())
			m.pmks.Tick(time.Now())
			m.stationStatistics.Tick(time.Now())
			m.mu.Unlock()
			m.tickRRM(time.Now())
			cfg := m.snapshot()
			m.mu.Lock()
			if time.Since(lastSave) > 30*time.Second {
				_ = atomicJSON(filepath.Join(filepath.Dir(m.path), "known-aps.json"), m.known)
				lastSave = time.Now()
			}
			m.mu.Unlock()
			for _, ap := range aps {
				if !ap.Online || running[ap.ID] {
					continue
				}
				running[ap.ID] = true
				workers.Add(1)
				go func(ap cweng.APStatus) {
					defer workers.Done()
					m.reconcileAP(cweng.PinAP(ctx, ap), ap, cfg)
					select {
					case completed <- ap.ID:
					case <-ctx.Done():
					}
				}(ap)
			}
		}
	}
}

func (m *Manager) reconcileAP(ctx context.Context, ap cweng.APStatus, cfg Config) {
	defer func() {
		m.mu.Lock()
		defer m.mu.Unlock()
		if current, ok := m.known[ap.ID]; ok && current.ConnectedAt != ap.ConnectedAt {
			m.clearAPSessionLocked(ap.ID, ap.ConnectedAt)
		}
	}()

	if m.upgradeStep(ctx, ap, cfg) {
		return
	}
	if m.rrmStep(ctx, ap) {
		return
	}
	if changed, err := m.ensureEDCARules(); err != nil {
		return
	} else if changed {
		cfg = m.snapshot()
	}
	if err := m.applyAPManagement(ctx, ap, cfg); err != nil {
		return
	}
	cfg = effectiveRadioConfig(cfg, ap)
	navigation := cfg.BandNavigation
	m.applyBandNavigation(ctx, ap, navigation)
	if navigation != nil && ap.HasCapability(3) {
		m.mu.Lock()
		failed := m.status[ap.ID+"/band-navigation"].State == "failed"
		m.mu.Unlock()
		if failed {
			return
		}
	}
	m.applyStorm(ctx, ap, cfg)
	m.applyProtection(ctx, ap, cfg)
	m.applyPools(ctx, ap, cfg)
	for _, radio := range cfg.Radios {
		if radio.AP == ap.ID {
			m.reconcileRadio(ctx, ap, radio, cfg.Version)
		}
	}
	m.applyRates(ctx, ap, cfg)
	m.applyMobility(ctx, ap, cfg)
	m.applyMesh(ctx, ap, cfg)
	m.applyMulticastGroups(ctx, ap, cfg)
	for _, service := range cfg.Services {
		// Effective schedule was evaluated once with the batch snapshot.
		key := ap.ID + "/" + service.ID
		version := serviceVersion(service, ap, cfg)
		m.mu.Lock()
		previous := m.status[key]
		done := m.applied[key] == version && ((previous.State != "failed" && previous.State != "blocked") || time.Since(previous.At) < 30*time.Second)
		m.mu.Unlock()
		if done {
			continue
		}
		target := serviceTargets(service, ap.ID, cfg)
		if !target && !m.ownsService(ap.ID, service.ID) {
			continue
		}
		if !target {
			service.Enabled = false
		}
		if !service.Enabled && !m.ownsService(ap.ID, service.ID) {
			continue
		}
		state := ApplyStatus{AP: ap.ID, Service: service.ID, State: "applying", At: time.Now()}
		m.mu.Lock()
		m.status[key] = state
		m.mu.Unlock()
		err := m.apply(ctx, ap, service, cfg)
		state.At = time.Now()
		state.State = "acknowledged"
		if err == nil && service.Enabled && len(selectedServiceRadios(service, ap)) == 0 {
			state.State = "not_applicable"
			state.Reason = "此 AP 没有所选频段的可用覆盖射频"
		}
		if err != nil {
			state.State = "failed"
			var failure serviceApplyError
			if errors.As(err, &failure) && !failure.staged {
				state.State = "blocked"
			}
			state.Error = err.Error()
		}
		m.mu.Lock()
		m.status[key] = state
		m.applied[key] = version
		m.mu.Unlock()

	}
	m.applyReporting(ctx, ap, cfg)
	m.applyTelemetry(ctx, ap)

	m.commitAP(ctx, ap, cfg)
	if m.configurationSettled(ap, cfg) {
		m.refreshClientFacts(ctx, ap)
	}

}
func wlanElements(s Service, radio uint8) []capwap.Element {
	if !s.Enabled {
		return []capwap.Element{{Type: 0x0403, Value: []byte{radio, s.WLAN}}}
	}
	// V6 successful WLAN trace: 0x33dd01 + 0x0400 + vendor 0x63.
	// Address anchors: _uac_wserv_packet_send_callback 0x006dbd74,
	// cw_80211_add_wlan_assemble 0x0065a5d4, wsrv_new_assemble 0x00695f68.
	add := []byte{radio, s.WLAN, 0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}
	if s.Hidden {
		add[18] = 0
	}
	add = append(add, []byte(s.SSID)...)
	o := serviceOptions(s)
	ssid, _ := serviceSSID(s)
	add = append(add[:19], ssid...)
	mode, tail := serviceSecurity(s)
	para := capwap.PrivWsrvParaNew{Header: capwap.PrivWsrvParaFields{A: radio, B: s.WLAN, C: uint16(o.VLAN), D: 100, E: 3, F: boolean(o.Isolate), G: mode}, Tail: tail}

	return []capwap.Element{{Type: 0x0400, Value: add}, {Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0x63, []capwap.PrivElementValue{{Type: 0x63, Value: para.AssembleValue()}})}}
}
func (m *Manager) ownsAny(ap string, wlan uint8) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	for _, v := range m.owned[ap][wlan] {
		if v {
			return true
		}
	}
	return false
}
func (m *Manager) apply(ctx context.Context, ap cweng.APStatus, s Service, cfg Config) (err error) {
	staged := false
	defer func() {
		if err != nil {
			err = serviceApplyError{staged, err}
		}
	}()
	if ap.Radios <= 0 || ap.Radios > 31 {
		return errors.New("AP has not reported any radios")
	}
	selected := selectedServiceRadios(s, ap)
	// Validate every selected target before staging any radio. Incompatible
	// security on a second radio must not leave the first partially configured.
	for _, capability := range ap.Capabilities {
		bound, _ := binding(s, ap.ID, capability.RadioID)
		if s.Enabled && selected[capability.RadioID] && bound && !radioDisabled(cfg, ap.ID, capability.RadioID) {
			if err := validateServiceCapability(s, ap, capability.RadioID); err != nil {
				return err
			}
			if _, err := m.allocate(ap.ID, s.ID, capability.RadioID, capability.MaxSSID); err != nil {
				return err
			}
		}
	}
	for radio := uint8(1); radio <= uint8(ap.Radios); radio++ {
		bound, vlan := binding(s, ap.ID, radio)
		enabled := s.Enabled && selected[radio] && bound
		m.mu.Lock()
		slot := m.assignments[ap.ID][s.ID][radio]
		owned := slot != 0
		m.mu.Unlock()
		if enabled && radioDisabled(cfg, ap.ID, radio) {
			continue
		}
		if !enabled && !owned {
			continue
		}
		if enabled {
			max := 0
			for _, c := range ap.Capabilities {
				if c.RadioID == radio {
					max = c.MaxSSID
				}
			}
			var err error
			slot, err = m.allocate(ap.ID, s.ID, radio, max)
			if err != nil {
				return err
			}
		}
		if slot == 0 {
			continue
		}

		command := s
		command.WLAN = slot
		o := serviceOptions(s)
		o.VLAN = vlan
		command.Options = &o
		command.Enabled = enabled
		c, cancel := context.WithTimeout(ctx, 4*time.Second)
		var err error
		if enabled {
			err = validateServiceCapability(command, ap, radio)
		}
		if err == nil {
			m.dirtyAP(ap.ID)
			staged = true
			_, err = m.engine.Request(c, ap.ID, capwap.MsgIe1, advancedWLANElements(command, radio, ap))
		}
		cancel()
		if err != nil {
			return fmt.Errorf("radio %d: %w", radio, err)
		}
		if enabled {
			for _, el := range wirelessExtraElements(command, radio, ap) {
				c, cancel := context.WithTimeout(ctx, 4*time.Second)
				_, err := m.engine.Request(c, ap.ID, 7, []capwap.Element{el})
				cancel()
				if err != nil {
					return fmt.Errorf("radio %d extra: %w", radio, err)
				}
			}
		}
		if err := m.stageWLAN(ap.ID, s.ID, radio, slot, enabled); err != nil {
			return err
		}

	}
	return nil
}

func validate(s Service) error {
	if !utf8.ValidString(s.SSID) || len([]byte(s.SSID)) < 1 || strings.ContainsAny(s.SSID, "\x00\r\n") {
		return errors.New("SSID 必须为 1–32 字节，不能包含控制字符")
	}
	if !hasString([]string{"open", "wpa-psk", "wpa2-psk", "wpa-wpa2-psk", "wpa2-wpa3-psk"}, s.Security) {
		return errors.New("安全方式无效")
	}
	if strings.HasSuffix(s.Security, "psk") {
		valid := len(s.Passphrase) >= 8 && len(s.Passphrase) <= 63
		if len(s.Passphrase) == 64 {
			_, err := hex.DecodeString(s.Passphrase)
			valid = err == nil
		}
		for _, c := range []byte(s.Passphrase) {
			valid = valid && c >= 32 && c <= 126
		}
		if !valid {
			return errors.New("PSK 密码须为 8–63 个可见 ASCII 字符，或 64 位十六进制密钥")
		}
	}

	if err := validateBindings(s); err != nil {
		return err
	}
	if s.AutoBindFrequencies != nil && *s.AutoBindFrequencies == 0 {
		return errors.New("至少选择一个自动绑定频段")
	}
	if len(s.Radios) == 0 && s.AutoBindFrequencies == nil {
		return errors.New("至少选择一个射频")
	}
	seen := map[uint8]bool{}
	for _, r := range s.Radios {
		if r < 1 || r > 31 || seen[r] {
			return errors.New("射频列表无效")
		}
		seen[r] = true
	}
	return validateWirelessOptions(s)
}
func (m *Manager) saveService(s Service) (Service, error) {
	m.mu.Lock()
	defer m.mu.Unlock()
	if strings.HasSuffix(s.Security, "enterprise") {
		return s, fmt.Errorf("RADIUS 企业认证不在本程序功能范围内")
	}
	for _, g := range s.Groups {
		found := false
		for _, group := range m.config.Groups {
			found = found || g == group.ID
		}
		if !found {
			return s, fmt.Errorf("无线服务引用不存在的 AP 分组")
		}
	}
	idx := -1
	for i, old := range m.config.Services {
		if old.ID == s.ID && s.ID != "" {
			idx = i
			if old.Deleting {
				return s, errors.New("此服务正在删除，等待设备应答")
			}
			if s.Options == nil {
				s.Options = old.Options
			} else if s.Options.Radius != nil && s.Options.Radius.Secret == "" && old.Options != nil && old.Options.Radius != nil {
				r := *s.Options.Radius
				r.Secret = old.Options.Radius.Secret
				o := *s.Options
				o.Radius = &r
				s.Options = &o
			}
			s.WLAN = old.WLAN
			if s.Passphrase == "" {
				s.Passphrase = old.Passphrase
			}
			break
		}
	}
	if s.ID != "" && idx < 0 {
		return s, errors.New("无线服务不存在")
	}
	if s.Security == "open" {
		s.Passphrase = ""
	}
	if serviceOptions(s).VLANPool != 0 {
		found := false
		for _, p := range m.config.VLANPools {
			found = found || p.ID == serviceOptions(s).VLANPool && !p.Deleting
		}
		if !found {
			return s, errors.New("VLAN 池不存在或正在删除")
		}
	}
	if err := validate(s); err != nil {
		return s, err
	}
	if idx < 0 {
		used := map[uint8]bool{}
		for _, v := range m.config.Services {
			used[v.WLAN] = true
		}
		s.WLAN = 0
		for n := 1; n <= 255; n++ {
			i := uint8(n)
			if !used[i] {
				s.WLAN = i
				break
			}
		}

		if s.WLAN == 0 {
			return s, errors.New("无线服务已满")
		}
		id := make([]byte, 8)
		if _, err := rand.Read(id); err != nil {
			return s, err
		}
		s.ID = hex.EncodeToString(id)
	}
	next := m.config
	next.Version++
	next.Services = append([]Service(nil), m.config.Services...)
	if idx < 0 {
		next.Services = append(next.Services, s)
	} else {
		next.Services[idx] = s
	}
	if err := m.persistConfigLocked(next, false); err != nil {
		return s, err
	}
	return s, nil
}
func jsonReply(w http.ResponseWriter, status int, v any) {
	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	w.Header().Set("Cache-Control", "no-store")
	w.WriteHeader(status)
	_ = json.NewEncoder(w).Encode(v)
}
func (m *Manager) Handler() http.Handler {
	mux := http.NewServeMux()
	m.historyRoutes(mux)
	m.stormRoutes(mux)
	m.protectionScanRoutes(mux)
	m.protectionRoutes(mux)
	m.upgradeRoutes(mux)
	m.managementRoutes(mux)
	m.clientRoutes(mux)
	m.rateRoutes(mux)
	mux.HandleFunc("GET /api/aps/{id}/effective-radios", func(w http.ResponseWriter, r *http.Request) {
		for _, ap := range m.APs() {
			if ap.ID == r.PathValue("id") {
				cfg := effectiveRadioConfig(m.snapshot(), ap)
				rows := []RadioSetting{}
				for _, row := range cfg.Radios {
					if row.AP == ap.ID {
						rows = append(rows, row)
					}
				}
				jsonReply(w, 200, rows)
				return
			}
		}
		jsonReply(w, 404, map[string]string{"error": "AP 未知"})
	})
	mux.HandleFunc("GET /api/aps", func(w http.ResponseWriter, r *http.Request) { jsonReply(w, 200, m.APs()) })
	mux.HandleFunc("POST /api/aps/{id}/refresh", m.refreshAPHTTP)
	mux.HandleFunc("GET /api/aps/{id}/configuration", func(w http.ResponseWriter, r *http.Request) {
		ctx, cancel := context.WithTimeout(r.Context(), 6*time.Second)
		defer cancel()
		b, err := m.engine.RequestJSON(ctx, r.PathValue("id"), json.RawMessage(`{"method":"get","wireless":{"table":"radio_entry"}}`))
		if err != nil {
			jsonReply(w, 502, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 200, b)
	})
	mux.HandleFunc("GET /api/aps/{id}/reports", func(w http.ResponseWriter, r *http.Request) { jsonReply(w, 200, m.engine.Reports(r.PathValue("id"))) })
	mux.HandleFunc("POST /api/band-navigation", m.bandNavigationHTTP)
	mux.HandleFunc("GET /api/aps/{id}/band-navigation", func(w http.ResponseWriter, r *http.Request) {
		ctx, cancel := context.WithTimeout(r.Context(), 6*time.Second)
		defer cancel()
		b, err := m.readBandNavigation(ctx, r.PathValue("id"))
		if err != nil {
			jsonReply(w, 502, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 200, b)
	})
	mux.HandleFunc("GET /api/aps/{id}/wireless-capabilities", func(w http.ResponseWriter, r *http.Request) {
		ctx, cancel := context.WithTimeout(r.Context(), 6*time.Second)
		defer cancel()
		b, err := m.engine.RequestJSON(ctx, r.PathValue("id"), json.RawMessage(`{"method":"get","wireless":{"name":"capability"}}`))
		if err != nil {
			jsonReply(w, 502, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 200, b)
	})
	mux.HandleFunc("GET /api/clients", func(w http.ResponseWriter, r *http.Request) {
		rows := []map[string]any{}
		online := map[string]bool{}
		for _, ap := range m.APs() {
			online[ap.ID] = ap.Online
		}
		for _, ev := range m.clients.Display() {
			mac := net.HardwareAddr(ev.MAC[:]).String()
			m.mu.Lock()
			label := m.config.ClientLabels[mac]
			if label.Name == "" {
				label.Name = m.config.ReportedClientNames[mac]
			}
			m.mu.Unlock()
			state := ev.State
			if (state == "associating" && time.Since(ev.Seen) > 30*time.Second) || (state != "disconnected" && time.Since(ev.Seen) > 6*time.Minute) {
				state = "stale"
			}
			if !online[ev.APID] && state != "disconnected" {
				state = "ap_offline"
			}
			rows = append(rows, map[string]any{"vlan_id": ev.VLAN, "ssid": ev.SSID, "service_id": ev.ServiceID, "name": label.Name, "note": label.Note, "mac": mac, "ip": ev.IP, "ipv6": ev.IPv6, "mlo": ev.MLD != nil, "ap_id": ev.APID, "radio_id": ev.RadioID, "wlan_id": ev.WLANID, "state": state, "rssi_dbm": ev.RSSI, "last_seen": ev.Seen, "statistics": ev.Statistics, "connected_at": ev.ConnectedAt, "mlo_links": ev.MLOLinks, "radio_entries": ev.LinkStatus, "device": ev.Device})
		}
		sort.Slice(rows, func(i, j int) bool { return rows[i]["mac"].(string) < rows[j]["mac"].(string) })
		jsonReply(w, 200, rows)
	})
	mux.HandleFunc("GET /api/config", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		c := publicManagement(m.config)
		c.Services = append([]Service{}, c.Services...)
		for i := range c.Services {
			c.Services[i] = redactService(c.Services[i])
		}
		states := []ApplyStatus{}
		for _, v := range m.status {
			states = append(states, v)
		}
		jsonReply(w, 200, map[string]any{"config": c, "apply": states, "assignments": m.assignments, "operations": m.operations, "server_time": time.Now(), "timezone": time.Local.String()})
	})
	mux.HandleFunc("POST /api/services", func(w http.ResponseWriter, r *http.Request) {
		var s Service
		r.Body = http.MaxBytesReader(w, r.Body, 16<<10)
		dec := json.NewDecoder(r.Body)
		dec.DisallowUnknownFields()
		if err := dec.Decode(&s); err != nil {
			jsonReply(w, 400, map[string]string{"error": "请求格式无效"})
			return
		}
		s, err := m.saveService(s)
		if err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		s = redactService(s)
		jsonReply(w, 202, map[string]any{"status": "saved", "service": s})
	})
	mux.HandleFunc("POST /api/radios", m.saveRadioHTTP)
	m.mobilityRoutes(mux)
	m.meshRoutes(mux)
	m.multicastRoutes(mux)
	m.rrmRoutes(mux)
	m.edcaRoutes(mux)
	m.resourceRoutes(mux)
	mux.HandleFunc("POST /api/vlan-pools", m.poolHTTP)
	mux.HandleFunc("DELETE /api/vlan-pools/{id}", m.poolHTTP)
	mux.HandleFunc("GET /api/radios/defaults", m.radioDefaultsHTTP)
	mux.HandleFunc("DELETE /api/services/{id}", m.deleteServiceHTTP)
	mux.HandleFunc("POST /api/aps/{id}/led", func(w http.ResponseWriter, r *http.Request) {
		var v struct {
			On bool `json:"on"`
		}
		r.Body = http.MaxBytesReader(w, r.Body, 1024)
		if err := json.NewDecoder(r.Body).Decode(&v); err != nil {
			jsonReply(w, 400, map[string]string{"error": "请求格式无效"})
			return
		}
		value := []byte{0, 0, 0, 0}
		if v.On {
			value[3] = 1
		}
		elements := []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x39, Value: value}})}}
		result, err := m.engine.Request(r.Context(), r.PathValue("id"), 7, elements)
		if err != nil {
			jsonReply(w, 502, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 200, result)
	})
	mux.HandleFunc("POST /api/aps/{id}/label", func(w http.ResponseWriter, r *http.Request) {
		var v struct {
			Name string `json:"name"`
		}
		r.Body = http.MaxBytesReader(w, r.Body, 1024)
		if err := json.NewDecoder(r.Body).Decode(&v); err != nil || len([]byte(v.Name)) > 52 {
			jsonReply(w, 400, map[string]string{"error": "名称最多 52 字节"})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.Labels = map[string]string{}
		for k, v := range m.config.Labels {
			next.Labels[k] = v
		}
		next.Labels[r.PathValue("id")] = v.Name
		if err := m.persistConfigLocked(next, false); err != nil {
			jsonReply(w, 500, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 200, map[string]string{"status": "saved"})
	})
	mux.HandleFunc("GET /api/interfaces", func(w http.ResponseWriter, r *http.Request) {
		ifaces, err := net.Interfaces()
		if err != nil {
			jsonReply(w, 500, map[string]string{"error": err.Error()})
			return
		}
		rows := []map[string]any{}
		for _, i := range ifaces {
			addr, _ := i.Addrs()
			ips := []string{}
			for _, a := range addr {
				ips = append(ips, a.String())
			}
			rows = append(rows, map[string]any{"name": i.Name, "addresses": ips, "up": i.Flags&net.FlagUp != 0, "bound": i.Name == m.engine.BoundInterface()})
		}
		jsonReply(w, 200, rows)
	})
	mux.HandleFunc("POST /api/interface", func(w http.ResponseWriter, r *http.Request) {
		var v struct {
			Name string `json:"name"`
		}
		r.Body = http.MaxBytesReader(w, r.Body, 1024)
		if err := json.NewDecoder(r.Body).Decode(&v); err != nil {
			jsonReply(w, 400, map[string]string{"error": "请求格式无效"})
			return
		}
		i, err := net.InterfaceByName(v.Name)
		if err != nil || i.Flags&net.FlagLoopback != 0 {
			jsonReply(w, 400, map[string]string{"error": "请选择实际网络接口"})
			return
		}
		addrs, _ := i.Addrs()
		hasIP := false
		for _, a := range addrs {
			ip, _, _ := net.ParseCIDR(a.String())
			if ip.To4() != nil {
				hasIP = true
			}
		}
		if !hasIP {
			jsonReply(w, 400, map[string]string{"error": "所选接口没有 IPv4 地址"})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.Interface = v.Name
		if err := m.persistConfigLocked(next, false); err != nil {
			jsonReply(w, 500, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 200, map[string]string{"status": "saved", "message": "已保存，程序下次启动生效"})
	})
	sub, _ := fs.Sub(assets, "assets")
	mux.Handle("/", http.FileServer(http.FS(sub)))
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		host := r.Host
		if h, _, err := net.SplitHostPort(host); err == nil {
			host = h
		}
		if host != "localhost" && !net.ParseIP(host).IsLoopback() {
			jsonReply(w, 403, map[string]string{"error": "管理界面仅允许本机访问"})
			return
		}
		w.Header().Set("X-Content-Type-Options", "nosniff")
		w.Header().Set("Content-Security-Policy", "default-src 'self'; img-src 'self' data:; style-src 'self'; script-src 'self'; frame-ancestors 'none'; base-uri 'none'")
		if r.Method != "GET" && r.Method != "HEAD" {
			if origin := r.Header.Get("Origin"); origin != "" {
				u, e := url.Parse(origin)
				if e != nil || u.Host != r.Host {
					jsonReply(w, 403, map[string]string{"error": "请求来源无效"})
					return
				}
			}
		}
		mux.ServeHTTP(w, r)
	})
}

func configurationKey(v any, connected time.Time) string {
	b, _ := json.Marshal(v)
	sum := sha256.Sum256(b)
	return fmt.Sprintf("%x/%s", sum, connected.Format(time.RFC3339Nano))
}

func hasString(xs []string, v string) bool {
	for _, x := range xs {
		if x == v {
			return true
		}
	}
	return false
}

// mu held. Session-specific failures cannot block a new session, but WLAN
// ownership and deletion intent must survive until the new commit completes.
func (m *Manager) clearAPSessionLocked(ap string, connection time.Time) {
	if known, ok := m.known[ap]; !ok || known.ConnectedAt == connection {
		m.balance.ForgetAP(ap)

	}
	suffix := "/" + connection.Format(time.RFC3339Nano)
	for key, value := range m.applied {
		if strings.HasPrefix(key, ap+"/") && strings.HasSuffix(value, suffix) {
			delete(m.applied, key)
			delete(m.status, key)
		}
	}
	if strings.HasSuffix(m.settled[ap], suffix) {
		delete(m.settled, ap)
	}
	if s, ok := m.settling[ap]; ok && s.Connection == connection {
		delete(m.settling, ap)
	}
}
