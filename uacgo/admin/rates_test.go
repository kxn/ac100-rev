package admin

import (
	"bytes"
	"context"
	"os"
	"testing"
	"time"
	"uacgo/cweng"
)

func TestRateEncodingMatchesVendorCapture(t *testing.T) {
	want, err := os.ReadFile("../data/rate-default.bin")
	if err != nil {
		t.Fatal(err)
	}
	p := defaultRatePolicy()
	if err = validateRates(p); err != nil {
		t.Fatal(err)
	}
	if got := legacyRateValue(p, 1); !bytes.Equal(got, want) {
		t.Fatalf("vendor capture mismatch\ngot %x\nwant%x", got, want)
	}
	p.A.Supported = append(p.A.Supported, 6)
	if validateRates(p) == nil {
		t.Fatal("overlapping basic/supported accepted")
	}
	p = defaultRatePolicy()
	p.AX.Supported = 24
	if validateRates(p) == nil {
		t.Fatal("invalid AX index accepted")
	}
}
func TestRateCapabilitiesRetryAndRestore(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap.Capabilities = []cweng.RadioCapability{{RadioID: 1, SupportAX: true}, {RadioID: 2, SupportAC: true, SupportAX: true}}
	ap.GeneralCapabilities = []uint32{0, 0, 1 << 6}
	p := defaultRatePolicy()
	p.G.Basic = []float64{12}
	p.G.Supported = []float64{24, 54}
	cfg := Config{Rates: &p}
	f.mu.Lock()
	f.rejectPrivate = 0xa
	f.rejectCount = 1
	f.mu.Unlock()
	ctx := context.Background()
	m.applyRates(ctx, ap, cfg)
	if m.status[ap.ID+"/rates"].State != "failed" {
		t.Fatal("AP rejection hidden")
	}
	m.mu.Lock()
	st := m.status[ap.ID+"/rates"]
	st.At = time.Now().Add(-time.Minute)
	m.status[ap.ID+"/rates"] = st
	m.mu.Unlock()
	m.applyRates(ctx, ap, cfg)
	if m.status[ap.ID+"/rates"].State != "acknowledged" {
		t.Fatal(m.status)
	}
	f.mu.Lock()
	before := len(f.packets)
	f.mu.Unlock()
	m.applyRates(ctx, ap, Config{})
	f.mu.Lock()
	defer f.mu.Unlock()
	if len(f.packets) <= before {
		t.Fatal("removing policy did not restore AP defaults")
	}
	found := false
	for _, pkt := range f.packets[before:] {
		for _, el := range pkt.Elements {
			if el.Type == 0x25 && len(el.Value) >= 65 && bytes.Equal(el.Value[len(el.Value)-55:], legacyRateValue(defaultRatePolicy(), 1)) {
				found = true
			}
		}
	}
	if !found {
		t.Fatal("default rate table not restored")
	}
}
