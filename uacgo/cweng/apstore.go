package cweng

import (
	"database/sql"
	"fmt"
)

func (e *Engine) UseStore(st APStore) { e.apStore = st }

type APStore interface{ UpsertAP(ap *APEntry) error }
type SQLiteAPStore struct {
	Cfg *sql.DB
	Run *sql.DB
}

func (st *SQLiteAPStore) UpsertAP(ap *APEntry) error {
	mac := ap.MAC
	if mac == "" {
		mac = ap.Serial
	}
	if mac == "" {
		return fmt.Errorf("ap entry without MAC or serial")
	}
	tx, err := st.Cfg.Begin()
	if err != nil {
		return err
	}
	defer tx.Rollback()
	var id int64
	err = tx.QueryRow(`SELECT entry_id FROM ApEntryCfg_table WHERE mac=?`, mac).Scan(&id)
	if err == sql.ErrNoRows {
		if err = tx.QueryRow(`SELECT COALESCE(MAX(CAST(entry_id AS INTEGER)),-1)+1 FROM ApEntryCfg_table`).Scan(&id); err != nil {
			return err
		}
	} else if err != nil {
		return err
	}
	hardware := ap.HardwareVersion
	if hardware == "" {
		hardware = "unknown"
	}
	if _, err = tx.Exec(`INSERT INTO ApEntryCfg_table(entry_id,mac,entry_name,model_id,hardware_ver,ap_role) VALUES(?,?,?,?,?,?) ON CONFLICT(mac) DO UPDATE SET model_id=excluded.model_id,hardware_ver=excluded.hardware_ver`, id, mac, ap.Name, ap.ModelID, hardware, "ap"); err != nil {
		return fmt.Errorf("apmngr cfg: %w", err)
	}
	if err = tx.Commit(); err != nil {
		return err
	}
	ap.EntryID = uint32(id)
	_, err = st.Run.Exec(`INSERT INTO ApEntryRun_table(entry_id,ap_role,status,errno) VALUES(?,?,-1,-1) ON CONFLICT(entry_id) DO UPDATE SET status=-1`, id, "ap")
	return err
}
