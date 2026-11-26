package capwap

import "encoding/binary"

// Client/station elements (wsta path).

// StaInfoList is element 0x0034 "station information list" (min 9 max 0x581),
// carried in WTP Event Requests as clients associate.
// Layout per cw_sta_info_list_parse:
//
//	u8 radio id (<0x20)
//	BE32 WLAN id (<0x11), BE32 station count
//	entries × { BE32 a, BE32 b, 6-byte mac }   (14 bytes each)
type StaInfoList struct {
	RadioID uint8
	WLANID  uint32
	Entries []StaInfoEntry
}

// StaInfoEntry is one station record.
type StaInfoEntry struct {
	A   uint32
	B   uint32
	MAC [6]byte
}

// ParseStaInfoList decodes the element value bytes.
func ParseStaInfoList(v []byte) (*StaInfoList, error) {
	if len(v) < 9 || v[0] >= 0x20 {
		return nil, ErrShortPacket
	}
	l := &StaInfoList{RadioID: v[0], WLANID: binary.BigEndian.Uint32(v[1:])}
	count := binary.BigEndian.Uint32(v[5:])
	if l.WLANID >= 0x11 || count > 1000 || uint64(count)*14+9 != uint64(len(v)) {
		return nil, ErrShortPacket
	}
	off := 9
	for i := uint32(0); i < count; i++ {
		if off+14 > len(v) {
			return nil, ErrShortPacket
		}
		var e StaInfoEntry
		e.A = binary.BigEndian.Uint32(v[off:])
		e.B = binary.BigEndian.Uint32(v[off+4:])
		copy(e.MAC[:], v[off+8:off+14])
		l.Entries = append(l.Entries, e)
		off += 14
	}
	return l, nil
}

// AssembleValue writes the element value bytes.
func (l *StaInfoList) AssembleValue() []byte {
	b := binary.BigEndian.AppendUint32([]byte{l.RadioID}, l.WLANID)
	b = binary.BigEndian.AppendUint32(b, uint32(len(l.Entries)))
	for _, e := range l.Entries {
		b = binary.BigEndian.AppendUint32(b, e.A)
		b = binary.BigEndian.AppendUint32(b, e.B)
		b = append(b, e.MAC[:]...)
	}
	return b
}

// PrivStaList is private element 0x1f "private sta list" (min 6),
// per cw_priv_sta_list_parse @0x5c6c28:
//
//	u8 radio id (<0x20), u8 count (<0x11), BE32 wlan id, count × 6-byte mac
type PrivStaListData struct {
	RadioID uint8
	WlanID  uint32
	MACs    [][6]byte
}

// ParsePrivStaList decodes the private value bytes.
func ParsePrivStaList(v []byte) (*PrivStaListData, error) {
	if len(v) < 6 || v[0] >= 0x20 || v[1] >= 0x11 {
		return nil, ErrShortPacket
	}
	l := &PrivStaListData{RadioID: v[0], WlanID: binary.BigEndian.Uint32(v[2:])}
	off := 6
	for i := 0; i < int(v[1]); i++ {
		if off+6 > len(v) {
			return nil, ErrShortPacket
		}
		var mac [6]byte
		copy(mac[:], v[off:off+6])
		l.MACs = append(l.MACs, mac)
		off += 6
	}
	return l, nil
}

// AssembleValue writes the private value bytes.
func (l *PrivStaListData) AssembleValue() []byte {
	b := []byte{l.RadioID, byte(len(l.MACs)), 0, 0, 0, 0}
	binary.BigEndian.PutUint32(b[2:], l.WlanID)
	for _, m := range l.MACs {
		b = append(b, m[:]...)
	}
	return b
}
