# TL-AC100 V6.0 Web、uac 与 CAPWAP 对照

固件为 TL-AC100 V6.0 1.0.3 Build 260817 Rel.68871n。本文地址取自该固件自己的 `usr/sbin/uac` 和 `usr/sbin/uac_symbol_fun`。ELF Build ID 为 `7346df6c645058f30948c066f93708c38cc2193e`，SHA-256 为 `b12d1584fcafda2a71aa9038b41b7e1c5b893b350f3e6edf5105e445d024a912`。仓库 `asm/` 是另一构建，函数地址需要按版本查。目标 AP 为 TL-XAP3006GC-PoE/DC，设备 MAC `04:F9:F8:76:A1:97`。实测环境为 [QEMU AC 与实体 AP](../ap-deployment/PROGRESS.md)。

## 完整 JCS 接口文档

uac 的 278 个 `(name, op)` 注册项、传输封装、处理函数地址、字段类型证据、逐接口探测输入/响应和验证层级见 [UAC-INTERFACES.md](UAC-INTERFACES.md)。机器可读的逐接口状态在 [jcs-verification.tsv](jcs-verification.tsv)，字段 getter/地址在 [jcs-types.tsv](jcs-types.tsv)，Web 侧字段构造表达式在 [jcs-web-expressions.tsv](jcs-web-expressions.tsv)，277 个原始请求/响应在 [captures/jcs-samples.jsonl](captures/jcs-samples.jsonl)。

## Web 全局索引

| 索引 | 条目 | 用法 |
|---|---:|---|
| [Web 路由](web-routes.tsv) | 118 | 按路径、菜单名或组件名在 `app.*.js` 中定位。行列号可区分同名路由和不同设备分支。|
| [LuCI 操作](web-operations.tsv) | 659 | 用 `module`、`keyword` 与方法定位控制器、处理函数和处理函数中的直接 JCS 调用。包含模块和 section 注册。|
| [JCS 调用](web-jcs-calls.tsv) | 371 | 按控制器、函数、调用名、操作、参数表达式反查。涵盖 `jcsUI2uac`、`jcsService2uac`，也保留发给其他进程的调用。|

索引通过解析原厂打包后的 JS 与 77 个 `usr/lib/lua/luci/controller/admin/*.lua` 生成。路由索引收录对象中的字面量，动态拼接和能力开关可能改变设备上实际显示的菜单。参数列表中的变量名保留原 Lua 表达式，`~` 表示从文件级赋值推得的候选名称。调用列为空时，处理逻辑可能通过局部函数继续调用 JCS，也可能直接读写 UCI、SQLite 或其他服务。277 个 JCS 命令已在厂商 `uac` 的 QEMU 环境中执行并记录响应，1 个 WIPS 请求在畸形探针下触发崩溃。AP 真实生效目前只验证入网/状态/SSID 查询和 `qiyitt` 双频 WPA2 下发；其余接口响应不代表 AP 已应用配置。实际浏览器登录和 HTTP 提交未联调。

## 请求如何进入 uac

Web 发送包含 `method`、模块名以及模块内 `name` 或 `table` 的 JSON。`filter`、`para`、`start`、`end` 按操作传递。LuCI 的 `luci/controller/ds.lua` 在 `do_ds` 中分派，注册表位于原厂控制器的 `index()`。本次 QEMU 用固件 Lua 直接调用已注册的后端函数。实际浏览器登录与 HTTP POST 未联调。

以下是 WLAN 新建表的 Web 字段与后端层次示意。实际启用的附加字段见后文。

```json
{
  "method": "add",
  "apmng_wserv": {
    "table": "wlan_serv",
    "para": {
      "ssid": "qiyitt",
      "ssid_code_type": 1,
      "enable": "on",
      "auto_bind": "on",
      "default_bind_freq": 257,
      "default_bind_vlan": 0,
      "encryption": 1,
      "auth": 2,
      "cipher": 2,
      "key": "<PSK>"
    }
  }
}
```

