package cweng

import (
	"sort"

	"uacgo/capwap"
)

// AC-side steering decision engine — the centralized roaming strategy
// ("roaming strategy: centralized"). Ported from the uac binary (all
// data and logic provenance is the AC side):
//
//	_wsta_roam_pkt_roaming_trigger_request @0x48847c (0x58 in)
//	  └─ _bstm_ngr_generate          RCPI method probe + rcpi→rssi + neighbor build
//	_roaming_nbr_select @0x4871bc    hard filter + sort + admission + truncation
//	_roaming_nbr_packet_create @0x487610  0x59 out (ap union + per-sta targets)
//	wss_steer_candidate_rate_estimate @0x48b644 / get_estimate_by_stat @0x48b238
//
// The AP firmware is used only to cross-check the wire interaction
// (field-by-field 0x57/0x58/0x59 correspondence —
// notes/apfw-xap5407gc-crosscheck.md §4), never as a data or logic source.

// RCPI method constants — the AC's _bstm_ngr_generate probe result
// (0 = raw is already dBm, 1 = 802.11k protocol encoding, 2 = mixed/
// undetermined). Label naming was cross-checked against the AP
// implementation (校验 only).
const (
	RCPIMethodLegacy   = 0 // raw is already dBm
	RCPIMethodProtocol = 1 // 802.11k RCPI = 2*(rssi+110)
	RCPIMethodUnknown  = 2 // mixed / undetermined
)

// DetectRCPIMethod mirrors the probe loop in _bstm_ngr_generate: scan the
// neighbor RCPI values and decide how they are encoded.
func DetectRCPIMethod(rcpi []uint8, rsni []uint8) int {
	method := RCPIMethodUnknown
	for i := range rcpi {
		b := rcpi[i]
		var m int
		switch {
		case int8(b) >= 0:
			return RCPIMethodProtocol // positive raw cannot be dBm
		case b == 0xdc:
			return RCPIMethodLegacy // -36 marker
		case uint8(b+0x23) < 0x22:
			return RCPIMethodLegacy // 0xdd..0xff range
		case b&1 == 0:
			// even raw: disambiguate by RSNI (>= 61 → protocol encoding)
			if i < len(rsni) && rsni[i] >= 61 {
				m = RCPIMethodProtocol
			} else {
				m = RCPIMethodLegacy
			}
		default:
			m = RCPIMethodLegacy
		}
		if method != RCPIMethodUnknown && method != m {
			return RCPIMethodUnknown // "un-consistent rcpi method"
		}
		method = m
	}
	return method
}

// NormalizeRCPI converts one raw RCPI to dBm per the detected method.
// Method 1: signed((raw>>1) + 146) ≡ raw/2 − 110 (802.11k). Method 0:
// signed(raw).
func NormalizeRCPI(raw uint8, method int) int8 {
	if method == RCPIMethodProtocol {
		return int8(raw>>1 + 146)
	}
	return int8(raw)
}

// RCPIToRSSI applies the vendor smoothing ("rcpi[%u --> %d], rssi=%d"):
// rssi = max(rcpi − 10, −95).
func RCPIToRSSI(rcpi int8) int8 {
	r := rcpi - 10
	if r < -95 {
		return -95
	}
	return r
}

// SteerCandidate is one BSS candidate of the BSTM neighbor list
// (0x18-byte "bstm nbr" record on the AC).
type SteerCandidate struct {
	APMAC      [6]byte
	APID       uint16
	RadioID    uint8
	WLANID     uint8
	BSSID      [6]byte
	Channel    uint8
	ChlLoad    uint8 // channel load % of the target radio (stats)
	NoiseFloor int8  // target radio noise floor (0 → assume −95)
	RSSI       int8  // normalized + smoothed signal at the candidate
	EstRate    int   // estimated throughput Mbps; −1 = not estimable
}

// SteerConfig carries the per-decision tunables. Fields map to the 0x57
// roaming-control parameters and the wsta_roam config record
// (_wsta_roam_read_config / wsta_roam_db_cfg_get).
type SteerConfig struct {
	// hard filter (network mode 2 / "high performance" mode)
	Floor2G      int8 // default −75 (cfg override)
	Floor5G      int8 // default −80 (cfg override)
	ChlLoadMax2G uint8
	ChlLoadMax5G uint8
	// preference rule
	RoamingDif   int8 // hysteresis ("roaming dif")
	FiveGTo2GFix int8 // extra 2G penalty ("wsta_roam_5gto2g_fix")
	// selection
	MaxNbr int // wsta_roam_max_nbr (budget shared, 5G first)
}

