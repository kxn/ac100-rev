#!/usr/bin/env python3
"""Extract JSON value accessors used by the AC100 JCS handlers."""
import bisect
import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ASM = Path('/tmp/uac-load1.asm')
FIELDS = Path('/tmp/jcs_fields.tsv')
REGISTRY = ROOT / 'notes/vendor-web/jcs-registry.tsv'
OUTPUT = ROOT / 'notes/vendor-web/jcs-types.tsv'

INS = re.compile(r'^\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+(\S+)\s*(.*)$')
VALUE_GETTERS = {
    'json_object_get_string': 'string',
    'json_object_get_int': 'number',
    'json_object_get_int64': 'number',
    'json_object_get_double': 'number',
    'json_object_get_boolean': 'boolean',
    'json_object_get_object': 'object',
    'json_object_get_type': 'type-check',
}


def main():
    if not ASM.exists() or not FIELDS.exists():
        raise SystemExit('missing /tmp/uac-load1.asm or /tmp/jcs_fields.tsv')

    instructions = {}
    for line in ASM.read_text().splitlines():
        match = INS.match(line)
        if match:
            instructions[int(match.group(1), 16)] = (match.group(2), match.group(3))
    addresses = sorted(instructions)

    sys.path.insert(0, str(ROOT / 'tools'))
    import jcs_fields

    plt = jcs_fields.load_plt()

    def scan_value_getters(pc, end, evidence):
        cursor = bisect.bisect_right(addresses, pc + 4)
        while cursor < len(addresses) and addresses[cursor] < end:
            call_pc = addresses[cursor]
            mnemonic, operands = instructions[call_pc]
            if mnemonic == 'jal':
                try:
                    target = int(operands, 16)
                except ValueError:
                    target = None
                name = plt.get(target) if target is not None else None
                if name in VALUE_GETTERS:
                    evidence['getters'].add(name.removeprefix('json_object_get_'))
                    evidence['types'].add(VALUE_GETTERS[name])
            cursor += 1

    registry = defaultdict(list)
    for line in REGISTRY.read_text().splitlines()[1:]:
        row = line.split('\t')
        registry[row[2]].append((row[0], row[1]))

    accesses = defaultdict(lambda: {'types': set(), 'getters': set(), 'sites': set()})
    raw = defaultdict(list)
    for line in FIELDS.read_text().splitlines()[1:]:
        handler, symbol, direction, key, pc_text = line.split('\t')
        if direction != 'in':
            continue
        pc = int(pc_text, 16)
        raw[(handler, symbol)].append((pc, key))

    for (handler, symbol), fields in raw.items():
        fields.sort()
        for index, (pc, key) in enumerate(fields):
            next_field = fields[index + 1][0] if index + 1 < len(fields) else pc + 0x300
            end = min(next_field, pc + 0x300)
            found = accesses[(handler, key)]
            found['sites'].add(pc)
            scan_value_getters(pc, end, found)

    symbols = jcs_fields.load_syms()
    by_address = {address: (size, symbol) for address, size, symbol in symbols}
    symbol_address = {symbol: address for address, _, symbol in symbols}
    evidence_rows = {}
    for line in FIELDS.read_text().splitlines()[1:]:
        handler, symbol, direction, key, _ = line.split('\t')
        if direction == 'in':
            evidence_rows[(int(handler, 16), key)] = accesses[(handler, key)]

    handler_api = defaultdict(list)
    for address, entries in registry.items():
        handler_api[int(address, 16)].extend(entries)

    api_fields = {}
    for handler, entries in handler_api.items():
        function = by_address.get(handler)
        if not function:
            continue
        size, _ = function
        helpers = set()
        start = bisect.bisect_left(addresses, handler)
        end = handler + size
        for call_pc in addresses[start:]:
            if call_pc >= end:
                break
            mnemonic, operands = instructions[call_pc]
            if mnemonic == 'jal':
                try:
                    target = int(operands, 16)
                except ValueError:
                    continue
                if target in by_address and target != handler:
                    helpers.add(target)
        for helper in helpers:
            helper_size, helper_symbol = by_address[helper]
            helper_fields = sorted({(pc, key) for pc, kind, key in
                                    jcs_fields.analyze(helper, helper_size, instructions, plt)
                                    if kind == 'json_object_object_get' and key})
            for index, (call_pc, key) in enumerate(helper_fields):
                evidence = accesses[(f'0x{helper:08x}', key)]
                evidence['sites'].add(call_pc)
                next_pc = helper_fields[index + 1][0] if index + 1 < len(helper_fields) else call_pc + 0x300
                scan_value_getters(call_pc, min(next_pc, call_pc + 0x300), evidence)
                evidence_rows[(helper, key)] = evidence

        for name, op in entries:
            api = f'{name}:{op}'
            for (symbol_address_value, key), evidence in evidence_rows.items():
                if symbol_address_value == handler:
                    api_fields[(api, key, 'uac')] = evidence
            for helper in helpers:
                helper_symbol = by_address[helper][1]
                for (symbol_address_value, key), evidence in evidence_rows.items():
                    if symbol_address_value == helper:
                        api_fields[(api, key, 'helper')] = evidence

    rows = []
    for (api, key, layer), evidence in api_fields.items():
        rows.append((api, layer, key, ','.join(sorted(evidence['types'])),
                     ','.join(sorted(evidence['getters'])),
                     ','.join(f'0x{pc:08x}' for pc in sorted(evidence['sites']))))
    rows.sort()
    with OUTPUT.open('w') as stream:
        stream.write('api\tlayer\tfield\tjson_type\tjson_getters\tcall_sites\n')
        for row in rows:
            stream.write('\t'.join(row) + '\n')
    classified = sum(bool(row[3]) for row in rows)
    print(f'field_accesses={len(rows)} typed={classified} output={OUTPUT}')


if __name__ == '__main__':
    main()
