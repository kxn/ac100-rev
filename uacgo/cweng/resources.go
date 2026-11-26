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
func (e *Engine) sessionLimit() int {
	if r := e.resources.Load(); r != nil {
		return r.sessions
	}
	return e.MaxSessions
}
func (e *Engine) queueLimit() int {
	if r := e.resources.Load(); r != nil {
		return r.queue
	}
	return 0
}
func (e *Engine) canAddSession() bool {
	e.mu.Lock()
	n := len(e.sessions)
	e.mu.Unlock()
	limit := e.sessionLimit()
	return limit <= 0 || n < limit
}
