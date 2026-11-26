package cweng

import (
	"context"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestCommandSubmissionIsImmutableFIFOAndSafeInsideEvent(t *testing.T) {
	e, s, sent := requestTestSession(t)
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	s.mu.Lock()
	ap := s.statusLocked()
	value := []byte{1, 2, 3, 4}
	first, err := e.QueueAP(ctx, ap, 7, []capwap.Element{{Type: 0x17, Value: value}})
	if err != nil {
		s.mu.Unlock()
		t.Fatal(err)
	}
	value[0] = 99
	second, err := e.QueueAP(ctx, ap, 7, []capwap.Element{{Type: 0x17, Value: []byte{5, 6, 7, 8}}})
	if err != nil {
		s.mu.Unlock()
		t.Fatal(err)
	}
	s.mu.Unlock()
	ack := func(p *capwap.ParsedPacket) {
		r, _ := capwap.NewParsedPacket(8)
		r.Control.SeqNum = p.Control.SeqNum
		r.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
		s.mu.Lock()
		s.acknowledge(r)
		s.mu.Unlock()
	}
	var p *capwap.ParsedPacket
	select {
	case p = <-sent:
	case <-ctx.Done():
		t.Fatal("first queued command did not transmit")
	}
	if p.Elements[0].Value[0] != 1 {
		t.Fatal("queued bytes changed after submission", p)
	}
	select {
	case <-sent:
		t.Fatal("second command bypassed the first ACK")
	default:
	}
	ack(p)
	if _, err = first.Wait(ctx); err != nil {
		t.Fatal(err)
	}
	select {
	case p = <-sent:
	case <-ctx.Done():
		t.Fatal("second command did not transmit")
	}
	if p.Elements[0].Value[0] != 5 {
		t.Fatal(p)
	}
	ack(p)
	if _, err = second.Wait(ctx); err != nil {
		t.Fatal(err)
	}
}

func TestLiveGoLimitsKeepExistingSessionAndQueuedCommands(t *testing.T) {
	e, s, sent := requestTestSession(t)
	e.SetResourceLimits(1, 1)
	if e.canAddSession() {
		t.Fatal("AP capacity not enforced")
	}
	ctx, cancel := context.WithTimeout(context.Background(), 3*time.Second)
	defer cancel()
	s.mu.Lock()
	ap := s.statusLocked()
	s.mu.Unlock()
	first, err := e.QueueAP(ctx, ap, 7, nil)
	if err != nil {
		t.Fatal(err)
	}
	read := func() *capwap.ParsedPacket {
		select {
		case p := <-sent:
			return p
		case <-ctx.Done():
			t.Fatal("command did not transmit")
			return nil
		}
	}
	p := read()
	second, err := e.QueueAP(ctx, ap, 7, nil)
	if err != nil {
		t.Fatal(err)
	}
	if _, err = e.QueueAP(ctx, ap, 7, nil); err == nil {
		t.Fatal("queue budget ignored")
	}
	ack := func(p *capwap.ParsedPacket) {
		r, _ := capwap.NewParsedPacket(8)
		r.Control.SeqNum = p.Control.SeqNum
		r.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
		s.mu.Lock()
		s.acknowledge(r)
		s.mu.Unlock()
	}
	e.SetResourceLimits(2, 1)
	if !e.canAddSession() {
		t.Fatal("live capacity increase had no effect")
	}
	ack(p)
	if _, err = first.Wait(ctx); err != nil {
		t.Fatal(err)
	}
	p = read()
	ack(p)
	if _, err = second.Wait(ctx); err != nil {
		t.Fatal("queue resize lost existing command", err)
	}
}
