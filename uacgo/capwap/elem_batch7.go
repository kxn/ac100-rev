package capwap

// Batch-7 standard elements (lengths per elements.tsv; field orders from
// the vendor assemble functions).

// AppendACTimestamp is element 0x0006 (BE32, min=max=4;
// cw_ac_timestamp_assemble: single restore32).
func AppendACTimestamp(dst []byte, ts uint32) []byte {
	return AppendElement(dst, 0x0006, AppendUint32BE(nil, ts))
}

// ParseACTimestamp decodes element 0x0006.
func ParseACTimestamp(v []byte) (uint32, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return Uint32BE(v), nil
}

// AppendMaximumMessageLength is element 0x001d (BE16, min=max=2;
// cw_maximum_message_length_assemble: single restore16).
func AppendMaximumMessageLength(dst []byte, n uint16) []byte {
	return AppendElement(dst, 0x001d, AppendUint16BE(nil, n))
}

// ParseMaximumMessageLength decodes element 0x001d.
func ParseMaximumMessageLength(v []byte) (uint16, error) {
	if len(v) != 2 {
		return 0, ErrShortPacket
	}
	return Uint16BE(v), nil
}

// AppendRadioOperationalState is element 0x0020 (3 bytes: radio id + state
// + cause; cw_radio_operational_state_assemble: restore8 ×3).
func AppendRadioOperationalState(dst []byte, radioID, state, cause uint8) []byte {
	return AppendElement(dst, 0x0020, []byte{radioID, state, cause})
}

// ParseRadioOperationalState decodes element 0x0020.
func ParseRadioOperationalState(v []byte) (radioID, state, cause uint8, err error) {
	if len(v) != 3 {
		return 0, 0, 0, ErrShortPacket
	}
	return v[0], v[1], v[2], nil
}

// AppendStatisticsTimer is element 0x0024 (BE16, min=max=2;
// cw_statistics_timer_assemble: single restore16).
func AppendStatisticsTimer(dst []byte, secs uint16) []byte {
	return AppendElement(dst, 0x0024, AppendUint16BE(nil, secs))
}

// ParseStatisticsTimer decodes element 0x0024.
func ParseStatisticsTimer(v []byte) (uint16, error) {
	if len(v) != 2 {
		return 0, ErrShortPacket
	}
	return Uint16BE(v), nil
}

// AppendSessionID is element 0x0023 (min=max=16 raw;
// cw_session_id_assemble: raw bytes).
func AppendSessionID(dst []byte, id [16]byte) []byte {
	return AppendElement(dst, 0x0023, id[:])
}

// ParseSessionID decodes element 0x0023.
func ParseSessionID(v []byte) ([16]byte, error) {
	var out [16]byte
	if len(v) != 16 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// AppendCapwapLocalIPv6Address is element 0x001f-family sibling 0x0036
// (16 raw bytes; cw_capwap_local_ipv6_address_assemble).
func AppendCapwapLocalIPv6Address(dst []byte, ip [16]byte) []byte {
	return AppendElement(dst, 0x0036, ip[:])
}

// ParseCapwapLocalIPv6Address decodes element 0x0036.
func ParseCapwapLocalIPv6Address(v []byte) ([16]byte, error) {
	var out [16]byte
	if len(v) != 16 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}
