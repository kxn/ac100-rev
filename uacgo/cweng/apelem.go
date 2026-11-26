package cweng

import (
	"encoding/binary"
	"encoding/hex"
	"fmt"
	"net"
	"strings"

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
	EntryID             uint32
	RadioLinkage        *RadioLinkage
	linkageTable        []byte
	linkageControl      []byte
	MeshParent          string
	RadioModes          []RadioMode
	RadioMode           *RadioModeState
	Ports               []PortCapability
	ExtWirePhys         int
	SupportTrunk        bool
	HardwareID          string
	FirmwareID          string
	BlockedFirmware     []string
	SoftwareVersion     string
	EDCAPresets         *capwap.EDCAPresets
	GeneralCapabilities []uint32
	SubCapabilities     map[uint16]uint32
	Capabilities        []RadioCapability
	MAC                 string
	Model               string
	HardwareVersion     string
	Name                string
	ModelID             uint32
	Serial              string
	Location            string
	LocalIP             [4]byte
	RadioCount          int
	MACType             uint8
}

// ParseAPEntry extracts the identity fields from a parsed Join Request.
func ParseAPEntry(req *capwap.ParsedPacket) (*APEntry, error) {
	e := &APEntry{}
	var featureDefaults *RadioFeatureDefaults
	for _, el := range req.Elements {
		switch el.Type {
		case 0x32:
			if len(el.Value)%4 == 0 && len(el.Value) <= 64 {
				for b := el.Value; len(b) >= 4; b = b[4:] {
					e.GeneralCapabilities = append(e.GeneralCapabilities, binary.BigEndian.Uint32(b))
				}
			}
		case 0x0025:
			if len(el.Value) >= 6 {
				for v := el.Value[6:]; len(v) >= 4; {
					n := int(binary.BigEndian.Uint16(v[2:]))
					if n+4 > len(v) {
						break
					}
					if binary.BigEndian.Uint16(v) == 0xc8 {
						if rows, err := capwap.ParseVendorList(v[4 : 4+n]); err == nil {
							for _, r := range rows {
								if r.Type == 12 {
									if ports, err := parsePortCapabilities(r.Value); err == nil {
										e.Ports = ports
									}
								}
							}
						}
					}
					if binary.BigEndian.Uint16(v) == 0x76 {
						if rows, err := capwap.ParseVendorList(v[4 : 4+n]); err == nil {
							for _, r := range rows {
								if r.Type == 16 && len(r.Value) == 7 && r.Value[0] == 1 && r.Value[1]&1 == 0 && meshMAC(r.Value[1:]) != "00:00:00:00:00:00" {
									e.MeshParent = meshMAC(r.Value[1:])
								}
							}
						}
					}
					if binary.BigEndian.Uint16(v) == 0x7f {
						e.linkageTable = append([]byte{}, v[4:4+n]...)
					}
					if binary.BigEndian.Uint16(v) == 0x90 {
						e.linkageControl = append([]byte{}, v[4:4+n]...)
					}
					if binary.BigEndian.Uint16(v) == 0xbb {
						if modes, err := ParseRadioModes(v[4 : 4+n]); err == nil {
							e.RadioModes = modes
						}
					}
					if binary.BigEndian.Uint16(v) == 0xbc {
						if mode, err := parseRadioModeState(v[4 : 4+n]); err == nil {
							e.RadioMode = mode
						}
					}
					if binary.BigEndian.Uint16(v) == 0xce {
						if presets, err := capwap.ParseEDCAPresets(v[4 : 4+n]); err == nil {
							e.EDCAPresets = presets
						}
					}
					if binary.BigEndian.Uint16(v) == 0x5b {
						if info, err := capwap.ParsePrivAPFirmwareID(v[4 : 4+n]); err == nil {
							e.FirmwareID = hex.EncodeToString(info.FirmwareID[:])
							for _, id := range info.Blocked {
								e.BlockedFirmware = append(e.BlockedFirmware, hex.EncodeToString(id[:]))
							}
						}
					}
					if binary.BigEndian.Uint16(v) == 0x51 {
						if c, err := ParseAPCapabilities(v[4 : 4+n]); err == nil {
							e.Model = c.Model
							e.HardwareID = c.HardwareID
							e.ExtWirePhys = c.ExtWirePhys
							e.SupportTrunk = c.SupportTrunk
							e.Capabilities = c.Radios
						}
					}
					if binary.BigEndian.Uint16(v) == 0xb2 && featureDefaults == nil {
						featureDefaults = parseRadioFeatureDefaults(v[4 : 4+n])
					}
					if binary.BigEndian.Uint16(v) == 0x8f && n >= 2 {
						b := v[4 : 4+n]
						count := int(binary.BigEndian.Uint16(b))
						b = b[2:]
						e.SubCapabilities = map[uint16]uint32{}
						for i := 0; i < count && len(b) >= 4; i++ {
							typ, size := binary.BigEndian.Uint16(b), int(binary.BigEndian.Uint16(b[2:]))
							b = b[4:]
							if size > len(b) || size > 4 {
								break
							}
							var value uint32
							for _, x := range b[:size] {
								value = value<<8 | uint32(x)
							}
							e.SubCapabilities[typ] = value
							b = b[size:]
						}
					}
					v = v[4+n:]
				}
			}
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
			e.Serial = strings.TrimRight(SerialNumber(subs), "\x00")
			for _, sub := range subs {
				if sub.Type == 4 && len(sub.Value) == 6 {
					e.MAC = net.HardwareAddr(sub.Value).String()
				}
			}
		case 0x0027:
			if d, err := capwap.ParseWTPDescriptor(el.Value); err == nil {
				e.RadioCount = int(d.RadioCount)
				for _, sub := range d.SubElements {
					if sub.Type == 1 && len(sub.Value) == 14 {
						v := sub.Value
						date := binary.BigEndian.Uint32(v[6:])
						e.SoftwareVersion = fmt.Sprintf("%d.%d.%d Build %04d%02d%02d Rel.%d", binary.BigEndian.Uint16(v), binary.BigEndian.Uint16(v[2:]), binary.BigEndian.Uint16(v[4:]), date>>16, (date>>8)&255, date&255, binary.BigEndian.Uint32(v[10:]))
					}
					if sub.Type == 0 {
						if len(sub.Value) == 4 {
							e.HardwareVersion = fmt.Sprintf("%d.%d", binary.BigEndian.Uint16(sub.Value), binary.BigEndian.Uint16(sub.Value[2:]))
						}
					}
				}
			}
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
			if e.RadioCount == 0 {
				e.RadioCount = 1
			}
		}
	}
	// V6 initializes/checks and serializes Wi-Fi6 fields using radio1's
	// extension bitmap for every radio (@73d0f0, @742e24, @73ea84).
	firstFeatures := map[string]bool{}
	for _, c := range e.Capabilities {
		if c.RadioID == 1 {
			firstFeatures = c.Features
		}
	}
	for i := range e.Capabilities {
		features := map[string]bool{}
		for name, value := range firstFeatures {
			features[name] = value
		}
		e.Capabilities[i].ControlFeatures = features
		if featureDefaults != nil && e.HasCapability(70) {
			d := *featureDefaults
			e.Capabilities[i].AXDefaults = &d
		}
	}

	refreshRadioLinkage(e)
	return e, nil
}
