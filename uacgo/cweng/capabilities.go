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
	AXDefaults       *RadioFeatureDefaults `json:"feature_defaults,omitempty"`
	ControlFeatures  map[string]bool       `json:"control_features"`
	Source           string                `json:"source"`
	Alternate        *RadioCapability      `json:"alternate_band,omitempty"`
	FunctionType     int                   `json:"function_type"`
	RadioID          uint8                 `json:"radio_id"`
	Band             string                `json:"band"`
	MaxSSID          int                   `json:"max_ssid"`
	MaxClients       int                   `json:"max_clients"`
	MinPower         int                   `json:"min_power_dbm"`
	MaxPower         int                   `json:"max_power_dbm"`
	DefaultPower     int                   `json:"default_power_dbm"`
	RealMaxPower     int                   `json:"real_max_power_dbm,omitempty"`
	RealMinPower     int                   `json:"real_min_power_dbm,omitempty"`
	RealDefaultPower int                   `json:"real_default_power_dbm,omitempty"`
	SupportAC        bool                  `json:"support_11ac"`
	SupportAX        bool                  `json:"support_11ax"`
	SupportBE        bool                  `json:"support_11be"`
	Support160       bool                  `json:"support_160mhz"`
	Support240       bool                  `json:"support_240mhz"`
	Support80P80     bool                  `json:"support_80p80mhz"`
	SupportWPA3      bool                  `json:"support_wpa3"`
	TxStreams        int                   `json:"tx_streams"`
	RxStreams        int                   `json:"rx_streams"`
	DefaultBandwidth *int                  `json:"default_bandwidth,omitempty"`
	MutexChannels    string                `json:"mutex_channels,omitempty"`
	Channels         []int                 `json:"channels"`
	Modes            []int                 `json:"modes"`
	Bandwidths       []int                 `json:"bandwidths"`
	Features         map[string]bool       `json:"features"`
	Raw              map[string]string     `json:"raw_subtypes"`
}

// Private b2, cw_priv_11ax_feature_default_value_parse @6b2e80.
// rdmngr_capwap_callback_join_req_listen @73d0f0 consumes its first instance.
type RadioFeatureDefaults struct {
	Reserved                     uint8 `json:"reserved"`
	DownlinkMUMIMO, UplinkMUMIMO uint8
	DownlinkOFDMA, UplinkOFDMA   uint8
	TWT                          uint8
	GI                           int8
	Enable6G, PSC6G              uint8
}

func parseRadioFeatureDefaults(b []byte) *RadioFeatureDefaults {
	if len(b) != 9 {
		return nil
	}
	return &RadioFeatureDefaults{b[0], b[1], b[2], b[3], b[4], b[5], int8(b[6]), b[7], b[8]}
}

