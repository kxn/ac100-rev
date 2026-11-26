package cweng

import (
	"time"
	"uacgo/capwap"
)

// V6 uses AC-initiated sequential msg15 chunks acknowledged by msg16, not
// client-offset pulls. Confirm must authorize a scheduled, model-matched image.
// Called under the AP session lock: never call engine/session readers here.
type ImageConfirm func(ap string, connection time.Time, identifier []byte) (capwap.ImageInformation, error)

type ImageAction func(ap string, connection time.Time, action capwap.PrivSubFirmwareAction) (*capwap.PrivSubFirmwareAction, error)

func (e *Engine) RegisterImageActions(action ImageAction) {
	e.Register(capwap.MsgImageDataRequest, 2, "apupd_sub_image_action", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {

		privateElements(req, func(typ uint16, b []byte) {
			if typ != 0xb1 {
				return
			}
			p, err := capwap.ParsePrivSubFirmwareAction(b)
			if err != nil || action == nil {
				appendResultCode(rsp, 0x10)
				return
			}
			reply, err := action(sessionID(ctx.Session), ctx.Session.Created, *p)
			if err != nil {
				appendResultCode(rsp, 0x10)
				return
			}
			appendResultCode(rsp, 0)
			if reply != nil {
				rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0xb1, Value: reply.AssembleValue()}})})
			}
		})
		return true
	})
}

func (e *Engine) RegisterUpdHandlers(confirm ImageConfirm) {
	e.Register(capwap.MsgImageDataRequest, 1, "apupd_image_request", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		hasAction := false
		privateElements(req, func(typ uint16, _ []byte) { hasAction = hasAction || typ == 0xb1 })
		if hasAction {
			return true
		}
		id, identified := elementOf(req, 0x19)
		_, initiate := elementOf(req, 0x1b)
		if !identified || !initiate || len(id.Value) != 18 || confirm == nil {
			appendResultCode(rsp, 0x10)
			return true
		}
		info, err := confirm(sessionID(ctx.Session), ctx.Session.Created, append([]byte{}, id.Value...))
		if err != nil {
			appendResultCode(rsp, 0x10)
			return true
		}
		appendResultCode(rsp, 0)
		rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x1a, Value: info.AssembleValue()})
		return true
	})
}
func elementOf(p *capwap.ParsedPacket, t uint16) (capwap.Element, bool) {
	for _, el := range p.Elements {
		if el.Type == t {
			return el, true
		}
	}
	return capwap.Element{}, false
}
func appendResultCode(rsp *capwap.ParsedPacket, code uint32) {
	rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x21, Value: capwap.AppendUint32BE(nil, code)})
}
