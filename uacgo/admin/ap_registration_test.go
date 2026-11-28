package admin

import (
	"encoding/binary"
	"encoding/json"
	"os"
	"strings"
	"testing"
	"uacgo/capwap"
	"uacgo/cweng"
)

func joinModel(id uint32) func(*capwap.ParsedPacket) {
	return func(p *capwap.ParsedPacket) {
		board := []byte{0x12, 0x34, 0x56, 0x78, 0, 0, 0, 4}
		board = binary.BigEndian.AppendUint32(board, id)
		p.Elements = append(p.Elements, capwap.Element{Type: 0x26, Value: board})
	}
}

func TestNewAPCopiesOnlyExplicitModelDefaultDuringJoin(t *testing.T) {
	m, e := testController(t)
	on, off := true, false
	m.mu.Lock()
	m.config.Templates = []APTemplate{
		{ID: "snapshot", Name: "Imported AP snapshot", ModelID: 123, Options: APOptions{LED: &off, Account: &APAccount{Username: "old-device", Password: "NotForNewAP"}}},
		{ID: "other", Name: "Other model", ModelID: 124, ApplyOnJoin: true, Options: APOptions{LED: &off}},
		{ID: "default", Name: "New model default", ModelID: 123, ApplyOnJoin: true, Hardware: "different-hardware", Options: APOptions{LED: &on}},
	}
	m.mu.Unlock()
	_, ap := newDeferredAP(t, e, joinModel(123))
	m.mu.Lock()
	defer m.mu.Unlock()
	var got APProfile
	for _, p := range m.config.APProfiles {
		if p.AP == ap.ID {
			got = p
		}
	}
	if got.InitialTemplate != "default" || got.Template != "" || got.Options.LED == nil || !*got.Options.LED || got.Options.Account != nil {
		t.Fatal("not an isolated copy of the model default", got)
	}
	// A later template edit and reconnect cannot change the stored AP copy.
	m.config.Templates[2].Options.LED = &off
	b, err := os.ReadFile(m.path)
	if err != nil {
		t.Fatal(err)
	}
	var saved Config
	if err = json.Unmarshal(b, &saved); err != nil {
		t.Fatal(err)
	}
	if len(saved.APProfiles) != 1 || !*saved.APProfiles[0].Options.LED {
		t.Fatal("Join did not persist the first-registration copy")
	}
	if *m.config.APProfiles[0].Options.LED != true {
		t.Fatal("template edit mutated AP settings")
	}
}

func TestModelDefaultNeverReappliesToExistingOrImportedAP(t *testing.T) {
	for _, existingProfile := range []bool{false, true} {
		m, _ := testController(t)
		on := true
		m.config.Templates = []APTemplate{{ID: "default", Name: "Default", ModelID: 123, ApplyOnJoin: true, Options: APOptions{LED: &on}}}
		if existingProfile {
			m.config.APProfiles = []APProfile{{AP: "ap", Name: "Imported", Location: "Keep"}}
		}
		ap := cweng.APStatus{ID: "ap", ModelID: 123}
		if err := m.registerAPJoin(ap, existingProfile); err != nil {
			t.Fatal(err)
		}
		if p := m.config.APProfiles[0]; p.InitialTemplate != "" || p.Options.LED != nil || existingProfile && p.Location != "Keep" {
			t.Fatal(p)
		}
		if err := m.registerAPJoin(ap, true); err != nil {
			t.Fatal(err)
		}
		if m.config.APProfiles[0].InitialTemplate != "" {
			t.Fatal("retry treated an existing profile as new")
		}
	}
}

func TestModelDefaultIsFrozenEvenWhenNoTemplateMatched(t *testing.T) {
	m, _ := testController(t)
	ap := cweng.APStatus{ID: "ap", ModelID: 123}
	if err := m.registerAPJoin(ap, true); err != nil {
		t.Fatal(err)
	}
	m.config.Templates = []APTemplate{{ID: "later", Name: "Later", ModelID: 123, ApplyOnJoin: true}}
	if err := m.registerAPJoin(ap, true); err != nil {
		t.Fatal(err)
	}
	if m.config.APProfiles[0].InitialTemplate != "" {
		t.Fatal("a reconnect retroactively adopted a template")
	}
}

func TestModelDefaultValidationAndCreationExclusions(t *testing.T) {
	on := true
	region := uint8(1)
	cfg := Config{Templates: []APTemplate{{ID: "a", Name: "A", ModelID: 123, ApplyOnJoin: true}, {ID: "b", Name: "B", ModelID: 123, ApplyOnJoin: true}}}
	if validateManagement(cfg) == nil {
		t.Fatal("ambiguous model defaults allowed")
	}
	cfg.Templates = cfg.Templates[:1]
	cfg.Templates[0].ModelID = 0
	if validateManagement(cfg) == nil {
		t.Fatal("unkeyed automatic template allowed")
	}
	ap := cweng.APStatus{GeneralCapabilities: make([]uint32, 4)}
	ap.GeneralCapabilities[73/32] |= 1 << (73 % 32)
	ap.GeneralCapabilities[44/32] |= 1 << (44 % 32)
	o := initialTemplateOptions(APOptions{RegionCode: &region, FitFatButton: &on, Mesh: &on}, ap, Config{})
	if o.RegionCode != nil || o.FitFatButton == nil || *o.FitFatButton || o.Mesh == nil || *o.Mesh {
		t.Fatal("copied excluded creation fields", o)
	}
}

func TestFirstRegistrationNameAndMeshChildRegionFollowOriginal(t *testing.T) {
	m, _ := testController(t)
	region := uint8(3)
	caps := make([]uint32, 4)
	caps[65/32] |= 1 << (65 % 32)
	m.config.Groups = []APGroup{{ID: "parent-group", Name: "Parent group"}}
	m.config.APProfiles = []APProfile{{AP: "parent", Group: "parent-group", Options: APOptions{RegionCode: &region}}}
	m.known["parent"] = cweng.APStatus{ID: "parent", GeneralCapabilities: caps}
	ap := cweng.APStatus{ID: "child", EntryID: 7, ModelID: 123, Model: "Model", MeshParent: "parent", Encapsulated: true, GeneralCapabilities: caps}
	if err := m.registerAPJoin(ap, true); err != nil {
		t.Fatal(err)
	}
	p := m.config.APProfiles[1]
	if p.Name != "Model-0007" || p.Group != "parent-group" || p.Options.RegionCode == nil || *p.Options.RegionCode != 3 {
		t.Fatal(p)
	}
}

func TestGeneratedAPNameDoesNotUseWebRenameLimit(t *testing.T) {
	m, _ := testController(t)
	prefix := strings.Repeat("A", 52)
	m.config.Templates = []APTemplate{{ID: "default", Name: prefix, ModelID: 123, ApplyOnJoin: true}}
	ap := cweng.APStatus{ID: "ap", ModelID: 123, EntryID: 7}
	if err := m.registerAPJoin(ap, true); err != nil {
		t.Fatal(err)
	}
	name := m.config.APProfiles[0].Name
	if name != prefix+"-0007" || !validStoredAPName(name) || validAPName(name) {
		t.Fatal(name)
	}
	w := callManagement(t, m, "POST", "aps/ap/settings", APProfile{Name: strings.Repeat("B", 51)})
	if w.Code != 400 {
		t.Fatal("generated-name allowance weakened Web rename", w.Code)
	}
}
