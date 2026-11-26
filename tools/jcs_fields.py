#!/usr/bin/env python3
"""Extract direct json-c key literals from JCS handler functions.

The vendor uac links libjson-c.so.2; its PLT stubs sit at 0x8b9xxx and are
mapped to dynamic symbols through the ELF jump-slot relocations.  We
disassemble LOAD1 once, then run a small forward dataflow per handler to
recover the (json object, key) arguments of json_object_object_get/add.
"""
import os
import re
import subprocess
import sys
from pathlib import Path

from ac100_env import ROOT
from ac100_env import ROOTFS as FW
UAC = FW / "usr/sbin/uac"
SYM = FW / "usr/sbin/uac_symbol_fun"
from ac100_env import ASM
LOAD1_END = 0x8ba180


from ac100_env import build_vendor_asm as build_asm



def read_cstr(va):
    data = UAC.read_bytes()
    if not (0x400000 <= va < LOAD1_END):
        return None
    off = va - 0x400000
    end = data.find(b"\0", off)
    if end < 0:
        return None
    b = data[off:end]
    if not b or len(b) > 96:
        return None
    try:
        return b.decode("utf-8")
    except UnicodeDecodeError:
        return None


def load_syms():
    out = []
    for line in SYM.read_text().splitlines():
        p = line.split()
        if len(p) >= 4:
            try:
                out.append((int(p[0], 16), int(p[1], 16), " ".join(p[3:])))
            except ValueError:
                pass
    out.sort()
    return out


def load_plt():
    data = UAC.read_bytes()
    rel = subprocess.run(
        ["mips-linux-gnu-readelf", "-rW", "--use-dynamic", str(UAC)],
        capture_output=True, text=True).stdout
    got = {}
    for line in rel.splitlines():
        m = re.match(r"([0-9a-f]{8})\s+\S+\s+R_MIPS_JUMP_SLOT\s+\S+\s+(\S+)", line.strip())
        if m:
            got[int(m.group(1), 16)] = m.group(2)
    plt = {}
    for addr in range(0x8b9000, LOAD1_END, 16):
        off = addr - 0x400000
        w0 = int.from_bytes(data[off:off + 4], "big")
        w1 = int.from_bytes(data[off + 4:off + 8], "big")
        if (w0 >> 16) == 0x3c0f and (w0 & 0xffff) == 0x008d and (w1 >> 16) == 0x8df9:
            imm = w1 & 0xffff
            imm = imm - 0x10000 if imm >= 0x8000 else imm
            plt[addr] = got.get((0x8d0000 + imm) & 0xffffffff, "?")
    return plt


INS = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S+)\s*(.*)$")


def load_ins():
    ins = {}
    for line in ASM.read_text().splitlines():
        m = INS.match(line)
        if m:
            ins[int(m.group(1), 16)] = (m.group(3), m.group(4).split("#")[0].strip())
    return ins


def s16(x):
    x &= 0xffff
    return x - 0x10000 if x >= 0x8000 else x


def imm(s):
    try:
        return int(s, 16) if s.startswith("0x") else int(s)
    except ValueError:
        return None


UNK = None
BRANCH = ("beq", "bne", "beqz", "bnez", "bgez", "bgtz", "blez", "bltz",
          "bgezal", "bltzal", "beql", "bnel", "beqzl", "bnezl", "bgezl",
          "bgtzl", "blezl", "bltzl", "bgezall", "bltzall")
JUMPS = ("j", "b", "bal", "jal")
CALLER = ("a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5",
          "t6", "t7", "t8", "t9", "v0", "v1", "ra", "gp", "at")


