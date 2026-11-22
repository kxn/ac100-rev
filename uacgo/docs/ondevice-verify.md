# 真机复核清单（四项）

前置：用户提供 TL-AC100 真机或可访问的真实 AC/AP 环境（SSH/telnet
可达，能跑 tcpdump/uci）。以下每项给出「取证动作 → 对比物 → 判定」。
全部为只读取证（抓包/读配置/握手），不改设备配置。

## 1. JCS 帧格式抓包复核

目的：核对 Go `jcs` 层的 unix-socket JSON 信封
（`{"method":..,"module":..,"keyword":..,"params":..}`，jcs.go:92）与
真实 uac 的 JCS 服务端帧格式一致。

动作（在设备上）：
```
# 找到 JCS 服务 socket（五子系统各一个，如 /tmp/jcs.service.srv.apmngr）
ls -l /tmp/*.srv.* 2>/dev/null; netstat -lnp | grep uac
# 抓 uac 与 web 服务之间的本地 unix 流量（strace 跟一次页面操作）
strace -f -s 4096 -e trace=read,write -p $(pidof uac) 2>&1 | grep -E 'srv\.|method'
# 或在 web 端触发一次 AP 列表刷新后抓取写入 JCS socket 的字节
```
对比物：Go 侧同 module/keyword 请求的 JSON（`jcs.Call` 产物）。
判定：method/module/keyword 字段名、params 嵌套层次、响应
`error_code`/`ret` 字段名一致。

## 2. SendImageNotify 方向复核

目的：确认固件升级通知是 AC→AP（下行 Control Request，消息号 0x0e
response 侧）而非 AP 上报。

动作：
```
tcpdump -i any -w /tmp/cap.pcap udp port 5247
# Web 界面对一台在线 AP 触发固件升级，停止抓包
tcpdump -r /tmp/cap.pcap -vv | grep -i -E 'image|0x0e|notify'
```
对比物：Go `cweng` 引擎 SendImageNotify 构造的消息（notes §
image 元素 0xaf/0xb0/0xb1 编解码）。
判定：方向（AC 发起 seq 递增请求 vs AP 响应）、消息类型字段、
Image Data 元素分块长度一致。

## 3. profile.ini 数值校准（uci show profile）

目的：data/profile.ini 中标注 (recon) 的占位值与真机 UCI 实际值对齐。

动作（在设备上，只读）：
```
uci show profile
# 备份一份原始导出
uci export profile
```
对比物：`uacgo/data/profile.ini` 每个 section/option。
判定：逐键比对；recon 占位值全部替换为实机值；键名不一致的以实机
为准并同步 cweng/store.go 的读取键。跑 `go test ./cweng/ -run Profile`
回归。

## 4. pion DTLS 握手 normal 验证

目的：Go 侧 pion/dtls v2.2.12（cweng/dtls_pion.go）与真机 AP 完成
CAPWAP DTLS 握手（沙箱内此前跳过）。

动作（主机侧，与 AP 同网段）：
```
# 用 Go 守护进程在 5247 上以 DTLS 侦听（identity.json 用测试证书）
cd uacgo && go build ./cmd/acd && ./acd -listen :5247 -data data
# AP 侧指到主机地址后发起 join；主机抓包
tcpdump -i any -w /tmp/dtls.pcap udp port 5247
```
对比物：固件自带 /etc/cacert.pem + privkey（CA 与 AP 侧一致）。
判定：ClientHello/ServerHello/HPSK 或证书套件协商成功、应用数据
（CAPWAP Control）解封装正常；失败时记录 alert 与套件清单。

## 完成标记

每项执行后：把抓包/uci 导出落到 `notes/`（或 attachments），
在 notes/00-architecture.md 追加 §51 真机复核记录，勾掉本清单对应项。
