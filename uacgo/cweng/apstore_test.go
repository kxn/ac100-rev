package cweng

import (
	"database/sql"
	"fmt"
	"net"
	"path/filepath"
	"testing"

	_ "modernc.org/sqlite"

	"time"

	"uacgo/capwap"
	"uacgo/store"
)

var (
	schemaApEntryCfg = store.SchemaApentrycfgTable
	schemaApEntryRun = store.SchemaApentryrunTable
)

// Join → RUN stores the AP in apmngr.db (ApEntryCfg_table / ApEntryRun_table).
func TestJoinStoresAPEntry(t *testing.T) {
	dir := t.TempDir()
	dbFile := filepath.Join(dir, "apmngr.db")
	cfgDB, err := sql.Open("sqlite", dbFile)
	if err != nil {
		t.Fatal(err)
	}
	defer cfgDB.Close()
	for _, sc := range []string{schemaApEntryCfg, schemaApEntryRun} {
		if _, err := cfgDB.Exec(sc); err != nil {
			t.Fatal(err)
		}
	}
	st := &SQLiteAPStore{Cfg: cfgDB, Run: cfgDB}

	e, _ := NewEngine(0)
	e.UseStore(st)
	t.Cleanup(func() { e.Close() })
	go func() { _ = e.Run() }()

	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	c.Write(withSeq(t, "cw_join_req_0074f150.bin", 2))
	buf := make([]byte, 65536)
	c.SetReadDeadline(time.Now().Add(2 * time.Second))
	if _, err := c.Read(buf); err != nil {
		t.Fatalf("no join response: %v", err)
	}

	var name string
	err = cfgDB.QueryRow(`SELECT entry_name FROM ApEntryCfg_table LIMIT 1`).Scan(&name)
	if err != nil || name != "My WTP 1" {
		t.Fatalf("apmngr.db entry_name = %q err=%v", name, err)
	}
	var status int
	err = cfgDB.QueryRow(`SELECT status FROM ApEntryRun_table LIMIT 1`).Scan(&status)
	if err != nil {
		t.Fatalf("run table: %v", err)
	}
}

func TestInventoryInitializationFailureDoesNotAcknowledgeJoin(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.RegisterAttachHandlers(fixtureIdentity{})
	sends := 0
	e.sendToForTest = func(_ *net.UDPAddr, _ []byte) error { sends++; return nil }
	e.UseStore(&joinTestStore{fail: true})
	e.handlePlainDatagram(withSeq(t, "cw_join_req_0074f150.bin", 2), &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 15000})
	if sends != 0 || len(e.APs()) != 0 {
		t.Fatal("failed registration was acknowledged", sends, e.APs())
	}
}

type joinTestStore struct {
	calls int
	fail  bool
	seen  []string
}

func (st *joinTestStore) UpsertAP(ap *APEntry, initialize func(bool) error) error {
	st.calls++
	st.seen = append(st.seen, ap.MAC)
	if st.fail {
		return fmt.Errorf("synthetic persistence failure")
	}
	return initialize(true)
}

func TestStoredIdentityPrecedesZeroModelNameFallback(t *testing.T) {
	db, err := sql.Open("sqlite", filepath.Join(t.TempDir(), "ap.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	for _, schema := range []string{schemaApEntryCfg, schemaApEntryRun} {
		if _, err = db.Exec(schema); err != nil {
			t.Fatal(err)
		}
	}
	st := &SQLiteAPStore{Cfg: db, Run: db}
	ap := &APEntry{MAC: "02:00:00:00:00:01", ModelID: 123, HardwareVersion: "1.0", Name: "Original"}
	var first []bool
	init := func(created bool) error { first = append(first, created); return nil }
	if err = st.UpsertAP(ap, init); err != nil {
		t.Fatal(err)
	}
	ap.ModelID = 0
	if err = st.UpsertAP(ap, init); err != nil {
		t.Fatal(err)
	}
	if ap.ModelID != 123 || len(first) != 2 || !first[0] || first[1] {
		t.Fatal(ap, first)
	}
}

func TestJoinPrechecksRunBeforeRegistrationAndDuplicateDoesNotReinitialize(t *testing.T) {
	for _, reject := range []bool{false, true} {
		e, err := NewEngine(0)
		if err != nil {
			t.Fatal(err)
		}
		inventory := &joinTestStore{}
		e.UseStore(inventory)
		e.RegisterAttachHandlers(fixtureIdentity{})
		e.Register(3, 100, "upgrade-precheck", func(_ *Ctx, _, _ *capwap.ParsedPacket) bool { return !reject })
		sends := 0
		e.sendToForTest = func(_ *net.UDPAddr, _ []byte) error { sends++; return nil }
		addr := &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 15000}
		req := withSeq(t, "cw_join_req_0074f150.bin", 2)
		e.handlePlainDatagram(req, addr)
		if reject {
			if inventory.calls != 0 || sends != 0 {
				t.Fatal("registration preceded precheck", inventory.calls, sends)
			}
		} else {
			e.handlePlainDatagram(req, addr)
			if inventory.calls != 1 || sends != 2 {
				t.Fatal("duplicate Join initialized twice", inventory.calls, sends)
			}
		}
		e.Close()
	}
}

