// Package cweng implements the AC-side CAPWAP engine (session FSM, timers,
// retransmission, dispatch) with the exact behaviour extracted from the
// TL-AC100 `uac` binary (re/notes/00-architecture.md §6-7, registry.tsv).
package cweng

import "fmt"

// FSM states — PTR_s_START_006e4510 name table, cw_fsm_get_state_name @0x59c800.
const (
	StateSTART          = 0
	StateIDLE           = 1
	StateDISCOVERY      = 2
	StateSULKING        = 3
	StateDTLSSetup      = 4
	StateDTLSTeardown   = 5
	StateJoinWait       = 6
	StateJoinFinish     = 7
	StateImageData      = 8
	StateConfigure      = 9
	StateReset          = 10
	StateDateCheck      = 11
	StateDateCheckToRun = 12
	StateRun            = 13
	StateDead           = 14
)

// StateNames indexed by state id (binary name table).
var StateNames = [...]string{
	"START", "IDLE", "DISCOVERY", "SULKING", "DTLS_SETUP", "DTLS_TEARDOWN",
	"JOIN_WAIT", "JOIN_FINISH", "IMAGE_DATA", "CONFIGURE", "RESET",
	"DATE_CHECK", "DATE_CHECK_TO_RUN", "RUN", "DEAD",
}

// FSM events — name table @0x6e4ab0.
const (
	EventNone          = 0
	EventRecvPktCheck  = 1
	EventCheckFailed   = 2
	EventCheckPassed   = 3
	EventImageFinished = 4
	EventTimeout       = 5
	EventOperation     = 6
	EventDTLSSetup     = 7
	EventDTLSEstab     = 8
	EventDTLSTeardown  = 9
	EventInitialized   = 10
	EventSendPktCheck  = 11
	EventSendPkt       = 12
)

var EventNames = [...]string{
	"-EVENT_NONE-", "RECV_PKT_CHECK", "RECV_PKT_CHECK_FAILED", "RECV_PKT_CHECK_PASSED",
	"IMAGE_DATA_TRANSFER_FINISHED", "TIMEOUT", "OPERATION", "DTLS_SETUP_NOTIFY",
	"DTLS_ESTABLISHED_NOTIFY", "DTLS_TEARDOWN_NOTIFY", "INITIALIZED_NOTIFY",
	"SEND_PKT_TYPE_CHECK", "SEND_PKT", "-EVENT_MAX-",
}

// FSM timers — name table @0x6e4ae8; default timeouts l_timeouts @0x74cfac.
const (
	TimerNone              = 0
	TimerWaitDTLS          = 1
	TimerWaitJoin          = 2
	TimerImageDataXmit     = 3
	TimerChangeStatePend   = 4
	TimerDataCheck         = 5
	TimerDTLSSessionDelete = 6
	TimerDiscoveryInterval = 7
	TimerSilentInterval    = 8
	TimerEchoInterval      = 9
	TimerRetransmit        = 10
)

// TimerTimeouts[id] = l_timeouts @0x74cfac (seconds).
var TimerTimeouts = [...]int{
	0, 60, 60, 60, 30, 30, 10, 5, 30, 30, // 0..9
}

// Timeout returns the default timeout for a timer id
// (cw_fsm_ac_get_timer_timeout @0x59c9bc; timer 9 uses the session value).
func (s *Session) Timeout(timer uint) (int, bool) {
	if timer >= 12 {
		return -1, false
	}
	if timer == 9 {
		if s.EchoInterval > 0 {
			return s.EchoInterval, true
		}
		return -1, false
	}
	switch timer {
	case 1, 2, 5, 3, 4:
		return TimerTimeouts[timer], true
	}
	return 0, true // timers 6..8 have entries but are handled elsewhere
}

