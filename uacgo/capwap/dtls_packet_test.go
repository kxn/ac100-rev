package capwap

import "testing"

func TestAuthenticatedAPControlMarker(t *testing.T) {
	p, _ := NewParsedPacket(MsgJoinRequest)
	p.Header.Type = 1
	b := p.Assemble()
	if _, err := ParsePacket(b); err == nil {
		t.Fatal("unauthenticated type=1 control accepted")
	}
	got, err := ParseDTLSPacket(b)
	if err != nil || got.Control.MsgType != MsgJoinRequest || got.Header.Type != 1 {
		t.Fatalf("authenticated AP control packet: %v", err)
	}
	p.Header.Type = 2
	if _, err := ParseDTLSPacket(p.Assemble()); err == nil {
		t.Fatal("unknown inner type accepted")
	}
}
