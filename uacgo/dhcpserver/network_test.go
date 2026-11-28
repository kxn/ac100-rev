//go:build linux

package dhcpserver

import (
	"context"
	"encoding/json"
	"net"
	"net/http"
	"os"
	"path/filepath"
	"testing"
	"time"
)

// Run only inside a disposable network namespace created by the wire checker.
func TestServeWire(t *testing.T) {
	if os.Getenv("AC100_DHCP_WIRE_TEST") != "1" {
		t.Skip("isolated wire test")
	}
	ctx, cancel := context.WithTimeout(context.Background(), 8*time.Second)
	defer cancel()
	path := filepath.Join(t.TempDir(), "settings.json")
	p := Settings{Enabled: true, Config: Config{Interface: "ac0", Server: "198.18.0.1", Start: "198.18.0.50", End: "198.18.0.55", Netmask: "255.255.255.0", AC: []string{"198.18.0.1"}, LeaseSeconds: 600}}
	if err := writeSettings(path, p); err != nil {
		t.Fatal(err)
	}
	r, err := NewRuntime(ctx, path, "ac0", nil)
	if err != nil {
		t.Fatal(err)
	}
	// Test-only control channel in the disposable namespace. The real admin
	// handler has a separate HTTP regression; this exercises live UDP updates.
	listener, err := net.Listen("tcp4", "198.18.0.1:18080")
	if err != nil {
		t.Fatal(err)
	}
	server := &http.Server{Handler: http.HandlerFunc(func(w http.ResponseWriter, req *http.Request) {
		if req.Method == "POST" {
			var settings Settings
			if err := json.NewDecoder(req.Body).Decode(&settings); err != nil {
				http.Error(w, err.Error(), 400)
				return
			}
			if err := r.Update(settings); err != nil {
				http.Error(w, err.Error(), 400)
				return
			}
		}
		_ = json.NewEncoder(w).Encode(r.Status())
	})}
	defer server.Close()
	go server.Serve(listener)
	<-ctx.Done()
	if status := r.Status(); status.Error != "" {
		t.Fatal(status.Error)
	}
}
