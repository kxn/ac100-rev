package cweng

import (
	"bytes"
	"net"
	"testing"
	"time"

	"uacgo/capwap"
)

// Response retransmission: after a join response the AC re-sends it while the
// AP stays silent (ac_msg_handle arms cw_ac_retransmit_timer_start); a new
// request cancels the pending retransmission (ac_packet_buf_send queue flush).
func TestResponseRetransmit(t *testing.T) {
	e, _ := NewEngine(0)
	e.RegisterAttachHandlers(fixtureIdentity{})
	e.RetransIntervalMs = 150
	e.RetransMax = 3
	go func() { _ = e.Run() }()

	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	buf := make([]byte, capwap.MaxUdpPayload)
	read := func(d time.Duration) ([]byte, bool) {
		c.SetReadDeadline(time.Now().Add(d))
		n, err := c.Read(buf)
		if err != nil {
			return nil, false
		}
		return buf[:n], true
	}

	c.Write(withSeq(t, "cw_join_req_0074f150.bin", 2))
	first, ok := read(time.Second)
	if !ok {
		t.Fatal("no join response")
	}
	// stay silent: expect up to 3 retransmissions
	retrans := 0
	for i := 0; i < 3; i++ {
		b, ok := read(time.Second)
		if !ok {
			break
		}
		if !bytes.Equal(b, first) {
			t.Fatalf("retransmission differs from original response")
		}
		retrans++
	}
	if retrans == 0 {
		t.Fatal("no response retransmission observed")
	}

	// a new request cancels pending retransmission: cfg status → response,
	// then silence — after >2 intervals no further packet may arrive.
	c.Write(withSeq(t, "cw_cfg_req_0074ef5c.bin", 3))
	resp2, ok := read(time.Second)
	if !ok {
		t.Fatal("no cfg status response")
	}
	// A gate-accepted packet (CSE in CONFIGURE) replaces the pending
	// retransmission; a gate-rejected one (another cfg status in CONFIGURE)
	// would NOT (the binary drops it before the queue is touched). The CSE
	// response itself then retransmits (msg 11 is an armed request type) —
	// drain those and require the pending cfg-status retransmission stopped:
	// every subsequent packet must be 16 bytes (empty CSE response), never
	// the cfg-status response.
	c.Write(withSeq(t, "cw_cse_req_0074ee9c.bin", 4))
	if _, ok := read(time.Second); !ok {
		t.Fatal("no cse response")
	}
	_ = resp2
	for {
		b, ok := read(700 * time.Millisecond)
		if !ok {
			break
		}
		if len(b) != 16 {
			t.Fatalf("stale cfg-status retransmission after cancel: %d bytes", len(b))
		}
	}
}
