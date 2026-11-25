#!/usr/bin/env python3
"""Export Lua expressions used to construct each Web-to-JCS data field."""
import json
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
RAW = Path('/tmp/lua_jcs_fields.jsonl')
OUT = ROOT / 'notes/vendor-web/jcs-web-expressions.tsv'
OPS = {'JCS_OP_TYPE_ADD': '0', 'JCS_OP_TYPE_DEL': '1',
       'JCS_OP_TYPE_SET': '2', 'JCS_OP_TYPE_GET': '3'}
CONDITIONAL_NAME = "r==s and'macauth_group_for_ssid'or'macauth_group'"


def canonical_op(value):
    for name, number in OPS.items():
        if name in value:
            return number
    match = re.search(r'\b([0-3])\b', value or '')
    return match.group(1) if match else ''


def main():
    if not RAW.exists():
        raise SystemExit(f'missing {RAW}')

    canonical = set()
    for line in (ROOT / 'notes/vendor-web/jcs-web-fields.tsv').read_text().splitlines()[1:]:
        name, op, _, sources = line.split('\t')
        for source in sources.split(';'):
            canonical.add((source, name, op))

    expressions = defaultdict(lambda: {'values': set(), 'sources': set()})
    for line in RAW.read_text().splitlines():
        record = json.loads(line)
        name = re.sub(r'\s*\(.*\)$', '', (record.get('name') or '').strip()).lstrip('~')
        op = canonical_op(record.get('op') or '')
        source = f"{record['file'].split('/')[-1]}:{record['line']}"
        if (source, name, op) not in canonical:
            continue

        resolved_names = [name]
        resolution = 'literal-or-constant'
        if name == 'F' and source == 'apmng_wserv.lua:210':
            resolved_names = ['wserv_global']
            resolution = 'resolved-from-controller-context'
        elif name == CONDITIONAL_NAME:
            resolved_names = ['macauth_group', 'macauth_group_for_ssid']
            resolution = 'conditional-name-branch'

        for field, expression in (record.get('fields') or {}).items():
            for resolved_name in resolved_names:
                entry = expressions[(resolved_name, op, field, resolution)]
                entry['values'].add(str(expression))
                entry['sources'].add(source)

    with OUT.open('w') as stream:
        stream.write('name\top\tfield_path\tlua_expressions\tsources\tname_resolution\n')
        for (name, op, field, resolution), entry in sorted(expressions.items()):
            stream.write('\t'.join((name, op, field,
                                    ';'.join(sorted(entry['values'])),
                                    ';'.join(sorted(entry['sources'])),
                                    resolution)) + '\n')
    print(f'wrote {OUT} rows={len(expressions)}')


if __name__ == '__main__':
    main()
