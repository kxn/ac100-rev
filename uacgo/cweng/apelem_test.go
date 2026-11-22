package cweng

import (
	"testing"

	"uacgo/capwap"
)

// Parse the vendor cw_join_req fixture: the AP's identity elements must come
// out with the values encoded in the vendor template
// (name "My WTP 1", location "Next to Fridge", local ip 192.168.1.200).
func TestParseAPEntryFromFixture(t *testing.T) {
	raw := mustFixture(t, "cw_join_req_0074f150.bin")
	pkt, err := capwap.ParsePacket(raw)
	if err != nil {
		t.Fatal(err)
	}
	ap, err := ParseAPEntry(pkt)
	if err != nil {
		t.Fatal(err)
	}
	if ap.Name != "My WTP 1" {
		t.Fatalf("name = %q", ap.Name)
	}
	if ap.Location != "  Next to Fridge" { // fixture keeps two leading spaces
		t.Fatalf("location = %q", ap.Location)
	}
	if ap.LocalIP != [4]byte{192, 168, 1, 200} {
		t.Fatalf("local ip = %v", ap.LocalIP)
	}
	if ap.RadioCount != 2 {
		t.Fatalf("radio count = %d", ap.RadioCount)
	}
	if ap.Serial == "" {
		t.Fatal("serial missing (board data sub-element 1)")
	}
	t.Logf("model=%d serial=%s", ap.ModelID, ap.Serial)
}
