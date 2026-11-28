package admin

import (
	"encoding/binary"
	"fmt"
	"golang.org/x/text/encoding/simplifiedchinese"
	"strings"
	"uacgo/capwap"
	"uacgo/cweng"
)

type WirelessOptions struct {
	VLANPool    uint16             `json:"vlan_pool,omitempty"`
	Schedule    *ServiceSchedule   `json:"schedule,omitempty"`
	MLO         bool               `json:"mlo"`
	Description string             `json:"description"`
	Encoding    string             `json:"encoding"`
	Isolate     bool               `json:"isolate"`
	VLAN        int                `json:"vlan"`
	Auth        int                `json:"auth"`   // 1 WPA, 2 WPA2, 3 mixed
	Cipher      int                `json:"cipher"` // 1 TKIP, 2 AES, 0 auto
	KeyUpdate   int                `json:"key_update_interval"`
	RateLimit   *WirelessRateLimit `json:"rate_limit,omitempty"`
	Multicast   *MulticastOptions  `json:"multicast,omitempty"`
}
type WirelessRateLimit struct {
	Enabled  bool   `json:"enabled"`
	Mode     string `json:"mode"`
	Upload   int    `json:"upload_kbps"`
	Download int    `json:"download_kbps"`
}
type MulticastOptions struct {
	ConfigureGlobal bool `json:"configure_global"`
	GlobalSnooping  bool `json:"global_snooping"`
	Snooping        bool `json:"snooping"`
	ToUnicast       bool `json:"to_unicast"`
	DropUnknown     bool `json:"drop_unknown"`
	Rate2G          int  `json:"rate_2g"`
	Rate5G          int  `json:"rate_5g"`
	RateType2G      int  `json:"rate_type_2g"` // original igmp_2g_rate_type: 0 Mbps, 1 MCS
	RateType5G      int  `json:"rate_type_5g"`
	Query           bool `json:"query"`
	QueryInterval   int  `json:"query_interval"`
	MaxResponse     int  `json:"max_response"`
}

