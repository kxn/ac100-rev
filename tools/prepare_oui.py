#!/usr/bin/env python3
"""Prepare the complete public IEEE MAC-assignment snapshot for offline Go use.

Raw registrant names are authoritative. Optional reviewed brand aliases never
remove an assignment or replace its registrant; no fuzzy ownership inference.
"""
import argparse
import collections
import csv
import datetime
import gzip
import hashlib
import io
import json
import pathlib
import re
import unicodedata
import urllib.request

ROOT = pathlib.Path(__file__).resolve().parents[1]
SOURCES = {
    "oui.csv": ("https://standards-oui.ieee.org/oui/oui.csv", 24),
    "mam.csv": ("https://standards-oui.ieee.org/oui28/mam.csv", 28),
    "oui36.csv": ("https://standards-oui.ieee.org/oui36/oui36.csv", 36),
    "iab.csv": ("https://standards-oui.ieee.org/iab/iab.csv", 36),
}


def normalize(value):
    return re.sub(r"[\W_]+", " ", unicodedata.normalize("NFKC", value).casefold()).strip()


# Reviewed registrant-name families. Word-boundary prefix matching tolerates
# punctuation/legal-name suffixes; it is not arbitrary substring/fuzzy matching.
# In particular VivoTech/Invivo, Shenzhen Honor Electronic, Amazonia and
# Huawei Symantec are not inferred to be the phone/consumer brands.
FAMILIES = {
    "Apple": ["apple"],
    "Samsung": ["samsung electronics", "samsung electro mechanics", "samsung electronic", "samsung sds"],
    "Huawei": ["huawei technologies", "huawei device"],
    "Xiaomi": ["beijing xiaomi", "xiaomi communications", "xiaomi electronics", "xiaomi ev technology"],
    "vivo": ["vivo mobile communication"],
    "OPPO": ["guangdong oppo mobile telecommunications", "oppo digital"],
    "Honor": ["honor device"],
    "OnePlus": ["oneplus electronics", "oneplus tech", "oneplus technology"],
    "realme": ["realme chongqing"],
    "Google": ["google"],
    "Microsoft": ["microsoft"],
    "Amazon": ["amazon technologies", "amazon com", "blink by amazon", "amazon robotics"],
    "Sony": ["sony"],
    "Lenovo": ["lenovo", "beijing lenovo"],
    "Motorola": ["motorola mobility", "motorola mobile devices"],
    "Nokia": ["nokia"],
    "ASUS": ["asustek", "asus computer"],
    "Acer": ["acer"],
    "Dell": ["dell"],
    "HP": ["hp inc", "hewlett packard"],
    "HPE": ["hewlett packard enterprise", "hpe"],
    "TP-Link": ["tp link", "tplink"],
    "NETGEAR": ["netgear"],
    "Ubiquiti": ["ubiquiti"],
    "Cisco": ["cisco", "cisco linksys"],
    "Aruba": ["aruba networks", "aruba a hewlett packard"],
    "Ruijie": ["ruijie", "fujian ruijie"],
    "H3C": ["h3c", "hangzhou h3c", "new h3c"],
    "Hikvision": ["hangzhou hikvision", "hikvision"],
    "Dahua": ["zhejiang dahua", "dahua technology"],
    "Espressif": ["espressif"],
    "Tuya": ["tuya", "hangzhou tuya"],
    "Intel": ["intel"],
    "MediaTek": ["mediatek"],
    "Qualcomm": ["qualcomm"],
    "Broadcom": ["broadcom"],
    "Raspberry Pi": ["raspberry pi"],
    "ZTE": ["zte", "zte corporation", "zte kangxun"],
    "TCL": ["tcl", "tct mobile"],
    "LG": ["lg electronics", "lg innotek"],
    "Panasonic": ["panasonic", "matsushita electric"],
    "Nintendo": ["nintendo"],
    "Sonos": ["sonos"],
    "DJI": ["sz dji", "dji"],
    "Tesla": ["tesla motors", "tesla inc"],
    "Murata": ["murata"],
    "AzureWave": ["azurewave"],
    "Lite-On": ["lite on"],
    "Foxconn": ["hon hai", "foxconn"],
    "Wistron": ["wistron"],
    "Compal": ["compal"],
}


def brand_for(name):
    value = normalize(name)
    candidates = []
    for brand, prefixes in FAMILIES.items():
        for prefix in prefixes:
            if value == prefix or value.startswith(prefix + " "):
                candidates.append((len(prefix), brand))
    if not candidates:
        return ""
    # HPE is more specific than the old Hewlett-Packard family.
    longest = max(length for length, _ in candidates)
    brands = {brand for length, brand in candidates if length == longest}
    if len(brands) != 1:
        raise ValueError(f"ambiguous brand alias: {name}")
    return brands.pop()


