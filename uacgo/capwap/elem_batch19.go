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

// PrivRoamingTrigger is 0x58. Wire (cw_priv_roaming_trigger_parse
// @0x5bd644 retrieve sequence r8 r8 r8 r32 rbytes(6) r8 r8 r8 r8
// rbytes(6) r8 r8 r8 = 26 bytes):
// {u8 a, u8 b, u8 c, BE32, mac1[6], u8×4, mac2[6], u8×3}.
type PrivRoamingTrigger struct {
	A, B, C uint8
	W       uint32
	MAC1    [6]byte
	U8a     uint8
	U8b     uint8
	U8c     uint8
	U8d     uint8
	MAC2    [6]byte
	Tail    [3]uint8
}

// AssembleValue writes the 26 bytes.
func (p PrivRoamingTrigger) AssembleValue() []byte {
	b := []byte{p.A, p.B, p.C}
	b = AppendUint32BE(b, p.W)
	b = append(b, p.MAC1[:]...)
	b = append(b, p.U8a, p.U8b, p.U8c, p.U8d)
	b = append(b, p.MAC2[:]...)
	return append(b, p.Tail[:]...)
}

// ParsePrivRoamingTrigger decodes the 26 bytes.
func ParsePrivRoamingTrigger(v []byte) (*PrivRoamingTrigger, error) {
	if len(v) != 26 {
		return nil, ErrShortPacket
	}
	p := &PrivRoamingTrigger{A: v[0], B: v[1], C: v[2], W: Uint32BE(v[3:])}
	copy(p.MAC1[:], v[7:13])
	p.U8a, p.U8b, p.U8c, p.U8d = v[13], v[14], v[15], v[16]
	copy(p.MAC2[:], v[17:23])
	copy(p.Tail[:], v[23:26])
	return p, nil
}

// PrivRoamingCalcResult is 0x59 (min 10 max 0x2c8a):
// u8 a + u8 b + BE32 count + entries
// (cw_priv_roaming_calculate_result_parse @0x5bc118.)
type PrivRoamingCalcResult struct {
	A    uint8
	B    uint32
	Data []byte
}

// AssembleValue writes header + data.
func (p PrivRoamingCalcResult) AssembleValue() []byte {
	b := []byte{p.A}
	b = AppendUint32BE(b, p.B)
	return append(b, p.Data...)
}

// ParsePrivRoamingCalcResult decodes header + data.
func ParsePrivRoamingCalcResult(v []byte) (*PrivRoamingCalcResult, error) {
	if len(v) < 5 {
		return nil, ErrShortPacket
	}
	p := &PrivRoamingCalcResult{A: v[0], B: Uint32BE(v[1:5])}
	p.Data = append([]byte(nil), v[5:]...)
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
