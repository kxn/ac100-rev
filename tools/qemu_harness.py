#!/usr/bin/env python3
"""Drive the vendor TL-AC100 uac inside QEMU over its serial console.

The guest rootfs is the vendor image; a second ext4 disk is mounted at
/mnt/share and appears inside the chroot as /share, so host-side test
scripts and capture output cross the VM boundary without editing the
vendor rootfs.
"""
import os
import shutil
import socket
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
H = Path(os.environ.get("AC100_H", "/tmp/ac100/harness"))
KERNEL = Path("/tmp/ac100/openwrt-24.10.0-malta-be-vmlinux-initramfs.elf")
BASE = H / "base.img"
RUN = H / "run.img"
SHARE = H / "share.img"
SERIAL = H / "serial.sock"
TAP = "ac100qtest"
TAP_HOST = "172.30.194.1"
TAP_GUEST = "172.30.194.2"


class Guest:
    def __init__(self):
        self.s = None
        self.buf = b""

    def connect(self, timeout=30):
        end = time.time() + timeout
        while time.time() < end:
            try:
                self.s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                self.s.connect(str(SERIAL))
                self.s.settimeout(0.2)
                return
            except OSError:
                time.sleep(0.3)
        raise TimeoutError("serial socket")

    def _read(self, timeout):
        end = time.time() + timeout
        out = b""
        while time.time() < end:
            try:
                c = self.s.recv(8192)
                if not c:
                    break
                out += c
                self.buf += c
            except socket.timeout:
                pass
        return out

    def wait_prompt(self, timeout=60):
        self.buf = b""
        try:
            self.s.sendall(b"cd /root\n")
        except OSError:
            pass
        return self.wait_for(b":~# ", timeout=timeout, count=1)

    def wait_for(self, needle, timeout=60, count=1):
        if isinstance(needle, str):
            needle = needle.encode()
        end = time.time() + timeout
        while time.time() < end:
            self._read(0.3)
            if self.buf.count(needle) >= count:
                return self.buf
        raise TimeoutError((needle, self.buf[-2000:]))

    def cmd(self, line, marker=None, timeout=60):
        """Send one shell line; wait for marker echoed+printed (count 2)."""
        if marker is None:
            marker = "__M%d__" % (int(time.time() * 1000) & 0xffff)
            sep = " echo " if line.rstrip().endswith("&") else "; echo "
            line = line + sep + marker
            count = 2
        else:
            count = 2
        self.buf = b""
        self.s.sendall(line.encode() + b"\n")
        return self.wait_for(marker, timeout=timeout, count=count)


    def put_file(self, guest_path, content, timeout=60):
        """Write text to the guest via a serial heredoc."""
        term = "__EOF_%d__" % (int(time.time() * 1000) & 0xffffff)
        marker = "__PUT_%d__" % (int(time.time() * 1000) & 0xffffff)
        payload = f"cat > {guest_path} <<'{term}'\n{content}\n{term}\necho {marker}\n"
        self.buf = b""
        self.s.sendall(payload.encode())
        return self.wait_for(marker, timeout=timeout, count=2)

    def run_lua(self, guest_path, marker, timeout=120):
        self.buf = b""
        self.s.sendall(f"chroot /mnt /usr/bin/lua {guest_path}; echo {marker}\n".encode())
        return self.wait_for(marker, timeout=timeout, count=2)

    def close(self):
        if self.s:
            self.s.close()


def sh(cmd, **kw):
    return subprocess.run(cmd, shell=True, check=True, **kw)


def build_base():
    """Build H/base.img from the extracted vendor rootfs plus test config."""
    src = Path(os.environ.get("AC100_ROOTFS", "/tmp/ac100/rootfs"))
    if not (src / "usr/sbin/uac").exists():
        raise SystemExit(f"vendor rootfs not found: {src}")
    H.mkdir(parents=True, exist_ok=True)
    rootfs = H / "rootfs"
    if rootfs.exists():
        shutil.rmtree(rootfs)
    shutil.copytree(src, rootfs, symlinks=True,
                    ignore=shutil.ignore_patterns("dev"))
    (rootfs / "dev").mkdir(exist_ok=True)
    for d in ("tmp/etc/uc_conf", "tmp/etc/nouci_conf/dbs",
              "tmp/.volatiles/etc/nms_report", "tmp/ac_config", "tmp/run"):
        (rootfs / d).mkdir(parents=True, exist_ok=True)
    cfg = ROOT / "deploy/qemu-config"
    if (cfg / "etc_config").exists():
        shutil.copytree(cfg / "etc_config", rootfs / "tmp/etc/uc_conf",
                        dirs_exist_ok=True)
    if (cfg / "nms_report").exists():
        shutil.copytree(cfg / "nms_report",
                        rootfs / "tmp/.volatiles/etc/nms_report",
                        dirs_exist_ok=True)
    if BASE.exists():
        BASE.unlink()
    sh(f"truncate -s 256M {BASE}")
    sh(f"mkfs.ext4 -q -F -d {rootfs} {BASE}")
    print("BASE", BASE)


