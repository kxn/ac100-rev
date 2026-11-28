package admin

import (
	"bytes"
	"context"
	"encoding/binary"
	"os"
	"testing"
	"time"
	"uacgo/capwap"
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
	ap.Capabilities = []cweng.RadioCapability{{RadioID: 1, Band: "2.4 GHz", SupportAX: true}, {RadioID: 2, Band: "5 GHz", SupportAC: true, SupportAX: true}}
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

func TestRateEncodersShareOriginalAXCapabilityGate(t *testing.T) {
	for _, band := range []string{"2.4 GHz", "5 GHz", "6 GHz"} {
		for _, radioAX := range []bool{false, true} {
			for _, main70 := range []bool{false, true} {
				c := cweng.RadioCapability{RadioID: 1, Band: band, MaxClients: 64, SupportAC: true, SupportAX: radioAX}
				ap := cweng.APStatus{Capabilities: []cweng.RadioCapability{c}}
				if main70 {
					ap.GeneralCapabilities = []uint32{0, 0, 1 << 6}
				}
				a := defaultRadioAdvanced(c)
				for _, els := range [][]capwap.Element{rateElements(defaultRatePolicy(), ap), advancedRadioElements(RadioSetting{Radio: 1, Advanced: &a}, ap, c)} {
					ac, ax := false, false
					for _, el := range els {
						if el.Type != 0x25 || len(el.Value) < 10 {
							continue
						}
						switch binary.BigEndian.Uint16(el.Value[6:]) {
						case 0x2b:
							ac = true
						case 0xa0:
							ax = true
						}
					}
					if ax != main70 || ac != (band == "5 GHz") {
						t.Fatalf("band=%s radioAX=%v main70=%v: AC=%v AX=%v", band, radioAX, main70, ac, ax)
					}
				}
			}
		}
	}
}
