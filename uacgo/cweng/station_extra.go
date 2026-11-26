package cweng

import (
	"strings"
	"time"
	"uacgo/capwap"
	"uacgo/terminal"
)

type ClientDeviceInfo struct {
	Recognition *terminal.Result `json:"recognition,omitempty"`
	Brand       string           `json:"brand,omitempty"`
	System      string           `json:"system,omitempty"`
	Inputs      []terminal.Input `json:"-"`
	NameSet     bool             `json:"-"`
	Hostname    string           `json:"hostname,omitempty"`
	VendorClass string           `json:"vendor_class,omitempty"`
	UserAgent   string           `json:"user_agent,omitempty"`
	Name        string           `json:"device_name,omitempty"`
	Capacity    *uint32          `json:"capacity,omitempty"`
	VendorOUIs  [][3]byte        `json:"vendor_ouis,omitempty"`
}

func stationTime(seconds uint32, now time.Time) time.Time {
	return now.Add(-time.Duration(seconds) * time.Second)
}
func (e *Engine) stationExtra(ctx *Ctx, sink ClientSink, b []byte) uint32 {
	rows, err := capwap.ParseStationExtra(b)
	if err != nil {
		return 0x15
	}
	result := uint32(0)
	for _, row := range rows {
		now := time.Now()
		online := uint32(0)
		for _, f := range row.Fields {
			if f.Type == 10 {
				online = capwap.Uint32BE(f.Value)
				break
			}
		}
		for _, f := range row.Fields {
			device := ClientDeviceInfo{}
			v := f.Value
			switch f.Type {
			case 0:
				for b := v[1:]; len(b) >= 3; b = b[3:] {
					var oui [3]byte
					copy(oui[:], b[:3])
					device.VendorOUIs = append(device.VendorOUIs, oui)
				}
			case 1:
				device.Hostname = strings.TrimRight(string(v), "\x00")
			case 2:
				device.VendorClass = strings.TrimRight(string(v), "\x00")
			case 3:
				device.UserAgent = strings.TrimRight(string(v), "\x00")
			case 6:
				device.Name = strings.SplitN(string(v), "\x00", 2)[0]
				if len(device.Name) > 64 {
					device.Name = device.Name[:64]
				}
				device.NameSet = true
			case 7:
				n := capwap.Uint32BE(v)
				device.Capacity = &n
			case 4, 9:
				radio, wlan, rssi, seconds := uint8(0), uint8(0), int8(0), online
				var vlan *uint16
				if f.Type == 4 {
					radio = uint8(capwap.Uint32BE(v))
					wlan = uint8(capwap.Uint32BE(v[4:]))
					rssi = int8(int16(capwap.Uint16BE(v[8:])))
					n := capwap.Uint16BE(v[10:])
					vlan = &n
					seconds = capwap.Uint32BE(v[12:])
				} else {
					radio = v[0]
					wlan = v[1]
					rssi = int8(v[2])
					result = e.associationCode(sessionID(ctx.Session), radio, wlan, row.MAC, &rssi, nil)
				}
				if e.ObserveAssociation != nil && !e.ObserveAssociation(sessionID(ctx.Session), radio, wlan, row.MAC) {
					continue
				}
				if e.AdmitStation != nil && !e.AdmitStation(sessionID(ctx.Session), radio, wlan) {
					continue
				}
				sink.StationEvent(ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), MAC: row.MAC, RadioID: radio, WLANID: uint32(wlan), RSSI: &rssi, VLAN: vlan, ConnectedAt: stationTime(seconds, now), Seen: now, Kind: "associate", State: "connected"})
			case 8:
				if v[0] < 1 || v[0] > 3 {
					return 0x25
				}
				links := []capwap.AssociationLink{}
				for b := v[1:]; len(b) >= 9; b = b[9:] {
					var mac [6]byte
					copy(mac[:], b[:6])
					links = append(links, capwap.AssociationLink{MAC: mac, Radio: b[6], WLAN: b[7], RSSI: int32(int8(b[8]))})
				}
				valid := true
				if e.AdmitStation != nil {
					for _, link := range links {
						if !e.AdmitStation(sessionID(ctx.Session), link.Radio, link.WLAN) {
							valid = false
						}
					}
				}
				if !valid {
					result = 0x26
					continue
				}
				rssi := int8(links[0].RSSI)
				sink.StationEvent(ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), MAC: row.MAC, MLD: &row.MAC, MLOLinks: links, RadioID: links[0].Radio, WLANID: uint32(links[0].WLAN), RSSI: &rssi, ConnectedAt: stationTime(online, now), Seen: now, Kind: "associate", State: "connected"})
			}
			if f.Type <= 3 {
				device.Inputs = append(device.Inputs, terminal.Input{Type: f.Type, Text: string(v), OUIs: device.VendorOUIs})
			}
			if f.Type <= 3 || f.Type == 6 || f.Type == 7 {
				sink.StationEvent(ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), MAC: row.MAC, Device: &device, Kind: "device", Seen: now})
			}
		}
	}
	return result
}

