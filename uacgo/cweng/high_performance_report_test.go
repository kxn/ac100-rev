package cweng

import (
	"net"
	"testing"
	"time"
	"uacgo/capwap"
)

func TestV4ChannelScanListenerConsumesFirstEventElement(t *testing.T) {
	e, err := NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	e.RegisterObservationHandlers()
	s := newSession(&net.UDPAddr{}, e.acData)
	got := []uint8{}
	e.OnChannelScan = func(_ string, epoch time.Time, rows []capwap.ChannelScanSample) {
		if epoch != s.Created {
			t.Fatal("lost report session identity")
		}
		got = append(got, rows[0].Channel)
	}
	for _, kind := range []uint32{5, 8, 9} {
		req, _ := capwap.NewParsedPacket(kind)
		rsp, _ := capwap.NewParsedPacket(kind + 1)
		req.Elements = []capwap.Element{{Type: 0x25, Value: capwap.VendorEnvelopeValue(0, 0, []capwap.PrivElementValue{{Type: 0x9c, Value: []byte{1, 6, 1, 20, 0, 0, 0, 0, 0, 0}}, {Type: 0x9c, Value: []byte{1, 11, 2, 30, 0, 0, 0, 0, 0, 0}}})}}
		e.reg.handleMsg(&Ctx{Session: s}, kind, req, rsp)
	}
	if len(got) != 1 || got[0] != 6 {
		t.Fatal("scan input expanded beyond the original type9/first9c listener", got)
	}
}