`luci/torchlight/uac/jcs.lua` 把调用封装为 `{"name": "...", "op": 0, "clt_path": "...", "data": {...}}`。UI 路径用 `/tmp/jcs.ui.srv.uac`，进程间服务路径用 `/tmp/jcs.service.srv.uac`，客户端自己绑定回包地址。操作码为 ADD `0`、DEL `1`、SET `2`、GET `3`。原厂 Lua 使用 `uds` 的本地数据报接口。Go 重建版的本地 JCS 包装另有 JSON 格式，见 [Go JCS](../../uacgo/jcs/jcs.go)。

## AP 管理

「AP 状态」的路由为 `apStatus`，其「无线服务列表」子路由为 `apSsidList`。子页面的 `apManagement-apSetting-status-ssid-index-vue.34e5e6fe684f8cfa6269.js` 把 `entryId` 放入 `apmng_status.ap_ssid_list` 的过滤器，由 `apmng_status.lua` 的 `get_ap_ssid_list_data` 处理。AP 重连前 `online_num=0`，重连后 `online_num=1`，`ap_status` 返回目标 MAC。新建前 `ap_status_ssid` 返回两条默认 SSID，新建并重连后又返回两条启用的 `qiyitt`。这些 GET 读取 AC 当前状态。

| Web 条目 | JCS 名称及操作 | 参数、结果及 uac 函数 |
|---|---|---|
| AP 列表 `ap_list` | `ap_status` GET | `start`、`size=end-start+1`、`ap_role`。支持组、状态、搜索和排序。结果含 `total_num`、`file_name`，LuCI 读回文件中的 AP 列表。 `_apmngr_jcs_entry_get @0x006060d4`。 |
| AP SSID `ap_ssid_list` | `ap_status_ssid` GET | Web 的 `filter[1].entry_id` 转成字符串，`start` 转成数字，`size=end-start+1`。实测 JCS 参数为 `{"entry_id":"0","start":0,"size":64}`。结果含 `total_num`、`ssid_entry[]`。每条含 SSID、频段、启用状态、加密模式、编码、VLAN 和描述。 `_apmngr_jcs_ssid_get @0x005ed95c`。 |
| 在线及离线数量 | `ap_count` GET | 本次传 `{}`，返回 `online_num`、`offline_num`、`total_num`。 `_apmngr_jcs_ap_count_get @0x005f414c`。 |
| AP 数量趋势 | `ap_count_trend` GET | 接收筛选对象，返回 `ap_count_trend`。 `_apmngr_jcs_ap_count_trend_get @0x005f42b4`。 |
| 在线 AP 型号 | `apmngr_online_model` GET | 接收列表查询条件，从 `file_name` 取结果，`total_num` 分页。 `_apmngr_jcs_online_ap_model_get @0x005f8c94`。 |
| 重启、复位、LED | `ap_status_evt` SET | `entry_id`、`evt`。重启和复位使用 `reboot` 和 `reset`。 `_apmngr_jcs_ap_evt @0x005f8888`。 |
| Telnet、崩溃转储开关 | `ap_telnet_status_evt`、`ap_crashdump_status_evt` SET | `entry_id`、`evt`，Lua 按对应开关选择事件。 `_apmngr_jcs_ap_telnet_evt @0x005f8558`、`_apmngr_jcs_ap_crashdump_evt @0x005f8228`。 |

## WLAN 服务与射频绑定

「无线服务」的路由为 `wirelessService`，组件为 `apManagement/wirelessService/ac/index`。「射频绑定」子路由 `rfBindList` 使用 `apManagement/wirelessService/rfBind/ac/index`。后端为 `apmng_wserv.lua`。新建路径为 `add_wserv_list_data` → 局部函数 `A` 归一化 → `wservice` ADD → `_uac_wserv_jcs_add`，成功后 LuCI 写入 WLAN SQLite 表。`qiyitt` 获得 `serv_id=2`，AP 重连后控制器向两个射频分别下发。

