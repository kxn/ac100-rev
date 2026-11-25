#!/usr/bin/env python3
"""Infer the json-c getter used for each direct input key.

After json_object_object_get returns in v0, handlers usually do
`move a0,v0; jal json_object_get_int` (or string/int64/...).  Scan a small
window around the get call site and record that getter.
"""
import re
from collections import defaultdict
from pathlib import Path

ASM = Path('/tmp/uac-load1.asm')
FIELDS = Path('/tmp/jcs_fields.tsv')
GETTERS = {
    0x8b98f0: 'int', 0x8b9580: 'string', 0x8b9a40: 'int64',
    0x8b9750: 'double', 0x8b92f0: 'boolean', 0x8b9770: 'object',
    0x8b94b0: 'type',
}
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
        a0_is_v0 = False
        for off in range(4, 52, 4):
            q = pc + off
            if q not in ins:
                break
            mn, ops = ins[q]
            if mn == 'move' and ops.replace(' ', '') == 'a0,v0':
                a0_is_v0 = True
                continue
            if mn in ('jal',) and a0_is_v0:
                try:
                    tgt = int(ops, 16)
                except ValueError:
                    break
                if tgt in GETTERS:
                    hits[key].add(GETTERS[tgt])
                break
            if mn in ('jal', 'jalr', 'lw', 'li', 'lui', 'addiu', 'move'):
                # a0 was clobbered or call happened
                if mn in ('li', 'lui', 'addiu', 'move', 'lw') and ops.split(',')[0].strip() == 'a0':
                    break
                if mn in ('jal', 'jalr'):
                    break
    print('key\ttypes')
    for k in sorted(hits):
        print(f"{k}\t{','.join(sorted(hits[k]))}")
    print('covered', len(hits), file=__import__('sys').stderr)


if __name__ == '__main__':
    main()
