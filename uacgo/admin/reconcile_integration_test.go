package admin

import (
	"context"
	"encoding/binary"
	"fmt"
	"net"
	"os"
	"path/filepath"
	"sync"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

// A UDP AP model with a deferred cache: radio OFF destroys its VAPs, ON
// alone does not restore them. A marker applies the cache, independently of
// the controller's bookkeeping. This tests behavior beyond codec roundtrips.
type deferredAP struct {
	responses     chan *capwap.ParsedPacket
	onCommand     func(*capwap.ParsedPacket)
	conn          *net.UDPConn
	mu            sync.Mutex
	active        map[[2]byte]string
	staged        map[[2]byte]string
	seen          map[string]bool
	commits       int
	dropCommit    bool
	dropACK       bool
	dropAll       bool
	rejectPrivate uint16
	rejectCount   int
	sequence      []string
	commands      int
	packets       []*capwap.ParsedPacket
}

func newDeferredAP(t *testing.T, e *cweng.Engine, joinOptions ...func(*capwap.ParsedPacket)) (*deferredAP, cweng.APStatus) {
	t.Helper()
	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	t.Cleanup(func() { c.Close() })
	for i, name := range []string{"cw_join_req_0074f150.bin", "cw_cfg_req_0074ef5c.bin", "cw_cse_req_0074ee9c.bin"} {
		b, err := os.ReadFile("../testdata/" + name)
		if err != nil {
			t.Fatal(err)
		}
		b[12] = byte(i + 2)
		if i == 0 {
			p, err := capwap.ParsePacket(b)
			if err != nil {
				t.Fatal(err)
			}
			// Independent fake AP identity, including concurrent AP tests.
			port := c.LocalAddr().(*net.UDPAddr).Port
			board := []byte{0x12, 0x34, 0x56, 0x78, 0, 4, 0, 6, 2, 0, 0, 0, byte(port >> 8), byte(port)}
			p.Elements = append(p.Elements, capwap.Element{Type: 0x26, Value: board})
			for _, option := range joinOptions {
				option(p)
			}
			b = p.Assemble()
		}
		if _, err = c.Write(b); err != nil {
			t.Fatal(err)
		}
		c.SetReadDeadline(time.Now().Add(time.Second))
		if _, err = c.Read(make([]byte, 65536)); err != nil {
			t.Fatal(err)
		}
	}
	var ap cweng.APStatus
	for _, a := range e.APs() {
		if a.Address == c.LocalAddr().String() {
			ap = a
		}
	}
	if !ap.Online {
		t.Fatalf("fake AP did not reach RUN: %+v", ap)
	}
	ap.Radios = 2
	ap.Capabilities = []cweng.RadioCapability{{RadioID: 1, MaxSSID: 1}, {RadioID: 2, MaxSSID: 1}}
	f := &deferredAP{conn: c, responses: make(chan *capwap.ParsedPacket, 8), active: map[[2]byte]string{}, staged: map[[2]byte]string{}, seen: map[string]bool{}}
	go func() {
		var fragments capwap.Reassembler
		for {
			c.SetReadDeadline(time.Time{})
			b := make([]byte, 65536)
			n, err := c.Read(b)
			if err != nil {
				return
			}
			complete, err := fragments.Push("controller", b[:n])
			if err != nil || complete == nil {
				continue
			}
			p, err := capwap.ParsePacket(complete)
			if err != nil {
				continue
			}
			if p.Control.MsgType%2 == 0 {
				select {
				case f.responses <- p:
				default:
				}
				continue
			}
			f.mu.Lock()
			f.commands++
			f.packets = append(f.packets, p)
			if f.dropAll {
				f.mu.Unlock()
				continue
			}
			result := byte(0)
			marker := false
			for _, el := range p.Elements {
				if el.Type == 0x25 && len(el.Value) >= 10 && binary.BigEndian.Uint16(el.Value[6:]) == f.rejectPrivate && f.rejectCount > 0 {
					f.rejectCount--
					result = 1
				}
				if el.Type == 0x25 && len(el.Value) >= 10 && binary.BigEndian.Uint16(el.Value[6:]) == 0x41 {
					marker = true
				}
			}
			if marker && f.dropCommit {
				f.mu.Unlock()
				continue
			}
			token := fmt.Sprintf("%x", b[:n])
			fresh := !f.seen[token]
			if fresh {
				f.seen[token] = true
				for _, el := range p.Elements {
					v := el.Value
					switch el.Type {
					case 0x400:
						if len(v) >= 19 {
							f.staged[[2]byte{v[0], v[1]}] = string(v[19:])
						}
					case 0x403:
						if len(v) == 2 {
							f.staged[[2]byte{v[0], v[1]}] = ""
						}
					case 0x1f:
						f.sequence = append(f.sequence, "radio-state")
						if len(v) == 2 && v[1] == 2 {
							for k := range f.active {
								if k[0] == v[0] {
									delete(f.active, k)
								}
							}
						}
					case 0x25:
						if len(v) >= 14 && binary.BigEndian.Uint16(v[6:]) == 0x3a {
							state := "navigation-off"
							if v[10] != 0 {
								state = "navigation-on"
							}
							f.sequence = append(f.sequence, state)
						}
					}
				}
				if marker {
					for k, v := range f.staged {
						if v == "" {
							delete(f.active, k)
						} else {
							f.active[k] = v
						}
					}
					f.staged = map[[2]byte]string{}
					f.commits++
				}
			}
			hook := f.onCommand
			drop := f.dropACK
			f.dropACK = false
			f.mu.Unlock()
			if drop {
				if fresh && hook != nil {
					hook(p)
				}
				continue
			}
			ack, _ := capwap.NewParsedPacket(p.Control.MsgType + 1)
			ack.Control.SeqNum = p.Control.SeqNum
			ack.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, result}}}
			c.Write(ack.Assemble())
			if fresh && hook != nil {
				hook(p)
			}
		}
	}()
	return f, ap
}

