package cweng

import (
	"encoding/binary"
	"time"
	"uacgo/capwap"
)

// Callbacks run with the session locked and must not call Engine methods.
// Configure returns only policy for this authenticated AP. Authorize must
// explicitly permit the candidate; a discovery or a transport ACK is no grant.
func (e *Engine) RegisterMeshControl(configure func(APStatus) []capwap.Element, authorize func(string, time.Time, string, uint8) bool) {
	e.meshChildAuthorize = authorize
	e.Register(5, 130, "mesh_configuration", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		if configure != nil && ctx.Session.apEntry != nil && ctx.Session.apEntry.HasCapability(44) {
			rsp.Elements = append(rsp.Elements, configure(APStatus{ID: sessionID(ctx.Session), Model: ctx.Session.apEntry.Model, HardwareVersion: ctx.Session.apEntry.HardwareVersion, GeneralCapabilities: ctx.Session.apEntry.GeneralCapabilities, SubCapabilities: ctx.Session.apEntry.SubCapabilities})...)
		}
		return true
	})
	e.Register(9, 95, "mesh_pair_query", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		if ctx.Session.apEntry == nil || !ctx.Session.apEntry.HasCapability(44) {
			return true
		}
		privateElements(req, func(typ uint16, b []byte) {
			if typ != 0x76 {
				return
			}
			rows, err := capwap.ParseVendorList(b)
			if err != nil {
				return
			}
			for _, r := range rows {
				if r.Type != 12 || len(r.Value) != 7 || r.Value[0]&1 != 0 || meshMAC(r.Value[:6]) == "00:00:00:00:00:00" {
					continue
				}
				s := ctx.Session
				permit := authorize != nil && authorize(sessionID(s), s.Created, meshMAC(r.Value[:6]), r.Value[6])
				// The original sends a 60-second temporary admission to the parent before
				// answering permission. Never interrupt a tracked configuration request.
				if permit {
					seq, available := s.reserveMeshTemporarySequence()
					permit = available
					if permit {
						tmp := binary.BigEndian.AppendUint16(nil, 1)
						tmp = append(tmp, r.Value[:6]...)
						tmp = binary.BigEndian.AppendUint32(tmp, 60)
						p, _ := capwap.NewParsedPacket(7)
						p.Control.SeqNum = seq
						p.Header.Rid = 1
						p.Elements = []capwap.Element{meshControlElement([]capwap.VendorRecord{{Type: 20, Value: tmp}})}
						permit = e.sendSession(s, p.Assemble()) == nil
					}
				}
				result := append([]byte{}, r.Value[:6]...)
				code := uint32(1)
				if permit {
					code = 0
				}
				result = binary.BigEndian.AppendUint32(result, code)
				rsp.Elements = append(rsp.Elements, meshControlElement([]capwap.VendorRecord{{Type: 13, Value: result}}))
			}
		})
		return true
	})
}
func meshControlElement(rows []capwap.VendorRecord) capwap.Element {
	return capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x76, Value: capwap.AssembleVendorList(rows)}})}
}

// Called with the logical AP locked; serialize temporary admissions against
// every tracked command on the shared CAP transport.
func (s *Session) reserveMeshTemporarySequence() (uint8, bool) {
	root := s.transportRoot()
	if root != s {
		root.mu.Lock()
		defer root.mu.Unlock()
	}
	if root.dead || len(root.commandGate) > 0 || len(root.pending) > 0 || len(s.pending) > 0 {
		return 0, false
	}
	root.OutSeq++
	if root.OutSeq == 0 {
		root.OutSeq = 1
	}
	s.OutSeq = root.OutSeq
	return s.OutSeq, true
}
