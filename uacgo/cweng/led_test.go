package cweng

import (
	"net"
	"testing"
	"time"

	"uacgo/capwap"
)

func capwapParse(b []byte) (*capwap.ParsedPacket, error) { return capwap.ParsePacket(b) }
func capwapMsg7() uint32                                 { return capwap.MsgConfigurationUpdateRequest }

// 0x6f value mapping: mode 0 → 1, else 3 (apmngr entry+0x130 semantics,
// apmngr_pkt_config_update_request_pkt_send @0x5590c0).
func TestLEDModeFraming(t *testing.T) {
	e, _ := NewEngine(0)
	s := newSession(&net.UDPAddr{}, &AcDataCounters{})
	var sent [][]byte
	e.sendToForTest = func(_ *net.UDPAddr, b []byte) error { sent = append(sent, b); return nil }

	if err := e.SendLEDMode(s, 0); err != nil {
		t.Fatal(err)
	}
	pkt, err := capwap.ParsePacket(sent[0])
	if err != nil || pkt.Control.MsgType != capwap.MsgConfigurationUpdateRequest {
		t.Fatalf("LED mode packet: %v", err)
	}
	env := pkt.Elements[0].Value
	want := []byte{0, 0, 0, 0, 0, 0, 0x6f >> 8, 0x6f & 0xff, 0, 4, 0, 0, 0, 1}
	if string(env) != string(want) {
		t.Fatalf("mode-0 envelope = %x want %x", env, want)
	}

	if err := e.SendLEDMode(s, 2); err != nil {
		t.Fatal(err)
	}
	pkt2, _ := capwap.ParsePacket(sent[1])
	env2 := pkt2.Elements[0].Value
	if string(env2[len(env2)-4:]) != string([]byte{0, 0, 0, 3}) {
		t.Fatalf("mode-2 value = %x", env2[len(env2)-4:])
	}
}

// LED schedule: next trigger selection across midnight.
func TestNextLEDTrigger(t *testing.T) {
	p := LEDPlan{Enable: true, CloseTime: "23:30", OpenTime: "06:30"}
	now := time.Date(2026, 1, 1, 7, 0, 0, 0, time.UTC)
	tm, on := nextLEDTrigger(p, now)
	if on || tm.Hour() != 23 || tm.Minute() != 30 {
		t.Fatalf("got %v on=%v (want 23:30 close event on=false)", tm, on)
	}
	now2 := time.Date(2026, 1, 1, 2, 0, 0, 0, time.UTC)
	tm2, on2 := nextLEDTrigger(p, now2)
	if !on2 || tm2.Hour() != 6 || tm2.Minute() != 30 {
		t.Fatalf("got %v on=%v (want today 06:30 open)", tm2, on2)
	}
	now3 := time.Date(2026, 1, 1, 6, 30, 0, 0, time.UTC)
	tm3, on3 := nextLEDTrigger(p, now3)
	if on3 || tm3.Hour() != 23 {
		t.Fatalf("at exactly 06:30 the next event is close: %v on=%v", tm3, on3)
	}
}

// Bluetooth config envelope: priv 0xa7, value word = byte << 24.
func TestBluetoothConfigFraming(t *testing.T) {
	e, _ := NewEngine(0)
	s := newSession(&net.UDPAddr{}, &AcDataCounters{})
	var sent [][]byte
	e.sendToForTest = func(_ *net.UDPAddr, b []byte) error { sent = append(sent, b); return nil }
	if err := e.SendBluetoothConfig(s, 1); err != nil {
		t.Fatal(err)
	}
	pkt, err := capwap.ParsePacket(sent[0])
	if err != nil || pkt.Control.MsgType != capwap.MsgConfigurationUpdateRequest {
		t.Fatalf("bluetooth packet: %v", err)
	}
	env := pkt.Elements[0].Value
	want := []byte{0, 0, 0, 0, 0, 0, 0, 0xa7, 0, 4, 1, 0, 0, 0}
	if string(env) != string(want) {
		t.Fatalf("bluetooth envelope = %x want %x", env, want)
	}
}
