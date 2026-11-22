package capwap

// IEEE 802.11 element group (0x0400-0x0418 range). Fixture values from
// cw_cfg_update_req / cw_join_req (wire-level roundtrip targets).

// AppendMacOperation is element 0x0406 (min=max=16): radio config MAC
// operation parameters (beacon interval, DTIM, RTS/frag thresholds).
// Fixture: 01 00 092a 0000 092a 0000 0000 0000 0000 (radio=1, beacon=0x092a).
func AppendMacOperation(dst []byte, value [16]byte) []byte {
	return AppendElement(dst, 0x0406, value[:])
}

// AppendTxPower is element 0x0411 (min=max=4): radio_id + rsvd + BE16 power.
// Fixture: 01 00 0014 (radio=1, rsvd=0, power=20).
func AppendTxPower(dst []byte, radioID uint8, power uint16) []byte {
	v := []byte{radioID, 0}
	v = AppendUint16BE(v, power)
	return AppendElement(dst, 0x0411, v)
}

// ParseTxPower decodes element 0x0411 (radio_id, rsvd, power).
func ParseTxPower(v []byte) (uint8, uint8, uint16, error) {
	if len(v) != 4 {
		return 0, 0, 0, ErrShortPacket
	}
	return v[0], v[1], Uint16BE(v[2:]), nil
}

// AppendRadioConfig is element 0x0416 (min=max=16): radio configuration
// (mode, bandwidth, channel etc.). Fixture: 01 01 0801 0000 0000 64434e20 00.
func AppendRadioConfig(dst []byte, value [16]byte) []byte {
	return AppendElement(dst, 0x0416, value[:])
}

// AppendSupportedRates is element 0x0403 (IEEE 802.11 supported rates).
// min=max=8: rate set bytes.
func AppendSupportedRates(dst []byte, rates [8]byte) []byte {
	return AppendElement(dst, 0x0403, rates[:])
}

// AppendMultiDomain x = element 0x0404 (IEEE 802.11 multi-domain capability,
// min=max=4): BE16 first channel + BE16 number of channels.
func AppendMultiDomainCapability(dst []byte, firstCh, numCh uint16) []byte {
	v := AppendUint16BE(nil, firstCh)
	v = AppendUint16BE(v, numCh)
	return AppendElement(dst, 0x0404, v)
}
