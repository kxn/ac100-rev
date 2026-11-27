package cweng

import (
	"net"
	"sync"
	"time"

	"uacgo/capwap"
	"uacgo/terminal"
)

// wsta subsystem (client tracking).
//
// Registry evidence: uac_wstation registers msg 9 (WTP Event Request) at
// priority100 (_uac_wsta_pkt_wtp_event_listener @0x74a4b0). The listener
// reads element 0x34 station information list (and private fallbacks
// 0x02/0x8a/0x03/0x4d) and reads the response's 0x21 result code.

// ClientEvent is one observed station add/remove.
type ClientStatistics struct {
	NegotiatedMbps uint16  `json:"negotiated_mbps"`
	Bandwidth      int8    `json:"bandwidth_code"`
	UpstreamKbps   *uint32 `json:"upstream_kbps,omitempty"`
	DownstreamKbps *uint32 `json:"downstream_kbps,omitempty"`
	UploadKB       *uint32 `json:"upload_increment_kbytes,omitempty"`
	DownloadKB     *uint32 `json:"download_increment_kbytes,omitempty"`
	RetryPercent   *byte   `json:"retry_percent,omitempty"`
	LossPercent    *byte   `json:"loss_percent,omitempty"`
}

func stationStatistics(a capwap.StaStatisticsRecord) *ClientStatistics {
	s := &ClientStatistics{NegotiatedMbps: a.NegotiatedMbps, Bandwidth: int8(a.Bandwidth)}
	if a.Capabilities&1 != 0 {
		s.RetryPercent = &a.RetryPercent
	}
	if a.Capabilities&2 != 0 {
		s.LossPercent = &a.LossPercent
	}
	if a.Capabilities&4 != 0 {
		s.UpstreamKbps = &a.UpstreamKbps
	}
	if a.Capabilities&8 != 0 {
		s.DownstreamKbps = &a.DownstreamKbps
	}
	if a.Capabilities&16 != 0 {
		s.UploadKB = &a.UploadKB
	}
	if a.Capabilities&32 != 0 {
		s.DownloadKB = &a.DownloadKB
	}
	return s
}

type ClientEvent struct {
	DisplayRSSI *int8              `json:"-"` // firmware MLO missing-report sentinel; not a measured sample
	Connection  time.Time          `json:"-"`
	LinkStatus  []ClientLinkStatus `json:"radio_entries,omitempty"`
	Device      *ClientDeviceInfo  `json:"device,omitempty"`
	MLOPeer     bool               `json:"mlo_peer,omitempty"`
	RSSIAt      time.Time
	VLAN        *uint16
	ServiceID   string
	SSID        string
	IPv6        []string
	ConnectedAt time.Time
	Statistics  *ClientStatistics

	MLD      *[6]byte
	MLOLinks []capwap.AssociationLink
	IP       string
	Kind     string
	State    string
	WLANID   uint32
	RSSI     *int8
	APID     string
	Seen     time.Time
	MAC      [6]byte
	RadioID  uint8
	A, B     uint32
}

// ClientSink receives station events parsed from WTP Event Requests.
type ClientSink interface {
	StationEvent(ev ClientEvent)
}

