package capwap

import "testing"

// Batch-4 fixed-length elements: lengths per elements.tsv, synthetic
// roundtrips (fields from the vendor assemble restore sequences).
func TestBatch4Roundtrips(t *testing.T) {
	cases := []struct {
		name  string
		val   []byte
		parse func([]byte) (any, error)
		asm   func() []byte
	}{
		{"wire vlan", make4(7), func(b []byte) (any, error) { return ParsePrivApWireVlan(b) },
			func() []byte { return PrivApWireVlan(7).AssembleValue() }},
		{"wire vlan2", make8v(1, 2, 3, 4), func(b []byte) (any, error) { return ParsePrivApWireVlan2(b) },
			func() []byte { v, _ := ParsePrivApWireVlan2(make8v(1, 2, 3, 4)); return v.AssembleValue() }},
		{"ap trunk", make4(3), func(b []byte) (any, error) { return ParsePrivApTrunk(b) },
			func() []byte { return PrivApTrunk(3).AssembleValue() }},
		{"switch link", make4(1), func(b []byte) (any, error) { return ParsePrivApSwitchLink(b) },
			func() []byte { return PrivApSwitchLink(1).AssembleValue() }},
		{"working channel", make24(), func(b []byte) (any, error) { return ParsePrivWorkingChannelList(b) },
			func() []byte { p, _ := ParsePrivWorkingChannelList(make24()); return p.AssembleValue() }},
		{"telnet config", []byte{1, 0x23, 0x7a}, func(b []byte) (any, error) { return ParsePrivTelnetConfig(b) },
			func() []byte { return PrivTelnetConfig{1, 9082}.AssembleValue() }},
		{"config checksum", make16(), func(b []byte) (any, error) { return ParsePrivConfigChecksum(b) },
			func() []byte { p, _ := ParsePrivConfigChecksum(make16()); return p.AssembleValue() }},
		{"checksum result", []byte{1}, func(b []byte) (any, error) { return ParsePrivChecksumResult(b) },
			func() []byte { return PrivChecksumResult(1).AssembleValue() }},
		{"rate2", make4(20), func(b []byte) (any, error) { return ParsePrivRate2(b) },
			func() []byte { return PrivRate2(20).AssembleValue() }},
	}
	for _, c := range cases {
		t.Run(c.name, func(t *testing.T) {
			v, err := c.parse(c.val)
			if err != nil {
				t.Fatalf("parse: %v", err)
			}
			_ = v
			if got := c.asm(); !bytesEqBytes(got, c.val) {
				t.Fatalf("roundtrip %x != %x", got, c.val)
			}
			// wrong length must be rejected
			if _, err := c.parse(c.val[:len(c.val)-1]); err == nil && len(c.val) > 1 {
				t.Fatal("short parse must fail")
			}
		})
	}
}

func make4(v uint32) []byte { return AppendUint32BE(nil, v) }
func make8v(a, b, c, d uint16) []byte {
	out := AppendUint16BE(nil, a)
	out = AppendUint16BE(out, b)
	out = AppendUint16BE(out, c)
	return AppendUint16BE(out, d)
}
func make24() []byte {
	out := make([]byte, 24)
	for i := range out {
		out[i] = byte(i)
	}
	return out
}
func make16() []byte {
	out := make([]byte, 16)
	for i := range out {
		out[i] = byte(i * 2)
	}
	return out
}

func bytesEqBytes(a, b []byte) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
