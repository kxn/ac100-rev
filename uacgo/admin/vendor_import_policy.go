package admin

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
	"uacgo/mobility"
	"uacgo/vendorbackup"
)

func vendorSection(a *vendorbackup.Archive, module, name string) vendorbackup.Section {
	for _, s := range a.UCI[module] {
		if s.Name == name {
			return s
		}
	}
	return vendorbackup.Section{Values: map[string][]string{}}
}
func uciInt(s vendorbackup.Section, key string, fallback int) int {
	v := s.Value(key)
	if v == "" {
		return fallback
	}
	n, err := strconv.Atoi(v)
	if err != nil {
		return fallback
	}
	return n
}
func uciOn(s vendorbackup.Section, key string, fallback bool) bool {
	v := s.Value(key)
	if v == "" {
		return fallback
	}
	return v == "on" || v == "1" || v == "true"
}
func uciInts(s vendorbackup.Section, key string) []int {
	var out []int
	for _, v := range s.Values[key] {
		for _, part := range strings.FieldsFunc(v, func(r rune) bool { return r == ',' || r == ' ' }) {
			if n, err := strconv.Atoi(part); err == nil {
				out = append(out, n)
			}
		}
	}
	return out
}
func vendorDays(s string) (uint8, error) {
	if s == "eve" {
		return 127, nil
	}
	days := []string{"mon", "tue", "wed", "thu", "fri", "sat", "sun"}
	for i, v := range days {
		if s == v {
			return 1 << i, nil
		}
	}
	return 0, fmt.Errorf("unsupported weekly day")
}
func vendorMinute(s string) (int, error) {
	parts := strings.Split(s, ":")
	if len(parts) < 2 {
		return 0, fmt.Errorf("invalid schedule time")
	}
	h, e := strconv.Atoi(parts[0])
	m, f := strconv.Atoi(parts[1])
	if e != nil || f != nil || h < 0 || h > 23 || m < 0 || m > 59 {
		return 0, fmt.Errorf("invalid schedule time")
	}
	return h*60 + m, nil
}
func vendorLEDSchedule(r vendorRow) (*ServiceSchedule, error) {
	days, e := vendorDays(r.s("led_close_date"))
	if e != nil {
		return nil, e
	}
	open, e := vendorDays(r.s("led_open_date"))
	if e != nil {
		return nil, e
	}
	start, e := vendorMinute(r.s("led_close_time"))
	if e != nil {
		return nil, e
	}
	end, e := vendorMinute(r.s("led_open_time"))
	if e != nil {
		return nil, e
	}
	if days != open {
		return nil, fmt.Errorf("LED weekly endpoints differ; cannot collapse to a daily window")
	}
	return &ServiceSchedule{Enabled: true, Timezone: "Asia/Shanghai", Action: "off", Windows: []WeeklyWindow{{Days: days, Start: start, End: end}}}, nil
}