// RegisterWstaHandlers wires the msg 9 listener that parses 0x34 and adds
// result code 0 to the response when absent.
func (e *Engine) RegisterWstaHandlers(sink ClientSink) {
	e.registerWirelessStatistics(sink)
	e.Register(9, 1, "v6_balance_discovery", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		if b, ok := firstPrivateElement(req, 0x0b); ok {
			if a, err := capwap.ParseStaDiscovery(b); err == nil {
				if e.OnStationDiscovery != nil {
					e.OnStationDiscovery(sessionID(ctx.Session), ctx.Session.Created, a.MAC)
				}
				sink.StationEvent(ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), RadioID: a.Radio, WLANID: uint32(a.WlanID), MAC: a.MAC, Kind: "probe", Seen: time.Now()})
			}
		}
		return true
	})
	e.Register(9, 90, "v6_roaming", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		privateElements(privatePacketForTypes(req, []uint16{0x49, 0x58}), func(typ uint16, b []byte) {
			if typ == 0x58 && e.OnRoamingTrigger != nil {
				if p, err := capwap.ParsePrivRoamingTrigger(b); err == nil {
					if row, ok := ctx.Session.radioStatistics[p.Radio]; ok {
						row.ChannelLoad = p.ChannelLoad
						row.NoiseFloor = p.NoiseFloor
						row.ReceivedAt = time.Now()
						ctx.Session.radioStatistics[p.Radio] = row
					}
					e.OnRoamingTrigger(sessionID(ctx.Session), ctx.Session.Created, *p)
				}
				return
			}
			if typ != 0x49 || e.OnStationPMK == nil {
				return
			}
			p, err := capwap.ParsePrivStaPMKReq(b)
			if err != nil || p.MAC == [6]byte{} || p.MAC[0]&1 != 0 {
				return
			}
			special := ctx.Session.apEntry != nil && ctx.Session.apEntry.HasCapability(66)
			response := e.OnStationPMK(sessionID(ctx.Session), ctx.Session.Created, special, *p)
			if response == nil {
				return
			}
			if response.Result != 0 {
				if table, ok := sink.(interface{ DisconnectStation([6]byte, time.Time) }); ok {
					table.DisconnectStation(p.MAC, time.Now())
				}
			}
			if response.Result == 0 && p.Operation == 3 {
				sink.StationEvent(ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), Seen: time.Now(), MAC: p.MAC, RadioID: p.Radio, WLANID: uint32(p.WLAN), Kind: "associate", State: "connected"})
			}
			rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0x49, []capwap.PrivElementValue{{Type: 0x49, Value: response.AssembleValue()}})})
		})
		return true
	})
	e.Register(9, 100, "uac_wsta_wtp_event", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		for _, el := range rsp.Elements {
			if el.Type == 0x21 && (len(el.Value) != 4 || capwap.Uint32BE(el.Value) != 0) {
				return true
			}
		}
		setStationResult(rsp, 0)
		req = stationEventPacket(req)
		for _, el := range req.Elements {
			if el.Type == 0x0034 {
				if l, err := capwap.ParseStaInfoList(el.Value); err == nil {
					for _, en := range l.Entries {
						if e.ObserveAssociation != nil && !e.ObserveAssociation(sessionID(ctx.Session), l.RadioID, uint8(l.WLANID), en.MAC) {
							continue
						}
						now := time.Now()
						rssi := int8(int32(en.B))
						sink.StationEvent(ClientEvent{
							Kind: "associate", State: "connected", WLANID: l.WLANID,
							Connection: ctx.Session.Created, APID: sessionID(ctx.Session), Seen: now, RSSI: &rssi, ConnectedAt: stationTime(en.A, now),
							MAC: en.MAC, RadioID: l.RadioID, A: en.A, B: en.B,
						})
					}
				}
			}
			if el.Type == 0x33 {
				if l, err := capwap.ParseStaRSSI(el.Value); err == nil && uint64(l.Count)*7 == uint64(len(l.Body)) {
					for b := l.Body; len(b) >= 7; b = b[7:] {
						var mac [6]byte
						copy(mac[:], b[:6])
						rssi := int8(b[6])
						sink.StationEvent(ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), Seen: time.Now(), MAC: mac, RadioID: l.RadioID, Kind: "rssi", RSSI: &rssi})
					}
				}
			}
		}
		privateElements(req, func(typ uint16, b []byte) {
			switch typ {

			case 2:
				a, err := capwap.ParseLegacyAssociation(b)
				if err != nil {
					return
				}
				result := uint32(0)
				if a.MAC == [6]byte{} || a.MAC[0]&1 != 0 {
					result = 0x25
				}
				if ctx.Session.apEntry != nil && int(a.Radio) > ctx.Session.apEntry.RadioCount {
					result = 0x26
				}

				var signal *int8
				if a.RSSI != nil && *a.RSSI >= -128 && *a.RSSI <= 0 {
					v := int8(*a.RSSI)
					signal = &v
				}
				if result == 0 {
					result = e.associationCode(sessionID(ctx.Session), a.Radio, a.WLAN, a.MAC, signal, nil)
				}
				rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 4, []capwap.PrivElementValue{{Type: 4, Value: a.Result(result)}})})
				if result == 0 {
					ev := ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), Seen: time.Now(), MAC: a.MAC, RadioID: a.Radio, WLANID: uint32(a.WLAN), Kind: "associate", State: "connected"}
					if a.RSSI != nil && *a.RSSI >= -128 {
						v := int8(*a.RSSI)
						ev.RSSI = &v
					}
					sink.StationEvent(ev)
				}
			case 0x8a:
				a, err := capwap.ParseStaAssociationNew(b)
				if err != nil {
					return
				}
				response := capwap.StaAssociationNew{Radio: a.Radio, WLAN: a.WLAN, MAC: a.MAC, Phase: a.Phase}
				var mlo *capwap.AssociationMLO
				for _, sub := range a.Sub {
					switch sub.Type {
					case 0:
						if len(sub.Value) > 0 {
							response.Sub = append(response.Sub, capwap.Element{Type: 1, Value: sub.Value})
						} else {
							response.Word = 0x25
						}
					case 1:
						var err error
						mlo, err = capwap.ParseAssociationMLO(sub.Value)
						if err != nil {
							response.Word = 0x25
						} else {
							response.Sub = append(response.Sub, capwap.Element{Type: 2, Value: []byte{}})
							// @7498c0 treats this as an ordinary association if
							// the AP does not advertise MLO; optional metadata
							// alone is not an admission failure.
							if ctx.Session.apEntry == nil || ctx.Session.apEntry.SubCapabilities[0x5f]&2 == 0 {
								mlo = nil
							}
						}
					case 2:
						if len(sub.Value) < 4 {
							response.Word = 0x25
						} // association metadata, not an admission failure
					}
				}

				if a.MAC == [6]byte{} || a.MAC[0]&1 != 0 {
					response.Word = 0x25
				}
				if a.Radio == 0 || a.WLAN == 0 || (ctx.Session.apEntry != nil && int(a.Radio) > ctx.Session.apEntry.RadioCount) {
					response.Word = 0x26
				}
				if response.Word == 0 {
					rssi := int8(int32(a.Word))
					response.Word = e.associationCode(sessionID(ctx.Session), a.Radio, a.WLAN, a.MAC, &rssi, mlo)
				}
				rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0x8b, []capwap.PrivElementValue{{Type: 0x8b, Value: response.AssembleValue()}})})
				if response.Word != 0 {
					found := false
					for i := range rsp.Elements {
						if rsp.Elements[i].Type == 0x21 {
							rsp.Elements[i].Value = []byte{0, 0, 0, 0x15}
							found = true
						}
					}
					if !found {
						rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x21, Value: []byte{0, 0, 0, 0x15}})
					}
				}
				if response.Word == 0 {
					state := "connected"
					rssi := int8(int32(a.Word))
					ev := ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), Seen: time.Now(), MAC: a.MAC, RadioID: a.Radio, WLANID: uint32(a.WLAN), Kind: "associate", State: state, RSSI: &rssi}
					if mlo != nil {
						ev.MAC = mlo.MAC
						ev.MLD = &mlo.MAC
						ev.MLOLinks = append([]capwap.AssociationLink{}, mlo.Links...)
						ev.RadioID = mlo.Links[0].Radio
						ev.WLANID = uint32(mlo.Links[0].WLAN)
						rssi := int8(mlo.Links[0].RSSI)
						ev.RSSI = &rssi
					}
					sink.StationEvent(ev)
				}
			case 3:
				if a, err := capwap.ParseStaDeassoc(b); err == nil {
					if ctx.Session.apEntry != nil && ctx.Session.apEntry.SubCapabilities[95]&2 != 0 {
						if table, ok := sink.(interface {
							DisassociateMLO(string, [6]byte, time.Time) bool
						}); ok && table.DisassociateMLO(sessionID(ctx.Session), a.MAC, time.Now()) {
							return
						}
					}
					sink.StationEvent(ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), Seen: time.Now(), MAC: a.MAC, RadioID: a.Radio, WLANID: uint32(a.WlanID), Kind: "disassociate", State: "disconnected"})
				}
			case 0xc6:
				setStationResult(rsp, e.stationExtra(ctx, sink, b))
			case 0x4d:
				if rows, err := capwap.ParseStationAddressList(b); err == nil {
					for _, r := range rows {
						sink.StationEvent(ClientEvent{Connection: ctx.Session.Created, APID: sessionID(ctx.Session), Seen: time.Now(), MAC: r.MAC, Kind: "ip", IP: net.IP(r.Address).String()})
					}
				}

			}
		})
		// result code 0 in the response (the binary's listener expects it)
		hasResult := false
		for _, el := range rsp.Elements {
			if el.Type == 0x0021 {
				hasResult = true
			}
		}
		if !hasResult {
			rsp.Elements = append(rsp.Elements, capwap.Element{
				Type: 0x0021, Value: []byte{0, 0, 0, 0}})
		}
		return true
	})
}

