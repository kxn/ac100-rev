package admin

import (
	"encoding/binary"
	"fmt"
	"math"
	"uacgo/capwap"
	"uacgo/cweng"
)

// RadioAdvanced follows the retained rf_mngr fields in the V6 controller.
// The base values are the vendor's defaults, not guesses about the AP's state.
type RadioAdvanced struct {
	DCS               *DCSConfig        `json:"dcs,omitempty"`
	Reject            *AdmissionControl `json:"admission,omitempty"`
	Mode              int               `json:"mode"`
	Bandwidth         int               `json:"bandwidth"`
	MaxClients        int               `json:"max_clients"`
	Antenna           int               `json:"antenna"`
	WMM               bool              `json:"wmm"`
	ShortGI           bool              `json:"short_gi"`
	BroadcastProbe    bool              `json:"broadcast_probe"`
	Fragmentation     int               `json:"fragmentation"`
	RTS               int               `json:"rts"`
	Beacon            int               `json:"beacon_interval"`
	DTIM              int               `json:"dtim"`
	ManagementRate    int               `json:"management_rate"`
	RSSIRestrict      bool              `json:"rssi_restrict"`
	RSSIThreshold     int               `json:"rssi_threshold"`
	RSSIKick          bool              `json:"rssi_kick"`
	RSSIKickThreshold int               `json:"rssi_kick_threshold"`
	Airtime           bool              `json:"airtime"`
	DownlinkMUMIMO    bool              `json:"downlink_mumimo"`
	UplinkMUMIMO      bool              `json:"uplink_mumimo"`
	DownlinkOFDMA     bool              `json:"downlink_ofdma"`
	UplinkOFDMA       bool              `json:"uplink_ofdma"`
	TWT               bool              `json:"twt"`
	GI                int               `json:"gi_mode"`
	Enable6G          bool              `json:"enable_6g"`
	PSC6G             bool              `json:"psc_6g"`
	EDCA              *EDCAConfig       `json:"edca,omitempty"`
}
type DCSConfig struct {
	Mode      int  `json:"mode"`
	Online    bool `json:"online"`
	Interval  int  `json:"interval"`
	Occupancy int  `json:"occupancy"`
	Tolerance int  `json:"tolerance"`
	Reselect  bool `json:"reselect"`
}
type AdmissionControl struct {
	Enabled    bool `json:"enabled"`
	Threshold  int  `json:"threshold"`
	Difference int  `json:"difference"`
}
type EDCAConfig struct {
	Preset  *uint8      `json:"preset,omitempty"`
	Mode    *int        `json:"mode,omitempty"`
	Enabled bool        `json:"enabled"`
	Queues  []EDCAQueue `json:"queues"` // AP VO/VI/BE/BK, STA VO/VI/BE/BK
}
type EDCAQueue = capwap.EDCAQueue

