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
func (e *Engine) RequestJSON(ctx context.Context, id string, body json.RawMessage) (json.RawMessage, error) {
	return e.requestJSON(ctx, id, body, true)
}

// NotifyJSON waits for the configuration ACK without requesting a separate
// model reply. It shares transport eligibility and transaction IDs with RPC.
func (e *Engine) NotifyJSON(ctx context.Context, id string, body json.RawMessage) error {
	_, err := e.requestJSON(ctx, id, body, false)
	return err
}

func (e *Engine) requestJSON(ctx context.Context, id string, body json.RawMessage, needReply bool) (response json.RawMessage, resultErr error) {
	defer func() {
		e.Events.Context(ctx, "native_model.completed", "ap_id", id, "request_bytes", len(body), "response_bytes", len(response), "expect_reply", needReply, "error", errorText(resultErr))
	}()
	if !json.Valid(body) || len(body) > 4096 {
		return nil, fmt.Errorf("invalid AP JSON request")
	}
	s := e.findAP(id)
	if s == nil {
		return nil, fmt.Errorf("AP offline")
	}
	s.mu.Lock()
	// Both V4 and V6 _send_tdcp_request_to_ap_by_id select capability49.
	if !s.apEntry.HasCapability(49) {
		s.mu.Unlock()
		return nil, fmt.Errorf("AP does not advertise TDCP capability49")
	}
	if s.rpc == nil {
		s.rpc = map[uint32]chan []byte{}
	}
	if needReply && len(s.rpc) >= 8 {
		s.mu.Unlock()
		return nil, fmt.Errorf("too many AP JSON requests")
	}
	s.rpcSeq++
	if s.rpcSeq == 0 {
		s.rpcSeq++
	}
	seq := s.rpcSeq
	e.Events.Context(ctx, "native_model.requested", "ap_id", id, "session", s.Created, "transaction", seq, "request_bytes", len(body), "expect_reply", needReply)
	var ch chan []byte
	if needReply {
		ch = make(chan []byte, 1)
		s.rpc[seq] = ch
	}
	s.mu.Unlock()
	if needReply {
		defer func() { s.mu.Lock(); delete(s.rpc, seq); s.mu.Unlock() }()
	}
	b := binary.BigEndian.AppendUint32(nil, seq)
	b = binary.BigEndian.AppendUint32(b, uint32(len(body)))
	flag := byte(0)
	if needReply {
		flag = 1
	}
	b = append(b, flag)
	b = append(b, body...)
	_, err := e.requestSession(ctx, s, 7, []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0x83, []capwap.PrivElementValue{{Type: 0x83, Value: b}})}})
	if err != nil || !needReply {
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
