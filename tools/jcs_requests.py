#!/usr/bin/env python3
"""Build field-complete JCS requests from jcs-schema.tsv.

Values are deliberately conservative: IDs point at non-existent entries,
enable/switch fields are off, and actions use no-op strings so that the
probe exercises parsing without rebooting APs or deleting real objects.
"""
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SCHEMA = ROOT / "notes/vendor-web/jcs-schema.tsv"


def value_for(key):
    k = key.split(".")[-1]
    if k in ("start", "offset", "index", "ser_index", "insert_index"):
        return 0
    if k in ("size", "limit", "count", "num"):
        return 10
    if k in ("enable", "switch", "relay", "auto_bind", "ssidbrd", "isolate",
             "brd_probe", "wmm", "short_gi", "airtime") or k.endswith("_enable") or k.endswith("_switch"):
        return 0
    if k == "operation":
        return 0
    if k == "evt":
        return "noop"
    if k == "action":
        return "stop"
    if k == "mac" or k.endswith("_mac"):
        return "00:11:22:33:44:55"
    if k == "ssid" or k.endswith("_ssid"):
        return "probe"
    if k in ("name", "entry_name", "group_name", "server_name", "rule_name") or k.endswith("_name"):
        return "probe"
    if "passwd" in k or "password" in k or k in ("key", "share_key", "radius_pwd"):
        return "12345678"
    if "ip" in k and "mask" not in k:
        return "192.168.1.1"
    if "url" in k:
        return "http://192.168.1.1/"
    if "port" in k:
        return 80
    if "vlan" in k:
        return 1
    if "time" in k or "date" in k:
        return "2026-01-01 00:00:00"
    if "id" in k or k in ("type", "mode", "auth", "cipher", "encryption", "protocol",
                          "result", "status", "level", "threshold", "interval", "rate"):
        return 0
    return "probe"


ARRAY_EMPTY = {
    "requests", "params", "join_test_sensor", "multi_id_list", "phy_wire_vlan_list",
    "lag_phy_list", "ap_ids", "group_ids", "ids", "serv_ids", "arp_ids",
    "whitelist_ids", "extend_dev_ids", "topic_comment", "topic_data_type",
    "broadcast_channel_set", "broadcast_filter_data_type",
    "broadcast_filter_enable", "broadcast_filter_match_data", "mac_array",
    "service", "test_case_id", "ssid_list", "white_list",
}
OBJECT_EMPTY = {
    "mac_id_map", "serv_id_map", "old_serv_id_map", "request_info", "requestData",
    "sso_config", "time_obj", "dev_info", "search_arg", "filter",
}
TYPE_OVERRIDES = {
    ("bluetooth_network_rule_list", 1, "id"): [999],
    ("ftp_server_list", 1, "rule_id"): [999],
    ("iot_server_list", 1, "id"): [999],
    ("ftp_status_list", 3, "rule_id"): [999],
    ("ac_forward", 3, "request_id"): [999],
    ("apmngr_apdb_info", 3, "firmware_id"): [999],
    ("apmngr_apdb_info", 3, "model_id"): [999],
}


def is_array(path):
    k = path.split(".")[-1]
    return k.endswith("[]") or k in ARRAY_EMPTY


def set_path(obj, path, val):
    parts = path.split(".")
    cur = obj
    for p in parts[:-1]:
        if p not in cur or not isinstance(cur[p], dict):
            cur[p] = {}
        cur = cur[p]
    cur[parts[-1]] = val


def build(inputs, name=None, op=None):
    data = {}
    for path in inputs:
        if not path:
            continue
        v = value_for(path)
        k = path.split(".")[-1]
        if (name, op, k) in TYPE_OVERRIDES:
            v = list(TYPE_OVERRIDES[(name, op, k)])
        if k in ARRAY_EMPTY or k.endswith("[]"):
            v = []
        elif k in OBJECT_EMPTY:
            v = {}
        set_path(data, path, v)
    return data


LUA_RESERVED = {"and","break","do","else","elseif","end","false","for","function","goto","if","in","local","nil","not","or","repeat","return","then","true","until","while"}


