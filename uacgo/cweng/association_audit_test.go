package cweng

import (
	"encoding/hex"
	"net"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestAdmissionRuleCoversBothV6AssociationFamilies(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	clients := NewClientTable()
	e.RegisterWstaHandlers(clients)
	e.AdmitStation = func(_ string, radio, wlan uint8) bool { return radio == 2 && wlan == 1 }
	s := newSession(&net.UDPAddr{}, e.acData)
	s.apEntry = &APEntry{RadioCount: 2}
	for _, row := range []struct {
		typ, reply uint16
		wire       string
	}{
		{2, 4, "0201020304050607ffffffec00000002aabb"},
		{0x8a, 0x8b, "020102030405060700000001010000000600000002aabb"},
	} {
		for _, allowed := range []bool{true, false} {
			wire, _ := hex.DecodeString(row.wire)
			if !allowed {
				wire[1] = 2
			}
			req, _ := capwap.NewParsedPacket(9)
			rsp, _ := capwap.NewParsedPacket(10)
			req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, row.typ, []capwap.PrivElementValue{{Type: row.typ, Value: wire}})}}
			e.reg.handleMsg(&Ctx{Session: s}, 9, req, rsp)
			found := false
			privateElements(rsp, func(typ uint16, b []byte) {
				if typ == row.reply {
					found = true
					if (capwap.Uint32BE(b[8:]) == 0) != allowed {
						t.Errorf("type %x allowed=%v reply=%x", row.typ, allowed, b)
					}
				}
			})
			if !found {
				t.Fatalf("missing response to type %x", row.typ)
			}
		}
	}
}

func TestFirmwareAssociationMovesClientAndStatisticsCannotMoveItBack(t *testing.T) {
	table := NewClientTable()
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	now := time.Now()
	old := ClientEvent{Kind: "associate", State: "connected", MAC: mac, APID: "a", RadioID: 1, WLANID: 1, IP: "192.0.2.2", Seen: now}
	table.StationEvent(old)
	next := ClientEvent{Kind: "associate", MAC: mac, APID: "b", RadioID: 2, WLANID: 1, Seen: now.Add(time.Second)}
	table.StationEvent(next)
	if v := table.All()[0]; v.APID != "b" || v.State != "connected" {
		t.Fatal("successful V6 association did not update location", v)
	}
	next.Kind = "statistics"
	next.Statistics = &ClientStatistics{NegotiatedMbps: 1201}
	next.Seen = now.Add(121 * time.Second)
	table.StationEvent(next)
	old.Kind = "disassociate"
	old.State = "disconnected"
	old.Seen = next.Seen.Add(time.Second)
	table.StationEvent(old)
	old.Kind = "statistics"
	old.Statistics = &ClientStatistics{NegotiatedMbps: 54}
	table.StationEvent(old)
	if v := table.All()[0]; v.APID != "b" || v.State != "connected" {
		t.Fatal("old AP report moved client back", v)
	}
}

func TestDisconnectedClientNotResurrectedByLateReports(t *testing.T) {
	table := NewClientTable()
	mac := [6]byte{2, 3, 4, 5, 6, 7}
	ev := ClientEvent{Kind: "associate", State: "connected", MAC: mac, APID: "a", RadioID: 1, WLANID: 1}
	table.StationEvent(ev)
	ev.Kind = "disassociate"
	ev.State = "disconnected"
	table.StationEvent(ev)
	ev.Kind = "statistics"
	ev.Statistics = &ClientStatistics{NegotiatedMbps: 1201}
	table.StationEvent(ev)
	ev.Kind = "ip"
	ev.IP = "192.0.2.3"
	table.StationEvent(ev)
	if v := table.All()[0]; v.State != "disconnected" {
		t.Fatal(v)
	}
	ev.Kind = "associate"
	ev.State = "associating"
	ev.IP = ""
	ev.Statistics = nil
	table.StationEvent(ev)
	if v := table.All()[0]; v.IP != "" || v.Statistics != nil {
		t.Fatal("new connection inherited old DHCP/traffic", v)
	}
}
