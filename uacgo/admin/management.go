package admin

import (
	"encoding/json"
	"fmt"
	"strings"
	"uacgo/cweng"
	"unicode/utf8"
)

// Nil means inherit/leave unchanged, including false and zero overrides.
type APOptions struct {
	RFMode            *APRFMode        `json:"rf_mode,omitempty"`
	USB               *bool            `json:"usb,omitempty"`
	Mesh              *bool            `json:"mesh,omitempty"`
	Radios            []RadioSetting   `json:"radios,omitempty"`
	EchoSeconds       *uint8           `json:"echo_seconds,omitempty"`
	EchoMisses        *uint32          `json:"echo_misses,omitempty"`
	ClientKeepAlive   *uint32          `json:"client_keep_alive,omitempty"`
	ClientIdle        *uint32          `json:"client_idle,omitempty"`
	OfflineSelfManage *bool            `json:"offline_self_manage,omitempty"`
	LED               *bool            `json:"led,omitempty"`
	LEDWiFiSync       *bool            `json:"led_wifi_sync,omitempty"`
	LEDSchedule       *ServiceSchedule `json:"led_schedule,omitempty"`
	RebootSchedule    *ServiceSchedule `json:"reboot_schedule,omitempty"`
	Trunk             *bool            `json:"trunk,omitempty"`
	FitFatButton      *bool            `json:"fit_fat_button,omitempty"`
	RegionCode        *uint8           `json:"region_code,omitempty"`
	Account           *APAccount       `json:"account,omitempty"`
	Ports             []APPort         `json:"ports,omitempty"`
	LAG               *APLAG           `json:"lag,omitempty"`
}
type APRFMode struct {
	Enabled bool  `json:"enabled"`
	ID      uint8 `json:"id"`
}
type APAccount struct {
	Username    string `json:"username"`
	Password    string `json:"password,omitempty"`
	HasPassword bool   `json:"has_password,omitempty"`
}
type APPort struct {
	ID      uint8   `json:"id"`
	VLAN    *uint16 `json:"vlan,omitempty"`
	Enabled *bool   `json:"enabled,omitempty"`
}
type APLAG struct {
	Enabled bool      `json:"enabled"`
	Mode    uint8     `json:"mode"`
	Ports   RadioList `json:"ports"`
}
type APProfile struct {
	AP       string    `json:"ap_id"`
	Name     string    `json:"name"`
	Location string    `json:"location"`
	Group    string    `json:"group_id"`
	Template string    `json:"template_id"`
	Options  APOptions `json:"options"`
}
type APGroup struct {
	ID       string           `json:"id"`
	Name     string           `json:"name"`
	Options  APOptions        `json:"options"`
	Strategy *APGroupStrategy `json:"strategy,omitempty"`
}
type APTemplate struct {
	ID       string    `json:"id"`
	Name     string    `json:"name"`
	Model    string    `json:"model"`
	Hardware string    `json:"hardware_version"`
	Options  APOptions `json:"options"`
}

// Standalone startup choices for settings whose factory values lived in the
// AC's Flash configuration. They remain ordinary editable AP settings; wire
// meanings, model constraints and roaming/RRM defaults are firmware-derived.
func standaloneAPDefaults() APOptions {
	echo, miss, keep, idle, offline := uint8(20), uint32(5), uint32(30), uint32(3600), true
	return APOptions{EchoSeconds: &echo, EchoMisses: &miss, ClientKeepAlive: &keep, ClientIdle: &idle, OfflineSelfManage: &offline}
}

