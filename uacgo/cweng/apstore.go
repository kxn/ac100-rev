package cweng

import (
	"database/sql"
	"fmt"
)

// Attach the store to the engine: entering RUN records the AP in
// apmngr.db (ApEntryCfg_table + ApEntryRun_table), mirroring
// _apmngr_try_create_ap_entry_by_template_or_db (schema strings in
// store/schemas.go carry the evidence).
func (e *Engine) UseStore(st APStore) {
	e.apStore = st
}

// APStore is the persistence surface the engine needs.
type APStore interface {
	UpsertAP(ap *APEntry) error
}

// SQLiteAPStore implements APStore over apmngr.db.
type SQLiteAPStore struct {
	Cfg *sql.DB
	Run *sql.DB
}

// UpsertAP inserts or updates the AP row keyed by MAC
// (ApEntryCfg_table.mac is UNIQUE in the binary's schema).
func (st *SQLiteAPStore) UpsertAP(ap *APEntry) error {
	if ap.Serial == "" {
		return fmt.Errorf("ap entry without serial")
	}
	entryID := ap.Serial // entry_id derived from the serial in the join path
	model, hw := int64(ap.ModelID), "1.0"
	if _, err := st.Cfg.Exec(
		`INSERT INTO ApEntryCfg_table(entry_id,mac,entry_name,model_id,hardware_ver,ap_role)
		 VALUES(?,?,?,?,?,?)
		 ON CONFLICT(mac) DO UPDATE SET entry_name=excluded.entry_name,
		   model_id=excluded.model_id, hardware_ver=excluded.hardware_ver`,
		entryID, ap.Serial, ap.Name, model, hw, "ap"); err != nil {
		return fmt.Errorf("apmngr cfg: %w", err)
	}
	if _, err := st.Run.Exec(
		`INSERT INTO ApEntryRun_table(entry_id,ap_role,status,errno)
		 VALUES(?,?,-1,-1)
		 ON CONFLICT(entry_id) DO UPDATE SET status=-1`,
		entryID, "ap"); err != nil {
		return fmt.Errorf("apmngr run: %w", err)
	}
	return nil
}
