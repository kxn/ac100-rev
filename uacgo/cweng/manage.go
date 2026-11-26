package cweng

import (
	"context"
	"encoding/binary"
	"encoding/json"
	"errors"
	"fmt"
	"sort"
	"time"
	"uacgo/capwap"
)

type APStatus struct {
	liveSession         *Session
	EntryID             uint32                   `json:"entry_id"`
	VAPStatistics       []capwap.APVAPStatistics `json:"vap_statistics"`
	RadioStatistics     []RadioStatistics        `json:"radio_statistics"`
	ProtectionLimits    map[string]int           `json:"protection_limits,omitempty"`
	RadioLinkage        *RadioLinkage            `json:"radio_linkage,omitempty"`
	MeshParent          string                   `json:"mesh_parent,omitempty"`
	Encapsulated        bool                     `json:"encapsulated,omitempty"`
	RadioModes          []RadioMode              `json:"radio_modes"`
	RadioMode           *RadioModeState          `json:"radio_mode,omitempty"`
	Mesh                *MeshReport              `json:"mesh,omitempty"`
	Ports               []PortCapability         `json:"ports"`
	ExtWirePhys         int                      `json:"downlink_port_count"`
	SupportTrunk        bool                     `json:"support_trunk"`
	ChannelScan         *ChannelScanReport       `json:"channel_scan,omitempty"`
	ARPScan             *ARPScanReport           `json:"arp_scan,omitempty"`
	HardwareID          string                   `json:"hardware_id"`
	FirmwareID          string                   `json:"firmware_id"`
	BlockedFirmware     []string                 `json:"blocked_firmware_ids"`
	SoftwareVersion     string                   `json:"software_version"`
	RRMReports          []RRMReport              `json:"rrm_reports"`
	EDCAPresets         *capwap.EDCAPresets      `json:"edca_presets,omitempty"`
	GeneralCapabilities []uint32                 `json:"general_capabilities"`
	SubCapabilities     map[uint16]uint32        `json:"sub_capabilities"`
	Features            map[string]bool          `json:"features"`
	Telemetry           *WirelessTelemetry       `json:"wireless_telemetry,omitempty"`
	RadioStatus         []RadioStatus            `json:"radio_status"`
	ReportedSSIDs       []ReportedSSID           `json:"reported_ssids"`
	Capabilities        []RadioCapability        `json:"capabilities"`
	HardwareVersion     string                   `json:"hardware_version"`
	ID                  string                   `json:"id"`
	Name                string                   `json:"name"`
	Model               string                   `json:"model"`
	MAC                 string                   `json:"mac"`
	Address             string                   `json:"address"`
	LocalIP             string                   `json:"local_ip"`
	Serial              string                   `json:"serial"`
	Location            string                   `json:"location"`
	State               string                   `json:"state"`
	Online              bool                     `json:"online"`
	Radios              int                      `json:"radios"`
	ConnectedAt         time.Time                `json:"connected_at"`
	LastSeen            time.Time                `json:"last_seen"`
}

func sessionID(s *Session) string {
	if s == nil {
		return ""
	}
	if s.apEntry != nil {
		if s.apEntry.MAC != "" {
			return s.apEntry.MAC
		}
		if s.apEntry.Serial != "" {
			return s.apEntry.Serial
		}
	}
	return s.Addr.String()
}
func (e *Engine) sessionList() []*Session {
	e.mu.Lock()
	defer e.mu.Unlock()
	out := make([]*Session, 0, len(e.sessions))
	for _, s := range e.sessions {
		out = append(out, s)
	}
	return out
}
func (e *Engine) APs() []APStatus {
	out := []APStatus{}
	for _, s := range e.sessionList() {
		s.mu.Lock()
		v := s.statusLocked()
		s.mu.Unlock()
		out = append(out, v)
	}
	sort.Slice(out, func(i, j int) bool { return out[i].ID < out[j].ID })
	return out
}
func (e *Engine) findAP(id string) *Session {
	for _, s := range e.sessionList() {
		s.mu.Lock()
		match := sessionID(s) == id && !s.dead
		s.mu.Unlock()
		if match {
			return s
		}
	}
	return nil
}

