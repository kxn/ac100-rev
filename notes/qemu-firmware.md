# 在 QEMU 里启动 TL-AC100 V6.0 的 uac

目标：用真机固件回答协议问题（如 WLAN 安全配置的线格式）。

当前可执行的主机配置、固件导入及 Linux USB 网卡直连流程见
[环境说明](../docs/setup.md)。下文 `/tmp/ac100` 和 Windows/WSL 参数为历史采集记录；
新脚本默认使用仓库 `.local/ac100/`，可用 `AC100_*` 环境变量覆盖。

## 结论：能跑，但厂商 daemon 需要设备 flash 里的配置

| 步骤 | 状态 |
|---|---|
| 固件格式解析 | ✅ TP-LINK 容器；uImage @0x30800（MIPS BE / Linux 4.4.140）、squashfs(LE 元数据) @0x270200 |
| 根文件系统提取 | ✅ `unsquashfs`（38MB，1729 inodes，含 `usr/sbin/uac` MIPS32 BE + uClibc 0.9.33） |
| 内核 | ✅ 用 OpenWrt 的 malta/be 内核（厂商内核板级相关，malta 上起不来） |
| 用户态 | ✅ qemu-system-mips -M malta + 厂商 rootfs（ext4 盘）→ `uac` 原生执行 |
| uac 主进程启动 | 新建磁盘冷启动进入 `cw_ac_run()`，同一 PID 监听 IPv4 和 IPv6 的 UDP 5246 |

关键点：

1. `qemu-mips`（用户态）**跑不了**：`uac` 里有 MCHK 内存检查器写未对齐尾哨兵
   （`lui t8,0xaaaa; ori; sw t8,0x10(s0)`，基址 2 字节对齐），真机由内核 DSEMUL 修正，
   qemu 用户态直接 SIGBUS。换 `-cpu`/环境变量都无效。
2. 必须全系统：`qemu-system-mips -M malta`，内核用 OpenWrt malta/be
   （`openwrt-24.10.0-malta-be-vmlinux-initramfs.elf`，自动带 initramfs 与 shell）。
3. 厂商 rootfs 做成 ext4 盘挂进 guest 再 chroot 执行 —— 内核会做未对齐修正，`uac` 正常进入 main。
4. `-initrd` 自定义 initramfs 不被识别（VFS panic），所以用"内置 initramfs 内核 + ext4 盘"。
5. `-M malta` 需要 `-net none -vga none`（否则缺 `efi-pcnet.rom` / `vgabios-cirrus.bin`）。

## 从固件镜像复现

在仓库根目录执行。内核使用 OpenWrt 24.10.0 的 Malta BE 内置 initramfs ELF。

```sh
work=$(mktemp -d)
kernel=/tmp/ac100/openwrt-24.10.0-malta-be-vmlinux-initramfs.elf
python3 - "$work/rootfs.sqfs" <<'PY'
import struct
import sys
from pathlib import Path

firmware = Path("TL-AC100 V6.0_1.0.3_Build_260817_Rel.68871n.bin").read_bytes()
offset = 0x270200
assert firmware[offset:offset+4] == b"hsqs"
size = struct.unpack_from("<Q", firmware, offset + 40)[0]
Path(sys.argv[1]).write_bytes(firmware[offset:offset+size])
PY
unsquashfs -d "$work/rootfs" "$work/rootfs.sqfs"

rootfs="$work/rootfs"
mkdir -p "$rootfs/tmp/etc/uc_conf" "$rootfs/tmp/etc/nouci_conf/dbs" \
  "$rootfs/tmp/.volatiles/etc/nms_report" "$rootfs/tmp/ac_config" "$rootfs/tmp/run"
cp -a deploy/qemu-config/etc_config/. "$rootfs/tmp/etc/uc_conf/"
cp -a deploy/qemu-config/nms_report/. "$rootfs/tmp/.volatiles/etc/nms_report/"
truncate -s 192M "$work/vendor.img"
mkfs.ext4 -q -F -d "$rootfs" "$work/vendor.img"

qemu-system-mips -M malta -m 256 -net none -vga none \
  -kernel "$kernel" -drive "file=$work/vendor.img,format=raw,if=ide" \
  -nographic -no-reboot -snapshot
```

串口按 Enter 进入 OpenWrt shell 后执行。

