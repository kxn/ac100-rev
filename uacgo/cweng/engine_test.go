package cweng

import (
	"net"
	"os"
	"testing"
	"time"
	"uacgo/internal/testroot"

	"uacgo/capwap"
)

// fixtureIdentity supplies the same values the vendor fixtures encode.
type fixtureIdentity struct{}

func (fixtureIdentity) ACDescriptor() capwap.ACDescriptor {
	return capwap.ACDescriptor{
		Stations: 0, StationLim: 10000, ActiveStas: 1, ActiveLim: 1000,
		Status: 2, RStatus: 2, SlaveStatus: 4,
		SubElements: []capwap.ACDescriptorSubElement{
			{Vendor: 0x12345678, Type: 4, Data: capwap.PaddedString("TL-AC1000 v1.0", 64)},
			{Vendor: 0x12345678, Type: 5, Data: capwap.PaddedString("1.0.1 Build 20140919 Rel.59746", 64)},
		},
	}
}
func (fixtureIdentity) ACName() string                    { return "TL-AC1000" }
func (fixtureIdentity) ControlAddress() ([4]byte, uint16) { return [4]byte{192, 168, 1, 253}, 0 }
func (fixtureIdentity) LocalAddress() [4]byte             { return [4]byte{192, 168, 1, 253} }
func (fixtureIdentity) Radios() [][2]uint8                { return [][2]uint8{{1, 0}, {2, 0}} }
func (fixtureIdentity) CfgStatusFixed() CfgStatusFixed {
	return CfgStatusFixed{
		DiscoveryTimer: 0x14, EchoTimer: 0x14,
		DecryptPeriod: [3]byte{0x01, 0x00, 0x78},
		IdleTimeout:   3600,
		WTPFallback:   1,
		ACIPv4List:    [][4]byte{{192, 168, 1, 253}},
	}
}
func (fixtureIdentity) Envelope(mt uint32) [][]byte { return nil }

func mustFixture(t *testing.T, name string) []byte {
	t.Helper()
	b, err := os.ReadFile(testroot.Root() + "/ghidra-export/data/" + name)
	if err != nil {
		t.Fatal(err)
	}
	return b
}

// withSeq clones a fixture with the control seq byte replaced (byte 12).
// Vendor fixtures each carry their own sample seq; a live session's requests
// must have monotonically increasing seq (ac_msg_pretreat window rule).
func withSeq(t *testing.T, name string, seq byte) []byte {
	t.Helper()
	b := append([]byte(nil), mustFixture(t, name)...)
	b[12] = seq
	return b
}

// synthMsg builds a minimal request packet (message types the vendor .data
// templates don't include, e.g. Echo Request).
func synthMsg(t *testing.T, msgType uint32, seq byte) []byte {
	t.Helper()
	p, err := capwap.NewParsedPacket(msgType)
	if err != nil {
		t.Fatal(err)
	}
	p.Control.SeqNum = seq
	return p.Assemble()
}

