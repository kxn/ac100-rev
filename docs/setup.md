# 环境重建说明

从零拿到这份仓库后，按你的目的分两条路径：

- **A. 只想构建 / 运行 / 测试 Go 实现** → 只需要 Go，其它都在仓库里。
- **B. 想重建取证语料 / 继续对 uac 二进制做逆向** → 需要装逆向工具链，
  下面给出每一步的精确命令与产物。

仓库布局回顾：`uacgo/`（Go 实现）、`notes/`（取证笔记+工件）、
`firmware/usr/sbin/`（uac 二进制+固件自带符号表）、`asm/`（5683 个
函数的注释反汇编）、`ghidra-export/`（全量伪代码+vendor 报文 fixtures）、
`tools/`（取证脚本）。

---

## A. 构建与测试（最小环境）

1. 装 Go **1.26+**（go.mod 要求 `go 1.26.0`）：
   https://go.dev/dl/ 或发行版包。
2. 首次构建需要联网拉模块（pion/dtls v2.2.12、modernc.org/sqlite 等，
   `go.sum` 已固定版本）：

```sh
cd uacgo
go build ./...        # CGO_ENABLED=0，全程无 cgo
go test ./...         # 会消费 ghidra-export/data 下的 vendor 报文 fixtures
```

可选环境变量（都有默认值，正常不需要设）：

| 变量 | 默认 | 含义 |
|---|---|---|
| `AC100_REV_ROOT` | 仓库根（测试自动推导 `../../`） | 取证工件（fixtures/notes）的根目录 |
| `AC100_FW_ROOT` | `<仓库>/firmware` | 含 `usr/sbin/uac` + 符号表的解包 rootfs |

跨平台编译（无 cgo，全部可交叉）：

```sh
GOOS=linux   GOARCH=arm64 CGO_ENABLED=0 go build ./...
GOOS=windows GOARCH=amd64 CGO_ENABLED=0 go build ./...
```

### 运行守护进程

```sh
cd uacgo
go build -o acd ./cmd/acd
./acd -data ./data -port 5246 [-iface 0.0.0.0] [-debug]
```

`-data` 目录需要四个文件（仓库 `uacgo/data/` 已带）：
`identity.json`（AC 身份，fixture 值）、`profile.ini`（运行时配置重建，
标 `(recon)` 的值待真机校准）、`apdb.json`（AP 库种子）、
`rate-default.bin`（速率表）。

已知沙箱注意事项：部分容器/沙箱内核拒绝回环 UDP 的多包快速交换，
`TestPionDTLSHandshake`（内核 UDP 路径）会自动 Skip；进程内全链路
握手测试 `TestPionDTLSHandshakeInProcess` 不受影响、始终执行。

---

## B. 取证语料重建（继续逆向时才需要）

仓库已包含全部生成产物（`asm/`、`ghidra-export/`、`notes/`），
**只有想从二进制重新生成、或继续取证时**才需要以下工具链。

### 1. 固件镜像与解包

- 固件镜像从 TP-Link 官网 TL-AC100 支持页下载（公开）。
- 镜像为 squashfs 打包，解出根目录树（例证用的目录名 `sq/`）：

```sh
unsquashfs -d firmware/rootfs <固件镜像内的 squashfs 分区>
# 或用 binwalk 定位分区偏移后 dd + unsquashfs
```

- 把这三个文件放进 `firmware/usr/sbin/`（仓库已带，重解包后可校验
  是否同一版本）：
  - `uac`（3.4MB MIPS32 BE ELF，无 section header，有 program header）
  - `uac_symbol_fun`（固件自带函数符号表：addr size kind name，5683 行）
  - `uac_symbol_obj`（数据对象符号表，1213 行）

### 2. 反汇编工具

```sh
# Debian/Ubuntu
apt install binutils-mips-linux-gnu llvm python3
```

生成线性反汇编基准 `raw_text.asm`（绕过缺 section header 的问题，
按 raw binary + 指定 VMA 反汇编；LOAD1 文本段 vaddr 0x400000）：

```sh
mips-linux-gnu-objdump -D -b binary -m mips:isa32r2 -EB \
    --adjust-vma=0x400000 firmware/usr/sbin/uac > raw_text.asm
```

注意：`mips-linux-gnu-objdump -d`（按 ELF）在这个文件上输出为空
（无 section header），必须用上面的 `-b binary` 形式；llvm-objdump
按 program header 也能反，格式略有差异（字节列空格分隔）。

### 3. 注释反汇编语料（asm/ + func_index.tsv）

```sh
# 把 raw_text.asm 放到仓库根（tools/annotate.py 默认读 <root>/raw_text.asm）
python3 tools/annotate.py
# 产物：asm/（每函数一个 .asm 文件，带符号名头）+ func_index.tsv
```

### 4. Ghidra 全量伪代码（ghidra-export/decomp/）

- 装 Ghidra **11.3.2** 与 JDK 21（`JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64`）。
- headless 导入 uac（分析要数十分钟）：

```sh
$GHIDRA/headless/analyzeHeadless ./ghidraProj ac100 -import firmware/usr/sbin/uac
```

- 用仓库里的 `tools/ExportAll.java` 批量导出每个函数的伪代码：

```sh
$GHIDRA/headless/analyzeHeadless ./ghidraProj ac100 -process uac -noanalysis \
    -scriptPath tools -postScript ExportAll.java ghidra-export
```

坑：Ghidra 升级/换版本后若脚本报编译错误，清一次用户 OSGi 缓存
（`~/.config/ghidra/ghidra_11.3.2_PUBLIC/osgi`）再跑。

### 5. 符号/元素/调用点提取

```sh
python3 tools/syms.py      # → syms.json + ghidra-export/data/（vendor 报文 fixtures）
python3 tools/elements.py  # → notes/elements.tsv + ghidra-export/elements.json
python3 tools/callargs.py  # → 调用点字符串参数表（profile 等键取证）
```

`tools/` 的脚本全部从 `AC100_REV_ROOT`（默认：仓库根，按脚本位置
推导）读输入、写输出；`syms.py` 另认 `AC100_FW_ROOT`（默认：
`<仓库>/firmware`）。

### 6. 回归门

改完任何东西后：

```sh
cd uacgo && go test ./...   # fixtures 回归（报文 fixture 解析必须逐字节过）
```

新增协议结论时：在 `notes/00-architecture.md` 记地址锚点；动到元素
编解码器则同步 `notes/element_retseq.txt`（生成器逻辑见
`tools/`，序列 = parse 函数内 `cw_protocol_retrieve*` 调用序列）。

---

## 真机复核（可选）

四项需要真机/真实 AP 的复核清单见 `uacgo/docs/ondevice-verify.md`
（JCS 帧抓包、SendImageNotify 方向、`uci show profile` 校准
`uacgo/data/profile.ini` 的 `(recon)` 占位值、与真机 GnuTLS 的 DTLS
线上互操作）。
