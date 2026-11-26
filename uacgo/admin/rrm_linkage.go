package admin

import (
	"fmt"
	"uacgo/cweng"
)

// Optimize one AP's radios together: choosing channels independently can leave
// a combination which no reported RRST row allows. The constraints are local
// to each AP; equal-channel members form a single choice, avoiding a Cartesian
// search over every channel on every radio.
func rrmLinkedChannels(nodes []rrmNode, cfg Config, initial []int) ([]int, error) {
	channels := append([]int{}, initial...)
	byAP := map[string][]int{}
	var order []string
	for i, n := range nodes {
		if _, ok := byAP[n.AP.ID]; !ok {
			order = append(order, n.AP.ID)
		}
		byAP[n.AP.ID] = append(byAP[n.AP.ID], i)
	}
	for pass := 0; pass < 3; pass++ {
		for _, id := range order {
			indices := byAP[id]
			ap := nodes[indices[0]].AP
			rows := []cweng.RadioLinkageRow{{}}
			if ap.RadioLinkage != nil && len(ap.RadioLinkage.Rows) > 0 {
				rows = nil
				for _, row := range ap.RadioLinkage.Rows {
					if linkageRowActive(row, ap.RadioLinkage, linkageRegion(cfg, ap)) {
						rows = append(rows, row)
					}
				}
			}
			bestCost, bestMoves := int(^uint(0)>>1), int(^uint(0)>>1)
			var best []int
			for _, row := range rows {
				domains := map[int][]int{}
				byRadio := map[uint8]int{}
				for _, i := range indices {
					domains[i] = rrmAllowed(nodes[i].Cap, nodes[i].Band)
					byRadio[nodes[i].Cap.RadioID] = i
				}
				valid, fixedEqual := true, -1
				var equal []int
				for _, member := range row.Radios {
					i, optimized := byRadio[member.Radio]
					if !optimized {
						r, c := linkageRadioState(cfg, ap, member.Radio)
						if c.RadioID == 0 || !linkageMemberFits(r, c, ap, member) {
							valid = false
							break
						}
						if member.EqualChannel {
							ch := linkageChannel(r, ap)
							if fixedEqual >= 0 && fixedEqual != ch {
								valid = false
								break
							}
							fixedEqual = ch
						}
						continue
					}
					r, _ := linkageRadioState(cfg, ap, member.Radio)
					if !linkageStatus(member.StatusMask, linkageEnabled(r)) || !hasInt(member.Bandwidths, nodes[i].Band.Bandwidth) {
						valid = false
						break
					}
					d := []int{}
					for _, ch := range domains[i] {
						if hasInt(member.Channels, ch) {
							d = append(d, ch)
						}
					}
					domains[i] = d
					if member.EqualChannel {
						equal = append(equal, i)
					}
				}
				if !valid {
					continue
				}
				groups := [][]int{}
				if len(equal) > 0 {
					common := append([]int{}, domains[equal[0]]...)
					for _, i := range equal {
						next := []int{}
						for _, ch := range common {
							if hasInt(domains[i], ch) && (fixedEqual < 0 || ch == fixedEqual) {
								next = append(next, ch)
							}
						}
						common = next
					}
					for _, i := range equal {
						domains[i] = common
					}
					groups = append(groups, equal)
				}
				for _, i := range indices {
					if len(domains[i]) == 0 {
						valid = false
						break
					}
					if !hasInt(equal, i) {
						groups = append(groups, []int{i})
					}
				}
				if !valid {
					continue
				}
				candidate := append([]int{}, channels...)
				for _, g := range groups {
					for _, i := range g {
						candidate[i] = domains[g[0]][0]
					}
				}
				for inner := 0; inner < 3; inner++ {
					for _, g := range groups {
						cost, moves, choice := int(^uint(0)>>1), int(^uint(0)>>1), 0
						for _, ch := range domains[g[0]] {
							for _, i := range g {
								candidate[i] = ch
							}
							score, changed := rrmAPScore(nodes, candidate, indices)
							if score < cost || score == cost && changed < moves {
								cost, moves, choice = score, changed, ch
							}
						}
						for _, i := range g {
							candidate[i] = choice
						}
					}
				}
				score, moves := rrmAPScore(nodes, candidate, indices)
				if score < bestCost || score == bestCost && moves < bestMoves {
					bestCost, bestMoves, best = score, moves, candidate
				}
			}
			if best == nil {
				return nil, fmt.Errorf("AP %s 的优化候选信道和带宽没有合法的射频关联组合", id)
			}
			channels = best
		}
	}
	return channels, nil
}

func rrmAPScore(nodes []rrmNode, channels, indices []int) (int, int) {
	score, moves := 0, 0
	for _, i := range indices {
		if channels[i] != nodes[i].CurrentChannel {
			moves++
		}
		for j := range nodes {
			if i == j || j < i && nodes[j].AP.ID == nodes[i].AP.ID {
				continue
			}
			score += channelCost(nodes[i], nodes[j], channels[i], channels[j])
		}
	}
	return score, moves
}
