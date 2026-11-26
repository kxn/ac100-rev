package mobility

import "time"

// V6 statistics entries retain PHY/neighbor facts across a short disconnect.
// _stats_sta_deassoc_cb @7b42b4 sets deletion to now+905s (900 @8f5630,
// plus5); _stats_sta_idle_timer_handle @7a9b48 sweeps every60s. Association
// @7ae310 cancels deletion without clearing accumulated PHY capabilities.
type StationDB struct {
	entries   map[MAC]*stationFacts
	neighbors RSSINeighbors
	nextSweep time.Time
}
type stationFacts struct {
	Capabilities StationCapabilities
	DeleteAt     time.Time
}

func (s *StationDB) Start(now time.Time) {
	if s.nextSweep.IsZero() {
		s.nextSweep = now.Add(time.Minute)
	}
}
func (s *StationDB) Tick(now time.Time) {
	s.Start(now)
	if now.Before(s.nextSweep) {
		return
	}
	sweep := s.nextSweep.Add((now.Sub(s.nextSweep) / time.Minute) * time.Minute)
	for mac, entry := range s.entries {
		if !entry.DeleteAt.IsZero() && !entry.DeleteAt.After(sweep) {
			delete(s.entries, mac)
			s.neighbors.ForgetStation(mac)
		}
	}
	s.nextSweep = sweep.Add(time.Minute)
}
func (s *StationDB) Associate(mac MAC, now time.Time) {
	s.Tick(now)
	if s.entries == nil {
		s.entries = map[MAC]*stationFacts{}
	}
	if s.entries[mac] == nil {
		s.entries[mac] = &stationFacts{}
	}
	s.entries[mac].DeleteAt = time.Time{}
}
func (s *StationDB) Disconnect(mac MAC, now time.Time) {
	s.Tick(now)
	if e := s.entries[mac]; e != nil {
		e.DeleteAt = now.Add(905 * time.Second)
	}
}
func (s *StationDB) Observe(mac MAC, band int, word uint32, width int8) {
	if e := s.entries[mac]; e != nil {
		e.Capabilities.Observe(band, word, width)
	}
}
func (s *StationDB) Capabilities(mac MAC) StationCapabilities {
	if e := s.entries[mac]; e != nil {
		return e.Capabilities
	}
	return StationCapabilities{}
}
func (s *StationDB) UpdateNeighbor(mac MAC, n RSSINeighbor, age time.Duration) {
	if s.entries[mac] != nil {
		s.neighbors.Update(mac, n, age)
	}
}
func (s *StationDB) Neighbors(mac MAC, now time.Time, age time.Duration) []RSSINeighbor {
	s.Tick(now)
	return s.neighbors.Get(mac, now, age)
}
