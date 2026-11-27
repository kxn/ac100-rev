# Docker / RouterOS Container

同一份纯 Go 程序提供两种镜像和两份独立 Compose 配置：

| 配置 | 镜像默认标签 | 默认用户 / 权限 |
| --- | --- | --- |
| `compose.no-dhcp.yml` | `go-ac:latest-arm64` | UID/GID 10001；删除全部 capabilities |
| `compose.dhcp.yml` | `go-ac:latest-arm64-dhcp` | 容器内 root；仅 NET_BIND_SERVICE、NET_RAW |

DHCP 版仍然**只响应精确 TP-LINK AP 标识**，含原 Mesh Discover 特例；不提供普通 Wi-Fi 客户端的 DHCP、DNS、NAT。AP 执行的 DHCP/ARP 防护两版都有。镜像没有原 UAC、QEMU、固件、运行配置或私钥。

## 构建及离线归档

在仓库根目录运行，需要 Docker + Buildx。默认构建 Linux arm64 的两种镜像，同时加载到本机 Docker 并导出单平台 Docker save 归档及 SHA-256：

```sh
./tools/build_docker.sh
# 同时生成 Linux amd64 与 arm64：
./tools/build_docker.sh --platform linux/amd64,linux/arm64
# 只构建无 DHCP 版本，指定版本标签及目录：
./tools/build_docker.sh --platform linux/arm64 --variant no-dhcp --tag v1 --output-dir ./dist/docker
```

默认文件：`dist/docker/go-ac-latest-arm64.tar`、`go-ac-latest-arm64-dhcp.tar`。`--load-only` 不导出归档。脚本不推送仓库、不启动容器。使用本机构建平台的 Go 工具链交叉编译，目标镜像没有 RUN 步骤，构建不要求安装 ARM 仿真器；测试运行 ARM 镜像才需要 ARM 主机或仿真器。

基础镜像可通过 `GO_IMAGE` / `RUNTIME_IMAGE` 覆盖。镜像构建标签记录源码 revision；本地未提交改动也会参与构建，标签不是未提交源码的证明。

## Linux Docker 启动

两份 Compose 均使用 **host 网络**，使 AP 广播发现及 DHCP 保持二层可达；需要普通的 Linux Docker Engine。这里 `AC_INTERFACE` 是宿主机连接 AP 的真实接口名，不能照填容器桥接网络常见的 `eth0`。控制端口 UDP5246 不需要发布映射。

先复制环境模板，并为 AP 提供匹配的 DTLS 证书和 RSA 私钥。这是 AP 兼容传输材料，不是 Web HTTPS 证书；不要用任意自签证书替代后就认定 AP 能接入：

```sh
cp deploy/docker/.env.example deploy/docker/.env
# 编辑 .env：至少设置 AC_INTERFACE 和需要的管理端口。
sudo install -d -o 0 -g 10001 -m 0750 deploy/docker/certs
sudo install -o 0 -g 10001 -m 0440 /path/to/cacert.pem deploy/docker/certs/cacert.pem
sudo install -o 0 -g 10001 -m 0440 /path/to/privkey.pem deploy/docker/certs/privkey.pem
```

初始化文件权限需要管理员；无 DHCP 版正常运行的程序不需要 root。当前实验环境可使用 `.local/ac100/go-data/cacert.pem` 和 `.local/ac100/go-data/privkey.pem` 作为上述来源；镜像不会自动打包它们。

```sh
# 无 DHCP，默认 arm64：
docker compose --env-file deploy/docker/.env -f deploy/docker/compose.no-dhcp.yml up -d
# amd64 主机先把 .env 中 AC_PLATFORM 改为 linux/amd64，两个镜像标签改为 amd64。
```

启用 DHCP 前复制、编辑池配置；`interface` 必须等于 `AC_INTERFACE`，`server` 必须是该接口已配置的本机 IPv4，`ac` 必须是 AP 可达的控制器地址：

```sh
cp deploy/docker/ap-dhcp.example.json deploy/docker/ap-dhcp.json
# 编辑上述 JSON 后启动，不能与另一份配置同时运行：
docker compose --env-file deploy/docker/.env -f deploy/docker/compose.dhcp.yml up -d
```

示例 IP 为 `192.168.88.2/24`，不会自动给主机配置地址。现有主机 DHCP 服务若已占用同一 UDP67，需要先选择由谁提供 AP DHCP；镜像不接管其它服务和主机网络设置。

两版共用 `go-ac_ac-data` 数据卷，存放 `controller.json`、SQLite、AP 状态及租约。切换版本时 UID 会变化，先停止原容器，再用目标配置做一次仅更改数据所有权的初始化，然后启动：

