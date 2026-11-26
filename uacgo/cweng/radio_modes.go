package cweng

import (
	"encoding/binary"
	"fmt"
	"strings"
	"uacgo/capwap"
	"unicode/utf8"
)

// Private BB: count8, then modeID8/subcount8 and type8/length16/value
// records. The IDs are AP supplied, not the unrelated 802.11 mode enums.
type RadioMode struct {
	ID          uint8      `json:"id"`
	Name        string     `json:"name"`
	Description string     `json:"description"`
	RFMode      uint16     `json:"rf_mode"`
	Radios      NumberList `json:"radios"`
}
type RadioModeState struct {
	Enabled bool  `json:"enabled"`
	ID      uint8 `json:"id"`
}

func ParseRadioModes(b []byte) ([]RadioMode, error) {
	if len(b) < 1 || b[0] > 64 {
		return nil, capwap.ErrShortPacket
	}
	count := int(b[0])
	b = b[1:]
	rows := []RadioMode{}
	seen := map[uint8]bool{}
	for i := 0; i < count; i++ {
		if len(b) < 2 {
			return nil, capwap.ErrShortPacket
		}
		m := RadioMode{ID: b[0], Radios: []uint8{}}
		n := int(b[1])
		b = b[2:]
		if seen[m.ID] || n > 32 {
			return nil, fmt.Errorf("invalid radio mode list")
		}
		seen[m.ID] = true
		fields := map[byte]bool{}
		radioSeen := map[uint8]bool{}
		for j := 0; j < n; j++ {
			if len(b) < 3 {
				return nil, capwap.ErrShortPacket
			}
			typ := b[0]
			l := int(binary.BigEndian.Uint16(b[1:]))
			if l > len(b)-3 {
				return nil, capwap.ErrShortPacket
			}
			v := b[3 : 3+l]
			b = b[3+l:]
			if typ != 3 && fields[typ] {
				return nil, fmt.Errorf("duplicate radio mode field")
			}
			fields[typ] = true
			switch typ {
			case 1, 2:
				if !utf8.Valid(v) || len(v) > 128 {
					return nil, fmt.Errorf("invalid radio mode label")
				}
				text := strings.TrimRight(string(v), "\x00")
				if typ == 1 {
					m.Description = text
				} else {
					m.Name = text
				}
			case 3:
				if len(v) < 1 || v[0] == 0 || v[0] > 31 || radioSeen[v[0]] {
					return nil, fmt.Errorf("invalid radio mode member")
				}
				radioSeen[v[0]] = true
				m.Radios = append(m.Radios, v[0])
			case 4:
				if len(v) != 2 {
					return nil, capwap.ErrLenMismatch
				}
				m.RFMode = binary.BigEndian.Uint16(v)
			}
		}
		if m.Name == "" {
			m.Name = fmt.Sprintf("模式 %d", m.ID)
		}
		rows = append(rows, m)
	}
	if len(b) != 0 {
		return nil, capwap.ErrLenMismatch
	}
	return rows, nil
}
func parseRadioModeState(b []byte) (*RadioModeState, error) {
	if len(b) != 3 || b[0] > 1 {
		return nil, capwap.ErrLenMismatch
	}
	return &RadioModeState{Enabled: b[0] != 0, ID: b[1]}, nil
}
