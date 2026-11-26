#!/usr/bin/env python3
"""Merge uac handler keys, Web/LuCI-built fields, and captured response keys."""
import json
import re
from collections import defaultdict
from pathlib import Path

from ac100_env import ROOT
REG = ROOT / "notes/vendor-web/jcs-registry.tsv"
WEB = ROOT / "notes/vendor-web/jcs-web-fields.tsv"
SAMPLES = ROOT / "notes/vendor-web/captures/jcs-samples.jsonl"
OUT = ROOT / "notes/vendor-web/jcs-schema.tsv"

IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*(\.[A-Za-z_][A-Za-z0-9_]*)*$")


def clean_key(k):
    k = k.strip()
    if k.endswith("[]"):
        k = k[:-2]
    if k.endswith("."):
        k = k[:-1]
    if not IDENT.match(k):
        return None
    return k


def resp_paths(obj, prefix="", out=None):
    if out is None:
        out = set()
    if isinstance(obj, dict):
        for k, v in obj.items():
            p = f"{prefix}.{k}" if prefix else k
            out.add(p)
            resp_paths(v, p, out)
    elif isinstance(obj, list):
        for v in obj:
            resp_paths(v, prefix + "[]" if prefix else "[]", out)
    return out


ROAM_FIELDS = {
    "id", "name", "ap_ids", "group_ids", "switch_11k", "switch_11v", "switch_11r",
    "roaming_threshold_type_2g", "rssi_trigger_threshold_2g",
    "rssi_trigger_threshold_high_performance", "low_rssi_kick_2g",
    "low_rssi_threshold_2g", "rate_trigger_threshold_2g", "low_rate_kick_2g",
    "low_rate_threshold_2g", "roaming_threshold_type_5g",
    "rssi_trigger_threshold_5g", "low_rssi_kick_5g", "low_rssi_threshold_5g",
    "rate_trigger_threshold_5g", "low_rate_kick_5g", "low_rate_threshold_5g",
    "threshold_check_interval", "roaming_dif", "blacklist_restrict_time",
    "stats_switch", "stats_interval",
}

EXTRA_INPUTS = {
    ("sensor_test_case_list", 0): {
        "test_case_name", "change_id", "sch_period", "sch_time", "sch_type",
        "rssi_threshold", "group_id", "join_test_sensor", "ssid_info", "service",
    },
    ("apmngr_apdb_info", 3): {"[].firmware_id", "[].model_id"},
    ("apmngr_firm", 2): {"[]"},
    ("ac_roam_list", 0): {"[]." + x for x in ROAM_FIELDS},
    ("ac_roam_list", 2): set(ROAM_FIELDS),
    ("sensor_test_case_list", 2): {
        "test_case_name", "change_id", "sch_period", "sch_time", "sch_type",
        "rssi_threshold", "group_id", "join_test_sensor", "ssid_info", "service",
        "test_case_id",
    },
}


def load_helper_inputs():
    path = ROOT / "notes/vendor-web/jcs-helper-fields.tsv"
    out = {}
    if not path.exists():
        return out
    for line in path.read_text().splitlines()[1:]:
        p = line.split("\t")
        keys = {x for x in p[3].split(",") if x}
        name, op = p[0], int(p[1])
        if name == "wportal":
            continue
        if name == "ac_roam_list" and op == 0:
            keys = {"[]." + x for x in keys}
        elif name == "apmngr_apdb_info" and op == 3:
            keys = {"[]." + x for x in keys}
        elif name == "sensor_test_case_list":
            fixed = set()
            for k in keys:
                if k == "params":
                    continue
                if k == "ser_name":
                    fixed.add("service[].ser_name")
                else:
                    fixed.add("service[].params[]." + k)
            keys = fixed
        out[(name, op)] = keys
    return out


HELPER_INPUTS = load_helper_inputs()


def main():
    reg = {}
    for line in REG.read_text().splitlines()[1:]:
        p = line.split("\t")
        reg[(p[0], int(p[1]))] = p
    web = defaultdict(set)
    for line in WEB.read_text().splitlines()[1:]:
        p = line.split("\t")
        for k in p[2].split(","):
            ck = clean_key(k)
            if ck:
                web[(p[0], int(p[1]))].add(ck)
    samples = {}
    for line in SAMPLES.read_text().splitlines():
        r = json.loads(line)
        samples[(r["name"], r["op"])] = r
    rows = []
    for key, p in reg.items():
        name, op = key
        uac_in = {x for x in p[4].split(",") if x}
        uac_out = {x for x in p[5].split(",") if x}
        wf = web.get(key, set())
        inputs = uac_in | wf | EXTRA_INPUTS.get((name, op), set()) | HELPER_INPUTS.get((name, op), set())
        s = samples.get(key)
        ro = set()
        if s and isinstance(s.get("response"), (dict, list)):
            ro = resp_paths(s["response"])
        outputs = uac_out | {x for x in ro if "[]" not in x}
        src = "both" if (uac_in and wf) else ("uac" if uac_in else ("web" if wf else ""))
        if HELPER_INPUTS.get((name, op)):
            src = (src + "+helper") if src else "helper"
        rows.append((name, op, p[2], p[3], ",".join(sorted(inputs)), ",".join(sorted(outputs)),
                     src, "yes" if s else "no", ",".join(sorted(wf - uac_in))))
    rows.sort(key=lambda x: (x[0], x[1]))
    with open(OUT, "w") as f:
        f.write("name\top\thandler\thandler_symbol\tinputs\toutputs\tinput_source\tsampled\tweb_only_inputs\n")
        for r in rows:
            f.write("\t".join(str(x) for x in r) + "\n")
    no_input = [r for r in rows if not r[4]]
    print("rows", len(rows), "no_input_fields", len(no_input), "web_only_pairs", sum(1 for r in rows if r[8]))


if __name__ == "__main__":
    main()
