package admin

import (
	"fmt"
	"reflect"
	"uacgo/cweng"
)

func linkageRadioState(cfg Config, ap cweng.APStatus, id uint8) (RadioSetting, cweng.RadioCapability) {
	var cap cweng.RadioCapability
	for _, c := range ap.Capabilities {
		if c.RadioID == id {
			cap = c
		}
	}
	r := RadioSetting{AP: ap.ID, Radio: id}
	for _, v := range effectiveRadioConfig(cfg, ap).Radios {
		if v.AP == ap.ID && v.Radio == id {
			r = v
			break
		}
	}
	return r, cap
}
func linkageChannel(r RadioSetting, ap cweng.APStatus) int {
	if r.Channel != nil {
		return *r.Channel
	}
	for _, v := range ap.RadioStatus {
		if v.Radio == r.Radio {
			return int(v.Channel)
		}
	}
	return 0
}
func linkageBandwidth(r RadioSetting, c cweng.RadioCapability) int {
	if r.Advanced != nil {
		return r.Advanced.Bandwidth
	}
	return defaultRadioAdvanced(c).Bandwidth
}
func linkageEnabled(r RadioSetting) bool { return r.Enabled == nil || *r.Enabled }
func linkageStatus(mask uint32, on bool) bool {
	if on {
		return mask&1 != 0
	}
	return mask&2 != 0
}
func linkageRegion(cfg Config, ap cweng.APStatus) int {
	o, _ := effectiveAPOptions(cfg, ap)
	if o.RegionCode != nil && *o.RegionCode != 255 {
		return int(*o.RegionCode)
	}
	return 0
}
func linkageRowActive(row cweng.RadioLinkageRow, p *cweng.RadioLinkage, region int) bool {
	return row.TableMask&(1<<p.TableID) != 0 && row.FeatureMask&1 != 0 && (len(row.Regions) == 0 || hasInt(row.Regions, region))
}
func linkageMemberFits(r RadioSetting, c cweng.RadioCapability, ap cweng.APStatus, member cweng.RadioLinkageMember) bool {
	return linkageStatus(member.StatusMask, linkageEnabled(r)) && hasInt(member.Bandwidths, linkageBandwidth(r, c)) && hasInt(member.Channels, linkageChannel(r, ap))
}
func putLinkedRadio(cfg *Config, r RadioSetting) {
	for i, v := range cfg.Radios {
		if v.AP == r.AP && v.Radio == r.Radio {
			cfg.Radios[i] = r
			return
		}
	}
	cfg.Radios = append(cfg.Radios, r)
}

// The edited radio remains exact. Choose a reported legal combination with
// minimal changes to peers, matching the original's linked-radio operation.
// All peer values are validated before the caller persists the batch.
func planRadioLinkage(cfg *Config, ap cweng.APStatus, edited uint8) error {
	p := ap.RadioLinkage
	if p == nil || len(p.Rows) == 0 {
		return nil
	}
	r, c := linkageRadioState(*cfg, ap, edited)
	channel := linkageChannel(r, ap)
	region := linkageRegion(*cfg, ap)
	bestCost := int(^uint(0) >> 1)
	var best []RadioSetting
	for _, row := range p.Rows {
		if !linkageRowActive(row, p, region) {
			continue
		}
		var source *cweng.RadioLinkageMember
		for _, m := range row.Radios {
			if m.Radio == edited {
				copy := m
				source = &copy
			}
		}
		if source == nil || !linkageMemberFits(r, c, ap, *source) {
			continue
		}
		candidate := []RadioSetting{}
		cost := 0
		valid := true
		for _, member := range row.Radios {
			if member.Radio == edited {
				continue
			}
			peer, cap := linkageRadioState(*cfg, ap, member.Radio)
			if cap.RadioID == 0 {
				valid = false
				break
			}
			before := peer
			if !linkageStatus(member.StatusMask, linkageEnabled(peer)) {
				switch {
				case member.StatusMask&1 != 0:
					v := true
					peer.Enabled = &v
				case member.StatusMask&2 != 0:
					v := false
					peer.Enabled = &v
				default:
					valid = false
				}
				cost += 10
			}
			bw := linkageBandwidth(peer, cap)
			if !hasInt(member.Bandwidths, bw) {
				found := false
				for _, v := range member.Bandwidths {
					if hasInt(cap.Bandwidths, v) {
						bw = v
						found = true
						break
					}
				}
				if !found {
					valid = false
					break
				}
				a := defaultRadioAdvanced(cap)
				if peer.Advanced != nil {
					a = *peer.Advanced
				}
				a.Bandwidth = bw
				peer.Advanced = &a
				cost++
			}
			ch := linkageChannel(peer, ap)
			if source.EqualChannel {
				ch = channel
			} else if !hasInt(member.Channels, ch) {
				ch = -1
				if member.DefaultChannel != nil && hasInt(member.Channels, *member.DefaultChannel) && (*member.DefaultChannel == 0 || hasInt(cap.Channels, *member.DefaultChannel)) {
					ch = *member.DefaultChannel
				}
				if ch < 0 {
					for _, v := range member.Channels {
						if v == 0 || hasInt(cap.Channels, v) {
							ch = v
							break
						}
					}
				}
			}
			if ch < 0 || !hasInt(member.Channels, ch) || ch != 0 && !hasInt(cap.Channels, ch) {
				valid = false
				break
			}
			if ch != linkageChannel(peer, ap) {
				value := ch
				peer.Channel = &value
				cost++
			}
			if err := validateAdvanced(peer, ap, cap); err != nil {
				valid = false
				break
			}
			if !reflect.DeepEqual(before, peer) {
				candidate = append(candidate, peer)
			}
		}
		if valid && cost < bestCost {
			bestCost = cost
			best = candidate
		}
	}
	if bestCost == int(^uint(0)>>1) {
		return fmt.Errorf("AP 上报的射频关联表不允许此状态、信道与带宽组合")
	}
	cfg.Radios = append([]RadioSetting{}, cfg.Radios...)
	for _, peer := range best {
		putLinkedRadio(cfg, peer)
	}
	return nil
}

// Validate an already-formed batch without rewriting another explicitly
// requested setting (imports, RRM and ACS can use the same constraints).
func validateRadioLinkage(cfg Config, ap cweng.APStatus) error {
	p := ap.RadioLinkage
	if p == nil || len(p.Rows) == 0 {
		return nil
	}
	region := linkageRegion(cfg, ap)
	for _, row := range p.Rows {
		if !linkageRowActive(row, p, region) {
			continue
		}
		ok := true
		equal := -1
		for _, member := range row.Radios {
			r, c := linkageRadioState(cfg, ap, member.Radio)
			if c.RadioID == 0 || !linkageMemberFits(r, c, ap, member) {
				ok = false
				break
			}
			if member.EqualChannel {
				if equal >= 0 && equal != linkageChannel(r, ap) {
					ok = false
					break
				}
				equal = linkageChannel(r, ap)
			}
		}
		if ok {
			return nil
		}
	}
	return fmt.Errorf("AP %s 的关联射频组合不符合其上报能力", ap.ID)
}
