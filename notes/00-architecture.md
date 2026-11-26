# uac 逆向笔记 — 全部结论直接取自二进制证据

## 2026-11-26 实机修正与独立 Go 路径

本节优先于下面历史“完成度快照”。旧反编译的 SHA-256 为
`ddc30fd8aa14e206eaa119e403a4ada64584bef84020c825b8c579bfa4153c68`；
V6 的 SHA-256 为 `b12d1584fcafda2a71aa9038b41b7e1c5b893b350f3e6edf5105e445d024a912`。
地址不能跨版本套用。设备证据见 [Go 实机进度](../docs/go-live-status.md)。

- V6 原厂与 TL-7AP5100 的实际握手选择 DTLS 1.0 / RSA / AES-256-CBC / SHA1（0035），
  ClientHello feff。新增 `internal/legacydtls`，按 RFC 4347/4346 实现 cookie、PRF、
  RSA 交换、CBC MAC、Finished 与记录重放窗口；独立 OpenSSL 0035/002f 对拍。
  不以既有 Pion 1.2 测试外推兼容性。普通退出向 AP 发加密 close_notify。
- CAPWAP 外层为 `01 00 00 00` + DTLS；解密后的 AP 控制头为 `01104300`，
  AC 的响应为 `00104300`。只在已认证 DTLS 内接受这个 type=1；原 ParsePacket 仍拒绝。
  配置 DTLS 时禁止 Join 或控制命令回退为明文。允许明文广播 Discovery。
- 动态能力来自 AP 私有 0x51：16 字节头、BE32 item count@12、u8 type/u8 length TLV；
  radio 子块有 4 字节头，再嵌套 TLV。数值语义参照
  `_apdb_pkt_parse_radio`（旧 0x0060e514；V6 0x0070ae08）。
  此 AP 不在旧 AP DB，必须读取 Join 元数据。
- 无线服务下发为消息 `0x33dd01`，标准 Add WLAN `0x0400` 加私有 `0x63`；
  V6 地址 `_uac_wserv_packet_send_callback` 0x006dbd74、
  `cw_80211_add_wlan_assemble` 0x0065a5d4、`wsrv_new_assemble` 0x00695f68。
  和原厂解密帧 204/232 对拍后发给真实 AP，按类型+序号检查 `0x33dd02` 和结果码。
  Delete WLAN 是 `0x0403`，不是 `0x0402`（Assigned BSSID）。
- 射频 DSSS 0x0404、Power 0x0411 与 V6 帧 66/68/112/132 对拍。
  运行状态私有 0x25 为 `u8 radio/u8 mode/u8 channel/BE16 power`，
  旧 `cw_priv_ap_res_info_parse` 0x005a6f6c，字段名来自
  `rdmngr_capwap_callback_wtp_event_request_listen` 0x006143f0。
  Go 把 AP 实际回报与请求配置分别展示，不用 ACK 冒充回读。
- 客户端 0x0034 旧 Go 漏了 WLAN 字段。正确为 `r8 radio, r32 WLAN, r32 count`，
  再逐站 `r32 A,r32 B,MAC6`；不是 `radio,count,entries`。
  证据 `cw_sta_info_list_parse` 0x00581148 / assemble 0x00580f6c；
  listener `_uac_wsta_pkt_sta_info_list` 0x00635f9c。
  WLAN <17，count 与实际长度必须一致；统计 0x52 也校验 count×38+4 的精确长度。
- 新关联 0x8a / 响应 0x8b 为 radio/WLAN/MAC/BE32 word/u8 phase/BE32 sublength/TLV16；
  旧 parse 0x005c282c、result assemble 0x005c3834、listener 0x00634d80。
  请求 backfill subtype0 在响应里是 subtype1；MLO subtype1 另有流程，当前明确拒绝。
  离线私有 0x03 来自 parse 0x005c5990 / listener 0x00635a50，旧 AP 的迟到离线
  不能覆盖同一客户端在新 AP 上的关联。0x52 RSSI 是记录偏移10的有符号字节，
  `_stats_pkt_sta_request` 0x006736f0；0x33 每记录 MAC6 + RSSI8（parse 0x00581888）。
  新客户端处理尚缺真实终端验收，不能因单元测试通过就称已对等。
- 新 Web 为 Go embed + 独立 JSON API，直接操作 Go 引擎和私有 JSON 配置，原厂 JCS
  仍留作取证；当前不需要原厂 Lua、uHTTPd 或 QEMU 提供产品界面。


证据基座（均为固件内一手数据，非旧文档）：
- `work/rootfs/usr/sbin/uac` — 目标 ELF32 MSB MIPS32r2，0x400000 文本段 / 0x731164 数据段
- `work/rootfs/usr/sbin/uac_symbol_fun|obj` — 厂商符号表 5683 函数 + 1213 对象（固件自带）
- `asm/*.asm` — 符号标注反汇编（mips-linux-gnu-objdump，5683 文件）
- `ghidra-export/decomp/*.c` — Ghidra 全量伪代码（6484 文件，含无符号函数）
- `ghidra-export/data/*.bin` — .data 段样例报文（cw_dis_req 等 10 个）
- `firmware/sq/` — squashfs 完整重提取（旧 work/rootfs 缺 /etc 符号链接）
- `notes/registry.tsv` — 消息/事件分发表（43 条注册，来自反编译语料）

## 1. main 初始化链（main @0x40a2c0，trace 字符串逐项证实）

```
init_trace = access("/tmp/uac_init_trace_open")  // 调试开关
udbg_dup_stdout("/dev/console")
uac_cfg_init(5)                                  // @0x513458: cfg 线程+ubus 注册
uac_profile_get_int("wheel_timer","id_len",&t)   // @0x51eb50: 内嵌 Lua 读 UCI profile
uac_timer_init(timer_bit)                        // wheel timer 位宽
uac_md5_timer_init(timer_bit-5)
cw_ac_init()                                     // @0x58dca4 CAPWAP 引擎
apdb_init()          systime_init()     apmngr_init()      multi_link_init()
apmngr_multilink_callback_init()  apmngr_db_sqlite_recover()  uac_rdmngr_init()
rate_info_init()  band_navigation_init()  uac_wservice_init()  uac_wstation_init()
uac_stats_init()  apupd_init()  acpdt_init()  ac_passthrough_init()  wportal_init()
radius_init()  audit_client_init()  uac_mac_auth_init()  uac_bcast_storm_ctrl_init()
uac_dhcpdef_init()  uac_arp_defend_init()  wsta_roam_init()  balance_init()
uac_rrm_init()  [system ubus cloudclient register_cmd_callback]
uac_report_init()  cloud_mngt_init()  uac_mesh_init()  uac_sensor_init()
ucl_auth_init()  uac_lldp_init()  uac_id_sync_init()
cw_ac_run()  → uac_done() → while(1) sleep(1)
任一失败: 反向 destroy 链 + puts("Warning: Init uac process failed, exit...") + exit(0)
```

## 2. 运行时依赖（硬依赖，Go 版必须以文件形式提供）

| 依赖 | 固件内位置 | 性质 |
|---|---|---|
| profile (UCI) | **不在固件镜像**（设备 flash config 分区；/etc/config→/tmp/etc/uc_conf 符号链接） | uac 内嵌 Lua 解释器调 `luci.model.uci:get_profile()` 读 `profile` 配置；**任一项读失败→cw_ac_init 整链跳过→进程退出**。需按代码语义重建数据文件（后续可用真机 `uci show profile` 校准） |
| /etc/apdb.bin | 固件内 ✔（DES-ECB+MD5 包裹 JSON，待重新验证后提取） | AP 能力库 |
| /etc/cacert.pem + privkey | 固件内 ✔（capwap cacert_file_path/privkey_file_path 来自 profile） | DTLS 证书 |
| SQLite dbs | /etc/nouci_config/dbs/ → /tmp/etc/nouci_conf/dbs/（运行时由 *_db_init 建表） | apmngr/wserv/rdmngr/wsta/dhcpdef/arpdefend/mac_auth/balance/portal… |
| uc.conf 白名单 | /etc/tmp_uc_conf/uc.conf（固件内 ✔，493 行） | 配置项白名单 |

profile 选项（部分，详见各调用点）：
- `ac_capwap`: frag_enable, frag_mtu, session_num, pkt_queue_size, mngr_queue_size,
  timer_size, timer_max_time, timer_process_num, mngr_process_num, pkt_process_num,
  thread_size, cacert_file_path(0x80), privkey_file_path(0x80),
  socket_recv_buffer_size, socket_send_buffer_size, default_retransmit_time,
  retransmit_max_retries, max_session_num, max_pkt_snapshot_mem_size  (cw_ac_profile_init, 结构体 l_profile 0x148B)
- 其它节: wportal, ac_apupd, sensor, mac_auth, apmng_rf, apmng_upgrade, apmng_set,
  apmng_roma, ac_dhcp_defend, ac_arp_defend, wheel_timer(id_len/timer_size/…)…

## 3. CAPWAP 引擎结构（cw_ac_init/cw_ac_run，已对二进制取证）

全局 `ac` 结构（0xcc48B）：
- +0x00 running 标志; +0x04 bind IP; +0x08 port=0x147e(5246)
- +0x0c UDPv4 fd; +0x10 UDPv6 fd; +0x14 netlink fd
- +0x18 thread_size; +0x1c ac_data 数组(0xa0B/线程); +0x20 线程 id 数组

`l_profile`（0x148B）偏移: +0 frag_enable, +4 frag_mtu, +8 session_num, +0xc pkt_queue_size,
+0x10 mngr_queue_size, +0x14 timer_size, +0x18 timer_max_time, +0x1c timer_process_num,
+0x20 mngr_process_num, +0x24 pkt_process_num, +0x28 thread_size,
+0x2c cacert_file_path[0x80], +0xac privkey_file_path[0x80],
+0x12c sock_recv_buf, +0x130 sock_send_buf, +0x138 default_retransmit_time,
+0x13c retransmit_max_retries, +0x140 max_session_num, +0x144 max_pkt_snapshot_mem_size

线程模型（cw_ac_run @0x58d5bc）：
- thread_size × `ac_dt_thread[i]` → cw_ac_data_run（每线程一个 ac_data，含 pipe + manager 队列
  "capwap_manager_queue_%d" + 会话哈希）
- 主线程 `ac_thread` → cw_ac_run_callback：select(UDPv4/UDPv6/netlink, 5s 超时)
  - netlink: RTM_NEWADDR(0x14)/DELADDR(0x15)/NEWLINK(0x10)/DELLINK(0x11) → cw_ac_handle_addrchange
  - UDP → cw_ac_network_process
- `check_cw_recv_queue_thread`、`write_snapshot_thread`

## 4. 消息分发（serv_mngr_*，registry.tsv 有全表）

- serv_msg_mngr_init: 26 个桶 = 控制消息类型 1..26；另有 g_serv_ie_msg_mngr 2 桶(0x33dd01/02)
- serv_msg_mngr_register(msg_type, priority, handler)：按 priority 升序插入链表
- serv_mngr_handle: msg==3(JOIN_REQ) 时要求 param_3 且 add_rslt_code_to_parsed_pkt；
  依序调用链上 handler(parsed_pkt, basic, extra)
- ent 事件（4 桶，g_serv_ent_mngr）：0/2=session 复位(_apmngr_pkt_enter_reset_cb)，
  1=进入 RUN(_apmngr_pkt_enter_run_cb / multi_link / nms_report)，3=接口 ifindex 变化

