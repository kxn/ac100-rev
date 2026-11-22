package cweng

import (
	"bytes"
	"net"
	"testing"

	"uacgo/capwap"
)

// The AP config bundle framing: envelope(0x05)+envelope(0x3c)+0x0c+0x17+
// envelope(0x3d), one msg 7, out-seq advanced once.
func TestAPConfigBundle(t *testing.T) {
	e, _ := NewEngine(0)
	s := newSession(&net.UDPAddr{}, &AcDataCounters{})
	var sent [][]byte
	e.sendToForTest = func(_ *net.UDPAddr, b []byte) error { sent = append(sent, b); return nil }

	cfg := APConfig{
		BasePara:    capwap.PrivApBasePara{KeepAlive: 10, ClientKeepAlive: 20},
		OfflineMngr: capwap.PrivApOfflineMngr{Words: [6]uint32{1, 2, 3, 4, 5, 6}},
		DiscoveryT:  20, EchoT: 20, IdleTimeout: 3600,
	}
	copy(cfg.User.Username[:], "admin")
	copy(cfg.User.Password[:], "secret")
	if err := e.SendAPConfigBundle(s, cfg); err != nil {
		t.Fatal(err)
	}
	if s.OutSeq != 1 {
		t.Fatalf("out seq = %d", s.OutSeq)
	}
	pkt, err := capwap.ParsePacket(sent[0])
	if err != nil || pkt.Control.MsgType != capwap.MsgConfigurationUpdateRequest {
		t.Fatalf("bundle packet: %v", err)
	}
	if pkt.Control.SeqNum != 1 || len(pkt.Elements) != 5 {
		t.Fatalf("seq=%d elements=%d", pkt.Control.SeqNum, len(pkt.Elements))
	}
	// each envelope's priv decodes back
	priv := func(el capwap.Element, want uint16) []byte {
		t.Helper()
		if el.Type != 0x0025 {
			t.Fatalf("element %#x", el.Type)
		}
		vid, field := int(el.Value[0])<<24|int(el.Value[1])<<16|int(el.Value[2])<<8|int(el.Value[3]),
			uint16(el.Value[4])<<8|uint16(el.Value[5])
		if vid != 0x12345678 || field != 0 {
			t.Fatalf("envelope vendor=%#x field=%d", vid, field)
		}
		pt := uint16(el.Value[6])<<8 | uint16(el.Value[7])
		if pt != want {
			t.Fatalf("priv type %#x want %#x", pt, want)
		}
		return el.Value[10:]
	}
	if bp, _ := capwap.ParsePrivApBasePara(priv(pkt.Elements[0], 0x05)); bp.KeepAlive != 10 {
		t.Fatalf("base para %+v", bp)
	}
	if om, _ := capwap.ParsePrivApOfflineMngr(priv(pkt.Elements[1], 0x3c)); om.Words[5] != 6 {
		t.Fatalf("offline mngr %+v", om)
	}
	if t2 := pkt.Elements[2]; t2.Type != 0x000c || !bytes.Equal(t2.Value, []byte{20, 20}) {
		t.Fatalf("timers = %#x %x", t2.Type, t2.Value)
	}
	if it := pkt.Elements[3]; it.Type != 0x0017 || !bytes.Equal(it.Value, []byte{0, 0, 0x0e, 0x10}) {
		t.Fatalf("idle timeout = %#x %x", it.Type, it.Value)
	}
	if u, _ := capwap.ParsePrivApUser(priv(pkt.Elements[4], 0x3d)); string(u.Username[:5]) != "admin" {
		t.Fatalf("user %q", u.Username[:10])
	}
}
