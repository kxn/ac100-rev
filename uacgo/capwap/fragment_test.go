package capwap

import (
	"bytes"
	"testing"
)

func TestLargeCertificateFragmentsReassembleOutOfOrder(t *testing.T) {
	p, _ := NewParsedPacket(7)
	p.Control.SeqNum = 19
	p.Elements = []Element{{Type: 0x25, Value: bytes.Repeat([]byte{0x56}, 61440)}}
	original := p.Assemble()
	parts, err := FragmentPacket(original, 0x1234, 1200)
	if err != nil || len(parts) < 50 {
		t.Fatal(len(parts), err)
	}
	var r Reassembler
	var joined []byte
	for i := len(parts) - 1; i >= 0; i-- {
		h, n, err := ParseHeader(parts[i])
		if err != nil || h.F != 1 || h.FragID != 0x1234 || int(h.FragOff)*8 != i*1192 || len(parts[i]) > 1200 || i < len(parts)-1 && (len(parts[i])-n)%8 != 0 {
			t.Fatal(i, h, err)
		}
		v, err := r.Push("authenticated-ap", parts[i])
		if err != nil {
			t.Fatal(err)
		}
		if v != nil {
			joined = v
		}
	}
	if !bytes.Equal(joined, original) {
		t.Fatal("large certificate changed in CAPWAP fragmentation")
	}
}
