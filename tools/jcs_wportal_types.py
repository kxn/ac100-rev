#!/usr/bin/env python3
"""Group wportal calls by type constant and op."""
import json
import re
from collections import defaultdict
from pathlib import Path

from ac100_env import ROOT
from ac100_env import ROOTFS
LUA = ROOTFS / "usr/lib/lua/luci/torchlight/uac/wportal_public.lua"
from ac100_env import LUA_FIELDS as RAW
OUT = ROOT / 'notes/vendor-web/jcs-wportal-types.tsv'
IDENT = re.compile(r'^[A-Za-z_][A-Za-z0-9_]*$')


def main():
    consts = {}
    if LUA.exists():
        for m in re.finditer(r'(WPORTAL_JCS_[A-Z0-9_]+)\s*=\s*(\d+)', LUA.read_text()):
            consts[m.group(1)] = int(m.group(2))
    groups = defaultdict(lambda: {'fields': set(), 'calls': 0, 'sources': set()})
    for line in RAW.read_text().splitlines():
        r = json.loads(line)
        name = re.sub(r'\s*\(.*\)$', '', (r.get('name') or '').strip()).lstrip('~')
        if name != 'wportal':
            continue
        op = 0
        for k, v in (('ADD', 0), ('DEL', 1), ('SET', 2), ('GET', 3)):
            if k in (r.get('op') or ''):
                op = v
        t = (r.get('fields') or {}).get('type') or '?'
        if t == 'I' and op == 0:
            t, num_override = 'WPORTAL_JCS_ADD_FREESTRATEGY', 2
        elif t == 'p' and op == 1:
            t, num_override = 'WPORTAL_JCS_DEL_FREESTRATEGY', 2
        else:
            num_override = None
        g = groups[(op, t)]
        g['calls'] += 1
        g['sources'].add(r['file'].split('/')[-1] + ':' + str(r['line']))
        for f in (r.get('fields') or {}):
            if f == 'type' or '[' in f or f.endswith('.'):
                continue
            if IDENT.match(f):
                g['fields'].add(f)
    with open(OUT, 'w') as f:
        f.write('op\ttype\ttype_num\tcalls\tfields\tsources\n')
        for (op, t), g in sorted(groups.items()):
            num = num_override if num_override is not None else consts.get(t, '')
            f.write(f"{op}\t{t}\t{num}\t{g['calls']}\t{','.join(sorted(g['fields']))}\t{';'.join(sorted(g['sources']))}\n")
    print('groups', len(groups), 'resolved', sum(1 for (_, t) in groups if t in consts))


if __name__ == '__main__':
    main()
