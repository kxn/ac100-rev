package capwap

import "encoding/binary"

// WTP Descriptor (element 0x0027) — parse/assemble per
// cw_wtp_descriptor_parse @0x584978 / cw_wtp_descriptor_assemble @0x584674.
//
// Wire layout:
//   u8  radio_count       (max radios)
//   u8  radios_in_use     (must be <= radio_count)
//   u8  encryption_count
//   encryption_count × { u8 wbid (&0x1f == itself), BE16 encryption capabilities }
//   N × { BE32 vendor, BE16 type (<=3), BE16 len (1..0x400), value }
//   parse requires exact consumption of the element bytes.

// WTPDescEncryptionSub is one {wbid, capabilities} encryption sub-element.
type WTPDescEncryptionSub struct {
	WBID         uint8
	Capabilities uint16
}

// WTPDescSub is one vendor descriptor sub-element.
type WTPDescSub struct {
	Vendor uint32
	Type   uint16
	Value  []byte
}

// WTPDescriptor is the parsed 0x0027 element.
type WTPDescriptor struct {
	RadioCount  uint8
	RadiosInUse uint8
	Encryption  []WTPDescEncryptionSub
	SubElements []WTPDescSub
}

// ParseWTPDescriptor decodes the element value bytes.
func ParseWTPDescriptor(v []byte) (*WTPDescriptor, error) {
	if len(v) < 3 {
		return nil, ErrShortPacket
	}
	d := &WTPDescriptor{RadioCount: v[0], RadiosInUse: v[1]}
	if d.RadiosInUse > d.RadioCount {
		return nil, ErrShortPacket
	}
	off := 3
	encN := int(v[2])
	for i := 0; i < encN; i++ {
		if off+3 > len(v) {
			return nil, ErrShortPacket
		}
		wbid := v[off]
		if wbid&0x1f != wbid {
			return nil, ErrShortPacket
		}
		d.Encryption = append(d.Encryption, WTPDescEncryptionSub{
			WBID: wbid, Capabilities: binary.BigEndian.Uint16(v[off+1:]),
		})
		off += 3
	}
	for off < len(v) {
		if off+8 > len(v) {
			return nil, ErrShortPacket
		}
		sub := WTPDescSub{
			Vendor: binary.BigEndian.Uint32(v[off:]),
			Type:   binary.BigEndian.Uint16(v[off+4:]),
		}
		l := binary.BigEndian.Uint16(v[off+6:])
		off += 8
		if sub.Type > 3 || l == 0 || l > 0x400 || off+int(l) > len(v) {
			return nil, ErrShortPacket
		}
		sub.Value = v[off : off+int(l)]
		off += int(l)
		d.SubElements = append(d.SubElements, sub)
	}
	return d, nil
}

// AssembleValue writes the element value bytes (mirror of the parse).
func (d *WTPDescriptor) AssembleValue() []byte {
	b := []byte{d.RadioCount, d.RadiosInUse, byte(len(d.Encryption))}
	for _, e := range d.Encryption {
		b = append(b, e.WBID, byte(e.Capabilities>>8), byte(e.Capabilities))
	}
	for _, s := range d.SubElements {
		b = binary.BigEndian.AppendUint32(b, s.Vendor)
		b = binary.BigEndian.AppendUint16(b, s.Type)
		b = binary.BigEndian.AppendUint16(b, uint16(len(s.Value)))
		b = append(b, s.Value...)
	}
	return b
}