func TestCapacityBlockedCreateDoesNotPreventPendingDeleteCommit(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), 5*time.Second)
	defer cancel()
	old := Service{ID: "old", SSID: "Old", Security: "open", Enabled: true, Radios: []uint8{2}}
	cfg := Config{Services: []Service{old}}
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	old.Enabled = false
	old.Deleting = true
	next := Service{ID: "new", SSID: "New", Security: "open", Enabled: true, Radios: []uint8{1, 2}}
	cfg.Services = []Service{next, old}
	cfg.Version++
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	if st := m.status[ap.ID+"/new"]; st.State != "blocked" {
		t.Fatal("capacity failure not classified before any write", st)
	}
	if st := m.status[ap.ID+"/configuration-commit"]; st.State != "acknowledged" {
		t.Fatal("blocked create held delete hostage", st)
	}
	f.mu.Lock()
	defer f.mu.Unlock()
	if len(f.active) != 0 {
		t.Fatal("partial create or uncommitted delete", f.active)
	}
}

func TestLostACKRetriesWithoutReapplyingBatch(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	f.mu.Lock()
	f.dropACK = true
	f.mu.Unlock()
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), 5*time.Second)
	defer cancel()
	s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1}}
	cfg := Config{Services: []Service{s}}
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	f.mu.Lock()
	defer f.mu.Unlock()
	if f.active[[2]byte{1, 1}] != "Office" || f.commits != 1 {
		t.Fatal("retry applied a different operation", f.active, f.commits)
	}
	if m.status[ap.ID+"/office"].State != "acknowledged" {
		t.Fatal("lost ACK never recovered")
	}
}

func TestTelemetrySubscriptionRetriesAfterFailure(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e, func(p *capwap.ParsedPacket) {
		bits := binary.BigEndian.AppendUint32(nil, 0)
		bits = binary.BigEndian.AppendUint32(bits, 1<<17)
		p.Elements = append(p.Elements, capwap.Element{Type: 0x32, Value: bits})
	})
	f.mu.Lock()
	f.rejectPrivate = 0x83
	f.rejectCount = 1
	f.mu.Unlock()
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), time.Second)
	defer cancel()
	m.applyTelemetry(ctx, ap)
	key := ap.ID + "/wireless-reporting"
	m.mu.Lock()
	st := m.status[key]
	m.mu.Unlock()
	if st.State != "failed" {
		t.Fatal("rejection not recorded", st)
	}
	st.At = st.At.Add(-31 * time.Second)
	m.mu.Lock()
	m.status[key] = st
	m.mu.Unlock()
	m.applyTelemetry(ctx, ap)
	m.mu.Lock()
	st = m.status[key]
	m.mu.Unlock()
	if st.State != "acknowledged" {
		t.Fatal("failed subscription was never retried", st)
	}
}

