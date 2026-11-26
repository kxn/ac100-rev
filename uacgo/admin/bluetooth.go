package admin

import (
	"context"
	"crypto/md5"
	"encoding/binary"
	"encoding/hex"
	"encoding/json"
	"fmt"
	"net"
	"net/http"
	"os"
	"path/filepath"
	"slices"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

type BluetoothFilter struct {
	Enabled bool   `json:"enabled"`
	Type    uint8  `json:"type"`
	Mode    uint8  `json:"mode"`
	Data    string `json:"data"`
}
type BluetoothRule struct {
	PolicyTarget
	ID          string            `json:"id"`
	Name        string            `json:"name"`
	Mode        int               `json:"mode"`
	Username    string            `json:"operation_username,omitempty"`
	Password    string            `json:"operation_password,omitempty"`
	HasPassword bool              `json:"has_password,omitempty"`
	Scan        bool              `json:"scan"`
	RSSIDedup   bool              `json:"rssi_deduplicate"`
	DataDedup   bool              `json:"data_deduplicate"`
	RSSI        int               `json:"rssi_threshold"`
	Channels    RadioList         `json:"channels"`
	Filters     []BluetoothFilter `json:"filters"`
	Server      uint8             `json:"server"`
}
type BluetoothTopic struct {
	Type     uint8  `json:"type"`
	Function uint8  `json:"function"`
	Format   uint8  `json:"format"`
	Topic    string `json:"topic"`
	Comment  string `json:"comment"`
}
type BluetoothServer struct {
	ID          uint8            `json:"id"`
	Name        string           `json:"name"`
	AddressType string           `json:"address_type"`
	Address     string           `json:"address"`
	Port        uint16           `json:"port"`
	Protocol    string           `json:"protocol"`
	Username    string           `json:"username"`
	Password    string           `json:"password,omitempty"`
	HasPassword bool             `json:"has_password,omitempty"`
	ClientID    string           `json:"client_id"`
	TLS         bool             `json:"tls"`
	CA          []byte           `json:"ca,omitempty"`
	Connected   bool             `json:"connected"`
	Topics      []BluetoothTopic `json:"topics"`
}
type BluetoothConfig struct {
	Rules   []BluetoothRule   `json:"rules"`
	Servers []BluetoothServer `json:"servers"`
}

func validateBluetooth(p *BluetoothConfig, cfg Config) error {
	if p == nil {
		return nil
	}
	if len(p.Rules) > 3000 || len(p.Servers) > 255 {
		return fmt.Errorf("蓝牙规则或服务器数量超限")
	}
	ids := map[uint8]bool{}
	totalCA := 0
	for _, s := range p.Servers {
		totalCA += len(s.CA)
		if s.ID == 0 || ids[s.ID] || s.Name == "" || !validLabel(s.Name, 256) || !validLabel(s.Address, 255) || s.Address == "" || s.Protocol != "mqtt" || len(s.CA) > 61440 || s.TLS && len(s.CA) == 0 || !validLabel(s.Username, 255) || !validLabel(s.Password, 255) || !validLabel(s.ClientID, 255) || len(s.Topics) > 32 {
			return fmt.Errorf("蓝牙服务器参数无效")
		}
		ids[s.ID] = true
		ip := net.ParseIP(s.Address)
		if s.AddressType != "url" && s.AddressType != "ipv4" && s.AddressType != "ipv6" || s.AddressType == "ipv4" && (ip == nil || ip.To4() == nil) || s.AddressType == "ipv6" && (ip == nil || ip.To4() != nil) {
			return fmt.Errorf("物联网服务器地址类型不符")
		}
		for _, t := range s.Topics {
			if t.Type != 0 || t.Function != 0 || t.Format != 0 || t.Topic == "" || !validLabel(t.Topic, 255) || !validLabel(t.Comment, 256) {
				return fmt.Errorf("物联网主题无效")
			}
		}
	}
	if totalCA > 1<<20 {
		return fmt.Errorf("蓝牙证书总容量超过 1 MiB")
	}
	groups := map[string]bool{}
	for _, g := range cfg.Groups {
		groups[g.ID] = true
	}
	rules := map[string]bool{}
	names := map[string]bool{}
	for _, r := range p.Rules {
		if r.ID == "" || rules[r.ID] || names[r.Name] || r.Name == "" || !validLabel(r.Name, 256) || r.Mode < 0 || r.Mode > 2 || r.RSSI < -127 || r.RSSI > 0 || len(r.Channels) > 40 || len(r.Filters) > 10 || !validLabel(r.Username, 32) || !validLabel(r.Password, 32) || r.Mode == 2 && (r.Username == "" || len(r.Password) < 5) || r.Server != 0 && !ids[r.Server] {
			return fmt.Errorf("蓝牙规则参数无效或服务器不存在")
		}
		rules[r.ID] = true
		names[r.Name] = true
		for _, g := range r.Groups {
			if !groups[g] {
				return fmt.Errorf("蓝牙规则引用不存在的 AP 分组")
			}
		}
		channels := map[uint8]bool{}
		for _, c := range r.Channels {
			if c > 39 || channels[c] {
				return fmt.Errorf("蓝牙广播信道为 0–39，不能重复")
			}
			channels[c] = true
		}
		for _, f := range r.Filters {
			if f.Mode > 2 || len(f.Data) > 255 || !validLabel(f.Data, 255) {
				return fmt.Errorf("蓝牙过滤数据最多 255 字节")
			}
		}
	}
	return nil
}
func bluetoothFor(p *BluetoothConfig, ap string, cfg Config) *BluetoothRule {
	if p != nil {
		for _, r := range p.Rules {
			if r.PolicyTarget.matches(ap, cfg) {
				v := r
				return &v
			}
		}
	}
	return nil
}
func bluetoothTLV(typ uint16, value []byte) []byte {
	b := binary.BigEndian.AppendUint16(nil, typ)
	b = binary.BigEndian.AppendUint16(b, uint16(len(value)))
	return append(b, value...)
}
func bluetoothGateway(r BluetoothRule) []byte {
	mode, flags := boolean(r.Scan), byte(0)
	if r.RSSIDedup {
		flags |= 1
	}
	if r.DataDedup {
		flags |= 2
	}
	b := []byte{mode, flags}
	var tlvs []byte
	if r.Scan {
		tlvs = append(tlvs, bluetoothTLV(0, []byte{byte(r.RSSI)})...)
		tlvs = append(tlvs, bluetoothTLV(1, append([]byte{byte(len(r.Channels))}, r.Channels...))...)
		filters := []byte{0}
		for _, f := range r.Filters {
			if !f.Enabled {
				continue
			}
			filters[0]++
			filters = append(filters, f.Type, f.Mode, byte(len(f.Data)))
			filters = append(filters, []byte(f.Data)...)
		}
		tlvs = append(tlvs, bluetoothTLV(2, filters)...)
	}
	b = binary.BigEndian.AppendUint32(b, uint32(len(tlvs)))
	return append(b, tlvs...)
}
func bluetoothCertificate(s BluetoothServer) (string, []byte) {
	sum := md5.Sum(s.CA)
	name := hex.EncodeToString(sum[:])
	b := append([]byte{32}, []byte(name)...)
	b = append(b, []byte(name)...)
	b = binary.BigEndian.AppendUint16(b, uint16(len(s.CA)))
	return name, append(b, s.CA...)
}
func bluetoothServerWire(s BluetoothServer) []byte {
	// V6 iot_server_packet_create fixes protocol/function to zero on the wire;
	// the address remains a hostname string for URL, IPv4 and IPv6 alike.
	b := []byte{s.ID, 0, 0, byte(len(s.Address))}
	b = append(b, []byte(s.Address)...)
	b = binary.BigEndian.AppendUint16(b, s.Port)
	login := append([]byte{byte(len(s.Username))}, []byte(s.Username)...)
	login = append(login, byte(len(s.Password)))
	login = append(login, []byte(s.Password)...)
	tlvs := bluetoothTLV(0, login)
	tlvs = append(tlvs, bluetoothTLV(2, []byte(s.ClientID))...)
	topics := []byte{byte(len(s.Topics))}
	for _, t := range s.Topics {
		topics = append(topics, t.Type, t.Function, t.Format, byte(len(t.Topic)))
		topics = append(topics, []byte(t.Topic)...)
	}
	tlvs = append(tlvs, bluetoothTLV(3, topics)...)
	if s.TLS {
		name, _ := bluetoothCertificate(s)
		digest := md5.Sum([]byte(name))
		v := append([]byte{0}, []byte(hex.EncodeToString(digest[:]))...)
		v = append(v, byte(len(name)))
		v = append(v, []byte(name)...)
		tlvs = append(tlvs, bluetoothTLV(1, v)...)
	}
	b = binary.BigEndian.AppendUint32(b, uint32(len(tlvs)))
	return append(b, tlvs...)
}
func bluetoothMode(mode int, ap cweng.APStatus) capwap.Element {
	enabled, wire := byte(1), uint32(0xffffffff)
	if mode == -1 {
		enabled = 0
	} else if ap.SubCapabilities[77]&1 != 0 {
		wire = map[int]uint32{0: 4, 1: 2, 2: 1}[mode]
	}
	b := binary.BigEndian.AppendUint32([]byte{enabled}, wire)
	b = binary.BigEndian.AppendUint32(b, 0xffffffff)
	return privateSetting(0xa7, b)
}
func (m *Manager) applyBluetooth(ctx context.Context, ap cweng.APStatus, cfg Config) {
	if !ap.HasCapability(77) || cfg.Bluetooth == nil && !m.policyOwned(ap.ID, "bluetooth") {
		return
	}
	r := bluetoothFor(cfg.Bluetooth, ap.ID, cfg)
	if r == nil && !m.policyOwned(ap.ID, "bluetooth") {
		m.mu.Lock()
		delete(m.status, ap.ID+"/bluetooth")
		m.mu.Unlock()
		return
	}
	key := ap.ID + "/bluetooth"
	fail := func(err error) {
		m.mu.Lock()
		m.status[key] = ApplyStatus{AP: ap.ID, Service: "bluetooth", State: "failed", Error: err.Error(), At: time.Now()}
		m.mu.Unlock()
	}
	if r != nil && (r.Mode == 0 && (!ap.HasCapability(102) || ap.SubCapabilities[102]&1 == 0) || r.Mode == 2 && !ap.HasCapability(79)) {
		m.mu.Lock()
		m.status[ap.ID+"/bluetooth"] = ApplyStatus{AP: ap.ID, Service: "bluetooth", State: "blocked", Error: "AP 未声明此蓝牙工作模式的能力", At: time.Now()}
		m.mu.Unlock()
		return
	}

	newServer := uint8(0)
	if r != nil && r.Mode == 0 {
		newServer = r.Server
	}
	m.mu.Lock()
	oldServers := append([]uint8{}, m.bluetoothOwned[ap.ID]...)
	m.mu.Unlock()
	intent := append([]uint8{}, oldServers...)
	found := newServer == 0
	for _, id := range intent {
		found = found || id == newServer
	}
	if !found {
		intent = append(intent, newServer)
	}
	m.mu.Lock()
	err := m.saveBluetoothBindingsLocked(ap.ID, intent)
	m.mu.Unlock()
	if err != nil {
		fail(err)
		return
	}

	fallback := -1
	if r == nil {
		if options, err := effectiveAPOptions(cfg, ap); err == nil && options.Bluetooth != nil {
			fallback = *options.Bluetooth
		}
	}
	els := []capwap.Element{bluetoothMode(fallback, ap)}
	var disconnect []capwap.Element
	for _, id := range oldServers {
		if id != newServer {
			disconnect = append(disconnect, privateSetting(0xdd, []byte{0, id, 1, 0, 0, 0, 0}))
		}
	}

	if r != nil {
		els = []capwap.Element{bluetoothMode(r.Mode, ap)}
		if r.Mode == 2 && ap.HasCapability(79) {
			els = append(els, privateSetting(0xa9, capwap.PrivApWebAccount{Algorithm: 1, Username: []byte(r.Username), Password: capwap.APWebPasswordV2(r.Password)}.AssembleValue()))
		}
		if r.Mode == 0 && ap.HasCapability(102) && ap.SubCapabilities[102]&1 != 0 {
			els = append(els, privateSetting(0xdb, bluetoothGateway(*r)))
			if cfg.Bluetooth != nil {
				for _, s := range cfg.Bluetooth.Servers {
					if s.ID != r.Server {
						continue
					}
					if s.TLS {
						_, v := bluetoothCertificate(s)
						els = append(els, privateSetting(0xde, v))
					}
					els = append(els, privateSetting(0xdc, bluetoothServerWire(s)), privateSetting(0xdd, []byte{0, s.ID, boolean(!s.Connected), 0, 0, 0, 0}))
				}
			}
		}
	}
	els = append(els, disconnect...)
	m.applyPolicy(ctx, ap, "bluetooth", struct {
		Rule   *BluetoothRule
		Config *BluetoothConfig
	}{r, cfg.Bluetooth}, els)
	m.mu.Lock()
	if m.status[key].State == "acknowledged" {
		remaining := []uint8{}
		if newServer != 0 {
			remaining = append(remaining, newServer)
		}
		err = m.saveBluetoothBindingsLocked(ap.ID, remaining)
	}
	m.mu.Unlock()
	if err != nil {
		fail(err)
	}
}
func publicBluetooth(p *BluetoothConfig) *BluetoothConfig {
	if p == nil {
		return nil
	}
	q := *p
	q.Rules = append([]BluetoothRule{}, p.Rules...)
	q.Servers = append([]BluetoothServer{}, p.Servers...)
	for i := range q.Rules {
		q.Rules[i].HasPassword = q.Rules[i].Password != ""
		q.Rules[i].Password = ""
	}
	for i := range q.Servers {
		q.Servers[i].HasPassword = q.Servers[i].Password != ""
		q.Servers[i].Password = ""
	}
	return &q
}
func (m *Manager) bluetoothRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/bluetooth", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		p := publicBluetooth(m.config.Bluetooth)
		if p == nil {
			p = &BluetoothConfig{Rules: []BluetoothRule{}, Servers: []BluetoothServer{}}
		}
		jsonReply(w, 200, p)
	})
	mux.HandleFunc("POST /api/bluetooth", func(w http.ResponseWriter, r *http.Request) {
		var p BluetoothConfig
		if err := decodeManagement(w, r, &p); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		if old := m.config.Bluetooth; old != nil {
			for i := range p.Rules {
				for _, v := range old.Rules {
					if v.ID == p.Rules[i].ID && p.Rules[i].Password == "" {
						p.Rules[i].Password = v.Password
					}
				}
			}
			for i := range p.Servers {
				for _, v := range old.Servers {
					if v.ID == p.Servers[i].ID && p.Servers[i].Password == "" {
						p.Servers[i].Password = v.Password
					}
				}
			}
		}
		next := m.config
		next.Bluetooth = &p
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]string{"status": "saved"})
	})
	mux.HandleFunc("POST /api/aps/{id}/bluetooth-query", func(w http.ResponseWriter, r *http.Request) {
		var in struct {
			Server uint8 `json:"server"`
		}
		if err := decodeManagement(w, r, &in); err != nil || in.Server == 0 {
			jsonReply(w, 400, map[string]string{"error": "服务器编号无效"})
			return
		}
		var ap cweng.APStatus
		for _, a := range m.APs() {
			if a.ID == r.PathValue("id") {
				ap = a
			}
		}
		if !ap.Online || !ap.HasCapability(102) || ap.SubCapabilities[102]&1 == 0 {
			jsonReply(w, 409, map[string]string{"error": "AP 未声明物联网网关能力"})
			return
		}
		m.mu.Lock()
		busy := m.upgradeBusyLocked(ap.ID)
		cfg := m.config
		rule := bluetoothFor(cfg.Bluetooth, ap.ID, cfg)
		member := rule != nil && rule.Mode == 0 && rule.Server == in.Server
		m.mu.Unlock()
		if busy || !member {
			jsonReply(w, 409, map[string]string{"error": "AP 正在升级或未绑定此网关服务器"})
			return
		}
		ctx, cancel := context.WithTimeout(cweng.PinAP(r.Context(), ap), 5*time.Second)
		defer cancel()
		_, err := m.engine.Request(ctx, ap.ID, 7, []capwap.Element{privateSetting(0xdd, []byte{0, in.Server, 2, 0, 0, 0, 0})})
		if err != nil {
			jsonReply(w, 502, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]string{"status": "acknowledged"})
	})
}

func (m *Manager) bluetoothOwnedPath() string {
	return filepath.Join(filepath.Dir(m.path), "bluetooth-servers.json")
}
func (m *Manager) loadBluetoothOwned() error {
	m.bluetoothOwned = map[string][]uint8{}
	b, err := os.ReadFile(m.bluetoothOwnedPath())
	if os.IsNotExist(err) {
		return nil
	}
	if err != nil {
		return err
	}
	if err = json.Unmarshal(b, &m.bluetoothOwned); err != nil {
		return err
	}
	if m.bluetoothOwned == nil {
		return fmt.Errorf("蓝牙服务器绑定记录损坏")
	}
	return nil
}

func (m *Manager) saveBluetoothBindingsLocked(ap string, ids []uint8) error {
	old := m.bluetoothOwned[ap]
	if slices.Equal(old, ids) {
		return nil
	}
	m.bluetoothOwned[ap] = append([]uint8{}, ids...)
	if err := atomicJSON(m.bluetoothOwnedPath(), m.bluetoothOwned); err != nil {
		m.bluetoothOwned[ap] = old
		return err
	}
	return nil
}