// End-to-end over a real UDP socket: the full AP attach lifecycle
// discovery → join → config-status → change-state → echo, with state
// assertions matching the binary's FSM transitions, plus the duplicate
// request re-send and old-seq drop semantics.
func TestEngineApLifecycle(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	e.RegisterAttachHandlers(fixtureIdentity{})
	go func() { _ = e.Run() }()

	// Transport abstraction: real UDP when the loopback path carries the
	// large vendor fixtures (~2.4KB), otherwise an in-memory transport
	// (some sandboxes drop IP fragments / >1500B IP packets on the
	// loopback path — the fixture frames themselves are unaffected).
	var tp lifecycleTransport
	if largeUDPWorks() {
		c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
		if err != nil {
			t.Fatal(err)
		}
		defer c.Close()
		tp = lifecycleTransport{
			peerKey: c.LocalAddr().String(),
			write:   func(b []byte) error { _, err := c.Write(b); return err },
			read: func(d time.Duration) ([]byte, error) {
				buf := make([]byte, capwap.MaxUdpPayload)
				c.SetReadDeadline(time.Now().Add(d))
				n, err := c.Read(buf)
				return buf[:n], err
			},
		}
	} else {
		t.Log("large UDP loopback unavailable — running the lifecycle over the in-memory transport")
		peer := &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 40000}
		rx := make(chan []byte, 16)
		e.sendToForTest = func(_ *net.UDPAddr, b []byte) error {
			rx <- append([]byte(nil), b...)
			return nil
		}
		tp = lifecycleTransport{
			peerKey: peer.String(),
			write:   func(b []byte) error { e.handleDatagram(b, peer); return nil },
			read: func(d time.Duration) ([]byte, error) {
				select {
				case b := <-rx:
					return b, nil
				case <-time.After(d):
					return nil, os.ErrDeadlineExceeded
				}
			},
		}
	}
	read := func(t *testing.T) []byte {
		t.Helper()
		b, err := tp.read(2 * time.Second)
		if err != nil {
			t.Fatalf("no response: %v", err)
		}
		return b
	}
	expectNoReply := func(t *testing.T) {
		t.Helper()
		if b, err := tp.read(300 * time.Millisecond); err == nil {
			t.Fatalf("expected no reply, got %d bytes", len(b))
		}
	}

	// --- discovery: no session, response carries the identity elements ---
	tp.write(mustFixture(t, "cw_dis_req_0074f340.bin"))
	rsp, err := capwap.ParsePacket(read(t))
	if err != nil || rsp.Control.MsgType != capwap.MsgDiscoveryResponse {
		t.Fatalf("bad discovery response: %v", err)
	}

	// --- join (seq 2): creates session, IDLE→JOIN_WAIT→(PASSED)→JOIN_FINISH ---
	tp.write(withSeq(t, "cw_join_req_0074f150.bin", 2))
	rsp, err = capwap.ParsePacket(read(t))
	if err != nil || rsp.Control.MsgType != capwap.MsgJoinResponse || rsp.Control.SeqNum != 2 {
		t.Fatalf("bad join response: %v", err)
	}
	e.mu.Lock()
	s := e.sessions[tp.peerKey]
	st := s.State
	e.mu.Unlock()
	if s == nil || st != StateJoinFinish {
		t.Fatalf("session state = %v (want JOIN_FINISH)", st)
	}

	// retransmitted join in JOIN_FINISH: the binary's gate
	// (join_finish_recv_pkt_check @0x59f328 accepts only {15,5}) drops it.
	tp.write(withSeq(t, "cw_join_req_0074f150.bin", 2))
	expectNoReply(t)

	// --- config status (seq 3): JOIN_FINISH→CONFIGURE ---
	tp.write(withSeq(t, "cw_cfg_req_0074ef5c.bin", 3))
	rsp, err = capwap.ParsePacket(read(t))
	if err != nil || rsp.Control.MsgType != capwap.MsgConfigurationStatusResponse {
		t.Fatalf("bad cfg status response: %v", err)
	}
	if st := s.State; st != StateConfigure {
		t.Fatalf("state = %s (want CONFIGURE)", StateNames[st])
	}

	// --- change state event (seq 4): CONFIGURE→RUN + ent-1 listeners fired ---
	ran := make(chan struct{}, 1)
	e.OnEntRun = func(x *Session) error { ran <- struct{}{}; return nil }
	tp.write(withSeq(t, "cw_cse_req_0074ee9c.bin", 4))
	rsp, err = capwap.ParsePacket(read(t))
	if err != nil || rsp.Control.MsgType != capwap.MsgChangeStateEventResponse {
		t.Fatalf("bad cse response: %v", err)
	}
	if st := s.State; st != StateRun {
		t.Fatalf("state = %s (want RUN)", StateNames[st])
	}
	select {
	case <-ran:
	default:
		t.Fatal("ent-1 (enter run) listeners not fired")
	}

	// --- echo (seq 5): RUN keep-alive, empty response (msg 14) ---
	tp.write(synthMsg(t, cwengMsgEcho, 5))
	rsp, err = capwap.ParsePacket(read(t))
	if err != nil || rsp.Control.MsgType != 14 {
		t.Fatalf("bad echo response: %v", err)
	}
	if len(rsp.Elements) != 0 {
		t.Fatalf("echo response carries %d elements (binary adds none)", len(rsp.Elements))
	}

	// --- duplicate echo (same seq 5): stored response re-sent
	// (ac_msg_handle same-seq branch: "send last send response") ---
	tp.write(synthMsg(t, cwengMsgEcho, 5))
	rsp2, err := capwap.ParsePacket(read(t))
	if err != nil || rsp2.Control.MsgType != 14 || rsp2.Control.SeqNum != 5 {
		t.Fatalf("bad duplicate echo response: %v", err)
	}

	// --- old-seq echo (seq 4 < 5): ac_msg_pretreat window drops it ---
	tp.write(synthMsg(t, cwengMsgEcho, 4))
	expectNoReply(t)
}

// cwengMsgEcho — capwap package doesn't re-export 13 under this name.
const cwengMsgEcho = 13

// lifecycleTransport abstracts the client side of TestEngineApLifecycle.
type lifecycleTransport struct {
	peerKey string // the engine's session map key for this client
	write   func([]byte) error
	read    func(time.Duration) ([]byte, error)
}

// largeUDPWorks reports whether the loopback path carries IP packets
// above the 1500-byte Ethernet MTU (needed for the ~2.4KB vendor
// fixtures; some sandboxes drop the fragments).
func largeUDPWorks() bool {
	srv, err := net.ListenUDP("udp", &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 0})
	if err != nil {
		return false
	}
	defer srv.Close()
	cli, err := net.DialUDP("udp", nil, srv.LocalAddr().(*net.UDPAddr))
	if err != nil {
		return false
	}
	defer cli.Close()
	go func() {
		buf := make([]byte, 4096)
		if n, addr, err := srv.ReadFromUDP(buf); err == nil && n == 2000 {
			srv.WriteToUDP([]byte{1}, addr)
		}
	}()
	if _, err := cli.Write(make([]byte, 2000)); err != nil {
		return false
	}
	cli.SetReadDeadline(time.Now().Add(500 * time.Millisecond))
	buf := make([]byte, 1)
	n, err := cli.Read(buf)
	return err == nil && n == 1
}

// TestEngineDiscoveryRealUDP exercises the engine over real UDP with a
// compact synthesized discovery request (fits any loopback MTU).
func TestEngineDiscoveryRealUDP(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	e.RegisterAttachHandlers(fixtureIdentity{})
	go func() { _ = e.Run() }()
	defer e.conn.Close()

	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	// minimal valid discovery request: the fixture preamble + control
	// header {type 1, seq 1, MEL 3 (=0 elements + 3), flags 0}
	req := []byte{0x00, 0x10, 0x43, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 3, 0}
	if _, err := c.Write(req); err != nil {
		t.Fatal(err)
	}
	buf := make([]byte, capwap.MaxUdpPayload)
	c.SetReadDeadline(time.Now().Add(2 * time.Second))
	n, err := c.Read(buf)
	if err != nil {
		t.Fatalf("no response over real UDP: %v", err)
	}
	rsp, err := capwap.ParsePacket(buf[:n])
	if err != nil || rsp.Control.MsgType != capwap.MsgDiscoveryResponse {
		t.Fatalf("bad discovery response: %v", err)
	}
}