def lua(v, indent=0):
    sp = "  " * indent
    if isinstance(v, dict):
        if not v:
            return "{}"
        items = []
        for k, val in v.items():
            key = k if re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", k) and k not in LUA_RESERVED else "[" + json.dumps(k) + "]"
            items.append(sp + "  " + key + " = " + lua(val, indent + 1))
        return "{\n" + ",\n".join(items) + "\n" + sp + "}"
    if isinstance(v, list):
        if not v:
            return "{}"
        return "{" + ", ".join(lua(x, indent + 1) for x in v) + "}"
    if isinstance(v, bool):
        return "true" if v else "false"
    if isinstance(v, (int, float)):
        return str(v)
    return json.dumps(v, ensure_ascii=False)


SKIP = {("wips_event_detail", 3)}
ROAM_VALUES = {
    "id": 0, "name": "probe", "ap_ids": [], "group_ids": [],
    "switch_11k": 0, "switch_11v": 0, "switch_11r": 0,
    "roaming_threshold_type_2g": 0, "rssi_trigger_threshold_2g": 0,
    "rssi_trigger_threshold_high_performance": 0, "low_rssi_kick_2g": 0,
    "low_rssi_threshold_2g": 0, "rate_trigger_threshold_2g": 0,
    "low_rate_kick_2g": 0, "low_rate_threshold_2g": 0,
    "roaming_threshold_type_5g": 0, "rssi_trigger_threshold_5g": 0,
    "low_rssi_kick_5g": 0, "low_rssi_threshold_5g": 0,
    "rate_trigger_threshold_5g": 0, "low_rate_kick_5g": 0,
    "low_rate_threshold_5g": 0, "threshold_check_interval": 0,
    "roaming_dif": 0, "blacklist_restrict_time": 0,
    "stats_switch": 0, "stats_interval": 0,
}
SPECIAL = {
    ("apmngr_apdb_info", 3): [{"firmware_id": 999, "model_id": 999}],
    ("apmngr_firm", 2): [0],
    ("ac_roam_list", 0): [dict(ROAM_VALUES)],
    ("ac_roam_list", 2): dict(ROAM_VALUES),
    ("sensor_test_case_list", 0): {
        "test_case_name": "cap_probe", "change_id": 0, "sch_period": 0,
        "sch_time": 0, "sch_type": 0, "rssi_threshold": -95,
        "group_id": {}, "join_test_sensor": {}, "ssid_info": {},
        "service": [{"ser_name": "dns", "params": [{"ser_index": 0}]}],
    },
    ("sensor_test_case_list", 2): {
        "test_case_id": 0, "test_case_name": "cap_probe", "change_id": 0,
        "sch_period": 0, "sch_time": 0, "sch_type": 0, "rssi_threshold": -95,
        "group_id": {}, "join_test_sensor": {}, "ssid_info": {},
        "service": [{"ser_name": "dns", "params": [{"ser_index": 0}]}],
    },
}


def main():
    rows = [l.split("\t") for l in SCHEMA.read_text().splitlines()[1:]]
    cases = []
    for r in rows:
        name, op = r[0], int(r[1])
        if (name, op) in SKIP:
            continue
        inputs = [x for x in r[4].split(",") if x]
        data = SPECIAL.get((name, op)) or build(inputs, name, op)
        cases.append((name, op, data))
    out = ROOT / "notes/vendor-web/captures/field-cases.lua"
    with open(out, "w") as f:
        f.write("return {\n")
        for name, op, data in cases:
            f.write("  {name=%s, op=%d, data=%s},\n" % (json.dumps(name), op, lua(data, 1)))
        f.write("}\n")
    with open(ROOT / "notes/vendor-web/captures/field-cases.json", "w") as f:
        json.dump([{"name": n, "op": o, "data": d} for n, o, d in cases], f, ensure_ascii=False, indent=1)
    with open(ROOT / "notes/vendor-web/captures/field-requests.tsv", "w") as f:
        for name, op, data in cases:
            f.write(f"{name}\t{op}\t{json.dumps(data, ensure_ascii=False, separators=(',', ':'))}\n")
    print("cases", len(cases), "bytes", out.stat().st_size)


if __name__ == "__main__":
    main()
