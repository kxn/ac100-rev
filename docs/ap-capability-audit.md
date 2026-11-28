# AP 能力与型号限制复核（2026-11-28）

本轮从现有 Go 的能力判断、页面可见性和原固件发送入口双向检查，覆盖本程序保留的 AP 配置、状态、漫游和调度路径。基础配置协议以 V6 UAC 为依据；V4/V6 漫游及独立优化的算法选择维持各自策略，不因取消型号限制而改变。排除的认证、Portal、蓝牙、云及 AC 操作系统功能仍不启用。

原始固件、解包文件、生产配置、客户端信息和日志保留在本地忽略目录。公开索引只记录函数位置、摘要、Go 对应符号和测试名，见 [行为合同](uac-web-behavior-contracts.json)。下面的 `main` 为通用能力位编号，`subN bitM` 为能力 N 的第 M 位，均从零计数；两种编号不能混用。

## 取消的限制与保留的实际边界

- 删除原生射频的“仅已测型号及硬件版本”条件。TDCP 的发送资格来自 **main49**：V4 `_send_tdcp_request_to_ap_by_id@50b9c0`、V6 `@58a0bc`，经 `apmngr_db_get_addr_by_capacity` 过滤。main70 是 AX 扩展，main66 是 PMK 分支，不能代替49。
- 原生射频、双频优选、客户端快照、诊断读取、设备原生操作和遥测订阅统一经过 `cweng.requestJSON`，通知与等待回复共用会话事务编号。无 TDCP 的 AP 继续使用其 CAPWAP 配置和上报入口。
- AP 替换按原 `apmngr_ap_edit_ap_replace@5d87c0` 比较型号，去掉额外的硬件版本相等条件。迁移后的配置仍校验目标 AP 实际能力。
- 去掉“无 main81 就拒绝超过16MiB固件”的限制。普通升级发送入口 `apupd_update_wtp_image_request_send@786f08` 没有该筛选；`apupd_large_image_info_send_by_capwap@794ce0` 的 AF/B0/B1 扩展才要求81。16MiB保留为 Go 的流式传输分片参数，不是设备兼容性结论。

继续保留：型号库按准确型号/硬件及协商固件索引取元数据；用户自己设置的型号模板筛选；镜像声明的型号/硬件兼容性；明确配置的绑定、访问控制和替换旧身份退役。这些不能当作“实验设备白名单”删除。

`protectionLimits` 中仍有一个型号/硬件条件：已取得的 AP DMS 固件 ARP/ND 解析器分别只分配48/24项缓冲区（`@c9d64`、`@ca330`），后续处理使用收到的计数。这是已知解析器容量约束，不是仅允许该型号使用防护；其他型号继续走通用协议上限，不借用这个设备的容量。DMS 输入摘要：`a4bbe07741ea0eaceb890466aba21bd0d74670e72388addd188c50c92ec08b71`。

## 能力检查对应表

