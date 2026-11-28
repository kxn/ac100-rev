package admin

import (
	"context"
	"encoding/json"
	"errors"
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
	"time"
	"uacgo/cweng"
)

// Modern DMS APs expose their radio model over the same authenticated TDCP
// channel used by the original AC for NMS. Probe the model before using it;
// older APs continue to receive the independent CAPWAP radio codecs.
func radioModel(b json.RawMessage, radio uint8) (map[string]string, error) {
	var v struct {
		Error    *int `json:"error_code"`
		Wireless struct {
			Rows []map[string]map[string]json.RawMessage `json:"radio_entry"`
		} `json:"wireless"`
	}
	if err := json.Unmarshal(b, &v); err != nil {
		return nil, err
	}
	if v.Error == nil {
		return nil, fmt.Errorf("AP model reply lacks error_code")
	}
	if *v.Error != 0 {
		return nil, modelError{*v.Error}
	}
	for _, row := range v.Wireless.Rows {
		for _, r := range row {
			if nativeString(r, "radio_id") == strconv.Itoa(int(radio)) {
				out := make(map[string]string, len(r))
				for key := range r {
					out[key] = nativeString(r, key)
				}
				return out, nil
			}
		}
	}
	return nil, errNativeModelUnavailable
}
func (m *Manager) readRadio(ctx context.Context, id string, radio uint8) (map[string]string, error) {
	b, err := m.engine.RequestJSON(ctx, id, json.RawMessage(`{"method":"get","wireless":{"table":"radio_entry"}}`))
	if err != nil {
		return nil, err
	}
	return radioModel(b, radio)
}
func nativeParameters(r RadioSetting, c cweng.RadioCapability, current map[string]string, ap cweng.APStatus) (map[string]string, error) {
	p := map[string]string{}
	put := func(k string, v int) { p[k] = strconv.Itoa(v) }
	flag := func(k string, v bool) { put(k, int(boolean(v))) }
	onoff := func(k string, v bool) {
		p[k] = "off"
		if v {
			p[k] = "on"
		}
	}
	if r.Enabled != nil {
		onoff("enable", *r.Enabled)
	}
	if r.Channel != nil {
		put("channel", *r.Channel)
	}
	if r.Power != nil {
		level := 1
		if c.MaxPower > c.MinPower {
			level = 1 + int(math.Round(float64(*r.Power-c.MinPower)*9/float64(c.MaxPower-c.MinPower)))
		}
		put("power", level)
	}
	if a := r.Advanced; a != nil {
		// ac_mode_convert_to_ap @AP DMS 0xc2b04, bandwidth conversion @0xc2b28.
		modes := []int{5, 0, 1, 3, 6, 2, 4, 7, 12, 8, 9, 10, 11, 12}
		bw := []int{1, 2, 0, 3, 8, 5, 6, 7}
		if a.Mode < 0 || a.Mode >= len(modes) || a.Bandwidth < 0 || a.Bandwidth >= len(bw) {
			return nil, fmt.Errorf("radio model conversion out of range")
		}
		if ap.HasCapability(70) && (radioControlFeatures(c)["uplink_mumimo"] || radioControlFeatures(c)["uplink_ofdma"]) {
			// Shared native downlink keys cannot deliver independent uplink
			// controls, including an explicit disable. Send the complete CAPWAP
			// extension instead; equality of requested directions proves nothing.
			return nil, fmt.Errorf("uplink_mumimo/uplink_ofdma require CAPWAP extensions")
		}
		if a.DCS != nil || a.Reject != nil || a.EDCA != nil || radioControlFeatures(c)["enable_6g"] || a.Enable6G || a.PSC6G || a.DownlinkMUMIMO != a.UplinkMUMIMO || a.DownlinkOFDMA != a.UplinkOFDMA {
			return nil, fmt.Errorf("radio requires CAPWAP extensions")
		}
		put("mode", modes[a.Mode])
		put("bandwidth", bw[a.Bandwidth])
		put("radio_max_sta", a.MaxClients)
		put("antenna", a.Antenna)
		put("beacon_intv", a.Beacon)
		put("dtim_period", a.DTIM)
		put("frag_threshold", a.Fragmentation)
		put("rts_threshold", a.RTS)
		for k, v := range map[string]bool{"wmm": a.WMM, "short_gi": a.ShortGI, "brd_probe": a.BroadcastProbe} {
			flag(k, v)
		}
		if ap.HasCapability(1) {
			flag("rssi_weak_restrict", a.RSSIRestrict)
			flag("rssi_weak_kick", a.RSSIKick)
			put("rssi_weak_restrict_val", a.RSSIThreshold)
			put("rssi_weak_kick_val", a.RSSIKickThreshold)
		}
		if ap.HasCapability(10) {
			flag("airtime", a.Airtime)
		}
		if ap.HasCapability(70) {
			onoff("vhtmubfer", a.DownlinkMUMIMO)
			onoff("ofdma", a.DownlinkOFDMA)
			onoff("twt", a.TWT)
			// Match the independent CAPWAP capability70 tail, including reset0.
			put("gi_mode", max(0, a.GI))
		}
		if a.ManagementRate != 1 {
			put("mgnt_frame_rate", a.ManagementRate)
		}
	}
	var missing []string
	for k := range p {
		if _, ok := current[k]; !ok {
			missing = append(missing, k)
		}
	}
	if len(missing) > 0 {
		sort.Strings(missing)
		return nil, fmt.Errorf("AP radio model lacks %s", strings.Join(missing, ", "))
	}
	return p, nil
}

