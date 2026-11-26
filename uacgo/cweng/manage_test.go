package cweng

import (
	"context"
	"net"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestCommandRequiresMatchingDeviceACK(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.RegisterAttachHandlers(fixtureIdentity{})
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
	aps := e.APs()
	if len(aps) != 1 || !aps[0].Online {
		t.Fatalf("AP not in RUN: %+v", aps)
	}
	done := make(chan error, 1)
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	go func() { _, err := e.Request(ctx, aps[0].ID, 7, nil); done <- err }()
	request := read()
	if request.Control.MsgType != 7 {
		t.Fatal("wrong outbound command")
	}
	queuedCtx, queuedCancel := context.WithTimeout(context.Background(), 10*time.Millisecond)
	defer queuedCancel()
	if _, err := e.Request(queuedCtx, aps[0].ID, 7, nil); err != context.DeadlineExceeded {
		t.Fatalf("queued command did not respect cancellation: %v", err)
	}
	rsp, _ := capwap.NewParsedPacket(8)
	rsp.Control.SeqNum = request.Control.SeqNum + 1
	c.Write(rsp.Assemble())
	select {
	case <-done:
		t.Fatal("unrelated sequence completed command")
	case <-time.After(20 * time.Millisecond):
	}
	rsp.Control.SeqNum = request.Control.SeqNum
	rsp.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 3}}}
	c.Write(rsp.Assemble())
	select {
	case err := <-done:
		if err == nil {
			t.Fatal("AP rejection reported as success")
		}
	case <-ctx.Done():
		t.Fatal("matching response was not delivered")
	}
}

func TestReconnectReplacesIdentityBeforeSessionLimit(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.SetResourceLimits(1, 1024)
	e.RegisterAttachHandlers(fixtureIdentity{})
	e.sendToForTest = func(*net.UDPAddr, []byte) error { return nil }
	a := &net.UDPAddr{IP: net.IPv4(192, 0, 2, 1), Port: 1000}
	b := &net.UDPAddr{IP: net.IPv4(192, 0, 2, 1), Port: 2000}
	wire := withSeq(t, "cw_join_req_0074f150.bin", 2)
	e.handleDatagram(wire, a)
	old := e.sessionFor(a)
	if old == nil {
		t.Fatal("first session missing")
	}
	e.handleDatagram(wire, b)
	if e.sessionFor(a) != nil || e.sessionFor(b) == nil || !old.dead || len(e.APs()) != 1 {
		t.Fatal("reconnect kept stale AP identity or hit session limit")
	}
}
