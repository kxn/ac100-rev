// Package capwap implements the CAPWAP wire format exactly as the TL-AC100
// `uac` MIPS binary parses and assembles it. Every rule here cites binary
// evidence (function symbol @ address in work/rootfs/usr/sbin/uac).
//
// Evidence map (per cw_header_parse @0x5a0cc0, cw_control_header_parse @0x5a1268,
// cw_header_assemble / cw_control_header_assemble @0x5a1484, verified by
// round-trip against the vendor's own .data fixtures cw_dis_req etc.):
//
//	word0 (BE32) bit layout (MIPS32r2 `ext` extraction in cw_header_parse):
//	  [31:28] version       hdr.Version   (parse rejects >=2)
//	  [27:24] type          hdr.Type      (0=control, 1=data)
//	  [23:19] hlen          hdr.Hlen      (32-bit words; offset += (hlen-2)*4)
//	  [18:14] rid           hdr.Rid
//	  [13:9]  wbid          hdr.Wbid
//	  [8]     T             hdr.T
//	  [7]     F             hdr.F
//	  [6]     L             hdr.L
//	  [5]     W             hdr.W
//	  [4:3]   reserved      hdr.Flags?    (stored as hdr[8..10] in binary)
//	word1 (BE32):
//	  [31:16] frag id       BE16          hdr.FragID
//	  [15:3]  frag offset   (BE16)>>3     hdr.FragOff   (units of 8 bytes)
//	optional TLVs when hlen>2, then control header:
//	  msg type  BE32, accepted 1..26 or 0x33dd01..0x33dd02
//	  seqNum    u8
//	  MEL       BE16        ** vendor quirk: actual element bytes = MEL-3 **
//	  flags     u8          must be 0
package capwap

import (
	"encoding/binary"
	"errors"
)

// MaxUdpPayload mirrors capwap_plain_packet_receive's 0xcc00-byte buffer
// (cw_ac_network_process @0x589f44).
const MaxUdpPayload = 0xcc00

var (
	ErrShortPacket = errors.New("capwap: packet too short")
	ErrBadVersion  = errors.New("capwap: header version >= 2")
	ErrBadFlags    = errors.New("capwap: control header flags not zero")
	ErrBadMsgType  = errors.New("capwap: control message type unrecognised")
	ErrLenMismatch = errors.New("capwap: message length mismatch")
)

// Header is the parsed CAPWAP preamble (0x10-byte struct in the binary).
type Header struct {
	Version uint8 // bits 31:28
	Type    uint8 // bits 27:24
	Hlen    uint8 // bits 23:19, in 32-bit words
	Rid     uint8 // bits 18:14
	Wbid    uint8 // bits 13:9
	T       uint8 // bit 8
	F       uint8 // bit 7
	L       uint8 // bit 6
	W       uint8 // bit 5
	Rsvd    uint8 // bits 4:3 (binary stores bits 5..3 into hdr[8..10])

	FragID  uint16 // word1 [31:16]
	FragOff uint16 // word1 [15:3], 8-byte units
}

// ParseHeader decodes the CAPWAP preamble from b, returning the number of
// bytes consumed (4+4 plus (hlen-2)*4 optional-TLV bytes).
//
// Evidence: cw_header_parse @0x5a0cc0 — version check `lbu v0,0(v0); sltiu v0,v0,2`,
// `ext` field extraction, trailing `(hlen-2)*4` offset advance.
func ParseHeader(b []byte) (Header, int, error) {
	var h Header
	if len(b) < 8 {
		return h, 0, ErrShortPacket
	}
	w := binary.BigEndian.Uint32(b)
	if w>>28 >= 2 { // sltiu v0,v0,2 — version must be 0 or 1
		return h, 0, ErrBadVersion
	}
	h.Version = uint8(w >> 28)
	h.Type = uint8(w>>24) & 0xf
	h.Hlen = uint8(w>>19) & 0x1f
	if h.Hlen < 2 {
		return h, 0, ErrShortPacket
	}
	h.Rid = uint8(w>>14) & 0x1f
	h.Wbid = uint8(w>>9) & 0x1f
	h.T = uint8(w>>8) & 1
	h.F = uint8(w>>7) & 1
	h.L = uint8(w>>6) & 1
	h.W = uint8(w>>5) & 1
	h.Rsvd = uint8(w>>3) & 3
	// The binary only accepts the packet when L==0 or F!=0 (beqz a0 / beqz v1
	// guard at 0x5a0d9c..0x5a0da8: reject when L set without F).
	if h.L != 0 && h.F == 0 {
		return h, 0, errors.New("capwap: L set without F")
	}
	w1 := binary.BigEndian.Uint32(b[4:])
	h.FragID = uint16(w1 >> 16)
	h.FragOff = uint16(w1>>3) & 0x1fff
	consumed := 8 + int(h.Hlen-2)*4
	if consumed > len(b) {
		return h, 0, ErrShortPacket
	}
	return h, consumed, nil
}

// AppendHeader writes the CAPWAP preamble to dst (which must have room for
// at least 8 bytes) and returns the extended slice.
//
// Evidence: cw_header_assemble @0x5a0fd0 — fields re-packed into word0/word1.
func AppendHeader(dst []byte, h Header) []byte {
	w := uint32(h.Version&0xf)<<28 | uint32(h.Type&0xf)<<24 |
		uint32(h.Hlen&0x1f)<<19 | uint32(h.Rid&0x1f)<<14 |
		uint32(h.Wbid&0x1f)<<9 | uint32(h.T&1)<<8 | uint32(h.F&1)<<7 |
		uint32(h.L&1)<<6 | uint32(h.W&1)<<5 | uint32(h.Rsvd&3)<<3
	w1 := uint32(h.FragID)<<16 | uint32(h.FragOff&0x1fff)<<3
	dst = binary.BigEndian.AppendUint32(dst, w)
	dst = binary.BigEndian.AppendUint32(dst, w1)
	return dst
}