// Delivery and readback coverage are separate: a successful write must not
// become a failure (or a verified configuration) merely because a model omits
// a field on readback. Missing fields never imply a false/off value.
type nativeRadioResult struct {
	used     bool
	verified bool
	reason   string
}

func (m *Manager) tryNativeRadio(ctx context.Context, ap cweng.APStatus, r RadioSetting, c cweng.RadioCapability) (nativeRadioResult, error) {
	// The DMS model is selected by TDCP capability and the fields it actually
	// exposes, never by which model/hardware happened to be tested in the lab.
	// Legacy devices retain the independent CAPWAP radio codecs.
	if !ap.SupportsTDCP() {
		return nativeRadioResult{}, nil
	}
	probe, cancel := context.WithTimeout(ctx, 3*time.Second)
	current, err := m.readRadio(probe, ap.ID, r.Radio)
	cancel()
	if err != nil {
		if errors.Is(err, errNativeModelUnavailable) {
			return nativeRadioResult{reason: "AP 未提供原生射频回读；使用 CAPWAP 下发，尚未验证"}, nil
		}
		if unsupportedModel(err) {
			return nativeRadioResult{reason: "AP 不支持原生射频模型；使用 CAPWAP 下发，尚未回读验证"}, nil
		}
		return nativeRadioResult{used: true}, err
	}
	p, err := nativeParameters(r, c, current, ap)
	if err != nil {
		return nativeRadioResult{reason: "使用完整 CAPWAP 射频配置下发，尚未回读验证：" + err.Error()}, nil
	}
	body, _ := json.Marshal(map[string]any{"method": "set", "wireless": map[string]any{"table": "radio_entry", "filter": []map[string]string{{"radio_id": strconv.Itoa(int(r.Radio))}}, "para": p}})
	b, err := m.engine.RequestJSON(ctx, ap.ID, body)
	if err != nil {
		return nativeRadioResult{used: true}, err
	}
	if err = modelResult(b); err != nil {
		return nativeRadioResult{used: true}, err
	}
	actual, err := m.readRadio(ctx, ap.ID, r.Radio)
	if err != nil {
		if errors.Is(err, errNativeModelUnavailable) {
			return nativeRadioResult{used: true, reason: "配置已下发，AP 尚未提供射频回读，尚未验证"}, nil
		}
		return nativeRadioResult{used: true}, err
	}
	missing, err := compareNativeParameters(p, actual)
	return nativeRadioResult{used: true, verified: err == nil && len(missing) == 0, reason: nativeReadbackReason(missing)}, err
}
