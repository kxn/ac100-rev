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

## RouterOS arm64

RouterOS 不是 Docker Engine，不执行 Compose。导入脚本产生的单平台 `.tar`，用 `/container` 配置 veth、环境变量和挂载。以下命令按官方现行 RouterOS 7.26 字段 `envlists`、`mountlists`、挂载 `mode` 编写；较旧版本可能使用 `envlist`/`mounts`，应以设备 CLI 为准。

要求设备已安装匹配架构的 container 包并启用相应 device-mode，使用外部磁盘。以下是示例，须把桥、地址和磁盘路径改成实际值：

- `veth-go-ac` 接入 AP 所在的二层桥；容器内接口为 `eth0`。
- 容器地址 `192.168.88.2/24`，网关/RouterOS 为 `192.168.88.1`。
- Web 访问 `http://192.168.88.2:18090`；这是容器地址，没有 Docker 的宿主机端口映射。
- DHCP 版的 JSON `server` 取容器 `.2`，不是路由器 `.1`。AP 不与容器同一广播域时，必须另行配置发现/中继；普通 srcnat/dstnat 不会自动转发发现广播。

上传对应 tar 到 `disk1/`，匹配的证书到 `disk1/go-ac-certs/`。DHCP 版额外把编辑好的 `ap-dhcp.json` 放进 `disk1/go-ac-config/`。

```routeros
/interface/veth/add name=veth-go-ac address=192.168.88.2/24 gateway=192.168.88.1
/interface/bridge/port/add bridge=bridge interface=veth-go-ac
/container/envs/add list=go-ac key=AC_INTERFACE value=eth0
/container/envs/add list=go-ac key=AC_HTTP_HOST value=0.0.0.0
/container/envs/add list=go-ac key=AC_HTTP_PORT value=18090
/container/mounts/add list=go-ac-data src=disk1/go-ac-data dst=/data mode=rw
/container/mounts/add list=go-ac-certs src=disk1/go-ac-certs dst=/certs mode=rw
```

**无 DHCP**：先作为一次性初始化运行，准备数据和证书权限；每次启动前等上一次容器确实停止：

```routeros
/container/add name=go-ac file=disk1/go-ac-latest-arm64.tar interface=veth-go-ac root-dir=disk1/go-ac-root envlists=go-ac mountlists=go-ac-data,go-ac-certs user=0:0 cmd=init-data logging=yes
/container/start go-ac
# 等待 stopped 后：
/container/set go-ac cmd=init-certs
/container/start go-ac
# 再次等待 stopped 后，恢复正式启动参数和只读证书：
/container/mounts/set [find list=go-ac-certs] mode=ro
/container/set go-ac user=10001:10001 cmd="" start-on-boot=yes
/container/start go-ac
```

**带 DHCP**：改用 `go-ac-latest-arm64-dhcp.tar`，同样执行两步初始化；增加挂载并让正式进程保持 `user=0:0`：

```routeros
/container/mounts/add list=go-ac-dhcp src=disk1/go-ac-config dst=/etc/go-ac mode=ro
# 创建时采用 DHCP tar 并加入 go-ac-dhcp 挂载列表；初始化后：
/container/set go-ac user=0:0 cmd="" mountlists=go-ac-data,go-ac-certs,go-ac-dhcp start-on-boot=yes
/container/start go-ac
```

同一实例只选一种镜像，不同时运行两份 AC。切换镜像应保留 `/data` 外部目录，并用目标镜像的 `init-data` 调整所有权。DHCP 版需要 RouterOS 的容器运行时允许绑定 UDP67 和绑定 veth；Docker 的 `cap_add` 字段不能直接搬到 RouterOS。当前没有 RouterOS 真机，目标设备上的权限和二层互通仍需实测，不把普通 Docker 测试冒充 RouterOS 验证。

来源：[MikroTik Container](https://manual.mikrotik.com/docs/containers/)、[容器 CLI](https://manual.mikrotik.com/docs/cli-reference/container/)、[挂载 CLI](https://manual.mikrotik.com/docs/cli-reference/container/mounts/)、[Docker capabilities](https://docs.docker.com/engine/containers/run/)。

## 回归

```sh
python3 tools/check_docker.py --platform linux/amd64
# ARM 主机，或已注册 ARM64 仿真器的构建机：
python3 tools/check_docker.py --platform linux/arm64
```

检查镜像真实启动、可配置 Web 端口、无 DHCP 时的普通用户/零权限、DHCP 的 UDP67 监听、发现回复宣告地址、数据卷跨重启和两版本切换。测试只创建自己的内部 Docker 网络/容器/数据卷，不连接实体 AP，也不占用主机 UDP67/5246，结束会清理。


本次验证（2026-11-27）：已实际构建 amd64/arm64 × 两版本共4个镜像及归档。amd64 原生运行、arm64 在已有 QEMU binfmt 环境运行，各自完成无 DHCP→DHCP→无 DHCP 三次启动；管理端口18090/18091/18092、证书初始化、UID/capabilities、UDP67启停、CAPWAP发现地址、重启及跨版本配置保留和正常SIGTERM退出均通过。Compose 两配置解析及自定义管理端口通过；Go全量测试/vet、admin/acd race及可执行固件证据合同通过。所有临时容器、网络和数据卷已清理，原实验服务没有替换。