type CommandResult struct {
	Status   string  `json:"status"`
	Type     uint32  `json:"message_type"`
	Sequence uint8   `json:"sequence"`
	Result   *uint32 `json:"result_code,omitempty"`
}
type pendingCommand struct {
	expected uint32
	done     chan CommandResult
}

type sessionContextKey struct{}
type sessionReference struct {
	id        string
	connected time.Time
}

// PinAP keeps a reconciliation batch on the connection whose capabilities and
// identity were inspected. Reconnection requires a fresh batch and snapshot.
func PinAP(ctx context.Context, ap APStatus) context.Context {
	return context.WithValue(ctx, sessionContextKey{}, sessionReference{ap.ID, ap.ConnectedAt})
}

func (e *Engine) requestSession(ctx context.Context, s *Session, kind uint32, elements []capwap.Element) (CommandResult, error) {
	if kind%2 == 0 || !(kind == 7 || kind == 15 || kind == 17 || kind == 21 || kind == 23 || kind == 25 || kind == capwap.MsgIe1) {
		return CommandResult{}, fmt.Errorf("unsupported AC request type %d", kind)
	}
	p, err := capwap.NewParsedPacket(kind)
	if err != nil {
		return CommandResult{}, err
	}
	if ref, ok := ctx.Value(sessionContextKey{}).(sessionReference); ok && (!s.Created.Equal(ref.connected)) {
		return CommandResult{}, errors.New("AP session changed; reconciliation must restart")
	}
	return e.requestOnSession(ctx, s, p, elements)
}

// Request waits for the matching AP response. A successful socket write alone
// never produces an acknowledged status. Retries retain the CAPWAP sequence.
func (e *Engine) Request(ctx context.Context, id string, kind uint32, elements []capwap.Element) (CommandResult, error) {
	s := e.findAP(id)
	if s == nil {
		return CommandResult{}, errors.New("AP is offline")
	}
	return e.requestSession(ctx, s, kind, elements)
}

