package admin

import "slices"

// These copies keep inherited profiles independent without serializing an
// internal value through its Web/storage representation.
func clonePtr[T any](p *T) *T {
	if p == nil {
		return nil
	}
	v := *p
	return &v
}

func cloneSchedule(p *ServiceSchedule) *ServiceSchedule {
	out := clonePtr(p)
	if out != nil {
		out.Windows = slices.Clone(out.Windows)
		out.Dates = slices.Clone(out.Dates)
	}
	return out
}

func cloneRadio(r RadioSetting) RadioSetting {
	r.Enabled, r.Channel = clonePtr(r.Enabled), clonePtr(r.Channel)
	r.Bandwidth = clonePtr(r.Bandwidth)
	r.Power, r.PowerLevel = clonePtr(r.Power), clonePtr(r.PowerLevel)
	r.Advanced = clonePtr(r.Advanced)
	if a := r.Advanced; a != nil {
		a.DCS, a.Reject, a.EDCA = clonePtr(a.DCS), clonePtr(a.Reject), clonePtr(a.EDCA)
		if e := a.EDCA; e != nil {
			e.Preset, e.Mode = clonePtr(e.Preset), clonePtr(e.Mode)
			e.Queues = slices.Clone(e.Queues)
		}
	}
	return r
}

func cloneOptions(o APOptions) APOptions {
	o.RFMode, o.USB, o.Mesh = clonePtr(o.RFMode), clonePtr(o.USB), clonePtr(o.Mesh)
	o.EchoSeconds, o.EchoMisses = clonePtr(o.EchoSeconds), clonePtr(o.EchoMisses)
	o.ClientKeepAlive, o.ClientIdle = clonePtr(o.ClientKeepAlive), clonePtr(o.ClientIdle)
	o.OfflineSelfManage, o.LED, o.LEDWiFiSync = clonePtr(o.OfflineSelfManage), clonePtr(o.LED), clonePtr(o.LEDWiFiSync)
	o.LEDSchedule, o.RebootSchedule = cloneSchedule(o.LEDSchedule), cloneSchedule(o.RebootSchedule)
	o.Trunk, o.FitFatButton, o.RegionCode = clonePtr(o.Trunk), clonePtr(o.FitFatButton), clonePtr(o.RegionCode)
	o.Account, o.LAG = clonePtr(o.Account), clonePtr(o.LAG)
	if o.LAG != nil {
		o.LAG.Ports = slices.Clone(o.LAG.Ports)
	}
	if len(o.Radios) == 0 {
		o.Radios = nil
	} else {
		o.Radios = slices.Clone(o.Radios)
		for i := range o.Radios {
			o.Radios[i] = cloneRadio(o.Radios[i])
		}
	}
	if len(o.Ports) == 0 {
		o.Ports = nil
	} else {
		o.Ports = slices.Clone(o.Ports)
		for i := range o.Ports {
			o.Ports[i].VLAN, o.Ports[i].Enabled = clonePtr(o.Ports[i].VLAN), clonePtr(o.Ports[i].Enabled)
		}
	}
	return o
}