func convertVendorGlobals(a *vendorbackup.Archive, cfg *Config, report *VendorImportReport, targetMode int) error {
	p := defaultMobility()
	s := vendorSection(a, "apmng_roam", "roam")
	r := &p.Default
	r.K = uciOn(s, "11k_switch", r.K)
	r.V = uciOn(s, "11v_switch", r.V)
	r.R = uciOn(s, "11r_switch", r.R)
	for _, band := range []struct {
		prefix string
		out    *RoamBand
	}{{"2g", &r.Band2G}, {"5g", &r.Band5G}} {
		v := band.out
		k := band.prefix + "_"
		types := s.Values[k+"roaming_threshold_type"]
		if len(types) > 0 {
			v.Type = 0
			for _, t := range types {
				switch t {
				case "rssi":
					v.Type |= 1
				case "rate":
					v.Type |= 2
				default:
					return fmt.Errorf("unsupported roaming threshold type")
				}
			}
		}
		v.RSSI = uciInt(s, k+"rssi_trigger_threshold", v.RSSI)
		v.RSSIKick = uciOn(s, k+"low_rssi_kick", v.RSSIKick)
		v.RSSIKickThreshold = uciInt(s, k+"low_rssi_threshold", v.RSSIKickThreshold)
		v.Rate = uciInt(s, k+"rate_trigger_threshold", v.Rate)
		v.RateKick = uciOn(s, k+"low_rate_kick", v.RateKick)
		v.RateKickThreshold = uciInt(s, k+"low_rate_threshold", v.RateKickThreshold)
	}
	r.CheckInterval = uciInt(s, "threshold_check_interval", r.CheckInterval)
	r.Difference = uciInt(s, "roaming_dif", r.Difference)
	r.BlacklistTime = uciInt(s, "blacklist_restrict_time", r.BlacklistTime)
	r.HighPerformanceRSSI = uciInt(s, "rssi_trigger_threshold_high_performance", r.HighPerformanceRSSI)
	r.Statistics = uciOn(s, "stats_switch", false)
	r.StatisticsInterval = uciInt(s, "stats_interval", r.StatisticsInterval)
	mode := vendorSection(a, "apmng_roam", "wireless_network_mode")
	sourceMode := uciInt(mode, "wireless_network_mode", 2)
	report.SourceMode = sourceMode
	if targetMode < 0 {
		targetMode = sourceMode
	}
	if targetMode < 0 || targetMode > 2 {
		return fmt.Errorf("invalid target network mode %d: expected0,1,2", targetMode)
	}
	if sourceMode != targetMode {
		report.Warnings = append(report.Warnings, fmt.Sprintf("显式迁移模式%d→%d：旧高性能/自动模式的共同信道ACS和模式触发语义不等价；其余配置保留，不宣称无损迁移", sourceMode, targetMode))
	}
	p.NetworkMode = targetMode
	if targetMode == 0 || targetMode == 1 || report.HardwareVersion == "4.0" {
		p.ModeSource = v4ModeSource
		report.PolicyReference = "TL-AC100 V4.0 1.4.3 Build 240715 Rel.80898n"
		report.Warnings = append(report.Warnings, "保留V4网络模式：模式控制、候选和估速按官网下载的1.4.3策略族；PMK共用分支与原NULL缺陷修复已单列；未取得1.4.4，不宣称两个发布版本已逐函数确认相同")
	}
	if mode.Value("default_roam_cnt") != "" || mode.Value("default_silence_time") != "" {
		p.Silence = &RoamSilence{Count: uint8(uciInt(mode, "default_roam_cnt", 3)), Seconds: uint16(uciInt(mode, "default_silence_time", 30))}
	}
	if mode.Value("high_performance_roam_cnt") != "" || mode.Value("high_performance_silence_time") != "" {
		p.HighPerformanceSilence = &RoamSilence{Count: uint8(uciInt(mode, "high_performance_roam_cnt", 3)), Seconds: uint16(uciInt(mode, "high_performance_silence_time", 30))}
	}
	if targetMode == 0 {
		p.CurrentMode = uciInt(mode, "cur_wireless_network_mode", 0)
		if p.CurrentMode == 0 {
			p.CurrentMode = 1
		}
		profile := vendorSection(a, "profile", "apmng_roma")
		if profile.Value("high_performance_ap_cnt") != "" || profile.Value("high_performance_sta_cnt") != "" {
			p.AutomaticLimits = &mobility.V4AutomaticLimits{APs: uciInt(profile, "high_performance_ap_cnt", 5), Stations: uciInt(profile, "high_performance_sta_cnt", 30)}
		}
	}
	p.ACSTimeout = uint8(uciInt(mode, "acs_timeout", 0))
	report.TargetMode = targetMode
	cfg.Mobility = &p
	b := vendorSection(a, "apmng_balance", "settings")
	if len(b.Values) > 0 {
		p.Balance = []BalanceRule{{ID: "vendor-balance", Name: "原AC均衡", Enabled: uciOn(b, "enable", false), Clients: uciInt(b, "usr_threshold", 20), Difference: uciInt(b, "dif_threshold", 4), MaxFailures: uciInt(b, "max_fail_num", 3), RSSI: uciInt(b, "rssi_threshold", -75)}}
	}
	n := vendorSection(a, "apmng_band_navigation", "settings")
	if len(n.Values) > 0 {
		cfg.BandNavigation = &BandNavigation{Enabled: uciOn(n, "enable", false), Threshold5G: uciInt(n, "5g_threshold", 20), Difference: uciInt(n, "dif_threshold", 4), MaxFailures: uciInt(n, "max_fail_num", 10)}
	}
	if len(a.UCI["apmng_rate"]) > 0 {
		rates := defaultRatePolicy()
		for _, x := range []struct {
			name string
			out  *LegacyRateSet
		}{{"11a", &rates.A}, {"11b", &rates.B}, {"11g", &rates.G}} {
			s := vendorSection(a, "apmng_rate", "rate_"+x.name)
			x.out.Basic = nil
			x.out.Supported = nil
			for _, v := range uciInts(s, x.name+"_base") {
				x.out.Basic = append(x.out.Basic, float64(v)/2)
			}
			for _, v := range uciInts(s, x.name+"_supp") {
				x.out.Supported = append(x.out.Supported, float64(v)/2)
			}
			x.out.Multicast = float64(uciInt(s, x.name+"_mult", -1))
			if x.out.Multicast >= 0 {
				x.out.Multicast /= 2
			}
		}
		for _, x := range []struct {
			name string
			out  *MCSRateSet
		}{{"11n", &rates.N}, {"11ac", &rates.AC}, {"11ax", &rates.AX}} {
			s := vendorSection(a, "apmng_rate", "rate_"+x.name)
			x.out.Basic = uciInt(s, x.name+"_base", x.out.Basic)
			x.out.Supported = uciInt(s, x.name+"_supp", x.out.Supported)
			x.out.Multicast = uciInt(s, x.name+"_mult", x.out.Multicast)
		}
		cfg.Rates = &rates
	}
	opt := vendorSection(a, "apmng_rrm", "settings")
	if len(opt.Values) > 0 {
		rule := defaultRRMRule()
		if cfg.Mobility != nil && cfg.Mobility.ModeSource == v4ModeSource {
			rule.StrategyVersion = "v4"
		}
		rule.ID = "vendor-rrm"
		rule.Name = "原AC无线优化"
		rule.Enabled = true
		rule.Frequency = uciInt(opt, "freq_enable", 0)
		rule.Channel = uciOn(opt, "chnl_enable", false)
		rule.Power = uciOn(opt, "pwr_enable", false)
		rule.Band2G.Channels = uciInts(opt, "chnl_2g_set")
		for _, key := range []string{"chnl_5g1_set"} {
			for _, ch := range uciInts(opt, key) {
				if !hasInt(rule.Band5G.Channels, ch) {
					rule.Band5G.Channels = append(rule.Band5G.Channels, ch)
				}
			}
		}
		rule.Band5G.SecondaryChannels = uciInts(opt, "chnl_5g2_set")
		bandwidth := map[string]int{"20M": 0, "40M": 1, "80M": 3, "160M": 5}
		var ok bool
		rule.Band2G.Bandwidth, ok = bandwidth[opt.Value("bw_2g")]
		if !ok {
			return fmt.Errorf("unknown RRM 2G bandwidth")
		}
		rule.Band5G.Bandwidth, ok = bandwidth[opt.Value("bw_5g")]
		if !ok {
			return fmt.Errorf("unknown RRM 5G bandwidth")
		}
		for _, b := range []*RRMBand{&rule.Band2G, &rule.Band5G} {
			b.MinPower = uciInt(opt, "pwr_min_pwr", 10)
			b.MaxPower = uciInt(opt, "pwr_max_pwr", 50)
			b.PowerThreshold = uciInt(opt, "pwr_threshold", -65)
		}
		if uciOn(opt, "autorrm_enable", false) {
			d, e := vendorDays(opt.Value("autorrm_date"))
			if e != nil {
				return e
			}
			minute, e := vendorMinute(opt.Value("autorrm_time"))
			if e != nil {
				return e
			}
			rule.Schedule = &ServiceSchedule{Enabled: true, Timezone: "Asia/Shanghai", Action: "on", Windows: []WeeklyWindow{{Days: d, Start: minute, End: minute + 1}}}
		}
		cfg.RRM = []RRMRule{rule}
	}
	storm := vendorSection(a, "apmng_bcast_storm_ctrl", "settings")
	if len(storm.Values) > 0 {
		v := defaultStorm()
		v.Enabled = uciOn(storm, "enable", false)
		v.Rate = uint32(uciInt(storm, "storm_rate", 1024))
		v.Custom = storm.Value("type") == "custom"
		cfg.Storm = &v
	}
	mesh := vendorSection(a, "apmng_mesh", "settings")
	if len(mesh.Values) > 0 {
		web := vendorSection(a, "webpasswd", "userinfo")
		if web.Value("password") == "" {
			for _, s := range a.UCI["webpasswd"] {
				if s.Value("password") != "" {
					web = s
					break
				}
			}
		}
		cfg.Mesh = &MeshConfig{Enabled: uciOn(mesh, "enable", false), AutoAdd: uciOn(mesh, "re_auto_switch", false), SSID: mesh.Value("backhaul_ssid"), Key: mesh.Value("backhaul_key"), Token: mesh.Value("backhaul_token"), BackhaulMode: uint8(uciInt(mesh, "bh_work_mode", 1)), WebPassword: web.Value("password"), Members: []MeshMemberPolicy{}}
	}
	settings := vendorSection(a, "apmng_set", "settings")
	if uciOn(settings, "auto_reboot", false) {
		d, e := vendorDays(settings.Value("reboot_day"))
		if e != nil {
			return e
		}
		minute, e := vendorMinute(settings.Value("reboot_time"))
		if e != nil {
			return e
		}
		cfg.APDefaults.RebootSchedule = &ServiceSchedule{Enabled: true, Timezone: "Asia/Shanghai", Action: "on", Windows: []WeeklyWindow{{Days: d, Start: minute, End: minute + 1}}}
	}
	// auto_firm is automatic AP confirmation, not automatic firmware
	// upgrade. V6 do_settings forces it on; Go's Join already admits APs.
	if settings.Value("auto_firm") == "off" {
		report.Warnings = append(report.Warnings, "原AC关闭了AP自动确认；Go按V6的自动接入方式工作，需在接入设备前复核")
	}
	return nil
}

