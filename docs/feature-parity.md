# 原厂 UAC/Web 与 Go 对应核查

2026-11-27。本表描述当前源码；实机仍运行历史 `587d414`。本轮没有以原厂运行结果、假 AP 或外部设备试验推导调度策略。算法的入口、计算和时序依据见 [策略对照](mobility-parity-audit.md)，版本哈希及129个函数指纹见 [静态清单](mobility-firmware-evidence.json)。

[原厂目录](original-feature-inventory.json)列出23个 AP 控制器模块，[双向索引](uac-web-parity-map.json)记录保留/排除范围、Go对应文件、回归入口和参考代码。`python3 tools/check_parity_map.py --verify-firmware` 检查模块遗漏、未归类的 Go 源码、文件失配和旧配置源被重新启用；它不替代语义审查。

| 保留功能 | 当前 Go 对应与本轮整改 | 主要依据/回归 |
| --- | --- | --- |
| 发现、DTLS、Join/Configure/RUN、心跳、重连 | cweng；会话epoch、同序号应答、重传/取消；统一 FIFO 将提交与ACK分开 | cweng生命周期/command_queue测试 |
| AP身份、名称、位置、设置、模板、分组、复制/替换 | management、options_capability；自动IP分组补入Join/规则修改，Mesh和升级分支保留 | 原apmng_set、5da88c/5f70f0；group_strategy/management测试 |
| AP重启、复位、定时和升级 | operations、upgrade、firmware；镜像/型号校验、传输/重连/实际版本分开 | upgrade/schedule测试 |
| 无线服务 | Open/PSK/WPA2-WPA3、隐藏、编码、隔离、限速、MLO、时间计划、组播 | apmng_wserv；service_wire/reconcile测试 |
| AP/频率/精确射频绑定、VLAN、池、删除提交 | auto_binding、assignments、wlan_state、vlan_pool；cap92虚拟位序与原模型模式列表一致 | 729de0/6fa788；auto_binding/assignments测试 |
| 射频模式/带宽/信道/功率/时序/人数/性能开关 | radio_*；RRST改原有序策略，默认和AX两阶段初始化；UI模式编号名称修正 | 73abf0/5dd2d8/7301dc/7304f0；radio_*测试 |
| EDCA八队列、型号场景和命名规则 | edca；补规则目标、频段冲突、解绑和Join语义，修正队列默认/范围 | 74108c/725b88/741dd0/8ec530；edca测试 |
| a/b/g/n/ac/ax速率表、DCS、RSSI限制、公平调度 | rates/radio_advanced；按AP能力控制命令与表单 | apmng_rate/apmng_rf；rates/radio_advanced测试 |
| 双频优选、RSSI频段引导 | band_navigation与射频Reject；删除额外SSID/VLAN/射频状态门禁 | 633a60；navigation_interlock测试 |
| 关联许可、容量、负载均衡 | admission、mobility/balance；原返回码、即时DB更新、0b发现和原计数时钟 | 744b70/4f6f54；admission/balance测试 |
| k/v/r、PMK、无缝漫游调度 | mobility纯计算+admin适配；真正4e5638选择器、原表/排序/回退、完整分包/AP并集；删除ACK冷却 | JAL4e713c、4e5638、4e46c0；mobility测试 |
| RRM信道/功率优化、规则和计划 | rrm原SCA/TPC+rrm_runtime；冻结集合、NDP/90秒/两轮/低高5G、原下发；统一RF写门禁 | 527c70→so+ab44→5094/677c；rrm测试 |
| AP/射频/SSID/客户端状态、名称、下线、导出和历史 | 52/53/54/c6/bd、BSSID索引、终端识别；MLO内部peer与展示折叠分离，迟到/缺测不造事实 | 74a4b0/7b4a30/7b1e44；client*/bssid/terminal测试 |
| Mesh配置、授权、发现/配对/增删/拓扑、子AP会话 | mesh；成员持久化、独立子会话共享父传输队列、错误归属和父断开清理 | apmng_mesh；mesh_*测试 |
| AP执行的DHCP/ARP/ND防护、绑定/扫描、风暴/代理和USB | protection/storm/APOptions；旧新能力、容量及混合地址，完整编辑与下发 | 原相应AP模块；protection/arp_scan测试 |
| 控制接口、选择性AP DHCP | 绑定接口；Go DHCP精确TP-Link标识、普通终端静默、Mesh Discover特例 | dhcpserver测试；普通客户端DHCP/DNS/NAT只在实验工具 |
| 配置/Web/恢复 | 一个正式配置来源；旧SQLite WLAN/RF和JCS不参与启动；API、能力表单、持久化/恢复/失败状态 | main真实进程UDP污染旧库回归；config_store；UI 2能力/10页/46表单 |

## 不属于产品的原厂内容

- AC Linux的网络/VLAN/系统管理、机器监控、本机无线同步；只保留程序监听接口选择。
- RADIUS、Portal、认证状态/认证管理/PPSK认证、云管理、网络运维、WIPS/Sensor、远程审计/统计推送、抓包/FTP日志。
- AP蓝牙已按用户要求删除产品配置、HTTP路由、表单、运行状态和能力展示；参考协议编解码不代表开放功能。
- V6 Web禁止修改网络模式，启动迁移固定为2；旧自动/高性能/共同信道ACS不是当前可启用功能。
- 共享Lua/SQL字段不自动算功能。rail字段明确不支持；central字段无当前有效消费链；calibration文件是批量命名。依据在策略对照中逐项说明。

## 证据的限度

源码推导/边界向量、Go UDP状态回归、HTTP表单提交、AP ACK、配置回读和实际空口效果是不同证据。本轮源码审查和回归不意味着穷举所有参数/型号，亦不意味着形式化等价证明。升级包缺失的flash profile容量/默认值不能拿重建QEMU配置补成“原厂值”；V4也未据此认定等价。当前改动未部署，多AP真实互通和硬件长期行为仍应另记兼容性结果。

历史设备测试保留在 [go-live-status.md](go-live-status.md) 和 Git `587d414` 的旧表；旧“最少联动”“ACK冷却”“可切换网络模式”和BLE完成记录已被本轮范围/源码结论取代。
