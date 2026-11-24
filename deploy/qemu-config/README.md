# 厂商 uac 的配置文件重建（用于 QEMU 跑真机固件）

固件镜像里**不含**运行时配置：`/etc/config` 是指向 `/tmp/etc/uc_conf` 的软链，
真实值在设备 flash 的配置分区里；镜像自带的 `/etc/tmp_uc_conf/uc.conf` 只是
**键名白名单**（564 行 `config section option`，无值）。

所以要让厂商 `uac` 在 QEMU 里跑起来，必须重建这套配置。

## 文件

| 文件 | 内容 |
|---|---|
| `profile.uci` | UCI `profile` 配置，从 uac 二进制的 `get_profile(section, option)` 调用点逆向（54 个键 / 15 段） |
| `device_info.uci` | 设备身份，`vendor_id` 只接受 `0x00010001`/`0x00020001`/`0x00000001` |
| `rate.uci` | `apmng_rate` 的参考写法（注意真实配置名是 `apmng_rate`） |
| `gen_config.py` | 由 `uc.conf` 键名生成整棵 `/etc/config`，段名必须**具名** |
| `etc_config/` | 当前最好的一组配置（uac 能跑过 apmngr 的全部 restore） |

## 已确认的坑（每一条都是靠错误信息迭代出来的）

1. **段必须具名**：`config settings 'settings'`。uac 用
   `uac_com_uci_parse_req("cfg","sec")` 拼 `<cfg>.<sec>.<opt>` 路径，
   匿名段只能按索引访问，路径查不到。
2. **布尔值走 `&onoff_map`**：必须是 `on`/`off`，写 `0`/`1` 会报
   `transfer string to llint failed`。
3. **`vendor_id`** 决定 apdb 选择：`0x00000001`→0 与镜像里的 apdb 匹配
   （用 `0x00010001` 会报 `apdb vendor not match[0/1]`）。
4. **`export_proto`** 只接受 `tftp`（`on`/`0` 都会失败）。
5. **`sub_proxy_protocol`** 只接受 `http`/`https`；`remote_server`/`server_ip`
   必须是合法 IP（`0` 报 `Illegal remote server`）。
6. `uc.conf` 是 cfgsync 白名单，**不全**：`sub_proxy_*`、`dft_offline_selfmanage`、
   `http_port`/`https_port` 等 uac 会读但白名单里没有。

## 当前进度

`uac` 在 QEMU 里已能跑完 profile 读取、apdb、apmngr 的全部 restore；
停在 `rate_db_init()`：`option[11a_base] not found or type mismatch`
（UCI 侧 `uci get apmng_rate.rate_11a.11a_base` 正常返回，说明是 uac 期望的
类型不同——很可能是 list 或掩码串，待定）。