func convertVendorProtection(rd vendorReader, cfg *Config, aps map[int]string) error {
	p := &ProtectionConfig{}
	dhcp, arp := map[int]ProtectionRule{}, map[int]ProtectionRule{}
	if err := rd.table("dhcpdef_svr.db", "svr_tbl", nil, func(r vendorRow) error {
		p.Servers = append(p.Servers, DHCPTrustedServer{ID: importID("dhcp", r.n("svr_id")), Name: r.s("name"), Address: r.s("svr_addr")})
		r.n("addr_type")
		return nil
	}); err != nil {
		return err
	}
	if err := rd.table("arp_defend.db", "arpDefendArp", nil, func(r vendorRow) error {
		p.Bindings = append(p.Bindings, ARPBinding{ID: importID("arp", r.n("arp_id")), Name: importID("arp", r.n("arp_id")), IP: r.s("ip"), MAC: r.s("mac"), Description: r.s("description")})
		return nil
	}); err != nil {
		return err
	}
	ids := func(raw, kind string) []string {
		var out []string
		for _, v := range strings.FieldsFunc(raw, func(r rune) bool { return r == ',' || r == ' ' }) {
			if n, e := strconv.Atoi(v); e == nil && n >= 0 {
				out = append(out, importID(kind, n))
			}
		}
		return out
	}
	if err := rd.table("dhcpdef_bind.db", "bind_tbl", nil, func(r vendorRow) error {
		id := r.n("ap_id")
		if ap, ok := aps[id]; ok {
			dhcp[id] = ProtectionRule{PolicyTarget: PolicyTarget{APs: []string{ap}}, DHCP: r.on("enable"), Servers: ids(r.s("svr_ids"), "dhcp")}
		}
		return nil
	}); err != nil {
		return err
	}
	if err := rd.table("arp_defend.db", "arpDefendAp", nil, func(r vendorRow) error {
		id := r.n("ap_id")
		if ap, ok := aps[id]; ok {
			arp[id] = ProtectionRule{PolicyTarget: PolicyTarget{APs: []string{ap}}, ARP: r.on("enable"), Bindings: ids(r.s("bind_id_list"), "arp"), Wired: true, Wireless: true}
		}
		return nil
	}); err != nil {
		return err
	}
	var ordered []int
	for id := range aps {
		ordered = append(ordered, id)
	}
	sort.Ints(ordered)
	for _, id := range ordered {
		ap := aps[id]
		d, a := dhcp[id], arp[id]
		p.Rules = append(p.Rules, ProtectionRule{ID: importID("protection", id), Name: importID("protection", id), PolicyTarget: PolicyTarget{APs: []string{ap}}, DHCP: d.DHCP, Servers: d.Servers, ARP: a.ARP, Bindings: a.Bindings, Wired: true, Wireless: true})
	}
	cfg.Protection = p
	return nil
}
