package cweng

import (
	"encoding/binary"
	"encoding/hex"
	"fmt"
	"math/big"
	"strconv"
	"strings"
	"unicode/utf8"
)

// RadioCapability is AP-reported metadata from private 0x51. Numeric subtype
// meanings: _apdb_pkt_parse_radio (legacy 0x0060e514; V6 0x0070ae08).
// The TLV container and actual values are checked against the V6 AP Join.
type RadioCapability struct {
	Source           string            `json:"source"`
	Alternate        *RadioCapability  `json:"alternate_band,omitempty"`
	FunctionType     int               `json:"function_type"`
	RadioID          uint8             `json:"radio_id"`
	Band             string            `json:"band"`
	MaxSSID          int               `json:"max_ssid"`
	MaxClients       int               `json:"max_clients"`
	MinPower         int               `json:"min_power_dbm"`
	MaxPower         int               `json:"max_power_dbm"`
	DefaultPower     int               `json:"default_power_dbm"`
	SupportAC        bool              `json:"support_11ac"`
	SupportAX        bool              `json:"support_11ax"`
	SupportBE        bool              `json:"support_11be"`
	Support160       bool              `json:"support_160mhz"`
	Support240       bool              `json:"support_240mhz"`
	Support80P80     bool              `json:"support_80p80mhz"`
	SupportWPA3      bool              `json:"support_wpa3"`
	TxStreams        int               `json:"tx_streams"`
	RxStreams        int               `json:"rx_streams"`
	DefaultBandwidth *int              `json:"default_bandwidth,omitempty"`
	MutexChannels    string            `json:"mutex_channels,omitempty"`
	Channels         []int             `json:"channels"`
	Modes            []int             `json:"modes"`
	Bandwidths       []int             `json:"bandwidths"`
	Features         map[string]bool   `json:"features"`
	Raw              map[string]string `json:"raw_subtypes"`
}
type APCapabilities struct {
	ExtWirePhys  int
	SupportTrunk bool
	HardwareID   string
	Model        string
	Radios       []RadioCapability
}

func (a *APEntry) HasCapability(bit int) bool {
	return a != nil && bit >= 0 && bit/32 < len(a.GeneralCapabilities) && a.GeneralCapabilities[bit/32]&(1<<uint(bit%32)) != 0
}

func (a APStatus) HasCapability(bit int) bool {
	return bit >= 0 && bit/32 < len(a.GeneralCapabilities) && a.GeneralCapabilities[bit/32]&(1<<uint(bit%32)) != 0
}

