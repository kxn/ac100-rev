package admin

import (
	"bytes"
	"context"
	"encoding/binary"
	"encoding/hex"
	"fmt"
	"testing"
	"uacgo/cweng"
)

func TestDefenseGoldenMixedAddressesAndRuleRemoval(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{1<<15 | 1<<16 | 1<<30 | 1<<31}
	ap.SubCapabilities = map[uint16]uint32{16: 1}
	p := ProtectionConfig{Servers: []DHCPTrustedServer{{"ip", "Router", "192.0.2.1"}, {"mac", "Other", "02:03:04:05:06:07"}, {"v6", "IPv6", "2001:db8::1"}}, Bindings: []ARPBinding{{"a", "Laptop", "192.0.2.20", "02:03:04:05:06:07", ""}, {"b", "Laptop v6", "2001:db8::20", "02:03:04:05:06:07", ""}}, Rules: []ProtectionRule{{ID: "r", Name: "Office", DHCP: true, Servers: []string{"ip", "mac", "v6"}, ARP: true, Bindings: []string{"a", "b"}, Filter: true, Wired: true, Wireless: true}}}
	if err := validateProtection(&p, Config{}); err != nil {
		t.Fatal(err)
	}
	m.applyProtection(context.Background(), ap, Config{Protection: &p})
	want := map[uint16]string{0x47: "01010000000200c0000201000001020304050607", 0x61: "01010000000201020304050607000000000000000000000020010db8000000000000000000000001", 0x48: "350100000001c0000214020304050607", 0x62: "35010000000120010db8000000000000000000000020020304050607"}
	f.mu.Lock()
	for _, packet := range f.packets {
		for _, el := range packet.Elements {
			v := el.Value
			if el.Type != 0x25 {
				continue
			}
			typ := binary.BigEndian.Uint16(v[6:])
			if hex.EncodeToString(v[10:]) != want[typ] {
				f.mu.Unlock()
				t.Fatalf("defense 0x%x got %x want %s", typ, v[10:], want[typ])
			}
		}
	}
	if len(f.packets) != 4 {
		f.mu.Unlock()
		t.Fatal("missing IPv4/IPv6 defense")
	}
	f.mu.Unlock()
	m.applyProtection(context.Background(), ap, Config{})
	f.mu.Lock()
	defer f.mu.Unlock()
	if len(f.packets) != 8 {
		t.Fatal("removed protection not cleared")
	}
	for _, p := range f.packets[4:] {
		if !bytes.Equal(p.Elements[0].Value[10:], []byte{0, 1, 0, 0, 0, 0}) {
			t.Fatal("stale AP address bindings", p)
		}
	}
}
func TestLegacyDefenseUsesBooleanNotExtendedFlags(t *testing.T) {
	p := ProtectionConfig{Bindings: []ARPBinding{{ID: "v4", IP: "192.0.2.20", MAC: "02:03:04:05:06:07"}, {ID: "v6", IP: "2001:db8::20", MAC: "02:03:04:05:06:07"}}}
	r := ProtectionRule{ARP: true, Filter: true, Wireless: true, Bindings: []string{"v4", "v6"}}
	a := cweng.APStatus{GeneralCapabilities: []uint32{1<<16 | 1<<31}}
	for _, extended := range []bool{false, true} {
		if extended {
			a.SubCapabilities = map[uint16]uint32{16: 1}
		}
		els := protectionElements(&p, r, a)
		if len(els) != 2 {
			t.Fatal("missing ARP/ND", els)
		}
		want := byte(1)
		if extended {
			want = 0x25
		}
		for _, el := range els {
			if el.Value[10] != want {
				t.Fatalf("extended=%v: flags=%x", extended, el.Value[10])
			}
		}
	}
}
func TestDefenseRejectsInvalidAndDuplicateReferences(t *testing.T) {
	cases := []ProtectionConfig{
		{Servers: []DHCPTrustedServer{{"a", "A", "239.0.0.1"}}},
		{Servers: []DHCPTrustedServer{{"a", "A", "01:00:5e:00:00:01"}}},
		{Servers: []DHCPTrustedServer{{"a", "A", "::"}}},
		{Servers: []DHCPTrustedServer{{"a", "A", "192.0.2.1"}, {"b", "B", "192.0.2.1"}}},
		{Rules: []ProtectionRule{{ID: "r", Name: "r", Servers: []string{"missing"}}}},
		{Bindings: []ARPBinding{{"b", "b", "192.0.2.1", "192.0.2.2", ""}}},
	}
	for _, p := range cases {
		if validateProtection(&p, Config{}) == nil {
			t.Fatal("invalid protection accepted", p)
		}
	}
}

