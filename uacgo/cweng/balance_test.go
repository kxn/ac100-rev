package cweng

import (
	"testing"
	"time"
)

type fakeClock struct{ t time.Time }

func (c *fakeClock) now() time.Time      { return c.t }
func (c *fakeClock) add(d time.Duration) { c.t = c.t.Add(d) }

func setupBalance(cfg BalanceConfig) (*BalanceEngine, *fakeClock) {
	clk := &fakeClock{t: time.Unix(1_700_000_000, 0)}
	b := NewBalanceEngine(cfg)
	b.SetNow(clk.now)
	b.UpsertWTP(1, [6]byte{0, 0, 0, 0, 0, 1})
	b.UpsertWTP(2, [6]byte{0, 0, 0, 0, 0, 2})
	b.UpsertWTP(3, [6]byte{0, 0, 0, 0, 0, 3})
	return b, clk
}

func TestBalanceAdmissionTree(t *testing.T) {
	sta := [6]byte{9, 9, 9, 9, 9, 9}
	wtp1, wtp2, wtp3 := [6]byte{0, 0, 0, 0, 0, 1}, [6]byte{0, 0, 0, 0, 0, 2}, [6]byte{0, 0, 0, 0, 0, 3}

	// balance off → accept without recording
	b, _ := setupBalance(BalanceConfig{Enable: false})
	b.NoteProbe(sta, wtp1)
	if len(b.dis) != 0 {
		t.Fatal("probe must not record while off")
	}
	if !b.AllowStaConnect(sta, wtp1) {
		t.Fatal("off must accept")
	}

	// enabled, no discovery record → accept
	b, _ = setupBalance(BalanceConfig{Enable: true, Mode: 1, UsrThreshold: 5, DifThreshold: 3, MaxFailNum: 2})
	if !b.AllowStaConnect(sta, wtp1) {
		t.Fatal("no record must accept")
	}

	// reached threshold + materially lighter known WTP → reject, counter++
	b.SetStaCount(wtp1, 6) // target at/over threshold
	b.SetStaCount(wtp2, 2) // lighter by 4 >= dif 3
	b.NoteProbe(sta, wtp2) // STA knows wtp2
	if b.AllowStaConnect(sta, wtp1) {
		t.Fatal("differ-threshold hit must reject")
	}
	if b.dis[sta].FailNum != 1 {
		t.Fatalf("fail_num = %d, want 1", b.dis[sta].FailNum)
	}

	// max_fail_num budget: second rejection allowed (2), third not
	if b.AllowStaConnect(sta, wtp1) {
		t.Fatal("second reject expected")
	}
	if !b.AllowStaConnect(sta, wtp1) {
		t.Fatal("budget exhausted must accept")
	}

	// fail window: after >59s the counter clears → can reject again
	b, clk := setupBalance(BalanceConfig{Enable: true, Mode: 1, UsrThreshold: 5, DifThreshold: 3, MaxFailNum: 2})
	b.SetStaCount(wtp1, 6)
	b.SetStaCount(wtp2, 2)
	b.NoteProbe(sta, wtp2)
	b.AllowStaConnect(sta, wtp1) // reject #1
	clk.add(60 * time.Second)
	if b.AllowStaConnect(sta, wtp1) {
		t.Fatal("window cleared must reject again")
	}

	// unknown target WTP → reject without counter update
	b, _ = setupBalance(BalanceConfig{Enable: true, Mode: 1, UsrThreshold: 5, DifThreshold: 3, MaxFailNum: 2})
	b.NoteProbe(sta, wtp1)
	if b.AllowStaConnect(sta, [6]byte{0xff}) {
		t.Fatal("unknown wtp must reject")
	}
	if b.dis[sta].FailNum != 0 {
		t.Fatal("unknown-wtp reject must not count")
	}

	// below threshold → accept despite lighter neighbors
	b, _ = setupBalance(BalanceConfig{Enable: true, Mode: 1, UsrThreshold: 5, DifThreshold: 3, MaxFailNum: 2})
	b.SetStaCount(wtp1, 4)
	b.SetStaCount(wtp2, 0)
	b.NoteProbe(sta, wtp2)
	if !b.AllowStaConnect(sta, wtp1) {
		t.Fatal("below threshold must accept")
	}

	// lighter neighbor exists but gap < dif_threshold → accept
	b, _ = setupBalance(BalanceConfig{Enable: true, Mode: 1, UsrThreshold: 5, DifThreshold: 3, MaxFailNum: 2})
	b.SetStaCount(wtp1, 6)
	b.SetStaCount(wtp2, 4) // gap 2 < 3
	b.NoteProbe(sta, wtp2)
	if !b.AllowStaConnect(sta, wtp1) {
		t.Fatal("gap below dif must accept")
	}

	// target itself / offline WTP are skipped as candidates
	b, _ = setupBalance(BalanceConfig{Enable: true, Mode: 1, UsrThreshold: 5, DifThreshold: 3, MaxFailNum: 2})
	b.SetStaCount(wtp1, 6)
	b.SetStaCount(wtp3, 0)
	b.NoteProbe(sta, wtp1) // only knows the target itself
	b.RemoveWTP(3)         // wtp3 offline → not a candidate
	if !b.AllowStaConnect(sta, wtp1) {
		t.Fatal("no lighter candidate must accept")
	}
}

