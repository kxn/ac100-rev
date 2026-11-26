package admin

import (
	"encoding/json"
	"fmt"
	"os"
	"path/filepath"
)

func (m *Manager) policyOwnerPath() string {
	return filepath.Join(filepath.Dir(m.path), "ap-policy-owners.json")
}
func (m *Manager) loadPolicyOwners() error {
	b, err := os.ReadFile(m.policyOwnerPath())
	if os.IsNotExist(err) {
		return nil
	}
	if err != nil {
		return err
	}
	if err := json.Unmarshal(b, &m.policyOwners); err != nil {
		return err
	}
	if m.policyOwners == nil {
		return fmt.Errorf("AP 策略所有权记录损坏")
	}
	return nil
}
func (m *Manager) policyOwned(ap, kind string) bool {
	m.mu.Lock()
	defer m.mu.Unlock()
	return m.policyOwners[ap][kind]
}

// Persist intent before the first AP write. Keep historical ownership so a
// removed rule can restore defaults after an interrupted commit or reconnect.
func (m *Manager) touchPolicy(ap, kind string) error {
	m.mu.Lock()
	defer m.mu.Unlock()
	if m.policyOwners[ap][kind] {
		return nil
	}
	if m.policyOwners[ap] == nil {
		m.policyOwners[ap] = map[string]bool{}
	}
	m.policyOwners[ap][kind] = true
	if err := atomicJSON(m.policyOwnerPath(), m.policyOwners); err != nil {
		delete(m.policyOwners[ap], kind)
		return err
	}
	return nil
}
