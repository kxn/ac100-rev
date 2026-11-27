# V4 网络模式控制、自动回退与共同信道参考

用户报告的软件是 **1.4.4 Build240911 Rel.65759n**。本次没有找到该版本的公开下载，按用户允许使用相近版本的要求，从[官方资料中心](https://resource.tp-link.com.cn/pc/docCenter/showDoc?id=1730963408141364)取得 **TL-AC100 V4.0 1.4.3 Build240715 Rel.80898n**。下载ZIP、升级镜像、UAC、62个UAC函数、5个uClibc函数、数据表和4个源码文件的摘要记录在 `v4-high-performance-evidence.json`。

下载包中的UAC与仓库原有 `firmware/usr/sbin/uac` 完全相同，SHA256为 `ddc30fd8aa14e206eaa119e403a4ada64584bef84020c825b8c579bfa4153c68`。这确认了旧二进制的来源；不能据此断言用户的1.4.4也相同。V4和提供的V6静态型号库解密内容也完全相同。

## 版本边界

`mode_source=tl-ac100-v4-1.4.3`现在统一选择V4模式控制、AP参数、共同信道/自动回退、候选与估速分支，配置模式支持0/1/2；不再把V4模式控制与V6候选默认拼接。PMK按两版共用语义实现，V4特殊同步的NULL缺陷明确修复。未标记的兼容2仍走V6族；AP协议兼容层保留现代上报支持，不宣称完整V4二进制或1.4.4整套逐函数等价。完整跨版本差异见[双向复核](cross-version-mobility-review.md)。未标记的旧Go原型模式值仍按此前V6迁移规则处理。

V4自动模式0已开放，并在导入时保留配置模式与实际模式。用户备份使用固定高性能1，导入仍保留1；Go新建配置默认兼容2。不能因备份未用自动模式就省略自动路径，也不能把配置0默认为固定1。

## 自动模式的入口与门限

`automatic_limits.aps/stations` 是策略门限，默认5/30来自 `_wsta_roam_read_config@480fe8` 读取profile `apmng_roma.high_performance_ap_cnt/high_performance_sta_cnt` **失败时的代码回退值**，不是硬件容量，也不宣称是缺失Flash中的实际值。Web可修改这两个门限。`current_network_mode` 是持久化的控制器状态，Web读取展示；同一自动配置的普通保存不能借此强行升档。

| 入口 | 原固件证据 | Go行为 |
| --- | --- | --- |
| 初始化、手工切换 | `check_cur@486994`；直接调用仅来自 `pkt_init@48a0d8` 和 `manual_change@489c9c` | 配置0且实际已为2时，普通初始化保持2；手工从其他配置模式改选0才重查AP数和STA数，两者均不超过门限才选1 |
| 新AP进入RUN | `pkt_init@489fc0` 注册 `ctl_pkt_send_cb@489930`；`multi_link_status_switch@6632bc` 先回调再递增计数 | 计入本次AP后数量严格大于门限才退到2；不调用客户端路径的信道重分配。AP-entry角色7（sensor，原始ProductType2）独立计数，不混入普通AP数 |
| STA关联 | `pkt_init@48a008` 注册优先级9的 `sta_stats@484d2c → sta_change_ap_info@484c00` | 已更新关联总数严格大于门限才退到2；默认在第31个触发，随后遍历AP决定是否重分配 |
| STA统计关联 | `uac_stats_init@673228` 注册优先级10的 `stats_sta_assoc_cb@672eac` | 在自动决策后才迁移/新建统计行；新行上下行原始值为uint32最大值，旧行重关联不清速率 |
| STA或AP离线、普通周期 | 没有调用 `check_cur` 的此类入口 | 不凭负载下降自动升回1；重新选择0需要先切换配置模式 |

`wsta_db_sta_assoc@63c5e0` 在关联回调前已插入全局及AP列表，因此总数包含新客户端。反向枚举所有符号范围内的J/JAL（含尾跳转）得到6条直接分支；另以Ghidra导出上述3个注册根的17条非流程函数引用，覆盖AP回调、STA回调、重分配foreach以及统计生命周期注册。指令、目标和所属函数均记录在证据清单。直接枚举不声称能解析任意计算函数指针。

## 客户端超限后的信道重分配

`_set_rd_info_by_sta@484fd0` 仅在实际模式2执行。对每台AP，关联数必须小于 `floor(STA门限/AP门限)`；该AP统计表中满足上行或下行原始值 `>1` 的条目数也必须小于此商，才有资格改信道。统计遍历包括离线后暂存的行；未知速率的uint32最大值也按原比较算活跃。离线行在905秒后、60秒扫描时删除；Go沿用StationDB的生命周期，没有另造仅数在线客户端的替代算法。

每台符合条件的AP分别执行 `srand(time(NULL)); rand(); rand()`，使用镜像里的uClibc type3、degree31、separation3加法发生器和310次预热。两次随机数乘10先按uint32回绕；2.4GHz索引是 `%3+1`，5GHz索引是 `&7` 后再 `+1`。原始连续表为 `1,6,11,0,36,40,44,48,149,153,157,161`，实际输出2.4GHz为6/11/0，5GHz为40/48/153/161；2.4GHz取0表示保留信道。这里没有用Go随机库、统一轮转或均匀分配替换。只修改存在的RF记录的channel，带宽、功率及其他配置保留。

自动回退的参数下发先9d再57，再应用需要改变的RF。回退后新加入的AP按原兼容入口只需57；显式的独立程序静默覆盖仍可应用。AP能力72和25各自判断。若回退发生在RRM共同信道扫描中，终止原扫描，由RRM业务等待观察状态；回退至实际模式2后续功率阶段可继续，不重新启动信道阶段；若仍为高性能1，原pwr_rrm_start拒绝TPC，Go已纠正此前错误接续功率阶段的行为。

## 入口与执行

| 入口 | V4代码 | Go对应与行为 |
| --- | --- | --- |
| 固定模式切换 | `manual_change@489c08 → check_cur@486994 → change_handle@484624` | 显式模式设置，先下发模式静默块和漫游参数，再进入ACS；Go异步管理入口共用参数下发屏障，手工扫描和RRM不能抢先启动计时；固定1不按客户端数量自动退到2 |
| AP上线 | `ctl_pkt_send_cb@489930 → set_rd_info@484800` | 加入时沿用已确定的三个频段槽；双频AP优先低5GHz槽，空时回退高5GHz槽 |
| AP报告信道变化 | `rd_chnl_changed_by_subdev@485e48 → update_high_per@482dfc` | 配置为自动或报告等于配置时，只能填充未确定的槽；不能让后上线AP任意覆盖共同信道 |
| 手工信道变更 | `rd_chnl_modify_by_manual@489b60` | 强制更新对应频段，并按该频段传播；高5GHz事件不能被双频AP的低5GHz槽覆盖 |
| 无线优化的信道阶段 | `chnl_rrm_start@4ad1d8 → do_acs@486710` | 高性能模式使用全局共同信道ACS，不使用兼容模式的SCA候选集；后续功率阶段继续现有TPC流程 |
| 扫描请求 | `start_acs_send@483f7c` | capability72独立筛选；private9b，dwell100、零基radio、`1 6 11`及`36-48 149-161` |
| 扫描报告 | `pkt_init@489f2c → event_listener@489380 → scan_report@489024` | 仅消息9的第一个private9c参与协调；AP身份和当前会话保留。原监听器不额外要求报告AP属于预期名单 |
| 收集与选择 | `chnl_handle@486aa8 → worker@4857a8` | 各AP同信道BSS与负载求和；正常分支先最小BSS再负载，有任一reject=1时使用最小负载分支 |
| ACS完成下发 | `collect_chnl_set_to_ap@485524` | **独立于上线入口**：双频AP使用本轮overall-best5；三射频按频段分配。不能把它合并成low5优先 |
| 配置传播事件 | `rdmngr_callback_proc@613634` | AC内部改信道事件2、AP报告事件4、手工事件5分开；RRM/ACS内部写入不递归当成手工变更 |
| RF应用 | `_rd_chnl_bw_set@6301e8` | 信道与自动带宽2一起生效；Go只保存这两项覆盖，不把整份继承高级参数固定下来 |

private9d只带次数/静默秒数，不带模式号。capability72与private57使用的capability25分别判断。高性能private57将两频段的触发类型改为RSSI，并使用高性能RSSI门限；K/V/R、踢除等独立字段保留。

扫描容器等待 `get_acs_timeout()+1`，UCI值0时getter返回5秒。RRM业务另等 `timeout()+6`；若扫描仍在进行，最多重新等待10次。没有任何有效样本时原代码使用1/36/149默认值；所有AP均离线时不应用。Go没有从其他统计流编造扫描分数，也没有把失败样本当成成功测量。

模式静默参数分别可配置。备份未提供的Flash初值使用明确的Go默认值3次/30秒，不能冒称为原机器默认值。

## 明确修复的源缺陷

V4正常BSS分支搜索相反5GHz频段前，没有清空已用于overall-best5的临时变量；找不到另一频段时，可能把旧值当成新的候选。按用户“不复制明显bug”的要求，Go使该输出独立为空，并使用源码已有的36/149回退。有候选时的排序，以及reject分支使用另一频段默认值的行为均保留。该差异单列 `v4-acs-empty-opposite-band-output`，不伪装成完全逐字节一致。

## 验证

```sh
python3 tools/audit_v4_reference.py
python3 tools/check_behavior_contracts.py --verify-firmware --run-tests
python3 tools/check_parity_map.py --verify-firmware
go -C uacgo test ./...
```

V4参考解包目录为 `.local/ac100/v4-review/rootfs/`，与V6目录分开。代码摘要和命名回归用于定位证据与防止回归，不构成穷尽语义等价证明。没有运行原UAC，没有用实机测试推导上述策略。

自动模式补齐阶段的验证记录：57个分支合同对应179个命名回归均实际执行通过；全套Go测试、vet和admin/cweng/mobility/vendorbackup的race检查通过，Linux amd64/arm64静态构建通过。V4反向核对含62个UAC函数、5个libc函数、6条直接分支和17条注册根的非流程函数引用。这些是静态证据与回归覆盖的范围，不把数字当作穷尽等价证明。本轮没有部署或修改运行中的AP。

后续V4/V6跨版本审查补齐候选、估速、伪关联和均衡策略消费者；当前结果以[跨版本复核](cross-version-mobility-review.md)为准。原固件异常及保留/修正理由见[清单](firmware-mobility-quirks.md)。

漫游/客户端策略与独立射频优化现按功能分别选择，后者每条规则可选V4 DCA/TPC或V6 SCA/TPC，见[策略版本设置](component-strategy-versions.md)。
