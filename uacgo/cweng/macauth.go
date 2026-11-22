package cweng

import (
	"sort"
	"sync"
)

// MAC authentication engine — the one defense subsystem with a real
// AC-side admission decision (uac_mac_auth_init @0x451078 registers
// mac_auth_wsta_callback_sta_check @0x451380 into the wsta association
// check chain at priority 0x14).
//
// Decision tree from _uac_mac_auth_sta_check @0x44c480 +
// mac_auth_db_mac_get_{vlan,ssid}_bind_status @0x4563b8/@0x456510:
//
//	group = (mode==1) ? group_by_vlan(sta.vlan) : group_by_ssid(sta.wserv)
//	no group            → pass (MAC auth not enabled for that VLAN/SSID)
//	mac not in the table: black_list group → pass; white_list group → forbid
//	mac in the table:     white_list: bound ? pass : forbid
//	                      black_list: bound ? forbid : pass
//	forbid → uac_wstation_free_sta_by_mac (kick/reject)

// MacAuthMode selects the group lookup dimension (uci authentication/
// macauth): 1 = by VLAN, otherwise by SSID.
type MacAuthMode int

const (
	MacAuthBySSID MacAuthMode = 0
	MacAuthByVLAN MacAuthMode = 1
)

// Mac group types (group entry +0x184).
const (
	MacAuthWhiteList = 0
	MacAuthBlackList = 1
)

// MacAuthMac is one MAC table entry (id/name/mac).
type MacAuthMac struct {
	ID   int
	Name string
	MAC  [6]byte
}

// MacAuthGroup is one policy group (0x188B group entry).
type MacAuthGroup struct {
	ID       int
	Status   bool // enabled (+0x10)
	Name     string
	Note     string
	BindVLAN string       // +0x14c
	Type     int          // 0 white_list / 1 black_list
	Bound    map[int]bool // bind_map: mac-entry ids bound to this group
}

// MacAuthSta is the check input (wsta record slice).
type MacAuthSta struct {
	MACs    [][6]byte // primary + MLO link MACs
	VLAN    string    // bind dimension when mode==1
	WServID string    // bind dimension otherwise
}

// MacAuthDB is the in-memory mac_auth database (mac/group tables).
type MacAuthDB struct {
	mu     sync.Mutex
	mode   MacAuthMode
	macs   map[int]*MacAuthMac
	byMAC  map[[6]byte]int
	groups map[int]*MacAuthGroup
	byVLAN map[string]int
	bySSID map[string]int
}

// NewMacAuthDB creates the database.
func NewMacAuthDB(mode MacAuthMode) *MacAuthDB {
	return &MacAuthDB{
		mode:   mode,
		macs:   map[int]*MacAuthMac{},
		byMAC:  map[[6]byte]int{},
		groups: map[int]*MacAuthGroup{},
		byVLAN: map[string]int{},
		bySSID: map[string]int{},
	}
}

// SetMode switches the lookup dimension (macauth_type.set).
func (d *MacAuthDB) SetMode(mode MacAuthMode) {
	d.mu.Lock()
	defer d.mu.Unlock()
	d.mode = mode
}

// UpsertMac adds/updates one MAC entry.
func (d *MacAuthDB) UpsertMac(e MacAuthMac) {
	d.mu.Lock()
	defer d.mu.Unlock()
	d.macs[e.ID] = &e
	d.byMAC[e.MAC] = e.ID
}

// DelMac removes one MAC entry and unbinds it everywhere.
func (d *MacAuthDB) DelMac(id int) {
	d.mu.Lock()
	defer d.mu.Unlock()
	if e, ok := d.macs[id]; ok {
		delete(d.byMAC, e.MAC)
		delete(d.macs, id)
	}
	for _, g := range d.groups {
		delete(g.Bound, id)
	}
}

// UpsertGroup adds/updates one group; key is the group's VLAN or SSID
// binding dimension per the current mode.
func (d *MacAuthDB) UpsertGroup(g MacAuthGroup) {
	d.mu.Lock()
	defer d.mu.Unlock()
	if g.Bound == nil {
		g.Bound = map[int]bool{}
	}
	old := d.groups[g.ID]
	if old != nil {
		g.Bound = old.Bound
	}
	cp := g
	d.groups[g.ID] = &cp
	switch d.mode {
	case MacAuthByVLAN:
		d.byVLAN[g.BindVLAN] = g.ID
	default:
		d.bySSID[g.BindVLAN] = g.ID // BindVLAN carries the SSID key in SSID mode
	}
}

// DelGroup removes one group.
func (d *MacAuthDB) DelGroup(id int) {
	d.mu.Lock()
	defer d.mu.Unlock()
	g, ok := d.groups[id]
	if !ok {
		return
	}
	delete(d.groups, id)
	for k, v := range d.byVLAN {
		if v == id {
			delete(d.byVLAN, k)
		}
	}
	for k, v := range d.bySSID {
		if v == id {
			delete(d.bySSID, k)
		}
	}
	_ = g
}

// Bind attaches mac-entry ids to a group (macauth_mac_for_group).
func (d *MacAuthDB) Bind(groupID int, macIDs []int, on bool) {
	d.mu.Lock()
	defer d.mu.Unlock()
	g := d.groups[groupID]
	if g == nil {
		return
	}
	for _, id := range macIDs {
		if on {
			g.Bound[id] = true
		} else {
			delete(g.Bound, id)
		}
	}
}

// Check runs the association admission decision. true = pass,
// false = forbid (the caller kicks via uac_wstation_free_sta_by_mac).
// For MLO sets every link MAC must pass (any forbid → forbid).
func (d *MacAuthDB) Check(sta MacAuthSta) bool {
	d.mu.Lock()
	defer d.mu.Unlock()
	var gid int
	var ok bool
	if d.mode == MacAuthByVLAN {
		gid, ok = d.byVLAN[sta.VLAN]
	} else {
		gid, ok = d.bySSID[sta.WServID]
	}
	if !ok {
		return true // no group for this VLAN/SSID → MAC auth not enabled
	}
	g := d.groups[gid]
	if g == nil || !g.Status {
		return true
	}
	pass := true
	for _, mac := range sta.MACs {
		if !d.checkOneLocked(g, mac) {
			pass = false
		}
	}
	return pass
}

func (d *MacAuthDB) checkOneLocked(g *MacAuthGroup, mac [6]byte) bool {
	id, inTable := d.byMAC[mac]
	bound := inTable && g.Bound[id]
	switch {
	case !inTable:
		// mac not in the table: black_list groups pass, white_list forbid
		return g.Type == MacAuthBlackList
	case g.Type == MacAuthWhiteList:
		return bound
	default: // black_list
		return !bound
	}
}

// MacList returns the MAC table rows (macauth_mac.get).
func (d *MacAuthDB) MacList() []MacAuthMac {
	d.mu.Lock()
	defer d.mu.Unlock()
	out := make([]MacAuthMac, 0, len(d.macs))
	for _, e := range d.macs {
		out = append(out, *e)
	}
	sort.Slice(out, func(i, j int) bool { return out[i].ID < out[j].ID })
	return out
}

// GroupList returns the group rows (macauth_group.get).
func (d *MacAuthDB) GroupList() []MacAuthGroup {
	d.mu.Lock()
	defer d.mu.Unlock()
	out := make([]MacAuthGroup, 0, len(d.groups))
	for _, g := range d.groups {
		cp := *g
		out = append(out, cp)
	}
	sort.Slice(out, func(i, j int) bool { return out[i].ID < out[j].ID })
	return out
}
