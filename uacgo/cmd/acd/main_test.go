package main

import (
	"bytes"
	"context"
	"flag"
	"net"
	"os"
	"os/exec"
	"path/filepath"
	"strconv"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/store"
)

func TestIdentityAdvertisesSelectedControlPort(t *testing.T) {
	f := fileIdentity{id: &cweng.Identity{ControlIP: "127.0.0.1", ControlPort: 5246}, port: 5247}
	if _, port := f.ControlAddress(); port != 5247 {
		t.Fatal("advertised stale identity.json control port", port)
	}
}

func TestIdentityAdvertisesGoCapacityInsteadOfOriginalHardwareLimit(t *testing.T) {
	e, err := cweng.NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.SetResourceLimits(2048, 1024)
	f := fileIdentity{id: &cweng.Identity{}, engine: e}
	if d := f.ACDescriptor(); d.ActiveLim != 2048 || d.StationLim != 65535 {
		t.Fatal(d)
	}
}

func TestStandaloneHelperProcess(t *testing.T) {
	if os.Getenv("AC100_TEST_CHILD") != "1" {
		return
	}
	flag.CommandLine = flag.NewFlagSet("acd", flag.ExitOnError)
	os.Args = []string{"acd", "-data", os.Getenv("AC100_TEST_DATA"), "-port", os.Getenv("AC100_TEST_PORT"), "-http", "", "-iface", "127.0.0.1"}
	main()
}

// Exercise the real executable bootstrap, not a test-only registration chain.
// A leftover prototype SSID must never be injected in Configure, even though
// its old DB is present. The standalone no longer needs profile.ini/rate-default.bin or
// creates the authentication/Portal database as a startup side effect.
func TestStandaloneIgnoresLegacyWirelessDatabase(t *testing.T) {
	dir := t.TempDir()
	for _, name := range []string{"identity.json", "apdb.json"} {
		b, err := os.ReadFile(filepath.Join("..", "..", "data", name))
		if err != nil {
			t.Fatal(err)
		}
		if err = os.WriteFile(filepath.Join(dir, name), b, 0600); err != nil {
			t.Fatal(err)
		}
	}
	legacy, err := store.Open(filepath.Join(dir, "dbs", "wserv.db"), store.SchemaWservTbl)
	if err != nil {
		t.Fatal(err)
	}
	const poison = "Legacy-Must-Not-Be-Pushed"
	if err = legacy.SetWserv(store.WservRow{WservID: 1, Enable: "on", SSID: poison}); err != nil {
		t.Fatal(err)
	}
	if err = legacy.Close(); err != nil {
		t.Fatal(err)
	}
	probe, err := net.ListenUDP("udp4", &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1)})
	if err != nil {
		t.Fatal(err)
	}
	port := probe.LocalAddr().(*net.UDPAddr).Port
	probe.Close()
	ctx, cancel := context.WithTimeout(context.Background(), 10*time.Second)
	defer cancel()
	cmd := exec.CommandContext(ctx, os.Args[0], "-test.run=^TestStandaloneHelperProcess$")
	cmd.Env = append(os.Environ(), "AC100_TEST_CHILD=1", "AC100_TEST_DATA="+dir, "AC100_TEST_PORT="+strconv.Itoa(port))
	logfile, err := os.Create(filepath.Join(dir, "child.log"))
	if err != nil {
		t.Fatal(err)
	}
	defer logfile.Close()
	cmd.Stdout, cmd.Stderr = logfile, logfile
	if err = cmd.Start(); err != nil {
		t.Fatal(err)
	}
	done := make(chan error, 1)
	go func() { done <- cmd.Wait() }()
	defer func() {
		_ = cmd.Process.Signal(os.Interrupt)
		select {
		case <-done:
		case <-time.After(3 * time.Second):
			cancel()
			<-done
		}
	}()
	conn, err := net.ListenUDP("udp4", &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1)})
	if err != nil {
		t.Fatal(err)
	}
	defer conn.Close()
	peer := &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: port}
	exchange := func(file string, seq uint8, expected uint32) *capwap.ParsedPacket {
		t.Helper()
		b, e := os.ReadFile(filepath.Join("..", "..", "testdata", file))
		if e != nil {
			t.Fatal(e)
		}
		p, e := capwap.ParsePacket(b)
		if e != nil {
			t.Fatal(e)
		}
		p.Control.SeqNum = seq
		buffer := make([]byte, 65536)
		deadline := time.Now().Add(4 * time.Second)
		for time.Now().Before(deadline) {
			_, e = conn.WriteToUDP(p.Assemble(), peer)
			if e != nil {
				t.Fatal(e)
			}
			conn.SetReadDeadline(time.Now().Add(100 * time.Millisecond))
			n, _, e := conn.ReadFromUDP(buffer)
			if e != nil {
				continue
			}
			r, e := capwap.ParsePacket(buffer[:n])
			if e == nil && r.Control.MsgType == expected && r.Control.SeqNum == seq {
				return r
			}
		}
		logs, _ := os.ReadFile(logfile.Name())
		t.Fatalf("bootstrap did not respond to %s: %s", file, logs)
		return nil
	}
	exchange("cw_dis_req_0074f340.bin", 1, capwap.MsgDiscoveryResponse)
	exchange("cw_join_req_0074f150.bin", 2, capwap.MsgJoinResponse)
	rsp := exchange("cw_cfg_req_0074ef5c.bin", 3, capwap.MsgConfigurationStatusResponse)
	if bytes.Contains(rsp.Assemble(), []byte(poison)) {
		t.Fatal("legacy SQLite WLAN leaked into the standalone Configure response")
	}
	if _, err = os.Stat(filepath.Join(dir, "dbs", "portal.db")); !os.IsNotExist(err) {
		t.Fatal("standalone boot created an excluded Portal DB", err)
	}
}
