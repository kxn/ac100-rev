package cweng

import (
	"math"
	"sort"
	"sync"
	"time"

	"uacgo/capwap"
)

// RRM/ACS decision engine — the ac_rrm subsystem (uac_rrm_init
// @0x4af92c) plus the ACS delegation of wsta intelligent roam
// (_wsta_intelligent_roam_do_acs @0x486710). Decision algorithms from
// _rrm_task @0x4aef30, run_DCA @0x4b07f8, run_TPC @0x4b1750 and
// wsta_roam_chnl_handle_thread @0x4857a8.
//
// Data flow (AC side):
//
//	collect: ndp para (0x5c) per AP/radio → APs report rrm neighs (0x5d)
//	calc:    DCA (greedy + DFS over the neighbor interference matrix) /
//	         TPC (high/low RSSI thresholds, bounded steps)
//	apply:   uac_rdmngr_chnl_pwr_modify_by_rdid → rdmngr radio DB → AP
//
// ACS delegation: chnl_scan (0x9b) → APs report chnl_scan_report (0x9c)
// → per-channel sumA/sumB aggregates → argmin channel per band.

// RRMState is the rrm_db_state machine (strings.txt: collecting /
// wait for calculate / calculating (channel|power) rrm).
type RRMState int

const (
	RRMIdle        RRMState = 0 // ready
	RRMCollectChnl RRMState = 1
	RRMWaitChnl    RRMState = 2
	RRMCalcChnl    RRMState = 3
	RRMCollectPwr  RRMState = 4
	RRMWaitPwr     RRMState = 5
	RRMCalcPwr     RRMState = 6
	RRMDone        RRMState = 7 // finished, may start again
	RRMACSEnd      RRMState = 8 // ACS delegation finished
)

// Band indices of the per-band record sets.
const (
	RRMBand2G = iota
	RRMBand5G1
	RRMBand5G2
	RRMBandCount
)

// RRMConfig carries the 15 apmng_rrm.settings fields plus the TPC/DCA
// knobs (debug-help names of the binary).
type RRMConfig struct {
	ChnlEnable, PwrEnable, FreqEnable bool
	BW2G, BW5G                        int
	ChnlSets                          [RRMBandCount][]int // chnl_2g/5g1/5g2_set
	PwrThreshold                      int
	PwrMaxPwr, PwrMinPwr              int
	AutoEnable                        bool
	AutoDate                          int // 0..6 weekday, 7 = every day
	AutoTime                          string
	GroupIDs                          []int
	// TPC/DCA knobs
	TpcNeighSize    int  // rrm_pwr_tpc_neigh_size
	PwrMaxNeighSize int  // rrm_pwr_max_neigh_size
	SmoothTPC       bool // rrm_pwr_smooth_tpc_switch
	MaxChangePower  int  // pwr_rrm_max_change_power (level step)
	MaxTPCCount     int  // pwr_rrm_max_count (iteration budget)
	HighThreshold   int  // strongest-neighbor RSSI ceiling
	LowThreshold    int  // strongest-neighbor RSSI floor
	CollectTime     time.Duration
	ACSTimeout      time.Duration
}

// RrmNeighSample is one reported neighbor measurement (0x5d triple).
type RrmNeighSample struct {
	NeighAP int
	Radio   uint8
	Channel int // the neighbor's channel at measurement time
	RSSI    int // transformed metric (RRMRRSITransform applied)
}

// RrmRadioRec is one AP-radio collection record.
type RrmRadioRec struct {
	ApID     int
	Radio    int
	CurChnl  int
	CurPower int // dBm
	Neighs   []RrmNeighSample
	Reported bool
	// decision outputs
	ChnlIdx int // index into the band candidate list
	Power   int // dBm after TPC
}

type rrmBandCollect struct {
	recs      []*RrmRadioRec
	reportedN int
}

