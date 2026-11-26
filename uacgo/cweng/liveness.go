package cweng

import (
	"context"
	"fmt"
)

// SetLiveness is used only after the AP acknowledged its CW Timers/private05
// configuration; the AC watchdog must track the newly advertised cadence.
func (e *Engine) SetLiveness(ctx context.Context, id string, seconds *uint8, misses *uint32) error {
	s := e.findAP(id)
	if s == nil {
		return fmt.Errorf("AP offline")
	}
	s.mu.Lock()
	defer s.mu.Unlock()
	if s.dead {
		return fmt.Errorf("AP session closed")
	}
	if ref, ok := ctx.Value(sessionContextKey{}).(sessionReference); ok && !s.Created.Equal(ref.connected) {
		return fmt.Errorf("AP session changed")
	}
	if seconds != nil {
		s.EchoInterval = int(*seconds)
	}
	if misses != nil {
		s.EchoMaxMisses = int(*misses)
	}
	s.EchoWatchdog = 0
	s.setTimer(TimerEchoInterval)
	return nil
}
