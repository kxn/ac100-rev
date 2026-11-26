#!/usr/bin/env python3
"""Check the bidirectional review index and standalone configuration boundary.

This guards against unclassified source additions, missing counterparts and
accidental reactivation of the old second configuration source. It does not
prove algorithm equivalence; firmware fingerprints and source-derived Go
vectors are separate checks.
"""
import argparse
import hashlib
import json
import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--verify-firmware', action='store_true')
    args = parser.parse_args()
    index = json.loads((ROOT / 'docs/uac-web-parity-map.json').read_text())
    original = json.loads((ROOT / 'docs/original-feature-inventory.json').read_text())
    modules = {c['module'] for c in original['controllers']}
    assert set(index['controller_review']) == modules, 'Original controller scope is unclassified'
    ids = {r['id'] for r in index['features']}
    assert len(ids) == len(index['features']), 'Duplicate feature IDs'
    covered = set(index['supporting_or_reference_files'])
    for row in index['features']:
        assert row['basis'] and row['go_files'] and row['regressions'], row['id']
        assert set(row['firmware_modules']) <= modules, row['id']
        for path in row['go_files'] + row['regressions']:
            assert (ROOT / path).is_file(), f'Missing counterpart: {path}'
        covered.update(row['go_files'])
    for name, row in index['controller_review'].items():
        assert set(row['features']) <= ids, name
        assert row['scope'] == 'excluded' or row['features'], name
    production = {
        str(p.relative_to(ROOT)) for p in (ROOT / 'uacgo').rglob('*.go')
        if not p.name.endswith('_test.go')
        and not any(x.startswith('.') for x in p.relative_to(ROOT / 'uacgo').parts)
    }
    assert production <= covered, f'Go files without review classification: {sorted(production - covered)}'
    assert all((ROOT / path).is_file() for path in covered), 'Stale review file entry'
    startup = (ROOT / 'uacgo/cmd/acd/main.go').read_text()
    for forbidden in ('"uacgo/jcs"', 'store.OpenAll(', 'RegisterWserviceHandlers(', 'StoreWserviceConfig', 'RegisterApmngrJCS('):
        assert forbidden not in startup, f'Second configuration authority reactivated: {forbidden}'
    if args.verify_firmware:
        for c in original['controllers']:
            raw = (ROOT / '.local/ac100/rootfs' / c['source']).read_bytes()
            assert hashlib.sha256(raw).hexdigest() == c['sha256'], f'Firmware source changed: {c["module"]}'
    print(f'Checked {len(modules)} original controller scopes, {len(ids)} feature chains, '
          f'{len(production)} Go source files and the single configuration authority; '
          'no algorithm equivalence inferred')


if __name__ == '__main__':
    main()
