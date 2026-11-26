package admin

import (
	"bytes"
	"encoding/hex"
	"testing"
	"uacgo/cweng"
)

func TestWirelessOptionsIndependentV6Oracle(t *testing.T) {
	base := Service{WLAN: 2, SSID: "Oracle-WiFi", Security: "wpa2-psk", Passphrase: "synthetic-test-key", Enabled: true, Radios: []uint8{1, 2}}
	tests := []struct {
		name   string
		modify func(*Service)
		hex    string
	}{
		{"psk", func(s *Service) {}, "010200000064030001020200015180001273796e7468657469632d746573742d6b6579"},
		{"isolation", func(s *Service) { o := serviceOptions(*s); o.Isolate = true; s.Options = &o; s.Hidden = true }, "010200000064030101020200015180001273796e7468657469632d746573742d6b6579"},
		{"radius", func(s *Service) {
			s.Security = "wpa2-enterprise"
			o := serviceOptions(*s)
			o.Radius = &RadiusOptions{IP: "192.168.70.200", Port: 1812, AccountingPort: 1813, Secret: "synthetic-radius"}
			s.Options = &o
		}, "01020000006403000202020001518001c0a846c801c0a846c801c0a846c8071407150715001073796e7468657469632d726164697573"},
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
func TestGBKLengthAndRadiusRedaction(t *testing.T) {
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
	o.Radius = &RadiusOptions{Secret: "private-radius-key"}
	redacted := redactService(s)
	if redacted.Options.Radius.Secret != "" || !redacted.Options.Radius.HasSecret || s.Options.Radius.Secret == "" {
		t.Fatal("RADIUS redaction leaks or mutates stored secret")
	}
}
