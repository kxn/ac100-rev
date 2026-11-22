package cweng

import (
	"encoding/hex"
	"net"
	"testing"
	"time"

	"uacgo/capwap"
)

func timeDeadline() time.Time { return time.Now().Add(2 * time.Second) }

// rateFixture55 returns the vendor cfg_update rate payload (55 bytes).
func rateFixture55() []byte {
	out := make([]byte, 55)
	v, _ := hex.DecodeString("010c18300000000000122448606c00000000020400000b1600000002040b1600000000000000000c1218243048606c0000000000ff17ff")
	copy(out, v)
	return out
}

// wserv/rdmngr listeners add correctly framed SSID/radio envelopes to the
// config-status response, and rdmngr adds radio params to join responses.
func TestWserviceHandlers(t *testing.T) {
	e, _ := NewEngine(0)
	e.RegisterAttachHandlers(fixtureIdentity{})
	e.RegisterWserviceHandlers(testWsvc{})
	go func() { _ = e.Run() }()

	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	read := func() []byte {
		buf := make([]byte, capwap.MaxUdpPayload)
		c.SetReadDeadline(readDeadline())
		n, err := c.Read(buf)
		if err != nil {
			t.Fatalf("no response: %v", err)
		}
		return buf[:n]
	}

	c.Write(withSeq(t, "cw_join_req_0074f150.bin", 2))
	join := read()
	pkt, err := capwap.ParsePacket(join)
	if err != nil {
		t.Fatal(err)
	}
	adv := privFromEnvelope(t, pkt, 0x08)
	if adv == nil {
		t.Fatal("join response missing 0x08 adv rd para envelope")
	}
	if _, err := capwap.ParsePrivAdvRdPara(adv); err != nil {
		t.Fatalf("adv rd para malformed: %v", err)
	}
	rate := privFromEnvelope(t, pkt, 0x0a)
	if rate == nil {
		t.Fatal("join response missing 0x0a rate envelope")
	}
	if _, err := capwap.ParsePrivRate(rate); err != nil {
		t.Fatalf("rate malformed: %v", err)
	}

	// config status: complete the lifecycle to CONFIGURE
	c.Write(withSeq(t, "cw_cfg_req_0074ef5c.bin", 3))
	cfgPkt, err := capwap.ParsePacket(read())
	if err != nil {
		t.Fatal(err)
	}
	wl := privFromEnvelope(t, cfgPkt, 0x1e)
	if wl == nil {
		t.Fatal("cfg status missing 0x1e wlan list envelope")
	}
	l, err := capwap.ParsePrivWlanList(wl)
	if err != nil {
		t.Fatalf("wlan list malformed: %v", err)
	}
	if len(l.Entries) != 1 || string(l.Entries[0].SSID[:7]) != "00_YXJ_" {
		t.Fatalf("wlan list entries = %d ssid=%q", len(l.Entries), l.Entries[0].SSID)
	}
	if privFromEnvelope(t, cfgPkt, 0x09) == nil {
		t.Fatal("cfg status missing 0x09 wsrv para envelope")
	}
}

func readDeadline() time.Time { return time.Now().Add(2 * time.Second) }

// testWsvc is the fixture-shaped config source.
type testWsvc struct{}

func (testWsvc) WlanServices() []WlanService {
	var ssid [32]byte
	copy(ssid[:], "00_YXJ_统一技术_GBK")
	return []WlanService{{
		WservID: 1, RadioID: 1, SSID: ssid,
		Para: PrivWsrvParaFields{A: 1, B: 2, C: 1, D: 10000},
	}}
}
func (testWsvc) Radios() []RadioConfig {
	adv := capwap.PrivAdvRdPara{RadioID: 1}
	adv.Byte15 = 0xff
	rate, _ := capwap.ParsePrivRate(rateFixture55())
	return []RadioConfig{{RadioID: 1, AdvRd: adv, Rate: *rate}}
}

// privFromEnvelope extracts a private TLV value from the 0x25 envelopes.
func privFromEnvelope(t *testing.T, pkt *capwap.ParsedPacket, privType uint16) []byte {
	t.Helper()
	for _, e := range pkt.Elements {
		if e.Type != 0x0025 || len(e.Value) < 6 {
			continue
		}
		v := e.Value[6:]
		for len(v) >= 4 {
			pt := uint16(v[0])<<8 | uint16(v[1])
			pl := uint16(v[2])<<8 | uint16(v[3])
			if int(pl)+4 > len(v) {
				break
			}
			if pt == privType {
				return v[4 : 4+int(pl)]
			}
			v = v[4+int(pl):]
		}
	}
	return nil
}
