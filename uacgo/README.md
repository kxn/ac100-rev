# uacgo — TL-AC100 `uac` 的 Go 重实现（进行中）

对固件 `/usr/sbin/uac`（ELF32 MSB MIPS32r2, 3.4MB）的逆向重建。
**每一条实现结论都直接取自 uac 二进制本身**（反汇编 / 伪代码 / .data 原始数据 / 固件自带样例报文），
旧会话的文档只作线索，未作为任何实现依据。

## 规模

12,635 行 Go 代码（119 文件）、64 个测试函数、4 包 + 1 二进制。
依赖：modernc.org/sqlite v1.62.0（纯 Go SQLite）+ pion/dtls v2.2.12（纯 Go DTLS）。

## 运行

```bash
go build ./cmd/acd && ./acd -data data -port 5246 [-iface 192.168.1.253] [-debug]
```

```bash
go test ./...   # 全部测试：fixtures 字节级对拍 + UDP 生命周期 + 控制流
```

交叉编译（纯 Go，零 cgo，零第三方依赖）：

```bash
GOOS=linux GOARCH=arm64 go build -o acd-arm64 ./cmd/acd
GOOS=windows GOARCH=amd64 go build -o acd.exe ./cmd/acd
```

## 数据文件（固件内嵌依赖 → 落盘读取）

| 文件 | 来源 | 证据 |
|---|---|---|
| `data/apdb.json` | `/etc/apdb.bin` 解密（DES-ECB，key `478da50bf9e3d2cf`@0x71ced0）| `accrypt_des_decrypt@0x666c94 → tpcom_des_min_do(...,&DAT_0071ced0,0)`，载荷 MD5 自校验通过，81 个 AP 型号 |
| `data/identity.json` | AC 身份（名称/版本/固件串/厂商 ID 0x12345678）| 值取自固件 .data 样例报文 `cw_dis_rsp@0x74f254`、`cw_join_rsp@0x74efe8` |
| `data/profile.ini` | UCI `profile` 配置（**固件镜像不含**，在设备 flash 配置分区）| `cw_ac_profile_init@0x58dca4` 任一项读失败 → 整链 init 跳过 → 进程退出（硬依赖）。节/键 = 二进制内全部 `uac_profile_get_*` 调用点；数值为重建占位，待真机 `uci show profile` 校准 |
| `testdata/*.bin` | uac .data 段 10 个厂商自带整包样例（`g_cw_*` 符号）| 全部解析→重组字节级一致 |
| `data/dbs/*.db` | 运行时自动创建（apmngr/wserv/wserv_rd/rdmngr）| 建表语句 = 二进制 .rodata 原文（`store/schemas.go`，19 条，含函数证据注释）|

## 已实现（证据锚定）

### capwap 包 — 线层
- 头位域（`cw_header_parse@0x5a0cc0` 的 MIPS32r2 `ext` 逐位）：
  ver/type/hlen/rid/wbid/T/F/L/W + 分片词(id/偏移8字节单位)；`L=1&&F=0` 拒收
- 控制头 = type(4)+seq(1)+MEL(2)+flags(1)；消息 1..26 与伪消息 0x33dd01/02
- **MEL = 元素字节 + 3**（`cw_parsed_pkt_create@0x588488` 计数器初始 3）
- 元素 TLV 遍历；未知元素跳过；0x25 信封 = vendor(4)+X(2)+私有 TLV(type<0xc1)
- 元素注册表全量提取（`notes/elements.tsv`：49 标准 + 25 802.11 + 120 私有，
  含 min/max/parse/assemble 符号）
- 发现/加入/配置状态三响应重建与厂商 fixture 字节一致（含 AC Descriptor
  12B 头 + 64B 厂商子元素布局）

### cweng 包 — 引擎
- 分发注册表：43 条注册（msg 类型 × 优先级升序 + ent 事件 0..3），见 `notes/registry.tsv`
- 线程模型：UDP 单 socket + 会话表（Go goroutine 等价）
- FSM：15 状态 + 12 事件 + 12 定时器（超时表 `l_timeouts@0x74cfac`），
  每状态门控消息集合（RUN: {13,9,8,18,24,26,15,16,0x33dd02,11}）
- 接入生命周期：发现(无会话) → join(建会话 IDLE→JOIN_WAIT→JOIN_FINISH)
  → 配置状态(→CONFIGURE) → 变更状态(→RUN + ent-1) → echo(RUN 看门狗)
- seq 语义：响应复制请求 seq（rid/wbid 同步复制，`ac_parsed_packet_create@0x590d58`）；
  出向请求用 session+0xa4 计数器（0xff→1 回绕）
