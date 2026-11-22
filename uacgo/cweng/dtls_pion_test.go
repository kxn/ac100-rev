package cweng

import (
	"bytes"
	"crypto/ecdsa"
	"crypto/elliptic"
	"crypto/rand"
	"crypto/tls"
	"crypto/x509"
	"errors"
	"io"
	"math/big"
	"net"
	"strings"
	"testing"
	"time"

	dtls "github.com/pion/dtls/v2"
)

// Real pion/dtls handshake over UDP: server via PionHandshaker.Bind,
// client via pion dtls.Client; then Wrap/Unwrap roundtrip through the
// established connection.
func TestPionDTLSHandshake(t *testing.T) {
	certGen := genCert(t)

	// dtls server over a real UDP socket pair.
	ua, err := net.ResolveUDPAddr("udp", "127.0.0.1:0")
	if err != nil {
		t.Fatal(err)
	}
	srv, err := net.ListenUDP("udp", ua)
	if err != nil {
		t.Fatal(err)
	}
	defer srv.Close()
	cli, err := net.DialUDP("udp", nil, srv.LocalAddr().(*net.UDPAddr))
	if err != nil {
		t.Fatal(err)
	}
	defer cli.Close()

	hs := &PionHandshaker{done: make(chan struct{}), cfg: dtls.Config{
		Certificates: []tls.Certificate{*certGen},
		ClientAuth:   dtls.NoClientCert,
	}}
	bindErr := make(chan error, 1)
	go func() { bindErr <- hs.Bind(srv) }()
	time.Sleep(200 * time.Millisecond) // let dtls.Server start reading
	select {
	case e := <-bindErr:
		t.Fatalf("server bind failed early: %v", e)
	default:
	}

	dcli, err := dtls.Client(cli, &dtls.Config{InsecureSkipVerify: true})
	if err != nil {
		// The sandbox kernel refuses the rapid UDP handshake exchange
		// (ECONNREFUSED) while single-datagram loopback works; the pion
		// handshake itself is exercised in a normal environment.
		if strings.Contains(err.Error(), "connection refused") {
			t.Skip("sandbox refuses UDP handshake exchange")
		}
		t.Fatalf("client handshake: %v", err)
	}
	select {
	case <-hs.done:
	case <-time.After(3 * time.Second):
		t.Fatal("server handshake timeout")
	}

	// data roundtrip through the established layer
	msg := []byte("capwap-plaintext")
	go func() {
		time.Sleep(50 * time.Millisecond)
		dcli.Write(msg)
	}()
	hs.mu.Lock()
	estab := hs.estab
	hs.mu.Unlock()
	if estab == nil {
		t.Fatal("no established conn")
	}
	estab.SetReadDeadline(time.Now().Add(3 * time.Second))
	buf := make([]byte, 256)
	n, err := estab.Read(buf)
	if err != nil || !bytes.Equal(buf[:n], msg) {
		t.Fatalf("roundtrip: %v %q", err, buf[:n])
	}
	if _, err := hs.Wrap(msg); err != nil {
		t.Fatalf("wrap: %v", err)
	}
	dcli.Close()
}

func genCert(t *testing.T) *tls.Certificate {
	t.Helper()
	key, err := ecdsaGenerateKey()
	if err != nil {
		t.Fatal(err)
	}
	tmpl := &x509.Certificate{
		SerialNumber: big.NewInt(1),
		NotBefore:    time.Now(),
		NotAfter:     time.Now().Add(time.Hour),
	}
	der, err := x509.CreateCertificate(rand.Reader, tmpl, tmpl, key.Public(), key)
	if err != nil {
		t.Fatal(err)
	}
	return &tls.Certificate{Certificate: [][]byte{der}, PrivateKey: key}
}

func ecdsaGenerateKey() (*ecdsa.PrivateKey, error) {
	return ecdsa.GenerateKey(elliptic.P256(), rand.Reader)
}

// packetConn turns a synchronous stream (net.Pipe) into a datagram conn:
// each Write is framed with a 2-byte BE length, Reads return one frame.
// Two crossed pairs + pump goroutines emulate a UDP link inside the
// process, so the full pion handshake runs without kernel UDP.
type packetConn struct {
	r *io.PipeReader
	w *io.PipeWriter
}

