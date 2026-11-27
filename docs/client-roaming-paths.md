# 客户端漫游路径：V6 源码复核

> 再次双向审查发现上一轮尚有偏差，已修正终端带宽枚举2、逐槽统计与有效性、统计接收门禁、能力25/72独立下发、模型失败分类、PMK特殊请求RSSI，以及原包输出参数残留。最新分支矩阵和证据见 [再次双向核查](roaming-bidirectional-recheck.md)。下文已随实现纠正，不以此前通过的测试替代本轮证据。

审查基准为用户提供的 **TL-AC100 V6.0 1.0.3 Build 260817 Rel.68871n**，不是未提供的 V4 固件。复核读取解包 ELF、Lua、配置迁移脚本和反汇编调用点；没有运行原 UAC、没有把外部 AP 测试结果当作原算法的证据。

本文说明 AC 能决定的行为。AP 如何发出无线管理帧、终端是否接受 BSS Transition、最终换台是否无丢包，属于 AP/客户端执行层，不能由 AC 固件单独证明。单台 AP 能接入、能上网，也不能证明多 AP 调度正确。

## 本轮结论和修正

此前的实现有真实偏差，不能据已有测试宣称完全对齐。本轮修正如下，均已补充按原分支编写的回归：

| 问题 | 原固件依据 | 本轮修正 |
| --- | --- | --- |
| 排序前按 2G、5G 拼候选，改变非稳定排序的同分顺序 | `roam_nbr_select@4e5638` 先复制 `+0x1a8`，后复制 `+0x28` | 先 5G 后 2G，再执行原 quicksort |
| 负载均衡把 MLO 根和附属 peer 都算成人数 | `4ed3e4/4ed520` 跳过 `station+0x91==2`，`766458` 创建 peer 时写入 2 | AP 负载只计逻辑 MLD/普通客户端；每射频容量仍按链路计数 |
| 观测带宽枚举2被当作80 MHz | `_wlan_caps_calculate@4ea84c` 与 `_sta_caps_calculate@4ea640` 均只识别0/1/3/5；上一轮声称两者不同不准确 | 合并观测解码；AP配置自动先取观测值，未知观测宽度回退为2G20/5G80 MHz |
| Mesh 速率只凭链路标记判断，缺数据时可能按普通 AP 估算 | APDB `70cc34`、Join `60b040`、估算器 `4eb314` | 传播产品类别和 Mesh 标记，按角色选择回传；只用当前父节点，缺回传为 0。不可估算角色为 -1：当前 BSS 保留 -1，邻居插入时跳过 |
| PMK 查询失败只改客户端表，漏发原 AP 删除命令；MLO 可能遗留 peer | `4e46c0 → 766fdc → 754c74 → 75492c/75efec` | 清整组关联，向客户端原所在 AP 提交 msg25/Delete Station，随后通知生命周期；不误发给密钥请求 AP |
| 旧 AP 型号库回退只识别 `5G`，漏掉原库 `5.0G` 射频 | `_apdb_radio_freq_string_to_enum@6f1b54` 明确比较 `5.0G`，原库 `TL-AP1200C-PoE` 等型号使用此键 | 按原频段键恢复双频能力，保留旧导出别名；不借用其它硬件版本 |

这些修正针对配置/数据流和共享数据库操作，不增加厂商之外的兜底调度算法。

## 路径总览

| 路径 | 谁触发 | AC 的职责 | 是否需要先有漫游候选计算 |
| --- | --- | --- | --- |
| 客户端自主换 AP | 终端重新关联；新 AP 上报许可/同步事件 | 准入检查、关联表迁移、状态和历史 | 不需要 |
| BSTM 邻居报告漫游 | AP private `0x58` 带邻居信息 | 识别测量值、估速、排序筛选、下发 `0x59` | 就在本次事件内计算 |
| 无 BSTM 邻居的回退 | AP `0x58` 无邻居，AC 已有 `0x53` RSSI 邻居记录 | 用独立邻居表，保留未知速率和弱信号兜底 | 就在本次事件内计算 |
| 关联负载均衡 | 新关联许可检查，结合 AP 的 `0x0b` 发现记录 | 必要时拒绝本次接入，达到拒绝上限后放行 | 不需要；不是踢掉已有客户端 |
| 802.11r 密钥交接 | AP private `0x49` | PMK 缓存、服务隔离、应答和失败清理 | 不需要；不是候选选择器 |
| AP 本地弱信号/低速踢除 | AP 按下发策略运行 | 配置 `0x57` 参数 | 不等同于 AC 选择候选 |
| 双频优选 | AP 根据全局双频策略处理接入 | JSON `0x83` 或旧 `0x3a` 配置通道 | 独立于多 AP 漫游 |

