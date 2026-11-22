package cweng

import (
	"net"
	"testing"
	"time"

	"uacgo/capwap"
)

type testApdb struct{ got [][]byte }

func (a *testApdb) ApdbInfo(_ *Session, info capwap.PrivApdbInfo) { a.got = append(a.got, info) }

// The apdb listeners (msg 1/3 priority 256) pull 0x51 out of request
// envelopes; the stats/roaming/period senders frame 0x55/0x57/0x0c.
func TestPrivCtrl(t *testing.T) {
	// --- discovery path: 0x51 captured ---
	e, _ := NewEngine(0)
	e.RegisterAttachHandlers(fixtureIdentity{})
	sink := &testApdb{}
	e.RegisterApdbHandlers(sink)
	go func() { _ = e.Run() }()

	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()

	// discovery fixture has no 0x51; craft one with a blob
	p, _ := capwap.NewParsedPacket(capwap.MsgDiscoveryRequest)
	p.Control.SeqNum = 1
	env := capwap.VendorEnvelopeValue(0x12345678, 0,
		[]capwap.PrivElementValue{{Type: 0x51, Value: []byte{0xde, 0xad, 0xbe, 0xef}}})
	p.Elements = append(p.Elements, capwap.Element{Type: 0x0025, Value: env})
	c.Write(p.Assemble())
	buf := make([]byte, capwap.MaxUdpPayload)
	c.SetReadDeadline(time.Now().Add(2 * time.Second))
	if _, err := c.Read(buf); err != nil {
		t.Fatalf("no discovery response: %v", err)
	}
	if len(sink.got) != 1 || !bytesEq(sink.got[0], []byte{0xde, 0xad, 0xbe, 0xef}) {
		t.Fatalf("apdb sink = %x", sink.got)
	}

	// --- senders' framing ---
	s := newSession(&net.UDPAddr{}, &AcDataCounters{})
	var sent [][]byte
	e.sendToForTest = func(_ *net.UDPAddr, b []byte) error { sent = append(sent, b); return nil }

	if err := e.SendStatsControl(s, capwap.PrivStatisticsControl{A: 1, B: 2, C: 3, D: 300, E: 4, F: 5}); err != nil {
		t.Fatal(err)
	}
	pkt, _ := capwap.ParsePacket(sent[0])
	el := pkt.Elements[0]
	if el.Value[6] != 0 || el.Value[7] != 0x55 || len(el.Value) != 6+4+9 {
		t.Fatalf("stats envelope = %x", el.Value)
	}

	var rc capwap.PrivRoamingControl
	rc.Reserved[14] = 9
	if err := e.SendRoamingControl(s, rc); err != nil {
		t.Fatal(err)
	}
	pkt2, _ := capwap.ParsePacket(sent[1])
	el2 := pkt2.Elements[0]
	if el2.Value[7] != 0x57 || len(el2.Value) != 6+4+36 {
		t.Fatalf("roaming envelope = %x", el2.Value)
	}

	if err := e.SendStateReportPeriod(s, capwap.PrivStatPrd{A: 60, B: 300}); err != nil {
		t.Fatal(err)
	}
	pkt3, _ := capwap.ParsePacket(sent[2])
	if pkt3.Elements[0].Value[7] != 0x0c {
		t.Fatalf("stat prd envelope = %x", pkt3.Elements[0].Value)
	}
}

func bytesEq(a, b []byte) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
