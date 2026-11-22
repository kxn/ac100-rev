package cweng

import (
	"sync"

	"uacgo/capwap"
)

// SteerRegistry is an in-memory TriggerLookup for the steering engine:
// AP/radio stats and BSS rows are registered as the APs report them
// (join/attach,0x58 trigger radio header, stats reports), station rows as
// they associate (wsta events). It satisfies both TriggerLookup and
// APSessionResolver when paired with SetSession.
type SteerRegistry struct {
	mu       sync.Mutex
	stas     map[[6]byte]StaContext
	bss      map[[6]byte]BSSRow
	radio    map[uint16]RadioStats
	meshCap  map[uint16]int
	sessions map[[6]byte]*Session
}

// BSSRow is one managed BSS (AP+radio+wlan).
type BSSRow struct {
	APID       uint16
	APMAC      [6]byte
	RadioID    uint8
	WLANID     uint8
	Channel    uint8
	ChlLoad    uint8
	NoiseFloor int8
}

// RadioStats is the latest radio environment sample.
type RadioStats struct {
	ChlLoad    uint8
	NoiseFloor int8
}

// NewSteerRegistry creates empty registries.
func NewSteerRegistry() *SteerRegistry {
	return &SteerRegistry{
		stas:     map[[6]byte]StaContext{},
		bss:      map[[6]byte]BSSRow{},
		radio:    map[uint16]RadioStats{},
		meshCap:  map[uint16]int{},
		sessions: map[[6]byte]*Session{},
	}
}

// RegisterSta records an association.
func (r *SteerRegistry) RegisterSta(sta StaContext) {
	r.mu.Lock()
	defer r.mu.Unlock()
	r.stas[sta.MAC] = sta
}

// ForgetSta removes an association.
func (r *SteerRegistry) ForgetSta(mac [6]byte) {
	r.mu.Lock()
	defer r.mu.Unlock()
	delete(r.stas, mac)
}

// RegisterBSS records/updates one BSS row.
func (r *SteerRegistry) RegisterBSS(bssid [6]byte, row BSSRow) {
	r.mu.Lock()
	defer r.mu.Unlock()
	r.bss[bssid] = row
}

// SetRadioStats records the environment sample of one AP radio.
func (r *SteerRegistry) SetRadioStats(apID uint16, s RadioStats) {
	r.mu.Lock()
	defer r.mu.Unlock()
	r.radio[apID] = s
}

// SetMeshRate2Cap records the backhaul cap of a mesh RE (0 clears).
func (r *SteerRegistry) SetMeshRate2Cap(apID uint16, mbps int) {
	r.mu.Lock()
	defer r.mu.Unlock()
	r.meshCap[apID] = mbps
}

// SetSession maps an AP MAC to its live session (for 0x59 pushes).
func (r *SteerRegistry) SetSession(apMAC [6]byte, s *Session) {
	r.mu.Lock()
	defer r.mu.Unlock()
	r.sessions[apMAC] = s
}

// StaForTrigger implements TriggerLookup with the reporting-radio match.
func (r *SteerRegistry) StaForTrigger(mac [6]byte, reportAPID uint16, radioID, wlanID uint8) (StaContext, bool) {
	r.mu.Lock()
	defer r.mu.Unlock()
	sta, ok := r.stas[mac]
	if !ok {
		return StaContext{}, false
	}
	if reportAPID != 0 && sta.APID != reportAPID {
		return StaContext{}, false
	}
	if sta.RadioID != radioID || sta.WLANID != wlanID {
		return StaContext{}, false
	}
	return sta, true
}

// APByBSSID implements TriggerLookup.
func (r *SteerRegistry) APByBSSID(bssid [6]byte) (uint16, [6]byte, uint8, uint8, uint8, uint8, int8, bool) {
	r.mu.Lock()
	defer r.mu.Unlock()
	row, ok := r.bss[bssid]
	if !ok {
		return 0, [6]byte{}, 0, 0, 0, 0, 0, false
	}
	load, nf := row.ChlLoad, row.NoiseFloor
	if s, ok := r.radio[row.APID]; ok {
		load, nf = s.ChlLoad, s.NoiseFloor
	}
	return row.APID, row.APMAC, row.RadioID, row.WLANID, row.Channel, load, nf, true
}

// MeshRate2Cap implements TriggerLookup.
func (r *SteerRegistry) MeshRate2Cap(apID uint16) int {
	r.mu.Lock()
	defer r.mu.Unlock()
	return r.meshCap[apID]
}

// SteerCapsFor implements TriggerLookup using the STA's recorded caps
// (WLAN caps unknown → same as STA caps; the min intersection is then
// the STA caps).
func (r *SteerRegistry) SteerCapsFor(sta StaContext, _ uint16, _, _ uint8, _ uint8) (SteerCaps, SteerCaps, bool) {
	r.mu.Lock()
	defer r.mu.Unlock()
	cur, ok := r.stas[sta.MAC]
	if !ok {
		return SteerCaps{}, SteerCaps{}, false
	}
	return cur.Caps, cur.Caps, true
}

// SessionByAPMAC implements APSessionResolver.
func (r *SteerRegistry) SessionByAPMAC(mac [6]byte) *Session {
	r.mu.Lock()
	defer r.mu.Unlock()
	return r.sessions[mac]
}

// NoteTrigger implements TriggerStatsSink: the 0x58 report is a live data
// source — the reporting radio's channel load / noise floor and each
// station's current RSSI refresh the registries.
func (r *SteerRegistry) NoteTrigger(reportAPID uint16, trig *capwap.PrivRoamingTrigger) {
	r.mu.Lock()
	defer r.mu.Unlock()
	r.radio[reportAPID] = RadioStats{ChlLoad: trig.ChannelLoad, NoiseFloor: trig.NoiseFloor}
	for _, st := range trig.Stations {
		if sta, ok := r.stas[st.MAC]; ok {
			sta.RSSI = st.RSSI
			r.stas[st.MAC] = sta
		}
	}
}

// StationEvent implements ClientSink: wsta station reports (element
// 0x34) populate the registry's STA rows; RSSI/AP context is refreshed
// later by NoteTrigger.
func (r *SteerRegistry) StationEvent(ev ClientEvent) {
	r.mu.Lock()
	defer r.mu.Unlock()
	sta := r.stas[ev.MAC]
	sta.MAC = ev.MAC
	sta.RadioID = ev.RadioID
	r.stas[ev.MAC] = sta
}

// FanClientSink delivers each station event to several sinks.
type FanClientSink []ClientSink

// StationEvent implements ClientSink.
func (f FanClientSink) StationEvent(ev ClientEvent) {
	for _, s := range f {
		s.StationEvent(ev)
	}
}
