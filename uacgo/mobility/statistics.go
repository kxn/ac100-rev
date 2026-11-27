package mobility

import "time"

// SupportWord is _stats_sta_support_cal @0x0040f314. The new report owns
// the upper flags; NSS, PHY and MCS accumulate component-wise maxima.
func SupportWord(old, current uint32) uint32 {
	if old == 0 {
		return current
	}
	if current == 0 {
		return old
	}
	return current&0xffff0000 | max(old&15, current&15) | max(old>>4&15, current>>4&15)<<4 | max(old>>8&255, current>>8&255)<<8
}

type StationCapabilities struct {
	Ready [2]bool
	Word  [2]uint32
	Width [2]int8
}

func (s *StationCapabilities) Observe(band int, word uint32, width int8) {
	if band < 0 || band > 1 {
		return
	}
	if !s.Ready[band] {
		s.Width[band] = -1
	}
	s.Word[band] = SupportWord(s.Word[band], word)
	if width > s.Width[band] {
		s.Width[band] = width
	}
	s.Ready[band] = true
}
func (s StationCapabilities) PHY(band int) PHY {
	return s.PHYFor(V6Policy, band)
}

type RSSINeighbor struct {
	AP          string
	Radio, WLAN uint8
	RSSI        int8
	At          time.Time
}
type RSSINeighbors struct{ rows map[MAC][]RSSINeighbor }

func NeighborAge(interval int) time.Duration { return time.Duration((interval*3+1)>>1) * time.Second }

// Update is stats_db_sta_update_nbr @0x007aecb8: refresh in place;
// otherwise first expired, free slot, or first weakest (equal RSSI allowed).
func (s *RSSINeighbors) Update(mac MAC, n RSSINeighbor, age time.Duration) {
	if s.rows == nil {
		s.rows = map[MAC][]RSSINeighbor{}
	}
	rows := s.rows[mac]
	expired, weak := -1, -1
	weakRSSI := int8(0)
	for i, r := range rows {
		if r.AP == n.AP && r.Radio == n.Radio {
			rows[i] = n
			s.rows[mac] = rows
			return
		}
		if expired < 0 {
			if n.At.Sub(r.At) >= age || n.At.Before(r.At) {
				expired = i
			} else if r.RSSI < weakRSSI {
				weak, weakRSSI = i, r.RSSI
			}
		}
	}
	if expired >= 0 {
		rows[expired] = n
	} else if len(rows) < 12 {
		rows = append(rows, n)
	} else if weak >= 0 && n.RSSI >= rows[weak].RSSI {
		rows[weak] = n
	}
	s.rows[mac] = rows
}
func (s *RSSINeighbors) Get(mac MAC, now time.Time, age time.Duration) []RSSINeighbor {
	out := []RSSINeighbor{}
	for _, r := range s.rows[mac] {
		if !now.Before(r.At) && now.Sub(r.At) < age {
			out = append(out, r)
		}
	}
	return out
}
func (s *RSSINeighbors) ForgetStation(mac MAC) { delete(s.rows, mac) }
func (s *RSSINeighbors) ForgetAP(ap string) {
	for mac, rows := range s.rows {
		out := rows[:0]
		for _, r := range rows {
			if r.AP != ap {
				out = append(out, r)
			}
		}
		if len(out) == 0 {
			delete(s.rows, mac)
		} else {
			s.rows[mac] = out
		}
	}
}
