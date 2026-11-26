# 本轮持续实现记录

用户已明确要求：除 RADIUS 和此前排除的菜单外，补齐所有保留缺口；管理逻辑可用模拟 AP 验证，现有 AP 设置逐项验证；额外 AP/终端留到最后实际需要时集中提出。不能在核查、单项修复或仅列缺项后停止。

实施顺序：

1. AP 设置、分组/模板/批量、配置导入导出/替换、名称位置、LED/重启计划。
2. 客户端管理、服务级上限、PPSK、组播列表和配置完整性。
3. 完整速率表、全局优化、均衡/漫游配置与模拟 AP 决策/协议交互。
4. AP 特有扩展、固件升级流程/型号校验、选择性 DHCP 剩余分支。
5. 联合模拟回归、现有 AP 逐项设置回读/恢复与 ADB 回归，最后汇总额外硬件才能验证的行为。

已补入本轮代码：

- AP 默认/模板/分组/AP 继承、复制/替换/备份导入导出、LED 与重启计划、名称位置和客户端编辑/下线/CSV。
- APOptions 的射频继承（单 AP 显式字段覆盖）、服务总客户端上限的跨 AP 原子预约。
- a/b/g/n/ac/ax 可编辑速率表、能力门控、失败重试、移除策略恢复默认。
- AP 原生客户端/IP 表合并，修复 AC 重启后仍在线客户端 IP 空白。真实平板 ADB cycle 已通过（184103）。
- 均衡规则和 AP 探测/最近覆盖、客户端数/差值/拒绝次数；漫游 k/v/r/门限与规则、AP 变长触发/候选协议、双 UDP 假 AP 测试。
- IGMP 组播 IP 列表（IPv4/IPv6）、清空/能力门控及模拟下发。
- 全局 RRM 规则/周计划/手动任务、NDP 测量命令/变长邻居报告、Go 计划和持久化任务。模拟图信道分配/功率范围、配置变更取消、重启恢复已有测试。实际 AP NDP 测量尚未跑。

真机 AP 设置测试：LED off/on（报告回读一致）、心跳、客户端保活/空闲时间、离线自主管理共 7 项 ACK。后者 ACK 不等于 AC 断线场景验证。所有设置已恢复。第一轮客户端回归发现 IP 恢复缺口，已修复并通过真实平板重连/HTTPS/API 一致性。

UI：2 套能力、7 页、23 次表单模拟提交通过（包含速率、均衡、默认漫游、RRM），无 JS 错误。尚需扩展新菜单/扩展设置检查。隔离 Playwright 环境在 .local/ac100/ui-venv。

复核纠正：PPSK 在这份 TL-AC100 V6 只有共用 Lua 残留；页面 bundle 仅有两条错误文案，没有入口。原厂 QEMU 运行时 ppsk_group/ppsk_user GET 明确记录 No callback operation registered（证据 .local/ac100/ppsk-runtime-check.txt）。因此不是此固件可用功能，不应把它误算成实际 Go 缺项或声称 Go 已实现。与“当前 AP 不报能力就省略”不同。

进行中（不能据此停止）：升级流程/固件格式及 AP 扩展逐项核对；DHCP Mesh Detect 已补精确 Discover-only 分支，但还需物理 AP 切至 Go DHCP 验证和恢复 lab DNS/DHCP。DHCPv6 是否属于已排除的主机网络菜单需按真实固件路径复核，不能只因 dhcpd 链入通用 v6 栈就新增范围。

新发现必须修：旧 ImageData 编码把 C 结构体的 length 字段误当线上字段；V6 @0x63d0f4/@0x63d2e0 实际是 type8 + raw，type1/2 为 1–1024 字节，type5 必须无数据。旧 cweng/apupd.go 的带偏移 pull 协议也是虚构，应换成原厂的 AC 顺序 push msg15 + ACK16，identifier/size+MD5 握手和最终 reset/mask。已导出相关源在 parity-decomp。尚未改升级原型，不能调用它刷真实 AP。

本轮 rate/radio/mobility/RRM/组播等代码已部署（最近约18:58），AP 正常 5GHz 上网；DHCP Mesh Detect/后续改动还没部署。最后 race 失败只因 mobility_test.go 残留 e.Debug=true 在 engine.Run 后赋值，已删除并启动新 race（session45979）；需读结果。



