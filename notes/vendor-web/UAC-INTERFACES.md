# TL-AC100 V6.0 uac JCS 接口抓包与反汇编对照

本文的「接口」指 Web/LuCI 通过 JCS 调用的 uac 接口；CAPWAP 空口元素、UBus 和内部线程不在本文范围（CAPWAP 见 [README.md](README.md)）。

本文把 AC100 V6.0 原厂 Web/LuCI 可触达的 uac JCS 接口整理为复刻参考：包含全部 278 个 `(name, op)` 注册项、处理函数地址、字段表、原始请求样本、类型反汇编证据和逐接口验证状态。CAPWAP 空口行为与部分字段的成功配置效果单列验证，不能从一次 JCS 回包推断 AP 已应用设置。

| 项 | 值 |
|---|---|
| 固件 | TL-AC100 V6.0 1.0.3 Build 260817 Rel.68871n |
| uac | `/usr/sbin/uac`，Build ID `7346df6c645058f30948c066f93708c38cc2193e`，SHA-256 `b12d1584fcafda2a71aa9038b41b7e1c5b893b350f3e6edf5105e445d024a912` |
| Web | 原厂 LuCI 控制器 `usr/lib/lua/luci/controller/admin/*.lua`，分发 `luci/controller/ds.lua` |
| 客户端封装 | `luci/torchlight/uac/jcs.lua` → `uds` (`usr/lib/lua/uds.so`) |
| 实测环境 | QEMU Malta MIPS BE + 原厂 rootfs/uac；实体 AP TL-XAP3006GC-PoE/DC 在线（MAC `04:F9:F8:76:A1:97`） |
| 接口全集 | 278 个 `(name, op)`，由 `jcs_callback_register` 的 278 个调用点静态恢复 |
| Web 可达 | 244 个，在静态索引中至少匹配到一个原厂 LuCI 控制器调用点 |
| 实测样本 | 277 个；236 个请求 `data` 非空；仅 `wips_event_detail` 未取得响应，原因见 §7 |
| AP 侧效果验证 | `ap_count`、`ap_status`、`ap_status_ssid` 读回及 `wservice ADD` 的 qiyitt 双频 WPA2 下发；其余 JCS 项未逐项验证 AP 生效 |

## 0. 结论摘要

1. Web 到 uac 的主链路是：浏览器 JSON → `luci/controller/ds.lua` → 控制器里构造 `data` → `jcsUI2uac(name, op, true, data)` → `/tmp/jcs.ui.srv.uac`。
2. 承载协议是 AF_UNIX 本地 JSON 报文，封装固定为 `{"name","op","clt_path","data"}`，`op` 为 `0=ADD`、`1=DEL`、`2=SET`、`3=GET`。
3. uac 的响应也是 JSON 对象。成功/失败通常用 `ret` 表示；列表类 GET 通常返回 `file_name`（uac 侧 `/tmp/...` 文件）+ `total_num`，文件内容是 JSON 数组或 CSV。
4. uac 在启动时按子系统注册回调：`jcs_callback_register(name, op, handler)`。本文的 278 行总表就是该注册表的完整恢复结果；每行都能对应到处理函数地址。
5. 277 个接口有实测样本，其中 236 个请求 `data` 非空；请求和响应原样保存在 [captures/jcs-samples.jsonl](captures/jcs-samples.jsonl)。`wips_event_detail` 在事件 ID 不存在时触发 `uac_mem_free_my` 非法释放并 SIGBUS，是唯一没有响应的接口（见 §7）。

逐接口状态、处理函数、Web 调用点、探测输入与响应见 [jcs-verification.tsv](jcs-verification.tsv)。合并 schema 有 1558 个输入字段路径。MIPS JSON getter 静态证据可按接口和字段名分类其中 1164 个路径。另有 340 个字段路径只在 Web 构造表中出现，49 个 UAC/helper 字段及 5 个数组/嵌套字段没有独立类型判定。Web 的实际 Lua 表达式见 [jcs-web-expressions.tsv](jcs-web-expressions.tsv)，getter 证据见 [jcs-types.tsv](jcs-types.tsv)。字段类型证据覆盖率不代表 AP 设置效果覆盖率。

### 0.1 Go 侧构造一次 JCS 请求

JCS 是 AF_UNIX `SOCK_DGRAM` JSON 请求，不是 Web 的 `{"method":"set","module":...}` HTTP 请求。Go 客户端给每次调用绑定唯一回包路径，再向固定服务端路径写一个完整 JSON 数据报。

```go
package main

import (
	"encoding/json"
	"fmt"
	"net"
	"os"
	"time"
)

func jcsCall(name string, op int, data json.RawMessage) ([]byte, error) {
	type jcsRequest struct {
		Name   string          `json:"name"`
		Op     int             `json:"op"`
		Client string          `json:"clt_path"`
		Data   json.RawMessage `json:"data"`
	}

	request := jcsRequest{
		Name: name,
		Op: op,
		Client: fmt.Sprintf("/tmp/jcs.ui.srv.uac%d.luaclt", os.Getpid()),
		Data: data,
	}
	payload, err := json.Marshal(request)
	if err != nil {
		return nil, err
	}

	local := &net.UnixAddr{Name: request.Client, Net: "unixgram"}
	remote := &net.UnixAddr{Name: "/tmp/jcs.ui.srv.uac", Net: "unixgram"}
	_ = os.Remove(request.Client)
	conn, err := net.ListenUnixgram("unixgram", local)
	if err != nil {
		return nil, err
	}
	defer os.Remove(request.Client)
	defer conn.Close()
	if err = conn.SetDeadline(time.Now().Add(3 * time.Second)); err != nil {
		return nil, err
	}
	if _, err = conn.WriteToUnix(payload, remote); err != nil {
		return nil, err
	}

	buf := make([]byte, 0x20000)
	n, _, err := conn.ReadFromUnix(buf)
	if err != nil {
		return nil, err
	}
	return append([]byte(nil), buf[:n]...), nil
}

func main() {
	response, err := jcsCall("ap_count", 3, json.RawMessage(`{}`))
	if err != nil {
		panic(err)
	}
	_ = response
}
```

代码展示单次调用的信封。`Op` 为 `0=ADD`、`1=DEL`、`2=SET`、`3=GET`。同一进程并发调用时需给 `Client` 加请求唯一后缀。逐项探测 `data` 在 [jcs-verification.tsv](jcs-verification.tsv) 的 `request_data_json` 列。探测值包含占位字符串、关闭状态或不存在的 ID，只验证分发和参数解析，不能当作成功配置命令。真实可用参数以模块的 Web 构造路径、正确类型和单独列出的 AP 回读结果为准。

列表 GET 还要读取响应中的 `file_name`。该路径位于 uac 的 Linux namespace，响应不会内嵌列表。Go 实现若与 uac 共处 namespace，应读取临时文件、按原格式解析，并遵循原厂调用方读取后删除文件的行为。

## 1. 证据链与抓包方法

### 1.0 浏览器到 LuCI（背景层）

浏览器侧不是直接发 JCS，而是发包含 `method`、模块名和模块内 `name`/`table` 的 JSON；`luci/controller/ds.lua` 的 `do_ds` 负责按 `method`（`get/add/delete/set/do`）分派到控制器，控制器再调用 `jcsUI2uac`。典型形状：

```json
{"method":"get","apmng_status":{"table":"ap_status","start":0,"end":63}}
```

这一层是 LuCI 的 HTTP/JSON 协议，不是 uac 的接口；本文的报文级证据都在下一层 JCS。浏览器登录与 HTTP POST 未在本轮联调中实测，HTTP 形状来自原厂打包 Lua 的静态阅读。

### 1.1 从 Web 到 JCS

原厂 LuCI 的 `ds.lua` 只负责把 HTTP JSON 分发到控制器；控制器再调用 `jcsUI2uac`。`jcs.lua` 的实现（原厂打包后的 Lua）是：

```lua
local m = { name = f, op = i, clt_path = c, data = p }
l.send(sock, '/tmp/jcs.ui.srv.uac', cjson.encode(m))
local reply = l.rcve(sock, 180)
```

其中 `c = '/tmp/jcs.ui.srv.uac' .. uds.getpid() .. '.luaclt'`。因此 `clt_path` 不是独立的客户端目录，而是「服务端路径 + PID + 固定后缀」。服务端按请求里的 `clt_path` 回包；缺这个字段就没有回包（见 §2.4）。

`op` 常量在 `jcs.lua` 中定义为：

| 值 | 名称 | 语义 |
|---:|---|---|
| 0 | `JCS_OP_TYPE_ADD` | 新建 |
| 1 | `JCS_OP_TYPE_DEL` | 删除 |
| 2 | `JCS_OP_TYPE_SET` | 修改/动作 |
| 3 | `JCS_OP_TYPE_GET` | 查询 |

### 1.2 静态恢复 278 个注册项

uac 内 `jcs_callback_register @0x005af370` 的签名是 `(const char *name, int op, handler, ...)`。全镜像中直接调用其 thunk `0x0040cee0` 的位置有 278 处。对每个调用点做一次带分支/延迟槽的数据流回放，恢复出：

- `a0`：name 字符串地址；
- `a1`：op；
- `a2`：handler 地址。

结果就是 [jcs-registry.tsv](jcs-registry.tsv) 的 278 行。处理函数名取自同镜像的 `usr/sbin/uac_symbol_fun`。
本文所有地址都取自上述镜像；仓库 `asm/` 是另一构建，函数地址不同，不能直接混用。

### 1.3 动态抓包

抓包点在原厂 Lua 客户端的 `uds.send` / `uds.rcve` 边界：用 Lua 包装这两个函数，把传给 socket 的原始 JSON 字符串原样写入 JSONL。这样记录到的就是 uac 实际收到的请求和实际发出的响应，不经过任何重新编码。

环境为 QEMU Malta + 原厂 ext4 rootfs + 原厂 `uac`，AP 通过 TAP 与 Windows/WSL 中继接入。抓包时 AP 在线，`ap_count` 返回 `online_num=1`。驱动脚本见 [tools/qemu_harness.py](../../tools/qemu_harness.py)，字段抽取脚本见 [tools/jcs_fields.py](../../tools/jcs_fields.py)，注册表恢复脚本见 [tools/jcs_registry.py](../../tools/jcs_registry.py)。

## 2. 传输与封装协议

### 2.1 端点

| 端点 | 用途 | 证据 |
|---|---|---|
| `/tmp/jcs.ui.srv.uac` | Web/LuCI → uac（本文主体） | `jcs_run @0x005af740` 用 `sprintf("%s.%s","/tmp/jcs.ui.srv",pname)` |
| `/tmp/jcs.service.srv.uac` | 进程间 service 调用 | 同一函数中 `"/tmp/jcs.service.srv"` |

Lua 客户端只导入 `socket`、`bind`、`sendto`、`recvfrom`、`select`、`unlink`（`uds.so` 动态符号表），没有 `connect/listen/accept`；抓包表现为「一次 sendto 一个完整 JSON，回包写到 `clt_path`」。uac 侧 `jcs_work_task @0x005afa54` 把请求读入 `0x20000` 字节缓冲区后解析并分发。

### 2.2 请求封装

| 字段 | 类型 | 说明 |
|---|---|---|
| `name` | string | 接口名，必须是注册表里的 name |
| `op` | int | 0/1/2/3，必须是该 name 已注册的 op |
| `clt_path` | string | 客户端回包路径；服务端按此路径回包 |
| `data` | object/array | 业务参数；GET 可为 `{}`，SET/ADD 通常为对象 |

实测原始请求（`ap_count` GET）：

```json
{"data":{},"op":3,"name":"ap_count","clt_path":"/tmp/jcs.ui.srv.uac2977.luaclt"}
```

注意 `cjson` 会把 `/` 转义为 `\/`，上面的文本是解码后的可读形式；JSONL 中保留了原始转义。

### 2.3 响应封装

响应是一个 JSON 对象。没有统一的顶层信封，约定由各 handler 自己决定，常见模式：

| 模式 | 例子 | 说明 |
|---|---|---|
| `{"ret":0,...}` | `ap_count` | `ret` 为 0 表示成功 |
| `{"file_name":"/tmp/ap_list","total_num":1}` | `apmngr_entry` GET | 列表写入 uac 的 `/tmp` 文件，调用方读文件 |
| `{"ret":1,"err_code":0}` | `sensor_test_case_list` ADD | 业务错误码在 `err_code` |
| `{}` | `wportal` GET/DEL | 空对象，调用方按无数据/成功处理 |
| `{"state":0,"fail_reason":0}` | `ac_rrm_state` | 直接返回状态字段 |

列表文件路径是 **uac 进程命名空间里的 `/tmp`**，不是宿主 `/tmp`。LuCI 在收到 `file_name` 后直接 `io.open` 读取并 `os.remove`。

另外，uac 用 cjson 编码，空数组会被写成 `{}` 而不是 `[]`。例如空 `ssid_entry` 的响应是 `{"ssid_entry":{},"total_num":0}`，调用方必须把空对象当空数组处理。

### 2.4 边界行为（实测）

| 请求 | 响应 | 服务端日志/说明 |
|---|---|---|
| 未知 name，合法 op | `{}` | `jcs_work_task()/341 No callback operation [name=...,t=...] registered.` |
| 已注册 name，op=4 | 无响应（客户端超时） | `jcs_work_task()/279 Operation wrong, op=4.` |
| 缺 `data` 字段 | 无响应 | `jcs_work_task()/267 Parse json string failed, no expected field.` |
| 非法 JSON | 无响应 | `jcs_work_task()/256 Invalid json string: ...` |
| `data` 为数组 | 正常响应 | GET handler 不关心 data 类型 |
| 缺 `clt_path` | 无响应 | 服务端没有回包地址 |

原始记录见 [captures/jcs-edge.txt](captures/jcs-edge.txt)。

### 2.5 操作码与注册分布

| op | 语义 | 注册项数 |
|---:|---|---:|
| 0 | ADD | 26 |
| 1 | DEL | 29 |
| 2 | SET | 121 |
| 3 | GET | 102 |
| 合计 | | 278 |

同一个 name 可以注册多个 op（例如 `apmngr_entry` 的 0/1/2/3），但 `(name, op)` 全局唯一；278 个注册项没有重复的 `(name, op)`。
按本文 §4 的模块划分：

| 模块 | 注册项 |
|---|---:|
| AP 管理 | 103 |
| 无线服务与射频 | 24 |
| Portal 与认证 | 24 |
| 漫游、RRM 与负载均衡 | 21 |
| Mesh | 10 |
| Sensor、WIPS 与深度体检 | 36 |
| 网络防御与交换 | 21 |
| 系统、云与统计 | 39 |
| 合计 | 278 |


## 3. 字段表怎么读

本文把字段分成三层，避免把「handler 直接读到的键」误当成完整协议：

| 文件 | 内容 | 用途 |
|---|---|---|
| [jcs-registry.tsv](jcs-registry.tsv) | 278 个 `(name,op)` 的 handler 地址、直接 `in_keys`/`out_keys`、Web 调用点 | 反汇编与分发对照 |
| [jcs-web-fields.tsv](jcs-web-fields.tsv) | 原厂 LuCI 在每个 JCS 调用点实际构造的 `data` 字段（含嵌套路径） | 证明 uac 直接键漏掉的字段 |
| [jcs-web-expressions.tsv](jcs-web-expressions.tsv) | 每个字段的 Lua 表达式、来源行号及动态接口名解析情况 | 追表单值转换与 Web-only 参数 |
| [jcs-schema.tsv](jcs-schema.tsv) | **合并后的最终字段**：uac 直接键 ∪ Web/Lua 构造字段；输出 = uac `out_keys` ∪ 实测响应键 | §4 模块表的数据源；Go 复刻按这张表 |
| [jcs-types.tsv](jcs-types.tsv) | handler/helper 的 JSON getter、静态字段类型候选与 MIPS 调用地址 | 字段类型反汇编证据 |
| [jcs-verification.tsv](jcs-verification.tsv) | 每个 `(name,op)` 的探测响应、原始 `data`、输入字段数和 AP 效果验证状态 | 逐项定位请求样本及验证层级 |
| [jcs-web-only.tsv](jcs-web-only.tsv) | 77 个接口中「Web 有、uac 直接键没有」的字段 | 证明原来只看 `in_keys` 漏了哪些字段 |
| [jcs-helper-fields.tsv](jcs-helper-fields.tsv) | 19 个接口：handler 调用本地 helper，helper 读取的额外键 | 补 `in_keys` 和 Web 都没覆盖的字段（如 `ac_roam_list` 的 28 个元素字段） |

合并统计：

| 项 | 数值 |
|---|---:|
| 注册项 | 278 |
| 至少有一个输入字段 | 237 |
| 无输入字段（含 28 个无输入 GET） | 41 |
| 输入字段总数（去重后按接口累计） | 1558 |
| 输出字段总数（去重后按接口累计） | 554 |
| Web 字段补出了 uac 直接键之外的字段的接口 | 77 |
| 实测样本 | 277（236 个请求非空） |
| 其中请求 `data` 非空 | 236 |

