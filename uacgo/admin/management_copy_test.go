package admin

import (
	"encoding/json"
	"testing"
	"uacgo/cweng"
)

func copyFixture(t *testing.T) (*Manager, string, string) {
	t.Helper()
	m, _ := testController(t)
	source, target := "02:00:00:00:00:01", "02:00:00:00:00:02"
	cap := cweng.RadioCapability{RadioID: 1, Band: "2.4 GHz", Channels: []int{1, 6, 11}, Modes: []int{6}, Bandwidths: []int{0, 2}, MaxClients: 128, MinPower: 1, MaxPower: 30}
	for _, id := range []string{source, target} {
		m.known[id] = cweng.APStatus{ID: id, Model: "AP", Capabilities: []cweng.RadioCapability{cap}, GeneralCapabilities: []uint32{0, 0, 1 << 28}, RadioModes: []cweng.RadioMode{{ID: 7}}}
	}
	a, b, c := 6, 1, 11
	echo := uint8(30)
	m.config.Groups = []APGroup{{ID: "source-group", Name: "Source group", Options: APOptions{EchoSeconds: &echo, Radios: []RadioSetting{{Radio: 1, Channel: &a}}}}, {ID: "target-group", Name: "Target group", Options: APOptions{Radios: []RadioSetting{{Radio: 1, Channel: &b}}}}}
	m.config.APProfiles = []APProfile{{AP: source, Name: "Source", Group: "source-group", Options: APOptions{RFMode: &APRFMode{Enabled: true, ID: 7}, Radios: []RadioSetting{{Radio: 1, Channel: &c}}}}, {AP: target, Name: "Target", Location: "Keep location", Group: "target-group", Options: APOptions{RFMode: &APRFMode{Enabled: false, ID: 7}, Radios: []RadioSetting{{Radio: 1, Channel: &b}}}}}
	power1, power2 := 10, 5
	m.config.Radios = []RadioSetting{{AP: source, Radio: 1, Power: &power1}, {AP: target, Radio: 1, Channel: &a, Power: &power2}}
	return m, source, target
}

func TestAPCopyWithoutRadiosPreservesTargetMembershipAndRadioLayers(t *testing.T) {
	m, source, target := copyFixture(t)
	w := callManagement(t, m, "POST", "aps/"+source+"/copy", map[string]any{"targets": []string{target}, "radios": false})
	if w.Code != 202 {
		t.Fatal(w.Code, w.Body.String())
	}
	p := m.config.APProfiles[1]
	if p.Name != "Target" || p.Location != "Keep location" || p.Group != "target-group" || p.Options.EchoSeconds == nil || *p.Options.EchoSeconds != 30 {
		t.Fatal("copy lost identity/group or ignored effective source settings", p)
	}
	if p.Options.RFMode == nil || p.Options.RFMode.Enabled || len(p.Options.Radios) != 1 || *p.Options.Radios[0].Channel != 1 {
		t.Fatal("unchecked radio option copied source RF settings", p.Options)
	}
	for _, r := range effectiveRadioConfig(m.config, m.known[target]).Radios {
		if r.AP == target && (*r.Channel != 6 || *r.Power != 5) {
			t.Fatal("target effective radio changed", r)
		}
	}
}

func TestAPCopyWithRadiosIncludesSourceInheritanceAndIsAtomicAcrossTargets(t *testing.T) {
	m, source, target := copyFixture(t)
	bad := "02:00:00:00:00:03"
	ap := m.known[target]
	ap.ID = bad
	ap.Capabilities = append([]cweng.RadioCapability{}, ap.Capabilities...)
	ap.Capabilities[0].Channels = []int{1, 6}
	m.known[bad] = ap
	before, _ := json.Marshal(m.config)
	w := callManagement(t, m, "POST", "aps/"+source+"/copy", map[string]any{"targets": []string{target, bad}, "radios": true})
	after, _ := json.Marshal(m.config)
	if w.Code != 400 || string(before) != string(after) {
		t.Fatal("failed batch left partial configuration", w.Code, w.Body.String())
	}
	w = callManagement(t, m, "POST", "aps/"+source+"/copy", map[string]any{"targets": []string{target}, "radios": true})
	if w.Code != 202 {
		t.Fatal(w.Code, w.Body.String())
	}
	for _, r := range effectiveRadioConfig(m.config, m.known[target]).Radios {
		if r.AP == target && (r.Channel == nil || *r.Channel != 11 || r.Power == nil || *r.Power != 10) {
			t.Fatal("copy ignored inherited source RF", r)
		}
	}
	if m.config.APProfiles[1].Group != "target-group" {
		t.Fatal("copy moved target to source group")
	}
}