// processEvent mirrors cw_fsm_ac_process_event @0x59d3e8:
// dispatch by state to the state handler table (l_event_processes @0x74cf70).
// States without handlers (START/DISCOVERY/SULKING/DATE_CHECK_TO_RUN/DEAD)
// reject every event.
func (s *Session) processEvent(ev *Event) error {
	if s.State >= 0xf {
		return fmt.Errorf("invalid state %d", s.State)
	}
	switch s.State {
	case StateIDLE:
		return s.fsmIdle(ev)
	case StateDTLSSetup:
		return s.fsmDTLSSetup(ev)
	case StateDTLSTeardown:
		return s.fsmDTLSTeardown(ev)
	case StateJoinWait:
		return s.fsmJoinWait(ev)
	case StateJoinFinish:
		return s.fsmJoinFinish(ev)
	case StateImageData:
		return s.fsmImageData(ev)
	case StateConfigure:
		return s.fsmConfigure(ev)
	case StateReset:
		return s.fsmReset(ev)
	case StateDateCheck:
		return s.fsmDataCheck(ev)
	case StateRun:
		return s.fsmRun(ev)
	}
	return fmt.Errorf("state %s has no process-func", StateNames[s.State])
}

// fsmIdle mirrors cw_fsm_ac_idle @0x59e7d0:
//
//	event 7 (DTLS_SETUP_NOTIFY)    → timer WAIT_DTLS, → DTLS_SETUP
//	event 8 (DTLS_ESTABLISHED_NOTIFY, also used directly when DTLS off)
//	                               → timer WAIT_JOIN, → JOIN_WAIT
func (s *Session) fsmIdle(ev *Event) error {
	switch ev.ID {
	case EventDTLSSetup:
		s.setTimer(TimerWaitDTLS)
		s.setState(StateDTLSSetup)
	case EventDTLSEstab:
		s.setTimer(TimerWaitJoin)
		s.setState(StateJoinWait)
	default:
		return fmt.Errorf("IDLE: invalid event %s", EventNames[ev.ID])
	}
	return nil
}

// fsmDTLSSetup mirrors cw_fsm_ac_dtls_setup @0x59e330.
func (s *Session) fsmDTLSSetup(ev *Event) error {
	switch ev.ID {
	case EventDTLSEstab:
		s.setTimer(TimerWaitJoin)
		s.setState(StateJoinWait)
	case EventTimeout:
		if ev.Timer == TimerWaitDTLS {
			s.clearTimers()
			s.teardown()
			return nil
		}
		return fmt.Errorf("DTLS_SETUP: invalid timeout timer %d", ev.Timer)
	default:
		return fmt.Errorf("DTLS_SETUP: invalid event %d", ev.ID)
	}
	return nil
}

// fsmDTLSTeardown mirrors cw_fsm_ac_dtls_teardown @0x59e590.
func (s *Session) fsmDTLSTeardown(ev *Event) error {
	switch ev.ID {
	case EventDTLSTeardown:
		s.setState(StateIDLE)
	case EventTimeout:
		if ev.Timer == TimerDTLSSessionDelete {
			s.clearTimers()
			s.teardown()
			return nil
		}
		return fmt.Errorf("DTLS_TEARDOWN: invalid timeout timer %d", ev.Timer)
	default:
		return fmt.Errorf("DTLS_TEARDOWN: invalid event %d", ev.ID)
	}
	return nil
}

// fsmJoinWaitRecv mirrors cw_fsm_ac_join_wait_recv_pkt @0x59f850:
//
//	CHECK_PASSED + JOIN REQ(3)  → JOIN_FINISH, acData.JoinCount++
//	CHECK_PASSED + anything else → teardown
func (s *Session) fsmJoinWaitRecv(ev *Event) error {
	if ev.ID == EventCheckPassed && ev.MsgType == MsgJoin {
		s.setState(StateJoinFinish)
		s.acData.JoinCount++
		return nil
	}
	s.teardown()
	return nil
}

// fsmJoinFinishRecv mirrors cw_fsm_ac_join_finish_recv_pkt @0x59f0a0:
//
//	CHECK_PASSED + Image Data Req(15) → ECHO timer, → IMAGE_DATA
//	CHECK_PASSED + Config Status Req(5) → CHANGE_STATE_PENDING timer, → CONFIGURE
//	CHECK_PASSED + JOIN REQ(3) or type 0 → stay
//	CHECK_FAILED → teardown
func (s *Session) fsmJoinFinishRecv(ev *Event) error {
	switch {
	case ev.ID == EventCheckFailed:
		s.teardown()
		return nil
	case ev.ID == EventCheckPassed && ev.MsgType == MsgImageDataRequest:
		s.setTimer(TimerEchoInterval)
		s.setState(StateImageData)
	case ev.ID == EventCheckPassed && ev.MsgType == MsgConfigStatus:
		s.setTimer(TimerChangeStatePend)
		s.setState(StateConfigure)
	case ev.ID == EventCheckPassed && (ev.MsgType == MsgJoin || ev.MsgType == 0):
		// stay in JOIN_FINISH
	default:
		return fmt.Errorf("JOIN_FINISH: event %d msg %d unexpected", ev.ID, ev.MsgType)
	}
	return nil
}

