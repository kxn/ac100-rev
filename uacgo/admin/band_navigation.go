package admin

import (
	"context"
	"encoding/json"
	"errors"
	"fmt"
	"net/http"
	"strconv"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

// BandNavigation is the original AC's global 5 GHz preference policy, distinct
// from radio RSSI-orientation 0x4c and from multi-AP roaming.
type BandNavigation struct {
	Enabled     bool `json:"enabled"`
	Threshold5G int  `json:"threshold_5g"`
	Difference  int  `json:"difference"`
	MaxFailures int  `json:"max_failures"`
}

func (b BandNavigation) validate() error {
	if b.Threshold5G < 2 || b.Threshold5G > 40 || b.Difference < 1 || b.Difference > 8 || b.MaxFailures < 0 || b.MaxFailures > 100 {
		return fmt.Errorf("5 GHz 客户端门限为 2–40，差值为 1–8，最大失败次数为 0–100")
	}
	return nil
}
func (b BandNavigation) element() capwap.Element {
	return capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x3a, Value: []byte{boolean(b.Enabled), byte(b.Threshold5G), byte(b.Difference), byte(b.MaxFailures)}}})}
}
func (m *Manager) readBandNavigation(ctx context.Context, id string) (json.RawMessage, error) {
	return m.engine.RequestJSON(ctx, id, json.RawMessage(`{"method":"get","apmng_band_navigation":{"name":"settings"}}`))
}
func bandModel(b json.RawMessage) (map[string]string, error) {
	var v struct {
		Error  *int `json:"error_code"`
		Module struct {
			Settings map[string]string `json:"settings"`
		} `json:"apmng_band_navigation"`
	}
	if err := json.Unmarshal(b, &v); err != nil {
		return nil, err
	}
	if v.Error == nil {
		return nil, fmt.Errorf("AP 频段引导回复缺少 error_code")
	}
	if *v.Error != 0 {
		return nil, modelUnavailable{*v.Error}
	}
	if v.Module.Settings == nil {
		return nil, fmt.Errorf("AP 未提供频段引导配置回读")
	}
	return v.Module.Settings, nil
}
func (m *Manager) applyBandNavigation(ctx context.Context, ap cweng.APStatus, b *BandNavigation) {
	if b == nil || !ap.HasCapability(3) {
		return
	}
	key := ap.ID + "/band-navigation"
	version := configurationKey(b, ap.ConnectedAt)
	m.mu.Lock()
	done := m.applied[key] == version && (m.status[key].State != "failed" || time.Since(m.status[key].At) < 30*time.Second)
	m.mu.Unlock()
	if done {
		return
	}
	c, cancel := context.WithTimeout(ctx, 12*time.Second)
	defer cancel()
	enabled := b.Enabled
	state := ApplyStatus{AP: ap.ID, Service: "band-navigation", State: "acknowledged", At: time.Now(), EffectiveEnabled: &enabled}
	var raw json.RawMessage
	var probeErr error
	var current map[string]string
	var modelErr error = modelUnavailable{-1}
	if ap.HasCapability(70) {
		raw, probeErr = m.readBandNavigation(c, ap.ID)
		if probeErr == nil {
			current, modelErr = bandModel(raw)
		}
	}
	var err error
	if probeErr == nil && modelErr == nil && current["enable"] != "" {
		enabled := "off"
		if b.Enabled {
			enabled = "on"
		}
		para := map[string]string{"enable": enabled, "5g_threshold": strconv.Itoa(b.Threshold5G), "dif_threshold": strconv.Itoa(b.Difference), "max_fail_num": strconv.Itoa(b.MaxFailures)}
		body, _ := json.Marshal(map[string]any{"method": "set", "apmng_band_navigation": map[string]any{"settings": para}})
		var reply json.RawMessage
		reply, err = m.engine.RequestJSON(c, ap.ID, body)
		if err == nil {
			err = modelResult(reply)
		}
		if err == nil {
			raw, err = m.readBandNavigation(c, ap.ID)
			if err == nil {
				var actual map[string]string
				actual, err = bandModel(raw)
				if err == nil {
					for k, v := range para {
						if actual[k] != v {
							err = fmt.Errorf("频段引导 %s 回读不一致", k)
							break
						}
					}
				}
			}
		}
		if err == nil {
			state.State = "verified"
		}
	} else if probeErr != nil {
		err = probeErr
	} else {
		// Only an explicit unsupported-model response permits the legacy path.
		var unavailable modelUnavailable
		if !errors.As(modelErr, &unavailable) {
			err = modelErr
		} else {
			_, err = m.engine.Request(c, ap.ID, 7, []capwap.Element{b.element()})
		}
	}
	if err != nil {
		state.State = "failed"
		state.Error = err.Error()
	}
	state.At = time.Now()
	m.mu.Lock()
	m.status[key] = state
	m.applied[key] = version
	m.mu.Unlock()
}
func (m *Manager) bandNavigationHTTP(w http.ResponseWriter, r *http.Request) {
	var b BandNavigation
	r.Body = http.MaxBytesReader(w, r.Body, 2048)
	d := json.NewDecoder(r.Body)
	d.DisallowUnknownFields()
	if err := d.Decode(&b); err != nil {
		jsonReply(w, 400, map[string]string{"error": "请求格式无效"})
		return
	}
	if err := b.validate(); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	next := m.config
	next.Version++
	next.BandNavigation = &b
	if err := m.persistConfigLocked(next, managementUser); err != nil {
		jsonReply(w, 500, map[string]string{"error": err.Error()})
		return
	}
	jsonReply(w, 202, map[string]string{"status": "saved"})
}
