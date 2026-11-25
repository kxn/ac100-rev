#!/usr/bin/env python3
"""Build the per-operation reverse-engineering and validation index."""
import csv
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DOCS = ROOT / 'notes/vendor-web'


def rows(path):
    with path.open(newline='') as stream:
        return list(csv.DictReader(stream, delimiter='\t'))


def main():
    registry = rows(DOCS / 'jcs-registry.tsv')
    schema = {(row['name'], row['op']): row for row in rows(DOCS / 'jcs-schema.tsv')}
    samples = {}
    for line in (DOCS / 'captures/jcs-samples.jsonl').read_text().splitlines():
        sample = json.loads(line)
        samples[(sample['name'], str(sample['op']))] = sample

    types = {}
    for row in rows(DOCS / 'jcs-types.tsv'):
        for api in row['api'].split(','):
            if ':' not in api:
                continue
            name, op = api.rsplit(':', 1)
            if row['json_type']:
                types.setdefault((name, op), set()).add(row['field'])

    out = DOCS / 'jcs-verification.tsv'
    columns = ('name', 'op', 'handler', 'handler_symbol', 'web_refs', 'jcs_probe',
               'sample_data', 'request_data_json', 'sample_response', 'input_fields', 'typed_fields',
               'ap_behavior_validation')
    with out.open('w', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=columns, delimiter='\t',
                                lineterminator='\n')
        writer.writeheader()
        for entry in registry:
            key = (entry['name'], entry['op'])
            sample = samples.get(key)
            schema_row = schema.get(key, {})
            inputs = [field for field in schema_row.get('inputs', '').split(',') if field]
            if sample:
                try:
                    request = json.loads(sample['request'])
                    data = request.get('data')
                    data_state = 'nonempty' if data not in ({}, [], None) else 'empty'
                except (KeyError, TypeError, json.JSONDecodeError):
                    data_state = 'unknown'
                if sample.get('error'):
                    probe = 'no-response'
                elif sample.get('response') is None:
                    probe = 'no-response'
                else:
                    probe = 'QEMU-replied'
                response = json.dumps(sample.get('response'), ensure_ascii=False,
                                      separators=(',', ':'))
                request_data = json.dumps(data, ensure_ascii=False, separators=(',', ':'))
            else:
                data_state = 'not-sampled'
                probe = 'not-sampled; wips_event_detail GET crashes in captured test'
                response = ''
                request_data = ''

            if key in {('ap_count', '3'), ('ap_status', '3'),
                       ('ap_status_ssid', '3')}:
                ap_test = '实体AP在线状态/SSID由JCS读回验证'
            elif key == ('wservice', '0'):
                ap_test = 'qiyitt双频下发、ACK、WPA2/CCMP空口扫描验证'
            else:
                ap_test = '未逐项验证AP侧生效'

            writer.writerow({
                'name': entry['name'],
                'op': entry['op'],
                'handler': entry['handler'],
                'handler_symbol': entry['handler_symbol'],
                'web_refs': entry['web_refs'],
                'jcs_probe': probe,
                'sample_data': data_state,
                'request_data_json': request_data,
                'sample_response': response,
                'input_fields': len(inputs),
                'typed_fields': sum(1 for field in inputs
                                    if field.rsplit('.', 1)[-1] in types.get(key, set())),
                'ap_behavior_validation': ap_test,
            })
    print(f'wrote {out} rows={len(registry)}')


if __name__ == '__main__':
    main()
