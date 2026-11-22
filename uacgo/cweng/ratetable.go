package cweng

import (
	"os"

	"uacgo/capwap"
)

// Rate estimation tables for the steering engine.
//
// Data and logic provenance is the AC binary ONLY (firmware/usr/sbin/uac):
// estimate_rate_from_snr @0x48ae10 and its data objects (uac_symbol_obj:
// estimate_snr_rate_table_2g @0x731668 size 0x118, estimate_snr_rate_table_5g
// @0x731550 size 0x118, nsdTable @0x731500 size 0x50 — MIPS big-endian).
// The AP firmware is used exclusively to cross-check the wire interaction
// (notes/apfw-xap5407gc-crosscheck.md), never as a data or logic source.
//
// data/estimate-rate-tables.bin layout (640 bytes, extracted verbatim
// from firmware/usr/sbin/uac):
//
//	[0:280]   2g table: 5 modes × 14 entries × {u8 snr, u8 pad, u16 BE rate}
//	[280:560] 5g table: same shape
//	[560:640] nsdTable: 5 modes × 4 bandwidths × u32 BE (data subcarriers)

const (
	rateTableModes     = 5
	rateTablePoints    = 14
	rateTableEntrySize = 4
	rateTableRowSize   = rateTablePoints * rateTableEntrySize // 56 = 0x38
	rateTableFileSize  = 2*rateTableModes*rateTableRowSize + rateTableModes*4*4
)

// RatePoint is one (snr, rate) breakpoint of the vendor table.
type RatePoint struct {
	SNR  uint8
	Rate uint16
}

// RateTables holds the two band tables and the subcarrier table.
type RateTables struct {
	Band2G [rateTableModes][rateTablePoints]RatePoint
	Band5G [rateTableModes][rateTablePoints]RatePoint
	NSD    [rateTableModes][4]uint32 // nsd per (mode, bw index)
}

// LoadEstimateRateTables reads data/estimate-rate-tables.bin (640 bytes).
func LoadEstimateRateTables(path string) (*RateTables, error) {
	raw, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	return ParseEstimateRateTables(raw)
}

// ParseEstimateRateTables decodes the 640-byte table image.
func ParseEstimateRateTables(raw []byte) (*RateTables, error) {
	if len(raw) != rateTableFileSize {
		return nil, capwap.ErrShortPacket
	}
	t := &RateTables{}
	parse := func(off int, dst *[rateTableModes][rateTablePoints]RatePoint) {
		for m := 0; m < rateTableModes; m++ {
			for i := 0; i < rateTablePoints; i++ {
				e := off + m*rateTableRowSize + i*rateTableEntrySize
				dst[m][i] = RatePoint{
					SNR:  raw[e],
					Rate: uint16(raw[e+2])<<8 | uint16(raw[e+3]),
				}
			}
		}
	}
	parse(0, &t.Band2G)
	parse(rateTableModes*rateTableRowSize, &t.Band5G)
	nsdOff := 2 * rateTableModes * rateTableRowSize
	for m := 0; m < rateTableModes; m++ {
		for b := 0; b < 4; b++ {
			o := nsdOff + (m*4+b)*4
			t.NSD[m][b] = uint32(raw[o])<<24 | uint32(raw[o+1])<<16 |
				uint32(raw[o+2])<<8 | uint32(raw[o+3])
		}
	}
	return t, nil
}

// SteerCaps is the negotiated (min) capability set of one STA×BSS pair,
// mirroring _steer_candidate_caps_calculate @0x48a7a0 ("Min Candidate
// Capability [nss] [mode] [bw] [mcs]").
type SteerCaps struct {
	BW   uint8 // 0=20 1=40 2=80 3=160
	NSS  uint8 // spatial streams
	Mode uint8 // 0 legacy / 1 HT / 2 VHT / 3 HE / 4 EHT
	MCS  uint8 // negotiated MCS (from the STA side)
}

// MinCaps intersects STA and WLAN capabilities (bw/mode/nss min, mcs
// from the STA) — _steer_candidate_caps_calculate semantics.
func MinCaps(sta, wlan SteerCaps) SteerCaps {
	out := SteerCaps{
		BW:   minU8(sta.BW, wlan.BW),
		NSS:  minU8(sta.NSS, wlan.NSS),
		Mode: minU8(sta.Mode, wlan.Mode),
		MCS:  sta.MCS,
	}
	return out
}