后续进展：
- 真实射频参数矩阵又有38项通过：WMM/短GI/探测响应/分片/RTS/Beacon/DTIM/管理帧速率/RSSI门限/TWT/GI/信道/功率/MU-MIMO/OFDMA及逐项恢复。真实平板双频/HTTPS/AC状态回归通过，证据radio-setting-tests/20261126-191538.json及adb-tests/20261126-191538-cycle.json。
- 原厂天线只接受内置0，旧Go虚构1/2选项导致原生RPC超时，已同时修API/导入校验和UI。GI=-1恢复时漏发导致保留手动GI，已改为显式gi_mode=0。当前实机临时GI=0，部署后需恢复逻辑-1并回读0。ManagementRate=1是保持当前，已去除假下发并修正按频段速率。
- 升级原型已替换：新增firmware包检查现代容器和SafeLoader/内嵌MD5/硬件支持列表；AP能力0x51顶层9正是硬件ID（当前B54610C361B4F086E5B13F665CAFCD73）；0x5b按当前固件ID+计数黑名单修复。新增AP状态软件版本/硬件ID/固件ID。真实AP固件容器解析得到1.0.18、大小30016512及正确硬件ID；用户AC镜像在AP格式检查处被拒绝。
- 升级库/上传/兼容校验/批量定时/取消未开始任务/持久化中断状态/UI已接通。顺序push/1024分块ACK/大固件0xaf/0xb0、子MD5结果0xb1、总校验与授权刷写回复、普通固件最终reset以及重连版本确认，完整UDP假AP验证小镜像和16MiB+4096镜像通过；不曾刷写真AP。校验错误/ACK丢失等分支还需补模拟。
- RRM进一步修复：NDP共享AC MAC持久化；80MHz相邻块重叠成本修正、160MHz候选过滤；启动必须配置已settled；计划先持久化再保存配置并恢复识别，避免崩溃误记未应用。仍需实际NDP测量与恢复。


用户补充范围确认：保留所有通过AC下发至AP执行的设置/AP运行状态/AP间协调；排除AC Linux主机本身的功能。AP端DHCP/ARP/ND防护和广播抑制属于保留范围；AP选择性DHCP按此前明确要求保留为Go可选服务；普通客户端DHCP/DNS/NAT只在实验工具里。

最新结果：单AP NDP全流程实测完成，报告/Go计划/参数回读/提交通过并恢复原始配置（rrm-tests/20261126-193546.json）；GI逻辑已恢复-1实际0，ADB状态/HTTPS通过193648。新版升级实现已部署，但从未执行实际刷写。

新增protection.go/storm.go与UI：DHCP信任IPv4/IPv6/MAC库、ARP/ND绑定、AP/组规则、模式/端口范围、广播/协议速率、ARP/ND/mDNS代理；独立golden和UDP假AP/清理策略测试通过。APOptions新增USB(100)、Mesh(44)、蓝牙(77，模式及子能力77)及继承/UI。源对照发现旧Go把Mesh能力44误用于每SSID组播；已改为43，转单播子能力从44改99。修复公开capwap防护codec的错误额外长度字段和计数校验。后续这些尚未部署。

Go DHCP Mesh Detect Discover-only namespace验证通过。第一次真AP Go DHCP试跑在重启AP前发现dnsmasq虽no-dhcp-interface仍占67，已完整恢复，没有让AP重启。改为临时DNS-only配置（去掉dhcp-行）再次开始，仍在进行，必须读取dhcp-live-test.log并核实恢复。临时runner使用同一个dhcpserver.Serve，不是另写实现。

真机DHCP第二次：Go成功独占67，但原厂CAPWAP Reset(17空)后AP仅重建控制连接，没有任何DHCP包；180秒后自动恢复dnsmasq。原厂AC的apmngr_pkt_reset_pkt_send(mode1)确实是空Reset，所以原有控制重启实现吻合原厂；AP CWWtpReset实际只重启DMS控制会话。AP自身Web的完整设备重启明确为TDCP {method:do,system:{reboot:null}}。新增独立reboot-device操作用于完整AP重启/验证，不能把控制重连称为OS启动证明。还需部署后第三次DHCP真机验证。


第三次Go DHCP真AP测试通过（1950–1952，dhcp-live-tests/20261126-194921）：完整AP重启后真实TP-LINK Discover、Go OFFER、AP REQUEST、Go ACK，Go持久化bound租约192.168.70.50。抓包同时包含Android平板Discover且Go未回复。第一次多个Discover是客户端自身等待/地址检查过程，不能看到前几次重发就宣称Go Offer错误。普通dnsmasq DHCP/DNS已自动恢复，ac100-go在线。Native完整重启操作已应答且待观察AP重新上线。检查后需ADB上网回归。


