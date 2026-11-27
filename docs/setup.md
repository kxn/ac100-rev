# 开发与联调环境

本项目有两套固件证据，必须分别使用，不能混用地址表。

| 用途 | 固件身份 | 默认位置 |
|---|---|---|
| 旧 Go 实现、`asm/`、`ghidra-export/` 的基准 | `uac` SHA-256 `ddc30fd8aa14e206eaa119e403a4ada64584bef84020c825b8c579bfa4153c68`；已由官网下载包逐字节确认为 **TL-AC100 V4.0 1.4.3 Build240715 Rel.80898n**（不是用户的1.4.4） | `firmware/usr/sbin/`，二进制和两个符号表；本次完整V4参考解包到`.local/ac100/v4-review/rootfs/` |
| QEMU 原厂 AC、`notes/vendor-web/`、JCS 字段分析 | **TL-AC100 V6.0 1.0.3 Build 260817 Rel.68871n**；`uac` SHA-256 `b12d1584fcafda2a71aa9038b41b7e1c5b893b350f3e6edf5105e445d024a912` | `.local/ac100/rootfs/`，完整厂商 rootfs |

`identity.json` 中的 2014 年固件串来自厂商样例报文，不足以认定旧二进制的发布版本。
新固件导入到独立目录，不要覆盖仓库 `firmware/` 或旧反汇编。依赖固定地址的提取器会校验二进制 SHA-256。

## 1. 主机工具和项目环境

Debian/Ubuntu 主机：

```sh
sudo apt-get install binutils-mips-linux-gnu python3 python3-scapy \
  qemu-system-mips squashfs-tools e2fsprogs tshark tcpdump dnsmasq-base
npm ci --prefix tools --ignore-scripts --no-audit --no-fund
source tools/env.sh
python3 tools/prepare_firmware.py kernel
python3 tools/check_env.py
```

Go 模块要求 **1.26.0+**。本机登录 shell 的 Go 是 1.24.6，进入 `uacgo/` 后，
`GOTOOLCHAIN=auto` 已能选择 1.26.0。首次下载工具链和模块需要联网。
环境脚本显式设置 `CGO_ENABLED=0`，无需安装 MIPS C 编译器或 SQLite 开发头文件。

本机已安装 Ghidra **12.1.4**，位置为 `$HOME/tools/ghidra`；JDK 21 位于
`/usr/lib/jvm/java-21-openjdk-amd64`。`env.sh` 仅修改当前 shell，不改系统默认 Java。
在其它主机上可先设置 `GHIDRA`、`AC100_JAVA_HOME` 再 source。
Ghidra 启动路径是 **`$GHIDRA/support/analyzeHeadless`**。

| 变量 | 默认值 | 用途 |
|---|---|---|
| `AC100_REV_ROOT` | 仓库根 | 证据输入/输出；Go 测试也认此变量 |
| `AC100_WORK_DIR` | `<仓库>/.local/ac100` | 不进 Git 的固件、内核、磁盘、抓包和中间文件 |
| `AC100_FW_ROOT` | `<仓库>/firmware` | **旧二进制**及配套符号表 |
| `AC100_ROOTFS` | `<work>/rootfs` | **V6 完整 rootfs**；`AC100_FW` 为兼容别名 |
| `AC100_KERNEL` | `<work>/openwrt-24.10.0-malta-be-vmlinux-initramfs.elf` | QEMU 内核 |
| `AC100_H` | `<work>/harness` | 虚拟磁盘、串口、PID、日志和 TAP 抓包 |
| `AC100_ASM` | `<work>/analysis/uac-load1.asm` | V6 反汇编；有二进制校验旁文件 |
| `AC100_FIELDS` | `<work>/analysis/jcs-fields.tsv` | V6 JCS 直接字段 |
| `AC100_LUA_FIELDS` | `<work>/analysis/lua-jcs-fields.jsonl` | LuCI 分析结果 |
| `AC100_RELAY_LISTEN` | `127.0.0.1:5257` | 原 WSL 上游；本机 USB 联调为 `0.0.0.0:5246`，接收广播发现 |
| `AC100_RELAY_PEERS` | 默认不限制；USB 配置后为 `192.168.70.0/24` | 限制接收的 AP 来源网段 |
| `AC100_TAP` | `ac100qtest` | QEMU 的专用 TAP |

## 2. Go 构建和回归

```sh
source tools/env.sh
cd uacgo
CGO_ENABLED=0 go build ./...
go test ./...
go vet ./...
GOOS=linux GOARCH=arm64 CGO_ENABLED=0 go build ./...
GOOS=windows GOARCH=amd64 CGO_ENABLED=0 go build ./...
```

真实 UDP 的 `TestPionDTLSHandshake` 和 `TestPionSmoke` 已改为接受每个对端的连接后握手；
原先将未连接 UDP 套接字传给 Pion 造成的失败不再标记为沙箱限制。
这两个测试及进程内握手都应实际 PASS，不应 Skip。
真实 TL-7AP5100 使用 DTLS 1.0 RSA/AES-CBC，另有纯 Go 兼容后端；Go 主程序已接入该后端。

