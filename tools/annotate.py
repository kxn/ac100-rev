#!/usr/bin/env python3
"""Annotate raw objdump disassembly with vendor symbol names (uac_symbol_fun).
Output: asm/ directory - one annotated .asm per function, plus func_index.tsv.
Only LOAD1 (text) range is disassembled raw; functions outside are skipped.
"""
import json
import re
import sys
from pathlib import Path

# repo root (ac100-rev checkout); override with AC100_REV_ROOT
RE_DIR = Path(__import__("os").environ.get("AC100_REV_ROOT",
    str(Path(__file__).resolve().parents[1])))
RAW = RE_DIR / "raw_text.asm"
OUT = RE_DIR / "asm"

LINE = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s")


def main():
    syms = json.loads((RE_DIR / "syms.json").read_text())
    funs = {int(a, 0) if isinstance(a, str) else a: o for a, o in syms["functions"].items()}
    funs = {int(a): o for a, o in funs.items()}
    starts = sorted(funs)

    OUT.mkdir(parents=True, exist_ok=True)
    index = open(RE_DIR / "func_index.tsv", "w")

    cur_name = None
    cur_fh = None
    cur_start = None
    total = 0

    def close_cur():
        nonlocal cur_fh, cur_name
        if cur_fh:
            cur_fh.close()
            cur_fh = None

    with open(RAW) as f:
        for line in f:
            m = LINE.match(line)
            if m:
                addr = int(m.group(1), 16)
                if addr in funs and (funs[addr]["kind"] in ("T", "t")):
                    o = funs[addr]
                    close_cur()
                    cur_name = o["name"]
                    cur_start = addr
                    p = OUT / f"{addr:08x}_{cur_name.replace('/', '_')}.asm"
                    cur_fh = open(p, "w")
                    cur_fh.write(f"; func {cur_name} @ {addr:#010x} size={o['size']:#x}\n")
                    index.write(f"{addr:08x}\t{o['size']:08x}\t{cur_name}\n")
                    total += 1
            if cur_fh is not None:
                # only keep lines inside LOAD1 text range
                if m:
                    a = int(m.group(1), 16)
                    if a >= 0x721164:
                        close_cur()
                        continue
                cur_fh.write(line)
    close_cur()
    index.close()
    print(f"functions written: {total}")


if __name__ == "__main__":
    main()
