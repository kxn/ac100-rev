#!/usr/bin/env python3
"""Drive the vendor TL-AC100 uac inside QEMU over its serial console.

The guest rootfs is the vendor image; a second ext4 disk is mounted at
/mnt/share and appears inside the chroot as /share, so host-side test
scripts and capture output cross the VM boundary without editing the
vendor rootfs.
"""
import os
import argparse
import shlex
import shutil
import socket
import subprocess
import sys
import time
from pathlib import Path
from ac100_env import ROOT, HARNESS as H, KERNEL, ROOTFS, require_uac

BASE = H / "base.img"
RUN = H / "run.img"
SHARE = H / "share.img"
SERIAL = H / "serial.sock"
TAP = os.environ.get("AC100_TAP", "ac100qtest")
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
                H.mkdir(parents=True, exist_ok=True)
                with (H / "serial.log").open("ab") as log:
                    log.write(c)
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
        """Wait for a standalone completion line, independent of console wrapping."""
        if marker is None:
            marker = "__M%d__" % (int(time.time() * 1000) & 0xffff)
        sep = " " if line.rstrip().endswith("&") else "; "
        line += sep + "printf '\\n%s\\n' '" + marker + "'"
        self.buf = b""
        self.s.sendall(line.encode() + b"\n")
        return self.wait_for(b"\n" + marker.encode() + b"\r\n", timeout=timeout)


    def put_file(self, guest_path, content, timeout=60):
        """Write text to the guest via a serial heredoc."""
        term = "__EOF_%d__" % (int(time.time() * 1000) & 0xffffff)
        marker = "__PUT_%d__" % (int(time.time() * 1000) & 0xffffff)
        payload = f"cat > {shlex.quote(guest_path)} <<'{term}'\n{content}\n{term}\nprintf '\\n%s\\n' '{marker}'\n"
        self.buf = b""
        self.s.sendall(payload.encode())
        return self.wait_for(b"\n" + marker.encode() + b"\r\n", timeout=timeout)

    def run_lua(self, guest_path, marker, timeout=120):
        return self.cmd(f"chroot /mnt /usr/bin/lua {shlex.quote(guest_path)}", marker, timeout)

    def close(self):
        if self.s:
            self.s.close()


def sh(cmd, **kw):
    return subprocess.run(cmd, check=True, **kw)


def host_tool(name):
    path = shutil.which(name)
    if path:
        return path
    for directory in ("/usr/sbin", "/sbin"):
        path = Path(directory) / name
        if path.is_file():
            return str(path)
    raise SystemExit(f"Missing host tool: {name}")


def setup_network():
    existing = subprocess.run(["ip", "link", "show", "dev", TAP], capture_output=True)
    if existing.returncode:
        sh(["sudo", "-n", "ip", "tuntap", "add", "dev", TAP, "mode", "tap", "user", str(os.getuid())])
    else:
        info = subprocess.check_output(["ip", "-details", "link", "show", "dev", TAP], text=True)
        if "type tap" not in info:
            raise SystemExit(f"Refusing to reuse non-TAP interface {TAP}")
    sh(["sudo", "-n", "ip", "addr", "replace", f"{TAP_HOST}/30", "dev", TAP])
    sh(["sudo", "-n", "ip", "link", "set", TAP, "up"])


def build_base():
    """Build H/base.img from the extracted vendor rootfs plus test config."""
    src = ROOTFS
    require_uac(src)
    for relative in ("lib/ld-uClibc.so.0", "sbin/ubusd", "bin/tddpd", "usr/bin/lua"):
        p = src / relative
        if not (p.exists() or p.is_symlink()):
            raise SystemExit(f"Incomplete vendor rootfs: missing {p}")
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
    sh(["truncate", "-s", "256M", str(BASE)])
    sh([host_tool("mkfs.ext4"), "-q", "-F", "-d", str(rootfs), str(BASE)])
    print("BASE", BASE)


