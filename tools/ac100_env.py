"""Shared host paths and firmware identities for the two evidence corpora."""
import hashlib
import os
import subprocess
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
ROOT = Path(os.environ.get("AC100_REV_ROOT", REPO)).expanduser().resolve()
WORK = Path(os.environ.get("AC100_WORK_DIR", ROOT / ".local/ac100")).expanduser().resolve()
CACHE = WORK / "analysis"
ROOTFS = Path(os.environ.get("AC100_ROOTFS", os.environ.get("AC100_FW", WORK / "rootfs"))).expanduser().resolve()
LEGACY_FW = Path(os.environ.get("AC100_FW_ROOT", REPO / "firmware")).expanduser().resolve()
ASM = Path(os.environ.get("AC100_ASM", CACHE / "uac-load1.asm"))
FIELDS = Path(os.environ.get("AC100_FIELDS", CACHE / "jcs-fields.tsv"))
LUA_FIELDS = Path(os.environ.get("AC100_LUA_FIELDS", CACHE / "lua-jcs-fields.jsonl"))
KERNEL_NAME = "openwrt-24.10.0-malta-be-vmlinux-initramfs.elf"
KERNEL = Path(os.environ.get("AC100_KERNEL", WORK / KERNEL_NAME))
HARNESS = Path(os.environ.get("AC100_H", WORK / "harness"))
LEGACY_SHA256 = "ddc30fd8aa14e206eaa119e403a4ada64584bef84020c825b8c579bfa4153c68"
V6_SHA256 = "b12d1584fcafda2a71aa9038b41b7e1c5b893b350f3e6edf5105e445d024a912"
V6_VERSION = "TL-AC100 V6.0 1.0.3 Build 260817 Rel.68871n"


def require_uac(rootfs=ROOTFS, expected=V6_SHA256):
    binary = rootfs / "usr/sbin/uac"
    if not binary.is_file():
        raise SystemExit(f"Missing {binary}. Import the complete {V6_VERSION} firmware; see docs/setup.md.")
    digest = hashlib.sha256(binary.read_bytes()).hexdigest()
    if digest != expected:
        raise SystemExit(f"Firmware mismatch: {binary}\nSHA-256 {digest}\nExpected {expected}; the legacy and V6 address maps are different.")
    return binary


def build_vendor_asm():
    """Never reuse disassembly from another binary or a partial previous run."""
    binary = require_uac()
    stamp = ASM.with_suffix(ASM.suffix + ".sha256")
    if ASM.is_file() and stamp.is_file() and stamp.read_text().strip() == V6_SHA256:
        return
    ASM.parent.mkdir(parents=True, exist_ok=True)
    temporary = ASM.with_suffix(ASM.suffix + ".partial")
    try:
        with temporary.open("w") as output:
            subprocess.run(["mips-linux-gnu-objdump", "-D", "-b", "binary", "-m", "mips:isa32r2",
                            "-EB", "--adjust-vma=0x400000", "--start-address=0x400000",
                            "--stop-address=0x8ba180", str(binary)], stdout=output, check=True)
        temporary.replace(ASM)
        stamp.write_text(V6_SHA256 + "\n")
    finally:
        temporary.unlink(missing_ok=True)