| 能力 | 原固件路径与判断 | Go 对应路径 / 复核结果 |
| --- | --- | --- |
| main1、9、10、21、57、61、70 | `rdmngr_wtp_pkt_send@73ea84`：弱信号、DCS、公平调度、RSSI频段引导、管理帧速率、EDCA、AX扩展 | `radio_advanced.go`、`radio_inheritance.go`、`options_capability.go` 与页面；公平调度字段名由误导性的 fragmentation 改为 airtime |
| main70 的AX速率表 | `rdmngr_wtp_pkt_send` 内 `@740308` 只查通用位70 | `radioRateElements` 供速率设置与高级射频共用；AX统一按70，AC按5GHz及AC能力；补齐高级批次漏发的AC表，不再用不同门禁 |
| main38 | `rrm_get_apdb_pwr@4ac8e4` 选择物理功率视图 | `finalizeRadioCapabilities`；上报能力和型号库回退都经过同一归一化 |
| main70 + radio1 扩展 bit8–13 | `@73d0f0 / 742e24 / 73ea84` 使用第一个射频的 DL MU、UL MU、DL OFDMA、UL OFDMA、TWT、6G 位控制所有射频；GI 随 TWT 位序列化 | 原始逐射频能力保留供诊断；`control_features` 单独表达 AC 的实际控制条件。显式空控制表不会回落到原始能力。无 TWT 位不显示/接受正数 GI 设置 |
| main61 sub0 / sub1 | `edca_rule_to_ap@74108c`：预设场景 / 模式 | `edca.go`、`resolveEDCA`；场景值来自该 AP 的0xce报告，不按实验机写死 |
| main3 | `band_navigation_wtp_packt_send@633a60` | `band_navigation.go`；3a配置和原生模型读写资格49分开 |
| main24 | `_stats_ctl_pkt_send_cb@7b5ad8`、`stats_pkt_ctl_update_to_all_ap@7b5c58` | `applyReporting` 补齐发送资格；接收现有统计仍按各报告格式处理 |
| main25 / 72 / 27 | `wsta_intelligent_roam_ctl_send_to_ap@4e9534`、网络模式发送、RRM收集链 | 漫游控制/结果分发、模式下发、独立优化接收方；反查 `wsta_intelligent_roam_ctl_send_to_ap` 的四处调用及 `update_to_all_ap` 调用，现有入口附加筛选参数均为0，不自行启用其潜在main53筛选；既有 V4/V6 分支见[跨版本复核](cross-version-mobility-review.md)，不扩大或缩小到实验机名单 |
| main66 | PMK 请求及关联的特殊分支 | `wsta.go` 与 PMK 策略；不再借用此位筛选客户端原生读取 |
| main13 | `_uac_wserv_packet_send_callback@6dbd74` | SSID限速；其他服务参数仍按其各自资格发送 |
| main63 / 32 / 都没有 | 同上：优先94，次选63，否则09 | `advancedWLANElements` 补齐09旧格式；开放和PSK数据的09/63公共段逐字节比较，RADIUS尾部不在范围内 |
| 每射频 WPA3 能力 | 同上调用 `apdb_support_wpa3_by_id`，不支持时 encryption4→1 | 去掉混合PSK服务整体阻塞及页面硬禁选；保留 auth/cipher/key 原值，只修改原代码修改的字段，并展示该射频兼容回退说明 |
| main43 | 组播全局、每SSID开关、查询及静态组成员发送入口 | `service_advanced.go`、`multicast_groups.go`；无能力不阻塞基础WLAN，注明不适用项 |
| main99 sub0 / sub1 | `_uac_wserv_igmp_snooping_parameter_to_ap@6d9ef8`、`_uac_wserv_pkt_igmp_snooping_config_send@6ecd34` | 独立处理转单播与MCS速率；补齐MCS配置、备份导入与页面。MCS用c9 type1，不混入70的Mbps列表 |
| sub95 bit1 | `_apmngr_pkt_join_req_listen@60b040`、MLO关联/统计入口 | `manage.go`、`wsta.go`、`wireless_statistics.go` 的MLO分支；保留源码直接读sub位的规则，不额外杜撰main95要求 |
| main98 + sub95 bit3 | VLAN池发送/能力衍生链 | `supportsPool` 与页面；不把端口扩展位误作VLAN池资格 |
| sub98 bit1 / bit14 / bit12 | `apmngr_pkt_config_update_request_pkt_send@6119c4`、`apmngr_ap_port_cfg_send@5ded4c` | 分别为扩展端口VLAN、启停、端口描述。按源码直接读sub，不统一追加main98门槛；去掉错误的sub77假设 |
| 旧1–4个LAN | `@6119c4` 的无扩展VLAN分支 | 单LAN私有30，多LAN私有43；完整向量替换，未配置位置用原默认0（不分配VLAN）。页面明确此默认，显式支持VLAN0。端口身份、上联排除仍取实际报告 |
| main14 + sub0/1/2/3 | `_uac_bcast_storm_ctrl_pkt_send_to_wtp@4afdcc`：ARP/ND代理、分类限速、转单播、mDNS | `stormElements`；补齐原有矛盾组合错误：有sub2而无sub0不生成空代理块。Go在发送前报blocked，原代码会先发基础块再报错，避免新增半批配置 |
| main15 / 30 | `_uac_dhcpdef_notify_ap@4b259c` | `protection.go` 的AP DHCPv4/v6防护；与本程序可选的选择性DHCP服务器是两回事 |
| main16 / 31 + sub16 bit0 | `arp_defend_wtp_pkt_send@4cacd8` | ARP/ND基础能力分开，扩展范围共用sub16 bit0，不因名称相近改成sub31 |
| main16 + sub1 | `uac_arp_defend_do_scan@4c4db0` | `SupportsARPScan`；修正误用sub0，扫描和扩展防护不再混淆 |
| main44 + sub1 | `mesh_pkt_bh_work_mode_send@53f248` | `SupportsMeshBackhaulMode`；修正误用sub0；Mesh加入、子AP传输、动作仍走main44及真实拓扑 |
| main42 / 71 / 73 / 92 / 100 与型号Trunk属性 | `apmngr_pkt_config_update_request_pkt_send@6119c4`、`apmngr_usb_wtp_packet_send@62258c` 等 | LED同步、聚合、FIT/FAT按键、射频模式、USB、Trunk；继承投影、显式AP校验、页面使用同一含义；未发现实验型号门禁 |
| 子能力记录长度 | `cw_priv_wtp_sub_capability_parse@6ae860` | 更宽记录保留定义范围内的低32位并继续读后面的记录；不再因size>4丢掉全部后续能力。不宣称实现尚未定义的高位语义；TLV项数按实际载荷边界校验，去掉额外128项门槛 |

