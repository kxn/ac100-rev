#!/usr/bin/env python3
"""Conservative Go-reimplementation readiness count."""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SCHEMA = ROOT / 'notes/vendor-web/jcs-schema.tsv'
SAMPLES = ROOT / 'notes/vendor-web/captures/jcs-samples.jsonl'
WARN = ROOT / 'notes/vendor-web/captures/type-warnings.tsv'
SPECIAL = {'wportal', 'wservice', 'apmngr_entry', 'ac_roam_list'}


def main():
    samples = {}
    for line in SAMPLES.read_text().splitlines():
        r = json.loads(line)
        samples[(r['name'], r['op'])] = r
    warns = {}
    if WARN.exists():
        for line in WARN.read_text().splitlines()[1:]:
            p = line.split('\t')
            warns[(p[0], int(p[1]))] = int(p[2])
    strict = typep = noin = special = missing = 0
    for line in SCHEMA.read_text().splitlines()[1:]:
        p = line.split('\t')
        key = (p[0], int(p[1]))
        ik = {x for x in p[4].split(',') if x}
        ok = {x for x in p[5].split(',') if x}
        s = samples.get(key)
        resp = s.get('response') if s else None
        if not s:
            missing += 1
        elif not ik:
            noin += 1
        elif any('[]' in x for x in ik) or p[0] in SPECIAL:
            special += 1
        elif warns.get(key):
            typep += 1
        else:
            strict += 1
    print(f'total=278 strict={strict} type_pending={typep} special={special} '
          f'no_input={noin} missing={missing}')
    print('sum', strict + typep + special + noin + missing)


if __name__ == '__main__':
    main()
