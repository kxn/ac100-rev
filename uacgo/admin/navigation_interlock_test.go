package admin

import (
	"context"
	"testing"
	"uacgo/cweng"
)

func TestVendorBandNavigationDoesNotInventServiceOrVLANGates(t *testing.T) {
	m, e := testController(t)
	_, ap := newDeferredAP(t, e)
	ap.GeneralCapabilities = []uint32{1 << 3}
	off := false
	cfg := Config{BandNavigation: &BandNavigation{Enabled: true, Threshold5G: 20, Difference: 4, MaxFailures: 10}, Radios: []RadioSetting{{AP: ap.ID, Radio: 2, Enabled: &off}}}
	m.config = cfg
	// band_navigation_wtp_packt_send @633a60 checks capability3 and sends
	// the global policy; it does not consult WLAN assignments or RF enable.
	m.reconcileAP(cweng.PinAP(context.Background(), ap), ap, cfg)
	st := m.status[ap.ID+"/band-navigation"]
	if st.EffectiveEnabled == nil || !*st.EffectiveEnabled {
		t.Fatal(st)
	}
}
