package cweng

import (
	"sync"
	"time"

	"uacgo/capwap"
)

// Balance admission engine — the "balance" subsystem of the AC
// (balance_init @0x4590a8). All semantics re-derived from the AC binary:
//
//	balance_allow_sta_conect_wtp @0x45a040 (gate) →
//	balance_sta_connect_wtp_by_session @0x457b40 (logging wrapper) →
//	balance_db_dis_sta_check @0x45d824 (the decision)
//
// Discovery bookkeeping: balance_sta_want_connect_wtp @0x459d30 on the
// WTP event probe element 0x0b; LRU connect-wtp list (cap 10) with 900s
// idle expiry swept by balance_thread_callback @0x45aaf8 (300s cadence);
// WTP removal cleans its nodes (balance_cnt_wtp_clear @0x45af40).
//
// Config keys (UCI apmng_balance.settings): enable/mode/usr_threshold/
// dif_threshold/max_fail_num/rssi_threshold. rssi_threshold is used for
// the "vsp with spec rssi" push (element 0x3e), NOT in the admission
// decision.

// BalanceConfig is the 0x18-byte config block (balance_db_config_get).
type BalanceConfig struct {
	Enable        bool   // state (com[2])
	Mode          uint8  // only mode 1 (session) is supported (com[3])
	UsrThreshold  uint32 // sta-count gate (com[4])
	DifThreshold  uint32 // load gap that justifies rejection (com[5])
	MaxFailNum    int    // per-60s-window rejection budget (com[6])
	RssiThreshold int8   // spec rssi push only (com[7])
}

const (
	balanceFailWindow  = 59 * time.Second // fail_num clears when age > 59s
	balanceCntWtpTTL   = 900 * time.Second
	balanceCntWtpMax   = 10 // LRU cap of per-STA connect-wtp records
	balanceSweepPeriod = 300 * time.Second
)

type balanceWtp struct {
	ID     int
	State  uint8
	MAC    [6]byte
	StaCnt uint32
}

type cntWtpNode struct {
	WtpID    int
	LastSeen time.Time
}

type disStaEntry struct {
	FailNum    int
	LastReject time.Time
	CntWtp     []cntWtpNode // oldest first (tail-insert LRU)
}

// BalanceEngine is the in-memory balance database (balance_db_*).
type BalanceEngine struct {
	mu   sync.Mutex
	cfg  BalanceConfig
	wtps map[[6]byte]*balanceWtp
	byID map[int]*balanceWtp
	dis  map[[6]byte]*disStaEntry
	now  func() time.Time
}

// NewBalanceEngine creates the engine with the given config.
func NewBalanceEngine(cfg BalanceConfig) *BalanceEngine {
	return &BalanceEngine{
		cfg:  cfg,
		wtps: map[[6]byte]*balanceWtp{},
		byID: map[int]*balanceWtp{},
		dis:  map[[6]byte]*disStaEntry{},
		now:  time.Now,
	}
}

// SetNow injects a clock (tests).
func (b *BalanceEngine) SetNow(f func() time.Time) { b.now = f }

// SetConfig replaces the config block (balance_jcs_callback_balance_set).
func (b *BalanceEngine) SetConfig(cfg BalanceConfig) {
	b.mu.Lock()
	defer b.mu.Unlock()
	b.cfg = cfg
}

// Config returns a copy of the current config.
func (b *BalanceEngine) Config() BalanceConfig {
	b.mu.Lock()
	defer b.mu.Unlock()
	return b.cfg
}

// UpsertWTP registers/refreshes one WTP (balance_wtp_entry_update:
// state=1, sta count preserved).
func (b *BalanceEngine) UpsertWTP(id int, mac [6]byte) {
	b.mu.Lock()
	defer b.mu.Unlock()
	if w, ok := b.wtps[mac]; ok {
		w.ID, w.State = id, 1
		b.byID[id] = w
		return
	}
	w := &balanceWtp{ID: id, State: 1, MAC: mac}
	b.wtps[mac] = w
	b.byID[id] = w
}

