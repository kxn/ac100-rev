package admin

import (
	"fmt"
	"net/http"
	"strconv"
)

type ServiceBinding struct {
	AP    string `json:"ap_id"`
	Radio uint8  `json:"radio_id"`
	VLAN  int    `json:"vlan"`
}

func binding(s Service, ap string, radio uint8) (bool, int) {
	if len(s.Bindings) == 0 {
		return true, serviceOptions(s).VLAN
	}
	for _, b := range s.Bindings {
		if b.AP == ap && b.Radio == radio {
			return true, b.VLAN
		}
	}
	return false, 0
}
func (m *Manager) deleteServiceHTTP(w http.ResponseWriter, r *http.Request) {
	m.mu.Lock()
	defer m.mu.Unlock()
	next := m.config
	next.Services = append([]Service{}, m.config.Services...)
	found := false
	for i, s := range next.Services {
		if s.ID == r.PathValue("id") {
			s.Enabled = false
			s.Deleting = true
			next.Services[i] = s
			found = true
		}
	}
	if !found {
		jsonReply(w, 404, map[string]string{"error": "无线服务不存在"})
		return
	}
	next.Version++
	if err := m.persistConfigLocked(next, false); err != nil {
		jsonReply(w, 500, map[string]string{"error": err.Error()})
		return
	}
	jsonReply(w, 202, map[string]string{"status": "deleting"})
}

// Keep deletion intent until all APs which own this WLAN have acknowledged
// its removal, including devices which are currently offline.
func (m *Manager) finishDeletions() {
	m.mu.Lock()
	defer m.mu.Unlock()
	next := m.config
	next.Services = []Service{}
	removed := []string{}
	for _, s := range m.config.Services {
		owned := false
		for _, services := range m.assignments {
			owned = owned || len(services[s.ID]) > 0
		}
		if s.Deleting && !owned {
			removed = append(removed, s.ID)
		} else {
			next.Services = append(next.Services, s)
		}
	}
	if len(removed) == 0 {
		return
	}
	next.Version++
	if m.persistConfigLocked(next, false) != nil {
		return
	}
	for key, status := range m.status {
		for _, id := range removed {
			if status.Service == id {
				delete(m.status, key)
				delete(m.applied, key)
			}
		}
	}
}
func (m *Manager) radioDefaultsHTTP(w http.ResponseWriter, r *http.Request) {
	n, err := strconv.Atoi(r.URL.Query().Get("radio_id"))
	if err != nil {
		jsonReply(w, 400, map[string]string{"error": "射频编号无效"})
		return
	}
	for _, ap := range m.APs() {
		if ap.ID != r.URL.Query().Get("ap_id") {
			continue
		}
		for _, c := range ap.Capabilities {
			if int(c.RadioID) == n {
				jsonReply(w, 200, defaultAPRadio(ap, c).Advanced)
				return
			}
		}
	}
	jsonReply(w, 404, map[string]string{"error": "设备尚未上报此射频能力"})
}
func validateBindings(s Service) error {
	seen := map[string]bool{}
	for _, b := range s.Bindings {
		k := fmt.Sprintf("%s/%d", b.AP, b.Radio)
		if b.AP == "" || b.Radio < 1 || b.Radio > 31 || b.VLAN < 0 || b.VLAN > 4094 || seen[k] {
			return fmt.Errorf("AP / 射频 / VLAN 绑定无效")
		}
		seen[k] = true
	}
	return nil
}
