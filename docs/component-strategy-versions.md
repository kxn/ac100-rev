# 按功能选择策略版本

版本选项分别属于功能，不存在修改整台控制器的全局V4/V6开关。选项选择Go中的原策略实现，不给AP刷固件，不改变型号能力解析的优先级。

| 功能与页面 | 配置/API | 可选行为 |
| --- | --- | --- |
| 无缝漫游 → 策略版本与默认漫游 | `mobility.mode_source`，`POST /api/mobility` | `tl-ac100-v4-1.4.3`或`tl-ac100-v6-1.0.3`；候选、估速、均衡消费者、关联结果码及网络模式作为一个客户端策略族配套切换 |
| 自动射频优化 → 每条规则 | `rrm[].strategy_version`，`POST /api/rrm/rules` | `v4`：DCA/TPC；`v6`：SCA/TPC。任务冻结规则，手工与自动计划使用同一选择入口 |

已有未标记的兼容配置和优化规则保持V6。旧V4来源标记仍选择V4客户端策略。新建Go配置默认V6；V4备份转换保留V4客户端来源，并为其原RRM设置明确选择V4，不再合并两个5GHz候选域。修改漫游设置不修改优化规则，修改优化规则也不修改漫游设置。规则保存、备份/恢复、重启保留各自选择。

V4客户端族可选自动0、高性能1和兼容2；V6原产品入口只允许兼容2。V6射频优化在高性能网络状态下明确拒绝启动，避免其独立信道结果与共同信道机制冲突；进入兼容网络状态后，各漫游/优化组合均可选择。V4高性能信道优化仍走原共同ACS入口；`pwr_rrm_start@4ad448`只接受实际模式2，任务明确显示跳过不支持的功率阶段。自动模式在ACS期间回退为2时，原后续功率阶段可以继续。

## 策略范围总览

下面按当前Go代码的职责归类。两处版本选项不代表只有两种策略，也不代表所有配置项都应增加版本开关。这里的“已实现”指当前代码具有该功能，不等于已证明V4/V6每条路径相同。

### AC计算或协调的无线策略

| 策略 | 决策内容 | 当前版本处理与代码入口 |
| --- | --- | --- |
| 漫游候选选择 | 邻居筛选、排序、跨频段偏好、信号/速率门限、无候选回退、结果数量 | 已证实V4/V6有差异，随客户端策略选择；`roaming_policy.go`、`roam_decision.go`、`mobility/legacy_select.go`、`mobility/select.go` |
| 漫游候选速率估算 | RSSI、带宽、空间流、PHY/MCS及Mesh回传速率如何参与估算 | 已证实V4/V6有差异，随客户端策略选择，没有单独开关；`mobility/policy.go`、`mobility/rate.go` |
| 接入负载均衡 | 根据AP客户端数量、发现记录、数量差及拒绝次数允许/拒绝新接入 | 已核对部分明确差异：MLO计数及均衡对漫游参数的影响；当前随客户端策略选择，没有独立版本开关；`balance_decision.go`、`mobility/balance.go` |
| 关联准入及目标预检查 | 服务/射频是否有效、容量是否足够、是否执行均衡检查及返回何种结果 | 已确认版本返回码及V4候选伪关联预检查不同；随客户端策略选择。不是RADIUS/Portal；`admission.go`、`roaming_policy.go` |
| 网络模式自动回退 | 自动/高性能/兼容模式，AP/客户端数量触发，回退后的低负载AP信道重分配 | V4具有活跃产品路径；V6产品只开放兼容2。当前包含于客户端策略设置；`automatic_mode.go`、`mobility/automatic.go` |
| 高性能共同信道ACS | AP加入、手工修改、扫描完成时如何协调共同信道，超时如何回退 | V4高性能路径，和普通RRM信道算法分开；`high_performance.go`、`mobility/high_performance.go` |
| 全网RRM信道优化 | 分组、邻居干扰图、信道枚举、双5GHz关系及失败保留 | 每条RRM规则选择V4 DCA或V6 SCA；`rrm_v4.go`、`rrm_runtime.go`、`rrm/v4.go`、`rrm/channel.go` |
| 全网RRM功率优化 | 使用哪些邻居、目标RSSI、功率上下界、量化、测量轮次及停止条件 | 每条RRM规则选择V4或V6 TPC；与该规则的信道优化配套，不分别混搭；`rrm_v4.go`、`rrm_runtime.go`、`rrm/v4.go`、`rrm/power.go` |
| 快速漫游PMK协同 | 密钥缓存的服务隔离、查询/特殊同步、断开保留、失败清理 | 两版核心流程已双向对照并共用；原V4 NULL缺陷有意修复，不提供“恢复bug”的版本选择；`pmk.go`、`mobility/pmk.go` |
| 多射频联动/互斥匹配 | 修改一个射频后，按型号关系表选择其他射频的信道、带宽、PHY；匹配顺序也影响结果 | 当前按已核对的V6 RRST有序策略及AP关系表执行，没有独立V4/V6选择；尚不能宣称已完成完整双版等价核验；`radio_linkage.go` |

