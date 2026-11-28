package admin

import (
	"context"
	"encoding/binary"
	"encoding/json"
	"strings"
	"sync/atomic"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func nativeAXCapabilities() cweng.APStatus {
	return cweng.APStatus{GeneralCapabilities: []uint32{1<<1 | 1<<10, 1 << 25, 1 << 6}}
}

func TestNativeRadioEnumConversionAndReadback(t *testing.T) {
	b := []byte(`{"error_code":0,"wireless":{"radio_entry":[{"radio_entry_1":{"radio_id":"1","mode":"11","bandwidth":"0","enable":"off","radio_max_sta":"256"}}]}}`)
	current, err := radioModel(b, 1)
	if err != nil {
		t.Fatal(err)
	}
	on := true
	c := cweng.RadioCapability{MinPower: 3, MaxPower: 24}
	p, err := nativeParameters(RadioSetting{Radio: 1, Enabled: &on}, c, current, nativeAXCapabilities())
	if err != nil || p["enable"] != "on" {
		t.Fatal(p, err)
	}
	a := RadioAdvanced{Mode: 10, Bandwidth: 0, MaxClients: 64, ManagementRate: 1, Beacon: 200, DTIM: 2}
	_, err = nativeParameters(RadioSetting{Radio: 1, Advanced: &a}, c, current, nativeAXCapabilities())
	if err == nil {
		t.Fatal("accepted incomplete AP model")
	}
	for _, key := range []string{"antenna", "beacon_intv", "dtim_period", "frag_threshold", "rts_threshold", "wmm", "short_gi", "brd_probe", "rssi_weak_restrict", "rssi_weak_kick", "airtime", "rssi_weak_restrict_val", "rssi_weak_kick_val", "vhtmubfer", "ofdma", "twt", "gi_mode"} {
		current[key] = "0"
	}
	p, err = nativeParameters(RadioSetting{Radio: 1, Advanced: &a}, c, current, nativeAXCapabilities())
	if err != nil || p["mode"] != "9" || p["bandwidth"] != "1" || p["radio_max_sta"] != "64" {
		t.Fatal(p, err)
	}
	a.EDCA = &EDCAConfig{}
	if _, err = nativeParameters(RadioSetting{Advanced: &a}, c, current, nativeAXCapabilities()); err == nil {
		t.Fatal("silently omitted EDCA")
	}
}

func TestNativeModelResponsesRequireExplicitSuccess(t *testing.T) {
	for _, b := range []string{`{}`, `null`, `{"error_code":null}`, `{"error_code":"0"}`, `{"error_code":1}`} {
		if modelResult([]byte(b)) == nil {
			t.Fatal("accepted ambiguous success", b)
		}
	}
	if modelResult([]byte(`{"error_code":0}`)) != nil {
		t.Fatal("rejected success")
	}
	if _, err := radioModel([]byte(`{"wireless":{"radio_entry":[{"r":{"radio_id":"1"}}]}}`), 1); err == nil {
		t.Fatal("missing result accepted")
	}
	if _, err := bandModel([]byte(`{"apmng_band_navigation":{"settings":{"enable":"on"}}}`)); err == nil {
		t.Fatal("missing result accepted")
	}
}

func TestNativeAutomaticGIClearsPreviousManualValue(t *testing.T) {
	c := cweng.RadioCapability{RadioID: 1, MaxClients: 64, Modes: []int{6}, Bandwidths: []int{0}}
	a := defaultRadioAdvanced(c)
	a.GI = -1
	current := map[string]string{}
	for _, k := range []string{"mode", "bandwidth", "radio_max_sta", "antenna", "beacon_intv", "dtim_period", "frag_threshold", "rts_threshold", "wmm", "short_gi", "brd_probe", "rssi_weak_restrict", "rssi_weak_kick", "airtime", "rssi_weak_restrict_val", "rssi_weak_kick_val", "vhtmubfer", "ofdma", "twt", "gi_mode"} {
		current[k] = "2"
	}
	p, err := nativeParameters(RadioSetting{Radio: 1, Advanced: &a}, c, current, nativeAXCapabilities())
	if err != nil || p["gi_mode"] != "0" {
		t.Fatal(p, err)
	}
}

// Exercise the real TDCP request/ACK/asynchronous reply path. The callback is
// installed before the controller sends a command and runs on the fake AP.
func nativeModelAP(t *testing.T, reply func(json.RawMessage) json.RawMessage) (*Manager, *deferredAP, cweng.APStatus) {
	t.Helper()
	m, e := testController(t)
	e.RegisterRPCHandlers()
	f, ap := newDeferredAP(t, e, func(p *capwap.ParsedPacket) {
		bits := binary.BigEndian.AppendUint32(nil, 1<<3)
		bits = binary.BigEndian.AppendUint32(bits, 1<<17)
		p.Elements = append(p.Elements, capwap.Element{Type: 0x32, Value: bits})
	})
	eventSequence := uint8(80)
	f.mu.Lock()
	f.onCommand = func(packet *capwap.ParsedPacket) {
		for _, el := range packet.Elements {
			if el.Type != 0x25 || len(el.Value) < 19 || binary.BigEndian.Uint16(el.Value[6:]) != 0x83 {
				continue
			}
			b := reply(json.RawMessage(el.Value[19:]))
			if b == nil {
				continue
			}
			v := binary.BigEndian.AppendUint32(nil, binary.BigEndian.Uint32(el.Value[10:]))
			v = binary.BigEndian.AppendUint32(v, uint32(len(b)))
			v = append(v, 0)
			v = append(v, b...)
			p, _ := capwap.NewParsedPacket(9)
			p.Control.SeqNum = eventSequence
			eventSequence++
			p.Elements = []capwap.Element{privateSetting(0x83, v)}
			f.conn.Write(p.Assemble())
		}
	}
	f.mu.Unlock()
	return m, f, ap
}

func radioModelReply(fields map[string]string) json.RawMessage {
	b, _ := json.Marshal(map[string]any{"error_code": 0, "wireless": map[string]any{"radio_entry": []any{map[string]any{"radio_entry_1": fields}}}})
	return b
}

func TestNativeRadioUsesReportedModelNotTestedDeviceIdentity(t *testing.T) {
	for _, identity := range []struct{ model, hardware string }{
		{"TL-7AP5100HC-PoE/DC易展版", "1.0"},
		{"TL-7AP5100HC-PoE/DC易展版", "2.0"},
		{"TL-XAP3006GC-PoE/DC", "1.0"},
		{"Unlisted AP", "9.9"},
		{"", ""},
	} {
		t.Run(identity.model+"/"+identity.hardware, func(t *testing.T) {
			current := map[string]string{"radio_id": "1", "enable": "off"}
			var writes atomic.Int32
			m, _, ap := nativeModelAP(t, func(b json.RawMessage) json.RawMessage {
				var request struct {
					Method   string
					Wireless struct{ Para map[string]string }
				}
				if err := json.Unmarshal(b, &request); err != nil {
					t.Error(err)
				}
				if request.Method == "set" {
					writes.Add(1)
					for k, v := range request.Wireless.Para {
						current[k] = v
					}
					return json.RawMessage(`{"error_code":0}`)
				}
				return radioModelReply(current)
			})
			ap.Model, ap.HardwareVersion = identity.model, identity.hardware
			on := true
			m.reconcileRadio(context.Background(), ap, RadioSetting{Radio: 1, Enabled: &on}, 1)
			state := m.status[ap.ID+"/radio:1"]
			if state.State != "verified" || writes.Load() != 1 {
				t.Fatal(state, writes.Load())
			}
		})
	}
}

func TestNativeRadioWithoutTDCPUsesCAPWAPDespiteAXAndPMK(t *testing.T) {
	m, f, ap := nativeModelAP(t, func(json.RawMessage) json.RawMessage { t.Error("TDCP requested without capability49"); return nil })
	ap.GeneralCapabilities = []uint32{0, 0, 1<<2 | 1<<6}
	on := true
	m.reconcileRadio(context.Background(), ap, RadioSetting{Radio: 1, Enabled: &on}, 1)
	if state := m.status[ap.ID+"/radio:1"]; state.State != "acknowledged" {
		t.Fatal(state)
	}
	f.mu.Lock()
	defer f.mu.Unlock()
	if f.commands != 1 {
		t.Fatal("expected one CAPWAP configuration request", f.commands)
	}
}

func TestNativeRadioCannotReplaceUplinkCommandsWithDownlinkKeys(t *testing.T) {
	for _, enabled := range []bool{false, true} {
		m, f, ap := nativeModelAP(t, func(b json.RawMessage) json.RawMessage {
			if strings.Contains(string(b), `"set"`) {
				t.Error("downlink native keys used to deliver uplink controls")
			}
			return radioModelReply(map[string]string{"radio_id": "1", "enable": "on"})
		})
		ap.GeneralCapabilities = append(ap.GeneralCapabilities, 1<<6)
		c := cweng.RadioCapability{RadioID: 1, Band: "5 GHz", MaxClients: 64, Modes: []int{11}, Bandwidths: []int{0}, Features: map[string]bool{"downlink_mumimo": true, "uplink_mumimo": true, "downlink_ofdma": true, "uplink_ofdma": true}}
		ap.Capabilities = []cweng.RadioCapability{c}
		a := defaultRadioAdvanced(c)
		a.DownlinkMUMIMO = enabled
		a.UplinkMUMIMO = enabled
		a.DownlinkOFDMA = enabled
		a.UplinkOFDMA = enabled
		m.reconcileRadio(context.Background(), ap, RadioSetting{Radio: 1, Advanced: &a}, 1)
		state := m.status[ap.ID+"/radio:1"]
		if state.State != "acknowledged" || !strings.Contains(state.Reason, "uplink") {
			t.Fatal(state)
		}
		f.mu.Lock()
		found := false
		for _, p := range f.packets {
			for _, e := range p.Elements {
				if e.Type == 0x25 && len(e.Value) >= 10 && binary.BigEndian.Uint16(e.Value[6:]) == 8 {
					v, err := capwap.ParsePrivAdvRdPara(e.Value[10:])
					want := byte(0)
					if enabled {
						want = 15
					}
					if err != nil || len(v.Tail6) != 6 || v.Tail6[0]&15 != want {
						t.Fatal(enabled, v, err)
					}
					found = true
				}
			}
		}
		f.mu.Unlock()
		if !found {
			t.Fatal("missing complete independent MU/OFDMA command")
		}
	}
}

func TestNativeRadioBaseModelDoesNotWriteUnsupportedExtensions(t *testing.T) {
	c := cweng.RadioCapability{RadioID: 1, MaxClients: 64, Modes: []int{6}, Bandwidths: []int{0}}
	a := defaultRadioAdvanced(c)
	current := map[string]string{"mode": "4", "bandwidth": "1", "radio_max_sta": "64", "antenna": "0", "beacon_intv": "100", "dtim_period": "1", "frag_threshold": "2346", "rts_threshold": "2346", "wmm": "1", "short_gi": "1", "brd_probe": "1"}
	p, err := nativeParameters(RadioSetting{Radio: 1, Advanced: &a}, c, current, cweng.APStatus{GeneralCapabilities: []uint32{0, 1 << 17}})
	if err != nil {
		t.Fatal(err)
	}
	for _, k := range []string{"vhtmubfer", "ofdma", "twt", "gi_mode", "airtime", "rssi_weak_restrict", "rssi_weak_kick"} {
		if _, ok := p[k]; ok {
			t.Fatal("TDCP capability enabled unrelated extension", k, p)
		}
	}
}

func TestNativeRadioSparseReadbackIsUnverifiedNotOffOrFailure(t *testing.T) {
	for _, tc := range []struct{ name, actual, state string }{
		{"omitted", "", "acknowledged"},
		{"explicit-off", "off", "failed"},
		{"matching", "on", "verified"},
	} {
		t.Run(tc.name, func(t *testing.T) {
			written := false
			m, _, ap := nativeModelAP(t, func(b json.RawMessage) json.RawMessage {
				if strings.Contains(string(b), `"set"`) {
					written = true
					return json.RawMessage(`{"error_code":0}`)
				}
				fields := map[string]string{"radio_id": "1", "enable": "off"}
				if written {
					if tc.actual == "" {
						delete(fields, "enable")
					} else {
						fields["enable"] = tc.actual
					}
				}
				return radioModelReply(fields)
			})
			on := true
			m.reconcileRadio(context.Background(), ap, RadioSetting{Radio: 1, Enabled: &on}, 1)
			state := m.status[ap.ID+"/radio:1"]
			if state.State != tc.state {
				t.Fatal(state)
			}
			if tc.actual == "" && !strings.Contains(state.Reason, "enable") {
				t.Fatal("missing coverage explanation", state)
			}
		})
	}
}

func TestSparseNativeRadioFallsBackWithoutDroppingAdvancedSettings(t *testing.T) {
	m, f, ap := nativeModelAP(t, func(b json.RawMessage) json.RawMessage {
		if strings.Contains(string(b), `"set"`) {
			t.Error("incomplete native schema used for write")
		}
		return radioModelReply(map[string]string{"radio_id": "1", "enable": "on"})
	})
	c := cweng.RadioCapability{RadioID: 1, Band: "5 GHz", MaxClients: 64, Modes: []int{11}, Bandwidths: []int{0}, Features: map[string]bool{}}
	ap.GeneralCapabilities = append(ap.GeneralCapabilities, 1<<6)
	ap.Capabilities = []cweng.RadioCapability{c}
	a := defaultRadioAdvanced(c)
	on := true
	m.reconcileRadio(context.Background(), ap, RadioSetting{Radio: 1, Enabled: &on, Advanced: &a}, 1)
	state := m.status[ap.ID+"/radio:1"]
	if state.State != "acknowledged" || !strings.Contains(state.Reason, "vhtmubfer") {
		t.Fatal(state)
	}
	f.mu.Lock()
	defer f.mu.Unlock()
	found := false
	for _, packet := range f.packets {
		for _, el := range packet.Elements {
			if el.Type != 0x25 || len(el.Value) < 10 || binary.BigEndian.Uint16(el.Value[6:]) != 8 {
				continue
			}
			v, err := capwap.ParsePrivAdvRdPara(el.Value[10:])
			if err != nil {
				t.Fatal(err)
			}
			if len(v.Tail6) != 6 || v.Tail6[0]&3 != 0 {
				t.Fatal("MU directions were dropped", v)
			}
			found = true
		}
	}
	if !found {
		t.Fatal("missing complete CAPWAP advanced command")
	}
}

func TestNativeRadioIndependentDirectionsAnd6GUseCompleteProtocol(t *testing.T) {
	for _, c := range []cweng.RadioCapability{{}, {Features: map[string]bool{"enable_6g": true}}} {
		a := RadioAdvanced{Mode: 11, Bandwidth: 0, DownlinkMUMIMO: true}
		if _, err := nativeParameters(RadioSetting{Advanced: &a}, c, nil, nativeAXCapabilities()); err == nil || !strings.Contains(err.Error(), "CAPWAP extensions") {
			t.Fatal(err)
		}
		a.DownlinkMUMIMO = false
		if c.Features["enable_6g"] {
			if _, err := nativeParameters(RadioSetting{Advanced: &a}, c, nil, nativeAXCapabilities()); err == nil || !strings.Contains(err.Error(), "CAPWAP extensions") {
				t.Fatal("native path cannot clear previous 6G setting", err)
			}
		}
	}
}

func TestNativeRadioFailuresCannotMasqueradeAsLegacySuccess(t *testing.T) {
	for _, tc := range []struct {
		name, reply string
		legacy      bool
	}{
		{"unsupported", `{"error_code":-40106}`, true},
		{"model-unavailable", `{"error_code":0,"wireless":{"radio_entry":[]}}`, true},
		{"forbidden", `{"error_code":-40107}`, false},
		{"malformed", `{}`, false},
		{"timeout", "", false},
	} {
		t.Run(tc.name, func(t *testing.T) {
			m, f, ap := nativeModelAP(t, func(json.RawMessage) json.RawMessage { return json.RawMessage(tc.reply) })
			ctx, cancel := context.WithTimeout(context.Background(), 100*time.Millisecond)
			defer cancel()
			on := true
			m.reconcileRadio(ctx, ap, RadioSetting{Radio: 1, Enabled: &on}, 1)
			state := m.status[ap.ID+"/radio:1"]
			if (state.State == "acknowledged") != tc.legacy {
				t.Fatal(state)
			}
			f.mu.Lock()
			defer f.mu.Unlock()
			legacy := false
			for _, p := range f.packets {
				for _, el := range p.Elements {
					legacy = legacy || el.Type == 0x1f
				}
			}
			if legacy != tc.legacy {
				t.Fatal("incorrect fallback after model error", legacy, state)
			}
		})
	}
}