// fsmConfigureRecv mirrors cw_fsm_ac_configure_recv_pkt @0x59d6e0:
//
//	non-PASSED event → clear, enter_reset, delete
//	PASSED + Change State Event Req(11) → ECHO timer, enter_run (fires ent 1),
//	    acData.RunCount++, → RUN
//	PASSED + Config Status Req(5) → stay
func (s *Session) fsmConfigureRecv(ev *Event) error {
	if ev.ID != EventCheckPassed {
		s.clearTimers()
		s.enterReset()
		s.delete()
		return nil
	}
	switch ev.MsgType {
	case MsgChangeStateEvent:
		s.setTimer(TimerEchoInterval)
		s.enterRun()
		s.acData.RunCount++
		s.setState(StateRun)
	case MsgConfigStatus:
		// stay in CONFIGURE
	default:
		return fmt.Errorf("CONFIGURE: unexpected msg %d", ev.MsgType)
	}
	return nil
}

// event 5 TIMEOUT timer WAIT_JOIN → ac_data.JoinFail++ teardown.
// events 1/2/3 (recv gate / failed / passed) handled by recv helpers.
func (s *Session) fsmJoinWait(ev *Event) error {
	switch ev.ID {
	case EventTimeout:
		if ev.Timer == TimerWaitJoin {
			s.acData.JoinFailCount++
			s.clearTimers()
			s.teardown()
			return nil
		}
		return fmt.Errorf("JOIN_WAIT: invalid timeout timer %d", ev.Timer)
	case EventRecvPktCheck:
		// join_wait_recv_pkt_check @0x59f6e0: accepts JOIN(3) and 0
		if ev.MsgType == 3 || ev.MsgType == 0 {
			return nil
		}
		return fmt.Errorf("JOIN_WAIT: check rejects msg %d", ev.MsgType)
	case EventCheckFailed, EventCheckPassed:
		return s.fsmJoinWaitRecv(ev)
	default:
		return fmt.Errorf("JOIN_WAIT: invalid event %d", ev.ID)
	}
}

// fsmJoinFinish mirrors cw_fsm_ac_join_finish @0x59f448 (same shape as JOIN_WAIT
// but in the JOIN_FINISH state, WAIT_JOIN timeout → teardown as well).
func (s *Session) fsmJoinFinish(ev *Event) error {
	switch ev.ID {
	case EventTimeout:
		if ev.Timer == TimerWaitJoin {
			s.acData.JoinFailCount++
			s.clearTimers()
			s.teardown()
			return nil
		}
		return fmt.Errorf("JOIN_FINISH: invalid timeout timer %d", ev.Timer)
	case EventRecvPktCheck:
		// join_finish_recv_pkt_check @0x59f328: accepts Image Req(15), Cfg Status(5)
		if ev.MsgType == MsgImageDataRequest || ev.MsgType == MsgConfigStatus {
			return nil
		}
		return fmt.Errorf("JOIN_FINISH: check rejects msg %d", ev.MsgType)
	case EventCheckFailed, EventCheckPassed:
		return s.fsmJoinFinishRecv(ev)
	default:
		return fmt.Errorf("JOIN_FINISH: invalid event %d", ev.ID)
	}
}

