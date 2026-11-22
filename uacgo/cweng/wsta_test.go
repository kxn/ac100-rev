package cweng

import (
	"net"
	"testing"
	"time"

	"uacgo/capwap"
)

// A WTP Event Request carrying 0x34 station info updates the client table
// and the response carries result code 0 (wsta listener @0x6360ec path).
func TestWstaClientTracking(t *testing.T) {
	e, _ := NewEngine(0)
	e.RegisterAttachHandlers(fixtureIdentity{})
	table := NewClientTable()
	e.RegisterWstaHandlers(table)
	go func() { _ = e.Run() }()

	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	read := func() []byte {
		buf := make([]byte, capwap.MaxUdpPayload)
		c.SetReadDeadline(time.Now().Add(2 * time.Second))
		n, err := c.Read(buf)
		if err != nil {
			t.Fatalf("no response: %v", err)
		}
		return buf[:n]
	}

	// join + cfg status + cse to reach RUN (msg 9 gate in RUN accepts 9)
	c.Write(withSeq(t, "cw_join_req_0074f150.bin", 2))
	read()
	c.Write(withSeq(t, "cw_cfg_req_0074ef5c.bin", 3))
	read()
	c.Write(withSeq(t, "cw_cse_req_0074ee9c.bin", 4))
	read()

	// WTP event request with a station info list (msg 9, seq 5)
	pkt, _ := capwap.NewParsedPacket(capwap.MsgWTPEvent)
	pkt.Control.SeqNum = 5
	l := capwap.StaInfoList{RadioID: 1}
	l.Entries = append(l.Entries, capwap.StaInfoEntry{
		A: 1, B: 2, MAC: [6]byte{0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff}})
	pkt.Elements = append(pkt.Elements, capwap.Element{Type: 0x0034, Value: l.AssembleValue()})
	c.Write(pkt.Assemble())
	rspPkt, err := capwap.ParsePacket(read())
	if err != nil {
		t.Fatal(err)
	}
	if rspPkt.Control.MsgType != capwap.MsgWTPEventResponse {
		t.Fatalf("response msg = %d", rspPkt.Control.MsgType)
	}
	hasResult := false
	for _, el := range rspPkt.Elements {
		if el.Type == 0x0021 {
			hasResult = true
		}
	}
	if !hasResult {
		t.Fatal("wtp event response missing result code")
	}
	evs := table.All()
	if len(evs) != 1 || evs[0].MAC != [6]byte{0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff} {
		t.Fatalf("client events = %+v", evs)
	}
}
