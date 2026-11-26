package cweng

import (
	"encoding/binary"
	"fmt"
	"golang.org/x/net/ipv4"
	"log"
	"net"
	"os"
	"sync"
	"sync/atomic"
	"time"

	"uacgo/capwap"
	"uacgo/controllercfg"
	"uacgo/internal/legacydtls"
)

// Engine is the AC-side CAPWAP engine. It mirrors the binary's structure:
// one UDP socket pair (v4+v6 combined in Go), a session table, per-message
// handler chains registered by the subsystems, and the session FSM.
type Engine struct {
	outboundMu     sync.Mutex
	outbound       map[*Session]*commandQueue
	apdb           *APDB
	mu             sync.Mutex
	conn           *net.UDPConn
	sessions       map[string]*Session
	reg            *registry
	acData         *AcDataCounters
	packetConn     *ipv4.PacketConn
	interfaceIndex int
	legacyDTLS     *legacydtls.Server
	trace          func(string, []byte)
	fragments      capwap.Reassembler

	resources         atomic.Pointer[engineResources]
	Debug             bool
	RetransIntervalMs int // profile default_retransmit_time (ms, test-tunable)
	RetransMax        int // profile retransmit_max_retries

	// Identity used by the built-in response builders (runtime values the
	// binary reads from its config store).
	ACName      string
	ACVersion   string
	ACFirmware  string
	ControlIP   [4]byte
	ControlPort uint16
	RadioTypes  [][2]uint8 // radio id + type flags for 0x418 elements

	// sendToForTest overrides the raw send path in unit tests.
	sendToForTest func(*net.UDPAddr, []byte) error
	apStore       APStore

	// EntEvent hooks fire the ent lifecycle listeners (0/2 reset, 1 run).
	OnEntReset func(*Session) error
	OnEntRun   func(*Session) error
	OnDelete   func(*Session)
	OnAPState  func(APStatus)
	// Set before Run. Nil retains protocol-only operation for engine users.
	ObserveAssociation func(ap string, radio, wlan uint8, mac [6]byte) bool
	AdmitStation       func(ap string, radio, wlan uint8) bool
	// Runs under the AP session lock; must not call session/engine readers.
	CheckAssociation    func(ap string, radio, wlan uint8, mac [6]byte, rssi *int8, mlo *capwap.AssociationMLO) uint32
	AdmitClient         func(ap string, radio, wlan uint8, mac [6]byte, rssi *int8) bool
	meshChildAuthorize  func(string, time.Time, string, uint8) bool
	OnRoamingTrigger    func(ap string, connection time.Time, report capwap.PrivRoamingTrigger)
	OnStationDiscovery  func(ap string, connection time.Time, mac [6]byte)
	OnStationStatistics func(ap string, connection time.Time, stats capwap.StaStatisticsRecord)
	OnRSSIStatistics    func(ap string, connection time.Time, stats capwap.PrivRssiStatistics)
	OnAPStatistics      func(ap string, connection time.Time, stats capwap.PrivApStatistics)
	OnBSSIDLocations    func(ap string, connection time.Time, rows []capwap.BSSIDLocation)
	OnRRMReport         func(ap string, connection time.Time, report capwap.PrivRrmNeighsList)
	OnStationPMK        func(ap string, connection time.Time, special bool, request capwap.PrivStaPMKReq) *capwap.PrivStaPMKReq
}

// LocalPort returns the bound UDP port (test/diagnostic helper).
func (e *Engine) LocalPort() int {
	if e.conn == nil {
		return 0
	}
	return e.conn.LocalAddr().(*net.UDPAddr).Port
}

var debugEngine = os.Getenv("UACGO_DEBUG") != ""

func NewEngine(port uint16) (*Engine, error) {
	addr := &net.UDPAddr{Port: int(port)}
	conn, err := net.ListenUDP("udp", addr)
	if err != nil {
		return nil, err
	}
	e := &Engine{
		conn:              conn,
		sessions:          make(map[string]*Session),
		reg:               newRegistry(),
		acData:            &AcDataCounters{},
		RetransIntervalMs: 3000,
		RetransMax:        5,
		ACName:            "TL-AC100",
		ACVersion:         "1.0",
		ACFirmware:        "1.0.1 Build 20140919 Rel.59746",
		ControlPort:       port,
	}
	r := controllercfg.Defaults()
	e.SetResourceLimits(r.MaxAPSessions, r.CommandQueueDepth)
	return e, nil
}

