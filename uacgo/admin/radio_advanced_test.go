package admin

import (
	"bytes"
	"encoding/hex"
	"testing"
	"uacgo/capwap"
	"uacgo/cweng"
)

func TestAdvancedRadioVendorWireAndGates(t *testing.T) {
	c := cweng.RadioCapability{RadioID: 1, Band: "2.4 GHz", MaxClients: 256, MinPower: 3, MaxPower: 24, Modes: []int{6, 10, 12}, Bandwidths: []int{0, 1, 2}, Channels: []int{1, 6, 11}, Features: map[string]bool{"downlink_mumimo": true, "uplink_mumimo": true}}
	ap := cweng.APStatus{GeneralCapabilities: []uint32{2, 1 << 25, 1 << 6}}
	a := defaultRadioAdvanced(c)
	r := RadioSetting{Radio: 1, Advanced: &a}
	if err := validateAdvanced(r, ap, c); err != nil {
		t.Fatal(err)
	}
	want, _ := hex.DecodeString("010c0201010000010100000000000a0000000000030000000000")
	found := false
	for _, el := range advancedRadioElements(r, ap, c) {
		if el.Type != 0x25 {
			continue
		}
		if len(el.Value) >= 10 && el.Value[6] == 0 && el.Value[7] == 8 {
			found = true
			if !bytes.Equal(el.Value[10:], want) {
				t.Fatalf("adv got %x want %x", el.Value[10:], want)
			}
		}
	}

	if !found {
		t.Fatal("no advanced radio element")
	}
	a.TWT = true
	if validateAdvanced(r, ap, c) == nil {
		t.Fatal("accepted unsupported TWT")
	}
	a.TWT = false
	ch := 149
	r.Channel = &ch
	if validateAdvanced(r, ap, c) == nil {
		t.Fatal("accepted unadvertised channel")
	}
	if levelPower(1, c) != 3 || levelPower(10, c) != 24 || levelPower(5, c) != 12 {
		t.Fatal("power level mapping")
	}
}

func TestOtherAPAdvancedProfiles(t *testing.T) {
	// This profile deliberately advertises features absent on the physical AP.
	c := cweng.RadioCapability{RadioID: 3, Band: "5 GHz", MaxClients: 512, Modes: []int{7, 9, 11}, Bandwidths: []int{0, 1, 2, 3, 5}, Channels: []int{36, 40, 149}}
	ap := cweng.APStatus{GeneralCapabilities: []uint32{1<<9 | 1<<21, 1 << 29}, SubCapabilities: map[uint16]uint32{61: 2}}
	a := defaultRadioAdvanced(c)
	mode := 1
	a.DCS = &DCSConfig{Mode: 0, Online: true, Interval: 8, Occupancy: 50, Tolerance: 20}
	a.Reject = &AdmissionControl{Enabled: true, Threshold: -60, Difference: 6}
	a.EDCA = &EDCAConfig{Enabled: true, Mode: &mode, Queues: make([]EDCAQueue, 8)}
	for i := range a.EDCA.Queues {
		a.EDCA.Queues[i] = EDCAQueue{AIFS: 3, CWMin: 4, CWMax: 10, TXOP: 0}
	}
	ch := 36
	r := RadioSetting{Radio: 3, Channel: &ch, Advanced: &a}
	if err := validateAdvanced(r, ap, c); err != nil {
		t.Fatal(err)
	}
	found := map[uint16]int{}
	for _, el := range advancedRadioElements(r, ap, c) {
		if el.Type == 0x404 {
			want, _ := hex.DecodeString("03002402000000000101000800320064001400")
			if !bytes.Equal(el.Value, want) {
				t.Fatalf("DCS %x", el.Value)
			}
		}
		if el.Type == 0x25 {
			found[uint16(el.Value[6])<<8|uint16(el.Value[7])] = len(el.Value) - 10
		}
	}
	if found[0x92] != 42 || found[0xcf] != 2 || found[0x4c] != 8 {
		t.Fatalf("missing EDCA/admission codecs: %v", found)
	}
	ap.GeneralCapabilities = nil
	if validateAdvanced(r, ap, c) == nil {
		t.Fatal("accepted unsupported advanced controls")
	}
}

func TestRadioLocalWLANAllocationAndOfflineDelete(t *testing.T) {
	dir := t.TempDir()
	m := &Manager{path: dir + "/controller.json", assignments: WLANAssignments{}, owned: map[string]map[uint8]map[uint8]bool{}, status: map[string]ApplyStatus{}, applied: map[string]string{}}
	first, err := m.allocate("ap-one", "office", 1, 1)
	if err != nil || first != 1 {
		t.Fatal(first, err)
	}
	// Another AP and another radio independently reuse slot one.
	if slot, err := m.allocate("ap-two", "guest", 1, 1); err != nil || slot != 1 {
		t.Fatal(slot, err)
	}
	if slot, err := m.allocate("ap-one", "guest", 2, 1); err != nil || slot != 1 {
		t.Fatal(slot, err)
	}
	if _, err := m.allocate("ap-one", "guest", 1, 1); err == nil {
		t.Fatal("capacity overrun")
	}
	m.config.Services = []Service{{ID: "office", SSID: "Office", Security: "open", Radios: []uint8{1}, WLAN: 99, Deleting: true}}
	m.finishDeletions()
	if len(m.config.Services) != 1 {
		t.Fatal("discarded pending removal on offline AP")
	}
	delete(m.assignments["ap-one"]["office"], 1)
	m.finishDeletions()
	if len(m.config.Services) != 0 {
		t.Fatal("completed removal not collected")
	}
}

