#!/usr/bin/env python3
"""Verify captured request fields against the merged JCS schema."""
import json
from collections import Counter
from pathlib import Path

from ac100_env import ROOT
SCHEMA = ROOT / "notes/vendor-web/jcs-schema.tsv"
SAMPLES = ROOT / "notes/vendor-web/captures/jcs-samples.jsonl"


def main():
    schema = {}
    outputs = {}
    for line in SCHEMA.read_text().splitlines()[1:]:
        p = line.split("\t")
        schema[(p[0], int(p[1]))] = {x for x in p[4].split(",") if x}
        outputs[(p[0], int(p[1]))] = {x for x in p[5].split(",") if x}
    recs = [json.loads(l) for l in SAMPLES.read_text().splitlines() if l.strip()]
    errors = []
    nonempty = 0
    unknown = Counter()
    for r in recs:
        key = (r["name"], r["op"])
        try:
            req = json.loads(r["request"])
        except Exception as e:
            errors.append(f"{key}: bad request json {e}")
            continue
        data = req.get("data")
        if data not in ({}, [], None):
            nonempty += 1
        if isinstance(data, dict):
            allowed = schema.get(key, set())
            for k in data:
                if k not in allowed:
                    unknown[(key, k)] += 1
        if key not in schema:
            errors.append(f"{key}: not in schema")
    empty_with_inputs = 0
    for r in recs:
        key = (r["name"], r["op"])
        try:
            data = json.loads(r["request"]).get("data")
        except Exception:
            continue
        if schema.get(key) and data == {}:
            empty_with_inputs += 1
            errors.append(f"{key}: empty data but schema has inputs")
    unknown_out = Counter()
    for r in recs:
        key = (r["name"], r["op"])
        resp = r.get("response")
        if isinstance(resp, dict):
            for k in resp:
                if k not in outputs.get(key, set()):
                    unknown_out[(key, k)] += 1
    print(f"samples={len(recs)} nonempty={nonempty} unknown_fields={len(unknown)} "
          f"unknown_outputs={len(unknown_out)} empty_with_inputs={empty_with_inputs} errors={len(errors)}")
    for (key, k), n in sorted(unknown.items()):
        print("UNKNOWN", key[0], key[1], k, n)
    for e in errors:
        print("ERROR", e)
    return 1 if errors or unknown else 0


if __name__ == "__main__":
    raise SystemExit(main())