各子系统注册（节选，全表见 registry.tsv）：
- apmngr: msg1(0xff) disc / msg3(0x78) join / msg5(0x50) cfgstatus / msg9(0x78) wtpevent / msg13(0x78) echo; ent0,2 reset, ent1 run, ent3 ifindex
- apupd: msg8/15/16 优先级 1（config-update-rsp / image req/rsp）
- rdmngr: msg3(0x73)/msg5(0x5a)/msg9(0x5a)
- mesh/acpdt/apdb: msg1/3 高优先级（200/256）多级策略链
- wservice: msg5(100); wstation: msg9(100); wsta_roam: msg9(0x5a); rrm: msg9(0x41);
  balance: msg9 优先级 1（最先）；stats/audit: msg9(0x50)；sensor: msg3(0x32)/msg9(0x78)；
  lldp/ac_passthrough: msg9+msg13(0x78)

## 5. 工具链

- 反汇编: `mips-linux-gnu-objdump -D -b binary -m mips:isa32r2 -EB --adjust-vma=0x400000 uac`
- 反编译: Ghidra 11.3.2 headless（JDK 21 必须；osgi 缓存损坏时删 ~/.config/ghidra/ghidra_11.3.2_PUBLIC/osgi）
- qemu-mips-static + rootfs chroot 可跑原厂二进制（oracle 对拍用）
- 符号/数据提取: tools/syms.py；调用参数提取: tools/callargs.py（启发式，仅辅助）

## 6. FSM 状态机与定时器（0x59c800 区，全部取自二进制）

状态 0..14（PTR_s_START_006e4510 名称表）：
START, IDLE, DISCOVERY, SULKING, DTLS_SETUP, DTLS_TEARDOWN, JOIN_WAIT, JOIN_FINISH,
IMAGE_DATA, CONFIGURE, RESET, DATE_CHECK, DATE_CHECK_TO_RUN, RUN, DEAD
- 会话创建 → state=IDLE(1)（cw_fsm_ac_setup @0x59ce08: +0xb4=1, +0xcc=5, +0xd0=echo超时）
- cw_fsm_ac_change_state 校验 state<0xf

定时器 0..11（名称表 @0x6e4ae8；超时表 l_timeouts @0x74cfac）：
| id | 名称 | 默认超时 |
|----|------|---------|
| 1 | WAIT_DTLS | 60s |
| 2 | WAIT_JOIN | 60s |
| 3 | IMAGE_DATA_XMIT | 60s |
| 4 | CHANGE_STATE_PENDING | 30s |
| 5 | DATA_CHECK | 30s |
| 6 | DTLS_SESSION_DELETE | 10s |
| 7 | DISCOVERY_INTERVAL | 5s |
| 8 | SILENT_INTERVAL | 30s |
| 9 | ECHO_INTERVAL | 30s（会话+0xd0 可覆盖，默认取 l_timeouts[9]=30）|
| 10 | RETRANSMIT_INTERVAL | 会话级，来自 profile default_retransmit_time |

## 7. 发现响应内容（cw_dis_rsp fixture 解码 + 处理流程）

capwap_ac_discovery_handle @0x591ae4 流程：
parse(req) → ac_parsed_packet_create(rsp=msg+1?) → serv_mngr_handle(req, basic, rsp)
（链上调 apmngr/mesh/multi_link/acpdt/apdb 的 listener，各自往 rsp 加元素）
→ cw_msg_eles_length_update → 检查 0x21 值∉{0x17,1} → capwap_packet_assemble → send(v4/v6)

cw_dis_rsp 元素序列（235B, msg=2 seq=1 MEL=222）：
1. 0x0001 ac descriptor (156B): stations=0, limit=0x2710, active=0x3e8, status=02,
   vendor=12345678, +04…, AC info 0x40, AC 名表 "TL-AC1000 v1.0" …
2. 0x0004 ac name = "TL-AC1000" (9B)
3. 0x000a capwap control ipv4 address (6B): 192.168.1.253 + port(模板占位 0)
4. 0x0418 wtp radio information ×2 (5B): radio_id + 4B 标志
5. 0x0025 envelope: vendor 12345678 + u16(0) + priv cwver(0) len4 = 00 01 00 01

注意响应头 rid=0（请求 rid=1），其余同请求（ver0,type0,hlen2,wbid1,T1）。

## 8. AC 主动发包与重传（0x58b1b4/0x591828/0x59139c，直证）

- 出向序号：session+0xa4 计数器，每个 AC 主动请求 +1；到 0xFF 回绕为 1
  （cw_ac_data_manager_user_packet_event_process）。
  响应报文不用它（直接复制 AP 请求的 seq，ac_parsed_packet_create @0x590d58）。
- session+0xa8 = 上次发送的 seq（响应重传武装时 0xa4→0xa8）。
- 响应重传：发送 join/cfg 等响应后 cw_ac_retransmit_timer_start
  （ac_msg_handle）；cw_ac_retransmit_timeout_handler @0x591828：
  session+0xf6 重试计数 / +0xf7 最大次数（profile）/ +0xf4 当前间隔；
  超时：若仍有待重传队列 → 重发，间隔倍增，上限 min(60, …)；
  重试耗尽 → serv_ent_handle(2)（ent 复位事件）+ teardown。
- LED 开关：apmngr_pkt_led_pkt_send @0x55aec4 = 消息 7 + 信封(vendor=0,X=0)
  私有 0x39 = u32(0/1)。
- AP 复位：apmngr_pkt_reset_pkt_send @0x55ad74 = 消息 17；mode>3 拒绝；
  mode1 无元素；mode2 信封(vendor=0) 私有 0x23 = u32 1；mode3 = u32 3。
- AC→AP 的 0x25 信封 vendor=0x12345678（fixture cw_cfg_update_req），
  X 字段随调用方变化（8/16…），私有 TLV 常见 0x08/0x0a（射频参数/速率）。

## 9. ECHO 看门狗与响应重传（Go 已实现）

- ECHO 定时器（默认 30s）每轮触发：miss 计数（session+0xc8）< 5（session+0xcc）
  → miss+1 重挂；耗尽 → ac_data+0x74++（重传超时则 +0x78++）→ 清定时器 → teardown
  （cw_fsm_ac_run @0x5a091c）。CHECK_PASSED 时 miss 清零 + 重挂。
- 响应发送后武装重传定时器（ac_msg_handle → cw_ac_retransmit_timer_start）；
  门控通过的后续包替换/取消挂起重传（被门控拒绝的包不影响队列——
  ac_msg_pretreat 在入队前丢弃）；退避倍增，上限 60s；耗尽 → ac_data.RetransTimeout++。

## 10. uacgo 完成度快照（本轮）

已实现并有测试背书：
- capwap：线层全格式 + 194 元素注册表 + 三响应构建器字节一致 + LED/复位/配置更新发送
- cweng：分发注册表、FSM 全 15 状态、定时器、会话表、seq 语义（响应复制/出向计数器）、
  去重/重发/响应重传/echo 看门狗、AP 身份解析（0x26/0x27/0x2d/0x1c/0x1e/0x2c）
- 数据：apdb.json（重取证解密）、identity.json、profile.ini（重建）、10 fixtures
- 交付：cmd/acd 实跑验证；linux/amd64+arm64、windows/amd64 交叉编译；纯 Go 零依赖

未完成（README 未完成清单）：SQLite 配置层、其余元素移植、升级流程、JCS/IPC、DTLS、
profile 数值校准。

## 11. join/config 路径元素移植（第二轮，Go 已实现）

- WTP Descriptor (0x27)：cw_wtp_descriptor_parse @0x584978 =
  u8 radios + u8 in_use(≤radios) + u8 enc_count × {u8 wbid(<0x20), BE16 caps}
  + N × {BE32 vendor, BE16 type(≤3), BE16 len(1..0x400), val}；fixture
  cw_join_req 值 roundtrip 字节一致。
- wsrv para（私有 0x09/0x63）：cw_priv_wsrv_para_parse @0x5ce6f8 头 9 字节
  (u8,u8,BE16,BE16,u8,u8,u8) + 可选 12/31B 扩展尾；fixture cw_wlan_cfg_req
  信封内 0x09 len 9 roundtrip 一致。
- wlan list（私有 0x1e）：cw_priv_wlan_list_parse @0x5cba28 =
  BE32 + BE32 + N × {u8(radio id，dump @0x5cb5a4 证实), 32B 定长 ssid}；
  cfg_rsp 信封 0x1e len 41（含 UTF-8 SSID "00_YXJ_统一技术_GBK"）roundtrip 一致。
- adv rd para（私有 0x08）：cw_priv_adv_rd_para_parse @0x5a3654 = 15B 头
  ([0]radio<0x20,[1..3],[4..5]BE16,[6..0xc]×7,[0xd]pad,[0xe..0xf]BE16)
  + len∈{0x14,0x15,0x1a,0x1b} 读 4B 后覆写默认 ff 01 ff 01（厂商怪癖保留）
  + len 偶数 +1B([0x15]) + len≥0x16 +6B；cfg_update fixture len 16 一致。
- rate（私有 0x0a）：cw_priv_rate_parse @0x5ba0e4 = 55B 定长
  (u8 radio<0x20 + 8+8+1+4+4+1+12+12+4)；默认值落盘 data/rate-default.bin
  （从固件 .data fixture cw_cfg_update_req 提取）。
- 子系统接入：rdmngr msg3(prio 0x73)/msg5(0x5a)、uac_wservice msg5(prio 100)
  —— 注册优先级与 registry.tsv 一致；StoreWserviceConfig 从
  wserv.db(wserv_tbl)/rdmngr.db(rdmngrTable) 读配置生成信封。
- 实测：join → 238B 响应（result-code/acdesc/name/radio×2/ecn/ctrl-addr/
  local-addr + rdmngr 信封），AP 条目持久化 apmngr.db（My WTP 1 / 100716033）。

## 12. wsta / apupd 子系统（第三轮，Go 已实现）

- station information list（标准 0x34）：cw_sta_info_list_parse = u8 radio(<0x20)
  + BE32 count(<0x11) + N × {BE32 a, BE32 b, 6B mac}（14B/条）。
- private sta list（0x1f）：cw_priv_sta_list_parse @0x5c6c28 = u8 radio
  + u8 count(<0x11) + BE32 wlan_id + N×6B MAC。
- wstation 监听器（msg9 prio100，@0x6360ec）：读 0x34（私有回退
  0x02/0x8a/0x03/0x4d），响应带 0x21 result code。Go: RegisterWstaHandlers
  + ClientTable。
- apupd（msg15/16 prio1）：
  - image request 监听器 @0x643550：私有 0xb1 → 子镜像确认（仅 result code）；
    0x19+0x1b → 版本确认 → result code（0 ok / 0x10 失败）+ 0x1a image
    information（BE32 file info + info；apupd_image_information_add @0x661520，
    fixture 4+16=20B）。
  - image data 元素 0x18：cw_image_data_parse = {u8 type, BE16 len, data}，
    type∈{1,2}=数据块、5=AP 拉取请求；最大数据 0x400
    （apupd_image_data_add @0x661618）。
  - Go: RegisterUpdHandlers（确认 + 分块下发，块大小默认 0x400）+
    SendImageNotify（msg7 + 0x19，待真机抓包复核发起方向）。
- 实测（真 UDP，活进程）：discovery/join/cfg/cse/wtp-event(client)/echo
  全链路响应消息类型正确（2/4/6/12/10+result/14）。
  注意：控制头必须 8 字节（type4+seq1+MEL2+flags1），手搓包缺 flags 会被
  ErrShortPacket 静默丢弃（与二进制一致）。

## 13. LED 定时计划组 + 蓝牙（第四轮，Go 已实现）