字段抽取方法：

1. **uac 侧**：uac 动态链接 `libjson-c.so.2`，PLT thunk 在 `0x8b9xxx`；用 ELF jump-slot relocation 把 thunk 映射到符号，再对每个 handler 做分支/延迟槽数据流回放，记录 `json_object_object_get/add` 的 `a1` 字符串。
2. **Web 侧**：用 `luaparse` 解析 77 个原厂 LuCI 控制器，在每个 `jcsUI2uac` 调用点解析第 4 个参数；表构造直接取键，局部变量按函数内赋值回放，并解析一层本地 helper 返回的 table。原始 371 个调用点、268 个 `(name,op)` 有 Web 字段。
3. **响应侧**：把实测响应 JSON 递归展开成路径，补充 handler 通过 helper 构造、未出现在 `out_keys` 里的字段。

合并后，`jcs-schema.tsv` 的 `inputs`/`outputs` 列就是 §4 表中的字段。`input_source` 列标记 `uac`/`web`/`both`/`helper`（或组合，如 `both+helper`）；`web_only_inputs` 列列出 Web 有、uac 直接键没有的字段——这些正是之前用 `{}` 时漏掉的部分。

### 3.1 数组型 `data` 与嵌套元素

`jcs-schema.tsv` 的 `inputs` 默认是根对象字段；下列接口的 `data` 本身是数组，或字段在数组元素里，用 `[]` 记号表示：

| 接口 | op | `data` 形状 | 元素/嵌套字段 |
|---|---:|---|---|
| `ac_roam_list` | 0 ADD | `data = [ { ... } ]` | `id,name,ap_ids,group_ids,switch_11k/11v/11r,roaming_threshold_type_2g/5g,rssi_trigger_threshold_2g/5g,rssi_trigger_threshold_high_performance,low_rssi_kick_2g/5g,low_rssi_threshold_2g/5g,rate_trigger_threshold_2g/5g,low_rate_kick_2g/5g,low_rate_threshold_2g/5g,threshold_check_interval,roaming_dif,blacklist_restrict_time,stats_switch,stats_interval` |
| `ac_roam_list` | 2 SET | `data = { ... }` | 同上（平铺对象，不是数组） |
| `apmngr_apdb_info` | 3 GET | `data = [ { ... } ]` | `firmware_id,model_id` |
| `ac_forward` | 3 GET | `data = { ... }` | `extend_dev_ids`、`request_id` 必须是数组；标量会让 `array_list_length` 崩溃 |
| `sensor_test_case_list` | 0/2 | `data = { service=[ { ser_name, params=[ { ... } ] } ] }` | `service[].ser_name`、`service[].params[].addr/auth_type/domain/encryption/freqband/passwd/path/port/protocol/radius_key/radius_name/radius_type/ser_index/serv_id/share_key/ssid_key/support_freqband/trans_type/url/user_name` |

`ac_roam_list` 的 28 个元素字段来自 `_wsta_roam_jcs_json_to_entry @0x004d412c` 的直接 `json_object_object_get`；这是只看 `in_keys` 完全看不到的部分。

还有几项 `data` 不是命名字段，而是编号表/数组，不能硬编成字段名：

| 接口 | op | Web 侧构造 |
|---|---:|---|
| `apmngr_firm` | 2 | `t[e]=tonumber(...)`，`data` 是 firmware/model ID 数组 |
| `apmngr_aplog` | 2 | 数字键表（日志项按索引写入） |
| `apmngr_crashdump` | 2 | 数字键表 |
| `ac_statics` | 2 | 字符串键对象（stat ID → 值） |
| `wsta_bind_info` | 1 | 数组（每条绑定信息） |

这些接口在 §4 表里可能显示空输入，是因为它们没有可命名的对象字段；请求形状应按上表，而不是 `{}`。

`wportal` 还有一组**认证事件**字段（`acctSessid`、`chapPassword1..4`、`openId`、`serialNo`、`token`、`sta_mac` 等），来自 `_wportal_jcs_add_callback`，与 Portal 配置不是同一套 schema；它们保存在 `jcs-helper-fields.tsv`，没有并入 `wportal` 的配置输入，避免把认证报文当成配置字段。

**类型说明**：`jcs-types.tsv` 中的 `string`、`number`、`boolean`、`object` 是从同版本 ELF 的 `json_object_get_*` 调用点恢复的类型候选。`type-check` 表示固件检查过 JSON 类型，不是可以传入的值类型。同一个字段出现多个 getter 时，需结合控制流、字段子操作和 Web 编码方式判定，不能把所有候选都当作可互换输入。空类型代表还需完整追踪 handler/helper 或嵌套数据结构。

## 4. 模块分述

以下每张表覆盖该模块的全部注册项。`输入字段` 是 uac 直接键与 Web/Lua 构造字段的并集，`输出字段` 是 uac 直接写出的键与实测响应键的并集；实测样本在 `captures/jcs-samples.jsonl`。表中 `Web 调用点` 只列第一个引用，完整引用见 TSV。

**空单元格不是漏填**：输入为空表示 uac handler 没读任何 JSON 键、原厂 Web 也没构造字段；其中 28 个是无输入 GET，13 个是无字段变更类/内部回调（见 §7.6）。输出为空表示实测响应是 `{}` 且 handler 没有直接 `json_object_object_add`，多数是 SET/动作类接口。


### 4.1 AP 管理


对应 Web 的 AP 状态、AP 分组、AP 升级、AP 日志/抓包、终端列表等页面（`apmng_status.lua`、`apmng_set.lua`、`apmng_upgrade.lua`、`apmng_client.lua`、`host_management.lua`）。核心语义：

- `ap_status` / `apmngr_entry` 都返回 `file_name` + `total_num`，文件内容见 §5；`ap_status_ssid`、`ap_status_radio_info` 直接返回数组/对象。
- `ap_status_evt`、`ap_telnet_status_evt`、`ap_crashdump_status_evt` 用 `entry_id` + `evt`，`evt` 的取值由 Lua 侧枚举决定（如 `reboot`、`reset`）。
- `apmngr_entry` 的 0/1/2/3 分别对应新增、删除、修改、查询；`apmngr_group_join` 把 `ap_ids` 批量加入 `group_id`。
- `apupd_*` 是升级子状态机：`apupd_model` 维护型号/批次，`apupd_wtp` 维护单 AP 升级，`apupd_status`、`apupd_upgrade_status` 查询进度。

实测 `ap_count`：

```json
请求 data: {}
响应: {"online_num":1,"ret":0,"total_num":1,"offline_num":0}
```

实测 `apmngr_entry` GET（文件 `/tmp/ap_list`）：

```json
请求 data: {}
响应: {"total_num":1,"file_name":"/tmp/ap_list"}
```


