package dhcpserver

import (
	"context"
	"encoding/json"
	"os"
	"path/filepath"
	"testing"
)

func TestRuntimePersistsDisabledPoolAndPreservesReadonlySeed(t *testing.T) {
	dir := t.TempDir()
	seed := filepath.Join(dir, "seed.json")
	p := Settings{Config: testServer(t).cfg, Enabled: false}
	b, _ := json.Marshal(p)
	if err := os.WriteFile(seed, b, 0400); err != nil {
		t.Fatal(err)
	}
	ctx, cancel := context.WithCancel(context.Background())
	defer cancel()
	path := filepath.Join(dir, "saved.json")
	r, err := NewRuntimeFrom(ctx, path, seed, "lab", nil)
	if err != nil {
		t.Fatal(err)
	}
	p = r.Status().Settings
	p.Start = "192.0.2.51"
	p.Reservations = map[string]string{"02:00:00:00:00:01": "192.0.2.52"}
	p.LeaseFile = filepath.Join(dir, "untrusted-write-target")
	if err = r.Update(p); err != nil {
		t.Fatal(err)
	}
	if _, err = os.Stat(p.LeaseFile); !os.IsNotExist(err) {
		t.Fatal("management chose a filesystem write path", err)
	}
	b2, _ := os.ReadFile(seed)
	if string(b) != string(b2) {
		t.Fatal("read-only seed changed")
	}
	r2, err := NewRuntimeFrom(ctx, path, seed, "lab", nil)
	if err != nil {
		t.Fatal(err)
	}
	status := r2.Status()
	if status.Running || status.Settings.Enabled || status.Settings.Start != p.Start || len(status.Settings.Reservations) != 1 || status.Settings.LeaseFile != "" {
		t.Fatal("saved runtime pool did not survive restart", status)
	}
	status.Settings.Reservations["02:00:00:00:00:01"] = "192.0.2.51"
	if r2.Status().Settings.Reservations["02:00:00:00:00:01"] != "192.0.2.52" {
		t.Fatal("status alias mutated active reservation")
	}
}
