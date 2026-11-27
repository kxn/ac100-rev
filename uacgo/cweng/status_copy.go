package cweng

import (
	"bytes"
	"encoding/json"
	"slices"
)

func cloneTelemetry(t *WirelessTelemetry) *WirelessTelemetry {
	if t == nil {
		return nil
	}
	out := *t
	out.Radios = slices.Clone(t.Radios)
	for i := range out.Radios {
		r := &out.Radios[i]
		r.Channel, r.MaxClients = copyStatusPtr(r.Channel), copyStatusPtr(r.MaxClients)
		r.Data = copyReportData(r.Data)
	}
	out.VAPs = slices.Clone(t.VAPs)
	for i := range out.VAPs {
		v := &out.VAPs[i]
		v.ShortGI, v.WeakSignal = copyStatusPtr(v.ShortGI), copyStatusPtr(v.WeakSignal)
		v.Data = copyReportData(v.Data)
	}
	return &out
}

func copyStatusPtr[T any](p *T) *T {
	if p == nil {
		return nil
	}
	v := *p
	return &v
}

func copyReportData(data map[string]json.RawMessage) map[string]json.RawMessage {
	if data == nil {
		return nil
	}
	out := make(map[string]json.RawMessage, len(data))
	for k, v := range data {
		out[k] = bytes.Clone(v)
	}
	return out
}
