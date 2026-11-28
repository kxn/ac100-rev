# AP DHCP、备份配置与设备上报来源复核

## DHCP不能只检查请求厂商名

原AC的AP专用DHCP有两个独立方向：请求侧按Option60筛选AP；应答侧发送厂商标识，供AP判断是否优先接受。只实现前者，普通DHCP互操作测试仍可能通过，但AP在其他服务器存在时会暂不接受这份OFFER。

本轮对照以下原始代码，不以外部试验推导厂商策略：

| 原始来源 | 入口与行为 |
| --- | --- |
| AC V4 1.4.3 / V6 1.0.3 | `usr/lib/lua/dhcp_server/dhcp_load.lua`将`option60`写为`vendor-class-identifier`，将`option138`写为`capwap-ac-v4` |
| AC V4 / V6 Discover与Request | V4 `413c80/414860`，V6 `412f30/4137b0`，AP模式按长度与完整厂商字符串筛选；Mesh Detect只走Discover特例 |
| AC V4 / V6 应答构造 | `410bf0/40ff78`，Mesh Detect请求的Option60应答改成16字节`AC_DETECT_RESULT` |
| 3007GC 1.0.12 | `dhcpcLanInit@1cbdfc`注册OFFER回调`1cbb00`；尾调用校验函数`1cb890`读取应答Option60，与`/device_info/info/info`中的厂商标识按长度和内容比较 |
| 5100HC 1.0.18 | `dhcpcLanInit@252fc4`注册OFFER回调`251734`，同样读取Option60并比较设备厂商；它还按AP工作形态/配对状态决定是否执行Fit分支 |
| 两款AP DHCP状态机 | `2c9f58/385bc0`处理OFFER时调用所注册回调；回调失败不会立即把该OFFER转成选中服务器 |
| 两款AP ACK后发现地址 | `1cdff4/255864`先取Option138，缺失时才取Option43；后者直接读取前四字节，不是先解析`01 04`子TLV |

在Fit或相应管理模式下，OFFER回调的原计数小于10时要求厂商匹配；计数达到阈值后允许回退。它是有条件的接受门禁，不是“始终给AC无限高优先级”，也不是按MAC OUI识别。不能自行加入永久拒绝普通服务器或抢占既有租约的策略。

## 确认的Go偏差与修复

旧实现只验证请求的精确`TP-LINK`标识，正常应答遗漏了Option60；另外无依据地增加Option43子TLV。现修正为：

- 正常AP的OFFER/ACK携带Option60 ASCII `TP-LINK`及Option138原始IPv4列表。
- 精确`TP-LINK MESH DETECT 1.0`只得到OFFER，其Option60为`AC_DETECT_RESULT`；Request仍静默。
- 移除原AC配置没有要求的Option43，不把AP兼容回退的原始IPv4接口误写成子TLV。
- 普通终端、非精确厂商字符串、选择其他DHCP服务器的请求继续静默，不对其他服务的地址发送NAK。

日志里的`dhcp.ap_reply`表示应答已构造。新增`dhcp.reply_sent`表示UDP发送完成，包含事务号、类型、地址和目标；这仍不等于AP已选中。只有选中本服务器的REQUEST和对应ACK/后续租约能支持采用结论。`dhcp.other_server_selected`明确记录选中其他服务器的请求，避免把没有最终租约误判成没有收到Discover。

现场保留日志能够证明：控制器反复构造了预留地址的OFFER，其中一台AP最后选择了其他DHCP，另一台选择了Go并获得ACK。旧应答缺少标识足以触发源码中的拒绝分支，与该序列一致；旧日志没有完整DHCP收包抓取，不能据此单独证明每个OFFER都已到达AP。

源文件及AC函数字节由`check_behavior_contracts.py --verify-firmware`校验；AP端函数由[上报证据索引](ap-reporting-evidence.json)与`audit_ap_reporting.py`校验。它们固定审查样本和入口，不宣称已重建原ISC DHCP的所有系统、故障转移与通用企业功能。

## 网页、运行时与持久化

入口为 **AP管理 → AP DHCP服务**，与安全管理的“DHCP防护 → 可信DHCP服务器”分开。可编辑启停、地址池、掩码、网关、DNS、AC发现地址、租期和固定预留；租约标明待确认OFFER与已确认ACK。

`dhcpserver.Runtime`独立拥有端口67。调整地址池时在同一个socket上替换请求处理器；关闭只关闭这个socket；重新启用重新绑定。配置写入失败或新配置校验失败时保持原服务。DHCP运行错误显示在状态中，不再用`log.Fatal`结束整台AC。配置、收包及租约持久化串行，避免新处理器读到旧处理器尚未写完的租约。

原`--ap-dhcp FILE`是初始化种子；页面保存至数据目录的`ap-dhcp.json`，后续启动优先使用保存值，兼容只读容器挂载。旧JSON没有`enabled`时仍按原显式启用语义处理。全新安装没有配置则关闭，不开端口67；`--ap-dhcp off`明确禁用服务，供无DHCP权限的容器配置使用。启用仍需要Linux端口/接口绑定所需权限，页面不会提升进程权限。

DHCP设置和租约分别保存在`ap-dhcp.json`与租约文件中；它们不在只包含`controller.json`的管理备份中，备份数据目录时需一起保存。已分配地址不被网页修改强制收回，也不会远程重启AP；新预留在AP下次选择本服务时生效。

验证包含：原厂应答标识与发现字段、普通终端静默、Mesh Detect分支、固定预留、只读种子与重启持久化、管理API不修改WLAN/AP配置；独立命名空间中的真实UDP测试覆盖热改地址池/预留、关闭静默和重新开启。以上运行测试验证Go实现，不代替上述固件代码证据。

## 安装位置与Mesh为何看起来不像备份

3007固件包含`My WTP 1`、`Next to Fridge`等示例标识，CAPWAP会把它们上报。备份没有安装位置，原页面却用非空上报字符串回填空配置，造成了假位置。

现将控制器的安装位置与`reported_location/reported_name`分开：空配置保持空，页面显示“未设置”，上报原值只放在能力与调试中。没有按字符串或实验型号过滤；未来AP的任何上报位置同样不冒充用户配置。

备份中的Mesh全局开关为开，AP条目开关为关；转换保留两层，编译进型号模板的AP关闭值仍然抑制实际组网。全局页面显示“开”不等于这些AP已启用，`mesh_device`产品元数据也不是运行开关。新增`mesh_policy_enabled`展示控制器最终配置，计算与实际下发共用函数。用户后来手动关闭的全局配置予以保留，不用重新转换覆盖。

本轮重新解密转换备份，与原转换稿及运行配置逐字段对照，核对AP、服务、射频、客户端命名及固定租约；运行中的地址池/四条固定预留与源备份一致，AC通告地址按目标主机调整。旧离线转换器将AC Linux DHCP排除，部署时这部分单独生成；不能把这种部署步骤描述成`controller.json`已经包含全部服务器设置。新增页面补上这项管理缺口。

详细配置、设备标识与现场报文仅保存在忽略目录。公共说明、合成回归和证据指纹不包含原网络凭据或身份。