def start_qemu(with_relay=True):
    require_uac()
    if not KERNEL.is_file():
        raise SystemExit(f"Kernel missing: {KERNEL}; run python3 tools/prepare_firmware.py kernel")
    for name in ("qemu.pid",):
        p = H / name
        if p.exists() and Path(f"/proc/{p.read_text().strip()}").exists():
            raise SystemExit(f"Process already running ({p}); stop it before starting again")
    if SERIAL.exists():
        SERIAL.unlink()
    setup_network()
    shutil.copyfile(BASE, RUN)
    if SHARE.exists():
        SHARE.unlink()
    sh(["truncate", "-s", "32M", str(SHARE)])
    sh([host_tool("mkfs.ext4"), "-q", "-F", str(SHARE)])
    if with_relay:
        start_relay()
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
    ], stdin=subprocess.DEVNULL, stdout=open(H / "qemu.log", "wb"), stderr=subprocess.STDOUT,
        start_new_session=True)
    (H / "qemu.pid").write_text(str(qemu.pid))
    return qemu


def start_relay():
    H.mkdir(parents=True, exist_ok=True)
    pid_file = H / "relay.pid"
    if pid_file.exists():
        pid = int(pid_file.read_text().strip())
        command = Path(f"/proc/{pid}/cmdline")
        if command.exists():
            if str(ROOT / "tools/tap-relay.py").encode() not in command.read_bytes():
                raise SystemExit(f"Refusing to replace unrelated relay PID {pid}")
            os.kill(pid, 15)
            for _ in range(20):
                if not command.exists() or not command.read_bytes():
                    break
                time.sleep(0.05)
    with (H / "relay.log").open("wb") as logfile:
        relay = subprocess.Popen([sys.executable, str(ROOT / "tools/tap-relay.py")],
                                 stdin=subprocess.DEVNULL, stdout=logfile, stderr=subprocess.STDOUT,
                                 start_new_session=True)
    pid_file.write_text(str(relay.pid))
    time.sleep(0.1)
    if relay.poll() is not None:
        pid_file.unlink(missing_ok=True)
        raise SystemExit(f"Relay failed: {(H / 'relay.log').read_text()}")


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
    result = g.cmd("if test -s /mnt/tmp/uac_init_done && kill -0 $(cat /mnt/tmp/uac_init_done) "
                   "&& test -S /mnt/tmp/jcs.ui.srv.uac && netstat -lunp | grep -q ':5246 '; "
                   "then printf '\\n__UAC_READY__\\n'; else printf '\\n__UAC_FAILED__\\n'; fi")
    if b"\n__UAC_READY__\r\n" not in result:
        raise RuntimeError("Vendor uac did not become ready; inspect harness/serial.log")


def stop_qemu():
    for name in ("qemu.pid", "relay.pid"):
        p = H / name
        if p.exists():
            try:
                pid = int(p.read_text().strip())
                cmdline = Path(f"/proc/{pid}/cmdline").read_bytes().replace(b"\0", b" ").decode()
                expected = str(RUN) if name == "qemu.pid" else str(ROOT / "tools/tap-relay.py")
                if expected not in cmdline:
                    raise SystemExit(f"Refusing to stop unrelated process {pid} from stale {p}")
                os.kill(pid, 15)
                p.unlink()
            except Exception:
                pass
    time.sleep(1)
    # Keep the reusable TAP interface; never delete an existing host interface.


def extract(path):
    out = subprocess.run([host_tool("debugfs"), "-R", f"cat {path}", str(SHARE)],
                         capture_output=True)
    return out.stdout.decode("utf-8", "replace")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", choices=("build", "network", "relay", "start", "stop", "extract"))
    parser.add_argument("--no-relay",action="store_true",help="start only QEMU for an isolated oracle; keep Go on UDP 5246")
    parser.add_argument("path", nargs="?", help="guest file to extract from share disk")
    args = parser.parse_args()
    if args.command == "network":
        setup_network()
    elif args.command == "relay":
        start_relay()
    elif args.command == "build":
        build_base()
    elif args.command == "start":
        if not BASE.exists():
            raise SystemExit("base image missing; run: python3 tools/qemu_harness.py build")
        start_qemu(with_relay=not args.no_relay)
        g = Guest()
        try:
            setup_guest(g)
        except BaseException:
            stop_qemu()
            raise
        finally:
            g.close()
        print("READY", (H / "qemu.pid").read_text())
    elif args.command == "stop":
        stop_qemu()
    elif args.command == "extract":
        if not args.path:
            parser.error("extract requires a guest path")
        print(extract(args.path))
