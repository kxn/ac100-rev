package cweng

import (
	"sync"

	"uacgo/capwap"
)

// wsta subsystem (client tracking).
//
// Registry evidence: uac_wstation registers msg 9 (WTP Event Request) at
// priority 100 (_uac_wsta_pkt_wtp_event_listener @0x6360ec). The listener
// reads element 0x34 station information list (and private fallbacks
// 0x02/0x8a/0x03/0x4d) and reads the response's 0x21 result code.

// ClientEvent is one observed station add/remove.
type ClientEvent struct {
	MAC     [6]byte
	RadioID uint8
	A, B    uint32
}

// ClientSink receives station events parsed from WTP Event Requests.
type ClientSink interface {
	StationEvent(ev ClientEvent)
}

// RegisterWstaHandlers wires the msg 9 listener that parses 0x34 and adds
// result code 0 to the response when absent.
func (e *Engine) RegisterWstaHandlers(sink ClientSink) {
	e.Register(9, 100, "uac_wsta_wtp_event", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		for _, el := range req.Elements {
			if el.Type == 0x0034 {
				if l, err := capwap.ParseStaInfoList(el.Value); err == nil {
					for _, en := range l.Entries {
						sink.StationEvent(ClientEvent{
							MAC: en.MAC, RadioID: l.RadioID, A: en.A, B: en.B,
						})
					}
				}
			}
		}
		// result code 0 in the response (the binary's listener expects it)
		hasResult := false
		for _, el := range rsp.Elements {
			if el.Type == 0x0021 {
				hasResult = true
			}
		}
		if !hasResult {
			rsp.Elements = append(rsp.Elements, capwap.Element{
				Type: 0x0021, Value: []byte{0, 0, 0, 0}})
		}
		return true
	})
}

// ClientTable is a simple in-memory ClientSink (session bookkeeping).
type ClientTable struct {
	mu sync.Mutex
	m  map[[6]byte]ClientEvent
}

// NewClientTable creates the table.
func NewClientTable() *ClientTable {
	return &ClientTable{m: make(map[[6]byte]ClientEvent)}
}

// StationEvent records the latest event per MAC.
func (t *ClientTable) StationEvent(ev ClientEvent) {
	t.mu.Lock()
	t.m[ev.MAC] = ev
	t.mu.Unlock()
}

// All returns a snapshot.
func (t *ClientTable) All() []ClientEvent {
	t.mu.Lock()
	defer t.mu.Unlock()
	out := make([]ClientEvent, 0, len(t.m))
	for _, ev := range t.m {
		out = append(out, ev)
	}
	return out
}