通用能力位不是单一的“主位与子位必须都为真”规则。是否需要主位，要逐个发送入口核对：端口和 MLO 的直接子位，与 ARP扫描/AX/组播等组合要求不同。

## 原生模型和 CAPWAP 的边界

`nativeParameters` 只在原生模型能完整表达本次配置时使用该写法。`vhtmubfer` 是下行 VHT MU beamformer，不能代替上行 MU；`ofdma` 同样不能替代独立的上行控制。即使上下行意图相等，有独立上行能力时也走完整 CAPWAP 扩展。DCS、RSSI方向引导、EDCA和6G等无法完整表达的配置也走对应协议，不静默省略。

成功的读取缺少 `vhtmubfer`、某个可选字段或整个射频行，只能表示原生接口没有给出独立回读。状态维持“已下发，尚未验证”；实际返回一个与请求相反的值才是回读不一致。禁止、忙、参数错误、损坏格式和超时仍是失败，不能用旧通道成功掩盖。

原生枚举适配属于 Go 的控制器实现选择；固件的 CAPWAP 发送代码和本地 AP DMS 字段提供编码依据，不代表每个型号都已完成空口验证。模拟AP测试证明选择了正确入口、字节、失败和回读状态；不证明AP驱动已经执行。

## 信号问题的归因

已直接检查收到的 DTLS 解密明文 `plain-rx`，记录点在 `Engine.handleDatagram` 中、调用 `handlePlainDatagram` **之前**。该报文本身含 `wireless.sta_list`，字段原文已经是 `"rssi":"45"`；对应 ASCII 字节为 `22 72 73 73 69 22 3a 22 34 35 22`。这一步直接读取接收字节，不调用 Go 的 CAPWAP、TDCP、JSON 解码器，也不依赖分片重组后的推断。因此可以确定：**正数是 AP 发来的 JSON 原值，不是 Go 解析时丢了负号或做错符号转换。** 私有证据保留原始记录位置和明文摘要，不提交生产报文。

代码链路中，TDCP回复仅复制JSON字节；`nativeRows` 用 `json.RawMessage` 保存字段，`nativeString` 对字符串只做JSON解码，对数值保留原文，没有取绝对值、无符号整数或偏移换算。UDP端到端回归验证 `"45"`、`"-74"`、`45`、`-74`，分片回归逐字节比较这类回复，分别覆盖传输重组和客户端表解析。

后续已取得现场同版本3007与之前Wi-Fi7的官网固件，完成[上报路径交叉核查](ap-reporting-review.md)：3007原生表直接输出驱动无符号信号量，Wi-Fi7在JSON输出前减95；两者不能混为同一种dBm接口。现场3007的CAPWAP信号则走驱动统计中的减95路径，仍是负值。不能把“原生全是正值”作为跨型号结论。

确认的 Go 问题是：整表原生快照抹掉同位置已有的CAPWAP测量，并把原生实时流量误填成协商Mbps。现已分别保存 `native_signal`、`native_rates` 和带 `rssi_at` 的dBm采样；只有同一会话、位置、服务且仍连接时保留旧CAPWAP事实，不刷新旧信号的采样时间。3007的协商0值是AP发送代码的占位，页面显示未上报，不伪造实际PHY速率。

## 复核与运行边界

回归包括真实UDP模拟AP、能力组合、固定编码向量、失败应答、稀疏回读、会话替换及原生/CAPWAP信号合并；公开合同关联实际测试执行和固件函数摘要。页面用两组能力配置检查可见性和表单写入。通过这些检查不等于所有型号的所有硬件行为已验证，也不构成穷尽等价证明。

本轮运行日志检查只读，代码修改和模拟测试不自动替换正在管理生产AP的进程。
