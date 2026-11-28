package dhcpserver

import (
	"context"
	"encoding/binary"
	"net"
	"uacgo/internal/eventlog"
)

func (s *Server) Serve(ctx context.Context) error {
	conn, err := listenDHCP(ctx, s.cfg)
	if err != nil {
		return err
	}
	defer conn.Close()
	return serveDHCPPackets(ctx, conn, s.Handle, s.Events)
}

func serveDHCPPackets(ctx context.Context, conn net.PacketConn, handle func([]byte) ([]byte, error), events *eventlog.Log) error {
	done := make(chan struct{})
	defer close(done)
	go func() {
		select {
		case <-ctx.Done():
			conn.Close()
		case <-done:
		}
	}()
	buf := make([]byte, 1600)
	for {
		n, _, err := conn.ReadFrom(buf)
		if err != nil {
			if ctx.Err() != nil {
				return nil
			}
			return err
		}
		reply, err := handle(buf[:n])
		if err != nil {
			return err
		}
		if reply == nil {
			continue
		}
		target := &net.UDPAddr{IP: net.IPv4bcast, Port: 68}
		if !net.IP(buf[12:16]).IsUnspecified() && buf[10]&128 == 0 {
			target.IP = append(net.IP{}, buf[12:16]...)
		}
		if _, err = conn.WriteTo(reply, target); err != nil {
			return err
		}
		events.Event("dhcp.reply_sent", "mac", net.HardwareAddr(reply[28:34]).String(), "transaction", binary.BigEndian.Uint32(reply[4:8]), "message_type", reply[242], "address", net.IP(reply[16:20]).String(), "destination", target.String())
	}
}
