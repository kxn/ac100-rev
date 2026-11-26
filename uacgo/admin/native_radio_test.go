package admin

import (
	"testing"
	"uacgo/cweng"
)

func TestNativeRadioEnumConversionAndReadback(t *testing.T) {
	b := []byte(`{"error_code":0,"wireless":{"radio_entry":[{"radio_entry_1":{"radio_id":"1","mode":"11","bandwidth":"0","enable":"off","radio_max_sta":"256"}}]}}`)
	current, err := radioModel(b, 1)
	if err != nil {
		t.Fatal(err)
	}
	on := true
	c := cweng.RadioCapability{MinPower: 3, MaxPower: 24}
	p, err := nativeParameters(RadioSetting{Radio: 1, Enabled: &on}, c, current)
	if err != nil || p["enable"] != "on" {
		t.Fatal(p, err)
	}
	a := RadioAdvanced{Mode: 10, Bandwidth: 0, MaxClients: 64, ManagementRate: 1, Beacon: 200, DTIM: 2}
	_, err = nativeParameters(RadioSetting{Radio: 1, Advanced: &a}, c, current)
	if err == nil {
		t.Fatal("accepted incomplete AP model")
	}
	for _, key := range []string{"antenna", "beacon_intv", "dtim_period", "frag_threshold", "rts_threshold", "wmm", "short_gi", "brd_probe", "rssi_weak_restrict", "rssi_weak_kick", "airtime", "rssi_weak_restrict_val", "rssi_weak_kick_val", "vhtmubfer", "ofdma", "twt", "gi_mode"} {
		current[key] = "0"
	}
	p, err = nativeParameters(RadioSetting{Radio: 1, Advanced: &a}, c, current)
	if err != nil || p["mode"] != "9" || p["bandwidth"] != "1" || p["radio_max_sta"] != "64" {
		t.Fatal(p, err)
	}
	a.EDCA = &EDCAConfig{}
	if _, err = nativeParameters(RadioSetting{Advanced: &a}, c, current); err == nil {
		t.Fatal("silently omitted EDCA")
	}
}

func TestNativeModelResponsesRequireExplicitSuccess(t *testing.T) {
	for _, b := range []string{`{}`, `null`, `{"error_code":null}`, `{"error_code":"0"}`, `{"error_code":1}`} {
		if modelResult([]byte(b)) == nil {
			t.Fatal("accepted ambiguous success", b)
		}
	}
	if modelResult([]byte(`{"error_code":0}`)) != nil {
		t.Fatal("rejected success")
	}
	if _, err := radioModel([]byte(`{"wireless":{"radio_entry":[{"r":{"radio_id":"1"}}]}}`), 1); err == nil {
		t.Fatal("missing result accepted")
	}
	if _, err := bandModel([]byte(`{"apmng_band_navigation":{"settings":{"enable":"on"}}}`)); err == nil {
		t.Fatal("missing result accepted")
	}
}

func TestNativeAutomaticGIClearsPreviousManualValue(t *testing.T) {
	c := cweng.RadioCapability{RadioID: 1, MaxClients: 64, Modes: []int{6}, Bandwidths: []int{0}}
	a := defaultRadioAdvanced(c)
	a.GI = -1
	current := map[string]string{}
	for _, k := range []string{"mode", "bandwidth", "radio_max_sta", "antenna", "beacon_intv", "dtim_period", "frag_threshold", "rts_threshold", "wmm", "short_gi", "brd_probe", "rssi_weak_restrict", "rssi_weak_kick", "airtime", "rssi_weak_restrict_val", "rssi_weak_kick_val", "vhtmubfer", "ofdma", "twt", "gi_mode"} {
		current[k] = "2"
	}
	p, err := nativeParameters(RadioSetting{Radio: 1, Advanced: &a}, c, current)
	if err != nil || p["gi_mode"] != "0" {
		t.Fatal(p, err)
	}
}
