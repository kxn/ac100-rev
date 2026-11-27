#!/usr/bin/env python3
"""Check the reviewed roaming registration census and reverse direct callers.

Use --references with ExportEntryReferences.java output to check the complete
Ghidra reference set for the declared roots. No firmware or AP is executed.
"""
import argparse
import hashlib
import json
import pathlib
import re

from audit_mobility_firmware import ELF32BE, UAC_SHA256

ROOT = pathlib.Path(__file__).resolve().parents[1]


def verify_entries(verify_firmware=False, references=None, reverse_references=None):
    audit = json.loads((ROOT / 'docs/roaming-entry-audit.json').read_text())
    behavior = json.loads((ROOT / 'docs/uac-web-behavior-contracts.json').read_text())
    contracts = {c['id']: c for c in behavior['contracts']}
    assert audit['firmware'] == behavior['firmware'] and audit['uac_sha256'] == UAC_SHA256
    exception = contracts[audit['intentional_firmware_bug_fix_contract']]
    assert exception['origin'] == 'firmware-bug-fix' and exception['authorization']
    roots = {f['name']: f for f in audit['roots']}
    assert len(roots) == len(audit['roots'])
    functions = list(roots.values()) + audit['direct_targets'] + audit['review_support']
    expected = []
    targets = set()
    for entry in audit['entries']:
        f = entry['source']
        assert f['name'] not in targets
        targets.add(f['name'])
        functions.append(f)
        assert entry['note'] and entry['classification'] in {
            'decision', 'configuration', 'lifecycle', 'diagnostic',
            'legacy-mode', 'container-utility', 'excluded-auth',
        }, f
        assert set(entry['contracts']) <= contracts.keys(), f
        if entry['classification'] in ('decision', 'configuration', 'lifecycle', 'legacy-mode'):
            assert entry['contracts'], f
        for ref in entry['references']:
            root = roots[ref['root']]
            assert int(root['address'], 16) <= int(ref['site'], 16) < int(root['address'], 16) + root['size']
            expected.append((ref['root'], ref['site'][2:], f['name'], f['address'][2:]))
    assert len(expected) == len(set(expected)), 'Duplicate registration reference'
    if references:
        actual = [tuple(line.split('\t')) for line in references.read_text().splitlines()]
        assert sorted(actual) == sorted(expected), 'Unclassified or stale Ghidra callback reference'
    if reverse_references:
        actual = []
        seen_targets = set()
        target = None
        for line in reverse_references.read_text().splitlines():
            match = re.search(r'FindCallers.java> TARGET (\S+) ', line)
            if match:
                target = match[1]
                seen_targets.add(target)
            match = re.search(r'FindCallers.java> CALLER ([0-9a-f]+) (\S+)', line)
            if match:
                actual.append((target, match[2], '0x' + match[1]))
        expected_reverse = [(r['target'], r['caller'], r['site']) for r in audit['reverse_references']]
        assert seen_targets == {f['name'] for f in audit['direct_targets']}, 'Missing reverse search target (including zero-reference targets)'
        assert sorted(actual) == sorted(expected_reverse), 'Unclassified reverse entry reference'
    functions += [slot['source'] for slot in audit['statistics_timer_table']]
    if verify_firmware:
        rootfs = ROOT / '.local/ac100/rootfs'
        elf = ELF32BE(rootfs / 'usr/sbin/uac', UAC_SHA256)
        raw = (rootfs / 'usr/sbin/uac_symbol_fun').read_bytes()
        assert hashlib.sha256(raw).hexdigest() == audit['symbol_file_sha256']
        symbols = {}
        for line in raw.decode().splitlines():
            fields = line.split(maxsplit=3)
            if len(fields) == 4:
                symbols[fields[3]] = int(fields[0], 16), int(fields[1], 16)
        for f in functions:
            address = int(f['address'], 16)
            assert symbols[f['name']] == (address, f['size']), f
            assert hashlib.sha256(elf.read(address, f['size'])).hexdigest() == f['sha256'], f
        for entry in audit['entries']:
            for ref in entry['references']:
                assert elf.u32(int(ref['site'], 16)) == int(ref['instruction'], 16), ref
        for slot in audit['statistics_timer_table']:
            assert elf.u32(int(slot['pointer'], 16)) == int(slot['source']['address'], 16), slot
            assert elf.u32(int(slot['interval_address'], 16)) == slot['seconds'], slot
        for ref in audit['reverse_references']:
            pc = int(ref['site'], 16)
            address, size = symbols[ref['caller']]
            assert address <= pc < address + size
            word = elf.u32(pc)
            assert word == int(ref['instruction'], 16) and ref['direct'] == (word >> 26 in (2, 3))
        destinations = {int(f['address'], 16): f['name'] for f in audit['direct_targets']}
        found = []
        # Include tail J as well as JAL, scan every symbol-bounded function,
        # and retain targets with zero callers in the declared target set.
        for name, (address, size) in sorted(symbols.items(), key=lambda p: p[1][0]):
            for pc in range(address, address + size, 4):
                word = elf.u32(pc)
                if word >> 26 not in (2, 3):
                    continue
                target = ((pc + 4) & 0xf0000000) | ((word & 0x3ffffff) << 2)
                if target in destinations:
                    found.append(dict(caller=name, site=f'0x{pc:08x}', instruction=f'0x{word:08x}', target=destinations[target]))
        assert found == audit['direct_callers'], 'Direct roaming callers differ from reviewed inventory'
        assert found == [{k: r[k] for k in ('caller', 'site', 'instruction', 'target')} for r in sorted(audit['reverse_references'], key=lambda r: int(r['site'], 16)) if r['direct']]
    return dict(registration_roots=len(roots), callback_references=len(expected),
                callback_functions=len(targets), timer_table_slots=len(audit['statistics_timer_table']),
                direct_branches=len(audit['direct_callers']),
                reverse_references=len(audit['reverse_references']),
                verified_ghidra_references=references is not None,
                verified_ghidra_reverse_references=reverse_references is not None)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--verify-firmware', action='store_true')
    parser.add_argument('--references', type=pathlib.Path)
    parser.add_argument('--reverse-references', type=pathlib.Path)
    args = parser.parse_args()
    print(json.dumps(verify_entries(args.verify_firmware, args.references, args.reverse_references)))


if __name__ == '__main__':
    main()
