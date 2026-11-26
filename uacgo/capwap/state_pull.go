package capwap

import "fmt"

// Private 0xbd, cw_priv_ac_msg_pull_parse @6a0c24. A station list here
// supplies addresses, not association authority. BSSID rows feed roaming.
type BSSIDLocation struct {
	Radio, WLAN uint8
	BSSID       [6]byte
}
type PulledStation struct {
	MAC                [6]byte
	Radio, WLAN, State uint8
	IPv4               [4]byte
	IPv6               [16]byte
}
type StatePull struct {
	Control                *uint8
	Stations               []PulledStation
	BSSIDs                 []BSSIDLocation
	HasStations, HasBSSIDs bool
}

func ParseStatePull(b []byte) (*StatePull, error) {
	if len(b) < 2 {
		return nil, fmt.Errorf("pull: missing count")
	}
	count := int(Uint16BE(b))
	b = b[2:]
	if count < 1 || count > 4 {
		return nil, fmt.Errorf("pull: invalid field count")
	}
	p := &StatePull{}
	for i := 0; i < count; i++ {
		if len(b) < 4 {
			return nil, fmt.Errorf("pull: short field")
		}
		typ, n := Uint16BE(b), int(Uint16BE(b[2:]))
		b = b[4:]
		if n > len(b) {
			return nil, fmt.Errorf("pull: short value")
		}
		v := b[:n]
		b = b[n:]
		switch typ {
		case 0:
			if len(v) != 1 {
				return nil, fmt.Errorf("pull: invalid control")
			}
			if p.Control == nil {
				c := v[0]
				p.Control = &c
			}
		case 1, 2:
			width := 29
			if typ == 2 {
				width = 8
			}
			if len(v) < 1 || len(v) != 1+width*int(v[0]) {
				return nil, fmt.Errorf("pull: invalid row count/length")
			}
			if typ == 1 && p.HasStations || typ == 2 && p.HasBSSIDs {
				continue
			}
			if typ == 1 {
				p.HasStations = true
			} else {
				p.HasBSSIDs = true
			}
			for v = v[1:]; len(v) > 0; v = v[width:] {
				if typ == 2 {
					r := BSSIDLocation{Radio: v[0], WLAN: v[1]}
					copy(r.BSSID[:], v[2:8])
					p.BSSIDs = append(p.BSSIDs, r)
				} else {
					r := PulledStation{Radio: v[6], WLAN: v[7], State: v[8]}
					copy(r.MAC[:], v[:6])
					copy(r.IPv4[:], v[9:13])
					copy(r.IPv6[:], v[13:29])
					p.Stations = append(p.Stations, r)
				}
			}
		}
	}
	if len(b) != 0 {
		return nil, fmt.Errorf("pull: trailing data")
	}
	return p, nil
}