// fsmConfigure mirrors cw_fsm_ac_configure @0x59da30:
//
//	TIMEOUT (CHANGE_STATE_PENDING) → ac_data.CSPFail++, enter_reset, delete.
func (s *Session) fsmConfigure(ev *Event) error {
	switch ev.ID {
	case EventTimeout:
		if ev.Timer == TimerChangeStatePend {
			s.acData.CSPFailCount++
			s.clearTimers()
			s.enterReset()
			s.delete()
			return nil
		}
		return fmt.Errorf("CONFIGURE: invalid timeout timer %d", ev.Timer)
	case EventRecvPktCheck:
		// configure_recv_pkt_check @0x59d918: accepts Change State Event(11)
		if ev.MsgType == MsgChangeStateEvent {
			return nil
		}
		return fmt.Errorf("CONFIGURE: check rejects msg %d", ev.MsgType)
	case EventCheckFailed, EventCheckPassed:
		return s.fsmConfigureRecv(ev)
	default:
		return fmt.Errorf("CONFIGURE: invalid event %d", ev.ID)
	}
}

// fsmImageData mirrors cw_fsm_ac_image_data @0x59edec (gate-only state;
// timeouts of IMAGE_DATA_XMIT drop to error handling — port when upgrade flow
// is implemented; upgrades are not exercised in the attach path).
func (s *Session) fsmImageData(ev *Event) error {
	switch ev.ID {
	case EventRecvPktCheck, EventCheckFailed, EventCheckPassed:
		return nil
	case EventImageFinished:
		return nil
	default:
		return fmt.Errorf("IMAGE_DATA: invalid event %d", ev.ID)
	}
}

// fsmReset mirrors cw_fsm_ac_reset @0x5a014c.
func (s *Session) fsmReset(ev *Event) error {
	switch ev.ID {
	case EventRecvPktCheck, EventCheckFailed, EventCheckPassed:
		return nil
	default:
		return fmt.Errorf("RESET: invalid event %d", ev.ID)
	}
}

// fsmDataCheck mirrors cw_fsm_ac_data_check @0x59e094:
//
//	DATA_CHECK timeout → teardown; recv events forwarded.
func (s *Session) fsmDataCheck(ev *Event) error {
	switch ev.ID {
	case EventTimeout:
		if ev.Timer == TimerDataCheck {
			s.clearTimers()
			s.teardown()
			return nil
		}
		return fmt.Errorf("DATE_CHECK: invalid timeout timer %d", ev.Timer)
	case EventRecvPktCheck, EventCheckFailed, EventCheckPassed:
		return nil
	default:
		return fmt.Errorf("DATE_CHECK: invalid event %d", ev.ID)
	}
}

// fsmRun mirrors cw_fsm_ac_run @0x5a091c + run_recv_pkt @0x5a03e0 +
// run_recv_pkt_check @0x5a07c0:
//
//	gate accepts msg types {13 echo, 9 wtp-event, 8 cfg-upd-rsp, 18 reset-rsp,
//	24, 26, 15/16 image, 0x33dd02, 11 change-state}
//	CHECK_PASSED (no debug: event id 3) → EchoWatchdog=0, restart ECHO timer
//	CHECK_FAILED (event id 2)         → teardown
func (s *Session) fsmRun(ev *Event) error {
	switch ev.ID {
	case EventRecvPktCheck:
		switch ev.MsgType {
		case 0xd, 9, 8, 0x12, 0x18, 0x1a, 0xf, 0x10, 0x33dd02, 0xb:
			return nil
		}
		return fmt.Errorf("RUN: check rejects msg %d", ev.MsgType)
	case EventCheckPassed:
		// run_recv_pkt: any accepted request in RUN resets the echo watchdog
		s.EchoWatchdog = 0
		s.setTimer(TimerEchoInterval)
		return nil
	case EventCheckFailed:
		s.teardown()
		return nil
	case EventTimeout:
		switch ev.Timer {
		case TimerEchoInterval:
			// cw_fsm_ac_run @0x5a091c: misses < EchoMaxMisses → count and
			// re-arm; exhausted → ac_data.EchoTimeout++, clear, teardown.
			if int(s.EchoWatchdog) < s.EchoMaxMisses {
				s.EchoWatchdog++
				s.setTimer(TimerEchoInterval)
				return nil
			}
			s.acData.EchoTimeout++
			s.clearTimers()
			s.teardown()
			return nil
		case TimerRetransmit:
			s.acData.RetransTimeout++
			s.clearTimers()
			s.teardown()
			return nil
		}
		return fmt.Errorf("RUN: unexpected timeout timer %d", ev.Timer)
	default:
		return fmt.Errorf("RUN: invalid event %d", ev.ID)
	}
}