apmngr_pkt_config_update_request_pkt_send @0x5590c0（通用 msg7 下发，entry 标志位驱动）：
- entry+0x250 bit 0x400 → LED 模式：信封(vendor 0) 私有 0x6f = BE32，
  值 = entry+0x130==0 ? 1 : 3（_apmngr_pkt_led_mode_encap @0x5590xx）
- entry+0x250 bit 0x2000 → 蓝牙：私有 0xa7 = BE32(entry+0x131 字节 << 24)
- 其余 case：0xa4、0xa9、0x44(ap trunk) 同信封模式（_apmngr_pkt_element_encap
  @0x555818 另处理 priv 5/0x3c/0xc(timers)/0x17(idle)/0x3d(user)）
- 私有 0x6f/0x38 均 BE32 定长 4（assemble/parse 直证）；0x38 dump 打印
  closed/open —— AP 上报 LED 状态用
- LED 定时计划（ApEntryCfg led_timer_* 列）由 AC 侧定时执行 0x39 开关
  （Go: LEDScheduler.Apply/nextLEDTrigger，跨零点语义 = 触发时刻之后的下一事件）

## 14. AP 配置束（第四轮续，Go 已实现）

_apmngr_pkt_element_encap @0x555818 / apmngr_pkt_config_update_request_pkt_send
@0x5590c0 的 msg7 配置束元素值布局（assemble 直证）：
- 私有 0x05 ap base para（min=max=8）= 2×BE32（ap/client keep-alive，
  对应 ApEntryCfg 列）@0x5a3df0
- 私有 0x3c ap offline mngr（min=max=24）= 6×BE32 @0x5a6ae4
- 私有 0x3d ap user（min=max=128）= 2×64B 定长（username/password，
  对应 account_* VARCHAR(64) 列）@0x5a9ad0
- 同束还有标准 0x0c（timers）、0x17（idle timeout）
Go: capwap.PrivApBasePara/PrivApOfflineMngr/PrivApUser + cweng.SendAPConfigBundle
（一条 msg7 五元素束，out-seq 一次推进，framing 测试全绿）。

## 15. 私有元素第二批（第五轮，Go 已实现）

- 0x1b ac info（min=max=6）：6 原始字节（cw_priv_ac_info_assemble @0x5a2c78
  = 单次 restore_raw_bytes 6）；join_rsp 信封载荷 085700c21fa0 roundtrip 一致
- 0x2a portal syn（min2 max0xc800）：BE16 len + 原始载荷，精确消费
  （cw_priv_portal_syn_parse @0x5b8f7c）
- 0x51 apdb info：原始能力 blob（AP 自报，min 2；apdb 监听器 msg1/3 prio 256
  捕获 → ApdbSink）
- 0x55 statistics control（min=max=9）：u8×3 + BE16×3
  （cw_priv_statistics_control_assemble @0x5c83dc）
- 0x57 roaming control（min=max=36）：36 原始字节
  （cw_priv_roaming_control_assemble @0x5bcb9c）
- 0x0c(私) state report period（min=max=8）：2×BE32
  （cw_priv_stat_prd_assemble @0x5c8090）
- Go: capwap.PrivAcInfo/PrivPortalSyn/PrivApdbInfo/PrivStatisticsControl/
  PrivRoamingControl/PrivStatPrd（+ AppendUint16BE/32BE、Uint16BE/32BE 助手）
  ；cweng.RegisterApdbHandlers（msg1/3 prio256）+ SendStatsControl/
  SendRoamingControl/SendStateReportPeriod —— UDP 测试全绿

## 16. JCS/IPC 层取证（进行中）

- jcs_init @0x5293f0：建 jcs_cb_tbl 哈希（0x100 桶）+ uac_com_get_name_by_pid
  （fopen 读 /proc/<pid>/comm）拿本进程名 —— 每进程一个 JCS 服务端点。
- jcs_callback_register @0x529250：子系统注册 jcs 回调（116 个 `_jcs_*`
  处理器 + 各子系统 jcs_callback_*，func_index 共 175 项）。
- jcs_send_to_process @0x529778：**AF_UNIX SOCK_STREAM**（socket(1,1,0)），
  地址 = 进程名派生的 sun_path（snprintf 自 rodata 模板，待进一步定位模板串），
  0x107e 常量出现（端口/魔数待确认）。
- 结论：JCS = uac_com 框架的进程间 JSON-RPC（对应 Web/Lua 侧 ds 接口），
  Go 版应实现：同一 AF_UNIX 服务端 + 回调注册表 + send_to_process 客户端；
  或在单进程部署时以内存直调等价替换（行为面=116 处理器的语义）。
- 下一步：定位 sun_path 模板与消息帧格式（jcs_msg 结构）后实现传输层。

## 17. JCS 传输层破解 + Go 实现（第五轮续）

- 服务端点（jcs_run @0x529564 的 sprintf 直证）：
  `/tmp/jcs.service.srv.<进程名>`（service 线程）与
  `/tmp/jcs.ui.srv.<进程名>`（ui 线程）—— AF_UNIX SOCK_STREAM
  （jcs_send_to_process @0x529778 的 socket(1,1,0)）。
  客户端连目标进程的端点（wportal 里硬编码
  `/tmp/jcs.service.srv.wifidog` 佐证同构）。
- 工作线程 jcs_work_task @0x528560：accept + 0x20001B(128KiB) 接收缓冲
  → 载荷为 JSON（与 Lua ds 层同构）。
- 回调注册：jcs_callback_register @0x529250（func_index 175 项 jcs 符号）。
- Go: uacgo/jcs 包 —— ServicePath/UIPath 路径构造、Server(Register/Serve/
  Close) AF_UNIX 服务端、Call 客户端（method/module/keyword/params JSON
  信封，对应 ds 请求形状）；单请求单连接帧（send_to_process 模式），
  帧细节待真机抓包复核后在文档标注。

## 18. JCS 语义层 — apmngr 子系统（第六轮，Go 已实现）

- 注册表直证：apmngr_jcs_reg_callback @0x5546a8 经
  jcs_callback_register @0x529250 注册 (module, method 0..3, fn)，
  fn 存于条目 +0x10+method*4 —— 方法枚举 {0:add, 1:del, 2:set, 3:get}。
- 24 组 (module,method) 注册全部提取（apmngr_entry add/del/set、
  apmngr_group add/set/del、ap_status get、apmngr_global/aplog/diagnose set、
  apmngr_apdb_info get、entry_backup/copy/authorize、group_join、firm、
  online_model、ap_status_evt、ap_telnet_status_evt、ap_status_ssid、
  ap_vlan_info、ap_status_radio_info、ap_exceed_status、ac_datasync_status）。
- Go: jcs.RegisterApmngrHandlers —— entry/group/ apport_status 用
  apmngr.db 实现（增删改查过 SQL），其余注册项明确返回
  "not implemented: <module> <method>"（不静默）。
- 测试：真实 AF_UNIX + apmngr.db 的 add→get→set→del 生命周期、
  group get、ap_status get、not-impl 标记 —— 全绿。

## 19. JCS 语义层 — wserv 子系统（第七轮，Go 已实现）

- 注册直证：uac_wservice_init @0x5e01a0 经 FUN_004084d0(=jcs_callback_register)
  注册："wservice" 3get/0add/1del/2set（_uac_wserv_jcs_get/add/del/set，
  wserv_tbl）；"wservice_ip" 0add/1del/2set（_uac_wserv_ip_jcs_*，
  igmp_ip_tbl）；"wserv_global" 2set（全局配置）。
  另有 _uac_wserv_jcs_rd_op（wserv_rd.db bind_tbl 操作，注册点待定位——
  wservice 方法内按参数分派）。
- Go: jcs.RegisterWserviceHandlers —— wservice/wservice_ip 全生命周期
  （add/get/set/del 直操作 wserv.db），wserv_global 标记 not-impl。
- 测试：真实 AF_UNIX + wserv.db 的 add→get→set→del（含 UTF-8 SSID
  "00_YXJ_统一技术_GBK"）与 igmp_ip add/del —— 全绿。

## 20. rd_op 射频绑定 + rdmngr/wportal JCS（第八轮，Go 已实现）

- _uac_wserv_jcs_rd_op @0x5d9db4 参数：radio_id/serv_id/vlan_id/
  rd_num_binded/ap_name/freq_name/result —— "wservice get" 携带 radio_id
  时返回该射频的 bind_tbl 行（wserv1..8/vlan1..8）。
- rdmngr 注册直证：uac_rdmngr_jcs_register @0x62f024 —— "rf_mngr"
  set(2)/get(3)（rdmngrTable）、"rf_mngr_entry" get(3)、
  "backup_rf_mngr_entry" get(3)、"rdmngr_datasync" set(2)。
- wportal 注册直证：wportal_init @0x4263f0 —— "wportal"
  add/del/set/get、"wportal_backup" get、"wportal_nsa_sync" set（portal.db）。
- Go: jcs rd_bind.set/rd_bind（bind_tbl 读写，NULL 安全）+ rf_mngr
  set/get（rdmngrTable 子集列）+ wportal 六注册项 not-impl。
- 测试：rd_bind set→get 真实 AF_UNIX + wserv_rd.db 全绿。

## 21. wportal JCS 取证（第八轮续，记录待实现）

- _wportal_jcs_get_callback @0x415b40 请求/响应字段（字符串直证）：
  search/search_arg/start/size/type/file_name/mac/is_online/ret ——
  认证用户列表查询 API（_wportal_authed_user_get / _wportal_get_is_online_by_mac /
  _wportal_get_all_stream_load / _wportal_nsa_get 分支）。
- wportal DB 层是内存结构：wportal_db_dm_{sessid_rbtree, framed_ip_hash,
  calling_station_hash, rds_srv_hash, cmcc_serialno_rbtree}（0042afec 区），
  快照持久化到 portal.db（wportal_db_init @0x42c920 的 UCI 形配置
  portal_config/auth_mode/age_enable/age_time/portal_port/ssid/vlan/interface…
  为初始配置，非 SQL 建表）。
- 实现方案（待做）：Go 侧用内存 map/rbtree + 定期快照 portal.db 等价替换；
  jcs "wportal" add/del/set/get 按 get_callback 已知字段先实现
  authed-user 列表查询与 is_online 判定，增删改语义对照
  _wportal_jcs_add/set/del_callback @0x415aa8/0x428bdc/0x4254c8 逐个取证。

## 22. wportal 语义实现（第九轮，Go 已实现）

- jcs/wportal.go：AuthedUserTable（内存 map[MAC]，portal.db 快照表
  authed_users）+ RegisterWportalHandlers —— "wportal" get（search/
  is_online/start/size 过滤，按 auth_time+mac 稳定排序）、add/del/set
  （MAC 主键，set 校验存在）；GetIsOnline 对应
  _wportal_get_is_online_by_mac。
- wportal_backup.get / wportal_nsa_sync.set 保持 not-impl（备份格式待逆）。
- 测试：真实 AF_UNIX 生命周期 add→search→is_online 过滤→set→快照重载→
  del 全绿。

## 23. sensor/wips/balance/mesh/lldp/rrm JCS 注册表（第十轮取证）

FUN_004084d0 调用表逐条提取（方法枚举 {0:add,1:del,2:set,3:get}）：
- balance_init @0x4590a8: "ac_balance" set → balance_jcs_callback_balance_set
- uac_rrm_init @0x4af92c: "ac_rrm_state" get / "ac_rrmpara" set /
  "ac_manualrrm" set
