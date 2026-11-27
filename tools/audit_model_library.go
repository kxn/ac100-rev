// Run from uacgo: go run ../tools/audit_model_library.go
// Compare every decrypted model-library field, not just model counts.
package main

import (
	"encoding/json"
	"fmt"
	"os"
	"reflect"
	"uacgo/cweng"
	"uacgo/vendorbackup"
)

func main() {
	raw, err := os.ReadFile("../.local/ac100/rootfs/etc/apdb.bin")
	check(err)
	plain, err := vendorbackup.Decode(raw)
	check(err)
	bundled, err := os.ReadFile("data/apdb.json")
	check(err)
	var original, current any
	check(json.Unmarshal(plain, &original))
	check(json.Unmarshal(bundled, &current))
	if !reflect.DeepEqual(original, current) {
		check(fmt.Errorf("bundled model library differs from original firmware"))
	}
	db, err := cweng.LoadAPDB("data/apdb.json")
	check(err)
	variants := 0
	for _, m := range db.Models() {
		variants += len(m.Models)
	}
	fmt.Printf("Verified complete original APDB content: %d normal + %d multi-AP models, %d hardware variants\n", len(db.APList), len(db.MultiAPList), variants)
}
func check(err error) {
	if err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}
