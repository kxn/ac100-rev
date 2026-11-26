# 独立 Go AC 的核查与回归

2026-11-27。验收对象是控制器：配置、命令、应答/报告、状态、持久化和恢复。AP 的吞吐、射频物理效果与空口切换不作为本轮算法静态对照的证明，也不能因当前 AP 不报某能力而省略代码。

## 依据与判定

1. **固件静态依据**：先确认版本、有效入口和调用点，再核对字段、分支、数值运算、顺序和时钟。不能凭函数名选旧算法，不能拿共享 Lua 字段代替活动消费链。
2. **Go 源码向量**：按上述分支编写边界输入和预期输出，检查移植；这些向量不是外部试验推导出的策略。
3. **控制器回归**：假 AP 通过本机 UDP 验证命令、会话、ACK/报告、乱序、取消和恢复；HTTP/UI 检查能力展示和提交。它们不单独证明原厂算法等价。
4. **设备兼容记录**：历史单 AP 结果单列在 [go-live-status.md](go-live-status.md)。本轮复核及整改记录见 [controller-revalidation.md](controller-revalidation.md)；设备结果必须与具体部署版本对应。

成功关联按原厂入口立即进入站点 DB，统计/IP不制造关联。配置保存、AP应答、报告确认及实际切换分别展示；升级最后分块ACK不等于升级成功，漫游结果ACK不等于客户端已迁移。

## 功能入口

| 链路 | 主要源码/回归 |
| --- | --- |
| AP接入、心跳、独立会话、统一命令FIFO | cweng/engine、session、manage、command_queue及相应测试 |
| 正式启动配置权威 | cmd/acd/main_test.go：真实进程入口+UDP，植入旧WLAN库，不得下发旧SSID或创建Portal库；监听端口与宣告端口一致 |
| AP设置、分组/模板/复制/替换、自动IP分组 | admin/management*、group_strategy*、policy_retarget*、ports*、ap_export* |
| 无线服务、槽位、VLAN/池、组播、时间/删除提交 | admin/service_wire*、assignments*、auto_binding*、vlan_pool*、multicast_groups*、schedule*、reconcile_integration* |
| RF与RRST、继承和AX默认 | admin/radio_*、rf_mode*、native_radio*；cweng/capabilities*、radio_linkage* |
| EDCA字段覆盖、规则、场景、手工操作次序 | admin/edca_test.go：真实UDP下发、解绑、继承变化、同值手工写、可选字段和普通保存不重跑规则 |
| 均衡/关联、原估算和候选/PMK | mobility/*_test.go、admin/mobility*、admission*；cweng/association_audit*、station_policy* |
| RRM原库/测量/时钟/两轮/应用/配置门禁 | rrm/firmware_test.go、admin/rrm*、config_store_test.go |
| 站点/BSSID/终端识别/MLO/无线历史 | capwap/station_extra*、state_pull*；cweng客户端/统计测试；admin/client*、bssid_state*、history*；terminal/* |
| Mesh、子会话、成员授权和任务恢复 | admin/mesh*、cweng/mesh* |
| AP防护、风暴/代理/USB | admin/protection*、arp_scan*；cweng/arp_report* |
| 选择性AP DHCP | dhcpserver/*_test.go：精确厂商、普通终端静默、Mesh特例 |
| Go程序预算、默认值与配置分层 | controllercfg/resources_test.go、admin/resources_test.go、cweng/command_queue_test.go；实时调整/持久化/恢复、保留已有会话与命令、不改变AP配置及RRM、超过旧32/50条规则容量、无profile.ini启动 |
| Web | tools/check_admin_ui.py：两套能力×11页，50次表单提交，无JS错误；写操作均被HTTP模拟拦截 |

完整原厂模块→Go以及Go→原厂/基础设施分类见 [双向索引](uac-web-parity-map.json)。文件覆盖检查不等于声称穷举所有功能参数。

## 重跑

```bash
python3 tools/check_parity_map.py --verify-firmware
python3 tools/check_behavior_contracts.py --verify-firmware --run-tests
python3 tools/audit_mobility_firmware.py --go-output uacgo/mobility/tables_generated.go
python3 tools/extract_terminal_firmware.py
cd uacgo
go test ./...
go vet ./...
go test -race ./...
CGO_ENABLED=0 go build ./...
```

固件工具要求本机已有相同版本提取目录；普通Go测试不依赖原厂运行时。UI工具使用本地只读状态构造夹具和模拟HTTP写入，需本机Playwright环境；它不向AP修改无线配置。跨平台构建仅验证编译；设备绑定和选择性DHCP的运行环境限制单列在环境文档。

## 已知证据边界

固件没有flash运行配置，重建profile不是原厂容量/默认值依据。V4菜单不证明V6运行行为；多AP真实互通、硬件特性及长期稳定性尚不能由本轮源码审查认定。保留未定义C输入的安全防护，不声称复刻其未定义结果。

排除AC Linux系统/网络/机器监控、RADIUS/Portal/认证、云、网络运维/WIPS/Sensor/FTP/外部审计推送和AP蓝牙。普通客户端DHCP/DNS/NAT只在实验工具；AP执行的DHCP/ARP/ND防护、无线VLAN/池和用户明确要求的AP-only Go DHCP保留。

## 独立程序默认值（用户2026-11-27决策）

原AC硬件的容量/profile不再作为需要复刻的目标。正式acd不读取profile.ini；程序配置通过Web/API保存，资源字段的默认值、校验范围及表单元数据共享controllercfg定义。AP会话/待发队列、服务/组/模板/每类规则默认均为1024，信任服务器及地址绑定各10000，固件库32镜像/512MiB；上限可编辑，已有对象/固件占用不能被新预算截断，已有会话和已入队命令不会因降低容量而被清除。

AP管理的Go初值：心跳20秒、超时5次、客户端保活30秒、空闲3600秒、允许AC离线后AP自管理。通过已有全局AP设置/模板/分组/单AP页面编辑，显式停用不会被初值覆盖。资源专页只调整程序预算；AP能力限制、协议参数范围、漫游/RRM门限/运算/事件次序继续按原固件依据校验。资源编辑不改变AP配置身份，亦不取消进行中的RRM。
