// Package dhcpserver implements the controller's opt-in AP-only DHCPv4 service.
package dhcpserver

import (
	"bytes"
	"encoding/binary"
	"encoding/hex"
	"encoding/json"
	"fmt"
	"net"
	"os"
	"path/filepath"
	"sync"
	"time"
	"uacgo/internal/eventlog"
)

type Config struct {
	Reservations map[string]string `json:"reservations,omitempty"`
	Interface    string            `json:"interface"`
	Server       string            `json:"server"`
	Start        string            `json:"start"`
	End          string            `json:"end"`
	Netmask      string            `json:"netmask"`
	Gateway      string            `json:"gateway,omitempty"`
	DNS          []string          `json:"dns,omitempty"`
	AC           []string          `json:"ac"`
	LeaseSeconds uint32            `json:"lease_seconds"`
	LeaseFile    string            `json:"lease_file,omitempty"`
}
type Lease struct {
	MAC     string    `json:"mac,omitempty"`
	IP      string    `json:"ip"`
	Expires time.Time `json:"expires"`
	Bound   bool      `json:"bound"`
}
type Server struct {
	Events     *eventlog.Log
	reserved   map[string]uint32
	owners     map[uint32]string
	mu         sync.Mutex
	cfg        Config
	leases     map[string]Lease
	now        func() time.Time
	start, end uint32
	network    uint32
	mask       uint32
}

func ipnum(s string) (uint32, error) {
	ip := net.ParseIP(s).To4()
	if ip == nil {
		return 0, fmt.Errorf("invalid IPv4 address %q", s)
	}
	return binary.BigEndian.Uint32(ip), nil
}
func numip(n uint32) string { return net.IP(binary.BigEndian.AppendUint32(nil, n)).String() }
func New(c Config) (*Server, error) {
	if c.Interface == "" {
		return nil, fmt.Errorf("AP DHCP requires an explicit interface")
	}
	server, err := ipnum(c.Server)
	if err != nil {
		return nil, err
	}
	mask, err := ipnum(c.Netmask)
	if err != nil {
		return nil, err
	}
	ones, bits := net.IPMask(net.ParseIP(c.Netmask).To4()).Size()
	if bits != 32 || ones < 16 || ones > 30 {
		return nil, fmt.Errorf("DHCP mask must be /16–/30")
	}
	lo, err := ipnum(c.Start)
	if err != nil {
		return nil, err
	}
	hi, err := ipnum(c.End)
	if err != nil {
		return nil, err
	}
	network := server & mask
	if lo > hi || hi-lo >= 4096 || lo&mask != network || hi&mask != network || lo == network || hi == network|^mask {
		return nil, fmt.Errorf("invalid DHCP pool")
	}
	if c.LeaseSeconds < 60 || c.LeaseSeconds > 604800 || len(c.AC) == 0 || len(c.AC) > 16 || len(c.DNS) > 8 {
		return nil, fmt.Errorf("lease is 60–604800 seconds; 1–16 AC addresses required")
	}
	for _, ip := range append(append(append([]string{}, c.AC...), c.DNS...), c.Gateway) {
		if ip != "" {
			if _, err := ipnum(ip); err != nil {
				return nil, err
			}
		}
	}
	s := &Server{cfg: c, leases: map[string]Lease{}, now: time.Now, start: lo, end: hi, network: network, mask: mask}
	s.reserved = map[string]uint32{}
	s.owners = map[uint32]string{}
	for raw, address := range c.Reservations {
		mac, err := net.ParseMAC(raw)
		if err != nil || len(mac) != 6 || mac[0]&1 != 0 || bytes.Equal(mac, make([]byte, 6)) {
			return nil, fmt.Errorf("invalid DHCP reservation MAC")
		}
		ip, err := ipnum(address)
		if err != nil || !s.usable(ip) {
			return nil, fmt.Errorf("reservation is outside usable AP pool")
		}
		key := hex.EncodeToString(mac)
		if _, ok := s.reserved[key]; ok {
			return nil, fmt.Errorf("duplicate DHCP reservation MAC")
		}
		if _, ok := s.owners[ip]; ok {
			return nil, fmt.Errorf("duplicate DHCP reservation IP")
		}
		s.reserved[key], s.owners[ip] = ip, key
	}

	if c.LeaseFile != "" {
		b, err := os.ReadFile(c.LeaseFile)
		if err == nil {
			if err = json.Unmarshal(b, &s.leases); err != nil {
				return nil, err
			}
			if s.leases == nil {
				s.leases = map[string]Lease{}
			}
		} else if !os.IsNotExist(err) {
			return nil, err
		}
	}
	return s, nil
}

