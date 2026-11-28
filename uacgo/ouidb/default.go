package ouidb

import (
	"bytes"
	"sync"
	controllerdata "uacgo/data"
)

var defaultOnce sync.Once
var defaultDB *Database

// Default loads the shipped snapshot once. An invalid built-in data file is a
// broken installation, rather than a reason to silently use a smaller table.
func Default() *Database {
	defaultOnce.Do(func() {
		var err error
		defaultDB, err = Load(bytes.NewReader(controllerdata.IEEERegistry))
		if err != nil {
			panic("invalid embedded IEEE registry: " + err.Error())
		}
	})
	return defaultDB
}

// LookupOUI handles an AP's three-byte OUI hint. It deliberately uses only the
// MA-L table: padding it to48 bits must not invent a narrower MA-M/MA-S match.
func (db *Database) LookupOUI(oui [3]byte) []Match {
	if oui[0]&3 != 0 {
		return nil
	}
	return db.lookupPrefix(24, uint64(oui[0])<<16|uint64(oui[1])<<8|uint64(oui[2]))
}
