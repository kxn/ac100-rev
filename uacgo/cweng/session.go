package cweng

import (
	"fmt"
	"net"
	"sync"
	"sync/atomic"
	"time"

	"uacgo/capwap"
)

// Control message ids needed by the engine (values verified against the
// binary: capwap control header parse range 1..26; names from cw_control_msg_name).
const (
	MsgDiscovery        = 1
	MsgJoin             = 3
	MsgConfigStatus     = 5
	MsgConfigUpdateRsp  = 8
	MsgWTPEvent         = 9
	MsgChangeStateEvent = 11
	MsgEcho             = 13
	MsgImageDataRequest = 15
	MsgReset            = 17
)

// Event is the FSM event record (binary passes [id, arg] pairs;
// ac_msg_handle fires [3|2, msg_type], ac_msg_pretreat fires [1, msg_type],
// timers fire [5, timer_id]).
type Event struct {
	ID      uint32
	MsgType uint32 // arg for recv events
	Timer   uint32 // arg for timeout events
}

// AcDataCounters mirror the ac_data fields the FSM touches
// (ac_data+0x5c join count, +0x60 run count, +0x68 join fail, +0x6c csp fail —
// cw_fsm_ac_join_wait/finish/configure increment sites).
type AcDataCounters struct {
	JoinCount      atomic.Uint32 // ac_data+0x5c
	RunCount       atomic.Uint32 // ac_data+0x60
	JoinFailCount  atomic.Uint32 // ac_data+0x68
	CSPFailCount   atomic.Uint32 // ac_data+0x6c
	EchoTimeout    atomic.Uint32 // ac_data+0x74 (cw_fsm_ac_run RUN ECHO exhaustion)
	RetransTimeout atomic.Uint32 // ac_data+0x78 (RUN retransmit exhaustion)
}

// Session is the per-AP control session. Layout mirrors the binary's session
// struct fields the FSM engine reads/writes:
//
//	addr / acData / State(+0xb4) / EchoInterval(+0xd0) /
//	LastReqSeq(+0xa6) / LastRspBuf(+0xd4) / EchoWatchdog(+0xc8)
type Session struct {
	meshParent       *Session
	meshReport       *MeshReport
	fragmentID       uint16
	bluetoothServers map[uint8]BluetoothServerStatus
	channelScan      *ChannelScanReport
	arpScan          *ARPScanReport
	rrmReports       map[uint8]RRMReport
	rpc              map[uint32]chan []byte
	rpcSeq           uint32
	mu               sync.Mutex

	acData *AcDataCounters

	Addr         *net.UDPAddr // peer udp addr (binary keeps sockaddr + ifindex)
	State        uint32
	EchoInterval int // seconds; default 30 (l_timeouts[9] @0x74cfac)

	OutSeq        uint8 // session+0xa4, AC-initiated request seq counter
	EchoMaxMisses int   // session+0xcc, default 5 (cw_fsm_ac_setup @0x59ce08)

	RetransInterval int // profile default_retransmit_time (session create)
	RetransMax      int // profile retransmit_max_retries

	rspRetries int
	rspTimer   *time.Timer

	LastReqSeq          int    // session+0xa6, -1 = none
	LastRspBuf          []byte // session+0xd4, resend on duplicate request
	EchoWatchdog        uint32 // session+0xc8
	LastSeen            time.Time
	Created             time.Time
	transportGeneration [32]byte
	radioStatus         map[uint8]RadioStatus
	telemetry           *WirelessTelemetry
	reports             map[uint16]APReport
	reportedSSIDs       []ReportedSSID

	pending     map[uint8]*pendingCommand
	commandGate chan struct{}
	apEntry     *APEntry // parsed join identity (for the apmngr store)

	// timers: id → deadline
	timers map[uint]*time.Timer
	dead   bool
	closed chan struct{}

	// hooks (set by engine)
	onTeardown   func(*Session)
	onEnterRun   func(*Session) error
	onEnterReset func(*Session) error
	onDelete     func(*Session)
	send         func(*Session, []byte) error
}

func newSession(addr *net.UDPAddr, acData *AcDataCounters) *Session {
	return &Session{
		acData:        acData,
		Addr:          addr,
		Created:       time.Now(),
		State:         StateIDLE, // cw_fsm_ac_setup @0x59ce08: state 1
		EchoInterval:  TimerTimeouts[TimerEchoInterval],
		LastReqSeq:    -1,
		EchoMaxMisses: 5,
		timers:        make(map[uint]*time.Timer),
		closed:        make(chan struct{}),
	}
}

func (s *Session) setState(st uint32) { s.State = st }

// setTimer mirrors cw_fsm_ac_timer_set @0x59cb34: restart the given FSM timer
// with its default timeout (session-sourced for ECHO_INTERVAL).
func (s *Session) setTimer(timer uint) {
	s.clearTimer(timer)
	d, ok := s.Timeout(timer)
	if !ok || d <= 0 {
		return
	}
	id := timer
	s.timers[timer] = time.AfterFunc(time.Duration(d)*time.Second, func() {
		s.mu.Lock()
		defer s.mu.Unlock()
		if s.dead {
			return
		}
		delete(s.timers, id)
		_ = s.processEvent(&Event{ID: EventTimeout, Timer: uint32(id)})
	})
}

func (s *Session) clearTimer(timer uint) {
	if t, ok := s.timers[timer]; ok {
		t.Stop()
		delete(s.timers, timer)
	}
}

// clearTimers mirrors cw_fsm_ac_timer_clear @0x59ca38.
func (s *Session) clearTimers() {
	for id := range s.timers {
		s.clearTimer(id)
	}
}