// Register mirrors serv_msg_mngr_register.
func (e *Engine) Register(msgType uint32, prio uint16, name string, h Handler) {
	e.reg.Register(msgType, prio, name, h)
}

// RegisterEnt mirrors serv_ent_mngr_register (0/2 reset, 1 run, 3 ifindex).
func (e *Engine) RegisterEnt(ent uint, prio uint16, name string, h Handler) {
	e.reg.RegisterEnt(ent, prio, name, h)
}

// Run serves until the connection closes (cw_ac_run → cw_ac_run_callback).
func (e *Engine) Run() error {
	buf := make([]byte, capwap.MaxUdpPayload)
	for {
		var n int
		var addr *net.UDPAddr
		var err error
		if e.packetConn != nil {
			var peer net.Addr
			var cm *ipv4.ControlMessage
			n, cm, peer, err = e.packetConn.ReadFrom(buf)
			if err == nil && (cm == nil || cm.IfIndex != e.interfaceIndex) {
				continue
			}
			addr, _ = peer.(*net.UDPAddr)
		} else {
			n, addr, err = e.conn.ReadFromUDP(buf)
		}
		if err != nil {
			return err
		}
		pkt := make([]byte, n)
		copy(pkt, buf[:n])
		if e.trace != nil {
			e.trace("rx", pkt)
		}
		e.handleDatagram(pkt, addr)
	}
}

// sendToForTest overrides the raw send path in unit tests.
var _ = net.IPv4

func (e *Engine) sendTo(addr *net.UDPAddr, b []byte) error {
	if e.sendToForTest != nil {
		return e.sendToForTest(addr, b)
	}
	if addr == nil {
		return fmt.Errorf("nil peer addr")
	}
	if e.legacyDTLS != nil && !(len(b) >= 12 && binary.BigEndian.Uint32(b[8:12]) == capwap.MsgDiscoveryResponse) {
		if !e.legacyDTLS.Established(addr.String()) {
			return fmt.Errorf("AP DTLS session is unavailable")
		}
		if e.trace != nil {
			e.trace("plain-tx", b)
		}
		packet, err := e.legacyDTLS.Encrypt(addr.String(), b)
		if err != nil {
			return err
		}
		b = append([]byte{1, 0, 0, 0}, packet...)
	}
	return e.sendRaw(addr, b)
}

// sendSession is called with s.mu held, so teardown cannot race plaintext
// sends. DTLS additionally pins encryption to this session's handshake.
func (e *Engine) sendSession(s *Session, b []byte) error {
	if s.meshParent != nil {
		return e.sendMeshSession(s, b)
	}
	if len(b) <= 1200 {
		return e.sendSessionFragment(s, b)
	}
	s.fragmentID++
	packets, err := capwap.FragmentPacket(b, s.fragmentID, 1200)
	if err != nil {
		return err
	}
	for _, packet := range packets {
		if err := e.sendSessionFragment(s, packet); err != nil {
			return err
		}
	}
	return nil
}
func (e *Engine) sendSessionFragment(s *Session, b []byte) error {
	if s.dead {
		return fmt.Errorf("AP session closed")
	}
	if e.legacyDTLS == nil || e.sendToForTest != nil {
		return e.sendTo(s.Addr, b)
	}
	packet, err := e.legacyDTLS.EncryptGeneration(s.Addr.String(), s.transportGeneration, b)
	if err != nil {
		return err
	}
	if e.trace != nil {
		e.trace("plain-tx", b)
	}
	return e.sendRaw(s.Addr, append([]byte{1, 0, 0, 0}, packet...))
}

