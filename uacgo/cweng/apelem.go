package cweng

import (
	"encoding/binary"

	"uacgo/capwap"
)

// Join-request element parsing (AP identity), byte-exact per the vendor
// parse functions.

// SubElement is one {type,len,value} entry inside a vendor-structured
// element (WTP Board Data / WTP Descriptor sub-elements).
type SubElement struct {
	Type  uint16
	Value []byte
}

// WTPBoardData mirrors cw_wtp_board_data_parse @0x5838e0:
// BE32 vendor id + N × {BE16 type (1..0x400), BE16 len (1..0x400), value}.
// Sub-element 0 (len 4) is the model number consumed by
// acpdt_capwap_callback_discovery_reqeust_listen @0x6653f8.
func ParseWTPBoardData(v []byte) (vendor uint32, subs []SubElement, err error) {
	if len(v) < 4 {
		return 0, nil, capwap.ErrShortPacket
	}
	vendor = binary.BigEndian.Uint32(v)
	off := 4
	for off < len(v) {
		if off+4 > len(v) {
			return vendor, subs, capwap.ErrShortPacket
		}
		t := binary.BigEndian.Uint16(v[off:])
		l := binary.BigEndian.Uint16(v[off+2:])
		off += 4
		if l == 0 || l > 0x400 || off+int(l) > len(v) {
			return vendor, subs, capwap.ErrShortPacket
		}
		subs = append(subs, SubElement{Type: t, Value: v[off : off+int(l)]})
		off += int(l)
	}
	return vendor, subs, nil
}

// ModelNumber returns board-data sub-element 0 as u32 (the AP model id that
// indexes the AP capability database).
func ModelNumber(subs []SubElement) (uint32, bool) {
	if len(subs) == 0 || len(subs[0].Value) != 4 {
		return 0, false
	}
	return binary.BigEndian.Uint32(subs[0].Value), true
}

// SerialNumber returns board-data sub-element 1 (16-char ASCII serial in the
// fixture).
func SerialNumber(subs []SubElement) string {
	for _, s := range subs {
		if s.Type == 1 {
			return string(s.Value)
		}
	}
	return ""
}

// WTPName is element 0x002d (min 1 max 0x200): raw name bytes.
func WTPName(v []byte) string { return string(v) }

// APEntry is the AP identity derived from a Join Request — the input record
// for the AP management table (the vendor's _apmngr_try_create_ap_entry...).
type APEntry struct {
	Name       string
	ModelID    uint32
	Serial     string
	Location   string
	LocalIP    [4]byte
	RadioCount int
	MACType    uint8
}

// ParseAPEntry extracts the identity fields from a parsed Join Request.
func ParseAPEntry(req *capwap.ParsedPacket) (*APEntry, error) {
	e := &APEntry{}
	for _, el := range req.Elements {
		switch el.Type {
		case 0x001c:
			e.Location = string(el.Value)
		case 0x0026:
			_, subs, err := ParseWTPBoardData(el.Value)
			if err != nil {
				return nil, err
			}
			if id, ok := ModelNumber(subs); ok {
				e.ModelID = id
			}
			e.Serial = SerialNumber(subs)
		case 0x002d:
			e.Name = WTPName(el.Value)
		case 0x001e:
			if len(el.Value) == 4 {
				copy(e.LocalIP[:], el.Value)
			}
		case 0x002c:
			if len(el.Value) == 1 {
				e.MACType = el.Value[0]
			}
		case 0x0418:
			e.RadioCount++
		}
	}
	return e, nil
}
