# 原 AC 配置备份：离线解析、转换和缺项检查

转换工具读取原 `.bin`，生成 Go 的配置备份、`controller.json`、协商型号库与不含配置值的审查报告。它不连接 AP，也不修改运行中的控制器。原 AC 的 Linux 系统配置不作为 Go 程序的运行环境导入。

## 本次备份的范围

用户提供的备份元数据为 **TL-AC100 4.0、配置格式2.0.2**（2.0.2不是固件版本；用户随后确认实际软件为1.4.4 Build240911 Rel.65759n）。已识别4条AP配置、8路射频、7个无线服务、1个分组、2条组播规则、19个客户端名称。4条配置记录不代表当前有4台设备在线；历史记录保留。原配置内容和转换文件仅保存在本地忽略目录，不进入Git或测试夹具。

本次26张SQLite表均分类：11张属于应用转换（包含空的ARP/DHCP可信服务器表），1张为空的模板表，8张为排除的认证数据，2张为AC Linux DHCP静态租约，4张为排除的网络运维。另读取了JSON协商型号库。审查报告列出表名、行数、列名和范围；不输出密码、SSID或客户端名称值。非空未知应用表会使转换失败，不静默跳过。

备份选择了**固定高性能模式1**。已按官网V4.0 **1.4.3 Build240715 Rel.80898n**补入共同信道协调，转换保留模式1，并写明模式参考来源。用户的1.4.4公开包未取得，使用相近版本已经用户允许；不能宣称1.4.4与1.4.3逐函数相同。完整路径和版本边界见[高性能模式对照](v4-high-performance-reference.md)。候选与估速也按同一V4来源选择，不再沿用V6活跃选择器；PMK已双版核查，原V4特殊同步NULL缺陷有意修复。详见[跨版本复核](cross-version-mobility-review.md)，不宣称完整1.4.4二进制等价。

转换默认保留源模式0、1或2。模式0按V4 1.4.3补入数量触发、兼容态回退和重分配，保留`cur_wireless_network_mode`；已有实际模式2不能因导入而自动提升。只有显式传入`--target-mode=0/1/2`才生成更改模式的版本，并在报告记录差异。最早的模式2评审稿已被本次保留模式1的转换稿替代，本次没有应用任何转换配置。

## 型号库核对

- 项目`data/apdb.json`与提供的V6固件`etc/apdb.bin`解密内容逐字段一致：81个普通型号、3个多AP型号，共102个硬件版本。
- 已从官网下载的V4 1.4.3再次逐字段核对，静态库与V6也完全相同。
- 原加载器遗漏`multi_ap_list`，现已补上，并保留互斥信道、默认带宽与Trunk元数据。
- 新型号不一定出现在这份静态老库中。备份中的`apdb_nego.db`包含两种型号及三个能力版本；Go支持把它作为`apdb-nego.json`载入。
- 按`model ID → fwid → 零基ap_index → 硬件版本/硬件ID`选择，不能把同一型号的AX和BE能力合并。当前AP的private51报告优先；缓存只用于缺报告的回退。
- JSON库与private51共享模式、带宽、信道派生。读取NSS、WPA3、160/240/80+80、扩展能力与专用射频类型。

完整库校验使用Go解密器，比较整个JSON对象而非只数型号：

```sh
go -C uacgo run ../tools/audit_model_library.go
```

## 迁移中的语义处理

