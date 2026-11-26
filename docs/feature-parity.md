# 原厂功能与 Go 对应核查（2026-11-26）

**当前验收对象是独立 Go AC 的功能与逻辑。** 配置/API/UI、按能力生成命令、处理上报、状态展示、持久化和失败恢复构成 AC 闭环。复杂功能以真实 UDP 模拟 AP 验证，实机只保留必要的接入、下发、回报与基本可用性冒烟。

下表保留历史设备行为证据。空口速率、吞吐、AP硬件专属效果等属于后续设备兼容/性能验证，不因为它们未逐项实测就判定 AC 功能未实现，也不作为本轮完成门槛。

当前 AC 功能验收与自动回归入口统一见 [ac-acceptance.md](ac-acceptance.md)。下表最后一列保留历史兼容性观察，不是一张当前待开发清单。

本表按用户保留范围核查。原始 AC V6 页、Lua 控制器及字段索引见 [original-feature-inventory.json](original-feature-inventory.json)，由 `tools/audit_function_inventory.py` 从提供的固件生成并记录源码哈希。V4 实机菜单与 V6 编译分支可能不同，源码出现只证明候选功能存在。

“程序闭环”要求独立 Go 的配置、API/UI、能力判断、下发、持久化与状态形成链路；仅有结构体、编解码或 SQLite/JCS 接口不能算完成功能。各行的验证对象是对应已列出的场景，未测试参数、其它型号和长时间稳定性不自动包含。