新增冷启动缺口修复（已于约19:55部署）：AP完整重启后真实平板已联网但AC错过早期上线事件，clients为空，ADB回归明确失败195420。已加AP实时wireless.sta_list全表恢复（仅匹配Go已有SSID/VLAN/射频/WLAN槽，URL解码SSID；普通host_info有线主机不进入；计数不全拒绝；并发新事件优先；不能用旧AP快照抢走另一AP已确认的客户端）。已恢复真实平板MAC/IP/radio2/WLAN1状态。原IP补充函数仍仅合并已确认客户。需继续ADB cycle确认。

还在源码未部署：cweng.ClientTransition事件环（仅确认上线/离线/位置变更，不把探测/许可算上线）；admin/history.go持久化无线射频趋势24h和客户端事件7天，容量限制/查询过滤；history.js图表和记录页面。History/Snapshot测试已通过，尚待完整race/浏览器回归。UI顶栏在线客户端数已改为仅connected。


紧急真机回归待修：1955AC冷重启后NativeSnapshot恢复客户成功，但200113的ADBcycle baseline HTTPS/IP/API通过，WiFi关开后关联失败。Android日志明确ASSOCIATION_REJECTION status1/timeout，两频都失败；不是仅DHCP/IP。Go trace最近没有收到新的private1/2/8a关联请求（只有9/8/13），需继续抓包和AP侧诊断；不能把NativeSnapshot显示恢复当作新关联已修复。当前已暂时关闭band_navigation排除引导因素（备份.local/ac100/bandnav-before-cold-check.json），并通过ADB设置页点GoAC-Lab重连。最终必须恢复策略并通过coldboot+cycle。

未完成事项仍包括：网络模式自动/兼容/高性能的完整原厂行为（72能力的私有9d静默参数，9b ACS及结果）；源默认兼容3次/30秒，高性能5次/15秒，自动切换阈值5AP/30STA，从原始QEMU UCI与uac数据取值；现有代码仅mode1RSSI转换，其他没接完。AP扩展还需蓝牙IoT详细规则/CA、Mesh组网整体流程、AP物理端口能力/可切换RF/轨道高速模式等按实际启用页面核对。新增ARP扫描CA命令/报告/API/UI已写但未全面测。所有缺口需继续实现，不能在审计或汇报后停。

关联失败发现根因候选（20:07左右）：原厂V6 `_apmngr_pkt_config_status_req_listen @0x60a598` 每次Configure Response必发私有26软件控制开关 {mask=0x6f,value=0x2e}。Go fileIdentity.Envelope=nil，RegisterV6Compatibility仅Join，Manager.Mobility=nil又跳过26，因此冷AP从未初始化这些开关；热AP可能保留先前原厂AC值。已在RegisterV6Compatibility新增msg5/prio120必发26基线。需部署并实际验证新关联；不能只据源码宣布问题已解决。源码AP厂商handler元数据需用十进制地址转hex准确导出，不手写猜地址；正确列表sw-info-correct.symbols。


初始化26修复已部署并验证：200755 ADBcycle baseline 2.4GHz HTTPS/API通过，Wi-Fi关开后5GHz HTTPS/API通过；双频优选已恢复enabled=true。AP源码 CWManageSpecMsgSw @ed848证实控制位更新AP Fit Report Mask与cwWlanSysMode。需要再完整冷重启+重复DHCP/客户端回归，确保不是再次靠热状态。DHCP上次pcap在stop时丢了内核最后1–2秒（leasefile确定REQUEST已处理但pcap缺末尾REQUEST/ACK）；脚本加bound后2秒flush，正在重测完整抓包。

20:09 后完整冷启动复验通过：dhcp-live-tests/20261126-200825/dhcp.pcap 明确包含真实 AP 的 Discover/OFFER/REQUEST/ACK，也包含 Android 的 Request 而 Go 静默。服务已恢复正常实验 DHCP/DNS/NAT。ADB 201205-cycle：冷 AP 后新连接与再次 Wi-Fi 关开均 5 GHz、HTTPS 和 API MAC/IP/radio/WLAN 一致通过。此前冷启动 private26 基线漏发已实际复验修复。

