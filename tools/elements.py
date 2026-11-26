#!/usr/bin/env python3
"""Extract the complete CAPWAP element registry from the uac binary.

Tables (all inside the binary, .data):
  standard elements : PTR array @0x6d2db0, element types 1..0x36  (cw_msg_ele_mngr_get)
  802.11 elements   : PTR array @0x6d2e88, element types 0x400..0x418
  private elements  : PTR array @0x6e6700, sub types 0..0xc0      (cw_msg_ele_priv_mngr_get)

Each entry points to a 0x24-byte mngr struct (symbols g_cw_msg_ele*_mngr in uac_symbol_obj):
  +0x00 u16 element_type     +0x02 u16 pad
  +0x04 ptr  name string (rodata)
  +0x08 u16 min_len          +0x0a u16 max_len
  +0x0c parse_fn  +0x10 assemble_fn  +0x14 create_fn
  +0x18 free_fn   +0x1c dump_fn      +0x20 len_get_fn
Function pointers are verified against uac_symbol_fun.
"""
import json
import struct
import sys
from pathlib import Path
from ac100_env import ROOT

sys.path.insert(0, str(__import__("pathlib").Path(__file__).resolve().parent))
from syms import parse_sym, read_at, SYM_FUN, SYM_OBJ  # noqa: E402

FUNS = parse_sym(SYM_FUN)


def fname(addr):
    e = FUNS.get(addr)
    return e["name"] if e else None


def read_ptr(va):
    b = read_at(va, 4)
    return struct.unpack(">I", b)[0] if b else None


def read_u16(va):
    b = read_at(va, 2)
    return struct.unpack(">H", b)[0] if b else None


def read_cstr(va, n=96):
    b = read_at(va, n)
    if b is None:
        return None
    end = b.find(b"\x00")
    if end < 0:
        end = n
    try:
        return b[:end].decode("utf-8")
    except UnicodeDecodeError:
        return b[:end].decode("latin-1")


def extract_table(table_va, lo, hi, kind):
    out = []
    for i in range(lo, hi + 1):
        p = read_ptr(table_va + (i - lo) * 4)
        if p is None or p == 0:
            continue
        m = {
            "kind": kind,
            "type": i,
            "mngr_addr": f"{p:#x}",
            "type_field": read_u16(p),
            "name_addr": f"{read_ptr(p + 4):#x}" if read_ptr(p + 4) else None,
            "name": read_cstr(read_ptr(p + 4)) if read_ptr(p + 4) else None,
            "min_len": read_u16(p + 8),
            "max_len": read_u16(p + 10),
            "parse": fname(read_ptr(p + 12)),
            "assemble": fname(read_ptr(p + 16)),
            "create": fname(read_ptr(p + 20)),
            "free": fname(read_ptr(p + 24)),
            "dump": fname(read_ptr(p + 28)),
            "len_get": fname(read_ptr(p + 32)),
        }
        m["type_field_ok"] = m["type_field"] == (i & 0xFFFF)
        out.append(m)
    return out


def main():
    std = extract_table(0x6D2DB0, 1, 0x36, "standard")
    ieee = extract_table(0x6D2E88, 0x400, 0x418, "80211")
    priv = extract_table(0x6E6700, 0, 0xC0, "private")
    all_e = std + ieee + priv
    out = {"standard": std, "ieee80211": ieee, "private": priv}
    (ROOT / "ghidra-export").mkdir(parents=True, exist_ok=True)
    (ROOT / "notes").mkdir(parents=True, exist_ok=True)
    (ROOT / "ghidra-export" / "elements.json").write_text(json.dumps(out, indent=1))

    lines = ["kind\ttype\tmin\tmax\tname\tparse\tassemble"]
    for m in all_e:
        lines.append(
            f"{m['kind']}\t{m['type']:#06x}\t{m['min_len']:#06x}\t{m['max_len']:#06x}\t"
            f"{m['name']}\t{m['parse']}\t{m['assemble']}"
        )
    (ROOT / "notes" / "elements.tsv").write_text("\n".join(lines) + "\n")

    bad = [m for m in all_e if not m["type_field_ok"]]
    print(f"standard={len(std)} ieee80211={len(ieee)} private={len(priv)} "
          f"type_field_mismatch={len(bad)}")


if __name__ == "__main__":
    main()