func TestBalanceProbeLRUAndSweep(t *testing.T) {
	sta := [6]byte{9, 9, 9, 9, 9, 9}
	b, clk := setupBalance(BalanceConfig{Enable: true, Mode: 1})
	for id := 1; id <= 12; id++ {
		mac := [6]byte{0, 0, 0, 0, 0, byte(id)}
		b.UpsertWTP(id, mac)
		b.NoteProbe(sta, mac)
	}
	e := b.dis[sta]
	if len(e.CntWtp) != balanceCntWtpMax {
		t.Fatalf("lru cap = %d, want %d", len(e.CntWtp), balanceCntWtpMax)
	}
	if e.CntWtp[0].WtpID != 3 { // 12 records, cap 10 → oldest two evicted
		t.Fatalf("oldest kept = %+v", e.CntWtp)
	}
	// refresh moves the node to the tail
	b.NoteProbe(sta, [6]byte{0, 0, 0, 0, 0, 3})
	if e.CntWtp[len(e.CntWtp)-1].WtpID != 3 {
		t.Fatalf("refresh must tail-insert: %+v", e.CntWtp)
	}
	// 900s idle expiry, empty entry removed
	clk.add(901 * time.Second)
	if n := b.Sweep(); n != balanceCntWtpMax {
		t.Fatalf("swept %d, want %d", n, balanceCntWtpMax)
	}
	if len(b.dis) != 0 {
		t.Fatal("empty discovery entry must be deleted")
	}
}

func TestBalanceMloAnyReject(t *testing.T) {
	sta := [6]byte{9, 9, 9, 9, 9, 9}
	wtp1, wtp2 := [6]byte{0, 0, 0, 0, 0, 1}, [6]byte{0, 0, 0, 0, 0, 2}
	b, _ := setupBalance(BalanceConfig{Enable: true, Mode: 1, UsrThreshold: 5, DifThreshold: 3, MaxFailNum: 5})
	b.SetStaCount(wtp1, 10)
	b.SetStaCount(wtp2, 0)
	linkA := [6]byte{8, 8, 8, 8, 8, 8}
	b.NoteProbe(linkA, wtp2)
	// link A gets rejected → whole MLO check rejected
	if b.AllowMloStaConnect(sta, [][6]byte{linkA}, wtp1) {
		t.Fatal("any-reject semantics: link reject must fail the MLO check")
	}
	// primary only, no record → accept
	if !b.AllowMloStaConnect(sta, nil, wtp1) {
		t.Fatal("primary with no record must accept")
	}
}

// BalanceAdmissionAdapter wires the engine into the steer AdmissionChecker.
func TestBalanceChecker(t *testing.T) {
	sta := [6]byte{9, 9, 9, 9, 9, 9}
	wtp1, wtp2 := [6]byte{0, 0, 0, 0, 0, 1}, [6]byte{0, 0, 0, 0, 0, 2}
	b, _ := setupBalance(BalanceConfig{Enable: true, Mode: 1, UsrThreshold: 5, DifThreshold: 3, MaxFailNum: 5})
	b.SetStaCount(wtp1, 10)
	b.SetStaCount(wtp2, 0)
	b.NoteProbe(sta, wtp2)
	ck := b.Checker(func(apID uint16) [6]byte {
		return [6]byte{0, 0, 0, 0, 0, byte(apID)}
	})
	if ck.PseudoAssociateOK(1, 1, 1, sta) {
		t.Fatal("checker must reject the loaded AP")
	}
	if !ck.PseudoAssociateOK(2, 1, 1, sta) {
		t.Fatal("checker must accept the light AP")
	}
}
