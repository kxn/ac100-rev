package cweng

import (
	"encoding/json"
	"os"
	"path/filepath"
	"testing"
)

func TestEntireFirmwareLibraryIncludesMultiAPModels(t *testing.T) {
	db, err := LoadAPDB("../data/apdb.json")
	if err != nil {
		t.Fatal(err)
	}
	if len(db.APList) != 81 || len(db.MultiAPList) != 3 || len(db.Models()) != 84 {
		t.Fatal("truncated firmware library")
	}
	variants := 0
	for _, m := range db.Models() {
		for _, hw := range m.Models {
			variants++
			ap := &APEntry{ModelID: uint32(m.ID), HardwareVersion: hw.HWVer}
			db.ResolveCapabilities(ap)
			if len(ap.Capabilities) != len(hw.Radios) || ap.Model != m.APName {
				t.Fatalf("unresolved %s/%s", m.APName, hw.HWVer)
			}
			for _, r := range ap.Capabilities {
				if r.MaxSSID < 1 || r.MaxClients < 1 || len(r.Channels) == 0 {
					t.Fatalf("missing radio metadata %s/%s", m.APName, hw.HWVer)
				}
			}
			bad := &APEntry{ModelID: uint32(m.ID), HardwareVersion: "unlisted-revision"}
			db.ResolveCapabilities(bad)
			if len(bad.Capabilities) > 0 {
				t.Fatal("borrowed HW revision")
			}
		}
	}
	if variants != 102 {
		t.Fatal("hardware library changed", variants)
	}
	model := db.MultiAPList[0]
	ap := &APEntry{ModelID: uint32(model.ID), HardwareVersion: "1.0"}
	db.ResolveCapabilities(ap)
	if !ap.SupportTrunk || len(ap.Capabilities[0].Channels) != 2 || ap.Capabilities[0].DefaultBandwidth == nil || *ap.Capabilities[0].DefaultBandwidth != 0 {
		t.Fatal("lost multi AP trunk/channel/default metadata", ap.Capabilities)
	}
}

func TestNegotiatedModelSelectionUsesFirmwareAndHardwareIdentity(t *testing.T) {
	dir := t.TempDir()
	base := []byte(`{"ap_list":[],"multi_ap_list":[]}`)
	if err := os.WriteFile(filepath.Join(dir, "apdb.json"), base, 0600); err != nil {
		t.Fatal(err)
	}
	// Same model and HW, different firmware: never union AX and BE features.
	cache := []byte(`{"ap_item_list":[{"id":123,"fwid_list":[{"fwid":"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","ap_index":0},{"fwid":"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB","ap_index":1}],"ap_list":[{"id":123,"ap_name":"Example-AX","hardware_id":"device-hw","is_mesh_device":true,"models":[{"hwver":"1.0","radios":{"5.0G_2":{"max_ssid":8,"max_stations":100,"max_tx_power":27,"min_tx_power":5,"max_tx_stream":2,"support_11ac":true,"support_11ax":true,"support_160M":true,"support_80M_80M":true,"radio_func_type":1,"support_WPA3":true,"mutex_channel":"36,40"},"2.4G_1":{"max_ssid":8,"max_stations":100,"max_tx_power":24,"min_tx_power":3,"support_11ax":true}}}]},{"id":123,"ap_name":"Example-BE","hardware_id":"device-hw","models":[{"hwver":"1.0","radios":{"5.0G_1":{"max_ssid":8,"max_stations":100,"max_tx_power":27,"min_tx_power":5,"support_11be":true}}}]}]}]}`)
	if !json.Valid(cache) {
		t.Fatal("fixture JSON")
	}
	if err := os.WriteFile(filepath.Join(dir, "apdb-nego.json"), cache, 0600); err != nil {
		t.Fatal(err)
	}
	db, err := LoadAPDB(filepath.Join(dir, "apdb.json"))
	if err != nil {
		t.Fatal(err)
	}
	for _, v := range []struct {
		fw     string
		be     bool
		radios int
	}{{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", false, 2}, {"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB", true, 1}} {
		ap := &APEntry{ModelID: 123, HardwareVersion: "1.0", HardwareID: "DEVICE-HW", FirmwareID: v.fw}
		db.ResolveCapabilities(ap)
		if len(ap.Capabilities) != v.radios || ap.Capabilities[len(ap.Capabilities)-1].SupportBE != v.be {
			t.Fatal("wrong firmware variant", ap)
		}
		if !v.be && (ap.Capabilities[0].Band != "2.4 GHz" || ap.Capabilities[1].TxStreams != 2 || !ap.Capabilities[1].SupportWPA3 || !ap.Capabilities[1].Support80P80 || ap.Capabilities[1].FunctionType != 1 || len(ap.Capabilities[1].Channels) != 2) {
			t.Fatal("lost negotiated metadata", ap.Capabilities)
		}
	}
	for _, ap := range []*APEntry{{ModelID: 123, HardwareVersion: "1.0", FirmwareID: "unknown"}, {ModelID: 123, HardwareVersion: "2.0", FirmwareID: "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"}, {ModelID: 123, HardwareVersion: "1.0", HardwareID: "different-hw", FirmwareID: "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"}} {
		db.ResolveCapabilities(ap)
		if len(ap.Capabilities) > 0 {
			t.Fatal("borrowed incompatible cache", ap)
		}
	}
	reported := &APEntry{ModelID: 123, FirmwareID: "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB", Capabilities: []RadioCapability{{RadioID: 1, Source: "ap-report", MaxSSID: 3}}}
	db.ResolveCapabilities(reported)
	if reported.Capabilities[0].Source != "ap-report" || reported.Capabilities[0].MaxSSID != 3 {
		t.Fatal("cache replaced current AP report")
	}
}
