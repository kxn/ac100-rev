package capwap

import (
	"bytes"
	"encoding/hex"
	"os"
	"testing"
	"uacgo/internal/testroot"
)

// Rebuild the vendor join response (cw_join_rsp) and config status response
// (cw_cfg_rsp) fixtures byte-for-byte from structured values, proving the
// framing of every element type they carry (0x21/0x01/0x04/0x418/0x35/0x0a/
// 0x1e/0x25 envelopes, and 0x0c/0x10/0x17/0x28/0x02).

func mustRaw(t *testing.T, name string) []byte {
	t.Helper()
	b, err := os.ReadFile(testroot.Root() + "/ghidra-export/data/" + name)
	if err != nil {
		t.Fatal(err)
	}
	return b
}

func TestBuildJoinResponse(t *testing.T) {
	raw := mustRaw(t, "cw_join_rsp_0074efe8.bin")

	pkt, _ := NewParsedPacket(MsgJoinResponse)
	pkt.Header.Rid = 0
	pkt.Control.SeqNum = 2

	desc := ACDescriptor{
		Stations: 0, StationLim: 10000, ActiveStas: 1, ActiveLim: 1000,
		Status: 2, RStatus: 2, SlaveStatus: 4,
		SubElements: []ACDescriptorSubElement{
			{Vendor: 0x12345678, Type: 4, Data: PaddedString("TL-AC1000 v1.0", 64)},
			{Vendor: 0x12345678, Type: 5, Data: PaddedString("1.0.1 Build 20140919 Rel.59746", 64)},
		},
	}
	pkt.Elements = append(pkt.Elements,
		Element{Type: 0x0021, Value: []byte{0, 0, 0, 0}}, // result code 0
		Element{Type: 0x0001, Value: desc.AssembleValue()},
		Element{Type: 0x0004, Value: []byte("TL-AC1000")},
		Element{Type: 0x0418, Value: []byte{1, 0, 0, 0, 0}},
		Element{Type: 0x0418, Value: []byte{2, 0, 0, 0, 0}},
		Element{Type: 0x0035, Value: []byte{0}}, // ECN support
		Element{Type: 0x000a, Value: []byte{0xc0, 0xa8, 0x01, 0xfd, 0x00, 0x01}},
		Element{Type: 0x001e, Value: []byte{0xc0, 0xa8, 0x01, 0xfd}}, // local ipv4
		// vendor envelopes verbatim (runtime data: cwver / ap-info / ap res /
		// tunnel mode / config type)
		Element{Type: 0x0025, Value: mustHex(t, "1234567800000000000400010001")},
		Element{Type: 0x0025, Value: mustHex(t, "12345678001b001b0006085700c21fa0")},
		Element{Type: 0x0025, Value: mustHex(t, "12345678001200120020d41d8cd98f00b204e9800998ecf8427e1e4a1b03d1b6cd8a174a826f76e009f4")},
		Element{Type: 0x0025, Value: mustHex(t, "12345678001d001d000400000002")},
		Element{Type: 0x0025, Value: mustHex(t, "1234567800270027000400000000")},
	)

	got := pkt.Assemble()
	if !bytes.Equal(got, raw) {
		t.Fatalf("join response mismatch\n got: %s\nwant: %s",
			hex.EncodeToString(got), hex.EncodeToString(raw))
	}
}

func TestBuildConfigStatusResponse(t *testing.T) {
	raw := mustRaw(t, "cw_cfg_rsp_0074eeb4.bin")

	pkt, _ := NewParsedPacket(MsgConfigurationStatusResponse)
	pkt.Header.Rid = 0
	pkt.Control.SeqNum = 3

	pkt.Elements = append(pkt.Elements,
		Element{Type: 0x000c, Value: []byte{0x14, 0x14}}, // timers 20/20
		Element{Type: 0x0010, Value: []byte{0x01, 0x00, 0x78}},
		Element{Type: 0x0017, Value: []byte{0x00, 0x00, 0x0e, 0x10}}, // idle 3600
		Element{Type: 0x0028, Value: []byte{1}},                      // wtp fallback
		Element{Type: 0x0002, Value: []byte{0xc0, 0xa8, 0x01, 0xfd}}, // AC ipv4 list
		Element{Type: 0x0025, Value: mustHex(t, "123456780005000500080000000a00000006")},
		Element{Type: 0x0025, Value: mustHex(t, "1234567800300030000400000000")},
		Element{Type: 0x0025, Value: mustHex(t, "12345678001e001e002900000002000000010130305f59584a5fe4b8ade696875f555446380000000000000000000000000000")},
		Element{Type: 0x0025, Value: mustHex(t, "123456780026002600080000003f0000003e")},
	)

	got := pkt.Assemble()
	if !bytes.Equal(got, raw) {
		t.Fatalf("cfg status response mismatch\n got: %s\nwant: %s",
			hex.EncodeToString(got), hex.EncodeToString(raw))
	}
}

func mustHex(t *testing.T, s string) []byte {
	t.Helper()
	b, err := hex.DecodeString(s)
	if err != nil {
		t.Fatal(err)
	}
	return b
}
