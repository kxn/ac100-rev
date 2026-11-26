package cweng

import (
	"fmt"
	"uacgo/capwap"
)

type PortCapability struct {
	ID       uint8 `json:"id"`
	Name     uint8 `json:"name"`
	Uplink   bool  `json:"uplink"`
	MaxSpeed uint8 `json:"max_speed_code"`
	Media    uint8 `json:"media_code"`
	Type     uint8 `json:"type"`
	LAG      bool  `json:"lag"`
}

// V6 _apdb_pkt_parse_port_info consumes AP-extra type12: count8 then six
// packed bytes per port. Unpack role and LAG from the documented bit fields.
func parsePortCapabilities(b []byte) ([]PortCapability, error) {
	if len(b) < 1 || len(b) != 1+int(b[0])*6 {
		return nil, capwap.ErrLenMismatch
	}
	var out []PortCapability
	seen := map[byte]bool{}
	for b = b[1:]; len(b) > 0; b = b[6:] {
		if b[0] == 0 || seen[b[0]] {
			return nil, fmt.Errorf("invalid AP port identity")
		}
		seen[b[0]] = true
		out = append(out, PortCapability{ID: b[0], Name: b[1], Uplink: b[5]&1 != 0, MaxSpeed: b[5] >> 1 & 15, Media: b[5] >> 5, Type: b[4] & 7, LAG: b[4]&8 != 0})
	}
	return out, nil
}
