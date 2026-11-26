package capwap

// Batch-23: priv 0x3e/0x41/0x42/0x45/0x4d/0x53/0x54. Layouts from the
// vendor parse functions' retrieve sequences (cw_priv_*_parse addresses
// in the comments; rbytes lengths from the retrieve_bytes a2 argument).

// PrivSpecRssi is 0x3e: BE32 (cw_priv_spec_rssi_parse @0x5c11f8).
type PrivSpecRssi uint32

// AssembleValue writes the 4 bytes.
func (p PrivSpecRssi) AssembleValue() []byte { return AppendUint32BE(nil, uint32(p)) }

// ParsePrivSpecRssi decodes the 4 bytes.
func ParsePrivSpecRssi(v []byte) (PrivSpecRssi, error) {
	if len(v) != 4 {
		return 0, ErrShortPacket
	}
	return PrivSpecRssi(Uint32BE(v)), nil
}

// PrivApConfigChecksum is 0x41: 16 raw bytes
// (cw_priv_ap_config_checksum_parse @0x5a4870, rbytes(16)).
type PrivApConfigChecksum [16]byte

// AssembleValue returns the 16 bytes.
func (p PrivApConfigChecksum) AssembleValue() []byte { return append([]byte(nil), p[:]...) }

// ParsePrivApConfigChecksum decodes the 16 bytes.
func ParsePrivApConfigChecksum(v []byte) (PrivApConfigChecksum, error) {
	var out PrivApConfigChecksum
	if len(v) != 16 {
		return out, ErrShortPacket
	}
	copy(out[:], v)
	return out, nil
}

// PrivWechatIPList is 0x42: BE32 count + raw ip list
// (cw_priv_wechat_iplist_parse @0x5cb378).
type PrivWechatIPList struct {
	Count uint32
	Rest  []byte
}

// AssembleValue writes header + rest.
func (p PrivWechatIPList) AssembleValue() []byte {
	return append(AppendUint32BE(nil, p.Count), p.Rest...)
}

// ParsePrivWechatIPList decodes header + rest.
func ParsePrivWechatIPList(v []byte) (*PrivWechatIPList, error) {
	if len(v) < 4 {
		return nil, ErrShortPacket
	}
	return &PrivWechatIPList{Count: Uint32BE(v), Rest: append([]byte(nil), v[4:]...)}, nil
}

// PrivBwCtrl is 0x45: r8 r32 r32 r8 r32 r8 rbytes = 15-byte header + tail
// (cw_priv_bw_ctrl_parse @0x5ac66c).
type PrivBwCtrl struct {
	A    uint8
	W1   uint32
	W2   uint32
	B    uint8
	W3   uint32
	C    uint8
	Tail []byte
}

// AssembleValue writes header + tail.
func (p PrivBwCtrl) AssembleValue() []byte {
	b := []byte{p.A}
	b = AppendUint32BE(b, p.W1)
	b = AppendUint32BE(b, p.W2)
	b = append(b, p.B)
	b = AppendUint32BE(b, p.W3)
	b = append(b, p.C)
	return append(b, p.Tail...)
}

// ParsePrivBwCtrl decodes header + tail.
func ParsePrivBwCtrl(v []byte) (*PrivBwCtrl, error) {
	if len(v) < 15 {
		return nil, ErrShortPacket
	}
	p := &PrivBwCtrl{A: v[0], W1: Uint32BE(v[1:]), W2: Uint32BE(v[5:]),
		B: v[9], W3: Uint32BE(v[10:]), C: v[14],
		Tail: append([]byte(nil), v[15:]...)}
	return p, nil
}

// PrivStaIPList is 0x4d: BE32 count + per-sta {mac6, ip4}
// (cw_priv_sta_ip_list_parse @0x5c64f4: r32 rbytes(6) rip).
type PrivStaIPList struct {
	Count uint32
	Rows  []PrivStaIPRow
}