func TestUnresponsiveAPDoesNotBlockAnotherAP(t *testing.T) {
	m, e := testController(t)
	slow, _ := newDeferredAP(t, e)
	fast, _ := newDeferredAP(t, e)
	slow.mu.Lock()
	slow.dropAll = true
	slow.mu.Unlock()
	m.config.Services = []Service{{ID: "office", SSID: "Office", Enabled: true, Security: "open", Radios: []uint8{1}}}
	// The fixture has no radio capability advertisement: a basic reporting
	// subscription still exercises independent AP command timeouts/workers.
	ctx, cancel := context.WithCancel(context.Background())
	done := make(chan struct{})
	go func() { m.Run(ctx); close(done) }()
	defer func() { cancel(); <-done }()
	deadline := time.Now().Add(4 * time.Second)
	for time.Now().Before(deadline) {
		fast.mu.Lock()
		committed := fast.commits > 0
		fast.mu.Unlock()
		if committed {
			return
		}
		time.Sleep(20 * time.Millisecond)
	}
	t.Fatal("unresponsive AP blocked configuration of another AP")
}

func TestLegacyAdvancedFailureRecoversRadioAndRebuildsWLAN(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.Capabilities[0] = cweng.RadioCapability{RadioID: 1, MaxSSID: 1, MaxClients: 64, Modes: []int{6}, Bandwidths: []int{0}}
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), 5*time.Second)
	defer cancel()
	s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1}}
	cfg := Config{Services: []Service{s}}
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	advanced := defaultRadioAdvanced(ap.Capabilities[0])
	cfg.Radios = []RadioSetting{{AP: ap.ID, Radio: 1, Advanced: &advanced}}
	cfg.Version++
	m.config = cfg
	f.mu.Lock()
	f.rejectPrivate = 8
	f.rejectCount = 1
	f.mu.Unlock()
	m.reconcileAP(ctx, ap, cfg)
	if st := m.status[ap.ID+"/radio:1"]; st.State != "failed_recovered" {
		t.Fatal("radio failure/recovery not recorded", st)
	}
	f.mu.Lock()
	ssid := f.active[[2]byte{1, 1}]
	f.mu.Unlock()
	if ssid != "Office" {
		t.Fatal("radio recovery left WLAN absent")
	}
}

func testController(t *testing.T) (*Manager, *cweng.Engine) {
	t.Helper()
	e, err := cweng.NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	t.Cleanup(func() { e.Close() })
	e.Register(3, 1, "test-join", func(_ *cweng.Ctx, _, rsp *capwap.ParsedPacket) bool {
		rsp.Elements = []capwap.Element{{Type: 0x21, Value: []byte{0, 0, 0, 0}}}
		return true
	})
	m, err := New(e, cweng.NewClientTable(), t.TempDir())
	if err != nil {
		t.Fatal(err)
	}
	go e.Run()
	return m, e
}

