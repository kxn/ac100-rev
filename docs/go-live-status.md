# 独立 Go 控制器实机进度（2026-11-26）

## 最新部署：2026-11-27 06:51（Asia/Singapore）

已部署双向复核与根因整改提交 `90fd82b07b0209a331b04f6b0a3ec467275ff7f4`，构建信息 `vcs.modified=false`、`CGO_ENABLED=0`。详细问题、证据和验证见 [复核记录](controller-revalidation.md)。已补齐 AP 批量 CSV 命名并统一名称存储；会话容量、配置校验和客户端事实入口已收敛，移除 RADIUS 残留及重复修补路径。

46 项行为合同、126 个具名用例、129 个已取证 UAC 函数归类、全量测试/vet/race、三平台纯 Go 构建、两能力×11页/50次表单全部通过。部署后 AP 重新 RUN，两路 RF 回读 verified，13 项同步无失败/受阻；平板保持 5 GHz 5200 MHz，网关、DNS/HTTPS及 Go 客户端位置/IP检查通过。旧二进制和数据一致性快照已私存。此次基本设备检查不作为原厂漫游/调度算法的证明。

以下较早部署与设备检查属于历史记录，以本节为当前版本。

## 2026-11-27 独立程序配置更新

已部署代码 `f0ebf98dd2c1f6882cf1d32bb649d6f536d26346`，替换下节的策略部署版本。构建信息确认revision一致、vcs.modified=false，服务active/running且NRestarts=0。

新增“程序配置”页，10项Go资源预算可实时修改、持久化及备份恢复。实际HTTP验证将AP预算1024临时提高至1025再恢复1024，原AP连接时间保持不变；Web主页面与资源脚本已更新。AP基础初值20秒心跳/5次超时/30秒保活/3600秒空闲/离线自管理允许已填入已有管理页。正式程序不读取原硬件profile.ini。

全量Go测试/vet/race及Linux amd64/arm64、Windows amd64纯Go构建通过；两能力×11页、48表单无JS错误。实际AP回RUN、配置无failed/blocked，平板5GHz连接及网关/DNS/HTTPS通过，客户端IP/射频/统计显示正常。此轮未更改漫游/RRM纯计算模块，资源调整不改变AP配置身份和策略；设备检查仅确认基本可用性。

## 2026-11-27 部署更新

策略整改代码已提交并部署为 `712f49648d70392034a17b112bad2fa7568c6e75`。运行二进制的 Go 构建信息确认该 revision、`vcs.modified=false`、`CGO_ENABLED=0`；systemd 服务 active/running，重启计数0。部署前已在忽略目录私存旧二进制及数据库一致性备份。

本次基本可用性检查：AP重新进入RUN，两路射频配置 verified，共13项配置同步状态无failed/blocked；原有平板保持GoAC-Lab连接在5200MHz，网关及DNS/HTTPS通过，Go客户端显示connected、正确射频、IP及统计。未运行多AP调度对比，不将此次设备检查当作原厂算法等价证明。私人部署快照和验证记录存于 `.local/ac100/deployments/`、`.local/ac100/adb-tests/`。

下文为11月26日的历史设备记录。所有文档中“本轮未部署”的描述均指此前源码审计收尾时点；以本节为最新部署状态。

> 历史设备记录，部署基线为 `587d414`。2026-11-27 的策略/协议/配置架构整改尚未部署，下文不代表整改后的实机结果，也不证明原厂算法等价。当前源码与依据见 [策略对照](mobility-parity-audit.md) 和 [功能对应](feature-parity.md)。AP蓝牙、RADIUS、Portal和AC主机系统功能均不在产品范围。