// PrivStaIPRow is one 10-byte row.
type PrivStaIPRow struct {
	MAC [6]byte
	IP  [4]byte
}

// AssembleValue writes count + rows.
func (p PrivStaIPList) AssembleValue() []byte {
	b := AppendUint32BE(nil, p.Count)
	for _, r := range p.Rows {
		b = append(b, r.MAC[:]...)
		b = append(b, r.IP[:]...)
	}
	return b
}

// ParsePrivStaIPList decodes count + 10-byte rows.
func ParsePrivStaIPList(v []byte) (*PrivStaIPList, error) {
	if len(v) < 4 {
		return nil, ErrShortPacket
	}
	p := &PrivStaIPList{Count: Uint32BE(v)}
	off := 4
	for off+10 <= len(v) {
		var r PrivStaIPRow
		copy(r.MAC[:], v[off:off+6])
		copy(r.IP[:], v[off+6:off+10])
		p.Rows = append(p.Rows, r)
		off += 10
	}
	if off != len(v) {
		return nil, ErrShortPacket
	}
	return p, nil
}

// PrivRssiStatistics is private0x53: load[8], noise[8], count32,
// then count * {MAC[6], per-radio RSSI[8]}; V6 6b2740, max400 rows.
type RssiStatisticsStation struct {
	MAC  [6]byte
	RSSI [8]int8
}
type PrivRssiStatistics struct {
	ChannelLoad [8]uint8
	NoiseFloor  [8]int8
	Stations    []RssiStatisticsStation
}

func (p PrivRssiStatistics) AssembleValue() []byte {
	b := append([]byte{}, p.ChannelLoad[:]...)
	for _, n := range p.NoiseFloor {
		b = append(b, byte(n))
	}
	b = AppendUint32BE(b, uint32(len(p.Stations)))
	for _, s := range p.Stations {
		b = append(b, s.MAC[:]...)
		for _, n := range s.RSSI {
			b = append(b, byte(n))
		}
	}
	return b
}
func ParsePrivRssiStatistics(v []byte) (*PrivRssiStatistics, error) {
	if len(v) < 20 {
		return nil, ErrShortPacket
	}
	n := Uint32BE(v[16:])
	if n > 400 || uint64(len(v)) != 20+uint64(n)*14 {
		return nil, ErrShortPacket
	}
	p := &PrivRssiStatistics{Stations: []RssiStatisticsStation{}}
	copy(p.ChannelLoad[:], v[:8])
	for i := range p.NoiseFloor {
		p.NoiseFloor[i] = int8(v[8+i])
	}
	for v = v[20:]; len(v) > 0; v = v[14:] {
		var s RssiStatisticsStation
		copy(s.MAC[:], v[:6])
		for i := range s.RSSI {
			s.RSSI[i] = int8(v[6+i])
		}
		p.Stations = append(p.Stations, s)
	}
	return p, nil
}

// PrivApStatistics is private0x54: a42-byte global/header followed by
// radio-count *32 and VAP-count *28. V6 69ed48/69e080; counts <=8/64.
type APStatisticsGlobal struct {
	CPUCount          uint8
	CPUUtilization    [8]byte
	MemoryUtilization uint8
	Capabilities      uint16
	Counters          [7]uint32
}
type APRadioStatistics struct {
	Radio              uint8     `json:"radio_id"`
	Channel            uint8     `json:"channel"`
	Bandwidth          uint16    `json:"bandwidth_code"`
	TxPower            uint16    `json:"power_dbm"`
	Capabilities       uint16    `json:"capabilities"`
	NoiseFloor         int8      `json:"noise_floor_dbm"`
	ChannelLoad        uint8     `json:"channel_load_percent"`
	RetryPercent       uint8     `json:"retry_percent"`
	LossPercent        uint8     `json:"loss_percent"`
	Counters           [4]uint32 `json:"rate_traffic_counters"`
	Interference       uint8     `json:"interference_percent"`
	UpLoad             uint8     `json:"up_load_percent"`
	DownLoad           uint8     `json:"down_load_percent"`
	WeakStationPercent uint8     `json:"weak_station_percent"`
}
type APVAPStatistics struct {
	Radio, WLAN               uint8
	BSSID                     [6]byte
	Capabilities              uint16
	RetryPercent, LossPercent uint8
	Counters                  [4]uint32
}
type PrivApStatistics struct {
	Global APStatisticsGlobal
	Radios []APRadioStatistics
	VAPs   []APVAPStatistics
}

