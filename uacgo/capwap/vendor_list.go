package capwap

import "encoding/binary"

// VendorRecord is a packed type16/length16/value record in the count16 list
// used by AP-extra information and Mesh private control. C pointers/padding
// never appear on the wire.
type VendorRecord struct {
	Type  uint16
	Value []byte
}

func ParseVendorList(b []byte) ([]VendorRecord, error) {
	if len(b) < 2 {
		return nil, ErrShortPacket
	}
	n := int(binary.BigEndian.Uint16(b))
	b = b[2:]
	if n > 1024 {
		return nil, ErrLenMismatch
	}
	rows := make([]VendorRecord, 0, n)
	for i := 0; i < n; i++ {
		if len(b) < 4 {
			return nil, ErrShortPacket
		}
		l := int(binary.BigEndian.Uint16(b[2:]))
		if l > len(b)-4 {
			return nil, ErrShortPacket
		}
		rows = append(rows, VendorRecord{binary.BigEndian.Uint16(b), append([]byte{}, b[4:4+l]...)})
		b = b[4+l:]
	}
	if len(b) != 0 {
		return nil, ErrLenMismatch
	}
	return rows, nil
}
func AssembleVendorList(rows []VendorRecord) []byte {
	b := AppendUint16BE(nil, uint16(len(rows)))
	for _, r := range rows {
		b = AppendUint16BE(b, r.Type)
		b = AppendUint16BE(b, uint16(len(r.Value)))
		b = append(b, r.Value...)
	}
	return b
}
