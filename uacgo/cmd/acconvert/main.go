// acconvert converts an original AC export offline. It never applies it.
package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"uacgo/admin"
)

func main() {
	input := flag.String("input", "", "original config.bin")
	out := flag.String("output", "", "new, private output directory")
	iface := flag.String("interface", "", "target controller interface (empty: choose before running)")
	mode := flag.Int("target-mode", -1, "explicit target mode; -1 requires preserving the source mode")
	flag.Parse()
	if *input == "" || *out == "" {
		flag.Usage()
		os.Exit(2)
	}
	data, err := os.ReadFile(*input)
	if err != nil {
		fatal(err)
	}
	converted, err := admin.ConvertVendorBackup(data, *iface, *mode)
	if err != nil {
		fatal(err)
	}
	if err := os.Mkdir(*out, 0700); err != nil {
		fatal(err)
	}
	write := func(name string, value any) {
		b, e := json.MarshalIndent(value, "", "  ")
		if e != nil {
			fatal(e)
		}
		if e = os.WriteFile(filepath.Join(*out, name), append(b, '\n'), 0600); e != nil {
			fatal(e)
		}
	}
	write("go-ac-configuration.json", map[string]any{"format": "go-ac-configuration", "schema": 1, "config": converted.Config})
	write("controller.json", converted.Config)
	write("conversion-report.json", converted.Report)
	if len(converted.APDB) > 0 {
		write("apdb-nego.json", converted.APDB)
	}
	fmt.Printf("Converted %d AP records, %d radios, %d services, %d client names; %d review warnings. Files: %s\n", len(converted.Config.APProfiles), len(converted.Config.Radios), len(converted.Config.Services), len(converted.Config.ClientLabels), len(converted.Report.Warnings), *out)
}
func fatal(err error) { fmt.Fprintln(os.Stderr, err); os.Exit(1) }