func (e *Engine) requestOnSession(ctx context.Context, s *Session, p *capwap.ParsedPacket, elements []capwap.Element) (CommandResult, error) {
	ticket, err := e.queueOnSession(ctx, s, p, elements)
	if err != nil {
		return CommandResult{}, err
	}
	return ticket.Wait(ctx)
}
func (e *Engine) executeOnSession(ctx context.Context, s *Session, p *capwap.ParsedPacket, elements []capwap.Element) (CommandResult, error) {
	if err := ctx.Err(); err != nil {
		return CommandResult{}, err
	}
	root := s.transportRoot()
	root.mu.Lock()
	if root.commandGate == nil {
		root.commandGate = make(chan struct{}, 1)
	}
	gate := root.commandGate
	root.mu.Unlock()
	select {
	case gate <- struct{}{}:
		defer func() { <-gate }()
	case <-ctx.Done():
		return CommandResult{}, ctx.Err()
	case <-s.closed:
		return CommandResult{}, errors.New("AP session closed")
	case <-root.closed:
		return CommandResult{}, errors.New("AP transport closed")
	}
	s.mu.Lock()
	if s.State != StateRun || s.dead {
		s.mu.Unlock()
		return CommandResult{}, errors.New("AP is not in RUN state")
	}
	if ref, ok := ctx.Value(sessionContextKey{}).(sessionReference); ok && ref.id != sessionID(s) {
		s.mu.Unlock()
		return CommandResult{}, errors.New("AP identity changed")
	}
	if s.pending == nil {
		s.pending = map[uint8]*pendingCommand{}
	}
	if len(s.pending) > 0 {
		s.mu.Unlock()
		return CommandResult{}, errors.New("AP already has a pending command")
	}
	if root != s {
		root.mu.Lock()
	}
	seq := root.OutSeq + 1
	if seq == 0 {
		seq = 1
	}
	root.OutSeq = seq
	if root != s {
		root.mu.Unlock()
	}
	s.OutSeq = seq
	p.Control.SeqNum = seq
	p.Elements = elements
	pending := &pendingCommand{expected: p.Control.MsgType + 1, done: make(chan CommandResult, 1)}
	s.pending[seq] = pending
	s.mu.Unlock()
	defer func() { s.mu.Lock(); delete(s.pending, seq); s.mu.Unlock() }()
	packet := p.Assemble()
	for i := 0; i < 3; i++ {
		s.mu.Lock()
		err := e.sendSession(s, packet)
		s.mu.Unlock()
		if err != nil {
			return CommandResult{}, err
		}
		timer := time.NewTimer(time.Second)
		select {
		case result := <-pending.done:
			timer.Stop()
			s.mu.Lock()
			dead := s.dead
			s.mu.Unlock()
			if dead {
				return CommandResult{}, errors.New("AP session closed")
			}
			if result.Result != nil && *result.Result != 0 {
				return result, fmt.Errorf("AP rejected command: result %d", *result.Result)
			}
			return result, nil
		case <-ctx.Done():
			timer.Stop()
			return CommandResult{}, ctx.Err()
		case <-s.closed:
			timer.Stop()
			return CommandResult{}, errors.New("AP session closed")
		case <-root.closed:
			timer.Stop()
			return CommandResult{}, errors.New("AP transport closed")
		case <-timer.C:
		}
	}
	return CommandResult{}, errors.New("AP acknowledgement timeout")
}
func (s *Session) acknowledge(req *capwap.ParsedPacket) {
	p := s.pending[req.Control.SeqNum]
	if p == nil || p.expected != req.Control.MsgType {
		return
	}
	result := CommandResult{Status: "acknowledged", Type: req.Control.MsgType, Sequence: req.Control.SeqNum}
	for _, el := range req.Elements {
		if el.Type == 0x21 {
			if len(el.Value) != 4 || result.Result != nil {
				return
			}
			v := binary.BigEndian.Uint32(el.Value)
			result.Result = &v
		}
	}
	// Both configuration response families used by the AC require exactly one
	// Result Code. Empty/malformed replies must never turn a write into success.
	if (req.Control.MsgType == 8 || req.Control.MsgType == capwap.MsgIe2) && result.Result == nil {
		return
	}
	select {
	case p.done <- result:
	default:
	}
}

