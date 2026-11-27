package cweng

import (
	"encoding/json"
	"net"
	"testing"
	"time"
)

func resourceSession() *Session {
	channel, limit := 6, 256
	t := &WirelessTelemetry{ReceivedAt: time.Now()}
	for radio := 1; radio <= 2; radio++ {
		t.Radios = append(t.Radios, WirelessRadio{RadioID: radio, Channel: &channel, MaxClients: &limit, Bandwidth: "40", Data: map[string]json.RawMessage{"channelUsage": json.RawMessage(`[1,2,3,4,5]`), "noiseFloor": json.RawMessage(`[-90,-90,-90,-90,-90]`)}})
		for range 8 {
			t.VAPs = append(t.VAPs, WirelessVAP{RadioID: radio, SSID: "Office", Data: map[string]json.RawMessage{"txPkts": json.RawMessage(`[1,2,3,4,5]`)}})
		}
	}
	return &Session{Addr: &net.UDPAddr{IP: net.IPv4(192, 0, 2, 1), Port: 5246}, telemetry: t}
}

func BenchmarkResourceAPSnapshot(b *testing.B) {
	s := resourceSession()
	b.ReportAllocs()
	for b.Loop() {
		_ = s.statusLocked()
	}
}
