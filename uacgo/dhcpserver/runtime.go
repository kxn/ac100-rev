package dhcpserver

import (
	"context"
	"encoding/json"
	"fmt"
	"net"
	"os"
	"path/filepath"
	"sort"
	"sync"
	"time"
	"uacgo/internal/eventlog"
)

// Settings extends the existing --ap-dhcp file. Legacy files without enabled
// remain enabled; a fresh installation stays off and never opens port67.
type Settings struct {
	Config
	Enabled bool `json:"enabled"`
}

func (p Settings) clone() Settings {
	p.AC = append([]string(nil), p.AC...)
	p.DNS = append([]string(nil), p.DNS...)
	if p.Reservations != nil {
		copy := make(map[string]string, len(p.Reservations))
		for mac, ip := range p.Reservations {
			copy[mac] = ip
		}
		p.Reservations = copy
	}
	return p
}

type Status struct {
	Settings Settings `json:"settings"`
	Running  bool     `json:"running"`
	Error    string   `json:"error,omitempty"`
	Leases   []Lease  `json:"leases"`
}

// Runtime owns the optional DHCP socket independently of CAPWAP. Updating a
// pool replaces the packet handler on the same socket; disabling closes only
// this socket. Management writes and packet processing share one lock so a
// new handler cannot reload lease state while an old handler is persisting it.
type Runtime struct {
	mu        sync.Mutex
	ctx       context.Context
	path      string
	bound     string
	leaseFile string
	settings  Settings
	server    *Server
	conn      net.PacketConn
	lastError string
	events    *eventlog.Log
}

func NewRuntime(ctx context.Context, path, bound string, events *eventlog.Log) (*Runtime, error) {
	return NewRuntimeFrom(ctx, path, "", bound, events)
}

// A read-only container seed is used until settings are first saved in the
// writable data directory. Later starts load that saved configuration.
func NewRuntimeFrom(ctx context.Context, path, seed, bound string, events *eventlog.Log) (*Runtime, error) {
	r := &Runtime{ctx: ctx, path: path, bound: bound, events: events, leaseFile: filepath.Join(filepath.Dir(path), "dhcp-leases.json")}
	p := Settings{Config: Config{Interface: bound, LeaseSeconds: 172800}}
	b, err := os.ReadFile(path)
	if os.IsNotExist(err) && seed != "" && seed != path {
		b, err = os.ReadFile(seed)
		if err != nil {
			return nil, err
		}
	}
	if err == nil {
		p.Enabled = true // --ap-dhcp legacy format explicitly opted in.
		if err = json.Unmarshal(b, &p); err != nil {
			return nil, err
		}
	} else if !os.IsNotExist(err) {
		return nil, err
	}
	if p.LeaseFile != "" {
		r.leaseFile = p.LeaseFile
	}
	r.mu.Lock()
	err = r.updateLocked(p, false)
	r.mu.Unlock()
	if err != nil {
		return nil, err
	}
	go func() {
		<-ctx.Done()
		r.mu.Lock()
		if r.conn != nil {
			r.conn.Close()
			r.conn = nil
		}
		r.mu.Unlock()
	}()
	return r, nil
}

func (r *Runtime) Update(p Settings) error {
	r.mu.Lock()
	defer r.mu.Unlock()
	return r.updateLocked(p, true)
}

func (r *Runtime) updateLocked(p Settings, persist bool) error {
	if err := r.ctx.Err(); err != nil {
		return err
	}
	p = p.clone()
	// Neither a management request nor its JSON can choose a filesystem path.
	p.LeaseFile = r.leaseFile
	if p.Interface != r.bound {
		return fmt.Errorf("DHCP 接口必须与当前 AC 绑定接口一致：%s", r.bound)
	}
	var next *Server
	var err error
	if p.Enabled || p.Server != "" || p.Start != "" || p.End != "" {
		next, err = New(p.Config)
		if err != nil {
			return err
		}
		next.Events = r.events
	}
	conn := r.conn
	opened := false
	if p.Enabled {
		if err = checkDHCPBinding(p.Config); err != nil {
			return err
		}
		if conn == nil {
			conn, err = listenDHCP(r.ctx, p.Config)
			if err != nil {
				return fmt.Errorf("启动 AP DHCP：%w", err)
			}
			opened = true
		}
	}
	if persist {
		if err = writeSettings(r.path, p); err != nil {
			if opened {
				conn.Close()
			}
			return err
		}
	}
	r.settings, r.server, r.lastError = p, next, ""
	if !p.Enabled {
		if r.conn != nil {
			r.conn.Close()
		}
		r.conn = nil
	} else if opened {
		r.conn = conn
		go r.serve(conn)
	}
	r.events.Event("dhcp.configuration", "enabled", p.Enabled, "interface", p.Interface, "server", p.Server, "start", p.Start, "end", p.End, "reservations", len(p.Reservations))
	return nil
}

func writeSettings(path string, p Settings) error {
	b, err := json.MarshalIndent(p, "", "  ")
	if err != nil {
		return err
	}
	f, err := os.CreateTemp(filepath.Dir(path), ".ap-dhcp-")
	if err != nil {
		return err
	}
	defer os.Remove(f.Name())
	defer f.Close()
	if err = f.Chmod(0600); err != nil {
		return err
	}
	if _, err = f.Write(append(b, '\n')); err != nil {
		return err
	}
	if err = f.Sync(); err != nil {
		return err
	}
	if err = f.Close(); err != nil {
		return err
	}
	return os.Rename(f.Name(), path)
}

func (r *Runtime) serve(conn net.PacketConn) {
	err := serveDHCPPackets(r.ctx, conn, func(b []byte) ([]byte, error) {
		r.mu.Lock()
		defer r.mu.Unlock()
		if r.conn != conn || !r.settings.Enabled {
			return nil, nil
		}
		return r.server.Handle(b)
	}, r.events)
	r.mu.Lock()
	defer r.mu.Unlock()
	if r.conn == conn {
		conn.Close()
		r.conn = nil
		if err != nil && r.ctx.Err() == nil {
			r.lastError = err.Error()
			r.events.Event("dhcp.service_failed", "error", r.lastError)
		}
	}
}

func (r *Runtime) Status() Status {
	r.mu.Lock()
	defer r.mu.Unlock()
	// Detach maps/slices so callers cannot change the active packet handler.
	settings := r.settings.clone()
	settings.LeaseFile = ""
	status := Status{Settings: settings, Running: r.conn != nil, Error: r.lastError, Leases: []Lease{}}
	now := time.Now()
	if r.server != nil {
		for _, l := range r.server.leases {
			if l.Expires.After(now) {
				status.Leases = append(status.Leases, l)
			}
		}
	}
	sort.Slice(status.Leases, func(i, j int) bool { return status.Leases[i].IP < status.Leases[j].IP })
	return status
}
