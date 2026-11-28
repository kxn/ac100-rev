// Package data embeds the public offline lookup data shipped with the program.
package data

import _ "embed"

// IEEERegistry is the complete prepared public registry, including display names.
// The compressed bytes are immutable; no download or translation runs in AC.
//
//go:embed oui/registry.json.gz
var IEEERegistry []byte