func (e *Engine) sendRaw(addr *net.UDPAddr, b []byte) error {
	if e.trace != nil {
		e.trace("tx", b)
	}
	if e.packetConn != nil {
		_, err := e.packetConn.WriteTo(b, &ipv4.ControlMessage{IfIndex: e.interfaceIndex, Src: net.IP(e.ControlIP[:])}, addr)
		return err
	}
	_, err := e.conn.WriteToUDP(b, addr)
	return err
}

// BindInterface filters received packets by IP_PKTINFO and selects the same
// interface for replies, while retaining limited-broadcast discovery.
func (e *Engine) BindInterface(name string) error {
	iface, err := net.InterfaceByName(name)
	if err != nil {
		return err
	}
	p := ipv4.NewPacketConn(e.conn)
	if err = p.SetControlMessage(ipv4.FlagInterface, true); err != nil {
		return err
	}
	e.packetConn = p
	e.interfaceIndex = iface.Index
	return nil
}
func (e *Engine) BoundInterface() string {
	if e.interfaceIndex == 0 {
		return ""
	}
	nic, err := net.InterfaceByIndex(e.interfaceIndex)
	if err != nil {
		return ""
	}
	return nic.Name
}

func (e *Engine) EnableLegacyDTLS(certFile, keyFile string) error {
	var err error
	e.legacyDTLS, err = legacydtls.New(certFile, keyFile)
	if err == nil {
		e.legacyDTLS.SetMaxPeers(e.MaxAPSessions() + 8) // bounded room for reconnect handshakes
	}
	return err
}

// Trace records wire datagrams without exposing keys through ordinary logs.
func (e *Engine) Trace(fn func(string, []byte)) { e.trace = fn }
func (e *Engine) Close() error {
	for _, s := range e.sessionList() {
		s.mu.Lock()
		if e.legacyDTLS != nil {
			if b, err := e.legacyDTLS.Close(s.Addr.String()); err == nil && len(b) > 0 {
				_ = e.sendRaw(s.Addr, append([]byte{1, 0, 0, 0}, b...))
			}
		}
		s.teardown()
		s.mu.Unlock()
	}
	return e.conn.Close()
}

// handleDatagram mirrors cw_ac_data_network_process + ac_msg_pretreat +
// ac_msg_handle for the no-DTLS configuration the AC100 ships with.
func (e *Engine) handleDatagram(raw []byte, addr *net.UDPAddr) {
	if len(raw) >= 4 && raw[0] == 1 && raw[1] == 0 && raw[2] == 0 && raw[3] == 0 {
		if e.legacyDTLS == nil {
			return
		}
		responses, packets, err := e.legacyDTLS.Handle(addr.String(), raw[4:])
		for _, b := range responses {
			_ = e.sendRaw(addr, append([]byte{1, 0, 0, 0}, b...))
		}
		if err != nil {
			log.Printf("DTLS %s: %v", addr, err)
			return
		}
		for _, plain := range packets {
			if e.trace != nil {
				e.trace("plain-rx", plain)
			}
			e.handlePlainDatagram(plain, addr)
		}
		return
	}
	if e.legacyDTLS != nil && !capwap.IsDiscoveryRequest(raw) {
		return
	}
	e.handlePlainDatagram(raw, addr)
}

