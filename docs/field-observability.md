# 实机日志阅读与故障排查交接指南

这份文档面向接手 Go AC 的开发者和联调人员。重点是判断 **AC 收到了什么、执行了哪条策略、下发了什么、结果有没有得到后续事实支持**。

实测用于观察实现的行为。策略应依据固定版本的原固件入口、分支和编译数据核对，不能因为手机成功换了 AP，就宣称算法正确或全部路径已验证。策略背景见[跨版本复核](cross-version-mobility-review.md)、[入口审查](roaming-entry-audit.md)和[按功能选择版本](component-strategy-versions.md)。

本文中的设备标识、SSID、IP 和示例 ID 均为替代值。实测案例保留数值和行为，不包含真实网络身份。

## 1. 接手后的前五分钟

依次确认：

1. **运行实例**：实际二进制、启动参数、数据目录、绑定接口、管理地址。不要把实验配置、旧日志或另一个进程当成当前控制器。
2. **日志完整性**：事件日志确实开启；`run_id` 对应当前进程；`dropped`、`write_failures` 为零；没有轮转保留缺口。零计数也不能排除所查时间段已经被删除。
3. **设备身份**：客户端的当前 MAC、SSID、IP；AP 的 `ap_id`、型号、能力和会话。手机名称只是线索，随机 MAC 变化后必须重新匹配。
4. **实际策略**：客户端决策看 `policy`、`actual_mode`、`settings`；独立 RRM 看该任务自己的 `policy`。它们可以分别选择 V4/V6。
5. **证据等级**：把“算法执行”“发送成功”“AP 应答”“客户端换 AP”“业务连续”分别记录，不能合并为一个“成功”。

本地主机联调曾使用 `ac100-go.service`、`ac100-field-monitor.service`，运行目录通过 `.local/ac100/field-test/current` 指向当前场次。这是本地部署约定，不是程序的固定路径；换机器后以实际启动参数为准。

```sh
systemctl show ac100-go.service -p MainPID -p ActiveState -p NRestarts
systemctl cat ac100-go.service
journalctl -u ac100-go.service --since '15 minutes ago' --no-pager
```

查看启动参数和 unit 输出时注意本地目录及其他私有信息，不要原样贴进公开 issue。容器部署则检查对应容器的启动参数、卷和进程标准错误日志。

## 2. 日志在哪里、分别能回答什么

```sh
acd --data /private/ac-data \
  --event-log /private/ac-logs/controller.jsonl \
  --log-max-mib 32 --log-backups 4
```

| 来源 | 用途 | 局限 |
| --- | --- | --- |
| `--event-log` 的 JSONL | 决策输入、实际筛选步骤、命令、应答、状态变化 | 默认关闭；异步写入；有意不包含密钥和完整报文 |
| `--trace` 的 JSONL | 私有原始报文以及解密后的 CAPWAP，补查协议字段 | 可包含密码、PMK 等敏感负载，只能私下保存和分析 |
| 程序标准错误 / systemd journal | 启动失败、DTLS 错误、事件日志写入失败 | 不能替代结构化的决策链 |
| 监控器 `status.json` | 当前 AP、客户端、策略、配置失败及观察器状态 | 是轮询快照，可能错过短暂状态 |
| 监控器 `monitor.jsonl` | 状态变化、命令失败提示、部分策略事件副本 | 不复制完整候选和命令链；告警列表也不是完整诊断 |
| 只读管理 API | 当前库存和配置状态，用于与历史日志对照 | 当前状态不能反向证明过去某时刻的状态 |

`--trace` 也使用 `--log-max-mib`、`--log-backups`。默认每类保留当前文件和四个旧段，通常最多约 160 MiB；这个上限分别计算，不是两类日志合计。单条记录不会为了凑大小而拆开，大小上限不是严格逐字节的磁盘配额。

事件输出使用有界异步队列，磁盘写入不阻塞策略执行。队列满、编码失败或单条事件超过 64 KiB 会计入 `dropped`；写入失败计入 `write_failures`。这些计数在控制器进程重启后重新开始。

```sh
AC_API_URL='http://127.0.0.1:8090'
curl --fail --silent --show-error "$AC_API_URL/api/observability" | jq .
curl --fail --silent --show-error "$AC_API_URL/api/mobility/status" | jq .
```