| Web 条目 | JCS 接口 | 传参和汇编入口 |
|---|---|---|
| 无线服务读列表 `wlan_serv` | 读 WLAN SQLite | `start`、`end`、过滤器。结果按 `serv_id` 命名并附 VLAN 类型。 |
| 无线服务新建 | `wservice` ADD `0` | `serv_id=-1` 由 AC 分配。其余见字段表。返回 `serv_id`。 `_uac_wserv_jcs_add @0x006e3970`。 |
| 无线服务编辑 | `wservice` SET `2` | `operation=0`，现有 `serv_id`，先加载旧记录再合并新字段。 `_uac_wserv_jcs_set @0x006e2fd4`、`_uac_wserv_jcs_modify @0x006e06b8`。 |
| 批量启用、停用 | `wservice` SET `2` | 逗号分隔的 `serv_id`，`operation=3` 启用、`4` 停用。 |
| 无线服务删除 | `wservice` DEL `1` | 每个请求一个数值 `serv_id`。Web 也能以 `ssid_id` 查找服务。 `_uac_wserv_jcs_del @0x006e3590`。 |
| 读取射频绑定 `radio_bind_list` | `wservice` GET `3` | 必填 `serv_id`，分页 `limit`、`offset`，可带 `group_id`、`radio_id`、`search_cond`。响应 `file_name`、`total_num`。 `_uac_wserv_jcs_get @0x006d5670`。 |
| 写入射频绑定 | `wservice` SET `2` | `operation=1` 绑定、`2` 解绑。传 `serv_id`、逗号连接的 `radio_id`，绑定时传等长的 `vlan_id` 列表。 `_uac_wserv_jcs_rd_op @0x006d7838`。 |
| IGMP 全局设置 `igmp_settings` | GET 读 UCI，SET 调 `wserv_global` | 开关、速率、查询周期和响应时间。 `_uac_wserv_jcs_global_set @0x006d4428`。 |
| IGMP 组播地址 `igmp_ip_list` | `wservice_ip` ADD、SET、DEL | 新建用 `ip_addr`、`relay`、`enable`，修改及删除用 `id` 标识。 `_uac_wserv_ip_jcs_add @0x006e6e4c`、`_uac_wserv_ip_jcs_set @0x006e616c`、`_uac_wserv_ip_jcs_del @0x006e6ac0`。 |
| PPSK 组和用户 | `ppsk_group`、`ppsk_user` | 组用 `name`、`group_id`。用户用 `id`、`username`、`passwd`、`group_id`、`mac`、`wserv_id`，字段随方法变化。完整调用点在 [JCS 索引](web-jcs-calls.tsv)。 |

### 新建字段

| Web / JCS 字段 | 本次配置及用途 |
|---|---|
| `ssid`、`ssid_code_type`、`desc`、`ssid_id` | 名称 `qiyitt` 写入 `0x0400` 尾部，编码 `1` 表示 UTF-8。描述及平台 SSID 标识保留在配置层。 |
| `enable`、`ssidbrd`、`isolate` | `on`、`1`、`0`。服务启用、广播可见、关闭隔离。 |
| `auto_bind`、`default_bind_freq`、`default_bind_vlan` | `on`、`257 = 1 + 256`、`0`。该频段掩码使同一服务绑定 2.4 GHz 和 5 GHz，实际下发的 Radio ID 分别为 `1` 和 `2`。 |
| `encryption` | `1` 表示 PSK 家族，选择 `0x63` 的 PSK 尾部。页面另有关闭 `0`、企业认证 `2` 和混合安全等选项。 |
| `auth`、`cipher` | `2`、`2`。前端枚举分别为 WPA2、AES，在 PSK 尾部表现为相邻字节 `02 02`。 |
| `key_update_intv`、`key` | `86400` 秒和 8 字节测试 PSK。CAPWAP 明文里的 `0x63` 带长度和原始 PSK 字节。 |
| `radius_ip`、`radius_port`、`radius_acct_port`、`radius_pwd`、`radius_nas_id`、`radius_session_timeout`、`radius_auth_channel`、`radius_vlan_enable`、`ppsk_group` | 认证分支字段。此次 PSK 模式沿用 Lua 缺省值，`ppsk_group=-1`。 |
| `bw_ctrl_enable`、`bw_ctrl_mode`、`up_limit`、`down_limit` | 带宽控制组。本次用 Lua 的禁用缺省值。 |
| `igmp_snooping_enable`、`igmp_multi_to_unicast`、`igmp_drop_unknown`、`igmp_2g_rate`、`igmp_5g_rate`、`igmp_2g_rate_type`、`igmp_5g_rate_type`、`igmp_query_interval`、`igmp_max_resp_time`、`igmp_snooping_switch`、`igmp_query_switch` | 本次显式传 `on,on,0,1,6,0,0,60,10,on,off`。QEMU 合成的全局 UCI 将 `igmp_drop_unknown` 写成 `on` 时，LuCI 的 `tonumber` 得 nil，新建失败。使用数值 `0` 后成功。 |
| `central_forward_switch`、`time_switch`、`mlo_switch` | 本次为 `off`、`off`、`0`。CAPWAP 里的附加开关含义需用单变量对照进一步确定。 |