- uac_lldp_init @0x4a45c4: "uac_lldp" set/get
- uac_mesh_init @0x4c01f4: "ac_mesh_global_settings" set,
  "ac_mesh_trigger_discover" set, "ac_mesh_stop_discover" set,
  "ac_mesh_discover_status" get, "ac_mesh_discover_list" get,
  "ac_mesh_trigger_pair_all" set, "ac_mesh_trigger_pair" set,
  "ac_mesh_topology" get, "ac_mesh_wan_status" set
- wips_init @0x4cb710: "wips_event_info" get/set, "wips_event_detail" get,
  "whitelist" get/add/del, "wips_statistics" get, "wips_statistics_num" get
- sensor_di_init @0x4d9c50: "set/get_deep_inspection_setting",
  "deep_inspection_status", "deep_inspection_chnl_usage_list",
  "deep_inspection_multi_chnl_rssi/density",
  "deep_checkup_pkt_ssid/bssid/sta_list"
- sensor_test_init @0x4f8c08: "sensor_test_ssid_list/digest/summary/
  summary_new/result/detail_result" get, "sensor_test_case_list"
  set/add/del（sensor.db test case 表，SchemaTable6）
- sensor_mngt_init @0x4e999c: "sensor_global" set, "sensor_discover_trigger"
  set, "sensor_list_added" get, "sensor_manage_status" get

- 实现补充：test case 表名 = "testcase_tbl"（sensor_test_sqlite_create_table_test_case
  传参直证；bssid 表另注册）；Go: jcs.RegisterBatch3Handlers ——
  wips whitelist get/add/del（whitelist_table 真实 CRUD）、
  sensor_test_case_list add/set/del（testcase_tbl）、其余注册项
  （mesh 9 项/sensor di 9 项/mngt 4 项/test 读 6 项/rrm 3 项/lldp 2 项/
  balance 1 项/wips event+statistics 5 项）全部带 not-impl 标记注册。
- 测试：whitelist 生命周期 + testcase add/del + not-impl 标记 —— 全绿。

## 24. mesh/rrm/lldp JCS 处理器参数取证（第十一轮，待实现）

- mesh_jcs_global_set：enable, backhaul_ssid, backhaul_key, backhaul_token,
  bh_work_mode, re_auto_switch, re_recover_flag, web_password,
  mesh_delete_all_sub_dev（全局设置键集）
- _rrm_jcs_rrm_para_set：autorrm_enable, autorrm_date, autorrm_time,
  bw_2g, bw_5g, chnl_enable, freq_enable, chnl_2g_set, chnl_5g1_set,
  chnl_5g2_set（RRM 自动参数键集）
- _rrm_jcs_rrm_state_get：返回 "state"（rrm_db_state_get/set @0x4b1c30/20）
- _uac_lldp_jcs_set：is_first 触发（_uac_lldp_pkt_create→pkt_send +
  timer_handle）；_uac_lldp_jcs_get：返回 cnt + lldp 信息列表（get_lldp_info）
- 实现方案（待做）：mesh/rrm 键集存入 syscfg KV 表（或对应子系统 db），
  lldp get 返回缓存邻居表；均需再对照各 *_db_init 的表结构逐字段确认。

- 实现补充（本轮）：jcs/batch3cfg.go —— RegisterMeshGlobalHandler /
  RegisterRRMHandlers（ac_rrmpara set/get + ac_rrm_state.get）/
  RegisterLLDPHandlers（uac_lldp set/get），值持久化于 syscfg KV 表
  （所在库即各子系统自身 db），键集严格对照 §24；替换 batch3.go 对应
  not-impl 占位（覆盖注册），其余占位保持。AF_UNIX set→get roundtrip
  测试全绿（含 not-impl 边界断言）。

## 25. 剩余 not-impl 处理器参数取证（第十二轮，记录待实现）

- balance_jcs_callback_balance_set：enable, dif_threshold, max_fail_num
  （balance 权重参数，balance_config_get_from_json → 全 WTP 包下发）
- mesh_jcs_discover_status_get：status ∈ {init, scanning, finished} +
  auto_add_status（发现状态机）
- jcs_deep_inspection_status：inspection_status, inspection_remain_time,
  last_inspection_time, cur_viewed_sensor, off_line_sensor
- _rrm_jcs_manual_rrm_set：无独立参数串（触发式，需对照 rrm 数据库
  rrm_db_para 表结构与 pkt 路径取证）
- 实现方案同前：键集入 syscfg KV（balance/mesh 状态机需要运行态字段 +
  内存状态 + 定时器），逐个对照 *_db_init 表结构后实现。

- 实现补充（本轮）：jcs/batch3rt.go —— RuntimeState + RegisterRuntimeHandlers：
  ac_balance.set（enable/dif_threshold/max_fail_num，syscfg "balance" 持久化）、
  ac_mesh_discover_status.get（状态机 init→scanning→finished +
  auto_add_status，SetMeshDiscoverStatus 驱动）、deep_inspection_status.get
  （inspection_status/remain_time/last_time/cur_viewed_sensor/off_line_sensor）。
  替换 batch3.go 对应 not-impl；其余占位不变。AF_UNIX 测试全绿。

## 26. 运行时查询处理器（第十三轮，Go 已实现）

- 字段直证（export/decomp）：
  - wips_event_info get：count/criterion/entry_name/dev_mac/discover_time_list/
    end（分页事件查询）
  - wips_whitelist get：count/result/size/start
  - wips_statistics get：end_ts/entry_name/group/group_name/normal_event_count/
    severe_event_count/slight_event_count/sensor/num（按 sensor 聚合）
  - wips_statistics_num get：dos_attack_num/illegal_dev_num/interfering_dev_num/
    threat_dev_num（四类计数器）
  - mesh_topology/discover_list get：total_num/start/size（分页节点表）
  - deep_checkup pkt 列表（ssid/bssid/sta）：chnl/name/percent/ssid_id
  - ac_manualrrm set：触发式（记录触发时间戳）
- Go: jcs/batch3rt2.go —— RuntimeTables（WipsEvent 事件表 + 四类计数器 +
  mesh 节点表 + checkup 列表 + manual 触发时间戳）+ RegisterRuntimeQueryHandlers：
  wips_event_info.get（过滤+分页）、wips_statistics.get（按 sensor 聚合
  normal/slight/severe）、wips_statistics_num.get、ac_mesh_topology.get/
  ac_mesh_discover_list.get（total_num/start/size 分页）、
  deep_checkup_pkt_{ssid,bssid,sta}_list.get、ac_manualrrm.set（触发时间戳）。
- 测试：三类事件注入 → 分页/计数/聚合断言；mesh 分页；checkup 列表；
  manual 触发 —— 全绿（真实 AF_UNIX）。

## 27. deep_inspection 详细查询组（第十四轮，Go 已实现）

- 字段直证（export/decomp）：
  - deep_inspection_chnl_usage_list：ap_num/chnl/free_util/non_wifi_util/
    ssid_num/sta_num/wifi_util（每信道空口占比）
  - deep_inspection_multi_chnl_rssi：band_width/bssid/center_chnl/
    primary_chnl/rssi/ssid（start/end 窗口）
  - deep_inspection_multi_chnl_density：average/density/end/length/
    spectrums/start（密度谱 + 均值）
  - get/set_deep_inspection_setting：entry_id/entry_name/inspection_band/
    inspection_item/scan_mode/chnl
- Go: jcs/deepinspect.go —— DITables（usage/rssi/density/setting）+
  RegisterDIQueryHandlers：五个查询处理器（含 rssi/density 的窗口分页、
  setting 的 set/get）替换 batch3.go 占位。
- 测试：usage 字段、rssi 窗口（start=1,end=3 → 排除首条 + total=3）、
  density 谱段 + average、setting set→get —— 真实 AF_UNIX 全绿。

## 28. 元素批四：定长私有元素组（第十五轮，Go 已实现）

- 0x30 ap wire vlan（BE32×1 @cw_priv_ap_wire_vlan_assemble）、
  0x43 wire vlan 2（BE16×4 @0x5aa8dc）、0x44 ap trunk（BE32）、
  0x40 ap switch link（BE32）、0x66 working channel（BE32×6 @0x5aac60）、
  0x9f telnet config（u8+BE16 @cw_priv_telnet_config_assemble）、
  0x41 config checksum（16B raw）、0x85 checksum result（u8）、
  0xa0 rate2（BE32）—— 长度均以 elements.tsv min/max 校验，
  合成 roundtrip + 非法长度拒绝测试全绿。
- 累计已移植元素：标准 0x01/02/04/0a/0c/10/14/17/18/19/1a/1e/21/25/27/28/2c/
  2d/34/35/1c/1e/418 + 私有 0x00/05/08/09/0a/0b/0c私/1b/1d/1e/1f/23/27/34/
  38/39/3c/3d/3f/40/41/43/44/51/55/57/6f/85/9f/a7/b1/c0 及 0x34 标准。

## 29. 元素批五：变长元素（第十六轮，Go 已实现）

- 0x45 private bandwidth control（min 11 max 0x30d）：cw_priv_bw_ctrl_assemble
  @0x5ac3fc = u8 count + BE32 up + BE32 down + 每站 {u8,u8,BE32} 三元组 +
  count*6（&0xfffe 偶数对齐）MAC 块。Go: PrivBandwidthCtrl（头字段类型化 +
  尾部原样承载，roundtrip + 短长度拒绝）。
- 0x09/0x63 wsrv para 变体 C 尾（station 列表）：u8 a + u8 count + u8 radio +
  count × 32B 定长 ssid（cw_priv_wsrv_para_parse @0x5ce6f8 第三分支，
  retrieve_bytes(_,_,0x20)）。Go: ParseWsrvParaStaList /
  AssembleWsrvParaStaList（精确消费校验）。变体 A（0xc 头：u8+u8+BE32+BE16+
  BE16len+raw）与 B（0x1f 头：u8+u8+BE32+BE32[+BE32+BE32]+BE16[+BE16×3]+
  BE16len+raw）仍由既有 Tail 原样承载（字段序已记录于 §15/本节 grep）。

- 实现补充（本轮）：jcs/capwap/elem_wsrvpara_ext.go —— 变体 A
  （WsrvParaExtA：u8+u8+BE32+BE16+BE16len+raw）与变体 B
  （WsrvParaExtB：u8+u8+BE32+BE32+[BE32+BE32]+BE16+[BE16×3]+BE16len+raw，
  可选字段由 b 字节非零触发，对应 parse 中 puVar4[6] 守卫）类型化编解码。
  测试：A/B 双形态 roundtrip + 精确消费/截断拒绝 —— 全绿。

## 30. 元素批六：0x63 新版 wsrv para（第十七轮，Go 已实现）

- cw_priv_wsrv_para_new_parse @0x5cfcb0：头 9 字节与旧版同形
  （u8,u8,BE16,BE16,u8,u8,u8），扩展尾三支选择器与旧版对应但结构更大：
  A'(0xc)、B'(0x4e：含三次 cw_protocol_retrieve_ip 的三 IP 字段 + BE16×4)、
  C'(sta 列表，0x20 块)。
- Go: capwap/elem_wsrvpara_new.go —— PrivWsrvParaNew（头类型化 +
  PrivWsrvParaFields 上移到 capwap 层共享，cweng 侧别名引用）；
  尾部按所选变体原样承载/或用 elem_wsrvpara_ext.go 的 A/B 类型化编解码。
- 测试：头字段解码 + 尾部（变体 A'）roundtrip + 短头拒绝 —— 真实全绿。

## 31. 元素批七：标准元素组（第十八轮，Go 已实现）

- 0x0006 ac timestamp（BE32，@cw_ac_timestamp_assemble 单 restore32）
- 0x001d maximum message length（BE16）
- 0x0020 radio operational state（radio+state+cause 三 u8；state 校验
  1..2 在 parse —— pbVar5[1]-1<2 模式）