专用 USB 链路和 DHCP 配置好后，停止占用 UDP 5246 的原厂中继，再启动 Go：

```sh
# 如需从原厂完整环境切换，可先停其 QEMU/relay：
python3 tools/qemu_harness.py stop
python3 tools/go_lab.py start --iface enxc817f5dd9eb9
python3 tools/go_lab.py status
python3 tools/check_env.py --go-live
```

`go_lab.py` 使用私有工作目录保存证书、数据库和 Web 配置，先构建成功再启动。
Web 位于运行服务器的 `http://127.0.0.1:8090`。
`-interface` 真正约束收包和回包接口，保留广播发现；`-iface` 指定通告 IPv4。
不改主机路由；数据库自动创建，无需独立 SQLite 服务。
完整进度、命令和边界见 [Go 实机进度](go-live-status.md)。

## 3. 导入原厂固件与 QEMU 冷启动

需要完整 BIN 或只含一个 BIN 的 ZIP：
`TL-AC100 V6.0_1.0.3_Build_260817_Rel.68871n.bin`。
导入器定位 SquashFS、校验解包后 `uac` 的 SHA-256，再写入 rootfs 和来源清单；
已有 rootfs 时拒绝覆盖。

```sh
source tools/env.sh
python3 tools/prepare_firmware.py import '/绝对路径/TL-AC100 V6.0_1.0.3_Build_260817_Rel.68871n.bin'
python3 tools/prepare_firmware.py kernel
python3 tools/qemu_harness.py network
python3 tools/check_env.py --vendor
python3 tools/qemu_harness.py build
export AC100_RELAY_LISTEN=0.0.0.0:5246
export AC100_RELAY_PEERS=192.168.70.0/24   # USB 直连时先配置下一节网卡
python3 tools/qemu_harness.py start
```

