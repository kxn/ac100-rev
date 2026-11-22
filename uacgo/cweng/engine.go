package cweng

import (
	"encoding/binary"
	"fmt"
	"log"
	"net"
	"os"
	"sync"

	"uacgo/capwap"
)

// Engine is the AC-side CAPWAP engine. It mirrors the binary's structure:
// one UDP socket pair (v4+v6 combined in Go), a session table, per-message
// handler chains registered by the subsystems, and the session FSM.
type Engine struct {
	mu       sync.Mutex
	conn     *net.UDPConn
	sessions map[string]*Session
	reg      *registry
	acData   *AcDataCounters

	// OnAttach is invoked after the join identity is parsed (the binary's
	// join listeners register the WTP into apmngr/steering databases).
	OnAttach func(*Session, *APEntry)

	MaxSessions       int // l_profile[0x140] max_session_num
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
	return &Engine{
		conn:              conn,
		sessions:          make(map[string]*Session),
		reg:               newRegistry(),
		acData:            &AcDataCounters{},
		MaxSessions:       64,
		RetransIntervalMs: 3000,
		RetransMax:        5,
		ACName:            "TL-AC100",
		ACVersion:         "1.0",
		ACFirmware:        "1.0.1 Build 20140919 Rel.59746",
		ControlPort:       port,
	}, nil
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
		n, addr, err := e.conn.ReadFromUDP(buf)
		if err != nil {
			return err
		}
		pkt := make([]byte, n)
		copy(pkt, buf[:n])
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
	_, err := e.conn.WriteToUDP(b, addr)
	return err
}

// handleDatagram mirrors cw_ac_data_network_process + ac_msg_pretreat +
// ac_msg_handle for the no-DTLS configuration the AC100 ships with.
func (e *Engine) handleDatagram(raw []byte, addr *net.UDPAddr) {
	if len(raw) < 16 {
		return
	}
	if capwap.IsDiscoveryRequest(raw) {
		e.handleDiscovery(raw, addr)
		return
	}
	// parsed packet for the session path
	req, err := capwap.ParsePacket(raw)
	if err != nil {
		return
	}
	msgType := req.Control.MsgType
	if debugEngine {
		log.Printf("[ENG] recv msg=%d seq=%d from %s", msgType, req.Control.SeqNum, addr)
	}
	s := e.sessionFor(addr)

	if s == nil {
		// cw_ac_data_network_process: only join requests create sessions
		// (capwap_dtls_enable_switch == 0 path).
		if msgType != MsgJoin {
			return
		}
		if e.MaxSessions > 0 && len(e.sessions) >= e.MaxSessions {
			return // capwap_ac_session_exceed_max_num: "just ignore it"
		}
		s = newSession(addr, e.acData)
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
		s.send = func(x *Session, b []byte) error { return e.sendTo(x.Addr, b) }
		s.RetransInterval = e.RetransIntervalMs
		s.RetransMax = e.RetransMax
		// cw_fsm_ac_process_event(session, 8) — DTLS established (direct path)
		if err := s.processEvent(&Event{ID: EventDTLSEstab}); err != nil {
			log.Printf("fsm: %v", err)
		}
		if ap, err := ParseAPEntry(req); err == nil {
			s.apEntry = ap
			s.SetAPIdentity(0, ap.MAC)
			// The binary creates the AP entry inside the join listener
			// (_apmngr_try_create_ap_entry_by_template_or_db), not at RUN.
			if e.apStore != nil {
				if err := e.apStore.UpsertAP(ap); err != nil {
					log.Printf("apmngr store: %v", err)
				}
			}
			if e.OnAttach != nil {
				e.OnAttach(s, ap)
			}
		}
		e.mu.Lock()
		e.sessions[addr.String()] = s
		e.mu.Unlock()
	}

	e.handleSessionPacket(s, req, raw)
}

// handleSessionPacket mirrors ac_msg_pretreat + ac_msg_handle.
func (e *Engine) handleSessionPacket(s *Session, req *capwap.ParsedPacket, raw []byte) {
	if debugEngine {
		log.Printf("[ENG] session pkt msg=%d seq=%d state=%s", req.Control.MsgType, req.Control.SeqNum, StateNames[s.State])
	}
	s.mu.Lock()
	defer s.mu.Unlock()

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
			s.mu.Unlock()
			e.sendTo(s.Addr, rsp)
			s.mu.Lock()
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
		if debugEngine {
			log.Printf("[ENG] sending rsp len=%d elements=%d", len(out), len(rsp.Elements))
		}
		if err := e.sendTo(s.Addr, out); err != nil {
			if debugEngine {
				log.Printf("[ENG] send err: %v", err)
			}
			return
		}
		s.NoteSeq(seq, out)
		_ = s.recvResult(msgType, ok)
		return
	}

	// RESPONSE message (even type): dispatch to handlers, then FSM result.
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
	if cur, ok := e.sessions[s.Addr.String()]; ok && cur == s {
		delete(e.sessions, s.Addr.String())
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
