package admin

import (
	"archive/tar"
	"bytes"
	"compress/gzip"
	"crypto/des"
	"crypto/md5"
	"database/sql"
	"encoding/hex"
	"encoding/json"
	"net/http/httptest"
	"os"
	"path/filepath"
	"testing"
	"uacgo/cweng"
)

func vendorTestTar(t *testing.T, files map[string][]byte) []byte {
	t.Helper()
	var b bytes.Buffer
	z := gzip.NewWriter(&b)
	w := tar.NewWriter(z)
	for name, data := range files {
		if err := w.WriteHeader(&tar.Header{Name: name, Mode: 0600, Size: int64(len(data))}); err != nil {
			t.Fatal(err)
		}
		if _, err := w.Write(data); err != nil {
			t.Fatal(err)
		}
	}
	if err := w.Close(); err != nil {
		t.Fatal(err)
	}
	if err := z.Close(); err != nil {
		t.Fatal(err)
	}
	return b.Bytes()
}

func vendorTestDatabase(t *testing.T, schema string) []byte {
	t.Helper()
	p := filepath.Join(t.TempDir(), "source.db")
	db, err := sql.Open("sqlite", p)
	if err != nil {
		t.Fatal(err)
	}
	if _, err := db.Exec(schema); err != nil {
		db.Close()
		t.Fatal(err)
	}
	if err := db.Close(); err != nil {
		t.Fatal(err)
	}
	b, err := os.ReadFile(p)
	if err != nil {
		t.Fatal(err)
	}
	return b
}

func vendorTestExport(t *testing.T, mode int, modeOptions ...string) []byte {
	t.Helper()
	// All identities, credentials and database rows below are synthetic.
	// Do not replace them with an export from a deployed controller.
	app := map[string][]byte{
		"apmngr.db": vendorTestDatabase(t, `CREATE TABLE Group_table(group_id INTEGER,name TEXT); INSERT INTO Group_table VALUES(0,'Example group');
CREATE TABLE ApEntryCfg_table(entry_id INTEGER,group_id INTEGER,mac TEXT,entry_name TEXT,ap_keep_alive INTEGER,client_keep_alive INTEGER,client_idle INTEGER,offline_selfmanage TEXT,ap_trunk INTEGER,new_ap_trunk INTEGER,region_code INTEGER,radio_role_table_idx INTEGER,phy_wire_vlan_1 INTEGER,username TEXT,password TEXT);
INSERT INTO ApEntryCfg_table VALUES(1,0,'02-00-00-00-00-01','Example AP',30,300,3600,'on',-1,255,255,0,0,'admin','Example123');`),
		"rdmngr.db": vendorTestDatabase(t, `CREATE TABLE rdmngrTable(rf_id INTEGER,freq_band INTEGER,mode INTEGER,bandwidth INTEGER,channel INTEGER,power_level INTEGER,max_usr INTEGER,antenna INTEGER,frag_thr INTEGER,rts_thr INTEGER,bcn_intvl INTEGER,dtim_prd INTEGER,manage_frame_rate INTEGER,wmm TEXT,rf_state TEXT,gi_mode INTEGER,rf_check_circle INTEGER,rf_chnl_occup_threshold INTEGER,rf_chnl_tolerance INTEGER,reject_limit INTEGER,reject_diff INTEGER);
INSERT INTO rdmngrTable VALUES(17,0,6,2,6,6,100,0,2346,2346,100,1,11,'on','on',-1,8,50,20,-60,6);`),
		"wserv.db": vendorTestDatabase(t, `CREATE TABLE wserv_tbl(serv_id INTEGER,encryption INTEGER,auth INTEGER,cipher INTEGER,key_update_intv INTEGER,ssid TEXT,ssid_code_type INTEGER,key TEXT,enable TEXT,ssidbrd INTEGER,desc TEXT,isolate INTEGER,default_bind_vlan INTEGER,auto_bind TEXT,default_bind_freq INTEGER,bw_ctrl_enable INTEGER,bw_ctrl_mode INTEGER,up_limit INTEGER,down_limit INTEGER,igmp_snooping_enable TEXT,igmp_snooping_switch TEXT,igmp_query_switch TEXT,igmp_2g_rate INTEGER,igmp_5g_rate INTEGER,igmp_query_interval INTEGER,igmp_max_resp_time INTEGER);
INSERT INTO wserv_tbl VALUES(0,4,3,2,86400,'Example中文',1,'Example123','on',1,'test',0,200,'on',257,1,0,256,2560,'on','on','off',1,6,60,10);
INSERT INTO wserv_tbl VALUES(3,1,2,2,86400,'Specific',1,'Example456','on',1,'test',0,0,'off',771,0,1,0,0,'on','on','off',1,6,60,10);`),
		"wserv_rd.db":  vendorTestDatabase(t, `CREATE TABLE bind_tbl(radio_id INTEGER,wserv1 INTEGER,vlan1 INTEGER,wserv2 INTEGER,vlan2 INTEGER);INSERT INTO bind_tbl VALUES(17,3,0,0,200);`),
		"auth_user.db": vendorTestDatabase(t, `CREATE TABLE userNameTable(name TEXT,mac TEXT,key INTEGER);INSERT INTO userNameTable VALUES('Example tablet','02-11-22-33-44-55',1);CREATE TABLE authUserTable(username TEXT,password TEXT);INSERT INTO authUserTable VALUES('EXCLUDED-ACCOUNT','EXCLUDED-PASSWORD');`),
	}
	var files = map[string][]byte{}
	for n, b := range app {
		files["tmp/etc/userconfig/dbs/"+n] = b
		sum := md5.Sum(b)
		files["tmp/etc/userconfig/dbs.md5/"+n+".md5"] = []byte(hex.EncodeToString(sum[:]) + "\n")
	}
	uci := map[string][]byte{"tmp/backup/uc_conf/apmng_roam": []byte("config global 'roam'\noption 11k_switch 'on'\noption 11v_switch 'on'\noption 11r_switch 'on'\nconfig global 'wireless_network_mode'\noption wireless_network_mode '" + string(rune('0'+mode)) + "'\n"), "tmp/backup/uc_conf/apmng_set": []byte("config global 'settings'\noption auto_firm 'on'\n")}
	for _, option := range modeOptions {
		uci["tmp/backup/uc_conf/apmng_roam"] = append(uci["tmp/backup/uc_conf/apmng_roam"], []byte(option+"\n")...)
	}
	inner := vendorTestTar(t, map[string][]byte{"tmp/cfg_save/backconf_tmp/backup/uc_conf.tar.gz": vendorTestTar(t, uci), "tmp/cfg_save/backconf_tmp/backup/non_uci.tar.gz": vendorTestTar(t, files)})
	sum := md5.Sum(inner)
	plain := vendorTestTar(t, map[string][]byte{"tmp/cfg_save/backconf_tmp/product_name_conf": []byte("example-product 2.0.2 TL-AC100 4.0"), "tmp/cfg_save/backconf_tmp/md5_sum_conf": []byte(hex.EncodeToString(sum[:]) + "\n"), "tmp/cfg_save/backconf_tmp/tmp_conf.tar.gz": inner})
	digest := md5.Sum(plain)
	envelope := append(digest[:], plain...)
	padding := 8 - len(envelope)%8
	envelope = append(envelope, bytes.Repeat([]byte{byte(padding)}, padding)...)
	block, _ := des.NewCipher([]byte{0x47, 0x8d, 0xa5, 0x0b, 0xf9, 0xe3, 0xd2, 0xcf})
	encrypted := make([]byte, len(envelope))
	for i := 0; i < len(envelope); i += 8 {
		block.Encrypt(encrypted[i:i+8], envelope[i:i+8])
	}
	return encrypted
}

