package admin

import (
	"context"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestBandNavigationRequiresUsableMatchingBands(t *testing.T) {
	ap := cweng.APStatus{ID: "ap", Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "2.4 GHz"}, {RadioID: 2, Band: "5 GHz"}}}
	cfg := Config{BandNavigation: &BandNavigation{Enabled: true, Threshold5G: 20, Difference: 4, MaxFailures: 10}, Services: []Service{{ID: "office", Enabled: true, Radios: []uint8{1, 2}}}}
	if b, _ := effectiveBandNavigation(ap, cfg); !b.Enabled {
		t.Fatal("matching dual-band service rejected")
	}
	off := false
	cfg.Radios = []RadioSetting{{AP: "ap", Radio: 2, Enabled: &off}}
	if b, _ := effectiveBandNavigation(ap, cfg); b.Enabled {
		t.Fatal("steering toward disabled 5 GHz")
	}
	cfg.Radios = nil
	cfg.Services[0].Radios = []uint8{1}
	if b, _ := effectiveBandNavigation(ap, cfg); b.Enabled {
		t.Fatal("steering where 5 GHz lacks the service")
	}
	cfg.Services[0].Radios = []uint8{1, 2}
	cfg.Services[0].Bindings = []ServiceBinding{{AP: "ap", Radio: 1, VLAN: 10}, {AP: "ap", Radio: 2, VLAN: 20}}
	if b, _ := effectiveBandNavigation(ap, cfg); b.Enabled {
		t.Fatal("steering between different VLANs")
	}
}

func TestBandNavigationDisabledBeforeClosingRadioAndHeldUntilSettled(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.Capabilities[0].Band = "2.4 GHz"
	ap.Capabilities[1].Band = "5 GHz"
	ap.GeneralCapabilities = []uint32{1 << 3}
	cfg := Config{BandNavigation: &BandNavigation{Enabled: true, Threshold5G: 20, Difference: 4, MaxFailures: 10}, Services: []Service{{ID: "office", SSID: "Office", Security: "open", Enabled: true, Radios: []uint8{1, 2}}}}
	m.config = cfg
	ctx, cancel := context.WithTimeout(cweng.PinAP(context.Background(), ap), 3*time.Second)
	defer cancel()
	m.reconcileAP(ctx, ap, cfg)
	key := ap.ID + "/band-navigation"
	if st := m.status[key]; st.EffectiveEnabled == nil || *st.EffectiveEnabled {
		t.Fatal("navigation enabled before WLAN settlement", st)
	}
	m.mu.Lock()
	settling := m.settling[ap.ID]
	settling.Ready = time.Now().Add(-time.Second)
	m.settling[ap.ID] = settling
	m.mu.Unlock()
	m.reconcileAP(ctx, ap, cfg)
	if st := m.status[key]; st.EffectiveEnabled == nil || !*st.EffectiveEnabled {
		t.Fatal("navigation not enabled after settlement", st)
	}
	off := false
	cfg.Radios = []RadioSetting{{AP: ap.ID, Radio: 2, Enabled: &off}}
	cfg.Version++
	m.config = cfg
	f.mu.Lock()
	f.sequence = nil
	f.mu.Unlock()
	m.reconcileAP(ctx, ap, cfg)
	f.mu.Lock()
	sequence := append([]string{}, f.sequence...)
	f.mu.Unlock()
	if len(sequence) < 2 || sequence[0] != "navigation-off" {
		t.Fatal("radio closed before navigation was disabled", sequence)
	}
	if st := m.status[key]; st.EffectiveEnabled == nil || *st.EffectiveEnabled {
		t.Fatal("single-band AP still steering", st)
	}
}