20:24 左右新改动已部署：VLAN 池客户端实际 VLAN 到服务槽位恢复；空 DHCP lease JSON null 不再导致 map 写入 panic；原生客户端快照只更新协商速率，保留 CAPWAP 流量/带宽统计。自动/高性能/兼容模式的生效模式、5AP/30STA 自动阈值、private9d 5次15s / 3次30s、private55 RSSI 统计开关与周期已接通；模拟真实 UDP 验证。漫游候选结果失败保留并仅重试未确认 AP，全部相关 AP ACK 后才开始回连限制。双模拟 AP 拒绝再重试回归通过。

新增高性能漫游 ACS：9b dwell100、零基射频索引与原厂空格/范围信道语法；9c packed 9-byte report 解析/状态；测量任务、共同信道选择（BSS / load）、配置保存和提交确认、超时不改配置、与 RRM/升级互斥、API/UI。真实 UDP 模拟扫描上报→计算→保存→settled 后完成通过，尚待当前 AP 实测，三射频角色/双5g分段选择还须完善。

ARP scan 真机仅 ACK 无报告，进一步对照原厂 uac_arp_defend_do_scan 发现要求 subcap16 bit0，非 general16 即足够。当前 AP 未报该子能力且 vendor handler 表没有 CA，因此修接口和 UI 为精确子能力门控；不能把 ACK 当扫描完成。packed IPv4/MAC codec 和 UDP 报告进入 AP 状态测试通过。

全 Go test ./... 与核心 race 在这些改动后通过；UI 2能力/10页/33表单无 JS 错误。仍需新增 ACS/非空历史/扩展页面用例。当前持续工作：升级失败分支、Bluetooth IoT 规则/服务器/CA、Mesh 完整管理、RF角色/rail字段、wireless central_forward/auto_bind 等逐项核对。蓝牙两个原厂 JCS GET 已确认运行时有注册；不是 PPSK 那种残留，需实现。不要在这些缺项没处理时宣称全部完成或停在审计结论。

20:25 单 AP 漫游模式/ACS 真机通过（mobility-tests/20261126-202450.json）：兼容/高性能控制与RSSI统计17s获ACK；真实9c上报2g1/6/11和5g36/40，Go选择11/36，下发/回读/commit完成；恢复原6/40，ADB202542-cycle通过。真实扫描报告证实9字节/行的接收布局正确。

新增蓝牙完整管理（约20:38部分已部署，后续修改尚未部署）：BluetoothConfig规则/AP和分组、MQTT服务器、扫描信道/RSSI/去重/10项AD过滤、主题、TLS/CA、运维账号、服务器连接指令和AP真实连接状态报告，API/UI/持久化/脱敏、替换AP迁移目标。AP basic bluetooth数字含义已对照bluetooth_rule_from_json纠正：0网关、1价签、2运维（原先误写0关闭/2IoT）。Rule字段同此原厂内部枚举。运维0xa9密码不是明文/MD5：apmngr_encrypt_alg_md5_v2替换表，已按原始常量实现并golden测试。IoT CA 0xde文件名/MD5是CA内容MD5的32ASCII；0xdc中的CA摘要又是文件名字符串MD5（源bluetooth_md5_string），已按源码区别处理。蓝牙server绑定先持久化发送意图，规则删除/换服务器/重启后用0xdd断开旧连接。UDP假AP证书/完整策略/删除后重启/秘密保留与状态报告测试通过。

源范围进一步纠正：原厂Vue蓝牙只启用MQTT，Lua里HTTP、scanning_window/interval等是共用残留，不是当前可用Web功能；目前Go按实际Vue+uac走MQTT。rail_high_speed_mode_switch的uac rdmngr_db_sqlite_cb明示no support column_name，并未接收字段，不能凭共享Lua字段杜撰下发。central_forward/local_wserv_sync/auto_bind尚在继续核对，不能擅自记完成。

大报文修复：Go原发送端没有CAPWAP分片，60KiB证书超DTLS单条/MTU；新增capwap.FragmentPacket，1200字节以内加密片，13bit偏移；重组总容量放宽65535（原52224只是单UDP缓冲，不能当重组上限）。60KiB乱序重组和真实UDP模拟大证书传输通过。观察器同时接收9和8中AP报告。未对当前无蓝牙能力的AP伪造连接测试。

