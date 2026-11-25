# JCS 抓包样本与字段探测

## 文件

| 文件 | 内容 |
|---|---|
| `jcs-samples.jsonl` | 277 行；字段完整请求 + 实测响应，其中 236 行请求 `data` 非空 |
| `jcs-samples-empty.jsonl` | 早期用 `{}` 请求的 277 行样本，只作对照留档 |
| `jcs-summary.tsv` | 同上，TSV 形式，便于 grep/awk |
| `field-requests.tsv` | 277 个 `(name,op)` 的原始 JSON `data`（`[]`/`{}` 保真，不经过 Lua cjson） |
| `field-cases.lua` / `field-cases.json` | 同一批请求的 Lua/JSON 形式，供其他脚本复用 |
| `field-raw-run.lua` | guest 侧驱动：逐行读 TSV，拼完整 JCS 信封并发送 |
| `field-raw-results.jsonl` | 字段探测的原始 TX/RX 日志（含每个请求的完整 JSON） |
| `type-warnings.tsv` | 每个接口在探测中触发的 `Get ... unmatch` 类型告警数 |
| `jcs-edge.txt` | 未知 name、非法 op、缺字段、非法 JSON、缺 `clt_path` 的边界行为 |
| `jcs-crash-wips.txt` | `wips_event_detail` 无有效事件 ID 时的请求和 SIGBUS 证据 |
| `list-files/raw-serial.txt` | uac 写出的列表文件原文（串口抓取） |
| `list-files/tmp/` | 从 guest `/tmp` 直接导出的 33 个 `file_name` 输出文件 |
| `list-files/manifest.tsv` | 上述文件的大小清单 |

## JSONL 字段

| 字段 | 含义 |
|---|---|
| `name` | JCS 接口名 |
| `op` | 0/1/2/3 |
| `request` | 完整请求 JSON 字符串（含 `name/op/clt_path/data`） |
| `response` | uac 回包的 JSON 值；无回包时为 `null` |
| `error` | 客户端错误；字段探测的 277 个样本均为 `null` |
| `batch` | `field`（字段完整探测）或 `legacy-empty`（旧样本） |

`request` 里的 `clt_path` 含采集时的 PID，跨运行无意义；协议字段本身是固定的。

## 数值约定

探测值不是业务配置：ID 指向不存在的对象（`999`/`0`）、开关置 `0`、动作传 `noop`、字符串传 `probe`，目的是让 handler 走解析路径而不是改坏配置。因此大量响应是 `ret=-1/1/2` 或空对象；这只能证明字段名和分发路径，不能当作成功报文。字段类型仍以 handler 的实际 `json_object_get_*` 为准，日志里的 `Get int/string/intArray ... unmatch` 就是探测值类型不符。

## 复现

见 [../UAC-INTERFACES.md](../UAC-INTERFACES.md) §8。校验命令：

```sh
python3 tools/jcs_verify.py
# registry=278 samples=277 nonempty=236 missing=1 errors=0
# MISSING wips_event_detail 3

python3 tools/jcs_field_verify.py
# samples=277 nonempty=236 unknown_fields=0 unknown_outputs=0 empty_with_inputs=0 errors=0

python3 tools/jcs_go_ready.py
# total=278 strict=101 type_pending=115 special=20 no_input=41 missing=1
```

唯一没有响应的是 `wips_event_detail`，原因见文档 §7.1。
