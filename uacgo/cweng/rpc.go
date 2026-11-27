package cweng

import (
	"context"
	"encoding/binary"
	"encoding/json"
	"fmt"
	"uacgo/capwap"
)

// RegisterRPCHandlers receives the AP's asynchronous TDCP JSON response. A
// configuration ACK alone does not contain the requested model's values.
func (e *Engine) RegisterRPCHandlers() {
	e.Register(9, 85, "tdcp_json_reply", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		privateElements(req, func(typ uint16, b []byte) {
			if typ != 0x83 || len(b) < 9 {
				return
			}
			n := binary.BigEndian.Uint32(b[4:8])
			if n > 51200 || int(n) != len(b)-9 || !json.Valid(b[9:]) {
				return
			}
			ch := ctx.Session.rpc[binary.BigEndian.Uint32(b)]
			if ch != nil {
				select {
				case ch <- append([]byte{}, b[9:]...):
				default:
				}
			}
		})
		return true
	})
}
func (e *Engine) RequestJSON(ctx context.Context, id string, body json.RawMessage) (response json.RawMessage, resultErr error) {
	defer func() {
		e.Events.Context(ctx, "native_model.completed", "ap_id", id, "request_bytes", len(body), "response_bytes", len(response), "error", errorText(resultErr))
	}()
	if !json.Valid(body) || len(body) > 4096 {
		return nil, fmt.Errorf("invalid AP JSON request")
	}
	s := e.findAP(id)
	if s == nil {
		return nil, fmt.Errorf("AP offline")
	}
	s.mu.Lock()
	if s.rpc == nil {
		s.rpc = map[uint32]chan []byte{}
	}
	if len(s.rpc) >= 8 {
		s.mu.Unlock()
		return nil, fmt.Errorf("too many AP JSON requests")
	}
	s.rpcSeq++
	if s.rpcSeq == 0 {
		s.rpcSeq++
	}
	seq := s.rpcSeq
	e.Events.Context(ctx, "native_model.requested", "ap_id", id, "session", s.Created, "transaction", seq, "request_bytes", len(body))
	ch := make(chan []byte, 1)
	s.rpc[seq] = ch
	s.mu.Unlock()
	defer func() { s.mu.Lock(); delete(s.rpc, seq); s.mu.Unlock() }()
	b := binary.BigEndian.AppendUint32(nil, seq)
	b = binary.BigEndian.AppendUint32(b, uint32(len(body)))
	b = append(b, 1)
	b = append(b, body...)
	_, err := e.requestSession(ctx, s, 7, []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0x83, []capwap.PrivElementValue{{Type: 0x83, Value: b}})}})
	if err != nil {
		return nil, err
	}
	select {
	case b := <-ch:
		s.mu.Lock()
		dead := s.dead
		s.mu.Unlock()
		if dead {
			return nil, fmt.Errorf("AP session closed")
		}
		return json.RawMessage(b), nil
	case <-ctx.Done():
		return nil, ctx.Err()
	case <-s.closed:
		return nil, fmt.Errorf("AP session closed while waiting for JSON reply")
	}
}
