package cweng

import (
	"encoding/binary"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestMeshPairTemporaryAdmissionPrecedesPermission(t *testing.T) {
	e, s, sent := requestTestSession(t)
	s.apEntry = &APEntry{MAC: "02:00:00:00:00:01", GeneralCapabilities: []uint32{0, 1 << 12}}
	permit := true
	e.RegisterMeshControl(nil, func(ap string, c time.Time, mac string, k uint8) bool {
		return permit && ap == s.apEntry.MAC && c == s.Created && mac == "02:00:00:00:00:02" && k == 1
	})
	req, _ := capwap.NewParsedPacket(9)
	req.Elements = []capwap.Element{meshControlElement([]capwap.VendorRecord{{Type: 12, Value: []byte{2, 0, 0, 0, 0, 2, 1}}})}
	for _, allow := range []bool{true, false} {
		permit = allow
		rsp, _ := capwap.NewParsedPacket(10)
		e.reg.handleMsg(&Ctx{Session: s}, 9, req, rsp)
		if allow {
			p := <-sent
			if p.Control.MsgType != 7 {
				t.Fatal(p)
			}
			rows, err := capwap.ParseVendorList(p.Elements[0].Value[10:])
			if err != nil || len(rows) != 1 || rows[0].Type != 20 || len(rows[0].Value) != 12 || binary.BigEndian.Uint16(rows[0].Value) != 1 || binary.BigEndian.Uint32(rows[0].Value[8:]) != 60 {
				t.Fatal(rows, err)
			}
		} else {
			select {
			case <-sent:
				t.Fatal("denied candidate received temporary grant")
			default:
			}
		}
		rows, err := capwap.ParseVendorList(rsp.Elements[0].Value[10:])
		if err != nil || len(rows) != 1 || rows[0].Type != 13 || len(rows[0].Value) != 10 || (binary.BigEndian.Uint32(rows[0].Value[6:]) == 0) != allow {
			t.Fatal(rows, err)
		}
	}
	// A concurrent tracked request cannot be displaced by unsolicited admission.
	permit = true
	s.pending = map[uint8]*pendingCommand{1: {}}
	rsp, _ := capwap.NewParsedPacket(10)
	e.reg.handleMsg(&Ctx{Session: s}, 9, req, rsp)
	rows, _ := capwap.ParseVendorList(rsp.Elements[0].Value[10:])
	if binary.BigEndian.Uint32(rows[0].Value[6:]) != 1 {
		t.Fatal("pending configuration displaced")
	}
	delete(s.pending, 1)
}