RRM 的信道/功率优化会改变无线环境，但另有独立算法和触发任务，不作为这些客户端路径的秘密回退选择器。

## 一、普通关联与客户端自主漫游

客户端可以自行决定离开 AP-A、接入 AP-B，不必先获得 AC 的候选列表。Go 从 AP 的关联许可、关联/同步、完整无线状态快照维护客户端位置；仅收到统计、RSSI 或候选结果 ACK 不把客户端改成“已经漫游”。

普通许可检查依次包含有效服务/射频及槽位、MAC、配置的负载均衡、每射频容量。原结果码分别为 `0x26`、`0x25`、`0x27`、`0x11`。MLO 各链路与逻辑 MLD 分开保存；Web 折叠展示根和链路，不用展示列表替代内部计数。

不同上报入口并非一律重新执行准入：例如清单同步描述的是已有关联，11r 特殊成功分支也直接同步关联；不能给所有入口强加同一个均衡检查。原固件的许可成功分支本身就可立即更新站点 DB，所以 Web 的“在线”是协议关联状态，也不是对每一帧空口完成的独立证明。

Go 使用会话 epoch 防止旧 AP 断开/迟到快照覆盖新关联，这是并发实现对生命周期边界的处理，不是另加漫游策略。

## 二、AC 主动计算：带 BSTM 邻居的 `0x58`

有效链为 `wsta_roam_pkt_init@4e9b78 → _wsta_roam_pkt_wtp_event_listener@4e89ac → 4e8440 → 4e6564 → roam_nbr_select@4e5638`。

关键调用点 `0x4e713c` 的 JAL 指令 `0x0c13958e` 确实指向 `0x4e5638`。ELF 中名字相近的旧 `_roaming_nbr_select@4e4b3c` 不是这个入口调用的选择器。

### 触发与数据准备

AP 接收 `0x57` 的 11k/v/r、2G/5G RSSI/速率触发、可选踢除、检查间隔、差值、限制回连等参数。由 AP 上报 `0x58` 才进入本次计算，AC 不用一个自行发明的定时器遍历所有客户端后踢人。

本地必须已有位置匹配的客户端。邻居 BSSID 要能通过原 `0xbd/0x54` 数据流建立的索引解析成受管 AP、射频、WLAN，并具备需要的有效射频统计；不从页面遥测的SSID猜槽位。整份邻居报告统一判断 RCPI/有符号 RSSI，不能逐个邻居任选一种解释：明确 RCPI 值 `<128`，明确有符号 RSSI 编码 `>=220`，中间区结合奇偶和 RSNI；不一致的模糊报告不当作有效邻居。

RCPI 按 `value/2-110` 换算。估速使用未减 10 的换算 RSSI；排序和过滤使用 `max(-95, RSSI-10)`。仅当第 0 个邻居匹配当前 AP/射频/WLAN 时，它提供当前 BSS 的估算率和修正信号；否则保留报告的当前信号，当前估算率初值为 0。当前 BSS 估算结果若为 -1，保留该值，选择器按原 uint16 截断处理，不能变成零基线。

### 估速与 Mesh

`4eb314/4eab48` 按原编译速率表计算。STA/AP 取原 PHY、空间流、带宽组合，保留 STA MCS；使用原固定 -85 噪声假定、整数插值截断和 16 位结果，不能改成浮点“更准确”公式。

APDB 顶层类型 12 为 Mesh-device、13 为产品类别；原解析器是 `switch(type-1)`，不能把反编译 case 号直接当线上的类型号。Join 决定角色：普通 AP/CAP、RE-AP、路由/XVR 等；估算器接受 0..4、6、8，拒绝 5、7、未知角色，结果为 -1。BSTM 邻居估算为 -1 的记录不入候选。

