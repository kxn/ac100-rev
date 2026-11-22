package capwap

// Batch-25: the 0x54 AP statistics row view (cw_priv_ap_statistics_parse
// @0x5a7f04). The element is variable-length: a 42-byte header (radio
// count ≤8, ssid count ≤0x40), then radio rows (32B each) and ssid rows
// (28B each) — max 0x2a + 8×0x20 + 0x40×0x1c = 0x82a exactly the
// registry max. The ssid row is the AC's BSS table feed
// (stats_db_ssid_update → stats_db_bssid_update).

// ApStatsRadioRow is one 32-byte radio statistics row.
type ApStatsRadioRow struct {
	RadioID uint8
	Raw     [31]byte
}

// ApStatsSsidRow is one 28-byte SSID/BSS statistics row:
// u8 radio, u8 wlan, bssid[6], u16, u8, u8, u32×4.
type ApStatsSsidRow struct {
	RadioID uint8
	WLANID  uint8
	BSSID   [6]byte
	Raw     [20]byte // remaining statistics bytes
}

// PrivApStatisticsRows is the structured view of 0x54.
type PrivApStatisticsRows struct {
	RadioCount uint8
	SsidCount  uint8
	Head       [40]byte // the fixed statistics header after the counts
	Radios     []ApStatsRadioRow
	Ssids      []ApStatsSsidRow
}

// ParsePrivApStatisticsRows decodes the variable 0x54 value.
func ParsePrivApStatisticsRows(v []byte) (*PrivApStatisticsRows, error) {
	if len(v) < 0x2a {
		return nil, ErrShortPacket
	}
	p := &PrivApStatisticsRows{RadioCount: v[0], SsidCount: v[1]}
	if p.RadioCount > 8 || p.SsidCount > 0x40 {
		return nil, ErrShortPacket
	}
	copy(p.Head[:], v[2:42])
	off := 42
	for i := 0; i < int(p.RadioCount); i++ {
		if off+32 > len(v) {
			return nil, ErrShortPacket
		}
		var r ApStatsRadioRow
		r.RadioID = v[off]
		copy(r.Raw[:], v[off+1:off+32])
		p.Radios = append(p.Radios, r)
		off += 32
	}
	for i := 0; i < int(p.SsidCount); i++ {
		if off+28 > len(v) {
			return nil, ErrShortPacket
		}
		var s ApStatsSsidRow
		s.RadioID, s.WLANID = v[off], v[off+1]
		copy(s.BSSID[:], v[off+2:off+8])
		copy(s.Raw[:], v[off+8:off+28])
		p.Ssids = append(p.Ssids, s)
		off += 28
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return p, nil
}

// AssembleValue writes the variable 0x54 value.
func (p PrivApStatisticsRows) AssembleValue() []byte {
	b := []byte{p.RadioCount, p.SsidCount}
	b = append(b, p.Head[:]...)
	for _, r := range p.Radios {
		b = append(b, r.RadioID)
		b = append(b, r.Raw[:]...)
	}
	for _, s := range p.Ssids {
		b = append(b, s.RadioID, s.WLANID)
		b = append(b, s.BSSID[:]...)
		b = append(b, s.Raw[:]...)
	}
	return b
}
