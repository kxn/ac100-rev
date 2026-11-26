#!/usr/bin/env python3
"""Aggregate JCS data fields built by the vendor LuCI controllers."""
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

from ac100_env import ROOT
from ac100_env import LUA_FIELDS as RAW


def opnum(s):
    s = s or ""
    for name, val in (("ADD", 0), ("DEL", 1), ("SET", 2), ("GET", 3)):
        if name in s:
            return val
    m = re.search(r"\b([0-3])\b", s)
    return int(m.group(1)) if m else None


def main():
    raw = json.loads  # noqa
    rows = [json.loads(l) for l in RAW.read_text().splitlines() if l.strip()]
    agg = defaultdict(lambda: {"fields": set(), "sources": set(), "values": {}})
    for r in rows:
        name = re.sub(r"\s*\(.*\)$", "", (r.get("name") or "").strip()).lstrip("~")
        op = opnum(r.get("op"))
        if not name or op is None:
            continue
        key = (name, op)
        agg[key]["sources"].add(r["file"].split("/")[-1] + ":" + str(r["line"]))
        for path, val in (r.get("fields") or {}).items():
            agg[key]["fields"].add(path)
            agg[key]["values"].setdefault(path, set()).add(val)
    out = ROOT / "notes/vendor-web/jcs-web-fields.tsv"
    with open(out, "w") as f:
        f.write("name\top\tfields\tsources\n")
        for (name, op) in sorted(agg):
            a = agg[(name, op)]
            f.write(f"{name}\t{op}\t{','.join(sorted(a['fields']))}\t{';'.join(sorted(a['sources']))}\n")
    print("wrote", out, len(agg), "pairs")


if __name__ == "__main__":
    main()