```sh
docker compose --env-file deploy/docker/.env -f deploy/docker/compose.dhcp.yml down
# 示例：由 DHCP 切回无 DHCP；反向则换成 compose.dhcp.yml。
docker compose --env-file deploy/docker/.env -f deploy/docker/compose.no-dhcp.yml run --rm --no-deps \
  --user 0:0 --cap-add CHOWN --cap-add DAC_OVERRIDE --cap-add FOWNER ac init-data
docker compose --env-file deploy/docker/.env -f deploy/docker/compose.no-dhcp.yml up -d
```

初始化容器不启动 AC/DHCP，不改变保存的配置。不要使用 `down -v`，除非确实要删除全部持久化数据。

## Web 管理端口

在 `.env` 中修改，然后重新创建容器：

```ini
AC_HTTP_HOST=0.0.0.0
AC_HTTP_PORT=18090
```

host 网络直接监听主机的 `18090`，不写 `ports: 18090:8090`。无 DHCP 版要保持零额外权限，应选择不小于 1024 的管理端口；低端口是否可用还取决于宿主机的低端口绑定设置。默认 Compose 只监听 `127.0.0.1:8090`；开放局域网访问时设置管理接口地址或 `0.0.0.0`。Web 当前没有登录认证，应只开放到可信管理网。容器启动明确使用新增的 `--http-allow-remote`，普通宿主机启动仍默认只允许回环地址。

环境变量还支持 `AC_CONTROL_PORT`、`AC_DATA_DIR`、`AC_DTLS_CERT`、`AC_DTLS_KEY`、`AC_DHCP_CONFIG`、`AC_DHCP_ENABLED=0|1`。证书挂载到 `/certs`，DHCP 文件挂载到 `/etc/go-ac/ap-dhcp.json`。当前入口从绑定接口选择本地控制 IPv4；跨网段时应让 AP 直接路由到该地址或通过已有 DHCP Option43 指向它，不用普通端口映射代替 AP 网络设计。

## CPU 与内存预算

两种镜像默认 `GOMEMLIMIT=64MiB`，Compose 可通过 `.env` 的 `AC_GO_MEMORY_LIMIT` 覆盖，例如 `96MiB` 或 `128MiB`。RouterOS 不执行 Compose，应在其容器环境列表中设置原生 `GOMEMLIMIT`；不设置时使用镜像默认值。

这是 Go 运行时的**软内存预算**，用于调节垃圾回收及归还空闲页；不是进程 RSS 或容器内存硬上限。AP 数量、客户端与历史记录增加时需要提高预算，过低会增加 GC 的 CPU 开销。容器还需要给可执行文件、网络缓冲及文件页缓存留空间，不能把容器硬上限与该值直接设成相同值。默认并非所有 AP 规模下的容量保证。

程序不固定 `GOMAXPROCS`；保留 Go 运行时对 CPU 配额的处理。需要显式限定并行度时可在 Docker/RouterOS 环境中设置 `GOMAXPROCS`，不要通过降低 AP 计时器频率改变漫游、均衡或重传策略来省 CPU。

AP 状态和配置继承避免 JSON 往返拷贝；历史按实际到期时间清理、流式落盘；固件上传和传输使用文件与固定大小缓冲。后台 Web 页签不再每四秒轮询。基准方法、结果和测试边界见 [资源优化记录](../../docs/resource-usage.md)。

## RouterOS arm64

RouterOS 不执行 Compose，使用已有的单平台 Docker save `.tar`，通过 `/container` 配置 veth、环境变量和目录挂载。下面采用官方文档当前 7.26 的 `envlists`、`mountlists`、挂载 `mode` 语法；旧版可能使用 `envlist`、`mounts` 和挂载 `name` 等字段，以本机 CLI 帮助为准。

### 示例前提与文件

- 路由器 `architecture-name=arm64`，已安装与 RouterOS 版本、架构匹配的 `container` 包。可用 `/system/resource/print`、`/system/package/print` 检查。
- 使用支持 Linux 所有权/权限的外部磁盘，例如 ext4；示例磁盘为 `disk1`。不在这里执行格式化。
- AP 管理网为 `192.168.88.0/24`，RouterOS 地址为 `192.168.88.1`，AP 接入的未打标签桥名为 `bridge`。容器固定地址 `192.168.88.2` 须空闲，并从所有 DHCP 地址池中排除；不要同时给 RouterOS 主机配置该 `.2`。
- 若 AP 管理网络在 VLAN 中，先让 veth 加入该管理 VLAN；仅把 veth 加到另一个容器/NAT 网段不会传递 AP 发现广播。
- 优先选择无 DHCP 镜像，由已有 RouterOS DHCP 给 AP 和 Wi-Fi 客户端分配地址。Go AC 仅负责 AP 控制；客户端的网关、DNS、互联网 NAT 使用已有网络配置。

上传文件：

