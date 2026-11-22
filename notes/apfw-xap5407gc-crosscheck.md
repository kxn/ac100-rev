# AP 固件交叉验证 — TL-XAP5407GC-PoE DC易展版 V1.0.16 (2022-09-02)

AP 侧固件（`TL-XAP5407GC-PoE_DC易展版 V1.0_1.0.16_Build_20220902_Rel.42859.bin`，
12,387,328B，仓库根目录）与 AC 侧 `uac` 逆向结论的对应验证。结论：**同一线协议、
同一元素 ID 空间、同一套漫游决策/执行分工，全部对上。**

> **来源边界（重要）**：Go 复刻的**一切数据与逻辑只取自 AC 二进制**
> （`firmware/usr/sbin/uac`）。AP 固件**仅用于交互逻辑校验**——验证两侧
> 报文字段/流程互相咬合，**不作为任何数据或逻辑的来源**。本文档记录的即
> 校验证据本身。

## 1. 固件解包

- TP-Link 私有头 `00 00 01 00 55 aa …`（512B），其后高熵（压缩/加密）。
- **squashfs 4.0 (xz, 256KB block) 根文件系统 @ 文件偏移 0x262194**（"hsqs" 魔数，
  filesystem size 9,618,222B）：

```sh
dd if=<fw.bin> of=sq.bin bs=1 skip=$((0x262194))
unsquashfs -d rootfs sq.bin
```

- 平台：**ARMv7 LE (EABI5) + musl**，QCA IPQ 系（qca-nss-drv/qcn9000，kernel 4.4.60），
  与 AC（MIPS32 BE uClibc）不同架构——协议跨平台互通。

## 2. AP 侧程序布局

| 文件 | 说明 |
|---|---|
| `bin/dms` (3,993,432B) | 用户态管理/CAPWAP WTP 端守护（device management service），stripped 但 **`.dynsym` 完整（6758 个导出符号）** |
| `lib/modules/4.4.60/k_capwap.ko` | CAPWAP 内核数据面（AC 侧没有对应：AC 是纯用户态） |
| `lib/modules/4.4.60/wportal.ko` | portal（AC 侧对应 wportal 子系统） |

## 3. 元素 ID 对照（核心证据）

AP 侧每个 vendor 元素有一个 96B 描述符（`.data`，名字内嵌 + type id），全表提取在
**`notes/apfw-xap5407gc-elems.tsv`**（73 项，含本地符号项）。与 AC 侧
`notes/elements.tsv` 私有元素逐 ID 对照：**66 个共有 ID 全部语义一致**（命名差异
只是习惯不同）。抽样：

| id | AP (dms) | AC (uac) | 语义 |
|---|---|---|---|
| 0x0b | PROBE_NOTIFY | station discovery | 探针上报=balance"sta want connect" |
| 0x3e | RSSI_THRESHOLD | spec rssi | balance 信号阈值下发 |
| 0x49 | PMK_REQUEST | station pmk request | 11r PMK-R0 分发 |
| 0x57 | ROAMING_CONTROL | roaming control request | 漫游参数下发 |
| 0x59 | ROAMING_RESULT | roaming calculate result request | AC 算出的漫游目标 |
| 0x5a | STA_DEAUTH_IMPLICTLY_RES_INFO | delete implicitly leave station | 隐式离线 |
| 0x5d | RRM_NEIGH_INFO_CTRL | rrm neighs list | 11k 邻居表 |
| 0x6f | LED_MODE_CONTROL | ap led mode control | LED 模式 |

差异与注记：
- **0x58（AC: roaming trigger）**：AP 侧无导出描述符（本地符号），对应
  `CWAssembleMsgLowRssiStaListReport`（"low rssi station list report to AC"），
  枚举名 `VENDOR_SPEC_PAYLOAD_TPS_INFO` 之外的本地实现；字段布局与 AC dump
  **逐字段一致**（见 §4）。
- `CWVendor_tps_info` = 0x3a（AC: ap spectral），与 0x58 无关。
- AP-only 6 项（0x20 CFG_VER/0x22 STA_CHANNEL/0x29 PORTAL_FRESH/0x2d/0x37/0x64），
  AC-only 54 项（AC 注册表更全：0x52-0x54 统计、0x4c rssi_orient、0x5f ap log 等）。

## 4. 漫游闭环逐环节对照

