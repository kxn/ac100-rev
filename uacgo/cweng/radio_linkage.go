package cweng

import (
	"encoding/binary"
	"fmt"
	"strconv"
	"strings"
	"uacgo/capwap"
)

// RRST is the AP's list of allowed combinations across related radios. Each
// row's table_mask selects protocol tables; it is not a unique row number.
type RadioLinkage struct {
	TableID               uint8             `json:"table_id"`
	ParameterCapabilities uint32            `json:"parameter_capabilities"`
	DefaultBandwidths     NumberList        `json:"default_bandwidths"`
	DefaultChannels       NumberList        `json:"default_channels"`
	Rows                  []RadioLinkageRow `json:"rows"`
}
type RadioLinkageRow struct {
	TableMask   uint32               `json:"table_mask"`
	FeatureMask uint32               `json:"feature_mask"`
	Regions     []int                `json:"regions"`
	Radios      []RadioLinkageMember `json:"radios"`
}
type RadioLinkageMember struct {
	Radio          uint8  `json:"radio_id"`
	StatusMask     uint32 `json:"status_mask"`
	BindID         uint8  `json:"bind_id"`
	Bandwidths     []int  `json:"bandwidths"`
	Channels       []int  `json:"channels"`
	DefaultChannel *int   `json:"default_channel,omitempty"`
	EqualChannel   bool   `json:"equal_channel"`
}

func ParseRadioLinkage(table, control []byte) (*RadioLinkage, error) {
	out := &RadioLinkage{Rows: []RadioLinkageRow{}}
	if len(control) < 1 || control[0] < 1 || control[0] > 4 {
		return nil, capwap.ErrShortPacket
	}
	n := int(control[0])
	control = control[1:]
	seen := map[byte]bool{}
	for i := 0; i < n; i++ {
		if len(control) < 3 {
			return nil, capwap.ErrShortPacket
		}
		typ := control[0]
		l := int(binary.BigEndian.Uint16(control[1:]))
		if l > len(control)-3 || seen[typ] {
			return nil, capwap.ErrLenMismatch
		}
		seen[typ] = true
		v := control[3 : 3+l]
		control = control[3+l:]
		switch typ {
		case 0:
			if l != 1 || v[0] > 31 {
				return nil, capwap.ErrLenMismatch
			}
			out.TableID = v[0]
		case 1:
			if l != 4 {
				return nil, capwap.ErrLenMismatch
			}
			out.ParameterCapabilities = binary.BigEndian.Uint32(v)
		case 2:
			if l > 31 {
				return nil, capwap.ErrLenMismatch
			}
			out.DefaultBandwidths = append([]byte{}, v...)
		case 3:
			if l > 31 {
				return nil, capwap.ErrLenMismatch
			}
			out.DefaultChannels = append([]byte{}, v...)
		}
	}
	if len(control) != 0 {
		return nil, capwap.ErrLenMismatch
	}
	if len(table) < 1 || table[0] > 64 {
		return nil, capwap.ErrLenMismatch
	}
	n = int(table[0])
	table = table[1:]
	for i := 0; i < n; i++ {
		if len(table) < 10 {
			return nil, capwap.ErrShortPacket
		}
		row := RadioLinkageRow{TableMask: binary.BigEndian.Uint32(table), FeatureMask: binary.BigEndian.Uint32(table[5:]), Regions: []int{}, Radios: []RadioLinkageMember{}}
		radios, cols := int(table[4]), int(table[9])
		table = table[10:]
		if radios < 1 || radios > 8 || cols < 1 || cols > 16 {
			return nil, capwap.ErrLenMismatch
		}
		if out.ParameterCapabilities&1 != 0 {
			if len(table) < 1 || int(table[0])+1 > len(table) {
				return nil, capwap.ErrShortPacket
			}
			for _, s := range strings.Fields(string(table[1 : 1+int(table[0])])) {
				v, err := strconv.Atoi(s)
				if err != nil || v < 0 || v > 31 {
					return nil, fmt.Errorf("invalid RRST region")
				}
				row.Regions = append(row.Regions, v)
			}
			table = table[1+int(table[0]):]
		}
		ids := map[uint8]bool{}
		for j := 0; j < radios; j++ {
			member := RadioLinkageMember{Bandwidths: []int{}, Channels: []int{}}
			fields := map[byte]bool{}
			for k := 0; k < cols; k++ {
				if len(table) < 2 {
					return nil, capwap.ErrShortPacket
				}
				typ := table[0]
				l := int(table[1])
				if l > len(table)-2 || fields[typ] {
					return nil, capwap.ErrLenMismatch
				}
				fields[typ] = true
				v := table[2 : 2+l]
				table = table[2+l:]
				switch typ {
				case 1:
					if l != 1 || v[0] == 0 || v[0] > 31 || ids[v[0]] {
						return nil, fmt.Errorf("invalid RRST radio")
					}
					member.Radio = v[0]
					ids[v[0]] = true
				case 2:
					if l != 4 {
						return nil, capwap.ErrLenMismatch
					}
					member.StatusMask = binary.BigEndian.Uint32(v)
				case 3:
					if l == 1 && out.ParameterCapabilities&2 != 0 {
						member.BindID = v[0]
					} // Original tolerates APs reporting a malformed bind-ID field.
				case 4:
					for _, s := range strings.Fields(string(v)) {
						bw, err := strconv.Atoi(s)
						if err != nil || bw < 0 || bw > 7 {
							return nil, fmt.Errorf("invalid RRST bandwidth")
						}
						member.Bandwidths = append(member.Bandwidths, bw)
					}
				case 5:
					for _, s := range strings.Fields(string(v)) {
						if s == "equal" {
							member.EqualChannel = true
							continue
						}
						if strings.HasPrefix(s, "default:") {
							v, err := strconv.Atoi(strings.TrimPrefix(s, "default:"))
							if err != nil || v < 0 || v > 233 {
								return nil, fmt.Errorf("invalid RRST default channel")
							}
							member.DefaultChannel = &v
							continue
						}
						if strings.Contains(s, ":") {
							continue
						} // Original ignores non-default colon annotations.
						parts := strings.Split(s, "-")
						lo, err := strconv.Atoi(parts[0])
						if err != nil || lo < 0 || lo > 233 || len(parts) > 2 {
							return nil, fmt.Errorf("invalid RRST channel")
						}
						hi := lo
						if len(parts) == 2 {
							hi, err = strconv.Atoi(parts[1])
							if err != nil || hi < lo || hi > 233 {
								return nil, fmt.Errorf("invalid RRST channel range")
							}
						}
						for ch := lo; ch <= hi; ch++ {
							if len(member.Channels) >= 256 {
								return nil, fmt.Errorf("too many RRST channels")
							}
							member.Channels = append(member.Channels, ch)
						}
					}
				}
			}
			if member.Radio == 0 {
				return nil, fmt.Errorf("missing RRST radio identity")
			}
			row.Radios = append(row.Radios, member)
		}
		out.Rows = append(out.Rows, row)
	}
	if len(table) != 0 {
		return nil, capwap.ErrLenMismatch
	}
	return out, nil
}
func refreshRadioLinkage(ap *APEntry) {
	if len(ap.linkageTable) == 0 || len(ap.linkageControl) == 0 {
		return
	}
	if p, err := ParseRadioLinkage(ap.linkageTable, ap.linkageControl); err == nil {
		ap.RadioLinkage = p
	}
}
