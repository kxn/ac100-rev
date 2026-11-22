package cweng

import "uacgo/capwap"

// Defense config payload builders — dhcpdef / arp_defend / bcast_storm
// are configuration managers on the AC: JCS config → in-memory DB →
// Configuration-Update + vendor element to the APs (the APs enforce).
// Element layouts from the AC dumps:
//
//	0x47 dhcp defend  : enable, bind_refresh, count, list[7B: addr_type+addr]
//	0x61 dhcpv6 defend: same shape (v6 addresses)
//	0x48 arp defend   : enable, refresh, bind_count, list[12B: ip4+mac]
//	0x62 nd defend    : enable, refresh, bind_count, list[22B: addr16+mac6]
//	0x46 storm ctrl   : state(0/1) + rate(Kbps)

// DhcpDefendServer is one trusted DHCP server entry (svr_tbl).
type DhcpDefendServer struct {
	AddrType uint8
	Addr     []byte // 4 (v4) or up to 16 (v6) bytes
}

// BuildDhcpDefend assembles the 0x47/0x61 payload
// (cw_priv_dhcp_defend_dump: enable@0, bind_refresh@1, count@+4, 7B
// entries @+8).
func BuildDhcpDefend(enable, refresh bool, svrs []DhcpDefendServer) (v4, v6 capwap.PrivElementValue) {
	build := func(v6Addrs bool) []byte {
		e, r := byte(0), byte(0)
		if enable {
			e = 1
		}
		if refresh {
			r = 1
		}
		b := []byte{e, r, 0, 0, 0, 0, 0, 0} // enable, refresh, pad2, count BE32
		n := 0
		for _, s := range svrs {
			is6 := len(s.Addr) > 4
			if is6 != v6Addrs {
				continue
			}
			entry := make([]byte, 7)
			entry[0] = s.AddrType
			copy(entry[1:], s.Addr)
			b = append(b, entry...)
			n++
		}
		b[4] = byte(n >> 24)
		b[5] = byte(n >> 16)
		b[6] = byte(n >> 8)
		b[7] = byte(n)
		return b
	}
	v4 = capwap.PrivElementValue{Type: 0x47, Value: build(false)}
	v6 = capwap.PrivElementValue{Type: 0x61, Value: build(true)}
	return v4, v6
}

// ArpBinding is one IP-MAC binding (arp entry).
type ArpBinding struct {
	IP  [4]byte
	MAC [6]byte
}

// NdBinding is one IPv6 ND binding.
type NdBinding struct {
	IP  [16]byte
	MAC [6]byte
}

// BuildArpDefend assembles the 0x48 payload (cw_priv_arp_defend_dump:
// enable@0, refresh@1, bind_count@+4, 0xC-byte entries @+8 — ip4+mac6
// plus 2 bytes padding).
func BuildArpDefend(enable, refresh bool, binds []ArpBinding) capwap.PrivElementValue {
	e, r := byte(0), byte(0)
	if enable {
		e = 1
	}
	if refresh {
		r = 1
	}
	b := []byte{e, r, 0, 0, 0, 0, 0, 0}
	for _, x := range binds {
		b = append(b, x.IP[:]...)
		b = append(b, x.MAC[:]...)
		b = append(b, 0, 0) // 0xC-per-entry stride (ip4+mac6+2 pad)
	}
	n := len(binds)
	b[4], b[5], b[6], b[7] = byte(n>>24), byte(n>>16), byte(n>>8), byte(n)
	return capwap.PrivElementValue{Type: 0x48, Value: b}
}

// BuildNdDefend assembles the 0x62 payload (IPv6 ND bindings).
func BuildNdDefend(enable, refresh bool, binds []NdBinding) capwap.PrivElementValue {
	e, r := byte(0), byte(0)
	if enable {
		e = 1
	}
	if refresh {
		r = 1
	}
	b := []byte{e, r, 0, 0, 0, 0, 0, 0}
	for _, x := range binds {
		b = append(b, x.IP[:]...)
		b = append(b, x.MAC[:]...)
	}
	n := len(binds)
	b[4], b[5], b[6], b[7] = byte(n>>24), byte(n>>16), byte(n>>8), byte(n)
	return capwap.PrivElementValue{Type: 0x62, Value: b}
}

// BuildStormCtrl assembles the 0x46 payload (state@0 + BE32 rate).
func BuildStormCtrl(enable bool, rateKbps uint32) capwap.PrivElementValue {
	s := byte(0)
	if enable {
		s = 1
	}
	b := []byte{s}
	b = capwap.AppendUint32BE(b, rateKbps)
	return capwap.PrivElementValue{Type: 0x46, Value: b}
}

// SendDefendConfig pushes one or more defense payloads on msg 7
// (_uac_dhcpdef_notify_ap / arp_defend_wtp_pkt_send /
// _uac_bcast_storm_ctrl_pkt_send all send Configuration Update).
func (e *Engine) SendDefendConfig(s *Session, privs ...capwap.PrivElementValue) error {
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest, privs...)
}