// teardown mirrors cw_fsm_ac_teardown: DTLS teardown notification + state →
// DTLS_TEARDOWN (id 5); with DTLS disabled the session is simply torn down.
func (s *Session) teardown() {
	if s.dead {
		return
	}
	s.clearTimers()
	s.dead = true
	close(s.closed)
	s.cancelRspRetransmit()
	if s.onTeardown != nil {
		s.onTeardown(s)
	}
}

// enterRun fires ent event 1 (session entered RUN) to the registered
// listeners (multi_link / apmngr / uac_nms_report registered ent 1 handlers).
func (s *Session) enterRun() error {
	if s.onEnterRun != nil {
		return s.onEnterRun(s)
	}
	return nil
}

// enterReset fires ent events 0/2 (reset) listeners (apmngr enter_reset cb).
func (s *Session) enterReset() error {
	if s.onEnterReset != nil {
		return s.onEnterReset(s)
	}
	return nil
}

// delete removes the session from the engine's session table.
func (s *Session) delete() {
	if s.onDelete != nil {
		s.onDelete(s)
	}
}

// gate mirrors the ac_msg_pretreat FSM gate (event 1 RECV_PKT_CHECK with the
// msg type as argument) — returns error when the state rejects the message.
func (s *Session) gate(msgType uint32) error {
	return s.processEvent(&Event{ID: EventRecvPktCheck, MsgType: msgType})
}

// recvResult fires CHECK_PASSED / CHECK_FAILED with the request msg type
// (ac_msg_handle: local_21c = 3|2, local_218 = msg type).
func (s *Session) recvResult(msgType uint32, ok bool) error {
	id := uint32(EventCheckFailed)
	if ok {
		id = EventCheckPassed
	}
	return s.processEvent(&Event{ID: id, MsgType: msgType})
}

// NoteSeq mirrors ac_msg_handle bookkeeping: remember the request seq and the
// assembled response, then arm response retransmission
// (cw_ac_retransmit_timer_start after the response send).
func (s *Session) NoteSeq(reqSeq uint8, rsp []byte) {
	s.LastReqSeq = int(reqSeq)
	s.LastRspBuf = rsp
	s.armRspRetransmit(rsp)
}

// armRspRetransmit re-sends the stored response until the AP's next request
// arrives (a new outgoing response cancels the pending one — the retransmit
// queue flush in ac_packet_buf_send @0x590ed4) or retries are exhausted.
// Backoff doubles each fire, capped at 60 s (cw_ac_retransmit_timeout_handler
// @0x591828; exact cap formula to re-check there when tuning).
func (s *Session) armRspRetransmit(rsp []byte) {
	s.cancelRspRetransmit()
	if s.RetransInterval <= 0 || s.RetransMax <= 0 {
		return
	}
	s.rspRetries = 0
	buf := append([]byte(nil), rsp...)
	interval := s.RetransInterval
	s.rspTimer = time.AfterFunc(time.Duration(interval)*time.Millisecond, func() {
		s.mu.Lock()
		defer s.mu.Unlock()
		if s.dead {
			return
		}
		if s.rspRetries >= s.RetransMax {
			s.acData.RetransTimeout.Add(1)
			s.rspTimer = nil
			return
		}
		s.rspRetries++
		if s.send != nil {
			_ = s.send(s, buf)
		}
		next := interval * 2
		if next > 60000 {
			next = 60000
		}
		interval = next
		s.rspTimer = time.AfterFunc(time.Duration(interval)*time.Millisecond, func() {
			// re-fire through the same closure body
			fireRspRetransmit(s, buf, &interval)
		})
	})
}

func fireRspRetransmit(s *Session, buf []byte, interval *int) {
	s.mu.Lock()
	defer s.mu.Unlock()
	if s.dead {
		return
	}
	if s.rspRetries >= s.RetransMax {
		s.acData.RetransTimeout.Add(1)
		s.rspTimer = nil
		return
	}
	s.rspRetries++
	if s.send != nil {
		_ = s.send(s, buf)
	}
	next := *interval * 2
	if next > 60000 {
		next = 60000
	}
	*interval = next
	s.rspTimer = time.AfterFunc(time.Duration(*interval)*time.Millisecond, func() {
		fireRspRetransmit(s, buf, interval)
	})
}

// cancelRspRetransmit stops any pending response retransmission.
func (s *Session) cancelRspRetransmit() {
	if s.rspTimer != nil {
		s.rspTimer.Stop()
		s.rspTimer = nil
	}
}

// String for logs.
func (s *Session) String() string {
	return fmt.Sprintf("{%s state=%s}", s.Addr, StateNames[s.State])
}

// VerifySeqWindow mirrors ac_msg_pretreat's "illegal request sequence" rule:
// a request whose seq trails LastReqSeq by < 0x80 (or jumps ahead by > 0x80)
// is dropped. LastReqSeq == -1 (none yet) accepts everything.
func (s *Session) VerifySeqWindow(seq uint8) bool {
	if s.LastReqSeq == -1 {
		return true
	}
	last := s.LastReqSeq
	if int(last) < int(seq) && 0x80 < int(seq)-last {
		return false
	}
	if int(seq) < int(last) && int(last)-int(seq) < 0x80 {
		return false
	}
	return true
}

// DuplicateReq mirrors ac_msg_handle's same-seq retransmission handling:
// a request with seq == LastReqSeq and a stored response is answered by
// re-sending that response (ac_packet_buf_send).
func (s *Session) DuplicateReq(seq uint8) bool {
	return s.LastReqSeq != -1 && int(seq) == s.LastReqSeq && s.LastRspBuf != nil
}

// ParseRequest is a small helper the engine uses on raw datagrams.
func ParseRequest(b []byte) (*capwap.ParsedPacket, error) {
	return capwap.ParsePacket(b)
}
