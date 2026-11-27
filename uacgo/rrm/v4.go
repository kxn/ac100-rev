package rrm

import "math"

// V4Graph is the directed AP graph in run_DCA@4b07f8/dfs@4b0180.
// Colors are domain indices, not channel numbers. Costs intentionally retain
// the firmware's 16-bit arithmetic and signed root-priority comparison.
type V4Graph struct {
	APs    []V4Vertex
	Out    [][]*V4Edge
	In     [][]*V4Edge
	Colors int
}
type V4Vertex struct {
	ID        string
	Color     []int
	Forbidden []bool
	Cost      [][]uint16
	Total     uint16
}
type V4Edge struct {
	From, To int
	Weight   uint16
	// Target radio first, reporting radio second (including the reverse list).
	Matrix [][]uint16
}
type V4Sample struct {
	Radio int
	RSSI  int8
}

func (g *V4Graph) AddAP(id string, radios int) int {
	v := V4Vertex{ID: id, Color: make([]int, radios), Forbidden: make([]bool, g.Colors), Cost: make([][]uint16, radios)}
	for i := range v.Cost {
		v.Cost[i] = make([]uint16, g.Colors)
	}
	g.APs = append(g.APs, v)
	g.Out = append(g.Out, nil)
	g.In = append(g.In, nil)
	return len(g.APs) - 1
}

// rrm_ap_para_neighbor_add@4b21b8 admits the first six AP neighbors,
// accumulates every sample (no -85 cutoff or EWMA), and moves an updated
// edge before equal-weight edges. Incoming order is insertion order.
func (g *V4Graph) Observe(from, radio, to int, samples []V4Sample) {
	var edge *V4Edge
	position := -1
	for i, e := range g.Out[from] {
		if e.To == to {
			edge = e
			position = i
			break
		}
	}
	if edge == nil && len(g.Out[from]) >= 6 {
		return
	}
	valid := false
	for _, s := range samples {
		if s.Radio >= 0 && s.Radio < len(g.APs[to].Color) {
			valid = true
		}
	}
	if !valid {
		return
	}
	if edge == nil {
		edge = &V4Edge{From: from, To: to, Matrix: make([][]uint16, len(g.APs[to].Color))}
		for i := range edge.Matrix {
			edge.Matrix[i] = make([]uint16, len(g.APs[from].Color))
		}
		g.In[to] = append(g.In[to], edge)
	} else {
		g.Out[from] = append(g.Out[from][:position], g.Out[from][position+1:]...)
	}
	for _, s := range samples {
		if s.Radio < 0 || s.Radio >= len(edge.Matrix) {
			continue
		}
		rssi := int(s.RSSI) + 100
		w := uint16(rssi * rssi / 100)
		edge.Weight += w
		edge.Matrix[s.Radio][radio] += w
		g.APs[from].Total += w
		g.APs[from].Cost[radio][0] += w
	}
	position = 0
	for position < len(g.Out[from]) && g.Out[from][position].Weight > edge.Weight {
		position++
	}
	g.Out[from] = append(g.Out[from], nil)
	copy(g.Out[from][position+1:], g.Out[from][position:])
	g.Out[from][position] = edge
}

func copyV4Vertices(src []V4Vertex) []V4Vertex {
	out := make([]V4Vertex, len(src))
	for i, v := range src {
		out[i] = v
		out[i].Color = append([]int{}, v.Color...)
		out[i].Cost = make([][]uint16, len(v.Cost))
		for j, c := range v.Cost {
			out[i].Cost[j] = append([]uint16{}, c...)
		}
	}
	return out
}

// rrm_add_co_chnl_itf@4b2be4: the already-selected second 5G group
// contributes a fixed color cost through the first group's incoming list.
func (g *V4Graph) AddExternal(ap, color int) {
	if color < 0 || color >= g.Colors {
		return
	}
	for _, e := range g.In[ap] {
		for radio := range g.APs[e.From].Color {
			w := e.Matrix[0][radio]
			g.APs[e.From].Cost[radio][color] += w
			g.APs[e.From].Total += w
		}
	}
}

