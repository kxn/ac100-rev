#!/usr/bin/env python3
"""Generate the /etc/config tree for the vendor uac.

Sources:
  * key whitelist: /etc/tmp_uc_conf/uc.conf shipped in the firmware image
    (only names, no values).
  * values: reconstructed. uac parses most booleans through &onoff_map
    (string -> int), so they must be 'on'/'off', never '0'/'1'.
"""
import collections, os, re, sys

keys_file, outdir = sys.argv[1], sys.argv[2]
overrides = {}
if len(sys.argv) > 3:
    for ln in open(sys.argv[3]):
        p = ln.split()
        if len(p) == 4:
            overrides[(p[0], p[1], p[2])] = p[3]

BOOL_HINT = re.compile(r'(^auto_|_switch$|^enable|^has_|^is_)')
OFF_HINT = re.compile(r'(^auto_firm$|^auto_reboot$|^auto_upgrade$)')

def value_for(cfg, sec, opt):
    if (cfg, sec, opt) in overrides:
        return overrides[(cfg, sec, opt)]
    if BOOL_HINT.search(opt):
        return 'off' if OFF_HINT.search(opt) else 'on'
    return '0'

tree = collections.OrderedDict()
for ln in open(keys_file):
    ln = ln.strip()
    if not ln or ln.startswith('#'):
        continue
    p = ln.split()
    if len(p) < 3:
        continue
    tree.setdefault(p[0], collections.OrderedDict()).setdefault(p[1], [])
    if p[2] not in tree[p[0]][p[1]]:
        tree[p[0]][p[1]].append(p[2])

os.makedirs(outdir, exist_ok=True)
for cfg, secs in tree.items():
    body = []
    for sec, opts in secs.items():
        body.append(f"config {sec} '{sec}'")
        for o in opts:
            body.append(f"\toption {o} '{value_for(cfg, sec, o)}'")
        body.append('')
    open(os.path.join(outdir, cfg), 'w').write('\n'.join(body))
print(f'{len(tree)} configs written to {outdir}')
