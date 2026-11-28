package cweng

import (
	"context"
	"net"
	"testing"
	"time"
	"uacgo/capwap"
)

func requestTestSession(t *testing.T) (*Engine, *Session, chan *capwap.ParsedPacket) {
	t.Helper()
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	t.Cleanup(func() { e.Close() })
	s := newSession(&net.UDPAddr{IP: net.IPv4(192, 0, 2, 1), Port: 12000}, e.acData)
	s.State = StateRun
	s.apEntry = &APEntry{GeneralCapabilities: []uint32{0, 1 << 17}}
	e.sessions[s.Addr.String()] = s
	sent := make(chan *capwap.ParsedPacket, 8)
	e.sendToForTest = func(_ *net.UDPAddr, b []byte) error {
		p, err := capwap.ParsePacket(b)
		if err == nil {
			sent <- p
		}
		return err
	}
	return e, s, sent
}

func TestMalformedACKNeverAcknowledgesConfiguration(t *testing.T) {
	e, s, sent := requestTestSession(t)
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	done := make(chan error, 1)
	go func() { _, err := e.Request(ctx, s.Addr.String(), 7, nil); done <- err }()
	p := <-sent
	ack, _ := capwap.NewParsedPacket(8)
	ack.Control.SeqNum = p.Control.SeqNum
	for _, els := range [][]capwap.Element{nil, {{Type: 0x21, Value: []byte{0}}}, {{Type: 0x21, Value: []byte{0, 0, 0, 1}}, {Type: 0x21, Value: []byte{0, 0, 0, 0}}}} {
		ack.Elements = els
		s.mu.Lock()
		s.acknowledge(ack)
		s.mu.Unlock()
		select {
		case err := <-done:
			t.Fatalf("malformed ACK completed command: %v", err)
		case <-time.After(10 * time.Millisecond):
		}
	}
	ack.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
	s.mu.Lock()
	s.acknowledge(ack)
	s.mu.Unlock()
	if err := <-done; err != nil {
		t.Fatal(err)
	}
}

func TestDisconnectCancelsInFlightAndQueuedRequests(t *testing.T) {
	e, s, sent := requestTestSession(t)
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	done := make(chan error, 2)
	go func() { _, err := e.Request(ctx, s.Addr.String(), 7, nil); done <- err }()
	<-sent
	go func() { _, err := e.Request(ctx, s.Addr.String(), 7, nil); done <- err }()
	s.mu.Lock()
	s.teardown()
	s.mu.Unlock()
	for i := 0; i < 2; i++ {
		select {
		case err := <-done:
			if err == nil {
				t.Fatal("closed session reported success")
			}
		case <-time.After(100 * time.Millisecond):
			t.Fatal("request waited for timeout after disconnect")
		}
	}
	select {
	case <-sent:
		t.Fatal("closed session transmitted another command")
	default:
	}
}

func TestPinnedBatchAndRPCRejectReplacementSession(t *testing.T) {
	e, s, sent := requestTestSession(t)
	ctx, cancel := context.WithTimeout(PinAP(context.Background(), e.APs()[0]), time.Second)
	defer cancel()
	replacement := newSession(s.Addr, e.acData)
	replacement.State = StateRun
	s.mu.Lock()
	s.teardown()
	s.mu.Unlock()
	e.mu.Lock()
	e.sessions[s.Addr.String()] = replacement
	e.mu.Unlock()
	if _, err := e.Request(ctx, s.Addr.String(), 7, nil); err == nil {
		t.Fatal("old batch sent on replacement")
	}
	if _, err := e.RequestJSON(ctx, s.Addr.String(), []byte(`{"method":"get"}`)); err == nil {
		t.Fatal("old RPC sent on replacement")
	}
	select {
	case <-sent:
		t.Fatal("replacement session received old configuration")
	default:
	}
	for _, kind := range []uint32{0, 8, 99, 0xffffffff} {
		if _, err := e.Request(context.Background(), s.Addr.String(), kind, nil); err == nil {
			t.Fatalf("accepted request kind %d", kind)
		}
	}
}

func TestDisconnectWhileWaitingForAsyncJSON(t *testing.T) {
	e, s, sent := requestTestSession(t)
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	done := make(chan error, 1)
	go func() { _, err := e.RequestJSON(ctx, s.Addr.String(), []byte(`{"method":"get"}`)); done <- err }()
	p := <-sent
	ack, _ := capwap.NewParsedPacket(8)
	ack.Control.SeqNum = p.Control.SeqNum
	ack.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
	s.mu.Lock()
	s.acknowledge(ack)
	s.mu.Unlock()
	// It is immaterial whether teardown wins immediately before or after the
	// ACK is consumed: neither path may wait on an orphaned JSON channel.
	s.mu.Lock()
	s.teardown()
	s.mu.Unlock()
	select {
	case err := <-done:
		if err == nil {
			t.Fatal("RPC succeeded without reply")
		}
	case <-time.After(100 * time.Millisecond):
		t.Fatal("RPC not canceled")
	}
}
