package cweng

import (
	"crypto/tls"
	"fmt"
	"net"
	"sync"

	"uacgo/capwap"

	dtls "github.com/pion/dtls/v2"
)

// Real DTLS record/handshake layer backed by pion/dtls v2 (pure Go, no
// cgo). The stock binary links GnuTLS for the same role
// (capwap_dtls_global_init / capwap_network_session_init with the dtls
// flag); certificate and key paths come from the profile
// (cacert_file_path/privkey_file_path).
//
// Integration model: when the engine's UDP socket receives a ClientHello
// (IsClientHello), the peer's socket end is handed to dtls.Server via
// DTLSManager's factory; after establishment, Wrap/Unwrap implement the
// application-data record conversion.

// PionHandshaker implements Handshaker over one connected UDP transport.
type PionHandshaker struct {
	cfg   dtls.Config
	mu    sync.Mutex
	estab net.Conn
	done  chan struct{}
	err   error
}

// NewPionServerHandshaker builds a server-side handshaker from the profile
// certificate/key pair.
func NewPionServerHandshaker(certFile, keyFile string) (*PionHandshaker, error) {
	cert, err := tls.LoadX509KeyPair(certFile, keyFile)
	if err != nil {
		return nil, fmt.Errorf("dtls keypair: %w", err)
	}
	return &PionHandshaker{
		cfg: dtls.Config{
			Certificates: []tls.Certificate{cert},
			// The AC does not verify AP certificates (noted in the
			// protocol reference; DTLS_SETUP accepts any ClientHello).
			ClientAuth: dtls.NoClientCert,
		},
		done: make(chan struct{}),
	}, nil
}

// Bind wraps a connected transport (a connected UDP socket from the
// engine; any net.Conn for tests) and starts the server handshake loop;
// each received datagram is decrypted via Unwrap by the caller.
func (p *PionHandshaker) Bind(conn net.Conn) error {
	dconn, err := dtls.Server(conn, &p.cfg)
	if err != nil {
		return fmt.Errorf("dtls server: %w", err)
	}
	p.handshakeDone(dconn)
	return nil
}

func (p *PionHandshaker) handshakeDone(dconn net.Conn) {
	close(p.done)
	// stash the established connection for Wrap/Unwrap
	p.mu.Lock()
	p.estab = dconn
	p.mu.Unlock()
}

// Unwrap reads and decodes one application-data datagram from the
// established DTLS connection.
func (p *PionHandshaker) Unwrap() ([]byte, error) {
	p.mu.Lock()
	c := p.estab
	p.mu.Unlock()
	if c == nil {
		return nil, fmt.Errorf("dtls not established")
	}
	buf := make([]byte, capwap.MaxUdpPayload)
	n, err := c.Read(buf)
	if err != nil {
		return nil, err
	}
	return buf[:n], nil
}

// Handshake satisfies the Handshaker interface via Bind (the engine hands
// the peer's UDP socket once the ClientHello is seen).
func (p *PionHandshaker) Handshake(packets [][]byte) (bool, error) {
	select {
	case <-p.done:
		return true, p.err
	default:
		return false, nil
	}
}

// Wrap encrypts one application-data datagram.
func (p *PionHandshaker) Wrap(plain []byte) ([]byte, error) {
	p.mu.Lock()
	c := p.estab
	p.mu.Unlock()
	if c == nil {
		return nil, fmt.Errorf("dtls not established")
	}
	if _, err := c.Write(plain); err != nil {
		return nil, err
	}
	// pion writes the encrypted record onto the underlying UDP conn
	// synchronously; the caller's socket receives it.
	return plain, nil
}
