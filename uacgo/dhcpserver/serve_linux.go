//go:build linux

package dhcpserver

import (
	"context"
	"fmt"
	"golang.org/x/sys/unix"
	"net"
	"syscall"
)

func checkDHCPBinding(cfg Config) error {
	nic, err := net.InterfaceByName(cfg.Interface)
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
		found = found || ip.Equal(net.ParseIP(cfg.Server))
	}
	if !found {
		return fmt.Errorf("DHCP server address is not assigned to bound interface")
	}
	return nil
}

func listenDHCP(ctx context.Context, cfg Config) (net.PacketConn, error) {
	if err := checkDHCPBinding(cfg); err != nil {
		return nil, err
	}
	lc := net.ListenConfig{Control: func(_, _ string, c syscall.RawConn) error {
		var inner error
		err := c.Control(func(fd uintptr) {
			inner = unix.SetsockoptString(int(fd), unix.SOL_SOCKET, unix.SO_BINDTODEVICE, cfg.Interface)
			if inner == nil {
				inner = unix.SetsockoptInt(int(fd), unix.SOL_SOCKET, unix.SO_BROADCAST, 1)
			}
		})
		if err != nil {
			return err
		}
		return inner
	}}
	return lc.ListenPacket(ctx, "udp4", "0.0.0.0:67")
}