出现 `observer.records_dropped`、`observer.retention_gap`、`observer.invalid_record`、`observer.incomplete_record` 时，先限定证据缺失的时间段。监控器重启会重新读取仍保留的事件段；它的 `event_counts` 不是永久累计计数，历史失败也可能重新出现在提示中。监控器计数也不会在控制器换 `run_id` 时自动清零，不能把跨运行的总数误当成本次进程的统计。

## 3. 关联日志时必须保留的维度

| 字段 | 含义与正确用法 |
| --- | --- |
| `time` / `at` | 事件时间 / 被描述事实的时间。事件 `time` 为 UTC；其他时间可能带本地偏移，比较前统一时区 |
| `run_id` | 控制器本次运行。不同运行中的数值 ID 不能直接拼接 |
| `ap_id`、`session` | AP 身份和连接建立时间。AP 重连后的同一序号不是原会话的命令 |
| `client` / `mac` | 客户端 / DHCP 端使用的 MAC 字段；不是所有事件都叫 `client` |
| `decision_id` | 一次候选选择；关联输入、筛选步骤和选择结果 |
| `job_id` | 一次漫游结果分发或 RRM 任务；不同事件家族不要混用 |
| `command_id` | 一次控制器排队命令；关联重试和最终结果 |
| `sequence` | 含义依事件而异。CAPWAP 序号会回绕，客户端状态序列是另一套计数 |
| `config_version`、`operation`、`item` | 命令所带配置上下文、业务操作和配置项，按实际存在的字段使用 |
| `observed_config_version` | 捕捉应用状态变化时的全局版本，不是 AP 已应用该版本的证明 |

注意现有日志的关联边界：

- `roaming.candidate_input`、`roaming.selection_step` 没有 `client` 字段，必须通过 `(run_id, decision_id)` 找回同一客户端，不能只全文搜索 MAC。
- `roaming.result_created` 没有直接携带 `decision_id`；需核对运行、源 AP、时间和 `result.Stations` 中的 MAC。结果可能分包，也可能包含多个客户端。
- `roaming.result_dispatch` 没有直接携带 `command_id`；命令上下文也没有贯穿漫游 `job_id`。并发时仅凭时间接近不能唯一认领某条 ACK；需要核对 AP、会话、`operation=roaming_result`、私有元素 `0x0059`，必要时私下核对 trace。
- Native JSON 的 `transaction` 与 CAPWAP 序号不同，目前完成事件没有完整贯穿该 transaction。HTTP `request_id` 也没有贯穿全部后续命令。
- 异步生产者和轮询快照有时间差。文件相邻不等于因果相邻；同一个回调中的日志出现，不代表所有并发链都已经结束。

这些缺口是交接时应知道的可观测性限制。不能为得到漂亮的报告，把缺失的关联字段当作已有字段。

## 4. 如何判断 AC 真正执行了漫游调度

正常的证据链是：

```text
roaming.trigger / station_report
  → candidate_path / rate_estimate
  → decision → candidate_input → selection_step → selection_result
  → result_created → result_dispatch
  → command.queued → transmit → response → completed
  → 目标 AP 的 client.admission → client.transition
```

| 看到的事实 | 可以得出的结论 |
| --- | --- |
| `roaming.trigger` | AC 收到 AP 的触发上报；尚未证明有有效客户端或候选 |
| `roaming.decision` | AC 确实运行了一次候选选择，记录了当时的策略和输入 |
| `selected_count=0` | 本次没有选出目标。V4 会略过该客户端的空结果，不应据此期待一条调度下发 |
| `selected_count>0` | 算出了目标；还要核对是否生成结果、排队、成功应答 |
| 两端 `command.completed` 成功 | 两台 AP 接受了调度命令；尚未证明客户端照做 |
| 目标 AP 随后上报关联，位置与所选目标一致 | 有“AC 选出目标、实际下发、客户端随后切换”的闭环证据 |
| 只有 `client.transition=roamed` | 确认控制器记录的位置改变；不能据此声称 AC 主动调度 |

`roaming.result_dispatch.target_ap` 是**命令接收方**，并不都表示“让手机漫游到这台 AP”。原 AP 和候选 AP 都可能收到结果。真正的目标要从 `result.Stations[].Candidates[].APIndex` 索引 `result.APs`；还要核对同一行的 `Radio`、`WLAN`、`BSSID`。结果中的 MAC 采用字节数组表示。