func (g *V4Graph) Select() {
	visited := make([]bool, len(g.APs))
	for range g.APs {
		root, largest := -1, int16(-1)
		for i, v := range g.APs {
			if visited[i] {
				continue
			}
			if len(g.Out[i]) == 0 && len(g.In[i]) == 0 {
				visited[i] = true
				for j := range g.APs[i].Color {
					g.APs[i].Color[j] = -1
				}
				continue
			}
			if int16(v.Total) > largest {
				root, largest = i, int16(v.Total)
			}
		}
		if root < 0 {
			return
		}
		visited[root] = true
		order := []int{root}
		for _, e := range g.Out[root] {
			order = append(order, e.To)
		}
		work := copyV4Vertices(g.APs)
		best := 0
		var dfs func(int, int, uint32, int, int)
		dfs = func(pos, radio int, mask uint32, color, delta int) {
			ap := order[pos]
			if work[ap].Forbidden[color] {
				return
			}
			old := work[ap].Color[radio]
			if old != color {
				work[ap].Color[radio] = color
				for _, e := range g.In[ap] {
					for j, w := range e.Matrix[radio] {
						v := &work[e.From]
						v.Cost[j][old] -= w
						v.Cost[j][color] += w
						if v.Color[j] == old {
							delta -= int(w)
							v.Total -= w
						}
						if v.Color[j] == color {
							delta += int(w)
							v.Total += w
						}
					}
				}
				d := int(work[ap].Cost[radio][color]) - int(work[ap].Cost[radio][old])
				delta += d
				work[ap].Total += uint16(d)
			}
			nextPos, nextRadio, nextMask := pos, radio+1, mask|1<<uint(color)
			if nextRadio == len(work[ap].Color) {
				nextPos++
				nextRadio = 0
				nextMask = 0
			}
			if nextPos == len(order) {
				if delta < best {
					best = delta
					g.APs = copyV4Vertices(work)
				}
			} else {
				for loop := 0; loop < g.Colors; loop++ {
					if nextMask&(1<<uint(loop)) == 0 {
						dfs(nextPos, nextRadio, nextMask, (loop+ap)%g.Colors, delta)
					}
				}
			}
			// Restore the radio of this stack frame. The V4 business collector
			// admits one radio per AP in each graph; do not mutate the frame's
			// index when preparing the next recursive call.
			if old != color {
				work[ap].Color[radio] = old
				for _, e := range g.In[ap] {
					for j, w := range e.Matrix[radio] {
						v := &work[e.From]
						v.Cost[j][old] += w
						v.Cost[j][color] -= w
						if v.Color[j] == old {
							v.Total += w
						}
						if v.Color[j] == color {
							v.Total -= w
						}
					}
				}
				work[ap].Total += work[ap].Cost[radio][old] - work[ap].Cost[radio][color]
			}
		}
		for color := 0; color < g.Colors; color++ {
			dfs(0, 0, 0, color, 0)
		}
	}
}

func V4PowerForLevel(level, maxPower, minPower int) int {
	return minPower + int(math.Round(float64((maxPower-minPower)*(level-1))/9))
}
func V4LevelForPower(power, maxPower, minPower int) int {
	if maxPower == minPower {
		return 1
	}
	return int(math.Round(float64((power-minPower)*9)/float64(maxPower-minPower))) + 1
}
func v4Quantize(power, maxPower, minPower int) int {
	return V4PowerForLevel(V4LevelForPower(power, maxPower, minPower), maxPower, minPower)
}

// V4Power keeps exclusive bounds across the two measurement rounds. The
// V4 controller uses one threshold/min/max configuration for all bands.
type V4Power struct {
	Current, Upper, Lower, Max, Min int
	Neighbors                       []V4PowerNeighbor
}
type V4PowerNeighbor struct {
	AP    string
	Radio uint8
	RSSI  int8
}

func NewV4Power(maxPower, minPower, maxAllowed, minAllowed int) V4Power {
	upper, lower := maxPower, minPower
	if maxAllowed > 0 && maxAllowed < maxPower {
		upper = max(maxAllowed, minPower)
		q := v4Quantize(upper, maxPower, minPower)
		if q > upper {
			q = V4PowerForLevel(V4LevelForPower(upper, maxPower, minPower)-1, maxPower, minPower)
		}
		upper = q
	}
	if minAllowed > 0 && minAllowed > minPower {
		lower = min(minAllowed, maxPower)
		q := v4Quantize(lower, maxPower, minPower)
		if q < lower {
			q = V4PowerForLevel(V4LevelForPower(lower, maxPower, minPower)+1, maxPower, minPower)
		}
		lower = q
	}
	if lower > upper {
		lower = upper
	}
	return V4Power{Current: upper, Upper: upper + 1, Lower: lower - 1, Max: maxPower, Min: minPower}
}
func (p *V4Power) Observe(n V4PowerNeighbor) {
	for i, v := range p.Neighbors {
		if v.AP == n.AP && v.Radio == n.Radio {
			p.Neighbors = append(p.Neighbors[:i], p.Neighbors[i+1:]...)
			break
		}
	}
	if len(p.Neighbors) == 3 && n.RSSI <= p.Neighbors[2].RSSI {
		return
	}
	i := 0
	for i < len(p.Neighbors) && p.Neighbors[i].RSSI > n.RSSI {
		i++
	}
	p.Neighbors = append(p.Neighbors, V4PowerNeighbor{})
	copy(p.Neighbors[i+1:], p.Neighbors[i:])
	p.Neighbors[i] = n
	if len(p.Neighbors) > 3 {
		p.Neighbors = p.Neighbors[:3]
	}
}

// run_TPC@4b1750. Isolated-radio increases deliberately do not increment
// the changed count and therefore do not schedule a second measurement.
func (p *V4Power) Step(threshold int) bool {
	old := p.Current
	if len(p.Neighbors) == 0 {
		if p.Current < p.Upper-1 {
			p.Current = v4Quantize(p.Current+(p.Upper-p.Current)/2, p.Max, p.Min)
		}
		return false
	}
	if p.Lower >= p.Upper-2 {
		return false
	}
	if len(p.Neighbors) < 3 {
		rssi := int(p.Neighbors[0].RSSI)
		if rssi >= threshold {
			return false
		}
		step := min((threshold-rssi)&255, 30)
		p.Lower = max(p.Lower, p.Current)
		p.Current = min(p.Current+step, p.Upper-1)
	} else {
		rssi := int(p.Neighbors[2].RSSI)
		if rssi <= threshold {
			return false
		}
		step := min((rssi-threshold)&255, 30)
		p.Upper = min(p.Upper, p.Current)
		p.Current = max(p.Current-step, p.Lower+1)
	}
	p.Current = v4Quantize(p.Current, p.Max, p.Min)
	return p.Current != old
}