| 接口 | op | uac 处理函数 | 输入字段（Web+uac 合并） | 输出字段（uac+实测响应） | Web 调用点 |
|---|---:|---|---|---|---|
| `ap_calibrate` | 2 | `_apmngr_jcs_ap_calibrate_load` @ `0x005f5ee0` | file_name | ret | apmng_set:ap_calibrate_load |
| `ap_capture_list` | 0 | `_apmngr_jcs_ap_capture_add` @ `0x005f4c38` | ap_id, capture_type, channel_str, enable, id, rf_enable_str, rf_id_str | id, ret | apmng_set:ap_capture_list_data_add |
| `ap_capture_list` | 1 | `_apmngr_jcs_ap_capture_del` @ `0x00607e84` | id | ret | apmng_set:ap_capture_list_data_del |
| `ap_capture_list` | 2 | `_apmngr_jcs_ap_capture_set` @ `0x00608c88` | enable, id, operation | ret | apmng_set:ap_capture_list_data_set |
| `ap_capture_list` | 3 | `_apmngr_jcs_ap_capture_get` @ `0x005f55bc` | id, size, start | file_name, ret, total_num | apmng_set:ap_capture_list_data_get |
| `ap_capture_settings` | 2 | `_apmngr_jcs_ap_capture_settings_set` @ `0x005f5b60` | enable, remote_capture_port | ret | apmng_set:do_ap_capture_settings |
| `ap_count` | 3 | `_apmngr_jcs_ap_count_get` @ `0x005f414c` |  | offline_num, online_num, ret, total_num | apmng_status:get_ap_link_status |
| `ap_count_trend` | 3 | `_apmngr_jcs_ap_count_trend_get` @ `0x005f42b4` |  | ap_count_trend, ap_count_trend.offline_ap_count, ap_count_trend.online_ap_count, ap_count_trend.time, offline_ap_count, online_ap_count, ret, time | apmng_status:get_ap_count_trend |
| `ap_crashdump_status_evt` | 2 | `_apmngr_jcs_ap_crashdump_evt` @ `0x005f8228` | entry_id, evt, null |  | apmng_status:set_ap_list_data |
| `ap_exceed_status` | 3 | `_apmngr_jcs_ap_exceed_status` @ `0x005f6534` |  | status | apmng_set_status:ap_status_get |
| `ap_firmed_model` | 3 | `apupd_jcs_callback_apupd_model_list_get` @ `0x0079737c` | group_id, search_name, search_value, size, start | file_name, total_num | apmng_upgrade:get_firmed_model_list |
| `ap_log_debug_cfg_bind` | 2 | `_apmngr_jcs_ap_log_debug_cfg_bind_set` @ `0x00601e78` | ap_ids, log_config_id, status | ret | apmng_set:ap_log_config_bind_set |
| `ap_log_debug_list` | 0 | `_apmngr_jcs_ap_log_debug_list_add` @ `0x005f20ec` | debug_level, debug_switch, log_send_switch, model_str, server_ip | id, ret | apmng_set:ap_log_config_list_data_add |
| `ap_log_debug_list` | 3 | `_apmngr_jcs_ap_log_debug_list_get` @ `0x005f1b90` | ap_id | debug_level, debug_switch, file_name, log_config_id, log_send_switch, module_name_str, server_ip, total_num | apmng_set:ap_log_config_list_data_get |
| `ap_log_display_list` | 3 | `_apmngr_jcs_display_log_list_get` @ `0x005f3ac0` | ids, search_name, search_type, search_value, size, start | file_name, total_num | apmng_set:ap_log_display_list_data_get |
| `ap_log_download_list` | 0 | `_apmngr_jcs_download_log_list_add` @ `0x005f3618` | ap_id, log_file_ids | ret | apmng_set:ap_log_download_list_data_add |
| `ap_log_download_list` | 3 | `_apmngr_jcs_download_log_list_get` @ `0x005f2a68` |  | file_name, total_num | apmng_set:ap_log_download_list_data_get |
| `ap_log_download_result` | 2 | `_apmngr_jcs_log_download_result_set` @ `0x006022ac` | ap_id, log_file_id, result |  |  |
| `ap_log_download_start` | 2 | `_apmngr_jcs_log_download_start` @ `0x005f292c` |  | ret | apmng_set:ap_log_download_start |
| `ap_log_download_status` | 3 | `_apmngr_jcs_ap_log_download_status_get` @ `0x005f2578` | ap_id, log_file_fragment, log_file_id, log_file_name | download_status, ret | apmng_set:ap_log_download_status_data_get |
| `ap_log_export_cb` | 2 | `_apmngr_jcs_export_log_file_cb` @ `0x00602260` |  |  | apmng_set:ap_log_file_backup |
| `ap_log_timer_start` | 2 | `_apmngr_jcs_log_timer_start` @ `0x005f4054` |  | ret | apmng_set:ap_list_data_get |
| `ap_replace_config` | 2 | `apmngr_jcs_ap_replace_rule_load` @ `0x005f0f98` | file_name, null | ap_new, ap_replace, ret | apmng_set:ap_replace_load |
| `ap_replace_rule` | 2 | `apmngr_jcs_ap_replace_rule_set` @ `0x005f1644` | source_mac, target_mac | ret | apmng_set:ap_replace_rule_set |
| `ap_status` | 3 | `_apmngr_jcs_ap_status` @ `0x00604cf4` | ap_role, ap_status, cap_id, entry_id, entry_name, filter, freq_name, group_id, ip, led_status, link_status, mac, model_name, search_name, search_type, search_value, size, sort, sort_field, sort_type, ssid, start | file_name, total_num | apmng_status:get_ap_list_data |
| `ap_status_evt` | 2 | `_apmngr_jcs_ap_evt` @ `0x005f8888` | entry_id, evt, null |  | apmng_status:ap_reboot |
| `ap_status_radio_info` | 3 | `_apmngr_jcs_ap_radio_info` @ `0x005f0348` | entry_id | channel, freq_name, freq_unit, radio_func_type, rf_client_num, rf_entry |  |
| `ap_status_ssid` | 3 | `_apmngr_jcs_ssid` @ `0x005f7d58` | entry_id, size, start | ssid_entry, total_num | apmng_status:get_ap_ssid_list_data |
| `ap_telnet_status_evt` | 2 | `_apmngr_jcs_ap_telnet_evt` @ `0x005f8558` | entry_id, evt, null |  | apmng_status:set_ap_list_data |
| `ap_vlan_info` | 3 | `_apmngr_jcs_ap_vlan` @ `0x005f0740` | null, size, start | file_name, total_num | apmng_set:fit_ap_vlan_data_get |
| `apdb_datasync` | 2 | `_apdb_jcs_callback_datasync` @ `0x006f0638` | data_msg, len |  |  |
| `aplist_get` | 3 | `_apdb_jcs_callback_get_aplist` @ `0x006ee9ac` |  | file_name, ret | diagnose:apdb_backup |
| `apmng_backup_link` | 2 | `_multi_link_jcs_global_set` @ `0x007a4950` | backup_ip, backup_ip6, enable, priority |  |  |
| `apmngr_apdb_info` | 3 | `_apmngr_jcs_apdb_info_get` @ `0x005ff560` | [].firmware_id, [].model_id | file_name, total_num | apmng_set:apdb_info_list_get |
| `apmngr_aplog` | 2 | `_apmngr_jcs_aplog_set` @ `0x0060003c` | ac_log_level, ac_log_switch, remote_log_level, remote_report_interval, remote_server, remote_server_switch |  | apmng_set:do_aplog_setting |
| `apmngr_crashdump` | 2 | `_apmngr_jcs_crashdump_set` @ `0x005ff8a8` | enable, export_proto, gateway_ip, server_ip, server_port |  | apmng_set:do_crashdump_setting |
| `apmngr_cruise_setting` | 2 | `apmngr_jcs_cruise_setting_set` @ `0x005f0b20` | enable, scan_interval, scan_time | ret | apmng_set:do_cruise_setting |
| `apmngr_datasync` | 2 | `_apmngr_jcs_callback_datasync` @ `0x005f6230` | data_msg, len |  |  |
| `apmngr_entry` | 0 | `_apmngr_jcs_entry_add` @ `0x00602964` | account_password, account_username, ap_keep_alive, ap_mesh_switch, ap_role, ap_trunk, client_idle, client_keep_alive, crashdump_status, entry_id, entry_name, entry_type, firmware_id, fit_fat_button_status, group_id, hardware_ver, lag_mode, lag_phy_list, lag_phy_num, led, led_close_date, led_close_time, led_open_date, led_open_time, led_timer_enable, led_wifi_sync, mac, model_id, new_ap_trunk, offline_selfmanage, password, phy_wire_vlan_list, rf_change_enable, rf_mode, status, telnet_status, username | ap_too_many, entry_id | apmng_set:ap_list_data_add |
| `apmngr_entry` | 1 | `_apmngr_jcs_entry_del` @ `0x005fbaf4` | ap, ap_tmp, null, template |  | apmng_set:ap_list_data_del |
| `apmngr_entry` | 2 | `_apmngr_jcs_entry_set` @ `0x005fd1fc` | ap_keep_alive, ap_mesh_switch, ap_trunk, cap_id, client_idle, client_keep_alive, cloud_config_id, crashdump_status, entry_id, entry_name, entry_type, errno, fit_fat_button_status, lag_mode, lag_phy_list, lag_phy_num, led, led_close_date, led_close_time, led_open_date, led_open_time, led_timer_enable, led_wifi_sync, mac, model_id, multi_id_list, multi_ids, new_ap_trunk, offline_selfmanage, password, phy_wire_vlan_list, region_code, replace_mac, rf_change_enable, rf_mode, software_ver, telnet_status, username | capa_multi_list, ret, type_multi_list | apmng_set:D |
| `apmngr_entry` | 3 | `_apmngr_jcs_entry_get` @ `0x006060d4` | ap_role, condition, entry_type, filters, group_id, search_name, search_value, size, sort, sort_field, sort_type, start | file_name, total_num | apmng_set:ap_list_data_get |
| `apmngr_entry_authorize` | 2 | `_apmngr_jcs_entry_set_authorize` @ `0x005fa838` | entry_id, operation |  | apmng_set:authorize_ap_set |
| `apmngr_entry_authorize` | 3 | `_apmngr_jcs_entry_authorize_get` @ `0x00602590` | size, start | file_name, total_num | apmng_set:authorize_ap_list_get |
| `apmngr_entry_backup` | 3 | `_apmngr_jcs_entry_backup` @ `0x005f0170` |  | file_name | apmng_set:ap_backup |
| `apmngr_entry_copy` | 2 | `_apmngr_jcs_entry_copy` @ `0x005fab60` | ap_ids, copy_ap_id, entry_id, replace | ret, success_id_list | apmng_set:ap_list_data_copy |
| `apmngr_firm` | 2 | `_apmngr_jcs_firm` @ `0x005fa5b4` | [] | succ | apmng_set:C |
| `apmngr_global` | 2 | `_apmngr_jcs_global_set` @ `0x006005a0` | apmngr_status, auto_firm, auto_reboot, reboot_day, reboot_time |  | apmng_set:do_settings |
| `apmngr_group` | 0 | `_apmngr_jcs_group_add` @ `0x005f74bc` | end_ip, entry_name, group_id, name, specific_strategy, start_ip, strategy_enable |  | apmng_set:V |
| `apmngr_group` | 1 | `_apmngr_jcs_group_del` @ `0x005f6588` | group_id | group_id | apmng_set:group_list_data_del |
| `apmngr_group` | 2 | `_apmngr_jcs_group_set` @ `0x005f67dc` | end_ip, group_id, name, specific_strategy, start_ip, strategy_enable |  | apmng_set:group_list_data_set |
| `apmngr_group_join` | 2 | `_apmngr_jcs_group_join` @ `0x005f6cf4` | ap_ids, group_id, null, template_ids |  | apmng_set:D |
| `apmngr_online_model` | 3 | `_apmngr_jcs_online_ap_model_get` @ `0x005f8c94` | group_id, search_name, search_value, size, start | file_name, total_num | apmng_status:get_online_model_list_data |
| `apmngr_status_backup` | 3 | `_apmngr_jcs_ap_status_backup` @ `0x005eff64` |  | file_name, ret | apmng_status:ap_status_backup |
| `apupd_check_allow_update` | 3 | `apupd_jcs_callback_check_allow_update` @ `0x00796d84` | model_id, upgrade_type | allow_update | apmng_upgrade:check_allow_update |
| `apupd_config` | 2 | `apupd_jcs_callack_apupd_config_set` @ `0x0079a510` | state | ret |  |
| `apupd_group_delete` | 2 | `apupd_jcs_callback_ap_group_delete` @ `0x00796f9c` | group_id |  | apmng_upgrade:remove_group_in_batch_list_item |
| `apupd_image_check` | 3 | `apupd_jcs_callback_apupd_image_check` @ `0x00799048` | file_size | ret | apmng_upgrade:check_image_import |
| `apupd_large_image_status` | 2 | `apupd_jcs_large_image_status_set` @ `0x0079d988` | mac, model_id | ret | apmng_upgrade:set_apupd_large_image_status |
| `apupd_large_image_status` | 3 | `apupd_jcs_large_image_status_get` @ `0x00796a34` | mac, model_id | can_down_sub_image, ret, sub_image_num | apmng_upgrade:get_apupd_large_image_status |
| `apupd_log` | 1 | `apupd_jcs_callback_apupd_log_del` @ `0x0079c7a0` | model_id | ret | apmng_upgrade:fail_log_clear |
| `apupd_log` | 3 | `apupd_jcs_callback_apupd_log_get` @ `0x00798a64` | ap_role, model_id, size, start | file_name, logs_num, model_id, ret | apmng_upgrade:get_fail_log_data |
| `apupd_model` | 0 | `apupd_jcs_callback_apupd_models_add` @ `0x007a0a34` | ap_list, group_id, is_large_fw, is_sys, model_id, total_image_piece, total_image_size, total_md5, upgrade_date, upgrade_datetime_type, upgrade_start_time, upgrade_type | file_name, ret | apmng_upgrade:add_batch_ap_list_data |
| `apupd_model` | 1 | `apupd_jcs_callback_apupd_models_del` @ `0x007996ec` | model_id | ret | apmng_upgrade:del_batch_ap_list_data |
| `apupd_model` | 2 | `apupd_jcs_callback_apupd_models_set` @ `0x0079fb9c` | auto_to_manual, model_id, upgrade_date, upgrade_datetime_type, upgrade_start_time, upgrade_type | file_name, ret | apmng_upgrade:set_batch_ap_list_data |
| `apupd_model` | 3 | `apupd_jcs_callback_apupd_models_get` @ `0x0079ca50` | is_mesh_device, model_id, product_type, size, start, status, upgrade_type | file_name, ret, totalNum | apmng_upgrade:get_batch_ap_list_data |
| `apupd_status` | 3 | `apupd_jcs_callback_apupd_status_get` @ `0x00798964` |  | ret, status | apmng_upgrade:get_upgrade_status |
| `apupd_upgrade_status` | 3 | `apupd_jcs_callback_ap_upgrade_status` @ `0x0079715c` | entry_ids | ap_upgrade_status | apmng_set:k |
| `apupd_wtp` | 2 | `apupd_jcs_callback_apupd_set_for_ap` @ `0x0079ebfc` | is_large_fw, mac, total_image_piece, total_image_size, total_md5, upgrade_type | file_name, percent, ret | apmng_upgrade:get_single_upgrade_status |
| `apupd_wtp` | 3 | `apupd_jcs_callback_apupd_wtp_get` @ `0x00797c58` | ap_role, group_id, mac, model_id, size, start, state | file_name, model_id, ret, wtp_num | apmng_upgrade:get_ap_list_data |
| `bluetooth_network_rule_list` | 0 | `bluetooth_jcs_callback_rule_add` @ `0x0061d49c` | ap_ids, broadcast_channel_set, broadcast_deduplicate_enable, broadcast_filter_data_type, broadcast_filter_enable, broadcast_filter_match_data, broadcast_filter_match_method, group_ids, gw_work_mode, id, mode, name, operation_password, operation_username, rssi_deduplicate_enable, rssi_threshold, server_id | id, ret | apmng_bluetooth_set:bluetooth_rule_list_add |
| `bluetooth_network_rule_list` | 1 | `bluetooth_jcs_callback_rule_del` @ `0x0061c064` | id | ret | apmng_bluetooth_set:bluetooth_rule_list_del |
| `bluetooth_network_rule_list` | 2 | `bluetooth_jcs_callback_rule_set` @ `0x0061e0fc` | ap_ids, broadcast_channel_set, broadcast_deduplicate_enable, broadcast_filter_data_type, broadcast_filter_enable, broadcast_filter_match_data, broadcast_filter_match_method, group_ids, gw_work_mode, id, mode, name, operation_password, operation_username, rssi_deduplicate_enable, rssi_threshold, server_id | ret | apmng_bluetooth_set:bluetooth_rule_list_set |
| `bluetooth_network_rule_list` | 3 | `bluetooth_jcs_callback_rule_get` @ `0x0061e420` | id, name, size, start | bluetooth_network_rule_list, count, result, ret | apmng_bluetooth_set:bluetooth_rule_list_get |
| `client_rssi_data` | 3 | `_uac_wsta_jcs_client_rssi_data_get` @ `0x00763078` | duration | client_rssi_data, rssi_45_0, rssi_55_45, rssi_65_55, rssi_72, rssi_72_65, time | apmng_client:get_client_rssi_data |
| `ftp_server_list` | 0 | `ftp_jcs_callback_ftp_config_rule_entry_add` @ `0x00628f78` | ap_ids, group_ids, rule_id, user_name, user_password | ret, rule_id | apmng_ftp:ftp_server_list_add |
| `ftp_server_list` | 1 | `ftp_jcs_callback_ftp_config_rule_entry_del` @ `0x00626e10` | rule_id | ret | apmng_ftp:ftp_server_list_del |
| `ftp_server_list` | 2 | `ftp_jcs_callback_ftp_config_rule_entry_set` @ `0x00628284` | ap_ids, group_ids, rule_id, user_name, user_password | ret | apmng_ftp:ftp_server_list_set |
| `ftp_server_list` | 3 | `ftp_jcs_callback_ftp_config_rule_entry_get` @ `0x00628bc4` | size, start | count, ftp_server_list | apmng_ftp:ftp_server_list_get |
| `ftp_status_list` | 3 | `ftp_jcs_callback_ftp_status_get` @ `0x006265f0` | rule_id | count, ftp_status_list, ret | apmng_ftp:ftp_status_list_get |
| `host_info` | 3 | `_uac_wsta_jcs_host_info_get` @ `0x007698b0` | ap_role, auth_type, bind_enable, data_type, mac, mac_array, mac_count, operation_type, search_name, search_type, search_value, select_filter, size, sort, sort_field, sort_type, start | file_name, total_num | host_management:host_info_data_get |
| `host_info_back` | 3 | `_uac_wsta_host_info_jcs_backup` @ `0x00762e10` |  | file_name | host_management:host_info_backup |
| `iot_server_list` | 0 | `bluetooth_jcs_callback_iot_server_add` @ `0x0061b33c` | ca_file_path, client_id, id, is_encrypt, password, protocol, server_addr, server_port, server_type, topic_comment, topic_data_type, topic_detail, topic_feature, username | id, ret | apmng_bluetooth_set:iot_server_list_add |
| `iot_server_list` | 1 | `bluetooth_jcs_callback_iot_server_del` @ `0x0061a6d0` | id | ret | apmng_bluetooth_set:iot_server_list_del |
| `iot_server_list` | 2 | `bluetooth_jcs_callback_iot_server_set` @ `0x0061b4e4` | ca_file_path, client_id, id, is_encrypt, password, protocol, server_addr, server_port, server_type, topic_comment, topic_data_type, topic_detail, topic_feature, username | ret | apmng_bluetooth_set:iot_server_list_set |
| `iot_server_list` | 3 | `bluetooth_jcs_callback_iot_server_get` @ `0x0061b7e4` | id | count, iot_server_list, ret | apmng_bluetooth_set:iot_server_list_get |
| `unsupport_ap_get` | 3 | `_apdb_jcs_callback_get_unsupport_ap` @ `0x006f077c` |  | ret | apmng_set_status:unknown_ap_list_get |
| `wsta_bind_info` | 0 | `_uac_wsta_bind_info_jcs_add` @ `0x0077a30c` | bind_enable, bind_radio_id, down_limit, force_bind_enable, mac, time_obj, up_limit | result, sqldata | host_management:j |
| `wsta_bind_info` | 1 | `_uac_wsta_bind_info_jcs_del` @ `0x00779af4` | mac | result, sqldata | host_management:host_info_data_del |
| `wsta_bind_info` | 2 | `_uac_wsta_bind_info_jcs_set` @ `0x00778b34` | bind_enable, bind_radio_id, down_limit, force_bind_enable, mac, time_obj, up_limit | result, sqldata | host_management:c |
| `wsta_bind_info_net_rule` | 2 | `_uac_wsta_bind_info_net_rule_jcs_set` @ `0x007775d8` | enable, mac | result | host_management:host_info_time_out_handle |
| `wsta_iso_group` | 0 | `_uac_wsta_jcs_iso_group_add` @ `0x00761a74` | enable, group_ids, id, isolate_type, isolation_switch, name, ssid_list, white_list | id, name, ret | host_management:isolate_rule_list_add |
| `wsta_iso_group` | 1 | `_uac_wsta_jcs_iso_group_del` @ `0x007607d4` | id | ret | host_management:isolate_rule_list_del |
| `wsta_iso_group` | 2 | `_uac_wsta_jcs_iso_group_set` @ `0x00761640` | enable, group_ids, id, isolate_type, isolation_switch, name, ssid_list, white_list | ret | host_management:isolate_rule_list_set |
| `wsta_iso_group` | 3 | `_uac_wsta_jcs_iso_group_get` @ `0x0075fae8` | id, name, size, start | file_name, total_num | host_management:isolate_rule_list_get |
| `wstation` | 1 | `_uac_wsta_jcs_del` @ `0x0075f8f0` | entry_id, mac | entry_id | apmng_client:client_list_data_del |
| `wstation` | 2 | `_uac_wsta_jcs_set` @ `0x00763a84` | overload_threshold |  | event_report:handle_nms_report_event_cfg_changed |
| `wstation` | 3 | `_uac_wsta_jcs_get` @ `0x00765530` | ap_role, auth_type, bind_enable, filter, filter.auth_type, freq_name, group_id, search_name, search_value, size, sort, sort_field, sort_type, start | all_num, file_name, total_num | apmng_client:client_list_data_get |
| `wstation_backup` | 3 | `_uac_wsta_jcs_backup` @ `0x0075e6cc` |  | file_name | apmng_client:backup_wstation_client |
| `wstation_disconnect` | 2 | `_uac_wsta_jcs_disconnect` @ `0x0075f41c` | mac |  | host_management:do_disconnect |
| `wstation_mac` | 1 | `_uac_wsta_jcs_del_by_mac` @ `0x0075f6b4` | entry_id, mac | ret | apmng_client:client_list_data_del |
| `wstation_peer_mac` | 3 | `_uac_wsta_jcs_peer_mac_get_by_mld` @ `0x007637c4` | mac | peer_mac, ret |  |
| `wstation_recognize` | 2 | `_uac_wsta_jcs_recognize_set` @ `0x00762440` | brand, operating_system, prohibit_access_switch |  | host_management:do_settings |


### 4.2 无线服务与射频


对应 Web 的「无线服务」「射频绑定」「VLAN Pool」「射频设置」「EDCA 规则」等页面（`apmng_wserv.lua`、`apmng_rf.lua`）。核心语义：

- `wservice` 是 WLAN 服务的总入口。ADD 返回 `serv_id`；SET 的 `operation` 选择子操作：`0=编辑`、`1=绑定射频`、`2=解绑射频`、`3=批量启用`、`4=批量停用`；GET 必填 `serv_id`，返回 `file_name`/`total_num` 或空对象；DEL 每次一个 `serv_id`。
  按 `operation` 拆开的字段表在 [jcs-wservice-ops.tsv](jcs-wservice-ops.tsv)：`0` 编辑是 43 个全量字段；`1` 绑定是 `serv_id,radio_id,vlan_id`（`vlan_id` 必填且与 `radio_id` 等长）；`2` 解绑是 `serv_id,radio_id`；`3/4` 启停只有 `serv_id`。原厂 Lua 的局部常量 `O=0,J=1,K=2,Y=3,x=4` 已写进表里。
