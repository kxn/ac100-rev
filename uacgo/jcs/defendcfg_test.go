package jcs

import (
	"database/sql"
	"encoding/json"
	"path/filepath"
	"testing"
	"time"

	_ "modernc.org/sqlite"
	"uacgo/cweng"
)

func TestDefendConfigAndPayloads(t *testing.T) {
	dir := t.TempDir()
	db, err := sql.Open("sqlite", filepath.Join(dir, "cfg.db"))
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()

	// payload builders (wire shapes from the AC dumps)
	v4, v6 := cweng.BuildDhcpDefend(true, true, []cweng.DhcpDefendServer{
		{AddrType: 1, Addr: []byte{10, 0, 0, 1}},
		{AddrType: 2, Addr: make([]byte, 16)},
	})
	if v4.Type != 0x47 || len(v4.Value) != 8+7 {
		t.Fatalf("dhcp v4 payload = %d bytes type %x", len(v4.Value), v4.Type)
	}
	if v6.Type != 0x61 || len(v6.Value) != 8+7 {
		t.Fatalf("dhcp v6 payload = %d bytes type %x", len(v6.Value), v6.Type)
	}
	if v4.Value[0] != 1 || v4.Value[1] != 1 || v4.Value[7] != 1 {
		t.Fatalf("dhcp header = %x", v4.Value[:8])
	}
	arp := cweng.BuildArpDefend(true, false, []cweng.ArpBinding{{MAC: [6]byte{1}}})
	if arp.Type != 0x48 || len(arp.Value) != 8+12 || arp.Value[7] != 1 {
		t.Fatalf("arp payload = %x", arp.Value)
	}
	nd := cweng.BuildNdDefend(true, false, []cweng.NdBinding{{MAC: [6]byte{1}}})
	if nd.Type != 0x62 || len(nd.Value) != 8+22 {
		t.Fatalf("nd payload = %x", nd.Value)
	}
	storm := cweng.BuildStormCtrl(true, 512)
	if storm.Type != 0x46 || len(storm.Value) != 5 || storm.Value[0] != 1 {
		t.Fatalf("storm payload = %x", storm.Value)
	}

	// JCS surface: macauth engine + defense config with push hooks
	macDB := cweng.NewMacAuthDB(cweng.MacAuthByVLAN)
	var stormPush, dhcpPush, arpPush int
	push := &DefendPush{
		OnStorm: func(bool, uint32) { stormPush++ },
		OnDhcp:  func(bool, bool, []cweng.DhcpDefendServer) { dhcpPush++ },
		OnArp:   func(bool, bool, []cweng.ArpBinding) { arpPush++ },
	}
	s := NewServer()
	RegisterMacAuthHandlers(s, macDB)
	RegisterStormHandlers(s, db, push)
	RegisterDefendConfigHandlers(s, db, push)
	path := filepath.Join(dir, "jcs.service.srv.df")
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond)
	call := func(module, kw, method string, params any) string {
		t.Helper()
		resp, err := Call(path, method, module, kw, params)
		if err != nil {
			t.Fatal(err)
		}
		return string(resp)
	}

	// macauth lifecycle → engine decisions
	call("macauth_type", "set", "set", map[string]any{"type": 1})
	call("macauth_mac", "add", "add", map[string]any{"id": 1, "mac": "01:02:03:04:05:06"})
	call("macauth_group", "add", "add", map[string]any{
		"id": 1, "status": true, "bind_vlan": "10", "type": 0, "mac_ids": []int{1}})
	if resp := call("macauth_mac", "get", "get", nil); indexOfStr(resp, "01:02:03:04:05:06") < 0 &&
		indexOfStr(resp, "mac_list") < 0 {
		t.Fatalf("mac get = %s", resp)
	}
	sta := cweng.MacAuthSta{
		MACs: [][6]byte{{1, 2, 3, 4, 5, 6}}, VLAN: "10",
	}
	if !macDB.Check(sta) {
		t.Fatal("bound mac must pass after JCS add")
	}
	sta.MACs = [][6]byte{{9, 9, 9, 9, 9, 9}}
	if macDB.Check(sta) {
		t.Fatal("unknown mac must be forbidden on white list")
	}

	// storm / dhcp / arp set → hooks fired
	call("bcast_storm_ctrl", "set", "set", map[string]any{"enable": true, "storm_rate": 512})
	if stormPush != 1 {
		t.Fatal("storm push")
	}
	call("dhcpdef_svr", "add", "add", map[string]any{"svr_id": 1, "addr_type": 1, "svr_addr": "10.0.0.1"})
	if dhcpPush != 1 {
		t.Fatal("dhcp push")
	}
	call("arp_defend_arp", "add", "add", map[string]any{"arp_id": 1, "arp_ip": "10.0.0.2", "mac": "aa:bb:cc:dd:ee:ff"})
	if arpPush != 1 {
		t.Fatal("arp push")
	}
	var kv struct {
		Found bool `json:"found"`
	}
	if resp := call("arp_defend_ap", "get", "get", nil); json.Unmarshal([]byte(resp), &kv) != nil {
		t.Fatalf("arp ap get = %s", resp)
	}
	s.Close()
}