角色 4/6/8 的速率为 `Rwifi × Rbackhaul / (Rwifi + Rbackhaul)`；没有 Mesh DB/回传率为 0 时，结果为 0。Go 不能根据节点的 `wireless` 标记跳过这个公式，也不能从旧父 AP 的残留拓扑取到另一条速率。

### 排序与正常筛选

先按 5G、2G 拼数组，再按原非稳定 quicksort 排序：估算速率从大到小；同速率优先 5G；再按修正 RSSI 从高到低。完全同分时保留该 quicksort 产生的顺序，不另加 AP MAC、人数或随机排序。

正常候选同时满足：

1. 目标频段策略含 RSSI 类型位时，修正 RSSI 至少为 2G -85 / 5G -87；不含该位时至少为 -75。
2. 信道负载不高于 2G 70 / 5G 85。
3. 速率不是未知值 -1，且 `Rnew >= Rcur + floor(Rcur/5)`，同时 `Rnew > Rcur + 19`。
4. 最多选择 4 个；报文可容纳 6 个不表示默认策略选 6 个。

**这里的候选接收门限不是 Web 上的 AP 触发门限。** 默认 2G -75 / 5G -80 是下发给 AP 的触发配置，不能拿来替换 AC 选择器里的 -85/-87。

### 无正常候选时的弱信号兜底

必须同时是：正常候选数为 0、当前修正信号严格小于 -85、排序后的第一个邻居信号严格大于回退门限。满足才选第一个邻居。

原代码的回退门限取自筛选循环最后访问的频段，未必是第一个邻居的频段；这个细节保留。该分支绕过正常的速率增益和信道负载过滤，不能为了看起来更合理又加回这些过滤。

## 三、`0x58` 无 BSTM 邻居：RSSI 表路径

这条路径用统计 private `0x53` 建立的独立邻居表，不用负载均衡 `0x0b` 的发现表，也不用 Web 上最后一次客户端 RSSI。

目标 AP 必须有相同逻辑无线服务的绑定槽位，能找到对应 BSSID/射频事实，并在线。邻居最多 12 条，时效为 `(3 × reporting_interval + 1) >> 1` 秒；reporting 的 RSSI 间隔按配置与 120 秒取小值。

原 `stats_db_sta_get_nbr_set@7aef88` **明确把这些候选的估算率写为 -1**。因此它们过不了正常速率筛选，但仍能在上述弱信号兜底分支入选，即使没有已知速率或信道负载较高。没有有效新鲜邻居时不会重新寻找“最强 AP”；但原代码还有下述同包输出参数残留分支，不能简单概括成一律空结果。

RSSI 邻居上报由 `statistics` 开关控制；默认关闭时，不能假定表中一定有持续更新的邻居数据。Go 不为使回退好看而暗中打开它。

接收端同样检查统计开关，关闭后的迟到 `0x53` 不更新邻居和信道负载。`0x54` 逐槽累积，遗漏不删；槽位释放、射频关闭会清理有效状态，重新启用不能靠展示缓存恢复，必须有新的有效报告。`0xbd` 只维护BSSID索引，不冒充已就绪的逐SSID统计。

## 四、结果分发与状态：两条选择路径共用

**零邻居的原代码异常行为也保留。** `roam_nbr_select` 在 `4e577c` 发现邻居数0就跳到返回，不执行 `4e5aac` 的输出数量清零；调用循环在 `4e6ba0` 仅每包初始化输出参数。因此同包前一站点已有结果、后一站点完全无有效邻居时，后一站点会沿用前一结果。Go明确维护这段包内状态，并标注事件原因；新包清零，有邻居但筛选结果为空也清零。这是原数据流的复现，不解释成厂商有意设计，也没有移植不安全的内存操作。

`0x59` 发送给源 AP 与已知邻居 AP 的并集，包括没有入选的邻居；站点 bitmap 与最终候选列表的含义不同。AP 并集及每包站点数上限均为 128，大报告分包，不覆盖上一报告。无 BSTM 站点先处理，BSTM 站点后处理。

目标还必须在线且具备能力位 25。整批命令先提交，再等待各设备 ACK；ACK/失败更新命令状态，**不改变排名、不产生控制器冷却、不代表客户端已换 AP**。实际位置由后续关联/同步事实更新。

## 五、关联时负载均衡

