# 设备复核与实现边界

> 历史设备兼容记录。当前范围与策略静态依据见 [策略对照](../../docs/mobility-parity-audit.md)。2026-11-27整改尚未部署；正式acd已不注册旧JCS/SQLite无线配置路径，下文旧接口差异不再是正式产品路径。不得用此设备清单推导或证明调度算法。

当前主机环境与复现命令见 [环境说明](../../docs/setup.md)。
2026-11-26 已用原厂 AC100 V6.0 1.0.3 Build 260817 Rel.68871n + QEMU
通过 Linux USB 网卡接入实体 AP TL-7AP5100HC-PoE/DC 易展版。
随后独立 Go 程序已完成当前 AP 的 DTLS/Join/RUN、无线服务下发及接入时 SSID 读回，
并取得射频修改后的 AP 回报。最新证据和功能范围见
[Go 实机进度](../../docs/go-live-status.md)。客户端仍需实际终端验证。

1. **JCS**：V6 的实际协议已确认是 Unix 数据报 JSON `{name,op,clt_path,data}`，
   UI 路径为 `/tmp/jcs.ui.srv.uac`。完整帧、样本和字段见
   [接口记录](../../notes/vendor-web/UAC-INTERFACES.md)。Go `jcs` 当前仍使用自己的
   传输/信封，后续应针对该证据迁移，不能沿用旧文档中“已对等”的结论。
2. **DTLS**：Pion 组件 UDP/进程内测试通过，但其 DTLS 1.2 套件不能直接支持这台 AP。
   主程序已接入独立的 DTLS 1.0 RSA/AES-CBC 兼容后端并完成真实接入；
   当前范围与握手分片、抗丢包、其它认证方式等限制见实机进度，不能外推到所有 AP。
3. **profile**：Go `data/profile.ini` 的参数是重建值。原厂 QEMU 的合成 UCI 配置
   在 `deploy/qemu-config/`；若需设备真实默认值，仍须对应版本真机的 `uci show profile`。
4. **升级通知与分块**：`SendImageNotify` 的方向、消息号和块长仍需对照实机抓包。
   升级会改变 AP 状态，不作为环境验收动作；取得用户对目标设备升级的明确指令后再做。
5. **复位与旧配置**：DHCP、CAPWAP Join 和在线数量证明设备正常通信，不能证明
   历史配置已全部清除。先读状态、保留抓包，再决定是否需要恢复出厂。

环境验收只读取 `ap_count`、`ap_status` 和 `ap_status_ssid`，不批量运行写入类探测，
不调用已知可使原厂进程崩溃的 `wips_event_detail`。
