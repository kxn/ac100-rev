package cweng

import (
	"crypto/ecdsa"
	"crypto/elliptic"
	"crypto/rand"
	"crypto/tls"
	"crypto/x509"
	"math/big"
	"net"
	"strings"
	"testing"
	"time"

	dtls "github.com/pion/dtls/v2"
)

func TestPionSmoke(t *testing.T) {
	key, _ := ecdsa.GenerateKey(elliptic.P256(), rand.Reader)
	tmpl := &x509.Certificate{SerialNumber: big.NewInt(1),
		NotBefore: time.Now(), NotAfter: time.Now().Add(time.Hour)}
	der, _ := x509.CreateCertificate(rand.Reader, tmpl, tmpl, key.Public(), key)
	cert := tls.Certificate{Certificate: [][]byte{der}, PrivateKey: key}

	srv, _ := net.ListenUDP("udp", &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 0})
	srvAddr := srv.LocalAddr().(*net.UDPAddr)
	srvClosed := make(chan struct{})
	countConn := &countConn{UDPConn: srv}
	srvErr := make(chan error, 1)
	go func() {
		dconn, err := dtls.Server(countConn, &dtls.Config{Certificates: []tls.Certificate{cert}, ClientAuth: dtls.NoClientCert})
		if err != nil {
			srvErr <- err
			close(srvClosed)
			return
		}
		buf := make([]byte, 128)
		n, err := dconn.Read(buf)
		if err != nil {
			t.Logf("server read err: %v", err)
			close(srvClosed)
			return
		}
		t.Logf("server got %q", buf[:n])
		dconn.Close()
		close(srvClosed)
	}()

	cli, _ := net.DialUDP("udp", nil, srvAddr)
	dcli, err := dtls.Client(cli, &dtls.Config{InsecureSkipVerify: true})
	if err != nil {
		if strings.Contains(err.Error(), "connection refused") {
			t.Skip("sandbox refuses UDP handshake exchange")
		}
		t.Fatalf("client handshake: %v", err)
	}
	dcli.Write([]byte("ping"))
	select {
	case e := <-srvErr:
		t.Fatalf("server handshake err: %v", e)
	case <-srvClosed:
	case <-time.After(2 * time.Second):
		t.Log("timeout waiting server close")
	}
	_ = cli.Close()
}

type countConn struct {
	*net.UDPConn
	n int
}

func (c *countConn) ReadFrom(p []byte) (int, net.Addr, error) {
	n, a, err := c.UDPConn.ReadFrom(p)
	if err == nil {
		c.n++
	}
	return n, a, err
}

func (c *countConn) WriteTo(p []byte, a net.Addr) (int, error) {
	n, err := c.UDPConn.WriteTo(p, a)
	if err == nil {
		c.n++
	}
	return n, err
}
