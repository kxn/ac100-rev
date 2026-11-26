package admin

import (
	"crypto/rand"
	"encoding/json"
	"fmt"
	"net"
	"os"
	"path/filepath"
)

// NDP's six-byte controller ID is shared by every AP in a measurement group.
// Using each AP's own MAC prevents them from recognizing each other's probes.
func (m *Manager) loadControllerIdentity() error {
	path := filepath.Join(filepath.Dir(m.path), "controller-identity.json")
	var v struct {
		MAC string `json:"ndp_mac"`
	}
	b, err := os.ReadFile(path)
	if err == nil {
		if err = json.Unmarshal(b, &v); err != nil {
			return err
		}
		mac, ok := parseMAC6(v.MAC)
		if !ok {
			return fmt.Errorf("控制器 NDP 标识损坏")
		}
		m.ndpMAC = mac
		return nil
	}
	if !os.IsNotExist(err) {
		return err
	}
	if nic, e := net.InterfaceByName(m.config.Interface); e == nil && len(nic.HardwareAddr) == 6 {
		copy(m.ndpMAC[:], nic.HardwareAddr)
	} else {
		if _, err = rand.Read(m.ndpMAC[:]); err != nil {
			return err
		}
		m.ndpMAC[0] = (m.ndpMAC[0] | 2) & 0xfe
	}
	v.MAC = net.HardwareAddr(m.ndpMAC[:]).String()
	return atomicJSON(path, v)
}
