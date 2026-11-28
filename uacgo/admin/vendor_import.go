package admin

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"net"
	"os"
	"path"
	"path/filepath"
	"sort"
	"strconv"
	"strings"
	"uacgo/cweng"
	"uacgo/vendorbackup"
)

// VendorConversion is an offline result. Conversion never changes a running
// controller, loads an AC system backup, or provisions a network interface.
type VendorConversion struct {
	Config Config
	Report VendorImportReport
	APDB   json.RawMessage // original negotiated model database, without credentials
}

type VendorImportReport struct {
	Product             string                `json:"source_product"`
	ConfigFormatVersion string                `json:"source_config_format_version,omitempty"`
	Model               string                `json:"source_model,omitempty"`
	HardwareVersion     string                `json:"source_hardware_version,omitempty"`
	PolicyReference     string                `json:"roaming_mode_reference,omitempty"`
	SourceMode          int                   `json:"source_network_mode"`
	TargetMode          int                   `json:"target_network_mode"`
	Counts              map[string]int        `json:"converted_counts"`
	Tables              []VendorTableReport   `json:"tables"`
	Warnings            []string              `json:"warnings"`
	Excluded            []string              `json:"excluded"`
	UCI                 map[string][]string   `json:"uci_fields"`
	Inventory           []VendorDatabaseTable `json:"database_inventory"`
}

type VendorDatabaseTable struct {
	Database string   `json:"database"`
	Table    string   `json:"table"`
	Rows     int      `json:"rows"`
	Scope    string   `json:"scope"`
	Columns  []string `json:"columns"`
}

type VendorTableReport struct {
	Database    string   `json:"database"`
	Table       string   `json:"table"`
	Rows        int      `json:"rows"`
	Mapped      []string `json:"mapped_columns"`
	Excluded    []string `json:"excluded_columns"`
	Unknown     []string `json:"unhandled_columns"`
	Unexercised []string `json:"empty_table_columns"`
}

type vendorRow struct {
	data map[string]string
	used map[string]bool
}

func (r vendorRow) s(key string) string { r.used[key] = true; return r.data[key] }
func (r vendorRow) n(key string) int    { n, _ := strconv.Atoi(r.s(key)); return n }
func (r vendorRow) on(key string) bool {
	v := strings.ToLower(r.s(key))
	return v == "on" || v == "enable" || v == "1" || v == "true"
}
func (r vendorRow) has(key string) bool { _, ok := r.data[key]; return ok }

type vendorReader struct {
	archive *vendorbackup.Archive
	dir     string
	report  *VendorImportReport
}

// Read only named application tables. In particular auth_user.db also holds
// userNameTable; excluding that entire database would lose client aliases.
func (v vendorReader) table(database, table string, exclude []string, visit func(vendorRow) error) error {
	data, exists := v.archive.File("dbs/" + database)
	if !exists {
		return nil
	}
	file := filepath.Join(v.dir, database)
	if err := os.WriteFile(file, data, 0600); err != nil {
		return err
	}
	db, err := sql.Open("sqlite", "file:"+file+"?mode=ro&immutable=1")
	if err != nil {
		return err
	}
	defer db.Close()
	var found int
	if err := db.QueryRow("SELECT count(*) FROM sqlite_master WHERE type='table' AND name=?", table).Scan(&found); err != nil {
		return fmt.Errorf("%s: %w", database, err)
	}
	if found == 0 {
		return nil
	}
	rows, err := db.Query(`SELECT * FROM "` + table + `"`)
	if err != nil {
		return err
	}
	defer rows.Close()
	columns, err := rows.Columns()
	if err != nil {
		return err
	}
	report := VendorTableReport{Database: database, Table: table}
	used := map[string]bool{}
	for rows.Next() {
		values, dest := make([]any, len(columns)), make([]any, len(columns))
		for i := range dest {
			dest[i] = &values[i]
		}
		if err := rows.Scan(dest...); err != nil {
			return err
		}
		r := vendorRow{map[string]string{}, used}
		for i, c := range columns {
			switch x := values[i].(type) {
			case nil:
				r.data[c] = ""
			case []byte:
				r.data[c] = string(x)
			default:
				r.data[c] = fmt.Sprint(x)
			}
		}
		if err := visit(r); err != nil {
			return fmt.Errorf("%s/%s row %d: %w", database, table, report.Rows+1, err)
		}
		report.Rows++
	}
	if err := rows.Err(); err != nil {
		return err
	}
	for _, c := range columns {
		if c == "seq" || c == "priv_key" || c == "key" && table != "wserv_tbl" || hasString(exclude, c) {
			report.Excluded = append(report.Excluded, c)
		} else if report.Rows == 0 {
			report.Unexercised = append(report.Unexercised, c)
		} else if used[c] {
			report.Mapped = append(report.Mapped, c)
		} else {
			report.Unknown = append(report.Unknown, c)
		}
	}
	v.report.Tables = append(v.report.Tables, report)
	return nil
}

