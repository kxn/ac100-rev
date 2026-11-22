// Package testroot resolves the ac100-rev repository root for tests that
// read evidence artifacts (vendor packet fixtures, notes, rate table).
// Set AC100_REV_ROOT to override; the default assumes the checkout layout
// (<repo>/uacgo/<pkg> → <repo>).
package testroot

import "os"

// Root returns the repository root directory.
func Root() string {
	if r := os.Getenv("AC100_REV_ROOT"); r != "" {
		return r
	}
	wd, err := os.Getwd()
	if err != nil {
		return ".."
	}
	// tests run from uacgo/<pkg>; the repo root is two levels up
	return wd + "/../.."
}
