package capwap

// StaAssociationNew is private 0x8a/0x8b. The 17-byte header and
// 16-bit subelements are from cw_priv_sta_assoc_req_new_parse @0x5c282c
// and cw_priv_sta_assoc_rslt_new_assemble @0x5c3834.
// Word is the association metadata in a request, the result in a response.
type StaAssociationNew struct {
	Radio, WLAN uint8
	MAC         [6]byte
	Word        uint32
	Phase       uint8
	Sub         []Element
}

func ParseStaAssociationNew(b []byte) (*StaAssociationNew, error) {
	if len(b) < 17 || b[0] >= 32 || b[1] >= 17 || uint64(Uint32BE(b[13:]))+17 != uint64(len(b)) {
		return nil, ErrShortPacket
	}
	s := &StaAssociationNew{Radio: b[0], WLAN: b[1], Word: Uint32BE(b[8:]), Phase: b[12]}
	copy(s.MAC[:], b[2:8])
	for tail := b[17:]; len(tail) > 0; {
		if len(tail) < 4 {
			return nil, ErrShortPacket
		}
		n := int(Uint16BE(tail[2:]))
		if n > 1024 || n > len(tail)-4 {
			return nil, ErrShortPacket
		}
		s.Sub = append(s.Sub, Element{Type: Uint16BE(tail), Value: append([]byte{}, tail[4:4+n]...)})
		tail = tail[4+n:]
	}
	return s, nil
}
func (s StaAssociationNew) AssembleValue() []byte {
	var tail []byte
	for _, el := range s.Sub {
		tail = AppendElement(tail, el.Type, el.Value)
	}
	b := append([]byte{s.Radio, s.WLAN}, s.MAC[:]...)
	b = AppendUint32BE(b, s.Word)
	b = append(b, s.Phase)
	b = AppendUint32BE(b, uint32(len(tail)))
	return append(b, tail...)
}

// AssociationMLO is request subelement 1, parsed by the V6 assembler/parser:
// MLD MAC (6), peer count (1), then radio/WLAN/MAC/word (12) per peer.
type AssociationMLO struct {
	MAC   [6]byte
	Links []AssociationLink
}
type AssociationLink struct {
	Radio, WLAN uint8
	MAC         [6]byte
	Word        uint32
}

func ParseAssociationMLO(b []byte) (*AssociationMLO, error) {
	if len(b) < 7 || b[6] > 3 || len(b) != 7+int(b[6])*12 {
		return nil, ErrShortPacket
	}
	out := &AssociationMLO{}
	copy(out.MAC[:], b[:6])
	seen := map[[6]byte]bool{}
	for b = b[7:]; len(b) > 0; b = b[12:] {
		l := AssociationLink{Radio: b[0], WLAN: b[1], Word: Uint32BE(b[8:])}
		copy(l.MAC[:], b[2:8])
		if l.Radio == 0 || l.Radio >= 32 || l.WLAN == 0 || l.WLAN > 16 || l.MAC == [6]byte{} || l.MAC[0]&1 != 0 || seen[l.MAC] {
			return nil, ErrShortPacket
		}
		seen[l.MAC] = true
		out.Links = append(out.Links, l)
	}
	if out.MAC == [6]byte{} || out.MAC[0]&1 != 0 {
		return nil, ErrShortPacket
	}
	return out, nil
}

// StationAddressList uses the tagged cw_protocol_ip layout (IPv4=1, IPv6=2).
type StationAddress struct {
	MAC     [6]byte
	Address []byte
}

func ParseStationAddressList(b []byte) ([]StationAddress, error) {
	if len(b) < 4 {
		return nil, ErrShortPacket
	}
	count := Uint32BE(b)
	b = b[4:]
	if count > 200 {
		return nil, ErrShortPacket
	}
	out := make([]StationAddress, 0, count)
	for n := uint32(0); n < count; n++ {
		if len(b) < 7 {
			return nil, ErrShortPacket
		}
		v := StationAddress{}
		copy(v.MAC[:], b[:6])
		size := 0
		switch b[6] {
		case 1:
			size = 4
		case 2:
			size = 16
		default:
			return nil, ErrShortPacket
		}
		b = b[7:]
		if len(b) < size {
			return nil, ErrShortPacket
		}
		v.Address = append([]byte{}, b[:size]...)
		b = b[size:]
		out = append(out, v)
	}
	if len(b) != 0 {
		return nil, ErrShortPacket
	}
	return out, nil
}