func vendorMAC(raw string) (string, error) {
	raw = strings.ReplaceAll(strings.TrimSpace(raw), "-", ":")
	m, err := net.ParseMAC(raw)
	if err != nil || len(m) != 6 || m[0]&1 != 0 || m.String() == "00:00:00:00:00:00" {
		return "", fmt.Errorf("invalid AP/client MAC")
	}
	return m.String(), nil
}
func importID(kind string, id int) string { return fmt.Sprintf("vendor-%s-%d", kind, id) }

// ConvertVendorBackup converts application configuration. Target mode is an
// explicit migration choice because V4 exports may select V6-Web-forbidden
// legacy modes. A negative value rejects such a change rather than hiding it.
func ConvertVendorBackup(input []byte, iface string, targetMode int) (*VendorConversion, error) {
	a, err := vendorbackup.Read(input)
	if err != nil {
		return nil, err
	}
	dir, err := os.MkdirTemp("", "go-ac-convert-")
	if err != nil {
		return nil, err
	}
	defer os.RemoveAll(dir)
	out := &VendorConversion{Report: VendorImportReport{Product: a.Product, Counts: map[string]int{}, UCI: map[string][]string{}}}
	// config.sh writes hardware ID, cfg_info.settings.version, model, HW
	// version. The second field is the configuration format, not the firmware
	// release; the latter is not present in this export header.
	if fields := strings.Fields(a.Product); len(fields) == 4 {
		out.Report.ConfigFormatVersion = fields[1]
		out.Report.Model = fields[2]
		out.Report.HardwareVersion = fields[3]
	}
	rd := vendorReader{a, dir, &out.Report}
	cfg := &out.Config
	cfg.Interface = iface
	cfg.APDefaults = standaloneAPDefaults()
	cfg.ClientLabels = map[string]ClientLabel{}
	aps, groups := map[int]string{}, map[int]string{}
	modelIDs, hardware := map[string]uint32{}, map[string]string{}
	if err := rd.table("apmngr.db", "Group_table", nil, func(r vendorRow) error {
		id := r.n("group_id")
		groups[id] = importID("group", id)
		cfg.Groups = append(cfg.Groups, APGroup{ID: groups[id], Name: r.s("name")})
		return nil
	}); err != nil {
		return nil, err
	}
	if err := rd.table("apmngr.db", "ApEntryCfg_table", []string{"ap_role", "cap_id", "hdap_peer_id", "bluetooth_enable", "cloud_config_id", "telnet_status", "firmware_id", "ssid_mlo_support"}, func(r vendorRow) error {
		mac, err := vendorMAC(r.s("mac"))
		if err != nil {
			return err
		}
		aps[r.n("entry_id")] = mac
		modelIDs[mac], hardware[mac] = uint32(r.n("model_id")), r.s("hardware_ver")
		p := APProfile{AP: mac, Name: r.s("entry_name"), Group: groups[r.n("group_id")]}
		o := &p.Options
		// ap_keep_alive is encoded as echo interval, independently from
		// client keepalive and idle. Preserve absence separately from zero.
		if r.has("ap_keep_alive") {
			n := uint8(r.n("ap_keep_alive"))
			o.EchoSeconds = &n
		}
		if r.has("client_keep_alive") {
			n := uint32(r.n("client_keep_alive"))
			o.ClientKeepAlive = &n
		}
		if r.has("client_idle") {
			n := uint32(r.n("client_idle"))
			o.ClientIdle = &n
		}
		for key, dst := range map[string]**bool{"offline_selfmanage": &o.OfflineSelfManage, "led": &o.LED, "led_wifi_sync": &o.LEDWiFiSync, "ap_trunk": &o.Trunk, "fit_fat_button_status": &o.FitFatButton, "ap_mesh_switch": &o.Mesh} {
			if r.has(key) && r.s(key) != "" && r.data[key] != "null" && r.data[key] != "255" && r.data[key] != "-1" {
				b := r.on(key)
				*dst = &b
			}
		}
		if r.has("new_ap_trunk") {
			value := r.n("new_ap_trunk")
			if value == 0 || value == 1 {
				b := value == 1
				o.Trunk = &b
			}
		}
		if r.has("region_code") && r.n("region_code") >= 0 && r.n("region_code") < 255 {
			n := uint8(r.n("region_code"))
			o.RegionCode = &n
		}
		user, password := r.s("account_username"), r.s("account_password")
		legacyUser, legacyPassword := r.s("username"), r.s("password")
		if password == "" {
			user, password = legacyUser, legacyPassword
		}
		if user != "" && password != "" {
			o.Account = &APAccount{Username: user, Password: password}
		}
		for i := 1; i <= 4; i++ {
			key := fmt.Sprintf("phy_wire_vlan_%d", i)
			if r.has(key) {
				n := r.n(key)
				if n > 0 && n <= 4094 {
					vlan := uint16(n)
					o.Ports = append(o.Ports, APPort{ID: uint8(i), VLAN: &vlan})
				}
			}
		}
		if r.on("led_timer_enable") {
			o.LEDSchedule, err = vendorLEDSchedule(r)
			if err != nil {
				return err
			}
		} else {
			for _, k := range []string{"led_close_date", "led_close_time", "led_open_date", "led_open_time"} {
				r.s(k)
			}
		}
		if r.has("lag_mode") {
			lag := &APLAG{Enabled: r.on("lag_mode")}
			r.n("lag_phy_num")
			for _, port := range strings.FieldsFunc(r.s("lag_phy_list"), func(c rune) bool { return c == ',' || c == ' ' }) {
				n, e := strconv.Atoi(port)
				if e != nil {
					return e
				}
				if n > 0 {
					lag.Ports = append(lag.Ports, uint8(n))
				}
			}
			if lag.Enabled || len(lag.Ports) > 0 {
				o.LAG = lag
			}
		}
		if r.has("radio_role_table_idx") && r.n("radio_role_table_idx") > 0 {
			o.RFMode = &APRFMode{Enabled: true, ID: uint8(r.n("radio_role_table_idx"))}
		}
		cfg.APProfiles = append(cfg.APProfiles, p)
		return nil
	}); err != nil {
		return nil, err
	}
	if len(aps) == 0 {
		return nil, fmt.Errorf("backup has no supported AP records")
	}
	if err := rd.table("rdmngr.db", "rdmngrTable", []string{"rf_name", "freq_band", "chLock", "pwrLock", "scanMode", "scanType", "scanIntvl", "chErrFrameRatio"}, func(r vendorRow) error {
		id := r.n("rf_id")
		ap, exists := aps[id>>4]
		if !exists {
			return fmt.Errorf("unknown AP for radio %d", id)
		}
		enabled, channel, level := r.on("rf_state"), r.n("channel"), r.n("power_level")
		setting := RadioSetting{AP: ap, Radio: uint8(id & 15), Enabled: &enabled, Channel: &channel, PowerLevel: &level}
		a := RadioAdvanced{Mode: r.n("mode"), Bandwidth: r.n("bandwidth"), MaxClients: r.n("max_usr"), Antenna: r.n("antenna"), Fragmentation: r.n("frag_thr"), RTS: r.n("rts_thr"), Beacon: r.n("bcn_intvl"), DTIM: r.n("dtim_prd"), ManagementRate: r.n("manage_frame_rate"), RSSIThreshold: r.n("rssi_restrict_val"), RSSIKickThreshold: r.n("rssi_kick_val"), GI: r.n("gi_mode")}
		for key, dst := range map[string]*bool{"wmm": &a.WMM, "short_gi": &a.ShortGI, "brd_probe": &a.BroadcastProbe, "rssi_restrict": &a.RSSIRestrict, "rssi_kick": &a.RSSIKick, "airtime": &a.Airtime, "downlink_mumimo": &a.DownlinkMUMIMO, "uplink_mumimo": &a.UplinkMUMIMO, "downlink_ofdma": &a.DownlinkOFDMA, "uplink_ofdma": &a.UplinkOFDMA, "twt": &a.TWT, "enable_6g": &a.Enable6G, "enable_6g_psc": &a.PSC6G} {
			*dst = r.on(key)
		}
		a.DCS = &DCSConfig{Mode: r.n("rf_chnl_dcs"), Reselect: r.on("rf_chnl_reselect"), Online: r.on("rf_online_switch"), Interval: r.n("rf_check_circle"), Occupancy: r.n("rf_chnl_occup_threshold"), Tolerance: r.n("rf_chnl_tolerance")}
		a.Reject = &AdmissionControl{Enabled: r.on("reject_enable"), Threshold: r.n("reject_limit"), Difference: r.n("reject_diff")}
		r.n("freq_band")
		if r.data["downlink_mumimo"] == "null" {
			a.DownlinkMUMIMO = a.Mode >= 10
		}
		if r.data["uplink_mumimo"] == "null" {
			a.UplinkMUMIMO = a.Mode >= 10
		}
		setting.Advanced = &a
		cfg.Radios = append(cfg.Radios, setting)
		return nil
	}); err != nil {
		return nil, err
	}
	services := map[int]int{}
	if err := rd.table("wserv.db", "wserv_tbl", []string{"radius_ip", "radius_port", "radius_acct_port", "radius_pwd", "ssid_id"}, func(r vendorRow) error {
		id, encryption := r.n("serv_id"), r.n("encryption")
		security := "open"
		switch encryption {
		case 0:
		case 1:
			switch r.n("auth") {
			case 1:
				security = "wpa-psk"
			case 2:
				security = "wpa2-psk"
			case 3:
				security = "wpa-wpa2-psk"
			default:
				return fmt.Errorf("unsupported PSK auth")
			}
		case 4:
			security = "wpa2-wpa3-psk"
		default:
			out.Report.Warnings = append(out.Report.Warnings, fmt.Sprintf("无线服务%d使用不在产品范围内的认证类型%d，未转换，也未降级成开放网络", id, encryption))
			return nil
		}
		s := Service{ID: importID("service", id), SSID: r.s("ssid"), Enabled: r.on("enable"), Hidden: !r.on("ssidbrd"), Security: security, Passphrase: r.s("key"), Radios: RadioList{1, 2}}
		o := WirelessOptions{Description: r.s("desc"), Encoding: "utf-8", Isolate: r.on("isolate"), VLAN: r.n("default_bind_vlan"), Auth: r.n("auth"), Cipher: r.n("cipher"), KeyUpdate: r.n("key_update_intv"), MLO: r.on("mlo_switch")}
		if r.n("ssid_code_type") == 0 {
			o.Encoding = "gbk"
		}
		mode := "client"
		if r.n("bw_ctrl_mode") == 0 {
			mode = "ssid"
		}
		o.RateLimit = &WirelessRateLimit{Enabled: r.on("bw_ctrl_enable"), Mode: mode, Upload: r.n("up_limit") * 8, Download: r.n("down_limit") * 8}
		o.Multicast = &MulticastOptions{ConfigureGlobal: true, GlobalSnooping: r.on("igmp_snooping_enable"), Snooping: r.on("igmp_snooping_switch"), Query: r.on("igmp_query_switch"), DropUnknown: r.on("igmp_drop_unknown"), Rate2G: r.n("igmp_2g_rate"), Rate5G: r.n("igmp_5g_rate"), RateType2G: r.n("igmp_2g_rate_type"), RateType5G: r.n("igmp_5g_rate_type"), QueryInterval: r.n("igmp_query_interval"), MaxResponse: r.n("igmp_max_resp_time")}
		mask := uint16(r.n("default_bind_freq"))
		if r.on("auto_bind") {
			s.AutoBindFrequencies = &mask
		}
		s.Options = &o
		services[id] = len(cfg.Services)
		cfg.Services = append(cfg.Services, s)
		return nil
	}); err != nil {
		return nil, err
	}
	if err := rd.table("wserv_rd.db", "bind_tbl", nil, func(r vendorRow) error {
		id := r.n("radio_id")
		ap, exists := aps[id>>4]
		if !exists {
			return fmt.Errorf("unknown binding AP")
		}
		for i := 1; i <= 16; i++ {
			key := fmt.Sprintf("wserv%d", i)
			if !r.has(key) {
				continue
			}
			service, vlan := r.n(key), r.n(fmt.Sprintf("vlan%d", i))
			index, ok := services[service]
			if !ok || service < 0 {
				continue
			}
			s := &cfg.Services[index]
			s.Bindings = append(s.Bindings, ServiceBinding{AP: ap, Radio: uint8(id & 15), VLAN: vlan})
			if s.AutoBindFrequencies == nil && !hasString(s.APs, ap) {
				s.APs = append(s.APs, ap)
			}
		}
		return nil
	}); err != nil {
		return nil, err
	}
	for i := range cfg.Services {
		s := &cfg.Services[i]
		if s.AutoBindFrequencies != nil {
			// Redundant rows from wserv_rd are the result of automatic
			// binding, not an allowlist for all future APs. Keeping them
			// as an explicit allowlist would stop new APs being bound.
			for _, b := range s.Bindings {
				if b.VLAN != serviceOptions(*s).VLAN {
					return nil, fmt.Errorf("service %s has automatic binding with per-AP VLAN overrides; cannot convert to an explicit-only binding model without changing future AP behavior", s.ID)
				}
			}
			s.Bindings = nil
		}
		// An unbound, non-auto service stays disabled until explicitly bound.
		if cfg.Services[i].AutoBindFrequencies == nil && len(cfg.Services[i].Bindings) == 0 {
			cfg.Services[i].Enabled = false
		}
	}
	if err := rd.table("auth_user.db", "userNameTable", nil, func(r vendorRow) error {
		mac, err := vendorMAC(r.s("mac"))
		if err != nil {
			return err
		}
		cfg.ClientLabels[mac] = ClientLabel{Name: r.s("name")}
		return nil
	}); err != nil {
		return nil, err
	}
	if err := rd.table("wserv_ip.db", "igmp_ip_tbl", nil, func(r vendorRow) error {
		r.n("id")
		cfg.MulticastGroups = append(cfg.MulticastGroups, MulticastGroup{IP: r.s("ip_addr"), Enabled: r.on("enable"), Relay: r.on("relay")})
		return nil
	}); err != nil {
		return nil, err
	}
	if err := convertVendorGlobals(a, cfg, &out.Report, targetMode); err != nil {
		return nil, err
	}
	if err := convertVendorProtection(rd, cfg, aps); err != nil {
		return nil, err
	}
	if raw, ok := a.File("dbs/apdb_nego.db"); ok {
		out.APDB = json.RawMessage(raw)
	}
	if err := compileVendorTemplates(cfg, modelIDs, hardware, out.APDB); err != nil {
		return nil, err
	}
	if err := rd.inventory(); err != nil {
		return nil, err
	}
	for module, sections := range a.UCI {
		keys := map[string]bool{}
		for _, s := range sections {
			for key := range s.Values {
				keys[key] = true
			}
		}
		for key := range keys {
			out.Report.UCI[module] = append(out.Report.UCI[module], key)
		}
		sort.Strings(out.Report.UCI[module])
	}
	out.Report.Excluded = []string{"AC Linux的接口/IP/路由/NAT/DNS/DHCP服务器/静态租约/管理VLAN/管理员/证书/日志/云管理", "RADIUS、Portal、用户认证、蓝牙；auth_user.db仅取userNameTable客户端名称", "AP固件哈希、历史在线状态和数据库内部序号不是要下发的配置"}
	out.Report.Counts = map[string]int{"aps": len(cfg.APProfiles), "templates": len(cfg.Templates), "groups": len(cfg.Groups), "radios": len(cfg.Radios), "services": len(cfg.Services), "client_names": len(cfg.ClientLabels), "multicast_groups": len(cfg.MulticastGroups)}
	for _, t := range out.Report.Tables {
		if len(t.Unknown) > 0 {
			out.Report.Warnings = append(out.Report.Warnings, fmt.Sprintf("待核对列 %s/%s: %s", t.Database, t.Table, strings.Join(t.Unknown, ", ")))
		}
	}
	if err := validateConfig(*cfg); err != nil {
		return nil, fmt.Errorf("converted configuration validation: %w", err)
	}
	return out, nil
}