def start_qemu():
    if SERIAL.exists():
        SERIAL.unlink()
    # clean tap
    subprocess.run(["sudo", "-n", "ip", "link", "del", TAP],
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    sh(f"sudo -n ip tuntap add dev {TAP} mode tap user $(id -u)")
    sh(f"sudo -n ip addr add {TAP_HOST}/30 dev {TAP}")
    sh(f"sudo -n ip link set {TAP} up")
    shutil.copyfile(BASE, RUN)
    if SHARE.exists():
        SHARE.unlink()
    sh(f"truncate -s 32M {SHARE}")
    sh(f"mkfs.ext4 -q -F {SHARE}")
    relay = subprocess.Popen(["python3", str(ROOT / "tools" / "tap-relay.py")],
                             stdout=open(H / "relay.log", "wb"),
                             stderr=subprocess.STDOUT)
    (H / "relay.pid").write_text(str(relay.pid))
    qemu = subprocess.Popen([
        "qemu-system-mips", "-M", "malta", "-m", "256", "-vga", "none",
        "-kernel", str(KERNEL),
        "-drive", f"file={RUN},format=raw,if=ide,index=0",
        "-drive", f"file={SHARE},format=raw,if=ide,index=1",
        "-netdev", f"tap,id=ap,ifname={TAP},script=no,downscript=no",
        "-device", "pcnet,netdev=ap,romfile=",
        "-object", f"filter-dump,id=apcap,netdev=ap,file={H/'capwap.pcap'}",
        "-serial", f"unix:{SERIAL},server=on,wait=off",
        "-monitor", "none", "-display", "none", "-no-reboot",
    ], stdout=open(H / "qemu.log", "wb"), stderr=subprocess.STDOUT)
    (H / "qemu.pid").write_text(str(qemu.pid))
    return qemu


def setup_guest(g):
    g.connect()
    g.wait_for(b"Please press Enter", timeout=40)
    g.s.sendall(b"\n")
    g.wait_prompt(timeout=40)
    g.cmd("mount /dev/sda /mnt && mount --bind /dev /mnt/dev && mount -t proc proc /mnt/proc")
    g.cmd("mkdir -p /mnt/share && mount /dev/sdb /mnt/share && echo SHAREMNT")
    g.cmd("for t in $(seq 1 32); do ip -4 addr show dev br-lan 2>/dev/null | grep -q '192.168.1.1' && break; sleep 1; done; "
          f"ip addr add {TAP_GUEST}/30 dev br-lan")
    g.cmd("touch /mnt/tmp/uac_init_trace_open; "
          "chroot /mnt /sbin/ubusd & for t in $(seq 1 5); do test -S /mnt/tmp/run/ubus.sock && break; sleep 1; done; "
          "chroot /mnt /bin/tddpd & true")
    g.cmd("chroot /mnt /usr/bin/lua -e \"local db = require [[luci.torchlight.uac.wportal_sqlApi]]; "
          "db.portal_create_portal_entry_table(); db.auth_server_create_radius_table()\"")
    g.cmd("rm -f /mnt/tmp/uac_init_done; chroot /mnt /usr/sbin/uac & "
          "for t in $(seq 1 40); do test -s /mnt/tmp/uac_init_done && break; sleep 1; done; "
          "cat /mnt/tmp/uac_init_done", timeout=60)


def stop_qemu():
    for name in ("qemu.pid", "relay.pid"):
        p = H / name
        if p.exists():
            try:
                pid = int(p.read_text().strip())
                os.kill(pid, 15)
            except Exception:
                pass
    time.sleep(1)
    subprocess.run(["sudo", "-n", "ip", "link", "del", TAP],
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)


def extract(path):
    out = subprocess.run(["debugfs", "-R", f"cat {path}", str(SHARE)],
                         capture_output=True)
    return out.stdout.decode("utf-8", "replace")


if __name__ == "__main__":
    if sys.argv[1] == "build":
        build_base()
    elif sys.argv[1] == "start":
        if not BASE.exists():
            raise SystemExit("base image missing; run: python3 tools/qemu_harness.py build")
        start_qemu()
        g = Guest()
        setup_guest(g)
        print("READY", (H / "qemu.pid").read_text())
    elif sys.argv[1] == "stop":
        stop_qemu()
    elif sys.argv[1] == "extract":
        print(extract(sys.argv[2]))
