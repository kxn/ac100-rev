package cweng

import (
	"net"
	"testing"
	"time"
)

// raw UDP loopback baseline for the sandbox
func TestRawUDPLoopback(t *testing.T) {
	srv, err := net.ListenUDP("udp", &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 0})
	if err != nil {
		t.Fatal(err)
	}
	defer srv.Close()
	cli, err := net.DialUDP("udp", nil, srv.LocalAddr().(*net.UDPAddr))
	if err != nil {
		t.Fatal(err)
	}
	defer cli.Close()

	done := make(chan []byte, 1)
	go func() {
		buf := make([]byte, 128)
		n, _, err := srv.ReadFromUDP(buf)
		if err == nil {
			done <- buf[:n]
			srv.WriteToUDP([]byte("pong"), &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: cli.LocalAddr().(*net.UDPAddr).Port})
		}
	}()
	cli.Write([]byte("ping"))
	cli.SetReadDeadline(time.Now().Add(2 * time.Second))
	buf := make([]byte, 64)
	n, err := cli.Read(buf)
	if err != nil {
		t.Fatalf("raw udp loopback failed: %v", err)
	}
	select {
	case b := <-done:
		t.Logf("server side got %q, client got %q", b, buf[:n])
	default:
	}
}
