package capwap

// Remaining private elements (batch 2), each validated by fixture payload
// roundtrip or disassembly field order.

// PrivAcInfo is private element 0x1b "private ac info" (min=max=6): 6 raw
// bytes (radio/bssid pair in the join fixture). Roundtrip target: the
// cw_join_rsp envelope payload 085700c21fa0.
// cw_priv_ac_info_assemble @0x5a2c78.
type PrivAcInfo [6]byte

// AssembleValue returns the 6 bytes.
func (p PrivAcInfo) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParsePrivAcInfo decodes the 6 value bytes.
func ParsePrivAcInfo(v []byte) (PrivAcInfo, error) {
	var out PrivAcInfo
	if len(v) != 6 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// PrivPortalSyn is private element 0x2a "portal syn" (min 2 max 0xc800):
// BE16 length + raw payload. cw_priv_portal_syn_parse @0x5b8f7c.
type PrivPortalSyn struct {
	Payload []byte
}

// AssembleValue writes len+payload.
func (p PrivPortalSyn) AssembleValue() []byte {
	b := AppendUint16BE(nil, uint16(len(p.Payload)))
	return append(b, p.Payload...)
}

// ParsePrivPortalSyn decodes len+payload (exact consumption).
func ParsePrivPortalSyn(v []byte) (*PrivPortalSyn, error) {
	if len(v) < 2 {
		return nil, ErrShortPacket
	}
	n := int(Uint16BE(v))
	if 2+n != len(v) {
		return nil, ErrShortPacket
	}
	return &PrivPortalSyn{Payload: append([]byte(nil), v[2:]...)}, nil
}

// PrivApdbInfo is private element 0x51 "private apdb info": raw capability
// blob the AP self-reports (min 2); the AC merges it into the negotiated
// apdb (apdb_pkt_init listeners, registry.tsv prio 256). Raw carrier.
type PrivApdbInfo []byte

// AssembleValue returns the blob.
func (p PrivApdbInfo) AssembleValue() []byte { return append([]byte(nil), p...) }

// ParsePrivApdbInfo keeps the blob verbatim (min length 2 per table).
func ParsePrivApdbInfo(v []byte) (PrivApdbInfo, error) {
	if len(v) < 2 {
		return nil, ErrShortPacket
	}
	return PrivApdbInfo(append([]byte(nil), v...)), nil
}

// PrivStatisticsControl is private element 0x55 (min=max=9):
// u8×3 + BE16×3. cw_priv_statistics_control_assemble @0x5c83dc.
type PrivStatisticsControl struct {
	A, B, C uint8
	D, E, F uint16
}

// AssembleValue writes the 9 bytes.
func (p PrivStatisticsControl) AssembleValue() []byte {
	b := []byte{p.A, p.B, p.C}
	b = AppendUint16BE(b, p.D)
	b = AppendUint16BE(b, p.E)
	return AppendUint16BE(b, p.F)
}

// ParsePrivStatisticsControl decodes the 9 bytes.
func ParsePrivStatisticsControl(v []byte) (*PrivStatisticsControl, error) {
	if len(v) != 9 {
		return nil, ErrShortPacket
	}
	return &PrivStatisticsControl{
		A: v[0], B: v[1], C: v[2],
		D: Uint16BE(v[3:]), E: Uint16BE(v[5:]), F: Uint16BE(v[7:]),
	}, nil
}

// PrivRoamingControl is private element 0x57 (min=max=36): 36 raw bytes.
// cw_priv_roaming_control_assemble @0x5bcb9c.
type PrivRoamingControl [36]byte

// AssembleValue returns the 36 bytes.
func (p PrivRoamingControl) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParsePrivRoamingControl decodes the 36 bytes.
func ParsePrivRoamingControl(v []byte) (PrivRoamingControl, error) {
	var out PrivRoamingControl
	if len(v) != 36 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// PrivStatPrd is private element 0x0c "private state report period"
// (min=max=8): two BE32 words. cw_priv_stat_prd_assemble @0x5c8090.
type PrivStatPrd struct {
	A uint32
	B uint32
}

// AssembleValue writes the 8 bytes.
func (p PrivStatPrd) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.A)
	return AppendUint32BE(b, p.B)
}

// ParsePrivStatPrd decodes the 8 bytes.
func ParsePrivStatPrd(v []byte) (*PrivStatPrd, error) {
	if len(v) != 8 {
		return nil, ErrShortPacket
	}
	return &PrivStatPrd{A: Uint32BE(v), B: Uint32BE(v[4:])}, nil
}

// byte-order helpers shared by the private codecs.

// AppendUint16BE appends a big-endian u16.
func AppendUint16BE(b []byte, v uint16) []byte {
	return append(b, byte(v>>8), byte(v))
}

// AppendUint32BE appends a big-endian u32.
func AppendUint32BE(b []byte, v uint32) []byte {
	return append(b, byte(v>>24), byte(v>>16), byte(v>>8), byte(v))
}

// Uint16BE reads a big-endian u16.
func Uint16BE(b []byte) uint16 { return uint16(b[0])<<8 | uint16(b[1]) }

// Uint32BE reads a big-endian u32.
func Uint32BE(b []byte) uint32 {
	return uint32(b[0])<<24 | uint32(b[1])<<16 | uint32(b[2])<<8 | uint32(b[3])
}
