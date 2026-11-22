// Package jcs implements the uac_com JCS IPC transport.
//
// Evidence (uac binary):
//   - jcs_init @0x5293f0: per-process callback table; process name read from
//     /proc/<pid> (uac_com_get_name_by_pid @0x5148d4).
//   - jcs_run @0x529564: two server threads per process — "jcs_ui" bound to
//     /tmp/jcs.ui.srv.<name> and "jcs_service" bound to
//     /tmp/jcs.service.srv.<name> (sprintf("%s.%s", ...) @0x529564).
//   - jcs_send_to_process @0x529778: AF_UNIX SOCK_STREAM client
//     (socket(1,1,0)), connect to the target process's endpoint.
//   - jcs_work_task @0x528560: accept loop with a 0x20001-byte receive
//     buffer (128 KiB max JSON payload).
//
// The wire payload is JSON (the Lua ds layer speaks the same module/keyword
// requests). Framing: the vendor reads straight into a 128 KiB buffer —
// one JSON request per socket write, response streamed back (confirmed
// layout pending a live capture; this package uses whole-request framing,
// one request/response pair per connection, which the client-side call
// pattern in jcs_send_to_process implies).
package jcs

import (
	"encoding/json"
	"errors"
	"fmt"
	"net"
	"os"
	"sync"
	"syscall"
	"time"
)

// ServicePath returns the service endpoint for a process name.
func ServicePath(name string) string { return "/tmp/jcs.service.srv." + name }

// UIPath returns the UI endpoint for a process name.
func UIPath(name string) string { return "/tmp/jcs.ui.srv." + name }

// maxPayload mirrors the binary's 0x20001-byte receive buffer.
const maxPayload = 0x20001

// Handler processes one JCS request (decoded JSON) and returns the response
// value ( marshalled back). Mirrors the vendor's jcs_callback_register table
// (116 _jcs_* handlers across 26 subsystems).
type Handler func(req json.RawMessage) (any, error)

// Server is one process's JCS endpoint (service and/or UI socket).
type Server struct {
	mu       sync.Mutex
	handlers map[string]Handler
	lns      []net.Listener
}

// NewServer creates a handler registry.
func NewServer() *Server {
	return &Server{handlers: make(map[string]Handler)}
}

// Register installs a handler under "<module>.<keyword>" (the ds request
// shape the Lua layer emits: {"method":"get","<module>":{"name":..}}).
func (s *Server) Register(key string, h Handler) {
	s.mu.Lock()
	s.handlers[key] = h
	s.mu.Unlock()
}

// Serve binds path and serves until Close. Stale sockets are removed first
// (the vendor unlinks before bind on restart).
func (s *Server) Serve(path string) error {
	os.Remove(path)
	ln, err := net.ListenUnix("unix", &net.UnixAddr{Name: path, Net: "unix"})
	if err != nil {
		return fmt.Errorf("jcs listen %s: %w", path, err)
	}
	s.mu.Lock()
	s.lns = append(s.lns, ln)
	s.mu.Unlock()
	for {
		c, err := ln.AcceptUnix()
		if err != nil {
			return err
		}
		go s.handle(c)
	}
}

// handle reads one JSON request, dispatches, writes one JSON response.
func (s *Server) handle(c *net.UnixConn) {
	defer c.Close()
	buf := make([]byte, maxPayload)
	n, err := c.Read(buf)
	if err != nil && n == 0 {
		return
	}
	var env struct {
		Method  string          `json:"method"`
		Module  string          `json:"module"`
		Keyword string          `json:"keyword"`
		Params  json.RawMessage `json:"params"`
	}
	if err := json.Unmarshal(buf[:n], &env); err != nil {
		writeErr(c, "bad request")
		return
	}
	s.mu.Lock()
	h := s.handlers[env.Module+"."+env.Keyword]
	s.mu.Unlock()
	if h == nil {
		writeErr(c, fmt.Sprintf("no handler for %s.%s", env.Module, env.Keyword))
		return
	}
	resp, err := h(env.Params)
	if err != nil {
		writeErr(c, err.Error())
		return
	}
	out, _ := json.Marshal(resp)
	c.Write(out)
}

func writeErr(c *net.UnixConn, msg string) {
	b, _ := json.Marshal(map[string]any{"error_code": -1, "error": msg})
	c.Write(b)
}

// Call sends one request to a remote endpoint and reads the response.
func Call(path, method, module, keyword string, params any) (json.RawMessage, error) {
	c, err := dialRetry(path, 20)
	if err != nil {
		return nil, err
	}
	defer c.Close()
	req, _ := json.Marshal(map[string]any{
		"method": method, "module": module, "keyword": keyword, "params": params})
	if _, err := c.Write(req); err != nil {
		return nil, err
	}
	buf := make([]byte, maxPayload)
	n, err := c.Read(buf)
	if err != nil {
		return nil, err
	}
	return json.RawMessage(buf[:n]), nil
}

// dialRetry tolerates an endpoint that is still binding its socket
// (Serve runs in a goroutine right after the bind; local-socket startup
// window).
func dialRetry(path string, attempts int) (*net.UnixConn, error) {
	var err error
	for i := 0; i < attempts; i++ {
		var c *net.UnixConn
		c, err = net.DialUnix("unix", nil, &net.UnixAddr{Name: path, Net: "unix"})
		if err == nil {
			return c, nil
		}
		if !errors.Is(err, syscall.ECONNREFUSED) && !errors.Is(err, os.ErrNotExist) {
			break
		}
		time.Sleep(25 * time.Millisecond)
	}
	return nil, fmt.Errorf("jcs dial %s: %w", path, err)
}

// Close shuts every listener down.
func (s *Server) Close() {
	s.mu.Lock()
	defer s.mu.Unlock()
	for _, ln := range s.lns {
		ln.Close()
	}
	s.lns = nil
}