// MLO data has independent peer-MAC station records in the V6 DB. Statistics
// for a peer must not disappear or overwrite the MLD's primary radio location.
func (t *ClientTable) associateMLOPeers(ev ClientEvent) {
	if ev.Kind != "associate" || ev.MLD == nil || ev.MAC != *ev.MLD {
		return
	}
	for _, link := range ev.MLOLinks {
		if link.MAC == ev.MAC {
			continue
		}
		peer := ev
		peer.MAC = link.MAC
		peer.RadioID = link.Radio
		peer.WLANID = uint32(link.WLAN)
		rssi := int8(link.RSSI)
		peer.RSSI = &rssi
		peer.MLOPeer = true
		peer.MLOLinks = nil
		peer.ServiceID = ""
		peer.SSID = ""
		t.StationEvent(peer)
	}
}
func radioCountedStation(ev ClientEvent) bool {
	if ev.MLD == nil || ev.MLOPeer {
		return true
	}
	for _, link := range ev.MLOLinks {
		if link.MAC == ev.MAC {
			return true
		}
	}
	return false
}
func (t *ClientTable) RadioCount(ap string, radio uint8) (int, map[[6]byte]bool) {
	t.mu.Lock()
	defer t.mu.Unlock()
	count := 0
	macs := map[[6]byte]bool{}
	for mac, ev := range t.m {
		if ev.State == "connected" && ev.APID == ap && ev.RadioID == radio {
			macs[mac] = true
			if radioCountedStation(ev) {
				count++
			}
		}
	}
	return count, macs
}

// A deassociation of any MLO MAC removes every peer and the MLD on this AP.
// The AP capability gates this behavior in the packet handler (@7459fc).
func (t *ClientTable) DisassociateMLO(ap string, mac [6]byte, at time.Time) bool {
	t.mu.Lock()
	after := t.transitionSeq
	old, ok := t.m[mac]
	if !ok || old.MLD == nil || old.APID != ap {
		t.mu.Unlock()
		return false
	}
	mld := *old.MLD
	for key, ev := range t.m {
		if ev.APID != ap || ev.State != "connected" || ev.MLD == nil || *ev.MLD != mld {
			continue
		}
		next := ev
		next.State = "disconnected"
		next.Kind = "disassociate"
		next.Seen = at
		t.m[key] = next
		t.recordTransition(ev, true, next)
	}
	t.unlockAndNotify(after)
	return true
}
func cloneDevice(in *ClientDeviceInfo) *ClientDeviceInfo {
	if in == nil {
		return nil
	}
	v := *in
	if in.Recognition != nil {
		r := *in.Recognition
		v.Recognition = &r
	}
	v.Inputs = nil
	v.NameSet = false
	v.VendorOUIs = append([][3]byte{}, in.VendorOUIs...)
	if in.Capacity != nil {
		n := *in.Capacity
		v.Capacity = &n
	}
	return &v
}
func mergeDevice(old, next *ClientDeviceInfo) *ClientDeviceInfo {
	if next == nil {
		return cloneDevice(old)
	}
	if old == nil {
		old = &ClientDeviceInfo{}
	}
	v := cloneDevice(old)
	if next.Hostname != "" {
		v.Hostname = next.Hostname
	}
	if next.VendorClass != "" {
		v.VendorClass = next.VendorClass
	}
	if next.UserAgent != "" {
		v.UserAgent = next.UserAgent
	}
	if next.NameSet || next.Name != "" {
		v.Name = next.Name
	}
	if next.Capacity != nil {
		n := *next.Capacity
		v.Capacity = &n
	}
	if next.VendorOUIs != nil {
		v.VendorOUIs = append([][3]byte{}, next.VendorOUIs...)
	}
	if v.Recognition != nil {
		for _, in := range next.Inputs {
			*v.Recognition = v.Recognition.Observe(in)
		}
		v.Brand, v.System = v.Recognition.BrandName(), v.Recognition.SystemName()
	}
	return v
}

