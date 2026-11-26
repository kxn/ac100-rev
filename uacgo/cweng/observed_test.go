package cweng

import (
	"encoding/hex"
	"net"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/internal/legacydtls"
)

func TestDTLSModeRejectsPlainJoin(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.legacyDTLS = &legacydtls.Server{}
	e.RegisterAttachHandlers(fixtureIdentity{})
	e.handleDatagram(withSeq(t, "cw_join_req_0074f150.bin", 2), &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 12000})
	if len(e.APs()) != 0 {
		t.Fatal("plaintext join bypassed DTLS")
	}
	if err := e.sendTo(&net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 12000}, synthMsg(t, 7, 1)); err == nil {
		t.Fatal("command fell back to plaintext without an authenticated session")
	}
}

func TestRadioObservationFromVendorEvent(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.RegisterObservationHandlers()
	s := newSession(&net.UDPAddr{}, e.acData)
	// Independent decrypted V6 frame 124: radio 2, mode 13, ch40, power27.
	b, _ := hex.DecodeString("12345678000000250005020d28001b")
	req, _ := capwap.NewParsedPacket(9)
	rsp, _ := capwap.NewParsedPacket(10)
	req.Elements = []capwap.Element{{Type: 0x25, Value: b}}
	e.reg.handleMsg(&Ctx{Session: s}, 9, req, rsp)
	r := s.radioStatus[2]
	if r.Channel != 40 || r.Mode != 13 || r.Power != 27 || r.Seen.IsZero() {
		t.Fatalf("observation %+v", r)
	}
}

func TestClientRoamIgnoresOldAPDisconnect(t *testing.T) {
	table := NewClientTable()
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	table.StationEvent(ClientEvent{Kind: "associate", State: "connected", MAC: mac, APID: "ap-a", RadioID: 1, WLANID: 1})
	table.StationEvent(ClientEvent{Kind: "associate", State: "connected", MAC: mac, APID: "ap-b", RadioID: 2, WLANID: 1})
	table.StationEvent(ClientEvent{Kind: "disassociate", State: "disconnected", MAC: mac, APID: "ap-a", RadioID: 1, WLANID: 1})
	v := table.All()[0]
	if v.APID != "ap-b" || v.State != "connected" {
		t.Fatalf("stale disconnect replaced new association %+v", v)
	}
	rssi := int8(-57)
	table.StationEvent(ClientEvent{Kind: "statistics", MAC: mac, APID: "ap-b", RadioID: 2, WLANID: 1, RSSI: &rssi, Seen: time.Now()})
	v = table.All()[0]
	if v.State != "connected" || v.RSSI == nil || *v.RSSI != -57 {
		t.Fatalf("statistics erased association %+v", v)
	}
	table.StationEvent(ClientEvent{Kind: "disassociate", State: "disconnected", MAC: mac, APID: "ap-b", RadioID: 2, WLANID: 1})
	if table.All()[0].State != "disconnected" {
		t.Fatal("disconnect not reflected")
	}
}

func TestNewStationAssociationResponse(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	table := NewClientTable()
	e.RegisterWstaHandlers(table)
	s := newSession(&net.UDPAddr{}, e.acData)
	// 0x8a literal, radio2/WLAN1, metadata1, phase1, sub0 backfill aabb.
	b, _ := hex.DecodeString("020102030405060700000001010000000600000002aabb")
	req, _ := capwap.NewParsedPacket(9)
	rsp, _ := capwap.NewParsedPacket(10)
	req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0, []capwap.PrivElementValue{{Type: 0x8a, Value: b}})}}
	e.reg.handleMsg(&Ctx{Session: s}, 9, req, rsp)
	var got []byte
	privateElements(rsp, func(typ uint16, b []byte) {
		if typ == 0x8b {
			got = b
		}
	})
	// Response copies radio/WLAN/MAC/phase, result0, maps request sub0 to result sub1.
	want, _ := hex.DecodeString("020102030405060700000000010000000600010002aabb")
	if string(got) != string(want) {
		t.Fatalf("response %x want %x", got, want)
	}
	rows := table.All()
	if len(rows) != 1 || rows[0].WLANID != 1 || rows[0].State != "connected" {
		t.Fatalf("station state %+v", rows)
	}
}

func TestLegacyAssociationPermitEchoesPhysicalBackfill(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	table := NewClientTable()
	e.RegisterWstaHandlers(table)
	s := newSession(&net.UDPAddr{}, e.acData)
	b, _ := hex.DecodeString("0201020304050607ffffffec000000020000")
	req, _ := capwap.NewParsedPacket(9)
	rsp, _ := capwap.NewParsedPacket(10)
	req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 2, []capwap.PrivElementValue{{Type: 2, Value: b}})}}
	e.reg.handleMsg(&Ctx{Session: s}, 9, req, rsp)
	var result []byte
	privateElements(rsp, func(typ uint16, b []byte) {
		if typ == 4 {
			result = b
		}
	})
	want, _ := hex.DecodeString("020102030405060700000000000000020000")
	if hex.EncodeToString(result) != hex.EncodeToString(want) {
		t.Fatalf("missing permit %x", result)
	}
	if v := table.All(); len(v) != 1 || v[0].State != "associating" || v[0].RSSI == nil || *v[0].RSSI != -20 {
		t.Fatal(v)
	}
}

func TestClientConfirmedByAPAddressAndStatisticsReports(t *testing.T) {
	for _, kind := range []string{"ip", "statistics"} {
		table := NewClientTable()
		mac := [6]byte{2, 3, 4, 5, 6, 7}
		table.StationEvent(ClientEvent{Kind: "associate", State: "associating", MAC: mac, APID: "ap", RadioID: 2, WLANID: 1})
		ev := ClientEvent{Kind: kind, MAC: mac, APID: "ap", RadioID: 2, WLANID: 1, IP: "192.0.2.2"}
		if kind == "statistics" {
			ev.Statistics = &ClientStatistics{NegotiatedMbps: 1201}
		}
		table.StationEvent(ev)
		if table.All()[0].State != "connected" {
			t.Fatalf("AP %s report did not confirm connection", kind)
		}
	}
}

func TestClientIPv6ReportPreservesIPv4(t *testing.T) {
	table := NewClientTable()
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	table.StationEvent(ClientEvent{Kind: "associate", State: "associating", APID: "ap", RadioID: 1, WLANID: 1, MAC: mac})
	for _, ip := range []string{"192.0.2.2", "fe80::1234", "2001:db8::1", "fe80::1234"} {
		table.StationEvent(ClientEvent{Kind: "ip", APID: "ap", MAC: mac, IP: ip})
	}
	v := table.All()[0]
	if v.IP != "192.0.2.2" || len(v.IPv6) != 2 || v.State != "connected" {
		t.Fatal(v)
	}
	v.IPv6[0] = "modified"
	if table.All()[0].IPv6[0] == "modified" {
		t.Fatal("snapshot exposes mutable address list")
	}
}

func TestExistingClientReportsAfterControllerRestart(t *testing.T) {
	table := NewClientTable()
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	table.StationEvent(ClientEvent{Kind: "ip", APID: "ap", MAC: mac, IP: "192.0.2.2"})
	table.StationEvent(ClientEvent{Kind: "statistics", APID: "ap", MAC: mac, RadioID: 2, WLANID: 1, Statistics: &ClientStatistics{NegotiatedMbps: 1201}})
	v := table.All()[0]
	if v.State != "connected" || v.RadioID != 2 || v.IP != "192.0.2.2" || v.Statistics == nil {
		t.Fatal(v)
	}
}