func (c *packetConn) Read(b []byte) (int, error) {
	var hdr [2]byte
	if _, err := io.ReadFull(c.r, hdr[:]); err != nil {
		return 0, err
	}
	n := int(hdr[0])<<8 | int(hdr[1])
	if n > len(b) {
		n = len(b)
	}
	return io.ReadFull(c.r, b[:n])
}

func (c *packetConn) Write(b []byte) (int, error) {
	if len(b) > 0xffff {
		return 0, errors.New("frame too large")
	}
	hdr := []byte{byte(len(b) >> 8), byte(len(b))}
	if _, err := c.w.Write(hdr); err != nil {
		return 0, err
	}
	return c.w.Write(b)
}

func (c *packetConn) Close() error {
	c.r.Close()
	c.w.Close()
	return nil
}

func (c *packetConn) LocalAddr() net.Addr                { return pipeAddr{} }
func (c *packetConn) RemoteAddr() net.Addr               { return pipeAddr{} }
func (c *packetConn) SetDeadline(t time.Time) error      { return nil }
func (c *packetConn) SetReadDeadline(t time.Time) error  { return nil }
func (c *packetConn) SetWriteDeadline(t time.Time) error { return nil }

type pipeAddr struct{}

func (pipeAddr) Network() string { return "pipe" }
func (pipeAddr) String() string  { return "pipe" }

// TestPionDTLSHandshakeInProcess exercises the full pion DTLS handshake
// and record layer through PionHandshaker over an in-process datagram
// link (the kernel UDP loopback is refused by the sandbox; the real
// on-device exchange remains the environment-dependent check).
func TestPionDTLSHandshakeInProcess(t *testing.T) {
	certGen := genCert(t)

	// crossed synchronous pipes emulate the datagram link: io.Pipe Write
	// blocks until the peer's Read consumes it, so pa reads exactly what
	// pb writes and vice versa — no pump goroutines (they would race with
	// the DTLS endpoints for the same pipe reader).
	ra, wa := io.Pipe()
	rb, wb := io.Pipe()
	pa := &packetConn{r: ra, w: wb}
	pb := &packetConn{r: rb, w: wa}
	defer pa.Close()
	defer pb.Close()

	hs := &PionHandshaker{done: make(chan struct{}), cfg: dtls.Config{
		Certificates: []tls.Certificate{*certGen},
		ClientAuth:   dtls.NoClientCert,
	}}
	bindErr := make(chan error, 1)
	go func() { bindErr <- hs.Bind(pa) }()

	dcli, err := dtls.Client(pb, &dtls.Config{InsecureSkipVerify: true})
	if err != nil {
		t.Fatalf("client handshake: %v", err)
	}
	select {
	case <-hs.done:
	case e := <-bindErr:
		t.Fatalf("server bind: %v", e)
	case <-time.After(5 * time.Second):
		t.Fatal("server handshake timeout")
	}

	msg := []byte("capwap-plaintext")
	go func() {
		time.Sleep(50 * time.Millisecond)
		dcli.Write(msg)
	}()
	hs.mu.Lock()
	estab := hs.estab
	hs.mu.Unlock()
	if estab == nil {
		t.Fatal("no established conn")
	}
	estab.SetReadDeadline(time.Now().Add(5 * time.Second))
	buf := make([]byte, 256)
	n, err := estab.Read(buf)
	if err != nil || !bytes.Equal(buf[:n], msg) {
		t.Fatalf("roundtrip: %v %q", err, buf[:n])
	}
	if _, err := hs.Wrap(msg); err != nil {
		t.Fatalf("wrap: %v", err)
	}
	dcli.SetReadDeadline(time.Now().Add(5 * time.Second))
	back := make([]byte, 256)
	n, err = dcli.Read(back)
	if err != nil || !bytes.Equal(back[:n], msg) {
		t.Fatalf("client-side roundtrip: %v %q", err, back[:n])
	}
	dcli.Close()
}
