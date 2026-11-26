#!/usr/bin/env python3
"""Download the pinned QEMU kernel or import the expected vendor firmware BIN/ZIP."""
import argparse
import hashlib
import json
import shutil
import struct
import subprocess
import tempfile
import urllib.request
import zipfile
from pathlib import Path
from ac100_env import WORK, ROOTFS, KERNEL, KERNEL_NAME, V6_SHA256, V6_VERSION, require_uac

KERNEL_URL = "https://downloads.openwrt.org/releases/24.10.0/targets/malta/be/" + KERNEL_NAME
KERNEL_SHA256 = "491b29423a335bf13066775b37ebf2e2ca07c9e017c6c35673630719e1c3171f"


def kernel():
    KERNEL.parent.mkdir(parents=True, exist_ok=True)
    if KERNEL.is_file() and hashlib.sha256(KERNEL.read_bytes()).hexdigest() == KERNEL_SHA256:
        print("Kernel already verified:", KERNEL)
        return
    temporary = KERNEL.with_suffix(KERNEL.suffix + ".partial")
    try:
        with urllib.request.urlopen(KERNEL_URL, timeout=60) as source, temporary.open("wb") as target:
            shutil.copyfileobj(source, target)
        if hashlib.sha256(temporary.read_bytes()).hexdigest() != KERNEL_SHA256:
            raise SystemExit("Downloaded kernel SHA-256 mismatch")
        temporary.replace(KERNEL)
    finally:
        temporary.unlink(missing_ok=True)
    KERNEL.with_suffix(KERNEL.suffix + ".sha256").write_text(f"{KERNEL_SHA256}  {KERNEL.name}\n")
    print("Kernel verified:", KERNEL)


def import_firmware(source):
    if ROOTFS.exists():
        raise SystemExit(f"Rootfs already exists: {ROOTFS}; move it aside before importing another image")
    data = source.read_bytes()
    archive_sha = hashlib.sha256(data).hexdigest()
    member = None
    if zipfile.is_zipfile(source):
        with zipfile.ZipFile(source) as archive:
            candidates = [n for n in archive.namelist() if n.lower().endswith(".bin")]
            if len(candidates) != 1:
                raise SystemExit("ZIP must contain exactly one firmware .bin; select the BIN manually")
            member = candidates[0]
            data = archive.read(member)
    matches = []
    position = 0
    while True:
        position = data.find(b"hsqs", position)
        if position < 0:
            break
        if position + 96 <= len(data):
            size = struct.unpack_from("<Q", data, position + 40)[0]
            major = struct.unpack_from("<H", data, position + 28)[0]
            if major == 4 and 96 <= size <= len(data) - position:
                matches.append((position, size))
        position += 4
    if len(matches) != 1:
        raise SystemExit(f"Expected one complete SquashFS v4 partition, found {len(matches)}")
    offset, size = matches[0]
    WORK.mkdir(parents=True, exist_ok=True)
    ROOTFS.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix=".import-", dir=ROOTFS.parent) as temporary:
        temp = Path(temporary)
        image = temp / "rootfs.squashfs"
        image.write_bytes(data[offset:offset + size])
        subprocess.run(["unsquashfs", "-no-progress", "-d", str(temp / "rootfs"), str(image)], check=True)
        require_uac(temp / "rootfs", V6_SHA256)
        (temp / "rootfs").rename(ROOTFS)
    manifest = {"version": V6_VERSION, "source": str(source.resolve()), "archive_sha256": archive_sha,
                "zip_member": member, "firmware_sha256": hashlib.sha256(data).hexdigest(),
                "uac_sha256": V6_SHA256, "squashfs_offset": offset, "squashfs_size": size}
    (ROOTFS.parent / (ROOTFS.name + "-manifest.json")).write_text(json.dumps(manifest, indent=2) + "\n")
    print("Verified vendor rootfs:", ROOTFS)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    sub.add_parser("kernel")
    vendor = sub.add_parser("import")
    vendor.add_argument("image", type=Path)
    args = parser.parse_args()
    if args.command == "kernel":
        kernel()
    else:
        import_firmware(args.image)


if __name__ == "__main__":
    main()