| 功能 / 原厂来源 | Go 对应 | 当前证据 | 后续核验记录 / 优先级 |
| --- | --- | --- | --- |
| AP 发现、DTLS、Join/Configure/RUN / AP 接入 | `cweng/engine.go`, `session.go`, `internal/legacydtls` | 真实 AP 接入、重启 AC 后重连；模拟生命周期/race | 多型号、长期压力 / P0 |
| 同身份重连、请求重试与取消 | `cweng/manage.go`, `rpc.go` | UDP、会话替换、丢 ACK、错误 ACK、断开测试 | 多 AP 实机压力 / P0 |
| AP 型号、硬件、射频和扩展能力 | `cweng/capabilities.go`、APDB、`admin/assets/app.js` | 当前 AP 上报；另一能力集的 UI/协议测试 | 其它硬件的实际语义逐一核对 / P0 |
| AP 在线、IP、型号、版本 / `apmng_status` | `admin` AP 页面、NMS | 当前 AP 实报 | 更多型号、断线时序 / P0 |
| AP 名称 / `apmng_set.entry_name` | 名称/位置由原厂 AC 数据库维护；Go 标签及配置持久化 | API/备份/重启；真实 AP 设置矩阵 | 原厂同样是 AC 侧标签；不再误列缺少 AP 本机名称命令 |
| AP 位置、模板、AP 分组、复制 / `apmng_set` | admin/management*、radio_inheritance.go、完整管理 UI | 继承/覆盖/显式停用/分组/模板/复制测试 | 继续其它型号能力与组合验收 |
| AP 心跳、客户端保活、空闲时间 / `apmng_set` | APOptions + API/UI + 协议下发，ACK 后更新 AC watchdog | 真机 7 项设置 ACK / LED 回报，恢复原值 | 不同心跳下长时间断线时序 |
| AP 离线自管理 / `offline_selfmanage` | APOptions.OfflineSelfManage / private3c / UI / 持久化 | 源码字段及真机下发 ACK | 当前AP已实测：启用时断AC后已有/新客户端均HTTPS；禁用时已有连接保留、新接入失败，原设置恢复。其它型号及长期离线仍待 |
| AP LED / `apmng_set.led` | LED、无线状态同步、日期/周/时区计划及 UI | 真机 LED off/on 与实际报告一致；计划边界测试 | 按时段实际切换/不同型号 |
| AP 重启、复位 / `apmng_status` | 持久化 AP 操作及 UI；区分 CAPWAP 控制重连与原生完整重启 | 完整设备重启及重新 DHCP/接入通过 | 出厂复位未对真 AP 反复破坏性测试 |
| AP 定时重启 / `apmng_set` | APOptions.RebootSchedule、持久化一次性触发记录 | 时间边界、重启去重、模拟 AP | 实际到时执行与长时间运行 |
| AP 升级、批量升级、型号校验 / `apmng_upgrade` | firmware 包、admin/upgrade.go、上传/兼容/调度/批量/取消/UI | UDP 小镜像及 >16MiB 全传输、MD5、版本确认、ACK 丢失/校验失败/错会话/存储篡改 | 未刷写真 AP；升级结果须重连接收新版身份才完成 |
| AP 配置导入导出、替换设备 / `apmng_set` | 完整备份/导入/复制/替换；替换迁移策略目标并保留旧 WLAN 清理意图 | 恢复、继承、替换、保留凭据、删除 tombstone 测试 | 更多混合型号迁移 |
| AP 下联端口、Trunk/LAG、FIT/FAT 键、地区码 / `apmng_set` | APOptions.Ports/Trunk/LAG/FitFatButton/RegionCode 及 UI/协议 | 模拟与字节对照 | 端口具体能力/数量、RF 角色/地区列表仍需补齐核对 |
| SSID 新增、修改、启停、删除 / `apmng_wserv` | `admin/server.go`, `lifecycle.go` | 原厂字节/UDP；当前 AP 新增/删除与报告 | 新版已实测创建临时加密 SSID、平板连接上网、删除及槽位/SSID 报告清理 / P0 |
| AP/射频绑定、解绑、每绑定 VLAN / `rf_bind` | `admin/lifecycle.go`, `assignments.go` | 模拟 per-AP/per-radio 槽位、删除/重启恢复 | 固定 VLAN100真实平板获192.168.100.53、经专用VLAN接口HTTP及API VLAN/SSID/IP一致；多AP变化仍待 / P0 |
| 无线描述、UTF-8/GBK / `apmng_wserv` | `service_advanced.go` | 字节与长度测试 | 中文 SSID、GBK 终端兼容 / P1 |
| SSID 广播 / 隐藏 | `service_advanced.go`、UI | 真实平板接入隐藏 WPA2 SSID、HTTPS、AP/射频/WLAN 匹配；临时服务与保存网络清理 | 其它终端兼容 / P1 |
| 客户端隔离 | `service_advanced.go`、UI | 原厂字节对照 | 两客户端互访隔离实测 / P1 |
| Open / WPA/WPA2 PSK、加密算法 | `service_advanced.go`、UI | WPA2/AES 真实平板连接并 HTTPS；其它编码测试 | Open和PSK修改正反已实测：旧密码失效、新密码接入/HTTPS；混合/TKIP其它组合仍待 / P0–P1 |
| WPA2/WPA3 混合 | 编码、能力门控与 UI | 真实平板采用 SAE（Android security type4），5 GHz 接入/HTTPS、AP 槽位一致 | 其它终端、PMF空口和重协商 / P1 |
| 企业无线 RADIUS 基本地址/端口/密钥 | `RadiusOptions`、API/UI、编码 | 原厂固定报文、秘密字段脱敏 | 用户本轮明确排除，不再作为交付缺项 |
| RADIUS NAS ID、认证通道/AC 代理、动态 VLAN、Session Timeout | 原版 `radius_nas_id`, `radius_auth_channel`, `radius_vlan_enable`, `radius_session_timeout` | 目前 Go `RadiusOptions` 不含这些字段 | 用户本轮明确排除，不再实现/验收 |
| PPSK 用户、用户组、服务绑定与导入导出 | 已复核为共享 Lua/数据库残留，无当前 V6 功能闭环 | 原厂 QEMU GET 明确 No callback operation registered；Vue 无入口 | 不当作启用功能或 Go 已实现；不同固件若实际启用需另核对 |
| 无线服务客户端上限 `sta_max_cnt` | WirelessOptions.MaxClients，跨 AP 原子预约与总量限制 | 并发准入/预约超时/同 MAC 漫游不重复计数 | 多终端实际触顶行为；服务上限由 AC 准入执行 |
| 密钥更新间隔 | `service_advanced.go` | 编码测试 | 长连接 rekey 行为 / P1 |
| 上/下行限速、SSID/客户端模式 | `WirelessRateLimit` | 真实平板 HTTP：原约74/24Mbps，客户端/SSID两模式3000kbps均约3.2–3.5Mbps，恢复后约87/19Mbps | 多客户端聚合上限、UDP/其它型号 / P1 |
| MLO 无线服务 | `WirelessOptions.MLO`、新安全格式与 MLO 关联 | 能力门控/字节测试 | 当前平板不是 MLO 验收设备；多链路数据和回退未验证 / P1 |
| 固定 VLAN、VLAN 池定义/绑定/删除 | `vlan_pool.go` | 原厂固定字节、校验、模拟/能力集 UI | VLAN 池真实 AP 分配与数据面 / P1 |
| 周/日期/时区无线定时 | `schedule.go` | 时间边界测试；配置持久化 | 真正到时启停及重启恢复 / P1 |
| IGMP Snooping / Querier / 转单播 / 未知组播丢弃 / 频段速率 | `MulticastOptions` 与私有元素 | 编码/能力门控 | 加入/离开组、查询、丢弃、数据吞吐未验收 / P1 |
| IGMP IP 列表 `igmp_ip_list` | multicast_groups.go / IPv4/IPv6 列表及 UI | golden、模拟下发、移除清空、能力门控 | 实际组播数据面效果 |
| 射频启停 / `apmng_rf` | `radio.go`、原生模型/传统报文 | 清 VAP/重建模拟；实机分别关闭/恢复双频、平板实际接入 | 优选依赖已修复并通过实机双频恢复矩阵 / P0 |
| 模式、带宽、信道、功率 | `radio_advanced.go`, `native_radio.go` | 当前 AP 参数更改/恢复及模型回读；客户端 5 GHz 接入 | 全组合、自动信道/DFS/其它型号；配置回读不等于空口 / P0–P1 |
| Radio 客户端上限、天线、WMM、GI、探测响应 | `RadioAdvanced` | 编码；部分当前 AP 模型回读 | 每个开关的行为未全部实测 / P1 |
| RTS、分片、Beacon、DTIM | `RadioAdvanced` | 编码；Beacon/DTIM 当前 AP 模型回读 | 空口抓包、休眠终端行为 / P1 |
| 管理帧速率 | `ManagementRate` | 编码/能力校验 | 实际管理帧速率 / P1 |
| RSSI 拒绝、弱信号踢除、公平调度 | `RadioAdvanced` | 编码/条件字段 | 实际门限、踢除和负载效果 / P1 |
| MU-MIMO / OFDMA / TWT / 6 GHz | `RadioAdvanced` | 编码/条件能力；当前 AP 部分模型回读 | 具备终端和频段条件的空口/吞吐验收 / P1 |
| 单射频动态信道 DCS | `DCSConfig` | 编码/能力集 UI | 支持型号实际扫描、避让与重选 / P1 |
| EDCA 八队列、模式、AP 上报场景 | `EDCAConfig`、AP 0xce 解析 | 场景解析、字节测试、另一型号能力 UI | 型号专属场景及实际队列效果 / P1 |
| 无线射频速率表 `apmng_rate.rate_11*` | rates.go / 完整 a/b/g/n/ac/ax 编辑与 UI | 55 字节 golden、模拟应用/失败重试/移除恢复默认 | 真实吞吐/空口、不同 AP 能力 |
| 全局 RRM 自动/手动优化、规则与分组 | rrm.go / rrm_jobs.go，规则/分组/日期计划/任务/UI | 测量图算法/模拟；真机 NDP→计划→回读→commit 后恢复原配置 | 多 AP 干扰改善与功率效果 |
| 双频优选 `apmng_band_navigation` | 全局策略、按 AP 生效条件、同步联动和 UI | 参数回读；关闭任一频段后不再错误引导，双频矩阵通过 | 可用性已回归；主动引导效果仍需受控比较 / P0–P1 |
| RSSI 频段引导 `reject_*` | `AdmissionControl` / 私有 0x4c | 编码/能力门控 | 支持此功能的型号实机；与全局 0x3a 分开 / P1 |
| 客户端数/RSSI 负载均衡、规则分组 | mobility.go / balance_decision.go，规则/AP/分组与准入 | 模拟最近覆盖/同服务/VLAN/阈值/有界拒绝/失联回退 | 多 AP 真实负载迁移 |
| 无缝漫游、网络模式、低速/低信号策略、差值及规则 | k/v/r 参数、规则、自动/高性能/兼容、ACS扫描/共同信道、候选选择与结果分发 | 双 UDP AP、失败重试/全部 ACK 后 hysteresis；单 AP 真机模式/统计/ACS/提交通过 | 多 AP 实际切换；三射频高低5G分段已补模拟，仍需对应实机 |
| 802.11k/v/r | private57 配置与 AP 触发/候选协议；只由真实上报确认客户端位置 | 独立 wire 序列、双模拟 AP；真机参数 ACK | 尚无双 AP 实际 k/v/r 协商/切换证据 |
| 客户端 MAC/IP/IPv6/AP/SSID/射频/RSSI/速率/流量 | `cweng/wsta.go`、NMS、客户端页面 | 真实平板与 AP 上报；位置/迟到事件测试 | 多客户端并发、多 AP 统计合并、长时间数据 / P0 |
| 客户端名称、备注、强制下线、列表导出 | client_management.go，编辑、CSV、强制下线 | CSV防公式/持久化/模拟；真平板msg25应答+AP disassociate确认，再连接 | 多终端与其它型号 |
| AP/无线状态趋势、射频统计、客户端信号历史 | history.go / client_history.go / history.js，24h射频/AP数量、1h客户端RSSI、7天确认连接事件 | 新鲜测量时间、IP更新不造点、保留时限、重启恢复/退出保存/事件顺序、AP替换排除、API/非空图UI | 长期磁盘/数据稳定性兼容记录 |
| AP 列表导出 / apmng_status.export_ap_list | ap_export.go / AP 页 CSV 下载 | 标签/分组/实际身份、在线客户端计数、已替换记录排除、凭据不导出、CSV文本转义 | 不依赖 AP 额外能力 |
| AP 选择性 DHCPv4 | 可选 Go dhcpserver；精确 Option60 TP-LINK，普通终端静默 | namespace真实 UDP；真实 AP 完整冷启动 Discover/OFFER/REQUEST/ACK，Android 请求静默 | 与普通客户端 DHCP/DNS/NAT 独立；后者仅实验工具 |
| Mesh Detect 特例 / DHCPv6 | 精确 TP-LINK MESH DETECT 1.0 的 Discover-only 分支 | namespace OFFER/静默 REQUEST 和负例通过 | AC 主机普通 DHCPv6 不纳入；AP 的 DHCPv6 防护保留 |
| 监听接口选择 | `admin` API/UI + 引擎绑定 | 当前专用 USB 接口实跑 | 变更需重启；跨平台接口支持约束 / P0 |
| 认证状态、认证管理、网络运维、云管理 | 用户明确排除 | 不作为缺项或完成数 | 不实现 |
| AC 主机级系统管理/网络设置/机器监控 | 用户明确排除；保留程序接口选择 | 不作为缺项或完成数 | 不实现 |
| AP 的 DHCP/ARP/ND 防护、风暴控制 | protection.go / storm.go / protection_scan.go；信任库、IPv4/IPv6 绑定、规则、代理、协议抑制及 UI；蓝牙/USB另列 | 混合地址 golden、UDP 假 AP、清空/校验；真实DHCP信任/拒绝、ARP有线探测过滤及恢复；旧/新防护标志按subcap16 bit0分支，当前型号ARP48/ND24容量防溢出 | 当前旧型号无线ARP范围不支持；ND/其它型号需对应环境，不能以ACK作行为证明 |

