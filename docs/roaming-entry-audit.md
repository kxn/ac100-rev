# 漫游策略与入口核查（2026-11-27）

本轮按用户要求，修复原固件“零有效邻居沿用前一客户端候选”的缺陷；其它调度策略继续对照原固件。基准仍是 TL-AC100 V6.0 1.0.3 Build260817 Rel.68871n。没有执行原 UAC，没有用 AP 实测反推算法。

## 本轮实际修改

`calculateRoamingLocked` 删除包级 `lastSelection`，为每个客户端独立调用纯选择器。邻居缺失、BSSID 无法解析或整报告信号编码冲突时，该客户端得到空候选；不会复制其它客户端或其它无线服务的结果。分包、结果历史、AP bitmap 和 59 下发都使用当前客户端的结果。

这项有意差异记录在 [行为合同](uac-web-behavior-contracts.json) 的 `roaming-packet-output-state`，来源类型为 `firmware-bug-fix`，包含原缺陷、修改与用户授权。原 `4e577c/4e5aac/4e6ba0` 指令证据不修改。排序、信号/负载/速率增益门限、弱信号回退及能力过滤没有改动。

## 从注册点枚举入口

[机器可核验清单](roaming-entry-audit.json) 固定原 ELF 与符号表 SHA、注册根与回调字节、每一处引用的指令及分类。11 个根中核到 96 处地址引用，涉及 95 个函数；不是 95 套调度算法。

| 注册根 | 地址 | 核查内容 |
| --- | --- | --- |
| `wsta_roam_init` | `4d8240` | 关联/离线、AP/组生命周期、规则与模式 JCS |
| `wsta_roam_pkt_init` | `4e9b78` | msg9 priority90、AP上线、关联统计、射频变更、旧ACS容器 |
| `wsta_roam_db_init` | `4de794` | PMK与诊断记录定时器、RSSI统计开关/间隔消费者 |
| `wsta_roam_sql_init` | `4dabf0` | 规则持久化队列；Go由单一配置源与收敛替代 |
| `balance_init` | `4ef760` | msg9 priority1、msg5 priority50、准入、关联计数、组/API配置 |
| `balance_db_init` | `4f34f4` | 发现表和拒绝记录；300秒扫表线程 |
| `uac_stats_init` | `7b4578` | AP/站点/射频/WLAN有效性及生命周期 |
| `stats_pkt_init` | `7b5d6c` | msg9 priority80与55上报控制 |
| `stats_db_init` | `7ac914` | 统计寿命、采样定时器表、认证统计容器 |
| `band_navigation_init` | `633ce8` | 双频优选JCS及AP连接下发，能力3 |
| `band_navigation_db_init` | `633e60` | 默认配置读取，无新增回调 |

`stats_db_init` 还通过 `8f5620` 指针表注册四个采样回调，不能只看内联函数地址。表中的站点、设备、射频、VAP采样与默认间隔也已逐项固定；它们负责历史统计，不选择漫游目标。

分类区分决策、配置、生命周期、诊断、旧模式、容器工具和已排除认证。参与程序所需行为的入口关联到现有具名合同及 Go 回归；容器哈希/释放函数不伪装成未实现的漫游策略。原控制台漫游耗时直方图、认证统计容器没有当作新的产品功能移植。

## 反向追索，包含函数指针

对关键选择、PMK、均衡准入、模式切换和旧信道处理函数做了全符号范围的直接 `J/JAL` 扫描，并用 Ghidra 反向引用补查间接用途。结果为 11 处直接跳转和 2 处 `foreach` 函数地址引用，共 13 处：

- 当前 `roam_nbr_select@4e5638` 只有 `4e713c` 这一调用点；旧 `_roaming_nbr_select@4e4b3c` 在这份分析中没有引用。
- `58 → trigger@4e8440 → by_rssi_low@4e6564 → selector` 链闭合；PMK `49` 从同一监听器独立进入，先于 `58`，不会因为收到其中一种就跳过另一种。
- `_wsta_intelligent_roam_set_rd_info_by_sta` 在 `4e2f98` 被作为遍历回调传入，其上层 `sta_change_ap_info` 要求 configured=0；不是 mode2 中隐藏的周期迁移策略。
- `_wsta_intelligent_roam_set_rd_info` 在 `4e319c` 被作为遍历回调传入，另有两处直接调用。最终函数本身要求 actual=1；`set_rd_cfg` 只是包装函数，没有独立的配置模式门禁。

