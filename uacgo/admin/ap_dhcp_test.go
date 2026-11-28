package admin

import (
	"context"
	"encoding/json"
	"path/filepath"
	"testing"
	"uacgo/dhcpserver"
)

func TestAPDHCPManagementSavesPoolWithoutChangingControllerConfiguration(t *testing.T) {
	m, _ := testController(t)
	ctx, cancel := context.WithCancel(context.Background())
	defer cancel()
	r, err := dhcpserver.NewRuntime(ctx, filepath.Join(t.TempDir(), "ap-dhcp.json"), "lab", nil)
	if err != nil {
		t.Fatal(err)
	}
	m.SetDHCPRuntime(r)
	before, _ := json.Marshal(m.config)
	p := dhcpserver.Settings{Config: dhcpserver.Config{Interface: "lab", Server: "192.0.2.1", Start: "192.0.2.250", End: "192.0.2.253", Netmask: "255.255.255.0", AC: []string{"192.0.2.1"}, LeaseSeconds: 600, Reservations: map[string]string{"02:00:00:00:00:01": "192.0.2.251"}}}
	w := callManagement(t, m, "POST", "ap-dhcp", p)
	if w.Code != 200 {
		t.Fatal(w.Code, w.Body.String())
	}
	w = callManagement(t, m, "GET", "ap-dhcp", nil)
	var status dhcpserver.Status
	if err = json.Unmarshal(w.Body.Bytes(), &status); err != nil || status.Settings.Start != p.Start || len(status.Settings.Reservations) != 1 || status.Running {
		t.Fatal(w.Body.String(), err)
	}
	after, _ := json.Marshal(m.config)
	if string(before) != string(after) {
		t.Fatal("DHCP management changed AP/WLAN configuration")
	}
}
