package capwap

// LegacyAssociation is private 0x02. V6 cw_priv_sta_assoc_req_assemble and
// the physical AP agree: optional negative RSSI word precedes a 32-bit
// backfill length. The backfill must be echoed in private 0x04's permit.
type LegacyAssociation struct {
	Radio, WLAN byte
	MAC         [6]byte
	RSSI        *int32
	Backfill    []byte
}

func ParseLegacyAssociation(b []byte) (*LegacyAssociation, error) {
	if len(b) < 12 || b[0] == 0 || b[0] >= 32 || b[1] == 0 || b[1] > 16 {
		return nil, ErrShortPacket
	}
	a := &LegacyAssociation{Radio: b[0], WLAN: b[1]}
	copy(a.MAC[:], b[2:8])
	off := 8
	if int32(Uint32BE(b[off:])) < 0 {
		v := int32(Uint32BE(b[off:]))
		a.RSSI = &v
		off += 4
	}
	if len(b) < off+4 {
		return nil, ErrShortPacket
	}
	n := int(Uint32BE(b[off:]))
	off += 4
	if n > 300 || n != len(b)-off {
		return nil, ErrLenMismatch
	}
	a.Backfill = append([]byte{}, b[off:]...)
	return a, nil
}
func (a LegacyAssociation) Result(result uint32) []byte {
	b := append([]byte{a.Radio, a.WLAN}, a.MAC[:]...)
	b = AppendUint32BE(b, result)
	b = AppendUint32BE(b, uint32(len(a.Backfill)))
	return append(b, a.Backfill...)
}

func (a LegacyAssociation) AssembleValue() []byte {
	b := append([]byte{a.Radio, a.WLAN}, a.MAC[:]...)
	if a.RSSI != nil {
		b = AppendUint32BE(b, uint32(*a.RSSI))
	}
	b = AppendUint32BE(b, uint32(len(a.Backfill)))
	return append(b, a.Backfill...)
}