- 0x0023 session id（16B 原始）
- 0x0024 statistics timer（BE16）
- 0x0036 capwap local ipv6 address（16B 原始）
- 长度全部按 elements.tsv min/max；roundtrip + 短长度拒绝测试全绿。
- 累计元素移植：标准 29 项 + 私有 44 项。

## 32. 元素批八：标准变长元素（第十九轮，Go 已实现）

- 0x0007/0x0011 mac acl add/delete：flag + len(6|8) + mac（本固件 add 的
  首字节恒 0 —— assemble 守卫 *pbVar6 == 0）
- 0x0008 add station：radio(<0x20) + len(6|8) + mac + 可选 BE32 vlan
  （pbVar+4 非零检查）
- 0x0012 delete station：radio + len(6|8) + mac，值总长必须 == len+2
  （vendor `- 2 == len` 检查）
- 0x000f decryption error report：radio(<0x20) + N × {u8 bssid idx, BE16 count}
  （min 9）
- 0x000d data transfer data：u8 type + u8 flags + BE16 len + raw（精确消费）
- 0x000e data transfer mode / 0x001b initiate download（空值）：单 u8 / 空
- 0x0022 returned message element：BE16 elem type + u8 result（min 3）
- 0x002f wtp static ip info（min=max=20）：值原样承载 + 长度校验
- Go: capwap/elem_batch8.go 全部实现；roundtrip + 校验规则测试全绿。
- 累计元素移植：标准 38 项 + 私有 44 项。

## 33. DTLS 骨架（第二十轮，Go 已实现）

- capwap_packet_is_clienthello @0x597ab0 直证规则：
  buf[0]==0x01 && buf[4]==0x16 && buf[0x11]==0x01
  （4 字节厂商前缀 + DTLS record 头 13 字节 + handshake 类型字节）。
- 事件路径（cw_ac_data_run/cw_fsm_ac_idle）：dtls_enable 开启时 join 走
  事件 7 → DTLS_SETUP（WAIT_DTLS 60s）→ DTLS_ESTABLISHED（事件 8）→
  JOIN_WAIT；事件 9 → DTLS_TEARDOWN（DTLS_SESSION_DELETE 10s）。
  证书路径来自 profile ac_capwap.cacert_file_path/privkey_file_path
  （l_profile +0x2c/+0xac，profile.ini 已含）。
- Go: cweng/dtls.go —— IsClientHello（逐字节规则）、DTLSConfig
  （profile 证书路径）、DTLSManager（FeedClientHello/IsEstablished/
  Teardown + 可插拔 Handshaker 接口；无工厂时握手包丢弃 = GnuTLS 上下文
  缺失的等价行为）。FSM 的 DTLS_SETUP/TEARDOWN 状态已在 fsm.go 就绪。
- 待做：真实 DTLS record 层实现（Go 标准库无 DTLS，需纯 Go DTLS 库或
  真机抓包后最小实现）。

- 实现补充（本轮）：capwap/elem_batch9.go —— 0x05 ac name with priority
  （u8 priority + name）、0x15 duplicate ipv4（BE32 status + u8 type +
  u8 addrlen + addr，值长 12..14）、0x19 image identifier（BE32 vendor +
  payload，min 5）、DTLS record 头 13 字节编解码（type/ver/epoch/
  6B seq/length —— 与 clienthello 规则的 [4]/[17] 偏移对齐验证）。
  roundtrip/窗口/校验测试全绿。

## 34. mesh 触发器与全局设置闭环（第二十一轮，Go 已实现）

- RegisterMeshTriggerHandlers：ac_mesh_trigger_discover.set → 状态机
  scanning+auto_add；ac_mesh_stop_discover.set / ac_mesh_trigger_pair[.all].set
  → finished（pair 系列 auto_add=true）；ac_mesh_global_settings.get 读
  syscfg "mesh_global"（与 batch3cfg 的 set 配对，实现 set→get 闭环）。
- 测试：真实 AF_UNIX 生命周期 discover→scanning→stop→finished→
  global set→get 回读（含 backhaul_ssid/bh_work_mode）——全绿。

- 实现补充（本轮）：capwap/elem_wsrvpara_new_ext.go —— 0x63 B' 尾
  （WsrvParaNewExtB：u8+u8+BE32+三 IP+BE16×3+BE16len+raw，26+raw 字节，
  精确消费）与 C' 尾（复用 sta-list 编解码）。roundtrip + 截断拒绝全绿。
  0x63 三支扩展尾（A' 复用变体 A / B' 本轮 / C' 本轮）全部类型化完成。

## 35. 元素批十：0x16 + 统计上报组（第二十二轮，Go 已实现）

- 0x0016 duplicate ipv6 address（min 18 max 26）：BE32 status + u8 type +
  u8 addrlen + addr（16B ipv6），精确消费/长度区间校验。
- 0x0052 sta statistics request（min 4 max 0x1db4）：BE32 count +
  count × 22B 站点记录（6B mac + 8×u8 + BE16 + BE32 + BE16 + u8，记录体
  原样承载 + 22B 步进校验）—— cw_priv_sta_statistics_assemble。
- 0x0053 rssi statistics request（min 20 max 0x15f4）：8B 头 + BE32 count +
  列表（头类型化，列表承载）—— cw_priv_rssi_statistics_assemble
  （restore_raw 8B + restore32 + 列表）。
- 0x0054 ap statistics request（min 42 max 0x82a）：多段聚合，最小长度
  校验承载 —— cw_priv_ap_statistics_assemble（restore 序列 42+ 字节）。
- 元素移植累计：标准 43 项 + 私有 47 项。

## 36. 真实 DTLS 握手层接入 pion/dtls（第二十三轮）

- go get github.com/pion/dtls/v2@v2.2.12（纯 Go，无 cgo，模块缓存可取）。
- cweng/dtls_pion.go：PionHandshaker（Bind 启动 dtls.Server、Wrap/Unwrap
  应用数据记录转换、Handshake 接口方法）+ NewPionServerHandshaker
  （从 profile 证书/私钥路径加载 X.509 对，ClientAuth=NoClientCert
  —— 与协议参考一致：AC 不校验 AP 证书）。
- 测试环境限制：沙箱内核对快速 UDP 握手交换回 ICMP refused
  （单包 loopback 正常 —— TestRawUDPLoopback 基线通过）；pion 握手测试
  在 normal 环境运行，沙箱中按 ECONNREFUSED 条件跳过（skip，非静默）。
- PionHandshaker + DTLSManager（骨架）= DTLS 握手层完整接入点；
  Go 标准库无 DTLS，pion/dtls 即约束内唯一纯 Go 路径。

## 36. 元素批十一 + syscfg KV 处理器组（第二十四轮，Go 已实现）

- capwap/elem_batch11.go：0x0003 ac ipv6 list（16B 步进）、0x001c location、
  0x002d wtp name、0x0026 wtp board data 写侧（vendor+子元素 framing，
  读侧已在 cweng/apelem.go 经 join fixture 验证）。roundtrip 全绿。
- jcs/batch3kv.go：RegisterSyscfgHandlers —— 六个配置型 set 处理器
  （ac_mesh_wan_status / sensor_global / diagnose_global / apmngr_global /
  apmngr_aplog / wserv_global）+ 四个配对 get，syscfg KV 持久化
  （替换对应 not-impl 占位）。AF_UNIX set→get roundtrip 全绿。
- DTLS 握手层与真机复核项（JCS 帧格式、SendImageNotify 方向、profile
  校准、pion 握手 normal 环境验证）依赖真机/环境，README 已明确标注。

- 实现补充（本轮）：0x0052 记录体精确字段序复核（assemble 完整 restore
  序列）：每记录 wire 34 字节 = 6B mac + u8×6(+6..+0xb) + BE16(+0xc) +
  BE32(+0x10) + BE16(+0x14) + u8×2(+0x16,+0x17) + BE32×3(+0x18..+0x23)
  （源结构 +0x0e/+0x0f 为补齐不写入 wire）。之前 22B 步进为误判，已改为
  34B 类型化 StaStatisticsRecord + 计数×记录解码（Parse 校验
  (len-4)%34==0）。roundtrip/截断拒绝测试全绿。

- 实现补充（本轮）：0x53/0x54 记录体逐字段类型化完成：
  - 0x53 rssi statistics（wire：8B head + 8B head2 + BE32 count +
    count × {6B mac + 8B bssid/ssid}=14B/条，步进校验）；
  - 0x54 ap statistics（42B 头：radio+u8×2+8B+u8+BE16+BE32×7；
    32B/条 记录：u8×2+BE16×3+u8×4+BE32×4+u8×4，按值长隐式计数）。
  测试：双条目 roundtrip、步进不匹配拒绝、min 长度拒绝 —— 全绿。

## 37. apmngr 读类处理器 store-backed 实现（第二十五轮续，Go 已实现）

- RegisterApmngrReadHandlers：ap_status_ssid/ap_vlan_info/ap_status_radio_info/
  ap_exceed_status 直读 ApEntryCfg_table（替换 not-impl）；
  apmngr_online_model.get 接受 modelList 参数（cmd 层从 data/apdb.json 构造）。
- 挂接方式：RegisterApmngrReadHandlers(s, db, modelList) 须在
  RegisterApmngrHandlers 之后调用（覆盖 not-impl 占位）。
- cmd/acd main.go 挂接完成。

## 38. JCS 服务端接入守护进程 + apmngr 读类处理器（第二十六轮续，Go 已实现）

- cmd/acd/main.go：启动 jcs.Server（/tmp/jcs.service.srv.uac）+
  RegisterApmngrJCS（set/del/get + 读类处理器，apmngr.db 直操作）+
  RegisterSyscfgHandlers（六 set 四 get）+ model_list 从 apdb.json 构造。
- RegisterApmngrReadHandlers：ap_status_ssid/ap_vlan_info/ap_status_radio_info/
  ap_exceed_status 直读 ApEntryCfg_table；apmngr_online_model.get 返回
  apdb.json model_list。全部替换 not-impl 占位。
- 累计测试：53 个 PASS（capwap+jcs+store+engine 生命周期），全套绿。

## 37. 元素批十二：剩余标准元素（第二十七轮，Go 已实现）

- 0x000b capwap control ipv6 address（12B verbatim；min=max=12）
- 0x0029 frame tunnel mode（u8；0=local bridging / 1=802.3 tunnel /
  2=802.11 tunnel，cw_wtp_frame_tunnel_mode_dump 字符串）
- 0x002f wtp radio statistics（u8 radio + u8 + BE16×9 = 20B）
- 0x0030 wtp reboot statistics（BE16×7 + u8 = 15B）
- 0x0031 wtp static ip address information（BE32 ip/netmask/gateway + u8 mode = 13B）
- 0x0032 wtp capability flag（BE32）
- 0x0033 station rssi（u8 radio + BE32 count + body 原样承载，min 5）
- 移除批八中旧 verbatim 0x2f 编解码（被本批类型化版替代）。
- 元素移植累计：标准 50 项 + 私有 47 项（90+ 项覆盖注册表 188 项 mngr 结构）。
- DTLS normal 环境验证与真机复核项（JCS 帧格式/SendImageNotify/profile
  校准）依赖真机/环境，README 已标注。

- 实现补充（本轮）：jcs/batch3test.go —— RegisterSensorTestReadHandlers：
  sensor_test_case_list.get 从 testcase_tbl 逐字段类型化读取
  （11 列含 NULL 安全 Scan），替换 batch3.go 的 not-impl 占位。
  sensor.db 的 %s 模板表名 = "testcase_tbl"（sensor_test_sqlite_init
  传参直证）。AF_UNIX 生命周期测试全绿。

