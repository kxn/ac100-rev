package cweng

import (
	"testing"
	"uacgo/capwap"
)

func TestAPReportsSparsePortIdentitiesRolesAndLAG(t *testing.T) {
	// Two packed ports: uplink ID12, downlink ID103. Layout coordinates are
	// irrelevant to configuring ports; physical identities must remain intact.
	raw := []byte{2, 12, 1, 0, 0, 0, 7, 103, 2, 0, 0, 9, 6}
	ports, err := parsePortCapabilities(raw)
	if err != nil || len(ports) != 2 || !ports[0].Uplink || ports[1].ID != 103 || !ports[1].LAG || ports[1].Type != 1 || ports[1].Uplink {
		t.Fatal(ports, err)
	}
	req, _ := capwap.NewParsedPacket(3)
	req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0xc8, []capwap.PrivElementValue{{Type: 0xc8, Value: capwap.AssembleVendorList([]capwap.VendorRecord{{Type: 12, Value: raw}})}})}}
	ap, err := ParseAPEntry(req)
	if err != nil || len(ap.Ports) != 2 || ap.Ports[1].ID != 103 {
		t.Fatal(ap, err)
	}
	bad := append([]byte{}, raw...)
	bad[7] = 12
	if _, err := parsePortCapabilities(bad); err == nil {
		t.Fatal("duplicate physical port accepted")
	}
	if _, err := parsePortCapabilities(raw[:len(raw)-1]); err == nil {
		t.Fatal("truncated port info accepted")
	}
}
