package admin

import (
	"context"
	"encoding/binary"
	"fmt"
	"net/http"
	"uacgo/capwap"
	"uacgo/cweng"
)

type ProxyPolicy struct {
	Enabled   bool  `json:"enabled"`
	Scope     uint8 `json:"scope"`
	ToUnicast bool  `json:"to_unicast"`
}
type ProtocolLimit struct {
	Enabled bool   `json:"enabled"`
	Scope   uint8  `json:"scope"`
	Rate    uint32 `json:"rate"`
}
type StormConfig struct {
	Enabled   bool            `json:"enabled"`
	Rate      uint32          `json:"rate"`
	Custom    bool            `json:"custom"`
	ARP       ProxyPolicy     `json:"arp_proxy"`
	ND        ProxyPolicy     `json:"nd_proxy"`
	MDNS      ProxyPolicy     `json:"mdns_proxy"`
	Protocols []ProtocolLimit `json:"protocols"`
}

var stormProtocols = []string{"ARP", "ICMPv6 NS", "ICMPv6 RS", "DHCP", "DHCPv6", "IGMP", "其他广播", "其他组播"}

func validateStorm(s *StormConfig) error {
	if s == nil {
		return nil
	}
	if s.Rate < 1 || s.Rate > 1024 || len(s.Protocols) != 8 {
		return fmt.Errorf("广播抑制总速率为 1–1024，需提供八种协议限制")
	}
	for _, p := range []ProxyPolicy{s.ARP, s.ND, s.MDNS} {
		if p.Scope < 1 || p.Scope > 3 {
			return fmt.Errorf("代理范围为无线、有线或全部")
		}
	}
	for _, p := range s.Protocols {
		if p.Scope < 1 || p.Scope > 3 || p.Rate > 1024 {
			return fmt.Errorf("协议速率或作用范围无效")
		}
	}
	return nil
}
func defaultStorm() StormConfig {
	s := StormConfig{Rate: 64, ARP: ProxyPolicy{Scope: 3}, ND: ProxyPolicy{Scope: 3}, MDNS: ProxyPolicy{Scope: 3}}
	for range stormProtocols {
		s.Protocols = append(s.Protocols, ProtocolLimit{Scope: 3, Rate: 64})
	}
	return s
}
func stormElements(s StormConfig, ap cweng.APStatus) []capwap.Element {
	if !ap.HasCapability(14) {
		return nil
	}
	els := []capwap.Element{privateSetting(0x46, binary.BigEndian.AppendUint32([]byte{boolean(s.Enabled)}, s.Rate))}
	caps := ap.SubCapabilities[14]
	var mask uint16
	if caps&1 != 0 {
		if s.ARP.Enabled {
			mask |= 1
		}
		if s.ND.Enabled {
			mask |= 2
		}
		mask |= uint16(s.ARP.Scope) << 2
		mask |= uint16(s.ND.Scope) << 4
		if caps&4 != 0 {
			if s.ARP.ToUnicast {
				mask |= 0x40
			}
			if s.ND.ToUnicast {
				mask |= 0x80
			}
		}
	}
	if caps&8 != 0 {
		if s.MDNS.Enabled {
			mask |= 0x100
		}
		if s.MDNS.ToUnicast {
			mask |= 0x200
		}
	}
	if caps&13 != 0 {
		els = append(els, privateSetting(0xcb, binary.BigEndian.AppendUint16(binary.BigEndian.AppendUint16(nil, mask), 0)))
	}
	if caps&2 != 0 {
		// V6: reserved16/count16, then protocol16/enabled8/scope8/rate32.
		body := []byte{0, 0, 0, 8}
		for i, p := range s.Protocols {
			body = binary.BigEndian.AppendUint16(body, uint16(i))
			body = append(body, boolean(s.Enabled && s.Custom && p.Enabled), p.Scope)
			body = binary.BigEndian.AppendUint32(body, p.Rate)
		}
		els = append(els, privateSetting(0xcc, body))
	}
	return els
}
func (m *Manager) applyStorm(ctx context.Context, ap cweng.APStatus, cfg Config) {
	if cfg.Storm == nil && !m.policyOwned(ap.ID, "storm") {
		return
	}
	s := defaultStorm()
	if cfg.Storm != nil {
		s = *cfg.Storm
	}
	if els := stormElements(s, ap); len(els) > 0 {
		m.applyPolicy(ctx, ap, "storm", s, els)
	}
}
func (m *Manager) stormRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/storm/defaults", func(w http.ResponseWriter, r *http.Request) {
		jsonReply(w, 200, map[string]any{"defaults": defaultStorm(), "protocols": stormProtocols})
	})
	mux.HandleFunc("POST /api/storm", func(w http.ResponseWriter, r *http.Request) {
		var s StormConfig
		if err := decodeManagement(w, r, &s); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		cfg := m.config
		cfg.Storm = &s
		if err := m.saveManagement(cfg); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]bool{"saved": true})
	})
}
