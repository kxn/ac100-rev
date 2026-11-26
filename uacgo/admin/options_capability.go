package admin

import "uacgo/cweng"

func reportedDownlink(ap cweng.APStatus, id uint8) bool {
	if len(ap.Ports) == 0 {
		return id != 0 && int(id) <= ap.ExtWirePhys
	}
	for _, p := range ap.Ports {
		if p.ID == id {
			return !p.Uplink
		}
	}
	return false
}

// Global/group/template options may cover heterogeneous devices. Filter only
// optional fields absent on a device; direct AP overrides remain strict.
func supportedInheritedOptions(o APOptions, ap cweng.APStatus) APOptions {
	if o.RFMode != nil {
		found := !o.RFMode.Enabled
		for _, v := range ap.RadioModes {
			found = found || v.ID == o.RFMode.ID
		}
		if !ap.HasCapability(92) || !found {
			o.RFMode = nil
		}
	}
	if !ap.HasCapability(44) {
		o.Mesh = nil
	}
	if !ap.HasCapability(100) {
		o.USB = nil
	}

	if !ap.HasCapability(42) {
		o.LEDWiFiSync = nil
	}
	if !ap.SupportTrunk {
		o.Trunk = nil
	}
	if !ap.HasCapability(73) {
		o.FitFatButton = nil
	}
	if !ap.HasCapability(71) {
		o.LAG = nil
	} else if o.LAG != nil && len(ap.Ports) > 0 {
		for _, id := range o.LAG.Ports {
			found := false
			for _, p := range ap.Ports {
				found = found || p.ID == id && p.LAG
			}
			if !found {
				o.LAG = nil
				break
			}
		}
	}
	if len(o.Ports) > 0 {
		ports := []APPort{}
		for _, p := range o.Ports {
			if reportedDownlink(ap, p.ID) {
				ports = append(ports, p)
			}
		}
		o.Ports = ports
	}
	return o
}

func inheritedRadioOptions(o APOptions, ap cweng.APStatus) APOptions {
	out := []RadioSetting{}
	for _, r := range o.Radios {
		var c *cweng.RadioCapability
		for _, cap := range ap.Capabilities {
			if cap.RadioID == r.Radio {
				copy := cap
				c = &copy
			}
		}
		if c == nil {
			if len(ap.Capabilities) > 0 || ap.Radios > 0 && int(r.Radio) > ap.Radios {
				continue
			}
			out = append(out, r)
			continue
		}
		if r.Advanced != nil {
			a := *r.Advanced
			if !ap.HasCapability(1) {
				a.RSSIRestrict = false
				a.RSSIKick = false
			}
			if !ap.HasCapability(10) {
				a.Airtime = false
			}
			if !ap.HasCapability(57) {
				a.ManagementRate = 1
			}
			if !ap.HasCapability(9) {
				a.DCS = nil
			}
			if !ap.HasCapability(21) {
				a.Reject = nil
			}
			if !ap.HasCapability(61) {
				a.EDCA = nil
			} else if a.EDCA != nil && ap.SubCapabilities[61]&2 == 0 {
				v := *a.EDCA
				v.Mode = nil
				a.EDCA = &v
			}
			if !ap.HasCapability(70) || !radioControlFeatures(*c)["downlink_mumimo"] {
				a.DownlinkMUMIMO = false
			}
			if !ap.HasCapability(70) || !radioControlFeatures(*c)["uplink_mumimo"] {
				a.UplinkMUMIMO = false
			}
			if !ap.HasCapability(70) || !radioControlFeatures(*c)["downlink_ofdma"] {
				a.DownlinkOFDMA = false
			}
			if !ap.HasCapability(70) || !radioControlFeatures(*c)["uplink_ofdma"] {
				a.UplinkOFDMA = false
			}
			if !ap.HasCapability(70) || !radioControlFeatures(*c)["twt"] {
				a.TWT = false
			}
			if !ap.HasCapability(70) || !radioControlFeatures(*c)["enable_6g"] {
				a.Enable6G = false
				a.PSC6G = false
			}
			if !ap.HasCapability(70) {
				a.GI = -1
			}
			r.Advanced = &a
		}
		out = append(out, r)
	}
	o.Radios = out
	return o
}
