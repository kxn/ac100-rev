package jcs

import (
	"database/sql"
	"encoding/json"
	"os"
)

// apmngr event handlers — ap_status_evt.set / ap_telnet_status_evt.set /
// apmngr_apdb_info.get (the last three not-impl apmngr registrations of
// apmngr_jcs_reg_callback @0x5546a8).
//
// Evidence: _apmngr_jcs_ap_evt @0x54a250 and _apmngr_jcs_ap_telnet_evt
// @0x549ef8 (params {entry_id: []int, evt: string}, "evt" key at binary
// 0x6cdd1c) and _apmngr_jcs_apdb_info_get @0x55253c.

// ApmngrEvtHooks receives the CAPWAP side-effects of the event handlers
// (the binary sends reset/led/telnet packets via apmngr_pkt_*_send). All
// hooks are optional; the store updates always happen.
type ApmngrEvtHooks struct {
	// OnReboot: apmngr_ap_reboot @0x52e110 ("reboot" event).
	OnReboot func(entryIDs []int)
	// OnLED: apmngr_ap_led_update @0x52c558 ("led_on"/"led_off").
	OnLED func(entryIDs []int, on bool)
	// OnFactoryReset: apmngr_ap_reset @0x52f57c ("reset"): entry rows are
	// deleted here, the hook sends the factory-reset packet (code 3).
	OnFactoryReset func(entryIDs []int)
	// OnTelnet: apmngr_ap_telnet_status_update @0x52c358 ("on"/"off").
	OnTelnet func(entryIDs []int, on bool)
}

// RegisterApmngrEvtHandlers installs the two event setters plus the
// apdb_info getter.
func RegisterApmngrEvtHandlers(s *Server, db *sql.DB, hooks *ApmngrEvtHooks, apdb ApdbInfoFunc) {
	if hooks == nil {
		hooks = &ApmngrEvtHooks{}
	}
	// ap_status_evt.set — evt ∈ {reboot, led_on, led_off, reset}
	s.replaceNotImpl("ap_status_evt.set", func(req json.RawMessage) (any, error) {
		var q struct {
			EntryID []int  `json:"entry_id"`
			Evt     string `json:"evt"`
		}
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		switch q.Evt {
		case "reboot":
			// online APs get the pending-reset flag (apmngr_db_ap_reset_op_set)
			for _, id := range q.EntryID {
				_, _ = db.Exec(`UPDATE ApEntryRun_table SET status=status WHERE entry_id=?`, id)
			}
			if hooks.OnReboot != nil {
				hooks.OnReboot(q.EntryID)
			}
		case "led_on", "led_off":
			led := 2 // led_on=1, led_off=2 (evt→1/2 mapping, apmngr_ap_led_update)
			if q.Evt == "led_on" {
				led = 1
			}
			for _, id := range q.EntryID {
				_, _ = db.Exec(`UPDATE ApEntryCfg_table SET led=? WHERE entry_id=?`, led, id)
				_, _ = db.Exec(`UPDATE ApEntryRun_table SET led=? WHERE entry_id=?`, led == 1, id)
			}
			if hooks.OnLED != nil {
				hooks.OnLED(q.EntryID, q.Evt == "led_on")
			}
		case "reset":
			// apmngr_ap_reset: entry_delete (cfg+run rows) + id free + reset pkt 3
			for _, id := range q.EntryID {
				_, _ = db.Exec(`DELETE FROM ApEntryCfg_table WHERE entry_id=?`, id)
				_, _ = db.Exec(`DELETE FROM ApEntryRun_table WHERE entry_id=?`, id)
			}
			if hooks.OnFactoryReset != nil {
				hooks.OnFactoryReset(q.EntryID)
			}
		default:
			return map[string]any{"error_code": 0, "ret": -1}, nil
		}
		return ok(), nil
	})

	// ap_telnet_status_evt.set — evt ∈ {on, off}
	s.replaceNotImpl("ap_telnet_status_evt.set", func(req json.RawMessage) (any, error) {
		var q struct {
			EntryID []int  `json:"entry_id"`
			Evt     string `json:"evt"`
		}
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		on := q.Evt == "on"
		if q.Evt != "on" && q.Evt != "off" {
			return map[string]any{"error_code": 0, "ret": -1}, nil
		}
		for _, id := range q.EntryID {
			// _apmngr_db_sqlite_ap_telnet_update: UPDATE ApEntryCfg_table
			// SET telnet_status=%d; run state via msg 0x14
			_, _ = db.Exec(`UPDATE ApEntryCfg_table SET telnet_status=? WHERE entry_id=?`,
				map[bool]int{true: 1, false: 0}[on], id)
			_, _ = db.Exec(`UPDATE ApEntryRun_table SET telnet_status=? WHERE entry_id=?`, on, id)
		}
		if hooks.OnTelnet != nil {
			hooks.OnTelnet(q.EntryID, on)
		}
		return ok(), nil
	})

	// apmngr_apdb_info.get — request is a JSON array of
	// {model_id, firmware_id}; the vendor answers {file_name, total_num}
	// with the model info serialized to /tmp/apdb_info_list.
	s.replaceNotImpl("apmngr_apdb_info.get", func(req json.RawMessage) (any, error) {
		var want []struct {
			ModelID    string `json:"model_id"`
			FirmwareID string `json:"firmware_id"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &want); err != nil {
				return nil, err
			}
		}
		out := []map[string]any{}
		if apdb != nil {
			for _, w := range want {
				if info, ok := apdb(w.ModelID, w.FirmwareID); ok {
					out = append(out, info)
				}
			}
		}
		body, _ := json.Marshal(out)
		if err := os.WriteFile(ApdbInfoListFile, body, 0644); err != nil {
			return jerr(err), nil
		}
		return map[string]any{"error_code": 0, "file_name": ApdbInfoListFile,
			"total_num": len(out)}, nil
	})
}

// ApdbInfoListFile is the vendor's fixed result path
// (_apmngr_jcs_apdb_info_get @0x55253c).
const ApdbInfoListFile = "/tmp/apdb_info_list"

// ApdbInfoFunc resolves one (model_id, firmware_id) to the APDB model
// object (apdb_get_ap_by_id): model_name, id, hardware_ver, radios
// {"2.4G1"/"5.0G1"…}, port_info, region_list …
type ApdbInfoFunc func(modelID, firmwareID string) (map[string]any, bool)