func mergeOptions(base, override APOptions) APOptions {
	// JSON overlays only explicitly set options. Nested schedules/accounts and
	// complete port/LAG lists are atomic replacements, not partial surprises.
	a, _ := json.Marshal(base)
	b, _ := json.Marshal(override)
	var merged, overlay map[string]json.RawMessage
	_ = json.Unmarshal(a, &merged)
	_ = json.Unmarshal(b, &overlay)
	for k, v := range overlay {
		merged[k] = v
	}
	a, _ = json.Marshal(merged)
	var out APOptions
	_ = json.Unmarshal(a, &out)
	return out
}
func effectiveAPOptions(cfg Config, ap cweng.APStatus) (APOptions, error) {
	defaults := mergeOptions(standaloneAPDefaults(), cfg.APDefaults)
	o := inheritedRadioOptions(supportedInheritedOptions(defaults, ap), ap)
	for _, p := range cfg.APProfiles {
		if p.AP != ap.ID {
			continue
		}
		for _, t := range cfg.Templates {
			if t.ID == p.Template {
				if t.Model != "" && t.Model != ap.Model || t.Hardware != "" && t.Hardware != ap.HardwareVersion {
					return APOptions{}, fmt.Errorf("模板 %s 与 AP 型号/硬件不兼容", t.Name)
				}
				o = mergeOptions(o, inheritedRadioOptions(supportedInheritedOptions(t.Options, ap), ap))
			}
		}
		for _, g := range cfg.Groups {
			if g.ID == p.Group {
				o = mergeOptions(o, inheritedRadioOptions(supportedInheritedOptions(g.Options, ap), ap))
			}
		}
		o = mergeOptions(o, p.Options)
	}
	return o, validateAPOptions(o)
}
func serviceTargets(s Service, ap string, cfg Config) bool {
	for _, id := range cfg.RetiredAPs {
		if id == ap {
			return false
		}
	}
	if len(s.APs) == 0 && len(s.Groups) == 0 {
		return true
	}
	for _, id := range s.APs {
		if id == ap {
			return true
		}
	}
	for _, p := range cfg.APProfiles {
		if p.AP == ap {
			for _, g := range s.Groups {
				if g == p.Group {
					return true
				}
			}
		}
	}
	return false
}
func validLabel(s string, max int) bool {
	return utf8.ValidString(s) && len([]byte(s)) <= max && !strings.ContainsAny(s, "\x00\r\n")
}
func validateAPOptions(o APOptions) error {
	seenRadios := map[uint8]bool{}
	for _, r := range o.Radios {
		if r.AP != "" || r.Radio == 0 || r.Radio > 31 || seenRadios[r.Radio] {
			return fmt.Errorf("继承射频编号无效或重复，模板中不能指定 AP")
		}
		seenRadios[r.Radio] = true
		if r.Channel != nil && (*r.Channel < 0 || *r.Channel > 233) || r.Power != nil && (*r.Power < 0 || *r.Power > 100) || r.PowerLevel != nil && (*r.PowerLevel < 1 || *r.PowerLevel > 10) {
			return fmt.Errorf("模板射频信道/功率无效")
		}
	}
	if o.EchoSeconds != nil && (*o.EchoSeconds < 5 || *o.EchoSeconds > 120) {
		return fmt.Errorf("AP 心跳为 5–120 秒")
	}
	if o.EchoMisses != nil && (*o.EchoMisses < 1 || *o.EchoMisses > 20) {
		return fmt.Errorf("心跳超时次数为 1–20")
	}
	if o.ClientKeepAlive != nil && (*o.ClientKeepAlive < 5 || *o.ClientKeepAlive > 65535) {
		return fmt.Errorf("客户端保活为 5–65535 秒")
	}
	if o.ClientIdle != nil && (*o.ClientIdle < 30 || *o.ClientIdle > 86400) {
		return fmt.Errorf("客户端空闲为 30–86400 秒")
	}
	if err := o.LEDSchedule.validate(); err != nil {
		return err
	}
	if err := o.RebootSchedule.validate(); err != nil {
		return err
	}
	if o.RebootSchedule != nil && o.RebootSchedule.Enabled && o.RebootSchedule.Action != "on" {
		return fmt.Errorf("重启计划必须在时段内执行")
	}
	if o.Account != nil && (!validLabel(o.Account.Username, 63) || o.Account.Username == "" || !validLabel(o.Account.Password, 63)) {
		return fmt.Errorf("AP 账号为 1–63 字节，密码最多 63 字节")
	}
	seen := map[uint8]bool{}
	for _, p := range o.Ports {
		if p.ID == 0 || seen[p.ID] || p.VLAN != nil && (*p.VLAN < 1 || *p.VLAN > 4094) {
			return fmt.Errorf("AP 端口或 VLAN 无效")
		}
		seen[p.ID] = true
	}
	if o.LAG != nil {
		if o.LAG.Mode > 1 || len(o.LAG.Ports) > 16 || o.LAG.Enabled && len(o.LAG.Ports) < 2 {
			return fmt.Errorf("链路聚合模式/端口无效")
		}
		seen = map[uint8]bool{}
		for _, p := range o.LAG.Ports {
			if p == 0 || seen[p] {
				return fmt.Errorf("聚合端口无效")
			}
			seen[p] = true
		}
	}
	return nil
}
func validateManagement(cfg Config) error {
	if err := validateGroupStrategies(cfg.Groups); err != nil {
		return err
	}
	if err := validateAPOptions(cfg.APDefaults); err != nil {
		return err
	}
	groups, templates, aps := map[string]bool{}, map[string]bool{}, map[string]bool{}
	groupNames, templateNames := map[string]bool{}, map[string]bool{}
	for _, g := range cfg.Groups {
		if g.ID == "" || groups[g.ID] || !validLabel(g.Name, 52) || strings.TrimSpace(g.Name) == "" || groupNames[g.Name] {
			return fmt.Errorf("AP 分组编号/名称无效或重复")
		}
		groups[g.ID] = true
		groupNames[g.Name] = true
		if err := validateAPOptions(g.Options); err != nil {
			return err
		}
	}
	for _, t := range cfg.Templates {
		if t.ID == "" || templates[t.ID] || !validLabel(t.Name, 52) || strings.TrimSpace(t.Name) == "" || templateNames[t.Name] || !validLabel(t.Model, 128) || !validLabel(t.Hardware, 32) {
			return fmt.Errorf("AP 模板无效或重复")
		}
		templates[t.ID] = true
		templateNames[t.Name] = true
		if err := validateAPOptions(t.Options); err != nil {
			return err
		}
	}
	for _, p := range cfg.APProfiles {
		if p.AP == "" || aps[p.AP] || !validLabel(p.Name, 52) || !validLabel(p.Location, 200) || p.Group != "" && !groups[p.Group] || p.Template != "" && !templates[p.Template] {
			return fmt.Errorf("AP 设置引用无效或重复")
		}
		aps[p.AP] = true
		if err := validateAPOptions(p.Options); err != nil {
			return err
		}
	}
	for _, s := range cfg.Services {
		for _, g := range s.Groups {
			if !groups[g] {
				return fmt.Errorf("无线服务引用不存在的 AP 分组")
			}
		}
	}
	return nil
}

