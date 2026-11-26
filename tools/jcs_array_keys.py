#!/usr/bin/env python3
"""Find input keys that are immediately used as json arrays."""
import re
from collections import defaultdict
from pathlib import Path

from ac100_env import ASM
from ac100_env import FIELDS
ARRAY_FUNCS = {0x8b9240: 'length', 0x8b9520: 'get_idx'}
INS = re.compile(r'^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S+)\s*(.*)$')


def main():
    ins = {}
    for line in ASM.read_text().splitlines():
        m = INS.match(line)
        if m:
            ins[int(m.group(1), 16)] = (m.group(3), m.group(4).split('#')[0].strip())
    hits = defaultdict(set)
    for line in FIELDS.read_text().splitlines()[1:]:
        p = line.split('\t')
        if len(p) < 5 or p[2] != 'in':
            continue
        key, pc = p[3], int(p[4], 16)
        sym = p[1]
        tracked = {'v0'}
        for off in range(4, 80, 4):
            q = pc + off
            if q not in ins:
                break
            mn, ops = ins[q]
            if mn == 'move':
                parts = [x.strip() for x in ops.split(',')]
                if len(parts) == 2:
                    if parts[1] in tracked:
                        tracked.add(parts[0])
                    else:
                        tracked.discard(parts[0])
                continue
            if mn == 'jal':
                try:
                    tgt = int(ops, 16)
                except ValueError:
                    break
                if tgt in ARRAY_FUNCS and 'a0' in tracked:
                    hits[(sym,key)].add(ARRAY_FUNCS[tgt])
                if tgt not in (0x8b9bd0, 0x8b94b0):
                    tracked = {'v0'}  # other calls clobber
                continue
            if mn in ('li', 'lui', 'addiu', 'lw') and ops.split(',')[0].strip() in tracked:
                tracked.discard(ops.split(',')[0].strip())
    for (sym,k) in sorted(hits):
        print(f"{sym}\t{k}\t{','.join(sorted(hits[(sym,k)]))}")
    print('keys', len(hits), file=__import__('sys').stderr)


if __name__ == '__main__':
    main()