只搜索直接调用指令会遗漏后两种回调，因此清单分别保留直接跳转与反向引用。原内部 JCS 模式 setter 仍存在，可调用 0/1/2 模式切换；原 V6 Web setter 返回 EFORBID，配置迁移固定 configured/actual=2。Go 保留产品可配置范围，拒绝 0/1，不额外公开原内部调试/IPC 接口。

## 正向分支与 Go 反查

| 入口/分支 | 核查结果 |
| --- | --- |
| 关联许可、同步、完整站点列表 | 原 priority100 的类型优先级保留；准入、位置迁移与 MLO 计数不由候选 ACK 推断 |
| 53/54/bd 统计与BSSID索引 | priority80先于90；接收开关、逐槽保留、释放/禁用清事实、重连epoch均有回归 |
| 同包49/58 | 固定先49再58，各取首个同类型元素；新增倒序/重复元素及PMK成功、失败回归 |
| BSTM与无BSTM | 原测量识别、能力估速、53邻居时效与弱信号回退保留；两条路径都通过同一站点级选择调用 |
| AP能力25/72/66 | 分别过滤57/59收件人、9d、PMK特殊同步；25不额外改变候选排名 |
| 无候选 | 明确的厂商缺陷修正；每客户端空结果，不借用上一站点 |
| 59提交、拒绝、超时 | 先提交整批再等ACK；结果不可变，失败不改排名/客户端位置、不增加AC冷却 |
| 均衡 | 仅0b建立发现；每MAC共享拒绝次数、60秒、10AP、300/900秒边界及MLO逻辑计数保留 |
| AP离线、分组迁移、规则修改 | 原注册回调分别映射生命周期清理、引用检查、默认/分组规则选择和配置重发，不增加另一个策略所有者 |
| 旧ACS、关联统计、采样线程 | 追到模式门禁或纯统计/清理动作；没有遗漏一个需要在mode2新增的候选选择入口 |

反向核查使用现有 [双向合同检查器](../tools/check_behavior_contracts.py)，从 Go 符号及实际执行的具名测试回到原函数字节。独立程序的队列、会话隔离、持久化与Web适配保持单独来源，不允许给选择器增加额外门限、排序或冷却。

## 可重复验证

```sh
python3 tools/check_roaming_entries.py --verify-firmware
python3 tools/check_behavior_contracts.py --verify-firmware --run-tests
python3 tools/check_parity_map.py --verify-firmware
go -C uacgo test ./...
go -C uacgo vet ./...
go -C uacgo test -race ./admin ./cweng ./mobility
```

本轮还在 Ghidra 原项目只读重新导出注册引用与反向引用，使用下面的校验选项比对完整集合，而非仅查清单里已经存在的行：

```sh
python3 tools/check_roaming_entries.py --verify-firmware \
  --references /tmp/ac100-roaming-entry-references.tsv \
  --reverse-references /tmp/ac100-roaming-reverse-references.log
```

TSV由 [ExportEntryReferences.java](../tools/ExportEntryReferences.java) 产生，参数依次为输出路径、匹配上表11根的正则、原`uac_symbol_fun`路径；反向日志由 [FindCallers.java](../tools/FindCallers.java) 对清单`direct_targets`中的全部函数生成，包括零引用目标。二者均通过 Ghidra `analyzeHeadless -process uac -readOnly -noanalysis -postScript` 执行，未运行固件。

新增/扩展的四项空邻居回归在修复前实现下全部失败，修复后通过；覆盖同包、跨服务、分包以及 UDP 接收→59序列化→模拟AP接收。模拟AP验证的是已确定的Go分支，不作为原算法的来源。

此清单闭合的是所列注册根、目标和V6产品可用路径，不能据此承诺任意间接跳转已经形式化穷尽，或未来再核查绝不会发现偏差。没有用增加测试数量冒充全参数等价证明。本轮无需实机或原UAC运行时，未部署到实验AP。
