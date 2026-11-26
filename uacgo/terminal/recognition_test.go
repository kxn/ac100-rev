package terminal

import "testing"

func TestFirmwareRecognitionSources(t *testing.T) {
	r := New([6]byte{0xf0, 0x76, 0x6f, 1, 2, 3})
	if r.BrandName() != "apple" || r.BrandSource != 0 {
		t.Fatal(r)
	}
	r = r.Observe(Input{Type: 1, Text: "samsung"})
	if r.BrandName() != "samsung" {
		t.Fatal("equal priority must take the new result", r)
	}
	r = r.Observe(Input{Type: 1, Text: "iPhone"})
	if r.BrandSource != 2 {
		t.Fatal("Apple hostname did not win its higher priority", r)
	}
	r = r.Observe(Input{Type: 3, Text: "Android HMSCore"})
	if r.SystemName() != "harmonyOS" {
		t.Fatal(r)
	}
	r = r.Observe(Input{Type: 2, Text: "android-dhcp"})
	if r.SystemName() != "android" {
		t.Fatal("higher priority DHCP class must replace Harmony UA", r)
	}
	r = r.Observe(Input{Type: 3, Text: "Windows Win64"})
	if r.SystemName() != "android" {
		t.Fatal("lower priority UA replaced DHCP classification", r)
	}
}

func TestFirmwareUnknownCaseAndTruncation(t *testing.T) {
	r := New([6]byte{2, 1, 2, 3, 4, 5})
	r = r.Observe(Input{Type: 0}).Observe(Input{Type: 1, Text: "IPHONE"})
	if r.BrandName() != "others" {
		t.Fatal("strstr must stay case sensitive", r)
	}
	r = r.Observe(Input{Type: 2, Text: "unknown"}).Observe(Input{Type: 3, Text: "unknown"})
	if r.Flags != 31 || r.SystemName() != "others" {
		t.Fatal(r)
	}
	r = r.Observe(Input{Type: 1, Text: "samsung\x00iPhone"})
	if r.BrandName() != "samsung" {
		t.Fatal(r)
	}
	text := ""
	for i := 0; i < 255; i++ {
		text += "x"
	}
	r = r.Observe(Input{Type: 1, Text: text + "iPhone"})
	if r.BrandName() != "samsung" {
		t.Fatal("text beyond the firmware input length matched", r)
	}
}