// The allowed sets are pinned to both versions' recv_pkt_check functions,
// including their final conditional return (which previously hid Join/Config).
func TestAttachGateSetsMatchBothFirmwareVersions(t *testing.T) {
	for _, tc := range []struct {
		state   uint32
		allowed []uint32
	}{
		{StateJoinWait, []uint32{0, 3}}, {StateJoinFinish, []uint32{3, 5, 15}},
		{StateConfigure, []uint32{5, 11}}, {StateImageData, []uint32{13, 15, 16}},
		{StateDateCheck, []uint32{9, 11, 13}},
	} {
		s := newSession(&net.UDPAddr{}, &AcDataCounters{})
		s.State = tc.state
		for msg := uint32(0); msg < 32; msg++ {
			want := false
			for _, allowed := range tc.allowed {
				want = want || msg == allowed
			}
			if got := s.gate(msg) == nil; got != want {
				t.Fatalf("state %s msg %d accepted=%t want=%t", StateNames[tc.state], msg, got, want)
			}
		}
	}
}

func TestAttachFailureAndRecoveryStatesFollowFirmware(t *testing.T) {
	for _, msg := range []uint32{9, 13} {
		s := newSession(&net.UDPAddr{}, &AcDataCounters{})
		s.State = StateDateCheck
		entered := 0
		s.onEnterRun = func(*Session) error { entered++; return nil }
		if err := s.recvResult(msg, true); err != nil || s.State != StateRun || entered != 1 || s.acData.RunCount.Load() != 1 {
			t.Fatal(msg, s.State, entered, err)
		}
		s.teardown()
	}
	for _, state := range []uint32{StateConfigure, StateImageData} {
		s := newSession(&net.UDPAddr{}, &AcDataCounters{})
		s.State = state
		deleted := 0
		s.onDelete = func(*Session) { deleted++ }
		s.recvResult(0, false)
		select {
		case <-s.closed:
		default:
			t.Fatal("deleted session epoch remained open")
		}
		if !s.dead || deleted != 1 {
			t.Fatal(state, s.dead, deleted)
		}
	}
	s := newSession(&net.UDPAddr{}, &AcDataCounters{})
	s.State = StateDateCheck
	if err := s.recvResult(11, true); err != nil || s.State != StateDateCheck {
		t.Fatal("CSE retry changed recovery state", err)
	}
	s.processEvent(&Event{ID: EventTimeout, Timer: TimerDataCheck})
	if !s.dead || s.acData.DataCheckTimeout.Load() != 1 {
		t.Fatal("data-check timeout did not clean up")
	}
	for _, timer := range []uint32{TimerEchoInterval, TimerRetransmit} {
		s := newSession(&net.UDPAddr{}, &AcDataCounters{})
		s.State = StateImageData
		if err := s.processEvent(&Event{ID: EventTimeout, Timer: timer}); err != nil || !s.dead {
			t.Fatal(timer, err)
		}
	}
	s = newSession(&net.UDPAddr{}, &AcDataCounters{})
	s.State = StateImageData
	if err := s.processEvent(&Event{ID: EventImageFinished}); err != nil || s.State != StateReset {
		t.Fatal("image finish did not transition RESET", err)
	}
}
