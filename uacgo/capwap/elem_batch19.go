package capwap

// Batch-19: remaining private elements (roaming/mesh/capability).
// Field orders from vendor parse sequences.

// PrivFailStation is 0x56 (min 4): BE32 count + count × records.
// Record wire (cw_priv_fail_station_parse @0x5b1020 retrieve sequence
// rbytes(6) r8 r8 r8 r32 r32): 6B mac + 3×u8 + 2×BE32 = 17 bytes.
type PrivFailStation struct {
	Count   uint32
	Records [][]byte // verbatim 17B records
}

// AssembleValue writes count + records (flattened).
func (p PrivFailStation) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.Count)
	for _, rec := range p.Records {
		b = append(b, rec...)
	}
	return b
}

// ParsePrivFailStation decodes count + 17B records.
func ParsePrivFailStation(v []byte) (*PrivFailStation, error) {
	if len(v) < 4 {
		return nil, ErrShortPacket
	}
	p := &PrivFailStation{Count: Uint32BE(v)}
	off := 4
	for off+17 <= len(v) {
		p.Records = append(p.Records, append([]byte(nil), v[off:off+17]...))
		off += 17
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return p, nil
}

// RoamingTriggerNeighbor is one 9-byte neighbor measurement of 0x58
// (cw_priv_roaming_trigger_parse @0x5bd644 retrieve rbytes(6) r8 r8 r8,
// AC binary): bssid + rcpi + rsni + channel. Field order was
// cross-checked for consistency against the AP implementation
// (校验 only — notes/apfw-xap5407gc-crosscheck.md §4).
type RoamingTriggerNeighbor struct {
	BSSID   [6]byte
	RCPI    uint8
	RSNI    uint8
	Channel uint8
}

// RoamingTriggerSta is one 10-byte station record of 0x58 plus its
// neighbor list (wire: mac6 + wlan_id + rssi + band_mode + neighbor_cnt,
// then neighbor_cnt × 9-byte neighbors).
type RoamingTriggerSta struct {
	MAC       [6]byte
	WLANID    uint8
	RSSI      int8
	BandMode  uint8
	Neighbors []RoamingTriggerNeighbor // ≤ 12 (parse guard 0xc)
}

// PrivRoamingTrigger is private element 0x58 "roaming trigger request"
// (min 7 max 0x5c37): the WTP's low-RSSI station list report. Wire from
// the AC's cw_priv_roaming_trigger_parse (retrieve sequence r8 r8 r8 r32
// + per-sta rbytes(6) r8 r8 r8 r8 + per-neighbor rbytes(6) r8 r8 r8):
//
//	u8 radio_id, u8 channel_load(%), s8 noise_floor, BE32 sta_count(≤200)
//	sta_count × { mac6, u8 wlan_id, s8 rssi, u8 band_mode, u8 neighbor_cnt,
//	              neighbor_cnt × { bssid6, u8 rcpi, u8 rsni, u8 channel } }
type PrivRoamingTrigger struct {
	RadioID     uint8
	ChannelLoad uint8
	NoiseFloor  int8
	Stations    []RoamingTriggerSta // ≤ 200 (parse guard 0xc8)
}

// AssembleValue writes the trigger wire image.
func (p PrivRoamingTrigger) AssembleValue() []byte {
	b := []byte{p.RadioID, p.ChannelLoad, byte(p.NoiseFloor)}
	b = AppendUint32BE(b, uint32(len(p.Stations)))
	for _, st := range p.Stations {
		b = append(b, st.MAC[:]...)
		b = append(b, st.WLANID, byte(st.RSSI), st.BandMode, byte(len(st.Neighbors)))
		for _, n := range st.Neighbors {
			b = append(b, n.BSSID[:]...)
			b = append(b, n.RCPI, n.RSNI, n.Channel)
		}
	}
	return b
}

// ParsePrivRoamingTrigger decodes the trigger wire image.
func ParsePrivRoamingTrigger(v []byte) (*PrivRoamingTrigger, error) {
	if len(v) < 7 {
		return nil, ErrShortPacket
	}
	p := &PrivRoamingTrigger{RadioID: v[0], ChannelLoad: v[1], NoiseFloor: int8(v[2])}
	cnt := Uint32BE(v[3:])
	if cnt > 200 {
		return nil, ErrShortPacket
	}
	off := 7
	for i := uint32(0); i < cnt; i++ {
		if off+10 > len(v) {
			return nil, ErrShortPacket
		}
		var st RoamingTriggerSta
		copy(st.MAC[:], v[off:off+6])
		st.WLANID = v[off+6]
		st.RSSI = int8(v[off+7])
		st.BandMode = v[off+8]
		nc := int(v[off+9])
		if nc > 12 {
			return nil, ErrShortPacket
		}
		off += 10
		for j := 0; j < nc; j++ {
			if off+9 > len(v) {
				return nil, ErrShortPacket
			}
			var n RoamingTriggerNeighbor
			copy(n.BSSID[:], v[off:off+6])
			n.RCPI, n.RSNI, n.Channel = v[off+6], v[off+7], v[off+8]
			st.Neighbors = append(st.Neighbors, n)
			off += 9
		}
		p.Stations = append(p.Stations, st)
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return p, nil
}

// RoamingCalcRadioEntry is one 10-byte per-radio target of a 0x59
// station record (ap_index + radio_id + wlan_id + bssid6 + channel).
type RoamingCalcRadioEntry struct {
	APIndex uint8
	RadioID uint8
	WLANID  uint8
	BSSID   [6]byte
	Channel uint8
}

// RoamingCalcSta is one 23-byte station record of 0x59 plus its radio
// entries (wire: mac6 + ap_union_bitmap16 + radio_count, then
// radio_count × 10-byte entries). The bitmap is over the AP union in
// wire order.
type RoamingCalcSta struct {
	MAC           [6]byte
	APUnionBitmap [16]byte
	Radios        []RoamingCalcRadioEntry // ≤ 6 (parse guard)
}

// PrivRoamingCalcResult is private element 0x59 "roaming calculate
// result request" (min 10 max 0x2c8a): the AC's computed roam targets.
// Wire (cw_priv_roaming_calculate_result_parse @0x5bc118 retrieve r8 r8
// r32 r32 + union rbytes(6)×N + per-sta rbytes(6) rbytes(16) r8 +
// per-radio r8 r8 r8 rbytes(6) r8):
//
//	u8 current_ap, u8 radio_id, BE32 sta_count(≤0x80), BE32 ap_union_count(≤0x80)
//	ap_union_count × mac6
//	sta_count × { mac6, bitmap16, u8 radio_count(≤6),
//	              radio_count × { u8 ap_index, u8 radio_id, u8 wlan_id,
//	                              bssid6, u8 channel } }
type PrivRoamingCalcResult struct {
	CurrentAP uint8
	RadioID   uint8
	APUnion   [][6]byte
	Stations  []RoamingCalcSta
}

// AssembleValue writes the result wire image.
func (p PrivRoamingCalcResult) AssembleValue() []byte {
	b := []byte{p.CurrentAP, p.RadioID}
	b = AppendUint32BE(b, uint32(len(p.Stations)))
	b = AppendUint32BE(b, uint32(len(p.APUnion)))
	for _, m := range p.APUnion {
		b = append(b, m[:]...)
	}
	for _, st := range p.Stations {
		b = append(b, st.MAC[:]...)
		b = append(b, st.APUnionBitmap[:]...)
		b = append(b, byte(len(st.Radios)))
		for _, r := range st.Radios {
			b = append(b, r.APIndex, r.RadioID, r.WLANID)
			b = append(b, r.BSSID[:]...)
			b = append(b, r.Channel)
		}
	}
	return b
}

// ParsePrivRoamingCalcResult decodes the result wire image.
func ParsePrivRoamingCalcResult(v []byte) (*PrivRoamingCalcResult, error) {
	if len(v) < 10 {
		return nil, ErrShortPacket
	}
	p := &PrivRoamingCalcResult{CurrentAP: v[0], RadioID: v[1]}
	staCnt, unionCnt := Uint32BE(v[2:]), Uint32BE(v[6:])
	if staCnt > 0x80 || unionCnt > 0x80 {
		return nil, ErrShortPacket
	}
	off := 10
	if off+6*int(unionCnt) > len(v) {
		return nil, ErrShortPacket
	}
	for i := uint32(0); i < unionCnt; i++ {
		var m [6]byte
		copy(m[:], v[off:off+6])
		p.APUnion = append(p.APUnion, m)
		off += 6
	}
	for i := uint32(0); i < staCnt; i++ {
		if off+23 > len(v) {
			return nil, ErrShortPacket
		}
		var st RoamingCalcSta
		copy(st.MAC[:], v[off:off+6])
		copy(st.APUnionBitmap[:], v[off+6:off+22])
		rc := int(v[off+22])
		if rc > 6 {
			return nil, ErrShortPacket
		}
		off += 23
		for j := 0; j < rc; j++ {
			if off+10 > len(v) {
				return nil, ErrShortPacket
			}
			r := RoamingCalcRadioEntry{
				APIndex: v[off], RadioID: v[off+1], WLANID: v[off+2], Channel: v[off+9],
			}
			copy(r.BSSID[:], v[off+3:off+9])
			st.Radios = append(st.Radios, r)
			off += 10
		}
		p.Stations = append(p.Stations, st)
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return p, nil
}

// PrivApMloSwitch is 0xb6 (min=max=1): u8.
type PrivApMloSwitch uint8

// AssembleValue writes the byte.
func (p PrivApMloSwitch) AssembleValue() []byte { return []byte{byte(p)} }

// ParsePrivApMloSwitch decodes the byte.
func ParsePrivApMloSwitch(v []byte) (PrivApMloSwitch, error) {
	if len(v) != 1 {
		return 0, ErrShortPacket
	}
	return PrivApMloSwitch(v[0]), nil
}