若没有 AC 调度包，但发生了关联切换，AC 侧只能判断没有这条主动调度链。手机自主选择与 AP 本地机制，不能仅靠 AC 日志再细分。

### 两条候选入口

- `path=reported_bssid_neighbors`：消费 AP 上报的 BSSID 邻居。核对 BSSID 定位、整份报告的信号编码、速率估算及能力。
- `path=cached_station_rssi`：上报没有 BSSID 邻居时，使用独立统计缓存。核对 `maximum_age`、目标会话、VAP 就绪、服务绑定和射频状态。

`bssid_not_known`、`missing_statistics_offline_or_radio_unavailable` 会让某个邻居进不了选择器；`invalid_or_mixed_signal_encoding` 会让该组信号不能用于这个入口。先查输入为何缺失，不要立刻降低门限。

`station_location_not_current` 常见于客户端已换 AP、旧 AP 的报告才到达。正常行为是忽略旧报告，不能把客户端位置改回去；若它持续出现却从未有过新关联，再查位置归属、缓存和会话隔离。

### V4/V6 筛选原因怎么读

| 原因 / 阶段 | 重点核对 |
| --- | --- |
| `directional_rssi_delta` | V4 的当前频段、目标频段、当前信号、候选修正信号和配置差值 |
| `rssi_threshold` / `channel_load` | 当前策略族、实际模式及各自边界，不能用同一组门限解释两版 |
| `unknown_rate` | 终端/射频 PHY、统计是否就绪、AP 角色与回传；未知率不等于零吞吐 |
| `rate_gain_twenty_percent` / `rate_gain_absolute` | V6 的相对及绝对估速增益，不能套用 V4 的“强多少 dB”解释 |
| `pseudo_association_denied` | V4 的目标射频容量、服务绑定及均衡分支 |
| `four_candidate_limit` | 编译上限导致停止，不是发送失败 |
| `weak_rssi_fallback_uses_last_band` | V6 的既有弱信号回退；回退选中不代表之前的正常条件都通过 |

V4 中 `phase=stopped` 有排序遍历停止的含义，并不保证后面的每一项都有独立拒绝日志。两版排序、未知率、边界和回退都不同，以[跨版本复核](cross-version-mobility-review.md)和相应实现为准。

### 不要把 RSSI 的几种数值混为一谈

原生 `wireless.sta_list.rssi` 与 CAPWAP RSSI 属于不同接口。`client.native_signal` 保存 `raw_value`、`interface` 和 `unit=unspecified`；客户端 API 的 `native_signal` 也只表示原始值。正数不能直接取负、减100或当百分比；负数同样不自动证明单位是dBm。这些原生值不供漫游估算使用。

`client.native_rates` 记录 `wireless.sta_list` 的 `tx_rate/rx_rate` 原值，API使用独立的 `native_rates`。3007对应固件由驱动流量差分产生这些速率，空闲为0；不能把它们当作协商Mbps。该固件的CAPWAP协商字段又被明确置0，因此“协商未上报”和“实时流量0”必须分开。Wi-Fi7的CAPWAP会提供正协商值。正负信号及速率来源的逐函数说明见[AP上报交叉核查](ap-reporting-review.md)。

`client.native_snapshot` 记录本次快照开始时间、AP会话与错误。快照没有可用RSSI时，只能保留同一连接位置已有的CAPWAP测量及其原采样时间；看 `/api/clients` 的 `rssi_at` 和页面“采样”年龄，不能把快照时间当成新信号时间。字段缺失后RSSI整列消失，或采样时间不断变新却没有CAPWAP报告，都应检查合并逻辑。


BSSID 报告入口的 `roaming.rate_estimate` 同时给出 `raw_rssi` 和 `adjusted_rssi`。当前固件派生的预处理包括减 10 dB、下限钳位；`candidate_input.candidate.rssi` 已经是候选侧用于筛选的数值，不能再减一次。缓存入口不要照搬这一步。