// ClientTable is a simple in-memory ClientSink (session bookkeeping).
type ClientTable struct {
	// Explicit firmware release callback, separate from AP detach facts.
	OnRelease func(ClientEvent)
	epochs    map[string]clientEpoch
	// Set before events start; resolution occurs outside the table lock.
	ResolveService func(string, uint8, uint32) (string, string)
	// Set before events start. Notifications run after releasing the table lock.
	OnTransition   func(ClientTransition)
	OnDeviceName   func(ClientEvent)
	transitions    []ClientTransition
	transitionSeq  uint64
	mu             sync.Mutex
	m              map[[6]byte]ClientEvent
	observations   map[[6]byte]map[clientLocation]ClientEvent
	observationsGC time.Time
}

type clientLocation struct {
	AP    string
	Radio uint8
	WLAN  uint32
}

func clientPosition(e ClientEvent) clientLocation { return clientLocation{e.APID, e.RadioID, e.WLANID} }

// NewClientTable creates the table.
func NewClientTable() *ClientTable {
	return &ClientTable{m: make(map[[6]byte]ClientEvent)}
}

// StationEvent records the latest event per MAC.
// V6 association handlers (749290/7498c0) update wsta_db synchronously
// after _uac_wsta_do_check. A traffic/IP report cannot create/move a station.
func (t *ClientTable) StationEvent(ev ClientEvent) {
	if ev.Seen.IsZero() {
		ev.Seen = time.Now()
	}
	t.associateMLOPeers(ev)
	if t.ResolveService != nil && ev.SSID == "" && ev.Kind == "associate" {
		ev.ServiceID, ev.SSID = t.ResolveService(ev.APID, ev.RadioID, ev.WLANID)
	}
	t.mu.Lock()
	after := t.transitionSeq
	var nameReport *string
	defer func() {
		t.unlockAndNotify(after)
		if nameReport != nil && t.OnDeviceName != nil {
			t.OnDeviceName(ev)
		}
	}()
	if ev.Seen.IsZero() {
		ev.Seen = time.Now()
	}
	if ev.MAC == [6]byte{} || ev.MAC[0]&1 != 0 {
		return
	}
	if epoch, ok := t.epochs[ev.APID]; ok && !ev.Connection.IsZero() && (ev.Connection.Before(epoch.Connection) || ev.Connection.Equal(epoch.Connection) && !epoch.Online) {
		return
	}
	if ev.RSSI != nil {
		ev.RSSIAt = ev.Seen
	}
	if ev.Kind == "probe" || ev.RSSI != nil {
		t.observeLocked(ev)
	}
	if ev.Kind == "probe" {
		return
	}
	old, known := t.m[ev.MAC]
	if known && ev.Seen.Before(old.Seen) {
		return
	}
	if ev.Kind == "associate" {
		if known {
			t.retireMLOLocked(old, ev)
		}
		ev.State = "connected"
		if known && old.State == "connected" && clientPosition(old) == clientPosition(ev) && sameClientService(old, ev) {
			ev.IP = old.IP
			ev.IPv6 = append([]string{}, old.IPv6...)
			if ev.ConnectedAt.IsZero() {
				ev.ConnectedAt = old.ConnectedAt
			}
			if ev.VLAN == nil {
				ev.VLAN = old.VLAN
			}
			ev.Device = mergeDevice(old.Device, ev.Device)
			ev.Statistics = old.Statistics
		}
		if ev.ConnectedAt.IsZero() {
			ev.ConnectedAt = ev.Seen
		}
		if ev.Device == nil || ev.Device.Recognition == nil {
			r := terminal.New(ev.MAC)
			if ev.Device == nil {
				ev.Device = &ClientDeviceInfo{}
			}
			ev.Device.Recognition = &r
			ev.Device.Brand, ev.Device.System = r.BrandName(), r.SystemName()
		}
		t.m[ev.MAC] = ev
		t.recordTransition(old, known, ev)
		return
	}
	if !known || old.State != "connected" || old.APID != ev.APID {
		return
	}
	next := old
	next.Seen = ev.Seen
	next.Kind = ev.Kind
	switch ev.Kind {
	case "device":
		if ev.Device != nil {
			next.Device = mergeDevice(old.Device, ev.Device)
			if ev.Device.NameSet {
				name := ev.Device.Name
				nameReport = &name
			}
		}
	case "ip":
		ip := net.ParseIP(ev.IP)
		if ip == nil {
			return
		}
		if ip.To4() == nil {
			present := false
			for _, v := range next.IPv6 {
				present = present || v == ev.IP
			}
			if !present {
				next.IPv6 = append(append([]string{}, next.IPv6...), ev.IP)
			}
			if net.ParseIP(next.IP).To4() == nil {
				next.IP = ev.IP
			}
		} else {
			next.IP = ev.IP
		}
	case "rssi", "statistics", "disassociate":
		if old.RadioID != ev.RadioID || (ev.Kind != "rssi" && old.WLANID != ev.WLANID) {
			return
		}
		if ev.Kind == "disassociate" {
			next.State = "disconnected"
		} else {
			if ev.RSSI != nil {
				next.RSSI = ev.RSSI
				next.RSSIAt = ev.RSSIAt
				next.DisplayRSSI = nil
			}
			if ev.Statistics != nil {
				next.Statistics = ev.Statistics
			}
		}
	default:
		return
	}
	t.m[ev.MAC] = next
	t.recordTransition(old, true, next)
}
func (t *ClientTable) observeLocked(ev ClientEvent) {
	if t.observations == nil {
		t.observations = map[[6]byte]map[clientLocation]ClientEvent{}
	}
	if ev.Seen.Sub(t.observationsGC) > 10*time.Second {
		for mac, rows := range t.observations {
			for pos, v := range rows {
				if ev.Seen.Sub(v.Seen) > time.Minute {
					delete(rows, pos)
				}
			}
			if len(rows) == 0 {
				delete(t.observations, mac)
			}
		}
		t.observationsGC = ev.Seen
	}
	if len(t.observations) >= 4096 && t.observations[ev.MAC] == nil {
		return
	}
	if t.observations[ev.MAC] == nil {
		t.observations[ev.MAC] = map[clientLocation]ClientEvent{}
	}
	if len(t.observations[ev.MAC]) < 64 {
		t.observations[ev.MAC][clientPosition(ev)] = ev
	}
}