20:39 真实双频矩阵首次最后恢复步骤捕获Android缓存IP/尚无路由过渡（不是持续AP失败）；测试改等待AP commit ACK后13s及Android wlan0实际inet地址，ping显式绑定wlan0。20:42完整矩阵通过：baseline/重连/分别关闭5g和2g/恢复双频再重连全部HTTPS和AC状态一致（adb-tests/20261126-204202-radios.json）。恢复成功后不再finally重复保存相同配置引起二次commit。

无线历史：加载恢复最后采样时间、丢弃NaN/Inf数值、退出时最终flush；图表断线超过5min断开曲线，不连接虚构区间。UI增蓝牙服务器/规则与非空历史图，共2能力×10页/37表单通过。固件加强非零/重复硬件ID/固件ID与SafeLoader分区重叠检查；升级模拟新增首包丢ACK重试（假AP在ACK丢失时仍真正处理命令）、错误会话/错误分块/最终校验失败不授权、持久化成功后才授权。新代码还修重连时已知FirmwareID冲突不能仅凭同版本字符串判升级完成，以及各子校验阶段清旧重复报告。须最终完整测试/race/部署/ADB回归。

后续管理补齐（约21时后，源码尚待统一部署）：
- AP物理端口C8/12严格解析稀疏ID、上下联角色与LAG标记，APDB top4/5提供旧端口数/Trunk；API/UI只对实际下联端口配置，不再假定1–8。继承可选USB/蓝牙/端口/RF模式等按AP能力筛选，AP显式覆盖仍严格拒绝不支持的配置。
- WLAN自动绑定频率按原厂16bit掩码区分2g1…8与5g1…8，不能当作AP射频ID。绑定、准入、客户端快照、均衡/漫游目标和UI统一使用频段顺序。UDP假AP在射频1=5g/2=2g时创建→移频→删除VAP通过。
- 重连清除旧会话applied/status/settled失败记录并保留WLAN所有权，避免旧扩展策略失败阻塞新连接。ACS三射频5g低/高子段分组与高性能模式手动信道同步已有模拟用例。
- Mesh新增配置/API/UI：回传SSID/密钥/自动生成并持久化令牌、管理密码、自动已知AP接入、两种回传模式；配置阶段和运行期下发76/0a/0e/0f/15/17。节点发现81字节、拓扑38字节及增量操作解析，按真实报告确认任务，重启未确认任务不自动重发。配对查询原厂先发临时RE许可76/14(60秒)再回复76/0d；Go已补正确顺序，忙碌时拒绝且不打断已有配置。模拟测试通过编码、权限、先后顺序、报告/ACK区分、重启状态；真实多AP Mesh尚未验证，Mesh子AP代理/同步细节仍需继续核查，不可记全完成。
- 整机射频工作模式BB能力列表、BC三字节控制(开关/原生模式ID/保留0)、General92门控和AP设置UI已实现。模式ID与rf_mode位图不是同一个枚举。稀疏ID/坏报文/不支持模式、继承筛选和golden通过；RRST关联约束表和实际重启行为仍在核对。
- 当前最新常规go test ./...通过（后续RF改动后核心测试亦通过）；浏览器2能力×10页×39表单无JS错误；新版尚未部署和真实ADB回归。不能把这些当作其它硬件的实机成功。

21:22 真机回归通过：新版服务重启后 AP 约58秒重新 RUN；ADB baseline与Wi-Fi关开均5200MHz、网关/DNS/HTTPS及AC客户端AP/radio/IP一致（adb-tests/20261126-212236-cycle.json）。部署后立即执行测试曾因尚无online AP提前StopIteration；工具已改为等待上线，不把初始化过渡当成无线失败。

Mesh传输继续补齐（尚未部署）：原厂local_serv_packet_send用private75把普通CAPWAP元素转交子AP。Go新增严格count/MAC/长度/嵌套校验的public codec、授权子AP的独立Join/Configure/CSE/RUN会话，控制/JSON/报告按子AP归属，父AP与子AP共享传输命令门和序号空间但不共享ACK/客户端/遥测归属，父会话断开取消子会话，子AP断开不能删除父DTLS。模拟完整生命周期、父ACK不能确认子请求、子射频报告不污染父AP、未知子AP拒绝、父断开清理通过；仍待race与真实多AP Mesh验证。AP显式profile的能力校验已统一到restore/copy/group编辑等入口，避免导入绕过单台编辑校验。


