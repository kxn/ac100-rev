#!/usr/bin/env python3
"""Pin V4 RRM code, reverse callers, registrations and compiled defaults.

Static evidence only: no original controller execution or hardware oracle.
"""
import argparse
import hashlib
import json
from pathlib import Path

from audit_mobility_firmware import ELF32BE
from audit_v4_reference import SHA
from audit_cross_version_mobility import symbols, fingerprint, owner

ROOT = Path(__file__).resolve().parents[1]
DEST = ROOT / 'docs/v4-rrm-evidence.json'


def extract(registrations):
    elf = ELF32BE(ROOT / 'firmware/usr/sbin/uac', SHA)
    db = symbols(ROOT / 'firmware/usr/sbin/uac_symbol_fun')
    names = sorted(n for n in db if n.startswith(('rrm_', '_rrm_', 'uac_rrm_', '_autorrm'))
                   or n in ['run_DCA', 'dfs', 'run_TPC', 'run_smooth_TPC', 'chnl_rrm_start', 'pwr_rrm_start', '_apdb_pkt_parse_radio', 'uac_rdmngr_chnl_pwr_modify_by_rdid'])
    targets = {db[n][0]: n for n in names}
    callers = []
    for n, (a, size) in sorted(db.items(), key=lambda item: item[1][0]):
        for pc in range(a, a+size, 4):
            w = elf.u32(pc)
            if w >> 26 in (2, 3):
                target = ((pc+4) & 0xf0000000) | ((w & 0x3ffffff) << 2)
                if target in targets:
                    callers.append(dict(caller=n, target=targets[target], site=f'0x{pc:08x}', instruction=f'0x{w:08x}'))
    for r in registrations:
        pc = int(r['site'], 16)
        assert owner(db, pc) == r['root']
        assert db[r['target']][0] == int(r['address'], 16)
        assert elf.u32(pc) == int(r['instruction'], 16)
    data = []
    for label, a, size in [('power_and_ndp_defaults', 0x7318d8, 68), ('quantization_divisor_double9', 0x6a1600, 8)]:
        raw = elf.read(a, size)
        data.append(dict(name=label, address=f'0x{a:08x}', size=size, hex=raw.hex(), sha256=hashlib.sha256(raw).hexdigest()))
    files = []
    for path in ['usr/lib/lua/luci/controller/admin/apmng_rrm.lua', 'usr/lib/lua/luci/view/userrpm/apmng_rrm.htm']:
        files.append(dict(path=path, sha256=hashlib.sha256((ROOT / '.local/ac100/v4-review/rootfs' / path).read_bytes()).hexdigest()))
    return dict(binary_sha256=SHA, functions=[fingerprint(elf, db, n) for n in names],
                direct_callers=callers, registrations=registrations, data=data, files=files,
                scope='Product Web/JCS/scheduled RRM; debug CLI, logs, fixed hardware capacities and system-time management are not application policies. Internal smoothTPC flag defaults0 and is not a Web/JCS setting.')


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--write', action='store_true')
    p.add_argument('--registrations', type=Path)
    args = p.parse_args()
    if args.registrations:
        elf = ELF32BE(ROOT / 'firmware/usr/sbin/uac', SHA)
        db = symbols(ROOT / 'firmware/usr/sbin/uac_symbol_fun')
        regs = []
        for line in args.registrations.read_text().splitlines():
            _, site, target, address = line.split('\t')
            pc = int(site, 16)
            regs.append(dict(root=owner(db, pc), site='0x'+site, target=target, address='0x'+address, instruction=f'0x{elf.u32(pc):08x}'))
    else:
        regs = json.loads(DEST.read_text())['registrations']
    actual = extract(regs)
    if args.write:
        assert args.registrations, 'Writing requires freshly exported registrations'
        DEST.write_text(json.dumps(actual, ensure_ascii=False, indent=2)+'\n')
    else:
        assert actual == json.loads(DEST.read_text()), 'V4 RRM evidence changed'
    print(f"Verified V4 RRM: {len(actual['functions'])} functions, {len(actual['direct_callers'])} reverse direct branches, {len(regs)} registrations; no firmware execution")


if __name__ == '__main__':
    main()
