package capwap

import (
	"bytes"
	"os"
	"testing"
	"uacgo/internal/testroot"
)

func mustFixtureBytes(t *testing.T, name string) []byte {
	t.Helper()
	b, err := os.ReadFile(testroot.Root() + "/uacgo/testdata/" + name)
	if err != nil {
		t.Fatal(err)
	}
	return b
}

// Parse the WTP Descriptor carried in the vendor cw_join_req fixture and
// re-assemble it byte-identically (cw_wtp_descriptor_parse @0x584978).
func TestParseWTPDescriptorFixture(t *testing.T) {
	pkt, err := ParsePacket(mustFixtureBytes(t, "cw_join_req_0074f150.bin"))
	if err != nil {
		t.Fatal(err)
	}
	var raw []byte
	for _, e := range pkt.Elements {
		if e.Type == 0x0027 {
			raw = e.Value
		}
	}
	if raw == nil {
		t.Fatal("join fixture carries no 0x27")
	}
	d, err := ParseWTPDescriptor(raw)
	if err != nil {
		t.Fatalf("parse: %v", err)
	}
	if d.RadioCount != 2 || d.RadiosInUse != 0 {
		t.Fatalf("radios = %d/%d", d.RadioCount, d.RadiosInUse)
	}
	if len(d.Encryption) != 1 || d.Encryption[0].WBID != 1 {
		t.Fatalf("encryption = %+v", d.Encryption)
	}
	if len(d.SubElements) < 2 {
		t.Fatalf("sub elements = %d", len(d.SubElements))
	}
	if d.SubElements[0].Vendor != 0x12345678 {
		t.Fatalf("sub vendor = %#x", d.SubElements[0].Vendor)
	}
	if !bytes.Equal(d.AssembleValue(), raw) {
		t.Fatalf("round-trip mismatch\n got %x\nwant %x", d.AssembleValue(), raw)
	}
}
