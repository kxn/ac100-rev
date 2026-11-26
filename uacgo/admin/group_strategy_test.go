package admin

import (
	"testing"
	"time"
	"uacgo/cweng"
)

func ipGroup(id, start, end string) APGroup {
	return APGroup{ID: id, Name: id, Strategy: &APGroupStrategy{Enabled: true, Type: "ip_range", Start: start, End: end}}
}

func TestGroupIPRangeValidationIncludesDisabledRules(t *testing.T) {
	a := ipGroup("a", "192.0.2.1", "192.0.2.10")
	b := ipGroup("b", "192.0.2.10", "192.0.2.20")
	b.Strategy.Enabled = false
	if validateGroupStrategies([]APGroup{a, b}) == nil {
		t.Fatal("inclusive overlap accepted with disabled rule")
	}
	b.Strategy.Start = "192.0.2.11"
	if err := validateGroupStrategies([]APGroup{a, b}); err != nil {
		t.Fatal(err)
	}
}

func TestGroupJoinUsesControlAddressAndOriginalSnapshot(t *testing.T) {
	m, _ := testController(t)
	m.config.Groups = []APGroup{ipGroup("new", "192.0.2.1", "192.0.2.10"), ipGroup("old", "198.51.100.1", "198.51.100.10")}
	m.config.APProfiles = []APProfile{{AP: "ap", Group: "old", Name: "preserved"}}
	ap := cweng.APStatus{ID: "ap", Address: "192.0.2.1:5246", LocalIP: "198.51.100.1", Online: true, ConnectedAt: time.Unix(100, 0)}
	// Inventory can see the new session before it reaches RUN.
	pre := ap
	pre.Online = false
	m.known[ap.ID] = pre
	m.observeAPState(ap)
	// Original foreach compares both callbacks against old. The later old
	// rule sees the AP outside its range and writes group0 after new matched.
	if p := m.config.APProfiles[0]; p.Group != "" || p.Name != "preserved" {
		t.Fatal(p)
	}
	// A repeated RUN observation is not a new Join and must preserve manual edits.
	m.config.APProfiles[0].Group = "old"
	m.observeAPState(ap)
	if apGroup(m.config, "ap") != "old" {
		t.Fatal("reapplied Join strategy on polling")
	}
	m.config.Groups[0], m.config.Groups[1] = m.config.Groups[1], m.config.Groups[0]
	ap.ConnectedAt = ap.ConnectedAt.Add(time.Second)
	m.observeAPState(ap)
	if apGroup(m.config, "ap") != "new" {
		t.Fatal("lost insertion order or control peer IP")
	}
}

func TestGroupEditAndMeshFollowOriginalSeparateTriggers(t *testing.T) {
	m, _ := testController(t)
	group := ipGroup("floor", "192.0.2.10", "192.0.2.10")
	m.known["parent"] = cweng.APStatus{ID: "parent", Address: "203.0.113.1:5246"}
	m.known["ap"] = cweng.APStatus{ID: "ap", Address: "192.0.2.10:5246"}
	m.known["child"] = cweng.APStatus{ID: "child", MeshParent: "parent", Encapsulated: true, Address: "192.0.2.10:5246"}
	m.known["upgrade"] = cweng.APStatus{ID: "upgrade", Address: "192.0.2.10:5246"}
	m.upgradeActive["upgrade"] = &upgradeRuntime{}
	next := m.config
	next.Groups = []APGroup{group, {ID: "parent-group", Name: "Parent"}}
	next.APProfiles = []APProfile{{AP: "parent", Group: "parent-group"}}
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if apGroup(m.config, "ap") != "floor" || apGroup(m.config, "child") != "parent-group" || apGroup(m.config, "upgrade") != "" {
		t.Fatal(m.config.APProfiles)
	}
	// Disabling a strategy doesn't undo membership or align Mesh children.
	next = m.config
	next.Groups = append([]APGroup{}, next.Groups...)
	s := *next.Groups[0].Strategy
	s.Enabled = false
	next.Groups[0].Strategy = &s
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	if apGroup(m.config, "ap") != "floor" {
		t.Fatal("disabled strategy reset membership")
	}
}

func TestMeshJoinInheritsParentBeforeIPStrategy(t *testing.T) {
	for _, encapsulated := range []bool{false, true} {
		m, _ := testController(t)
		m.config.Groups = []APGroup{ipGroup("ip", "192.0.2.1", "192.0.2.10"), {ID: "parent-group", Name: "Parent"}}
		m.config.APProfiles = []APProfile{{AP: "parent", Group: "parent-group"}}
		m.known["parent"] = cweng.APStatus{ID: "parent"}
		m.observeAPState(cweng.APStatus{ID: "new", MeshParent: "parent", Encapsulated: encapsulated, Address: "192.0.2.5:5246", ConnectedAt: time.Now(), Online: true})
		if apGroup(m.config, "new") != "parent-group" {
			t.Fatal("IP rule overrode initial Mesh parent group", encapsulated, m.config.APProfiles)
		}
	}
}

func TestIPGroupRulesDoNotResurrectReplacedAP(t *testing.T) {
	m, _ := testController(t)
	m.config.RetiredAPs = []string{"old"}
	m.known["old"] = cweng.APStatus{ID: "old", Address: "192.0.2.1:5246"}
	next := m.config
	next.Groups = []APGroup{ipGroup("g", "192.0.2.1", "192.0.2.10")}
	if err := m.saveManagement(next); err != nil {
		t.Fatal(err)
	}
	m.observeAPState(cweng.APStatus{ID: "old", Address: "192.0.2.1:5246", Online: true, ConnectedAt: time.Now()})
	if len(m.config.APProfiles) != 0 {
		t.Fatal("automatic grouping recreated the deleted AP DB entry", m.config.APProfiles)
	}
}
