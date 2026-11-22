package cweng

import "testing"

// capwap_packet_is_clienthello @0x597ab0 rule: buf[0]=1, buf[4]=0x16,
// buf[0x11]=1 (4-byte prefix + DTLS record + handshake byte).
func TestIsClientHello(t *testing.T) {
	pkt := make([]byte, 0x12)
	pkt[0] = 1
	pkt[4] = 0x16
	pkt[0x11] = 1
	if !IsClientHello(pkt) {
		t.Fatal("client hello not detected")
	}
	for _, tc := range []struct {
		idx int
		val byte
	}{{0, 2}, {4, 0x15}, {0x11, 2}} {
		bad := append([]byte(nil), pkt...)
		bad[tc.idx] = tc.val
		if IsClientHello(bad) {
			t.Fatalf("byte %d=%#x must not match", tc.idx, tc.val)
		}
	}
	if IsClientHello(pkt[:0x11]) {
		t.Fatal("truncated packet must not match")
	}
}

// FeedClientHello without a handshaker factory returns false (unconfigured
// GnuTLS); with one, establishment flips IsEstablished and Teardown clears.
func TestDTLSManagerFlow(t *testing.T) {
	m := NewDTLSManager(DTLSConfig{Enable: false}, nil)
	if m.Enabled() {
		t.Fatal("must default disabled")
	}

	m = NewDTLSManager(DTLSConfig{Enable: true, CertFile: "/etc/cacert.pem", KeyFile: "/etc/privkey.pem"}, nil)
	pkt := make([]byte, 0x12)
	pkt[0], pkt[4], pkt[0x11] = 1, 0x16, 1
	if m.FeedClientHello("peer1", pkt) {
		t.Fatal("unconfigured factory must not establish")
	}

	m = NewDTLSManager(DTLSConfig{Enable: true}, func(peer string) Handshaker {
		return &stubHS{}
	})
	if !m.FeedClientHello("peer1", pkt) {
		t.Fatal("stub handshake failed")
	}
	if !m.IsEstablished("peer1") {
		t.Fatal("peer1 should be established")
	}
	m.Teardown("peer1")
	if m.IsEstablished("peer1") {
		t.Fatal("teardown did not clear peer1")
	}
}

type stubHS struct{}

func (stubHS) Handshake([][]byte) (bool, error) { return true, nil }
func (stubHS) Unwrap(b []byte) ([]byte, error)  { return b, nil }
func (stubHS) Wrap(b []byte) ([]byte, error)    { return b, nil }