// RRMEngine runs the state machine. I/O is injected via ApplyRadio and
// the collect/send callbacks.
type RRMEngine struct {
	mu         sync.Mutex
	state      RRMState
	cfg        RRMConfig
	bands      [RRMBandCount]*rrmBandCollect
	pwrBands   [RRMBandCount]*rrmBandCollect
	pwrIter    int
	rrmType    int // 1 manual / 2 auto
	chnlFail   bool
	pwrFail    bool
	now        func() time.Time
	acsSamples map[int][2]int // ACS aggregation: channel → (sumA, sumB)
	// ApplyRadio delivers one radio's new channel/bw/power-level to the
	// rdmngr radio DB (uac_rdmngr_chnl_pwr_modify_by_rdid); chnl<0 or
	// pwrLevel<0 mean "keep".
	ApplyRadio func(rdID, apID, radio, chnl, bw, pwrLevel int)
}

// NewRRMEngine creates the engine.
func NewRRMEngine(cfg RRMConfig) *RRMEngine {
	e := &RRMEngine{cfg: cfg, now: time.Now}
	for b := 0; b < RRMBandCount; b++ {
		e.bands[b] = &rrmBandCollect{}
		e.pwrBands[b] = &rrmBandCollect{}
	}
	return e
}

// State reports the current state.
func (e *RRMEngine) State() RRMState {
	e.mu.Lock()
	defer e.mu.Unlock()
	return e.state
}

// RRMRRSITransform is the wire→metric conversion of the neighbor report
// (_rrm_pkt_rssi_request @0x4adad4): (rssi_dbm+100)²/100.
func RRMRRSITransform(rssiDBm int) int {
	x := rssiDBm + 100
	return x * x / 100
}

// PwrToLevel maps dBm into the 1..10 power levels
// (rrm_transfer_pwr_to_level @0x4ab198).
func PwrToLevel(pwr, max, min int) int {
	if max <= min {
		return 1
	}
	lvl := int(math.Round(float64(pwr-min)*9/float64(max-min))) + 1
	if lvl < 1 {
		lvl = 1
	}
	if lvl > 10 {
		lvl = 10
	}
	return lvl
}

// LevelToPwr maps a 1..10 level back to dBm.
func LevelToPwr(level, max, min int) int {
	if level < 1 {
		level = 1
	}
	if level > 10 {
		level = 10
	}
	return min + (max-min)*(level-1)/9
}

// ManualStart mirrors _rrm_jcs_manual_rrm_set @0x4ad8e4: returns 0 ok,
// -1 bad state, -2 radio operation busy, -4 nothing enabled.
func (e *RRMEngine) ManualStart(radioBusy bool) int {
	e.mu.Lock()
	defer e.mu.Unlock()
	if e.state != RRMIdle && e.state != RRMDone {
		return -1
	}
	if radioBusy {
		return -2
	}
	if !e.cfg.ChnlEnable && !e.cfg.PwrEnable {
		return -4
	}
	e.rrmType = 1
	if e.cfg.ChnlEnable {
		e.startChnlLocked()
		return 0
	}
	e.startPwrLocked()
	e.pwrIter++
	return 0
}

// AutoFire mirrors _autorrm_tmo_handle @0x4ad674 (the caller owns the
// timer; busy radios reschedule after 10s). Returns 0 started, -1 bad
// state (skip this round), -2 busy.
func (e *RRMEngine) AutoFire(radioBusy bool) int {
	e.mu.Lock()
	defer e.mu.Unlock()
	if e.state != RRMIdle && e.state != RRMDone {
		return -1
	}
	if radioBusy {
		return -2
	}
	e.rrmType = 2
	if e.cfg.ChnlEnable {
		e.startChnlLocked()
		return 0
	}
	if e.cfg.PwrEnable {
		e.startPwrLocked()
		e.pwrIter++
		return 0
	}
	return -1
}

