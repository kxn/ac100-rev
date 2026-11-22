package capwap

import (
	"encoding/binary"
)

// ParsedPacket mirrors the binary's parsed_pkt struct used by
// capwap_packet_parse @0x587a94 and built by cw_parsed_pkt_create @0x588488.
type ParsedPacket struct {
	Header    Header
	HeaderLen int // bytes consumed by preamble (+ optional TLVs)
	Control   ControlHeader
	Elements  []Element
}

// TotalPacketLen mirrors capwap_packet_assemble @0x00587xxx line:
// total = (hlen+2)*4 + MEL - 3  (binary stores MEL accumulator starting at 3).
func (p *ParsedPacket) TotalPacketLen() int {
	elements := 0
	for _, e := range p.Elements {
		elements += 4 + len(e.Value)
	}
	return (int(p.Header.Hlen)+2)*4 + elements
}

// MEL is the wire value: elements + 3 (accumulator initialized to 3,
// cw_parsed_pkt_create @0x588488: `*(u16*)(pkt+0x16) = 3`).
func (p *ParsedPacket) MEL() uint16 {
	elements := 0
	for _, e := range p.Elements {
		elements += 4 + len(e.Value)
	}
	return uint16(3 + elements)
}

// ParsePacket parses a complete control-mode UDP payload:
// preamble (+optional TLVs) → control header → MEL-3 bytes of elements.
//
// Evidence: capwap_packet_parse @0x587a94.
func ParsePacket(b []byte) (*ParsedPacket, error) {
	hdr, off, err := ParseHeader(b)
	if err != nil {
		return nil, err
	}
	if hdr.Type != 0 {
		// The AC only parses control packets here (param_4=0 path).
		return nil, ErrShortPacket
	}
	ctrl, err := ParseControlHeader(b, off)
	if err != nil {
		return nil, err
	}
	off += 8
	nel := ctrl.ElementsLen()
	if off+nel > len(b) {
		return nil, ErrLenMismatch
	}
	eles, err := ParseElements(b, off, nel)
	if err != nil {
		return nil, err
	}
	return &ParsedPacket{Header: hdr, HeaderLen: off - 8, Control: ctrl, Elements: eles}, nil
}

// Assemble writes the packet in the binary's exact wire format.
//
// Evidence: capwap_packet_assemble — hlen=2 preamble (no optional TLVs),
// control header with MEL=elements+3, element TLVs appended in order.
// cw_header_init @ (cw_parsed_pkt_create) sets version=1, type=0(hlen 2? see below).
func (p *ParsedPacket) Assemble() []byte {
	var b []byte
	b = AppendHeader(b, p.Header)
	b = p.Control.withMEL(p.MEL()).appendTo(b)
	for _, e := range p.Elements {
		b = AppendElement(b, e.Type, e.Value)
	}
	return b
}

// withMEL overrides MEL for writing (the accumulator already includes the +3).
func (c ControlHeader) withMEL(mel uint16) ControlHeader {
	c.MEL = mel
	return c
}

func (c ControlHeader) appendTo(b []byte) []byte { return AppendControlHeader(b, c) }

// NewParsedPacket mirrors cw_parsed_pkt_create @0x588488 + cw_header_init
// @0x5a11f8: hdr[0]=0 version, hdr[1]=0 type, hdr[2]=2 hlen, hdr[3]=rid=1,
// hdr[4]=wbid=1, hdr[5]=1 T (matches every vendor fixture's word0 0x00104300);
// MEL accumulator starts at 3. SeqNum is assigned per send by the caller.
func NewParsedPacket(msgType uint32) (*ParsedPacket, error) {
	if !(msgType >= 1 && msgType <= 26) && !(msgType >= MsgIe1 && msgType <= MsgIe2) {
		return nil, ErrBadMsgType
	}
	return &ParsedPacket{
		Header:  Header{Version: 0, Type: 0, Hlen: 2, Rid: 1, Wbid: 1, T: 1},
		Control: ControlHeader{MsgType: msgType, Flags: 0},
	}, nil
}

// ---------------- data-mode helpers ----------------

// IsDiscoveryRequest mirrors is_cw_discovery_request (word2 == 1).
func IsDiscoveryRequest(b []byte) bool {
	return len(b) >= 12 && binary.BigEndian.Uint32(b[8:]) == MsgDiscoveryRequest
}

// IsJoinRequest mirrors is_cw_join_request (word2 == 3).
func IsJoinRequest(b []byte) bool {
	return len(b) >= 12 && binary.BigEndian.Uint32(b[8:]) == MsgJoinRequest
}
