package cweng

import (
	"encoding/binary"
	"sync"
	"time"

	"uacgo/capwap"
)

// LED element group (apmngr LED management).
//
// Evidence:
//   - priv 0x6f "ap led mode control" (min=max=4): plain BE32
//     (cw_priv_ap_led_mode_ctrl_assemble @0x5a4fcc / parse @0x5a5108).
//     Sender path: apmngr_pkt_config_update_request_pkt_send @0x5590c0 —
//     entry flags bit 0x400 → envelope priv 0x6f with value = 1 when the
//     entry's led-mode byte (entry+0x130) is 0, else 3
//     (_apmngr_pkt_led_mode_encap).
//   - priv 0x38 "ap led status" (min=max=4): plain BE32
//     (cw_priv_ap_led_status_assemble @0x5a55c4; dump prints "closed"/"open").
//   - priv 0x39 "ap led op": u32 0/1 (SendLED, apmngr_pkt_led_pkt_send).
//   - LED timer plans are executed AC-side (ApEntryCfg led_timer_enable /
//     led_close_date/led_close_time / led_open_date/led_open_time columns);
//     the AC schedules the 0x39 on/off sends itself.

// SendLEDMode mirrors the 0x6f path: mode 0 → value 1, otherwise 3.
func (e *Engine) SendLEDMode(s *Session, mode uint8) error {
	v := uint32(3)
	if mode == 0 {
		v = 1
	}
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0x6f, Value: encodeU32(v)})
}

// ParseLEDMode decodes a 0x6f value.
func ParseLEDMode(v []byte) (uint32, error) {
	if len(v) != 4 {
		return 0, capwap.ErrShortPacket
	}
	return binary.BigEndian.Uint32(v), nil
}

// ParseLEDStatus decodes a 0x38 value (0 = closed, 1 = open per the dump
// strings).
func ParseLEDStatus(v []byte) (uint32, error) {
	if len(v) != 4 {
		return 0, capwap.ErrShortPacket
	}
	return binary.BigEndian.Uint32(v), nil
}

// LEDPlan is the AC-side LED schedule for one session (ApEntryCfg columns
// led_timer_enable / led_close_* / led_open_*). Times are "HH:MM".
type LEDPlan struct {
	Enable    bool
	CloseTime string
	OpenTime  string
}

// LEDScheduler executes LED plans by firing SendLED at the configured wall
// clock times (the vendor's AC-side timer behaviour).
type LEDScheduler struct {
	mu      sync.Mutex
	stop    map[*Session]chan struct{}
	entries map[[6]byte]LEDPlan
}

// NewLEDScheduler creates the scheduler.
func NewLEDScheduler() *LEDScheduler {
	return &LEDScheduler{
		stop:    make(map[*Session]chan struct{}),
		entries: make(map[[6]byte]LEDPlan),
	}
}

// Apply installs (or clears) the plan for a session and restarts its timers.
// now returns the current local time (injectable for tests).
func (ls *LEDScheduler) Apply(s *Session, plan LEDPlan, now func() time.Time, send func(on bool)) {
	ls.mu.Lock()
	defer ls.mu.Unlock()
	ls.entries[s.macKey()] = plan
	if ch, ok := ls.stop[s]; ok {
		close(ch)
	}
	ch := make(chan struct{})
	ls.stop[s] = ch
	if !plan.Enable {
		return
	}
	go func() {
		for {
			cur := now()
			next, on := nextLEDTrigger(plan, cur)
			timer := time.NewTimer(time.Until(next))
			select {
			case <-ch:
				timer.Stop()
				return
			case <-timer.C:
				send(on)
			}
		}
	}()
}

// nextLEDTrigger returns the next trigger instant and whether it is an
// "open" (true) or "close" (false) event.
func nextLEDTrigger(p LEDPlan, now time.Time) (time.Time, bool) {
	closeT := parseHM(p.CloseTime, now)
	openT := parseHM(p.OpenTime, now)
	candidates := []struct {
		t  time.Time
		on bool
	}{{closeT, false}, {openT, true}}
	var best time.Time
	var bestOn bool
	first := true
	for _, c := range candidates {
		if !c.t.After(now) { // at exactly the trigger time, the next is the other one
			c.t = c.t.AddDate(0, 0, 1)
		}
		if first || c.t.Before(best) {
			best, bestOn, first = c.t, c.on, false
		}
	}
	return best, bestOn
}

// parseHM parses "HH:MM" into today's clock.
func parseHM(s string, now time.Time) time.Time {
	var h, m int
	if len(s) >= 4 {
		h = int(s[0]-'0')*10 + int(s[1]-'0')
		m = int(s[3]-'0')*10 + int(s[4]-'0')
	}
	return time.Date(now.Year(), now.Month(), now.Day(), h, m, 0, 0, now.Location())
}

// macKey identifies the session (its MAC is not stored on Session; use addr).
func (s *Session) macKey() [6]byte {
	var k [6]byte
	copy(k[:], s.Addr.IP.To4())
	return k
}

// SendBluetoothConfig mirrors the bit-0x2000 path of
// apmngr_pkt_config_update_request_pkt_send @0x5590c0: envelope priv 0xa7
// carrying BE32(entry+0x131 byte) — the value word is the byte in the high
// position (local_98 = bVar7 << 24).
func (e *Engine) SendBluetoothConfig(s *Session, enableByte byte) error {
	v := uint32(enableByte) << 24
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0xa7, Value: encodeU32(v)})
}
