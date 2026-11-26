package capwap

import (
	"fmt"
	"strconv"
	"strings"
)

// V6 0x9b scan requests use zero-based radio indexes. Channel strings use
// spaces and ranges (the original defaults are "1 6 11", "36-48 149-161").
type ScanRadio struct {
	Index    uint8
	Channels string
}
type ChannelScanRequest struct {
	Dwell  uint8
	Radios []ScanRadio
}

func (p ChannelScanRequest) AssembleValue() []byte {
	b := []byte{p.Dwell, byte(len(p.Radios))}
	for _, r := range p.Radios {
		b = append(b, r.Index, byte(len(r.Channels)))
		b = append(b, []byte(r.Channels)...)
	}
	return b
}
func ParseChannelScanRequest(b []byte) (ChannelScanRequest, error) {
	var p ChannelScanRequest
	if len(b) < 2 || b[1] > 31 {
		return p, ErrShortPacket
	}
	p.Dwell = b[0]
	n := int(b[1])
	b = b[2:]
	seen := map[byte]bool{}
	for i := 0; i < n; i++ {
		if len(b) < 2 || int(b[1]) > len(b)-2 || b[0] >= 31 || seen[b[0]] {
			return p, ErrShortPacket
		}
		r := ScanRadio{b[0], string(b[2 : 2+int(b[1])])}
		seen[b[0]] = true
		for _, part := range strings.Fields(r.Channels) {
			for _, v := range strings.Split(part, "-") {
				if n, err := strconv.Atoi(v); err != nil || n < 1 || n > 233 {
					return p, fmt.Errorf("invalid scan channel")
				}
			}
		}
		p.Radios = append(p.Radios, r)
		b = b[2+int(b[1]):]
	}
	if len(b) != 0 {
		return p, ErrShortPacket
	}
	return p, nil
}

// V6 cw_priv_chnl_scan_report_parse reads nine bytes per channel. The first
// four are channel/BSS count/load/reject flag; the remaining five are reserved.
type ChannelScanSample struct {
	Channel  uint8   `json:"channel"`
	BSS      uint8   `json:"bss"`
	Load     uint8   `json:"load"`
	Rejected uint8   `json:"rejected"`
	Reserved [5]byte `json:"-"`
}

func ParseChannelScanReport(b []byte) ([]ChannelScanSample, error) {
	if len(b) < 1 || len(b) != 1+int(b[0])*9 {
		return nil, ErrShortPacket
	}
	rows := make([]ChannelScanSample, 0, int(b[0]))
	for b = b[1:]; len(b) > 0; b = b[9:] {
		r := ChannelScanSample{Channel: b[0], BSS: b[1], Load: b[2], Rejected: b[3]}
		copy(r.Reserved[:], b[4:9])
		rows = append(rows, r)
	}
	return rows, nil
}