源链 `0x0b/4f0a04 → 4f0dfc → 4f0adc → 4f6f54`。它在新关联时决定允许/拒绝，不是周期性把已连接客户端搬到人数最少的 AP。

启用规则后每 MAC 记录最多 10 个发现 AP，按原更新顺序维护。当本 AP 逻辑客户端数达到门限、另一个已发现且在线的 AP 人数更少、人数差达到门限时，可以返回拒绝码 `0x27`。AC 不再加同 SSID、VLAN、相同规则的过滤；RSSI 门限由 AP 的发现策略处理。

拒绝计数是每 MAC 共享的，距**最后一次拒绝**满 60 秒才清零；达到最大拒绝次数会放行，避免永远无法入网。发现记录每 300 秒扫描、900 秒失效；AP 离开清除其发现。

MLO 的各非 MLD link MAC 与 MLD MAC 按原调用检查，某个拒绝不能跳过其它计数；AP 人数只算逻辑根/普通站点，不能把 peer 重复计数。每射频容量又是另一种计数，peer 占用自己的射频容量。

## 六、802.11r PMK：不依赖 `0x58`

private `0x49` 是固定 101 字节结构：

| operation | 行为 |
| --- | --- |
| 0 | AP 通知 PMK-R0/Name，AC 按客户端 MAC 和逻辑无线服务缓存 |
| 1 | 请求密钥，AC 返回 operation 2 |
| 3 | 特殊请求，仅能力位 66 的 AP 启用；成功还同步关联 |

结果 0 为成功；1 为没有密钥/服务不匹配；2 为已有密钥但目标服务槽位无效。无缓存时先返回 1，不改成 2。同名 SSID 不能跨逻辑服务拿到密钥。

断关联后缓存保留 60 秒，分钟扫描清理；同服务重关联撤销删除。operation 3 成功直接同步关联，不额外套一次普通准入均衡。这是原固件的独立分支。

请求失败时，原固件释放**数据库中当前所在 AP** 的站点/MLO 组，再向这个旧 AP 发 msg25、Delete Station 元素 `0x12`（旧 radio/MAC），同时向请求 AP 返回失败。旧 AP 与请求 AP 可以不同；删除命令不能跟着请求 AP 走。Go 在会话仍有效时异步提交原 AP 命令，不等它 ACK 才发密钥失败应答，断开会话的命令也不转给新会话。operation3 成功同步关联时沿用旧DB的RSSI，旧条目不存在则使用0，不丢掉这一参数，也不增加一次均衡准入。

密钥不放进 Web、普通日志或配置导出。

## 七、AP 本地策略和双频优选

弱信号踢除、低速踢除、限制回连时间等经 `0x57` 下发，由 AP 执行；射频 RSSI 引导经独立 `0x4c` 下发。Go 不根据这些开关另外运行一套 AC 踢人定时器。AC 镜像不含 AP 空口完整执行代码，不能声称已经证明其内部每一条管理帧行为。

双频优选控制 2.4/5 GHz 接入倾向，与 AP 间候选选择分开。Go为现代型号提供 `apmng_band_navigation` / private `0x83` 的JSON适配；原UAC的配置codec是 `0x3a` 四字节。未声明JSON能力、或明确回复不支持事件/操作/指令（-40104/-40105/-40106）时才回原codec；繁忙、禁止、参数错误或缺少有效enable字段均报告失败。JSON适配是Go传输兼容层，不宣称原UAC也按此优先顺序探测。两通道都由AP执行双频策略，不保证所有已连接终端被立刻强制转到5G。

能力25控制`0x57`，能力72独立控制`0x9d`。后者模式2取原UCI的`default_roam_cnt/default_silence_time`；Flash数值未包含在升级包里。独立程序初值为3次/30秒，可在默认漫游设置的“AP漫游静默控制”修改，API字段是`mobility.silence.count/seconds`。这是可配置初值，不冒称原机Flash值；次数8位、时间16位的打包规则仍按原固件。

AC 失联后，集中候选计算、均衡许可和跨 AP 的 PMK 查询都不能继续依赖 AC。独立 Go 的基础默认值允许 AP 离线自管理，经 `0x3c` 下发，页面可修改；是否允许新客户端和如何执行本地策略由 AP 的离线模式决定。不能把这个开关描述成仍有一台在线 AC 继续协调全网漫游，也不能据此承诺离线 11r 跨 AP 密钥交接。