```sh
mount /dev/sda /mnt
mount --bind /dev /mnt/dev
mount -t proc proc /mnt/proc
touch /mnt/tmp/uac_init_trace_open
chroot /mnt /sbin/ubusd &
for t in $(seq 1 5); do test -S /mnt/tmp/run/ubus.sock && break; sleep 1; done
chroot /mnt /bin/tddpd &
chroot /mnt /usr/bin/lua -e '
  local db = require "luci.torchlight.uac.wportal_sqlApi"
  db.portal_create_portal_entry_table()
  db.auth_server_create_radius_table()
'
chroot /mnt /bin/ubus call tddpServer getInfo '{"infoMask":33}'
chroot /mnt /sbin/uci -c /etc/nms_report get event_params.10001020.threshold
chroot /mnt /usr/sbin/uac &
for t in $(seq 1 40); do test -s /mnt/tmp/uac_init_done && break; sleep 1; done
cat /mnt/tmp/uac_init_done
kill -0 "$(cat /mnt/tmp/uac_init_done)" && netstat -lunp | grep ':5246 '
test -S /mnt/tmp/jcs.service.srv.uac
```

2026-11-24 用空数据库和 QEMU 快照复测，`main @0x0040f414` 打印
`-- Run > cw_ac_run()`，随后进程 PID、UDP 5246 和 JCS 套接字均可验证。
隔离 guest 缺少 `cloudclient`，云站点查询和回调注册会报错。
带 TAP 网卡的联调已接入实体 AP。厂商 LuCI 后端创建的 `qiyitt` 在双频广播 WPA2-PSK/CCMP，JCS 读回和空中扫描均已验证。 [真机联调记录](ap-deployment/PROGRESS.md#四qemu-厂商-ac-读回真机-ap-的-ssid)

## 实体 AP 与 QEMU 的联调链路

| 位置 | 本次配置 |
|---|---|
| 实体 AP | TL-XAP3006GC-PoE/DC，经有线直连 Windows，DHCP 地址 `192.168.70.50/24`。 |
| Windows 有线口 | `192.168.70.1/24`。运行 `dhcp4.exe -addr 192.168.70.1 -lease 192.168.70.50`，DHCP option 43 `01 04 c0 a8 46 01` 将 AC 指向 `192.168.70.1`。 |
| Windows UDP 中继 | `udprelay.exe -wire 192.168.70.1:5246 -wsl 127.0.0.1:5257`。 |
| WSL2 mirrored | 第二级 UDP 中继监听 `127.0.0.1:5257`，为每个对端从 `172.30.194.1` 绑定独立源端口，经 `ac100qtest` 转发。 |
| QEMU guest | Malta MIPS BE，OpenWrt initramfs 内核，厂商 ext4 盘。`br-lan` 加 `172.30.194.2/30`，厂商 `uac` 监听 UDP `5246`。 |

Windows 的 DHCP 与 UDP 中继使用仓库里的 Go 工具构建，并由 Windows 计划任务启动。QEMU 联调的中继目标端口为 `5257`，日常 Go AC 默认目标端口为 `5256`。 [Windows 工具与启动参数](../deploy/wsl/run.sh)

在 WSL 创建 TAP，已有 `ac100qtest` 时可直接使用现有接口。

```sh
sudo ip tuntap add dev ac100qtest mode tap user "$(id -u)"
sudo ip addr add 172.30.194.1/30 dev ac100qtest
sudo ip link set ac100qtest up
```

在独立 WSL 终端启动第二级中继。上行套接字必须绑定 TAP 地址，绑定 `127.0.0.1` 后向 guest 发送在本环境返回 `sendto: invalid argument`。

```sh
python3 - <<'PY'
from selectors import DefaultSelector, EVENT_READ
from socket import AF_INET, SOCK_DGRAM, socket

ac = ('172.30.194.2', 5246)
upstream = socket(AF_INET, SOCK_DGRAM)
upstream.bind(('127.0.0.1', 5257))
peers = {}
with DefaultSelector() as selector:
    selector.register(upstream, EVENT_READ)
    while True:
        for event, _ in selector.select():
            link = event.fileobj
            payload, sender = link.recvfrom(65535)
            if link is upstream:
                if sender not in peers:
                    downstream = socket(AF_INET, SOCK_DGRAM)
                    downstream.bind(('172.30.194.1', 0))
                    selector.register(downstream, EVENT_READ, sender)
                    peers[sender] = downstream
                peers[sender].sendto(payload, ac)
            elif sender == ac:
                upstream.sendto(payload, event.data)
PY
```

沿用上面的 `work`、`kernel` 和厂商盘。用 TAP 启动，同时在网卡上抓双向报文。`-snapshot` 下 guest 的运行时配置随本次 QEMU 会话结束而丢弃，宿主侧 PCAP 独立写入 `work`。

```sh
umask 077
qemu-system-mips -M malta -m 256 -vga none \
  -kernel "$kernel" -drive "file=$work/vendor.img,format=raw,if=ide" \
  -netdev tap,id=ap,ifname=ac100qtest,script=no,downscript=no \
  -device pcnet,netdev=ap,romfile= \
  -object "filter-dump,id=apcap,netdev=ap,file=$work/capwap.pcap" \
  -nographic -no-reboot -snapshot
```

在串口进入 guest 后，待 `br-lan` 出现，通过 `ip addr add 172.30.194.2/30 dev br-lan` 添加地址，再执行上面的挂载、厂商服务与 `uac` 启动命令。让 AP 重新入网，使抓包包含该会话的完整 DTLS 握手。`ap_count` 的 `online_num` 从 `0` 变为 `1`，并且 `ap_status` 返回实体 AP 的 MAC，即可确认链路。 [JCS 查询参数](vendor-web/README.md#ap-管理)

## 离线导出 CAPWAP 会话明文

本次测试协商 DTLS 1.0，套件为 `TLS_RSA_WITH_AES_256_CBC_SHA` (`0x0035`)。导出需要完整握手，以及与 Server Certificate 配对的测试 AC RSA 私钥。`AC_KEY` 指向该私钥。原始记录的第 `111` 帧为 Server Hello，第 `112` 帧为 Server Certificate。此方式适用于静态 RSA 密钥交换会话。协商 ECDHE 等临时密钥交换的会话需从测试端点另取会话密钥。

下面在 WSL 使用 Python 3、Scapy 和带 GnuTLS 支持的 Tshark 4.4。将 `capture` 指向新抓包，或者设为本次的 `/tmp/ac100/uac-check.7YxFd9/qiyitt.pcap`。`work` 为本地分析目录。每个 DTLS 数据报外层都有 `01 00 00 00` 的 CAPWAP 前导。移除该前导，并重新计算 IP 和 UDP 长度及校验和。保留所有帧与时间戳，以便用原始 PCAP 的帧号回查。

```sh
umask 077
capture="${capture:-$work/capwap.pcap}"
: "${AC_KEY:?请先指定测试 AC 的 RSA 私钥路径}"
python3 - "$capture" "$work/capwap-dtls.pcap" <<'PY'
import sys
from scapy.all import IP, UDP, PcapReader, PcapWriter

with PcapReader(sys.argv[1]) as source, PcapWriter(sys.argv[2], linktype=1) as target:
    for packet in source:
        if IP in packet and UDP in packet:
            ip, udp = packet[IP], packet[UDP]
            if 5246 in (udp.sport, udp.dport):
                payload = bytes(udp.payload)[:udp.len - 8]
                if payload.startswith(b'\x01\x00\x00\x00'):
                    udp.remove_payload()
                    udp.add_payload(payload[4:])
                    del ip.len, ip.chksum, udp.len, udp.chksum
        target.write(packet)
PY

tshark -r "$work/capwap-dtls.pcap" -d udp.port==5246,dtls \
  -Y 'dtls.handshake.type == 2' -T fields \
  -e frame.number -e dtls.handshake.version -e dtls.handshake.ciphersuite

tshark -r "$work/capwap-dtls.pcap" -d udp.port==5246,dtls \
  -o "dtls.keys_list:172.30.194.2,5246,data,$AC_KEY" \
  -Y 'dtls.record.content_type == 23 && data.data' -T fields -E aggregator=, \
  -e frame.number -e ip.src -e data.data > "$work/capwap-clear.tsv"
```

`capwap-clear.tsv` 的列为原始帧号、源 IP 和解密后的 CAPWAP 十六进制。抓包点在 TAP，`172.30.194.2` 是 AC，`172.30.194.1` 是代 AP 发送的中继。明文仍带 CAPWAP 内层头。同一帧有多个 `data.data` 时以逗号分隔。之前临时制作的 `direct-dtls.pcap` 只保留 DTLS 报文，并在 `ip.id` 中记录原始帧号。上面的复现使用 `frame.number` 直接保留原始索引。

uac 的 JCS 接口全集、字段和 277 个实测样本（236 个字段完整请求）见 [vendor-web/UAC-INTERFACES.md](vendor-web/UAC-INTERFACES.md)。

当前样本可用 `204/205` 和 `232/233` 验收。两条请求均为 `0x0033DD01`，对应应答为 `0x0033DD02`。明文文件包含测试 WLAN 口令，抓包、导出及私钥均保存在本地分析目录。 [WLAN 字段与汇编对照](vendor-web/README.md#capwap-明文与汇编)

## AC100 V6.0 的配置读取证据

地址来自 TL-AC100 V6.0 1.0.3 Build 260817 Rel.68871n 镜像中的 `/usr/sbin/uac`
及同镜像的 `uac_symbol_fun`。此 ELF 的 Build ID 是
`7346df6c645058f30948c066f93708c38cc2193e`，仓库 `asm/` 对应另一份 ELF。
可用 `mips-linux-gnu-objdump -D -b binary -m mips:isa32r2 -EB --adjust-vma=0x400000`
反汇编该镜像中的函数。下表的现象来自新建磁盘或原镜像的快照试跑。

| 功能与地址 | 对照现象 |
|---|---|
| `uac_com_get_dev_mac @0x0059b680` 调用 `tddpServer getInfo` 获取 MAC | 空数据库启动时，缺少 `tddpd` 会卡在 WLAN 服务的默认条目初始化。启动厂商 `ubusd` 和 `tddpd` 后，UBus 返回 `mac`，进程继续初始化。 |
| `wsta_db_init_buttom_half @0x0074e474` 从 `/etc/nms_report/event_params` 读取 `10001020.threshold` | UCI 在 `/etc/config` 能列出包时，uac 仍报加载失败。把文件放入 `/etc/nms_report` 并补 `threshold` 后，原有包和 section 告警消失。 |
| `wsta_assoc_info_init @0x00770ebc` 读取 `apmng_client.max_aging_time` | 把相同的 `300` 移入 `apmng_client` 后，日志中的 `sta_bind_info->max_ageing_time` 告警消失。 |
| `wportal_db_init @0x00442c08`、`_wportal_read_portal_config @0x0040d450`、`_wportal_read_radius_config @0x0040d610` | 补上 `authentication.portal.dns_upd_intv`，并调用固件 nginx 初始化所用的 Lua 函数建表后，Portal 解析和 SQLite 缺表告警消失。 |
| `ac_8021x_radius_auth_init @0x0044eb70`、`radius_init @0x0045a918`、`ldapc_init @0x00469a40` 读取 `wportal` 的线程数 | 分别显式设置为缺省值 `4` 后，三条线程数配置告警消失。 |
| `_audit_client_db_gloabal_config_read @0x005882f0` 读取审计 UCI，`uac_mac_auth_init @0x004a45c0` 读取 MAC 认证模式，`_bcast_storm_ctrl_cfg_load @0x004b0350` 读取风暴控制配置 | 审计使用 `local`，MAC 认证使用 `ssid`，风暴控制作用范围使用 `all` 后，三个模块均越过原配置解析错误。 |
| `_wsta_roam_read_config @0x004ddc54` 和 `rrm_ops_read_cfg_from_uci @0x0052249c` 读取漫游和 RRM 配置 | 第二批漫游参数缺失时停在 `default_roam_cnt`，RRM 的 `chnl_enable='0'` 也会导致初始化退出。补齐后启动到上报模块。漫游计数、静默时间和 RRM 信道集合是 QEMU 测试值。 |
| `_uac_report_read_config @0x0052f4c8`、`uac_com_get_dev_type @0x0059e874`、`uac_com_get_device_name @0x0059eefc` | 上报 `state='0'`、缺少设备类型、缺少设备别名依次阻塞启动。补齐后冷启动进入 `cw_ac_run()`。 |

## 备选（更省时）

真机 AP 在线时，直接下发候选配置 + 扫描验证，比把厂商 daemon 完整跑起来快得多。
