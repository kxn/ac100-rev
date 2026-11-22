package cweng

import (
	"uacgo/capwap"
)

// Attach-flow handlers mirroring the vendor listener chains (registry.tsv):
//
//	msg 1  discovery:  acpdt(200: acdesc/name/ctrl-addr/radios/cwver)
//	                   + apmngr(255: 0x25 priv 0x90)
//	msg 3  join:       acpdt(200: result-code/acdesc/name/radios/ecn/
//	                         ctrl-addr/local-addr) + apmngr(120: priv 0x1b/0x8f/0x1d)
//	msg 5  cfg status: apmngr(80: timers/decrypt-period/idle/wtp-fallback/
//	                         ac-ipv4-list + priv 0x3d/0x26) + others
//	msg 11 cse:        (no listeners — empty response, fixture cw_cse_rsp)
//	msg 13 echo:       apmngr(120): no elements (keep-alive only)
//
// Fixture targets: cw_dis_rsp / cw_join_rsp / cw_cfg_rsp / cw_cse_req+cse_rsp.

// IdentityProvider supplies the runtime values the binary pulls from its
// config store (uc_conf / profile / DBs). The Go version loads them from
// files (see cmd/acd).
type IdentityProvider interface {
	ACDescriptor() capwap.ACDescriptor
	ACName() string
	ControlAddress() ([4]byte, uint16)
	LocalAddress() [4]byte
	Radios() [][2]uint8 // {radio_id, type-mask}
	// EnvelopeValues returns verbatim 0x25 envelope value bytes per message
	// type (the binary builds these from per-AP DB state; the data-driven
	// equivalent reads them from the config store).
	Envelope(msgType uint32) [][]byte
	CfgStatusFixed() CfgStatusFixed
}

// CfgStatusFixed carries the config-status response values the binary reads
// from config (capwap timers 0x000c, decrypt period 0x0010, idle timeout
// 0x0017, wtp fallback 0x0028; fixture cw_cfg_rsp values noted inline).
type CfgStatusFixed struct {
	DiscoveryTimer uint8 // fixture 0x14 (20s)
	EchoTimer      uint8 // fixture 0x14 (20s)
	DecryptPeriod  [3]byte
	IdleTimeout    uint32
	WTPFallback    uint8
	ACIPv4List     [][4]byte
}

// RegisterAttachHandlers wires the default response builders into the engine
// with the vendor's priorities.
func (e *Engine) RegisterAttachHandlers(id IdentityProvider) {
	// ---- msg 1 discovery, prio 200 (acpdt) ----
	e.Register(1, 200, "acpdt_discovery", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		d := id.ACDescriptor()
		rsp.Elements = append(rsp.Elements,
			capwap.Element{Type: 0x0001, Value: d.AssembleValue()},
			capwap.Element{Type: 0x0004, Value: []byte(id.ACName())},
		)
		ip, port := id.ControlAddress()
		rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x000a,
			Value: []byte{ip[0], ip[1], ip[2], ip[3], byte(port >> 8), byte(port)}})
		for _, r := range id.Radios() {
			rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x0418,
				Value: []byte{r[0], 0, 0, 0, r[1]}})
		}
		rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x0025,
			Value: capwap.VendorEnvelopeValue(0x12345678, 0,
				[]capwap.PrivElementValue{{Type: 0, Value: []byte{0, 1, 0, 1}}})})
		return true
	})
	// ---- msg 3 join, prio 200 (acpdt) ----
	e.Register(3, 200, "acpdt_join", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		d := id.ACDescriptor()
		rsp.Elements = append(rsp.Elements,
			capwap.Element{Type: 0x0021, Value: []byte{0, 0, 0, 0}}, // result code 0
			capwap.Element{Type: 0x0001, Value: d.AssembleValue()},
			capwap.Element{Type: 0x0004, Value: []byte(id.ACName())},
		)
		for _, r := range id.Radios() {
			rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x0418,
				Value: []byte{r[0], 0, 0, 0, r[1]}})
		}
		rsp.Elements = append(rsp.Elements,
			capwap.Element{Type: 0x0035, Value: []byte{0}}, // ECN support
		)
		ip, port := id.ControlAddress()
		rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x000a,
			Value: []byte{ip[0], ip[1], ip[2], ip[3], byte(port >> 8), byte(port)}})
		local := id.LocalAddress()
		rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x001e,
			Value: []byte{local[0], local[1], local[2], local[3]}})
		return true
	})
	// ---- msg 5 config status, prio 80 (apmngr) ----
	e.Register(5, 80, "apmngr_cfg_status", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		c := id.CfgStatusFixed()
		rsp.Elements = append(rsp.Elements,
			capwap.Element{Type: 0x000c, Value: []byte{c.DiscoveryTimer, c.EchoTimer}},
			capwap.Element{Type: 0x0010, Value: c.DecryptPeriod[:]},
			capwap.Element{Type: 0x0017, Value: []byte{
				byte(c.IdleTimeout >> 24), byte(c.IdleTimeout >> 16),
				byte(c.IdleTimeout >> 8), byte(c.IdleTimeout)}},
			capwap.Element{Type: 0x0028, Value: []byte{c.WTPFallback}},
		)
		var ips []byte
		for _, ip := range c.ACIPv4List {
			ips = append(ips, ip[0], ip[1], ip[2], ip[3])
		}
		rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x0002, Value: ips})
		return true
	})
	// ---- msg 11 change state event: no listeners (empty response) ----
	// ---- msg 13 echo: apmngr(120) keep-alive, no elements ----
	e.Register(13, 120, "apmngr_echo", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		return true
	})

	// envelopes (verbatim per message type)
	for _, mt := range []uint32{1, 3, 5} {
		mt := mt
		prio := uint16(255)
		name := "apmngr_envelope"
		if mt == 3 {
			prio = 120
		}
		if mt == 5 {
			prio = 200
		}
		e.Register(mt, prio, name, func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
			for _, v := range id.Envelope(mt) {
				rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x0025, Value: cloneBytes(v)})
			}
			return true
		})
	}
}

func cloneBytes(b []byte) []byte {
	out := make([]byte, len(b))
	copy(out, b)
	return out
}
