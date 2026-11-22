package cweng

import (
	"encoding/binary"
	"sync"
)

// DTLS skeleton for the capwap_dtls_enable_switch path.
//
// Evidence (uac binary):
//   - capwap_packet_is_clienthello @0x597ab0: the exact detection rule is
//     buf[0]==0x01 && buf[4]==0x16 && buf[0x11]==0x01 — a 4-byte vendor
//     prefix followed by a DTLS record whose handshake byte (record header
//     13 bytes) is ClientHello.
//   - capwap_dtls_global_init / capwap_network_session_init(..., dtls, ...)
//     (cw_ac_data_run): when capwap_dtls_enable_switch != 0 the worker
//     passes event 7 (DTLS_SETUP_NOTIFY) instead of 8 and the session FSM
//     routes IDLE → DTLS_SETUP (cw_fsm_ac_idle @0x59e7d0) → JOIN_WAIT on
//     DTLS_ESTABLISHED; event 9 tears down (DTLS_TEARDOWN, timer
//     DTLS_SESSION_DELETE 10s).
//   - Certificate/key paths come from the profile (ac_capwap
//     cacert_file_path / privkey_file_path, 0x80-byte strings in
//     l_profile @0x2c/0xac).

// DTLSConfig carries the profile-sourced TLS material.
type DTLSConfig struct {
	Enable   bool
	CertFile string // cacert_file_path
	KeyFile  string // privkey_file_path
}

// Handshaker abstracts the DTLS record layer. The stock binary links
// GnuTLS; the Go port accepts any implementation that can turn the raw
// UDP datagrams of one session into plaintext CAPWAP packets.
type Handshaker interface {
	// Handshake consumes the packets up to (and including) the completed
	// DTLS handshake and reports whether the session is established.
	Handshake(packets [][]byte) (established bool, err error)
	// Unwrap decodes one encrypted datagram into CAPWAP plaintext.
	Unwrap(datagram []byte) ([]byte, error)
	// Wrap encrypts one outgoing CAPWAP plaintext datagram.
	Wrap(plain []byte) ([]byte, error)
}

// IsClientHello mirrors capwap_packet_is_clienthello @0x597ab0 byte rule.
func IsClientHello(b []byte) bool {
	return len(b) > 0x11 &&
		b[0] == 0x01 && b[4] == 0x16 && b[0x11] == 0x01
}

// DTLSManager tracks per-session DTLS state and routes handshake packets.
type DTLSManager struct {
	mu        sync.Mutex
	cfg       DTLSConfig
	new       func(peer string) Handshaker
	sessions  map[string]Handshaker
	establish map[string]bool
}

// NewDTLSManager creates the manager; new may be nil (no handshaker
// factory — handshake packets are then dropped, matching an unconfigured
// GnuTLS context).
func NewDTLSManager(cfg DTLSConfig, new func(peer string) Handshaker) *DTLSManager {
	return &DTLSManager{cfg: cfg, new: new, sessions: make(map[string]Handshaker),
		establish: make(map[string]bool)}
}

// Enabled reports the enable switch.
func (m *DTLSManager) Enabled() bool { return m != nil && m.cfg.Enable }

// IsEstablished reports DTLS readiness for a peer.
func (m *DTLSManager) IsEstablished(peer string) bool {
	if m == nil {
		return false
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	return m.establish[peer]
}

// FeedClientHello processes a ClientHello datagram for a peer. Without a
// handshaker factory it returns false (not established), mirroring the
// binary's behaviour when the GnuTLS context is missing.
func (m *DTLSManager) FeedClientHello(peer string, pkt []byte) bool {
	if m == nil || !m.Enabled() || !IsClientHello(pkt) {
		return false
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	h := m.sessions[peer]
	if h == nil {
		if m.new == nil {
			return false
		}
		h = m.new(peer)
		m.sessions[peer] = h
	}
	established, err := h.Handshake([][]byte{pkt})
	if err != nil || !established {
		return false
	}
	m.establish[peer] = true
	return true
}

// Teardown drops a peer's DTLS state (DTLS_TEARDOWN path).
func (m *DTLSManager) Teardown(peer string) {
	if m == nil {
		return
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	delete(m.sessions, peer)
	delete(m.establish, peer)
}

var _ = binary.BigEndian
