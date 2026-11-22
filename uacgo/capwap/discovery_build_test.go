package capwap

import (
	"bytes"
	"encoding/hex"
	"os"
	"testing"
	"uacgo/internal/testroot"
)

// Rebuild the vendor's cw_dis_rsp fixture from structured values and require
// byte identity. This proves the AC-side builders for AC Descriptor, AC Name,
// Control IPv4 Address, WTP Radio Information and the vendor envelope.
func TestBuildDiscoveryResponse(t *testing.T) {
	raw, err := os.ReadFile(testroot.Root() + "/ghidra-export/data/cw_dis_rsp_0074f254.bin")
	if err != nil {
		t.Fatal(err)
	}

	pkt, err := NewParsedPacket(MsgDiscoveryResponse)
	if err != nil {
		t.Fatal(err)
	}
	// ac_parsed_packet_create @0x590d58 copies rid/wbid/seq from the request;
	// the fixture corresponds to a request with rid=0, seq=1.
	pkt.Header.Rid = 0
	pkt.Control.SeqNum = 1

	// AC Descriptor: fixture header + two vendor sub-elements.
	desc := ACDescriptor{
		Stations:    0,
		StationLim:  10000,
		ActiveStas:  0,
		ActiveLim:   1000,
		Status:      0x02,
		RStatus:     0x02,
		Reserved:    0,
		SlaveStatus: 0x04,
		SubElements: []ACDescriptorSubElement{
			{Vendor: 0x12345678, Type: 4, Data: PaddedString("TL-AC1000 v1.0", 64)},
			{Vendor: 0x12345678, Type: 5, Data: PaddedString("1.0.1 Build 20140919 Rel.59746", 64)},
		},
	}
	pkt.Elements = append(pkt.Elements, Element{Type: 0x0001, Value: desc.AssembleValue()})
	pkt.Elements = append(pkt.Elements, Element{Type: 0x0004, Value: []byte("TL-AC1000")})
	pkt.Elements = append(pkt.Elements, Element{Type: 0x000a,
		Value: []byte{0xc0, 0xa8, 0x01, 0xfd, 0x00, 0x00}})
	pkt.Elements = append(pkt.Elements,
		Element{Type: 0x0418, Value: []byte{1, 0, 0, 0, 0}},
		Element{Type: 0x0418, Value: []byte{2, 0, 0, 0, 0}})
	pkt.Elements = append(pkt.Elements, Element{Type: 0x0025, Value: VendorEnvelopeValue(
		0x12345678, 0, []PrivElementValue{{Type: 0, Value: []byte{0, 1, 0, 1}}})})

	got := pkt.Assemble()
	if !bytes.Equal(got, raw) {
		t.Fatalf("discovery response mismatch\n got: %s\nwant: %s",
			hex.EncodeToString(got), hex.EncodeToString(raw))
	}
}
