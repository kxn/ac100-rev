package admin

import (
	"context"
	"encoding/binary"
	"fmt"
	"net"
	"net/http"
	"uacgo/capwap"
	"uacgo/cweng"
)

type MulticastGroup struct {
	IP      string `json:"ip"`
	Enabled bool   `json:"enabled"`
	Relay   bool   `json:"relay"`
}

func validateMulticastGroups(rows []MulticastGroup) error {
	if len(rows) > 32 {
		return fmt.Errorf("组播 IP 列表最多 32 项")
	}
	seen := map[string]bool{}
	for _, r := range rows {
		ip := net.ParseIP(r.IP)
		if ip == nil || !ip.IsMulticast() || seen[ip.String()] {
			return fmt.Errorf("组播 IP 无效或重复")
		}
		seen[ip.String()] = true
	}
	return nil
}
func multicastGroupValue(rows []MulticastGroup) []byte {
	b := make([]byte, 4)
	count := uint32(0)
	for _, r := range rows {
		if !r.Enabled {
			continue
		}
		ip := net.ParseIP(r.IP)
		b = append(b, boolean(r.Relay))
		if v := ip.To4(); v != nil {
			b = append(b, 1)
			b = append(b, v...)
		} else {
			b = append(b, 2)
			b = append(b, ip.To16()...)
		}
		count++
	}
	binary.BigEndian.PutUint32(b, count)
	return b
}
func (m *Manager) applyMulticastGroups(ctx context.Context, ap cweng.APStatus, cfg Config) {
	if !ap.HasCapability(43) || (len(cfg.MulticastGroups) == 0 && !m.policyOwned(ap.ID, "multicast-groups")) {
		return
	}
	m.applyPolicy(ctx, ap, "multicast-groups", cfg.MulticastGroups, []capwap.Element{privateSetting(0x74, multicastGroupValue(cfg.MulticastGroups))})
}
func (m *Manager) multicastRoutes(mux *http.ServeMux) {
	mux.HandleFunc("POST /api/multicast-groups", func(w http.ResponseWriter, r *http.Request) {
		var rows []MulticastGroup
		if err := decodeManagement(w, r, &rows); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.MulticastGroups = rows
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]string{"status": "saved"})
	})
}
