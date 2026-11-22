#!/usr/bin/env python3
"""Direct-binary evidence tools for TL-AC100 uac (MIPS32 BE).

Sources of truth (all inside the firmware, no external data):
  - usr/sbin/uac               : the binary itself
  - usr/sbin/uac_symbol_fun    : vendor function map  addr size kind name
  - usr/sbin/uac_symbol_obj    : vendor data-object map addr size kind name
Load mapping (from readelf -l):
  LOAD1 R E : vaddr 0x400000 .. +0x321164  == file offset (vaddr - 0x400000)
  LOAD2 RW  : vaddr 0x731164 .. +0x28774   == file offset (vaddr - 0x410000)
"""
import json
import struct
import sys
from pathlib import Path

# extracted rootfs containing usr/sbin/uac + symbol tables;
# default: this repo's firmware/ tree. Override with AC100_FW_ROOT.
FW_ROOT = Path(__import__("os").environ.get("AC100_FW_ROOT",
    str(Path(__file__).resolve().parents[1] / "firmware")))
UAC = FW_ROOT / "usr/sbin/uac"
SYM_FUN = FW_ROOT / "usr/sbin/uac_symbol_fun"
SYM_OBJ = FW_ROOT / "usr/sbin/uac_symbol_obj"

LOAD1_VA, LOAD1_OFF, LOAD1_SZ = 0x400000, 0x0, 0x321164
LOAD2_VA, LOAD2_OFF, LOAD2_SZ = 0x731164, 0x321164, 0x28774


def parse_sym(path):
    out = {}
    with open(path) as f:
        for line in f:
            t = line.split()
            if len(t) < 4:
                continue
            try:
                addr, size = int(t[0], 16), int(t[1], 16)
            except ValueError:
                continue
            kind, name = t[2], " ".join(t[3:])
            out[addr] = {"size": size, "kind": kind, "name": name}
    return out


def va_to_off(va):
    if LOAD1_VA <= va < LOAD1_VA + LOAD1_SZ:
        return va - LOAD1_VA
    if LOAD2_VA <= va < LOAD2_VA + LOAD2_SZ:
        return va - LOAD2_VA + LOAD2_OFF
    return None


def read_at(va, n):
    off = va_to_off(va)
    if off is None:
        return None
    data = UAC.read_bytes()
    if off + n > len(data):
        return None
    return data[off:off + n]


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else "dump-syms"
    if cmd == "dump-syms":
        funs = parse_sym(SYM_FUN)
        objs = parse_sym(SYM_OBJ)
        out = {"functions": funs, "objects": objs}
        Path(__import__("os").environ.get("AC100_REV_ROOT", str(Path(__file__).resolve().parents[1]))) / "syms.json".write_text(json.dumps(out, indent=0))
        print(f"functions={len(funs)} objects={len(objs)} -> syms.json")
    elif cmd == "extract":
        # extract data objects by name -> files under re/export/data/
        objs = parse_sym(SYM_OBJ)
        names = sys.argv[2:]
        outdir = Path(__import__("os").environ.get("AC100_REV_ROOT", str(Path(__file__).resolve().parents[1]))) / "ghidra-export" / "data"
        outdir.mkdir(parents=True, exist_ok=True)
        for name in names:
            hits = [a for a, o in objs.items() if o["name"] == name]
            if not hits:
                print(f"NOT FOUND: {name}")
                continue
            a = hits[0]
            o = objs[a]
            blob = read_at(a, o["size"])
            if blob is None:
                print(f"UNMAPPED: {name} @ {a:#x}")
                continue
            p = outdir / f"{name}_{a:08x}.bin"
            p.write_bytes(blob)
            print(f"{name} @ {a:#x} size={o['size']:#x} -> {p}")
    elif cmd == "hex":
        va, n = int(sys.argv[2], 16), int(sys.argv[3], 16)
        blob = read_at(va, n)
        if blob is None:
            print("UNMAPPED")
        else:
            for i in range(0, len(blob), 16):
                row = blob[i:i + 16]
                hx = " ".join(f"{b:02x}" for b in row)
                asc = "".join(chr(b) if 32 <= b < 127 else "." for b in row)
                print(f"{va + i:08x}  {hx:<47}  {asc}")
    else:
        print("usage: syms.py dump-syms|extract <names...>|hex <va> <n>")


if __name__ == "__main__":
    main()