// NextAutoDelay computes the autorrm timer delta (_autorrm_tmo_caculate
// @0x4a8b5c): date==7 → daily at AutoTime, else weekly by weekday.
func NextAutoDelay(now time.Time, date int, clock string) time.Duration {
	h, m, s := 0, 0, 0
	if t, err := time.Parse("15:04:05", clock); err == nil {
		h, m, s = t.Hour(), t.Minute(), t.Second()
	}
	next := time.Date(now.Year(), now.Month(), now.Day(), h, m, s, 0, now.Location())
	if date == 7 {
		if !next.After(now) {
			next = next.Add(24 * time.Hour)
		}
		return next.Sub(now)
	}
	days := (date - int(now.Weekday()) + 7) % 7
	next = next.AddDate(0, 0, days)
	if !next.After(now) {
		next = next.AddDate(0, 0, 7)
	}
	return next.Sub(now)
}

func (e *RRMEngine) startChnlLocked() {
	e.state = RRMCollectChnl
	e.chnlFail = false
	for b := 0; b < RRMBandCount; b++ {
		e.bands[b] = &rrmBandCollect{}
	}
}

func (e *RRMEngine) startPwrLocked() {
	e.state = RRMCollectPwr
	e.pwrFail = false
	for b := 0; b < RRMBandCount; b++ {
		e.pwrBands[b] = &rrmBandCollect{}
	}
}

// AddRadio registers one AP radio into the active collection
// (rrm_collect_active_ap @0x4a8fa0).
func (e *RRMEngine) AddRadio(band int, rec RrmRadioRec) {
	e.mu.Lock()
	defer e.mu.Unlock()
	if e.state == RRMCollectChnl {
		e.bands[band].recs = append(e.bands[band].recs, &rec)
	} else if e.state == RRMCollectPwr {
		e.pwrBands[band].recs = append(e.pwrBands[band].recs, &rec)
	}
}

// ReportNeigh ingests one AP radio's neighbor list (0x5d →
// _rrm_pkt_rssi_request). Returns true when every registered radio has
// reported (early completion).
func (e *RRMEngine) ReportNeigh(band, apID, radio int, samples []RrmNeighSample) bool {
	e.mu.Lock()
	defer e.mu.Unlock()
	var set *rrmBandCollect
	if e.state == RRMCollectChnl {
		set = e.bands[band]
	} else if e.state == RRMCollectPwr {
		set = e.pwrBands[band]
	} else {
		return false
	}
	for _, r := range set.recs {
		if r.ApID == apID && r.Radio == radio {
			r.Neighs = samples
			r.Reported = true
			set.reportedN++
			break
		}
	}
	for _, s := range []*rrmBandCollect{e.bands[band], e.pwrBands[band]} {
		_ = s
	}
	total, done := 0, 0
	for b := 0; b < RRMBandCount; b++ {
		s := e.bands[b]
		if e.state == RRMCollectPwr {
			s = e.pwrBands[b]
		}
		for _, r := range s.recs {
			total++
			if r.Reported {
				done++
			}
		}
	}
	return total > 0 && done == total
}

// CollectTimeout is rrm_timeout @0x4a8f58 (state 1→2, 4→5).
func (e *RRMEngine) CollectTimeout() {
	e.mu.Lock()
	defer e.mu.Unlock()
	switch e.state {
	case RRMCollectChnl:
		e.state = RRMWaitChnl
	case RRMCollectPwr:
		e.state = RRMWaitPwr
	}
}

// WaitForCalc moves collecting→wait when reports complete.
func (e *RRMEngine) WaitForCalc() {
	e.mu.Lock()
	defer e.mu.Unlock()
	switch e.state {
	case RRMCollectChnl:
		e.state = RRMWaitChnl
	case RRMCollectPwr:
		e.state = RRMWaitPwr
	}
}

