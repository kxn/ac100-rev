package admin

import (
	"encoding/binary"
	"fmt"
	"golang.org/x/text/encoding/simplifiedchinese"
	"net"
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
	Radius      *RadiusOptions     `json:"radius,omitempty"`
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
	Query           bool `json:"query"`
	QueryInterval   int  `json:"query_interval"`
	MaxResponse     int  `json:"max_response"`
}
type RadiusOptions struct {
	IP             string `json:"ip"`
	Port           int    `json:"port"`
	AccountingPort int    `json:"accounting_port"`
	Secret         string `json:"secret,omitempty"`
	HasSecret      bool   `json:"has_secret,omitempty"`
}

func serviceOptions(s Service) WirelessOptions {
	if s.Options != nil {
		return *s.Options
	}
	auth := 2
	if s.Security == "wpa-psk" || s.Security == "wpa-enterprise" {
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
	if o.Radius != nil {
		return fmt.Errorf("RADIUS 不在本程序功能范围内")
	}
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
		if x.QueryInterval < 1 || x.QueryInterval > 65535 || x.MaxResponse < 1 || x.MaxResponse > 255 || x.MaxResponse > x.QueryInterval || !hasInt([]int{1, 2, 5, 6, 9, 11, 12, 18, 24, 36, 48, 54}, x.Rate2G) || !hasInt([]int{6, 9, 12, 18, 24, 36, 48, 54}, x.Rate5G) {
			return fmt.Errorf("组播速率或查询周期无效")
		}
	}
	if strings.HasSuffix(s.Security, "enterprise") {
		r := o.Radius
		if r == nil || net.ParseIP(r.IP) == nil || r.Port < 1 || r.Port > 65535 || r.AccountingPort < 0 || r.AccountingPort > 65535 || len(r.Secret) < 1 || len(r.Secret) > 64 {
			return fmt.Errorf("请填写有效的 RADIUS 地址、端口与共享密钥")
		}
	}
	return nil
}
func validateServiceCapability(s Service, ap cweng.APStatus, radio uint8) error {
	for _, c := range ap.Capabilities {
		if c.RadioID != radio {
			continue
		}
		if s.Security == "wpa2-wpa3-psk" && !c.SupportWPA3 {
			return fmt.Errorf("radio %d 不支持 WPA3", radio)
		}
	}
	o := serviceOptions(s)
	if o.VLANPool != 0 && !supportsPool(ap) {
		return fmt.Errorf("AP 不支持 VLAN 池")
	}
	if x := o.Multicast; x != nil {
		if x.ConfigureGlobal && !ap.HasCapability(43) {
			return fmt.Errorf("AP 不支持全局组播配置")
		}
		if (x.Snooping || x.Query) && !ap.HasCapability(43) {
			return fmt.Errorf("AP 不支持按无线服务配置组播")
		}
		if x.ConfigureGlobal && x.ToUnicast && (!ap.HasCapability(99) || ap.SubCapabilities[99]&1 == 0) {
			return fmt.Errorf("AP 不支持组播转单播")
		}
	}
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
func serviceSecurity(s Service) (byte, []byte) {
	o := serviceOptions(s)
	mode := byte(0)
	if s.Security == "wpa2-wpa3-psk" {
		mode = 4
	} else if s.Security != "open" {
		mode = 1
	}
	if strings.HasSuffix(s.Security, "enterprise") {
		mode = 2
	}
	if mode == 0 {
		return 0, nil
	}
	tail := []byte{byte(o.Auth), byte(o.Cipher)}
	tail = binary.BigEndian.AppendUint32(tail, uint32(o.KeyUpdate))
	if mode == 2 {
		r := o.Radius
		ip := net.ParseIP(r.IP)
		for i := 0; i < 3; i++ {
			if v := ip.To4(); v != nil {
				tail = append(tail, 1)
				tail = append(tail, v...)
			} else {
				tail = append(tail, 2)
				tail = append(tail, ip.To16()...)
			}
		}
		tail = binary.BigEndian.AppendUint16(tail, uint16(r.Port))
		tail = binary.BigEndian.AppendUint16(tail, uint16(r.AccountingPort))
		tail = binary.BigEndian.AppendUint16(tail, uint16(r.AccountingPort))
		tail = binary.BigEndian.AppendUint16(tail, uint16(len(r.Secret)))
		return mode, append(tail, []byte(r.Secret)...)
	}
	tail = binary.BigEndian.AppendUint16(tail, uint16(len(s.Passphrase)))
	return mode, append(tail, []byte(s.Passphrase)...)
}
func advancedWLANElements(s Service, radio uint8, ap cweng.APStatus) []capwap.Element {
	if serviceOptions(s).VLANPool != 0 {
		o := serviceOptions(s)
		o.VLAN = 5000 + int(o.VLANPool)
		s.Options = &o
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
		rate := x.Rate2G
		for _, c := range ap.Capabilities {
			if c.RadioID == radio && c.Band == "5 GHz" {
				rate = x.Rate5G
			}
		}
		if x.ConfigureGlobal && ap.HasCapability(43) {
			add(0x70, []byte{boolean(x.GlobalSnooping), boolean(x.DropUnknown), 1, radio, byte(rate >> 8), byte(rate)})

			add(0x72, []byte{byte(x.QueryInterval >> 8), byte(x.QueryInterval), byte(x.MaxResponse)})

			// c9 radio extension: type 0 controls unknown multicast frames.
			if ap.HasCapability(99) && ap.SubCapabilities[99]&1 != 0 {
				add(0xc9, []byte{0, 1, 0, 1, boolean(x.ToUnicast)})
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
	if s.Options != nil {
		o := *s.Options
		s.Options = &o
		if o.Radius != nil {
			r := *o.Radius
			o.Radius = &r
			r.HasSecret = r.Secret != ""
			r.Secret = ""
		}
	}
	return s
}