| 环节 | AC (uac, MIPS) | AP (dms, ARM) | 一致性 |
|---|---|---|---|
| 0x57 解析/参数 | `cw_priv_roaming_control_dump`: _11k/_11v/_11r_switch、2g/5g trigger_type/rssi_trigger/rssi_kick en+th/rate_kick、check_interval、roaming dif、blacklist restrict time、strategy(distributed/centralized) | `wtp: [11kv] roaming control : k:%d, v:%d, r:%d` + `2G/5G : trigger type, rssi trigger, rssi kick en/th, rate trigger, rate kick en/th` + `check interval, roaming diff, black time`；`[%s] 11k,11v,11r,check_intval,roam_diff,black_time,roam strategy` | **字段逐项一致** |
| 0x58 触发上报 | `_wsta_roam_pkt_roaming_trigger_request` dump: radio id / channel load / noise floor / station count → sta {mac, wlan_id, rssi, band_mode, neighbor_cnt} → {bssid, rcpi, rsni, channel} | `---------- low rssi station list report to AC` / `LowRssiStaListEvent -> radio_id, channel_load, noise_floor, sta_cnt` → `sta_mac, wlan_id, rssi, band_mode, neighbor_cnt` → `bssid, rcpi, rsni, channel` | **字段逐项一致** |
| RCPI 归一化 | `_bstm_ngr_generate`: method 探测 (0/1/2), method1 = (raw>>1)+146 | `RCPI Method %d(0:Legacy 1:Protocol 2:Unknown)`、`Un-Consistent RCPI Method Judgement`、`Convert Protocol RCPI into Legacy`、`RCPI from %d to %d` | 同一算法族 |
| 0x59 结果消费 | `_roaming_nbr_packet_create` 组装 ap_union+bitmap+{ap,radio,wlan,bssid,channel} | `CWVendorInfo_roaming_result` / `VENDOR_SPEC_PAYLOAD_ROAMING_RESULT`；`Total=%d Availiable=%d Strategy=%d Bitmap=%d` | 一致 |
| 速率估算 | `estimate_rate_from_snr` + `estimate_snr_rate_table_2g/5g`（AC 符号表） | **同名函数/表**：`estimate_rate_from_snr` @0x1a0afc、`estimate_snr_rate_table_2g/5g`、`estimate_snr_from_rcpi`、`Estimate Rate for all Candidate AP` | 共享算法库 |
| 执行：BTM | AC 只算不发 BTM | `wlan_ioctl_btm_request`、`steer_send_btm_request_debug`、`Trigger BTM Request to …`、`recv BTM Response`、`wss_event_btmrsp`、`2ghighbtm/btmreq` 配置 | AP 执行 |
| 执行：踢/黑名单 | AC 下发 kick 阈值（0x57） | `wlan_ioctl_set_rssi_kick(_enable)`、`delayKickSta`、`wlan_netif_deauth`、`cwvendor_roaming_set_blacklist`、`roam blacklist for sta … time out in %d seconds`、`auth reject by roam blacklist` | AP 执行 |
| 11r PMK | `_wsta_roam_pkt_pmk_request`（nonce/pmk_r0/pmk_r0_name, 0x49） | `wss_aps_priv_ft_pmk_request_make`、`CWAssemblePMKEventRequest`、`wlan_ioctl_setPmkr0Info`、`dumpPmkr0Packet`、`wss_ft_check_sta_is_in_pmk_table` | 一致 |
| 11k 邻居 | `_roaming_nbr_*`（AC 算 BSTM 邻居） | `cw_rrm_neigh_assemble`、`cw_rrm_neigh_upload`、`CWVendorInfo_rrm_neigh_list`(0x5d)、`EVENT_STA_NEIGHBORREQ` | 一致 |

## 5. 分布式/集中式策略的实物证据

0x57 的 `roaming strategy: distributed / centralized / both` 两侧都能看到实体：
- **centralized** = AC 的 `_wsta_roam_pkt_roaming_trigger_request` → 0x59（本仓库
  notes/00-architecture.md 已取证）。
- **distributed** = AP 侧自带的 `wss`（wireless station steering）本地引擎：
  `wss_steer_*`（config_update_5gprefer_5g / band_hide / 2ghigh_btm / strategy_adjust）、
  `wss_event_*`（Probe:1 Assoc:2 DisAssoc:3 RssiXing:4 Activity:5 AuthRej:6 BeaconRsp:7
  NeighborReq:8 BTMRsp:9 BandHide:10 事件枚举）、STA 能力转储
  `Band/RRM/BTM/BW/NSS/Mode/MCS/TxPower/Steer/Blackout/AdjustThres/BandHide`。
  AP 本地也能算候选速率（"Estimate Rate for all Candidate AP"），与 AC 算法同源。

## 6. 对 Go 复刻的意义

> 按来源边界：以下均以 AC 二进制为数据/逻辑来源，AP 侧仅作校验。

- 元素编解码（118 项）可直接与 `apfw-xap5407gc-elems.tsv` 做 ID 级回归核对。
- 0x58/0x59/0x57 的字段序已被两个独立实现（AC dump + AP log）互证，Go 的
  `PrivRoamingTrigger/PrivRoamingCalcResult/PrivRoamingControl` 结构可据此定案。
- 速率估算数据缺口由 **AC 二进制自身**补齐（并非取自 AP）：`uac_symbol_obj`
  的 `estimate_snr_rate_table_2g @0x731668` / `_5g @0x731550`（各 0x118B）+
  `nsdTable @0x731500`（0x50B）→ `uacgo/data/estimate-rate-tables.bin`
  （640B 逐字节提取）；AP 侧同名表仅用于一致性校验。

## 7. 取证方法备忘

- dms 为 PIE (ET_DYN) + REL 重定位；`.dynstr/.dynsym` 未剥离，符号名可直接取。
- 96B 描述符结构：`char name[…]` 内嵌 + u32 id（name 后第一个 <0x10000 的字）。
- ARM 反汇编用 capstone（python）；注意 `mov r2,#0x58` 一类立即数多为 memset
  长度（0x58=88B 结构体），不能当作元素 ID 用。
