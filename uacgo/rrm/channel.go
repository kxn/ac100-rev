// Package rrm ports the active librrm_exec_by_param algorithms of AC100 V6.
// Input ordering, directed reports and integer operations are significant.
package rrm

import (
	"fmt"
	"sort"
)

type Neighbor struct {
	Target int
	RSSI   int8
}
type Radio struct {
	AP                             string
	Channel                        uint8
	Channels                       []uint8
	Neighbors                      []Neighbor // outgoing reports, before preprocessing
	MinPower, MaxPower, PowerLevel uint8
	UpperPower, LowerPower         uint8
}
type Config struct {
	NeighborLimit                                             uint8
	PowerThreshold                                            int8
	MinPower, MaxPower, TargetNeighbors, PowerStep, PowerStop uint8
}

func DefaultConfig() Config {
	return Config{NeighborLimit: 6, PowerThreshold: -65, MinPower: 10, MaxPower: 50, TargetNeighbors: 3, PowerStep: 30, PowerStop: 2}
}

// preprocess mirrors so+c1b0's selection/move-to-tail sort. Equal RSSI
// entries retain report insertion order. RSSI is not symmetrized.
func normalize(radios []Radio) ([][]Neighbor, error) {
	out := make([][]Neighbor, len(radios))
	for i, r := range radios {
		seen := map[int]int{}
		for _, n := range r.Neighbors {
			if n.Target < 0 || n.Target >= len(radios) || n.Target == i {
				return nil, fmt.Errorf("invalid directed RRM neighbor")
			}
			if j, ok := seen[n.Target]; ok {
				old := out[i][j].RSSI
				if old != -127 {
					n.RSSI = int8((int(old)*4 + int(n.RSSI)) / 5)
				}
				out[i][j].RSSI = n.RSSI
			} else {
				seen[n.Target] = len(out[i])
				out[i] = append(out[i], n)
			}
		}
	}
	return out, nil
}
func preprocess(radios []Radio) ([][]Neighbor, error) {
	out, err := normalize(radios)
	if err != nil {
		return nil, err
	}
	for i := range out {
		sort.SliceStable(out[i], func(a, b int) bool { return out[i][a].RSSI > out[i][b].RSSI })
	}
	return out, nil
}

// cochannel is so+4650, selected by work-init's score-mode1. Adjacent-channel
// penalties and change-count preferences are absent from this active path.
func cochannel(a, b uint8, rssi int8) uint32 {
	if a != b || rssi < -85 {
		return 0
	}
	v := int32(rssi) + 100
	return uint32(v*v) / 100
}
func Channels(radios []Radio, cfg Config) ([]uint8, error) {
	if len(radios) == 0 || cfg.NeighborLimit == 0 {
		return nil, fmt.Errorf("empty RRM network/config")
	}
	neighbors, err := preprocess(radios)
	if err != nil {
		return nil, err
	}
	trial, chosen := make([]uint8, len(radios)), make([]uint8, len(radios))
	assigned := make([]bool, len(radios))
	interference := make([]uint32, len(radios))
	order := make([]int, len(radios))
	for i, r := range radios {
		if len(r.Channels) == 0 || len(r.Channels) > 16 {
			return nil, fmt.Errorf("RRM channel domain must contain1–16 entries")
		}
		trial[i] = r.Channel
		order[i] = i
	}
	score := func(i int) uint32 {
		var total uint32
		for j, n := range neighbors[i] {
			if j >= int(cfg.NeighborLimit) {
				break
			}
			total += cochannel(trial[i], trial[n.Target], n.RSSI)
		}
		return total
	}
	for i := range radios {
		interference[i] = score(i)
	}
	sortRemaining := func(n int) {
		// so+d610 insertion sort, so+4c44 boolean swap predicate.
		for i := 1; i < n; i++ {
			for j := i; j > 0; j-- {
				a, b := order[j-1], order[j]
				swap := assigned[a] && !assigned[b] || assigned[a] == assigned[b] && interference[a] < interference[b]
				if !swap {
					break
				}
				order[j-1], order[j] = b, a
			}
		}
	}
	remaining := len(radios)
	sortRemaining(remaining)
	for remaining > 0 {
		root := order[0]
		if assigned[root] {
			break
		}
		group := []int{root}
		for j, n := range neighbors[root] {
			if j >= int(cfg.NeighborLimit) {
				break
			}
			group = append(group, n.Target)
		}
		best := uint32(0xffffffff)
		var bestChannels []uint8
		var enumerate func(int)
		enumerate = func(k int) {
			if k == len(group) {
				var cost uint32
				for _, i := range group {
					interference[i] = score(i)
					cost += interference[i]
				}
				if cost < best {
					best = cost
					bestChannels = make([]uint8, len(group))
					for j, i := range group {
						bestChannels[j] = trial[i]
					}
				}
				return
			}
			i := group[k]
			if assigned[i] {
				trial[i] = chosen[i]
				enumerate(k + 1)
				return
			}
			for _, ch := range radios[i].Channels {
				trial[i] = ch
				enumerate(k + 1)
			}
		}
		enumerate(0)
		if bestChannels == nil {
			return nil, fmt.Errorf("RRM combination evaluation failed")
		}
		newly := 0
		for j, i := range group {
			if !assigned[i] {
				newly++
			}
			assigned[i] = true
			chosen[i] = bestChannels[j]
			trial[i] = bestChannels[j]
		}
		// V6 refreshes each group's incoming sources then the group node itself.
		// Recomputing all values is equivalent (same trial array), without dedup
		// or sorting changes to the directed report lists.
		for i := range radios {
			interference[i] = score(i)
		}
		sortRemaining(remaining)
		remaining -= newly
	}
	return chosen, nil
}