func TestDeferredDeleteHoldsSlotThroughFailedCommitAndRestart(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), 8*time.Second)
	defer cancel()
	s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1}}
	cfg := Config{Services: []Service{s}}
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	f.mu.Lock()
	ssid := f.active[[2]byte{1, 1}]
	f.dropCommit = true
	f.mu.Unlock()
	if ssid != "Office" {
		t.Fatal("SSID not committed")
	}
	s.Enabled = false
	s.Deleting = true
	cfg.Services = []Service{s}
	cfg.Version++
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	if m.assigned(ap.ID, s.ID, 1) != 1 {
		t.Fatal("slot freed by delete ACK before commit")
	}
	if _, err := m.allocate(ap.ID, "guest", 1, 1); err == nil {
		t.Fatal("uncommitted delete slot reused")
	}
	m.finishDeletions()
	if len(m.config.Services) != 1 {
		t.Fatal("lost deletion tombstone")
	}
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if restored.assigned(ap.ID, s.ID, 1) != 1 {
		t.Fatal("restart lost pending reservation")
	}
	f.mu.Lock()
	f.dropCommit = false
	f.mu.Unlock()
	m.mu.Lock()
	delete(m.applied, ap.ID+"/configuration-commit")
	m.mu.Unlock()
	m.commitAP(ctx, ap, cfg)
	m.mu.Lock()
	st := m.settling[ap.ID]
	m.mu.Unlock()
	if st.Version == "" {
		t.Fatal("commit did not create settlement")
	}
	if err = m.settleWLANs(ap.ID, st.Version, ap.ConnectedAt, time.Now()); err != nil {
		t.Fatal(err)
	}
	if m.assigned(ap.ID, s.ID, 1) == 0 {
		t.Fatal("freed before deferred apply interval")
	}
	if err = m.settleWLANs(ap.ID, st.Version, ap.ConnectedAt, st.Ready); err != nil {
		t.Fatal(err)
	}
	if slot, err := m.allocate(ap.ID, "guest", 1, 1); err != nil || slot != 1 {
		t.Fatal("committed slot never became reusable", slot, err)
	}
	f.mu.Lock()
	defer f.mu.Unlock()
	if _, ok := f.active[[2]byte{1, 1}]; ok {
		t.Fatal("AP still has deleted WLAN")
	}
}

func TestBasicRadioReenableRecreatesVAP(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), 5*time.Second)
	defer cancel()
	s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1, 2}}
	cfg := Config{Services: []Service{s}}
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	off, on := false, true
	cfg.Radios = []RadioSetting{{AP: ap.ID, Radio: 2, Enabled: &off}}
	cfg.Version++
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	f.mu.Lock()
	_, exists := f.active[[2]byte{2, 1}]
	f.mu.Unlock()
	if exists {
		t.Fatal("fake AP did not clear VAP on OFF")
	}
	cfg.Radios = []RadioSetting{{AP: ap.ID, Radio: 2, Enabled: &on}}
	cfg.Version++
	m.config = cfg
	m.reconcileAP(ctx, ap, cfg)
	f.mu.Lock()
	defer f.mu.Unlock()
	if f.active[[2]byte{2, 1}] != "Office" {
		t.Fatal("ON restored radio without recreating WLAN")
	}
}

// V6 6dba0c/6dbbe8 select IGMP recipients by capability43 independently
// of the WLAN queue (6dbd74). Missing optional IGMP cannot veto WLANs.
func TestUnsupportedIGMPDoesNotBlockWirelessService(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = nil
	s := Service{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1, 2}}
	o := serviceOptions(s)
	o.Multicast = &MulticastOptions{ConfigureGlobal: true, GlobalSnooping: true, Snooping: true, Query: true, ToUnicast: true, Rate2G: 1, Rate5G: 6, QueryInterval: 60, MaxResponse: 10}
	s.Options = &o
	cfg := Config{Services: []Service{s}}
	m.config = cfg
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), 5*time.Second)
	defer cancel()
	m.reconcileAP(ctx, ap, cfg)
	st := m.status[ap.ID+"/office"]
	if st.State != "acknowledged" || st.Reason == "" {
		t.Fatal("optional IGMP blocked WLAN or was hidden", st)
	}
	f.mu.Lock()
	defer f.mu.Unlock()
	if f.active[[2]byte{1, 1}] != "Office" || f.active[[2]byte{2, 1}] != "Office" {
		t.Fatal("WLAN not committed on both radios", f.active)
	}
	for _, p := range f.packets {
		for _, el := range p.Elements {
			if el.Type == 0x25 && len(el.Value) >= 10 {
				kind := binary.BigEndian.Uint16(el.Value[6:])
				if kind >= 0x70 && kind <= 0x74 || kind == 0xc9 {
					t.Fatalf("unsupported IGMP emitted: %x", kind)
				}
			}
		}
	}
}
