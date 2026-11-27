package cweng

import (
	"bytes"
	"context"
	"encoding/json"
	"os"
	"path/filepath"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/internal/eventlog"
)

func TestCommandLogCorrelatesActualExchangeWithoutPayloads(t *testing.T) {
	e, s, sent := requestTestSession(t)
	path := filepath.Join(t.TempDir(), "events.jsonl")
	events, err := eventlog.Open(path, 1<<20, 1)
	if err != nil {
		t.Fatal(err)
	}
	defer events.Close()
	e.Events = events
	secret := []byte("sensitive-wlan-key-and-pmk")
	element := capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x59, Value: secret}})}
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	s.mu.Lock()
	ap := s.statusLocked()
	s.mu.Unlock()
	ticket, err := e.QueueAP(ctx, ap, 7, []capwap.Element{element})
	if err != nil {
		t.Fatal(err)
	}
	var packet *capwap.ParsedPacket
	select {
	case packet = <-sent:
	case <-ctx.Done():
		t.Fatal("not transmitted")
	}
	if !bytes.Equal(packet.Elements[0].Value, element.Value) {
		t.Fatal("logging changed wire data")
	}
	ack, _ := capwap.NewParsedPacket(8)
	ack.Control.SeqNum = packet.Control.SeqNum
	ack.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
	s.mu.Lock()
	s.acknowledge(ack)
	s.mu.Unlock()
	if _, err = ticket.Wait(ctx); err != nil {
		t.Fatal(err)
	}
	events.Close()
	b, err := os.ReadFile(path)
	if err != nil {
		t.Fatal(err)
	}
	if bytes.Contains(b, secret) {
		t.Fatal("secret payload logged")
	}
	seen := map[string]bool{}
	for _, line := range bytes.Split(bytes.TrimSpace(b), []byte{'\n'}) {
		var row map[string]any
		if err = json.Unmarshal(line, &row); err != nil {
			t.Fatal(err)
		}
		if row["command_id"] != float64(ticket.ID) {
			t.Fatal("missing command correlation", row)
		}
		seen[row["event"].(string)] = true
	}
	for _, event := range []string{"command.queued", "command.transmit", "command.response", "command.completed"} {
		if !seen[event] {
			t.Fatal("missing event", event)
		}
	}
	if !bytes.Contains(b, []byte(`"type":"0x0059"`)) {
		t.Fatal("private command identifier missing")
	}
}
