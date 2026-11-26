package capwap

import (
	"encoding/binary"
	"fmt"
	"net"
)

// Mesh public control forwards ordinary CAPWAP elements through the CAP.
// count16, MAC6[count], inner-length16, then standard type16/length16 TLVs.
func ParseMeshPublic(b []byte) ([]string, []Element, error) {
	if len(b) < 4 {
		return nil, nil, ErrShortPacket
	}
	n := int(binary.BigEndian.Uint16(b))
	if n < 1 || n > 100 || len(b) < 4+6*n {
		return nil, nil, ErrLenMismatch
	}
	off := 2 + 6*n
	l := int(binary.BigEndian.Uint16(b[off:]))
	if off+2+l != len(b) {
		return nil, nil, ErrLenMismatch
	}
	macs := []string{}
	seen := map[string]bool{}
	for i := 0; i < n; i++ {
		v := b[2+6*i : 8+6*i]
		mac := net.HardwareAddr(v).String()
		if v[0]&1 != 0 || mac == "00:00:00:00:00:00" || seen[mac] {
			return nil, nil, fmt.Errorf("invalid Mesh target")
		}
		seen[mac] = true
		macs = append(macs, mac)
	}
	els, err := ParseElements(b, off+2, l)
	if err != nil {
		return nil, nil, err
	}
	return macs, els, nil
}
func AssembleMeshPublic(macs []string, els []Element) ([]byte, error) {
	if len(macs) < 1 || len(macs) > 100 {
		return nil, ErrLenMismatch
	}
	b := binary.BigEndian.AppendUint16(nil, uint16(len(macs)))
	for _, v := range macs {
		mac, err := net.ParseMAC(v)
		if err != nil || len(mac) != 6 {
			return nil, fmt.Errorf("invalid Mesh target")
		}
		b = append(b, mac...)
	}
	inner := []byte{}
	for _, el := range els {
		if len(el.Value) > 65535 {
			return nil, ErrLenMismatch
		}
		inner = binary.BigEndian.AppendUint16(inner, el.Type)
		inner = binary.BigEndian.AppendUint16(inner, uint16(len(el.Value)))
		inner = append(inner, el.Value...)
	}
	if len(inner) > 65535-len(b)-2 {
		return nil, ErrLenMismatch
	}
	b = binary.BigEndian.AppendUint16(b, uint16(len(inner)))
	b = append(b, inner...)
	if _, _, err := ParseMeshPublic(b); err != nil {
		return nil, err
	}
	return b, nil
}
