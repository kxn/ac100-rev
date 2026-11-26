package admin

import (
	"context"
	"encoding/json"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestNamedEDCARulesUpdateRFDatabaseAndDisableOnUnbind(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{0, 1 << 29}
	ap.SubCapabilities = map[uint16]uint32{61: 2}
	c := cweng.RadioCapability{RadioID: 1, Band: "2.4 GHz", MaxClients: 64, MinPower: 3, MaxPower: 24, Modes: []int{6}, Bandwidths: []int{0, 2}, Channels: []int{1, 6, 11}}
	ap.Capabilities = []cweng.RadioCapability{c}
	ap.Radios = 1
	m.known[ap.ID] = ap
	mode := 0
	r := EDCARule{ID: "voice", Name: "Voice", Frequencies: 1, WMM: false, Custom: true, Config: EDCAConfig{Enabled: true, Mode: &mode, Queues: defaultEDCAQueues()}}
	r.Config.Queues[0].TXOP = 55
	next := m.config
	next.EDCARules = []EDCARule{r}
	m.mu.Lock()
	err := m.saveManagement(next)
	m.mu.Unlock()
	if err != nil {
		t.Fatal(err)
	}
	if len(m.config.Radios) != 0 {
		t.Fatal("EDCA materialized unrelated RF overrides", m.config.Radios)
	}
	got := effectiveRadioConfig(m.config, ap).Radios[0]
	if got.Advanced.EDCA == nil || !got.Advanced.EDCA.Enabled || got.Advanced.EDCA.Queues[0].TXOP != 55 || !got.Advanced.WMM {
		t.Fatal(got)
	}
	ctx, cancel := context.WithTimeout(context.Background(), 3*time.Second)
	defer cancel()
	m.reconcileRadio(ctx, ap, got, m.config.Version)
	if err = m.checkpoint(ctx, ap.ID, "named-edca"); err != nil {
		t.Fatal(err)
	}
	f.mu.Lock()
	found := false
	for _, p := range f.packets {
		for _, el := range p.Elements {
			if el.Type == 0x25 && len(el.Value) >= 10 && el.Value[6] == 0 && el.Value[7] == 0x92 {
				found = true
			}
		}
	}
	f.mu.Unlock()
	if !found {
		t.Fatal("named EDCA did not reach the existing RF command path")
	}
	// Like the source DB, retain later per-radio edits until a rule event.
	manual := *got.Advanced
	manual.EDCA = &EDCAConfig{Enabled: true, Mode: &mode, Queues: defaultEDCAQueues()}
	manual.EDCA.Queues[0].TXOP = 66
	next = m.config
	manualSetting := got
	manualSetting.Advanced = &manual
	next.Radios = []RadioSetting{manualSetting}
	m.mu.Lock()
	err = m.saveManagement(next)
	m.mu.Unlock()
	if err != nil {
		t.Fatal(err)
	}
	if effectiveRadioConfig(m.config, ap).Radios[0].Advanced.EDCA.Queues[0].TXOP != 66 {
		t.Fatal("ordinary save reapplied an unchanged rule")
	}
	next = m.config
	next.EDCARules = nil
	m.mu.Lock()
	err = m.saveManagement(next)
	m.mu.Unlock()
	if err != nil {
		t.Fatal(err)
	}
	if a := effectiveRadioConfig(m.config, ap).Radios[0].Advanced; a.EDCA.Enabled || a.EDCA.Queues[0].TXOP != 55 {
		t.Fatal("delete did not apply the old rule with EDCA disabled")
	}
}

func TestEDCAFieldOverlayDoesNotFreezeInheritedRadioOrReapplyOnLabels(t *testing.T) {
	m, _ := testController(t)
	ap := cweng.APStatus{ID: "ap", ConnectedAt: time.Unix(100, 0), GeneralCapabilities: []uint32{0, 1 << 29}, Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "2.4 GHz", MaxClients: 64, MinPower: 3, MaxPower: 24, Modes: []int{6}, Bandwidths: []int{0, 2}, Channels: []int{1, 6, 11}}}}
	m.known[ap.ID] = ap
	ch := 6
	next := m.config
	next.APDefaults.Radios = []RadioSetting{{Radio: 1, Channel: &ch}}
	next.EDCARules = []EDCARule{{ID: "r", Name: "R", Frequencies: 1, WMM: true, Custom: true, Config: EDCAConfig{Enabled: true, Queues: defaultEDCAQueues()}}}
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	next = m.config
	ch2 := 11
	next.APDefaults.Radios = []RadioSetting{{Radio: 1, Channel: &ch2}}
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	r := effectiveRadioConfig(m.config, ap).Radios[0]
	if *r.Channel != 11 || !r.Advanced.EDCA.Enabled || len(m.config.Radios) != 0 {
		t.Fatal("EDCA froze channel inheritance", r)
	}
	// Explicitly writing even the same old queue value is still a later
	// manual operation. Rule overlays must not win merely by hash equality.
	manual := *r.Advanced
	manual.EDCA = &EDCAConfig{Queues: defaultEDCAQueues()}
	next = m.config
	r.Advanced = &manual
	next.Radios = []RadioSetting{r}
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	next = m.config
	next.ClientLabels = map[string]ClientLabel{"02:00:00:00:00:01": {Name: "label"}}
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if effectiveRadioConfig(m.config, ap).Radios[0].Advanced.EDCA.Enabled {
		t.Fatal("label save reapplied an unchanged rule")
	}
	next = m.config
	next.EDCARules = append([]EDCARule{}, next.EDCARules...)
	next.EDCARules[0].Name = "R2"
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if !effectiveRadioConfig(m.config, ap).Radios[0].Advanced.EDCA.Enabled {
		t.Fatal("rule event did not replace manual queues")
	}
	// This POST contains exactly the same explicit RF row as before the
	// rule event. An explicit operation still wins over that later rule.
	if w := callManagement(t, m, "POST", "radios", m.config.Radios[0]); w.Code != 202 {
		t.Fatal(w.Code, w.Body.String())
	}
	if effectiveRadioConfig(m.config, ap).Radios[0].Advanced.EDCA.Enabled {
		t.Fatal("identical manual write lost to rule cache")
	}
	// Omitting optional EDCA while editing other advanced fields preserves
	// the rule's queue overlay, while WMM remains a manual scalar.
	next = m.config
	next.EDCARules = append([]EDCARule{}, next.EDCARules...)
	next.EDCARules[0].Name = "R3"
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	partial := *effectiveRadioConfig(m.config, ap).Radios[0].Advanced
	partial.EDCA = nil
	partial.Beacon = 200
	next = m.config
	next.Radios = []RadioSetting{{AP: ap.ID, Radio: 1, Advanced: &partial}}
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if a := effectiveRadioConfig(m.config, ap).Radios[0].Advanced; !a.EDCA.Enabled || a.Beacon != 200 {
		t.Fatal("omitted optional queues were reset", a)
	}
	backup, err := json.Marshal(map[string]any{"format": "go-ac-configuration", "schema": 1, "config": m.config})
	if err != nil {
		t.Fatal(err)
	}
	next = m.config
	disabled := *effectiveRadioConfig(m.config, ap).Radios[0].Advanced
	disabled.EDCA = &EDCAConfig{Queues: defaultEDCAQueues()}
	next.Radios = []RadioSetting{{AP: ap.ID, Radio: 1, Advanced: &disabled}}
	if err = m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if effectiveRadioConfig(m.config, ap).Radios[0].Advanced.EDCA.Enabled {
		t.Fatal("manual disable failed")
	}
	if w := callManagement(t, m, "POST", "restore", json.RawMessage(backup)); w.Code != 202 {
		t.Fatal(w.Code, w.Body.String())
	}
	if !effectiveRadioConfig(m.config, ap).Radios[0].Advanced.EDCA.Enabled {
		t.Fatal("restore retained current manual state instead of backup policy state")
	}
}

func TestEDCAFrequencyConflictsAndVirtualModeRank(t *testing.T) {
	mode := 0
	a := EDCARule{ID: "a", Name: "A", Frequencies: 256, Config: EDCAConfig{Mode: &mode, Queues: defaultEDCAQueues()}}
	b := a
	b.ID = "b"
	b.Name = "B"
	if validateEDCARules([]EDCARule{a, b}, Config{}) == nil {
		t.Fatal("disabled rules did not reserve their binding")
	}
	b.Frequencies = 512
	if err := validateEDCARules([]EDCARule{a, b}, Config{}); err != nil {
		t.Fatal(err)
	}
	ap := cweng.APStatus{GeneralCapabilities: []uint32{0, 0, 1 << 28}, Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "5 GHz"}, {RadioID: 2, Band: "5 GHz"}, {RadioID: 3, Band: "2.4 GHz"}}, RadioModes: []cweng.RadioMode{{ID: 1, Radios: []uint8{2, 3}}, {ID: 2, Radios: []uint8{1, 2}}}}
	bits := frequencyRadioBits(ap)
	if bits[1] != 256 || bits[2] != 256 || bits[3] != 1 {
		t.Fatal("virtual rank must use the first containing mode", bits)
	}
}
