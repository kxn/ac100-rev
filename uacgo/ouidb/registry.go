// Package ouidb reads an offline IEEE registry snapshot. It is independent of
// the firmware-derived terminal recognition policy; loading it does not change
// controller scheduling, authentication, or the existing classification rules.
package ouidb

import (
	"compress/gzip"
	"encoding/json"
	"fmt"
	"io"
	"net"
	"sort"
	"strconv"
)

type Organization struct {
	Name         string `json:"name"`
	Brand        string `json:"brand"`
	NameZH       string `json:"name_zh,omitempty"`
	NameZHSource string `json:"name_zh_source,omitempty"`
	BrandZH      string `json:"brand_zh,omitempty"`
}
type Source struct {
	URL    string `json:"url"`
	SHA256 string `json:"sha256"`
	Rows   int    `json:"rows"`
	Bytes  int    `json:"bytes"`
}
type assignment struct {
	prefix       uint64
	organization int
	registry     string
}
type Database struct {
	organizations []Organization
	groups        [3][]assignment
	sources       []Source
}
type Match struct {
	Prefix            string `json:"prefix"`
	Bits              int    `json:"prefix_bits"`
	Registry          string `json:"registry"`
	Organization      string `json:"organization"`
	Brand             string `json:"brand,omitempty"`
	OrganizationZH    string `json:"organization_zh,omitempty"`
	TranslationSource string `json:"translation_source,omitempty"`
	BrandZH           string `json:"brand_zh,omitempty"`
}

// Load accepts the registry.json.gz produced by tools/prepare_oui.py.
func Load(r io.Reader) (*Database, error) {
	z, err := gzip.NewReader(r)
	if err != nil {
		return nil, err
	}
	defer z.Close()
	var file struct {
		Schema        int            `json:"schema"`
		Sources       []Source       `json:"sources"`
		Organizations []Organization `json:"organizations"`
		Assignments   []struct {
			Prefix       string `json:"prefix"`
			Bits         int    `json:"bits"`
			Registry     string `json:"registry"`
			Organization int    `json:"organization"`
		} `json:"assignments"`
	}
	dec := json.NewDecoder(z)
	if err = dec.Decode(&file); err != nil {
		return nil, err
	}
	if err = dec.Decode(new(any)); err != io.EOF {
		if err == nil {
			err = fmt.Errorf("multiple registry documents")
		}
		return nil, err
	}
	if file.Schema != 1 {
		return nil, fmt.Errorf("unsupported OUI schema %d", file.Schema)
	}
	db := &Database{organizations: file.Organizations, sources: file.Sources}
	for _, a := range file.Assignments {
		group := -1
		switch a.Bits {
		case 24:
			group = 0
		case 28:
			group = 1
		case 36:
			group = 2
		}
		prefix, err := strconv.ParseUint(a.Prefix, 16, 64)
		if err != nil || group < 0 || len(a.Prefix)*4 != a.Bits || a.Organization < 0 || a.Organization >= len(db.organizations) {
			return nil, fmt.Errorf("invalid OUI assignment %q/%d", a.Prefix, a.Bits)
		}
		db.groups[group] = append(db.groups[group], assignment{prefix, a.Organization, a.Registry})
	}
	for _, group := range db.groups {
		sort.SliceStable(group, func(i, j int) bool { return group[i].prefix < group[j].prefix })
	}
	return db, nil
}
func (db *Database) Sources() []Source { return append([]Source(nil), db.sources...) }
func (db *Database) Count() int        { return len(db.groups[0]) + len(db.groups[1]) + len(db.groups[2]) }

// Lookup uses the longest public assignment: MA-S/IAB(36), MA-M(28), MA-L(24).
// Locally administered/random and multicast addresses are not factory identity.
// IEEE has historical duplicate prefixes; return all equally specific matches
// instead of silently selecting or dropping one registrant.
func (db *Database) Lookup(mac net.HardwareAddr) []Match {
	if len(mac) != 6 || mac[0]&3 != 0 {
		return nil
	}
	var value uint64
	for _, b := range mac {
		value = value<<8 | uint64(b)
	}
	for group := 2; group >= 0; group-- {
		bits := [3]int{24, 28, 36}[group]
		prefix := value >> uint(48-bits)
		out := db.lookupPrefix(bits, prefix)
		if len(out) > 0 {
			return out
		}
	}
	return nil
}
func (db *Database) lookupPrefix(bits int, prefix uint64) []Match {
	group := 0
	if bits == 28 {
		group = 1
	}
	if bits == 36 {
		group = 2
	}
	rows := db.groups[group]
	i := sort.Search(len(rows), func(i int) bool { return rows[i].prefix >= prefix })
	var out []Match
	for ; i < len(rows) && rows[i].prefix == prefix; i++ {
		a := rows[i]
		org := db.organizations[a.organization]
		out = append(out, Match{Prefix: fmt.Sprintf("%0*X", bits/4, prefix), Bits: bits, Registry: a.registry, Organization: org.Name, Brand: org.Brand, OrganizationZH: org.NameZH, TranslationSource: org.NameZHSource, BrandZH: org.BrandZH})
	}
	return out
}

func (db *Database) LookupString(mac string) ([]Match, error) {
	parsed, err := net.ParseMAC(mac)
	if err != nil {
		return nil, err
	}
	if len(parsed) != 6 {
		return nil, fmt.Errorf("expected EUI-48 MAC")
	}
	return db.Lookup(parsed), nil
}
