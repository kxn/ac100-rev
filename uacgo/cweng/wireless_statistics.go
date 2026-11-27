package cweng

import (
	"time"
	"uacgo/capwap"
)

type RadioStatistics struct {
	capwap.APRadioStatistics
	ReceivedAt time.Time `json:"received_at"`
}

// Private54 updates individual slots (stats_db_ssid_update @7b1e44).
// An omitted slot is not a deletion; a new session starts with an empty set.
func MergeVAPStatistics(previous, updates []capwap.APVAPStatistics, radios int) []capwap.APVAPStatistics {
	out := append([]capwap.APVAPStatistics{}, previous...)
	for _, update := range updates {
		// Keep incremental storage within the declared AP and Go's slot
		// schema; invalid IDs cannot accumulate an unbounded raw cache.
		if update.Radio == 0 || int(update.Radio) > radios || update.Radio > 31 || update.WLAN == 0 || update.WLAN > 16 {
			continue
		}
		found := false
		for i, old := range out {
			if old.Radio == update.Radio && old.WLAN == update.WLAN {
				out[i], found = update, true
				break
			}
		}
		if !found {
			out = append(out, update)
		}
	}
	return out
}

// V6 stats_pkt_init @0x007b5d6c runs at priority80, before roaming90
// and station lifecycle100. A packet can carry both statistics and a trigger.
func (e *Engine) registerWirelessStatistics(sink ClientSink) {
	e.Register(9, 80, "v6_wireless_statistics", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		s := ctx.Session
		ap := sessionID(s)
		control := capwap.PrivStatisticsControl{A: 1, C: 1, D: 120, E: 120, F: 120}
		if e.StatisticsControl != nil {
			control = e.StatisticsControl()
		}
		privateElements(privatePacketForTypes(req, []uint16{0x52, 0x56, 0x54, 0x53, 0xbd}), func(typ uint16, b []byte) {
			// _stats_pkt_wtp_event_listener @7b5694 gates consumption,
			// not just the configuration sent to the AP. Late disabled
			// reports cannot refresh the facts used by roaming.
			if (typ == 0x52 || typ == 0x56) && control.A == 0 || typ == 0x54 && control.C == 0 || typ == 0x53 && control.B == 0 {
				return
			}
			switch typ {
			case 0x52:
				if p, err := capwap.ParsePrivStaStatisticsReq(b); err == nil {
					for _, a := range p.Records {
						rssi := int8(a.RSSI)
						sink.StationEvent(ClientEvent{Connection: s.Created, APID: ap, Seen: time.Now(), MAC: a.MAC, RadioID: a.Radio, WLANID: uint32(a.WLAN), Kind: "statistics", RSSI: &rssi, Statistics: stationStatistics(a)})
						if e.OnStationStatistics != nil {
							e.OnStationStatistics(ap, s.Created, a)
						}
					}
					if s.apEntry != nil && s.apEntry.SubCapabilities[95]&2 != 0 {
						if table, ok := sink.(interface {
							MLOStatisticsMissing(string, time.Time, []capwap.StaStatisticsRecord)
						}); ok {
							table.MLOStatisticsMissing(ap, s.Created, p.Records)
						}
					}
				}
			case 0x53:
				if p, err := capwap.ParsePrivRssiStatistics(b); err == nil {
					for id, row := range s.radioStatistics {
						if id > 0 && id <= 8 {
							row.ChannelLoad = p.ChannelLoad[id-1]
							row.NoiseFloor = p.NoiseFloor[id-1]
							row.ReceivedAt = time.Now()
							s.radioStatistics[id] = row
						}
					}
					if e.OnRSSIStatistics != nil {
						e.OnRSSIStatistics(ap, s.Created, *p)
					}
				}
			case 0x54:
				if p, err := capwap.ParsePrivApStatistics(b); err == nil {
					if s.apEntry != nil {
						s.vapStatistics = MergeVAPStatistics(s.vapStatistics, p.VAPs, s.apEntry.RadioCount)
					}
					if s.radioStatistics == nil {
						s.radioStatistics = map[uint8]RadioStatistics{}
					}
					for _, r := range p.Radios {
						if r.Radio > 0 && s.apEntry != nil && int(r.Radio) <= s.apEntry.RadioCount {
							s.radioStatistics[r.Radio] = RadioStatistics{r, time.Now()}
						}
					}
					if e.OnAPStatistics != nil {
						e.OnAPStatistics(ap, s.Created, *p)
					}
				}
			case 0xbd:
				if p, err := capwap.ParseStatePull(b); err == nil && !p.HasStations && p.HasBSSIDs && e.OnBSSIDLocations != nil {
					// The V6 stats listener gives subtype1 precedence over subtype2.
					e.OnBSSIDLocations(ap, s.Created, p.BSSIDs)
				}
			}
		})
		return true
	})
}
