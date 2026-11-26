package admin

import (
	"bytes"
	"encoding/hex"
	"encoding/json"
	"net/http"
	"net/http/httptest"
	"strings"
	"testing"
	"uacgo/capwap"
	"uacgo/cweng"
)

func TestWLANMatchesCapturedVendorPacket(t *testing.T) {
	// Packet prefix from notes/vendor-web/README.md frames 204/232; the final
	// eight PSK bytes use a synthetic test password, not a captured credential.
	s := Service{WLAN: 2, SSID: "qiyitt", Security: "wpa2-psk", Passphrase: "12345678", Enabled: true}
	p, _ := capwap.NewParsedPacket(capwap.MsgIe1)
	p.Control.SeqNum = 0x24
	p.Elements = wlanElements(s, 1)
	want, err := hex.DecodeString("00104300000000000033dd01240047000400001901028000000000000000000000000000000101716979697474002500231234567800630063001901020000006403000102020001518000083132333435363738")
	if err != nil {
		t.Fatal(err)
	}
	got := p.Assemble()
	if !bytes.Equal(got, want) {
		t.Fatalf("vendor WLAN differs:\ngot  %x\nwant %x", got, want)
	}
	s.Enabled = false
	if e := wlanElements(s, 1); len(e) != 1 || e[0].Type != 0x403 || !bytes.Equal(e[0].Value, []byte{1, 2}) {
		t.Fatal("disable must use registered Delete WLAN 0x0403")
	}
}
func TestConfigPersistsAndRedactsPassword(t *testing.T) {
	e, err := cweng.NewEngine(0)
	if err != nil {
		t.Fatal(err)
	}
	defer e.Close()
	dir := t.TempDir()
	m, err := New(e, cweng.NewClientTable(), dir)
	if err != nil {
		t.Fatal(err)
	}
	s, err := m.saveService(Service{SSID: "Office", Security: "wpa2-psk", Passphrase: "synthetic-test-key", Enabled: true, Radios: []uint8{1, 2}})
	if err != nil {
		t.Fatal(err)
	}
	request := httptest.NewRequest(http.MethodGet, "http://localhost/api/config", nil)
	rec := httptest.NewRecorder()
	m.Handler().ServeHTTP(rec, request)
	if strings.Contains(rec.Body.String(), "synthetic-test-key") || !strings.Contains(rec.Body.String(), "has_password") {
		t.Fatal("API leaked credential or forgot password indicator")
	}
	restored, err := New(e, cweng.NewClientTable(), dir)
	if err != nil {
		t.Fatal(err)
	}
	s.Passphrase = ""
	s.SSID = "Changed"
	if _, err = restored.saveService(s); err != nil {
		t.Fatalf("blank edit must retain PSK: %v", err)
	}
	if restored.config.Services[0].Passphrase != "synthetic-test-key" {
		t.Fatal("credential lost across restart/edit")
	}
	bad := httptest.NewRequest(http.MethodPost, "http://localhost/api/services", strings.NewReader(`{}`))
	bad.Header.Set("Origin", "https://attacker.invalid")
	rec = httptest.NewRecorder()
	m.Handler().ServeHTTP(rec, bad)
	if rec.Code != http.StatusForbidden {
		t.Fatal("cross-origin mutation accepted")
	}
	bad = httptest.NewRequest(http.MethodGet, "http://attacker.invalid/api/config", nil)
	rec = httptest.NewRecorder()
	m.Handler().ServeHTTP(rec, bad)
	if rec.Code != http.StatusForbidden {
		t.Fatal("DNS-rebinding host accepted")
	}
	encoded, err := json.Marshal(s.Radios)
	if err != nil || string(encoded) != "[1,2]" {
		t.Fatalf("radio API must be numeric array: %s %v", encoded, err)
	}
}
func TestWirelessValidation(t *testing.T) {
	for _, s := range []Service{{SSID: "", Security: "open", Radios: []uint8{1}}, {SSID: "ok", Security: "wpa2-psk", Passphrase: "short", Radios: []uint8{1}}, {SSID: strings.Repeat("网", 11), Security: "open", Radios: []uint8{1}}, {SSID: "ok", Security: "open", Radios: []uint8{1, 1}}} {
		if validate(s) == nil {
			t.Fatalf("accepted invalid service %#v", s)
		}
	}
}

func TestRadioPacketMatchesCapturedFields(t *testing.T) {
	enabled := true
	channel, power := 6, 24
	elements := radioElements(RadioSetting{Radio: 1, Enabled: &enabled, Channel: &channel, Power: &power})
	if len(elements) != 3 || elements[0].Type != 0x1f || !bytes.Equal(elements[0].Value, []byte{1, 1}) || elements[1].Type != 0x404 || !bytes.Equal(elements[1].Value, []byte{1, 0, 6, 2, 0, 0, 0, 0}) || elements[2].Type != 0x411 || !bytes.Equal(elements[2].Value, []byte{1, 0, 0, 24}) {
		t.Fatalf("radio settings differ from V6 frame 112: %+v", elements)
	}
}

func TestRemoteHTTPOptInKeepsSameOriginWriteBoundary(t *testing.T) {
	m, _ := testController(t)
	address := "http://192.0.2.2:18090/api/controller/resources"
	w := httptest.NewRecorder()
	m.Handler().ServeHTTP(w, httptest.NewRequest("GET", address, nil))
	if w.Code != 403 {
		t.Fatal("local default accepted remote Host", w.Code)
	}
	handler := m.HandlerWithOptions(HTTPOptions{AllowRemote: true})
	w = httptest.NewRecorder()
	handler.ServeHTTP(w, httptest.NewRequest("GET", address, nil))
	if w.Code != 200 {
		t.Fatal("remote opt-in still rejects reachable Host", w.Code, w.Body.String())
	}
	for _, origin := range []string{"http://192.0.2.2:18090", "https://attacker.invalid"} {
		req := httptest.NewRequest("POST", address, strings.NewReader(`{"max_ap_sessions":2048}`))
		req.Header.Set("Origin", origin)
		w = httptest.NewRecorder()
		handler.ServeHTTP(w, req)
		want := 202
		if origin == "https://attacker.invalid" {
			want = 403
		}
		if w.Code != want {
			t.Fatal(origin, w.Code, w.Body.String())
		}
	}
}
