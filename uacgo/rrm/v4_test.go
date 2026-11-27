package rrm

import "testing"

func TestV4DCAAccumulatesEverySampleAndKeepsDirectedFirstSix(t *testing.T) {
	g := V4Graph{Colors: 3}
	for i := 0; i < 8; i++ {
		g.AddAP(string(rune('a'+i)), 1)
	}
	g.Observe(0, 0, 1, []V4Sample{{0, -90}, {0, -50}})
	if g.APs[0].Total != 26 || g.Out[0][0].Weight != 26 || len(g.In[1]) != 1 || len(g.Out[1]) != 0 {
		t.Fatal(g.APs[0], g.Out[0])
	}
	for i := 2; i < 8; i++ {
		g.Observe(0, 0, i, []V4Sample{{0, -40}})
	}
	if len(g.Out[0]) != 6 || len(g.In[7]) != 0 {
		t.Fatal("seventh neighbor must not displace an admitted edge")
	}
	g.Observe(0, 0, 1, []V4Sample{{0, -20}})
	if g.Out[0][0].To != 1 || g.Out[0][0].Weight != 90 {
		t.Fatal("existing edge must accumulate and reorder", g.Out[0])
	}
	g.Select()
	if g.APs[0].Color[0] == g.APs[1].Color[0] || g.APs[7].Color[0] != -1 {
		t.Fatal("connected colors/isolated sentinel", g.APs)
	}
}

func TestV4DCAUsesSignedRootCostStrictImprovementAndExternalPenalty(t *testing.T) {
	g := V4Graph{Colors: 2}
	g.AddAP("a", 1)
	g.AddAP("b", 1)
	g.Observe(0, 0, 1, []V4Sample{{0, -50}})
	g.AddExternal(1, 1)
	g.Select()
	// Either equal-cost separated assignment is legal in isolation; the
	// fixed color1 penalty on a makes the first improving b=1 result persist.
	if g.APs[0].Color[0] != 0 || g.APs[1].Color[0] != 1 {
		t.Fatal(g.APs)
	}
	g = V4Graph{Colors: 2}
	g.AddAP("a", 1)
	g.AddAP("b", 1)
	g.Observe(0, 0, 1, []V4Sample{{0, -50}})
	g.APs[0].Total = 0xffff
	g.APs[1].Total = 0xffff
	g.Select()
	if g.APs[0].Color[0] != 0 || g.APs[1].Color[0] != 0 {
		t.Fatal("negative signed roots must not become maximum", g.APs)
	}
}

func TestV4TPCQuantizedBoundsTopThreeAndPersistentRounds(t *testing.T) {
	p := NewV4Power(24, 3, 20, 10)
	if p.Current != 19 || p.Upper != 20 || p.Lower != 9 {
		t.Fatal(p)
	}
	for _, n := range []V4PowerNeighbor{{"a", 1, -40}, {"b", 1, -45}, {"c", 1, -50}, {"d", 1, -60}} {
		p.Observe(n)
	}
	if len(p.Neighbors) != 3 || p.Neighbors[2].AP != "c" {
		t.Fatal(p)
	}
	if !p.Step(-65) || p.Current != 10 || p.Upper != 19 || p.Lower != 9 {
		t.Fatal(p)
	}
	p.Neighbors = nil
	p.Observe(V4PowerNeighbor{"new", 2, -80})
	if !p.Step(-65) || p.Current != 17 || p.Lower != 10 || p.Upper != 19 {
		t.Fatal("second round must preserve exclusive bounds", p)
	}
	p.Neighbors = nil
	if p.Step(-65) {
		t.Fatal("isolated increase must not count as another-round change")
	}
}

func TestV4TPCReplacesByRSSIAndUpdatesEqualEntries(t *testing.T) {
	p := NewV4Power(24, 3, 50, 10)
	for _, n := range []V4PowerNeighbor{{"a", 1, -50}, {"b", 1, -60}, {"c", 1, -70}, {"d", 1, -70}} {
		p.Observe(n)
	}
	if p.Neighbors[2].AP != "c" {
		t.Fatal("equal tail must not replace", p)
	}
	p.Observe(V4PowerNeighbor{"c", 1, -50})
	if p.Neighbors[0].AP != "c" {
		t.Fatal("updated equal RSSI precedes existing", p)
	}
}