func TestProtectionKeepsLibraryAndPerDeviceCapacityDistinct(t *testing.T) {
	ap := cweng.APStatus{ID: "lab", Model: "TL-7AP5100HC-PoE/DC易展版", HardwareVersion: "1.0", GeneralCapabilities: []uint32{1<<16 | 1<<31}}
	p := ProtectionConfig{}
	r := ProtectionRule{}
	for i := 0; i < 49; i++ {
		id := fmt.Sprint(i)
		p.Bindings = append(p.Bindings, ARPBinding{ID: id, Name: id, IP: fmt.Sprintf("192.0.2.%d", i+1), MAC: "02:03:04:05:06:07"})
		r.Bindings = append(r.Bindings, id)
	}
	if validateProtection(&p, Config{}) != nil {
		t.Fatal("shared library incorrectly limited to one AP's capacity")
	}
	if validateProtectionForAP(&p, r, ap) == nil {
		t.Fatal("oversized native ARP table accepted even when disabled")
	}
	r.Bindings = r.Bindings[:48]
	if err := validateProtectionForAP(&p, r, ap); err != nil {
		t.Fatal(err)
	}
	for i := 0; i < 25; i++ {
		p.Bindings[i].IP = fmt.Sprintf("2001:db8::%x", i+1)
	}
	if validateProtectionForAP(&p, r, ap) == nil {
		t.Fatal("oversized native ND table accepted")
	}
	other := p.Bindings[30]
	other.ID = "different-network"
	other.Name = "different-network"
	other.MAC = "02:03:04:05:06:08"
	p.Bindings = append(p.Bindings, other)
	if err := validateProtection(&p, Config{}); err != nil {
		t.Fatal("same IP with distinct MAC on another network rejected", err)
	}
	p.Bindings[len(p.Bindings)-1].MAC = "02:03:04:05:06:07"
	if validateProtection(&p, Config{}) == nil {
		t.Fatal("duplicate IP/MAC pair accepted")
	}
}
func TestStormProxyAndProtocolCapabilities(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{1 << 14}
	ap.SubCapabilities = map[uint16]uint32{14: 15}
	s := defaultStorm()
	s.Enabled = true
	s.Custom = true
	s.Rate = 100
	s.ARP.Enabled = true
	s.ARP.Scope = 1
	s.ARP.ToUnicast = true
	s.ND.Enabled = true
	s.ND.Scope = 2
	s.MDNS.Enabled = true
	s.MDNS.ToUnicast = true
	s.Protocols[0] = ProtocolLimit{Enabled: true, Scope: 1, Rate: 200}
	if err := validateStorm(&s); err != nil {
		t.Fatal(err)
	}
	m.applyStorm(context.Background(), ap, Config{Storm: &s})
	f.mu.Lock()
	defer f.mu.Unlock()
	if len(f.packets) != 3 {
		t.Fatal("missing proxy/rate update")
	}
	raw := f.packets[0].Elements[0].Value[10:]
	if !bytes.Equal(raw, []byte{1, 0, 0, 0, 100}) {
		t.Fatal("storm rate", raw)
	}
	raw = f.packets[1].Elements[0].Value[10:]
	if !bytes.Equal(raw, []byte{3, 0x67, 0, 0}) {
		t.Fatalf("proxy flags %x", raw)
	}
	raw = f.packets[2].Elements[0].Value[10:]
	if len(raw) != 68 || !bytes.Equal(raw[:12], []byte{0, 0, 0, 8, 0, 0, 1, 1, 0, 0, 0, 200}) {
		t.Fatalf("protocol restrictions %x", raw)
	}
	ap.SubCapabilities = nil
	if len(stormElements(s, ap)) != 1 {
		t.Fatal("unsupported extensions sent")
	}
}
func TestAPMeshBluetoothAndUSBOptions(t *testing.T) {
	b := true
	mode := 2
	ap := cweng.APStatus{GeneralCapabilities: []uint32{0, 1 << 12, 1<<13 | 1<<15, 1 << 4}, SubCapabilities: map[uint16]uint32{77: 1}}
	o := APOptions{Mesh: &b, USB: &b, Bluetooth: &mode}
	els, err := managementElements(o, ap)
	if err != nil {
		t.Fatal(err)
	}
	want := map[uint16][]byte{0x76: {0, 1, 0, 0x15, 0, 2, 0, 1}, 0xd7: {0, 1, 0, 2, 0, 1, 1}, 0xa7: {1, 0, 0, 0, 1, 255, 255, 255, 255}}
	for _, el := range els {
		v := el.Value
		typ := binary.BigEndian.Uint16(v[6:])
		if !bytes.Equal(v[10:], want[typ]) {
			t.Fatalf("extension 0x%x %x", typ, v[10:])
		}
	}
	if _, err = managementElements(o, cweng.APStatus{}); err == nil {
		t.Fatal("capability-less AP accepted")
	}
}
