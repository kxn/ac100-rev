package cweng

import (
	"bytes"
	"context"
	"fmt"
	"net"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestUpdImageHandshakeAndACPushMatchesV6(t *testing.T) {
	e, _ := NewEngine(0)
	defer e.Close()
	e.RegisterAttachHandlers(fixtureIdentity{})
	identifier := append([]byte{0x12, 0x34, 0x56, 0x78}, make([]byte, 14)...)
	identifier[5] = 1
	e.RegisterUpdHandlers(func(ap string, connection time.Time, id []byte) (capwap.ImageInformation, error) {
		if ap == "" || connection.IsZero() || !bytes.Equal(id, identifier) {
			return capwap.ImageInformation{}, fmt.Errorf("not scheduled")
		}
		return capwap.ImageInformation{FileInfo: 2000, Info: [16]byte{1, 2, 3}}, nil
	})
	go e.Run()
	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	read := func() *capwap.ParsedPacket {
		b := make([]byte, 65536)
		c.SetReadDeadline(time.Now().Add(time.Second))
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
	for i, name := range []string{"cw_join_req_0074f150.bin", "cw_cfg_req_0074ef5c.bin", "cw_cse_req_0074ee9c.bin"} {
		c.Write(withSeq(t, name, byte(i+2)))
		read()
	}
	// An invented offset pull must be rejected, never expose a global firmware.
	p, _ := capwap.NewParsedPacket(15)
	p.Control.SeqNum = 5
	p.Elements = []capwap.Element{{Type: 0x18, Value: []byte{5, 0, 4, 0, 0, 4, 0}}}
	c.Write(p.Assemble())
	rsp := read()
	rc, _ := elementOf(rsp, 0x21)
	if !bytes.Equal(rc.Value, []byte{0, 0, 0, 0x10}) {
		t.Fatal("unsolicited download accepted")
	}
	p.Control.SeqNum = 6
	p.Elements = []capwap.Element{{Type: 0x19, Value: identifier}, {Type: 0x1b, Value: []byte{}}}
	c.Write(p.Assemble())
	rsp = read()
	info, ok := elementOf(rsp, 0x1a)
	if !ok || !bytes.Equal(info.Value[:4], []byte{0, 0, 7, 208}) || len(info.Value) != 20 {
		t.Fatal(info)
	}
	ap := e.APs()[0]
	done := make(chan error, 1)
	chunk := []byte{1, 0xaa, 0xbb, 0xcc}
	go func() {
		_, err := e.Request(PinAP(context.Background(), ap), ap.ID, 15, []capwap.Element{{Type: 0x18, Value: chunk}})
		done <- err
	}()
	command := read()
	if command.Control.MsgType != 15 || !bytes.Equal(command.Elements[0].Value, chunk) {
		t.Fatal("push chunk wire differs", command)
	}
	ack, _ := capwap.NewParsedPacket(16)
	ack.Control.SeqNum = command.Control.SeqNum
	ack.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
	c.Write(ack.Assemble())
	if err := <-done; err != nil {
		t.Fatal(err)
	}
}
