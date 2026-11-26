#!/usr/bin/env python3
"""Classify how no-input handlers use the root JCS data argument."""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import jcs_fields as jf

from ac100_env import ROOT
SCHEMA = ROOT / 'notes/vendor-web/jcs-schema.tsv'
from ac100_env import ASM

GETTERS = {
    0x8b98f0: 'int', 0x8b9580: 'string', 0x8b9a40: 'int64', 0x8b9750: 'double',
    0x8b92f0: 'boolean', 0x8b9770: 'object', 0x8b9240: 'array_length',
    0x8b9520: 'array_get_idx', 0x8b94b0: 'type', 0x8b9be0: 'new_array',
}


def main():
    ins = jf.load_ins()
    syms = jf.load_syms()
    by = {a: (s, n) for a, s, n in syms}
    rows = [l.split('\t') for l in SCHEMA.read_text().splitlines()[1:]]
    for p in rows:
        if p[4]:
            continue
        addr = int(p[2], 16)
        if addr not in by:
            continue
        size, sym = by[addr]
        data_a0 = True
        hits = set()
        for pc in range(addr, min(addr + size, addr + 0x400), 4):
            if pc not in ins:
                continue
            mn, ops = ins[pc]
            parts = [x.strip() for x in ops.split(',')] if ops else []
            if mn == 'move' and len(parts) == 2:
                if parts[1] == 'a0':
                    data_a0 = data_a0 or parts[0] == 's0'
                if parts[0] == 'a0':
                    data_a0 = parts[1] in ('a0', 's0')
            elif mn in ('li', 'lui', 'addiu', 'lw', 'la') and parts and parts[0] == 'a0':
                data_a0 = False
            elif mn == 'jal':
                try:
                    tgt = int(ops, 16)
                except ValueError:
                    continue
                if data_a0 and tgt in GETTERS:
                    hits.add(GETTERS[tgt])
                data_a0 = False
        print(f'{p[0]}\t{p[1]}\t{sym}\t{",".join(sorted(hits)) or "no-root-getter"}')


if __name__ == '__main__':
    main()
