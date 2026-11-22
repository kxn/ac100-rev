package capwap

import (
	"bytes"
	"testing"
)

func TestBatch21Roundtrips(t *testing.T) {
	fw := PrivAPFirmwareID{A: 7, Rest: []byte{1, 2, 3}}
	fw.Blk1[0] = 0x11
	fw.Blk2[15] = 0x22
	wire := fw.AssembleValue()
	if len(wire) != 36 {
		t.Fatalf("fw id wire = %d", len(wire))
	}
	if v, err := ParsePrivAPFirmwareID(wire); err != nil || v.A != 7 ||
		v.Blk1[0] != 0x11 || v.Blk2[15] != 0x22 || !bytes.Equal(v.Rest, fw.Rest) {
		t.Fatalf("fw id: %v", err)
	}

	lr := PrivLLDPReport{W: 9, Rest: []byte{4, 5}}
	if v, err := ParsePrivLLDPReport(lr.AssembleValue()); err != nil || v.W != 9 || !bytes.Equal(v.Rest, lr.Rest) {
		t.Fatalf("lldp report: %v", err)
	}
}
