// Package controllercfg owns standalone program resource settings. These are
// independent of AP capabilities, wire-format limits and firmware algorithms.
package controllercfg

import (
	"bytes"
	"encoding/json"
	"fmt"
)

type Resources struct {
	MaxAPSessions      int `json:"max_ap_sessions"`
	CommandQueueDepth  int `json:"command_queue_depth"`
	MaxServices        int `json:"max_services"`
	MaxGroups          int `json:"max_groups"`
	MaxTemplates       int `json:"max_templates"`
	MaxPolicyRules     int `json:"max_policy_rules"`
	MaxTrustedServers  int `json:"max_trusted_servers"`
	MaxAddressBindings int `json:"max_address_bindings"`
	MaxFirmwareImages  int `json:"max_firmware_images"`
	FirmwareStorageMiB int `json:"firmware_storage_mib"`
}

func Defaults() Resources {
	return Resources{MaxAPSessions: 1024, CommandQueueDepth: 1024, MaxServices: 1024, MaxGroups: 1024, MaxTemplates: 1024, MaxPolicyRules: 1024, MaxTrustedServers: 10000, MaxAddressBindings: 10000, MaxFirmwareImages: 32, FirmwareStorageMiB: 512}
}
func Effective(r *Resources) Resources {
	if r == nil {
		return Defaults()
	}
	return *r
}

// Old backups may omit this block or only contain some settings. Missing
// members inherit Go defaults; explicit zero remains invalid. API updates
// decode into the existing value to preserve unspecified members.
func (r *Resources) UnmarshalJSON(b []byte) error {
	if v := bytes.TrimSpace(b); len(v) == 0 || v[0] != '{' {
		return fmt.Errorf("程序容量配置必须为对象")
	}
	v := *r
	if v == (Resources{}) {
		v = Defaults()
	}
	type plain Resources
	d := json.NewDecoder(bytes.NewReader(b))
	d.DisallowUnknownFields()
	if err := d.Decode((*plain)(&v)); err != nil {
		return err
	}
	*r = v
	return nil
}

type Field struct {
	Key   string `json:"key"`
	Label string `json:"label"`
	Min   int    `json:"min"`
	Max   int    `json:"max"`
	Unit  string `json:"unit,omitempty"`
}

func Fields() []Field {
	return []Field{
		{"max_ap_sessions", "AP 会话上限（含 Mesh 子 AP）", 1, 65535, "台"},
		{"command_queue_depth", "每条 AP 管理连接的待发命令上限", 1, 65535, "条"},
		{"max_services", "无线服务数量上限", 1, 100000, "项"},
		{"max_groups", "AP 分组数量上限", 1, 100000, "组"},
		{"max_templates", "AP 模板数量上限", 1, 100000, "项"},
		{"max_policy_rules", "每类管理规则数量上限", 1, 100000, "条"},
		{"max_trusted_servers", "可信 DHCP 服务器表容量", 1, 1000000, "项"},
		{"max_address_bindings", "ARP/ND 地址绑定表容量", 1, 1000000, "项"},
		{"max_firmware_images", "AP 固件库镜像数量上限", 1, 1024, "个"},
		{"firmware_storage_mib", "AP 固件库存储上限", 16, 65536, "MiB"},
	}
}
func (r Resources) Validate() error {
	b, _ := json.Marshal(r)
	var values map[string]int
	_ = json.Unmarshal(b, &values)
	for _, f := range Fields() {
		if values[f.Key] < f.Min || values[f.Key] > f.Max {
			return fmt.Errorf("%s为 %d–%d", f.Label, f.Min, f.Max)
		}
	}
	return nil
}
