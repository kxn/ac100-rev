//go:build !linux

package dhcpserver

import (
	"context"
	"fmt"
)

func (s *Server) Serve(ctx context.Context) error {
	return fmt.Errorf("AP-only DHCP requires Linux interface binding")
}
