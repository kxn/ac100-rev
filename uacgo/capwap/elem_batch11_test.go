package capwap

import (
	"bytes"
	"testing"
)

// Batch-11: ac ipv6 list, location data, wtp name, wtp board data.
func TestBatch11Roundtrips(t *testing.T) {
	ips := [][16]byte{{1, 2}, {3, 4}}
	e := AppendACIPv6List(nil, ips)
	if v, err := ParseACIPv6List(e[4:]); err != nil || len(v) != 2 || v[1][1] != 4 {
		t.Fatalf("ipv6 list: %v", err)
	}
	if _, err := ParseACIPv6List(e[4 : len(e)-2]); err == nil {
		t.Fatal("non-16 stride must fail")
	}

	e = AppendLocationData(nil, "  Next to Fridge")
	if v, err := ParseLocationData(e[4:]); err != nil || v != "  Next to Fridge" {
		t.Fatalf("location: %v", err)
	}
	if _, err := ParseLocationData(nil); err == nil {
		t.Fatal("empty location must fail (min 1)")
	}

	e = AppendWTPName(nil, "My WTP 1")
	if v, err := ParseLocationData(e[4:]); err != nil || v != "My WTP 1" {
		t.Fatalf("wtp name via location codec: %v", err)
	}

	// board data: vendor + sub-element, join fixture already validated the
	// read side in cweng; here we check the write side framing.
	subs := []ACDescriptorSubElement{{Vendor: 0x12345678, Type: 1, Data: []byte("0000147590db8092")}}
	e = AppendWTPBoardData(nil, 0x12345678, subs)
	want := AppendUint32BE(nil, 0x12345678)
	want = AppendUint16BE(want, 1)
	want = AppendUint16BE(want, uint16(len(subs[0].Data)))
	want = append(want, subs[0].Data...)
	if !bytes.Equal(e[4:], want) {
		t.Fatalf("board data framing %x != %x", e[4:], want)
	}
}