// Original AC V6 dhcpd: discover FUN_00412f30 and request FUN_004137b0
// compare option 60's complete length and seven bytes. No OUI or prefix match.
func IsAPVendor(v []byte) bool { return bytes.Equal(v, []byte("TP-LINK")) }
func options(b []byte) (map[byte][]byte, bool) {
	out := map[byte][]byte{}
	for len(b) > 0 {
		code := b[0]
		b = b[1:]
		if code == 255 {
			return out, true
		}
		if code == 0 {
			continue
		}
		if len(b) < 1 || int(b[0]) > len(b)-1 {
			return nil, false
		}
		n := int(b[0])
		b = b[1:]
		if _, ok := out[code]; ok {
			return nil, false
		}
		out[code] = b[:n]
		b = b[n:]
	}
	return nil, false
}
func (s *Server) usable(ip uint32) bool {
	if ip < s.start || ip > s.end {
		return false
	}
	if ip == s.network || ip == s.network|^s.mask {
		return false
	}
	for _, v := range []string{s.cfg.Server, s.cfg.Gateway} {
		if v != "" {
			n, _ := ipnum(v)
			if n == ip {
				return false
			}
		}
	}
	return true
}
func (s *Server) free(ip uint32, key, mac string) bool {
	if owner, ok := s.owners[ip]; ok && owner != mac {
		return false
	}
	if fixed, ok := s.reserved[mac]; ok && fixed != ip {
		return false
	}
	if !s.usable(ip) {
		return false
	}
	for k, l := range s.leases {
		if k != key && l.IP == numip(ip) && l.Expires.After(s.now()) {
			if fixed, ok := s.reserved[mac]; ok && fixed == ip && l.MAC == mac {
				continue
			}
			return false
		}
	}
	return true
}
func (s *Server) persist() error {
	if s.cfg.LeaseFile == "" {
		return nil
	}
	b, err := json.MarshalIndent(s.leases, "", "  ")
	if err != nil {
		return err
	}
	dir := filepath.Dir(s.cfg.LeaseFile)
	f, err := os.CreateTemp(dir, ".dhcp-")
	if err != nil {
		return err
	}
	defer os.Remove(f.Name())
	defer f.Close()
	if err = f.Chmod(0600); err != nil {
		return err
	}
	if _, err = f.Write(b); err != nil {
		return err
	}
	if err = f.Sync(); err != nil {
		return err
	}
	if err = f.Close(); err != nil {
		return err
	}
	return os.Rename(f.Name(), s.cfg.LeaseFile)
}