// DefaultSteerConfig returns the vendor defaults documented in the
// filter (_nbr_filter: −75/−80 floors; budget min(6, max_nbr)).
func DefaultSteerConfig() SteerConfig {
	return SteerConfig{Floor2G: -75, Floor5G: -80, MaxNbr: 6}
}

// NbrFilterReject mirrors _nbr_filter @0x4861a4: true = candidate is
// dropped before sorting.
//
//	(1) floors: 2G ≤ −75 / 5G ≤ −80 (or configured) → drop
//	(2) channel load > per-band max → drop
//	(3) preference: effective RSSI must reach the STA's current RSSI;
//	    2G candidates pay the FiveGTo2GFix + RoamingDif bias.
func NbrFilterReject(cfg SteerConfig, staRSSI int8, policy uint8, band uint8, c SteerCandidate) bool {
	floor := cfg.Floor2G
	loadMax := cfg.ChlLoadMax2G
	if band == 1 {
		floor = cfg.Floor5G
		loadMax = cfg.ChlLoadMax5G
	}
	if c.RSSI <= floor {
		return true
	}
	if loadMax != 0 && c.ChlLoad > loadMax {
		return true
	}
	eff := c.RSSI
	if policy == 1 && band == 0 {
		eff = c.RSSI - cfg.FiveGTo2GFix - cfg.RoamingDif
	}
	return eff < staRSSI
}

// SortCandidates orders the survivors: estimated rate descending; when
// estimates are missing, RSSI descending; mixed pairs favor the
// unestimated candidate unless the other's RSSI leads by more than
// RoamingDif (_rssi_sort_fun @0x4862cc).
func SortCandidates(cfg SteerConfig, cands []SteerCandidate) {
	sort.SliceStable(cands, func(i, j int) bool {
		a, b := cands[i], cands[j]
		switch {
		case a.EstRate >= 0 && b.EstRate >= 0:
			if a.EstRate != b.EstRate {
				return a.EstRate > b.EstRate
			}
			return false
		case a.EstRate < 0 && b.EstRate < 0:
			if a.RSSI != b.RSSI {
				return a.RSSI > b.RSSI
			}
			return false
		case a.EstRate < 0: // a unestimated, b estimated
			if a.RSSI > b.RSSI && int(b.RSSI-a.RSSI) <= int(cfg.RoamingDif) {
				return true
			}
			return false
		default: // b unestimated, a estimated
			if b.RSSI > a.RSSI && int(a.RSSI-b.RSSI) <= int(cfg.RoamingDif) {
				return false
			}
			return true
		}
	})
}

// AdmissionChecker is the pseudo-associate check
// (uac_wsta_pseudo_associate_check @0x63450c → _uac_wsta_do_check chain:
// per-radio max stations, balance admission…).
type AdmissionChecker interface {
	PseudoAssociateOK(apID uint16, radioID, wlanID uint8, sta [6]byte) bool
}

// SelectNeighbors mirrors _roaming_nbr_select: budget = min(cfg.MaxNbr, 6)
// shared across bands, 5G list first, admission-checked in sorted order.
// band5G/band2G are already filtered and sorted; returns the kept lists.
func SelectNeighbors(cfg SteerConfig, adm AdmissionChecker, sta [6]byte,
	band5G, band2G []SteerCandidate) (keep5G, keep2G []SteerCandidate) {
	budget := cfg.MaxNbr
	if budget > 6 {
		budget = 6
	}
	take := func(in []SteerCandidate, out *[]SteerCandidate) {
		for _, c := range in {
			if budget <= 0 {
				return
			}
			if adm != nil && !adm.PseudoAssociateOK(c.APID, c.RadioID, c.WLANID, sta) {
				continue
			}
			*out = append(*out, c)
			budget--
		}
	}
	take(band5G, &keep5G)
	take(band2G, &keep2G)
	return keep5G, keep2G
}

// EstimateCandidateRate mirrors wss_steer_candidate_rate_estimate
// @0x48b644 with the AC300 semantics (AC300RateModel). rcpi is the
// normalized dBm value (NormalizeRCPI output). nf is the target radio's
// noise floor (0 → model fallback). meshRate2Cap > 0 means the target
// is a mesh RE and its backhaul caps the throughput.
func (t *RateTables) EstimateCandidateRate(sta, wlan SteerCaps, rcpi int8, nf int8, band uint8, meshRate2Cap int) int {
	return t.EstimateCandidateRateModel(AC300RateModel, sta, wlan, rcpi, nf, band, meshRate2Cap)
}