func (v vendorReader) inventory() error {
	converted := map[string]bool{}
	for _, t := range v.report.Tables {
		converted[t.Database+"/"+t.Table] = true
	}
	var names []string
	for name := range v.archive.Files {
		if strings.Contains(name, "/dbs/") && strings.HasSuffix(name, ".db") {
			names = append(names, name)
		}
	}
	sort.Strings(names)
	for _, name := range names {
		data := v.archive.Files[name]
		if !strings.HasPrefix(string(data), "SQLite format 3\x00") {
			continue
		}
		base := path.Base(name)
		file := filepath.Join(v.dir, base)
		if err := os.WriteFile(file, data, 0600); err != nil {
			return err
		}
		db, err := sql.Open("sqlite", "file:"+file+"?mode=ro&immutable=1")
		if err != nil {
			return err
		}
		rows, err := db.Query("SELECT name FROM sqlite_master WHERE type='table' AND name NOT LIKE 'sqlite_%' ORDER BY name")
		if err != nil {
			db.Close()
			return err
		}
		var tables []string
		for rows.Next() {
			var table string
			if err := rows.Scan(&table); err != nil {
				rows.Close()
				db.Close()
				return err
			}
			tables = append(tables, table)
		}
		err = rows.Err()
		rows.Close()
		if err != nil {
			db.Close()
			return err
		}
		for _, table := range tables {
			quoted := `"` + strings.ReplaceAll(table, `"`, `""`) + `"`
			t := VendorDatabaseTable{Database: base, Table: table, Scope: "needs-review"}
			if err := db.QueryRow("SELECT count(*) FROM " + quoted).Scan(&t.Rows); err != nil {
				db.Close()
				return err
			}
			columns, err := db.Query("SELECT * FROM " + quoted + " LIMIT 0")
			if err != nil {
				db.Close()
				return err
			}
			t.Columns, err = columns.Columns()
			columns.Close()
			if err != nil {
				db.Close()
				return err
			}
			if converted[base+"/"+table] {
				t.Scope = "application-converted"
			} else {
				switch base {
				case "auth_user.db", "auth_server.db", "mac_auth.db", "portal.db", "ssl_vpn_user.db":
					t.Scope = "excluded-authentication"
				case "dhcp_host.db", "dhcp6_host.db":
					t.Scope = "excluded-ac-linux-dhcp"
				case "sensor.db":
					t.Scope = "excluded-network-operations"
				default:
					if t.Rows == 0 {
						t.Scope = "empty-application-table"
					}
				}
			}
			if t.Scope == "needs-review" && t.Rows > 0 {
				db.Close()
				return fmt.Errorf("unconverted nonempty application table %s/%s (%d rows)", base, table, t.Rows)
			}
			v.report.Inventory = append(v.report.Inventory, t)
		}
		db.Close()
	}
	return nil
}

