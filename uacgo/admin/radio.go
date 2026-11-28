package admin

import (
	"context"
	"encoding/json"
	"fmt"
	"net/http"
	"strconv"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

type RadioSetting struct {
	AP         string         `json:"ap_id"`
	Radio      uint8          `json:"radio_id"`
	Enabled    *bool          `json:"enabled,omitempty"`
	Channel    *int           `json:"channel,omitempty"`
	Bandwidth  *int           `json:"bandwidth,omitempty"`
	Power      *int           `json:"power_dbm,omitempty"`
	PowerLevel *int           `json:"power_level,omitempty"`
	Advanced   *RadioAdvanced `json:"advanced,omitempty"`
}

func radioElements(r RadioSetting) []capwap.Element {
	var out []capwap.Element
	if r.Enabled != nil {
		state := byte(2)
		if *r.Enabled {
			state = 1
		}
		out = append(out, capwap.Element{Type: 0x1f, Value: []byte{r.Radio, state}})
	}
	// Matched V6 baseline frames 66/68 and 112/132. The 8-byte DSSS form
	// leaves optional bandwidth/EDCA extension fields at vendor sentinels.
	if r.Channel != nil {
		out = append(out, capwap.Element{Type: 0x404, Value: []byte{r.Radio, 0, byte(*r.Channel), 2, 0, 0, 0, 0}})
	}
	if r.Power != nil {
		out = append(out, capwap.Element{Type: 0x411, Value: []byte{r.Radio, 0, byte(*r.Power >> 8), byte(*r.Power)}})
	}
	return out
}
func reportingControl(cfg Config, ap string) capwap.PrivStatisticsControl {
	// stats_db_ctl_rssi_update uses the shortest enabled RSSI consumer interval,
	// capped at 120 seconds. The other two statistics streams remain enabled.
	p := capwap.PrivStatisticsControl{A: 1, C: 1, D: 120, E: 120, F: 120}
	s := defaultRoamSettings()
	if cfg.Mobility != nil {
		s = cfg.Mobility.Default
	}
	if cfg.Mobility != nil && s.Statistics {
		p.B = 1
		p.E = uint16(min(120, s.StatisticsInterval))
	}
	return p
}

func (m *Manager) statisticsControl() capwap.PrivStatisticsControl {
	m.mu.Lock()
	defer m.mu.Unlock()
	return reportingControl(m.config, "")
}

func (m *Manager) applyReporting(ctx context.Context, ap cweng.APStatus, cfg Config) {
	// V4/V6 _stats_ctl_pkt_send_cb selects general capability24.
	if !ap.HasCapability(24) {
		return
	}
	key := ap.ID + "/reporting"
	value := reportingControl(cfg, ap.ID).AssembleValue()
	version := configurationKey(value, ap.ConnectedAt)
	m.mu.Lock()
	previous := m.status[key]
	done := m.applied[key] == version && ((previous.State != "failed" && previous.State != "failed_recovered") || time.Since(previous.At) < 30*time.Second)
	m.mu.Unlock()
	if done {
		return
	}
	c, cancel := context.WithTimeout(ctx, 4*time.Second)
	defer cancel()
	// V6 baseline frame 84: statistics enable and three 120-second periods.
	_, err := m.engine.Request(c, ap.ID, 7, []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x55, Value: value}})}})
	state := ApplyStatus{AP: ap.ID, Service: "reporting", State: "acknowledged", At: time.Now()}
	if err != nil {
		state.State = "failed"
		state.Error = err.Error()
	}
	m.mu.Lock()
	m.applied[key] = version
	m.status[key] = state

	m.mu.Unlock()
}
func (m *Manager) reconcileRadio(ctx context.Context, ap cweng.APStatus, r RadioSetting, revision uint64) {
	ctx = m.itemContext(ctx, fmt.Sprintf("radio:%d", r.Radio))
	key := ap.ID + "/radio:" + strconv.Itoa(int(r.Radio))
	version := configurationKey(r, ap.ConnectedAt)
	m.mu.Lock()
	previous := m.status[key]
	done := m.applied[key] == version && ((previous.State != "failed" && previous.State != "failed_recovered") || time.Since(previous.At) < 30*time.Second)
	m.mu.Unlock()
	if done {
		return
	}
	c, cancel := context.WithTimeout(ctx, 20*time.Second)
	defer cancel()
	var cap cweng.RadioCapability
	for _, v := range ap.Capabilities {
		if v.RadioID == r.Radio {
			cap = v
		}
	}
	var err error
	var native nativeRadioResult
	recovered := false
	if err = validateAdvanced(r, ap, cap); err == nil {
		m.dirtyAP(ap.ID)
		native, err = m.tryNativeRadio(c, ap, r, cap)
		if !native.used && err == nil {
			if r.Advanced != nil && (r.Enabled == nil || *r.Enabled) {
				// The vendor cycles the radio before applying advanced parameters.
				off := false
				_, err = m.engine.Request(c, ap.ID, 7, radioElements(RadioSetting{Radio: r.Radio, Enabled: &off}))
				if err == nil {
					err = m.checkpoint(c, ap.ID, struct {
						Phase    string
						Radio    RadioSetting
						Revision uint64
					}{"radio-off", r, revision})
				}
				if err == nil {
					timer := time.NewTimer(time.Second)
					select {
					case <-c.Done():
						err = c.Err()
					case <-timer.C:
					}
					timer.Stop()
				}
				if err == nil {
					on := true
					command := r
					command.Enabled = &on
					err = m.sendRadio(c, ap.ID, advancedRadioElements(command, ap, cap))
				}
				if err != nil {
					on := true
					recoverCtx, recoverCancel := context.WithTimeout(ctx, 8*time.Second)
					_, recoverErr := m.engine.Request(recoverCtx, ap.ID, 7, radioElements(RadioSetting{Radio: r.Radio, Enabled: &on}))
					if recoverErr == nil {
						recoverErr = m.checkpoint(recoverCtx, ap.ID, struct {
							Phase string
							At    time.Time
						}{"radio-recovery", time.Now()})
					}
					if recoverErr != nil {
						err = fmt.Errorf("%w; radio recovery failed: %v", err, recoverErr)
					} else {
						recovered = true
					}
					recoverCancel()
				}
			} else {
				err = m.sendRadio(c, ap.ID, advancedRadioElements(r, ap, cap))
			}
		}
	}

	state := ApplyStatus{AP: ap.ID, Service: "radio:" + strconv.Itoa(int(r.Radio)), State: "acknowledged", Reason: native.reason, At: time.Now()}
	if native.verified && err == nil {
		state.State = "verified"
	}
	if err != nil {
		state.State = "failed"
		if recovered {
			state.State = "failed_recovered"
		}
		state.Error = err.Error()
	}
	m.mu.Lock()
	m.applied[key] = version
	m.status[key] = state
	if err == nil || recovered {
		delete(m.applied, ap.ID+"/rates")
		for _, s := range m.config.Services {
			delete(m.applied, ap.ID+"/"+s.ID)
		}
	}
	m.mu.Unlock()

}

