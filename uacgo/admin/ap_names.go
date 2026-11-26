package admin

import (
	"encoding/csv"
	"fmt"
	"net"
	"net/http"
	"sort"
	"strings"
	"unicode/utf8"
)

// apmng_set.lua's rename/import limit is 50 characters. ac_util's
// character_number counts UTF-8 leading bytes, not the encoded byte length.
func validAPName(name string) bool {
	return validLabel(name, 200) && utf8.RuneCountInString(name) <= 50
}

func setAPName(cfg *Config, id, name string) {
	cfg.APProfiles = append([]APProfile{}, cfg.APProfiles...)
	for i := range cfg.APProfiles {
		if cfg.APProfiles[i].AP == id {
			cfg.APProfiles[i].Name = name
			return
		}
	}
	cfg.APProfiles = append(cfg.APProfiles, APProfile{AP: id, Name: name})
}

// Labels was the prototype's second name store. Migrate once, preserving the
// later AP profile's explicit name, and never use it as a runtime authority.
func migrateAPNames(cfg *Config) bool {
	if cfg.Labels == nil {
		return false
	}
	ids := make([]string, 0, len(cfg.Labels))
	for id := range cfg.Labels {
		ids = append(ids, id)
	}
	sort.Strings(ids)
	for _, id := range ids {
		named := false
		for _, p := range cfg.APProfiles {
			if p.AP == id && p.Name != "" {
				named = true
				break
			}
		}
		if !named && cfg.Labels[id] != "" {
			setAPName(cfg, id, cfg.Labels[id])
		}
	}
	cfg.Labels = nil
	return true
}

func (m *Manager) apNameRoutes(mux *http.ServeMux) {
	mux.HandleFunc("GET /api/aps/names/template", func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("Content-Type", "text/csv; charset=utf-8")
		w.Header().Set("Content-Disposition", `attachment; filename="ap-names.csv"`)
		out := csv.NewWriter(w)
		defer out.Flush()
		_ = out.Write([]string{"编号", "MAC地址", "安装位置", "设备名称"})
		aps := m.APs()
		cfg := m.snapshot()
		for i, ap := range aps {
			if hasString(cfg.RetiredAPs, ap.ID) {
				continue
			}
			_ = out.Write([]string{fmt.Sprint(i + 1), ap.MAC, ap.Location, ap.Name})
		}
	})
	mux.HandleFunc("POST /api/aps/names/import", m.importAPNamesHTTP)
}

func (m *Manager) importAPNamesHTTP(w http.ResponseWriter, r *http.Request) {
	var body struct {
		CSV string `json:"csv"`
	}
	if err := decodeManagement(w, r, &body); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	reader := csv.NewReader(strings.NewReader(strings.TrimPrefix(body.CSV, "\ufeff")))
	reader.FieldsPerRecord = -1
	records, err := reader.ReadAll()
	if err != nil || len(records) == 0 || len(records[0]) != 4 || strings.TrimSpace(records[0][1]) != "MAC地址" || strings.TrimSpace(records[0][3]) != "设备名称" {
		jsonReply(w, 400, map[string]string{"error": "请使用 AP 名称模板 CSV（编号、MAC地址、安装位置、设备名称）"})
		return
	}
	// Original ap_calibrate_load validates rows separately, skips unknown MACs
	// and unchanged names, and applies only entry_name; address is not copied.
	aps := m.APs()
	m.mu.Lock()
	defer m.mu.Unlock()
	byMAC := map[string]string{}
	names := map[string]string{}
	for _, ap := range aps {
		if hasString(m.config.RetiredAPs, ap.ID) {
			continue
		}
		if mac, ok := parseMAC6(ap.MAC); ok {
			byMAC[net.HardwareAddr(mac[:]).String()] = ap.ID
			names[ap.ID] = ap.Name
		}
	}
	next := m.config
	changed, skipped := 0, 0
	errors := []map[string]any{}
	for i, row := range records[1:] {
		if len(row) != 4 {
			errors = append(errors, map[string]any{"row": i + 2, "error": "列数无效"})
			continue
		}
		name := strings.TrimSpace(row[3])
		mac, ok := parseMAC6(strings.TrimSpace(row[1]))
		if !ok || name == "" || !validAPName(name) {
			errors = append(errors, map[string]any{"row": i + 2, "error": "MAC 或名称无效（名称 1–50 个字符）"})
			continue
		}
		id := byMAC[net.HardwareAddr(mac[:]).String()]
		if id == "" {
			skipped++
			continue
		}
		if names[id] == name {
			skipped++
			continue
		}
		setAPName(&next, id, name)
		names[id] = name
		changed++
	}
	if changed > 0 {
		if err = m.saveManagement(next); err != nil {
			jsonReply(w, 400, map[string]string{"error": err.Error()})
			return
		}
	}
	jsonReply(w, 200, map[string]any{"updated": changed, "skipped": skipped, "errors": errors})
}