func serviceOptions(s Service) WirelessOptions {
	if s.Options != nil {
		return *s.Options
	}
	auth := 2
	if s.Security == "wpa-psk" {
		auth = 1
	}
	if strings.HasPrefix(s.Security, "wpa-wpa2") || s.Security == "wpa2-wpa3-psk" {
		auth = 3
	}
	return WirelessOptions{Encoding: "utf-8", Auth: auth, Cipher: 2, KeyUpdate: 86400}
}
func serviceSSID(s Service) ([]byte, error) {
	if serviceOptions(s).Encoding == "gbk" {
		return simplifiedchinese.GBK.NewEncoder().Bytes([]byte(s.SSID))
	}
	return []byte(s.SSID), nil
}
func validateWirelessOptions(s Service) error {
	o := serviceOptions(s)
	if err := o.Schedule.validate(); err != nil {
		return err
	}
	if o.Encoding != "" && o.Encoding != "utf-8" && o.Encoding != "gbk" {
		return fmt.Errorf("SSID 编码无效")
	}
	b, err := serviceSSID(s)
	if err != nil || len(b) < 1 || len(b) > 32 {
		return fmt.Errorf("SSID 编码后必须为 1–32 字节")
	}
	if o.VLANPool > 255 || o.VLANPool != 0 && o.VLAN != 0 {
		return fmt.Errorf("VLAN 池编号无效，且不能同时指定固定 VLAN")
	}
	if len([]byte(o.Description)) > 150 || o.VLAN < 0 || o.VLAN > 4094 {
		return fmt.Errorf("描述或 VLAN 无效")
	}
	if o.Auth < 1 || o.Auth > 3 || o.Cipher < 0 || o.Cipher > 2 || (o.KeyUpdate != 0 && o.KeyUpdate < 30) || o.KeyUpdate > 604800 {
		return fmt.Errorf("认证、加密或密钥更新周期无效")
	}
	if s.Security == "wpa2-wpa3-psk" && (o.Auth != 3 || o.Cipher != 2) {
		return fmt.Errorf("WPA2/WPA3 混合模式使用自动认证及 AES 加密")
	}
	if l := o.RateLimit; l != nil {
		if l.Mode != "client" && l.Mode != "ssid" {
			return fmt.Errorf("限速方式无效")
		}
		if l.Enabled && (l.Upload < 8 || l.Download < 8 || l.Upload > 8000000 || l.Download > 8000000 || l.Upload%8 != 0 || l.Download%8 != 0) {
			return fmt.Errorf("速率为 8–8000000 kbps，且须为 8 的倍数")
		}
	}
	if x := o.Multicast; x != nil {
		validRate := func(kind, value int, legacy []int) bool {
			return kind == 0 && hasInt(legacy, value) || kind == 1 && value >= 0 && value <= 255
		}
		if x.QueryInterval < 1 || x.QueryInterval > 65535 || x.MaxResponse < 1 || x.MaxResponse > 255 || x.MaxResponse > x.QueryInterval || !validRate(x.RateType2G, x.Rate2G, []int{1, 2, 5, 6, 9, 11, 12, 18, 24, 36, 48, 54}) || !validRate(x.RateType5G, x.Rate5G, []int{6, 9, 12, 18, 24, 36, 48, 54}) {
			return fmt.Errorf("组播速率或查询周期无效")
		}
	}

	return nil
}
func validateServiceCapability(s Service, ap cweng.APStatus, radio uint8) error {
	o := serviceOptions(s)
	if o.VLANPool != 0 && !supportsPool(ap) {
		return fmt.Errorf("AP 不支持 VLAN 池")
	}
	// IGMP is an independent firmware callback, gated by capability43 at
	// recipient selection (6dba0c/6dbbe8/6d9ef8). Unsupported IGMP must not
	// veto the ordinary WLAN creation. wirelessExtraElements gates its own
	// multicast elements and capability99 subfeatures independently.

	if o.MLO && s.Security == "open" {
		return fmt.Errorf("MLO 无线服务需要加密安全方式")
	}
	if o.MLO && ap.SubCapabilities[0x5f]&2 == 0 {
		return fmt.Errorf("AP 不支持 MLO 无线服务")
	}
	if l := o.RateLimit; l != nil && l.Enabled && !ap.HasCapability(13) {
		return fmt.Errorf("AP 不支持无线服务限速")
	}
	return nil
}
func serviceCapabilityNote(s Service, ap cweng.APStatus) string {
	var notes []string
	if s.Security == "wpa2-wpa3-psk" {
		for _, c := range ap.Capabilities {
			if selectedServiceRadios(s, ap)[c.RadioID] && !c.SupportWPA3 {
				notes = append(notes, fmt.Sprintf("射频 %d 未声明 WPA3，按原固件下发兼容 PSK 参数", c.RadioID))
			}
		}
	}
	x := serviceOptions(s).Multicast
	if x == nil {
		return strings.Join(notes, "；")
	}
	if !ap.HasCapability(43) && (x.ConfigureGlobal || x.Snooping || x.Query) {
		notes = append(notes, "AP 未上报组播配置能力；组播参数不适用，无线服务照常下发")
	}
	if x.ConfigureGlobal && x.ToUnicast && (!ap.HasCapability(99) || ap.SubCapabilities[99]&1 == 0) {
		notes = append(notes, "AP 未上报组播转单播能力；该扩展不适用，其余配置照常下发")
	}
	if x.ConfigureGlobal && (x.RateType2G == 1 || x.RateType5G == 1) && !ap.SupportsMulticastMCS() {
		notes = append(notes, "AP 未上报组播 MCS 速率能力；该速率扩展不适用，其余配置照常下发")
	}
	return strings.Join(notes, "；")
}