func TestVendorConversionKeepsBindingsNamesAndWireUnits(t *testing.T) {
	converted, err := ConvertVendorBackup(vendorTestExport(t, 2), "", -1)
	if err != nil {
		t.Fatal(err)
	}
	cfg := converted.Config
	if r := converted.Report; r.ConfigFormatVersion != "2.0.2" || r.Model != "TL-AC100" || r.HardwareVersion != "4.0" {
		t.Fatal("configuration format must not be interpreted as software release", r.Product)
	}
	if len(cfg.APProfiles) != 1 || len(cfg.Radios) != 1 || len(cfg.Services) != 2 || len(cfg.ClientLabels) != 1 {
		t.Fatal(converted.Report.Counts)
	}
	if cfg.ClientLabels["02:11:22:33:44:55"].Name != "Example tablet" {
		t.Fatal("lost aliases from authentication database")
	}
	b, _ := json.Marshal(cfg)
	if bytes.Contains(b, []byte("EXCLUDED-")) {
		t.Fatal("imported excluded authentication credentials")
	}
	p := cfg.APProfiles[0].Options
	if p.Trunk != nil || p.RegionCode != nil || p.RFMode != nil || len(p.Ports) != 0 {
		t.Fatal("unset sentinels became explicit commands", p)
	}
	s := cfg.Services[0]
	if s.ID != "vendor-service-0" || s.Security != "wpa2-wpa3-psk" || s.Options.Encoding != "utf-8" || s.Options.VLAN != 200 || s.AutoBindFrequencies == nil || *s.AutoBindFrequencies != 257 {
		t.Fatal("lost service zero/security/frequency", s.ID)
	}
	l := s.Options.RateLimit
	if !l.Enabled || l.Mode != "ssid" || l.Upload != 2048 || l.Download != 20480 {
		t.Fatal("changed DB rate units/mode", l)
	}
	ap := "02:00:00:00:00:01"
	if ok, vlan := binding(s, ap, 1); !ok || vlan != 200 {
		t.Fatal("lost tagged binding")
	}
	if ok, vlan := binding(cfg.Services[1], ap, 1); !ok || vlan != 0 {
		t.Fatal("lost untagged binding")
	}
	if len(s.Bindings) != 0 {
		t.Fatal("auto-bind results became a future AP allowlist")
	}
	if ok, vlan := binding(s, "02:00:00:00:00:99", 1); !ok || vlan != 200 {
		t.Fatal("auto binding no longer applies to new APs")
	}
	if cfg.Services[1].APs[0] != ap || cfg.Services[1].AutoBindFrequencies != nil {
		t.Fatal("manual service became automatic")
	}
	if converted.Report.PolicyReference == "" || cfg.Mobility.ModeSource != v4ModeSource || len(converted.Report.Warnings) != 1 {
		t.Fatal(converted.Report.Warnings)
	}
	if len(cfg.Templates) != 1 || cfg.Templates[0].Options.Radios[0].Advanced.DCS == nil {
		t.Fatal("lost stored optional preferences")
	}
	// An ordinary AP with no DCS/reject capabilities must still be manageable.
	// The vendor's disabled generic columns are retained in the template,
	// projected by the existing capability layer, not forced into commands.
	apStatus := cweng.APStatus{ID: ap, Radios: 1, GeneralCapabilities: []uint32{0, 1 << 25}, Capabilities: []cweng.RadioCapability{{RadioID: 1, Band: "2.4 GHz", MaxSSID: 8, MaxClients: 100, MinPower: 5, MaxPower: 20, Modes: []int{6}, Bandwidths: []int{0, 1, 2}, Channels: []int{1, 6, 11}}}}
	o, err := effectiveAPOptions(cfg, apStatus)
	if err != nil {
		t.Fatal(err)
	}
	if _, err := managementElements(o, apStatus); err != nil {
		t.Fatal("model-aware management failed", err)
	}
	for _, radio := range effectiveRadioConfig(cfg, apStatus).Radios {
		if err := validateKnownRadio(radio, apStatus); err != nil {
			t.Fatal("model-aware RF failed", err)
		}
	}
	for _, report := range converted.Report.Tables {
		if len(report.Unknown) > 0 {
			t.Fatal("unreviewed columns", report)
		}
	}
	// Exercise the actual Go restore handler, including its shared validators.
	m, _ := testController(t)
	payload, _ := json.Marshal(map[string]any{"format": "go-ac-configuration", "schema": 1, "config": cfg})
	response := httptest.NewRecorder()
	m.restoreHTTP(response, httptest.NewRequest("POST", "/api/restore", bytes.NewReader(payload)))
	if response.Code != 202 {
		t.Fatal(response.Code, response.Body.String())
	}
	if len(m.config.ClientLabels) != 1 || len(m.config.Services) != 2 {
		t.Fatal("restore lost imported application state")
	}
}