| RouterOS 位置 | 本项目来源 / 用途 |
| --- | --- |
| `disk1/go-ac-latest-arm64.tar` | `dist/docker/go-ac-latest-arm64.tar`，无 DHCP |
| `disk1/go-ac-certs/cacert.pem` | 当前已验证的 AP DTLS 证书 |
| `disk1/go-ac-certs/privkey.pem` | 与证书匹配的 RSA 私钥 |
| `disk1/go-ac-data/` | 持久化数据目录，首次安装可为空 |

当前实验环境的证书位于 `.local/ac100/go-data/cacert.pem` 和 `.local/ac100/go-data/privkey.pem`；镜像不会打包这些私密文件。新装没有实验环境的无线服务配置。若要迁移现有配置，停止原 Go AC 后复制完整 `go-data` 内容至外部数据目录，再做下面初始化；这样包含配置、AP 身份、WLAN 所有权、分配和历史。保留原目录备份，切换期间由一个 AC 管理同一批 AP。

### 开启容器功能

```routeros
/system/device-mode/update container=yes
```

按终端提示进行物理确认：在指定时间内短按 mode/reset 按钮或断电重新上电。官方说明常规软件 reboot 会取消待确认变更；不要长按 reset 恢复出厂配置。此步骤仅在尚未启用时执行。

### 创建网络、环境和挂载

**接口名更正：新版 RouterOS 容器内接口沿用 veth 名称**，本例 `AC_INTERFACE=veth-go-ac`。旧版可能仍叫 `eth0`；初始化容器存活时间很短，正式启动出错时可按后文临时 shell 检查，不能根据普通 Docker 的接口名猜测。

```routeros
/interface/veth/add name=veth-go-ac address=192.168.88.2/24 gateway=192.168.88.1
/interface/bridge/port/add bridge=bridge interface=veth-go-ac
/container/envs/add list=go-ac key=AC_INTERFACE value=veth-go-ac
/container/envs/add list=go-ac key=AC_HTTP_HOST value=0.0.0.0
/container/envs/add list=go-ac key=AC_HTTP_PORT value=18090
/container/envs/add list=go-ac key=GOMEMLIMIT value=64MiB
/container/mounts/add list=go-ac-data src=disk1/go-ac-data dst=/data mode=rw
/container/mounts/add list=go-ac-certs src=disk1/go-ac-certs dst=/certs mode=rw
/container/add name=go-ac file=disk1/go-ac-latest-arm64.tar interface=veth-go-ac root-dir=disk1/go-ac-root envlists=go-ac mountlists=go-ac-data,go-ac-certs user=0:0 cmd=init-data logging=yes
```

修改 `AC_HTTP_PORT` 就是修改容器 Web 的实际监听端口；不写 Docker `ports` 映射。对同一 LAN 内的 AP/管理电脑，无需添加专门的 NAT 规则。现有桥/VLAN/防火墙策略仍需允许 AP 到容器的 UDP5246，以及管理电脑到容器的 TCP18090；Web 当前没有登录，应限制在可信管理网内。

### 两步初始化与正式启动

先 `/container/print detail` 等待镜像导入完成并处于 stopped，再执行：

```routeros
/container/start go-ac
```

等 `init-data` 日志出现且状态回到 stopped（准备数据所有权），再执行：

```routeros
/container/set go-ac cmd=init-certs
/container/start go-ac
```

等证书初始化成功且再次 stopped 后，转为正式的普通用户运行，并把证书挂载改成只读：

```routeros
/container/mounts/set [find list=go-ac-certs] mode=ro
/container/set go-ac user=10001:10001 cmd="" start-on-boot=yes
/container/start go-ac
```

访问 `http://192.168.88.2:18090/`。镜像默认 Go 软预算为 64 MiB；支持当前内存参数的 RouterOS 上，可按实际 AP/客户端规模额外设置容器上限，例如：

```routeros
/container/set go-ac memory-high=100663296 memory-max=134217728
```

对应 96 MiB 回收压力阈值、128 MiB 硬上限；不是 AP 容量保证，规模增长需要一起调大 Go 预算及容器额度。`memory-high` 不是硬限制；超过 `memory-max` 会被终止。

### AP 发现与验收

先确保旧 AC 已退出同一批 AP 的接管。AP/容器同一广播域时可以使用广播发现；如果 AP 保存了旧 AC 地址，需要在 AP 上调整绑定或另行恢复配置，不能仅凭容器运行正常就认为已接管。

也可让 RouterOS DHCP 对 AP 下发控制器地址。Go 自带 DHCP 的 Option43 编码在本项目中为 `01 04 + AC IPv4`，另发 Option138 原始 IPv4。本例 `.2` 的 Option43 为 `0x0104c0a85802`。可在 RouterOS 定义后只分配给 AP 的静态租约，避免覆盖其它设备的厂商选项：

