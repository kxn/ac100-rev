package cweng

import (
	"net"
	"sync"
	"time"

	"uacgo/capwap"
)

// wsta subsystem (client tracking).
//
// Registry evidence: uac_wstation registers msg 9 (WTP Event Request) at
// priority 100 (_uac_wsta_pkt_wtp_event_listener @0x6360ec). The listener
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
	s := &ClientStatistics{NegotiatedMbps: a.U16a, Bandwidth: int8(a.U8[5])}
	if a.U16b&1 != 0 {
		s.RetryPercent = &a.U8b[0]
	}
	if a.U16b&2 != 0 {
		s.LossPercent = &a.U8b[1]
	}
	if a.U16b&4 != 0 {
		s.UpstreamKbps = &a.U32[0]
	}
	if a.U16b&8 != 0 {
		s.DownstreamKbps = &a.U32[1]
	}
	if a.U16b&16 != 0 {
		s.UploadKB = &a.U32[2]
	}
	if a.U16b&32 != 0 {
		s.DownloadKB = &a.U32[3]
	}
	return s
}

type ClientEvent struct {
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
	e.Register(9, 100, "uac_wsta_wtp_event", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		for _, el := range req.Elements {
			if el.Type == 0x0034 {
				if l, err := capwap.ParseStaInfoList(el.Value); err == nil {
					for _, en := range l.Entries {
						sink.StationEvent(ClientEvent{
							Kind: "associate", State: "connected", WLANID: l.WLANID,
							APID: sessionID(ctx.Session), Seen: time.Now(),
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
						sink.StationEvent(ClientEvent{APID: sessionID(ctx.Session), Seen: time.Now(), MAC: mac, RadioID: l.RadioID, Kind: "rssi", RSSI: &rssi})
					}
				}
			}
		}
		privateElements(req, func(typ uint16, b []byte) {
			switch typ {
			case 1:
				a, err := capwap.ParseStaAuthReq(b)
				if err != nil {
					return
				}
				result := uint32(0)
				if a.Radio == 0 || a.WlanID == 0 || a.MAC == [6]byte{} || a.MAC[0]&1 != 0 || (ctx.Session.apEntry != nil && int(a.Radio) > ctx.Session.apEntry.RadioCount) {
					result = 0x25
				}
				if e.AdmitStation != nil && !e.AdmitStation(sessionID(ctx.Session), a.Radio, a.WlanID) {
					result = 0x25
				}
				if e.AdmitClient != nil && !e.AdmitClient(sessionID(ctx.Session), a.Radio, a.WlanID, a.MAC, nil) {
					result = 0x25
				}
				permit := capwap.StaAuthResult{Radio: a.Radio, WlanID: a.WlanID, MAC: a.MAC, Result: result, Backfill: a.Backfill}
				rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0x13, []capwap.PrivElementValue{{Type: 0x13, Value: permit.AssembleValue()}})})
			case 0xb:
				if a, err := capwap.ParseStaDiscovery(b); err == nil {
					sink.StationEvent(ClientEvent{APID: sessionID(ctx.Session), RadioID: a.Radio, WLANID: uint32(a.WlanID), MAC: a.MAC, Kind: "probe", Seen: time.Now()})
				}
			case 0x58:
				if a, err := capwap.ParsePrivRoamingTrigger(b); err == nil && e.OnRoamingTrigger != nil {
					e.OnRoamingTrigger(sessionID(ctx.Session), ctx.Session.Created, *a)
				}
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
					result = 0x25
				}
				if e.AdmitStation != nil && !e.AdmitStation(sessionID(ctx.Session), a.Radio, a.WLAN) {
					result = 0x25
				}
				var signal *int8
				if a.RSSI != nil && *a.RSSI >= -128 && *a.RSSI <= 0 {
					v := int8(*a.RSSI)
					signal = &v
				}
				if e.AdmitClient != nil && !e.AdmitClient(sessionID(ctx.Session), a.Radio, a.WLAN, a.MAC, signal) {
					result = 0x25
				}
				rsp.Elements = append(rsp.Elements, capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 4, []capwap.PrivElementValue{{Type: 4, Value: a.Result(result)}})})
				if result == 0 {
					ev := ClientEvent{APID: sessionID(ctx.Session), Seen: time.Now(), MAC: a.MAC, RadioID: a.Radio, WLANID: uint32(a.WLAN), Kind: "associate", State: "associating"}
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
						if err != nil || ctx.Session.apEntry == nil || ctx.Session.apEntry.SubCapabilities[0x5f]&2 == 0 {
							response.Word = 0x25
						} else {
							if e.AdmitStation != nil {
								for _, link := range mlo.Links {
									if !e.AdmitStation(sessionID(ctx.Session), link.Radio, link.WLAN) {
										response.Word = 0x25
									}
								}
							}
							if e.AdmitClient != nil {
								for _, link := range mlo.Links {
									if !e.AdmitClient(sessionID(ctx.Session), link.Radio, link.WLAN, a.MAC, nil) {
										response.Word = 0x25
									}
								}
							}
							response.Sub = append(response.Sub, capwap.Element{Type: 2, Value: []byte{}})
						}
					case 2:
						if len(sub.Value) < 4 {
							response.Word = 0x25
						} // association metadata, not an admission failure
					}
				}

				if a.MAC == [6]byte{} || a.MAC[0]&1 != 0 || a.Radio == 0 || a.WLAN == 0 || (ctx.Session.apEntry != nil && int(a.Radio) > ctx.Session.apEntry.RadioCount) {
					response.Word = 0x25
				}
				if e.AdmitStation != nil && !e.AdmitStation(sessionID(ctx.Session), a.Radio, a.WLAN) {
					response.Word = 0x25
				}
				if e.AdmitClient != nil && !e.AdmitClient(sessionID(ctx.Session), a.Radio, a.WLAN, a.MAC, nil) {
					response.Word = 0x25
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
					state := "associating"
					if a.Phase != 0 {
						state = "connected"
					}
					ev := ClientEvent{APID: sessionID(ctx.Session), Seen: time.Now(), MAC: a.MAC, RadioID: a.Radio, WLANID: uint32(a.WLAN), Kind: "associate", State: state}
					if mlo != nil {
						ev.MLD = &mlo.MAC
						ev.MLOLinks = append([]capwap.AssociationLink{}, mlo.Links...)
					}
					sink.StationEvent(ev)
				}
			case 3:
				if a, err := capwap.ParseStaDeassoc(b); err == nil {
					sink.StationEvent(ClientEvent{APID: sessionID(ctx.Session), Seen: time.Now(), MAC: a.MAC, RadioID: a.Radio, WLANID: uint32(a.WlanID), Kind: "disassociate", State: "disconnected"})
				}
			case 0x4d:
				if rows, err := capwap.ParseStationAddressList(b); err == nil {
					for _, r := range rows {
						sink.StationEvent(ClientEvent{APID: sessionID(ctx.Session), Seen: time.Now(), MAC: r.MAC, Kind: "ip", IP: net.IP(r.Address).String()})
					}
				}
			case 0x52:
				if stats, err := capwap.ParsePrivStaStatisticsReq(b); err == nil {
					for _, a := range stats.Records {
						rssi := int8(a.U8[4])
						sink.StationEvent(ClientEvent{APID: sessionID(ctx.Session), Seen: time.Now(), MAC: a.MAC, RadioID: a.U8[0], WLANID: uint32(a.U8[1]), Kind: "statistics", RSSI: &rssi, Statistics: stationStatistics(a)})
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
	// Set before events start; resolution occurs outside the table lock.
	ResolveService func(string, uint8, uint32) (string, string)
	transitions    []ClientTransition
	transitionSeq  uint64
	mu             sync.Mutex
	m              map[[6]byte]ClientEvent
	candidates     map[[6]byte]map[clientLocation]ClientEvent
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
	return &ClientTable{m: make(map[[6]byte]ClientEvent), candidates: map[[6]byte]map[clientLocation]ClientEvent{}}
}

// StationEvent records the latest event per MAC.
func (t *ClientTable) StationEvent(ev ClientEvent) {
	if t.ResolveService != nil && ev.SSID == "" && (ev.Kind == "associate" || ev.Kind == "statistics") {
		ev.ServiceID, ev.SSID = t.ResolveService(ev.APID, ev.RadioID, ev.WLANID)
	}
	t.mu.Lock()
	defer t.mu.Unlock()
	if ev.Seen.IsZero() {
		ev.Seen = time.Now()
	}
	if ev.RSSI != nil {
		ev.RSSIAt = ev.Seen
	}
	old, known := t.m[ev.MAC]
	if ev.MAC == [6]byte{} || ev.MAC[0]&1 != 0 {
		return
	}
	previous := old
	if known && ev.Kind != "associate" {
		if old.SSID != "" {
			ev.SSID = old.SSID
		}
		if old.ServiceID != "" {
			ev.ServiceID = old.ServiceID
		}
	}
	defer func() { t.recordTransition(previous, known, t.m[ev.MAC]) }()
	if ev.Kind == "probe" || ev.RSSI != nil {
		if t.observations == nil {
			t.observations = map[[6]byte]map[clientLocation]ClientEvent{}
		}
		// Prune globally as well as per station so random probe MACs cannot grow
		// the table without bound.
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
		if len(t.observations) < 4096 || t.observations[ev.MAC] != nil {
			if t.observations[ev.MAC] == nil {
				t.observations[ev.MAC] = map[clientLocation]ClientEvent{}
			}
			if len(t.observations[ev.MAC]) < 64 {
				t.observations[ev.MAC][clientPosition(ev)] = ev
			}
		}
	}
	if ev.Kind == "probe" {
		return
	}
	if known && ev.Seen.Before(old.Seen) {
		return
	}
	if ev.Kind == "ip" && net.ParseIP(ev.IP) == nil {
		return
	}
	if ev.Kind == "associate" && ev.State == "associating" {
		if t.candidates[ev.MAC] == nil {
			t.candidates[ev.MAC] = map[clientLocation]ClientEvent{}
		}
		for pos, candidate := range t.candidates[ev.MAC] {
			if ev.Seen.Sub(candidate.Seen) > 5*time.Minute {
				delete(t.candidates[ev.MAC], pos)
			}
		}
		t.candidates[ev.MAC][clientPosition(ev)] = ev
		// Admission is permission to try. It does not move an established
		// client or downgrade its connection while another radio probes it.
		if known && old.State == "connected" {
			return
		}
	}
	if known && ev.Kind == "statistics" && ev.Statistics != nil && clientPosition(old) != clientPosition(ev) && old.RadioID != 0 {
		candidate, ok := t.candidates[ev.MAC][clientPosition(ev)]
		if !ok || ev.Seen.Sub(candidate.Seen) > 5*time.Minute {
			return
		}
		candidate.State = "connected"
		candidate.Seen = ev.Seen
		candidate.Statistics = ev.Statistics
		candidate.RSSI = ev.RSSI
		candidate.RSSIAt = ev.RSSIAt
		candidate.ConnectedAt = ev.Seen
		t.m[ev.MAC] = candidate
		delete(t.candidates, ev.MAC)
		return
	}
	if ev.Kind == "ip" && known {
		if ev.APID == old.APID {
			if ip := net.ParseIP(ev.IP); ip != nil && ip.To4() == nil {
				found := false
				for _, v := range old.IPv6 {
					found = found || v == ev.IP
				}
				if !found {
					old.IPv6 = append(append([]string{}, old.IPv6...), ev.IP)
				}
				if net.ParseIP(old.IP).To4() == nil {
					old.IP = ev.IP
				}
			} else {
				old.IP = ev.IP
			}
			if old.State == "associating" || old.State == "observed" {
				old.State = "connected"
				if old.ConnectedAt.IsZero() {
					old.ConnectedAt = ev.Seen
				}
			}
			old.Seen = ev.Seen
			t.m[ev.MAC] = old
		}
		return
	}
	if ev.Kind == "associate" && known && old.APID == ev.APID {
		if old.State != "disconnected" && old.WLANID == ev.WLANID && sameClientService(old, ev) {
			ev.IP = old.IP
			ev.IPv6 = append([]string{}, old.IPv6...)
			ev.ConnectedAt = old.ConnectedAt
			ev.VLAN = old.VLAN
			if old.RadioID == ev.RadioID {
				ev.Statistics = old.Statistics
			}
		}
	}
	if ev.Kind == "associate" && ev.ConnectedAt.IsZero() {
		ev.ConnectedAt = ev.Seen
	}
	if known && ev.Kind == "statistics" && old.APID == ev.APID && old.RadioID == 0 {
		old.RadioID = ev.RadioID
		old.WLANID = ev.WLANID
	}
	if known && ev.Kind != "associate" {
		if old.APID != ev.APID || old.RadioID != ev.RadioID || (ev.Kind != "rssi" && old.WLANID != ev.WLANID) {
			return
		}
		if ev.Kind == "disassociate" {
			ev.VLAN = old.VLAN
			ev.IP, ev.IPv6 = old.IP, append([]string{}, old.IPv6...)
			ev.ConnectedAt = old.ConnectedAt
		}
		if ev.Kind == "rssi" || ev.Kind == "statistics" {
			if old.State == "disconnected" {
				return
			}
			if old.SSID == "" {
				old.SSID = ev.SSID
				old.ServiceID = ev.ServiceID
			}
			old.RSSI = ev.RSSI
			old.RSSIAt = ev.RSSIAt
			if ev.Statistics != nil {
				if old.State == "associating" || old.State == "observed" {
					old.State = "connected"
					if old.ConnectedAt.IsZero() {
						old.ConnectedAt = ev.Seen
					}
				}
				old.Statistics = ev.Statistics
			}
			old.Seen = ev.Seen
			t.m[ev.MAC] = old
			return
		}
	}
	if ev.State == "" {
		ev.State = "observed"
		if ev.Kind == "statistics" && ev.Statistics != nil {
			ev.State = "connected"
			ev.ConnectedAt = ev.Seen
		}
	}
	t.m[ev.MAC] = ev
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
		ev.IPv6 = append([]string{}, ev.IPv6...)
		ev.MLOLinks = append([]capwap.AssociationLink{}, ev.MLOLinks...)
		out = append(out, ev)
	}
	return out
}

// Network facts do not constitute an association report. Merge only into an
// already confirmed station on the same AP; never resurrect an offline client
// or let a wired host/old AP change the wireless location.
func (t *ClientTable) NetworkInfo(ap string, mac [6]byte, ip string, connected time.Time) {
	t.mu.Lock()
	defer t.mu.Unlock()
	v, ok := t.m[mac]
	if !ok || v.APID != ap || v.State != "connected" || time.Since(v.Seen) > 6*time.Minute {
		return
	}
	if addr := net.ParseIP(ip); addr != nil && !addr.IsUnspecified() && !addr.IsMulticast() {
		v.IP = addr.String()
	}
	if !connected.IsZero() && !connected.After(time.Now()) {
		v.ConnectedAt = connected
	}
	t.m[mac] = v
}

func sameClientService(a, b ClientEvent) bool {
	return (a.ServiceID == "" || b.ServiceID == "" || a.ServiceID == b.ServiceID) && (a.SSID == "" || b.SSID == "" || a.SSID == b.SSID)
}