// CalcChannel runs the DCA over the collected matrices (state 2→3→7 or
// on to power). Returns the per-radio assignments.
func (e *RRMEngine) CalcChannel() map[int][]int {
	e.mu.Lock()
	defer e.mu.Unlock()
	if e.state != RRMWaitChnl {
		return nil
	}
	e.state = RRMCalcChnl
	out := map[int][]int{}
	for b := 0; b < 2; b++ { // channel calc loops 2.4G and 5G only
		set := e.bands[b]
		if len(set.recs) == 0 {
			continue
		}
		if set.reportedN < (len(set.recs)+1)/2 {
			e.chnlFail = true // majority report required
			continue
		}
		e.runDCA(set, e.cfg.ChnlSets[b])
		for _, r := range set.recs {
			out[r.ApID] = append(out[r.ApID], e.cfg.ChnlSets[b][r.ChnlIdx])
		}
	}
	// 5G2 co-channel interference is folded into the 5G matrix first
	if len(e.bands[RRMBand5G2].recs) > 0 && e.bands[RRMBand5G2].reportedN > 0 {
		e.runDCA(e.bands[RRMBand5G2], e.cfg.ChnlSets[RRMBand5G2])
	}
	if e.cfg.PwrEnable {
		e.startPwrLocked()
		e.pwrIter++
	} else {
		e.finishLocked()
	}
	return out
}

// CalcPower runs one TPC iteration (state 5→6). done=true when the
// engine finished (failure / no change / iteration budget).
func (e *RRMEngine) CalcPower() (levels map[int]int, done bool) {
	e.mu.Lock()
	defer e.mu.Unlock()
	if e.state != RRMWaitPwr {
		return nil, true
	}
	e.state = RRMCalcPwr
	levels = map[int]int{}
	changed := 0
	for b := 0; b < RRMBandCount; b++ {
		set := e.pwrBands[b]
		if len(set.recs) == 0 {
			continue
		}
		if set.reportedN < (len(set.recs)+1)/2 {
			e.pwrFail = true
			continue
		}
		changed += e.runTPC(set)
		for _, r := range set.recs {
			levels[r.ApID*100+r.Radio] = r.Power
		}
	}
	switch {
	case e.pwrFail || changed == 0 || e.pwrIter >= e.cfg.MaxTPCCount:
		e.pwrIter = 0
		e.finishLocked()
		done = true
	default:
		// iterate another collection round
		for b := 0; b < RRMBandCount; b++ {
			e.pwrBands[b] = &rrmBandCollect{}
		}
		e.state = RRMCollectPwr
	}
	return levels, done
}

func (e *RRMEngine) finishLocked() {
	e.state = RRMDone
	e.chnlFail, e.pwrFail = false, false
	e.rrmType = 0
}

// runDCA: greedy + backtracking channel assignment
// (run_DCA @0x4b07f8: pick the highest-total-interference AP, DFS its
// candidate channels). Interference of an AP on a candidate channel is
// the summed transformed RSSI of its reported neighbors currently on
// that channel.
func (e *RRMEngine) runDCA(set *rrmBandCollect, cands []int) {
	if len(cands) == 0 {
		return
	}
	cur := map[int]int{} // apID → assigned candidate index
	var order []*RrmRadioRec
	for _, r := range set.recs {
		order = append(order, r)
	}
	// interference ranking (record +10 = total itf)
	itf := func(r *RrmRadioRec) int {
		sum := 0
		for _, n := range r.Neighs {
			sum += n.RSSI
		}
		return sum
	}
	sort.SliceStable(order, func(i, j int) bool { return itf(order[i]) > itf(order[j]) })

	var assign func(k int) bool
	assign = func(k int) bool {
		if k == len(order) {
			return true
		}
		r := order[k]
		costOn := func(ci int) int {
			cost := 0
			for _, n := range r.Neighs {
				// a neighbor interferes on this candidate when it is
				// already assigned there or (unassigned) reported from
				// that channel
				if idx, ok := cur[n.NeighAP]; ok {
					if idx == ci {
						cost += n.RSSI
					}
				} else if n.Channel == cands[ci] {
					cost += n.RSSI
				}
			}
			return cost
		}
		best, bestCost := -1, math.MaxInt
		for ci := range cands {
			if cost := costOn(ci); cost < bestCost {
				best, bestCost = ci, cost
			}
		}
		for _, ci := range bestFirst(len(cands), best) {
			_ = costOn(ci)
			cur[r.ApID] = ci
			r.ChnlIdx = ci
			if assign(k + 1) {
				return true
			}
			delete(cur, r.ApID)
		}
		return false
	}
	assign(0)
}