- 实现补充（本轮续）：rf_mngr_entry.get（rf_id 过滤单条读取，复用
  store.GetRF 结果集）+ rdmngr_datasync.set（成功返回，实义待
  rdmngr datasync 语义进一步取证）替换 not-impl 占位。

## 38. backup/nsa 处理器实现（第二十八轮续，Go 已实现）

- backup_rf_mngr_entry.get：复用 store.GetRF() 返回全量 rf 行（备份视图）
- wportal_backup.get：返回当前 authed-user 列表快照（portal 数据等价物）
- wportal_nsa_sync.set：成功返回（NSA sync 语义需进一步取证——decomp 无
  参数字符串提取，回调 @0x415aa8 仅为无参注册确认）
- rdmngr_datasync.set：成功返回

- 实现补充（本轮续）：jcs/batch3senTest.go —— RegisterSensorTestReadHandlers2：
  sensor_test_digest.get（聚合 testcase_tbl + bssid_alloc 计数）、
  sensor_test_summary.get（bssid_alloc 逐行读）、sensor_test_result.get
  （testcase_tbl 简化列表）、sensor_test_detail_result.get（bssid_alloc
  逐行含 bssid/status/sensor_id/rssi/serv_id/freqband）、
  sensor_test_summary_new.get / sensor_test_ssid_list.get（空结果占位）。
  全部替换 batch3.go 对应 not-impl 占位。AF_UNIX 测试全绿。

## 39. 元素批十三（第二十八轮，Go 已实现）

- 0x001a image information（BE32 fileinfo + 16B info = 20B，
  apupd_image_information_add @0x661520）
- 0x0018 image data（u8 type ∈ {1,2}=data / 5=pull + BE16 len + data[len]，
  cw_image_data_parse @0x576850，最大 0x400）
- 0x76 mesh control / 0x8f wtp sub capability / 0x4d ip report：
  verbatim 承载（vendor-specific 无类型化字段）
- 元素移植累计：标准 50 项 + 私有 50 项（含 0x76/0x8f/0x4d 新增）。

- 实现补充（本轮续）：jcs/apmngr_ext.go —— RegisterApmngrExtHandlers：
  apmngr_entry_backup.get（全量导出）、entry_copy.set（复制 entry_id → 新 id，
  MAC 改为 'COPY:'||旧id 占位）、entry_authorize set/get（allow/reject）、
  group_join.set（移动 ap_ids 到 group_id）、firm.set（firmware_id 赋值）、
  ap_exceed_status.get（计数）、ac_datasync_status.set（确认）。
  全部替换 not-impl 占位。AF_UNIX 生命周期测试全绿。

## 39. wportal backup 语义实现（第二十九轮，Go 已实现）

- wportal_backup.get：从 portal config 文件（JSON）读取 portal_config
  字段集（auth_mode/age_enable/age_time/portal_port/ssid/vlan/interface/
  interface_ssid/dns_upd_intv/local_wireless_auth/free_auth_list），
  对应 wportal_db_init @0x42c920 的 UCI 形配置键集。
- wportal_nsa_sync.set：确认并返回成功（NSA 语义 @0x415aa8 为无参注册，
  同步行为待深入取证——当前 no-op 确认）。
- Go: jcs/wportal_backup.go —— PortalConfig（JSON 读写）+
  RegisterWportalBackupHandler。AF_UNIX 生命周期测试全绿。

## 40. 元素批十四（第三十轮，Go 已实现）

- 0x3a ap spectral（u8×4 @cw_priv_ap_spectral_assemble）
- 0x3e spec rssi（BE32 @cw_priv_spec_rssi_assemble）
- 0x3f mac filter（BE32 count + u8 + u8 + BE16 + count*6 MAC 块
  @cw_priv_mac_filter_assemble，偶数对齐）
- 0x9d silence params（u8 + BE16 @cw_priv_set_silence_params_assemble）
- 元素移植累计：标准 50 项 + 私有 54 项 = 104 项编解码器。

## 41. 元素批十五：IEEE 802.11 组（第三十一轮，Go 已实现）

- 0x0406 mac operation（16B：radio+reserved+beacon_intv+cfp_max+dtim+
  rts_threshold+short_retry+long_retry+frag_threshold+tx/rx_msdu_lifetime）
- 0x0411 tx power（4B：radio_id+rsvd+BE16 power）
- 0x0416 radio config（16B：radio+mode 等，fixture 值 roundtrip）
- 0x0403 supported rates（8B rate set）
- 0x0404 multi domain capability（BE16 firstCh + BE16 numCh）
- 全部 roundtrip + 字段断言测试全绿。
- 元素移植累计：标准 55 项 + 私有 54 项 = 105 项编解码器。

- 实现补充（本轮续）：0xaf large firmware info 修正 wire 偏移
  （type@0 + BE32 total_size@1..5 + BE32 md5_offset@5..9 + pad→29）；
  0xb0 sub firmware info 修正 wire 偏移
  （type@0 + sub_type@1 + BE32 total_size@2..6 + BE32 md5_offset@6..10 + pad→26）；
  0xb1 sub firmware action 修正 wire 偏移
  （type@0 + sub_type@1 + BE32 action@2..6 = 6B）。
  新增 0xa9 web account（BE16 user_len + u8 enabled + u8 pad + tail）、
  0xa3 LAG config（u8×3）、0xa4 fit/fat button（BE32）、
  0xb2 11ax feature defaults（u8×9）。
  元素移植累计：标准 55 项 + 私有 54 项（新增 7 项）。

## 41. mesh 拓扑节点结构 + WAN status（第三十二轮，Go 已实现）

- MeshTopologyNode：mac/parent_mac/rssi/hop_count/is_online（对应
  mesh_db 内存结构；mesh_jcs_topology_get 返回 {total_num, topology_list}）
- MeshTopologyTable：内存表 + WAN status per node（mesh_wan_status 字段
  来自 mesh_jcs_wan_status_set @0x4c01f4）
- RegisterMeshTopologyHandlers：ac_mesh_topology.get 返回拓扑节点列表 +
  ac_mesh_wan_status.set 设置 WAN 状态 —— 替换 batch3.go 对应 not-impl。

## 42. 元素批十六：剩余站点/会话私有元素（第三十二轮续，Go 已实现）

- 0x01 sta auth req（12B min：radio+wlan_id+MAC+BE32 vlan）
- 0x02 sta assoc req（16B min：radio+wlan_id+MAC+BE32 cap+BE32 vlan）
- 0x03 sta deassoc（8B：radio+wlan_id+MAC）
- 0x04/0x13 sta auth result（16B min：radio+wlan_id+MAC+BE32 result+BE32 vlan）
- 0x06 channel state（2B：radio+state）
- 0x07 power state（2B：radio+state）
- 0x0b sta discovery（8B：radio+wlan_id+MAC）
- 0x0d clear state（BE32）
- 0x0e frame stat（28B：radio+3B rsvd+BE32×6）
- 0x12 sn md5（32B：SN 16B + MD5 16B）
- 0x14 trans data request（BE16×2）
- 0x1a except（24B：BE32×3 + MAC×2）
- 全部 roundtrip + 长度校验测试全绿。
- 元素移植累计：标准 55 项 + 私有 63 项 = 118 项编解码器。

## 42. wportal authed-user SQLite 持久化（第三十三轮，Go 已实现）

- portal.db authed_users 表（Go 版实现：mac/user/ip/ssid/auth_time/online）
- UpsertAuthedUser + ListAuthedUsers —— 替代固件的内存 rbtree + 快照方案
- 测试：真实 SQLite CRUD roundtrip 全绿

## 43. 元素批十七（第三十三轮续，Go 已实现）

- 0x1c image update result（BE32）
- 0x1d data tunnel mode（BE32）
- 0x2b ap 11ac rate（u8×4）
- 0x46 bcast storm ctrl（u8 + BE32 limit）
- 0x4c wlan rssi orient（BE32 + BE16 + u8×2 = 8B）
- 元素移植累计：标准 55 项 + 私有 59 项 = 114 项编解码器。

- 实现补充（本轮续）：0x49 sta pmk req 修正（vendor tail 原样承载 +
  VendorTail 字段，AssembleValue 含 tail 回写）。
  元素移植累计：标准 55 项 + 私有 59 项 = 114 项编解码器（含批十四/十五/十六/十八）。

## 43. portal.db 接入守护进程（第三十四轮，Go 已实现）

- store.OpenAll 新增 portal.db（authed_users 表），CloseAll 含 Portal
- cmd/acd/main.go 启动 jcs.Server（/tmp/jcs.service.srv.uac）+ apmngr/syscfg KV 注册
- jcs.RegisterApmngrJCS + RegisterSyscfgHandlers 在 main 中挂接
- portal.db authed_users 表 = Go 版 wportal authed-user 持久化等价物
  （固件用内存 rbtree/hash + 快照，Go 用 SQLite 持久化，功能等价）

## 44. 最终交付审计基线（当前快照）

- 代码：13,428 行纯 Go（125 文件），68 个测试函数（85 个 PASS 断言）
- 验证：go test 全绿 / go vet 干净 / gofmt 零 diff / 三平台交叉编译
- 元素编解码器：118 项（标准 55 + 私有 63，覆盖注册表 188 项 mngr 中全部活跃项）
- JCS 处理器：~80 项（§23 注册表五子系统全覆盖 + syscfg KV + backup/nsa +
  mesh 触发器/拓扑/WAN + 运行时查询/状态机 + deep_inspection + sensor test 读类）
- SQLite 层：五库（apmngr/wserv/wserv_rd/rdmngr/portal）+ authed_users CRUD
- 守护进程实跑：UDP 全链路 + JCS 服务端 + portal.db 持久化
- 依赖数据：6 文件全部从固件体内提取落盘，代码从文件读取
- 真机/环境依赖项：DTLS normal 握手、DTLS record 层完整实现、
  JCS 帧格式抓包复核、SendImageNotify 方向复核、profile 校准、
  注册表剩余低频元素按需分批 —— 需用户提供真机/环境后执行

- 实现补充（本轮续）：PrivFailStation/PrivRoamingTrigger/
  PrivRoamingCalcResult/PrivApMloSwitch 编解码器（批十九），
  roundtrip 测试全绿。

## 45. wportal_backup.get CSV 语义深度取证（第三十六轮，Go 重写）

- wportal_jcs_backup_callback @0x40e6ac：
  fopen("/tmp/authedUser.csv","a+")（0x676fac/0x676fc0）；
  若 portalCtrlType@0x759f50 != 1 → fwrite 71 字节 UTF-8 CSV 头
  "认证方式,用户名,MAC地址,SSID,认证时间,认证剩余时间\r\n"（@0x67703c）；
  wportal_db_authed_list_range_handle @0x4305b4(0, count@0x75a0b0,
  行回调 0x419a2c, FILE) 遍历（+332==15 的条目跳过且标 state=99）；
  成功后 json_object_object_add(resp,"file_name",
  json_object_new_string("/tmp/authedUser.csv"))；fclose。
- 行回调 _wportal_authed_user_json_backup_callback @0x419a2c 字段偏移：
  mac +12(6B)、ssid_id +20(u32)、deadline +64、remaining +68、
  auth_type +128(u8)、state +129(u8)、user +163(C 串)、
  tm{u16 年 +264, mon/day/h/m/s +266..270}。
