package cweng

import (
	"encoding/binary"
	"fmt"
	"strings"
	"time"
)

type BluetoothServerStatus struct {
	Server     uint8     `json:"server"`
	Connected  bool      `json:"connected"`
	Reason     string    `json:"reason"`
	ReceivedAt time.Time `json:"received_at"`
}

func parseBluetoothServerStatus(b []byte) (BluetoothServerStatus, error) {
	var out BluetoothServerStatus
	if len(b) < 7 || b[0] != 1 || b[1] == 0 || b[2] > 1 || uint64(binary.BigEndian.Uint32(b[3:])) != uint64(len(b)-7) {
		return out, fmt.Errorf("invalid Bluetooth server status")
	}
	out = BluetoothServerStatus{Server: b[1], Connected: b[2] == 0, ReceivedAt: time.Now()}
	for b = b[7:]; len(b) > 0; {
		if len(b) < 4 {
			return out, fmt.Errorf("truncated Bluetooth status TLV")
		}
		n := int(binary.BigEndian.Uint16(b[2:]))
		if n > len(b)-4 {
			return out, fmt.Errorf("truncated Bluetooth status")
		}
		if binary.BigEndian.Uint16(b) == 0 {
			if n > 256 {
				return out, fmt.Errorf("Bluetooth reason too long")
			}
			out.Reason = strings.TrimRight(string(b[4:4+n]), "\x00")
		}
		b = b[4+n:]
	}
	return out, nil
}
