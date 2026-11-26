package admin

import (
	"encoding/csv"
	"encoding/json"
	"strings"
	"testing"
	"uacgo/cweng"
)

func TestAPInventoryExportUsesLabelsReportedFactsAndExcludesRetiredDevices(t *testing.T) {
	m, e := testController(t)
	_, ap := newDeferredAP(t, e)
	m.config.Groups = []APGroup{{ID: "floor", Name: "Office, east"}}
	m.config.APProfiles = []APProfile{{AP: ap.ID, Name: "=not-a-formula", Location: "Meeting room", Group: "floor"}}
	m.config.APDefaults.Account = &APAccount{Username: "private", Password: "do-not-export-this"}
	m.known["retired"] = cweng.APStatus{ID: "retired", Name: "Old device"}
	m.config.RetiredAPs = []string{"retired"}
	m.clients.StationEvent(cweng.ClientEvent{MAC: [6]byte{2, 1, 2, 3, 4, 5}, APID: ap.ID, RadioID: 1, WLANID: 1, Kind: "associate", State: "connected"})
	w := callManagement(t, m, "GET", "aps/export", nil)
	rows, err := csv.NewReader(strings.NewReader(w.Body.String())).ReadAll()
	if w.Code != 200 || err != nil || len(rows) != 2 || len(rows[1]) != 12 {
		t.Fatal(w.Code, err, rows)
	}
	row := rows[1]
	if row[1] != "'=not-a-formula" || row[2] != "Meeting room" || row[3] != "Office, east" || row[4] != ap.Model || row[8] != "RUN" || row[10] != "1" {
		t.Fatal("inventory identity or controller state differs", row)
	}
	if strings.Contains(w.Body.String(), "do-not-export-this") || !strings.Contains(w.Header().Get("Content-Disposition"), "access-points.csv") {
		t.Fatal("export leaked a credential or lacks download filename")
	}
}

func TestAPNameImportUsesOriginalCSVRowSemanticsAndSingleNameStore(t *testing.T) {
	m, _ := testController(t)
	m.known["a"] = cweng.APStatus{ID: "a", MAC: "02:00:00:00:00:01", Name: "Old"}
	m.known["retired"] = cweng.APStatus{ID: "retired", MAC: "02:00:00:00:00:02"}
	m.config.RetiredAPs = []string{"retired"}
	m.config.APProfiles = []APProfile{{AP: "a", Name: "Old", Location: "Keep location"}}
	name := strings.Repeat("网", 50)
	file := "编号,MAC地址,安装位置,设备名称\n1,02-00-00-00-00-01,Ignored," + name + "\n2,02-00-00-00-00-02,Ignored,Retired\n3,02-00-00-00-00-03,Ignored,Unknown\n4,invalid,Ignored,Bad\n5,02-00-00-00-00-01,Ignored," + strings.Repeat("x", 51) + "\n"
	w := callManagement(t, m, "POST", "aps/names/import", map[string]string{"csv": file})
	var result struct {
		Updated, Skipped int
		Errors           []map[string]any
	}
	if err := json.Unmarshal(w.Body.Bytes(), &result); err != nil {
		t.Fatal(err)
	}
	if w.Code != 200 || result.Updated != 1 || result.Skipped != 2 || len(result.Errors) != 2 {
		t.Fatal(w.Code, w.Body.String())
	}
	if m.config.APProfiles[0].Name != name || m.config.APProfiles[0].Location != "Keep location" || len(m.config.Labels) != 0 {
		t.Fatal("import changed other AP settings or used old name storage")
	}
	w = callManagement(t, m, "POST", "aps/a/label", map[string]string{"name": "New label"})
	if w.Code != 200 || m.config.APProfiles[0].Name != "New label" || len(m.config.Labels) != 0 {
		t.Fatal("single rename did not use the same authority", w.Code, w.Body.String())
	}
	w = callManagement(t, m, "GET", "aps/names/template", nil)
	if w.Code != 200 || strings.Contains(w.Body.String(), "02:00:00:00:00:02") || !strings.Contains(w.Body.String(), "New label") {
		t.Fatal(w.Code, w.Body.String())
	}
}

func TestLegacyAPNamesMigrateWithoutOverridingProfile(t *testing.T) {
	cfg := Config{Labels: map[string]string{"a": "Legacy", "b": "Imported"}, APProfiles: []APProfile{{AP: "a", Name: "Newer", Location: "Keep"}}}
	if !migrateAPNames(&cfg) || cfg.Labels != nil || cfg.APProfiles[0].Name != "Newer" || cfg.APProfiles[1].Name != "Imported" {
		t.Fatal(cfg)
	}
	if migrateAPNames(&cfg) {
		t.Fatal("name migration is not idempotent")
	}
}