// EstimateCandidateRateModel is the parameterized core: normalized caps
// (handshake range checks) → min caps → SNR (rcpi − nf, model fallback)
// → table rate → mesh backhaul harmonic cap. AC300 gates rcpi < −84
// ("SNR is too low", `slti -0x54`) and assumes nf −85 (`addiu 0x55`);
// AC100 gated at −94 (`slti -0x5e`) with nf −95 (`addiu 0x5f`).
func (t *RateTables) EstimateCandidateRateModel(m RateModel, sta, wlan SteerCaps, rcpi int8, nf int8, band uint8, meshRate2Cap int) int {
	caps := MinCaps(m.NormalizeCaps(sta, band), m.NormalizeCaps(wlan, band))
	if rcpi < m.MinRCPI {
		return 0 // "SNR is too low"
	}
	if nf == 0 {
		nf = m.NoiseFloor
	}
	snr := uint8(rcpi - nf)
	if snr == 0 {
		return 0
	}
	rate := int(t.EstimateRateFromSNR(snr, caps, band))
	if meshRate2Cap > 0 {
		sum := rate + meshRate2Cap
		if sum == 0 {
			return 0
		}
		rate = rate * meshRate2Cap / sum
	}
	return rate
}

// StaContext is the AC's wsta record of one association (inputs of the
// per-station decision).
type StaContext struct {
	MAC      [6]byte
	APID     uint16 // currently serving AP
	RadioID  uint8
	WLANID   uint8
	BSSID    [6]byte // serving BSSID
	RSSI     int8    // current signal at the serving AP (filter threshold)
	BandMode uint8   // band flags from the wsta record
	Policy   uint8   // preference policy byte (sta+0x18)
	Caps     SteerCaps
}

// TriggerLookup abstracts the AC-side databases the trigger handler
// consults (apmngr_db_entry_get_by_mac / stats_db_* / wsta_db_*).
type TriggerLookup interface {
	// StaForTrigger finds a known association and verifies it belongs to
	// the reporting radio — the wsta_db_get_entry_by_mac + "associated
	// target mismatch" gate. reportAPID 0 skips the AP-id check.
	StaForTrigger(mac [6]byte, reportAPID uint16, radioID, wlanID uint8) (StaContext, bool)
	// APByBSSID resolves a candidate BSSID to its AP/radio/wlan/channel
	// and current channel load + noise floor. ok=false skips the neighbor.
	APByBSSID(bssid [6]byte) (apID uint16, apMAC [6]byte, radioID, wlanID, channel, chlLoad uint8, nf int8, ok bool)
	// MeshRate2Cap returns the backhaul cap for mesh RE APs (0 = not a RE).
	MeshRate2Cap(apID uint16) int
	// SteerCapsFor returns STA-side and WLAN-side capabilities.
	SteerCapsFor(sta StaContext, apID uint16, radioID, wlanID uint8, band uint8) (staCaps, wlanCaps SteerCaps, ok bool)
}

