#!/usr/bin/env python3
"""Extract (section, option) string arguments passed to a target function at each call site.

Works on the per-function annotated asm corpus. MIPS o32: args in $a0..$a3.
String constants are materialized with `lui r,0xX` + `addiu r,r,N` (or `li r,N`).
We resolve them against the uac image directly (LOAD1/LOAD2 mapping).
"""
import re
import sys
from pathlib import Path

# repo root (ac100-rev checkout); override with AC100_REV_ROOT
RE_DIR = Path(__import__("os").environ.get("AC100_REV_ROOT",
    str(Path(__file__).resolve().parents[1])))
ASM = RE_DIR / "asm"

DATA = (RE_DIR / "firmware" / "usr/sbin" / "uac").read_bytes()
LOAD1_VA, LOAD1_SZ = 0x400000, 0x321164
LOAD2_VA, LOAD2_OFF, LOAD2_SZ = 0x731164, 0x321164, 0x28774


def read_cstr(va, maxlen=256):
    if LOAD1_VA <= va < LOAD1_VA + LOAD1_SZ:
        off = va - LOAD1_VA
    elif LOAD2_VA <= va < LOAD2_VA + LOAD2_SZ:
        off = va - LOAD2_VA + LOAD2_OFF
    else:
        return None
    end = DATA.find(b"\x00", off, off + maxlen)
    if end < 0:
        return None
    b = DATA[off:end]
    try:
        return b.decode("utf-8")
    except UnicodeDecodeError:
        return b.decode("latin-1")


INS = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S+)\s*(.*)$")
LUI = re.compile(r"(a[0-3]|v0|t[0-9]|s[0-7]),0x([0-9a-f]+)$")
ADDIU = re.compile(r"(a[0-3]|v0|t[0-9]|s[0-7]),\1,(-?[0-9a-fx]+)$")


def track_calls(target_lo, target_hi=None, prefix_lines=14):
    """Scan all asm files; for each `jal <target>`, reconstruct a0/a1 string args."""
    results = {}
    for p in sorted(ASM.glob("*.asm")):
        lines = p.read_text().splitlines()
        for i, line in enumerate(lines):
            m = INS.match(line)
            if not m:
                continue
            dis = m.group(3)
            ops = m.group(4).split("#")[0].strip()
            if dis != "jal" or not ops.startswith("0x"):
                continue
            tgt = int(ops[2:], 16)
            if tgt != target_lo and (target_hi is None or tgt != target_hi):
                continue
            # walk backwards, track register values for a0..a3
            regs = {}
            for back in range(1, prefix_lines + 1):
                j = i - back
                if j < 0:
                    break
                mm = INS.match(lines[j])
                if not mm:
                    continue
                mn, ops2 = mm.group(3), mm.group(4).split("#")[0].strip()
                if mn == "lui":
                    r = LUI.match(ops2.replace(" ", ""))
                    if r:
                        regs[r.group(1)] = int(r.group(2), 16) << 16
                elif mn in ("addiu", "li", "move", "la"):
                    o = ops2.replace(" ", "")
                    if mn in ("addiu",):
                        r = ADDIU.match(o)
                        if r and r.group(1) in regs:
                            lo = int(r.group(2), 16)
                            if lo >= 0x8000:
                                lo -= 0x10000
                            regs[r.group(1)] = (regs[r.group(1)] + lo) & 0xFFFFFFFF
                    elif mn == "li":
                        parts = o.split(",")
                        if len(parts) == 2:
                            try:
                                regs[parts[0]] = int(parts[1], 16) if parts[1].startswith("0x") else int(parts[1])
                            except ValueError:
                                pass
                    elif mn == "move":
                        parts = [x.strip() for x in o.split(",")]
                        if len(parts) == 2 and parts[1] in regs:
                            regs[parts[0]] = regs[parts[1]]
                elif mn in ("lw", "sw"):
                    # memory op kills our tracking for that reg
                    parts = o.split(",")
                    if parts and parts[0] in regs:
                        del regs[parts[0]]
            args = []
            for r in ("a0", "a1", "a2"):
                v = regs.get(r)
                args.append(read_cstr(v) if v is not None else None)
            caller = p.stem.split("_", 1)[1] if "_" in p.stem else p.stem
            results.setdefault(f"{tgt:#x}", []).append((caller, args))
    return results


if __name__ == "__main__":
    targets = [int(x, 16) for x in sys.argv[1:]]
    res = {}
    for t in targets:
        res.update(track_calls(t))
    for tgt, calls in sorted(res.items()):
        print(f"== target {tgt}")
        for caller, args in calls:
            print(f"  {caller}: a0={args[0]!r} a1={args[1]!r} a2={args[2]!r}")
