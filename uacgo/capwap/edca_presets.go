package capwap

import "encoding/binary"

type EDCAQueue struct {
	AIFS  int `json:"aifs"`
	CWMin int `json:"cw_min"`
	CWMax int `json:"cw_max"`
	TXOP  int `json:"txop"`
}
type EDCABandPreset struct {
	Band   uint8       `json:"band_id"`
	Queues []EDCAQueue `json:"queues"`
}
type EDCAScene struct {
	ID          uint8            `json:"id"`
	Name        string           `json:"name"`
	Description string           `json:"description"`
	Bands       []EDCABandPreset `json:"bands"`
}
type EDCAPresets struct {
	Version uint16      `json:"version"`
	Scenes  []EDCAScene `json:"scenes"`
}

// ParseEDCAPresets decodes AP-private 0xce. Presets are model/hardware-specific
// data reported by the AP, not universal office/density queue constants.
func ParseEDCAPresets(b []byte) (*EDCAPresets, error) {
	if len(b) < 4 {
		return nil, ErrShortPacket
	}
	p := &EDCAPresets{Version: binary.BigEndian.Uint16(b)}
	count := int(b[2])
	if count > 32 {
		return nil, ErrLenMismatch
	}
	b = b[3:]
	seen := map[byte]int{}
	for i := 0; i < count; i++ {
		if len(b) < 2 {
			return nil, ErrShortPacket
		}
		id, n := b[0], int(b[1])
		if _, ok := seen[id]; ok {
			return nil, ErrLenMismatch
		}
		b = b[2:]
		if len(b) < n+2 {
			return nil, ErrShortPacket
		}
		s := EDCAScene{ID: id, Name: string(b[:n])}
		b = b[n:]
		n = int(binary.BigEndian.Uint16(b))
		b = b[2:]
		if len(b) < n {
			return nil, ErrShortPacket
		}
		s.Description = string(b[:n])
		b = b[n:]
		seen[id] = len(p.Scenes)
		p.Scenes = append(p.Scenes, s)
	}
	if len(b) < 1 {
		return nil, ErrShortPacket
	}
	records := int(b[0])
	b = b[1:]
	if len(b) != records*42 {
		return nil, ErrLenMismatch
	}
	for i := 0; i < records; i++ {
		v := b[i*42 : (i+1)*42]
		scene, ok := seen[v[0]]
		if !ok || v[1] < 1 || v[1] > 4 {
			return nil, ErrLenMismatch
		}
		s := &p.Scenes[scene]
		for _, x := range s.Bands {
			if x.Band == v[1] {
				return nil, ErrLenMismatch
			}
		}
		band := EDCABandPreset{Band: v[1]}
		for side := 0; side < 2; side++ {
			v := v[2+side*20 : 2+(side+1)*20]
			for q := 0; q < 4; q++ {
				band.Queues = append(band.Queues, EDCAQueue{AIFS: int(v[q]), CWMin: int(v[4+q]), CWMax: int(v[8+q]), TXOP: int(binary.BigEndian.Uint16(v[12+2*q:]))})
			}
		}
		s.Bands = append(s.Bands, band)
	}
	return p, nil
}
