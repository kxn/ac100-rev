package cweng

import (
	"context"
	"encoding/binary"
	"net"
	"os"
	"testing"
	"time"
	"uacgo/capwap"
)

func wrapMeshTest(t *testing.T, id string, p *capwap.ParsedPacket) []byte {
	t.Helper()
	b, err := capwap.AssembleMeshPublic([]string{id}, p.Elements)
	if err != nil {
		t.Fatal(err)
	}
	q := *p
	q.Elements = []capwap.Element{meshControlPublicElement(b)}
	return q.Assemble()
}
func TestMeshChildLifecycleCommandsAndParentIsolation(t *testing.T) {
	e, parent, sent := requestTestSession(t)
	inventory := &joinTestStore{}
	e.UseStore(inventory)
	registered := false
	e.OnAPJoin = func(ap APStatus, first bool) error { registered = first && ap.Encapsulated; return nil }
	parent.apEntry = &APEntry{MAC: "02:00:00:00:00:01", GeneralCapabilities: []uint32{0, 1 << 12}}
	childID := "02:00:00:00:00:09"
	e.RegisterMeshControl(nil, func(_ string, _ time.Time, id string, _ uint8) bool { return id == childID })
	e.Register(3, 1, "join", func(_ *Ctx, _, rsp *capwap.ParsedPacket) bool {
		rsp.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
		return true
	})
	e.RegisterObservationHandlers()
	for i, name := range []string{"cw_join_req_0074f150.bin", "cw_cfg_req_0074ef5c.bin", "cw_cse_req_0074ee9c.bin"} {
		b, err := os.ReadFile("../testdata/" + name)
		if err != nil {
			t.Fatal(err)
		}
		p, err := capwap.ParsePacket(b)
		if err != nil {
			t.Fatal(err)
		}
		p.Control.SeqNum = byte(20 + i)
		if i == 0 {
			mac, _ := net.ParseMAC(childID)
			board := []byte{0, 0, 0, 0, 0, 4, 0, 6}
			board = append(board, mac...)
			p.Elements = append(p.Elements, capwap.Element{Type: 0x26, Value: board})
		}
		e.handlePlainDatagram(wrapMeshTest(t, childID, p), parent.Addr)
		select {
		case rsp := <-sent:
			if rsp.Control.MsgType != p.Control.MsgType+1 {
				t.Fatal(rsp)
			}
			ids, _, err := capwap.ParseMeshPublic(rsp.Elements[0].Value[10:])
			if err != nil || len(ids) != 1 || ids[0] != childID {
				t.Fatal(ids, err)
			}
		case <-time.After(time.Second):
			t.Fatalf("child lifecycle response missing at phase %d", i)
		}
	}
	if inventory.calls != 1 || len(inventory.seen) != 1 || inventory.seen[0] != childID || !registered {
		t.Fatal("Mesh child skipped inventory/initialization", inventory, registered)
	}
	child := e.findAP(childID)
	if child == nil || child.State != StateRun {
		t.Fatal("Mesh child not RUN")
	}
	if parent.State != StateRun || parent.LastReqSeq != -1 {
		t.Fatal("child changed parent FSM/sequence")
	}
	ctx, cancel := context.WithTimeout(context.Background(), 2*time.Second)
	defer cancel()
	done := make(chan error, 1)
	go func() {
		_, err := e.Request(ctx, childID, 7, []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x39, Value: []byte{0, 0, 0, 1}}})}})
		done <- err
	}()
	request := <-sent
	ids, els, err := capwap.ParseMeshPublic(request.Elements[0].Value[10:])
	if err != nil || ids[0] != childID || len(els) != 1 {
		t.Fatal(ids, els, err)
	}
	ack, _ := capwap.NewParsedPacket(8)
	ack.Control.SeqNum = request.Control.SeqNum
	ack.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
	e.handlePlainDatagram(ack.Assemble(), parent.Addr)
	select {
	case err := <-done:
		t.Fatal("parent ACK completed child request", err)
	case <-time.After(15 * time.Millisecond):
	}
	e.handlePlainDatagram(wrapMeshTest(t, childID, ack), parent.Addr)
	if err := <-done; err != nil {
		t.Fatal(err)
	}
	// Radio event belongs to the inner AP, with its own request sequence.
	report, _ := capwap.NewParsedPacket(9)
	report.Control.SeqNum = 23
	report.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x25, Value: []byte{1, 6, 11, 0, 15}}})}}
	e.handlePlainDatagram(wrapMeshTest(t, childID, report), parent.Addr)
	<-sent
	if child.radioStatus[1].Channel != 11 || len(parent.radioStatus) != 0 {
		t.Fatal("child telemetry attributed to parent")
	}
	// Parent commands use a distinct sequence from the same transport counter.
	go func() { _, err := e.Request(ctx, parent.apEntry.MAC, 7, nil); done <- err }()
	next := <-sent
	if next.Control.SeqNum == request.Control.SeqNum {
		t.Fatal("CAP transport reused child sequence")
	}
	ack.Control.SeqNum = next.Control.SeqNum
	e.handlePlainDatagram(ack.Assemble(), parent.Addr)
	if err := <-done; err != nil {
		t.Fatal(err)
	}
	parent.mu.Lock()
	parent.teardown()
	parent.mu.Unlock()
	until := time.Now().Add(time.Second)
	for {
		child.mu.Lock()
		dead := child.dead
		child.mu.Unlock()
		if dead {
			break
		}
		if time.Now().After(until) {
			t.Fatal("orphan child after parent disconnect")
		}
		time.Sleep(time.Millisecond)
	}
	if e.findAP(childID) != nil {
		t.Fatal("child leaked")
	}
}
func TestMeshPublicRejectsMalformedAndIdentityClaims(t *testing.T) {
	e, parent, _ := requestTestSession(t)
	parent.apEntry = &APEntry{MAC: "02:00:00:00:00:01", GeneralCapabilities: []uint32{0, 1 << 12}}
	e.RegisterMeshControl(nil, func(string, time.Time, string, uint8) bool { return false })
	p, _ := capwap.NewParsedPacket(3)
	p.Elements = []capwap.Element{{Type: 0x26, Value: []byte{0, 0, 0, 0, 0, 4, 0, 6, 2, 0, 0, 0, 0, 9}}}
	e.handlePlainDatagram(wrapMeshTest(t, "02:00:00:00:00:09", p), parent.Addr)
	if len(e.APs()) != 1 {
		t.Fatal("unapproved child created")
	}
	raw, _ := capwap.AssembleMeshPublic([]string{"02:00:00:00:00:09"}, nil)
	binary.BigEndian.PutUint16(raw[len(raw)-2:], 100)
	p.Elements = []capwap.Element{meshControlPublicElement(raw)}
	e.handlePlainDatagram(p.Assemble(), parent.Addr)
	if parent.State != StateRun {
		t.Fatal("malformed child join altered parent")
	}
}

