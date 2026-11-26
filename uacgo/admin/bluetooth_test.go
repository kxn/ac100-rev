package admin

import (
	"bytes"
	"context"
	"encoding/binary"
	"encoding/hex"
	"encoding/json"
	"net/http/httptest"
	"path/filepath"
	"strings"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func bluetoothAP(ap cweng.APStatus) cweng.APStatus {
	ap.GeneralCapabilities = []uint32{0, 0, 1<<13 | 1<<15, 1 << 6}
	ap.SubCapabilities = map[uint16]uint32{77: 1, 102: 1}
	return ap
}
func TestBluetoothGatewayPackedWireServerCertificateAndRemoval(t *testing.T) {
	m, e := testController(t)
	e.RegisterObservationHandlers()
	f, ap := newDeferredAP(t, e)
	ap = bluetoothAP(ap)
	rule := BluetoothRule{ID: "r", Name: "Gateway", Mode: 0, Scan: true, RSSI: -65, RSSIDedup: true, Channels: []uint8{37, 38, 39}, Filters: []BluetoothFilter{{Enabled: true, Type: 9, Mode: 1, Data: "TAG"}}, Server: 7}
	server := BluetoothServer{ID: 7, Name: "MQTT", AddressType: "url", Address: "mqtt.example", Port: 1883, Protocol: "mqtt", Username: "u", Password: "p", ClientID: "c", Connected: true, TLS: true, CA: []byte("abc"), Topics: []BluetoothTopic{{Topic: "adv"}}}
	p := BluetoothConfig{Rules: []BluetoothRule{rule}, Servers: []BluetoothServer{server}}
	if err := validateBluetooth(&p, Config{}); err != nil {
		t.Fatal(err)
	}
	m.applyBluetooth(context.Background(), ap, Config{Bluetooth: &p})
	wantGateway, _ := hex.DecodeString("01010000001800000001bf00010004032526270002000701090103544147")
	// Total TLV length = 5 + 8 + 11 = 24, with no C structure padding.
	f.mu.Lock()
	received := map[uint16][]byte{}
	for _, packet := range f.packets {
		for _, el := range packet.Elements {
			if el.Type == 0x25 {
				received[binary.BigEndian.Uint16(el.Value[6:])] = el.Value[10:]
			}
		}
	}
	f.mu.Unlock()
	if !bytes.Equal(received[0xdb], wantGateway) {
		t.Fatalf("gateway %x want %x", received[0xdb], wantGateway)
	}
	if !bytes.Equal(received[0xa7], []byte{1, 0, 0, 0, 4, 255, 255, 255, 255}) {
		t.Fatalf("gateway mode %x", received[0xa7])
	}
	if v := received[0xde]; len(v) != 70 || string(v[1:33]) != "900150983cd24fb0d6963f7d28e17f72" || string(v[33:65]) != "900150983cd24fb0d6963f7d28e17f72" || !bytes.Equal(v[65:], []byte{0, 3, 'a', 'b', 'c'}) {
		t.Fatalf("certificate %x", v)
	}
	v := received[0xdc]
	if len(v) < 22 || !bytes.Equal(v[:4], []byte{7, 0, 0, 12}) || string(v[4:16]) != "mqtt.example" || binary.BigEndian.Uint16(v[16:]) != 1883 || !bytes.Contains(v, []byte("ec0405c5aef93e771cd80e0db180b88b")) {
		t.Fatalf("server %x", v)
	}
	if !bytes.Equal(received[0xdd], []byte{0, 7, 0, 0, 0, 0, 0}) {
		t.Fatal("connect command", received[0xdd])
	}
	// A reconnect status report is independent of the configuration ACK.
	status, _ := capwap.NewParsedPacket(9)
	status.Control.SeqNum = 61
	status.Elements = []capwap.Element{privateSetting(0xdd, []byte{1, 7, 1, 0, 0, 0, 7, 0, 0, 0, 3, 'b', 'a', 'd'})}
	f.conn.Write(status.Assemble())
	until := time.Now().Add(time.Second)
	found := false
	for !found && time.Now().Before(until) {
		for _, a := range e.APs() {
			if a.ID == ap.ID && len(a.BluetoothServers) == 1 {
				found = a.BluetoothServers[0].Reason == "bad" && !a.BluetoothServers[0].Connected
			}
		}
		time.Sleep(time.Millisecond)
	}
	if !found {
		t.Fatal("AP connection report not exposed")
	}
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	restored.applyBluetooth(context.Background(), ap, Config{})
	f.mu.Lock()
	defer f.mu.Unlock()
	last := f.packets[len(f.packets)-1].Elements[0].Value
	if binary.BigEndian.Uint16(last[6:]) != 0xdd || !bytes.Equal(last[10:], []byte{0, 7, 1, 0, 0, 0, 0}) {
		t.Fatalf("removed/restarted policy leaked server connection %x", last)
	}
}
func TestBluetoothLargeCertificateUsesCAPWAPFragmentsAndRedactsSecrets(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	ap = bluetoothAP(ap)
	p := BluetoothConfig{Rules: []BluetoothRule{{ID: "r", Name: "R", Mode: 0, Scan: true, RSSI: -70, Channels: []uint8{37}, Server: 1}}, Servers: []BluetoothServer{{ID: 1, Name: "S", Protocol: "mqtt", AddressType: "ipv4", Address: "192.0.2.1", Port: 8883, Password: "private-test-secret", TLS: true, CA: bytes.Repeat([]byte{0x41}, 61440)}}}
	m.applyBluetooth(context.Background(), ap, Config{Bluetooth: &p})
	m.mu.Lock()
	state := m.status[ap.ID+"/bluetooth"].State
	m.mu.Unlock()
	if state != "acknowledged" {
		t.Fatal(state)
	}
	f.mu.Lock()
	seen := false
	for _, pkt := range f.packets {
		for _, el := range pkt.Elements {
			if el.Type == 0x25 && binary.BigEndian.Uint16(el.Value[6:]) == 0xde {
				seen = len(el.Value) > 61440
			}
		}
	}
	f.mu.Unlock()
	if !seen {
		t.Fatal("large certificate never reassembled at simulated AP")
	}
	m.config.Bluetooth = &p
	r := httptest.NewRecorder()
	m.Handler().ServeHTTP(r, httptest.NewRequest("GET", "http://localhost/api/config", nil))
	if strings.Contains(r.Body.String(), "private-test-secret") {
		t.Fatal("secret leaked through config")
	}
	public := publicBluetooth(&p)
	public.Servers[0].Password = ""
	body, _ := json.Marshal(public)
	r = httptest.NewRecorder()
	m.Handler().ServeHTTP(r, httptest.NewRequest("POST", "http://localhost/api/bluetooth", bytes.NewReader(body)))
	if r.Code != 202 || m.config.Bluetooth.Servers[0].Password != "private-test-secret" {
		t.Fatal("blank edit lost credential", r.Code, r.Body.String())
	}
}

func TestNumericAPListsAreNotBase64InPublicConfiguration(t *testing.T) {
	cfg := Config{Bluetooth: &BluetoothConfig{Rules: []BluetoothRule{{Channels: []uint8{37, 38, 39}}}}, APDefaults: APOptions{LAG: &APLAG{Ports: []uint8{103, 104}}}}
	b, err := json.Marshal(cfg)
	if err != nil {
		t.Fatal(err)
	}
	var v map[string]any
	if err := json.Unmarshal(b, &v); err != nil {
		t.Fatal(err)
	}
	rules := v["bluetooth"].(map[string]any)["rules"].([]any)
	if _, ok := rules[0].(map[string]any)["channels"].([]any); !ok {
		t.Fatal("Bluetooth channels encoded as binary", string(b))
	}
	lag := v["ap_defaults"].(map[string]any)["lag"].(map[string]any)
	if _, ok := lag["ports"].([]any); !ok {
		t.Fatal("LAG ports encoded as binary", string(b))
	}
	// Existing files written by the previous implementation remain readable.
	var old BluetoothRule
	if err := json.Unmarshal([]byte(`{"channels":"JSYn"}`), &old); err != nil || len(old.Channels) != 3 || old.Channels[0] != 37 {
		t.Fatal(old, err)
	}
}
