package admin

import (
	"testing"
)

func TestClientServiceResolverRequiresCommittedOwnedSlot(t *testing.T) {
	m, _ := testController(t)
	m.config.Version = 7
	m.config.Services = []Service{{ID: "old", SSID: "OldSSID", Enabled: true}}
	m.assignments["a"] = map[string]map[uint8]uint8{"old": {2: 1}}
	m.owned["a"] = map[uint8]map[uint8]bool{1: {2: true}}
	m.settled["a"] = "committed"
	m.settledVersions["a"] = 7
	id, ssid := m.resolveClientService("a", 2, 1)
	if id != "old" || ssid != "OldSSID" {
		t.Fatal(id, ssid)
	}
	m.config.Version++
	m.config.Services[0].SSID = "NewSSID"
	if _, ssid = m.resolveClientService("a", 2, 1); ssid != "" {
		t.Fatal("uncommitted SSID presented as observed")
	}
	m.settledVersions["a"] = 8
	if _, ssid = m.resolveClientService("a", 2, 1); ssid != "NewSSID" {
		t.Fatal(ssid)
	}
	m.config.Services[0].Deleting = true
	if _, ssid = m.resolveClientService("a", 2, 1); ssid != "" {
		t.Fatal("deleted service resolved")
	}
}