21:36–21:37 新的真实数据面证据：wireless-data-tests/20261126-213626-rates.json，两种3000kbps限速真实下载/上传分别约3.46/3.17和3.44/3.20Mbps，基线73.58/24.37Mbps，恢复87.34/19.36Mbps；策略已恢复。213715-disconnect.json真实msg25/26后收到AP source=disassociate的disconnected事件，再自动连接。不是只验证ACK。新增实验HTTP服务仅绑定USB实验地址，测试结束已关闭，平板临时文件已删除。

后续源码：蓝牙Channels和LAG Ports原先[]uint8被Go JSON编为Base64，现改数字列表Marshal，旧配置Base64仍可读取。射频模式/关联默认参数的字节列表同样修复。UI管理拆AP与分组/Mesh/蓝牙三页签，不再堆成超长页面；受阻配置也计入首页待处理。40个表单通过，包括稀疏端口与LAG回显。

RRST：7f矩阵(table_mask32/radioNum8/featureMask32/cols8/可选regions)及90控制count8+TLV解析；普通编辑按原厂feature0筛选，保留编辑射频、尽量少改同组射频，失败原子不改cfg；restore/RRM/ACS保存和运行期均校验组合。Discovery已按原厂advertise表协议1和参数0xf。模拟合法联动/坏包/约束失败通过。BindID的SSID映射语义和优化器如何选择受约束候选仍需继续核对，不能仅因parser存在称全部做完。最新完整go test/race/vet/无CGO ARM64构建与40表单均通过；正在部署本轮最新版，须后续真实回归。

21:52 最新部署后ADB复验通过（adb-tests/20261126-215202-cycle.json）。此前215138-cycle.json测试失败是脚本一直拿首次频段快照等待；当时实时平板/API都已5GHz且一致，脚本已改为比较时重读Wi-Fi信息，保留失败步骤，复验成功。不要把旧失败文件删除或当成实机已通过。

21:57 开放网络真机通过：security-tests/20261126-215733-open.json，临时GoAC-Open-Test只按自动频率掩码256绑定5GHz；平板真实接入/HTTPS和AP/radio/WLAN映射正确，临时网络已从平板忘记、Go服务删除完成，GoAC-Lab恢复。首轮215604-open.json曾已接入/HTTPS但脚本错误地读取不存在的clients.ssid字段而KeyError，修为实际槽位核对后重测通过。混合WPA2/WPA3正在验证（日志security-mixed-latest.log，工具finally会恢复Lab并删除临时服务）；不要同时操作ADB/WiFi或部署，先读工具结果与清理状态。

新源码未部署：ClientEvent/ClientTransition记录当时的SSID与service_id，避免服务重命名/删除、槽位复用后把历史客户端标成新SSID；Manager的解析回调只解析已提交的owned槽，回调在ClientTable锁外避免反向锁序。NativeSnapshot直接记录真实SSID，断开/统计保持旧事实，新的关联更新身份。API/历史/CSV/UI已接通；新增槽位复用/配置未提交/回调锁序测试，待完整race/UI和部署。API已断开的客户端不会因AP离线被改成ap_offline。

新源码未部署：原厂apdb_get_sensor_radio_id_bitmap证实FunctionType1为传感射频，自动/显式SSID绑定排除它，频段顺序不因跳过传感射频而挪位；本AP没有目标频段时同步显示not_applicable而不虚称设备ACK。对应模拟通过。


22:38 本轮范围澄清已纳入：保留由 AC 配置、AP 执行的 DHCP/ARP/ND 防护与 AP 协调；不纳入 AC Linux 自身网络/安全管理。先前明确要求的选择性 TP-Link AP DHCP 仍是可选 Go 服务，普通客户端 DHCP/DNS/NAT 仅实验工具。

22:32 ARP 实机发现并修复能力分支：V6 arp_defend_wtp_pkt_send 的 ap_entry+0x2b7 是 subcap16 bit0（通过 main→sub-index 常量表独立核对），只有它存在才发送过滤/端口位；旧 AP 接受布尔1而不识别0x25/0x35。修正后匹配绑定的 ARP 与 HTTPS正常，错误有线发送方绑定时3发0收，恢复3发3收/上网；证据 protection-tests/20261126-223257.json。该 AP brLocalArpFilter 明确跳过 host WLAN接口，所以不能把它当无线入口防护已验证。错误无线绑定仍能上网的旧失败记录保留；ARP过滤不能推导已有邻居缓存的IP流量一定阻断。

