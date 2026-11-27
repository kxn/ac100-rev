package mobility

import (
	"testing"
	"uacgo/capwap"
)

func TestV4HighPerformanceACSUsesAggregateAndSeparateDownlinks(t *testing.T) {
	s := V4SelectCommonChannels([][]capwap.ChannelScanSample{
		{{Channel: 1, BSS: 1, Load: 20}, {Channel: 6, BSS: 2, Load: 5}, {Channel: 36, BSS: 3, Load: 5}, {Channel: 40, BSS: 2, Load: 30}, {Channel: 149, BSS: 0, Load: 50}, {Channel: 153, BSS: 0, Load: 70}},
		{{Channel: 1, BSS: 5, Load: 20}, {Channel: 6, BSS: 1, Load: 25}, {Channel: 36, BSS: 0, Load: 5}, {Channel: 149, BSS: 0, Load: 5}},
	})
	if s.Channels != (CommonChannels{6, 40, 149}) || s.Best5 != 149 {
		t.Fatal(s)
	}
	if got := V4ACSChannel(s, 2, 2, true); got != 149 {
		t.Fatal("ACS dual-band entry must use overall best", got)
	}
	if got := V4CommonChannel(s.Channels, 2, 2, true, 0); got != 40 {
		t.Fatal("join must use the low slot", got)
	}
	if V4ACSChannel(s, 2, 3, true) != 40 || V4ACSChannel(s, 3, 3, true) != 149 {
		t.Fatal("tri-band slots", s)
	}
}

func TestV4HighPerformanceRejectBranchAndNoSamplesKeepVendorDefaults(t *testing.T) {
	s := V4SelectCommonChannels([][]capwap.ChannelScanSample{{{Channel: 6, BSS: 1, Load: 80}, {Channel: 11, BSS: 9, Load: 5}, {Channel: 40, BSS: 0, Load: 70}, {Channel: 149, BSS: 20, Load: 2, Rejected: 1}, {Channel: 153, BSS: 0, Load: 1}}})
	if s.Channels != (CommonChannels{11, 36, 153}) || s.Best5 != 153 {
		t.Fatal("reject uses min load and default other band", s)
	}
	if s = V4SelectCommonChannels(nil); s.Channels != (CommonChannels{1, 36, 149}) || s.Best5 != 36 {
		t.Fatal(s)
	}
	// A missing opposite band must not reuse the previous best-band loop
	// temporary. This is an uninitialized/stale-output bug, not a score rule.
	if s = V4SelectCommonChannels([][]capwap.ChannelScanSample{{{Channel: 40, BSS: 0, Load: 1}}}); s.Channels != (CommonChannels{1, 40, 149}) {
		t.Fatal(s)
	}
}

func TestV4HighPerformanceChannelSeedAndManualBandFilter(t *testing.T) {
	c := CommonChannels{}
	if !c.Update(2, 40, false) || c.Update(2, 48, false) || !c.Update(3, 157, true) {
		t.Fatal(c)
	}
	if got := V4CommonChannel(c, 2, 2, true, 3); got != 157 {
		t.Fatal("manual high-band event must not be replaced by low slot", got)
	}
	if got := V4CommonChannel(c, 2, 3, true, 3); got != 0 {
		t.Fatal("tri-band low radio must not consume high-band event", got)
	}
	if V4ChannelBand(14) != 0 || V4ChannelBand(64) != 2 || V4ChannelBand(100) != 3 || V4ChannelBand(192) != 0 {
		t.Fatal("V4 band boundaries")
	}
}
