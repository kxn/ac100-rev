package capwap

// Batch-11: remaining standard elements.

// AppendACIPv6List is element 0x0003 (min 16 max 0x1000): repeated 16-byte
// IPv6 addresses (cw_ac_ipv6_list_assemble — the ipv6 twin of 0x0002).
func AppendACIPv6List(dst []byte, ips [][16]byte) []byte {
	var v []byte
	for _, ip := range ips {
		v = append(v, ip[:]...)
	}
	return AppendElement(dst, 0x0003, v)
}

// ParseACIPv6List decodes element 0x0003 (16-byte stride).
func ParseACIPv6List(v []byte) ([][16]byte, error) {
	if len(v) < 16 || len(v)%16 != 0 {
		return nil, ErrShortPacket
	}
	out := make([][16]byte, 0, len(v)/16)
	for off := 0; off < len(v); off += 16 {
		var ip [16]byte
		copy(ip[:], v[off:off+16])
		out = append(out, ip)
	}
	return out, nil
}

// AppendLocationData is element 0x001c (min 1 max 0x400): raw location.
func AppendLocationData(dst []byte, loc string) []byte {
	return AppendElement(dst, 0x001c, []byte(loc))
}

// ParseLocationData decodes element 0x001c.
func ParseLocationData(v []byte) (string, error) {
	if len(v) < 1 {
		return "", ErrShortPacket
	}
	return string(v), nil
}

// AppendWTPName is element 0x002d (min 1 max 0x400): raw name bytes.
func AppendWTPName(dst []byte, name string) []byte {
	return AppendElement(dst, 0x002d, []byte(name))
}

// AppendWTPBoardData is element 0x0026 (vendor flavor used by the join
// path): BE32 vendor + sub-elements {BE16 type, BE16 len, data}
// (cw_wtp_board_data_assemble family; parse in cweng/apelem.go).
func AppendWTPBoardData(dst []byte, vendor uint32, subs []ACDescriptorSubElement) []byte {
	v := AppendUint32BE(nil, vendor)
	for _, s := range subs {
		v = AppendUint16BE(v, s.Type)
		v = AppendUint16BE(v, uint16(len(s.Data)))
		v = append(v, s.Data...)
	}
	return AppendElement(dst, 0x0026, v)
}