func redactAPOptions(o APOptions) APOptions {
	if o.Account != nil {
		a := *o.Account
		a.HasPassword = a.Password != ""
		a.Password = ""
		o.Account = &a
	}
	return o
}
func publicManagement(cfg Config) Config {
	cfg.EDCAState = nil
	cfg.Mesh = publicMesh(cfg.Mesh)
	cfg.APDefaults = redactAPOptions(cfg.APDefaults)
	cfg.APProfiles = append([]APProfile{}, cfg.APProfiles...)
	for i := range cfg.APProfiles {
		cfg.APProfiles[i].Options = redactAPOptions(cfg.APProfiles[i].Options)
	}
	cfg.Groups = append([]APGroup{}, cfg.Groups...)
	for i := range cfg.Groups {
		cfg.Groups[i].Options = redactAPOptions(cfg.Groups[i].Options)
	}
	cfg.Templates = append([]APTemplate{}, cfg.Templates...)
	for i := range cfg.Templates {
		cfg.Templates[i].Options = redactAPOptions(cfg.Templates[i].Options)
	}
	return cfg
}

func serviceVersion(s Service, ap cweng.APStatus, cfg Config) string {
	return configurationKey(struct {
		Service      Service
		Target       bool
		Capabilities []cweng.RadioCapability
		General      []uint32
		Sub          map[uint16]uint32
	}{s, serviceTargets(s, ap.ID, cfg), ap.Capabilities, ap.GeneralCapabilities, ap.SubCapabilities}, ap.ConnectedAt)
}
