#!/usr/bin/env python3
"""Inventory the supplied AC firmware's AP pages and Lua handlers.

This is source coverage evidence, not a claim that a handler or Go equivalent
works. Functional coverage and real-device results live in feature-parity.md.
"""
import argparse
import hashlib
import json
import pathlib
import re

ROOT = pathlib.Path(__file__).resolve().parents[1]


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--rootfs", type=pathlib.Path, default=ROOT / ".local/ac100/rootfs")
    p.add_argument("--output", type=pathlib.Path, default=ROOT / "docs/original-feature-inventory.json")
    args = p.parse_args()
    controllers = args.rootfs / "usr/lib/lua/luci/controller/admin"
    if not controllers.is_dir():
        raise SystemExit("Extract the supplied AC firmware first")
    result = {"firmware": "TL-AC100 V6.0 1.0.3 Build 260817 Rel.68871n", "meaning": "Original source inventory only; not implementation or validation status", "controllers": [], "ap_pages": []}
    for file in sorted(controllers.glob("apmng_*.lua")):
        raw = file.read_bytes()
        source = raw.decode("utf-8", errors="replace")
        result["controllers"].append({"module": file.stem, "source": str(file.relative_to(args.rootfs)), "sha256": hashlib.sha256(raw).hexdigest(), "functions": list(dict.fromkeys(re.findall(r"\bfunction\s+([A-Za-z_]\w*)\s*\(", source))), "literal_keys": sorted(set(re.findall(r'''\[\s*["']([a-z][a-z0-9_]+)["']\s*\]''', source)))})
    for file in sorted((args.rootfs / "www/web-static/js").glob("apManagement-*.js")):
        result["ap_pages"].append({"page": re.sub(r"\.[0-9a-f]+\.js$", "", file.name), "source": str(file.relative_to(args.rootfs)), "sha256": hashlib.sha256(file.read_bytes()).hexdigest()})
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n")
    print(f'Inventoried {len(result["controllers"])} AP controllers, {len(result["ap_pages"])} AP page chunks; no completion status inferred')


if __name__ == "__main__":
    main()
