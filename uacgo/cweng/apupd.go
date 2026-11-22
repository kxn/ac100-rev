package cweng

import (
	"encoding/binary"

	"uacgo/capwap"
)

// apupd subsystem (AP firmware upgrade).
//
// Evidence:
//   - registry: apupd registers msg 8/15/16 at priority 1 (registry.tsv,
//     apupd_init).
//   - Image Data Request listener apupd_capwap_callback_image_request_listen
//     @0x643550: private 0xb1 → sub-image action confirm; else elements
//     0x19 (image identifier) + 0x1b (image information) → software version
//     confirm → response result code (0 ok, 0x10 confirm-failed) +
//     apupd_image_information_add (element 0x1a = BE32 file info + info
//     bytes; fixture-sized 4+16=20 @0x661520).
//   - image data element 0x18 value = {u8 type, BE16 len, data[len]}
//     (cw_image_data_parse: type ∈ {1,2} data, 5 = pull request).
type ImageProvider interface {
	// Identifier is element 0x19 (vendor id + version fields).
	Identifier() [4]byte
	// Info is the 16-byte image information payload of element 0x1a.
	Info() [16]byte
	// File is the firmware image offered to APs.
	File() []byte
	// ChunkSize caps one 0x18 data chunk (vendor max data 0x400).
	ChunkSize() int
}

// RegisterUpdHandlers wires the apupd msg 15 listener (priority 1).
func (e *Engine) RegisterUpdHandlers(p ImageProvider) {
	e.Register(capwap.MsgImageDataRequest, 1, "apupd_image_request",
		func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
			// private 0xb1: sub-image action confirm — result code only
			for _, el := range req.Elements {
				if el.Type == 0x0025 && hasPriv(el.Value, 0xb1) {
					appendResultCode(rsp, 0)
					return true
				}
			}
			// chunk pull: 0x18 with type 5
			if el, ok := elementOf(req, 0x0018); ok && len(el.Value) >= 1 &&
				el.Value[0] == 5 {
				off := int(binary.BigEndian.Uint32(pad32(el.Value[3:])))
				return serveChunk(rsp, p, off)
			}
			// identifier confirm: 0x19 present → result + image information
			if _, ok := elementOf(req, 0x0019); ok {
				code := uint32(0)
				if len(p.File()) == 0 {
					code = 0x10
				}
				appendResultCode(rsp, code)
				if code == 0 {
					info := make([]byte, 4, 20)
					id := p.Identifier()
					info[0], info[1], info[2], info[3] = id[0], id[1], id[2], id[3]
					inf := p.Info()
					info = append(info, inf[:]...)
					rsp.Elements = append(rsp.Elements, capwap.Element{
						Type: 0x001a, Value: info})
				}
				return true
			}
			return false
		})
}

// serveChunk appends one 0x18 data chunk from off (type 1).
func serveChunk(rsp *capwap.ParsedPacket, p ImageProvider, off int) bool {
	file := p.File()
	if off < 0 || off >= len(file) {
		appendResultCode(rsp, 0x10)
		return false
	}
	n := p.ChunkSize()
	if n <= 0 || n > 0x400 {
		n = 0x400
	}
	end := off + n
	if end > len(file) {
		end = len(file)
	}
	chunk := file[off:end]
	val := make([]byte, 3, 3+len(chunk))
	val[0] = 1 // data chunk type
	binary.BigEndian.PutUint16(val[1:], uint16(len(chunk)))
	val = append(val, chunk...)
	rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x0018, Value: val})
	appendResultCode(rsp, 0)
	return true
}

// SendImageNotify starts an upgrade: Configuration Update Request (msg 7)
// carrying element 0x19 image identifier.
// (AC→AP initiation via the upgrade manager; msg 7 chosen per the
// Configuration Update Request path — flag: verify against a live capture.)
func (e *Engine) SendImageNotify(s *Session, id [4]byte) error {
	s.mu.Lock()
	next := s.OutSeq + 1
	if s.OutSeq == 0xff {
		next = 1
	}
	s.OutSeq = next
	s.mu.Unlock()

	pkt, err := capwap.NewParsedPacket(capwap.MsgConfigurationUpdateRequest)
	if err != nil {
		return err
	}
	pkt.Header.Rid = 1
	pkt.Control.SeqNum = next
	pkt.Elements = append(pkt.Elements, capwap.Element{
		Type: 0x0019, Value: append([]byte(nil), id[:]...)})
	return e.sendTo(s.Addr, pkt.Assemble())
}

// --- helpers ---

func elementOf(p *capwap.ParsedPacket, t uint16) (capwap.Element, bool) {
	for _, el := range p.Elements {
		if el.Type == t {
			return el, true
		}
	}
	return capwap.Element{}, false
}

func appendResultCode(rsp *capwap.ParsedPacket, code uint32) {
	rsp.Elements = append(rsp.Elements, capwap.Element{
		Type: 0x0021, Value: []byte{
			byte(code >> 24), byte(code >> 16), byte(code >> 8), byte(code)}})
}

func hasPriv(envelope []byte, privType uint16) bool {
	if len(envelope) < 6 {
		return false
	}
	v := envelope[6:]
	for len(v) >= 4 {
		t := uint16(v[0])<<8 | uint16(v[1])
		l := uint16(v[2])<<8 | uint16(v[3])
		if int(l)+4 > len(v) {
			return false
		}
		if t == privType {
			return true
		}
		v = v[4+int(l):]
	}
	return false
}

func pad32(b []byte) []byte {
	out := make([]byte, 4)
	copy(out[4-min(4, len(b)):], b)
	return out
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
