package ouidb

import (
	"bytes"
	"compress/gzip"
	"crypto/sha256"
	"encoding/json"
	"fmt"
	"os"
	"strings"
	"testing"
)

func TestLongestAssignmentAndHistoricalAmbiguity(t *testing.T) {
	raw := `{"schema":1,"organizations":[{"name":"Parent"},{"name":"Medium","brand":"M"},{"name":"Small"},{"name":"Historic"}],"assignments":[{"prefix":"001122","bits":24,"registry":"MA-L","organization":0},{"prefix":"0011223","bits":28,"registry":"MA-M","organization":1},{"prefix":"001122345","bits":36,"registry":"MA-S","organization":2},{"prefix":"001122345","bits":36,"registry":"IAB","organization":3}]}`
	var b bytes.Buffer
	z := gzip.NewWriter(&b)
	z.Write([]byte(raw))
	z.Close()
	db, err := Load(&b)
	if err != nil {
		t.Fatal(err)
	}
	for _, tc := range []struct {
		mac         string
		count, bits int
		name        string
	}{{"00:11:22:34:56:78", 2, 36, "Small"}, {"00:11:22:3f:00:00", 1, 28, "Medium"}, {"00:11:22:ff:00:00", 1, 24, "Parent"}} {
		got, err := db.LookupString(tc.mac)
		if err != nil || len(got) != tc.count || got[0].Bits != tc.bits || got[0].Organization != tc.name {
			t.Fatal(tc, got, err)
		}
	}
	hint := db.LookupOUI([3]byte{0, 0x11, 0x22})
	if len(hint) != 1 || hint[0].Bits != 24 || hint[0].Organization != "Parent" {
		t.Fatal("3-byte hint fabricated a narrow prefix", hint)
	}
	for _, mac := range []string{"02:11:22:34:56:78", "01:11:22:34:56:78", "00:ff:ee:00:00:01"} {
		got, err := db.LookupString(mac)
		if err != nil || len(got) != 0 {
			t.Fatal(mac, got, err)
		}
	}
}

func TestPreparedSnapshotKeepsEveryPublicAssignment(t *testing.T) {
	f, err := os.Open("../data/oui/registry.json.gz")
	if err != nil {
		t.Fatal(err)
	}
	defer f.Close()
	db, err := Load(f)
	if err != nil {
		t.Fatal(err)
	}
	b, err := os.ReadFile("../data/oui/manifest.json")
	if err != nil {
		t.Fatal(err)
	}
	var manifest struct {
		Assignments    int    `json:"assignments"`
		ArtifactSHA256 string `json:"artifact_sha256"`
	}
	if err = json.Unmarshal(b, &manifest); err != nil {
		t.Fatal(err)
	}
	raw, err := os.ReadFile("../data/oui/registry.json.gz")
	if err != nil {
		t.Fatal(err)
	}
	if fmt.Sprintf("%x", sha256.Sum256(raw)) != manifest.ArtifactSHA256 {
		t.Fatal("artifact fingerprint changed without manifest")
	}
	if db.Count() != manifest.Assignments || len(db.Sources()) != 4 {
		t.Fatal("snapshot lost public rows", db.Count(), manifest)
	}
	got, err := db.LookupString("08:00:30:00:00:01")
	if err != nil || len(got) != 3 {
		t.Fatal("historical multi-registrant prefix collapsed", got, err)
	}
	if !strings.Contains(got[0].Organization, "RESEARCH") {
		t.Fatal(got)
	}
}

func TestDefaultRegistryUsesCompleteSnapshotAndChineseReference(t *testing.T) {
	a, b := Default(), Default()
	if a != b || a.Count() != 59150 {
		t.Fatal("not one complete immutable registry")
	}
	m, err := a.LookupString("24:6f:28:00:00:01")
	if err != nil || len(m) != 1 || m[0].Brand != "Espressif" || m[0].BrandZH != "乐鑫" || m[0].OrganizationZH == "" || m[0].Organization == "" {
		t.Fatal(m, err)
	}
}