func TestRadioBatchesRetainEveryVendorParameter(t *testing.T) {
	elements := []capwap.Element{{Type: 0x1f}, {Type: 0x404}, {Type: 0x25, Value: []byte{8}}, {Type: 0x25, Value: []byte{10}}, {Type: 0x25, Value: []byte{0xa0}}}
	batches := radioBatches(elements)
	if len(batches) != 4 || len(batches[0]) != 2 {
		t.Fatalf("radio batches: %#v", batches)
	}
	var seen []byte
	for _, b := range batches {
		n := 0
		for _, el := range b {
			if el.Type == 0x25 {
				n++
				seen = append(seen, el.Value[0])
			}
		}
		if n > 1 {
			t.Fatal("each batch must acknowledge one extension independently")
		}
	}
	if !bytes.Equal(seen, []byte{8, 10, 0xa0}) {
		t.Fatalf("lost vendor parameters %x", seen)
	}
}

func TestEDCAScenesUseReportedModelValues(t *testing.T) {
	scene := uint8(2)
	queues := []EDCAQueue{{AIFS: 1, CWMin: 2, CWMax: 3, TXOP: 47}, {AIFS: 2, CWMin: 3, CWMax: 4, TXOP: 94}, {AIFS: 3, CWMin: 4, CWMax: 10}, {AIFS: 7, CWMin: 4, CWMax: 10}}
	queues = append(queues, queues...)
	ap := cweng.APStatus{SubCapabilities: map[uint16]uint32{61: 1}, EDCAPresets: &capwap.EDCAPresets{Version: 3, Scenes: []capwap.EDCAScene{{ID: 2, Name: "Office", Bands: []capwap.EDCABandPreset{{Band: 2, Queues: queues}}}}}}
	got, err := resolveEDCA(EDCAConfig{Preset: &scene}, ap, cweng.RadioCapability{Band: "5 GHz"})
	if err != nil || len(got.Queues) != 8 || got.Queues[1].TXOP != 94 {
		t.Fatal(got, err)
	}
	if _, err = resolveEDCA(EDCAConfig{Preset: &scene}, ap, cweng.RadioCapability{Band: "2.4 GHz"}); err == nil {
		t.Fatal("borrowed another band's preset")
	}
	if _, err = resolveEDCA(EDCAConfig{Preset: &scene}, cweng.APStatus{}, cweng.RadioCapability{Band: "5 GHz"}); err == nil {
		t.Fatal("invented absent preset")
	}
}

func TestAntennaChoicesMatchOriginalValidator(t *testing.T) {
	c := cweng.RadioCapability{RadioID: 1, MaxClients: 64, Modes: []int{6}, Bandwidths: []int{0}}
	a := defaultRadioAdvanced(c)
	a.Antenna = 1
	if validateAdvanced(RadioSetting{Radio: 1, Advanced: &a}, cweng.APStatus{}, c) == nil {
		t.Fatal("invented external antenna accepted")
	}
}

// AP-wide bandwidth support does not make every width valid in every mode.
func TestRadioModeWMMAndBandwidthCombinations(t *testing.T) {
	c := cweng.RadioCapability{RadioID: 1, Band: "5 GHz", Modes: []int{0, 7, 9}, Bandwidths: []int{0, 1, 2, 3}, MaxClients: 64}
	a := defaultRadioAdvanced(c)
	ap := cweng.APStatus{}
	for _, bad := range []RadioAdvanced{func() RadioAdvanced { b := a; b.WMM = false; return b }(), func() RadioAdvanced { b := a; b.Mode = 7; b.Bandwidth = 3; return b }(), func() RadioAdvanced { b := a; b.Mode = 0; b.Bandwidth = 1; return b }()} {
		if validateAdvanced(RadioSetting{Radio: 1, Advanced: &bad}, ap, c) == nil {
			t.Fatal("invalid mode/WMM/width accepted", bad)
		}
	}
	a.Mode = 0
	a.Bandwidth = 0
	a.WMM = false
	if err := validateAdvanced(RadioSetting{Radio: 1, Advanced: &a}, ap, c); err != nil {
		t.Fatal("legacy mode cannot disable WMM", err)
	}
}

func TestAPReportedFeatureDefaults(t *testing.T) {
	c := cweng.RadioCapability{Features: map[string]bool{"downlink_mumimo": true, "twt": true}, AXDefaults: &cweng.RadioFeatureDefaults{DownlinkMUMIMO: 0, TWT: 1, GI: 2}}
	a := defaultRadioAdvanced(c)
	if a.DownlinkMUMIMO || !a.TWT || a.GI != 2 || a.UplinkMUMIMO {
		t.Fatal(a)
	}
	c.AXDefaults = nil
	a = defaultRadioAdvanced(c)
	if !a.DownlinkMUMIMO || a.TWT || a.GI != -1 {
		t.Fatal("RUN fallback MU-MIMO default missing", a)
	}
}