## 八、旧模式、实际配置与证据边界

本 V6 的 Web 模式写入无条件 `EFORBID`，迁移脚本 `36_roam_cfg_sync.sh` 将配置/实际模式都设为 2。Go 仅接受模式 2。ELF 留有旧自动/高性能模式及智能 ACS 函数，不表示此产品当前可开启；不把这些旧计数门限和同信道逻辑拼成第二套正在运行的漫游算法。原 RRM 在模式 2 下进入普通 SCA/TPC，另见 [mobility-parity-audit.md](mobility-parity-audit.md)。

2026-11-27 复核时实验环境为：模式 2；11k/11v 开、11r 关；2G RSSI 触发 -75、5G -80；RSSI/速率踢除均关；检查间隔 1 秒、差值 8、限制回连 2 秒；RSSI 邻居统计关；未配置负载均衡规则；全局双频优选开。故**支持 11r、均衡不表示当前实验已经开启它们**。

这些阈值是当前配置快照，页面可以修改，不是程序永久写死的部署要求。

### 可复核映射

| 原始证据 | Go 位置 | 对应回归 |
| --- | --- | --- |
| `4e713c` 的 JAL、`4e5638/4e0d40` | `admin/roam_decision.go`、`mobility/select.go` | `TestRoamingUsesFiveGHzFirstBeforeFirmwareQuicksort`、`TestSelectionBandTieAndWeakFallbackKeepFirmwareQuirks` |
| `4ea84c/4ea640/4eb314/4eab48` | `mobility/rate.go`、`admin/roam_decision.go` | `TestRadioAutoWidthUsesWLANFallback`、`TestRateUsesFirmwareTableAndTruncatedSlope` |
| `70cc34/60b040/53c1a8/531eb8` | `cweng/capabilities.go`、`admin/roam_decision.go` | `TestProductMetadataFlowsFromAPReportToStatus`、`TestRoamingMeshRateUsesRoleAndCurrentParent`、`TestRoamingCurrentUnsupportedRoleKeepsUnknownRate` |
| `6f1b54/6f8780/6f239c` 与原型号库 `5.0G` 字段 | `cweng/capabilities.go` | `TestLegacyAPDBResolvesFiveGHzFirmwareKey` |
| `7aef88`、`0x58/0x59` | `mobility/statistics.go`、`admin/roam_decision.go` | 既有 RSSI 表、双 UDP 模拟 AP、分包及会话回归，见合同索引 |
| `4ed3e4/4ed520/766458` | `admin/balance_decision.go`、`mobility/balance.go` | `TestBalanceCountsMLDOnceAndExcludesPeerRows`、`TestBalanceUsesStationGlobalFailuresAndLastRejectionTime` |
| `4e46c0/766fdc/754c74/75492c/75efec` | `admin/pmk.go`、`cweng/client_history.go`、`cweng/station_extra.go` | `TestPMKFailureDeletesStationOnItsCurrentAP`、`TestPMKReleaseRemovesMLOGroupBeforeLifecycleNotification` |

静态指纹和编译常量见 [mobility-firmware-evidence.json](mobility-firmware-evidence.json)，源函数—Go 符号—实际执行测试对应关系见 [uac-web-behavior-contracts.json](uac-web-behavior-contracts.json)。`check_behavior_contracts.py --verify-firmware --run-tests` 核对固件 SHA/函数字节、实现符号和具名测试执行；`check_parity_map.py --verify-firmware` 检查双向范围索引。它们用于定位和防止已识别分支回退，不是全部参数/型号的形式等价证明。

上一轮记录为144个UAC函数、48项合同/137个具名用例；最新证据和执行统计见 [再次双向核查](roaming-bidirectional-recheck.md)。模拟AP验证Go管理报文、状态和分支，不用于反推原厂算法。

历史 AP 不上报新 APDB 元数据时使用静态型号库。本次核查随固件库的旧记录不含 Mesh/product 字段，原 `_apdb_ap_list_parse@6f8780` 在字段缺失时也明确置 0；不能由 AP 名称猜出另一个 Mesh/路由角色。本文核对报告元数据及静态回退的数据流，不声称已经完整重建每个型号的全部字段，或证明未提供的设备固件/V4 算法。