## CAPWAP 明文与汇编

QEMU 的启动、TAP 抓包及会话明文导出命令见 [QEMU 联调与离线解密](../qemu-firmware.md#离线导出-capwap-会话明文)。
标准 CAPWAP 字段、TP-Link 扩展与观测到的规范偏差见 [CAPWAP RFC 对照](CAPWAP-RFC.md)。

原始抓包是 `/tmp/ac100/uac-check.7YxFd9/qiyitt.pcap`。帧号以下均取原始 PCAP。第 111 帧协商 DTLS 1.0 和 `TLS_RSA_WITH_AES_256_CBC_SHA (0x0035)`。第 112 帧携带的 AC 公钥证书 SHA-256 指纹与固件 `/etc/cacert.pem` 一致。离线解密所需的密钥材料来自该证书对应的 AC RSA 私钥。该套件使用静态 RSA 密钥交换，因此可以从原始握手和对应私钥恢复本次会话密钥。解码时移除 UDP 负载最前面的四字节 CAPWAP DTLS 前导，交给 Tshark DTLS 解码器，记录 `data.data`。DTLS PDU 中的明文还保有自己的 CAPWAP 头。

| 请求帧 / 应答帧 | 方向、用途 | 消息 / 序号 |
|---|---|---|
| 160 / 161 | AC → AP，2.4 GHz 默认开放 WLAN | `0x0033DD01 / 0x0033DD02`，`18` |
| 204 / 205 | AC → AP，2.4 GHz 的 `qiyitt` | `0x0033DD01 / 0x0033DD02`，`36` |
| 212 / 213 | AC → AP，5 GHz 默认开放 WLAN | `0x0033DD01 / 0x0033DD02`，`38` |
| 232 / 233 | AC → AP，5 GHz 的 `qiyitt` | `0x0033DD01 / 0x0033DD02`，`44` |
| 248 | AP → AC，上报，包含 `qiyitt` 字符串 | 消息 `9`，`25`，顶层 `0x25`，首子项 `0x80` |

`_uac_wserv_packet_send_callback @0x006dbd74` 在 `0x006dc220` 构造 `0x0033DD01`，在 `0x006dc4d4` 加入 `0x0400`，最后调用 `capwap_packet_assemble @0x00638f34`。该发送函数也有其他能力分支，包含 `0x09` 和 `0x94`。本次两个加密请求均可在明文里直接确认使用 `0x63`。

两条成功下发均长 84 字节。消息元素的长度字段是大端 `00 47`，即 71。两条 TLV 连同各自 4 字节头占 68 字节，加固定的 3 后等于 71。以下偏移从 CAPWAP 明文起点算起。

| 偏移 | 字节 | 解释 |
|---:|---|---|
| 0–7 | `00 10 43 00 00 00 00 00` | 请求传输头，8 字节。 |
| 8–15 | `00 33 dd 01 24 00 47 00` | RFC 5416 WLAN Configuration Request、序号、MEL、Flags。5 GHz 序号为 `2c`。 |
| 16–19 | `04 00 00 19` | `0x0400`，值长 25。 |
| 20–23 | `01 02 80 00` | Radio ID 1、WLAN ID 2、Capability `0x8000`。5 GHz 的 Radio ID 为 2。 |
| 24–27 | `00 00 00 00` | Key Index、Key Status、Key Length。此 Add WLAN 元素的 Key Length 为 0。 |
| 28–33 | `00 00 00 00 00 00` | Group TSC。 |
| 34–38 | `00 00 00 01 01` | QoS、802.11 Auth Type、MAC Mode、Tunnel Mode、Suppress SSID 字节。按 RFC 5416 §6.1，Suppress SSID 为 1 时广播名称，空中扫描也确认可见。这里的 Auth Type 与 Web 的 WPA2 枚举属于不同字段。 |
| 39–44 | `71 69 79 69 74 74` | UTF-8 SSID `qiyitt`。 |
| 45–48 | `00 25 00 23` | 厂商信封，值长 35。 |
| 49–52 | `12 34 56 78` | Vendor ID。 |
| 53–58 | `00 63 00 63 00 19` | 信封字段 `0x63`、子项类型 `0x63`、子项长度 25。 |
| 59–67 | `01 02 00 00 00 64 03 00 01` | 私有参数头。前两字节为 Radio ID 和 WLAN ID。5 GHz 的首字节为 `02`。末字节 `01` 选择 PSK 尾部。中间值在两条保护报文和开放对照中保持相同，细分语义待单变量验证。 |
| 68–69 | `02 02` | WPA2 与 AES 枚举。 |
| 70–73 | `00 01 51 80` | 大端 32 位密钥更新间隔，`86400`。 |
| 74–75 | `00 08` | 大端 16 位密钥长度。 |
| 76–83 | `[PSK，8 字节]` | 本次实测的口令字节，文档遮盖。 |

`cw_80211_add_wlan_assemble @0x0065a5d4` 对应 `0x0400`。`cw_msg_ele_priv_mngr_get @0x0064f85c` 用 `0x63` 查到 `cw_priv_wsrv_para_new_assemble @0x00695f68`。写完 9 字节头以后，`0x00696098` 用末字节分派。选择值 `1` 进入 `0x006960c0`，依次写 `u8`、`u8`、`BE32`、`BE16` 和原始字节。因此 PSK 尾部的定长前缀为 8 字节。开放对照第 160 和 212 帧的 `0x63` 子项长度为 9，头末字节为 `00`，无尾部。

第 205 和 233 帧的回包以相同序号应答，`0x21` Result Code 值为 `00 00 00 00`，对应 `cw_result_code_parse @0x00643de0`，并携带厂商 `0x1f` 子项。本次在 Windows 主动无线扫描中确认两条 BSSID 均广播 WPA2 个人版和 CCMP。客户端认证尚未实测。

## Go 版对照

| 先前路径 | 与成功报文的差异 |
|---|---|
| `wlan.add` → `SendAddWlanIE` | 使用消息 `7`、`0x0400` 和 `0x0405`。厂商成功报文使用 `0x0033DD01`、`0x0400` 和带 `0x63` 的 `0x25`。[发送代码](../../uacgo/cweng/wlanpush.go) |
| 把 PSK 写进 `AddWlan.Key` | 实发 `0x0400` 的 Key Length 为 0。PSK 放在 `0x63` 的变长尾部。 |
| 重放旧 `0x09` 的 9 字节开放样本 | 缺少这次 `0x63` 的 PSK 分支，与两条请求帧对照可以直接区分。 |
| `wservice.add` 只持久化 ID、启用、VLAN、SSID | 安全参数需要从 API 持久化到射频下发。 [配置代码](../../uacgo/jcs/wservice.go) |
| 现有扩展 A 编解码器 | [编码器](../../uacgo/capwap/elem_wsrvpara_ext.go) 写出 8 字节前缀，解析器入口却要求至少 10 字节。当前加密样本总尾长 16，通过这一长度门。 |

复核时以同一会话的开放和加密 WLAN 为对照，检查加密两帧的 SSID、Radio ID、`0x0400` 密钥长度、`0x63` 头和尾部、ACK 序号及结果码。再以 AP 的状态和空中扫描验证配置实际生效。完整解密数据、私钥和口令留在本机测试目录。
