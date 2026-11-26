package admin

import (
	"encoding/csv"
	"net/http"
	"strconv"
	"strings"
	"time"
)

func csvText(v string) string {
	if strings.HasPrefix(v, "=") || strings.HasPrefix(v, "+") || strings.HasPrefix(v, "-") || strings.HasPrefix(v, "@") || strings.HasPrefix(v, "\t") || strings.HasPrefix(v, "\r") || strings.HasPrefix(v, "\n") {
		return "'" + v
	}
	return v
}

// Inventory export contains controller labels and reported device identity,
// never a serialized AP configuration or its credentials.
func (m *Manager) exportAPsHTTP(w http.ResponseWriter, r *http.Request) {
	aps, clients := m.APs(), m.clients.All()
	m.mu.Lock()
	cfg := m.config
	m.mu.Unlock()
	retired := map[string]bool{}
	for _, id := range cfg.RetiredAPs {
		retired[id] = true
	}
	groups := map[string]string{}
	for _, g := range cfg.Groups {
		groups[g.ID] = g.Name
	}
	w.Header().Set("Content-Type", "text/csv; charset=utf-8")
	w.Header().Set("Content-Disposition", `attachment; filename="access-points.csv"`)
	out := csv.NewWriter(w)
	defer out.Flush()
	_ = out.Write([]string{"MAC", "名称", "位置", "分组", "型号", "硬件版本", "软件版本", "管理地址", "状态", "射频数", "无线客户端数", "最近通信"})
	for _, ap := range aps {
		if retired[ap.ID] {
			continue
		}
		group, count := "", 0
		for _, p := range cfg.APProfiles {
			if p.AP == ap.ID {
				group = groups[p.Group]
			}
		}
		for _, c := range clients {
			if ap.Online && c.APID == ap.ID && c.State == "connected" && !c.Seen.Before(ap.ConnectedAt) && time.Since(c.Seen) < 6*time.Minute {
				count++
			}
		}
		version := ap.SoftwareVersion
		if version == "" && ap.Telemetry != nil {
			version = ap.Telemetry.Software
		}
		last := ""
		if !ap.LastSeen.IsZero() {
			last = ap.LastSeen.Format(time.RFC3339)
		}
		row := []string{ap.MAC, ap.Name, ap.Location, group, ap.Model, ap.HardwareVersion, version, ap.LocalIP, ap.State, strconv.Itoa(ap.Radios), strconv.Itoa(count), last}
		for i := range row {
			row[i] = csvText(row[i])
		}
		_ = out.Write(row)
	}
}
