//go:build linux

package dhcpserver

import (
	"context"
	"fmt"
	"golang.org/x/sys/unix"
	"net"
	"syscall"
)

func (s *Server) Serve(ctx context.Context) error {
	nic, err := net.InterfaceByName(s.cfg.Interface)
	if err != nil {
		return err
	}
	addresses, err := nic.Addrs()
	if err != nil {
		return err
	}
	found := false
	for _, a := range addresses {
		ip, _, _ := net.ParseCIDR(a.String())
		found = found || ip.Equal(net.ParseIP(s.cfg.Server))
	}
	if !found {
		return fmt.Errorf("DHCP server address is not assigned to bound interface")
	}
	lc := net.ListenConfig{Control: func(_, _ string, c syscall.RawConn) error {
		var inner error
		err := c.Control(func(fd uintptr) {
			inner = unix.SetsockoptString(int(fd), unix.SOL_SOCKET, unix.SO_BINDTODEVICE, s.cfg.Interface)
			if inner == nil {
				inner = unix.SetsockoptInt(int(fd), unix.SOL_SOCKET, unix.SO_BROADCAST, 1)
			}
		})
		if err != nil {
			return err
		}
		return inner
	}}
	conn, err := lc.ListenPacket(ctx, "udp4", "0.0.0.0:67")
	if err != nil {
		return err
	}
	defer conn.Close()
	go func() { <-ctx.Done(); conn.Close() }()
	buf := make([]byte, 1600)
	for {
		n, _, err := conn.ReadFrom(buf)
		if err != nil {
			if ctx.Err() != nil {
				return nil
			}
			return err
		}
		reply, err := s.Handle(buf[:n])
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
	}
}
