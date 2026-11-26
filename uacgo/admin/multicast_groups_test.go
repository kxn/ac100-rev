package admin

import (
	"bytes"
	"context"
	"testing"
)

func TestMulticastListWireAndRemovalThroughUDP(t *testing.T) {
	rows := []MulticastGroup{{IP: "239.1.2.3", Enabled: true, Relay: true}, {IP: "ff02::1", Enabled: true}, {IP: "239.1.1.1"}}
	if err := validateMulticastGroups(rows); err != nil {
		t.Fatal(err)
	}
	want := []byte{0, 0, 0, 2, 1, 1, 239, 1, 2, 3, 0, 2, 255, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
	if got := multicastGroupValue(rows); !bytes.Equal(got, want) {
		t.Fatalf("list %x", got)
	}
	if validateMulticastGroups([]MulticastGroup{{IP: "192.0.2.1"}}) == nil {
		t.Fatal("unicast accepted")
	}
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{0, 1 << 11}
	m.applyMulticastGroups(context.Background(), ap, Config{MulticastGroups: rows})
	m.applyMulticastGroups(context.Background(), ap, Config{})
	f.mu.Lock()
	defer f.mu.Unlock()
	last := f.packets[len(f.packets)-1].Elements[0]
	if !bytes.Equal(last.Value[10:], []byte{0, 0, 0, 0}) {
		t.Fatal("empty group list was not sent to clear AP")
	}
}