// Handle returns no packet for an ordinary network client, malformed request,
// relay, another DHCP server's selection, or a foreign address. It never NAKs
// clients belonging to another DHCP service.
func (s *Server) Handle(b []byte) ([]byte, error) {
	if len(b) < 240 || len(b) > 1500 || b[0] != 1 || b[1] != 1 || b[2] != 6 || b[3] != 0 || !bytes.Equal(b[236:240], []byte{99, 130, 83, 99}) || !bytes.Equal(b[24:28], []byte{0, 0, 0, 0}) || b[28]&1 != 0 || bytes.Equal(b[28:34], make([]byte, 6)) {
		return nil, nil
	}
	opts, ok := options(b[240:])
	if !ok || len(opts[53]) != 1 || opts[52] != nil {
		return nil, nil
	}
	typ := opts[53][0]
	// V6 Discover accepts the exact Mesh Detect identity; Request deliberately
	// accepts only TP-LINK. The probe can see an offer, but cannot claim a lease.
	meshDetect := typ == 1 && bytes.Equal(opts[60], []byte("TP-LINK MESH DETECT 1.0"))
	if !IsAPVendor(opts[60]) && !meshDetect {
		return nil, nil
	}
	if typ != 1 && typ != 3 && typ != 4 && typ != 7 && typ != 8 {
		return nil, nil
	}
	mac := hex.EncodeToString(b[28:34])
	s.Events.Event("dhcp.ap_request", "mac", net.HardwareAddr(b[28:34]).String(), "message_type", typ, "transaction", binary.BigEndian.Uint32(b[4:8]), "ciaddr", net.IP(b[12:16]).String(), "selected_server", net.IP(opts[54]).String(), "mesh_detect", meshDetect)
	server := net.ParseIP(s.cfg.Server).To4()
	if v := opts[54]; v != nil && (len(v) != 4 || !bytes.Equal(v, server)) {
		return nil, nil
	}
	key := "mac:" + hex.EncodeToString(b[28:34])
	if id := opts[61]; len(id) > 0 {
		key = "id:" + hex.EncodeToString(id)
	}
	s.mu.Lock()
	defer s.mu.Unlock()
	now := s.now()
	for k, l := range s.leases {
		if !l.Expires.After(now) {
			delete(s.leases, k)
		}
	}
	requested := binary.BigEndian.Uint32(b[12:16])
	if v := opts[50]; v != nil {
		if len(v) != 4 {
			return nil, nil
		}
		requested = binary.BigEndian.Uint32(v)
	}
	if typ == 4 || typ == 7 {
		if l, ok := s.leases[key]; ok && l.IP == numip(requested) {
			delete(s.leases, key)
			if typ == 4 {
				s.leases["declined:"+numip(requested)] = Lease{IP: numip(requested), Expires: now.Add(10 * time.Minute)}
			}
			if err := s.persist(); err != nil {
				return nil, err
			}
		}
		return nil, nil
	}
	address := uint32(0)
	response := byte(5)
	if typ == 8 {
		if requested&s.mask != s.network || requested == 0 {
			return nil, nil
		}
	} else {
		if typ == 1 {
			response = 2
			if fixed, ok := s.reserved[mac]; ok {
				address = fixed
			} else if l, ok := s.leases[key]; ok {
				address, _ = ipnum(l.IP)
			}
			if address == 0 && s.free(requested, key, mac) {
				address = requested
			}
			if !s.free(address, key, mac) {
				address = 0
			}
			if address == 0 {
				for n := s.start; n <= s.end; n++ {
					if s.free(n, key, mac) {
						address = n
						break
					}
				}
			}
		} else {
			if !s.free(requested, key, mac) {
				return nil, nil
			}
			address = requested
		}
		if address == 0 {
			s.Events.Event("dhcp.no_available_address", "mac", net.HardwareAddr(b[28:34]).String(), "requested", numip(requested), "reserved", numip(s.reserved[mac]))
			return nil, nil
		}
		expiry := now.Add(time.Duration(s.cfg.LeaseSeconds) * time.Second)
		if typ == 1 {
			expiry = now.Add(time.Minute)
		}
		s.leases[key] = Lease{MAC: mac, IP: numip(address), Expires: expiry, Bound: typ == 3}
		if err := s.persist(); err != nil {
			return nil, err
		}
	}
	s.Events.Event("dhcp.ap_reply", "mac", net.HardwareAddr(b[28:34]).String(), "message_type", response, "address", numip(address), "ac", s.cfg.AC, "lease_seconds", s.cfg.LeaseSeconds)
	out := make([]byte, 240)
	out[0] = 2
	out[1] = 1
	out[2] = 6
	copy(out[4:12], b[4:12])
	copy(out[12:16], b[12:16])
	binary.BigEndian.PutUint32(out[16:20], address)
	copy(out[20:24], server)
	copy(out[28:44], b[28:44])
	copy(out[236:], []byte{99, 130, 83, 99})
	add := func(code byte, v []byte) { out = append(out, code, byte(len(v))); out = append(out, v...) }
	add(53, []byte{response})
	add(54, server)
	add(1, net.ParseIP(s.cfg.Netmask).To4())
	if typ != 8 {
		add(51, binary.BigEndian.AppendUint32(nil, s.cfg.LeaseSeconds))
		add(58, binary.BigEndian.AppendUint32(nil, s.cfg.LeaseSeconds/2))
		add(59, binary.BigEndian.AppendUint32(nil, s.cfg.LeaseSeconds*7/8))
	}
	if s.cfg.Gateway != "" {
		add(3, net.ParseIP(s.cfg.Gateway).To4())
	}
	if len(s.cfg.DNS) > 0 {
		v := []byte{}
		for _, ip := range s.cfg.DNS {
			v = append(v, net.ParseIP(ip).To4()...)
		}
		add(6, v)
	}
	ac := []byte{}
	for _, ip := range s.cfg.AC {
		ac = append(ac, net.ParseIP(ip).To4()...)
	}
	add(138, ac)
	add(43, append([]byte{1, byte(len(ac))}, ac...))
	out = append(out, 255)
	for len(out) < 300 {
		out = append(out, 0)
	}
	return out, nil
}