type APCapabilities struct {
	ProductType  uint8
	MeshDevice   bool
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

// V4 _send_tdcp_request_to_ap_by_id@50b9c0 and V6@58a0bc prepend
// capability0x31 to apmngr_db_get_addr_by_capacity's variadic filter.
// Capability70 controls the AX radio extension; 66 controls PMK handling.
func (a APStatus) SupportsTDCP() bool { return a.HasCapability(49) }

func (a APStatus) SupportsARPScan() bool {
	return a.HasCapability(16) && a.SubCapabilities[16]&2 != 0
}
func (a APStatus) SupportsMeshBackhaulMode() bool {
	return a.HasCapability(44) && a.SubCapabilities[44]&2 != 0
}

// V6 config-update@6119c4 and apmngr_ap_port_cfg_send@5ded4c read
// sub98 bits1/14 directly. Without extended VLAN support the original full
// configuration uses private30 for one LAN, or private43 for two to four.
func (a APStatus) UsesExtendedPortVLAN() bool { return a.SubCapabilities[98]&2 != 0 }
func (a APStatus) SupportsPortEnable() bool   { return a.SubCapabilities[98]&(1<<14) != 0 }
func (a APStatus) SupportsMulticastMCS() bool {
	return a.HasCapability(99) && a.SubCapabilities[99]&2 != 0
}
func (a APStatus) SupportsPortVLAN(id uint8) bool {
	return a.UsesExtendedPortVLAN() || a.ExtWirePhys >= 1 && a.ExtWirePhys <= 4 && id >= 1 && int(id) <= a.ExtWirePhys
}

func parseByteTLVs(b []byte, count int, visit func(byte, []byte) error) error {
	if count < 0 || count > len(b)/2 {
		return fmt.Errorf("apdb: subtype count exceeds payload")
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
	if uint64(count) > uint64((len(b)-16)/2) {
		return out, fmt.Errorf("apdb: item count exceeds payload")
	}
	err := parseByteTLVs(b[16:], int(count), func(typ byte, v []byte) error {
		switch typ {
		case 12: // APDB_MSG_TYPE_IS_MESH_DEVICE: switch(type-1), V6 70cc34.
			if len(v) != 1 {
				return fmt.Errorf("apdb: invalid mesh device flag")
			}
			out.MeshDevice = v[0] != 0
		case 13: // APDB_MSG_TYPE_PRODUCT_TYPE: AP/router/sensor/XVR.
			if len(v) != 1 {
				return fmt.Errorf("apdb: invalid product type")
			}
			out.ProductType = v[0]
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
				case 1, 2, 3, 4, 5, 11, 12, 13:
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
					case 11:
						r.RealMaxPower = n
					case 12:
						r.RealMinPower = n
					case 13:
						r.RealDefaultPower = n
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
			completeRadioCapability(&r)
			out.Radios = append(out.Radios, r)
		}
		return nil
	})
	return out, err
}

// APDB radio subtypes11/12/13 are physical power values, used when the
// AP declares capability38. rrm_get_apdb_pwr@4ac8e4 falls back per field
// when a physical bound is zero. Normalize the shared capability view so
// the editor, validation, level conversion and RRM use the same units.
func effectiveRadioPower(c RadioCapability, physical bool) RadioCapability {
	if physical {
		if c.RealMaxPower != 0 {
			c.MaxPower = c.RealMaxPower
		}
		if c.RealMinPower != 0 {
			c.MinPower = c.RealMinPower
		}
		if c.RealDefaultPower != 0 {
			c.DefaultPower = c.RealDefaultPower
		}
	}
	return c
}

// Apply the same controller-facing capability view to private51 reports and
// model-library fallback. Raw per-radio features remain available separately.
// V6@73d0f0/742e24/73ea84 uses radio1's bitmap and general70 for AX controls;
// rrm_get_apdb_pwr@4ac8e4 switches to physical power under general38.
func (a *APEntry) finalizeRadioCapabilities() {
	first := map[string]bool{}
	for _, c := range a.Capabilities {
		if c.RadioID == 1 {
			first = c.Features
		}
	}
	for i := range a.Capabilities {
		c := effectiveRadioPower(a.Capabilities[i], a.HasCapability(38))
		c.ControlFeatures = map[string]bool{}
		for name, value := range first {
			c.ControlFeatures[name] = value && a.HasCapability(70)
		}
		if a.radioFeatureDefaults != nil && a.HasCapability(70) {
			d := *a.radioFeatureDefaults
			c.AXDefaults = &d
		}
		a.Capabilities[i] = c
	}
}

func (e *Engine) UseAPDB(db *APDB) { e.apdb = db }

// Old devices do not supply the private 0x51 capability tree. Match both the
// exact model ID and hardware revision in the firmware DB; never borrow a
// different hardware revision's capabilities.
func (db *APDB) ResolveCapabilities(ap *APEntry) {
	if len(ap.Capabilities) > 0 {
		return
	}
	if model, ok := db.negotiatedModel(ap.ModelID, ap.FirmwareID); ok {
		if model.HardwareID != "" && ap.HardwareID != "" && !strings.EqualFold(model.HardwareID, ap.HardwareID) {
			return
		}
		db.resolveModel(ap, model, "negotiated-apdb")
		return
	}
	for _, model := range db.Models() {
		if model.ID == uint64(ap.ModelID) {
			db.resolveModel(ap, model, "firmware-apdb")
			return
		}
	}
}

// Model ID zero follows the original Join fallback: existing inventory first
// (restored by APStore), otherwise exact model name and hardware in APDB.
// A current reported capability tree is never replaced by this identity lookup.
func (db *APDB) ResolveIdentity(ap *APEntry) {
	if ap.ModelID != 0 || ap.Model == "" {
		return
	}
	match := func(model APDBModel) bool {
		if model.APName != ap.Model {
			return false
		}
		for _, hw := range model.Models {
			if hw.HWVer == ap.HardwareVersion {
				ap.ModelID = uint32(model.ID)
				return true
			}
		}
		return false
	}
	for _, model := range db.Models() {
		if match(model) {
			return
		}
	}
	for _, entry := range db.Negotiated {
		for _, model := range entry.APList {
			if match(model) {
				return
			}
		}
	}
}
