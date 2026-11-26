package capwap

import (
	"bytes"
	"testing"
)

func TestAP1400ByteFragmentsOutOfOrder(t *testing.T) {
	p, _ := NewParsedPacket(9)
	p.Header.Type = 1
	p.Elements = []Element{{Type: 0x25, Value: bytes.Repeat([]byte{42}, 1800)}}
	whole := p.Assemble()
	frag := func(start, end int, last uint8) []byte {
		h := p.Header
		h.F = 1
		h.FragID = 731
		h.L = last
		h.FragOff = uint16(start / 8)
		return append(AppendHeader(nil, h), whole[8+start:8+end]...)
	}
	a := frag(0, 1400, 0)
	b := frag(1400, len(whole)-8, 1)
	var r Reassembler
	if v, e := r.Push("AP/session1", b); v != nil || e != nil {
		t.Fatal(e)
	}
	if v, e := r.Push("AP/session1", b); v != nil || e != nil {
		t.Fatal("duplicate fragment", e)
	}
	v, e := r.Push("AP/session1", a)
	if e != nil || !bytes.Equal(v, whole) {
		t.Fatal("reassembly failed", e)
	}
	if _, e := ParseDTLSPacket(v); e != nil {
		t.Fatal(e)
	}
	if v, _ := r.Push("AP/session1", a); v != nil {
		t.Fatal("premature completion")
	}
	if v, _ := r.Push("AP/session2", b); v != nil {
		t.Fatal("cross-session fragment merge")
	}
}
func TestRejectOverlappingFragmentAndBadHeader(t *testing.T) {
	var r Reassembler
	h := Header{Hlen: 2, F: 1}
	a := append(AppendHeader(nil, h), make([]byte, 16)...)
	h.FragOff = 1
	h.L = 1
	b := append(AppendHeader(nil, h), make([]byte, 16)...)
	if _, e := r.Push("AP", a); e != nil {
		t.Fatal(e)
	}
	if _, e := r.Push("AP", b); e == nil {
		t.Fatal("accepted overlap")
	}
	if _, _, e := ParseHeader(make([]byte, 1100)); e == nil {
		t.Fatal("accepted invalid header length")
	}
}
