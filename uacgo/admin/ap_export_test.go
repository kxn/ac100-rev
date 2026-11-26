package admin

import (
	"encoding/csv"
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
