package cweng

import (
	"encoding/binary"
	"testing"
	"uacgo/capwap"
)

func meshTestNode(mac byte) []byte {
	b := make([]byte, 38)
	copy(b, []byte{2, 0, 0, 0, 0, mac})
	copy(b[6:], []byte{192, 0, 2, mac})
	b[26] = 1
	b[27] = 2
	binary.BigEndian.PutUint32(b[28:], 866)
	copy(b[32:], []byte{2, 0, 0, 0, 0, 1})
	return b
}
func TestMeshPackedDiscoveryAndTopology(t *testing.T) {
	d := make([]byte, 83)
	binary.BigEndian.PutUint16(d, 1)
	copy(d[2:], []byte{2, 0, 0, 0, 0, 1})
	d[8] = 2
	d[9] = 206
	copy(d[10:], []byte{2, 0, 0, 0, 0, 2})
	copy(d[16:], "Mesh AP")
	d[81] = 4
	full := append([]byte{0, 1}, meshTestNode(2)...)
	r, err := updateMeshReport(nil, capwap.AssembleVendorList([]capwap.VendorRecord{{Type: 1, Value: d}, {Type: 6, Value: full}}))
	if err != nil || len(r.Nodes) != 1 || r.Nodes[0].IPv4 != "192.0.2.2" || r.Nodes[0].Rate != 866 || !r.Nodes[0].Wireless || len(r.Discoveries) != 1 || r.Discoveries[0].MAC != "02:00:00:00:00:02" || r.Discoveries[0].RSSI != -50 || r.Discoveries[0].Model != "Mesh AP" || r.Discoveries[0].Hardware != "4.0" {
		t.Fatal(r, err)
	}
	next, err := updateMeshReport(r, capwap.AssembleVendorList([]capwap.VendorRecord{{Type: 7, Value: append([]byte{0, 0, 1}, meshTestNode(3)...)}}))
	if err != nil || len(next.Nodes) != 2 || len(r.Nodes) != 1 {
		t.Fatal(next, r, err)
	}
	next, err = updateMeshReport(next, capwap.AssembleVendorList([]capwap.VendorRecord{{Type: 7, Value: append([]byte{1, 0, 1}, meshTestNode(2)...)}}))
	if err != nil || len(next.Nodes) != 1 || next.Nodes[0].MAC != "02:00:00:00:00:03" {
		t.Fatal(next, err)
	}
	if _, err = updateMeshReport(next, capwap.AssembleVendorList([]capwap.VendorRecord{{Type: 6, Value: full[:len(full)-1]}})); err == nil {
		t.Fatal("truncated topology accepted")
	}
	if len(next.Nodes) != 1 {
		t.Fatal("bad report modified state")
	}
}
