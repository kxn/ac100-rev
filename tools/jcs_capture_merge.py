#!/usr/bin/env python3
"""Merge raw field-probe TX/RX logs into jcs-samples.jsonl."""
import json
import sys
from pathlib import Path

from ac100_env import ROOT
from ac100_env import HARNESS
RAW = Path(sys.argv[1]) if len(sys.argv) > 1 else HARNESS / "field-raw-results.jsonl"
OUT = ROOT / 'notes/vendor-web/captures/jcs-samples.jsonl'
SUMMARY = ROOT / 'notes/vendor-web/captures/jcs-summary.tsv'
OLD = ROOT / 'notes/vendor-web/captures/jcs-samples-empty.jsonl'


def main():
    cases = []
    cur = None
    for line in RAW.read_text().splitlines():
        try:
            r = json.loads(line)
        except Exception:
            continue
        if r.get('dir') == 'tx':
            cur = r
        elif r.get('dir') == 'rx' and cur:
            resp = None
            try:
                resp = json.loads(r['data']) if r.get('data') else None
            except Exception:
                resp = r.get('data')
            cases.append({
                'name': cur['name'], 'op': cur['op'], 'request': cur['data'],
                'response': resp, 'error': r.get('err'),
            })
            cur = None

    def score(c):
        try:
            d = json.loads(c['request']).get('data')
        except Exception:
            d = None
        n = len(c['response']) if isinstance(c['response'], dict) else 0
        return (0 if c['error'] else 1, 0 if d in ({}, [], None) else 1, n)

    best = {}
    for c in cases:
        k = (c['name'], c['op'])
        if k not in best or score(c) >= score(best[k]):
            best[k] = c
    for c in best.values():
        c['batch'] = 'field'

    if OLD.exists():
        for line in OLD.read_text().splitlines():
            r = json.loads(line)
            k = (r['name'], r['op'])
            if k not in best:
                best[k] = dict(r, batch='legacy-empty')

    with open(OUT, 'w') as f:
        for k in sorted(best):
            f.write(json.dumps(best[k], ensure_ascii=False, separators=(',', ':')) + '\n')
    with open(SUMMARY, 'w') as f:
        f.write('name\top\tbatch\tret\trequest\tresponse\n')
        for k in sorted(best):
            r = best[k]
            resp = r.get('response')
            ret = resp.get('ret') if isinstance(resp, dict) else ''
            f.write(f"{r['name']}\t{r['op']}\t{r['batch']}\t{'' if ret is None else ret}\t"
                    f"{r['request']}\t{json.dumps(resp, ensure_ascii=False, separators=(',', ':')) if resp is not None else ''}\n")
    nonempty = 0
    errors = 0
    for r in best.values():
        if r.get('error'):
            errors += 1
        try:
            if json.loads(r['request']).get('data') not in ({}, [], None):
                nonempty += 1
        except Exception:
            pass
    print(f'samples={len(best)} nonempty={nonempty} errors={errors}')


if __name__ == '__main__':
    main()