// Keep base radio elements together and acknowledge vendor extensions
// individually. Each 0x25 envelope must contain exactly one private TLV;
// CWParseVendorPayload rejects trailing bytes after that TLV.
func radioBatches(elements []capwap.Element) [][]capwap.Element {
	var base []capwap.Element
	var batches [][]capwap.Element
	for _, el := range elements {
		if el.Type == 0x25 {
			batches = append(batches, []capwap.Element{el})
		} else {
			base = append(base, el)
		}
	}
	if len(base) > 0 {
		batches = append([][]capwap.Element{base}, batches...)
	}
	return batches
}

func (m *Manager) sendRadio(ctx context.Context, id string, elements []capwap.Element) error {
	for _, batch := range radioBatches(elements) {
		if _, err := m.engine.Request(ctx, id, 7, batch); err != nil {
			return err
		}
	}
	return nil
}
func (m *Manager) saveRadioHTTP(w http.ResponseWriter, req *http.Request) {
	var r RadioSetting
	req.Body = http.MaxBytesReader(w, req.Body, 16384)
	d := json.NewDecoder(req.Body)
	d.DisallowUnknownFields()
	if err := d.Decode(&r); err != nil {
		jsonReply(w, 400, map[string]string{"error": "请求格式无效"})
		return
	}
	manualChannel := r.Channel != nil
	manualAdvanced := r.Advanced != nil
	requestedAdvanced := r.Advanced
	manualLinkage := manualChannel || r.Advanced != nil || r.Enabled != nil || r.Bandwidth != nil
	var capability *cweng.RadioCapability
	var selectedAP cweng.APStatus
	for _, ap := range m.APs() {
		if ap.ID == r.AP {
			selectedAP = ap
			for _, c := range ap.Capabilities {
				if c.RadioID == r.Radio {
					copy := c
					capability = &copy
				}
			}
		}
	}
	if capability == nil {
		jsonReply(w, 400, map[string]string{"error": "该 AP 尚未上报对应射频能力"})
		return
	}
	if r.PowerLevel != nil {
		if *r.PowerLevel < 1 || *r.PowerLevel > 10 {
			jsonReply(w, 400, map[string]string{"error": "功率等级为 1–10"})
			return
		}
		p := levelPower(*r.PowerLevel, *capability)
		r.Power = &p
	}

	if r.Power != nil && (*r.Power < capability.MinPower || *r.Power > capability.MaxPower) {
		jsonReply(w, 400, map[string]string{"error": fmt.Sprintf("设备上报的功率范围为 %d–%d dBm", capability.MinPower, capability.MaxPower)})
		return
	}
	if r.Channel == nil && r.Power == nil && r.Enabled == nil && r.Advanced == nil && r.Bandwidth == nil {
		jsonReply(w, 400, map[string]string{"error": "没有需要修改的设置"})
		return
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	next := m.config
	next.Version++
	next.Radios = append([]RadioSetting{}, m.config.Radios...)
	idx := -1
	for i, x := range next.Radios {
		if x.AP == r.AP && x.Radio == r.Radio {
			idx = i
			old := x
			if r.Enabled == nil {
				r.Enabled = old.Enabled
			}
			if r.Channel == nil {
				r.Channel = old.Channel
			}
			if r.Power == nil {
				r.Power = old.Power
				r.PowerLevel = old.PowerLevel
			}
			if r.Advanced == nil {
				r.Advanced = old.Advanced
				if r.Bandwidth == nil {
					r.Bandwidth = old.Bandwidth
				}
			}
			break
		}
	}
	if err := validateAdvanced(r, selectedAP, *capability); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	if manualLinkage {
		r = normalizeLinkageRadio(r, *capability, next, selectedAP)
	}
	if idx < 0 {
		next.Radios = append(next.Radios, r)
	} else {
		next.Radios[idx] = r
	}
	if err := func() error {
		if manualLinkage {
			return planRadioLinkage(&next, selectedAP, r.Radio)
		}
		return nil
	}(); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}

	if err := m.validateConfigForAPs(next); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	if manualAdvanced {
		markManualEDCA(&next, r.AP, r.Radio, requestedAdvanced)
	}
	if err := m.persistConfigLocked(next, managementUser); err != nil {
		jsonReply(w, 500, map[string]string{"error": err.Error()})
		return
	}
	jsonReply(w, 202, map[string]string{"status": "saved"})
}

// Disabling a radio can remove its AP-side VAPs. Preserve assigned WLAN
// slots while disabled; every subsequent radio change invalidates service
// application keys so enabling rebuilds the service before the batch commit.
func radioDisabled(cfg Config, ap string, radio uint8) bool {
	for _, r := range inheritedRadioSettings(cfg, ap) {
		if r.AP == ap && r.Radio == radio && r.Enabled != nil {
			return !*r.Enabled
		}
	}
	return false
}
