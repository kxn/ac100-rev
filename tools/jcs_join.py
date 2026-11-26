#!/usr/bin/env python3
"""Join registry/fields/web refs into notes/vendor-web/jcs-registry.tsv."""
import os
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

from ac100_env import ROOT, REPO, CACHE, FIELDS
OUT = ROOT / "notes/vendor-web/jcs-registry.tsv"
WEB = ROOT / "notes/vendor-web/web-jcs-calls.tsv"


def norm(n):
    n = n.strip()
    n = re.sub(r"\s*\(.*\)$", "", n)
    if n.startswith("~"):
        n = n[1:]
    return n


def main():
    reg = subprocess.run([sys.executable, str(REPO / "tools/jcs_registry.py")],
                         check=True, capture_output=True, text=True).stdout
    fields = subprocess.run([sys.executable, str(REPO / "tools/jcs_fields.py")],
                            check=True, capture_output=True, text=True).stdout
    CACHE.mkdir(parents=True, exist_ok=True)
    FIELDS.parent.mkdir(parents=True, exist_ok=True)
    (CACHE / "jcs-registry-raw.tsv").write_text(reg)
    FIELDS.write_text(fields)
    fin, fout = defaultdict(set), defaultdict(set)
    for line in fields.splitlines()[1:]:
        p = line.split("\t")
        if len(p) < 5:
            continue
        (fin if p[2] == "in" else fout)[int(p[0], 16)].add(p[3])
    refs = defaultdict(set)
    for line in WEB.read_text().splitlines()[1:]:
        p = line.split("\t")
        if len(p) < 6:
            continue
        name, op = norm(p[4]), p[5].split()[0]
        if not name or not op.isdigit() or any(c in name for c in " ='\""):
            continue
        refs[(name, int(op))].add(p[0].split("/")[-1].replace(".lua", "") + ":" + p[2])
    rows = []
    for line in reg.splitlines():
        p = line.split("\t")
        if len(p) < 4:
            continue
        name, op, addr, sym = p[0], int(p[1]), int(p[2], 16), p[3]
        rows.append((name, op, addr, sym,
                     ",".join(sorted(fin[addr])),
                     ",".join(sorted(fout[addr])),
                     ";".join(sorted(refs.get((name, op), [])))))
    rows.sort(key=lambda r: (r[0], r[1]))
    with open(OUT, "w") as f:
        f.write("name\top\thandler\thandler_symbol\tin_keys\tout_keys\tweb_refs\n")
        for name, op, addr, sym, ik, ok, wr in rows:
            f.write(f"{name}\t{op}\t{addr:#010x}\t{sym}\t{ik}\t{ok}\t{wr}\n")
    print("wrote", OUT, len(rows), "rows")


if __name__ == "__main__":
    main()
