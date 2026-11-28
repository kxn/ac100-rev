package cweng

import (
	"math/big"
	"sort"
	"strconv"
	"strings"
)

func (db *APDB) Models() []APDBModel {
	models := make([]APDBModel, 0, len(db.APList)+len(db.MultiAPList))
	models = append(models, db.APList...)
	return append(models, db.MultiAPList...)
}

// The original apdb.lua fwids_k_v selects ap_index (zero based), never the
// newest or most capable entry. AX and BE versions can share a model/HW ID.
func (db *APDB) negotiatedModel(id uint32, firmware string) (APDBModel, bool) {
	for _, entry := range db.Negotiated {
		if entry.ID != uint64(id) {
			continue
		}
		for _, f := range entry.FirmwareIDs {
			if strings.EqualFold(f.FirmwareID, firmware) && f.Index >= 0 && f.Index < len(entry.APList) {
				return entry.APList[f.Index], true
			}
		}
	}
	return APDBModel{}, false
}

func apdbBool(v any) bool {
	switch x := v.(type) {
	case bool:
		return x
	case float64:
		return x != 0
	case string:
		return x == "1" || x == "true"
	}
	return false
}

func (db *APDB) resolveModel(ap *APEntry, model APDBModel, source string) {
	if ap.Model == "" {
		ap.Model = model.APName
	}
	for _, hw := range model.Models {
		if hw.HWVer != ap.HardwareVersion {
			continue
		}
		keys := make([]string, 0, len(hw.Radios))
		for key := range hw.Radios {
			keys = append(keys, key)
		}
		// Negotiated keys have _N suffixes. Legacy library order is 2G,5G.
		rank := func(key string) int {
			if _, n, ok := strings.Cut(key, "_"); ok {
				v, e := strconv.Atoi(n)
				if e == nil {
					return v
				}
			}
			if key == "2.4G" {
				return 0
			}
			return 1
		}
		sort.SliceStable(keys, func(i, j int) bool {
			a, b := rank(keys[i]), rank(keys[j])
			if a != b {
				return a < b
			}
			return keys[i] < keys[j]
		})
		var radios []RadioCapability
		for _, key := range keys {
			band, _, _ := strings.Cut(key, "_")
			if band != "2.4G" && band != "5.0G" && band != "5G" {
				continue
			}
			if band == "5G" {
				if _, exists := hw.Radios["5.0G"]; exists {
					continue
				}
			}
			v := hw.Radios[key]
			r := RadioCapability{Source: source, FunctionType: v.FunctionType, RadioID: uint8(len(radios) + 1), Band: "2.4 GHz", MaxSSID: v.MaxSSID, MaxClients: v.MaxStations, MinPower: v.MinTxPower, MaxPower: v.MaxTxPower, DefaultPower: v.DftTxPower, DefaultBandwidth: v.DftBWMode, MutexChannels: v.MutexChannel, TxStreams: v.MaxTxStream, RxStreams: v.MaxRxStream, Features: map[string]bool{}, Raw: map[string]string{}}
			r.SupportAC = apdbBool(v.Support11Ac)
			r.SupportAX = apdbBool(v.Support11Ax)
			r.SupportBE = apdbBool(v.Support11Be)
			r.Support160 = apdbBool(v.Support160)
			r.Support240 = apdbBool(v.Support240)
			r.Support80P80 = apdbBool(v.Support80P80)
			r.SupportWPA3 = apdbBool(v.SupportWPA3)
			if mask, ok := new(big.Int).SetString(v.ExtendCapability, 16); ok && mask.Sign() >= 0 && mask.BitLen() <= 128 {
				for i, name := range []string{"downlink_mumimo", "uplink_mumimo", "downlink_ofdma", "uplink_ofdma", "twt", "enable_6g"} {
					r.Features[name] = mask.Bit(8+i) != 0
				}
			}
			if band != "2.4G" {
				r.Band = "5 GHz"
			}
			completeRadioCapability(&r)
			radios = append(radios, r)
		}
		ap.Capabilities = radios
		ap.SupportTrunk = model.SupportTrunk
		ap.MeshDevice = model.MeshDevice
		ap.finalizeRadioCapabilities()
		return
	}
}

// Share final capability derivation for private51 and JSON model databases.
func completeRadioCapability(r *RadioCapability) {
	r.Bandwidths = []int{0, 1, 2}
	r.Modes = []int{1, 2, 3, 5, 6}
	if r.Band == "5 GHz" {
		r.Modes = []int{0, 4, 7}
	}
	if r.SupportAC {
		r.Modes = append(r.Modes, 8, 9)
		r.Bandwidths = append(r.Bandwidths, 3)
	}
	if r.SupportAX {
		if r.Band == "2.4 GHz" {
			r.Modes = append(r.Modes, 10)
		} else {
			r.Modes = append(r.Modes, 11)
		}
	}
	if r.SupportBE {
		if r.Band == "2.4 GHz" {
			r.Modes = append(r.Modes, 12)
		} else {
			r.Modes = append(r.Modes, 13)
		}
	}
	if r.Support160 {
		r.Bandwidths = append(r.Bandwidths, 5)
	}
	if r.Support240 {
		r.Bandwidths = append(r.Bandwidths, 6)
	}
	if r.Support80P80 {
		r.Bandwidths = append(r.Bandwidths, 4)
	}
	if r.MutexChannels != "" {
		for _, ch := range strings.Split(r.MutexChannels, ",") {
			n, e := strconv.Atoi(ch)
			if e == nil && n > 0 && n <= 233 {
				r.Channels = append(r.Channels, n)
			}
		}
	} else if r.Band == "2.4 GHz" {
		for i := 1; i <= 13; i++ {
			r.Channels = append(r.Channels, i)
		}
	} else {
		r.Channels = []int{36, 40, 44, 48, 149, 153, 157, 161, 165}
	}
}
