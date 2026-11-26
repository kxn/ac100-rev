//go:build linux

package dhcpserver

import (
	"context"
	"os"
	"testing"
	"time"
)

// Run only inside a disposable network namespace created by the wire checker.
func TestServeWire(t *testing.T) {
	if os.Getenv("AC100_DHCP_WIRE_TEST") != "1" {
		t.Skip("isolated wire test")
	}
	s, e := New(Config{Interface: "ac0", Server: "198.18.0.1", Start: "198.18.0.50", End: "198.18.0.55", Netmask: "255.255.255.0", AC: []string{"198.18.0.1"}, LeaseSeconds: 600})
	if e != nil {
		t.Fatal(e)
	}
	ctx, cancel := context.WithTimeout(context.Background(), 8*time.Second)
	defer cancel()
	if e = s.Serve(ctx); e != nil {
		t.Fatal(e)
	}
}
