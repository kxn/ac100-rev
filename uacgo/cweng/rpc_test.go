package cweng

import (
	"context"
	"encoding/binary"
	"encoding/json"
	"net"
	"strings"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestJSONReplyReassemblesRealSizedAPFragments(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.RegisterAttachHandlers(fixtureIdentity{})
	e.RegisterRPCHandlers()
	go e.Run()
	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	read := func() *capwap.ParsedPacket {
		b := make([]byte, 65536)
		c.SetReadDeadline(time.Now().Add(2 * time.Second))
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
	for i, f := range []string{"cw_join_req_0074f150.bin", "cw_cfg_req_0074ef5c.bin", "cw_cse_req_0074ee9c.bin"} {
		c.Write(withSeq(t, f, uint8(i+2)))
		read()
	}
	ctx, cancel := context.WithTimeout(context.Background(), 2*time.Second)
	defer cancel()
	done := make(chan json.RawMessage, 1)
	errs := make(chan error, 1)
	go func() {
		v, err := e.RequestJSON(ctx, e.APs()[0].ID, json.RawMessage(`{"method":"get","wireless":{"table":"radio_entry"}}`))
		done <- v
		errs <- err
	}()
	command := read()
	var id uint32
	privateElements(command, func(typ uint16, b []byte) {
		if typ == 0x83 {
			id = binary.BigEndian.Uint32(b)
			if b[8] != 1 {
				t.Error("reply flag missing")
			}
		}
	})
	if id == 0 {
		t.Fatal("missing request ID")
	}
	ack, _ := capwap.NewParsedPacket(8)
	ack.Control.SeqNum = command.Control.SeqNum
	ack.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
	c.Write(ack.Assemble())
	// Device sends JSON separately from the command ACK, in 1400-byte chunks.
	body, _ := json.Marshal(map[string]string{"value": strings.Repeat("x", 1800)})
	v := binary.BigEndian.AppendUint32(nil, id)
	v = binary.BigEndian.AppendUint32(v, uint32(len(body)))
	v = append(v, 0)
	v = append(v, body...)
	event, _ := capwap.NewParsedPacket(9)
	event.Control.SeqNum = 70
	event.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0, []capwap.PrivElementValue{{Type: 0x83, Value: v}})}}
	full := event.Assemble()
	h := event.Header
	h.F = 1
	h.FragID = 731
	c.Write(append(capwap.AppendHeader(nil, h), full[8:1408]...))
	h.L = 1
	h.FragOff = 175
	c.Write(append(capwap.AppendHeader(nil, h), full[1408:]...))
	read()
	if err := <-errs; err != nil {
		t.Fatal(err)
	}
	if got := <-done; string(got) != string(body) {
		t.Fatal("JSON reply lost/modified")
	}
}
