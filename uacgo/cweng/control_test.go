package cweng

import (
	"net"
	"testing"

	"uacgo/capwap"
)

// Verify the AC-initiated control flows against the vendor send functions:
//
//	LED   = msg 7 + envelope(vendor 0, field 0, priv 0x39, u32 0|1)
//	        (apmngr_pkt_led_pkt_send @0x55aec4)
//	Reset = msg 17; mode1: no elements; mode2: 0x23=u32 1; mode3: 0x23=u32 3
//	        (apmngr_pkt_reset_pkt_send @0x55ad74)
//	out-seq wraps 0xff → 1 (session+0xa4 semantics)
func TestControlFlows(t *testing.T) {
	e, _ := NewEngine(0)
	s := newSession(&net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 1}, &AcDataCounters{})
	var sent [][]byte
	e.sendToForTest = func(_ *net.UDPAddr, b []byte) error { sent = append(sent, b); return nil }

	if err := e.SendLED(s, true); err != nil {
		t.Fatal(err)
	}
	pkt, err := capwap.ParsePacket(sent[0])
	if err != nil || pkt.Control.MsgType != capwap.MsgConfigurationUpdateRequest {
		t.Fatalf("LED packet bad: %v", err)
	}
	if pkt.Control.SeqNum != 1 {
		t.Fatalf("LED seq = %d (want 1)", pkt.Control.SeqNum)
	}
	env := pkt.Elements[0]
	val := capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x39, Value: []byte{0, 0, 0, 1}}})
	if string(string(env.Value)) != string(val) {
		t.Fatalf("LED envelope = %x want %x", env.Value, val)
	}

	// reset modes
	for _, tc := range []struct {
		mode uint32
		priv bool
		val  byte
	}{
		{1, false, 0}, {2, true, 1}, {3, true, 3},
	} {
		sent = nil
		if err := e.SendReset(s, tc.mode); err != nil {
			t.Fatal(err)
		}
		pkt, err := capwap.ParsePacket(sent[0])
		if err != nil || pkt.Control.MsgType != capwap.MsgResetRequest {
			t.Fatalf("reset mode %d bad: %v", tc.mode, err)
		}
		if tc.priv {
			if len(pkt.Elements) != 1 || pkt.Elements[0].Type != 0x0025 {
				t.Fatalf("reset mode %d: want one envelope", tc.mode)
			}
			want := capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x23, Value: []byte{0, 0, 0, tc.val}}})
			if string(pkt.Elements[0].Value) != string(want) {
				t.Fatalf("reset mode %d envelope = %x want %x", tc.mode, pkt.Elements[0].Value, want)
			}
		} else if len(pkt.Elements) != 0 {
			t.Fatalf("reset mode 1 must carry no elements, got %d", len(pkt.Elements))
		}
	}

	if err := e.SendReset(s, 4); err != ErrBadResetMode {
		t.Fatalf("mode 4 must be rejected, got %v", err)
	}

	// out-seq wrap: 0xff → next is 1
	s.OutSeq = 0xff
	if err := e.SendLED(s, false); err != nil {
		t.Fatal(err)
	}
	if s.OutSeq != 1 {
		t.Fatalf("out seq after wrap = %d (want 1)", s.OutSeq)
	}
}