// A normal association of a former MLO MAC removes its other old records;
// a changed MLO association retires links no longer reported in that group.
// V6 wsta_db_sta_assoc @758cf8, branch @75a1c4.
func (t *ClientTable) retireMLOLocked(old, next ClientEvent) {
	if old.MLD == nil || next.MLOPeer {
		return
	}
	for mac, peer := range t.m {
		if mac == next.MAC || peer.MLD == nil || *peer.MLD != *old.MLD || peer.APID != old.APID || peer.State != "connected" {
			continue
		}
		keep := false
		if next.MLD != nil && next.APID == old.APID {
			for _, link := range next.MLOLinks {
				if mac == link.MAC && peer.RadioID == link.Radio && peer.WLANID == uint32(link.WLAN) {
					keep = true
					break
				}
			}
		}
		if keep {
			continue
		}
		ev := peer
		ev.Seen = next.Seen
		ev.Kind = "mlo_replaced"
		ev.State = "disconnected"
		t.m[mac] = ev
		t.recordTransition(peer, true, ev)
	}
}

type ClientLinkStatus struct {
	MAC        [6]byte           `json:"mac"`
	Radio      uint8             `json:"radio_id"`
	WLAN       uint8             `json:"wlan_id"`
	RSSI       *int8             `json:"rssi_dbm,omitempty"`
	Statistics *ClientStatistics `json:"statistics,omitempty"`
}

// _uac_wsta_get_entry @7670c8 shows MLD groups with per-link rate/RSSI and
// omits independent peer rows. Internal counting still uses the full DB.
func (t *ClientTable) Display() []ClientEvent {
	all := t.All()
	byMAC := map[[6]byte]ClientEvent{}
	for i, ev := range all {
		if ev.DisplayRSSI != nil {
			ev.RSSI = ev.DisplayRSSI
			all[i] = ev
		}
		byMAC[ev.MAC] = ev
	}
	out := []ClientEvent{}
	for _, ev := range all {
		if ev.MLOPeer {
			continue
		}
		if ev.MLD != nil {
			for _, link := range ev.MLOLinks {
				row := ClientLinkStatus{MAC: link.MAC, Radio: link.Radio, WLAN: link.WLAN}
				if peer, ok := byMAC[link.MAC]; ok && peer.APID == ev.APID && peer.RadioID == link.Radio && peer.WLANID == uint32(link.WLAN) && peer.State == "connected" {
					row.RSSI = peer.RSSI
					row.Statistics = peer.Statistics
				}
				ev.LinkStatus = append(ev.LinkStatus, row)
			}
		}
		out = append(out, ev)
	}
	return out
}

// _stats_pkt_sta_request @7b4a30 marks unreported links -95. Keep that
// display sentinel separate from RSSI history so it cannot become a sample.
// The original root-is-a-peer flag deliberately lives across the whole packet.
func (t *ClientTable) MLOStatisticsMissing(ap string, connection time.Time, rows []capwap.StaStatisticsRecord) {
	t.mu.Lock()
	defer t.mu.Unlock()
	if epoch, ok := t.epochs[ap]; ok && !connection.IsZero() && (connection.Before(epoch.Connection) || connection.Equal(epoch.Connection) && !epoch.Online) {
		return
	}
	reported := map[[6]byte]bool{}
	for _, r := range rows {
		reported[r.MAC] = true
	}
	rootIsPeer := false
	mark := func(mac [6]byte) {
		if ev, ok := t.m[mac]; ok && ev.APID == ap && ev.State == "connected" {
			missing := int8(-95)
			ev.DisplayRSSI = &missing
			t.m[mac] = ev
		}
	}
	for _, r := range rows {
		ev, ok := t.m[r.MAC]
		if !ok || ev.APID != ap || ev.MLD == nil || ev.State != "connected" {
			continue
		}
		root, ok := t.m[*ev.MLD]
		if !ok || root.APID != ap {
			continue
		}
		for _, link := range root.MLOLinks {
			if link.MAC == root.MAC {
				rootIsPeer = true
			}
			if !reported[link.MAC] {
				mark(link.MAC)
			}
		}
		if !rootIsPeer {
			mark(root.MAC)
		}
	}
}