```routeros
/ip/dhcp-server/option/add name=go-ac43 code=43 value=0x0104c0a85802
# 先把对应 AP 的已有租约设为静态；下行只是指定 MAC 的示例，执行前替换。
# /ip/dhcp-server/lease/set [find mac-address="AP-MAC"] dhcp-option=go-ac43
```

已有 `dhcp-option` 列表时保留其中其它项；AP 需要重新获取/续租后才收到新值。该编码是按本项目兼容实现给出的配置，并非所有厂商 AP 通用编码。

检查：

```routeros
/container/print detail
/log/print where topics~"container"
/ping 192.168.88.2
```

在 Web 确认 AP 在线、配置应答/回读状态、客户端上报，最后接客户端验证 DHCP、网关、DNS 和 HTTPS。能打开 Web 只证明管理面可达。

如果日志报找不到网卡，在 stopped 状态临时设 `entrypoint=/bin/sleep cmd=600 user=0:0` 并启动，再 `/container/shell go-ac` 执行 `ip addr`。确认后停止临时进程，恢复 `entrypoint=/usr/local/bin/go-ac-entrypoint cmd="" user=10001:10001`，并将 `AC_INTERFACE` 改成实际接口名，再启动。

### 使用带 DHCP 的镜像

仅当希望由 Go 给 AP 分配地址时，改用 `dist/docker/go-ac-latest-arm64-dhcp.tar`。仍要做上述 `init-data` / `init-certs` 初始化，正式运行保持 `user=0:0`。创建前额外准备 `disk1/go-ac-config/ap-dhcp.json`：

```json
{
  "interface": "veth-go-ac",
  "server": "192.168.88.2",
  "start": "192.168.88.200",
  "end": "192.168.88.220",
  "netmask": "255.255.255.0",
  "gateway": "192.168.88.1",
  "dns": ["192.168.88.1"],
  "ac": ["192.168.88.2"],
  "lease_seconds": 3600,
  "lease_file": "/data/ap-dhcp-leases.json"
}
```

上述地址池也是示例：必须从其它 DHCP 池排除，且确保 RouterOS 现有 DHCP 不会同时向这些 AP 抢答。Go 仍只响应已实现的 TP-LINK AP 标识，Wi-Fi 普通客户端的 DHCP 继续由 RouterOS/其它现有服务处理。

额外挂载：

```routeros
/container/mounts/add list=go-ac-dhcp src=disk1/go-ac-config dst=/etc/go-ac mode=ro
```

创建时采用 DHCP tar、`mountlists=go-ac-data,go-ac-certs,go-ac-dhcp`，初始化后用 `user=0:0 cmd=""` 正式启动。如果同时配置 `AC_DHCP_ENABLED`，DHCP 版需为 `1`；镜像本身已有该默认值。`server` 取容器 `.2`，与接口配置相同；`ac` 也必须为 AP 可达地址。

该版本依赖目标 RouterOS 运行时允许 UDP67 绑定、绑定指定 veth 所需的能力；Docker 的 `cap_add` 不能直接搬到 RouterOS。当前只有 amd64 原生、arm64 QEMU 容器回归，没有 RouterOS 真机验证，不将前者当作后者。

来源：[MikroTik Container](https://manual.mikrotik.com/docs/containers/)、[VETH](https://manual.mikrotik.com/docs/containers/veth/)、[容器 CLI](https://manual.mikrotik.com/docs/cli-reference/container/)、[挂载 CLI](https://manual.mikrotik.com/docs/cli-reference/container/mounts/)、[DHCP Option CLI](https://manual.mikrotik.com/docs/cli-reference/ip/dhcp-server/option/)。

## 回归

```sh
python3 tools/check_docker.py --platform linux/amd64
# ARM 主机，或已注册 ARM64 仿真器的构建机：
python3 tools/check_docker.py --platform linux/arm64
```

检查镜像真实启动、可配置 Web 端口、无 DHCP 时的普通用户/零权限、DHCP 的 UDP67 监听、发现回复宣告地址、数据卷跨重启和两版本切换。测试只创建自己的内部 Docker 网络/容器/数据卷，不连接实体 AP，也不占用主机 UDP67/5246，结束会清理。


本次验证（2026-11-27）：已实际构建 amd64/arm64 × 两版本共4个镜像及归档。amd64 原生运行、arm64 在已有 QEMU binfmt 环境运行，各自完成无 DHCP→DHCP→无 DHCP 三次启动；管理端口18090/18091/18092、证书初始化、UID/capabilities、UDP67启停、CAPWAP发现地址、重启及跨版本配置保留和正常SIGTERM退出均通过。Compose 两配置解析及自定义管理端口通过；Go全量测试/vet、admin/acd race及可执行固件证据合同通过。所有临时容器、网络和数据卷已清理，原实验服务没有替换。
