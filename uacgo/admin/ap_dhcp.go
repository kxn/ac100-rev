package admin

import (
	"net/http"
	"uacgo/dhcpserver"
)

func (m *Manager) SetDHCPRuntime(dhcp *dhcpserver.Runtime) { m.dhcp = dhcp }

func (m *Manager) apDHCPRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/ap-dhcp", func(w http.ResponseWriter, r *http.Request) {
		if m.dhcp == nil {
			jsonReply(w, 200, map[string]any{"available": false, "running": false})
			return
		}
		jsonReply(w, 200, m.dhcp.Status())
	})
	mux.HandleFunc("POST /api/ap-dhcp", func(w http.ResponseWriter, r *http.Request) {
		if m.dhcp == nil {
			jsonReply(w, 503, map[string]string{"error": "此进程未注册 AP DHCP 服务"})
			return
		}
		var p dhcpserver.Settings
		if err := decodeManagement(w, r, &p); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		if err := m.dhcp.Update(p); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 200, m.dhcp.Status())
	})
}
