package capwap

import (
	"bytes"
	"testing"
)

// Batch-8 standard variable-length elements: roundtrips with the vendor
// validation rules (mac len 6|8, exact consumption, radio id < 0x20).
func TestBatch8Roundtrips(t *testing.T) {
	mac6 := []byte{1, 2, 3, 4, 5, 6}

	// mac acl add/del
	e := AppendAddMACACLEntry(nil, mac6)
	if v, err := ParseMACACLEntry(e[4:]); err != nil || !bytes.Equal(v.MAC, mac6) {
		t.Fatalf("acl add: %v", err)
	}
	if _, err := ParseMACACLEntry(e[:4]); err == nil {
		t.Fatal("short acl must fail")
	}
	e = AppendDeleteMACACLEntry(nil, mac6)
	if v, err := ParseMACACLEntry(e[4:]); err != nil || v.Flag != 0 {
		t.Fatalf("acl del: %v", err)
	}

	// add station with optional vlan
	as := AddStation{RadioID: 1, MAC: mac6, HasVLAN: true, VLAN: 100}
	b := as.AssembleValue()
	if v, err := ParseAddStation(b); err != nil || !v.HasVLAN || v.VLAN != 100 {
		t.Fatalf("add station: %v %+v", err, v)
	}
	as2 := AddStation{RadioID: 2, MAC: mac6}
	if v, err := ParseAddStation(as2.AssembleValue()); err != nil || v.HasVLAN {
		t.Fatalf("add station no-vlan: %v", err)
	}
	if _, err := ParseAddStation([]byte{0x20, 6}); err == nil {
		t.Fatal("radio >= 0x20 must fail")
	}

	// delete station: exact length rule
	ds := DeleteStation{RadioID: 1, MAC: mac6}
	if v, err := ParseDeleteStation(ds.AssembleValue()); err != nil || len(v.MAC) != 6 {
		t.Fatalf("delete station: %v", err)
	}
	if _, err := ParseDeleteStation([]byte{1, 6, 1, 2}); err == nil {
		t.Fatal("delete station mismatched length must fail")
	}

	// decryption error report: two entries
	der := DecryptionErrorReport{RadioID: 1, Entries: []DecryptErrEntry{
		{BSSIDIdx: 0, Count: 10}, {BSSIDIdx: 1, Count: 20}}}
	if v, err := ParseDecryptionErrorReport(der.AssembleValue()); err != nil ||
		len(v.Entries) != 2 || v.Entries[1].Count != 20 {
		t.Fatalf("decrypt err report: %v", err)
	}

	// data transfer data/mode
	dt := DataTransferData{Type: 1, Flags: 2, Data: []byte("blob")}
	if v, err := ParseDataTransferData(dt.AssembleValue()); err != nil || !bytes.Equal(v.Data, []byte("blob")) {
		t.Fatalf("data transfer data: %v", err)
	}
	dtm := AppendDataTransferMode(nil, 3)
	if v, err := ParseDataTransferMode(dtm[4:]); err != nil || v != 3 {
		t.Fatalf("data transfer mode: %v", err)
	}

	// returned message element + static ip
	rme := AppendReturnedMessageElement(nil, 0x1234, 7)
	if t2, res, err := ParseReturnedMessageElement(rme[4:]); err != nil ||
		t2 != 0x1234 || res != 7 {
		t.Fatalf("returned element: %v", err)
	}

	// initiate download: empty element
	if e := AppendInitiateDownload(nil); len(e) != 4 || e[2] != 0 || e[3] != 0 {
		t.Fatalf("initiate download element = %x", e)
	}
}
