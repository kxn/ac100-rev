package capwap

import (
	"bytes"
	"testing"
)

func TestBatch21Roundtrips(t *testing.T) {
	fw := PrivAPFirmwareID{FirmwareID: [16]byte{0x11}, Blocked: [][16]byte{{0x22}, {0x33}}}
	wire := fw.AssembleValue()
	if len(wire) != 49 || wire[16] != 2 {
		t.Fatalf("wire %x", wire)
	}
	v, err := ParsePrivAPFirmwareID(wire)
	if err != nil || v.FirmwareID != fw.FirmwareID || len(v.Blocked) != 2 || v.Blocked[1] != fw.Blocked[1] {
		t.Fatalf("parse %+v %v", v, err)
	}
	for _, bad := range [][]byte{wire[:16], wire[:48], append(wire, 0), append(make([]byte, 16), 3)} {
		if _, err := ParsePrivAPFirmwareID(bad); err == nil {
			t.Fatalf("accepted %x", bad)
		}
	}
	zero := PrivAPFirmwareID{}
	if _, err := ParsePrivAPFirmwareID(zero.AssembleValue()); err != nil {
		t.Fatal(err)
	}

	lr := PrivLLDPReport{W: 9, Rest: []byte{4, 5}}
	if v, err := ParsePrivLLDPReport(lr.AssembleValue()); err != nil || v.W != 9 || !bytes.Equal(v.Rest, lr.Rest) {
		t.Fatalf("lldp report: %v", err)
	}
}