内核来自 [OpenWrt 24.10.0 Malta BE 官方目录](https://downloads.openwrt.org/releases/24.10.0/targets/malta/be/)，
下载器固定 SHA-256 `491b29423a335bf13066775b37ebf2e2ca07c9e017c6c35673630719e1c3171f`。
厂商板级内核不能直接用于 Malta；`qemu-mips` 用户态也无法替代全系统模拟。

`build` 从 rootfs 与 `deploy/qemu-config/` 构建基准盘；`start` 每次复制基准盘，
启动厂商 `ubusd`、`tddpd`、Portal 建表及 `uac`。运行配置只写副本盘，基准盘不变。
如需保留一次运行的磁盘，重新 start 前备份 `run.img`。
`stop` 校验 PID 对应进程后关闭 QEMU/中继，保留可复用 TAP。

```sh
python3 tools/qemu_harness.py stop
# 只更新中继监听地址而不重启 guest：
AC100_RELAY_LISTEN=0.0.0.0:5246 AC100_RELAY_PEERS=192.168.70.0/24 python3 tools/qemu_harness.py relay
# guest 放到 /share 的文件可离线读取；运行中的盘应先确保文件写完：
python3 tools/qemu_harness.py extract /field-raw-results.jsonl
```

详细启动证据和 CAPWAP 明文导出见 [QEMU 记录](../notes/qemu-firmware.md)。
该记录中的 `/tmp/ac100` 是历史采集路径，新运行应使用以上环境变量。

## 4. Linux USB 网卡与实体 AP

接线：Linux 主机 → USB 有线网卡 → 网线 → AP；AP 使用匹配的 DC 电源或 PoE 注入器供电。
USB 网卡不会提供 PoE。AP 的硬件版本主要影响固件选择；初次联调不需要刷 AP 固件。
本机 AP 已报告完整型号 TL-7AP5100HC-PoE/DC易展版、硬件 1.0；原有配置是否清空不能只凭接入确认。
恢复出厂成功不能只凭 Reset 时的指示灯判断。

```sh
source tools/env.sh
ip -brief link
# 将接口名替换为专用 USB 网卡；本次是 enxc817f5dd9eb9：
python3 tools/ap_link.py up --iface enxc817f5dd9eb9
source tools/env.sh
python3 tools/ap_link.py status --iface enxc817f5dd9eb9
export AC100_RELAY_LISTEN=0.0.0.0:5246
export AC100_RELAY_PEERS=192.168.70.0/24
python3 tools/qemu_harness.py relay
```

`ap_link.py` 要求 NetworkManager、systemd 和 sudo 权限，并核验该接口确为 USB 网卡、
不是网桥成员或默认路由接口。它新增独立的 `ac100-ap-direct` 连接，固定
`192.168.70.1/24`，不添加默认网关。临时 systemd 服务 `ac100-ap-dhcp` 仅在 USB 网卡上
提供 `192.168.70.50–60` DHCP，Option 43 `01 04 c0 a8 46 01` 指向测试 AC，关闭 DNS 和默认网关下发。
中继监听 `0.0.0.0:5246` 以接收广播发现，但仅处理 `192.168.70.0/24` 来源。
USB 配置写入工作目录 `ap-direct/link.env`，再次 source 环境脚本会自动加载。
不改主网桥、防火墙或系统 IP 转发配置。NetworkManager 连接会保留，DHCP 服务和 QEMU 在主机重启后需重新启动。

链路：AP → `192.168.70.1:5246` → 每对端 UDP 中继 → TAP `172.30.194.1/30`
→ guest `172.30.194.2:5246`。无需沿用旧 Windows/WSL 中继工具。

```sh
sudo tcpdump -ni enxc817f5dd9eb9 'arp or udp port 67 or udp port 68 or udp port 5246'
sudo journalctl -u ac100-ap-dhcp -n 30 --no-pager
cat "$AC100_WORK_DIR/ap-direct/dhcp.leases"
# 关闭测试 DHCP 与专用连接：
python3 tools/ap_link.py down --iface enxc817f5dd9eb9
```

DHCP 成功仅证明 AP 已启动并拿到地址；继续以 CAPWAP discovery/join、DTLS 握手、
原厂 JCS 的 `ap_count`/`ap_status` 读回确认上线。
涉及旧配置时先保留抓包、读出型号和状态，再决定是否恢复出厂，不自动下发复位或升级。

```sh
# 联调运行时验收主机和服务；读取原厂 AC 的在线 AP 与 SSID：
python3 tools/check_env.py --vendor --live
python3 tools/vendor_status.py
```

本机本次实测结果见 [environment-status.md](environment-status.md)。

## 5. 重建旧取证语料

以下步骤只用于仓库旧二进制，先生成符号 JSON，再反汇编和注释：

```sh
source tools/env.sh
python3 tools/syms.py dump-syms
mips-linux-gnu-objdump -D -b binary -m mips:isa32r2 -EB \
  --adjust-vma=0x400000 "$AC100_FW_ROOT/usr/sbin/uac" > raw_text.asm
python3 tools/annotate.py
python3 tools/elements.py
python3 tools/syms.py extract cw_dis_req cw_dis_rsp cw_join_req cw_join_rsp \
  cw_cfg_req cw_cfg_rsp cw_cse_req cw_cse_rsp cw_cfg_update_req cw_wlan_cfg_req
python3 tools/callargs.py 58dca4   # 参数为实际要检查的函数地址
```

默认输出会覆盖对应生成语料；对照实验可设置 `AC100_REV_ROOT` 为独立输出目录，
`AC100_FW_ROOT` 仍指向仓库旧固件。`annotate.py` 需要该输出目录的 `syms.json` 与 `raw_text.asm`。
`elements.json` 保留了基准中一条既有 `type_field_mismatch`；本次再生结果与仓库基准一致。

Ghidra headless 示例：

```sh
source tools/env.sh
mkdir -p ghidraProj
"$GHIDRA/support/analyzeHeadless" "$AC100_REV_ROOT/ghidraProj" ac100 \
  -import "$AC100_FW_ROOT/usr/sbin/uac"
"$GHIDRA/support/analyzeHeadless" "$AC100_REV_ROOT/ghidraProj" ac100 \
  -process uac -noanalysis -scriptPath "$AC100_REV_ROOT/tools" \
  -postScript ExportAll.java "$AC100_REV_ROOT/ghidra-export"
```

本机 12.1.4 已实际编译并执行 `ExportAll.java`。完整分析需另行运行，耗时较长。
Ghidra **项目路径**的任何目录段不能以 `.` 开头，因此项目放在 `ghidraProj/`，
不要放进 `.local/`；导出文件可以放在 `.local/`。
从头导入不能自动还原固件外置符号表，须导入配套符号后才有与现有语料相同的命名。

## 6. V6 的 JCS/LuCI 取证与离线校验

```sh
source tools/env.sh
python3 tools/jcs_registry.py > "$AC100_WORK_DIR/analysis/jcs-registry-raw.tsv"
python3 tools/jcs_fields.py > "$AC100_FIELDS"
node tools/lua_jcs_fields.js > "$AC100_LUA_FIELDS"
# 以下命令会更新相应 TSV 证据，变更后检查 diff：
python3 tools/jcs_join.py
python3 tools/jcs_web_fields.py
python3 tools/jcs_web_expressions.py
python3 tools/jcs_verify.py
python3 tools/jcs_field_verify.py
python3 tools/jcs_go_ready.py
```

无需连接设备即可校验仓库已有 277 个 JCS 样本；唯一缺失接口为既有记录中的
`wips_event_detail`。它在无效事件 ID 下导致厂商进程崩溃，环境验收不调用该接口。
新增协议结论请在 `notes/00-architecture.md` 记录对应版本与函数地址；
元素编解码变动同步 `notes/element_retseq.txt`，最后跑 Go 回归。
