#!/usr/bin/env python3
"""Group wservice SET calls by operation value."""
import json
import re
from collections import defaultdict
from pathlib import Path

from ac100_env import ROOT
from ac100_env import LUA_FIELDS as RAW
OUT = ROOT / 'notes/vendor-web/jcs-wservice-ops.tsv'
OPS = {'O': 0, 'J': 1, 'K': 2, 'Y': 3, 'x': 4}
NAMES = {0: 'edit', 1: 'bind_rf', 2: 'unbind_rf', 3: 'enable', 4: 'disable'}
IDENT = re.compile(r'^[A-Za-z_][A-Za-z0-9_]*$')


def main():
    groups = defaultdict(lambda: {'fields': set(), 'calls': 0, 'sources': set()})
    for line in RAW.read_text().splitlines():
        r = json.loads(line)
        name = re.sub(r'\s*\(.*\)$', '', (r.get('name') or '').strip()).lstrip('~')
        if name != 'wservice' or 'SET' not in (r.get('op') or ''):
            continue
        expr = (r.get('fields') or {}).get('operation')
        op = OPS.get(expr)
        if op is None:
            continue
        g = groups[op]
        g['calls'] += 1
        g['sources'].add(r['file'].split('/')[-1] + ':' + str(r['line']))
        for f in (r.get('fields') or {}):
            if f == 'operation' or '[' in f or f.endswith('.'):
                continue
            if IDENT.match(f):
                g['fields'].add(f)
    with open(OUT, 'w') as f:
        f.write('operation\tname\tcalls\tfields\tsources\n')
        for op in sorted(groups):
            g = groups[op]
            f.write(f"{op}\t{NAMES[op]}\t{g['calls']}\t{','.join(sorted(g['fields']))}\t{';'.join(sorted(g['sources']))}\n")
    print('ops', sorted(groups))


if __name__ == '__main__':
    main()
