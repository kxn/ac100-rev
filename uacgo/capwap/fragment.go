package capwap

import (
	"encoding/binary"
	"fmt"
)

// FragmentPacket fragments the control payload after the CAPWAP header, prior
// to DTLS encryption. Offsets count eight-byte units; only the last chunk may
// have a non-multiple-of-eight length. Optional header bytes are preserved.
func FragmentPacket(b []byte, id uint16, mtu int) ([][]byte, error) {
	h, n, err := ParseHeader(b)
	if err != nil {
		return nil, err
	}
	if h.F != 0 || h.FragOff != 0 {
		return nil, ErrBadFlags
	}
	if len(b) > 65535 {
		return nil, fmt.Errorf("CAPWAP control message exceeds 65535 bytes")
	}
	if len(b) <= mtu {
		return [][]byte{b}, nil
	}
	chunk := (mtu - n) / 8 * 8
	if chunk < 8 {
		return nil, fmt.Errorf("CAPWAP fragment MTU too small")
	}
	var out [][]byte
	for offset := 0; offset < len(b)-n; offset += chunk {
		end := min(offset+chunk, len(b)-n)
		header := append([]byte{}, b[:n]...)
		header[3] |= 0x80
		header[3] &= ^byte(0x40)
		if end == len(b)-n {
			header[3] |= 0x40
		}
		binary.BigEndian.PutUint32(header[4:], uint32(id)<<16|uint32(offset/8)<<3)
		out = append(out, append(header, b[n+offset:n+end]...))
	}
	return out, nil
}
