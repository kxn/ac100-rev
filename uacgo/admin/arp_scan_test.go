package admin

import (
	"net/http/httptest"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestARPScanNeedsSubCapabilityAndAcceptsUDPReport(t *testing.T) {
	m, e := testController(t)
	e.RegisterObservationHandlers()
	f, ap := newDeferredAP(t, e)
	// The fixture AP has no scan sub-capability, even if ARP defense is present.
	r := httptest.NewRecorder()
	m.Handler().ServeHTTP(r, httptest.NewRequest("POST", "http://localhost/api/aps/"+ap.ID+"/arp-scan", nil))
	if r.Code != 409 {
		t.Fatal("general capability falsely implied scan support", r.Code)
	}
	packet, _ := capwap.NewParsedPacket(9)
	packet.Control.SeqNum = 61
	packet.Elements = []capwap.Element{privateSetting(0xca, []byte{1, 0, 1, 192, 0, 2, 10, 2, 1, 2, 3, 4, 5})}
	if _, err := f.conn.Write(packet.Assemble()); err != nil {
		t.Fatal(err)
	}
	until := time.Now().Add(time.Second)
	for {
		for _, a := range e.APs() {
			if a.ID == ap.ID && a.ARPScan != nil {
				if len(a.ARPScan.Entries) != 1 || a.ARPScan.Entries[0].IP != "192.0.2.10" {
					t.Fatal(a.ARPScan)
				}
				return
			}
		}
		if time.Now().After(until) {
			t.Fatal("scan result never reached API model")
		}
		time.Sleep(time.Millisecond)
	}
}