| 内容 | 处理 |
| --- | --- |
| AP名称、分组、保活/空闲、离线自管理、LED、端口/聚合、Mesh、设备账号 | 保留应用设置；0/255/-1/null等值按字段含义处理，不能都转成“关闭”命令 |
| 原通用AP/RF参数行 | 编译成已有型号模板，保留不适用设备的参数，由现有能力投影控制下发；同设置模板去重。本次生成3个模板 |
| 信道、功率档位、射频开关 | 保持每台AP与实际radio归属的显式覆盖，旧内部数字AP ID转换为MAC身份 |
| SSID、PSK、混合WPA2/WPA3、隔离、隐藏、编码、更新周期 | 保留；`ssid_code_type=1`为UTF-8，0为GBK，不将不支持的认证降级成开放网络 |
| 自动绑定/手工绑定、VLAN | 手工绑定保留AP/radio/VLAN矩阵；自动绑定的冗余结果不能变成限制未来AP的名单。自动绑定含不同VLAN例外的情况目前明确拒绝，不假装无损支持 |
| 限速 | DB的`bw_ctrl_mode=0`为整SSID、1为每客户端；DB字节速率转换为Go接口的kbps，如256→2048，不能缩小8倍 |
| 客户端名称 | 从`auth_user.db/userNameTable`转为`client_labels`；这个表属于客户端管理，不随认证数据一起排除 |
| 漫游、双频优选、均衡、速率表、RRM | 转换参数、列表及启用状态；自动0、固定高性能1与兼容2分别保留；策略族保留，自动回退2也不改用V6选择器；版本边界单独报告，不发明切换算法 |
| DHCP/ARP防护 | 转换发给AP的可信服务器、绑定与开关；AC本机DHCP租约、DNS、路由、NAT不导入 |
| RADIUS、Portal、认证账户、蓝牙、云、网络运维、机器配置 | 按产品范围排除；Mesh管理密码仅作为AP功能所需字段使用，不配置Go的Web管理员 |

`auto_firm`是**AP自动确认/接入**，不是自动固件升级。原V6 `apmng_set.do_settings`强制它为on；Go的Join已自动接入。不能仅根据名字把它列成自动升级缺项。

原硬件容量/profile不复制。程序容量和原备份未提供的独立程序初值继续使用Go默认值；例如静默参数3/30不冒称为这台V4机器的Flash值。接口默认留空，或用`--interface`指定部署主机上的真实接口，不复制原AC的eth接口名称或IP。

## 使用

在仓库内运行（无需Docker或QEMU）：

```sh
go -C uacgo run ./cmd/acconvert \
  -input /path/to/config.bin \
  -output /path/to/new-private-directory
```

常规转换无需模式参数；只有明确接受改变模式时才增加`-target-mode=2`。输出目录必须不存在，权限0700；文件0600，配置保留原Wi-Fi/AP密钥。

原始备份、转换配置、协商缓存和现场抓包应放在仓库外或`.local/`内。仓库忽略上述配置产物的常用文件名；公开测试使用合成SQLite/UCI数据，不提交实际导出文件。固件证据清单记录来源、地址、哈希和分类，本次更新不增加原固件或解包文件。

输出：

- `go-ac-configuration.json`：Go Web“备份恢复”使用的配置格式。
- `controller.json`：独立程序的数据文件；不是完整运行数据目录。
- `apdb-nego.json`：可选型号缓存，放在运行数据目录的`apdb.json`旁。
- `conversion-report.json`：数量、来源/目标模式、字段与表的分类、迁移警示。

先检查报告，再选定主机接口与管理网络。原AP的IP、管理VLAN、DHCP租约、AC管理员及证书不随应用配置恢复。这里的转换校验不证明这些网络已配置，也不制造AP或客户端在线状态。

## 证据与验证

- `firmware_backuprestore.lua.back_up/parse_conf`调用`cfgSave -e`及`des_crypt -e/-d`。
- `des_crypt` SHA256为`ad361931466e283bc38d31805666107d6dbcf4624ba524a9130878bcbf9e5d1a`。`accrypt_des_decrypt@401498`使用`403b08`的DES key，去除填充后检查前16字节MD5，再取载荷。
- 原`apdb.lua`按fwid索引选`ap_index+1`，`_apdb_parse_radio@6f239c`定义JSON能力字段；`support_80M_80M`不能自行改成别的键。
- 原`host_management.lua`叠加userNameTable名称；`_uac_wserv_packet_send_callback@6dbd74`的限速路径把模式0编码为3、模式1编码为2。

合同及来源文件SHA见`uac-web-behavior-contracts.json`的`vendor-backup-offline-migration`和`complete-model-database-and-negotiation-cache`。合成备份回归覆盖真实SQLite→嵌套包→解密→转换→Go恢复入口、名称保留、VLAN、限速、模板能力投影及固定/自动模式保留、自动实际模式2不升档；不把用户的私人备份作为仓库夹具。

漫游客户端策略与RRM规则现可[分别选择版本](component-strategy-versions.md)。本V4备份的RRM保留为V4，第一/第二5GHz候选域分别转换；修改漫游版本不改写这些规则。