def prepare(raw_dir, out_dir, download=False, translations=None):
    raw_dir.mkdir(parents=True, exist_ok=True)
    rows, sources = [], []
    for filename, (url, bits) in SOURCES.items():
        path = raw_dir / filename
        if download:
            request = urllib.request.Request(url + "?download=1", headers={"User-Agent": "GoAC-OUI-Updater/1.0", "Accept": "text/csv"})
            data = urllib.request.urlopen(request, timeout=60).read()
            if not data.startswith(b"Registry,Assignment,Organization Name"):
                raise ValueError(f"unexpected registry response: {url}")
            path.write_bytes(data)
        data = path.read_bytes()
        registry_rows = list(csv.DictReader(io.StringIO(data.decode("utf-8-sig"))))
        for row in registry_rows:
            prefix = row["Assignment"].upper()
            if len(prefix) * 4 != bits or not re.fullmatch("[0-9A-F]+", prefix):
                raise ValueError(f"bad assignment: {prefix}/{bits}")
            rows.append({"prefix": prefix, "bits": bits, "registry": row["Registry"], "name": row["Organization Name"]})
        sources.append({"url": url, "sha256": hashlib.sha256(data).hexdigest(), "rows": len(registry_rows), "bytes": len(data)})
    names = sorted({r["name"] for r in rows})
    indexes = {name: index for index, name in enumerate(names)}
    organizations = [{"name": name, "brand": brand_for(name)} for name in names]
    translation_metadata = None
    if translations and translations.exists():
        from translate_oui import BRANDS_ZH
        translated = json.loads(gzip.decompress(translations.read_bytes()))
        override_path = out_dir / "name-overrides-zh.json"
        if override_path.exists():
            translated["translations"].update(json.loads(override_path.read_text()))
        for org in organizations:
            row = translated["translations"].get(org["name"], {})
            org["name_zh"] = row.get("name_zh", "")
            org["name_zh_source"] = row.get("source", "untranslated")
            org["brand_zh"] = BRANDS_ZH.get(org["brand"], "")
        translation_metadata = {"cache_sha256": hashlib.sha256(translations.read_bytes()).hexdigest(), "overrides_sha256": hashlib.sha256(override_path.read_bytes()).hexdigest() if override_path.exists() else None, "model": translated["model"], "with_chinese_reference": sum(bool(o["name_zh"]) for o in organizations), "source_counts": {source: sum(o["name_zh_source"] == source for o in organizations) for source in sorted({o["name_zh_source"] for o in organizations})}}

    assignments = [{"prefix": r["prefix"], "bits": r["bits"], "registry": r["registry"], "organization": indexes[r["name"]]} for r in sorted(rows, key=lambda r: (-r["bits"], r["prefix"]))]
    payload = {"schema": 1, "sources": sources, "organizations": organizations, "assignments": assignments}
    packed = gzip.compress(json.dumps(payload, ensure_ascii=False, separators=(",", ":")).encode(), mtime=0)
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "registry.json.gz").write_bytes(packed)
    groups = {}
    for org in organizations:
        if org["brand"]:
            groups.setdefault(org["brand"], []).append(org["name"])
    counts = dict(collections.Counter(organizations[indexes[r["name"]]]["brand"] for r in rows if organizations[indexes[r["name"]]]["brand"]))
    manifest = {"schema": 1, "downloaded_on": datetime.datetime.now(datetime.timezone.utc).date().isoformat(), "source": "IEEE Registration Authority public MA-L/MA-M/MA-S/IAB listings", "sources": sources, "assignments": len(rows), "organizations": len(names), "brands": len(groups), "brand_assignment_counts": counts, "artifact_sha256": hashlib.sha256(packed).hexdigest(), "artifact_bytes": len(packed)}
    if translation_metadata:
        manifest["chinese_names"] = translation_metadata
    (out_dir / "manifest.json").write_text(json.dumps(manifest, ensure_ascii=False, indent=2) + "\n")
    (out_dir / "brand-aliases.json").write_text(json.dumps(groups, ensure_ascii=False, indent=2, sort_keys=True) + "\n")
    print(json.dumps({key: manifest[key] for key in ["assignments", "organizations", "brands", "artifact_bytes"]}))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--raw-dir", type=pathlib.Path, default=ROOT / ".local/ac100/oui-registry")
    parser.add_argument("--out-dir", type=pathlib.Path, default=ROOT / "uacgo/data/oui")
    parser.add_argument("--download", action="store_true")
    parser.add_argument("--translations", type=pathlib.Path, default=ROOT / "uacgo/data/oui/names-zh.json.gz")
    args = parser.parse_args()
    prepare(args.raw_dir, args.out_dir, args.download, args.translations)
