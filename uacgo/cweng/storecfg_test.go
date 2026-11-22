package cweng

import (
	"path/filepath"
	"testing"
	"uacgo/internal/testroot"

	"uacgo/store"
)

// Store-backed wserv/rdmngr config flows through the engine handlers into
// correctly framed envelopes (store rows → wire bytes).
func TestStoreWserviceConfig(t *testing.T) {
	dir := t.TempDir()
	stores, err := store.OpenAll(filepath.Join(dir, "dbs"))
	if err != nil {
		t.Fatal(err)
	}
	defer stores.CloseAll()
	if err := stores.Wserv.SetWserv(store.WservRow{WservID: 1, Enable: "1", Vlan: 1, SSID: "00_YXJ_统一技术_GBK"}); err != nil {
		t.Fatal(err)
	}
	if err := stores.Rdmngr.SetRdmngr(store.RdmngrRow{RfID: 1, FreqBand: 6, Mode: 2, Bandwidth: 100, Channel: 6, PowerLevel: 20}); err != nil {
		t.Fatal(err)
	}
	rateDefault, err := LoadRateDefault(testroot.Root() + "/uacgo/data/rate-default.bin")
	if err != nil {
		t.Fatal(err)
	}
	cfg := &StoreWserviceConfig{Stores: stores, RateDefault: rateDefault}

	svcs := cfg.WlanServices()
	if len(svcs) != 1 || svcs[0].RadioID != 1 {
		t.Fatalf("services = %+v", svcs)
	}
	radios := cfg.Radios()
	if len(radios) != 1 || radios[0].Rate.RadioID != 1 {
		t.Fatalf("radios = %+v", radios)
	}
	if len(radios[0].Rate.AssembleValue()) != 55 {
		t.Fatal("rate payload must stay 55 bytes")
	}
}
