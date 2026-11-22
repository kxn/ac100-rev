package cweng

import (
	"sort"
	"sync"

	"uacgo/capwap"
)

// Handler processes one control message and appends elements to the response
// packet (serv_mngr_handle @0x599368 calls each handler with
// (parsed_pkt, basic, response); responses are built by the handlers adding
// elements, exactly like the vendor listeners do).
//
// For REQUEST messages the engine passes Rsp non-nil; handlers add response
// elements. The bool result feeds the FSM CHECK_PASSED/CHECK_FAILED event
// (ac_msg_handle: ac_packet_is_right(response)).
type Handler func(ctx *Ctx, req *capwap.ParsedPacket, rsp *capwap.ParsedPacket) bool

// Ctx carries per-call environment (worker/session) to handlers.
type Ctx struct {
	Session *Session // nil for session-less discovery requests
}

// registration mirrors serv_msg_mngr_register(msg_type, priority, fn): the
// per-type list is kept sorted by ascending priority (insert-walk in the
// binary) and every handler runs in order.
type registration struct {
	prio   uint16
	name   string
	handle Handler
}

type registry struct {
	mu   sync.RWMutex
	msgs map[uint32][]registration
	ents map[uint][]registration // ent events 0..3
}

func newRegistry() *registry {
	return &registry{msgs: make(map[uint32][]registration), ents: make(map[uint][]registration)}
}

// Register mirrors serv_msg_mngr_register @0x599c78 (sorted insert by priority).
func (r *registry) Register(msgType uint32, prio uint16, name string, h Handler) {
	r.mu.Lock()
	defer r.mu.Unlock()
	list := r.msgs[msgType]
	list = append(list, registration{prio: prio, name: name, handle: h})
	sort.SliceStable(list, func(i, j int) bool { return list[i].prio < list[j].prio })
	r.msgs[msgType] = list
}

// RegisterEnt mirrors serv_ent_mngr_register(ent_type 0..3, prio, fn) @0x599eec.
func (r *registry) RegisterEnt(ent uint, prio uint16, name string, h Handler) {
	r.mu.Lock()
	defer r.mu.Unlock()
	list := r.ents[ent]
	list = append(list, registration{prio: prio, name: name, handle: h})
	sort.SliceStable(list, func(i, j int) bool { return list[i].prio < list[j].prio })
	r.ents[ent] = list
}

// handleMsg mirrors serv_mngr_handle @0x599368: iterate the sorted handler
// chain; Join requests require a response packet (add_rslt_code gate).
func (r *registry) handleMsg(ctx *Ctx, msgType uint32, req, rsp *capwap.ParsedPacket) bool {
	r.mu.RLock()
	list := r.msgs[msgType]
	r.mu.RUnlock()
	for _, reg := range list {
		if !reg.handle(ctx, req, rsp) {
			return false
		}
	}
	return true
}

// fireEnt runs the listeners for an ent lifecycle event.
func (r *registry) fireEnt(ent uint, ctx *Ctx) bool {
	r.mu.RLock()
	list := r.ents[ent]
	r.mu.RUnlock()
	noop := &capwap.ParsedPacket{}
	for _, reg := range list {
		if !reg.handle(ctx, noop, nil) {
			return false
		}
	}
	return true
}
