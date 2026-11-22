package capwap

import (
	"bytes"
	"testing"
)

// Batch-9: ac name with priority, duplicate address report, image
// identifier roundtrips; DTLS record header roundtrip validates the layout
// behind the clienthello rule.
func TestBatch9Roundtrips(t *testing.T) {
	e := AppendACNameWithPriority(nil, 3, "AC-1")
	if p, name, err := ParseACNameWithPriority(e[4:]); err != nil || p != 3 || name != "AC-1" {
		t.Fatalf("ac name priority: %v", err)
	}

	// duplicate ipv4: status(4) + type(1) + len(1) + addr(4..6)
	d := DuplicateAddr{Status: 1, Type: 4, Addr: []byte{10, 0, 0, 9, 0, 0}}
	if v, err := ParseDuplicateIPv4Address(d.AssembleValue()); err != nil ||
		v.Status != 1 || !bytes.Equal(v.Addr, []byte{10, 0, 0, 9, 0, 0}) {
		t.Fatalf("duplicate addr: %v", err)
	}
	if _, err := ParseDuplicateIPv4Address(d.AssembleValue()[:11]); err == nil {
		t.Fatal("too-short duplicate addr must fail")
	}

	// image identifier: vendor + payload
	e = AppendImageIdentifier(nil, 0x12345678, []byte{1, 2})
	if v, p, err := ParseImageIdentifier(e[4:]); err != nil || v != 0x12345678 || !bytes.Equal(p, []byte{1, 2}) {
		t.Fatalf("image identifier: %v", err)
	}

	// DTLS record header: layout must agree with the clienthello offsets
	// (4-byte prefix + record: content type at +4, handshake byte at +17).
	var rec []byte
	rec = AppendDTLSRecordHeader(rec, DTLSRecordHeader{
		ContentType: 0x16, Version: 0xfefd, Epoch: 0,
		Sequence: 0x0102030405, Length: 64})
	rec = append(rec, make([]byte, 64+4)...)
	// vendor buffer = 4-byte prefix + record: content type lands at [4],
	// handshake type byte at [4+13] = [17] (clienthello rule offsets).
	prefixed := append([]byte{1, 0, 0, 1}, rec...) // prefix[0]=1 per the rule
	if prefixed[4] != 0x16 {
		t.Fatalf("content type offset wrong: %#x", prefixed[4])
	}
	// handshake type byte sits at prefix(4)+record header(13) = 17
	prefixed[17] = 1
	if !IsClientHelloLike(prefixed) {
		t.Fatal("prefixed record with handshake type 1 should match the rule")
	}
	h, err := ParseDTLSRecordHeader(rec)
	if err != nil {
		t.Fatal(err)
	}
	if h.ContentType != 0x16 || h.Version != 0xfefd || h.Length != 64 || h.Sequence != 0x0102030405 {
		t.Fatalf("record header %+v", h)
	}
}

func IsClientHelloLike(b []byte) bool {
	return len(b) > 0x11 && b[0] == 1 && b[4] == 0x16 && b[0x11] == 1
}
