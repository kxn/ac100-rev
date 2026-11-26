package admin

import "uacgo/cweng"

func mobilityRadioGroup(c cweng.RadioCapability) string {
	if c.Band != "5 GHz" {
		return c.Band
	}
	low, high := false, false
	for _, ch := range c.Channels {
		low = low || ch < 100
		high = high || ch >= 100
	}
	if low && !high {
		return "5 GHz 低频段"
	}
	if high && !low {
		return "5 GHz 高频段"
	}
	return "5 GHz"
}