func serviceSecurity(s Service) (byte, []byte) {
	o := serviceOptions(s)
	mode := byte(0)
	if s.Security == "wpa2-wpa3-psk" {
		mode = 4
	} else if s.Security != "open" {
		mode = 1
	}
	if mode == 0 {
		return 0, nil
	}
	tail := []byte{byte(o.Auth), byte(o.Cipher)}
	tail = binary.BigEndian.AppendUint32(tail, uint32(o.KeyUpdate))

	tail = binary.BigEndian.AppendUint16(tail, uint16(len(s.Passphrase)))
	return mode, append(tail, []byte(s.Passphrase)...)
}
func advancedWLANElements(s Service, radio uint8, ap cweng.APStatus) []capwap.Element {
	if serviceOptions(s).VLANPool != 0 {
		o := serviceOptions(s)
		o.VLAN = 5000 + int(o.VLANPool)
		s.Options = &o
	}
	if s.Security == "wpa2-wpa3-psk" {
		supported := false
		for _, c := range ap.Capabilities {
			supported = supported || c.RadioID == radio && c.SupportWPA3
		}
		if !supported {
			// Original callback@6dbd74 downgrades encryption4 to1 when
			// apdb_support_wpa3_by_id returns0; auth/cipher/key stay intact.
			o := serviceOptions(s)
			s.Options = &o
			s.Security = "wpa2-psk"
		}
	}
	out := wlanElements(s, radio)
	if !s.Enabled {
		return out
	}
	// Newest APs use 0x94 (additional NAS-ID/enable fields); older APs 0x63.
	if ap.HasCapability(63) {
		o := serviceOptions(s)
		mode, tail := serviceSecurity(s)
		value := []byte{radio, s.WLAN}
		value = binary.BigEndian.AppendUint16(value, uint16(o.VLAN))
		value = binary.BigEndian.AppendUint16(value, 100)
		value = append(value, 3, boolean(o.Isolate), 0, 0, 1, mode)
		value = append(value, tail...)
		out[1] = capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0x94, []capwap.PrivElementValue{{Type: 0x94, Value: value}})}
	} else if !ap.HasCapability(32) {
		// PSK/open fields are byte-identical in9 and63. Their RADIUS tails
		// differ, but RADIUS is outside this program's supported settings.
		out[1] = privateSetting(9, out[1].Value[10:])
	}
	return out
}
func wirelessExtraElements(s Service, radio uint8, ap cweng.APStatus) []capwap.Element {
	if !s.Enabled {
		return nil
	}
	o := serviceOptions(s)
	out := []capwap.Element{}
	add := func(typ uint16, b []byte) {
		out = append(out, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, typ, []capwap.PrivElementValue{{Type: typ, Value: b}})})
	}
	if ap.HasCapability(13) {
		kind := byte(1)
		up, down := 0, 0
		if l := o.RateLimit; l != nil && l.Enabled {
			kind = 2
			if l.Mode == "ssid" {
				kind = 3
			}
			up = l.Upload / 8
			down = l.Download / 8
		}
		v := binary.BigEndian.AppendUint32([]byte{kind}, uint32(up))
		v = binary.BigEndian.AppendUint32(v, uint32(down))
		add(0x45, append(v, radio, s.WLAN))
	}
	if ap.SubCapabilities[0x5f]&2 != 0 && s.Security != "open" {
		add(0xc0, []byte{radio, 0, 0, 0, 8, s.WLAN, 0, 0, 0, 3, 2, 1, boolean(o.MLO)})
	}
	if supportsPool(ap) {
		b := []byte{1, 1, boolean(o.VLANPool != 0)}
		if o.VLANPool != 0 {
			b = append(b, 2, 2, byte(o.VLANPool>>8), byte(o.VLANPool))
		}
		payload := append([]byte{4, byte(len(b))}, b...)
		v := []byte{radio}
		v = binary.BigEndian.AppendUint32(v, uint32(5+len(payload)))
		v = append(v, s.WLAN)
		v = binary.BigEndian.AppendUint32(v, uint32(len(payload)))
		add(0xc0, append(v, payload...))
	}
	if x := o.Multicast; x != nil {
		// Global multicast processing/rates, plus per-radio/WLAN snooping/query switches.
		rate, rateType := x.Rate2G, x.RateType2G
		for _, c := range ap.Capabilities {
			if c.RadioID == radio && c.Band == "5 GHz" {
				rate, rateType = x.Rate5G, x.RateType5G
			}
		}
		if x.ConfigureGlobal && ap.HasCapability(43) {
			legacy := []byte{boolean(x.GlobalSnooping), boolean(x.DropUnknown), 0}
			if rateType == 0 {
				legacy[2] = 1
				legacy = append(legacy, radio, byte(rate>>8), byte(rate))
			}
			add(0x70, legacy)

			add(0x72, []byte{byte(x.QueryInterval >> 8), byte(x.QueryInterval), byte(x.MaxResponse)})

			// V6 _uac_wserv_pkt_igmp_snooping_config_send@6ecd34:
			// c9 count16 then type8/length8/value; type0 is to-unicast,
			// type1 is count8 then radio8/MCS8. These subfeatures are independent.
			extension := []byte{0, 0}
			if ap.HasCapability(99) && ap.SubCapabilities[99]&1 != 0 {
				extension[1]++
				extension = append(extension, 0, 1, boolean(x.ToUnicast))
			}
			if rateType == 1 && ap.SupportsMulticastMCS() {
				extension[1]++
				extension = append(extension, 1, 3, 1, radio, byte(rate))
			}
			if extension[1] != 0 {
				add(0xc9, extension)
			}
		}
		if ap.HasCapability(43) {
			add(0x71, []byte{0, 0, 0, 1, radio, s.WLAN, boolean(x.Snooping)})
			add(0x73, []byte{0, 0, 0, 1, radio, s.WLAN, boolean(x.Query)})
		}
	}
	return out
}
func redactService(s Service) Service {
	s.HasPassword = s.Passphrase != ""
	s.Passphrase = ""
	return s
}
