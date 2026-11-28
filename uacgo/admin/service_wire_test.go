package admin

import (
	"bytes"
	"encoding/binary"
	"encoding/hex"
	"testing"
	"uacgo/cweng"
)

func TestWirelessServiceSelectsLegacy9New63AndEnable94(t *testing.T) {
	s := Service{WLAN: 2, SSID: "Office", Security: "wpa2-psk", Passphrase: "password1", Enabled: true, Radios: []uint8{1}}
	for _, tc := range []struct {
		bits   uint32
		typ    uint16
		header string
	}{
		{0, 9, "010200000064030001"},
		{1, 0x63, "010200000064030001"},
		{1 << 31, 0x94, "010200000064030000000101"},
	} {
		ap := cweng.APStatus{GeneralCapabilities: []uint32{0, tc.bits}}
		e := advancedWLANElements(s, 1, ap)[1]
		want, _ := hex.DecodeString(tc.header + "020200015180000970617373776f726431")
		if binary.BigEndian.Uint16(e.Value[6:]) != tc.typ || !bytes.Equal(e.Value[10:], want) {
			t.Fatalf("capability selected wrong service format: %x / %x", e.Value, want)
		}
	}
}

func TestWPA3MixedFallsBackPerRadioAsOriginalWithoutBlockingWLAN(t *testing.T) {
	s := Service{WLAN: 1, SSID: "Office", Security: "wpa2-wpa3-psk", Passphrase: "password1", Enabled: true, Radios: []uint8{1, 2}}
	ap := cweng.APStatus{GeneralCapabilities: []uint32{0, 1}, Capabilities: []cweng.RadioCapability{{RadioID: 1, SupportWPA3: true}, {RadioID: 2}}}
	for _, radio := range []uint8{1, 2} {
		if err := validateServiceCapability(s, ap, radio); err != nil {
			t.Fatal("mixed service was blocked on legacy hardware", err)
		}
		v := advancedWLANElements(s, radio, ap)[1].Value[10:]
		mode := byte(4)
		if radio == 2 {
			mode = 1
		}
		if v[8] != mode || v[9] != 3 || v[10] != 2 {
			t.Fatal("original encryption4-to1 fallback changed auth/cipher", radio, v)
		}
	}
	if s.Security != "wpa2-wpa3-psk" || s.Options != nil {
		t.Fatal("per-AP projection mutated desired service", s)
	}
}

func TestMulticastMCSAndUnicastUseIndependentSubCapabilities(t *testing.T) {
	s := Service{WLAN: 1, SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{2}}
	o := serviceOptions(s)
	o.Multicast = &MulticastOptions{ConfigureGlobal: true, GlobalSnooping: true, ToUnicast: true, Rate2G: 1, Rate5G: 7, RateType5G: 1, QueryInterval: 60, MaxResponse: 10}
	s.Options = &o
	if err := validateWirelessOptions(s); err != nil {
		t.Fatal(err)
	}
	for _, tc := range []struct {
		sub  uint32
		want string
	}{
		{0, ""}, {1, "0001000101"}, {2, "00010103010207"}, {3, "00020001010103010207"},
	} {
		ap := cweng.APStatus{GeneralCapabilities: []uint32{0, 1 << 11, 0, 1 << 3}, SubCapabilities: map[uint16]uint32{99: tc.sub}, Capabilities: []cweng.RadioCapability{{RadioID: 2, Band: "5 GHz"}}}
		var extension, base []byte
		for _, e := range wirelessExtraElements(s, 2, ap) {
			switch binary.BigEndian.Uint16(e.Value[6:]) {
			case 0xc9:
				extension = e.Value[10:]
			case 0x70:
				base = e.Value[10:]
			}
		}
		want, _ := hex.DecodeString(tc.want)
		if !bytes.Equal(extension, want) || !bytes.Equal(base, []byte{1, 0, 0}) {
			t.Fatal("MCS was sent as Mbps or gated by to-unicast", tc.sub, extension, base)
		}
	}
}

func TestWirelessOptionsV6SourceGolden(t *testing.T) {
	base := Service{WLAN: 2, SSID: "Oracle-WiFi", Security: "wpa2-psk", Passphrase: "synthetic-test-key", Enabled: true, Radios: []uint8{1, 2}}
	tests := []struct {
		name   string
		modify func(*Service)
		hex    string
	}{
		{"psk", func(s *Service) {}, "010200000064030001020200015180001273796e7468657469632d746573742d6b6579"},
		{"isolation", func(s *Service) { o := serviceOptions(*s); o.Isolate = true; s.Options = &o; s.Hidden = true }, "010200000064030101020200015180001273796e7468657469632d746573742d6b6579"},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := base
			tt.modify(&s)
			if err := validate(s); err != nil {
				t.Fatal(err)
			}
			want, _ := hex.DecodeString(tt.hex)
			got := wlanElements(s, 1)
			if !bytes.Equal(got[1].Value[10:], want) {
				t.Fatalf("got %x want %x", got[1].Value[10:], want)
			}
			if (got[0].Value[18] == 0) != s.Hidden {
				t.Fatal("SSID broadcast bit")
			}
		})
	}
}
func TestLimitUnitsMLOAndNewFormat(t *testing.T) {
	s := Service{WLAN: 2, SSID: "Parity", Security: "wpa2-psk", Passphrase: "synthetic-test-key", Enabled: true, Radios: []uint8{1}}
	o := serviceOptions(s)
	o.RateLimit = &WirelessRateLimit{Enabled: true, Mode: "ssid", Upload: 8000, Download: 16000}
	s.Options = &o
	ap := cweng.APStatus{GeneralCapabilities: []uint32{1 << 13, 0x80000000}, SubCapabilities: map[uint16]uint32{0x5f: 2}}
	els := wirelessExtraElements(s, 1, ap)
	want, _ := hex.DecodeString("03000003e8000007d00102")
	if !bytes.Equal(els[0].Value[10:], want) {
		t.Fatalf("limit %x", els[0].Value)
	}
	want, _ = hex.DecodeString("01000000080200000003020100")
	if !bytes.Equal(els[1].Value[10:], want) {
		t.Fatalf("MLO disabled %x", els[1].Value)
	}
	o.MLO = true
	if validateServiceCapability(s, ap, 1) != nil {
		t.Fatal("advertised MLO rejected")
	}
	if validateServiceCapability(s, cweng.APStatus{}, 1) == nil {
		t.Fatal("unadvertised MLO accepted")
	}
	if e := advancedWLANElements(s, 1, ap); e[1].Value[7] != 0x94 || e[1].Value[10+10] != 1 {
		t.Fatal("new security format missing enable field")
	}
	s.Security = "wpa2-wpa3-psk"
	s.Options = nil
	mode, tail := serviceSecurity(s)
	if mode != 4 || tail[0] != 3 || tail[1] != 2 {
		t.Fatal("V6 WPA2/WPA3 is encryption4/auth3/AES")
	}
}
func TestGBKEncodingByteLength(t *testing.T) {
	s := Service{SSID: "无线无线无线无线无线无线无线无线", Security: "open", Radios: []uint8{1}}
	if validate(s) == nil {
		t.Fatal("accepted UTF8 SSID over 32 bytes")
	}
	o := serviceOptions(s)
	o.Encoding = "gbk"
	s.Options = &o
	if err := validate(s); err != nil {
		t.Fatal(err)
	}
}
