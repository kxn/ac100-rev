package cweng

import (
	"time"
	"uacgo/capwap"
)

type RadioStatistics struct {
	capwap.APRadioStatistics
	ReceivedAt time.Time `json:"received_at"`
}

// V6 stats_pkt_init @0x007b5d6c runs at priority80, before roaming90
// and station lifecycle100. A packet can carry both statistics and a trigger.
func (e *Engine) registerWirelessStatistics(sink ClientSink) {
	e.Register(9, 80, "v6_wireless_statistics", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		s := ctx.Session
		ap := sessionID(s)
		privateElements(privatePacketForTypes(req, []uint16{0x52, 0x56, 0x54, 0x53, 0xbd}), func(typ uint16, b []byte) {
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
					s.vapStatistics = append([]capwap.APVAPStatistics{}, p.VAPs...)
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