func (e *Engine) handlePlainDatagram(raw []byte, addr *net.UDPAddr) {
	peer := addr.String()
	if e.legacyDTLS != nil {
		peer += fmt.Sprintf("/%x", e.legacyDTLS.Generation(addr.String()))
	}
	complete, fragmentErr := e.fragments.Push(peer, raw)
	if fragmentErr != nil || complete == nil {
		return
	}
	raw = complete
	if len(raw) < 16 {
		return
	}
	if capwap.IsDiscoveryRequest(raw) {
		e.handleDiscovery(raw, addr)
		return
	}
	// parsed packet for the session path
	var req *capwap.ParsedPacket
	var err error
	if e.legacyDTLS != nil && e.legacyDTLS.Established(addr.String()) {
		req, err = capwap.ParseDTLSPacket(raw)
	} else {
		req, err = capwap.ParsePacket(raw)
	}
	if err != nil {
		return
	}
	msgType := req.Control.MsgType
	if debugEngine || e.Debug {
		log.Printf("[ENG] recv msg=%d seq=%d from %s", msgType, req.Control.SeqNum, addr)
	}
	s := e.sessionFor(addr)
	if s != nil && e.handleMeshPublic(s, req) {
		return
	}
	if s != nil && msgType == MsgJoin && e.legacyDTLS != nil && s.transportGeneration != e.legacyDTLS.Generation(addr.String()) {
		s.mu.Lock()
		s.teardown()
		s.mu.Unlock()
		s = nil
	}

	if s == nil {
		// cw_ac_data_network_process: only join requests create sessions
		// (capwap_dtls_enable_switch == 0 path).
		if msgType != MsgJoin {
			return
		}
		ap, err := ParseAPEntry(req)
		if err == nil && len(ap.Capabilities) == 0 && e.apdb != nil {
			e.apdb.ResolveCapabilities(ap)
		}
		if err != nil {
			return
		}
		// An authenticated AP may reconnect from a new source port before
		// its old watchdog expires. Retire that identity before capacity
		// checks and before exposing it to management commands.
		id := ap.MAC
		if id == "" {
			id = ap.Serial
		}
		if id != "" {
			for _, old := range e.sessionList() {
				old.mu.Lock()
				if sessionID(old) == id {
					old.teardown()
				}
				old.mu.Unlock()
			}
		}
		s = newSession(addr, e.acData)
		if e.legacyDTLS != nil {
			s.transportGeneration = e.legacyDTLS.Generation(addr.String())
		}
		s.onAPState = e.OnAPState
		s.onTeardown = func(x *Session) { e.removeSession(x) }
		s.onEnterRun = func(x *Session) error {
			if e.OnEntRun != nil {
				return e.OnEntRun(x)
			}
			e.reg.fireEnt(1, &Ctx{Session: x})
			return nil
		}
		s.onEnterReset = func(x *Session) error {
			if e.OnEntReset != nil {
				return e.OnEntReset(x)
			}
			e.reg.fireEnt(2, &Ctx{Session: x})
			return nil
		}
		s.onDelete = func(x *Session) { e.removeSession(x) }
		s.send = func(x *Session, b []byte) error { return e.sendSession(x, b) }
		s.RetransInterval = e.RetransIntervalMs
		s.RetransMax = e.RetransMax
		// cw_fsm_ac_process_event(session, 8) — DTLS established (direct path)
		if err := s.processEvent(&Event{ID: EventDTLSEstab}); err != nil {
			log.Printf("fsm: %v", err)
		}
		s.apEntry = ap
		if !e.registerSession(s) {
			s.mu.Lock()
			s.teardown()
			s.mu.Unlock()
			return // capwap_ac_session_exceed_max_num: "just ignore it"
		}
		// The binary creates the AP entry inside the join listener
		// (_apmngr_try_create_ap_entry_by_template_or_db), not at RUN.
		if e.apStore != nil {
			if err := e.apStore.UpsertAP(ap); err != nil {
				log.Printf("apmngr store: %v", err)
			}
		}
	}

	e.handleSessionPacket(s, req, raw)
}

