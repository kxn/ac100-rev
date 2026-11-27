package dhcpserver

import (
	"bytes"
	"encoding/binary"
	"os"
	"path/filepath"
	"testing"
	"time"
)

func TestNullLeaseFileStillAllowsAPToAcquireAddress(t *testing.T) {
	s := testServer(t)
	if err := os.WriteFile(s.cfg.LeaseFile, []byte("null\n"), 0600); err != nil {
		t.Fatal(err)
	}
	s, err := New(s.cfg)
	if err != nil {
		t.Fatal(err)
	}
	if offer, err := s.Handle(request(1, "TP-LINK", 1)); err != nil || offer == nil {
		t.Fatal("empty persisted lease state prevented allocation", err)
	}
}

func testServer(t *testing.T) *Server {
	t.Helper()
	s, e := New(Config{Interface: "lab", Server: "192.0.2.1", Start: "192.0.2.50", End: "192.0.2.52", Netmask: "255.255.255.0", AC: []string{"192.0.2.1"}, LeaseSeconds: 600, LeaseFile: filepath.Join(t.TempDir(), "leases.json")})
	if e != nil {
		t.Fatal(e)
	}
	return s
}
func request(typ byte, vendor string, last byte, extra ...byte) []byte {
	b := make([]byte, 240)
	b[0] = 1
	b[1] = 1
	b[2] = 6
	b[4] = 42
	b[10] = 128
	b[28] = 2
	b[33] = last
	copy(b[236:], []byte{99, 130, 83, 99})
	b = append(b, 53, 1, typ)
	if vendor != "" {
		b = append(b, 60, byte(len(vendor)))
		b = append(b, vendor...)
	}
	b = append(b, extra...)
	return append(b, 255)
}
func TestExactVendorSilentIgnore(t *testing.T) {
	s := testServer(t)
	for _, v := range []string{"", "MSFT 5.0", "TP-LINK-extra", "tp-link", "TP-LINK\x00", "MERCURY", "FAST"} {
		for _, typ := range []byte{1, 3, 4, 7, 8} {
			b, e := s.Handle(request(typ, v, 1))
			if e != nil || b != nil {
				t.Fatalf("answered ordinary client %q/%d", v, typ)
			}
		}
	}
	if len(s.leases) != 0 {
		t.Fatal("ignored clients acquired leases")
	}
}
func TestDiscoverRequestRenewAndRestart(t *testing.T) {
	s := testServer(t)
	reply, e := s.Handle(request(1, "TP-LINK", 1))
	if e != nil || reply == nil {
		t.Fatal(e)
	}
	address := reply[16:20]
	o, _ := options(reply[240:])
	if o[53][0] != 2 || !bytes.Equal(o[138], []byte{192, 0, 2, 1}) {
		t.Fatalf("bad offer options %v", o)
	}
	req := request(3, "TP-LINK", 1, append([]byte{50, 4}, address...)...)
	reply, e = s.Handle(req)
	if e != nil || reply == nil {
		t.Fatal(e)
	}
	o, _ = options(reply[240:])
	if o[53][0] != 5 {
		t.Fatal("no ACK")
	}
	reopened, e := New(s.cfg)
	if e != nil {
		t.Fatal(e)
	}
	other, _ := reopened.Handle(request(1, "TP-LINK", 2))
	if bytes.Equal(other[16:20], address) {
		t.Fatal("lease reused after restart")
	}
	renew := request(3, "TP-LINK", 1)
	copy(renew[12:16], address)
	reply, e = reopened.Handle(renew)
	if e != nil || reply == nil || !bytes.Equal(reply[16:20], address) {
		t.Fatal("renew failed")
	}
}