def step(st, mn, ops):
    st = dict(st)
    p = [x.strip() for x in ops.split(",")] if ops else []
    if mn == "lui" and len(p) == 2:
        v = imm(p[1])
        st[p[0]] = (v << 16) & 0xffffffff if v is not None else UNK
    elif mn in ("addiu", "addi") and len(p) == 3:
        v, b = imm(p[2]), st.get(p[1])
        st[p[0]] = (b + v) & 0xffffffff if (b is not None and v is not None) else UNK
    elif mn == "ori" and len(p) == 3:
        v, b = imm(p[2]), st.get(p[1])
        st[p[0]] = (b | v) & 0xffffffff if (b is not None and v is not None) else UNK
    elif mn in ("li",) and len(p) == 2:
        v = imm(p[1])
        st[p[0]] = v & 0xffffffff if v is not None else UNK
    elif mn in ("move",) and len(p) == 2:
        st[p[0]] = st.get(p[1])
    elif mn == "or" and len(p) == 3 and p[0] == p[1] == p[2]:
        st[p[0]] = st.get(p[2])
    elif mn in ("lw", "lh", "lhu", "lb", "lbu", "lwl", "lwr", "mfhi", "mflo"):
        if p:
            st[p[0]] = UNK
    elif mn in ("jal", "jalr", "bal"):
        for r in CALLER:
            st[r] = UNK
    elif mn in ("addu", "subu", "slt", "sltu", "slti", "sltiu", "andi",
                "xori", "sll", "srl", "sra", "sllv", "srlv", "srav", "negu",
                "not", "mul", "div", "divu", "rem", "remu"):
        if p:
            st[p[0]] = UNK
    return st


def analyze(start, size, ins, plt):
    end = start + size
    init = {"zero": 0}
    for r in CALLER + ("s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp", "sp"):
        init[r] = UNK
    states = {}
    work = [(start, init)]
    hits = []
    steps = 0
    while work:
        pc, st = work.pop()
        while start <= pc < end and pc in ins:
            steps += 1
            if steps > 120000:
                return hits
            old = states.get(pc)
            if old is not None:
                merged = {}
                changed = False
                for k in st:
                    v = st[k] if old.get(k) == st[k] else UNK
                    merged[k] = v
                    if v != old.get(k):
                        changed = True
                if not changed:
                    break
                st = merged
            states[pc] = dict(st)
            mn, ops = ins[pc]
            if mn == "jal":
                tgt = imm(ops)
                if tgt is not None:
                    name = plt.get(tgt)
                    if name in ("json_object_object_get", "json_object_object_add"):
                        st_after = step(st, *ins[pc + 4]) if pc + 4 in ins else st
                        key = st_after.get("a1")
                        s = read_cstr(key) if isinstance(key, int) else None
                        if s:
                            hits.append((pc, name, s))
            if mn in ("j", "jal", "b", "bal"):
                if pc + 4 in ins:
                    st = step(st, *ins[pc + 4])
                if mn in ("j", "b", "bal"):
                    t = imm(ops.split(",")[0])
                    if t is None:
                        break
                    pc = t
                else:
                    pc += 8
                continue
            if mn in BRANCH:
                if pc + 4 in ins:
                    st = step(st, *ins[pc + 4])
                t = imm(ops.split(",")[-1])
                if t is not None:
                    work.append((t, dict(st)))
                pc += 8
                continue
            if mn == "jalr":
                if pc + 4 in ins:
                    st = step(st, *ins[pc + 4])
                pc += 8
                continue
            if mn == "jr":
                break
            if mn == "jal":
                if pc + 4 in ins:
                    st = step(st, *ins[pc + 4])
                pc += 8
                continue
            st = step(st, mn, ops)
            pc += 4
    return hits


def main():
    build_asm()
    syms = load_syms()
    ins = load_ins()
    plt = load_plt()
    registry = ROOT / "notes/vendor-web/jcs-registry.tsv"
    handlers = {}
    if registry.exists():
        for line in registry.read_text().splitlines():
            p = line.split("\t")
            if len(p) >= 4 and p[2].startswith("0x"):
                handlers[int(p[2], 16)] = p[3]
    else:
        for a, s, n in syms:
            if "jcs" in n:
                handlers[a] = n
    print("handler\tname\tkind\tkey\tpc")
    seen = set()
    for addr in sorted(handlers):
        sym = next((n for a, s, n in syms if a == addr), "")
        if addr in seen:
            continue
        seen.add(addr)
        size = next((s for a, s, n in syms if a == addr), 0)
        for pc, fn, key in analyze(addr, size, ins, plt):
            kind = "in" if fn.endswith("_get") else "out"
            print(f"{addr:#010x}\t{sym}\t{kind}\t{key}\t{pc:#010x}")


if __name__ == "__main__":
    main()
