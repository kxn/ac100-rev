# 本机环境验收（2026-11-26）

主机：Debian 13 / linux amd64；仓库 `/data/dl/ac100-rev`。
操作入口和重新启动命令见 [setup.md](setup.md)。以下是本次实际检查结果。

以下原厂环境结果是接管前的基准记录。随后 Go 已接管 UDP 5246，原厂 relay 已停止；
最新 Go 接入、Web、射频与剩余验收见 [Go 实机进度](go-live-status.md)。

## 固件与主机

- 用户提供的 `TL-AC100 V6.0_1.0.3_Build_260817_Rel.68871n.bin` 已导入。
  解包后 `usr/sbin/uac` SHA-256 与既有 V6 记录完全一致：
  `b12d1584fcafda2a71aa9038b41b7e1c5b893b350f3e6edf5105e445d024a912`。
  完整 rootfs 和导入清单位于 `.local/ac100/`。
- QEMU Malta BE 已冷启动原厂 `uac`，完成 UBus/tddpd/Portal 初始化。
  guest 中同时监听 IPv4/IPv6 UDP 5246，两个 JCS socket 已存在。
- OpenWrt 24.10.0 Malta BE 内核下载后通过固定 SHA-256 校验。
- MIPS binutils、Scapy、dnsmasq 已安装；Node `luaparse` 固定为 0.3.1。
- Ghidra 12.1.4 + JDK 21 实际完成最小 MIPS 程序导入、`ExportAll.java` 编译和执行。
  本次未重新运行整库自动分析。Ghidra 项目路径不能放在 `.local/` 下。
- `tools/check_env.py --vendor --live` 所有检查通过。

## USB 与实体 AP

| 项目 | 实测值 |
|---|---|
| USB 网卡 | `enxc817f5dd9eb9`，QinHeng USB 10/100 LAN，`cdc_ether` 驱动 |
| 主机测试地址 | `192.168.70.1/24`；专用 NetworkManager 连接 `ac100-ap-direct` |
| DHCP | 独立 `ac100-ap-dhcp` 服务，仅绑定 USB 接口；Option 43 指向 `192.168.70.1` |
| AP 租约地址 | `192.168.70.50` |
| AP MAC | `F8:CE:21:6B:58:FE` |
| 原厂 AC 读回型号 | `TL-7AP5100HC-PoE/DC易展版`；后续 Go 解析 AP 自报硬件版本 1.0 |
| QEMU TAP | 宿主 `172.30.194.1/30`，guest `172.30.194.2/30` |
| CAPWAP 中继 | `0.0.0.0:5246` 接收广播发现，仅接受 `192.168.70.0/24` 来源 |
| JCS `ap_count` | `online_num=1, offline_num=0, total_num=1, ret=0` |
| JCS `ap_status` | `link_status=1, ap_role=cap`，2.4 GHz 与 5 GHz 均上报 |
| SSID 状态读回 | `TP-LINK_935E` 和 `TP-LINK_5G_935E`，两条均启用 |

中继保留每个 AP 的独立 UDP 对端；因此 AC `ap_status.ip` 显示中继地址
`172.30.194.1`，AP 的真实 DHCP 地址仍是 `192.168.70.50`。
本次保留了 DHCP、广播发现、发现响应、后续 DTLS 及控制通信。
抓包 `.local/ac100/harness/capwap.pcap`，串口日志 `serial.log`，读回记录
`environment-status.txt`，均留在本机工作目录。

用户描述曾按住 Reset 上电。设备能拿到地址并加入 AC，证明当前运行与接入正常，
**不能证明所有历史配置已清空**。未再次触发复位，也未刷 AP 固件。
SSID 状态来自原厂 AC 读回，尚未通过空中扫描或客户端接入复核。

## 代码和取证工具

- 修复 `syms.py`、`elements.py` 的路径写入错误，以及 `annotate.py` 对 JSON 十进制地址的解析。
- 在独立输出目录重建 5683 个函数反汇编；十个提取报文与仓库样本逐字节一致，元素 JSON 相同。
  其中一条既有 `type_field_mismatch` 原样保留，不作为新结论修改。
- V6 的 278 个 JCS 注册项与仓库地址/符号一致；直接字段及 371 个 LuCI 调用点可重新生成。
- 已有 277 个 JCS 样本与字段校验通过；既有缺失 `wips_event_detail` 未调用。
- 真实 UDP 的 Pion 握手和双向明文传输实际通过；原来的“沙箱限制” Skip 已移除。
  修复了握手完成通知先于连接就绪的顺序问题。
- Go 全量测试、vet 与 `CGO_ENABLED=0` 的 linux/amd64、linux/arm64、windows/amd64 构建通过。
  DTLS 握手测试另以 race detector 连跑三次通过；该诊断构建临时启用 cgo，交付构建仍为纯 Go。

## 尚需后续开发的部分

原厂 QEMU + AP 的上线不等同于 Go AC 已对等实现。
Go 后续已完成当前 AP 的 DTLS 兼容接入；仍需按 V6 证据迁移 JCS 协议及完善子系统注册；
重建 profile 也需真机值校准。这些是实现工作，不是继续安装主机依赖可以解决的问题。
当前 QEMU 和测试 DHCP 服务已保持运行；主机重启后按 setup.md 重新启动。
