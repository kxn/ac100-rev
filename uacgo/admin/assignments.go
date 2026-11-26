package admin

import (
	"fmt"
)

// WLAN identifiers are local to each AP radio. Logical services must not
// consume the same slot on unrelated APs or inherit another model's limit.
type WLANAssignments map[string]map[string]map[uint8]uint8

func (m *Manager) assigned(ap, sid string, radio uint8) uint8 {
	m.mu.Lock()
	defer m.mu.Unlock()
	return m.assignments[ap][sid][radio]
}
func (m *Manager) ownsService(ap, sid string) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	return len(m.assignments[ap][sid]) > 0
}
func (m *Manager) allocate(ap, sid string, radio uint8, max int) (uint8, error) {
	m.mu.Lock()
	defer m.mu.Unlock()
	if max < 1 || max > 16 {
		return 0, fmt.Errorf("AP 射频的 SSID 容量未知或无效")
	}
	if slot := m.assignments[ap][sid][radio]; slot != 0 {
		if int(slot) > max {
			return 0, fmt.Errorf("原有 WLAN 编号 %d 超出 AP 当前容量 %d，须先移除旧绑定", slot, max)
		}
		return slot, nil
	}
	used := map[uint8]bool{}
	for _, byRadio := range m.assignments[ap] {
		if slot := byRadio[radio]; slot != 0 {
			used[slot] = true
		}
	}
	for slot, byRadio := range m.owned[ap] {
		if byRadio[radio] {
			used[slot] = true
		}
	}
	for slot := uint8(1); int(slot) <= max; slot++ {
		if used[slot] {
			continue
		}
		if m.assignments[ap] == nil {
			m.assignments[ap] = map[string]map[uint8]uint8{}
		}
		if m.assignments[ap][sid] == nil {
			m.assignments[ap][sid] = map[uint8]uint8{}
		}
		m.assignments[ap][sid][radio] = slot
		if err := m.saveWLANState(); err != nil {
			delete(m.assignments[ap][sid], radio)
			return 0, err
		}
		return slot, nil
	}
	return 0, fmt.Errorf("此 AP 的射频 %d 已达到 %d 个 SSID 上限", radio, max)
}
