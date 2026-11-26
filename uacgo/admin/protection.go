package admin

import (
	"context"
	"encoding/binary"
	"fmt"
	"net"
	"net/http"
	"net/netip"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

type DHCPTrustedServer struct {
	ID      string `json:"id"`
	Name    string `json:"name"`
	Address string `json:"address"`
}
type ARPBinding struct {
	ID          string `json:"id"`
	Name        string `json:"name"`
	IP          string `json:"ip"`
	MAC         string `json:"mac"`
	Description string `json:"description"`
}
type ProtectionRule struct {
	PolicyTarget
	ID       string   `json:"id"`
	Name     string   `json:"name"`
	DHCP     bool     `json:"dhcp"`
	Servers  []string `json:"servers"`
	ARP      bool     `json:"arp"`
	Bindings []string `json:"bindings"`
	Filter   bool     `json:"filter"`
	Wired    bool     `json:"wired"`
	Wireless bool     `json:"wireless"`
}
type ProtectionConfig struct {
	Servers  []DHCPTrustedServer `json:"servers"`
	Bindings []ARPBinding        `json:"bindings"`
	Rules    []ProtectionRule    `json:"rules"`
}

func trustedAddress(s string) (byte, []byte, error) {
	if ip, err := netip.ParseAddr(s); err == nil && ip.Zone() == "" && !ip.IsUnspecified() && !ip.IsMulticast() {
		if ip.Is4() {
			v := ip.As4()
			return 0, v[:], nil
		}
		v := ip.As16()
		return 2, v[:], nil
	}
	if mac, err := net.ParseMAC(s); err == nil && len(mac) == 6 && mac[0]&1 == 0 && mac.String() != "00:00:00:00:00:00" {
		return 1, mac, nil
	}
	return 0, nil, fmt.Errorf("信任服务器必须为有效单播 IP 或 MAC")
}
func validateProtection(p *ProtectionConfig, cfg Config) error {
	if p == nil {
		return nil
	}
	if len(p.Servers) > 10000 || len(p.Bindings) > 10000 || len(p.Rules) > 1024 {
		return fmt.Errorf("防护表超过容量")
	}
	servers, bindings, addresses, ids, names := map[string]bool{}, map[string]bool{}, map[string]bool{}, map[string]bool{}, map[string]bool{}
	for _, s := range p.Servers {
		typ, v, err := trustedAddress(s.Address)
		if err != nil {
			return err
		}
		key := fmt.Sprintf("%d:%x", typ, v)
		if s.ID == "" || servers[s.ID] || s.Name == "" || !validLabel(s.Name, 50) || names[s.Name] || addresses[key] {
			return fmt.Errorf("信任服务器名称、地址或编号无效/重复")
		}
		servers[s.ID] = true
		names[s.Name] = true
		addresses[key] = true
	}
	addresses = map[string]bool{}
	names = map[string]bool{}
	for _, b := range p.Bindings {
		ip, err := netip.ParseAddr(b.IP)
		if err != nil || ip.Zone() != "" || ip.IsMulticast() || ip.IsUnspecified() {
			return fmt.Errorf("ARP/ND 绑定 IP 无效")
		}
		_, _, err = trustedAddress(b.MAC)
		mac, e := net.ParseMAC(b.MAC)
		if err != nil || e != nil || len(mac) != 6 {
			return fmt.Errorf("绑定 MAC 无效")
		}
		key := ip.String() + "/" + mac.String()
		if b.ID == "" || bindings[b.ID] || addresses[key] || b.Name == "" || names[b.Name] || !validLabel(b.Name, 64) || !validLabel(b.Description, 128) {
			return fmt.Errorf("ARP/ND 绑定重复或名称无效")
		}
		bindings[b.ID] = true
		addresses[key] = true
		names[b.Name] = true
	}
	for _, r := range p.Rules {
		if r.ARP && !r.Wired && !r.Wireless {
			return fmt.Errorf("ARP/ND 防护至少选择一个端口范围")
		}
		if r.ID == "" || ids[r.ID] || r.Name == "" || !validLabel(r.Name, 64) || len(r.Servers) > 24 || len(r.Bindings) > 1024 {
			return fmt.Errorf("防护规则编号/名称或绑定数量无效")
		}
		ids[r.ID] = true
		for _, pair := range []struct {
			values []string
			valid  map[string]bool
		}{{r.Servers, servers}, {r.Bindings, bindings}} {
			seen := map[string]bool{}
			for _, id := range pair.values {
				if !pair.valid[id] || seen[id] {
					return fmt.Errorf("防护规则引用不存在或重复的记录")
				}
				seen[id] = true
			}
		}
		for _, id := range r.Groups {
			found := false
			for _, g := range cfg.Groups {
				found = found || g.ID == id
			}
			if !found {
				return fmt.Errorf("防护规则引用不存在的 AP 分组")
			}
		}
	}
	return nil
}

// Bounds verified in this AP's native parsers/model, not inferred from the
// controller's 1024-entry library limit or from unrelated capability bits.
// V1 dms: arp parse @c9d64 (48), ND parse @ca330 (24). Their manage loops
// still use the received count, so never send an oversized table to this AP.
func protectionLimits(ap cweng.APStatus) map[string]int {
	if ap.Model == "TL-7AP5100HC-PoE/DC易展版" && ap.HardwareVersion == "1.0" {
		return map[string]int{"arp": 48, "nd": 24}
	}
	return nil
}
func validateProtectionForAP(p *ProtectionConfig, r ProtectionRule, ap cweng.APStatus) error {
	limits := protectionLimits(ap)
	if p == nil || limits == nil {
		return nil
	}
	selected := map[string]bool{}
	for _, id := range r.Bindings {
		selected[id] = true
	}
	counts := map[string]int{}
	for _, b := range p.Bindings {
		if !selected[b.ID] {
			continue
		}
		ip, err := netip.ParseAddr(b.IP)
		if err != nil {
			return err
		}
		if ip.Is4() {
			counts["arp"]++
		} else {
			counts["nd"]++
		}
	}
	for _, kind := range []string{"arp", "nd"} {
		bit := 16
		if kind == "nd" {
			bit = 31
		}
		if ap.HasCapability(bit) && counts[kind] > limits[kind] {
			return fmt.Errorf("AP %s 的 %s 绑定容量为 %d，当前选择 %d 条", ap.ID, kind, limits[kind], counts[kind])
		}
	}
	return nil
}
func protectionFor(p *ProtectionConfig, id string, cfg Config) ProtectionRule {
	if p != nil {
		for _, r := range p.Rules {
			if r.matches(id, cfg) {
				return r
			}
		}
	}
	return ProtectionRule{}
}

// replace operation 1 sends the complete list; operation 0 toggles enable.
func defendList(enabled bool, rows [][]byte) []byte {
	b := []byte{boolean(enabled && len(rows) > 0), 1}
	b = binary.BigEndian.AppendUint32(b, uint32(len(rows)))
	for _, row := range rows {
		b = append(b, row...)
	}
	return b
}
func protectionElements(p *ProtectionConfig, r ProtectionRule, ap cweng.APStatus) []capwap.Element {
	v4, v6, arp, nd := [][]byte{}, [][]byte{}, [][]byte{}, [][]byte{}
	if p != nil {
		for _, id := range r.Servers {
			for _, s := range p.Servers {
				if s.ID != id {
					continue
				}
				typ, v, _ := trustedAddress(s.Address)
				if typ == 0 || typ == 1 {
					row := make([]byte, 7)
					row[0] = typ
					copy(row[1:], v)
					v4 = append(v4, row)
				}
				if typ == 2 || typ == 1 {
					row := make([]byte, 17)
					if typ == 1 {
						row[0] = 1
					}
					copy(row[1:], v)
					v6 = append(v6, row)
				}
			}
		}
		for _, id := range r.Bindings {
			for _, b := range p.Bindings {
				if b.ID != id {
					continue
				}
				ip, _ := netip.ParseAddr(b.IP)
				mac, _ := net.ParseMAC(b.MAC)
				row := append(ip.AsSlice(), mac...)
				if ip.Is4() {
					arp = append(arp, row)
				} else {
					nd = append(nd, row)
				}
			}
		}
	}
	var els []capwap.Element
	if ap.HasCapability(15) {
		els = append(els, privateSetting(0x47, defendList(r.DHCP, v4)))
	}
	if ap.HasCapability(30) {
		els = append(els, privateSetting(0x61, defendList(r.DHCP, v6)))
	}
	for i, typ := range []uint16{0x48, 0x62} {
		capbit := 16
		if i == 1 {
			capbit = 31
		}
		if !ap.HasCapability(capbit) {
			continue
		}
		rows := arp
		if i == 1 {
			rows = nd
		}
		b := defendList(r.ARP, rows)
		// V6 arp_defend_wtp_pkt_send gates the extended mode/scope flags on
		// ARP sub-capability 0, including the ND element. Legacy APs consume
		// this field as a boolean; e.g. 0x25 does not enable their filter.
		if b[0] != 0 && ap.SubCapabilities[16]&1 != 0 {
			if r.Filter {
				b[0] |= 4
			}
			if r.Wired {
				b[0] |= 16
			}
			if r.Wireless {
				b[0] |= 32
			}
		}
		els = append(els, privateSetting(typ, b))
	}
	return els
}
func (m *Manager) applyProtection(ctx context.Context, ap cweng.APStatus, cfg Config) {
	if cfg.Protection == nil && !m.policyOwned(ap.ID, "protection") {
		return
	}
	r := protectionFor(cfg.Protection, ap.ID, cfg)
	if err := validateProtectionForAP(cfg.Protection, r, ap); err != nil {
		m.mu.Lock()
		m.status[ap.ID+"/protection"] = ApplyStatus{AP: ap.ID, Service: "protection", State: "blocked", Error: err.Error(), At: time.Now()}
		m.mu.Unlock()
		return
	}
	els := protectionElements(cfg.Protection, r, ap)
	if len(els) > 0 {
		m.applyPolicy(ctx, ap, "protection", els, els)
	}
}
func (m *Manager) protectionRoutes(mux *http.ServeMux) {
	mux.HandleFunc("POST /api/protection", func(w http.ResponseWriter, r *http.Request) {
		var p ProtectionConfig
		if err := decodeManagement(w, r, &p); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		cfg := m.config
		cfg.Protection = &p
		if err := m.saveManagement(cfg); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]bool{"saved": true})
	})
}
