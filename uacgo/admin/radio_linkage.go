package admin

import (
	"fmt"
	"sort"
	"uacgo/cweng"
)

func linkageRadioState(cfg Config, ap cweng.APStatus, id uint8) (RadioSetting, cweng.RadioCapability) {
	var cap cweng.RadioCapability
	for _, c := range ap.Capabilities {
		if c.RadioID == id {
			cap = c
		}
	}
	r := defaultAPRadio(ap, cap)
	r.Radio = id
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
	return linkageStatus(member.StatusMask, linkageEnabled(r)) && linkageBandwidthAllowed(member, linkageBandwidth(r, c)) && hasInt(member.Channels, linkageChannel(r, ap))
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

// planRadioLinkage follows rdmngr_db_rrst_matched_row_search_strategy
// @73abf0 and _uac_rdmngr_linked_modify @714b9c. Rows are ordered policy,
// not candidates in a minimum-change optimization. Radio enable state is never
// changed by the peer-radio strategy.
func planRadioLinkage(cfg *Config, ap cweng.APStatus, edited uint8) error {
	p := ap.RadioLinkage
	if p == nil || len(p.Rows) == 0 {
		return nil
	}
	source, sourceCap := linkageRadioState(*cfg, ap, edited)
	var candidates []cweng.RadioLinkageRow
	for _, row := range p.Rows {
		if !linkageRowActive(row, p, linkageRegion(*cfg, ap)) {
			continue
		}
		for _, member := range row.Radios {
			if member.Radio == edited && linkageMemberFits(source, sourceCap, ap, member) {
				candidates = append(candidates, row)
				break
			}
		}
	}
	// The source routine returns index -1 (no peer changes) for no match.
	// Per-radio channel/bandwidth normalization is a separate operation.
	if len(candidates) == 0 {
		return nil
	}
	peers := append([]cweng.RadioCapability{}, ap.Capabilities...)
	sort.SliceStable(peers, func(i, j int) bool { return peers[i].RadioID < peers[j].RadioID })
	// pre_match @73aa14 retains its failed flag between rows. Only the first
	// candidate can make the full no-change test succeed; singleton rows can
	// still short circuit later. Preserve this observable V6 behavior.
	noChange := true
	for _, row := range candidates {
		if len(row.Radios) == 1 {
			return nil
		}
		for _, cap := range peers {
			if cap.RadioID == edited {
				continue
			}
			peer, _ := linkageRadioState(*cfg, ap, cap.RadioID)
			for _, member := range row.Radios {
				if member.Radio == cap.RadioID && (!linkageMemberFits(peer, cap, ap, member) || member.EqualChannel) {
					noChange = false
					break
				}
			}
			if !noChange {
				break
			}
		}
		if noChange {
			return nil
		}
	}
	var selected *cweng.RadioLinkageRow
	for i := range candidates {
		fits := true
		for _, cap := range peers {
			if cap.RadioID == edited {
				continue
			}
			peer, _ := linkageRadioState(*cfg, ap, cap.RadioID)
			for _, member := range candidates[i].Radios {
				if member.Radio == cap.RadioID && !linkageStatus(member.StatusMask, linkageEnabled(peer)) {
					fits = false
					break
				}
			}
			if !fits {
				break
			}
		}
		if fits {
			selected = &candidates[i]
			break
		}
	}
	if selected == nil {
		return nil
	}
	equal := false
	for _, member := range selected.Radios {
		if member.Radio == edited {
			equal = member.EqualChannel
			break
		}
	}
	used := []int{linkageChannel(source, ap)}
	next := *cfg
	next.Radios = append([]RadioSetting{}, cfg.Radios...)
	for _, cap := range peers {
		if cap.RadioID == edited {
			continue
		}
		for _, member := range selected.Radios {
			if member.Radio != cap.RadioID {
				continue
			}
			peer, _ := linkageRadioState(next, ap, cap.RadioID)
			a := defaultRadioAdvanced(cap)
			if peer.Advanced != nil {
				a = *peer.Advanced
			}
			// RRST relation unit always links the PHY mode to the edited radio.
			if source.Advanced != nil {
				a.Mode = source.Advanced.Mode
			} else {
				a.Mode = defaultRadioAdvanced(sourceCap).Mode
			}
			ch := linkageChannel(peer, ap)
			alreadyAllowed := hasInt(member.Channels, ch)
			if equal {
				ch = linkageChannel(source, ap)
			} else {
				domain := []int{}
				if member.DefaultChannel != nil {
					domain = append(domain, *member.DefaultChannel)
				}
				for _, c := range member.Channels {
					if member.DefaultChannel == nil || c != *member.DefaultChannel {
						domain = append(domain, c)
					}
				}
				if !alreadyAllowed || hasInt(used, ch) {
					found := false
					for _, c := range domain {
						if !hasInt(used, c) {
							ch = c
							found = true
							break
						}
					}
					if !found {
						return fmt.Errorf("AP 上报的射频联动策略没有可用的互斥信道")
					}
				}
				used = append(used, ch)
			}
			// @72750c: compliance prefers auto (enum2), then the highest
			// allowed enum. Its existing-channel branch intentionally skips
			// bandwidth correction; do not replace this with a joint solver.
			if (equal || !alreadyAllowed) && !hasInt(member.Bandwidths, a.Bandwidth) {
				if hasInt(member.Bandwidths, 2) {
					a.Bandwidth = 2
				} else {
					for bw := 5; bw >= 0; bw-- {
						if hasInt(member.Bandwidths, bw) {
							a.Bandwidth = bw
							break
						}
					}
				}
			}
			peer.Advanced = &a
			value := ch
			peer.Channel = &value
			if err := validateAdvanced(peer, ap, cap); err != nil {
				return err
			}
			putLinkedRadio(&next, peer)
			break
		}
	}
	*cfg = next
	return nil
}

// normalizeLinkageRadio is apmngr_get_linkage_chnl_bwMode @5dd2d8.
// This path uses table zero, independently of the peer strategy's current table.
func normalizeLinkageRadio(r RadioSetting, cap cweng.RadioCapability, cfg Config, ap cweng.APStatus) RadioSetting {
	p := ap.RadioLinkage
	if p == nil || len(p.Rows) == 0 {
		return r
	}
	channel, bandwidth := linkageChannel(r, ap), linkageBandwidth(r, cap)
	defaultBW, defaultChannel := 2, 0
	if i := int(r.Radio) - 1; i >= 0 {
		if i < len(p.DefaultBandwidths) {
			defaultBW = int(p.DefaultBandwidths[i])
		}
		if i < len(p.DefaultChannels) {
			defaultChannel = int(p.DefaultChannels[i])
		}
	}
	keepChannel := false
	region := linkageRegion(cfg, ap)
	for _, row := range p.Rows {
		if row.TableMask&1 == 0 || region != 255 && len(row.Regions) != 0 && !hasInt(row.Regions, region) {
			continue
		}
		for _, member := range row.Radios {
			if member.Radio != r.Radio || !hasInt(member.Channels, channel) {
				continue
			}
			if linkageBandwidthAllowed(member, bandwidth) {
				return r
			}
			if linkageBandwidthAllowed(member, defaultBW) {
				keepChannel = true
			}
		}
	}
	if !keepChannel {
		channel = defaultChannel
	}
	a := defaultRadioAdvanced(cap)
	if r.Advanced != nil {
		a = *r.Advanced
	}
	a.Bandwidth = defaultBW
	r.Advanced = &a
	r.Channel = &channel
	return r
}

func linkageBandwidthAllowed(member cweng.RadioLinkageMember, bw int) bool {
	return bw >= 0 && bw < 6 && hasInt(member.Bandwidths, bw)
}
