package cweng

import (
	"encoding/binary"
	"testing"
)

func linkageTableFixture() ([]byte, []byte) {
	control := []byte{2, 0, 0, 1, 1, 1, 0, 4, 0, 0, 0, 3}
	// table_mask2, two radios, feature_mask1(normal), five fields/radio,
	// supported region0. The region length precedes the packed members.
	b := []byte{1, 0, 0, 0, 2, 2, 0, 0, 0, 1, 5, 1, '0'}
	for _, id := range []byte{1, 3} {
		b = append(b, 1, 1, id, 2, 4, 0, 0, 0, 3, 3, 1, id, 4, 3, '0', ' ', '3')
		ch := []byte("36-48 0 default:36 equal")
		b = append(b, 5, byte(len(ch)))
		b = append(b, ch...)
	}
	return b, control
}
func TestRadioLinkagePackedMatrixAndMalformedAtomicity(t *testing.T) {
	table, control := linkageTableFixture()
	p, err := ParseRadioLinkage(table, control)
	if err != nil || p.TableID != 1 || len(p.Rows) != 1 || p.Rows[0].TableMask != 2 || len(p.Rows[0].Radios) != 2 {
		t.Fatal(p, err)
	}
	m := p.Rows[0].Radios[1]
	if m.Radio != 3 || m.BindID != 3 || m.StatusMask != 3 || !m.EqualChannel || len(m.Channels) != 14 || m.DefaultChannel == nil || *m.DefaultChannel != 36 || len(m.Bandwidths) != 2 {
		t.Fatal(m)
	}
	for i := 0; i < len(table); i++ {
		if _, err := ParseRadioLinkage(table[:i], control); err == nil {
			t.Fatalf("truncated RRST accepted %d", i)
		}
	}
	ap := &APEntry{linkageTable: table, linkageControl: control}
	refreshRadioLinkage(ap)
	old := ap.RadioLinkage
	ap.linkageTable = table[:len(table)-1]
	refreshRadioLinkage(ap)
	if ap.RadioLinkage != old {
		t.Fatal("invalid matrix replaced known capabilities")
	}
	bad := append([]byte{}, control...)
	binary.BigEndian.PutUint16(bad[2:], 65535)
	if _, err := ParseRadioLinkage(table, bad); err == nil {
		t.Fatal("truncated control accepted")
	}
}
