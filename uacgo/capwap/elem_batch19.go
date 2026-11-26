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

// PrivRoamingTrigger is 0x58. V6 @0x682a2c: header 7 bytes,
// count <=200, variable station rows with <=12 neighbor reports per row.
// The old 26-byte prototype encoded one row as the entire message.
type RoamNeighborReport struct {
	BSSID        [6]byte
	Signal, B, C uint8
}
type RoamTriggerStation struct {
	MAC                 [6]byte
	WLAN, Reason, Flags uint8
	Neighbors           []RoamNeighborReport
}
type PrivRoamingTrigger struct {
	Radio, ChannelLoad uint8
	NoiseFloor         int8
	Stations           []RoamTriggerStation
}

func (p PrivRoamingTrigger) AssembleValue() []byte {
	b := AppendUint32BE([]byte{p.Radio, p.ChannelLoad, byte(p.NoiseFloor)}, uint32(len(p.Stations)))
	for _, s := range p.Stations {
		b = append(b, s.MAC[:]...)
		b = append(b, s.WLAN, s.Reason, s.Flags, byte(len(s.Neighbors)))
		for _, n := range s.Neighbors {
			b = append(b, n.BSSID[:]...)
			b = append(b, n.Signal, n.B, n.C)
		}
	}
	return b
}
func ParsePrivRoamingTrigger(v []byte) (*PrivRoamingTrigger, error) {
	if len(v) < 7 {
		return nil, ErrShortPacket
	}
	n := Uint32BE(v[3:])
	if n > 200 {
		return nil, ErrShortPacket
	}
	p := &PrivRoamingTrigger{Radio: v[0], ChannelLoad: v[1], NoiseFloor: int8(v[2])}
	v = v[7:]
	for i := uint32(0); i < n; i++ {
		if len(v) < 10 || v[9] > 12 {
			return nil, ErrShortPacket
		}
		var s RoamTriggerStation
		copy(s.MAC[:], v)
		s.WLAN, s.Reason, s.Flags = v[6], v[7], v[8]
		count := int(v[9])
		v = v[10:]
		if len(v) < count*9 {
			return nil, ErrShortPacket
		}
		for j := 0; j < count; j++ {
			var r RoamNeighborReport
			copy(r.BSSID[:], v)
			r.Signal, r.B, r.C = v[6], v[7], v[8]
			s.Neighbors = append(s.Neighbors, r)
			v = v[9:]
		}
		p.Stations = append(p.Stations, s)
	}
	if len(v) != 0 {
		return nil, ErrShortPacket
	}
	return p, nil
}

// The 16-byte AP bitmap indexes the message's AP union; each station has
// at most six {AP index,radio,WLAN,BSSID[6],channel} candidate records.
type RoamCandidate struct {
	APIndex, Radio, WLAN uint8
	BSSID                [6]byte
	Channel              uint8
}
type RoamResultStation struct {
	MAC        [6]byte
	APBitmap   [16]byte
	Candidates []RoamCandidate
}
type PrivRoamingCalcResult struct {
	Radio, SourceAPIndex uint8
	APs                  [][6]byte
	Stations             []RoamResultStation
}

func (p PrivRoamingCalcResult) AssembleValue() []byte {
	b := AppendUint32BE([]byte{p.SourceAPIndex, p.Radio}, uint32(len(p.Stations)))
	b = AppendUint32BE(b, uint32(len(p.APs)))
	for _, a := range p.APs {
		b = append(b, a[:]...)
	}
	for _, s := range p.Stations {
		b = append(b, s.MAC[:]...)
		b = append(b, s.APBitmap[:]...)
		b = append(b, byte(len(s.Candidates)))
		for _, c := range s.Candidates {
			b = append(b, c.APIndex, c.Radio, c.WLAN)
			b = append(b, c.BSSID[:]...)
			b = append(b, c.Channel)
		}
	}
	return b
}
func ParsePrivRoamingCalcResult(v []byte) (*PrivRoamingCalcResult, error) {
	if len(v) < 10 {
		return nil, ErrShortPacket
	}
	count, aps := Uint32BE(v[2:]), Uint32BE(v[6:])
	if count > 128 || aps > 128 {
		return nil, ErrShortPacket
	}
	p := &PrivRoamingCalcResult{Radio: v[1], SourceAPIndex: v[0]}
	v = v[10:]
	if len(v) < int(aps)*6 {
		return nil, ErrShortPacket
	}
	for i := uint32(0); i < aps; i++ {
		var a [6]byte
		copy(a[:], v)
		p.APs = append(p.APs, a)
		v = v[6:]
	}
	if aps > 0 && uint32(p.SourceAPIndex) >= aps {
		return nil, ErrShortPacket
	}
	for i := uint32(0); i < count; i++ {
		if len(v) < 23 || v[22] > 6 {
			return nil, ErrShortPacket
		}
		var s RoamResultStation
		copy(s.MAC[:], v)
		copy(s.APBitmap[:], v[6:22])
		n := int(v[22])
		v = v[23:]
		if len(v) < n*10 {
			return nil, ErrShortPacket
		}
		for j := 0; j < n; j++ {
			c := RoamCandidate{APIndex: v[0], Radio: v[1], WLAN: v[2], Channel: v[9]}
			if uint32(c.APIndex) >= aps {
				return nil, ErrShortPacket
			}
			copy(c.BSSID[:], v[3:9])
			s.Candidates = append(s.Candidates, c)
			v = v[10:]
		}
		p.Stations = append(p.Stations, s)
	}
	if len(v) != 0 {
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
