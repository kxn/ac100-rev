package admin

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"testing"
	"time"
	"uacgo/cweng"
	"uacgo/firmware"
)

func resourceFixture() Config {
	on, echo, channel, power := true, uint8(20), 6, 15
	options := APOptions{LED: &on, EchoSeconds: &echo, Account: &APAccount{Username: "admin", Password: "fixture"}, Radios: []RadioSetting{{Radio: 1, Channel: &channel, Power: &power, Advanced: &RadioAdvanced{Mode: 6, MaxClients: 128, WMM: true}}}}
	cfg := Config{APDefaults: options, Groups: []APGroup{{ID: "floor", Options: options}}, Templates: []APTemplate{{ID: "model", Options: options}}}
	for i := range 32 {
		id := fmt.Sprintf("ap-%d", i)
		cfg.APProfiles = append(cfg.APProfiles, APProfile{AP: id, Group: "floor", Template: "model", Options: APOptions{LED: &on}})
		for radio := uint8(1); radio <= 2; radio++ {
			cfg.Radios = append(cfg.Radios, RadioSetting{AP: id, Radio: radio, Channel: &channel, Power: &power, Advanced: options.Radios[0].Advanced})
		}
	}
	for i := range 4 {
		cfg.Services = append(cfg.Services, Service{ID: fmt.Sprint(i), SSID: "Office", Enabled: true, Security: "wpa2-psk", Passphrase: "fixture-password", Radios: RadioList{1, 2}, Groups: []string{"floor"}})
	}
	return cfg
}

func BenchmarkResourceConfigSnapshot(b *testing.B) {
	m := &Manager{config: resourceFixture()}
	b.ReportAllocs()
	for b.Loop() {
		_ = m.snapshot()
	}
}

func BenchmarkResourceAPInheritance(b *testing.B) {
	cfg := resourceFixture()
	ap := cweng.APStatus{ID: "ap-0"}
	b.ReportAllocs()
	for b.Loop() {
		_, _ = effectiveAPOptions(cfg, ap)
	}
}

func BenchmarkResourceRadioOverlay(b *testing.B) {
	cfg := resourceFixture()
	base, over := cfg.Radios[0], cfg.APDefaults.Radios[0]
	b.ReportAllocs()
	for b.Loop() {
		_ = mergeRadio(base, over)
	}
}

func BenchmarkResourceHistoryIdle(b *testing.B) {
	now := time.Now()
	m := &Manager{historySaved: now, history: WirelessHistory{APCounts: []APCountSample{{At: now}}}}
	for range 20000 {
		m.history.Radios = append(m.history.Radios, RadioSample{At: now, Metrics: map[string]float64{"channelUsage": 20}})
	}
	for range 100000 {
		m.history.Clients = append(m.history.Clients, ClientSignalSample{At: now})
	}
	for range 10000 {
		m.history.Events = append(m.history.Events, StationTransition{ClientTransition: cweng.ClientTransition{At: now}})
	}
	b.ReportAllocs()
	for b.Loop() {
		m.captureHistory(nil, now)
	}
}

func BenchmarkResourceFirmwareRead(b *testing.B) {
	path := filepath.Join(b.TempDir(), "image.bin")
	if err := os.WriteFile(path, upgradeFixture(32<<20), 0600); err != nil {
		b.Fatal(err)
	}
	for _, streamed := range []bool{false, true} {
		name := "whole-file"
		if streamed {
			name = "reader-at"
		}
		b.Run(name, func(b *testing.B) {
			b.ReportAllocs()
			for b.Loop() {
				if streamed {
					f, err := os.Open(path)
					if err != nil {
						b.Fatal(err)
					}
					_, err = firmware.InspectReader(f, 32<<20)
					_ = f.Close()
					if err != nil {
						b.Fatal(err)
					}
				} else {
					data, err := os.ReadFile(path)
					if err != nil {
						b.Fatal(err)
					}
					if _, err = firmware.Inspect(data); err != nil {
						b.Fatal(err)
					}
				}
			}
		})
	}
}
func BenchmarkResourceHistoryEncoding(b *testing.B) {
	h := WirelessHistory{}
	for range 20000 {
		h.Radios = append(h.Radios, RadioSample{At: time.Now(), AP: "a", Metrics: map[string]float64{"usage": 20}})
	}
	for _, stream := range []bool{false, true} {
		name := "whole-document"
		if stream {
			name = "stream"
		}
		b.Run(name, func(b *testing.B) {
			b.ReportAllocs()
			for b.Loop() {
				if stream {
					if err := writeHistory(io.Discard, h); err != nil {
						b.Fatal(err)
					}
				} else {
					out, err := json.MarshalIndent(h, "", "  ")
					if err != nil {
						b.Fatal(err)
					}
					if _, err = io.Copy(io.Discard, bytes.NewReader(out)); err != nil {
						b.Fatal(err)
					}
				}
			}
		})
	}
}