func TestRevokedMeshChildIsRemovedWithoutClosingParent(t *testing.T) {
	e, parent, sent := requestTestSession(t)
	parent.apEntry = &APEntry{MAC: "02:00:00:00:00:01", GeneralCapabilities: []uint32{0, 1 << 12}}
	id := "02:00:00:00:00:09"
	child := newSession(parent.Addr, e.acData)
	child.apEntry = &APEntry{MAC: id}
	child.meshParent = parent
	child.State = StateRun
	child.onTeardown = e.removeSession
	e.sessions[child.sessionKey()] = child
	e.RegisterMeshControl(nil, func(string, time.Time, string, uint8) bool { return false })
	p, _ := capwap.NewParsedPacket(9)
	p.Control.SeqNum = 1
	e.handlePlainDatagram(wrapMeshTest(t, id, p), parent.Addr)
	if e.findAP(id) != nil || parent.dead || e.sessionFor(parent.Addr) != parent {
		t.Fatal("revocation failed or deleted parent")
	}
	select {
	case <-sent:
		t.Fatal("revoked child received accepted response")
	default:
	}
}

func TestMeshAdmissionUsesLiveSharedBudgetAboveOldDefault(t *testing.T) {
	e, parent, _ := requestTestSession(t)
	parent.apEntry = &APEntry{MAC: "02:00:00:00:00:01", GeneralCapabilities: []uint32{0, 1 << 12}}
	id := "02:00:00:00:00:09"
	e.RegisterMeshControl(nil, func(string, time.Time, string, uint8) bool { return true })
	e.SetResourceLimits(1, 1024)
	p, _ := capwap.NewParsedPacket(3)
	p.Elements = []capwap.Element{{Type: 0x26, Value: []byte{0, 0, 0, 0, 0, 4, 0, 6, 2, 0, 0, 0, 0, 9}}}
	wire := wrapMeshTest(t, id, p)
	e.handlePlainDatagram(wire, parent.Addr)
	if e.findAP(id) != nil {
		t.Fatal("Mesh bypassed full shared budget")
	}
	// Occupy the original default capacity; a live increase must apply to
	// the final Mesh insertion as well as any preliminary capacity check.
	e.SetResourceLimits(2048, 1024)
	for i := 0; i < 1023; i++ {
		s := newSession(&net.UDPAddr{IP: net.IPv4(192, 0, 2, 1), Port: 10000 + i}, e.acData)
		if !e.registerSession(s) {
			t.Fatal("live budget not used", i)
		}
	}
	e.handlePlainDatagram(wire, parent.Addr)
	if e.findAP(id) == nil {
		t.Fatal("Mesh still limited by original 1024-session field")
	}
}
