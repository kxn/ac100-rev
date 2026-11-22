package capwap

import "encoding/binary"

// Simple fixed-width standard element builders (all verified against the
// vendor fixtures cw_join_rsp / cw_cfg_rsp / cw_dis_rsp and the corresponding
// cw_*_assemble functions listed in re/notes/elements.tsv).

// AppendResultCode — element 0x0021, BE32 (cw_result_code_assemble; min=max=4).
// 0 = success (fixture join rsp value 00000000).
func AppendResultCode(dst []byte, code uint32) []byte {
	return AppendElement(dst, 0x0021, binary.BigEndian.AppendUint32(nil, code))
}

// AppendCapwapTimers — element 0x000c, 2 bytes: discovery wait + echo interval
// (cw_capwap_timers_assemble; min=max=2). cfg_rsp fixture: 00 1e (30,30).
func AppendCapwapTimers(dst []byte, discovery uint8, echo uint8) []byte {
	return AppendElement(dst, 0x000c, []byte{discovery, echo})
}

// AppendDecryptionErrorReportPeriod — element 0x0010, BE24 (min=max=3).
// cfg_rsp fixture value 01 27 10.
func AppendDecryptionErrorReportPeriod(dst []byte, secs uint32) []byte {
	v := []byte{byte(secs >> 16), byte(secs >> 8), byte(secs)}
	return AppendElement(dst, 0x0010, v)
}

// AppendIdleTimeout — element 0x0017, BE32 (min=max=4).
func AppendIdleTimeout(dst []byte, secs uint32) []byte {
	return AppendElement(dst, 0x0017, binary.BigEndian.AppendUint32(nil, secs))
}

// AppendWTPFallback — element 0x0028, u8 (min=max=1).
func AppendWTPFallback(dst []byte, mode uint8) []byte {
	return AppendElement(dst, 0x0028, []byte{mode})
}

// AppendWTPMacType — element 0x002c, u8 (min=max=1).
func AppendWTPMacType(dst []byte, t uint8) []byte {
	return AppendElement(dst, 0x002c, []byte{t})
}

// AppendECNSupport — element 0x0035, u8 (min=max=1).
func AppendECNSupport(dst []byte, v uint8) []byte {
	return AppendElement(dst, 0x0035, []byte{v})
}

// AppendACIPv4List — element 0x0002: repeated BE32 addresses
// (cw_ac_ipv4_list_assemble; min 4 max 0x1000).
func AppendACIPv4List(dst []byte, ips [][4]byte) []byte {
	var v []byte
	for _, ip := range ips {
		v = append(v, ip[0], ip[1], ip[2], ip[3])
	}
	return AppendElement(dst, 0x0002, v)
}

// AppendCapwapLocalIPv4Address — element 0x001e: BE32 (min=max=4).
func AppendCapwapLocalIPv4Address(dst []byte, ip [4]byte) []byte {
	return AppendElement(dst, 0x001e, []byte{ip[0], ip[1], ip[2], ip[3]})
}

// AppendRadioAdministrativeState — element 0x001f: u8 radio id + u8 state
// (cw_radio_administrative_state_assemble; min=max=2).
func AppendRadioAdministrativeState(dst []byte, radioID uint8, adminState uint8) []byte {
	return AppendElement(dst, 0x001f, []byte{radioID, adminState})
}