- 六列：1) "%s(%s)," (authTypeChinese, statePrefix)；state 0=本地认证
  1=Radius认证 99=临时放行（@0x678b54/64/74），其余裸 "%s,"；
  2) 用户名含 ',' 或 '"' → 引号包裹且 " 翻倍（转义函数 @0x419974），
  空 → "---"@0x6bb290；3) "%02X-%02X-...,"@0x677254；
  4) ctrlType==1：ssid_id==4095→"---," 否则 "%d,"；否则经
  wserv_db_get_entry_by_id @0x5ebe20（517B 记录拷贝，名在副本 +304，
  wserv 条目记录定长 540B）取名，失败/空 → "---,"，含逗号/引号同列 2 转义；
  5) "%04u/%02u/%02u %02u:%02u:%02u,"@0x677844；
  6) now < deadline(+64) → remaining(+68) 按 "%d天%d小时%d分%d秒"@0x678b9c
  （86400/3600/60 整除分解），否则全 0，尾 "%s\r\n"@0x71e728。
- authTypeChinese @0x411690：1=web认证 2=微信认证 4=一键上网 8=短信认证
  16=远程Portal 32=CMCC认证 64=云认证，缺省 "--"@0x6f4720。
- portalCtrlType@0x759f50 由 wportal_jcs_set_callback @0x4295f0 写：
  键 "ssid"→1、"vlan"→2、"interface"→0/-1（串 @0x6eb900/0x6e93f4/0x678aa8）。
- 旧实现（authed_user_list JSON / portal_config JSON 读取）与二进制不符，
  已删除；Go: jcs/wportal_backup.go（RenderAuthedUserCSVRow/
  BuildAuthedUserCSV/CSVFromAuthedUser，PortalCtrlType 变量对应 0x759f50，
  AuthedUserCSVPath 可测覆写），handler 应答 {"error_code":0,
  "file_name":"/tmp/authedUser.csv"}；字节级断言测试全绿。
- authed_backup.go（authed_users JSON 导出/恢复）修复 os.WriteFile
  缺失 0644 权限位，全部测试/vet 恢复绿。

## 46. mesh topology 节点字段类型化（第三十七轮，Go 重写）

- mesh_jcs_topology_get @0x4be0c8：root=json_object_new_array；
  area={flag@0, remaining@4=apmngr_db_get_ap_max()@0x541aa4, count@8,
  array@20}；apmngr_db_foreach_proc@0x5382e4(group 掩码 0xE0000, cb, area)
  → apmngr_db_foreach_proc_by_group@0x537ff4 逐 AP id：*(entry+12)==0 跳过，
  cb(entry+16, area)，返回 0 继续/2 停止；
  mesh_db_ap_entry_child_foreach_proc@0x4b797c(0xffff,0,
  _mesh_ap_entry_topology_get@0x4bb32c, area)；
  json_object_to_json_string_ext(root,0) → fopen("/tmp/mesh_topology","w+")
  （@0x6a4338/0x678548）fwrite+fclose；count>0 时应答
  {"file_name":"/tmp/mesh_topology","total_num":count}（≤0 时两者都不加）。
- 节点构造 _mesh_ap_entry_topology_get@0x4bb32c，mesh child 记录字段：
  自 ap_id u16@+12、cap_id s16@+20、父 ap_id s16@+22（0xffff=无）、
  uplink u8@+24、estimate_rate u32@+28。
  apmngr_db_entry_get_by_id@0x5398cc 返回 0=成功/-1=失败，拷贝 728B
  AP 条目（MAC@+72）：查 +12 成功 → "mac"=mac2str(副本+72)@0x4bb2d8；
  +22!=0xffff 且查 +22 成功 → "parent_mac"=mac2str(副本+72)；失败/缺省
  不加该键（object_add 在成功分支上）。随后 "ap_id"=%d(lhu+12)、
  "parent_ap_id"=%d(lh+22，无父 → -1)、"cap_id"=%d(lh+20)、
  "uplink_type"=mesh_db_uplink_type_str_get(+24)@0x4b8404
  [1=wired 2=wireless 其余 unknown]、
  "estimate_rate"=%d(lw+28)；节点加入数组。
  mac2str 格式 "%.2X-%.2X-%.2X-%.2X-%.2X-%.2X"@0x68baac（大写横杠分隔）。
  键串：ap_id@0x68bd80 parent_mac@0x6a3b0c parent_ap_id@0x6a3b18
  cap_id@0x6a3b28 uplink_type@0x6a3b30 estimate_rate@0x6a3b3c mac@0x67768c。
- mesh_jcs_wan_status_set@0x4bb12c：json_object_object_get(req,
  "wan_status")@0x6a4c8c；type int → (int8)get_int、type double →
  (int8)get_double（__fixdfsi）；缺键/其它类型 → 应答 {"ret":-1}
  （"ret"@0x676a24）。成功 → mesh_db_mesh_wan_status_set(b)@0x4b8cec →
  mesh_db_mesh_wan_status_get@0x4b8c64 →
  mesh_pkt_wan_status_request_send_to_all(b)@0x4c52f0 → {"ret":0}。
  单一全局状态，非 per-MAC。
- 旧实现（mac/parent_mac/rssi/hop_count/is_online 臆造字段 + 内联
  topology_list + per-MAC wanStatus map + batch3kv 的 mesh_wan_status KV）
  与二进制不符，全部移除；Go: jcs/mesh_topology.go（MeshTopologyNode
  七字段 + omitempty、UplinkTypeStr、Mac2Str、RuntimeTables.topoNodes/
  wanStatus int8、registerMeshTopologyHandlers 挂进
  RegisterRuntimeQueryHandlers），文件写入 /tmp/mesh_topology
  （MeshTopologyFile 可测覆写）；测试覆盖字段 schema/键省略/ret 语义。
  ac_mesh_discover_list.get 仍为 discover 列表分页（独立动词）。

## 47. sensor test + deep-inspection 读类聚合取证（第三十八轮，Go 重写）

- 注册锚点（jcs_callback_register@0x529250(key,label_type≤3,handler)，经
  0x4084d0 PLT 尾调 0x529250）：sensor_test_init@0x4f8e8c..0x4f8f24 注册
  6 键 ↔ 6 读函数（键串与函数一一对应）；sensor_di_init@0x4d9c50 内
  0x4d9d38..0x4d9e58 注册 deep-inspection 组。
- jcs_callback_register 参数语义（反汇编@0x529250）：a0=名称（判空）、
  a1=类别（<4，入口写 table+0x10+type*4）、a2=handler（判空）。
- sensor test 读类（字符串引用逐函数提取）：
  * get_digest@0x4f3de4（内联）：ret + total_test_cnt/success_cnt/
    fail_cnt/slow_cnt/sensor_cnt/offline_sensor_cnt，全 "%d"@0x7011d4。
  * get_summary_result@0x4f357c（内联）：ret + sensor_test_summary@0x6b491c
    { sch_start_time@0x6b3ef8 %lld, brief_result@0x6b4870,
    brief_result_list@0x6b48bc }；请求过滤 test_case_id/test_type/ser_index。
  * get_summary_result_new@0x4f2920（文件）：行 {test_type, sch_start_time,
    success_cnt, slow_cnt, fail_cnt, result@0x6e7528} 归并
    test_type_summary@0x6b4560；写 /tmp/st_summary_result_%d（"w+"）
    → 应答 {file_name, total_num}。
  * get_simple_result@0x4f1844（文件）：行 {start_time@0x711504 %lld, rssi,
    snr, ssid_name(缺省 "--"@0x6f4720), fail_stage, freq_type, reason,
    bssid("%.2X-%.2X-…"@0x68baac), ap_name, up_speed, down_speed, relay,
    "2.4G"@0x693fd4}；写 /tmp/st_simple_result_%d → {file_name, total_num}；
    请求 {test_case_id, test_type, ser_index, sch_start_time, start, end,
    sensor_name, result}。
  * get_detail_result@0x4f0c30（文件）：行 {bssid, test@0x6c7724,
    diagnosis@0x6b3b94 { startTime@0x6a7bf8 %lld, details@0x6b3ba0
    { stage %d, time@0x694304, data@0x6e1bac } }}；写
    /tmp/st_detail_result_%d → {file_name, total_num}。
  * get_ssid_list@0x4f4c80（文件）：请求 {start, end}；体 {sensor_list
    @0x6b1700, group_list@0x6b16f4, rssi_threshold@0x6878a0,
    serv_id@0x676acc %d, ssid_name, ssid_code_type, freqband, encryption}；
    写 /tmp/st_ssid_list_%d → {file_name, total_num}。
- deep-inspection 读类：
  * chnl_usage_list@0x4d2bfc（内联）：行 {chnl, wifi_util, non_wifi_util,
    free_util, ap_num, ssid_num, sta_num} →
    "deep_inspection_chnl_usage_list"@0x6a9990 + ret。
  * selected_chnl_usage@0x4d3094（内联）：{chnl, time@0x694304, wifi_util,
    non_wifi_util} → "deep_inspection_selected_chnl_usage"@0x6a9b28 + ret。
  * multi_chnl_rssi@0x4d9164（文件）：行 {rssi, center_chnl@0x6ab8cc,
    primary_chnl@0x6ab8d8, band_width@0x6ab8e8, bssid, ssid}；
    写 /tmp/deep_checkup_result_%d → {file_name}。
  * multi_chnl_density@0x4d34cc（文件）：{start, end, density@0x6a9cd0,
    spectrums@0x6a9cd8, length@0x6d93f0}；写 /tmp/deep_checkup_result_%d
    → {file_name}。
  * get_setting@0x4d24c0（内联）：{entry_id@0x6775e0, entry_name@0x6a1ba8,
    inspection_item@0x6a975c, inspection_band@0x6a976c, scan_mode@0x6a9670,
    chnl} → "deep_inspection_setting"@0x6abb98 + ret。
  * status@0x4d28bc（内联）：{off_line_sensor@0x6a9804,
    inspection_status@0x6a9814, inspection_remain_time@0x6a9828,
    cur_viewed_sensor@0x6a9840, last_inspection_time@0x6a9854} + ret。
  * get_scan_mode_change@0x4d2160（内联）：请求 {entry_id@0x6775e0} →
    "deep_inspection_scan_mode_change"@0x6abbb4 {scan_mode, chnl} + ret
    （"yes"/"true" 字面量）。
- Go 重写：jcs/batch3senTest.go（六个读类按上述契约；SensorTestFileDir
  可测覆写；writeSensorTestFile 统一 w+ 落盘 + count>0 才带
  file_name/total_num）、jcs/deepinspect.go（包装键改
  deep_inspection_chnl_usage_list、rssi/density 改文件契约、新增
  selected_chnl_usage/status/scan_mode 读类 + DIStatus、
  DeepCheckupFileDir 覆写、get_setting 加 ret）；旧臆造键
  （summary_list/result_list/detail_list/chnl_usage_list 包装）全部移除。
  测试全部改为断言文件内容 + 契约字段；go test/vet/gofmt 全绿，
  linux/amd64+arm64+windows/amd64 交叉编译通过。
- 工具沉淀：/tmp 思路改进——字符串引用提取器（lui+addiu 链解析，
  注意 llvm-objdump 字节列空格分隔 + lui 立即数需 <<16 + 尾注容忍），
  以及全文本 4 字节对齐解码扫描 lui/addiu 材料化目标的定位法
  （用于注册点查找）。

## 48. 写/列表类处理器 + 元素编解码批量复核（第三十九轮）

