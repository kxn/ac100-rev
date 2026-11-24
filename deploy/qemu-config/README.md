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

## 当前进度（uac 已能跑过大半模块初始化）

已依次通过：profile → apdb → apmngr(settings/aplog/crashdump/diagnose) →
bluetooth/ftp → rate_db → wservice(igmp) → wsta → apupd → wportal。

迭代中又确认的坑：

7. `apmng_rate` 里 `11a_base`/`11a_supp` 必须是 **list**，`11a_mult` 是标量；
   `11n_*`/`11ac_*` 是标量。
8. **同名段不能重复**：`get_profile` 以 `.type` 为键只保留第一个段，
   重复段的键会被静默忽略（合并段是必须的）。
9. 布尔型 UCI 选项（如 `apmng_wserv.igmp_settings.igmp_snooping_enable`、
   `authentication.portal.https_enable`）同样走 onoff_map，必须是 `on`。

剩余（当前停在这里）：

- `event_params` 包结构未知：uac 需要 `getUciSection(10001020)` 这类**数字段名**。
- `profile[sta_bind_info->max_ageing_time]` 仍取不到（段名待确认）。
- `device_info.sw_version` 的格式（`uac_com_get_dev_sw`：解析 "x.y.z Build N Rel.M"）。
- `wportal` 的 `dns_upd_intv` 与 sqlite 表 `portalTable`/`radiusTable`
  （这些表正常由 uac 自己建，缺表可能只是初始化顺序问题）。
