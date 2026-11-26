package cweng

import (
	"bytes"
	"encoding/binary"
	"net"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestColdAPAlwaysReceivesV6SoftwareSwitchBaseline(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.RegisterAttachHandlers(fixtureIdentity{})
	e.RegisterV6Compatibility()
	e.RegisterWstaHandlers(NewClientTable())
	go e.Run()
	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	read := func() *capwap.ParsedPacket {
		c.SetReadDeadline(time.Now().Add(time.Second))
		b := make([]byte, 65536)
		n, err := c.Read(b)
		if err != nil {
			t.Fatal(err)
		}
		p, err := capwap.ParsePacket(b[:n])
		if err != nil {
			t.Fatal(err)
		}
		return p
	}
	// Fake AP starts with zero control switches, without values retained from an AC.
	mask, value := uint32(0), uint32(0)
	for i, f := range []string{"cw_join_req_0074f150.bin", "cw_cfg_req_0074ef5c.bin", "cw_cse_req_0074ee9c.bin"} {
		c.Write(withSeq(t, f, byte(i+2)))
		rsp := read()
		if i == 1 {
			privateElements(rsp, func(typ uint16, b []byte) {
				if typ == 0x26 && len(b) == 8 {
					mask = binary.BigEndian.Uint32(b)
					value = binary.BigEndian.Uint32(b[4:])
				}
			})
		}
	}
	if mask != 0x6f || value != 0x2e {
		t.Fatalf("cold AP switches not initialized: mask=%x value=%x", mask, value)
	}
	// With the original AC's base switches the AP can forward association.
	if value&0x2e != 0x2e {
		t.Fatal("required station switches disabled")
	}
	a := capwap.LegacyAssociation{Radio: 1, WLAN: 1, MAC: [6]byte{2, 3, 4, 5, 6, 7}, Backfill: []byte{0xaa, 0xbb}}
	p, _ := capwap.NewParsedPacket(9)
	p.Control.SeqNum = 6
	p.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 2, []capwap.PrivElementValue{{Type: 2, Value: a.AssembleValue()}})}}
	c.Write(p.Assemble())
	rsp := read()
	found := false
	privateElements(rsp, func(typ uint16, b []byte) {
		if typ == 4 {
			found = bytes.Equal(b, a.Result(0))
		}
	})
	if !found {
		t.Fatal("cold AP association permit missing")
	}
}
