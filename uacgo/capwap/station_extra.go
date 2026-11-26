package capwap

// V6 private c6, cw_priv_sta_extra_info_parse @68ea40. The generic TLVs
// remain byte values; subtype8 embeds count +9-byte MLO link records.
type StationExtra struct {
	MAC    [6]byte
	Fields []Element
}

func ParseStationExtra(v []byte) ([]StationExtra, error) {
	if len(v) < 2 {
		return nil, ErrShortPacket
	}
	count := int(Uint16BE(v))
	v = v[2:]
	rows := make([]StationExtra, 0)
	for i := 0; i < count; i++ {
		if len(v) < 8 {
			return nil, ErrShortPacket
		}
		row := StationExtra{}
		copy(row.MAC[:], v[:6])
		fields := int(Uint16BE(v[6:]))
		v = v[8:]
		for j := 0; j < fields; j++ {
			if len(v) < 4 {
				return nil, ErrShortPacket
			}
			typ, n := Uint16BE(v), int(Uint16BE(v[2:]))
			v = v[4:]
			if n > len(v) {
				return nil, ErrShortPacket
			}
			b := v[:n]
			v = v[n:]
			switch typ {
			case 0:
				if len(b) < 1 || len(b) != 1+3*int(b[0]) {
					return nil, ErrLenMismatch
				}
			case 4:
				if len(b) != 16 {
					return nil, ErrLenMismatch
				}
			case 7, 10:
				if len(b) != 4 {
					return nil, ErrLenMismatch
				}
			case 8:
				if len(b) < 1 || len(b) != 1+9*int(b[0]) {
					return nil, ErrLenMismatch
				}
			case 9:
				if len(b) != 3 {
					return nil, ErrLenMismatch
				}
			}
			row.Fields = append(row.Fields, Element{Type: typ, Value: append([]byte{}, b...)})
		}
		rows = append(rows, row)
	}
	if len(v) != 0 {
		return nil, ErrLenMismatch
	}
	return rows, nil
}