// RemoveWTP deletes one WTP and its connect-wtp nodes everywhere
// (balance_db_wtp_delete → balance_cnt_wtp_clear).
func (b *BalanceEngine) RemoveWTP(id int) {
	b.mu.Lock()
	defer b.mu.Unlock()
	w, ok := b.byID[id]
	if ok {
		delete(b.wtps, w.MAC)
		delete(b.byID, id)
	}
	for mac, e := range b.dis {
		kept := e.CntWtp[:0]
		for _, n := range e.CntWtp {
			if n.WtpID != id {
				kept = append(kept, n)
			}
		}
		e.CntWtp = kept
		if len(e.CntWtp) == 0 {
			delete(b.dis, mac) // balance_dis_sta_entry_delete
		}
	}
}

// SetStaCount records the associated-STA count of one WTP
// (balance_wsta_callback_balance_sta_add/del bookkeeping).
func (b *BalanceEngine) SetStaCount(wtpMAC [6]byte, n uint32) {
	b.mu.Lock()
	defer b.mu.Unlock()
	if w, ok := b.wtps[wtpMAC]; ok {
		w.StaCnt = n
	}
}

// NoteProbe records that a STA probed/wants a WTP (balance_sta_want_
// connect_wtp on WTP-event element 0x0b). Balance off → not recorded.
func (b *BalanceEngine) NoteProbe(staMAC, wtpMAC [6]byte) {
	b.mu.Lock()
	defer b.mu.Unlock()
	if !b.cfg.Enable {
		return // "balance is off, then don't add discovery-station"
	}
	w, ok := b.wtps[wtpMAC]
	if !ok {
		return
	}
	e, ok := b.dis[staMAC]
	if !ok {
		e = &disStaEntry{}
		b.dis[staMAC] = e
	}
	now := b.now()
	// refresh existing node or append (LRU cap 10, oldest evicted)
	for i, n := range e.CntWtp {
		if n.WtpID == w.ID {
			e.CntWtp = append(append(e.CntWtp[:i], e.CntWtp[i+1:]...),
				cntWtpNode{WtpID: w.ID, LastSeen: now})
			return
		}
	}
	if len(e.CntWtp) >= balanceCntWtpMax {
		e.CntWtp = e.CntWtp[1:] // drop the oldest (head)
	}
	e.CntWtp = append(e.CntWtp, cntWtpNode{WtpID: w.ID, LastSeen: now})
}

// AllowStaConnect mirrors balance_allow_sta_conect_wtp →
// balance_sta_connect_wtp_by_session → balance_db_dis_sta_check.
// true = accept, false = reject.
func (b *BalanceEngine) AllowStaConnect(staMAC, wtpMAC [6]byte) bool {
	b.mu.Lock()
	defer b.mu.Unlock()
	return b.disStaCheckLocked(staMAC, wtpMAC)
}

// disStaCheckLocked is balance_db_dis_sta_check (returns accept semantics).
func (b *BalanceEngine) disStaCheckLocked(staMAC, wtpMAC [6]byte) bool {
	if !b.cfg.Enable {
		return true // "balance is off, so wtp accepts station"
	}
	e, ok := b.dis[staMAC]
	if !ok {
		return true // "get discovery-station(..) failed, so wtp accepts it"
	}
	now := b.now()
	// fail-count window: clear after >59s since the last rejection
	if now.Before(e.LastReject) || now.Sub(e.LastReject) > balanceFailWindow {
		e.FailNum = 0
	}
	// rejection budget: fail_num >= max_fail_num → always accept
	if e.FailNum >= b.cfg.MaxFailNum {
		return true
	}
	w, ok := b.wtps[wtpMAC]
	if !ok {
		return false // "get wtp failed, so wtp reject station" (no counter update)
	}
	if w.StaCnt < b.cfg.UsrThreshold {
		return true // "wtp's stations cann't reach threshold"
	}
	// reached threshold: reject only when a materially lighter known WTP exists
	for _, n := range e.CntWtp {
		other, ok := b.byID[n.WtpID]
		if !ok || other.State == 0 || other.ID == w.ID {
			continue
		}
		if other.StaCnt < w.StaCnt && w.StaCnt-other.StaCnt >= b.cfg.DifThreshold {
			e.LastReject = now
			e.FailNum++ // the only rejection counter
			return false
		}
	}
	return true // "reach threshold, but in differ-threshold with other wtps"
}

