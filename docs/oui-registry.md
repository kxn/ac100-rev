# IEEE OUI 数据与终端识别

## 已准备的数据

2026-11-28 从 [IEEE Registration Authority 官方公开列表](https://standards.ieee.org/products-programs/regauth/)下载了用于公开 MAC 地址分配查询的全部四类列表：

| 列表 | 前缀位数 | 原始记录数 |
| --- | --- | ---: |
| MA-L | 24 | 40,565 |
| MA-M | 28 | 6,704 |
| MA-S | 36 | 7,306 |
| IAB（历史分配） | 36 | 4,575 |

共59,150条记录、34,119个原始机构名。原始CSV保留在本地下载目录；可提交的接入文件是 `uacgo/data/oui/registry.json.gz`，约1 MiB（含中文参考名）。`manifest.json`记录来源URL、每份CSV的SHA-256、记录数及接入文件指纹。

这里的“完整”是上述IEEE公开MAC分配列表，不是每个实际设备的型号清单，也不包括未公开的机构身份。CID等其他用途的标识不作为随机MAC的厂商证据。接入文件保留每条分配和原始机构名称；通讯地址列不用于终端识别。

## 品牌名称归并

`brand-aliases.json`列出54个常见品牌/厂商组与实际命中的注册机构名，不以品牌名单过滤数据库。没有归并的机构仍可按原名完整查询。它是可审阅的展示层别名，不是对商标所有权、子公司关系或最终产品品牌的证明。

例如小米包含 `Xiaomi Communications Co Ltd`、`Beijing Xiaomi Electronics Co., Ltd.`、`Beijing Xiaomi Electronics Co.,Ltd`等变体。整理先统一大小写、Unicode和标点，再使用明确的名称家族规则；不通过编辑距离或任意子串推断公司关系。`Invivo`、`Vivotek`、`Vivo International`不会并入vivo；`SHENZHEN HONOR ELECTRONIC`不会并入Honor Device；`Amazonia`不会并入Amazon；Hewlett Packard Enterprise单列HPE。

任何MAC匹配结果同时返回原始机构和可选品牌。网卡/无线模组由代工厂或芯片厂申请地址时，OUI可能只说明该零部件的登记机构，不能无条件代表整机品牌。

## Go接入

`uacgo/ouidb`提供离线读取接口，无网络请求、无隐式下载，程序启动时会加载这份内置快照：

```go
f, err := os.Open("data/oui/registry.json.gz")
if err != nil { return err }
defer f.Close()
db, err := ouidb.Load(f)
if err != nil { return err }
matches, err := db.LookupString("00:11:22:33:44:55")
```

`Lookup`/`LookupString`使用36、28、24位最长前缀匹配。它不会把本地管理/随机MAC或组播地址的前三字节当作工厂OUI。普通查询使用排序表二分搜索，加载后无需为每个MAC扫描全部机构。

原始公开表的`080030`含三个不同机构、`0001C8`含两个机构；这些历史歧义全部保留。返回值是同一最具体前缀的全部候选，不能强取第一项当作确定品牌。

更新可运行：

```sh
python3 tools/prepare_oui.py --download
python3 tools/test_prepare_oui.py
cd uacgo && go test ./ouidb
```

生成器保留完整原始分配，输出可重复构建的gzip，并生成品牌归并清单供审核。更新不是运行时自动操作。

## 原厂规则不只查MAC

`uacgo/terminal`的两条OUI查询路径已替换为完整IEEE快照，原厂小表已从生成代码和运行时移除。主机名、DHCP Class、UA与已知品牌的优先级继续沿用原厂规则。完整IEEE数据对更多机构的识别是用户明确要求的展示扩展，不宣称这部分与原厂小表结果一致。输入仍有五类：

| 来源编号 | 输入 | 识别用途 |
| --- | --- | --- |
| 0 | 客户端自身MAC的前三字节 | 初始品牌候选 |
| 1 | AP扩展上报的OUI特征列表 | 品牌候选，查询公开MA-L分配，不把三字节提示补零伪造成28/36位分配 |
| 2 | AP上报的主机名 | 品牌特征，如iPhone、samsung等 |
| 3 | DHCP Vendor Class | 操作系统特征 |
| 4 | HTTP User-Agent | 操作系统特征，如Android、iOS、Windows、HarmonyOS |

各来源按原厂优先级表择优，并非简单“后报覆盖前报”。同优先级采用新结果；文本匹配区分大小写、遇NUL结束，最多处理255字节。UA中的Android是暂定命中，后续HarmonyOS/HMSCore规则可覆盖它。未收到足够来源时保留未知；原厂定义的相关来源均已处理后仍无命中，才转为others。

原固件样本的MAC厂商表有2,029个前缀（已被替换），不是完整IEEE登记库；本次源码样本的补充vendor-OUI特征表为空。品牌名称包含others、apple、samsung、microsoft、nokia、huawei、vivo、oppo、xiaomi、honor。AP没有采集或上报主机名、Vendor Class、UA时，控制器不会凭空补出这些证据。

客户端JSON的`device.recognition`保留`brand_source`、`system_source`与`reported_flags`。`reported_flags=1, brand_source=0`表示目前只用自身MAC前缀判定，不能解释成AP已完成全部终端识别。页面优先显示中文品牌/机构参考名，无译名才回退到英文。悬停可查看原始机构名、前缀及译名性质。IEEE匹配保留在`manufacturer_matches`，不会影响漫游、准入或调度。


## 中文显示与译名来源

原始机构名始终是数据键，归并先于翻译，不按中文译名认定机构相同。完整词条已增加34,018份中文参考显示，100个没有可用中文结果的名称保留英文回退。常见品牌有单独的中文显示别名；机构参考名包括原文汉字、人工订正和离线机器翻译三类，来源随匹配结果返回。

`names-zh.json.gz`保存全部翻译结果，`name-overrides-zh.json`是可维护的人工订正层；它优先于机器译名。机器翻译使用Argos en→zh 1.9/CTranslate2离线模型，包指纹、来源及生成参数写在manifest；模型权重不放进Repo，不在AC或RouterOS中运行翻译。机器结果是参考显示名，不能当成该机构的官方中文注册名称。

常见品牌采用词汇保护，例如Huawei固定为华为，防止机器译成其他近音。公司法定类型单独作保守翻译，Inc不擅自翻成股份有限公司；名称归并也不会因翻译而扩大。CERN、RMIT等抽查发现的错误由明确的原名订正，不用模糊替换改动其他机构。

重新批量翻译可安装准备工具的`ctranslate2`与`sentencepiece`，下载Argos官方英文到中文模型后运行：

```sh
python3 tools/translate_oui.py --model /path/to/translate-en_zh-1_9
python3 tools/prepare_oui.py
```

内置压缩数据随程序交付，只在启动时解码一次；每次查询二分查找，不扫描全表，不联网。运行时不再依赖原固件`macFactory.js`。本地管理/随机MAC不以其前三字节冒充工厂厂商；主机名等其他证据仍可独立识别。


原厂品牌枚举只覆盖部分手机厂商。新增IEEE机构使用兼容的通用枚举槽保存，但其完整登记机构/别名仍独立展示；不会为新品牌编造主机名特征或认证规则。`device.brand_label`用于中文优先显示，`device.brand`及`device.recognition.manufacturer_matches`保留可查询原始依据。

当前x86_64准备机实测，首次加载约0.11秒，保留堆内存约8.4 MiB；这是一次性静态数据，不为每个MAC追加无界查询缓存。ARM64速度与进程总内存应以目标设备为准。


### 人工品牌订正的公开依据

美的、追觅、庆科和欧智通使用品牌自身公开资料核对名称，不用机器直译替代品牌名：

- 美的集团[英文年报](https://www.midea.com.cn/content/dam/mideacn-aem/%E6%8A%95%E8%B5%84%E8%80%85%E5%85%B3%E7%B3%BBen/%E8%8B%B1%E6%96%87%E8%B4%A2%E5%8A%A1%E6%8A%A5%E5%91%8A/2023/MideaGroup-Annual-Report-2023-April-2024-pdf-pdf-coredownload-inline.pdf.coredownload.inline.pdf)列出GD Midea空调公司；[上市文件](https://www.hkexnews.hk/listedco/listconews/sehk/2024/0909/11360251/2024090900028.pdf)并列其中英文名称。
- 追觅[官网](https://www.dreame.tech/)展示品牌中文；其[隐私政策](https://protocol.dreame.tech/terms/zh/general_privacyPolicy.html)列出追觅科技（苏州）有限公司。
- 庆科[官网](https://www.mxchip.com/)与[服务条款](https://cdn.mxchip.com/mxchip_official_website/others/%E5%BA%86%E7%A7%91%E4%BF%A1%E6%81%AF%E7%BD%91%E7%AB%99%E6%9C%8D%E5%8A%A1%E6%9D%A1%E6%AC%BE.pdf)并列上海庆科与Shanghai MXCHIP。
- 欧智通[中文官网](https://cn.fn-link.com/)使用FN-LINK域名及品牌，列出湖南工厂总部。

归并仍保留各个IEEE登记机构。`Dell'Orto`经标点规范化会以“dell ”开头，不能因此归并戴尔；Intel–GE Care Innovations也不作为Intel Corporate品牌。相似名称反例在生成器校验中固定，原始机构及其OUI记录全部保留。
