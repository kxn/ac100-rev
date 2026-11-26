package cweng

import (
	"fmt"
	"time"
	"uacgo/capwap"
)

func (s *Session) sessionKey() string {
	if s.meshParent != nil {
		return s.meshParent.sessionKey() + "/mesh/" + s.apEntry.MAC
	}
	return s.Addr.String()
}
func (s *Session) transportRoot() *Session {
	for s.meshParent != nil {
		s = s.meshParent
	}
	return s
}

// Dispatch before the parent's sequence/FSM processing: public Mesh packets
// carry the child's identity and ordinary inner elements. They must never be
// interpreted as the parent's stations, configuration or command ACKs.
func (e *Engine) handleMeshPublic(parent *Session, req *capwap.ParsedPacket) bool {
	found := false
	privateElements(req, func(typ uint16, b []byte) {
		if typ != 0x75 {
			return
		}
		found = true
		macs, els, err := capwap.ParseMeshPublic(b)
		if err != nil {
			return
		}
		parent.mu.Lock()
		valid := !parent.dead && parent.State == StateRun && parent.apEntry.HasCapability(44) && parent.meshParent == nil
		parentID := sessionID(parent)
		if e.legacyDTLS != nil && parent.transportGeneration != e.legacyDTLS.Generation(parent.Addr.String()) {
			valid = false
		}
		created := parent.Created
		if valid {
			parent.LastSeen = time.Now()
		}
		parent.mu.Unlock()
		if !valid {
			return
		}
		for _, id := range macs {
			if id == parentID {
				continue
			}
			key := parent.sessionKey() + "/mesh/" + id
			e.mu.Lock()
			child := e.sessions[key]
			e.mu.Unlock()
			if e.meshChildAuthorize == nil || !e.meshChildAuthorize(parentID, created, id, 1) {
				if child != nil {
					child.mu.Lock()
					child.teardown()
					child.mu.Unlock()
				}
				continue
			}
			inner := *req
			inner.Elements = els
			// No nested forwarding or wrapper claims can change the authenticated CAP.
			nested := false
			privateElements(&inner, func(t uint16, _ []byte) { nested = nested || t == 0x75 })
			if nested {
				continue
			}
			if child == nil {
				if req.Control.MsgType != MsgJoin {
					continue
				}
				ap, err := ParseAPEntry(&inner)
				if err != nil || ap.MAC != id || ap.MeshParent != "" && ap.MeshParent != parentID {
					continue
				}
				if len(ap.Capabilities) == 0 && e.apdb != nil {
					e.apdb.ResolveCapabilities(ap)
				}
				// A child cannot overwrite a separately authenticated AP identity.
				if existing := e.findAP(id); existing != nil {
					continue
				}
				child = newSession(parent.Addr, e.acData)
				child.meshParent = parent
				child.apEntry = ap
				child.transportGeneration = parent.transportGeneration
				child.onAPState = e.OnAPState
				child.onTeardown = e.removeSession
				child.onDelete = e.removeSession
				child.onEnterRun = func(s *Session) error {
					if e.OnEntRun != nil {
						return e.OnEntRun(s)
					}
					e.reg.fireEnt(1, &Ctx{Session: s})
					return nil
				}
				child.onEnterReset = func(s *Session) error {
					if e.OnEntReset != nil {
						return e.OnEntReset(s)
					}
					e.reg.fireEnt(2, &Ctx{Session: s})
					return nil
				}
				child.send = func(s *Session, b []byte) error { return e.sendSession(s, b) }
				child.RetransInterval = e.RetransIntervalMs
				child.RetransMax = e.RetransMax
				if err := child.processEvent(&Event{ID: EventDTLSEstab}); err != nil {
					continue
				}
				e.mu.Lock()
				if e.MaxSessions > 0 && len(e.sessions) >= e.MaxSessions {
					e.mu.Unlock()
					child.mu.Lock()
					child.teardown()
					child.mu.Unlock()
					continue
				}
				e.sessions[key] = child
				e.mu.Unlock()
				go func(s *Session) {
					select {
					case <-parent.closed:
						s.mu.Lock()
						s.teardown()
						s.mu.Unlock()
					case <-s.closed:
					}
				}(child)
			}
			e.handleSessionPacket(child, &inner, inner.Assemble())
		}
	})
	return found
}
func (e *Engine) sendMeshSession(s *Session, b []byte) error {
	if s.dead {
		return fmt.Errorf("Mesh AP session closed")
	}
	p, err := capwap.ParsePacket(b)
	if err != nil {
		return err
	}
	value, err := capwap.AssembleMeshPublic([]string{s.apEntry.MAC}, p.Elements)
	if err != nil {
		return err
	}
	p.Elements = []capwap.Element{meshControlPublicElement(value)}
	root := s.transportRoot()
	root.mu.Lock()
	defer root.mu.Unlock()
	if root.dead || root.State != StateRun {
		return fmt.Errorf("Mesh parent offline")
	}
	return e.sendSession(root, p.Assemble())
}
func meshControlPublicElement(b []byte) capwap.Element {
	return capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x75, Value: b}})}
}