func TestVendorConversionNeverSilentlyChangesLegacyMode(t *testing.T) {
	backup := vendorTestExport(t, 1)
	preserved, err := ConvertVendorBackup(backup, "", -1)
	if err != nil || preserved.Report.SourceMode != 1 || preserved.Report.TargetMode != 1 || preserved.Config.Mobility.ModeSource != v4ModeSource {
		t.Fatal("V4 fixed high-performance policy not preserved", err)
	}
	auto, err := ConvertVendorBackup(vendorTestExport(t, 0), "", -1)
	if err != nil || auto.Report.TargetMode != 0 || auto.Config.Mobility.CurrentMode != 1 || auto.Config.Mobility.ModeSource != v4ModeSource {
		t.Fatal("automatic mode not preserved", err)
	}
	sticky, err := ConvertVendorBackup(vendorTestExport(t, 0, "option cur_wireless_network_mode '2'"), "", -1)
	if err != nil || sticky.Config.Mobility.CurrentMode != 2 {
		t.Fatal("import promoted an automatic controller already in compatibility mode", err)
	}
	got, err := ConvertVendorBackup(backup, "", 2)
	if err != nil {
		t.Fatal(err)
	}
	if got.Report.SourceMode != 1 || got.Report.TargetMode != 2 || got.Config.Mobility.ModeSource != v4ModeSource || len(got.Report.Warnings) != 2 {
		t.Fatal(got.Report)
	}
	if !got.Config.Mobility.Default.R || !got.Config.Mobility.Default.K || !got.Config.Mobility.Default.V {
		t.Fatal("mode choice discarded independent roaming settings")
	}
}