// EstimateRateFromSNR mirrors estimate_rate_from_snr @0x48ae10:
// table lookup with interpolation, then bandwidth/stream scaling by
// nsd ratios. Returns Mbps (integer arithmetic, like the vendor code).
// band: 0 = 2.4G, 1 = 5G.
func (t *RateTables) EstimateRateFromSNR(snr uint8, caps SteerCaps, band uint8) uint16 {
	if snr == 0 {
		return 0
	}
	mode, bw, nss := caps.Mode, caps.BW, caps.NSS
	if mode > 4 {
		mode = 4
	}
	if bw > 3 {
		bw = 3
	}
	if nss == 0 {
		nss = 1
	} else if nss > 16 {
		nss = 16
	}
	// per-mode capability clamps (estimate_rate_from_snr 0x12b..0x158)
	switch mode {
	case 0:
		nss, bw = 1, 0
	case 1:
		if bw > 1 {
			bw = 1
		}
		if nss > 4 {
			nss = 4
		}
	case 2, 3:
		if bw > 3 {
			bw = 3
		}
		if nss > 8 {
			nss = 8
		}
	}
	var row *[rateTablePoints]RatePoint
	if band == 0 {
		row = &t.Band2G[mode]
	} else if band == 1 {
		row = &t.Band5G[mode]
	} else {
		return 0
	}
	// walk the SNR breakpoints (idx 0..13, sentinel snr=0xff)
	var sub uint32
	i := 0
	for {
		p := row[i]
		if p.SNR > snr || p.SNR == 0xff || i == rateTablePoints-1 {
			switch {
			case i == rateTablePoints-1 || p.SNR == 0xff:
				sub = uint32(p.Rate)
			case i == 0:
				// below the first breakpoint: proportional
				if row[0].Rate == 0 || row[0].SNR == 0 {
					return 0
				}
				sub = (uint32(row[0].Rate) * uint32(snr)) / uint32(row[0].SNR)
			default:
				prev := row[i-1]
				slope := uint32(0)
				if p.SNR != prev.SNR {
					slope = (uint32(p.Rate) - uint32(prev.Rate)) / (uint32(p.SNR) - uint32(prev.SNR))
				}
				sub = slope*(uint32(snr)-uint32(prev.SNR)) + uint32(prev.Rate)
			}
			break
		}
		i++
	}
	// bandwidth + stream scaling: rate = sub × nss × nsd[mode][bw] / nsd[mode][0]
	div := t.NSD[mode][0]
	if div == 0 {
		return 0
	}
	total := sub * uint32(nss) * t.NSD[mode][bw] / div
	if total > 0xffff {
		total = 0xffff
	}
	return uint16(total)
}

// RateModel captures the model-specific constants of the estimation
// chain (SNR base, low-signal gate, capability ranges). AC300/NAC
// semantics are the default; AC100 is selectable. Evidence: MIPS
// disassembly of wss_steer_candidate_rate_estimate (AC100 `addiu 0x5f`
// + `slti -0x5e` vs AC300 `addiu 0x55` + `slti -0x54`) and the range
// checks of _sta_caps_calculate / _wlan_caps_calculate (bw 2档→4档,
// wlan cap 0xd→0xf) — notes/tl-ac300-policy-diff.md.
type RateModel struct {
	Name       string
	NoiseFloor int8 // nf fallback when the radio stats lack one
	MinRCPI    int8 // gate: rcpi < MinRCPI => not estimable (0)
	// capability ranges accepted from the handshake parse; anything
	// outside falls back to the per-band defaults (NormalizeCaps).
	StaMCSMax  uint8 // sta side MCS upper bound (inclusive)
	WlanMCSMax uint8 // wlan side MCS upper bound (inclusive)
	BWMax      uint8 // negotiated bw upper bound (inclusive)
}

// AC300RateModel is the current-generation semantics (AC300 and
// NAC10000S share it): nf −85, gate −84, bw up to 20/40/80/160.
var AC300RateModel = RateModel{
	Name: "AC300", NoiseFloor: -85, MinRCPI: -84,
	StaMCSMax: 13, WlanMCSMax: 14, BWMax: 3,
}

// AC100RateModel is the classic semantics: nf −95, gate −94, bw 20/40.
var AC100RateModel = RateModel{
	Name: "AC100", NoiseFloor: -95, MinRCPI: -94,
	StaMCSMax: 13, WlanMCSMax: 12, BWMax: 1,
}

// NormalizeCaps validates one parsed capability set against the model
// ranges (the "out of range, use default" paths of _sta_caps_calculate
// @0x48a928 / _wlan_caps_calculate @0x48ab30). Per-band defaults from
// the decomp (unchanged on AC300): 5G {bw=2,nss=2,mode=2,mcs=9},
// 2G {bw=0,nss=1,mode=1,mcs=7}.
func (m RateModel) NormalizeCaps(c SteerCaps, band uint8) SteerCaps {
	nssOK := c.NSS >= 1 && c.NSS <= 16
	modeOK := c.Mode <= 4
	mcsOK := c.MCS <= m.StaMCSMax && c.MCS <= m.WlanMCSMax
	bwOK := c.BW <= m.BWMax
	if nssOK && modeOK && mcsOK && bwOK {
		return c
	}
	if band == 1 {
		return SteerCaps{BW: 2, NSS: 2, Mode: 2, MCS: 9}
	}
	return SteerCaps{BW: 0, NSS: 1, Mode: 1, MCS: 7}
}

func minU8(a, b uint8) uint8 {
	if a < b {
		return a
	}
	return b
}
