#!/usr/bin/env python3
"""Check host readiness; --vendor additionally requires the supplied AC100 V6 rootfs."""
import argparse
import hashlib
import importlib.util
import os
import shutil
import subprocess
from pathlib import Path
from ac100_env import REPO, WORK, ROOTFS, LEGACY_FW, KERNEL, HARNESS, LEGACY_SHA256, V6_SHA256
from prepare_firmware import KERNEL_SHA256


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--vendor", action="store_true")
    parser.add_argument("--live", action="store_true", help="also require running QEMU, relay and USB DHCP")
    parser.add_argument("--go-live", action="store_true", help="check Go takeover instead of the vendor relay")
    args = parser.parse_args()
    if args.live and args.go_live:
        parser.error("--live and --go-live represent different owners of UDP 5246")
    failures = []

    def check(label, ready, detail="", required=True):
        print(f"{'OK' if ready else 'MISSING' if required else 'PENDING'} {label}: {detail}")
        if not ready and required:
            failures.append(label)

    search = os.environ.get("PATH", "") + ":/usr/sbin:/sbin"
    for name in ("go", "python3", "node", "mips-linux-gnu-objdump", "qemu-system-mips", "unsquashfs",
                 "mkfs.ext4", "debugfs", "tshark", "tcpdump", "dnsmasq", "ip"):
        found = shutil.which(name, path=search)
        check(name, bool(found), found or "not installed")
    version = subprocess.run(["go", "version"], cwd=REPO / "uacgo", capture_output=True, text=True) if shutil.which("go") else None
    import re
    match = re.search(r"go(\d+)\.(\d+)", version.stdout) if version else None
    check("project Go toolchain", bool(match) and tuple(map(int, match.groups())) >= (1, 26), version.stdout.strip() if version else "Go missing")
    check("Scapy", importlib.util.find_spec("scapy") is not None)
    lua = subprocess.run(["node", "-e", "require('luaparse')"], cwd=REPO / "tools", capture_output=True) if shutil.which("node") else None
    check("luaparse", lua is not None and lua.returncode == 0, "tools/package-lock.json")
    ghidra = Path(os.environ.get("GHIDRA", Path.home() / "tools/ghidra"))
    check("Ghidra headless", (ghidra / "support/analyzeHeadless").is_file(), str(ghidra))
    java = Path(os.environ.get("AC100_JAVA_HOME", "/usr/lib/jvm/java-21-openjdk-amd64")) / "bin/java"
    result = subprocess.run([str(java), "-version"], capture_output=True, text=True) if java.is_file() else None
    check("JDK 21", result is not None and result.returncode == 0 and 'version "21.' in result.stderr, str(java))
    legacy = LEGACY_FW / "usr/sbin/uac"
    check("legacy corpus identity", legacy.is_file() and hashlib.sha256(legacy.read_bytes()).hexdigest() == LEGACY_SHA256, str(legacy))
    check("QEMU kernel checksum", KERNEL.is_file() and hashlib.sha256(KERNEL.read_bytes()).hexdigest() == KERNEL_SHA256, str(KERNEL))
    vendor = ROOTFS / "usr/sbin/uac"
    check("AC100 V6 firmware", vendor.is_file() and hashlib.sha256(vendor.read_bytes()).hexdigest() == V6_SHA256,
          str(ROOTFS), required=args.vendor or args.live)
    ip = shutil.which("ip", path=search)
    tap_name = os.environ.get("AC100_TAP", "ac100qtest")
    tap = subprocess.run([ip, "-4", "addr", "show", "dev", tap_name], capture_output=True, text=True) if ip else None
    check("QEMU TAP", tap is not None and tap.returncode == 0 and "172.30.194.1/30" in tap.stdout,
          f"{tap_name} 172.30.194.1/30", required=args.vendor or args.live)
    if args.go_live:
        from go_lab import status
        check("standalone Go controller", status() == 0)
    if args.live:
        for name, expected in (("qemu", str(HARNESS / "run.img")), ("relay", str(REPO / "tools/tap-relay.py"))):
            pid_file = HARNESS / (name + ".pid")
            pid = pid_file.read_text().strip() if pid_file.is_file() else ""
            cmdline = Path(f"/proc/{pid}/cmdline")
            check(f"live {name}", bool(pid) and cmdline.is_file() and expected.encode() in cmdline.read_bytes(), pid)
    if args.live or args.go_live:
        iface = os.environ.get("AC100_AP_IFACE", "")
        nic = Path("/sys/class/net") / iface
        carrier = nic / "carrier"
        linked = False
        if iface and "/usb" in str((nic / "device").resolve()):
            try:
                linked = carrier.read_text().strip() == "1"
            except OSError:
                pass
        check("USB AP carrier", linked, iface or "source tools/env.sh after ap_link.py up")
        dhcp = subprocess.run(["systemctl", "is-active", "--quiet", "ac100-ap-dhcp"], capture_output=True)
        check("AP DHCP service", dhcp.returncode == 0, "ac100-ap-dhcp")
    print("Persistent work directory:", WORK)
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