// handleSessionPacket mirrors ac_msg_pretreat + ac_msg_handle.
func (e *Engine) handleSessionPacket(s *Session, req *capwap.ParsedPacket, raw []byte) {
	s.mu.Lock()
	defer s.mu.Unlock()
	if s.dead {
		return
	}
	if debugEngine || e.Debug {
		log.Printf("[ENG] session pkt msg=%d seq=%d state=%s", req.Control.MsgType, req.Control.SeqNum, StateNames[s.State])
	}
	s.LastSeen = time.Now()

	msgType := req.Control.MsgType
	seq := req.Control.SeqNum

	// --- ac_msg_pretreat: illegal-sequence drop ---
	if isRequestMsg(msgType) && !s.VerifySeqWindow(seq) {
		return
	}
	// --- FSM gate (event 1, arg = msg type) ---
	if err := s.gate(msgType); err != nil {
		return
	}
	// Gate passed: this packet replaces the pending response retransmission
	// (packets the gate rejects are dropped before touching the queue).
	s.cancelRspRetransmit()

	// --- ac_msg_handle ---
	if isRequestMsg(msgType) {
		// duplicate request with a stored response → re-send it
		if s.DuplicateReq(seq) {
			rsp := s.LastRspBuf
			if len(rsp) >= 12 && binary.BigEndian.Uint32(rsp[8:12]) == msgType+1 {
				e.sendSession(s, rsp)
			}
			return
		}
		rsp, err := capwap.NewParsedPacket(msgType + 1)
		if err != nil {
			return
		}
		// responses copy rid/wbid/seq from the request
		// (ac_parsed_packet_create @0x590d58)
		rsp.Header.Rid = req.Header.Rid
		rsp.Header.Wbid = req.Header.Wbid
		rsp.Control.SeqNum = seq

		ctx := &Ctx{Session: s}
		ok := e.reg.handleMsg(ctx, msgType, req, rsp)
		if msgType == MsgJoin && !ok {
			// ac_packet_is_right check on join responses; the binary warns
			// "Already joined" for result-code 7 and tears down otherwise.
			s.teardown()
			return
		}

		out := rsp.Assemble()
		if debugEngine || e.Debug {
			log.Printf("[ENG] sending rsp len=%d elements=%d", len(out), len(rsp.Elements))
		}
		if err := e.sendSession(s, out); err != nil {
			if debugEngine || e.Debug {
				log.Printf("[ENG] send err: %v", err)
			}
			return
		}
		s.NoteSeq(seq, out)
		_ = s.recvResult(msgType, ok)
		return
	}

	// RESPONSE message (even type): dispatch to handlers, then FSM result.
	s.acknowledge(req)
	ctx := &Ctx{Session: s}
	ok := e.reg.handleMsg(ctx, msgType, req, nil)
	_ = s.recvResult(0, ok)
}

// handleDiscovery mirrors capwap_ac_discovery_handle @0x591ae4:
// build a Discovery Response (msg 2) via the registered msg-1 handlers and
// send it; no session state involved.
func (e *Engine) handleDiscovery(raw []byte, addr *net.UDPAddr) {
	req, err := capwap.ParsePacket(raw)
	if err != nil {
		return
	}
	rsp, err := capwap.NewParsedPacket(capwap.MsgDiscoveryResponse)
	if err != nil {
		return
	}
	rsp.Header.Rid = req.Header.Rid
	rsp.Header.Wbid = req.Header.Wbid
	rsp.Control.SeqNum = req.Control.SeqNum
	e.reg.handleMsg(&Ctx{Session: nil}, capwap.MsgDiscoveryRequest, req, rsp)
	out := rsp.Assemble()
	_ = e.sendTo(addr, out)
}

func (e *Engine) sessionFor(addr *net.UDPAddr) *Session {
	e.mu.Lock()
	defer e.mu.Unlock()
	return e.sessions[addr.String()]
}

func (e *Engine) removeSession(s *Session) {
	e.mu.Lock()
	defer e.mu.Unlock()
	if cur, ok := e.sessions[s.sessionKey()]; ok && cur == s {
		delete(e.sessions, s.sessionKey())
		if s.meshParent == nil && e.legacyDTLS != nil && s.transportGeneration == e.legacyDTLS.Generation(s.Addr.String()) {
			e.legacyDTLS.Remove(s.Addr.String())
		}
	}
}

// isRequestMsg mirrors ac_packet_is_request @0x590438: bitmask 0xaa28 over
// msg types < 0x10 → {3,5,9,11,13,15}.
func isRequestMsg(t uint32) bool {
	if t >= 0x10 {
		return false
	}
	return 1<<(t&0x1f)&0xaa28 != 0
}

// WorkerIndex mirrors ip_to_ac_data @0x589cc8 (load spread across workers).
func WorkerIndex(ip [4]byte, port uint16, n int) int {
	if n == 0 {
		return 0
	}
	sum := uint32(ip[0]) + uint32(ip[1]) + uint32(ip[2]) + uint32(ip[3]) + uint32(port&0xff)
	return int((sum + uint32(port)%uint32(n)) % uint32(n))
}

var _ = fmt.Sprintf // keep fmt for future logging paths
var _ = binary.BigEndian