产品是独立 Go 程序，直接接入 AP、提供中文 Web 管理，不依赖原厂 UAC/QEMU。
保留 AP 管理、无线服务、射频、无线运行状态、AP 协调和接口选择；保留由 AP 执行的 DHCP/ARP/ND 防护、广播抑制。
排除 RADIUS、认证管理、网络运维、云管理和 AC Linux 的系统/网络管理。普通 DHCP/DNS/NAT 是独立实验工具；用户明确要求的 TP-Link AP 专用 DHCP 是可选 Go 组件。
完整功能及验证边界见 [feature-parity.md](feature-parity.md)，详细工作记录见 [parity-worklog.md](parity-worklog.md)。
AC 功能验收与自动回归入口见 [ac-acceptance.md](ac-acceptance.md)。

## 设备与固件

- 实体 AP：TL-7AP5100HC-PoE/DC易展版，硬件1.0，软件1.0.18 Build20250317 Rel.43192。
- AC 对照：用户提供的 TL-AC100 V6.0 1.0.3 Build260817 Rel.68871n；另取同版本 AP 固件核对设备端实现。
- USB `enxc817f5dd9eb9`，主机192.168.70.1/24，AP192.168.70.50；平板 Xiaomi Pad6 已通过 ADB 授权。
- Go UDP5246直接处理实体AP；原厂relay停止。Web默认127.0.0.1:8090。

固件只能提供字段与协议线索。字节/模拟、设备ACK、配置模型回读、真实数据面分别记录；不能相互替代。

## 已完成的实体链路验证

- Go DTLS1.0兼容接入、Join/Configure/RUN/心跳，AC重启和AP完整冷启动重接入。
- 冷启动必发private26初始化修复后，AP完整重启→Go选择性DHCP完整DORA→平板新关联和再次Wi-Fi重连通过。
- 双频SSID新增/删除和槽位提交，分别关闭2.4/5GHz、重建VAP、恢复双频五阶段均真实接入/HTTPS，AP/radio/WLAN/IP与平板一致。
- PSK修改已实测旧密码失效、新密码HTTPS；临时SSID及保存网络清理已复查。
- WPA2、开放网络、隐藏WPA2、WPA2/WPA3混合均真实接入/HTTPS；混合模式实际协商SAE（Android type4），没有把PSK回退当成SAE成功。
- 固定VLAN100：平板取得192.168.100.53，通过临时VLAN接口HTTP，AP实际SSID/VLAN/IP与Go显示一致；测试接口和服务已清理。
- SSID及单客户端3000kbps限速实测约3.2–3.5Mbps，恢复约87/19Mbps；强制下线收到实际AP disassociate，再连接。
- AP七项设置、LED开关与报告；RF38次更改/恢复及原生模型回读。回读不代表每一项空口效果都已验证。
- 单AP RRM测量/计划/应用/回读/恢复；单AP高性能/兼容模式、RSSI统计、真实ACS扫描和信道计划/提交/恢复。
- AP DHCP防护：信任实际服务器时获取地址/上网；只信任错误服务器后关联仍发生但45秒无IPv4，恢复正常。
- AP基本ARP防护：匹配绑定3发3收、错误有线发送方3发0收，恢复正常。此AP固定保护有线入口，未声明新式模式/端口范围，不能声称无线ARP行为已通过。

私人证据在Git忽略的 `.local/ac100/`，可能包含无线凭据和客户端信息，不提交原始trace或ADB XML。
平板和实验网络保留 `GoAC-Lab`；临时安全/VLAN服务及保存网络均清理。

## 复杂配置及其它型号

代码/API/UI覆盖模板、分组、覆盖/显式关闭、复制/替换、计划、升级任务及故障恢复；无线包括描述/编码、隐藏/隔离、PSK、绑定/VLAN/池、限速、组播/MLO/定时。
射频包括模式/带宽/信道/功率、速率表、客户端上限、时序/RSSI、MU/OFDMA/TWT/DCS/EDCA、整机射频模式和RRST联动。
AP 蓝牙已按用户要求从产品配置、API、页面和运行状态中移除；Mesh包括发现、配对、名单、拓扑和独立子AP代理会话。