新增补齐记录（2026-11-26 20:45）：

| 功能 | Go 对应 | 当前证据 | 剩余验证 |
| --- | --- | --- | --- |
| 蓝牙规则/运维/价签/网关、MQTT/CA/过滤/主题/连接控制 | `admin/bluetooth.go`, `assets/bluetooth.js`，密码编码、持久化清理、AP 服务器状态 | 原厂 Vue + 运行时 JCS + uac；UDP 模拟完整命令、60KiB CA、删除/重启清旧连接、错误能力/凭据脱敏 | 当前 AP 不具备蓝牙，实际 BLE/服务器连通需对应硬件；没有用本机不报能力省略代码 |
| USB、蓝牙、Mesh 基本 AP 开关 | `APOptions`、继承及 UI/私有元素 | golden 与模拟；按每 AP 能力展示 | Mesh发现/配对/拓扑/子AP代理已有完整模拟；真实多AP组网未验收 |
| 冷 AP 关联初始化 | `cweng/v6profile.go` 必发 private26 mask6f/value2e | 完整 AP 重启 + Go DHCP + 平板新连接及反复开关 Wi-Fi通过 | 更多型号/长期稳定性 |
| 大配置发送分片 | `capwap/fragment.go` / Session DTLS 发送 | 60KiB 乱序重组与 UDP 模拟大证书 | 真实具备相应扩展能力 AP 的大消息 |