`roaming.signal_decode` 给出 `private58.neighbors` 的原编码列表、`decoded_dbm` 及候选余量/下限，数组顺序与原邻居一致。这里可能有正 RCPI 编码，不要把它与原生 JSON 的正 SNR 混为一谈。编码冲突仍按原策略记录 `invalid_or_mixed_signal_encoding`，不会用原生字段救场。页面客户端列表只显示统一 dBm；原始 JSON 信号/速率在该客户端“信号详情 → AP 原始上报（调试）”，不与正常指标混排。客户端详情/历史的展示缓存不是漫游的直接输入；完整路径和已确认缺陷见[上报及调度关系](ap-reporting-review.md#信号怎样进入调度哪些转换确实存在)。

以下仅示范 **V4 同频段**、配置差值为 8 的比较：

| 情形 | 当前信号 | 候选原始 | 候选参与筛选 | 候选减当前 | 结论 |
| --- | ---: | ---: | ---: | ---: | --- |
| 未选中 | −65 | −84 | −94 | −29 | 不满足至少强 8 dB |
| 选中 | −74 | −51 | −61 | +13 | 信号差条件通过，仍须通过后续检查 |

同频段判断可写为 `候选参与筛选信号 - difference >= 当前信号`。V4 的跨频段还有方向分支，V6 则使用另一套增益筛选，不能把这条式子当成所有模式的统一算法。V4 的 `current_rssi` 取触发报文，不应拿首项自身 Beacon 测量擅自替换；`current_rate=0` 也不能单独作为 V4 估速损坏的证据。

估算速率、AP 上报的协商速率、实测吞吐是不同量。PHY 的 Mode/Bandwidth/NSS/MCS 也必须在对应编码域解释，不能把 Go PHY 枚举直接当成 AP Native 配置枚举。

## 5. 配置、命令及重试要怎么追

配置链看 `management.request/response`、`configuration.persist`、`configuration.apply_state`、命令，以及后续 AP 上报。

- HTTP 请求成功或配置持久化成功，只说明控制器接收了配置；不代表 AP 已生效。
- `command.queued` 不代表已经发送；`command.transmit` 才说明进入了发送尝试。同一 `command_id` 的多次 `attempt` 是重试，不能统计为多次调度决策。
- `command.response`、`command.completed` 和 `result_code` 要一起看。正向 ACK 与校验结果是两回事；`accepted=false` 的重复或错序 ACK 不能完成另一条命令。
- 当前传输最多尝试三次，每次等待一秒。先看最终 `completed`；早期重试后成功，不应继续报告成当前故障。
- `configuration.settled` 仅说明提交 ACK 与等待期已经结束，并开始请求新遥测，不代表每个射频/WLAN 都已做硬件回读验证。
- 只修改客户端名称等配置时，版本可以增加但不需要重发所有无线参数；不能单凭“版本变了却没发命令”判错。

原生配置回读缺字段（例如 `vhtmubfer`）或缺少射频行，应显示“已下发、尚未验证”及缺失说明；缺失不等于关闭、不匹配或AP故障。实际返回相反值才是回读不一致；超时、禁止、格式错误仍为失败。TDCP发送以能力49筛选，不能用AX70、PMK66或实验型号代替。详细入口见[能力复核](ap-capability-audit.md)。

反复出现“ACK 成功、状态不对”，优先查提交标记、整批提交顺序、缓存应用、缺失参数、Native/旧 CAPWAP 两条配置路径及回读格式；不要不断重发同一组未经核对的报文。

## 6. 其他调度路径也要单独看

| 路径 | 事件和要点 |
| --- | --- |
| 普通关联许可 | `client.admission`：`result_code`、`reason`、服务/射频绑定、容量、MLO；AC 允许关联不是“AC 发起漫游” |
| 清单同步 | `client.inventory_admission`：补录 AP 已有客户端，`balance_evaluated=false` 不等于漏做普通关联均衡 |
| 负载均衡 | `balance.discovery` → `inputs` → `decision`：发现覆盖、在线 AP 计数、规则、拒绝前后次数、最后拒绝时间 |
| PMK | `pmk.request/lookup/release`：操作、服务、特殊能力分支、结果、旧位置清理；不记录密钥 |
| 自动模式 | `mode.transition_requested`、`mode.redistribute`：触发计数、门限、是否需要重分配，与固定模式区分 |
| 共同信道 ACS | `acs.waiting/collection_started/scan_report/collection_finished/selection`：模式参数先完成、预期集合、有效报告、超时和选择结果 |
| 独立 RRM | `rrm.measurement_requested/report/state`：任务自己的版本、阶段、轮次、目标会话、收集失败与最终变更 |

均衡判断会修改拒绝计数。排查时读取实际执行记录，不要为了“解释原因”再调用一次 `Admit` 或伪关联回调，造成真正的策略副作用。

PMK lookup 的结果 0 表示找到对应服务的密钥；1 表示未命中或服务不匹配；已有密钥但目标服务未知时为 2。失败释放要定位数据库里客户端原来的 AP，不能用请求 PMK 的 AP 替代。没有 PMK 事件时，只能标记这条路径未观察到，不能因为客户端换了 AP 就宣布 PMK/802.11r 已验证。

ACS 超时并非总等于任务失败，原策略有使用默认信道的分支。RRM 也存在保留旧计划、取消共同信道阶段、跳过功率阶段等分支。要按实际版本、失败标志和源代码判断，不能以“信道没变”一概视为没执行，或擅自补一套回退算法。

## 7. 哪些现象可能暴露隐藏 bug

下面是排查线索，不是仅凭现象就认定根因。

| 现象 | 应检查的 AC 问题 | 不能直接下的结论 |
| --- | --- | --- |
| 未上报某个可选能力，所有 SSID 都 `blocked` | 可选功能的能力门禁是否错误地挡住基础 WLAN | 不能归咎于 AP“不兼容整套配置” |
| 算出目标，却没有分发 | 结果分包、AP 索引、目标会话、能力筛选、队列提交；也核对观测关联缺口 | 不能用后来一次自主换 AP 掩盖没发命令 |
| ACK 归错命令或重连后“自动成功” | 序号回绕、重复 ACK、缺 Result Code、旧会话 ticket/回调污染 | 不能仅按相同序号或 MAC 合并记录 |
| 一个客户端没邻居，却拿到另一客户端的候选 | 每客户端输出数组和计数是否独立清空 | 不能为了“1:1”复制原固件已确认的空邻居残留缺陷 |
| 当前 AP 在两份轮询快照间来回跳 | Native 旧清单、较晚到的旧 AP 报告是否覆盖新关联 | 不能先统计为真实的反复漫游 |
| 客户端持续重复关联、很快断开 | 许可码、服务槽位、安全参数、是否有 AC 删除/调度/重配、上报顺序 | 放行成功不证明密码握手或业务已经成功，也不证明问题一定在终端 |
| 只改一个射频，另一射频或所有 WLAN 消失 | 继承覆盖、射频关闭销毁 VAP、提交和重新建 WLAN 的顺序 | 不要靠周期性重建所有配置掩盖依赖错误 |
| 当前 UI 速率/RSSI 为空或跳变 | 不同上报格式的单位、字段缺失是否抹掉旧的有效事实、数据时效 | 不要把百分比当 dBm，或用零代替未知值 |
| 相同配置每轮都重发 | 应用签名是否包含不断变化的时间/观测字段、失败状态是否正确退避 | 不能把发送次数当功能覆盖率 |
| 低信号长期没有候选 | BSSID/VAP 就绪、缓存老化、混合 RCPI/RSSI、PHY/角色、当前策略 | “手机信号弱”不等于“另一 AP 是合格目标” |
| PMK 失败后删错 AP 的站点 | 请求位置与当前数据库位置、重连 epoch、MLO 分组释放 | 请求方并不总是旧关联所在 AP |
| 模式或优化任务莫名切换/卡住 | 版本选择是否串用、异步应用屏障、超时及取消是否闭合 | 不要通过另写默认策略让任务看似完成 |
| 配置一直被覆盖，日志找不到管理写入 | 是否又激活旧 SQLite/JCS 的第二配置源，或有其他控制器 | 不要在页面上反复保存当作修复 |

### 已观察案例与边界

**已修复的 AC 缺陷：可选组播阻断 WLAN。** 导入配置带组播参数，某型号没有上报相应能力；原 Go 把它作为整个无线服务的拒绝条件，导致所有服务不能下发。原固件的 IGMP 分支独立选择支持能力的 AP，不应阻断基础 WLAN。现在保留目标配置、按能力跳过不适用的组播元素，并通过应用状态的 `reason` 明示；回归见 `TestUnsupportedIGMPDoesNotBlockWirelessService`。遇到类似情况应修正能力边界，不应删除用户配置或伪造 AP 能力。

**已观察的调度闭环：** 一次 V4 计算中，当前 −74、候选修正后 −61，差值 +13，通过门限；向原 AP 和目标 AP 下发结果，两端成功应答；约 284 ms 后收到目标 AP 的关联上报。能确认这条 AC 调度链执行并与随后切换一致。284 ms 是两条日志间隔，不是业务中断时间，也不是单独的 802.11r 证明。

**仍需定位的重复上下线：** 某个 2.4 GHz 客户端在一次长时间观察中反复连接，约四秒后断开，累计数百次。AC 每次放行，未观察到针对它的漫游/删除命令；其他客户端较稳定。另一个客户端有数次约一秒后重新关联的记录，其中部分仍在同一 AP。只凭这些记录不能决定是握手、AP 本地策略、终端还是 AC 的其他参数问题，应作为待定位事件保留，不应统计成成功无缝漫游。本文不保存这些设备的身份；现场原始摘录留在私有目录。

## 8. 可直接使用的只读查询

以下在分析机执行，需要 Python 3、`jq`，不要求更改运行 AP。先按实际部署设置路径和 URL；示例从仓库根目录执行：

```sh
AC_FIELD_DIR="$PWD/.local/ac100/field-test/current"
AC_EVENT_LOG="$AC_FIELD_DIR/logs/controller.jsonl"
AC_API_URL='http://127.0.0.1:8090'
AC_CLIENT_MAC='02:00:00:00:01:01'
```

### 封存一个分析样本

按旧段到当前段流式读取，不把所有日志一次加载进内存。命令输出到权限为 600 的临时文件，不写入仓库：

```sh
AC_LOG_SNAPSHOT=$(mktemp)
python3 - "$AC_EVENT_LOG" > "$AC_LOG_SNAPSHOT" <<'PY'
import json
from pathlib import Path
import sys

path = Path(sys.argv[1])
segments = sorted(
    (p for p in path.parent.glob(path.name + '.*') if p.suffix[1:].isdigit()),
    key=lambda p: int(p.suffix[1:]), reverse=True,
)
for segment in [*segments, path]:
    with segment.open() as stream:
        for number, line in enumerate(stream, 1):
            if not line.strip():
                continue
            try:
                row = json.loads(line)
            except ValueError:
                print(f'Incomplete/invalid record: {segment.name}:{number}', file=sys.stderr)
                continue
            print(json.dumps(row, ensure_ascii=False))
PY
```

这不是与写入/轮转事务化同步的快照。若段在读取时被重命名/删除，命令可能报错或缺失一段；取证时保存整套原文件，核对保留范围和观察器缺口。不要把只读当前文件、读到半行或找不到旧段误报成“没有发生过”。

### 先选运行，再选客户端和决策

```sh
jq -c 'select(.event == "controller.start" or .event == "controller.ready")' "$AC_LOG_SNAPSHOT"
AC_RUN_ID='填入本次运行的 run_id'

jq -c --arg run "$AC_RUN_ID" --arg mac "$AC_CLIENT_MAC" '
  select(.run_id == $run and .client == $mac)
' "$AC_LOG_SNAPSHOT"

AC_DECISION_ID=1
jq -c --arg run "$AC_RUN_ID" --argjson id "$AC_DECISION_ID" '
  select(.run_id == $run and .decision_id == $id)
' "$AC_LOG_SNAPSHOT"
```

第一条按 MAC 查询会遗漏无 `client` 字段的候选事件，第二条通过 `decision_id` 补全。跨运行复查时，对每个运行分别处理，不要只取最后一次启动。

### 从分发结果找真正的客户端和目标 AP

```sh
python3 - "$AC_LOG_SNAPSHOT" "$AC_RUN_ID" "$AC_CLIENT_MAC" <<'PY'
import json
import sys

path, run, wanted = sys.argv[1:]
def mac(value):
    return ':'.join(f'{byte:02x}' for byte in value)

with open(path) as stream:
    for line in stream:
        row = json.loads(line)
        if row.get('run_id') != run or row.get('event') != 'roaming.result_created':
            continue
        result = row['result']
        for station in result['Stations']:
            if mac(station['MAC']) != wanted.lower():
                continue
            targets = []
            for candidate in station['Candidates']:
                targets.append({
                    'ap': mac(result['APs'][candidate['APIndex']]),
                    'radio': candidate['Radio'], 'wlan': candidate['WLAN'],
                    'bssid': mac(candidate['BSSID']), 'channel': candidate['Channel'],
                })
            print(json.dumps({'time': row['time'], 'run_id': run,
                              'job_id': row['job_id'], 'source_ap': row['source_ap'],
                              'client': wanted, 'targets': targets}))
PY

jq -c --arg run "$AC_RUN_ID" '
  select(.run_id == $run and
    (.event == "roaming.result_dispatch" or
     .event == "roaming.dispatch_failed" or .operation == "roaming_result"))
' "$AC_LOG_SNAPSHOT"
```

结合第 3 节的关联限制，核对同一批次的 `job_id`、目标 AP 和会话。若多个批次并发导致不能唯一对应，就记录“关联未闭合”，不要认领任意一个成功 ACK。

### 查异常、当前状态和客户端迁移

```sh
jq -c --arg run "$AC_RUN_ID" '
  select(.run_id == $run and
    ((.event == "command.completed" and .outcome == "failed") or
     (.event == "client.admission" and .result_code != 0) or
     .event == "observer.records_dropped"))
' "$AC_LOG_SNAPSHOT"

curl --fail --silent --show-error "$AC_API_URL/api/config" |
  jq '.apply[] | select(.state == "failed" or .state == "blocked" or .state == "failed_recovered")'

curl --fail --silent --show-error "$AC_API_URL/api/clients" |
  jq --arg mac "$AC_CLIENT_MAC" '.[] | select(.mac == $mac)'
```

实时跟踪可用 `tail -F "$AC_EVENT_LOG"` 配合 `jq --unbuffered`。它适合观察新增记录；复盘仍需查旧段，且单纯按 MAC 过滤仍有上述关联遗漏。

## 9. 持续监控与 AP 专用 DHCP

```sh
python3 tools/monitor_controller.py \
  --url "$AC_API_URL" \
  --expected /private/expected-aps.json \
  --events "$AC_EVENT_LOG" \
  --output /private/monitor
```

期望文件示例：`[{"mac":"02:00:00:00:00:a1","name":"AP-A","ip":"192.0.2.50"}]`。通过 systemd 等进程管理器运行后，聊天结束仍持续记录；聊天本身不会自动醒来分析。

监控区分 `not_seen`、`online`、`offline`，跟随日志轮转并保存策略事件。默认约五秒轮询 AP、约十五秒刷新其他摘要；它不会自动推演另一套漫游算法，也没有完整自动检测所有重连循环或零丢包。要读 `updated`、`last_success`，不能把历史快照当实时。

`recent_attention` 是有长度上限的历史提示；没有告警不等于全部路径正常。`apply_failures` 当前收集 `failed/blocked`，还应人工查看 `failed_recovered` 和其他任务状态。监控器的 `reachable=false` 也可能由某个附加 API 读取失败造成，不应直接判断整个 AC 或 AP 都掉线。

AP 专用 DHCP 与 AP 侧 DHCP/ARP 防护是不同功能。可选 DHCP JSON 的 `reservations` 按 MAC 固定地址，并避开动态分配；更换 DHCP client-id 不改变静态绑定的 MAC 所有者。普通客户端仍不能绕过精确 Option 60 过滤。

日志判读时：

- `dhcp.ap_reply.message_type=2` 是 OFFER，`5` 是 ACK；看到保留地址的 OFFER 不证明 AP 最后使用了它。
- `dhcp.ap_reply`只表示构造完成；`dhcp.reply_sent`才表示UDP发送成功。`dhcp.other_server_selected`记录AP选中了其他服务。还须核查应答Option60：Fit AP的优选回调需要厂商标识，只有请求侧过滤和Option138并不够，详见[DHCP协议复核](ap-dhcp-review.md)。
- 核对同一 MAC、transaction、REQUEST 的 `selected_server`、最终 ACK、租约及 AP 实际上报地址。另一个 DHCP 服务或旧租约可能让实际地址与本程序保留地址不同。
- 精确的 Mesh Detect 身份有 V6 Discover-only 特例：可以看到 OFFER，却不能按此身份完成 REQUEST 租约；不能把它当成完整 AP 获取地址。
- 普通客户端在过滤前就被静默忽略，没有对应事件。不能用“日志没有普通终端”证明网络内没有普通 DHCP 请求。
- 迁移 AC 时保留 AP 地址、掩码、网关、DNS、租期，但 DHCP server 和 Option 138 中的 AC 地址应指向新程序。
- DHCP服务配置入口是“AP管理 → AP DHCP服务”；启停/池/预留只改变DHCP运行时，不重启AC。控制器安装位置与`reported_location`分开；Mesh全局开关、AP有效开关及`mesh_device`能力元数据也要分别核对，不能把它们当成同一个开启状态。
- 单个 AP 不接入时，先查发现地址、接口和旧 AC 缓存；不要为了调试 AP，把生产网的普通 DHCP 一并停掉。

## 10. 留给下一位维护者的最小报告

每次排查至少保存以下内容，原始资料放私有目录：

| 项目 | 应记录 |
| --- | --- |
| 构建与配置 | 实际运行二进制的版本/摘要，配置版本、策略族、实际模式、绑定接口；区分磁盘源码与已部署二进制 |
| 时间与身份 | 统一时区的起止时间、`run_id`、AP 会话、当前客户端 MAC/SSID，以及随机 MAC 变化 |
| 策略链 | 触发入口、候选路径、`decision_id`、拒绝原因或真正目标、`job_id`、命令与 ACK |
| 结果 | 后续关联及位置变化、有没有断开记录；业务连续性若未测就明确写未测 |
| 异常 | 命令失败、重连次数、数据缺失、早期错误是否已恢复、缺口是否影响结论 |
| 证据边界 | 观察事实、推测根因、待查内容分开写；未触发的路径列为未覆盖 |

修改时先按下面的源码入口定位责任，再补能复现实际问题的分支/假 AP 回归；不要只补一个特殊型号或无条件重试来消掉日志：

| 责任 | 实现入口 |
| --- | --- |
| 事件输出、丢失与轮转 | `uacgo/internal/eventlog/log.go` |
| CAPWAP 会话、ACK 与命令队列 | `uacgo/cweng/engine.go`、`command_queue.go`、`manage.go` |
| 漫游输入、分包和分发 | `uacgo/admin/roam_decision.go` |
| 策略族及伪关联 | `uacgo/admin/roaming_policy.go` |
| V4/V6 选择及均衡 | `uacgo/mobility/legacy_select.go`、`select.go`、`balance.go` |
| 统计、BSSID、客户端快照 | `uacgo/admin/mobility_statistics.go`、`client_snapshot.go`，`uacgo/cweng/client_snapshot.go` |
| PMK、模式、ACS、RRM | `uacgo/admin/pmk.go`、`automatic_mode.go`、`high_performance.go`、`rrm_jobs.go` |
| 应用状态与管理写入日志 | `uacgo/admin/events.go` |
| 可选 AP DHCP、持续观察 | `uacgo/dhcpserver/server.go`、`tools/monitor_controller.py` |

公开文档和提交只能包含脱敏案例、合成测试数据及代码。真实 MAC/IP、SSID、客户端别名、原 AC 备份、完整运行目录、日志、trace、pcap、密钥、证书私钥和 Native 原始响应留在本地。事件日志虽然避开密钥，仍包含网络身份信息，不能直接当成“可公开日志”。


首次登记可查看 `ap.registration`：`first`区分新建与已有记录，`model_id`是原厂模板查找键，`initial_template`为空表示未使用型号默认模板，`group`是Join后的结果。`ap.registration_failed`表示持久化或初始化失败，不能同时当作已成功接管。见[首次接入核对](ap-onboarding-review.md)。


## 候选是否缺AP的只读检查

```sh
python3 tools/audit_roaming_candidates.py /path/controller.jsonl.1 /path/controller.jsonl --details .local/candidate-audit.json
```

工具按`run_id + decision_id`拼接候选输入，不依赖客户端MAC全文搜索；缺少输入的部分日志单列，避免把grep遗漏当成候选缺失。摘要不输出设备身份，详细文件含身份，必须留在私有目录。

`source_ap_only`只表示候选的AP ID均为来源AP。候选按BSS/射频记录，来源AP的另一频段也可以是正常目标；不要把它误认为当前BSS。进一步对照`raw_source_ap_only`、`reported_other_ap`和`unresolved_bssid_owner`：前者说明原邻居输入没有其他已识别AP，后两者需要继续查BSSID映射、AP会话在线与统计就绪、估速及选择步骤。

审计工具使用保留的VAP统计帮助归属BSSID；历史归属不能证明该时刻已经就绪，更不能单凭“邻居少”认定AP固件有bug。控制器不能为补齐数量凭空把所有在线AP加入候选。