22:38 AP DHCP防护实测通过：protection-tests/20261126-223833-dhcp.json，可信实验DHCP192.168.70.1时平板重新获取地址并HTTPS；只信任192.168.70.240后Wi-Fi已关联但45秒后wlan0没有IPv4；AP仍在线。原保护策略及平板上网已恢复。这与 Go 的选择性 DHCP Server 是两个功能。

当前源码尚待本轮统一部署：RRM按AP合法RRST行联动求解，ACS选择满足跨频段约束的次优组合，不再先独立优化再失败；继承禁用/传感射频排除覆盖测量发送与计划。BindID已核查原厂消费者：_apdb_add_ap_to_aplist与apdb_add_rrst_to_model只是输出元数据，控制算法未发现SSID重映射用途，Go保留原值供API展示，不凭字段名杜撰SSID移动。
当前源码尚待部署：客户端真实SSID/service_id已于22:28部署；新增实际AP sta_list VLAN事实到API/CSV/UI/历史，断开保留当时身份。保护绑定库按IP+MAC去重，允许不同网络复用IP。原厂全局max_bind_num实读1024，但此V1 AP parser固定ARP48/ND24，新增已核对型号的容量校验/API/UI，过量不下发、不静默截断。Mesh升级按父子传输组排队，循环角色元数据得到同一规范标识；重启/复位、Mesh未确认操作和RRM与升级互斥。


22:45 固定VLAN100真机通过：vlan-tests/20261126-224524.json，平板192.168.100.53、实际VLAN接口HTTP、Go客户端SSID/VLAN/IP一致；临时接口/服务器/SSID已清理，Lab上网恢复。
22:47/22:51 AC离线两组真机通过：offline-tests/20261126-224734-true.json 与225112-false.json。Go服务实际停止，两组已有连接5/20/40秒均HTTPS；启用离线自管理时新的Wi-Fi接入/HTTPS成功，禁用时新的接入65秒未成功。两组均恢复Go、原AP设置和Lab上网。不要把实验短期结果外推为全部型号/无限离线时长。
22:55 密码修改正反真机通过：security-tests/20261126-225524-psk-change.json，旧密码真实接入→下发新PSK→旧保存密码25秒不能接入→新密码HTTPS200，临时SSID删除及Lab恢复。该次工具UI忘记网络返回false，另发现此前混合SSID仍有保存记录：已用授权shell的精确network_id清理并核对全部五种临时SSID均无保存记录（security-tests/cleanup-followup.json）。WiFiUI.forget已改优先按精确SSID查ID/忘记并复查，不再把点击按钮当作已清理。
22:57 新版部署：新增无线模式/WMM/带宽组合验证及UI联动；N/ac/ax/be WMM必开，legacy仅20/auto，N-only不允许80以上；Fragmentation和ShortGI按原厂界面禁用不适用项。radio原生测试的WMM off场景改为11a/20，不能用AX+WMMoff的模型回读证明组合合理。新增无线槽位空表清理，在提交后原子副本中删除空项，未提交的保留槽位不动。全Go测试/vet、核心race、纯GoARM64/Windows构建与2能力×10页×41表单（含WMM模式联动）通过。正在新版基础status后测试实际11ax速率表，尚未出结果，不可记通过。


23:00 用户明确纠正验收边界：重点是Go AC，不是AP设备/空口性能。停止继续吞吐/PHY/逐项空口验收；后续以AC配置/API/UI/能力生成命令/上报状态/持久化/超时重连失败路径为准，以真实UDP模拟AP为主，实机仅必要的接入、命令/回报和基础可用性冒烟。不能再把AP硬件行为没逐项验证列为Go AC实现缺口或完成阻塞。

已对正在跑的rate-table工具发送SIGINT，让finally先恢复速率策略和原射频配置；证据rate-table-tests/20261126-230113.json保留为主动中断，不记成功或AC功能失败。原策略/射频已恢复，工具自动WiFi恢复未成功，随后通过明确选择GoAC-Lab恢复并确认HTTPS200（约23:02）。临时HTTP服务已随工具退出。禁止继续该吞吐测试或38项PHY复验，除非用户后续明确要求。

当前继续转向AC端管理闭环：核查备份/恢复/复制/替换、Mesh成员策略与任务持久化、异步任务冲突、完整UI能力/表单和协议模拟。发现候选：Mesh授权长期依赖completed任务，备份不包含成员意图、1000任务容量会堵塞后续操作；AP替换也未迁移这类成员策略。应补独立可备份的成员意图并用模拟验证，不需要另一台真实AP。速率表AC/AX四字节编码已从V6 assembler核对，无需依靠AP吞吐判断AC编码对错。