// AllowMloStaConnect mirrors balance_allow_mlo_sta_conect_wtp: ANY-reject
// over the link MACs and the primary MAC (each checked independently).
func (b *BalanceEngine) AllowMloStaConnect(primary [6]byte, links [][6]byte, wtpMAC [6]byte) bool {
	ok := true
	checked := map[[6]byte]bool{}
	for _, m := range links {
		if m == primary {
			continue
		}
		checked[m] = true
		if !b.AllowStaConnect(m, wtpMAC) {
			ok = false // any-reject; side effects still occur per link
		}
	}
	if !checked[primary] {
		if !b.AllowStaConnect(primary, wtpMAC) {
			ok = false
		}
	}
	return ok
}

// Sweep ages out the connect-wtp records (balance_cnt_wtp_delete_timer_
// callback, 900s idle) and drops empty discovery entries. The vendor
// thread runs every 300s; call periodically.
func (b *BalanceEngine) Sweep() int {
	b.mu.Lock()
	defer b.mu.Unlock()
	now := b.now()
	removed := 0
	for mac, e := range b.dis {
		for len(e.CntWtp) > 0 {
			head := e.CntWtp[0]
			if now.Before(head.LastSeen) || now.Sub(head.LastSeen) >= balanceCntWtpTTL {
				e.CntWtp = e.CntWtp[1:]
				removed++
				continue
			}
			break // head is the oldest
		}
		if len(e.CntWtp) == 0 {
			delete(b.dis, mac)
		}
	}
	return removed
}

// Checker adapts the engine to the steering AdmissionChecker using an
// ap-id → WTP MAC resolver.
func (b *BalanceEngine) Checker(wtpMACOf func(apID uint16) [6]byte) AdmissionChecker {
	return balanceChecker{b: b, wtpMACOf: wtpMACOf}
}

type balanceChecker struct {
	b        *BalanceEngine
	wtpMACOf func(uint16) [6]byte
}

func (c balanceChecker) PseudoAssociateOK(apID uint16, _, _ uint8, sta [6]byte) bool {
	return c.b.AllowStaConnect(sta, c.wtpMACOf(apID))
}

// BalanceSink is the probe-event side of the balance wiring (0x0b
// station discovery): NoteProbe is called from the msg 9 path.
type BalanceSink interface {
	NoteProbe(staMAC, wtpMAC [6]byte)
}

// RegisterBalanceHandlers wires the WTP-event probe element 0x0b
// (balance_capwap_callback_wtp_event_request_listen @0x459f60, msg 9
// priority 1 — first in the vendor dispatch order).
func (e *Engine) RegisterBalanceHandlers(b BalanceSink) {
	e.Register(capwap.MsgWTPEventRequest, 1, "balance_wtp_event",
		func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
			for _, el := range req.Elements {
				if el.Type != 0x0025 || len(el.Value) < 6 {
					continue
				}
				for _, sub := range unpackVendorSubs(el.Value[6:]) {
					if sub.Type != 0x0b || len(sub.Value) < 8 {
						continue
					}
					// 0x0b station discovery: value+2 carries the STA MAC
					// (cw_msg_ele_priv_val_get_from_pkt(pkt, 0xb)+2)
					var sta, wtp [6]byte
					copy(sta[:], sub.Value[2:8])
					if ctx != nil && ctx.Session != nil {
						wtp = ctx.Session.APMAC
					}
					b.NoteProbe(sta, wtp)
				}
			}
			return true
		})
}