func (p *PrivApStatistics) AssembleValue() []byte {
	g := p.Global
	b := []byte{byte(len(p.Radios)), byte(len(p.VAPs)), g.CPUCount}
	b = append(b, g.CPUUtilization[:]...)
	b = append(b, g.MemoryUtilization)
	b = AppendUint16BE(b, g.Capabilities)
	for _, v := range g.Counters {
		b = AppendUint32BE(b, v)
	}
	for _, r := range p.Radios {
		b = append(b, r.Radio, r.Channel)
		for _, v := range []uint16{r.Bandwidth, r.TxPower, r.Capabilities} {
			b = AppendUint16BE(b, v)
		}
		b = append(b, byte(r.NoiseFloor), r.ChannelLoad, r.RetryPercent, r.LossPercent)
		for _, v := range r.Counters {
			b = AppendUint32BE(b, v)
		}
		b = append(b, r.Interference, r.UpLoad, r.DownLoad, r.WeakStationPercent)
	}
	for _, v := range p.VAPs {
		b = append(b, v.Radio, v.WLAN)
		b = append(b, v.BSSID[:]...)
		b = AppendUint16BE(b, v.Capabilities)
		b = append(b, v.RetryPercent, v.LossPercent)
		for _, n := range v.Counters {
			b = AppendUint32BE(b, n)
		}
	}
	return b
}
func ParsePrivApStatistics(v []byte) (*PrivApStatistics, error) {
	if len(v) < 42 || v[0] > 8 || v[1] > 64 || v[2] < 1 || v[2] > 8 || len(v) != 42+int(v[0])*32+int(v[1])*28 {
		return nil, ErrShortPacket
	}
	nr, nv := int(v[0]), int(v[1])
	p := &PrivApStatistics{Radios: []APRadioStatistics{}, VAPs: []APVAPStatistics{}}
	g := &p.Global
	g.CPUCount = v[2]
	copy(g.CPUUtilization[:], v[3:11])
	g.MemoryUtilization = v[11]
	g.Capabilities = Uint16BE(v[12:])
	for i := range g.Counters {
		g.Counters[i] = Uint32BE(v[14+i*4:])
	}
	v = v[42:]
	for i := 0; i < nr; i++ {
		r := APRadioStatistics{Radio: v[0], Channel: v[1], Bandwidth: Uint16BE(v[2:]), TxPower: Uint16BE(v[4:]), Capabilities: Uint16BE(v[6:]), NoiseFloor: int8(v[8]), ChannelLoad: v[9], RetryPercent: v[10], LossPercent: v[11], Interference: v[28], UpLoad: v[29], DownLoad: v[30], WeakStationPercent: v[31]}
		for j := range r.Counters {
			r.Counters[j] = Uint32BE(v[12+j*4:])
		}
		p.Radios = append(p.Radios, r)
		v = v[32:]
	}
	for i := 0; i < nv; i++ {
		r := APVAPStatistics{Radio: v[0], WLAN: v[1], Capabilities: Uint16BE(v[8:]), RetryPercent: v[10], LossPercent: v[11]}
		copy(r.BSSID[:], v[2:8])
		for j := range r.Counters {
			r.Counters[j] = Uint32BE(v[12+j*4:])
		}
		p.VAPs = append(p.VAPs, r)
		v = v[28:]
	}
	return p, nil
}
