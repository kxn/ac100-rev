package cweng

import (
	"encoding/binary"
	"errors"
	"net"
	"time"
)

type ARPScanEntry struct {
	IP  string `json:"ip"`
	MAC string `json:"mac"`
}
type ARPScanReport struct {
	At      time.Time      `json:"at"`
	Type    byte           `json:"type"`
	Entries []ARPScanEntry `json:"entries"`
}

// V6 private CA: operation8/count16 followed by IPv4[4]/MAC[6], no C padding.
var fmtARPScan = errors.New("invalid AP ARP scan report")

func parseARPScan(b []byte) (*ARPScanReport, error) {
	if len(b) < 3 {
		return nil, fmtARPScan
	}
	n := int(binary.BigEndian.Uint16(b[1:]))
	if n > 4096 || len(b) != 3+n*10 {
		return nil, fmtARPScan
	}
	r := &ARPScanReport{At: time.Now(), Type: b[0], Entries: []ARPScanEntry{}}
	for b = b[3:]; len(b) > 0; b = b[10:] {
		r.Entries = append(r.Entries, ARPScanEntry{IP: net.IP(b[:4]).String(), MAC: net.HardwareAddr(b[4:10]).String()})
	}
	return r, nil
}
