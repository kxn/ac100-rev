#!/usr/bin/env python3
"""Verify explicit firmware -> Go symbol -> executed regression contracts.

This checks source identity, counterpart declarations and the named tests'
actual execution. It cannot establish exhaustive semantic equivalence.
No original firmware binary is executed, and no AP/device is contacted.
"""
import argparse
import collections
import hashlib
import json
import pathlib
import re
import subprocess

ROOT = pathlib.Path(__file__).resolve().parents[1]


def declared(path, name):
    return re.search(r'^func (?:\([^\n]+?\) )?' + re.escape(name) + r'\(', path.read_text(), re.M)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--verify-firmware', action='store_true')
    parser.add_argument('--run-tests', action='store_true')
    parser.add_argument('--report', type=pathlib.Path)
    args = parser.parse_args()
    manifest = json.loads((ROOT / 'docs/uac-web-behavior-contracts.json').read_text())
    features = json.loads((ROOT / 'docs/uac-web-parity-map.json').read_text())
    original = {c['module']: c for c in json.loads((ROOT / 'docs/original-feature-inventory.json').read_text())['controllers']}
    firmware = json.loads((ROOT / 'docs/mobility-firmware-evidence.json').read_text())
    assert manifest['firmware'] == features['firmware'] == firmware['firmware']
    expected_features = {f['id'] for f in features['features']}
    contracts = manifest['contracts']
    assert {c['feature'] for c in contracts} == expected_features, 'Feature contract coverage mismatch'
    assert len({c['id'] for c in contracts}) == len(contracts), 'Duplicate contract IDs'
    indexed = {row['id']: set(row['evidence_contracts']) for row in features['features']}
    for feature, ids in indexed.items():
        assert ids == {c['id'] for c in contracts if c['feature'] == feature}, f'Stale feature contracts: {feature}'
    source_review = {src['name']: src for c in contracts for src in c['sources'] if src['kind'] == 'uac'}
    references = manifest['reference_or_inactive_functions']
    for ref in references:
        assert ref['reason'] and ref['name'] not in source_review, ref
        source_review[ref['name']] = ref
    for original_function in firmware['uac_functions']:
        ref = source_review[original_function['name']]
        assert (ref['address'], ref['size'], ref['sha256']) == (original_function['address'], original_function['size'], original_function['bytes_sha256']), ref
    binaries = {}
    if args.verify_firmware:
        from audit_mobility_firmware import ELF32BE
        for path, digest in firmware['inputs'].items():
            binaries[path] = ELF32BE(ROOT / '.local/ac100/rootfs' / path, digest)
    if args.verify_firmware:
        elf = binaries['usr/sbin/uac']
        for ref in references:
            assert hashlib.sha256(elf.read(int(ref['address'], 16), ref['size'])).hexdigest() == ref['sha256'], ref
    selected = collections.defaultdict(set)
    symbol_count = set()
    source_count = set()
    for c in contracts:
        assert c['behavior'] and c['implementation'] and c['tests'], c['id']
        assert c['origin'] in ('firmware', 'standalone-go', 'firmware-bug-fix'), c['id']
        assert c['origin'] == 'standalone-go' or c['sources'], c['id']
        if c['origin'] == 'firmware-bug-fix':
            assert c['firmware_defect'] and c['intentional_change'] and c['authorization'], c['id']
        for imp in c['implementation']:
            assert declared(ROOT / imp['path'], imp['symbol']), f'Missing Go implementation: {imp}'
            symbol_count.add((imp['path'], imp['symbol']))
        for src in c['sources']:
            source_count.add(json.dumps(src, sort_keys=True))
            if src['kind'] == 'lua':
                o = original[src['module']]
                assert src['entry'] in o['functions'], src
                assert src['path'] == o['source'] and src['sha256'] == o['sha256'], src
                if args.verify_firmware:
                    raw = (ROOT / '.local/ac100/rootfs' / src['path']).read_bytes()
                    assert hashlib.sha256(raw).hexdigest() == src['sha256'], src
            elif src['kind'] == 'file':
                if args.verify_firmware:
                    assert hashlib.sha256((ROOT / '.local/ac100/rootfs' / src['path']).read_bytes()).hexdigest() == src['sha256'], src
            elif src['kind'] == 'v4-file':
                if args.verify_firmware:
                    assert hashlib.sha256((ROOT / '.local/ac100/v4-review/rootfs' / src['path']).read_bytes()).hexdigest() == src['sha256'], src
            elif src['kind'] in ('v4-uac', 'v4-library', 'comparison-uac'):
                if args.verify_firmware:
                    key = src['kind'] + ':' + src.get('path', '') + ':' + src.get('version', '')
                    if key not in binaries:
                        if src['kind'] == 'comparison-uac':
                            assert src['version'] in ('v4', 'v6'), src
                            path = ROOT / ('firmware' if src['version'] == 'v4' else '.local/ac100/rootfs') / 'usr/sbin/uac'
                        else:
                            path = ROOT / 'firmware/usr/sbin/uac' if src['kind'] == 'v4-uac' else ROOT / '.local/ac100/v4-review/rootfs' / src['path']
                        binaries[key] = ELF32BE(path, src['binary_sha256'])
                    elf = binaries[key]
                    assert hashlib.sha256(elf.read(int(src['address'],16),src['size'])).hexdigest() == src['sha256'],src
            elif src['kind'] in ('uac', 'rrm', 'dhcpd'):
                if args.verify_firmware:
                    path = 'usr/sbin/uac' if src['kind'] == 'uac' else src['path']
                    digest = firmware['inputs'][path] if src['kind'] == 'uac' else src['binary_sha256']
                    if path not in binaries:
                        binaries[path] = ELF32BE(ROOT / '.local/ac100/rootfs' / path, digest)
                    elf = binaries[path]
                    assert elf.sha256 == digest, src
                    size, expected = (src['size'], src['sha256']) if src['kind'] == 'uac' else (src['anchor_size'], src['anchor_sha256'])
                    assert hashlib.sha256(elf.read(int(src['address'], 16), size)).hexdigest() == expected, src
            else:
                raise AssertionError(f'Unknown source kind: {src}')
        for test in c['tests']:
            assert test['path'].endswith('_test.go') and declared(ROOT / test['path'], test['name']), test
            package = str(pathlib.PurePosixPath(test['path']).parent.relative_to('uacgo'))
            selected[package].add(test['name'])
    # Go's own test discovery prevents matching names hidden in comments or
    # excluded by build constraints from counting as executable evidence.
    for package, names in selected.items():
        listed = subprocess.run(['go', 'test', '-list', '^Test', './' + package], cwd=ROOT / 'uacgo', text=True, capture_output=True, check=True)
        assert names <= set(listed.stdout.splitlines()), f'Undiscoverable tests in {package}: {names - set(listed.stdout.splitlines())}'
    passed = set()
    if args.run_tests:
        names = sorted({n for group in selected.values() for n in group})
        pattern = '^(' + '|'.join(re.escape(n) for n in names) + ')$'
        command = ['go', 'test', '-json', '-count=1', '-run', pattern] + ['./' + p for p in selected]
        run = subprocess.run(command, cwd=ROOT / 'uacgo', capture_output=True, text=True)
        for line in run.stdout.splitlines():
            event = json.loads(line)
            if event.get('Action') == 'pass' and event.get('Test'):
                passed.add((event['Package'].removeprefix('uacgo/'), event['Test']))
        expected = {(p, n) for p, names in selected.items() for n in names}
        if run.returncode or not expected <= passed:
            failures = [line for line in run.stdout.splitlines() if '"Action":"fail"' in line]
            raise RuntimeError(f'Contract execution failed: missing pass {sorted(expected - passed)}, failure events {failures}; stderr={run.stderr[-2000:]}')
    from check_roaming_entries import verify_entries
    entry_report = verify_entries(args.verify_firmware)
    if args.verify_firmware:
        subprocess.run(['go', 'run', '../tools/audit_model_library.go'], cwd=ROOT / 'uacgo', check=True)
        from audit_cross_version_mobility import verify as verify_cross_versions
        cross_versions = verify_cross_versions(json.loads((ROOT / 'docs/cross-version-mobility-evidence.json').read_text()))
        from audit_v4_rrm import extract as extract_v4_rrm
        v4_rrm = json.loads((ROOT / 'docs/v4-rrm-evidence.json').read_text())
        assert extract_v4_rrm(v4_rrm['registrations']) == v4_rrm, 'V4 RRM source changed'
    else:
        cross_versions = None
    report = dict(firmware=manifest['firmware'], contracts=len(contracts), features=len(expected_features), pinned_uac_functions_classified=len(firmware['uac_functions']), implementation_symbols=len(symbol_count), source_references=len(source_count), named_tests=sum(map(len, selected.values())), verified_firmware=args.verify_firmware, executed_tests=len({(p,n) for p,n in passed if n in selected[p]}), intentional_firmware_bug_fixes=[c['id'] for c in contracts if c['origin'] == 'firmware-bug-fix'], roaming_entries=entry_report, cross_version_entries=cross_versions, meaning='Named branch contracts only; no original runtime oracle or exhaustive equivalence claim.')
    if args.report:
        args.report.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps(report, ensure_ascii=False))


if __name__ == '__main__':
    main()
