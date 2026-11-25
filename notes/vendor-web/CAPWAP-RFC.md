# TL-AC100 V6.0 CAPWAP 的 RFC 兼容性

范围为 TL-AC100 V6.0 1.0.3 Build 260817 的 QEMU 原厂 `uac` 与实体 TL-XAP3006GC-PoE/DC。帧号来自 `qiyitt.pcap` 原始抓包，解密和保留帧号的方法见 QEMU 记录。以下分别比较编号、字段格式、消息必选元素和实测行为。控制端口的验证覆盖发现、入网、运行状态和 WLAN 下发。 [QEMU 抓包与解密](../qemu-firmware.md#离线导出-capwap-会话明文)

## 可按 RFC 实现的部分

| 层或字段 | 实测证据 | 规范 |
|---|---|---|
| UDP 控制端口 | 实帧 102/103 和 204/205 以 AC UDP 5246 与对端临时端口收发。 | [RFC 5415 §3.1](https://www.rfc-editor.org/rfc/rfc5415.html#section-3.1) |
| 外层封装 | Discovery Request/Response 为明文。第 111 帧外层为 `01 00 00 00`，其后为 DTLS 记录。版本 0、Type 1 和 24 位保留零均与标准一致。 | [RFC 5415 §4、§4.1–4.2](https://www.rfc-editor.org/rfc/rfc5415.html#section-4) |
| DTLS 协商 | Server Hello 选择 DTLS 1.0 和 `0x0035 TLS_RSA_WITH_AES_256_CBC_SHA`。RFC 5415 对证书模式列为可选套件。AC 证书身份另见下文。 | [RFC 5415 §2.4.4.1](https://www.rfc-editor.org/rfc/rfc5415.html#section-2.4.4.1) |
| Transport/Control 头结构 | 实测普通控制报文 HLEN=2，WBID=1，Control Header 为 8 字节。Message Type 和 MEL 采用大端，Control Flags 为 0，请求和应答的序号一致。第 204 帧 HLEN=8 字节、明文 84 字节、MEL=`00 47`，恰为序号之后的 71 字节。TLV 占 68 字节，余下 3 字节为 MEL 字段本身和 Flags。 | [RFC 5415 §4.3、§4.5.1](https://www.rfc-editor.org/rfc/rfc5415.html#section-4.5.1) |
| TLV 外壳和 Result Code | 顶层 `type:BE16, length:BE16, value`，长度只计 value。帧 127、205、233 包含 `0x21`、Length=4、Result Code=0。帧 256 的 Echo Response 无 TLV，MEL=3，与 §7.2 允许空响应一致。 | [RFC 5415 §4.6](https://www.rfc-editor.org/rfc/rfc5415.html#section-4.6)、[§4.6.35](https://www.rfc-editor.org/rfc/rfc5415.html#section-4.6.35)、[§7.2](https://www.rfc-editor.org/rfc/rfc5415.html#section-7.2) |
| 射频配置元素的编号与定长布局 | 帧 152/154 的 Configuration Update 带 1028 Direct Sequence Control（8 字节）、1030 MAC Operation（16 字节）、1041 Tx Power（4 字节）、1046 WTP Radio Configuration（16 字节），同时带独立厂商项。 | [RFC 5416 §5.9、§6](https://www.rfc-editor.org/rfc/rfc5416.html#section-5.9) |
| WLAN 配置消息编号 | `0x0033DD01/02` 即十进制 `3398913/3398914`。高 24 位 `0x0033DD` 是 IEEE 802.11 的 IANA Enterprise Number 13277，低位 `01/02` 为 WLAN Configuration Request/Response。帧 204/205、232/233 都使用这一对。 | [RFC 5416 §3](https://www.rfc-editor.org/rfc/rfc5416.html#section-3)、[IANA CAPWAP](https://www.iana.org/assignments/capwap-parameters/capwap-parameters.xhtml) |

同版本固件的收发入口为 `capwap_packet_parse @0x0063800c`、`capwap_packet_assemble @0x00638f34`。从 `cw_header_parse @0x006792f0` 和 `cw_control_header_parse @0x00679890` 定位两级头，从 `cw_result_code_parse @0x00643de0` 定位标准 Result Code。

## 标准消息与实发内容的差异

| 消息 | 帧号 | 报文对照 |
|---|---|---|
| Discovery `1/2` | 102/103 | 请求含 Discovery Type、Board Data、Descriptor、Frame Tunnel Mode、MAC Type 和两条 Radio Information。AC 应答含 AC Name、AC Descriptor、两条 Radio Information 和 Control IPv4 Address，并附 `0x25` 私有项及 §5.2 未列出的 Local IPv6 Address（50）、AC Name with Priority（5）。更早的短应答 39 只有 37、50、5，缺 §5.2 必选的 AC Name、AC Descriptor、Radio Information 和 Control 地址。两次请求分别带不同内容，短应答的分支条件尚未确认。 [RFC 5415 §5.1–5.2](https://www.rfc-editor.org/rfc/rfc5415.html#section-5.1) |
| Join `3/4` | 118/119 | Join Request/Response 编号、方向和必选元素族可按 RFC 处理。AC 响应含 Result Code=0，并附三个 `0x25` 项。两条 Radio Information 的位图末字节为 `2f`、`3f`，标准定义的低四位之外还有 `0x20`、`0x30`，IANA 当前未分配这些位。字段由 `cw_80211_wtp_radio_information_assemble @0x0067c8ec` 组装，扩展位语义待核实。 [RFC 5415 §6](https://www.rfc-editor.org/rfc/rfc5415.html#section-6)、[RFC 5416 §6.25](https://www.rfc-editor.org/rfc/rfc5416.html#section-6.25)、[IANA CAPWAP](https://www.iana.org/assignments/capwap-parameters/capwap-parameters.xhtml) |
| Configuration Status `5/6` | 120/121 | 请求含 RFC 5415 的 AC Name、Radio Administrative State、Statistics Timer、WTP Reboot Statistics，但缺 RFC 5416 要求按 radio 携带的 1048。响应含 CAPWAP Timers（12，值 `14 1e`）、Decryption Error Report Period（16）、AC IPv4 List（2）、WTP Fallback（40）和私有项，缺必选 Idle Timeout（23）。随后帧 138 的 `7` 才出现 23。计时器编码入口为 `cw_capwap_timers_assemble @0x0065b0b0`。 [RFC 5415 §8.2–8.4](https://www.rfc-editor.org/rfc/rfc5415.html#section-8.2)、[RFC 5416 §5.7](https://www.rfc-editor.org/rfc/rfc5416.html#section-5.7) |
| Change State Event `11/12` | 122/123 | 请求只有 Result Code=0，缺 §8.6 所列的 Radio Operational State（32）。应答为空，符合 §8.7 的元素列表。 [RFC 5415 §8.6–8.7](https://www.rfc-editor.org/rfc/rfc5415.html#section-8.6) |
| Configuration Update `7/8` | 126/127、128/129、152/153 | 射频类请求混有标准元素和私有子项，另有请求仅用 `0x25` 携带厂商配置。帧 126 由 AC 下发顶层 Type 54、Length 16、值全零。IANA 将 54 分配给 RFC 8350 的 WTP→AC 能力通告，该帧至少在方向上不符合该定义。当前仅确认实发格式和方向。帧 127、129 的标准 Result Code 响应可复用。 [RFC 5415 §8.4–8.5](https://www.rfc-editor.org/rfc/rfc5415.html#section-8.4)、[RFC 8350 §3.1](https://www.rfc-editor.org/rfc/rfc8350.html#section-3.1) |
| WTP Event `9/10` | 124/125、248、251、398 | `9/10` 编号和方向是标准的。帧 248 的 SSID 上报在私有子项 `0x80`。AC 应答常附 RFC 5415 §9.5 未列出的 Result Code。帧 398 的顶层 Type 51 长 19 字节，标准同号元素为 CAPWAP Transport Protocol，长度固定为 1。此变体内容待确认，Go 解析时需按消息和长度区分。 [RFC 5415 §9.4–9.5](https://www.rfc-editor.org/rfc/rfc5415.html#section-9.4)、[§4.6.14](https://www.rfc-editor.org/rfc/rfc5415.html#section-4.6.14) |
| Echo `13/14` | 254/256 | AP 发请求、AC 原序号应答。AP 请求的 `0x25` 子项 `0x20/0x38` 自定义，AC 应答无 TLV。RFC 5415 允许在 Echo 中携带 Vendor Specific Payload。 [RFC 5415 §7](https://www.rfc-editor.org/rfc/rfc5415.html#section-7) |

控制消息之外也有可直接验证的差异。RFC 5415 §4.3 要求 DTLS 内层 CAPWAP 前导 Type 为 0。AC 实发 `00 10 43 00`，AP 内层发 `01 10 43 00`，两端都在 DTLS 外层使用标准的 `01 00 00 00`。在 Go 版按封装层分别解析，可保留对该 AP 内层 Type 1 的兼容。帧 1150、1821 的 AP 末片也带内层 Type 1，F/L 置位，片偏移字段为 175，即 1400 字节。未用本次导出验证完整重组。 [RFC 5415 §3.4、§4.2–4.3](https://www.rfc-editor.org/rfc/rfc5415.html#section-4.3)

QEMU TAP 抓包里的 AC IPv4 UDP 校验和字段为非零，例如帧 103、111、204。RFC 5415 §3.1 要求填零，这里只确认抓包点上的实发字段。固件 AC 证书与帧 112 指纹匹配，`openssl x509 -noout -ext extendedKeyUsage` 显示无扩展，缺 RFC 5415 §2.4.4.3 首段要求的角色 EKU。证书授权策略及 AP 证书未做完整测试。 [RFC 5415 §3.1](https://www.rfc-editor.org/rfc/rfc5415.html#section-3.1)、[§2.4.4.3](https://www.rfc-editor.org/rfc/rfc5415.html#section-2.4.4.3)

## TP-Link 私有元素与 WPA2

外层 Type 37（`0x25`）是 RFC 5415 的 Vendor Specific Payload。标准结构为 `Vendor Identifier:BE32, Element ID:BE16, Data`。实测 `uac` 在 Data 中继续用 `subtype:BE16, length:BE16, value` 分派，并在外层 Vendor Identifier 字段使用 `0` 或 `0x12345678`。帧 119、121、128 展示 AC 写 0 的路径，帧 204 展示 AC 写 `0x12345678` 的路径，AP 的帧 118、205 也使用后者。规范要求该字段为 IANA 分配的私有企业号，注册表所列 TP-Link 企业号为 11863 和 65855。兼容实现按样本保留两个实发值，并按内层 subtype 解释内容。汇编入口为 `cw_vendor_specific_payload_assemble @0x00639bac`、`cw_vendor_specific_payload_parse @0x00639fd0`、`cw_msg_ele_priv_mngr_get @0x0064f85c`。 [RFC 5415 §4.6.39](https://www.rfc-editor.org/rfc/rfc5415.html#section-4.6.39)、[IANA 企业号](https://www.iana.org/assignments/enterprise-numbers/)

WLAN 下发的 `0x0400` 是标准 Add WLAN，SSID、Radio ID 和 WLAN ID 可以复用 RFC 编解码。实测 `Suppress SSID=1` 正好符合 RFC 5416 §6.1 的「广播名称」。Tunnel Mode 实发 `1`，RFC 枚举对应 802.3 Tunnel，本次未验证数据面转发是否采用该模式。加密与开放样本的 Capability 均为 `0x8000`，即 ESS 位为 1、Privacy 位为 0。WPA2 帧的 `0x0400` Key Length 为 0，无伴随的 `0x0405` RSN Information Element。RFC 5416 的 Key 指会话密钥，CCMP 情况下是 GTK。实测 WPA2 的认证枚举、密码套件枚举、更新周期和 PSK 都由 TP-Link 私有 `0x63` 携带，并由 AP 本地生成相应安全配置。 [RFC 5416 §6.1](https://www.rfc-editor.org/rfc/rfc5416.html#section-6.1)、[WLAN 报文字节布局](README.md#capwap-明文与汇编)

实测 `0x63` 的 9 字节前缀末字节选安全分支。`0` 用于开放样本 160、212。`1` 用于 WPA2 样本 204、232，尾部依次为 `auth:u8, cipher:u8, key_update_intv:BE32, key_len:BE16, key`。应答 205、233 使用标准消息号和 Result Code，并有厂商 `0x1f`。固件发送入口为 `_uac_wserv_packet_send_callback @0x006dbd74`、`cw_80211_add_wlan_assemble @0x0065a5d4`、`cw_priv_wsrv_para_new_assemble @0x00695f68`，PSK 分支为 `0x006960c0`。固件还含 `0x09`、`0x94` 分支，当前 AP 样本没有用它们配置 WPA2。 [WLAN 复核](../sched-engines/REVIEW.md)

## Go 实现与验收依据

1. 公共编解码采用 RFC CAPWAP Transport Header、Control Header、MEL、消息编号、通用 TLV 和 802.11 基础元素。同一格式用于标准端点与 TP-Link 会话。
2. TP-Link 设备兼容处理 AP 的内层 Type 1、私有 Vendor Identifier 和 subtype、管理消息的必选项差异，并按 AP 能力选择 WLAN 安全扩展。Go 里的 JCS 是本地管理接口，线上兼容由 CAPWAP 会话和编解码实现。
3. 以第 204 帧验证 `0x0033DD01`、长度 `84 = 8 + 5 + 71`、`0x0400` Key Length=0、`0x63` 长 25。开放对照 160 的 `0x63` 长 9。以 205、233 验证序号回显和 Result Code=0，空中扫描已确认双频 WPA2-PSK/CCMP。以 120/121、122/123、398 验证标准解释与实发差异。严格标准解析和 TP-Link 兼容解析应各有这些输入的断言。
4. `uacgo/capwap/control.go` 现有注释把 MEL+3 写为厂商差异，把 23/24 标为 WLAN，把 `0x0033DD01/02` 标为伪类型。按 RFC，23/24 是 Clear Configuration，25/26 是 Station Configuration，WLAN 的标准编号为 `0x0033DD01/02`。当前抓包未覆盖 23/24、25/26，Go 中现有名称不能证明原厂 AC 对这些编号的实际行为。

分析输入为一份包含 1910 帧明文的快照及明文 Discovery 报文。完整可按头部解析的 1908 个 DTLS 内层包全部通过 MEL 长度检查，余下两个是末片。当前 TAP 只接入 AP 的 UDP 5246 控制通道，未验证 5247、数据通道保活、完整分片重组、重传容错、升级、漫游和跨厂互通。 [QEMU 采集路径](../qemu-firmware.md#实体-ap-与-qemu-的联调链路)