// Vendor DB rows include preferences for capabilities the AP does not have.
// Reuse the normal model-template layer to retain those preferences while
// applying the same capability projection as existing inherited settings.
// Physical channel/power/state stay explicit AP rows. Later user edits remain
// strict AP overrides; importing does not weaken any runtime validation.
func compileVendorTemplates(cfg *Config, modelIDs map[string]uint32, hardware map[string]string, raw json.RawMessage) error {
	var cache struct {
		Items []cweng.NegotiatedModel `json:"ap_item_list"`
	}
	if len(raw) > 0 {
		if err := json.Unmarshal(raw, &cache); err != nil {
			return err
		}
	}
	names := map[uint32]string{}
	for _, m := range cache.Items {
		names[uint32(m.ID)] = m.APName
	}
	identities := map[string]string{}
	for i := range cfg.APProfiles {
		p := &cfg.APProfiles[i]
		options := p.Options
		for n := range cfg.Radios {
			r := &cfg.Radios[n]
			if r.AP != p.AP {
				continue
			}
			options.Radios = append(options.Radios, RadioSetting{Radio: r.Radio, Advanced: r.Advanced})
			r.Advanced = nil
		}
		model := names[modelIDs[p.AP]]
		key, err := json.Marshal(struct {
			Model, Hardware string
			Options         APOptions
		}{model, hardware[p.AP], options})
		if err != nil {
			return err
		}
		id, ok := identities[string(key)]
		if !ok {
			id = importID("template", len(cfg.Templates)+1)
			identities[string(key)] = id
			cfg.Templates = append(cfg.Templates, APTemplate{ID: id, Name: fmt.Sprintf("原AC配置 %d", len(cfg.Templates)+1), Model: model, Hardware: hardware[p.AP], Options: options})
		}
		p.Template = id
		p.Options = APOptions{}
	}
	return nil
}