func bestFirst(n, best int) []int {
	out := []int{best}
	for i := 0; i < n; i++ {
		if i != best {
			out = append(out, i)
		}
	}
	return out
}

// runTPC: per-radio power adjustment (run_TPC @0x4b1750). Returns how
// many radios changed power.
func (e *RRMEngine) runTPC(set *rrmBandCollect) int {
	changed := 0
	for _, r := range set.recs {
		strongest := math.MinInt
		for _, n := range r.Neighs {
			if n.RSSI > strongest {
				strongest = n.RSSI
			}
		}
		target := r.CurPower
		switch {
		case len(r.Neighs) == 0:
			// no neighbors: step up toward the max-power midpoint
			mid := (e.cfg.PwrMaxPwr + e.cfg.PwrMinPwr) / 2
			if r.CurPower < mid {
				target = minInt(r.CurPower+e.cfg.MaxChangePower, mid)
			}
		case len(r.Neighs) < e.cfg.TpcNeighSize && strongest < e.cfg.LowThreshold:
			target = minInt(r.CurPower+e.cfg.MaxChangePower, e.cfg.PwrMaxPwr)
		case strongest > e.cfg.HighThreshold:
			target = maxInt(r.CurPower-e.cfg.MaxChangePower, e.cfg.PwrMinPwr)
		}
		if target != r.CurPower {
			r.CurPower = target
			r.Power = target
			changed++
		} else {
			r.Power = r.CurPower
		}
	}
	return changed
}

// ACSChannelSelect mirrors wsta_roam_chnl_handle_thread @0x4857a8:
// aggregate per-channel (sumA, sumB) samples and pick the least loaded
// channel per band (sumA order; loadMode uses sumB; ties broken by the
// other metric). Returns (ch2g, best5g, second5g).
func ACSChannelSelect(loadMode bool, samples map[int][2]int) (ch2G, best5G, second5G int) {
	less := func(a, b int) bool {
		sa, sb := samples[a], samples[b]
		if loadMode {
			if sa[1] != sb[1] {
				return sa[1] < sb[1]
			}
			return sa[0] < sb[0]
		}
		if sa[0] != sb[0] {
			return sa[0] < sb[0]
		}
		return sa[1] < sb[1]
	}
	pick := func(lo, hi int) int {
		best := -1
		for ch := lo; ch <= hi; ch++ {
			if _, ok := samples[ch]; !ok {
				continue
			}
			if best < 0 || less(ch, best) {
				best = ch
			}
		}
		return best
	}
	ch2G = pick(1, 14)
	if ch2G < 0 {
		ch2G = 1 // defaults: 1 / 36 / 149
	}
	best5G = pick(15, 0xc0)
	if best5G < 0 {
		best5G = 36
	}
	// second 5G channel: best of the *other* 5G band
	lo, hi := 15, 48
	if best5G <= 48 {
		lo, hi = 49, 0xc0
	}
	second5G = pick(lo, hi)
	if second5G < 0 {
		second5G = 149
	}
	return ch2G, best5G, second5G
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// ReportScan ingests one AP's 0x9c channel scan samples
// (_wsta_roam_pkt_chnl_scan_report: per-record sums accumulate per
// channel). Implements the RrmCollector half of the ACS path.
func (e *RRMEngine) ReportScan(apMAC [6]byte, records []capwap.ChnlScanRecord) {
	e.mu.Lock()
	defer e.mu.Unlock()
	if e.acsSamples == nil {
		e.acsSamples = map[int][2]int{}
	}
	for _, r := range records {
		cur := e.acsSamples[int(r.Channel)]
		e.acsSamples[int(r.Channel)] = [2]int{
			cur[0] + int(r.SumA), cur[1] + int(r.SumB),
		}
	}
}

// ACSCalc runs the ACS channel selection over the aggregated samples
// (wsta_roam_chnl_handle_thread) and returns (ch2g, best5g, second5g).
func (e *RRMEngine) ACSCalc(loadMode bool) (int, int, int) {
	e.mu.Lock()
	samples := e.acsSamples
	e.mu.Unlock()
	return ACSChannelSelect(loadMode, samples)
}