历史完整双频矩阵为 `20261126-204202-radios.json`：确认实际 wlan0 地址并等待提交后，五个阶段均 HTTPS/API 一致；不是仅拿缓存 IP 当成功。完整工作记录及私有证据目录见 `parity-worklog.md`。用户纠正后已停止继续 AP 吞吐/PHY 矩阵，后续以 AC 管理验收为准。

旧 `uacgo/AUDIT.md` 的完成标记是历史原型快照，不作为此表依据。那份审计把许多编解码/模拟与功能完成混在了一起，不能继续引用为“已经全做完”。


21:45 后续补齐（部分尚待本轮统一部署/实机复验）：

| 功能 | Go 对应 | 当前证据 | 剩余验证 |
| --- | --- | --- | --- |
| 物理下联端口与Trunk/LAG能力 | C8/12 packed端口、APDB4/5、AP设置UI | 稀疏ID103、上联排除、能力和JSON数字数组回显测试 | 对应有下联/聚合端口的实机 |
| 自动绑定频率顺序 | AutoBindFrequencies 16bit，准入/快照/漫游统一选频率 | 射频ID与频段顺序相反的UDP假AP创建、迁移、清理 | 多型号混用 |
| 整机射频工作模式 | BB列表、BC开关/原生ID、General92与UI | 原厂字节、模拟能力/稀疏ID、UI | 支持型号切换后重启及重报 |
| 射频关联约束RRST | 7f/90解析、Discovery表协议1、合法组合/最少联动、导入和运行期校验 | packed矩阵、截断/坏报文、两射频联动/失败原子性；当前实机未报此表 | RRM/ACS合法组合选择与不可行回滚已补模拟；BindID仅元数据，不杜撰SSID重映射；支持该表实机仍待 |
| Mesh配置和节点管理 | 回传/密码/自动已知AP接入/回传模式，发现/配对/添加/移除与拓扑、持久化成员名单 | 原厂源码、UDP/状态测试、UI；RE列表是授权同步，禁止伪装成无害刷新命令 | 真实多AP Mesh及子节点重新接入/角色切换 |
| Mesh子AP传输 | private75转发、独立子会话、父传输共享序号/请求门、独立ACK/报告归属、父断开清理 | 完整模拟Join/Configure/RUN/控制/报告，错误ACK与未授权身份、race | 真机代理转发 |
| 可选硬件JSON回显 | 蓝牙信道/LAG端口/射频ID使用数字数组，兼容旧Base64文件读取 | Go序列化与浏览器配置回显 | 对应真实扩展设备 |
| 复杂设置页面布局 | AP/分组、Mesh、蓝牙三个设置页签 | 2能力×10页×41表单，无JS错误 | 长表、多AP的使用体验 |


