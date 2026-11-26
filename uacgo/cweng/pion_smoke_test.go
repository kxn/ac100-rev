package cweng

import (
	"context"
	"crypto/tls"
	"fmt"
	"net"
	"testing"
	"time"

	dtls "github.com/pion/dtls/v2"
)

func TestPionSmoke(t *testing.T) {
	listener, err := dtls.Listen("udp", &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1)},
		&dtls.Config{Certificates: []tls.Certificate{*genCert(t)}, ClientAuth: dtls.NoClientCert})
	if err != nil {
		t.Fatal(err)
	}
	defer listener.Close()
	serverErr := make(chan error, 1)
	go func() {
		conn, err := listener.Accept()
		if err != nil {
			serverErr <- err
			return
		}
		defer conn.Close()
		conn.SetDeadline(time.Now().Add(5 * time.Second))
		buf := make([]byte, 128)
		n, err := conn.Read(buf)
		if err == nil && string(buf[:n]) != "ping" {
			err = fmt.Errorf("unexpected payload %q", buf[:n])
		}
		if err == nil {
			_, err = conn.Write([]byte("pong"))
		}
		serverErr <- err
	}()
	raw, err := net.DialUDP("udp", nil, listener.Addr().(*net.UDPAddr))
	if err != nil {
		t.Fatal(err)
	}
	defer raw.Close()
	ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
	defer cancel()
	client, err := dtls.ClientWithContext(ctx, raw, &dtls.Config{InsecureSkipVerify: true})
	if err != nil {
		t.Fatalf("client handshake: %v", err)
	}
	defer client.Close()
	client.SetDeadline(time.Now().Add(5 * time.Second))
	if _, err := client.Write([]byte("ping")); err != nil {
		t.Fatal(err)
	}
	buf := make([]byte, 128)
	n, err := client.Read(buf)
	if err != nil || string(buf[:n]) != "pong" {
		t.Fatalf("client response: %v %q", err, buf[:n])
	}
	select {
	case err := <-serverErr:
		if err != nil {
			t.Fatal(err)
		}
	case <-ctx.Done():
		t.Fatal("server timeout")
	}
}