前九项并不都是独立菜单：前六项及PMK相关适配属于当前客户端策略模块，RRM信道/功率属于优化规则。负载均衡和网络模式目前仍与漫游版本绑定，这个实际边界不能表述成“所有策略都已可独立选版本”。

### AC配置、由AP执行的策略

| 策略 | 当前程序的职责与边界 | 代码入口 |
| --- | --- | --- |
| 全局双频优选 | 下发5GHz客户端门限、差值及失败次数；实际频段引导由AP执行 | `band_navigation.go` |
| 射频RSSI频段引导 | 独立下发RSSI门限和差值；不是上一行的同一开关，也不是跨AP漫游选择器 | `radio_advanced.go`的`Reject`/private4c |
| 低信号接入限制/踢除 | 下发射频的RSSI拒绝、踢除开关和门限；与AC目标AP预检查分开 | `radio_advanced.go`的`RSSIRestrict`/`RSSIKick` |
| AP本地动态信道DCS | 下发检测周期、占用门限、容忍度及重选控制；不是Go在后台另算一套全网RRM | `radio_advanced.go`的`DCSConfig` |
| EDCA/WMM及Airtime公平调度 | AC解析型号场景、规则和手工覆盖，下发队列参数/开关；竞争和空口调度由AP执行 | `edca.go`、`radio_advanced.go` |
| 无线速率表、限速及PHY开关 | 下发基本/支持/MCS/组播速率、按SSID或客户端限速，以及MU-MIMO/OFDMA/TWT等能力参数。Go不实现AP的实时速率自适应或OFDMA调度器 | `rates.go`、`service_advanced.go`、`radio_advanced.go` |
| Mesh准入及回传配置 | AC管理自动加入、成员授权、配对、回传模式及子AP会话；不能把这些概括成Go已实现AP所有选父/路径优化算法 | `mesh.go`、`mesh_members.go`、`cweng/mesh_*` |
| DHCP/ARP/ND防护、广播抑制及组播 | AC选择规则目标、生成信任表/绑定和协议参数；数据包过滤、代理、组播转单播等由AP执行 | `protection.go`、`storm.go`、`service_advanced.go`、`multicast_groups.go` |
| AP离线自治 | AC下发离线自管理、保活及客户端空闲等配置；AP失联后的本地行为不能只凭Go有这个开关就宣称所有型号相同 | `management.go`、`management_wire.go`、`cweng/liveness.go` |

这些模块已有Go配置及能力分支，但未因本轮增加选择器而自动获得完整的V4/V6逐路径对照结论。需要核对的是AC参数、默认值、触发与下发路径；升级包只有AC代码的地方，不能凭它证明AP内部算法。没有独立版本开关，也不等于两版已证实完全相同。

### 其他自动管理规则

| 规则 | 当前职责 | 代码入口 |
| --- | --- | --- |
| AP自动分组及配置继承 | 按IP范围、Join/编辑事件和Mesh父子关系分组；决定全局、模板、分组、单AP、单射频覆盖的顺序 | `group_strategy.go`、`management.go`、`radio_inheritance.go` |
| SSID自动绑定和WLAN槽位分配 | 根据AP型号/射频模式选择服务目标及实际radio，分配并保留AP本地槽位；VLAN池配置下发AP，不在Go中另造每客户端选VLAN算法 | `auto_binding.go`、`assignments.go`、`vlan_pool.go` |
| 时间计划 | 决定无线服务、LED、AP重启、RRM任务何时生效及计划冲突规则 | `schedule.go`、`operations.go`、`rrm_schedule.go` |
| 可选AP专用DHCP | Go自己判断是否为精确TP-LINK标识、是否为Mesh发现探测、是否响应及分配租约；普通客户端静默。与AP的DHCP防护完全不同 | `dhcpserver/server.go` |

上述管理规则当前没有独立V4/V6版本选项。AP身份/能力库选择、状态数据有效期、协议重试和配置提交顺序也会影响结果，应作为共同约束单独核验；不把所有状态机、超时或普通Beacon/DTIM数值都包装成可切换的优化算法。

如果继续细化版本控制，应先补齐均衡/网络模式与漫游的依赖清单，再逐项核对射频联动、双频/RSSI引导、DCS和EDCA的两版控制端实现；有真实差异再讨论独立选项。这个顺序是后续核查建议，本次仅整理清单，未新增这些版本开关。

## 漫游差异

