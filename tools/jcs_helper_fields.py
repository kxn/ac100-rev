#!/usr/bin/env python3
"""For handlers with no direct JSON keys, inspect locally-called helpers."""
import sys
from collections import defaultdict
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
import jcs_fields as jf

from ac100_env import ROOT
SCHEMA = ROOT / 'notes/vendor-web/jcs-schema.tsv'


def main():
    ins = jf.load_ins(); plt = jf.load_plt(); syms = jf.load_syms()
    by_addr = {a: (sz, n) for a, sz, n in syms}
    out = []
    for line in SCHEMA.read_text().splitlines()[1:]:
        p = line.split('\t')
        if p[4]:
            continue
        addr = int(p[2], 16)
        if addr not in by_addr:
            continue
        size, sym = by_addr[addr]
        helpers = set()
        for pc in range(addr, addr + size, 4):
            if pc not in ins:
                continue
            mn, ops = ins[pc]
            if mn == 'jal':
                try:
                    tgt = int(ops, 16)
                except ValueError:
                    continue
                if 0x400000 <= tgt < 0x8b9000 and tgt in by_addr:
                    helpers.add(tgt)
        keys = set()
        for h in sorted(helpers):
            hsize, hname = by_addr[h]
            for pc, kind, key in jf.analyze(h, hsize, ins, plt):
                if kind == 'json_object_object_get' and key:
                    keys.add(key)
        if keys:
            out.append((p[0], p[1], sym, ','.join(sorted(keys))))
    with open(ROOT / 'notes/vendor-web/jcs-helper-fields.tsv', 'w') as f:
        f.write('name\top\thandler\thelper_inputs\n')
        for r in out:
            f.write('\t'.join(r) + '\n')
    print('handlers with helper keys', len(out))
    for r in out:
        print(r[0], r[1], r[2], r[3][:160])


if __name__ == '__main__':
    main()
