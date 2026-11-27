package admin

import (
	"context"
	"encoding/json"
	"fmt"
	"math"
	"strconv"
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
			Rows []map[string]map[string]string `json:"radio_entry"`
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
			if r["radio_id"] == strconv.Itoa(int(radio)) {
				return r, nil
			}
		}
	}
	return nil, fmt.Errorf("AP radio model unavailable")
}
func (m *Manager) readRadio(ctx context.Context, id string, radio uint8) (map[string]string, error) {
	b, err := m.engine.RequestJSON(ctx, id, json.RawMessage(`{"method":"get","wireless":{"table":"radio_entry"}}`))
	if err != nil {
		return nil, err
	}
	return radioModel(b, radio)
}
func nativeParameters(r RadioSetting, c cweng.RadioCapability, current map[string]string) (map[string]string, error) {
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
		if a.DCS != nil || a.Reject != nil || a.EDCA != nil || a.Enable6G || a.PSC6G || a.DownlinkMUMIMO != a.UplinkMUMIMO || a.DownlinkOFDMA != a.UplinkOFDMA {
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
		for k, v := range map[string]bool{"wmm": a.WMM, "short_gi": a.ShortGI, "brd_probe": a.BroadcastProbe, "rssi_weak_restrict": a.RSSIRestrict, "rssi_weak_kick": a.RSSIKick, "airtime": a.Airtime} {
			flag(k, v)
		}
		put("rssi_weak_restrict_val", a.RSSIThreshold)
		put("rssi_weak_kick_val", a.RSSIKickThreshold)
		onoff("vhtmubfer", a.DownlinkMUMIMO)
		onoff("ofdma", a.DownlinkOFDMA)
		onoff("twt", a.TWT)
		// The CAPWAP default/automatic selector encodes zero as well. Omitting
		// it left a previous manual GI active while reporting the reset verified.
		put("gi_mode", max(0, a.GI))
		if a.ManagementRate != 1 {
			put("mgnt_frame_rate", a.ManagementRate)
		}
	}
	for k := range p {
		if _, ok := current[k]; !ok {
			return nil, fmt.Errorf("AP radio model lacks %s", k)
		}
	}
	return p, nil
}
func (m *Manager) tryNativeRadio(ctx context.Context, ap cweng.APStatus, r RadioSetting, c cweng.RadioCapability) (bool, error) {
	// Enum conversions are established for this model/hardware. A JSON table
	// on another model does not prove that it uses the same enum ABI.
	if !ap.HasCapability(70) || ap.Model != "TL-7AP5100HC-PoE/DC易展版" || ap.HardwareVersion != "1.0" {
		return false, nil
	}
	probe, cancel := context.WithTimeout(ctx, 3*time.Second)
	current, err := m.readRadio(probe, ap.ID, r.Radio)
	cancel()
	if err != nil {
		if unsupportedModel(err) {
			return false, nil
		}
		return true, err
	}
	p, err := nativeParameters(r, c, current)
	if err != nil {
		return false, nil
	}
	body, _ := json.Marshal(map[string]any{"method": "set", "wireless": map[string]any{"table": "radio_entry", "filter": []map[string]string{{"radio_id": strconv.Itoa(int(r.Radio))}}, "para": p}})
	b, err := m.engine.RequestJSON(ctx, ap.ID, body)
	if err != nil {
		return true, err
	}
	if err = modelResult(b); err != nil {
		return true, err
	}
	actual, err := m.readRadio(ctx, ap.ID, r.Radio)
	if err != nil {
		return true, err
	}
	for k, v := range p {
		if actual[k] != v {
			return true, fmt.Errorf("AP radio readback %s=%s, requested %s", k, actual[k], v)
		}
	}
	return true, nil
}
