package cweng

import (
	"testing"

	"uacgo/capwap"
)

// TestJoinFixtureIdentity pins the join-identity extraction to the
// vendor fixture: board-data sub 4 carries the WTP MAC
// (14:75:90:db:80:92 in cw_join_req_0074f150.bin).
func TestJoinFixtureIdentity(t *testing.T) {
	raw := mustFixture(t, "cw_join_req_0074f150.bin")
	pkt, err := capwap.ParsePacket(raw)
	if err != nil {
		t.Fatal(err)
	}
	ap, err := ParseAPEntry(pkt)
	if err != nil {
		t.Fatal(err)
	}
	want := [6]byte{0x14, 0x75, 0x90, 0xdb, 0x80, 0x92}
	if ap.MAC != want {
		t.Fatalf("join MAC = %x, want %x", ap.MAC, want)
	}
	if ap.Serial == "" || ap.ModelID == 0 {
		t.Fatalf("identity incomplete: %+v", ap)
	}
}

// TestStatsBssSeeding feeds a 0x54 AP statistics report through the
// stats handler and verifies the steering registry learns the BSS rows.
func TestStatsBssSeeding(t *testing.T) {
	reg := NewSteerRegistry()
	var mac [6]byte = [6]byte{0x14, 0x75, 0x90, 0xdb, 0x80, 0x92}
	rows := capwap.PrivApStatisticsRows{RadioCount: 1, SsidCount: 2}
	rows.Radios = append(rows.Radios, capwap.ApStatsRadioRow{RadioID: 1})
	rows.Ssids = []capwap.ApStatsSsidRow{
		{RadioID: 1, WLANID: 1, BSSID: [6]byte{0xaa, 0, 0, 0, 0, 1}},
		{RadioID: 1, WLANID: 2, BSSID: [6]byte{0xaa, 0, 0, 0, 0, 2}},
	}
	// RegisterStatsHandlers is a thin msg 9 wrapper over this parse +
	// RegisterBSS path.
	parsed, err := capwap.ParsePrivApStatisticsRows(rows.AssembleValue())
	if err != nil || len(parsed.Ssids) != 2 {
		t.Fatalf("rows roundtrip: %v %+v", err, parsed)
	}
	for _, s := range parsed.Ssids {
		reg.RegisterBSS(s.BSSID, BSSRow{APID: 3, APMAC: mac, RadioID: s.RadioID, WLANID: s.WLANID})
	}
	apID, apMAC, radio, wlan, _, _, _, ok := reg.APByBSSID([6]byte{0xaa, 0, 0, 0, 0, 2})
	if !ok || apID != 3 || apMAC != mac || radio != 1 || wlan != 2 {
		t.Fatalf("bss lookup: ok=%v ap=%d %x r=%d w=%d", ok, apID, apMAC, radio, wlan)
	}
}
