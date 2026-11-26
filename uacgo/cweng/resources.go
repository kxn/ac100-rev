package cweng

// SetResourceLimits updates Go admission/backpressure limits without changing
// protocol timers or firmware policy. Existing sessions/queued commands stay.
func (e *Engine) SetResourceLimits(sessions, queue int) {
	e.resources.Store(&engineResources{sessions: sessions, queue: queue})
	if e.legacyDTLS != nil {
		e.legacyDTLS.SetMaxPeers(sessions + 8)
	}
}

type engineResources struct{ sessions, queue int }

func (e *Engine) MaxAPSessions() int { return e.sessionLimit() }
func (e *Engine) sessionLimit() int  { return e.resources.Load().sessions }
func (e *Engine) queueLimit() int    { return e.resources.Load().queue }

// The final admission and insert share the session-table lock for both UDP
// roots and Mesh children. Lowering a limit keeps existing sessions alive.
func (e *Engine) registerSession(s *Session) bool {
	e.mu.Lock()
	defer e.mu.Unlock()
	key := s.sessionKey()
	if e.sessions[key] != nil || len(e.sessions) >= e.sessionLimit() {
		return false
	}
	e.sessions[key] = s
	return true
}
