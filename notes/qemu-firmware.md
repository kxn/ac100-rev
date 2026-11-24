# 在 QEMU 里跑厂商 AC 固件（可行，已跑通到 uac 执行）

目标：用真机固件回答协议问题（如 WLAN 安全配置的线格式）。

## 结论：能跑，但厂商 daemon 需要设备 flash 里的配置

| 步骤 | 状态 |
|---|---|
| 固件格式解析 | ✅ TP-LINK 容器；uImage @0x30800（MIPS BE / Linux 4.4.140）、squashfs(LE 元数据) @0x270200 |
| 根文件系统提取 | ✅ `unsquashfs`（38MB，1729 inodes，含 `usr/sbin/uac` MIPS32 BE + uClibc 0.9.33） |
| 内核 | ✅ 用 OpenWrt 的 malta/be 内核（厂商内核板级相关，malta 上起不来） |
| 用户态 | ✅ qemu-system-mips -M malta + 厂商 rootfs（ext4 盘）→ `uac` 原生执行 |
| uac 完整启动 | ❌ 初始化静默失败：设备配置在 flash 分区，**不在固件镜像里** |

关键点：

1. `qemu-mips`（用户态）**跑不了**：`uac` 里有 MCHK 内存检查器写未对齐尾哨兵
   （`lui t8,0xaaaa; ori; sw t8,0x10(s0)`，基址 2 字节对齐），真机由内核 DSEMUL 修正，
   qemu 用户态直接 SIGBUS。换 `-cpu`/环境变量都无效。
2. 必须全系统：`qemu-system-mips -M malta`，内核用 OpenWrt malta/be
   （`openwrt-24.10.0-malta-be-vmlinux-initramfs.elf`，自动带 initramfs 与 shell）。
3. 厂商 rootfs 做成 ext4 盘挂进 guest 再 chroot 执行 —— 内核会做未对齐修正，`uac` 正常进入 main。
4. `-initrd` 自定义 initramfs 不被识别（VFS panic），所以用"内置 initramfs 内核 + ext4 盘"。
5. `-M malta` 需要 `-net none -vga none`（否则缺 `efi-pcnet.rom` / `vgabios-cirrus.bin`）。

## 复现

```sh
# 1) 提取 rootfs
python3 - <<'PY'   # 读 squashfs 超级块，按 bytes_used 切出来
import struct
d=open('TL-AC100 V6.0_1.0.3_Build_260817_Rel.68871n.bin','rb').read()
o=d.find(b'hsqs'); v=struct.unpack('<IIIIIHHHHHHQQQ', d[o:o+56])
open('/tmp/ac100/rootfs.sqfs','wb').write(d[o:o+v[12]])
PY
unsquashfs -d /tmp/ac100/rootfs /tmp/ac100/rootfs.sqfs

# 2) 做成磁盘
dd if=/dev/zero of=vendor.img bs=1M count=192
mkfs.ext4 -q -F -d /tmp/ac100/rootfs vendor.img

# 3) 启动（串口喂命令）
qemu-system-mips -M malta -m 256 -net none -vga none \
  -kernel openwrt-24.10.0-malta-be-vmlinux-initramfs.elf \
  -drive file=vendor.img,format=raw,if=ide -nographic -no-reboot
# guest 内：
#   mount /dev/sda /mnt; mount --bind /dev /mnt/dev; mount -t proc proc /mnt/proc
#   chroot /mnt /usr/sbin/uac
```

## 为什么卡住

- `/etc/config` 是指向 `/tmp/etc/uc_conf` 的软链，运行时由 flash 内容填充；
  镜像里的 `/etc/tmp_uc_conf/uc.conf` 只有 **键名清单**（564 行的 `section option key`），没有值。
- 没有配置时 `uac` 初始化失败并静默 uninit（`cw_ac_data_size_get(): assert(ac) failed`）。
- 继续需要"合成整套设备配置"（profile/network/wireless/dhcpd…），属于独立工作量；
  本地已有 `uacgo/data/profile.ini`（逆向重建的 profile 段）可作起点。

## 备选（更省时）

真机 AP 在线时，直接下发候选配置 + 扫描验证，比把厂商 daemon 完整跑起来快得多。