func TestMeshDetectDiscoverOnlyMatchesV6Branch(t *testing.T) {
	s := testServer(t)
	for _, vendor := range []string{"TP-LINK MESH DETECT 1.0-extra", "TP-LINK MESH DETECT 1.0\x00", "tp-link MESH DETECT 1.0"} {
		if b, _ := s.Handle(request(1, vendor, 1)); b != nil {
			t.Fatal("non-exact Mesh Detect answered")
		}
	}
	offer, err := s.Handle(request(1, "TP-LINK MESH DETECT 1.0", 1))
	if err != nil || offer == nil {
		t.Fatal("Mesh Detect discover", err)
	}
	for _, typ := range []byte{3, 4, 7, 8} {
		p := request(typ, "TP-LINK MESH DETECT 1.0", 1, append([]byte{50, 4}, offer[16:20]...)...)
		if reply, err := s.Handle(p); err != nil || reply != nil {
			t.Fatal("Mesh Detect acquired/changed lease", typ, err)
		}
	}
}
func TestOtherServerAndMalformedAreSilent(t *testing.T) {
	s := testServer(t)
	cases := [][]byte{request(3, "TP-LINK", 1, 54, 4, 192, 0, 2, 2), request(3, "TP-LINK", 1, 50, 4, 198, 51, 100, 1), request(1, "TP-LINK", 1, 60, 1, 1), request(1, "TP-LINK", 1, 52, 1, 1)}
	r := request(1, "TP-LINK", 1)
	r[24] = 1
	cases = append(cases, r)
	r = request(1, "TP-LINK", 1)
	r[len(r)-1] = 50
	cases = append(cases, r)
	for _, b := range cases {
		out, e := s.Handle(b)
		if out != nil || e != nil {
			t.Fatal("replied to foreign/malformed request")
		}
	}
}
func TestLeaseExpiryAndPoolExhaustion(t *testing.T) {
	s := testServer(t)
	now := time.Now()
	s.now = func() time.Time { return now }
	for i := byte(1); i <= 3; i++ {
		r, _ := s.Handle(request(1, "TP-LINK", i))
		if r == nil {
			t.Fatal("pool exhausted early")
		}
	}
	r, _ := s.Handle(request(1, "TP-LINK", 4))
	if r != nil {
		t.Fatal("overallocated pool")
	}
	now = now.Add(61 * time.Second)
	r, _ = s.Handle(request(1, "TP-LINK", 4))
	if r == nil {
		t.Fatal("expired offers not reusable")
	}
	if binary.BigEndian.Uint32(r[16:20]) != 0xc0000232 {
		t.Fatal("unexpected lease")
	}
}

func TestReservationsSurviveClientIDChangesAndExcludeOrdinaryClients(t *testing.T) {
	cfg := testServer(t).cfg
	cfg.Reservations = map[string]string{"02:00:00:00:00:01": "192.0.2.52", "02:00:00:00:00:02": "192.0.2.51"}
	s, err := New(cfg)
	if err != nil {
		t.Fatal(err)
	}
	for _, item := range []struct {
		mac byte
		ip  byte
	}{{2, 51}, {3, 50}, {1, 52}} {
		offer, err := s.Handle(request(1, "TP-LINK", item.mac))
		if err != nil || offer == nil || offer[19] != item.ip {
			t.Fatalf("reservation %d: %v %v", item.mac, offer, err)
		}
	}
	if reply, _ := s.Handle(request(1, "MSFT 5.0", 1)); reply != nil {
		t.Fatal("reservation bypassed AP-only filter")
	}
	if reply, _ := s.Handle(request(3, "TP-LINK", 1, 50, 4, 192, 0, 2, 50)); reply != nil {
		t.Fatal("fixed AP accepted another address")
	}
	for _, id := range []byte{5, 6} {
		ack, err := s.Handle(request(3, "TP-LINK", 1, 50, 4, 192, 0, 2, 52, 61, 1, id))
		if err != nil || ack == nil || ack[19] != 52 {
			t.Fatal("MAC reservation changed with client identifier", err)
		}
	}
	s, err = New(cfg)
	if err != nil {
		t.Fatal(err)
	}
	if offer, _ := s.Handle(request(1, "TP-LINK", 1)); offer == nil || offer[19] != 52 {
		t.Fatal("reservation lost across restart")
	}
	if offer, _ := s.Handle(request(1, "TP-LINK", 4)); offer != nil {
		t.Fatal("dynamic AP stole a reserved address")
	}
}
