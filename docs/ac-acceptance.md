# Go AC 验收范围与证据

2026-11-26 按用户纠正重新梳理。验收对象是独立 Go 控制器；AP 固件是被管理端。

## 判定方式

一项 AC 功能需要有配置和校验、API 与操作入口、按设备能力生成命令、处理应答或上报、展示状态，并在配置恢复、重连和失败时保持一致。原厂固件用于核对字段和协议；不能仅因为源码存在一个字段，就声称实际功能已验证。

模拟 AP 通过真实 UDP 接收命令并返回应答、错误或上报，用于验证 AC 的状态转换。界面测试模拟 HTTP 写入，验证能力展示和提交数据；它不能单独证明后端执行。现有真实 AP 只承担接入、下发、报告和基本可用性冒烟。

“已保存”“AP 已应答”“上报已确认”是不同状态。关联许可不能当作客户端上线，升级最后一个分块的 ACK 不能当作升级完成，漫游候选也不能当作客户端实际切换。

## 保留功能与回归入口

| AC 功能 | 检查内容 | 主要回归文件（uacgo 下） |
| --- | --- | --- |
| 接入与会话 | 发现、DTLS、Join/Configure/RUN、心跳、独立 AP 会话、重连、重试和取消 | cweng/engine_test.go、session_request_test.go、manage_test.go、admin/session_cleanup_test.go |
| AP 管理 | 名称/位置、默认/模板/分组/单 AP 继承、能力过滤、管理账号、设备端口及可选硬件、复制、替换、备份/恢复、列表导出 | admin/management_test.go、management_copy_test.go、policy_retarget_test.go、ports_test.go、ap_export_test.go |
| AP 操作 | 重启/复位、定时去重、批量升级、硬件和镜像校验、传输重试、重连确认及任务冲突 | admin/management_test.go、schedule_test.go、upgrade_test.go、firmware/*_test.go |
| 无线服务 | 启停/删除、SSID 编码、安全/密码、隔离、限速、组播、定时、VLAN/池、AP/频率绑定、槽位所有权及删除提交 | admin/service_wire_test.go、server_test.go、vlan_pool_test.go、multicast_groups_test.go、auto_binding_test.go、assignments_test.go、reconcile_integration_test.go |
| 射频配置 | 模式/带宽/信道/功率、WMM、时序、客户端门限、速率表、EDCA/DCS、可选 Wi-Fi 能力、整机模式与 RRST 约束 | admin/radio_advanced_test.go、native_radio_test.go、radio_inheritance_test.go、rates_test.go、rf_mode_test.go、radio_linkage_test.go |
| 无线状态 | AP/射频/SSID 报告、客户端在线位置/SSID/实际 VLAN/IP/信号/速率、名称/备注/下线/导出、事件及历史趋势 | cweng/telemetry*、association_audit_test.go、client_snapshot_test.go；admin/client_state_test.go、client_service_test.go、client_history_test.go、history_test.go |
| AP 协调 | 双频优选、准入总量、负载均衡、k/v/r、漫游候选与结果、网络模式、RRM/ACS 测量和合法方案 | admin/admission_test.go、band_navigation_test.go、navigation_interlock_test.go、mobility_test.go、mobility_mode_test.go、mobility_scan_test.go、rrm_test.go、radio_linkage_test.go |
| Mesh | 配置、发现/配对/增删、成员授权持久化、拓扑确认、子 AP 独立会话/报告、父传输并发及升级互斥 | admin/mesh_test.go、mesh_members_test.go、upgrade_test.go；cweng/mesh_transport_test.go、mesh_control_test.go |
| AP 执行的防护/外设 | DHCP/ARP/ND 信任及绑定、容量和能力差异、扫描报告、风暴/代理、蓝牙规则/MQTT/证书与 USB 开关 | admin/protection_test.go、mobility_scan_test.go、bluetooth_test.go；cweng/arp_report_test.go、bluetooth_report* |
| 控制接口与 AP 专用 DHCP | 接口保存和启动绑定、普通客户端静默、准确厂商标识、租约和 Mesh Discover 特例 | admin/server_test.go、dhcpserver/*_test.go |
| 管理界面 | 两套能力、每套三台模拟 AP、10 页和 49 次表单提交；复制/替换/导入、信号历史、AP 数量趋势及导出入口 | tools/check_admin_ui.py（位于仓库根目录） |

上表是已有回归场景的索引，不表示参数空间或所有型号穷举完成。具体字节与原厂来源见 [功能对应表](feature-parity.md)，部署和验证结果见 [工作记录](parity-worklog.md)。

## 本轮纠正后补齐

- Mesh 成员授权从任务历史独立成可备份配置，保留撤销意图；清理旧任务不会丢权限，达到 1000 条任务后也不会永久堵塞管理。成员策略写盘失败时不能显示完成；备份恢复和 AP 替换不会与未确认操作竞争。
- AP 复制保留目标名称、位置、分组和模板；取消“复制射频”时保留目标所有射频配置层。复制源使用实际继承结果，多目标能力不兼容时整批不写入。
- 客户端 RSSI 历史按真正测量时间采样，IP 更新不伪造新信号；保存、重启恢复、按客户端查询和界面曲线接通。AP 在线/离线数量趋势排除已替换设备的清理记录。
- 旧格式无线表缺少 VLAN 时，只有唯一已提交的 SSID/射频绑定才恢复客户端，未知 VLAN 不编成 0；同名服务无法唯一判定时等待明确报告。
- AP 列表 CSV 导出接入控制器标签和实际设备身份，排除已替换记录，不导出设备账号或无线凭据。
- 射频继承编辑和历史筛选按上报及现有配置构建射频编号列表，移除写死的 1–6 范围；编辑旧配置不能静默丢掉射频 8 的设置及高级字段。

## 不计入本轮开发缺口

RADIUS、认证类别、网络运维/诊断抓包/巡检/WIPS/FTP 日志、云管理，以及 AC Linux 的主机网络、系统、机器监控和管理 VLAN，均在用户排除范围。普通客户端 DHCP/DNS/NAT 只留在实验工具；用户要求的 TP-Link AP 专用 Go DHCP 保留。

多 AP 真机互通、漫游实际切换，以及各硬件的吞吐、PHY、MLO/BLE/射频专属效果，属于后续设备兼容验证。AC 的候选决策、命令、超时、失败和结果处理仍须模拟验证，不能因当前单 AP 缺少能力而省略实现；也不能因缺少空口测试就阻塞已验证的 AC 管理功能。
