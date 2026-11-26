#!/usr/bin/env python3
"""Verify the captured JCS samples against the recovered registry."""
import json
import sys
from pathlib import Path

from ac100_env import ROOT
REG = ROOT / "notes/vendor-web/jcs-registry.tsv"
SAMPLES = ROOT / "notes/vendor-web/captures/jcs-samples.jsonl"


def main():
    rows = [l.split("\t") for l in REG.read_text().splitlines()[1:] if l.strip()]
    registry = {(r[0], int(r[1])): r for r in rows}
    if len(registry) != len(rows):
        print(f"ERROR duplicate (name,op): {len(rows)-len(registry)}")
    recs = [json.loads(l) for l in SAMPLES.read_text().splitlines() if l.strip()]
    seen = set()
    errors = []
    for i, rec in enumerate(recs, 1):
        key = (rec["name"], rec["op"])
        if key not in registry:
            errors.append(f"line {i}: {key} not in registry")
        if key in seen:
            errors.append(f"line {i}: duplicate {key}")
        seen.add(key)
        try:
            req = json.loads(rec["request"])
        except Exception as e:
            errors.append(f"line {i}: bad request JSON: {e}")
            continue
        for field in ("name", "op", "clt_path", "data"):
            if field not in req:
                errors.append(f"line {i}: request missing {field}")
        if req.get("name") != rec["name"] or req.get("op") != rec["op"]:
            errors.append(f"line {i}: request/record mismatch")
    missing = sorted(set(registry) - seen)
    nonempty = 0
    for rec in recs:
        try:
            if json.loads(rec["request"]).get("data") not in ({}, [], None):
                nonempty += 1
        except Exception:
            pass
    print(f"registry={len(registry)} samples={len(seen)} nonempty={nonempty} missing={len(missing)} errors={len(errors)}")
    for k in missing:
        print("MISSING", k[0], k[1])
    for e in errors:
        print("ERROR", e)
    return 1 if errors else 0


if __name__ == "__main__":
    sys.exit(main())