// Session mutex held. Lifecycle and inventory consume the same typed facts.
func (s *Session) statusLocked() APStatus {
	v := APStatus{liveSession: s, ID: sessionID(s), Address: s.Addr.String(), State: StateNames[s.State], Online: s.State == StateRun && !s.dead, LastSeen: s.LastSeen, ConnectedAt: s.Created}
	if s.meshParent != nil {
		v.Encapsulated = true
		v.MeshParent = sessionID(s.meshParent)
	}
	if s.meshReport != nil {
		b, _ := json.Marshal(s.meshReport)
		_ = json.Unmarshal(b, &v.Mesh)
	}
	if s.channelScan != nil {
		r := *s.channelScan
		r.Channels = append([]capwap.ChannelScanSample{}, r.Channels...)
		v.ChannelScan = &r
	}
	if s.arpScan != nil {
		r := *s.arpScan
		r.Entries = append([]ARPScanEntry{}, r.Entries...)
		v.ARPScan = &r
	}
	for _, r := range s.rrmReports {
		b, _ := json.Marshal(r)
		var copy RRMReport
		_ = json.Unmarshal(b, &copy)
		v.RRMReports = append(v.RRMReports, copy)
	}
	if s.telemetry != nil {
		b, _ := json.Marshal(s.telemetry)
		_ = json.Unmarshal(b, &v.Telemetry)
	}
	for _, r := range s.radioStatus {
		v.RadioStatus = append(v.RadioStatus, r)
	}
	sort.Slice(v.RadioStatus, func(i, j int) bool { return v.RadioStatus[i].Radio < v.RadioStatus[j].Radio })
	v.VAPStatistics = append([]capwap.APVAPStatistics{}, s.vapStatistics...)
	for _, r := range s.radioStatistics {
		v.RadioStatistics = append(v.RadioStatistics, r)
	}
	sort.Slice(v.RadioStatistics, func(i, j int) bool { return v.RadioStatistics[i].Radio < v.RadioStatistics[j].Radio })
	v.ReportedSSIDs = append([]ReportedSSID{}, s.reportedSSIDs...)
	if a := s.apEntry; a != nil {
		if v.MeshParent == "" {
			v.MeshParent = a.MeshParent
		}
		if a.RadioLinkage != nil {
			b, _ := json.Marshal(a.RadioLinkage)
			_ = json.Unmarshal(b, &v.RadioLinkage)
		}
		v.HardwareID = a.HardwareID
		v.FirmwareID = a.FirmwareID
		v.BlockedFirmware = append([]string{}, a.BlockedFirmware...)
		v.SoftwareVersion = a.SoftwareVersion
		v.EDCAPresets = a.EDCAPresets
		v.GeneralCapabilities = append([]uint32{}, a.GeneralCapabilities...)
		v.SubCapabilities = map[uint16]uint32{}
		for key, val := range a.SubCapabilities {
			v.SubCapabilities[key] = val
		}
		v.Features = map[string]bool{}
		for name, bit := range map[string]int{"rf_mode_change": 92, "mesh": 44, "usb": 100, "storm_control": 14, "dhcp_defense": 15, "arp_defense": 16, "dhcpv6_defense": 30, "nd_defense": 31, "rssi_control": 1, "band_navigation": 3, "channel_optimization": 9, "fragmentation": 10, "ssid_rate_limit": 13, "new_security_format": 32, "frame_rate_control": 57, "edca": 61, "wifi6_features": 70, "multicast": 43, "multicast_per_ssid": 43, "band_steering": 21} {
			v.Features[name] = a.HasCapability(bit)
		}
		v.Features["arp_scan"] = a.HasCapability(16) && a.SubCapabilities[16]&1 != 0
		v.Features["arp_defense_mode_scope"] = a.HasCapability(16) && a.SubCapabilities[16]&1 != 0
		v.Features["mlo"] = a.SubCapabilities[0x5f]&2 != 0
		v.Features["vlan_pool"] = a.HasCapability(98) && a.SubCapabilities[0x5f]&8 != 0
		v.Features["multicast_to_unicast"] = a.HasCapability(99) && a.SubCapabilities[99]&1 != 0
		v.Features["edca_mode"] = a.SubCapabilities[0x3d]&2 != 0
		v.Ports = append([]PortCapability{}, a.Ports...)
		v.ExtWirePhys = a.ExtWirePhys
		v.SupportTrunk = a.SupportTrunk
		v.Features["trunk"] = a.SupportTrunk
		v.EntryID = a.EntryID
		v.Name = a.Name
		v.Serial = a.Serial
		v.Location = a.Location
		b, _ := json.Marshal(a.RadioModes)
		_ = json.Unmarshal(b, &v.RadioModes)
		if a.RadioMode != nil {
			mode := *a.RadioMode
			v.RadioMode = &mode
		}
		v.MAC = a.MAC
		v.Radios = a.RadioCount
		v.LocalIP = fmt.Sprintf("%d.%d.%d.%d", a.LocalIP[0], a.LocalIP[1], a.LocalIP[2], a.LocalIP[3])
		v.Model = a.Model
		v.HardwareVersion = a.HardwareVersion
		v.Capabilities = append([]RadioCapability{}, a.Capabilities...)
	}
	return v
}