当前AP不具备的能力仍有Go实现及模拟路径。UI逐AP展示，继承配置过滤不支持的可选硬件，直接AP覆盖严格校验。
旧的 RRM/ACS 联合优化是自定策略，已删除；V6 不开放旧 ACS 模式，RRM 按原库计算，再按原厂射频归一化和顺序联动下发。当前型号实际ARP48/ND24容量与AC全局1024库分开校验。
客户端保留AP上报的SSID、服务身份、实际VLAN及历史，配置重命名/槽位复用不会改写旧事实。
客户端信号历史按实际测量时间保存1小时，AP在线/离线数量趋势保留24小时；旧表未报VLAN时仅在服务身份唯一时恢复客户端，不虚构VLAN。
Mesh成员授权/撤销独立于任务日志，纳入备份与替换；操作记录可压缩，存储失败不标完成。
AP复制支持真正保持目标射频，保留目标名称/位置/组/模板；AP状态列表可单独导出CSV。

## 选择性 DHCP 与实验服务

`--ap-dhcp <JSON>` 显式绑定控制接口；普通DHCPv4请求静默，精确Option60 `TP-LINK` 可完成租约。
精确 `TP-LINK MESH DETECT 1.0` 只有Discover响应；Request静默。其它服务器选择、普通终端、转发及不匹配标识均不回应/不发NAK。
namespace真实UDP和实体AP冷启动DORA均已通过；同一抓包中的Android请求被Go忽略。

实验dnsmasq刻意给普通Wi-Fi终端提供DHCP/DNS，USB子网NAT让其上网，服务为 `ac100-ap-dhcp` / `ac100-ap-nat`。
它们不是Go产品的主机网络管理功能，也不能作为选择性DHCP的实现证据。

## 后续设备兼容记录（不作为本轮AC功能完成门槛）

- 多AP实际漫游/k/v/r、负载均衡和Mesh转发，需要第二台AP；双模拟AP只证明管理/协议状态转换。
- 多客户端隔离、总量限速，以及MLO、BLE、RRST切换等硬件专属效果，需要相应设备。
- 优选配置、双频可用性已验证；客户端自主选择5GHz不算AC/AP主动引导证据。
- 长时间稳定性及全部空口/边界组合未完成，不能声明“原厂所有功能每一项都实机验证”。
- AP离线自管理已实测当前型号：停止Go后，两组旧连接均保持；开关分别允许/拒绝新接入。两组原设置与连接均恢复，其它型号/长期离线仍待。

## 常用命令

```sh
source tools/env.sh
python3 tools/go_lab.py status
python3 tools/check_env.py --go-live
python3 tools/go_lab.py restart --iface enxc817f5dd9eb9
python3 tools/check_adb_wifi.py cycle --serial a1971f20
go -C uacgo test ./...
go -C uacgo vet ./...
```

全量Go测试/vet、核心race与两种能力×10页×49个表单已通过；纯Go交付构建不依赖CGO，ARM64 Linux及Windows构建通过。
较新源码、部署和具体实测时间以工作记录为准，表单测试不代表物理设备行为。


23:00 验收边界按用户纠正：停止继续AP吞吐/PHY细测。当前聚焦AC配置、API/UI、能力/命令、上报/展示和持久化/失败恢复，主要用模拟AP检查。速率吞吐工具主动中断，原速率/射频及GoAC-Lab已恢复，HTTPS200。继续AC管理闭环核查；不再用AP性能测试拖延AC功能对齐。

23:39 AC 管理补齐版本已部署：上述Mesh/复制/客户端历史/AP数量/列表导出/动态射频编号均已纳入。AP重接入、配置提交、客户端最新状态及本次会话RSSI历史确认；无失败/受阻/待处理配置。基本联网冒烟通过233608。自动回归49次表单、Go/vet/race和纯Go构建通过。该结论仅限当时的管理回归，已被 11 月 27 日策略核查发现的偏差纠正；多AP实际切换与其它硬件行为保留为兼容性验证，不声称已经实测。