- 重传：同 seq 请求 → 重发存储响应；旧 seq（±0x80 窗口）丢弃；
  响应重传定时器（间隔倍增，上限 60s，耗尽→ent2+拆链）
- 控制流：LED（msg7+信封{vendor0, 0x39,u32}）、复位（msg17；mode2/3+0x23=u32 1/3，
  mode>3 拒绝）
- join 解析：0x26 板数据（vendor+子元素，type0=型号ID/1=序列号/4=MAC）、
  0x2d 名称、0x1c 位置、0x1e 本地 IP → APEntry

### store 包 — SQLite 配置层（modernc.org/sqlite 纯 Go，无 cgo）
- DB 文件映射（符号串直证）：apmngr.db/wserv.db/wserv_rd.db/rdmngr.db …
- 19 条建表语句从反编译语料原文提取（ApEntryCfg/Run/TmpCfg、ApTemplate、Group、
  wserv_tbl、bind_tbl、rdmngrTable(rf 50 列)、sensor、whitelist、svr_tbl …）
- join → ApEntryCfg_table/ApEntryRun_table 落库（AP 条目在 join 监听器创建，
  对应 `_apmngr_try_create_ap_entry_by_template_or_db`）

### cweng — wserv/rdmngr 子系统
- WTP Descriptor(0x27)/wsrv para(0x09)/wlan list(0x1e)/adv rd para(0x08)/
  rate(0x0a) parse+assemble，全部用固件信封载荷 roundtrip 验证
- rdmngr(msg3 prio115, msg5 prio90)/uac_wservice(msg5 prio100) 监听器，
  优先级与注册表一致；StoreWserviceConfig 从 wserv.db/rdmngr.db 生成信封
- data/rate-default.bin：55B 射频速率默认值（固件 .data fixture 提取）

### cweng — wsta / apupd 子系统
- station info list(0x34)/priv sta list(0x1f) 解析；wsta msg9(prio100) 监听器
  跟踪客户端（0x34 → ClientTable）并在响应补 0x21 result code
- apupd：msg15(prio1) 监听器——0x19 确认 → result code + 0x1a image information；
  私有 0xb1 → 子镜像确认；0x18 type5 拉取 → 0x18 type1 数据块（≤0x400）；
  SendImageNotify（msg7+0x19）
- 实测全链路：discovery/join/cfg/cse/wtp-event(client)/echo 消息类型全对

### 实测
- UDP 发现请求（固件 fixture）→ 235B 响应，元素集与 `cw_dis_rsp` 一致
- 完整生命周期端到端（`TestEngineApLifecycle`）：状态迁移、去重、重发全部通过

## 未完成（按优先级）

1. **SQLite 层剩余面**：wsta/apdb_nego/sensor/portal/auth_server/mac_auth/
   dhcpdef/arp_defend 等库的 CRUD 与 JCS 对端（表结构已在 schemas.go）
2. **其余元素 parse/assemble**（注册表 194 项：已覆盖 fixtures 出现的
   0x01/0x02/0x04/0x0a/0x0c/0x10/0x14/0x17/0x18/0x19/0x1a/0x1e/0x21/0x25/
   0x27/0x28/0x2c/0x2d/0x34/0x35/0x1c/0x1e/0x418 及私有 0x00/0x08/0x09/0x0a/
   0x1b/0x1d/0x1e/0x23/0x27/0x39/0x51/0x55/0x57/0x2a/0x0c(私)/0x6f/0x38/
   0xa7/0x05/0x3c/0x3d/0xb1/0x30/0x40/0x43/0x44/0x66/0x9f/0x41/0x85/0xa0/0x45
   及 wsrv para 变体 A/B/C 扩展尾；其余按需分批）
3. **升级流程**（msg 15/16 + 元素 25 + 私有 0x5B/0x1C/0xAF/0xB0/0xB1）
4. **JCS/IPC 层**（116 个 jcs 处理器对端；与 Lua Web 后端的接口）
5. **DTLS**（`capwap_dtls_enable_switch` 默认关；证书路径来自 profile）
6. profile.ini 数值校准（需真机）

## 证据索引

- `notes/00-architecture.md` — 架构全记录（每节标函数地址）
- `notes/registry.tsv` — 分发注册表（43 条）
- `notes/elements.tsv` — 元素注册表（194 项 + 函数符号）
- `asm/`、`ghidra-export/decomp/` — 反汇编/伪代码全量语料
- `tools/` — 取证工具（符号解析、表提取、调用点扫描）