| 项目 | V4 1.4.3 | V6 1.0.3 |
| --- | --- | --- |
| 候选排序 | 先单独处理5GHz，再处理2.4GHz | 候选统一排序，以估计速率为主，再比较频段和RSSI |
| 正常候选 | 信号差值分支；同频使用配置差值，5→2额外减5dB，2→5无额外差值 | 估计速率至少提高20%，且至少增加20Mbps，同时检查信号与负载 |
| 无正常候选 | 不引入V6弱信号兜底；不输出该客户端结果 | 当前RSSI严格低于−85时有排序首项回退；允许空候选结果 |
| 未知率 | 允许按原RSSI差值比较分支参与 | 正常筛选拒绝未知率，仅可能进入弱信号回退 |
| 估速输入 | RSSI+95；自动PHY最高识别HE，配置12/13回退HT | RSSI+85；识别EHT及配置12/13 |
| MLO均衡计数 | 每条MAC记录计数，包括peer | 排除peer，按逻辑客户端计数 |

候选门限、BSTM自身首项、伪关联及PMK的细节见[跨版本双向核对](cross-version-mobility-review.md)。两版PMK基本流程共用；原V4特殊同步NULL参数缺陷及原V6空邻居候选复用缺陷保持有意修复。协议/功能能力层继续按AP当前上报与协商库支持Wi-Fi7设备；V4估速对EHT的限制不能解释为V4不能管理该AP，也不能暗中套用V6估速后称其为V4策略。

## V4独立射频优化的代码依据

与V6库分开实现于`uacgo/rrm/v4.go`和`uacgo/admin/rrm_v4.go`。静态指纹、全部相关符号的反向直接分支及初始化注册见[v4-rrm-evidence.json](v4-rrm-evidence.json)，检查命令为`python3 tools/audit_v4_rrm.py`。未运行原UAC或使用实机推导策略。

| 原入口/函数 | Go中的对应行为 |
| --- | --- |
| `uac_rrm_init@4af92c`、`_rrm_jcs_manual_rrm_set@4ad8e4` | 手工与计划进入同一任务；规则冻结；无优化内容拒绝启动 |
| `chnl_rrm_start@4ad1d8`、`pwr_rrm_start@4ad448`、`_rrm_task@4aef30` | 信道和功率分开收集；每次90秒；AP收集不足半数时对应阶段不应用。信道主循环检查2G/5G1，5G2在5G1前计算；功率检查三个组 |
| `rrm_collect_active_ap@4a8fa0` | 正常/CAP角色和有效射频；具有子节点的CAP跳过；每AP最多一个2G、两个5G的原算法拓扑适用范围。不是Go程序AP总数容量限制 |
| `rrm_ap_para_neighbor_add@4b21b8` | 定向AP图；接纳前六个邻居，已有边可更新；使用全部样本，累积`(RSSI+100)^2/100`，不加V6截断或EWMA；相同权重按原插入位置处理 |
| `run_DCA@4b07f8`、`dfs@4b0180` | 按有符号16位总干扰选根，枚举根及其出边邻居；只接受严格改善，同分保留；孤立AP的信道为−1，保留原信道和带宽 |
| `rrm_add_co_chnl_itf@4b2be4` | 先优化第二5GHz组，再向第一组加入对应固定信道干扰；双5G第一组保留原颜色禁用位 |
| `_rrm_pkt_rssi_request@4adad4` | Mesh开启时，符合单样本条件的2G观察投影到父AP首个5G射频；普通AP对不额外投影 |
| `_rrm_ctl_packet_create@4aae64` | private5c：−85、period1、duration60、max-neighbor6、expired0、每组第一个候选信道；功率阶段PHY/带宽为254保留值，不使用V6的低/高段两次扫描 |
| `rrm_get_apdb_pwr@4ac8e4`、`_apdb_pkt_parse_radio@60e514` | capability38使用APDB11/12/13物理功率字段，逐字段零值回退；共享能力视图统一编辑/校验/优化所用功率单位 |
| `run_TPC@4b1750`、量化函数`4ab198/4ab23c` | 原始RSSI、每射频最强三个入邻居、阈值/功率范围全频段共用、最大步长30、最多两轮；保留排他上下界，每轮清空邻居表，允许新邻居加入；孤立射频提升不触发新一轮 |
| `rrm_channel_set_to_all_ap@4aba4c`、`rrm_pwr_set_to_all_ap@4abe64`、`rrm_set_to_all_ap@4ac130` | 独立应用信道/带宽与功率；收集失败保留该阶段配置，功率单独优化保留信道/带宽；160MHz与BE模式仍通过原RF能力/联动约束 |

原内部`run_smooth_TPC`受默认0的调试开关控制，产品Web/JCS设置入口没有该字段；未将其疑似空循环变成可启用的产品策略。日志、原AC硬件容量、主机校时和调试CLI不属于移植范围。

静态证据和命名分支回归不代表穷尽所有参数/型号的语义等价。V4参考仍是用户允许的1.4.3，未取得其机器的1.4.4。
