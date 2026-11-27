// Package eventlog records bounded, structured controller diagnostics. Producers
// never wait for disk I/O; lost records and write failures are made explicit.
package eventlog

import (
	"context"
	"encoding/json"
	"fmt"
	"io"
	"log"
	"os"
	"path/filepath"
	"sync"
	"sync/atomic"
	"time"
)

type Log struct {
	run      string
	output   io.WriteCloser
	queue    chan []byte
	done     chan struct{}
	gate     sync.RWMutex
	closed   atomic.Bool
	dropped  atomic.Uint64
	failures atomic.Uint64
}

type Stats struct {
	Dropped       uint64 `json:"dropped"`
	WriteFailures uint64 `json:"write_failures"`
}

func Open(path string, maxBytes int64, backups int) (*Log, error) {
	w, err := OpenWriter(path, maxBytes, backups)
	if err != nil {
		return nil, err
	}
	return newLog(w), nil
}
func newLog(w io.WriteCloser) *Log {
	l := &Log{run: fmt.Sprintf("%s-%d", time.Now().UTC().Format("20060102T150405.000000000Z"), os.Getpid()), output: w, queue: make(chan []byte, 256), done: make(chan struct{})}
	go l.write()
	return l
}
func (l *Log) Enabled() bool { return l != nil && !l.closed.Load() }
func (l *Log) Stats() Stats {
	if l == nil {
		return Stats{}
	}
	return Stats{l.dropped.Load(), l.failures.Load()}
}

// Fields must be explicit metadata, never a configuration object, secret,
// PMK/key, native-model response body or decrypted packet. Encoding takes place
// before enqueue so callers may safely reuse their mutable snapshots.
func (l *Log) Event(event string, fields ...any) {
	if !l.Enabled() {
		return
	}
	row := map[string]any{"time": time.Now().UTC(), "event": event, "run_id": l.run}
	for i := 0; i+1 < len(fields); i += 2 {
		if key, ok := fields[i].(string); ok {
			row[key] = fields[i+1]
		}
	}
	b, err := json.Marshal(row)
	if err != nil || len(b) > 64<<10 {
		l.dropped.Add(1)
		return
	}
	b = append(b, '\n')
	l.gate.RLock()
	defer l.gate.RUnlock()
	if l.closed.Load() {
		return
	}
	select {
	case l.queue <- b:
	default:
		l.dropped.Add(1)
	}
}
func (l *Log) write() {
	defer close(l.done)
	defer l.output.Close()
	var reported uint64
	var lastError time.Time
	emit := func(b []byte) {
		if _, err := l.output.Write(b); err != nil {
			l.failures.Add(1)
			if time.Since(lastError) >= time.Minute {
				log.Printf("event log write failed: %v", err)
				lastError = time.Now()
			}
		}
	}
	for b := range l.queue {
		if lost := l.dropped.Load(); lost != reported {
			status, _ := json.Marshal(map[string]any{"time": time.Now().UTC(), "event": "observer.records_dropped", "run_id": l.run, "dropped_total": lost, "write_failures": l.failures.Load()})
			emit(append(status, '\n'))
			reported = lost
		}
		emit(b)
	}
}
func (l *Log) Close() error {
	if l == nil {
		return nil
	}
	l.gate.Lock()
	if l.closed.Swap(true) {
		l.gate.Unlock()
		<-l.done
		return nil
	}
	close(l.queue)
	l.gate.Unlock()
	<-l.done
	return nil
}

type contextKey struct{}

func With(ctx context.Context, fields ...any) context.Context {
	all := append([]any{}, Fields(ctx)...)
	all = append(all, fields...)
	return context.WithValue(ctx, contextKey{}, all)
}
func Fields(ctx context.Context) []any {
	if ctx == nil {
		return nil
	}
	v, _ := ctx.Value(contextKey{}).([]any)
	return v
}
func (l *Log) Context(ctx context.Context, event string, fields ...any) {
	if !l.Enabled() {
		return
	}
	all := append([]any{}, Fields(ctx)...)
	l.Event(event, append(all, fields...)...)
}

// Writer rotates whole records. Paths are private even when the caller's umask
// is permissive. It is also used for the optional private protocol trace.
type Writer struct {
	mu      sync.Mutex
	path    string
	max     int64
	backups int
	file    *os.File
	size    int64
}

func OpenWriter(path string, maxBytes int64, backups int) (*Writer, error) {
	if maxBytes < 1 || backups < 1 || backups > 100 {
		return nil, fmt.Errorf("invalid event log rotation limits")
	}
	if err := os.MkdirAll(filepath.Dir(path), 0700); err != nil {
		return nil, err
	}
	w := &Writer{path: path, max: maxBytes, backups: backups}
	if err := w.open(); err != nil {
		return nil, err
	}
	return w, nil
}
func (w *Writer) open() error {
	f, err := os.OpenFile(w.path, os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0600)
	if err != nil {
		return err
	}
	if err = f.Chmod(0600); err != nil {
		f.Close()
		return err
	}
	st, err := f.Stat()
	if err != nil {
		f.Close()
		return err
	}
	w.file, w.size = f, st.Size()
	return nil
}
func (w *Writer) Write(b []byte) (int, error) {
	w.mu.Lock()
	defer w.mu.Unlock()
	if w.file == nil {
		if err := w.open(); err != nil {
			return 0, err
		}
	}
	if w.size > 0 && w.size+int64(len(b)) > w.max {
		if err := w.file.Close(); err != nil {
			return 0, err
		}
		w.file = nil
		for i := w.backups; i >= 1; i-- {
			from := w.path
			if i > 1 {
				from = fmt.Sprintf("%s.%d", w.path, i-1)
			}
			to := fmt.Sprintf("%s.%d", w.path, i)
			if err := os.Rename(from, to); err != nil && !os.IsNotExist(err) {
				return 0, err
			}
		}
		if err := w.open(); err != nil {
			return 0, err
		}
	}
	n, err := w.file.Write(b)
	w.size += int64(n)
	return n, err
}
func (w *Writer) Close() error {
	w.mu.Lock()
	defer w.mu.Unlock()
	if w.file == nil {
		return nil
	}
	err := w.file.Close()
	w.file = nil
	return err
}
