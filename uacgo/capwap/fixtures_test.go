package capwap

import (
	"encoding/hex"
	"os"
	"path/filepath"
	"testing"
	"uacgo/internal/testroot"
)

// Fixtures are the vendor's own prebuilt packets (g_cw_* data symbols in the
// binary's .data segment, extracted verbatim by re/scripts/syms.py extract).
// Parse must succeed and re-assemble must reproduce the original bytes.
var fixtureDir = testroot.Root() + "/ghidra-export/data"

func fixtureFiles(t *testing.T) map[string][]byte {
	t.Helper()
	entries, err := os.ReadDir(fixtureDir)
	if err != nil {
		t.Fatalf("read fixture dir: %v", err)
	}
	out := map[string][]byte{}
	for _, e := range entries {
		name := e.Name()
		b, err := os.ReadFile(filepath.Join(fixtureDir, name))
		if err != nil {
			t.Fatalf("read %s: %v", name, err)
		}
		base := name
		for i := 0; i < len(base); i++ {
			if base[i] == '_' && base[i+1] == '0' {
				base = base[:i]
				break
			}
		}
		out[base] = b
	}
	return out
}

func TestParseVendorFixtures(t *testing.T) {
	fixtures := fixtureFiles(t)
	if len(fixtures) < 10 {
		t.Fatalf("expected >=10 fixtures, got %d", len(fixtures))
	}
	for name, raw := range fixtures {
		t.Run(name, func(t *testing.T) {
			pkt, err := ParsePacket(raw)
			if err != nil {
				t.Fatalf("parse: %v", err)
			}
			got := pkt.Assemble()
			if !bytesEqual(got, raw) {
				t.Fatalf("round-trip mismatch\n got: %s\nwant: %s",
					hex.EncodeToString(got), hex.EncodeToString(raw))
			}
		})
	}
}

func bytesEqual(a, b []byte) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

// cw_dis_req asserts the exact control framing the binary produced:
// word0=0x00104300 (ver0,type0,hlen2,rid1,wbid1,T1), msg=1, seq=1, MEL=2364.
func TestDisReqFraming(t *testing.T) {
	raw := fixtureFiles(t)["cw_dis_req"]
	pkt, err := ParsePacket(raw)
	if err != nil {
		t.Fatal(err)
	}
	if pkt.Header.Version != 0 || pkt.Header.Type != 0 || pkt.Header.Hlen != 2 ||
		pkt.Header.Rid != 1 || pkt.Header.Wbid != 1 || pkt.Header.T != 1 {
		t.Fatalf("header mismatch: %+v", pkt.Header)
	}
	if pkt.Control.MsgType != MsgDiscoveryRequest {
		t.Fatalf("msg type = %d", pkt.Control.MsgType)
	}
	if pkt.Control.SeqNum != 1 {
		t.Fatalf("seq = %d", pkt.Control.SeqNum)
	}
	if pkt.Control.MEL != 2364 {
		t.Fatalf("MEL = %d", pkt.Control.MEL)
	}
	if len(raw)-16 != int(pkt.Control.MEL)-3 {
		t.Fatalf("elements %d != MEL-3 %d", len(raw)-16, int(pkt.Control.MEL)-3)
	}
	// first element: discovery type (0x14), len 1, value 2
	e := pkt.Elements[0]
	if e.Type != 0x14 || e.Len != 1 || e.Value[0] != 2 {
		t.Fatalf("first element = %+v", e)
	}
}

// cw_wlan_cfg_req uses the pseudo message 0x33dd01 and a 0x25 envelope:
// vendor 0x12345678 + u16 + private TLVs (0x09 wlan list etc.).
func TestWlanCfgReqPseudoMsgAndEnvelope(t *testing.T) {
	raw := fixtureFiles(t)["cw_wlan_cfg_req"]
	pkt, err := ParsePacket(raw)
	if err != nil {
		t.Fatal(err)
	}
	if pkt.Control.MsgType != MsgIe1 {
		t.Fatalf("msg type = %#x", pkt.Control.MsgType)
	}
	var env *Element
	for i := range pkt.Elements {
		if pkt.Elements[i].Type == EleVendorSpecificPayload {
			env = &pkt.Elements[i]
		}
	}
	if env == nil {
		t.Fatal("no 0x25 envelope element")
	}
	if env.Value[0] != 0x12 || env.Value[1] != 0x34 || env.Value[2] != 0x56 || env.Value[3] != 0x78 {
		t.Fatalf("vendor id = %x", env.Value[:4])
	}
}
