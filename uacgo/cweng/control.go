package cweng

import (
	"encoding/binary"

	"uacgo/capwap"
)

// AC-initiated control flows, byte-exact per the vendor send functions.

// SendLED mirrors apmngr_pkt_led_pkt_send @0x55aec4: Configuration Update
// Request (msg 7) with one vendor envelope (vendor id 0, field 0) carrying
// private element 0x39 "ap led op" = u32(0|1).
func (e *Engine) SendLED(s *Session, on bool) error {
	v := uint32(0)
	if on {
		v = 1
	}
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0x39, Value: encodeU32(v)})
}

// SendReset mirrors apmngr_pkt_reset_pkt_send @0x55ad74: Reset Request
// (msg 17). mode 1 = reboot (no elements), mode 2 = envelope 0x23 = u32 1,
// mode 3 = envelope 0x23 = u32 3; mode > 3 rejected.
func (e *Engine) SendReset(s *Session, mode uint32) error {
	if mode > 3 || mode == 0 {
		return ErrBadResetMode
	}
	var privs []capwap.PrivElementValue
	if mode >= 2 {
		val := uint32(3)
		if mode == 2 {
			val = 1
		}
		privs = append(privs, capwap.PrivElementValue{Type: 0x23, Value: encodeU32(val)})
	}
	return e.sendACRequest(s, capwap.MsgResetRequest, privs...)
}

// SendConfigUpdate sends a generic Configuration Update Request (msg 7) with
// verbatim envelope values (the vendor builds 0x08 radio / 0x0a rate payloads
// from config; callers pass the same bytes here).
func (e *Engine) SendConfigUpdate(s *Session, envelopeValues [][]byte) error {
	var privs []capwap.PrivElementValue
	for _, v := range envelopeValues {
		privs = append(privs, capwap.PrivElementValue{Type: 0xffff, Value: v, Raw: true})
	}
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest, privs...)
}

// sendACRequest assigns the session's outgoing sequence number
// (session+0xa4 counter, wrapping 0xff → 1) and sends.
func (e *Engine) sendACRequest(s *Session, msgType uint32, privs ...capwap.PrivElementValue) error {
	s.mu.Lock()
	defer s.mu.Unlock()
	next := s.OutSeq + 1
	if s.OutSeq == 0xff { // signed-char -1 wrap in the binary
		next = 1
	}
	s.OutSeq = next

	pkt, err := capwap.NewParsedPacket(msgType)
	if err != nil {
		return err
	}
	pkt.Header.Rid = 1
	pkt.Control.SeqNum = next
	for _, p := range privs {
		var v []byte
		if p.Raw {
			v = append([]byte(nil), p.Value...)
		} else {
			v = capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: p.Type, Value: p.Value}})
		}
		pkt.Elements = append(pkt.Elements, capwap.Element{Type: 0x0025, Value: v})
	}
	return e.sendTo(s.Addr, pkt.Assemble())
}

func encodeU32(v uint32) []byte {
	return []byte{byte(v >> 24), byte(v >> 16), byte(v >> 8), byte(v)}
}

var _ = binary.BigEndian

// ErrBadResetMode mirrors apmngr_pkt_reset_pkt_send: mode must be 1..3.
var ErrBadResetMode = errorString("reset mode must be 1, 2 or 3")

type errorString string

func (e errorString) Error() string { return string(e) }
