//go:build !linux

package dhcpserver

import (
	"context"
	"fmt"
	"net"
)

func checkDHCPBinding(cfg Config) error {
	return fmt.Errorf("AP-only DHCP requires Linux interface binding")
}

func listenDHCP(ctx context.Context, cfg Config) (net.PacketConn, error) {
	return nil, checkDHCPBinding(cfg)
}
