package cweng

import (
	"bytes"
	"compress/zlib"
	"encoding/binary"
	"encoding/json"
	"fmt"
	"io"
	"strings"
	"time"
	"uacgo/capwap"
)

const maxReportJSON = 1 << 20

type APReport struct {
	Type       uint16          `json:"type"`
	ReceivedAt time.Time       `json:"received_at"`
	Data       json.RawMessage `json:"data"`
}
type WirelessRadio struct {
	ReceivedAt   time.Time                  `json:"received_at"`
	StatisticsAt time.Time                  `json:"statistics_at"`
	RadioID      int                        `json:"radioId"`
	Name         string                     `json:"radioName,omitempty"`
	Channel      *int                       `json:"channel,omitempty"`
	Bandwidth    string                     `json:"bw,omitempty"`
	MaxClients   *int                       `json:"maxStaLimit,omitempty"`
	Data         map[string]json.RawMessage `json:"data,omitempty"`
}
type WirelessVAP struct {
	RadioID    int                        `json:"radioId"`
	BSSID      string                     `json:"bssid"`
	SSID       string                     `json:"ssidName"`
	Bandwidth  string                     `json:"bw,omitempty"`
	Mode       string                     `json:"mode,omitempty"`
	ShortGI    *int                       `json:"sgi,omitempty"`
	WeakSignal *int                       `json:"weakSigThresh,omitempty"`
	Data       map[string]json.RawMessage `json:"data,omitempty"`
}
type WirelessTelemetry struct {
	ReceivedAt  time.Time       `json:"received_at"`
	Software    string          `json:"software_version,omitempty"`
	LED         string          `json:"led,omitempty"`
	Radios      []WirelessRadio `json:"radios"`
	VAPs        []WirelessVAP   `json:"vaps"`
	ReportCount uint64          `json:"report_count"`
}

// cw_priv_sub_device_report_parse @0x5c8a10: type16/encoding16/length32.
// Encoding2 is zlib in V6 frames104/105. Expansion is strictly bounded.
func decodeAPReport(b []byte) (APReport, error) {
	var out APReport
	if len(b) < 8 || uint64(binary.BigEndian.Uint32(b[4:])) != uint64(len(b)-8) {
		return out, fmt.Errorf("invalid AP report length")
	}
	out.Type = binary.BigEndian.Uint16(b)
	encoding := binary.BigEndian.Uint16(b[2:])
	body := b[8:]
	if encoding == 2 {
		reader, err := zlib.NewReader(bytes.NewReader(body))
		if err != nil {
			return out, err
		}
		defer reader.Close()
		body, err = io.ReadAll(io.LimitReader(reader, maxReportJSON+1))
		if err != nil {
			return out, err
		}
	} else if encoding != 0 {
		return out, fmt.Errorf("unsupported AP report encoding %d", encoding)
	}
	if len(body) > maxReportJSON || !json.Valid(body) {
		return out, fmt.Errorf("invalid or excessive AP report JSON")
	}
	out.Data = append(json.RawMessage{}, body...)
	out.ReceivedAt = time.Now()
	return out, nil
}

func normalizeDeviceMAC(s string) string { return strings.ToLower(strings.ReplaceAll(s, "-", ":")) }

func (e *Engine) RegisterTelemetryHandlers() {
	e.Register(9, 81, "wireless_telemetry", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		privateElements(req, func(typ uint16, b []byte) {
			if typ != 0x80 {
				return
			}
			report, err := decodeAPReport(b)
			if err != nil {
				return
			}
			s := ctx.Session
			if s.reports == nil {
				s.reports = map[uint16]APReport{}
			}
			if _, ok := s.reports[report.Type]; !ok && len(s.reports) >= 16 {
				return
			}

			var root struct {
				MAC      string          `json:"deviceMac"`
				Software string          `json:"softwareVersion"`
				LED      string          `json:"led"`
				Radios   []WirelessRadio `json:"radioStats"`
				VAPs     []WirelessVAP   `json:"vapStats"`
			}
			if json.Unmarshal(report.Data, &root) != nil {
				return
			}
			if s.apEntry != nil && s.apEntry.MAC != "" && root.MAC != "" && normalizeDeviceMAC(root.MAC) != s.apEntry.MAC {
				return
			}
			s.reports[report.Type] = report
			if s.telemetry == nil {
				s.telemetry = &WirelessTelemetry{Radios: []WirelessRadio{}, VAPs: []WirelessVAP{}}
			}
			t := s.telemetry
			t.ReceivedAt = report.ReceivedAt
			t.ReportCount++
			if root.Software != "" {
				t.Software = root.Software
			}
			if root.LED != "" {
				t.LED = root.LED
			}
			for _, r := range root.Radios {
				r.ReceivedAt = report.ReceivedAt
				if r.Data != nil {
					r.StatisticsAt = report.ReceivedAt
				}
				i := -1
				for n, x := range t.Radios {
					if x.RadioID == r.RadioID {
						i = n
						break
					}
				}
				if i < 0 {
					t.Radios = append(t.Radios, r)
				} else {
					old := t.Radios[i]
					old.ReceivedAt = r.ReceivedAt
					if r.Name != "" {
						old.Name = r.Name
					}
					if r.Channel != nil {
						old.Channel = r.Channel
					}
					if r.Bandwidth != "" {
						old.Bandwidth = r.Bandwidth
					}
					if r.MaxClients != nil {
						old.MaxClients = r.MaxClients
					}
					if r.Data != nil {
						old.Data = r.Data
						old.StatisticsAt = r.StatisticsAt
					}
					t.Radios[i] = old
				}
			}
			// Type 3 is a full device/configuration snapshot; type 2 contains
			// rolling statistics. Prune removed VAPs only on a configuration snapshot.
			if report.Type == 3 {
				var present map[string]json.RawMessage
				_ = json.Unmarshal(report.Data, &present)
				if _, ok := present["vapStats"]; ok {
					keep := t.VAPs[:0]
					for _, old := range t.VAPs {
						for _, v := range root.VAPs {
							if normalizeDeviceMAC(v.BSSID) == normalizeDeviceMAC(old.BSSID) {
								keep = append(keep, old)
								break
							}
						}
					}
					t.VAPs = keep
				}
			}
			for _, v := range root.VAPs {
				v.BSSID = normalizeDeviceMAC(v.BSSID)
				i := -1
				for n, x := range t.VAPs {
					if x.BSSID == v.BSSID {
						i = n
						break
					}
				}
				if i < 0 {
					t.VAPs = append(t.VAPs, v)
				} else {
					old := t.VAPs[i]
					if v.SSID != "" {
						old.SSID = v.SSID
					}
					if v.Mode != "" {
						old.Mode = v.Mode
					}
					if v.Bandwidth != "" {
						old.Bandwidth = v.Bandwidth
					}
					if v.Data != nil {
						old.Data = v.Data
					}
					if v.ShortGI != nil {
						old.ShortGI = v.ShortGI
					}
					if v.WeakSignal != nil {
						old.WeakSignal = v.WeakSignal
					}
					t.VAPs[i] = old
				}
			}
		})
		return true
	})
}

func (e *Engine) Reports(id string) []APReport {
	s := e.findAP(id)
	if s == nil {
		return []APReport{}
	}
	s.mu.Lock()
	defer s.mu.Unlock()
	out := []APReport{}
	for _, r := range s.reports {
		r.Data = append(json.RawMessage{}, r.Data...)
		out = append(out, r)
	}
	return out
}