- 新建字段见 `_uac_wserv_jcs_add` 的 `in_keys`：`ssid`、`ssid_code_type`、`desc`、`enable`、`ssidbrd`、`isolate`、`auto_bind`、`default_bind_freq`、`default_bind_vlan`、`encryption`、`auth`、`cipher`、`key_update_intv`、`key`、`bw_ctrl_*`、`igmp_*`、`mlo_switch` 等。
- `wserv_global` 是 IGMP/全局开关；`wservice_ip` 是组播地址表；`vlan_pool` 是 VLAN Pool；`rf_mngr` 是射频模板/绑定；`edca_rule` 是 EDCA 规则。
- WLAN 配置最终由 `_uac_wserv_packet_send_callback @0x006dbd74` 组装成 CAPWAP `0x0033DD01`，字段偏移与 PSK 位置见 [README.md](README.md#capwap-明文与汇编)。

`wservice` SET 的字段与 ADD 基本同集，但共享解析函数 `_uac_wserv_jcs_modify` 里读取，静态直接键只显示 `operation`；实际编辑时仍按 ADD 的字段名传。实测 `wservice` GET（空 data、无 `serv_id`）返回 `{}`，服务端日志 `serv_id not found!`；真实 `qiyitt` 新建的请求/响应见 [README.md](README.md#wlan-服务与射频绑定)。


| 接口 | op | uac 处理函数 | 输入字段（Web+uac 合并） | 输出字段（uac+实测响应） | Web 调用点 |
|---|---:|---|---|---|---|
| `backup_rf_mngr_entry` | 3 | `_uac_rdmngr_jcs_backup` @ `0x00713178` |  | file_name | apmng_rf:backup_rf |
| `edca_config` | 3 | `_rdmngr_jcs_get_edca_config` @ `0x007135b0` | ap_id, rf_id, size, start | file_name, total_num | apmng_rf:get_edca_scence_spe |
| `edca_rule` | 0 | `edca_rule_jcs_add` @ `0x00711fb0` | ap_be_aifs, ap_be_cwmax, ap_be_cwmin, ap_be_txop, ap_bk_aifs, ap_bk_cwmax, ap_bk_cwmin, ap_bk_txop, ap_id, ap_vi_aifs, ap_vi_cwmax, ap_vi_cwmin, ap_vi_txop, ap_vo_aifs, ap_vo_cwmax, ap_vo_cwmin, ap_vo_txop, edca_enable, edca_mode, edca_rule_id, edca_rule_name, freq_map, group_id, reset_edca_default, sta_be_aifs, sta_be_cwmax, sta_be_cwmin, sta_be_txop, sta_bk_aifs, sta_bk_cwmax, sta_bk_cwmin, sta_bk_txop, sta_vi_aifs, sta_vi_cwmax, sta_vi_cwmin, sta_vi_txop, sta_vo_aifs, sta_vo_cwmax, sta_vo_cwmin, sta_vo_txop, static_edca_type, wmm | edca_rule_id, edca_rule_name, ret | apmng_rf:add_edca_rule |
| `edca_rule` | 1 | `edca_rule_jcs_del` @ `0x00710cc0` | ids | ret | apmng_rf:delete_edca_rule |
| `edca_rule` | 2 | `edca_rule_jcs_set` @ `0x007129b4` | ap_be_aifs, ap_be_cwmax, ap_be_cwmin, ap_be_txop, ap_bk_aifs, ap_bk_cwmax, ap_bk_cwmin, ap_bk_txop, ap_id, ap_vi_aifs, ap_vi_cwmax, ap_vi_cwmin, ap_vi_txop, ap_vo_aifs, ap_vo_cwmax, ap_vo_cwmin, ap_vo_txop, edca_enable, edca_mode, edca_rule_id, edca_rule_name, freq_map, group_id, reset_edca_default, sta_be_aifs, sta_be_cwmax, sta_be_cwmin, sta_be_txop, sta_bk_aifs, sta_bk_cwmax, sta_bk_cwmin, sta_bk_txop, sta_vi_aifs, sta_vi_cwmax, sta_vi_cwmin, sta_vi_txop, sta_vo_aifs, sta_vo_cwmax, sta_vo_cwmin, sta_vo_txop, static_edca_type, wmm | edca_rule_id, edca_rule_name, ret | apmng_rf:set_edca_rule |
| `edca_rule` | 3 | `edca_rule_jcs_get` @ `0x007122d8` | edca_rule_name, ids, size, start | file_name, total_num | apmng_rf:get_edca_rule |
| `jcs_radio_mode_entry` | 3 | `_radio_mode_spec_cap_get` @ `0x007102c0` | ap_ids, filter, firmware_id, model_id, size, start | file_name, total_num | apmng_rf:get_raio_mode_spe |
| `rf_mngr` | 2 | `_uac_rdmngr_jcs_set` @ `0x007207f4` | airtime, antenna, ap_be_aifs, ap_be_cwmax, ap_be_cwmin, ap_be_txop, ap_bk_aifs, ap_bk_cwmax, ap_bk_cwmin, ap_bk_txop, ap_vi_aifs, ap_vi_cwmax, ap_vi_cwmin, ap_vi_txop, ap_vo_aifs, ap_vo_cwmax, ap_vo_cwmin, ap_vo_txop, bandwidth, bcn_intvl, brd_probe, channel, downlink_mumimo, downlink_ofdma, dtim_prd, edca_enable, edca_mode, enable_6g, enable_6g_psc, force_modify, frag_thr, freq_band, gi_mode, manage_frame_rate, max_usr, mode, multi_id_list, mutex_channel, operation, power_level, rail_high_speed_mode_switch, reject_diff, reject_enable, reject_limit, reset_edca_default, rf_check_circle, rf_chnl_dcs, rf_chnl_occup_threshold, rf_chnl_reselect, rf_chnl_tolerance, rf_name, rf_online_switch, rf_state, rssi_kick, rssi_kick_val, rssi_restrict, rssi_restrict_val, rts_thr, short_gi, sta_be_aifs, sta_be_cwmax, sta_be_cwmin, sta_be_txop, sta_bk_aifs, sta_bk_cwmax, sta_bk_cwmin, sta_bk_txop, sta_vi_aifs, sta_vi_cwmax, sta_vi_cwmin, sta_vi_txop, sta_vo_aifs, sta_vo_cwmax, sta_vo_cwmin, sta_vo_txop, static_edca_type, twt, uplink_mumimo, uplink_ofdma, wmm | result | apmng_rf:handle_cloud_cfg_to_local_event |
| `rf_mngr` | 3 | `_uac_rdmngr_jcs_get` @ `0x00719600` | ap_role, ap_status, group_id, search_cond, search_name, search_value, size, start | file_name, total_num | apmng_rf:get_multi_rf |
| `rf_mngr_entry` | 3 | `_uac_rdmngr_jcs_get_entry` @ `0x00718ed4` | rf_id | rd_entry, ret |  |
| `rf_mngr_template_export` | 3 | `_rdmngr_jcs_rf_template_export` @ `0x00712f0c` |  | file_name, ret | apmng_rf:rf_template_export |
| `vlan_id_str_check` | 3 | `_uac_wserv_vlan_id_str_check` @ `0x006e79cc` | id, vlan_id_str | ret | apmng_wserv:wserv_check_vlan_pool_id_str |
| `vlan_pool` | 0 | `_uac_wserv_vlan_pool_jcs_add` @ `0x006e7d04` | id, name, vlan_id_str | ret | apmng_wserv:add_vlan_pool_entry |
| `vlan_pool` | 1 | `_uac_wserv_vlan_pool_jcs_del` @ `0x006d1c44` | id | ret | apmng_wserv:del_vlan_pool_entry |
| `vlan_pool` | 2 | `_uac_wserv_vlan_pool_jcs_set` @ `0x006e85f8` | id, name, vlan_id_str | ret | apmng_wserv:set_vlan_pool_entry |
| `vlan_pool_del_check` | 3 | `_uac_wserv_vlan_pool_del_check` @ `0x006d198c` | id | ret | apmng_wserv:wserv_check_vlan_pool_del |
| `wserv_global` | 2 | `_uac_wserv_jcs_global_set` @ `0x006d4428` | igmp_2g_rate, igmp_2g_rate_type, igmp_5g_rate, igmp_5g_rate_type, igmp_drop_unknown, igmp_max_resp_time, igmp_multi_to_unicast, igmp_query_interval, igmp_snooping_enable, is_set_snp |  |  |
| `wservice` | 0 | `_uac_wserv_jcs_add` @ `0x006e3970` | auth, auto_bind, bw_ctrl_enable, bw_ctrl_mode, central_forward_switch, cipher, default_bind_freq, default_bind_vlan, desc, down_limit, enable, encryption, igmp_2g_rate, igmp_2g_rate_type, igmp_5g_rate, igmp_5g_rate_type, igmp_drop_unknown, igmp_max_resp_time, igmp_multi_to_unicast, igmp_query_interval, igmp_query_switch, igmp_snooping_enable, igmp_snooping_switch, isolate, key, key_update_intv, mlo_switch, ppsk_group, radius_acct_port, radius_auth_channel, radius_ip, radius_nas_id, radius_port, radius_pwd, radius_session_timeout, radius_vlan_enable, serv_id, ssid, ssid_code_type, ssid_id, ssidbrd, time_switch, up_limit | serv_id | apmng_wserv:add_wserv_list_data |
| `wservice` | 1 | `_uac_wserv_jcs_del` @ `0x006e3590` | serv_id | serv_id | apmng_wserv:del_wserv_list_data |
| `wservice` | 2 | `_uac_wserv_jcs_set` @ `0x006e2fd4` | auth, auto_bind, bw_ctrl_enable, bw_ctrl_mode, central_forward_switch, cipher, default_bind_freq, default_bind_vlan, desc, down_limit, enable, encryption, igmp_2g_rate, igmp_2g_rate_type, igmp_5g_rate, igmp_5g_rate_type, igmp_drop_unknown, igmp_max_resp_time, igmp_multi_to_unicast, igmp_query_interval, igmp_query_switch, igmp_snooping_enable, igmp_snooping_switch, isolate, key, key_update_intv, mlo_switch, operation, ppsk_group, radio_id, radius_acct_port, radius_auth_channel, radius_ip, radius_nas_id, radius_port, radius_pwd, radius_session_timeout, radius_vlan_enable, serv_id, ssid, ssid_code_type, ssid_id, ssidbrd, time_switch, up_limit, vlan_id | serv_id | apmng_wserv:R |
| `wservice` | 3 | `_uac_wserv_jcs_get` @ `0x006d5670` | group_id, limit, offset, radio_id, search_cond, search_name, search_value, serv_id | file_name, total_num | apmng_wserv:get_rf_bind_list_data |
| `wservice_ip` | 0 | `_uac_wserv_ip_jcs_add` @ `0x006e6e4c` | enable, id, ip_addr, relay | id | apmng_wserv:add_igmp_ip_list |
| `wservice_ip` | 1 | `_uac_wserv_ip_jcs_del` @ `0x006e6ac0` | id | result | apmng_wserv:delete_igmp_ip_list |
| `wservice_ip` | 2 | `_uac_wserv_ip_jcs_set` @ `0x006e616c` | enable, id, ip_addr, is_set_enable, relay | id, result | apmng_wserv:g |


### 4.3 Portal 与认证


对应 Web 的「认证配置」「Portal 页面」「Radius/LDAP 服务器」「MAC 黑白名单」「认证用户」等页面（`portal_auth.lua`、`authentication.lua`、`radius.lua`、`ldap.lua`、`macauth.lua`、`macauth_group.lua`）。核心语义：

- `wportal` 是**多态接口**：`type` 选择 Portal、Radius、LDAP、免认证策略、CMCC、NSA 等子对象；ADD/DEL/SET/GET 的字段集合是各子对象字段的并集，调用方必须带正确的 `type` 和该类型的必填字段。
`wportal` 的 `type` 取值来自原厂 Lua 的 `WPORTAL_JCS_*` 常量，按 `op` 复用同一批数字。主要分组：

| `type` | 子对象/动作 |
|---:|---|
| 1 | Portal 页面（ADD/DEL/SET/GET） |
| 2 | 免认证策略 |
| 3 | 认证用户 |
| 4 | 无感知认证（NSA） |
| 5 | Portal 端口 |
| 7–10 | 按 mode_id / username 删除认证用户或 NSA |
| 11–17 | 老化时间/开关、CMCC 端口、HTTPS 开关 |
| 200–202 | RADIUS 服务器 |
| 300–323 | CMCC 登出、页面 SSID、绑定列表、流负载、在线查询、VLAN 检查 |
| 400–402 | 认证模式、SSO 配置、默认 Portal 页面开关 |
| 600–609 | 接口维度的认证用户/NSA/提醒/流/失败结果变体 |
| 700–701 | 认证失败结果、删除全部资源 |
| 800–802 | LDAP 服务器 |

精确常量名与数值见原厂 Lua 的 `WPORTAL_JCS_*`；uac 侧在 `_wportal_jcs_add/del/set/get_callback` 内按 `type` 分派。

按 `(op, type)` 拆开的字段表在 [jcs-wportal-types.tsv](jcs-wportal-types.tsv)：共 26 组，25 组已解析到常量数值，每组列出 `calls`、`fields` 和 Web 调用点。`free_auth_strategy.lua` 里的局部变量 `I=2`、`p=2` 已按 `WPORTAL_JCS_ADD_FREESTRATEGY`/`DEL_FREESTRATEGY` 归一化。唯一未解析的是 `sessmngr.lua` 的 `NGINX_STATUS_GET_AUTH_USER`（数值 400），它是 nginx 认证用户查询的跨进程状态码，字段为 `search/search_arg/size/sort/start`，与 `WPORTAL_JCS_SET_AUTH_MODE=400` 不是同一语义；表中保留原名，避免猜成 Portal 配置。


- `wportal_user_data` 返回某客户端的认证能力集合（`client_auth_data` 内含 `web/onekey/wechat/sms/remote/cloud/cmcc/mac_auth/no_auth/qrcode` 等子对象）。
- `macauth_group` / `macauth_group_for_ssid` 维护 MAC 认证组；`macauth_mac` 维护 MAC 条目；`macauth_type` 设置认证模式；`macauth_vlan_str_check` 校验 VLAN 字符串。
- `wportal_backup`、`nsa_user_backup` 返回 CSV 文件（`authedUser.csv`、`nonSentientExport.csv`）。

实测 `macauth_group` ADD（空 data）返回 `{"id":-1}`；`wportal` GET（空 data）返回 `{}`；`wportal_user_data` GET 返回：

```json
{"client_auth_data":[{"web":{},"remote":{},"cloud":{},"mac_auth":{},"qrcode":{},"time":0,"no_auth":{},"cmcc":{},"wechat":{},"onekey":{},"sms":{}}]}
```


| 接口 | op | uac 处理函数 | 输入字段（Web+uac 合并） | 输出字段（uac+实测响应） | Web 调用点 |
|---|---:|---|---|---|---|
| `macauth_blacklist` | 3 | `_uac_mac_auth_global_backlist_jcs_get` @ `0x0049fc64` |  | id, result | host_management:T |
| `macauth_group` | 0 | `_uac_mac_auth_group_jcs_add` @ `0x004a2a2c` | auth_type, bind_vlan_type, enable, id, mac_id_map, name, note, old_serv_id_map, old_ssid, old_vlan, operation, serv_id_map, type, vlan, vlan_pool_id | id | mac_group:mac_auth_list_add |
| `macauth_group` | 1 | `_uac_mac_auth_group_jcs_del` @ `0x004a2554` | id, vlan | id |  |
| `macauth_group` | 2 | `_uac_mac_auth_group_jcs_set` @ `0x004a43f4` | auth_type, bind_vlan_type, enable, id, mac_id_map, name, note, old_serv_id_map, old_ssid, old_vlan, operation, serv_id_map, type, vlan, vlan_pool_id | result | mac_group:mac_auth_list_set |
| `macauth_group` | 3 | `_uac_mac_auth_group_jcs_get` @ `0x0049f6c8` | type | ret | mac_group:mac_auth_list_add |
| `macauth_group_for_ssid` | 0 | `_uac_mac_auth_group_jcs_add_for_ssid` @ `0x004a0d90` | auth_type, bind_vlan_type, enable, id, mac_id_map, name, note, old_serv_id_map, old_ssid, old_vlan, operation, serv_id_map, type, vlan, vlan_pool_id | id | mac_group:mac_auth_list_add |
| `macauth_group_for_ssid` | 1 | `_uac_mac_auth_group_jcs_del_for_ssid` @ `0x004a09c4` | id, name, serv_id_map, type, value | id | mac_group:del_mac_group_bind_ssid_by_serv_id |
| `macauth_group_for_ssid` | 2 | `_uac_mac_auth_group_jcs_set_for_ssid` @ `0x004a4228` | auth_type, bind_vlan_type, enable, id, mac_id_map, name, note, old_serv_id_map, old_ssid, old_vlan, operation, serv_id_map, type, vlan, vlan_pool_id | result | mac_group:mac_auth_list_set |
| `macauth_mac` | 0 | `_uac_mac_auth_mac_jcs_add` @ `0x0049f988` | id, mac, name | id, result | mac_auth:mac_addr_list_add |
| `macauth_mac` | 1 | `_uac_mac_auth_mac_jcs_del` @ `0x004a3c44` | id | id | mac_auth:mac_addr_list_del |
| `macauth_mac` | 2 | `_uac_mac_auth_mac_jcs_set` @ `0x004a38a0` | id, mac, name | id | mac_auth:mac_addr_list_set |
| `macauth_mac` | 3 | `_uac_mac_auth_mac_jcs_get` @ `0x0049e470` |  |  |  |
| `macauth_mac_for_group` | 1 | `_uac_mac_auth_mac_jcs_del_for_group` @ `0x004a361c` | id | ret | mac_auth:mac_addr_list_del |
| `macauth_type` | 2 | `_uac_mac_auth_auth_type_jcs_set` @ `0x0049ecb8` | auth_mode, type | result | mac_group:set_auth_mode |
| `macauth_vlan_str_check` | 3 | `_uac_mac_auth_vlan_id_str_check` @ `0x0049e7f4` | id, vlan_id_str | ret | mac_group:mac_group_check_vlan_pool_id_str |
| `notify_unbind` | 2 | `cloud_mngt_jcs_notify_unbind` @ `0x004fd34c` |  | cloud_status, method, notify_unbind | apmng_set:handle_cloud_unbind |
| `nsa_user_backup` | 3 | `wportal_jcs_non_sentient_export_callback` @ `0x00415558` |  | file_name, ret | nonsense:backup_nsa_user |
| `wportal` | 0 | `_wportal_jcs_add_callback` @ `0x004388b0` | account_port, admin_dn, admin_passwd, auth_port, auth_type, base_dn, cloud_portal_url, cmcc_ac_name, cmcc_auth_server_type, cmcc_mac_auth, cmcc_url, datasync_data_type, datasync_op_type, dst_ip, dst_ip_mask, dst_port_end, dst_port_start, entry_id, fail_id, fail_url, id, index, match_type, method, name, nas_identifier, nas_ip, portal_page_switch, protocol, radius_auth_type, remote_mac_auth, remote_url, retry_count, retry_interval, serv_id, server_addr, server_name, session_timeout, share_key, src_ip, src_ip_mask, src_mac, src_port_end, src_port_start, src_vlan, type, url, user_filter, user_passwd_filter, vlan_id | ret | free_auth_strategy:d |
| `wportal` | 1 | `_wportal_jcs_del_callback` @ `0x004328ac` | auth_mode, auth_type, bas_identifier, change, cmccServerIp, count, del_mode, del_user, entry_id, free_auth_id, index, interface, ip, key, mac, match_type, method, name, portal_port, serialNo, serv_id, sso_enable, sso_port, sso_server, sso_type, type, useChap, username, version, vlan_id | count, filename, mac, type | free_auth_strategy:I |
| `wportal` | 2 | `_wportal_jcs_set_callback` @ `0x0043683c` | account_port, admin_dn, admin_passwd, age_enable, age_time, ageing_enable, ageing_time, auth_mode, auth_port, auth_type, auto, base_dn, cloud_portal_url, cmcc_ac_name, cmcc_auth_server_type, cmcc_mac_auth, cmcc_port, cmcc_portal_port, cmcc_url, del_mode, entry_id, fail_id, fail_url, https_enable, id, index, key, method, nas_identifier, nas_ip, old_vlan_id, portal_page_switch, portal_port, radius_auth_type, remote_mac_auth, remote_url, retry_count, retry_interval, serv_id, server_addr, server_name, session_timeout, share_key, sso_config, sso_enable, sso_port, sso_server, sso_type, type, user_filter, user_passwd_filter, value, vlan_id | ret | ldap:set_ldap |
| `wportal` | 3 | `_wportal_jcs_get_callback` @ `0x0041c7d8` | ip, mac, portal_id, search, search_arg, search_arg.auth_type, search_arg.search_name, search_arg.search_value, search_arg.value_type, search_arg.write_to_file, serv_id, size, sort, start, type, vlan | file_name, is_online, mac, ret, totalNum | nonsense:get_nonsense |
| `wportal_backup` | 3 | `wportal_jcs_backup_callback` @ `0x0041572c` |  | file_name | sessmngr:backup_authed_user |
| `wportal_nsa_sync` | 2 | `wportal_jcs_nsa_sync_callback` @ `0x0041a530` |  |  |  |
| `wportal_user_data` | 3 | `_wportal_jcs_client_auth_data_get_callback` @ `0x0041356c` | duration | client_auth_data, cloud, cmcc, mac_auth, no_auth, onekey, qrcode, remote, sms, time, web, wechat | portal_auth:get_portal_user_data |


### 4.4 漫游、RRM 与负载均衡


对应 Web 的「智能漫游」「射频调优」「负载均衡」页面（`apmng_roam.lua`、`apmng_rrm.lua`、`apmng_balance.lua`）。核心语义：

- `ac_roam` 设置漫游参数；`ac_roam_list` 是漫游规则表（0/1/2/3）；`roam_wireless_network_mode` 设置无线网络模式；`roam_exist_unsupport_ap` 查询不支持漫游的 AP。
- `ac_rrmpara` 设置 RRM 参数；`ac_rrm_state` 查询 RRM 状态；`ac_rrm_list` 是 RRM 规则表；`ac_manualrrm` 触发手动调优；`ac_autorrm_list` 是自动调优列表。
- `ac_balance` 是负载均衡规则表；`apmng_band_navigation` 是频谱导航。
- 列表类 GET 仍返回 `file_name` + `total_num`；状态类 GET 直接返回 `state`/`fail_reason`。

实测 `ac_roam_list` GET：`{"result":0,"total_num":0,"file_name":"/tmp/roam_list_get"}`；`ac_rrm_state` GET：`{"state":0,"fail_reason":0}`。


| 接口 | op | uac 处理函数 | 输入字段（Web+uac 合并） | 输出字段（uac+实测响应） | Web 调用点 |
|---|---:|---|---|---|---|
| `ac_autorrm_list` | 2 | `rrm_ops_jcs_auto_rrm_set` @ `0x00525bf4` | id | ret | apmng_rrm:set_autorrm_list |
| `ac_balance` | 0 | `balance_jcs_callback_balance_add` @ `0x004ee97c` | ap_ids, dif_threshold, enable, group_ids, id, index_field, max_fail_num, mode, name, rssi_threshold, usr_threshold | id, ret | apmng_balance:balance_rule_list_add |
| `ac_balance` | 1 | `balance_jcs_callback_balance_del` @ `0x004ee73c` | id | ret | apmng_balance:balance_rule_list_del |
| `ac_balance` | 2 | `balance_jcs_callback_balance_set` @ `0x004eeb58` | ap_ids, dif_threshold, enable, group_ids, id, index_field, max_fail_num, mode, name, rssi_threshold, usr_threshold | ret | apmng_balance:balance_rule_list_set |
| `ac_balance` | 3 | `balance_jcs_callback_balance_get` @ `0x004ec470` | id, index_field, name, size, start | file_name, total_num | apmng_balance:balance_rule_list_get |
| `ac_manualrrm` | 2 | `rrm_ops_jcs_manual_rrm_set` @ `0x00525838` | ap_ids, autorrm_enable, autorrm_timeobj, bw_2g, bw_5g, chnl_2g_set, chnl_5g1_set, chnl_enable, freq_enable, group_ids, id, index_field, max_pwr_2g, max_pwr_5g, min_pwr_2g, min_pwr_5g, name, pwr_enable, pwr_threshold_2g, pwr_threshold_5g, setting_id | ret | apmng_rrm:set_manualrrm |
| `ac_roam` | 2 | `_wsta_roam_jcs_intelligent_set` @ `0x004d6e50` | ap_ids, blacklist_restrict_time, group_ids, id, low_rate_kick_2g, low_rate_kick_5g, low_rate_threshold_2g, low_rate_threshold_5g, low_rssi_kick_2g, low_rssi_kick_5g, low_rssi_threshold_2g, low_rssi_threshold_5g, name, rate_trigger_threshold_2g, rate_trigger_threshold_5g, roaming_dif, roaming_threshold_type_2g, roaming_threshold_type_5g, rssi_trigger_threshold_2g, rssi_trigger_threshold_5g, rssi_trigger_threshold_high_performance, stats_interval, stats_switch, switch_11k, switch_11r, switch_11v, threshold_check_interval | group_ids, name, result | apmng_roam:do_settings |
| `ac_roam_list` | 0 | `_wsta_roam_jcs_roam_list_add` @ `0x004d5734` | [].ap_ids, [].blacklist_restrict_time, [].group_ids, [].id, [].low_rate_kick_2g, [].low_rate_kick_5g, [].low_rate_threshold_2g, [].low_rate_threshold_5g, [].low_rssi_kick_2g, [].low_rssi_kick_5g, [].low_rssi_threshold_2g, [].low_rssi_threshold_5g, [].name, [].rate_trigger_threshold_2g, [].rate_trigger_threshold_5g, [].roaming_dif, [].roaming_threshold_type_2g, [].roaming_threshold_type_5g, [].rssi_trigger_threshold_2g, [].rssi_trigger_threshold_5g, [].rssi_trigger_threshold_high_performance, [].stats_interval, [].stats_switch, [].switch_11k, [].switch_11r, [].switch_11v, [].threshold_check_interval | id, result | apmng_roam:roam_list_add |
| `ac_roam_list` | 1 | `_wsta_roam_jcs_roam_list_del` @ `0x004d3c44` | id | id, result | apmng_roam:roam_list_del |
| `ac_roam_list` | 2 | `_wsta_roam_jcs_roam_list_set` @ `0x004d7c30` | ap_ids, blacklist_restrict_time, group_ids, id, low_rate_kick_2g, low_rate_kick_5g, low_rate_threshold_2g, low_rate_threshold_5g, low_rssi_kick_2g, low_rssi_kick_5g, low_rssi_threshold_2g, low_rssi_threshold_5g, name, rate_trigger_threshold_2g, rate_trigger_threshold_5g, roaming_dif, roaming_threshold_type_2g, roaming_threshold_type_5g, rssi_trigger_threshold_2g, rssi_trigger_threshold_5g, rssi_trigger_threshold_high_performance, stats_interval, stats_switch, switch_11k, switch_11r, switch_11v, threshold_check_interval | result | apmng_roam:roam_list_set |
| `ac_roam_list` | 3 | `_wsta_roam_jcs_roam_list_get` @ `0x004d66ac` | end, id, index_field, name, start | file_name, result, total_num | apmng_roam:default_roam_get |
| `ac_rrm_list` | 0 | `rrm_ops_jcs_rrm_para_list_add` @ `0x00524268` | ap_ids, autorrm_enable, autorrm_timeobj, bw_2g, bw_5g, chnl_2g_set, chnl_5g1_set, chnl_enable, freq_enable, group_ids, id, index_field, max_pwr_2g, max_pwr_5g, min_pwr_2g, min_pwr_5g, name, pwr_enable, pwr_threshold_2g, pwr_threshold_5g | id, name, ret | apmng_rrm:rrm_setting_list_add |
| `ac_rrm_list` | 1 | `rrm_ops_jcs_rrm_para_list_del` @ `0x005249c8` | id | ret | apmng_rrm:rrm_setting_list_del |
| `ac_rrm_list` | 2 | `rrm_ops_jcs_rrm_para_list_set` @ `0x005245f8` | ap_ids, autorrm_enable, autorrm_timeobj, bw_2g, bw_5g, chnl_2g_set, chnl_5g1_set, chnl_enable, freq_enable, group_ids, id, index_field, max_pwr_2g, max_pwr_5g, min_pwr_2g, min_pwr_5g, name, pwr_enable, pwr_threshold_2g, pwr_threshold_5g | ret | apmng_rrm:rrm_setting_list_set |
| `ac_rrm_list` | 3 | `rrm_ops_jcs_rrm_para_list_get` @ `0x00524c24` | id, index_field, name, size, start | file_name, total_num | apmng_rrm:rrm_setting_list_get |
| `ac_rrm_state` | 3 | `rrm_ops_jcs_rrm_state_get` @ `0x00521188` |  | fail_reason, state | apmng_rrm:radio_or_wserv_cfg_set_check |
| `ac_rrmpara` | 2 | `rrm_ops_jcs_rrm_para_set` @ `0x00521288` | autorrm_date, autorrm_enable, autorrm_time, bw_2g, bw_5g, chnl_2g_set, chnl_5g1_set, chnl_enable, freq_enable, group_id_str, pwr_enable, pwr_max_pwr, pwr_min_pwr, pwr_threshold | ret | apmng_rrm:before_settings |
| `apmng_band_navigation` | 2 | `band_navigation_jcs_set` @ `0x00633610` | 5g_threshold, dif_threshold, enable, max_fail_num |  | apmng_band_navigation:do_settings |
| `roam_exist_unsupport_ap` | 3 | `_wsta_roam_jcs_exist_unsupport_ap` @ `0x004d3890` | exist_unsupport_wireless_network_mode_ap | exist_unsupport_ap | apmng_roam:exist_unsupport_wireless_network_mode_ap |
| `roam_wireless_network_mode` | 2 | `_wsta_roam_jcs_intelligent_wireless_network_set` @ `0x004d3b5c` | wireless_network_mode | result |  |
| `roam_wireless_network_mode` | 3 | `_wsta_roam_jcs_intelligent_wireless_network_get` @ `0x004d3a94` | wireless_network_mode | real_mode, result | apmng_roam:get_real_wireless_network_mode |


### 4.5 Mesh


对应 Web 的 Mesh 组网/拓扑页面（`apmng_mesh.lua`）。核心语义：

- `ac_mesh_trigger_pair` / `ac_mesh_trigger_pair_all` 触发配对；`ac_mesh_stop_discover` 停止发现；`ac_mesh_trigger_discover` 开始发现；`ac_mesh_discover_cap_change` 处理能力变化。
- `ac_mesh_discover_status`、`ac_mesh_discover_list`、`ac_mesh_topology` 查询发现状态/列表/拓扑；`ac_mesh_global_settings` 设置全局参数；`ac_mesh_wan_status` 设置 WAN 状态。
- 本环境无 Mesh 设备，GET 多返回 `{}` 或空列表；字段仍由静态表给出。

实测 `ac_mesh_topology` GET 返回 `{}`。


| 接口 | op | uac 处理函数 | 输入字段（Web+uac 合并） | 输出字段（uac+实测响应） | Web 调用点 |
|---|---:|---|---|---|---|
| `ac_mesh_discover_cap_change` | 2 | `mesh_jcs_discover_cap_change` @ `0x00537714` | cap_id, mac | ret | apmng_mesh:select_mesh_ap |
| `ac_mesh_discover_list` | 3 | `mesh_jcs_discover_list_get` @ `0x00538d98` | size, start | file_name, total_num | apmng_mesh:unfirmed_ap_list_get |
| `ac_mesh_discover_status` | 3 | `mesh_jcs_discover_status_get` @ `0x005389d8` |  | auto_add_status, status | apmng_mesh:scan_new_device_status_get |
| `ac_mesh_global_settings` | 2 | `mesh_jcs_global_set` @ `0x0053a11c` | backhaul_key, backhaul_ssid, backhaul_token, bh_work_mode, enable, re_auto_switch, re_recover_flag, web_password |  | apmng_mesh:do_settings |
| `ac_mesh_stop_discover` | 2 | `mesh_jcs_stop_discover` @ `0x0053a0c0` |  | ret | apmng_mesh:scan_new_device |
| `ac_mesh_topology` | 3 | `mesh_jcs_topology_get` @ `0x00538b48` |  | file_name, total_num | apmng_mesh:re_node_list_get |
| `ac_mesh_trigger_discover` | 2 | `mesh_jcs_trigger_discover` @ `0x00539df8` |  | ret | apmng_mesh:scan_new_device |
| `ac_mesh_trigger_pair` | 2 | `mesh_jcs_trigger_pair` @ `0x00536908` | cap_id, dev_info, mac | ret | apmng_mesh:add_mesh_ap |
| `ac_mesh_trigger_pair_all` | 2 | `mesh_jcs_trigger_pair_all` @ `0x00537400` |  | ret | apmng_mesh:add_all_mesh_ap |
| `ac_mesh_wan_status` | 2 | `mesh_jcs_wan_status_set` @ `0x00536420` | wan_status | ret |  |


### 4.6 Sensor、WIPS 与深度体检


对应 Web 的「Sensor 管理」「Sensor 测试」「无线安全」「深度体检」页面（`apmng_sensor.lua`）。核心语义：

- `sensor_global` 设置 Sensor 全局开关；`sensor_discover_trigger` 触发发现；`sensor_list_added`、`sensor_manage_status` 查询 Sensor 列表/状态。
- `sensor_test_case_list` 0/1/2 分别新增/删除/修改测试用例；`sensor_test_*` 查询测试结果/摘要/详情；`sensor_test_group_delete_event_handle`、`sensor_test_wserv_delete_event_handle` 是删除联动事件。
- `wips_event_info` 查询 WIPS 事件列表（`file_name` + `count`）；`wips_event_detail` 查询单个事件；`wips_statistics`、`wips_statistics_num` 查询统计；`whitelist` 维护白名单。
- `deep_inspection_*`、`deep_checkup_*`、`get/set_deep_inspection_*` 是信道占用、RSSI、瀑布图、密度、报文明细等深度体检接口。

`sensor_test_case_list` 的 ADD/SET 大量字段在 `service`/`ssid_info` 子对象里，静态直接键只显示顶层 `join_test_sensor`；完整字段见 §7.2 和 Lua `add_sensor_test_case`。实测 `wips_event_info` GET：`{"ret":0,"count":0,"file_name":"/tmp/wips_info_tmp_file"}`。`wips_event_detail` 在没有有效事件 ID 时会使 uac SIGBUS（§7.1）；`sensor_test_case_list` ADD 的最小有效请求见 §7.2。


| 接口 | op | uac 处理函数 | 输入字段（Web+uac 合并） | 输出字段（uac+实测响应） | Web 调用点 |
|---|---:|---|---|---|---|
| `deep_checkup_pkt_bssid_list` | 3 | `jcs_deep_checkup_pkt_bssid_list` @ `0x00561f24` | end, start | bssid, bssid_list_cnt, deep_checkup_pkt_bssid_list, file_name, frame, percent, ret, ssid_id, subframe_a, subframe_p | apmng_sensor:get_deep_checkup_pkt_bssid_list |
| `deep_checkup_pkt_ssid_list` | 3 | `jcs_deep_checkup_pkt_ssid_list` @ `0x0055d9a8` | chnl, entry_id | deep_checkup_pkt_ssid_list, file_name, name, percent, ret, ssid_id | apmng_sensor:get_deep_checkup_pkt_ssid_list |
| `deep_checkup_pkt_sta_list` | 3 | `jcs_deep_checkup_pkt_sta_list` @ `0x005613e0` | end, start | bssid, deep_checkup_pkt_sta_list, file_name, frame, percent, ret, sta_list_cnt, sta_mac, subframe_a, subframe_p | apmng_sensor:get_deep_checkup_pkt_sta_list |
| `deep_inspection_chnl_usage_list` | 3 | `jcs_deep_inspection_chnl_usage_list` @ `0x0055f954` | entry_id | ap_num, chnl, deep_inspection_chnl_usage_list, free_util, non_wifi_util, ret, ssid_num, sta_num, wifi_util | apmng_sensor:get_deep_inspection_chnl_usage_list |
| `deep_inspection_multi_chnl_density` | 3 | `jcs_deep_inspection_multi_chnl_density` @ `0x0055ed9c` | entry_id | deep_inspection_multi_chnl_density, density, end, file_name, length, ret, spectrums, start | apmng_sensor:get_deep_inspection_freq_density |
| `deep_inspection_multi_chnl_rssi` | 3 | `jcs_deep_inspection_multi_chnl_rssi` @ `0x00560860` | entry_id | band_width, bssid, center_chnl, deep_inspection_multi_chnl_rssi, file_name, primary_chnl, ret, rssi, ssid | apmng_sensor:get_deep_inspection_multi_chnl_rssi |
| `deep_inspection_multi_chnl_waterfall` | 3 | `jcs_deep_inspection_multi_chnl_waterfall` @ `0x0055e3d4` | end, entry_id, start | deep_inspection_multi_chnl_waterfall, end, file_name, length, ret, spectrums, start, time, waterfall_cnt | apmng_sensor:get_deep_inspection_freq_waterfall |
| `deep_inspection_selected_chnl_usage` | 3 | `jcs_deep_inspection_selected_chnl_usage` @ `0x0055f4c8` | chnl, entry_id | deep_inspection_selected_chnl_usage, non_wifi_util, ret, time, wifi_util | apmng_sensor:get_deep_inspection_selected_chnl_usage |
| `deep_inspection_status` | 3 | `jcs_deep_inspection_status` @ `0x0055d3bc` |  | cur_viewed_sensor, inspection_remain_time, inspection_status, last_inspection_time, off_line_sensor, ret | apmng_sensor:deep_inspection_status |
| `get_deep_inspection_scan_mode_change` | 3 | `jcs_get_deep_inspection_sensor_scan_mode_change` @ `0x0055e044` | entry_id | chnl, deep_inspection_scan_mode_change, ret, scan_mode | apmng_sensor:get_deep_inspection_scan_mode_change |
| `get_deep_inspection_setting` | 3 | `jcs_get_deep_inspection_setting` @ `0x00562a4c` |  | chnl, deep_inspection_setting, entry_id, entry_name, inspection_band, inspection_item, ret, scan_mode | apmng_sensor:get_deep_inspection_setting |
| `sensor_discover_trigger` | 2 | `_sensor_jcs_discover_trigger` @ `0x0058579c` | action | ret | apmng_sensor:sensor_discover_trigger |
| `sensor_global` | 2 | `_sensor_jcs_global_set` @ `0x00581c78` | backhaul_enable, backhaul_encode, backhaul_key, backhaul_ssid, backhaul_ssidbrd, backhaul_wserv_id, enable, force_set, wserv_cfg_change | ret | apmng_sensor:before_settings |
| `sensor_list_added` | 3 | `_sensor_jcs_sensor_list_added_get` @ `0x00582348` | end, start | ap_id, file_name, group_id, mac, model_name, name, ret, test_status, total_num | apmng_sensor:sensor_list_added_get |
| `sensor_manage_status` | 3 | `_sensor_jcs_sensor_manage_status_get` @ `0x0057e570` |  | remain_time, ret, status | apmng_sensor:sensor_manage_status_get |
| `sensor_test_case_list` | 0 | `jcs_sensor_test_add_test_case` @ `0x00552324` | change_id, group_id, join_test_sensor, rssi_threshold, sch_period, sch_time, sch_type, service, service[].params[].addr, service[].params[].auth_type, service[].params[].domain, service[].params[].encryption, service[].params[].freqband, service[].params[].passwd, service[].params[].path, service[].params[].port, service[].params[].protocol, service[].params[].radius_key, service[].params[].radius_name, service[].params[].radius_type, service[].params[].ser_index, service[].params[].serv_id, service[].params[].share_key, service[].params[].ssid_key, service[].params[].support_freqband, service[].params[].trans_type, service[].params[].url, service[].params[].user_name, service[].ser_name, ssid_info, test_case_name | err_code, ret | apmng_sensor:add_sensor_test_case |
| `sensor_test_case_list` | 1 | `jcs_sensor_test_del_test_case` @ `0x00552804` | test_case_id | err_code, ret | apmng_sensor:del_sensor_test_case |
| `sensor_test_case_list` | 2 | `jcs_sensor_test_set_test_case` @ `0x00551bb4` | change_id, group_id, join_test_sensor, rssi_threshold, sch_period, sch_time, sch_type, service, service[].params[].addr, service[].params[].auth_type, service[].params[].domain, service[].params[].encryption, service[].params[].freqband, service[].params[].passwd, service[].params[].path, service[].params[].port, service[].params[].protocol, service[].params[].radius_key, service[].params[].radius_name, service[].params[].radius_type, service[].params[].ser_index, service[].params[].serv_id, service[].params[].share_key, service[].params[].ssid_key, service[].params[].support_freqband, service[].params[].trans_type, service[].params[].url, service[].params[].user_name, service[].ser_name, ssid_info, test_case_id, test_case_name | err_code, ret | apmng_sensor:set_sensor_test_case |
| `sensor_test_detail_result` | 3 | `jcs_sensor_test_get_detail_result` @ `0x0054cdb4` | bssid, ser_index, test_case_id, test_type | data, details, diagnosis, file_name, ret, stage, startTime, test, time | apmng_sensor:get_sensor_test_detail_result |
| `sensor_test_digest` | 3 | `jcs_sensor_test_get_digest` @ `0x00542e94` |  | fail_cnt, offline_sensor_cnt, ret, sensor_cnt, slow_cnt, success_cnt, total_test_cnt | apmng_sensor:get_sensor_test_digest |
| `sensor_test_group_delete_event_handle` | 2 | `jcs_sensor_test_group_delete_event_handle` @ `0x00548494` | group_id |  | apmng_sensor:group_delete_event_sensor_test_handle |
| `sensor_test_result` | 3 | `jcs_sensor_test_get_simple_result` @ `0x0054a890` | end, result, sch_start_time, sensor_name, ser_index, start, test_case_id, test_type | ap_name, bssid, down_speed, fail_stage, file_name, freq_type, reason, relay, result, ret, rssi, sensor_name, ser_index, snr, ssid_name, start_time, test_case_id, test_type, total_num, up_speed | apmng_sensor:get_sensor_test_result |
| `sensor_test_ssid_list` | 3 | `jcs_sensor_test_get_ssid_list` @ `0x005498a0` | end, group_list, rssi_threshold, sensor_list, start | encryption, file_name, freqband, ret, serv_id, ssid_code_type, ssid_name, total_num | apmng_sensor:get_sensor_test_ssid_list |
| `sensor_test_summary` | 3 | `jcs_sensor_test_get_summary_result` @ `0x00543514` | ser_index, test_case_id, test_type | brief_result, brief_result_list, ret, sch_start_time, sensor_test_summary, ser_index, test_case_id, test_type | apmng_sensor:get_sensor_test_summary |
| `sensor_test_summary_new` | 3 | `jcs_sensor_test_get_summary_result_new` @ `0x00543dec` | test_case_id | fail_cnt, file_name, result, ret, sch_start_time, sensor_test_summary_new, slow_cnt, success_cnt, test_case_id, test_type, test_type_summary, total_num | apmng_sensor:get_sensor_test_summary_new |
| `sensor_test_wserv_delete_event_handle` | 2 | `jcs_sensor_test_wserv_delete_event_handle` @ `0x0054fff4` | serv_id |  | apmng_sensor:wserv_delete_event_sensor_test_handle |
| `set_deep_inspection_scan_mode_change` | 2 | `jcs_deep_inspection_sensor_scan_mode_change` @ `0x0056746c` | chnl, entry_id, scan_mode | ret | apmng_sensor:set_deep_inspection_scan_mode_change |
| `set_deep_inspection_setting` | 2 | `jcs_deep_inspection_setting` @ `0x00567d60` | deep_inspection_set, entry_id, inspection_band, inspection_item, switch, use_previous_setting | err_code, ret | apmng_sensor:set_deep_inspection_setting |
| `whitelist` | 0 | `wips_jcs_callback_whitelist_add` @ `0x00559cd4` | mac, ssid, ssid_encode | ret | apmng_sensor:add_whitelist_data |
| `whitelist` | 1 | `wips_jcs_callback_whitelist_delete` @ `0x00558d0c` | whitelist_ids | ret | apmng_sensor:del_whitelist_data |
| `whitelist` | 3 | `wips_jcs_callback_whitelist_get` @ `0x00555c24` | size, start | count, result, ret | apmng_sensor:get_whitelist |
| `wips_event_detail` | 3 | `wips_jcs_callback_wips_event_detail_get` @ `0x005548fc` | size, start, wips_info_id | count, result | apmng_sensor:get_wips_detail |
| `wips_event_info` | 2 | `wips_jcs_callback_wips_event_info_set` @ `0x00559fd4` | operation, wips_info_ids | ret | apmng_sensor:wips_add_to_whitelist |
| `wips_event_info` | 3 | `wips_jcs_callback_wips_event_info_get` @ `0x00557284` | entry_name, size, start, wips_info_id, wips_threat_classname, wips_threat_level | count, file_name, ret | apmng_sensor:get_wips_info |
| `wips_statistics` | 3 | `wips_jcs_callback_statistics_get` @ `0x00553cb8` | type | end_ts, entry_name, group_name, normal_event_count, num, result, ret, severe_event_count, slight_event_count, start_ts, total | apmng_sensor:_get_wips_statistics_date |
| `wips_statistics_num` | 3 | `wips_jcs_callback_statistics_num_get` @ `0x005531b8` |  | dos_attack_num, illegal_dev_num, interfering_dev_num, threat_dev_num | apmng_sensor:get_wips_statistics_num |


### 4.7 网络防御与交换


对应 Web 的「ARP/ND 防护」「DHCP 防护」「广播风暴抑制」「LLDP」「端口设置」页面（`apmng_arpdefend.lua`、`apmng_dhcpdefend.lua`、`apmng_bcast_storm_ctrl.lua`、`lldp.lua`、`portSetting`）。核心语义：

- `arp_defend_setting` 设置全局防护；`arp_defend_ap` 查询/设置 AP 防护；`arp_defend_arp` 是 ARP/ND 条目表（0/1/2/3）；`arp_defend_do_scan` 触发扫描；`arp_defend_scan` 查询扫描结果。
- `dhcpdef_svr` 是 DHCP 服务器表；`dhcpdef_apbind`、`dhcpdef_apbind_svr` 是 AP 绑定关系；`bcast_storm_ctrl` 设置风暴抑制；`uac_lldp` 设置/查询 LLDP；`port_list` 设置/查询端口。
- 列表类 GET 返回 `file_name`；状态类返回 `ret`。

实测 `arp_defend_ap` GET：`{"total_num":1,"file_name":"/tmp/arp_defend_ap_get"}`。


| 接口 | op | uac 处理函数 | 输入字段（Web+uac 合并） | 输出字段（uac+实测响应） | Web 调用点 |
|---|---:|---|---|---|---|
| `arp_defend_ap` | 2 | `_uac_arp_defend_ap_jcs_set` @ `0x004c8258` | ap_id, arp_id, operation | enable, result | apmng_arpdefend:N |
| `arp_defend_ap` | 3 | `_uac_arp_defend_ap_jcs_get` @ `0x004c6a48` | group_id, limit, offset, search_name, search_type, search_value | file_name, total_num | apmng_arpdefend:get_ap_list |
| `arp_defend_arp` | 0 | `_uac_arp_defend_arp_jcs_add` @ `0x004c58b8` | arp_id, description, ip, is_scan_add, mac | arp_list_data_exceed, id | apmng_arpdefend:add_arp_list_data |
| `arp_defend_arp` | 1 | `_uac_arp_defend_arp_jcs_del` @ `0x004c754c` | arp_id | file_name, succ_num | apmng_arpdefend:del_arp_list_data |
| `arp_defend_arp` | 2 | `_uac_arp_defend_arp_jcs_set` @ `0x004c52d0` | arp_id, description, ip, mac | result | apmng_arpdefend:set_arp_list_data |
| `arp_defend_arp` | 3 | `_uac_arp_defend_arp_jcs_get` @ `0x004c4c90` |  |  |  |
| `arp_defend_do_scan` | 2 | `_uac_arp_defend_scan_jcs_set` @ `0x004c7dd8` | group_id_str | ret | apmng_arpdefend:set_arp_scan |
| `arp_defend_scan` | 3 | `_uac_arp_defend_scan_jcs_get` @ `0x004c6470` | limit, offset, search_name, search_value | file_name, total_num | apmng_arpdefend:get_arp_scan_list |
| `arp_defend_setting` | 2 | `_uac_arp_defend_setting_jcs_set` @ `0x004c4fe0` | defend_mode, wired_port_switch, wireless_port_switch |  | apmng_arpdefend:do_settings |
| `bcast_storm_ctrl` | 2 | `_uac_bcast_storm_ctrl_jcs_set` @ `0x004ade5c` | arp_limit_type, arp_proxy_switch, arp_proxy_to_unicast_switch, arp_proxy_type, arp_rate_limit, dhcp_limit_type, dhcp_rate_limit, dhcpv6_limit_type, dhcpv6_rate_limit, enable, icmpv6_ns_limit_type, icmpv6_ns_rate_limit, icmpv6_rs_limit_type, icmpv6_rs_rate_limit, igmp_limit_type, igmp_rate_limit, mdns_proxy_switch, mdns_proxy_to_unicast_switch, nd_proxy_switch, nd_proxy_to_unicast_switch, nd_proxy_type, other_broadcast_limit_type, other_broadcast_rate_limit, other_multicast_limit_type, other_multicast_rate_limit, proto_list, storm_rate |  | apmng_bcast_storm_ctrl:apply_settings |
| `dhcpdef_apbind` | 2 | `_uac_dhcpdef_jcs_set_bind_entries` @ `0x004b6d6c` | ap_id, operation | result | apmng_dhcp_defense:clear_apbind_list |
| `dhcpdef_apbind` | 3 | `_uac_dhcpdef_jcs_get_bind_entries` @ `0x004b46c0` | group_id, limit, offset, search_name, search_type, search_value | file_name, total_num | apmng_dhcp_defense:get_ap_list |
| `dhcpdef_apbind_svr` | 2 | `_uac_dhcpdef_jcs_set_bind_svrs` @ `0x004b7558` | ap_id, operation, svr_id | bind_exceed, result | apmng_dhcp_defense:set_apbind_list |
| `dhcpdef_apbind_svr` | 3 | `_uac_dhcpdef_jcs_get_bind_svrs` @ `0x004b3234` | ap_id, limit, offset, search_name, search_value | file_name, total_num |  |
| `dhcpdef_svr` | 0 | `_uac_dhcpdef_jcs_svr_add` @ `0x004b56a8` | addr_type, name, svr_addr, svr_id | svr_id | apmng_dhcp_defense:add_dhcp_filter |
| `dhcpdef_svr` | 1 | `_uac_dhcpdef_jcs_svr_del` @ `0x004b6374` | svr_id | file_name, succ_num | apmng_dhcp_defense:del_dhcp_filter |
| `dhcpdef_svr` | 2 | `_uac_dhcpdef_jcs_svr_set` @ `0x004b5528` | addr_type, name, operation, svr_addr, svr_id | svr_id | apmng_dhcp_defense:set_dhcp_filter |
| `port_list` | 2 | `_apmngr_jcs_ap_port_info_list_set` @ `0x005ee3f8` | ap_id_array, ap_mac_array, count, enable, port_id_array, pvid | ret | apmng_set:port_list_data_set |
| `port_list` | 3 | `_apmngr_jcs_ap_port_info_list_get` @ `0x005ef2a8` | ap_id, ap_mac, id | ap_id, duplex, enable, file_name, id, port_media, port_name, port_pos, port_position, port_speed_max, port_state, port_status_type, port_type, pvid, ret, speed, total_num | apmng_set:port_list_data_get |
| `uac_lldp` | 2 | `_uac_lldp_jcs_set` @ `0x0051b400` | is_first |  | lldp:get_lldp_info |
| `uac_lldp` | 3 | `_uac_lldp_jcs_get` @ `0x0051af90` | is_first | cnt, continue, get_lldp_info | lldp:get_lldp_info |


### 4.8 系统、云与统计


对应 Web 的云管理、时间设置、系统状态、上报、诊断、USB 等页面（`cloud_mngt.lua`、`system.lua`、`diagnose.lua`、`usbSettings`）。核心语义：

- `cloud_mngt_*`、`ac_alias_changed`、`ac_config_id_changed`、`ac_datasync_status`、`ac_notify_master_sync_data`、`ap_set_token`/`ap_update_token` 是云平台/主从同步/令牌回调；多数是内部服务接口，Web 只间接触发。
- `ac_report`、`client_report_switch`、`ap_report_switch`、`local_nms_switch`、`report_debug_switch_set`、`uac_nms_report_switch`、`start_report_sub_device_info` 控制上报开关。
- `systime` 设置系统时间；`target_ap` 查询/设置目标 AP；`tdcp_passthrough`、`send_tdcp_test` 是 TDCP 透传/测试；`udbg` 是调试开关；`usb_settings` 是 USB 配置；`ac_rate` 是 AC 速率设置。
- `host_info`、`host_info_back` 是终端信息列表/导出。

实测 `systime` SET（空 data）返回 `{"ret":1}`（缺少 `10001004` UCI section）；`ac_report` SET 返回 `{"ret":true}`。


| 接口 | op | uac 处理函数 | 输入字段（Web+uac 合并） | 输出字段（uac+实测响应） | Web 调用点 |
|---|---:|---|---|---|---|
| `ac_alias_changed` | 2 | `cloud_mngt_jcs_alias_changed` @ `0x00500b80` |  |  | cloud:handle_system_alias_event |
| `ac_audit` | 2 | `_audit_client_jcs_set_cb` @ `0x00587a00` | enable, remote_ip |  | apmng_audit:do_settings |
| `ac_clear_all_cloud_config_id` | 2 | `_apmngr_jcs_ac_clear_all_cloud_config_id` @ `0x005ebcb8` |  |  |  |
| `ac_config_id_changed` | 2 | `cloud_mngt_jcs_config_id_changed` @ `0x004fded4` | new_config_id |  | cloud:handle_config_id_event |
| `ac_datasync_status` | 2 | `_apmngr_jcs_ac_datasync_status_set` @ `0x005f6394` | status |  |  |
| `ac_forward` | 2 | `_ac_forward_jcs_set` @ `0x0058daa0` | content, extend_dev_id, requests | request_id, ret | forward:handle_forward |
| `ac_forward` | 3 | `_ac_forward_jcs_get` @ `0x0058f0ac` | device_type, extend_dev_ids, request_id | cnt, get_rsponse_info | forward:handle_forward |
| `ac_notify_master_sync_data` | 2 | `_apmngr_jcs_ac_nitify_master_sync_data_set` @ `0x005f6388` |  |  |  |
| `ac_passthrough` | 2 | `_ac_passthrough_jcs_set` @ `0x0058d10c` | ap_mac, apmng_passthrough, filepath, get_rsponse_info_sync, need_result, params, passthrough_to_subdevice, requestData, request_id, request_info | request_id, ret | apmng_passthrough:handle_apmng_passthrough |
| `ac_passthrough` | 3 | `_ac_passthrough_jcs_get` @ `0x0058eaa0` | ap_mac, filepath, get_rsponse_info_sync, need_result, request_id, request_info | cnt, continue, get_rsponse_info | apmng_passthrough:handle_apmng_passthrough |
| `ac_rate` | 2 | `jcs_callback_rate_set` @ `0x0062fdf0` | 11a_base, 11a_mult, 11a_supp, 11ac_base, 11ac_supp, 11ax_base, 11ax_supp, 11b_base, 11b_mult, 11b_supp, 11g_base, 11g_mult, 11g_supp, 11n_base, 11n_supp, rate_11a, rate_11ac, rate_11ax, rate_11b, rate_11g, rate_11n |  | apmng_rate:do_rate |
| `ac_report` | 2 | `_uac_report_jcs_set` @ `0x0052fa58` | active_ap_only, apgroup, content, interval, max_load, protocol, server_address, server_port, state | ret | apmng_report:apply_settings |
| `ac_statics` | 2 | `stats_sta_jcs_report_para_set` @ `0x007aba98` | clientStats, devStats, radioStats, report_time, sample_time, vapStats |  | apmng_set:handle_cloud_type_event |
| `ap_report_switch` | 2 | `cloud_mngt_jcs_report_msg_set` @ `0x0050cf58` | site_id, status, support_new_rule |  | apmng_set:_ |
| `ap_set_token` | 2 | `cloud_mngt_jcs_set_token_set` @ `0x004fd76c` | deviceToken, expiresIn |  |  |
| `ap_update_token` | 2 | `cloud_mngt_jcs_update_token_set` @ `0x00500d4c` | deviceToken, expiresIn, token_str |  |  |
| `client_report_switch` | 2 | `cloud_mngt_jcs_client_report_switch_set` @ `0x004fe1a0` | status |  | apmng_set:handle_cloud_notify_report |
| `cloud_mngt_clear_config_id` | 2 | `cloud_mngt_jcs_clear_cloud_config_id` @ `0x004fdf94` | cloud_config_id |  | apmng_set:p |
| `cloud_mngt_fast_report` | 2 | `cloud_mngt_jcs_fast_report` @ `0x004fd240` | time_interval |  | cloud:set_fast_report |
| `cloud_mngt_report_para` | 2 | `cloud_mngt_jcs_report_para_set` @ `0x004fddc0` | time_interval |  |  |
| `cloud_mngt_sync_cloud_config_switch` | 2 | `cloud_mngt_jcs_cloud_config_switch_set` @ `0x004fcb24` | status |  |  |
| `cloud_mngt_sync_device_config` | 2 | `cloud_mngt_jcs_device_cloud_config_id_set` @ `0x004fe048` | cloud_config_id, id |  |  |
| `cloud_mngt_sync_module_config_report` | 2 | `cloud_mngt_jcs_sync_module_config` @ `0x004fd930` | config_list, config_name, module_name, name |  | cloud:cloud_sync_local_module |
| `diagnose_global` | 2 | `_apmngr_jcs_diagnose_global_set` @ `0x005ffe10` | enable, telnet_port |  | diagnose:do_settings |
| `local_nms_switch` | 2 | `cloud_mngt_jcs_debug_nms_enable_set` @ `0x004fd0e4` | status, type |  |  |
| `local_server_set` | 2 | `cloud_mngt_jcs_debug_nms_server_set` @ `0x004fcf6c` | ip, local_server, port |  |  |
| `nego_del` | 1 | `_apdb_jcs_callback_del_all_negotiation` @ `0x006fb00c` |  | status | diagnose:clear_diagnose_data |
| `rdmngr_datasync` | 2 | `_rdmngr_jcs_callback_datasync` @ `0x00713448` | data_msg, len |  |  |
| `report_debug_switch_set` | 2 | `cloud_mngt_jcs_debug_switch_set` @ `0x004fcebc` | status |  |  |
| `send_tdcp_test` | 2 | `_tdcp_send_jcs_set` @ `0x0058978c` | tdcp_msg |  |  |
| `start_report_sub_device_info` | 2 | `cloud_mngt_jcs_start_report_sub_dev_set` @ `0x00512d44` | sub_device_mac_list |  | system:start_report_sub_device_info_handle |
| `systime` | 2 | `systime_jcs_callback_systime_set` @ `0x007a7700` |  | ret |  |
| `target_ap` | 2 | `cloud_mngt_jcs_debug_nms_ap_set` @ `0x004fcbe4` | is_all, is_set_group, target_ap_file, tftp |  |  |
| `target_ap` | 3 | `cloud_mngt_jcs_debug_nms_ap_get` @ `0x004fcb1c` |  |  |  |
| `tdcp_passthrough` | 2 | `_tdcp_passthrough_jcs_set` @ `0x00589670` | tdcp_msg |  |  |
| `uac_nms_report_switch` | 2 | `uac_nms_report_jcs_switch_set` @ `0x00516ce4` | enable |  | event_report:handle_nms_report_enable |
| `udbg` | 2 | `udbg_jcs_callback_set` @ `0x006bed44` | cmd |  |  |
| `usb_settings` | 2 | `apmngr_usb_jcs_callback_usb_global_config_set` @ `0x005e7970` | ap_ids, enable, group_ids | ret | apmng_usb:usb_settings_set |
| `usb_settings` | 3 | `apmngr_usb_jcs_callback_usb_global_config_get` @ `0x005e87bc` |  | ret, usb_settings, usb_settings.ap_ids, usb_settings.enable, usb_settings.group_ids | apmng_usb:usb_settings_get |


---

## 5. 列表类接口的文件格式

列表类 GET 的响应通常只有 `file_name` 和 `total_num`（或 `count`/`Num`），真正数据在 uac 的 `/tmp/<name>` 文件里。实测文件例子：

- `/tmp/ap_list`：JSON 数组，每项是 AP 条目。字段包括 `entry_id`、`group_id`、`entry_name`、`model_id`、`model_name`、`hardware_ver`、`software_ver`、`mac`、`entry_type`、`ap_keep_alive`、`client_keep_alive`、`client_idle`、`offline_selfmanage`、`username`、`password`、`led`、`status`、`telnet_status`、`crashdump_status`、`radio_role_table_idx`、`region_code`、`led_wifi_sync`、`firmware_id`、`phy_wire_vlan_list`、`ap_trunk`、`errno`、`cloud_config_id`、`ap_role`、`cap_id`、`led_open_time`、`led_open_date`、`led_timer_enable`、`led_close_time`、`led_close_date`、`new_ap_trunk`、`lag_mode`、`lag_phy_num`、`lag_phy_list`、`bluetooth_enable`、`account_username`、`account_password`、`fit_fat_button_status`、`ssid_mlo_support`、`ap_mesh_switch`、`wired_capture_support`、`wireless_capture_support`、`ap_replace_support`、`replace_status`、`replace_mac`、`log_mng_support`、`log_debug_enable`、`is_sensor_mode`。
- `/tmp/rdmngr_rd_get`：JSON 数组，每项是一条射频配置，字段包括 `rf_id`、`ap_name`、`ap_type`、`rf_name`、`freq_name`、`freq_unit`、`radio_func_type`、`mode`、`channel`、`bandwidth`、`power`、`max_usr`、`rf_state`、`antenna`、`frag_thr`、`bcn_intvl`、`manage_frame_rate`、`rts_thr`、`dtim_prd`、`wmm`、`brd_probe`、`short_gi`、`rssi_restrict`、`rssi_restrict_val`、`min_tx_pwr`、`max_tx_pwr`、`rf_max_usr`、`supp_11ac`、`supp_11ax`、`supp_11be`、`supp_160M`、`is_hdap`、`supp_240M`、`rf_chnl_dcs`、`rf_online_switch`、`rf_check_circle`、`rf_chnl_occup_threshold`、`rf_chnl_tolerance`、`airtime`、`reject_limit`、`reject_enable`、`reject_diff`、`downlink_mumimo`、`uplink_mumimo`、`downlink_ofdma`、`uplink_ofdma`、`twt`、`gi_mode`、`enable_6g`、`enable_6g_psc`、`mutex_channel`、`dft_tx_pwr`、`region_code`、`supp_edca`、`group_name`、`ap_role`。
- `/tmp/ap_firmed_model`：JSON 数组，AP 型号/固件能力。
- `/tmp/apupd_wtps`：JSON 数组，待升级 AP 列表。
- `/tmp/apmngrExport.csv`、`/tmp/apmngrStatusExport.csv`、`/tmp/rdEntry.csv`、`/tmp/host_info.csv`：CSV，首行中文表头，后续每行一条记录。

样本原文见 [captures/list-files/raw-serial.txt](captures/list-files/raw-serial.txt)。
本轮响应中出现过 34 个不同的 `file_name`；其中 33 个已在 guest 的 `/tmp` 找到并原样导出到 [captures/list-files/tmp/](captures/list-files/tmp/)，大小清单见 [manifest.tsv](captures/list-files/manifest.tsv)。`sensor_list_added` 在空 Sensor 列表时没有落盘，因此未导出。

## 6. 反汇编对照

### 6.1 JCS 核心

| 函数 | 地址 | 作用 |
|---|---|---|
| `jcs_callback_register` | `0x005af370` | 按 name/op 注册 handler，内部用哈希表 |
| `jcs_init` | `0x005af514` | 初始化 JCS 全局状态 |
| `jcs_run` | `0x005af740` | 创建 `jcs_ui`/`jcs_service` 两个线程，路径 `"/tmp/jcs.ui.srv.%s"`、`"/tmp/jcs.service.srv.%s"` |
| `jcs_work_task` | `0x005afa54` | 绑定端点、读 JSON、取 `name/op/clt_path/data`、查表回调、按 `clt_path` 回包 |
| `jcs_send_to_process` | `0x005b17a4` | 进程间发送 |

### 6.2 注册表与字段

278 个注册项的 handler 地址见 [jcs-registry.tsv](jcs-registry.tsv)。字段抽取依赖的 PLT：

| thunk | libjson-c 符号 |
|---|---|
| `0x008b9bd0` | `json_object_object_get` |
| `0x008b9930` | `json_object_object_add` |
| `0x008b9b20` | `json_object_new_int` |
| `0x008b9380` | `json_object_new_string` |
| `0x008b9fe0` | `json_object_new_object` |
| `0x008b9be0` | `json_object_new_array` |
| `0x008b98f0` | `json_object_get_int` |
| `0x008b9580` | `json_object_get_string` |
| `0x008b94b0` | `json_object_get_type` |
| `0x008ba0f0` | `json_object_put` |

### 6.3 关键链路

- WLAN 服务使用 `_uac_wserv_jcs_add @0x006e3970`、`_uac_wserv_jcs_set @0x006e2fd4`、`_uac_wserv_jcs_del @0x006e3590`、`_uac_wserv_jcs_get @0x006d5670`。射频绑定走 `_uac_wserv_jcs_rd_op`。`_uac_wserv_packet_send_callback @0x006dbd74` 按 RFC 5416 的 `0x0033DD01` 下发 WLAN，实测安全参数使用 TP-Link 子项 `0x63`。 [报文字段](README.md#capwap-明文与汇编) · [RFC 对照](CAPWAP-RFC.md)
- AP 状态：`ap_status` → `_apmngr_jcs_ap_status @0x00604cf4`；`ap_status_ssid` → `_apmngr_jcs_ssid @0x005f7d58`；`ap_count` → `_apmngr_jcs_ap_count_get @0x005f414c`。
- AP 条目：`apmngr_entry` 0/1/2/3 → `_apmngr_jcs_entry_add @0x00602964`、`_apmngr_jcs_entry_del @0x005fbaf4`、`_apmngr_jcs_entry_set @0x005fd1fc`、`_apmngr_jcs_entry_get @0x006060d4`。
- Portal：`wportal` 是**多态接口**，`type` 选择 LDAP/RADIUS/Portal/免认证等子对象；ADD/DEL/SET/GET 的 handler 分别是 `_wportal_jcs_add_callback @0x004388b0`、`_wportal_jcs_del_callback @0x004328ac`、`_wportal_jcs_set_callback @0x0043683c`、`_wportal_jcs_get_callback @0x0041c7d8`。
- MAC 认证：`macauth_group`、`macauth_group_for_ssid`、`macauth_mac`、`macauth_mac_for_group`、`macauth_type`、`macauth_vlan_str_check`，handler 见 TSV。
- 列表输出：`file_name` 由各 handler 写入 uac 的 `/tmp`，Web 侧 `io.open` 读取。

## 7. 覆盖、异常与未覆盖

### 7.1 `wips_event_detail` 没有响应

**`wips_event_detail` GET**（`wips_jcs_callback_wips_event_detail_get @0x005548fc`）要求 `wips_info_id` 指向存在的 WIPS 事件。本环境没有事件（`wips_event_info` 返回 `count=0`），发送 `{"wips_info_id":0,"start":0,"size":10}` 后 handler 走到：

```
[SENSOR_ERROR]wips_jcs_callback_wips_event_detail_get()/1957 wips event[id=0] not found
Bus Error
PC: 0x005a4128 {uac_mem_free_my}
<1>:[0x00554d68]:{wips_jcs_callback_wips_event_detail_get}
```

`ac_forward` GET 单独说明：它原来在 `request_id` 为标量时崩溃（`array_list_length` 空指针），把 `request_id` 改成数组 `[999]` 后成功返回 `{}`。因此该接口有字段级样本，请求是 `{"device_type":"probe","extend_dev_ids":[],"request_id":[999]}`，响应 `{}`；字段键为 `device_type,extend_dev_ids,request_id`，输出静态键为 `cnt,get_rsponse_info`，本次没有数据。

两个接口的完整记录见 [captures/jcs-crash-wips.txt](captures/jcs-crash-wips.txt)；`ac_forward` 的旧样本保留在 [captures/jcs-samples-empty.jsonl](captures/jcs-samples-empty.jsonl)。

### 7.2 `sensor_test_case_list` ADD 的崩溃条件

`{}` 直接 ADD 会在 `jcs_sensor_test_add_test_case` 中崩溃。补齐 Lua 侧要求的字段后不再崩溃，返回业务错误：

```json
{"ret":1,"err_code":0}
```

最小请求（实测）：

```json
{"data":{"change_id":0,"sch_type":0,"sch_period":0,
 "service":[{"ser_name":"dns","params":[{"ser_index":0}]}],
 "ssid_info":{},"group_id":{},"test_case_name":"cap_probe",
 "sch_time":0,"rssi_threshold":-95,"join_test_sensor":{}},"op":0,
 "name":"sensor_test_case_list","clt_path":"/tmp/jcs.ui.srv.uac3683.luaclt"}
```

字段要求来自 `apmng_sensor.lua:add_sensor_test_case`：`test_case_name` 必填，`sch_period`/`sch_time`/`sch_type` 转数字，`group_id`/`join_test_sensor`/`ssid_info` 转数字，`service` 至少一个带 `params` 的元素。

### 7.3 Web 索引里有、uac 里没有的名字

原厂 Web 打包资源包含跨型号能力，以下名字在 AC100 V6.0 的 `uac` 中没有注册（且多数在二进制里没有字符串）：

| Web 名字 | 说明 |
|---|---|
| `ppsk_group`、`ppsk_user`、`ppsk_user_backup`、`ppsk_user_import_set` | 本镜像 uac 无 PPSK handler，由其他进程/型号能力处理 |
| `deep_inspection_bssid_usage_detail`、`deep_inspection_pkt_usage_detail`、`deep_inspection_ssid_usage_detail`、`deep_inspection_sta_usage_detail` | AC100 未注册，Web 资源来自更高型号 |
| `journey_event_list`、`journey_event_phase`、`journey_sta_list` | 未注册 |
| `auth_session_list`、`ap_location_cfg`、`ac_autorrm` | 未注册 |
| `escape_radius_config` | 二进制里有该字符串，但没有 `jcs_callback_register` 调用点；当前能力未启用 |
| `F`、`r==s and ...` | Web 索引里的 Lua 变量/动态表达式，不是真实 JCS name |

这些名字不计入 278；Web 上如果可见，调用会得到「未知 name → `{}`」或由其他进程处理。

### 7.4 观测到的 `ret` 值

277 个样本中出现的 `ret`：`0`（53 次）、缺失（156 次）、`1`（24）、`-1`（23）、`-2`（5）、`18`（3）、`3`（3）、`-6`（2）、`2`（2）、`-12`（2）、`true`/`false`/`4`/`[]`（各 1）。`ret` 的语义是 handler 私有的；同一数值在不同模块可能含义不同。文档只把它当作「响应字段」，具体错误原因见对应 handler 日志和 `err_code`。

### 7.5 抓包能证明什么、不能证明什么

**已证明**：278 个注册项的 name/op/handler 对应关系；277 个样本（236 个请求 `data` 非空）的请求封装、uac 回包路径、响应形状；列表文件落盘格式；未知 name、非法 op、缺字段、非法 JSON、缺 `clt_path` 的边界行为；WIPS/Sensor/ac_forward 的异常路径。

**已补齐**：Web/LuCI 构造的字段与 uac 直接键合并后，278 个接口共 1558 个输入字段、554 个输出字段；77 个接口的字段是 Web 侧补出来的，原来只看 `in_keys` 会漏掉。

**仍未证明**：

1. 每个 SET/ADD 的业务成功路径。236 个非空请求里，很多值是为了触发解析而构造的保守值（ID 指向不存在的对象、开关置 0、动作传 `noop`），handler 常返回 `ret=-1/1/2` 或类型告警；这不影响字段名，但不能当作“成功报文”。
2. 每个字段的精确类型。日志里的 `Get int/string/intArray ... unmatch` 就是探测值与实际类型不符的证据。类型需要逐 handler 看 `json_object_get_*`，本文只对关键字段给出说明。
3. 子操作 schema。`wportal` 的 `type`、`wservice` 的 `operation`、`apmngr_entry` 的 `operation` 等会把同一 `(name,op)` 分成多套字段；§4 的合并表是并集，具体子操作还要看 §4 的专项说明。

### 7.6 字段覆盖统计

| 项 | 数量 |
|---|---:|
| 注册项 | 278 |
| 有实测样本 | 277 |
| 其中请求 `data` 非空 | 236 |
| 无输入字段 | 41（28 GET、12 SET、1 DEL） |
| 无输出字段 | 61（56 SET、3 GET、1 DEL、1 ADD） |
| Web 字段补出 uac 直接键之外的接口 | 77 |
| 未取得响应 | 1（`wips_event_detail` GET） |
| 已知无字段的变更类接口 | 13（另 1 个数组型 `apmngr_firm`，见下） |

13 个“无字段变更类”接口：`ac_alias_changed`、`ac_clear_all_cloud_config_id`、`ac_mesh_stop_discover`、`ac_mesh_trigger_discover`、`ac_mesh_trigger_pair_all`、`ac_notify_master_sync_data`、`ap_log_download_start`、`ap_log_export_cb`、`ap_log_timer_start`、`nego_del`、`notify_unbind`、`systime`、`wportal_nsa_sync`。`apmngr_firm` 不在其中：它是 `[id,...]` 数组，见 §3.1。它们的 uac 直接键为空、Web 也没有构造字段；多数是内部回调/动作，请求 `data` 就应该是 `{}`。如果后续发现某个需要 payload，应补在这一节，而不是当成已知。

### 7.7 值类型告警分布

字段名补齐了，不代表探测值类型都对。全量 277 个请求串口日志里共有 349 条 `Get int/string/intArray ... unmatch` 类告警，分布在 125 个接口。最多的：

| 接口 | op | 告警数 | 主要来源 |
|---|---:|---:|---|
| `edca_rule` | 0/2 | 40 / 40 | `edca_rule_config_parse_from_json` 的 int/intArray |
| `ac_roam_list` | 0/2 | 22 / 10 | `_wsta_roam_jcs_json_to_entry` 的 int/string |
| `wservice` | 0 | 17 | `_uac_wserv_jcs_add` 的 string/int |
| `ac_roam` | 2 | 16 | `_wsta_roam_jcs_json_to_entry` 的 int/string |
| `apmngr_entry` | 0 | 11 | `_apmngr_jcs_cfg_parse` 的 string |
| `ac_statics` | 2 | 8 | `stats_sta_jcs_report_para_set` 的 int |
| `ac_rrmpara` | 2 | 6 | `rrm_ops_jcs_rrm_para_set` 的 string/int |
| `macauth_group` | 0 | 6 | `_uac_mac_auth_group_jcs_add` 的 string |
| `ac_balance` | 0 | 5 | `balance_config_get_from_json` 的 int |
| `ac_report` | 2 | 5 | `_uac_report_jcs_set` 的 int/intArray |

这些告警说明：字段名在请求里，但值需要按 handler 的 `json_object_get_*` 类型重填（例如 `edca_rule` 的 EDCA 参数应是 int，`ac_roam` 的阈值应是 string/int 的特定组合）。字段名本身仍以 `jcs-schema.tsv` 为准；类型修正应逐接口按告警行号回看 handler。

### 7.8 Go 复刻口径

按“字段名 + 类型候选 + 输入输出样本”划分的静态复刻准备度：

| 口径 | 数量 | 说明 |
|---|---:|---|
| 简单对象候选 | 101 | 字段有输入/输出样本，探测无类型告警，参数不是已识别的数组/多态形状 |
| 字段名全、类型待修 | 115 | 字段名已补齐，但探测值触发 `Get ... unmatch`；需要按 handler 的 `json_object_get_*` 重填类型 |
| 数组/子操作特殊形状 | 20 | `ac_roam_list` ADD、`apmngr_apdb_info` GET、`wportal`、`wservice`、`apmngr_entry` 等，按 §3.1 和 §4 的子操作说明处理 |
| 无输入字段 | 41 | 28 个无输入 GET、13 个内部回调/动作 |
| 无响应 | 1 | `wips_event_detail`，见 §7.1 |
| 合计 | 278 | |

口径可用 `tools/jcs_go_ready.py` 复现；类型告警表在 [captures/type-warnings.tsv](captures/type-warnings.tsv)。`101` 是适合先落地的简单对象接口候选，不代表业务成功路径或 AP 效果已复刻。Go 实现还需逐接口实现状态校验、持久化、异步事件及 CAPWAP 下发。`115` 个接口需要按 getter 和 Web 编码补类型，`20` 个接口有数组或多态形状。现有 `uacgo` 是协议重建项目，其 API 名称和调用层与原厂 JCS 不能直接等同。

## 8. 复现

### 8.1 起 QEMU 与抓包

```sh
# 宿主机；需要 /tmp/ac100/openwrt-24.10.0-malta-be-vmlinux-initramfs.elf
# 以及已解包的 /tmp/ac100/rootfs（AC100_ROOTFS 可覆盖）
python3 tools/qemu_harness.py build
python3 tools/qemu_harness.py start
# READY <qemu-pid>
```

脚本会建 TAP `ac100qtest`、启动 `tools/tap-relay.py`、把 `base.img` 复制成 `run.img`、挂第二块 ext4 盘做 `/share`，然后通过串口执行挂载、ubusd、tddpd、Lua 建表、启动 `uac`。

### 8.2 在 guest 里跑一组接口

```sh
# 宿主机写脚本到 guest 的 /mnt/share，chroot 内看到 /share
python3 - <<'PY'
import sys; sys.path.insert(0,'tools')
from qemu_harness import Guest
g=Guest(); g.connect(); g.wait_prompt()
g.put_file('/mnt/share/probe.lua', open('probe.lua').read())
print(g.run_lua('/share/probe.lua','__DONE__').decode())
PY
```

`probe.lua` 的最小骨架：

```lua
local uds=require"uds"
local cjson=require"cjson"
local rs,rr=uds.send,uds.rcve
uds.send=function(s,p,d) io.stderr:write("TX ",d,"\n"); return rs(s,p,d) end
uds.rcve=function(s,t) local d,e=rr(s,5); io.stderr:write("RX ",tostring(d),"\n"); return d,e end
package.loaded.uds=uds
local j=require"luci.torchlight.uac.jcs"
local r,e=j.jcsUI2uac("ap_count",3,true,{})
print(cjson.encode(r or {}), tostring(e))
```

### 8.3 重建注册表、Web 字段和合并 schema

```sh
# 反汇编 LOAD1
mips-linux-gnu-objdump -D -b binary -m mips:isa32r2 -EB \
  --adjust-vma=0x400000 --start-address=0x400000 --stop-address=0x8ba180 \
  /tmp/ac100/rootfs/usr/sbin/uac > /tmp/uac-load1.asm

python3 tools/jcs_registry.py > /tmp/jcs_registry2.tsv
python3 tools/jcs_fields.py   > /tmp/jcs_fields.tsv
python3 tools/jcs_join.py     # 生成 jcs-registry.tsv

# Web/LuCI 字段（需要 Node + luaparse）
mkdir -p /tmp/luaparse && cd /tmp/luaparse && npm init -y && npm install luaparse
cd - 
node tools/lua_jcs_fields.js > /tmp/lua_jcs_fields.jsonl
python3 tools/jcs_web_fields.py   # 生成 jcs-web-fields.tsv
python3 tools/jcs_web_expressions.py # 生成 jcs-web-expressions.tsv
python3 tools/jcs_schema.py       # 生成 jcs-schema.tsv（合并字段）
python3 tools/jcs_type_evidence.py # 生成 jcs-types.tsv（handler/helper 的 JSON getter）
python3 tools/jcs_verification_matrix.py # 生成 jcs-verification.tsv

# 生成字段完整的请求（不写 {}；无输入 GET 除外）
python3 tools/jcs_requests.py     # 生成 field-requests.tsv / field-cases.lua

# 校验：注册表 vs 实测样本
python3 tools/jcs_verify.py
# registry=278 samples=277 nonempty=236 missing=1 errors=0
# MISSING wips_event_detail 3

# 校验：样本请求键是否都在 schema.inputs 内
python3 tools/jcs_field_verify.py
# samples=277 nonempty=236 unknown_fields=0 unknown_outputs=0 empty_with_inputs=0 errors=0

# Go 复刻严格口径
python3 tools/jcs_go_ready.py
# total=278 strict=101 type_pending=115 special=20 no_input=41 missing=1
```

`jcs-verification.tsv` 为每个 `(name,op)` 提供一条可复现的 JCS `data` 样本和响应。调用方用本节 0.1 的公共信封包装 `request_data_json`，按 `name`/`op` 查对应的注册项。样本来自字段解析探测，不保证业务约束通过。若需真实成功配置命令，应先按 §4 中原厂 Lua 的必填/枚举校验构造输入，再验证 UCI/SQLite 持久化、CAPWAP 下发、AP ACK 和状态回读。

### 8.4 在 guest 里执行字段完整请求

`tools/qemu_harness.py start` 后，宿主机在 `notes/vendor-web/captures/` 起一个只绑 TAP 地址的 HTTP 服务，guest 用 `wget` 拉取：

```sh
cd notes/vendor-web/captures
python3 -m http.server 8000 --bind 172.30.194.1
```

guest 侧：

```sh
cd /mnt/share
wget -q -O field-requests.tsv http://172.30.194.1:8000/field-requests.tsv
wget -q -O field-raw-run.lua  http://172.30.194.1:8000/field-raw-run.lua
echo '1 276' > batch.txt
chroot /mnt /usr/bin/lua /share/field-raw-run.lua
```

`field-raw-run.lua` 直接拼 JSON 字符串，因此 `[]`、`{}`、嵌套对象都按原样发送，不经过 Lua cjson 的“空表变对象”。结果写到 `/share/field-raw-results.jsonl`。

### 8.4 复核清单

1. `python3 tools/jcs_verify.py` 输出 `registry=278 samples=277 nonempty=236 missing=1 errors=0`，唯一缺失为 `wips_event_detail`。
2. 任取 `jcs-registry.tsv` 一行，按 `handler` 地址在 `uac-load1.asm` 中定位；其 `in_keys`/`out_keys` 应能在该函数的 `json_object_object_get/add` 调用参数中找到。
3. 任取 `jcs-samples.jsonl` 一行，`request` 解析后的 `name`/`op` 应与行首字段一致，且 `request.data` 只含该接口声明的键（或为 `{}`）。
4. 列表类 GET 的 `file_name` 基名应出现在 `captures/list-files/manifest.tsv`（33/34；`sensor_list_added` 空列表未落盘）。


---

## 附录 A：原厂 Web 侧调用链

| Web 路由/页面 | 控制器 | 典型 JCS |
|---|---|---|
| AP 状态 `apStatus` | `apmng_status.lua` | `ap_status`、`ap_status_ssid`、`ap_count`、`ap_count_trend` |
| 无线服务 `wirelessService` | `apmng_wserv.lua` | `wservice` 0/1/2/3、`wserv_global`、`wservice_ip` |
| 射频绑定 `rfBindList` | `apmng_wserv.lua` | `wservice` SET operation=1/2 |
| AP 分组 `apGroup` | `apmng_group.lua` | `apmngr_group`、`apmngr_group_join` |
| AP 升级 `apUpgrade` | `apmng_upgrade.lua` | `apupd_model`、`apupd_wtp`、`apupd_status` |
| 认证配置 `authConfig` | `authentication.lua`、`portal_auth.lua` | `wportal`、`wportal_user_data` |
| MAC 黑白名单 | `macauth.lua` | `macauth_mac`、`macauth_group`、`macauth_blacklist` |
| 智能漫游 | `apmng_roam.lua` | `ac_roam`、`ac_roam_list`、`roam_wireless_network_mode` |
| 射频调优 | `apmng_rrm.lua` | `ac_rrmpara`、`ac_rrm_list`、`ac_manualrrm` |
| Mesh | `apmng_mesh.lua` | `ac_mesh_*` |
| Sensor/WIPS | `apmng_sensor.lua` | `sensor_*`、`wips_*`、`deep_*` |
| DHCP/ARP 防护 | `apmng_arpdefend.lua`、`apmng_dhcpdefend.lua` | `arp_defend_*`、`dhcpdef_*` |
| 系统/云 | `cloud_mngt.lua`、`system.lua` | `cloud_mngt_*`、`systime`、`ac_report` |

## 附录 B：字段命名规律

- 列表分页通常是 `start` + `size`（少数用 `start`+`end` 或 `limit`+`offset`）。
- 条目 ID 常用 `id`、`entry_id`、`serv_id`、`ap_id`、`model_id`、`test_case_id`；具体含义由模块决定。
- 开关常用 `enable`/`status`，值为 `"on"/"off"` 或 `0/1`，由 handler 自己解析；不要假设统一布尔。
- 批量操作常用逗号分隔字符串（如 `ap_ids`、`ids`、`serv_id`）或 JSON 数组；以 `in_keys` 和 Lua 调用点为准。

---

完整样本：[captures/jcs-samples.jsonl](captures/jcs-samples.jsonl)（277 行；236 行请求 `data` 非空）。
旧的空请求样本留档：[captures/jcs-samples-empty.jsonl](captures/jcs-samples-empty.jsonl)。
完整响应摘要：[captures/jcs-summary.tsv](captures/jcs-summary.tsv)。
合并字段表（§4 数据源）：[jcs-schema.tsv](jcs-schema.tsv)。
Web 补出的字段清单：[jcs-web-only.tsv](jcs-web-only.tsv)。
Helper 补出的字段清单：[jcs-helper-fields.tsv](jcs-helper-fields.tsv)。
`wportal` 按 `(op,type)` 的字段表：[jcs-wportal-types.tsv](jcs-wportal-types.tsv)。
`wservice` 按 `operation` 的字段表：[jcs-wservice-ops.tsv](jcs-wservice-ops.tsv)。
Web/LuCI 字段：[jcs-web-fields.tsv](jcs-web-fields.tsv)。
直接注册表：[jcs-registry.tsv](jcs-registry.tsv)。
字段完整请求：[captures/field-requests.tsv](captures/field-requests.tsv)。
类型告警计数：[captures/type-warnings.tsv](captures/type-warnings.tsv)。
边界行为：[captures/jcs-edge.txt](captures/jcs-edge.txt)。
列表文件原文：[captures/list-files/raw-serial.txt](captures/list-files/raw-serial.txt)。