22:45 实机及代码复核追加：

- 开放、WPA2/WPA3（实际SAE）和隐藏SSID已分别真实接入/HTTPS；临时SSID和保存网络全部清理。限速/强制下线证据仍见上表。
- 固定VLAN100真实数据面通过：vlan-tests/20261126-224524.json。测试临时VLAN接口、DHCP/HTTP服务已清理，原GoAC-Lab和上网恢复。普通实验DHCP仍独立于产品选择性DHCP。
- DHCP防护：protection-tests/20261126-223833-dhcp.json，可信服务器可取地址，非信任服务器下Wi-Fi关联但45秒无IPv4；恢复上网。ARP：223257.json，匹配绑定3发3收，错误有线发送方3发0收。旧AP基本模式不支持单选无线端口，不能将此记为无线ARP已验证。
- 客户端API/CSV/UI/事件保留AP实际SSID、服务身份和VLAN，配置重命名或槽位复用不改写旧事实。真实VLAN100回报已确认。
- RRM按每台AP的合法RRST行联合选择；ACS在跨频段完整组合中选择合法次优解。继承禁用和传感射频不参加普通覆盖射频优化；失败不改配置。Mesh父子升级共享传输组，异常角色环规范化，升级与Mesh/重启/优化任务互斥。
- 当时新增源码已部署，基础ADB status通过224312。Go全测试/vet、核心race和2能力×10页×41个表单通过（新增蓝牙状态查询入口，ACK不显示为服务器已连通）。离线自管理结果已在下方追加。


