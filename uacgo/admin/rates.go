package admin

import (
	"context"
	"fmt"
	"net/http"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

type LegacyRateSet struct {
	Basic     []float64 `json:"basic_mbps"`
	Supported []float64 `json:"supported_mbps"`
	Multicast float64   `json:"multicast_mbps"`
}
type MCSRateSet struct {
	Basic     int `json:"basic"`
	Supported int `json:"supported"`
	Multicast int `json:"multicast"`
}
type RatePolicy struct {
	Enabled bool          `json:"enabled"`
	APs     []string      `json:"aps"`
	Groups  []string      `json:"groups"`
	A       LegacyRateSet `json:"11a"`
	B       LegacyRateSet `json:"11b"`
	G       LegacyRateSet `json:"11g"`
	N       MCSRateSet    `json:"11n"`
	AC      MCSRateSet    `json:"11ac"`
	AX      MCSRateSet    `json:"11ax"`
}

func defaultRatePolicy() RatePolicy {
	return RatePolicy{Enabled: true, A: LegacyRateSet{[]float64{6, 12, 24}, []float64{9, 18, 36, 48, 54}, -1}, B: LegacyRateSet{[]float64{1, 2}, []float64{5.5, 11}, -1}, G: LegacyRateSet{[]float64{1, 2, 5.5, 11}, []float64{6, 9, 12, 18, 24, 36, 48, 54}, -1}, N: MCSRateSet{-1, 23, -1}, AC: MCSRateSet{-1, 11, -1}, AX: MCSRateSet{-1, 23, -1}}
}
func validateRates(p RatePolicy) error {
	for _, row := range []struct {
		r       LegacyRateSet
		allowed []float64
		limit   int
	}{{p.A, []float64{6, 9, 12, 18, 24, 36, 48, 54}, 8}, {p.B, []float64{1, 2, 5.5, 11}, 4}, {p.G, []float64{1, 2, 5.5, 6, 9, 11, 12, 18, 24, 36, 48, 54}, 12}} {
		allowed := map[float64]bool{}
		for _, v := range row.allowed {
			allowed[v] = true
		}
		seen := map[float64]bool{}
		if len(row.r.Basic) > row.limit || len(row.r.Supported) > row.limit {
			return fmt.Errorf("速率表容量超限")
		}
		for _, list := range [][]float64{row.r.Basic, row.r.Supported} {
			for _, v := range list {
				if !allowed[v] || seen[v] {
					return fmt.Errorf("基础/支持速率无效或重复")
				}
				seen[v] = true
			}
		}
		if row.r.Multicast != -1 && !allowed[row.r.Multicast] {
			return fmt.Errorf("组播速率无效")
		}
	}
	for _, row := range []struct {
		r   MCSRateSet
		max int
	}{{p.N, 31}, {p.AC, 11}, {p.AX, 23}} {
		for _, v := range []int{row.r.Basic, row.r.Supported, row.r.Multicast} {
			if v < -1 || v > row.max {
				return fmt.Errorf("MCS/NSS 速率索引无效")
			}
		}
	}
	return nil
}
func legacyRateValue(p RatePolicy, radio uint8) []byte {
	b := make([]byte, 55)
	b[0] = radio
	fill := func(start int, v []float64) {
		for i, r := range v {
			b[start+i] = byte(r * 2)
		}
	}
	fill(1, p.A.Basic)
	fill(9, p.A.Supported)
	fill(18, p.B.Basic)
	fill(22, p.B.Supported)
	fill(27, p.G.Basic)
	fill(39, p.G.Supported)
	for _, row := range []struct {
		offset int
		value  float64
	}{{17, p.A.Multicast}, {26, p.B.Multicast}, {51, p.G.Multicast}} {
		if row.value >= 0 {
			b[row.offset] = byte(row.value * 2)
		}
	}
	b[52], b[53], b[54] = byte(p.N.Basic), byte(p.N.Supported), byte(p.N.Multicast)
	return b
}
func mcsRateValue(r MCSRateSet, radio uint8) []byte {
	basic := r.Basic
	if basic < 0 {
		basic = 0
	}
	return []byte{radio, byte(basic), byte(r.Supported), byte(r.Multicast)}
}
func rateElements(p RatePolicy, ap cweng.APStatus) []capwap.Element {
	var out []capwap.Element
	for _, c := range ap.Capabilities {
		out = append(out, privateSetting(0xa, legacyRateValue(p, c.RadioID)))
		if c.SupportAC {
			out = append(out, privateSetting(0x2b, mcsRateValue(p.AC, c.RadioID)))
		}
		if c.SupportAX && ap.HasCapability(70) {
			out = append(out, privateSetting(0xa0, mcsRateValue(p.AX, c.RadioID)))
		}
	}
	return out
}
func (m *Manager) applyRates(ctx context.Context, ap cweng.APStatus, cfg Config) {
	configured := cfg.Rates != nil && serviceTargets(Service{APs: cfg.Rates.APs, Groups: cfg.Rates.Groups}, ap.ID, cfg)
	if !configured && !m.policyOwned(ap.ID, "rates") {
		return
	}
	p := defaultRatePolicy()
	if configured && cfg.Rates.Enabled {
		p = *cfg.Rates
	}
	key := ap.ID + "/rates"
	version := configurationKey(p, ap.ConnectedAt)
	m.mu.Lock()
	st := m.status[key]
	done := m.applied[key] == version && (st.State != "failed" || time.Since(st.At) < 30*time.Second)
	m.mu.Unlock()
	if done {
		return
	}
	err := validateRates(p)
	if err == nil && len(ap.Capabilities) == 0 {
		err = fmt.Errorf("AP 尚未上报射频能力")
	}
	if err == nil {
		err = m.touchPolicy(ap.ID, "rates")
	}
	if err == nil {
		m.dirtyAP(ap.ID)
		for _, el := range rateElements(p, ap) {
			if _, err = m.engine.Request(ctx, ap.ID, 7, []capwap.Element{el}); err != nil {
				break
			}
		}
	}
	st = ApplyStatus{AP: ap.ID, Service: "rates", State: "acknowledged", At: time.Now()}
	if err != nil {
		st.State = "failed"
		st.Error = err.Error()
	}
	m.mu.Lock()
	m.applied[key] = version
	m.status[key] = st
	m.mu.Unlock()
}
func (m *Manager) rateRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/rates", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		p := m.config.Rates
		if p == nil {
			v := defaultRatePolicy()
			v.Enabled = false
			p = &v
		}
		jsonReply(w, 200, p)
	})
	mux.HandleFunc("POST /api/rates", func(w http.ResponseWriter, r *http.Request) {
		var p RatePolicy
		if err := decodeManagement(w, r, &p); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		if err := validateRates(p); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.Rates = &p
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, map[string]string{"status": "saved"})
	})
}