func (t *ClientTable) Observations(mac [6]byte) []ClientEvent {
	t.mu.Lock()
	defer t.mu.Unlock()
	out := []ClientEvent{}
	for _, v := range t.observations[mac] {
		if time.Since(v.Seen) < 30*time.Second {
			out = append(out, v)
		}
	}
	return out
}

// All returns a snapshot.
func (t *ClientTable) All() []ClientEvent {
	t.mu.Lock()
	defer t.mu.Unlock()
	out := make([]ClientEvent, 0, len(t.m))
	for _, ev := range t.m {
		if ev.VLAN != nil {
			v := *ev.VLAN
			ev.VLAN = &v
		}
		if ev.MLD != nil {
			v := *ev.MLD
			ev.MLD = &v
		}
		ev.Device = cloneDevice(ev.Device)
		ev.IPv6 = append([]string{}, ev.IPv6...)
		ev.MLOLinks = append([]capwap.AssociationLink{}, ev.MLOLinks...)
		out = append(out, ev)
	}
	return out
}

func sameClientService(a, b ClientEvent) bool {
	return (a.ServiceID == "" || b.ServiceID == "" || a.ServiceID == b.ServiceID) && (a.SSID == "" || b.SSID == "" || a.SSID == b.SSID)
}

// Protocol-only integrations can retain bool hooks; the controller uses the
// result-code hook so disabled service26, balance27 and capacity11 survive.
func (e *Engine) associationCode(ap string, radio, wlan uint8, mac [6]byte, rssi *int8, mlo *capwap.AssociationMLO) uint32 {
	if e.CheckAssociation != nil {
		return e.CheckAssociation(ap, radio, wlan, mac, rssi, mlo)
	}
	if e.AdmitStation != nil && !e.AdmitStation(ap, radio, wlan) {
		return 0x26
	}
	if e.AdmitClient != nil && !e.AdmitClient(ap, radio, wlan, mac, rssi) {
		return 0x27
	}
	return 0
}

func setStationResult(p *capwap.ParsedPacket, result uint32) {
	for i := range p.Elements {
		if p.Elements[i].Type == 0x21 {
			p.Elements[i].Value = capwap.AppendUint32BE(nil, result)
			return
		}
	}
	p.Elements = append(p.Elements, capwap.Element{Type: 0x21, Value: capwap.AppendUint32BE(nil, result)})
}
