package legacydtls

import (
	"bufio"
	"bytes"
	"context"
	"crypto/rand"
	"crypto/rsa"
	"crypto/x509"
	"crypto/x509/pkix"
	"encoding/pem"
	"math/big"
	"net"
	"os"
	"os/exec"
	"path/filepath"
	"testing"
	"time"
)

func testServer(t *testing.T) *Server {
	t.Helper()
	key, err := rsa.GenerateKey(rand.Reader, 2048)
	if err != nil {
		t.Fatal(err)
	}
	cert := &x509.Certificate{SerialNumber: big.NewInt(1), Subject: pkix.Name{CommonName: "dtls-test"}, NotBefore: time.Now().Add(-time.Hour), NotAfter: time.Now().Add(time.Hour), KeyUsage: x509.KeyUsageKeyEncipherment | x509.KeyUsageDigitalSignature}
	der, err := x509.CreateCertificate(rand.Reader, cert, cert, &key.PublicKey, key)
	if err != nil {
		t.Fatal(err)
	}
	dir := t.TempDir()
	cp, kp := filepath.Join(dir, "cert.pem"), filepath.Join(dir, "key.pem")
	if err = os.WriteFile(cp, pem.EncodeToMemory(&pem.Block{Type: "CERTIFICATE", Bytes: der}), 0600); err != nil {
		t.Fatal(err)
	}
	if err = os.WriteFile(kp, pem.EncodeToMemory(&pem.Block{Type: "RSA PRIVATE KEY", Bytes: x509.MarshalPKCS1PrivateKey(key)}), 0600); err != nil {
		t.Fatal(err)
	}
	s, err := New(cp, kp)
	if err != nil {
		t.Fatal(err)
	}
	return s
}

// Independent implementation as peer, not a client made from the server's own
// PRF/record functions: validates transcript hashing, RSA, CBC and both MACs.
func TestOpenSSLInterop(t *testing.T) {
	if _, err := exec.LookPath("openssl"); err != nil {
		t.Skip("optional OpenSSL interoperability peer is not installed")
	}
	for _, suite := range []string{"AES256-SHA", "AES128-SHA"} {
		t.Run(suite, func(t *testing.T) {
			s := testServer(t)
			udp, err := net.ListenUDP("udp4", &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1)})
			if err != nil {
				t.Fatal(err)
			}
			defer udp.Close()
			serverErrors := make(chan error, 1)
			go func() {
				buf := make([]byte, 65536)
				for {
					n, peer, e := udp.ReadFromUDP(buf)
					if e != nil {
						return
					}
					responses, packets, e := s.Handle(peer.String(), buf[:n])
					if e != nil {
						select {
						case serverErrors <- e:
						default:
						}
						continue
					}
					for _, b := range responses {
						_, _ = udp.WriteToUDP(b, peer)
					}
					for _, b := range packets {
						r, e := s.Encrypt(peer.String(), b)
						if e != nil {
							serverErrors <- e
							return
						}
						_, _ = udp.WriteToUDP(r, peer)
					}
				}
			}()
			ctx, cancel := context.WithTimeout(context.Background(), 6*time.Second)
			defer cancel()
			cmd := exec.CommandContext(ctx, "openssl", "s_client", "-dtls1", "-cipher", suite+":@SECLEVEL=0", "-connect", udp.LocalAddr().String(), "-quiet")
			stdin, _ := cmd.StdinPipe()
			stdout, _ := cmd.StdoutPipe()
			var stderr bytes.Buffer
			cmd.Stderr = &stderr
			if err = cmd.Start(); err != nil {
				t.Fatal(err)
			}
			defer func() { _ = cmd.Process.Kill(); _ = cmd.Wait() }()
			if _, err = stdin.Write([]byte("interop-payload\n")); err != nil {
				t.Fatal(err)
			}
			got := make(chan string, 1)
			go func() { line, _ := bufio.NewReader(stdout).ReadString('\n'); got <- line }()
			select {
			case line := <-got:
				if line != "interop-payload\n" {
					_ = cmd.Process.Kill()
					_ = cmd.Wait()
					t.Fatalf("independent peer returned %q: %s", line, stderr.String())
				}
			case err := <-serverErrors:
				t.Fatalf("server failed: %v", err)
			case <-ctx.Done():
				t.Fatal("independent DTLS handshake/roundtrip timed out")
			}
		})
	}
}
func TestCBCRejectsTamperingAndTruncation(t *testing.T) {
	key := bytes.Repeat([]byte{7}, 32)
	mac := bytes.Repeat([]byte{5}, 20)
	header := record(23, 1, 4, nil)
	original := []byte("authenticated control packet")
	encrypted, err := seal(key, mac, header, original)
	if err != nil {
		t.Fatal(err)
	}
	if plain, err := open(key, mac, header, encrypted); err != nil || !bytes.Equal(plain, original) {
		t.Fatalf("valid record: %v", err)
	}
	for i := range encrypted {
		bad := append([]byte{}, encrypted...)
		bad[i] ^= 1
		if _, err := open(key, mac, header, bad); err == nil {
			t.Fatalf("accepted tampering at byte %d", i)
		}
	}
	for n := 0; n < len(encrypted); n++ {
		if _, err := open(key, mac, header, encrypted[:n]); err == nil {
			t.Fatalf("accepted truncated record length %d", n)
		}
	}
	changed := append([]byte{}, header...)
	changed[10]++
	if _, err := open(key, mac, changed, encrypted); err == nil {
		t.Fatal("record sequence is not authenticated")
	}
}
func TestReplayWindow(t *testing.T) {
	p := &peer{}
	for _, seq := range []uint64{1, 4, 2, 3, 70, 69} {
		if !p.acceptSeq(seq) {
			t.Fatalf("new record %d rejected", seq)
		}
	}
	for _, seq := range []uint64{70, 69, 1, 4, 2, 3} {
		if p.acceptSeq(seq) {
			t.Fatalf("replayed/stale record %d accepted", seq)
		}
	}
}
func TestCookieDoesNotAllocatePeer(t *testing.T) {
	s := testServer(t)
	body := append([]byte{0xfe, 0xff}, make([]byte, 32)...)
	body = append(body, 0, 0, 0, 2, 0, 0x35, 1, 0)
	hello := record(22, 0, 0, handshake(1, 0, body))
	out, plain, err := s.Handle("127.0.0.1:1", hello)
	if err != nil || len(out) != 1 || len(plain) != 0 || len(s.peers) != 0 {
		t.Fatalf("cookie exchange allocated state: %v", err)
	}
	if bytes.Equal(s.makeCookie("127.0.0.1:1", make([]byte, 32)), s.makeCookie("127.0.0.1:2", make([]byte, 32))) {
		t.Fatal("cookie not bound to peer address")
	}
}
func FuzzHandle(f *testing.F) {
	s := &Server{peers: map[string]*peer{}}
	f.Add([]byte{})
	f.Add(record(22, 0, 0, handshake(1, 0, []byte{0xfe, 0xff})))
	f.Fuzz(func(t *testing.T, b []byte) { _, _, _ = s.Handle("127.0.0.1:1", b) })
}