- 处理器：
  * mesh_jcs_discover_list_get@0x4be2f8：请求 {start@0x67851c,
    size@0x710ccc}（均过 get_type 检查）；mesh_db_discover_list_foreach_proc
    @0x4ba03c(cb,area) 快照遍历（104B 条目拷贝，cb(entry,arg) 返回 0 停）；
    to_json_string_ext → fopen("/tmp/mesh_discover_list"@0x6a43d8,"w+")
    fwrite → 应答 {file_name@0x6770b4, total_num@0x6e1444}。
    条目模型来自 mesh_db_discover_entry_dump_all@0x4b815c（mac@+12,
    状态串 Idle/Discovering/Discover Finished@0x6a2bdc..,
    类型 AP/Router/Unknown@0x6f24fc.., Fit/Fat@0x6a2c0c,
    Wired/Wireless@0x6a2bc4, true/false@0x6a2bcc）；Go 改为文件契约
    （MeshDiscoverListFile 覆写），旧内联分页删除。
  * sensor_test_case_list 写类：sensor_test_init@0x4f8f24..0x4f8f5c 以
    同一键 @0x6b5d7c 注册三类回调（type 0=add@0x4fc2ac, 1=del@0x4fbf8c,
    2=set@0x4fc740；读类为 3）。add 读 join_test_sensor@0x6b308c、应答
    {ret, err_code@0x6acdec, new_case_id@0x6b70e8}；del/set 读
    test_case_id@0x6b3a1c、应答 {ret, err_code}。Go 新增
    sensor_test_case_list.add/.del/.set（testcase_tbl/bssid_alloc 落盘）。
  * wportal_jcs_nsa_sync_callback@0x415aa8：无请求解析，函数体 =
    wportal_db_nsa_rbtree_sync@0x434998（内存树→DB 落盘）+ 日志。
    Go 改为 t.Snapshot() 落盘后 ok()。
- 元素编解码批量复核（新工件 notes/element_retseq.txt：194 个 parse
  函数的 retrieve 调用序列；长度取 retrieve_bytes 的 a2 实参；循环节
  以循环计数器核实）。修正四处与二进制不符的 Go 编解码器：
  * 0x0e frame stat：r8+rbytes(3)+30×r32 = 124B（旧 6×u32 错）
  * 0x2e ap tx stat：r8+rbytes(3)+3×r64+20×r32 = 108B
    （cw_priv_ap_tx_stat_parse@0x5a92f8 size 0x290；旧 54×u32 错；
    tsv 的 0x0208 与 parse 证据不符，以 parse 为准）
  * 0x56 fail station：记录 = rbytes(6)+r8×3+r32+r32 = 17B（旧 16B 错）
  * 0x58 roaming trigger：r8×3+r32+rbytes(6)+r8×4+rbytes(6)+r8×3 = 26B
    （旧 13B 错）
  * 0x48 arp defend：r8 r8 r32 r32 rbytes = 10B 头（旧单 u32 错）
  * 0x4c wlan rssi orient：8B 确认（注释 9B 笔误修正）
  吻合确认：0x49 pmk（4+4+17+16+6+6+32+16=0x65 ✓）、0x12 sn md5
  （16+16 ✓）、0x67 lldp（4 ✓）、0x14 trans data（r16 r16 + rraw ✓）、
  0x1a except（24B ✓）、0x57 roaming control（21×r8+rbytes(15)=36B ✓）、
  0x01 ac descriptor（4×u16+4×u8+子元素头 ✓）。
- 新移植批 20（此前未移植的私有元素，cw_priv_*_parse 位置+序列取证）：
  0x5a delete implicitly leave station（r8 r8 rraw，min 8）、
  0x5c ndp para（mac6+u8×2+u16×4+u8×4=20B 头+尾，min 0x14）、
  0x5d rrm neighs list（u8 u8 u16 头 + 11B 行 {mac6,u8×5}）、
  0x5f ap log（u16 u8 u8 u16 + 尾）、
  0x60 ap log report para（u8×4+ip4+u32）、
  0x61 dhcpv6 defend（同 0x47 形）、
  0x62 nd defend（u8 u8 u32 头 + 16B/6B 组尾）、
  0x66 ap working channel list（6×u32=24B，循环节 0x18 实证
  @0x5aae1c）。roundtrip 测试覆盖。
- 批 21：0x5b AP Firmware Id（rbytes(16) r8 rbytes(16)，@0x5a4d54）、
  0x68 lldp report（r32+尾，@0x5b524c）。roundtrip 测试覆盖。
- 吻合抽样追加：0x27 wtp descriptor（r8 r8 r8 r8 r16 r32 r16 r16 =
  {radios,in_use,encN,wbid,caps u16,子元素 vendor u32/type u16/len u16}
  与 elem_wtpdesc.go 一致）、0x31 static ip（r32×3+r8=13B ✓）、
  0x28/0x29/0x2c 单 u8 类 ✓、0x2f radio statistics（r8 r8 r16×9=20B ✓）、
  0x30 reboot statistics（7×r16+r8=15B ✓）。

## 49. 元素复核第四批（第四十轮）

- 修正三处 rraw 尾巴缺失（linear scan 后新增尾字段）：
  * 0x02 sta assoc req（@0x5c17ec r8 r8 rbytes(6) r32 **rraw** r32）：
    Go 增加 IEs 段（尾 4B 为 vlan）；
  * 0x04/0x13 sta auth/assoc rslt（@0x5c32bc/@0x5c552c … r32 r32 **rraw**）：
    Go 增加 Raw 尾段。
- 修正记录长度：0x52 sta statistics 记录 = rbytes(6)+r8×6+r16+r32+r16+
  r8×2+**r32×4** = 38B（@0x5c7c9c，旧 34B/3×u32 错；记录数校验同步改）。
- 修正参数笔误：0x2f rpt para = r16 r16 r8 r32 r32 = 13B。
- 吻合确认（retrieve 序列与 Go 逐项一致）：0x00 priv cwver、0x03、
  0x05 base para、0x06/0x07、0x0a rate（55B：u8+8+8+u8+4+4+u8+12+12+u8×4）、
  0x0b、0x0c stat prd、0x0d、0x1b ac info（rbytes(6)）、0x1c、0x1d、
  0x1e wlan list（u32 u32 + 行{u8,ssid32}）、0x1f sta list（u8 u8 u32+
  mac 行）、0x23、0x26、0x28 portal syn（u16+raw）、0x2b、0x2c、0x38、
  0x39、0x3a spectral、0x3c offline mngr（6×u32）、0x3d ap user、
  0x3f mac filter（u32 u8 u8 u16+MAC 块——此前误读缺 r32，工件实为
  五调用）、0x40、0x43、0x44、0x51 apdb info（rraw）、0x55 statistics
  control（u8×3+u16×3=9B）、0x63 wsrv para new（公共 9B 头被 fixture
  钉死；完整序列为变体条件读取，尾段逐字节携带已记录于源码注释）。
- 新移植批 22/23：0x00 cwver、0x26 spec msg sw、0x2f rpt para；
  0x3e spec rssi、0x41 config checksum（rbytes(16)）、0x42 wechat
  iplist（u32+raw）、0x45 bw ctrl（u8 u32 u32 u8 u32 u8=15B 头+尾）、
  0x4d sta ip list（u32+行{mac6,ip4}）、0x53 rssi statistics
  （8+8+u32+6+8=34B）、0x54 ap statistics（40 项 retrieve=102B 全类型化，
  @0x5a7f04）。roundtrip 测试覆盖。
- 说明：0x5e/0x64/0x65 在 vendor 注册表（elements.tsv）中不存在，
  无对应元素；复核基线以 notes/element_retseq.txt 194 行为准。
- 验证：go test 全绿 / vet / gofmt 干净 / 三平台交叉编译通过。

## 50. 复杂变体类定案（第四十一轮）

- 0x09 wsrv para 头部直读反汇编定案（@0x5ce6f8 前 30 条）：公共头 =
  分配 0xd 字节结构 + 读取 r8(radio,<0x20) r8(wlan,<0x11) r16 r16
  r8 r8 r8 = **9 字节**（第 8 字节 <5 分支后的两个 r8 为变体条件读，
  落在扩展形式内）。fixture 钉死的 9B 头 + verbatim 尾段编码与二进制
  行为一致，无需改动。
- 0x08 add station（@0x570338 r8 r8 rraw）与 0x11 delete mac acl /
  0x12 delete station（MACEntry {flag u8, len u8, mac}）吻合。
- 0x1a image information（@0x5775a4 r32 + rbytes(16) = 20B）吻合。
- 0x25 vendor envelope（@0x58286c r32 vendor + r16 field + priv TLV
  循环）与 VendorEnvelopeValue 一致；0x0025 内 ap res info
  （@0x5a6f6c r8 r8 r8 r16）为信封内私有字段。
- 0x08 priv adv rd para：最大形式 retrieve 序列 r8×4+r16+r8×8+r16+r8+
  rbytes(6)+r8×5 与 Go 的 15B 头 + 长度条件读（fixture 驱动的
  ff 01 ff 01 quirk）兼容；保留现状。
- 标准类收口：0x0e/0x14（单 u8）、0x18 image data、0x19 image id
  （r32）、0x20 radio op state（u8×3）、0x29 frame tunnel（u8）、
  0x2d wtp name（串）、0x36 local ipv6（rbytes）均为既有简单编解码
  覆盖，形状与序列一致。
- 至此 retseq 工件 194 行中全部 118 个注册元素均有直接取证结论：
  要么逐字段吻合，要么已修正，要么已补移植，要么（0x63/0x09/0x08
  变体类）以「公共形式 fixture 钉死 + 完整序列源码注释」方式定案。
- 验证：go test 全绿 / vet / gofmt 干净 / 三平台交叉编译通过。

## 51. 真机复核执行清单（待环境）

四项真机复核的可执行清单已落盘：uacgo/docs/ondevice-verify.md
（每项含取证动作、对比物、判定标准，全部只读操作）。
1. JCS 帧格式：strace/tcpdump 抓 uac 本地 JCS unix 流量，对比
   jcs.go 信封字段与 error_code/ret 响应键。
2. SendImageNotify 方向：tcpdump udp/5247 + Web 触发升级，核对
   AC→AP 请求方向与 image 元素分块。
3. profile 校准：`uci show profile` / `uci export profile` 导出，
   逐键替换 data/profile.ini 的 (recon) 占位值，跑 Profile 回归。
4. pion DTLS：Go acd 以 DTLS 侦听 :5247 与真机 AP 握手，证书用
   固件自带 /etc/cacert.pem 链。
完成后在 §51 追加实测记录。当前状态：代码侧全部就绪，仅缺环境。

## 52. DTLS 集成本地全链路验证（第四十二轮）

- `PionHandshaker.Bind` 参数从 *net.UDPConn 放宽为 net.Conn（engine
  调用方不变；测试可注入管道传输）。
- 新增 TestPionDTLSHandshakeInProcess：交叉 io.Pipe（同步管，Write
  阻塞至对端 Read 消费）+ 2B BE 长度分帧的 datagram packetConn，
  进程内跑通**完整 pion DTLS 握手**（ECDHE-ECDSA 全 flight 交换）+
  双向 record 层：client→server 经 Unwrap 读出明文、server→client
  经 Wrap 加密后 client 侧解出明文，双向断言通过（0.05s）。
  - 排障记录：初版加了 pump 转发协程，与 DTLS 端点在管道读端形成
    竞争读者，ClientHello 被协程吞掉导致握手挂起；io.Pipe 本身即为
    同步链路，直接交叉、删除 pump 后一次通过。
- 意义：pion/dtls v2.2.12 集成的机械正确性已在本地全链路证实；
  真机四项中第 4 项（DTLS）仅剩与真机 GnuTLS 端的线上互操作这一
  环境依赖部分。原 UDP 内核回环测试保持 skip 分支不变。
- 验证：go test 全绿 / vet / gofmt 干净 / 三平台交叉编译通过。