func parseByteTLVs(b []byte, count int, visit func(byte, []byte) error) error {
	if count > 128 {
		return fmt.Errorf("apdb: excessive subtype count")
	}
	for i := 0; i < count; i++ {
		if len(b) < 2 {
			return fmt.Errorf("apdb: truncated subtype")
		}
		n := int(b[1])
		if n+2 > len(b) {
			return fmt.Errorf("apdb: truncated value")
		}
		if err := visit(b[0], b[2:2+n]); err != nil {
			return err
		}
		b = b[2+n:]
	}
	if len(b) != 0 {
		return fmt.Errorf("apdb: trailing bytes")
	}
	return nil
}
func ParseAPCapabilities(b []byte) (APCapabilities, error) { return parseAPCapabilities(b, 0) }
func parseAPCapabilities(b []byte, depth int) (APCapabilities, error) {
	var out APCapabilities
	if len(b) < 16 || depth > 2 {
		return out, fmt.Errorf("apdb: short header")
	}
	count := binary.BigEndian.Uint32(b[12:16])
	if count > 128 {
		return out, fmt.Errorf("apdb: excessive item count")
	}
	err := parseByteTLVs(b[16:], int(count), func(typ byte, v []byte) error {
		switch typ {
		case 4:
			if len(v) != 1 {
				return fmt.Errorf("apdb: invalid port count")
			}
			out.ExtWirePhys = int(v[0])
		case 5:
			if len(v) != 1 {
				return fmt.Errorf("apdb: invalid trunk capability")
			}
			out.SupportTrunk = v[0] != 0
		case 9:
			if len(v) == 32 {
				if id, err := hex.DecodeString(string(v)); err == nil {
					out.HardwareID = hex.EncodeToString(id)
				}
			}
		case 1:
			if !utf8.Valid(v) || len(v) == 0 {
				return fmt.Errorf("apdb: invalid model")
			}
			out.Model = strings.TrimRight(string(v), "\x00")
		case 7:
			if len(v) < 4 || v[0] > 1 {
				return fmt.Errorf("apdb: unsupported radio header")
			}
			r := RadioCapability{Source: "ap-report", RadioID: uint8(len(out.Radios) + 1), Band: "2.4 GHz", Raw: map[string]string{}, Features: map[string]bool{}}
			if v[0] == 1 {
				r.Band = "5 GHz"
			}
			err := parseByteTLVs(v[4:], int(v[1]), func(t byte, value []byte) error {
				r.Raw[strconv.Itoa(int(t))] = hex.EncodeToString(value)
				switch t {
				case 1, 2, 3, 4, 5:
					if len(value) != 2 {
						return fmt.Errorf("apdb: invalid numeric capability")
					}
					n := int(binary.BigEndian.Uint16(value))
					switch t {
					case 1:
						r.MaxSSID = n
					case 2:
						r.MaxClients = n
					case 3:
						r.MaxPower = n
					case 4:
						r.MinPower = n
					case 5:
						r.DefaultPower = n
					}
				case 6:
					if len(value) == 1 {
						r.SupportAC = value[0] != 0
					}
				case 10:
					if len(value) == 1 {
						r.SupportAX = value[0] != 0
					}
				case 7:
					r.MutexChannels = strings.TrimRight(string(value), "\x00")
				case 8:
					if len(value) == 1 {
						n := int(value[0])
						r.DefaultBandwidth = &n
					}
				case 9:
					if len(value) == 1 {
						r.Support160 = value[0] != 0
					}
				case 14:
					if len(value) == 1 {
						r.Support80P80 = value[0] != 0
					}
				case 15:
					h := make([]byte, 16)
					binary.BigEndian.PutUint32(h[12:], 1)
					h = append(h, 7, byte(len(value)))
					h = append(h, value...)
					child, err := parseAPCapabilities(h, depth+1)
					if err != nil || len(child.Radios) != 1 {
						return fmt.Errorf("invalid alternate radio capability")
					}
					r.Alternate = &child.Radios[0]
					r.Alternate.RadioID = r.RadioID
				case 24:
					if len(value) == 1 {
						r.FunctionType = int(value[0])
					}
				case 16:
					if len(value) == 1 {
						r.TxStreams = int(value[0])
					}
				case 17:
					if len(value) == 1 {
						r.RxStreams = int(value[0])
					}
				case 18:
					if len(value) == 1 {
						r.SupportWPA3 = value[0] != 0
					}
				case 19:
					mask, valid := new(big.Int).SetString(string(value), 16)
					if valid && mask.Sign() >= 0 && mask.BitLen() <= 128 {
						for i, name := range []string{"downlink_mumimo", "uplink_mumimo", "downlink_ofdma", "uplink_ofdma", "twt", "enable_6g"} {
							r.Features[name] = mask.Bit(8+i) != 0
						}
					}
				case 21:
					if len(value) == 1 {
						r.SupportBE = value[0] != 0
					}
				case 22:
					if len(value) == 1 {
						r.Support240 = value[0] != 0
					}
				}
				return nil
			})
			if err != nil {
				return err
			}
			r.Bandwidths = []int{0, 1, 2}
			r.Modes = []int{1, 2, 3, 5, 6}
			if v[0] == 1 {
				r.Modes = []int{0, 4, 7}
			}
			if r.SupportAC {
				r.Modes = append(r.Modes, 8, 9)
				r.Bandwidths = append(r.Bandwidths, 3)
			}
			if r.SupportAX {
				if v[0] == 0 {
					r.Modes = append(r.Modes, 10)
				} else {
					r.Modes = append(r.Modes, 11)
				}
			}
			if r.SupportBE {
				if v[0] == 0 {
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
			} else if v[0] == 0 {
				for n := 1; n <= 13; n++ {
					r.Channels = append(r.Channels, n)
				}
			} else {
				r.Channels = []int{36, 40, 44, 48, 149, 153, 157, 161, 165}
			}
			out.Radios = append(out.Radios, r)
		}
		return nil
	})
	return out, err
}

func (e *Engine) UseAPDB(db *APDB) { e.apdb = db }

// Old devices do not supply the private 0x51 capability tree. Match both the
// exact model ID and hardware revision in the firmware DB; never borrow a
// different hardware revision's capabilities.
func (db *APDB) ResolveCapabilities(ap *APEntry) {
	for _, model := range db.APList {
		if model.ID != uint64(ap.ModelID) {
			continue
		}
		if ap.Model == "" {
			ap.Model = model.APName
		}
		for _, hw := range model.Models {
			if hw.HWVer != ap.HardwareVersion {
				continue
			}
			for _, band := range []string{"2.4G", "5G"} {
				v, ok := hw.Radios[band]
				if !ok {
					continue
				}
				r := RadioCapability{Source: "firmware-apdb", RadioID: uint8(len(ap.Capabilities) + 1), Band: "2.4 GHz", MaxSSID: v.MaxSSID, MaxClients: v.MaxStations, MinPower: v.MinTxPower, MaxPower: v.MaxTxPower, DefaultPower: v.DftTxPower, Features: map[string]bool{}, Raw: map[string]string{}, Modes: []int{1, 2, 3, 5, 6}, Bandwidths: []int{0, 1, 2}}
				switch x := v.Support11Ac.(type) {
				case bool:
					r.SupportAC = x
				case float64:
					r.SupportAC = x != 0
				case string:
					r.SupportAC = x == "1" || x == "true"
				}
				if r.DefaultPower == 0 {
					r.DefaultPower = r.MaxPower
				}
				if band == "5G" {
					r.Band = "5 GHz"
					r.Modes = []int{0, 4, 7}
					r.Channels = []int{36, 40, 44, 48, 149, 153, 157, 161, 165}
				} else {
					for n := 1; n <= 13; n++ {
						r.Channels = append(r.Channels, n)
					}
				}
				if r.SupportAC {
					r.Modes = append(r.Modes, 8, 9)
					r.Bandwidths = append(r.Bandwidths, 3)
				}
				ap.Capabilities = append(ap.Capabilities, r)
			}
			return
		}
	}
}