// BuildNeighbors computes the BSTM neighbor lists of one station from its
// trigger measurements ("_bstm_ngr_generate" + rate estimation).
func (t *RateTables) BuildNeighbors(cfg SteerConfig, sta StaContext,
	neighbors []capwap.RoamingTriggerNeighbor, look TriggerLookup) (band5G, band2G []SteerCandidate) {
	rcpiRaw := make([]uint8, len(neighbors))
	rsniRaw := make([]uint8, len(neighbors))
	for i, n := range neighbors {
		rcpiRaw[i], rsniRaw[i] = n.RCPI, n.RSNI
	}
	method := DetectRCPIMethod(rcpiRaw, rsniRaw)
	if method == RCPIMethodUnknown {
		return nil, nil // "un-consistent rcpi method" — no neighbors
	}
	for _, n := range neighbors {
		apID, apMAC, radioID, wlanID, channel, chlLoad, nf, ok := look.APByBSSID(n.BSSID)
		if !ok {
			continue // "bssid not found, skip this bstm nbr"
		}
		if apID == sta.APID && radioID == sta.RadioID && n.BSSID == sta.BSSID {
			continue // skip the serving BSS
		}
		rcpi := NormalizeRCPI(n.RCPI, method)
		c := SteerCandidate{
			APMAC: apMAC, APID: apID, RadioID: radioID, WLANID: wlanID,
			BSSID: n.BSSID, Channel: channel, ChlLoad: chlLoad, NoiseFloor: nf,
			RSSI: RCPIToRSSI(rcpi),
		}
		// the trigger's own channel field is the primary band source
		band := uint8(0)
		if is5GChannel(n.Channel) || (n.Channel == 0 && is5GChannel(channel)) {
			band = 1
		}
		staCaps, wlanCaps, ok := look.SteerCapsFor(sta, apID, radioID, wlanID, band)
		if !ok {
			c.EstRate = 0 // "Calculate rate error, use default value = 0"
		} else {
			c.EstRate = t.EstimateCandidateRate(staCaps, wlanCaps, rcpi, nf, band, look.MeshRate2Cap(apID))
		}
		if NbrFilterReject(cfg, sta.RSSI, sta.Policy, band, c) {
			continue
		}
		if band == 1 {
			band5G = append(band5G, c)
		} else {
			band2G = append(band2G, c)
		}
	}
	SortCandidates(cfg, band5G)
	SortCandidates(cfg, band2G)
	return band5G, band2G
}

// DecideRoamingTrigger runs the full decision for one 0x58 report and
// builds the 0x59 result (ap union + per-station targets). Stations whose
// wsta record does not match the reporting AP/radio/wlan are skipped
// ("associated target mismatch").
func (t *RateTables) DecideRoamingTrigger(cfg SteerConfig, adm AdmissionChecker,
	reportAPID uint16, trig *capwap.PrivRoamingTrigger, look TriggerLookup) *capwap.PrivRoamingCalcResult {
	res := &capwap.PrivRoamingCalcResult{CurrentAP: 0, RadioID: trig.RadioID}
	unionIdx := map[[6]byte]uint8{}
	addUnion := func(m [6]byte) uint8 {
		if i, ok := unionIdx[m]; ok {
			return i
		}
		i := uint8(len(res.APUnion))
		unionIdx[m] = i
		res.APUnion = append(res.APUnion, m)
		return i
	}
	for _, st := range trig.Stations {
		sta, ok := look.StaForTrigger(st.MAC, reportAPID, trig.RadioID, st.WLANID)
		if !ok {
			continue // "station not found" / "associated target mismatch"
		}
		band5G, band2G := t.BuildNeighbors(cfg, sta, st.Neighbors, look)
		keep5G, keep2G := SelectNeighbors(cfg, adm, st.MAC, band5G, band2G)
		kept := append(append([]SteerCandidate{}, keep5G...), keep2G...)
		if len(kept) == 0 {
			continue // "no nbr selected, skip this station"
		}
		var cs capwap.RoamingCalcSta
		cs.MAC = st.MAC
		for _, c := range kept {
			idx := addUnion(c.APMAC)
			cs.APUnionBitmap[idx/8] |= 1 << (idx % 8)
			cs.Radios = append(cs.Radios, capwap.RoamingCalcRadioEntry{
				APIndex: idx, RadioID: c.RadioID, WLANID: c.WLANID,
				BSSID: c.BSSID, Channel: c.Channel,
			})
		}
		res.Stations = append(res.Stations, cs)
	}
	return res
}

// is5GChannel treats channel ≥ 14 as 5 GHz (the vendor uses band_mode on
// the trigger; the channel is the fallback discriminator).
func is5GChannel(ch uint8) bool { return ch > 14 }

// AdmitAll is a pass-through AdmissionChecker.
type AdmitAll struct{}

func (AdmitAll) PseudoAssociateOK(uint16, uint8, uint8, [6]byte) bool { return true }

// SteerEngine bundles the tables/config/lookups into the RoamDecider the
// msg 9 wiring (roamwire.go) consumes.
type SteerEngine struct {
	Tables *RateTables
	Cfg    SteerConfig
	Adm    AdmissionChecker
	Look   TriggerLookup
}

// Decide implements RoamDecider.
func (s *SteerEngine) Decide(reportAPID uint16, trig *capwap.PrivRoamingTrigger) *capwap.PrivRoamingCalcResult {
	adm := s.Adm
	if adm == nil {
		adm = AdmitAll{}
	}
	return s.Tables.DecideRoamingTrigger(s.Cfg, adm, reportAPID, trig, s.Look)
}