func boolean(v bool) byte {
	if v {
		return 1
	}
	return 0
}
func hasInt(xs []int, v int) bool {
	for _, x := range xs {
		if x == v {
			return true
		}
	}
	return false
}
func defaultRadioAdvanced(c cweng.RadioCapability) RadioAdvanced {
	mode := 6
	if c.Band == "5 GHz" {
		mode = 7
	}
	if len(c.Modes) > 0 {
		mode = c.Modes[len(c.Modes)-1]
	}
	bandwidth := 2
	if !hasInt(c.Bandwidths, bandwidth) && len(c.Bandwidths) > 0 {
		bandwidth = c.Bandwidths[0]
	}
	return RadioAdvanced{Mode: mode, Bandwidth: bandwidth, MaxClients: c.MaxClients, WMM: true, ShortGI: true, BroadcastProbe: true, Fragmentation: 2346, RTS: 2346, Beacon: 100, DTIM: 1, ManagementRate: 1, DownlinkMUMIMO: c.Features["downlink_mumimo"], UplinkMUMIMO: c.Features["uplink_mumimo"], GI: -1}
}
func radioNeedsWMM(mode int) bool { return !hasInt([]int{0, 1, 2, 5}, mode) }
func radioModeBandwidth(mode, bandwidth int) bool {
	if hasInt([]int{0, 1, 2, 5}, mode) {
		return bandwidth == 0 || bandwidth == 2
	}
	if hasInt([]int{3, 4, 6, 7, 10, 12}, mode) {
		return bandwidth >= 0 && bandwidth <= 2
	}
	return true
}
func validateAdvanced(r RadioSetting, ap cweng.APStatus, c cweng.RadioCapability) error {
	if r.Channel != nil && *r.Channel != 0 && !hasInt(c.Channels, *r.Channel) {
		return fmt.Errorf("AP 未声明支持此信道")
	}
	a := r.Advanced
	if a == nil {
		return nil
	}
	if !hasInt(c.Modes, a.Mode) || !hasInt(c.Bandwidths, a.Bandwidth) {
		return fmt.Errorf("无线模式或带宽超出 AP 能力")
	}
	if !radioModeBandwidth(a.Mode, a.Bandwidth) {
		return fmt.Errorf("此无线模式不支持所选带宽")
	}
	if radioNeedsWMM(a.Mode) && !a.WMM {
		return fmt.Errorf("802.11n/ac/ax/be 模式必须启用 WMM")
	}
	if r.Channel != nil && ((*r.Channel == 165 && a.Bandwidth != 0) || (*r.Channel >= 149 && a.Bandwidth == 5)) {
		return fmt.Errorf("此信道与带宽组合不受支持")
	}
	// Original rdmngr_public.check_antenna accepts only RD_ANTENNA=0.
	// Values1/2 were invented by the early Go editor, not AP antenna choices.
	if a.MaxClients < 1 || a.MaxClients > c.MaxClients || a.Antenna != 0 {
		return fmt.Errorf("客户端上限或天线设置无效")
	}
	if a.Fragmentation < 256 || a.Fragmentation > 2346 || a.RTS < 1 || a.RTS > 2346 || a.Beacon < 40 || a.Beacon > 1000 || a.DTIM < 1 || a.DTIM > 255 {
		return fmt.Errorf("分片、RTS、Beacon 或 DTIM 超出范围")
	}
	if !hasInt([]int{1, 2, 11, 12, 22, 24, 48}, a.ManagementRate) {
		return fmt.Errorf("管理帧速率无效")
	}
	if a.ManagementRate != 1 && !ap.HasCapability(57) {
		return fmt.Errorf("AP 不支持管理帧速率配置")
	}
	if a.ManagementRate != 1 && c.Band == "5 GHz" && !hasInt([]int{12, 24, 48}, a.ManagementRate) {
		return fmt.Errorf("5 GHz 管理帧速率仅支持 6、12、24 Mbps")
	}
	if a.ManagementRate != 1 && c.Band == "2.4 GHz" && !hasInt([]int{2, 11, 12, 22, 48}, a.ManagementRate) {
		return fmt.Errorf("2.4 GHz 管理帧速率不受支持")
	}
	if (a.RSSIRestrict || a.RSSIKick) && (!ap.HasCapability(1) || a.RSSIThreshold > 0 || a.RSSIThreshold < -100 || a.RSSIKickThreshold > 0 || a.RSSIKickThreshold < -100) {
		return fmt.Errorf("RSSI 设置无效或设备不支持")
	}
	if a.Airtime && !ap.HasCapability(10) {
		return fmt.Errorf("AP 不支持公平调度")
	}
	for name, enabled := range map[string]bool{"downlink_mumimo": a.DownlinkMUMIMO, "uplink_mumimo": a.UplinkMUMIMO, "downlink_ofdma": a.DownlinkOFDMA, "uplink_ofdma": a.UplinkOFDMA, "twt": a.TWT, "enable_6g": a.Enable6G} {
		if enabled && (!ap.HasCapability(70) || !c.Features[name]) {
			return fmt.Errorf("AP 不支持 %s", name)
		}
	}
	if a.GI < -1 || a.GI > 2 || a.PSC6G && !a.Enable6G {
		return fmt.Errorf("GI 或 6 GHz 设置无效")
	}
	if d := a.DCS; d != nil {
		if !ap.HasCapability(9) {
			return fmt.Errorf("AP 不支持动态信道优化")
		}
		if d.Mode < 0 || d.Mode > 2 || d.Interval < 3 || d.Interval > 180 || d.Occupancy < 0 || d.Occupancy > 100 || d.Tolerance < 0 || d.Tolerance > 100 {
			return fmt.Errorf("动态信道优化参数无效")
		}
	}
	if x := a.Reject; x != nil {
		if !ap.HasCapability(21) {
			return fmt.Errorf("AP 不支持双频接入引导")
		}
		if x.Threshold < -100 || x.Threshold > 0 || x.Difference < 0 || x.Difference > 100 {
			return fmt.Errorf("双频接入引导门限无效")
		}
	}
	if a.EDCA != nil {
		if !ap.HasCapability(61) {
			return fmt.Errorf("AP 不支持 EDCA 配置")
		}
		if a.EDCA.Mode != nil && (*a.EDCA.Mode < 0 || *a.EDCA.Mode > 1 || ap.SubCapabilities[61]&2 == 0) {
			return fmt.Errorf("EDCA 模式无效或 AP 不支持此设置")
		}
		resolved, err := resolveEDCA(*a.EDCA, ap, c)
		if err != nil {
			return err
		}
		if len(resolved.Queues) != 8 {
			return fmt.Errorf("EDCA 需要八个队列")
		}
		for _, q := range resolved.Queues {
			if q.AIFS < 1 || q.AIFS > 255 || q.CWMin < 0 || q.CWMin > 15 || q.CWMax < q.CWMin || q.CWMax > 15 || q.TXOP < 0 || q.TXOP > 65535 {
				return fmt.Errorf("EDCA 队列参数无效")
			}
		}
	}
	return nil
}
func advancedRadioElements(r RadioSetting, ap cweng.APStatus, c cweng.RadioCapability) []capwap.Element {
	out := radioElements(r)
	a := r.Advanced
	if a == nil {
		return out
	}
	priv := func(typ uint16, b []byte) {
		out = append(out, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: typ, Value: b}})})
	}
	if d := a.DCS; d != nil {
		channel := 0
		if r.Channel != nil {
			channel = *r.Channel
		}
		b := []byte{r.Radio, 0, byte(channel), 2, 0, 0, 0, 0, boolean(d.Mode == 0), boolean(d.Online)}
		b = binary.BigEndian.AppendUint16(b, uint16(d.Interval))
		b = binary.BigEndian.AppendUint16(b, uint16(d.Occupancy))
		b = binary.BigEndian.AppendUint16(b, 100)
		b = binary.BigEndian.AppendUint16(b, uint16(d.Tolerance))
		b = append(b, boolean(d.Reselect))
		replaced := false
		for i, el := range out {
			if el.Type == 0x404 {
				out[i].Value = b
				replaced = true
			}
		}
		if !replaced {
			out = append(out, capwap.Element{Type: 0x404, Value: b})
		}
	}
	// IEEE 802.11 MAC Operation and Radio Configuration, V6 rdmngr_wtp_pkt_send.
	mac := []byte{r.Radio, 0}
	mac = binary.BigEndian.AppendUint16(mac, uint16(a.RTS))
	mac = append(mac, 0, 0)
	mac = binary.BigEndian.AppendUint16(mac, uint16(a.Fragmentation))
	mac = append(mac, make([]byte, 8)...)
	out = append(out, capwap.Element{Type: 0x406, Value: mac})
	cfg := []byte{r.Radio, 1, 16, byte(a.DTIM), 0, 0, 0, 0, 0, 0}
	cfg = binary.BigEndian.AppendUint16(cfg, uint16(a.Beacon))
	cfg = append(cfg, 'C', 'N', ' ', 0)
	out = append(out, capwap.Element{Type: 0x416, Value: cfg})
	adv := capwap.PrivAdvRdPara{RadioID: r.Radio, Byte15: 0xff}
	adv.Head[0] = byte(a.Mode)
	adv.Head[1] = byte(a.Bandwidth)
	adv.Head[2] = boolean(a.WMM)
	binary.BigEndian.PutUint16(adv.Head[3:5], uint16(a.MaxClients))
	adv.Head[5] = byte(a.Antenna)
	adv.Head[6] = boolean(a.ShortGI)
	adv.Head[7] = boolean(a.BroadcastProbe)
	adv.Head[13] = 10
	if ap.HasCapability(1) {
		adv.Extra4 = []byte{boolean(a.RSSIRestrict), byte(a.RSSIThreshold), boolean(a.RSSIKick), byte(a.RSSIKickThreshold)}
	}
	if ap.HasCapability(10) {
		adv.HasByte15 = true
		adv.Byte15 = boolean(a.Airtime)
	}
	if ap.HasCapability(70) {
		adv.Tail6 = make([]byte, 6)
		for i, v := range []bool{a.DownlinkMUMIMO, a.UplinkMUMIMO, a.DownlinkOFDMA, a.UplinkOFDMA, a.TWT} {
			if v {
				adv.Tail6[0] |= 1 << i
			}
		}
		if a.GI > 0 {
			adv.Tail6[0] |= byte(a.GI) << 5
		}
		if a.Enable6G {
			adv.Tail6[0] |= 128
		}
		adv.Tail6[1] = boolean(a.PSC6G)
	}
	priv(8, adv.AssembleValue())
	priv(0x0a, legacyRateValue(defaultRatePolicy(), r.Radio))
	if c.SupportAX {
		priv(0xa0, mcsRateValue(defaultRatePolicy().AX, r.Radio))
	}
	if ap.HasCapability(57) && a.ManagementRate != 1 {
		priv(0x8e, []byte{r.Radio, 0, 1, 0, 0, 0, 0, byte(a.ManagementRate)})
	}
	if x := a.Reject; x != nil {
		priv(0x4c, (&capwap.PrivWlanRSSIOrient{W: uint32(int32(x.Threshold)), U16: uint16(r.Radio), A: boolean(x.Enabled), B: byte(x.Difference)}).AssembleValue())
	}
	if a.EDCA != nil {
		edca, _ := resolveEDCA(*a.EDCA, ap, c)
		b := []byte{r.Radio, boolean(a.EDCA.Enabled)}
		for _, q := range edca.Queues {
			b = append(b, byte(q.AIFS), byte(q.CWMin), byte(q.CWMax))
			b = binary.BigEndian.AppendUint16(b, uint16(q.TXOP))
		}
		priv(0x92, b)
		if a.EDCA.Mode != nil {
			priv(0xcf, []byte{r.Radio, byte(*a.EDCA.Mode)})
		}
	}
	return out
}
func levelPower(level int, c cweng.RadioCapability) int {
	return c.MinPower + int(math.Round(float64(c.MaxPower-c.MinPower)*float64(level-1)/9))
}

// Resolve scenes from this AP's model-specific 0xce report. Other APs may
// advertise different values under the same scene name.
func resolveEDCA(e EDCAConfig, ap cweng.APStatus, c cweng.RadioCapability) (EDCAConfig, error) {
	if e.Preset == nil {
		return e, nil
	}
	if ap.SubCapabilities[61]&1 == 0 || ap.EDCAPresets == nil {
		return e, fmt.Errorf("AP 未上报 EDCA 预设场景")
	}
	band := uint8(1)
	if c.Band == "5 GHz" {
		band = 2
	}
	if c.Band == "6 GHz" {
		band = 3
	}
	for _, s := range ap.EDCAPresets.Scenes {
		if s.ID == *e.Preset {
			for _, b := range s.Bands {
				if b.Band == band {
					e.Queues = append([]EDCAQueue{}, b.Queues...)
					return e, nil
				}
			}
		}
	}
	return e, fmt.Errorf("AP 未声明此频段的 EDCA 场景")
}