22:57 追加：离线自管理 true/false 已分别停止Go服务实测，见工作记录。PSK修改正反通过，ADB保存网络清理已用精确network_id复查。RF模式/WMM/带宽组合校验与UI联动已部署，N/ac/ax/be不能关闭WMM；不适用的分片/ShortGI不再作为可编辑有效项。旧38次模型测试不是每项空口行为证明；23:00后已按用户要求停止该方向复验。


23:00 用户重新明确：停止将AP吞吐、PHY和每项硬件效果作为AC验收工作。速率表吞吐试验已主动中断并恢复；GoAC-Lab重新选择后HTTPS200。后续工作转为AC管理、数据与协议闭环及模拟测试；上述“仍待实机”属于兼容性记录，不再自动视为AC开发缺口。

23:37 AC 管理回归：Mesh 成员策略独立持久化/备份/迁移及日志压缩、AP 复制有效配置与射频复选框语义、客户端 RSSI 历史、AP 数量趋势、旧客户端表缺省 VLAN 与 AP CSV 导出已补齐。继承编辑及历史筛选不再写死 1–6，已有射频 8 和高级设置可回显保留。全 Go/vet、核心 race、ARM64/Windows 无 CGO 构建通过；两套能力×10页×49次表单、非空曲线与导出入口通过。基础 ADB status 在233608通过；最终包含界面修复的二进制重接入结果见工作记录。

23:39 最终二进制已重接入并提交配置；客户端最新报告/新会话RSSI历史、AP导出和数量趋势确认，无失败或受阻配置。本轮AC管理修复部署闭环完成。