23:04–23:33 AC 管理补齐：

- Mesh 独立成员授权/撤销配置纳入备份与替换；nil 表示旧格式，显式空数组表示权威空名单，旧任务不能重新引入撤销的授权。策略写盘成功才标记任务完成；失败保留待确认并重试。1000 条任务按终态安全压缩至 800，保留不确定/活动任务；恢复/替换与未确认 Mesh 任务互斥，退役父 AP 不能授权旧子节点。真实 UDP 假 AP 收配对命令、返回 ACK 和拓扑，完成并写盘；备份/重启/旧日志/存储失败和容量测试通过。
- AP 复制修复：保留目标名称、位置、分组和模板；未勾选射频时保留目标 profile、独立射频及整机模式/地区；勾选时复制源有效继承结果。跨目标能力不兼容整批不写入。
- 原厂客户端 get_client_rssi_data 对应补充 1h RSSI 历史、按客户端查询和 UI 曲线。独立记录 RSSIAt，IP/轮询不把旧值变成新样本；采样新鲜度、会话边界、保留上限、持久化恢复有测试。
- 原厂 AP get_ap_count_trend 对应补充 AC 在线/离线/总数趋势，按变化/分钟采样，排除已替换身份。无线趋势和客户端曲线浏览器夹具已覆盖。
- 旧客户端表缺少 VLAN 时仍按唯一已提交 SSID/射频恢复状态，未知 VLAN 不编成 0；同名服务歧义不随便选择，明确 VLAN 可区分。修复与当前 AP 报不报字段无关，不要求实机枚举。
- 补原厂 AP 列表 CSV 导出，字段来自 AC 标签/分组和设备事实；排除退役清理记录，不带凭据；公式/控制字符转义与客户端导出共用。

23:31 首次部署本轮 Mesh/复制/历史修复；随后发现 AP CSV 缺口已补，最终合并版本待统一部署。此前全 Go、vet、核心 race、无 CGO ARM64/Windows 构建和2能力×10页×49次界面提交均通过；CSV 之后正在跑最后回归，不提前标记最终部署成功。

新增 docs/ac-acceptance.md 作为 AC 验收索引，功能表/实施计划清理旧“继续吞吐/38项PHY复验”等过期安排；后续不恢复这些 AP 测试。

23:34 CSV 合并版部署；全 Go/vet、核心 race、ARM64/Windows无CGO构建及49表单通过。23:36 基础只读冒烟通过：adb-tests/20261126-233608-status.json，平板保持5200MHz，网关/HTTPS和AC AP/射频/IP一致；没有切换Wi-Fi、射频或跑吞吐。

最后UI核查发现继承射频与历史筛选写死1–6：已改为实际上报/已存配置编号，编辑全局默认时保留radio8及其高级字段，并加浏览器回归。首次新增回归因部署重连时从真实API读到空客户端而等不到“信号记录”按钮，属于夹具依赖真实客户端；已改固定模拟客户端，避免把实验时序当AC界面失败。等待修正后回归与最终包含该UI的部署，不重复做AP配置矩阵。

23:37 UI 修复最终回归通过：49次提交，两能力×三台模拟AP×10页，无JS错误，radio8及高级参数保持。模拟客户端固定后还将信号断言限定在弹窗内，避免主表同值造成选择器歧义；不是产品错误。包含全部改动的Go全测试与两目标无CGO构建再次通过，Go源码的vet/核心race此前已通过且此后仅更改静态资源。最终版重启后仅等待AP RUN/commit、查询状态/导出/历史，不重复改AP射频或跑吞吐。私有汇总将保存到.local/ac100/ac-acceptance-summary.json。

23:39 最终版部署确认：AP已RUN且configuration-commit应答，无failed/blocked/pending配置；API已收到本次会话的GoAC-Lab客户端（radio2/WLAN1/实际IP），RSSI历史确认有新会话测量点，非只读取旧历史。AP CSV导出1台、AP数量趋势正常。证据汇总.local/ac100/ac-acceptance-summary.json已落盘，含最终二进制SHA256、检查结果和只读基础冒烟索引。本轮AC管理修复已部署完成；没有新增吞吐、PHY或逐开关AP行为测试。
