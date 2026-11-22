package capwap

import (
	"encoding/binary"
	"fmt"
)

// Control message types (binary: cw_control_header_parse @0x5a1268 accepts
// type-1 < 0x1a i.e. 1..26, and 0x33dd01..0x33dd02; names from the binary's
// own strings via cw_control_msg_name @ table in .rodata).
const (
	MsgDiscoveryRequest            = 1
	MsgDiscoveryResponse           = 2
	MsgJoinRequest                 = 3
	MsgJoinResponse                = 4
	MsgConfigurationStatusRequest  = 5
	MsgConfigurationStatusResponse = 6
	MsgConfigurationUpdateRequest  = 7
	MsgConfigurationUpdateResponse = 8
	MsgWTPEventRequest             = 9
	MsgWTPEventResponse            = 10
	MsgWTPEvent                    = 9 // alias (engine tests)
	MsgChangeStateEventRequest     = 11
	MsgChangeStateEventResponse    = 12
	MsgEchoRequest                 = 13
	MsgEchoResponse                = 14
	MsgImageDataRequest            = 15
	MsgImageDataResponse           = 16
	MsgResetRequest                = 17
	MsgResetResponse               = 18
	MsgPrimaryDiscoveryRequest     = 19
	MsgPrimaryDiscoveryResponse    = 20
	MsgDataTransferRequest         = 21
	MsgDataTransferResponse        = 22
	MsgWLANConfigurationRequest    = 23
	MsgWLANConfigurationResponse   = 24
	MsgWTPEventRequestAdvanced     = 25 // vendor name for 25 (cf. cw_control_msg_name)
	MsgWTPEventResponseAdvanced    = 26
	// Pseudo message types used by g_serv_ie_msg_mngr (serv_msg_mngr_init
	// @0x599a10 creates buckets 0x33dd01..0x33dd02).
	MsgIe1 = 0x33dd01
	MsgIe2 = 0x33dd02
)

// ControlHeader is the 8-byte control block that follows the CAPWAP preamble.
type ControlHeader struct {
	MsgType uint32
	SeqNum  uint8
	MEL     uint16 // Message Element Length, vendor quirk: elements = MEL-3
	Flags   uint8  // must be 0
}

// ElementsLen returns the true number of element bytes: MEL-3
// (capwap_packet_parse @0x587a94: `uVar1 - 3 == pkt_len - pkt_off`).
func (c ControlHeader) ElementsLen() int { return int(c.MEL) - 3 }

// ParseControlHeader decodes the control block at b[off:].
func ParseControlHeader(b []byte, off int) (ControlHeader, error) {
	var c ControlHeader
	if off+8 > len(b) {
		return c, ErrShortPacket
	}
	c.MsgType = binary.BigEndian.Uint32(b[off:])
	if !(c.MsgType >= 1 && c.MsgType <= 26) && !(c.MsgType >= MsgIe1 && c.MsgType <= MsgIe2) {
		return c, fmt.Errorf("%w: %d", ErrBadMsgType, c.MsgType)
	}
	c.SeqNum = b[off+4]
	c.MEL = binary.BigEndian.Uint16(b[off+5:])
	c.Flags = b[off+7]
	if c.Flags != 0 {
		return c, ErrBadFlags
	}
	return c, nil
}

// AppendControlHeader appends the control block; mirrors
// cw_control_header_assemble @0x5a1484 byte-for-byte.
func AppendControlHeader(dst []byte, c ControlHeader) []byte {
	dst = binary.BigEndian.AppendUint32(dst, c.MsgType)
	dst = append(dst, c.SeqNum)
	dst = binary.BigEndian.AppendUint16(dst, c.MEL)
	dst = append(dst, c.Flags)
	return dst
}
