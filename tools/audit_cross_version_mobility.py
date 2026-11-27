#!/usr/bin/env python3
"""Pin both firmware families, registrations, reverse callers and shared tables.

Read-only ELF/Ghidra evidence, never an original runtime oracle. Semantic
classifications are reviewed in docs/cross-version-mobility-review.md.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re

from audit_mobility_firmware import ELF32BE, UAC_SHA256
from audit_v4_reference import SHA as V4_SHA

ROOT = Path(__file__).resolve().parents[1]
DEST = ROOT / "docs/cross-version-mobility-evidence.json"
ROOTS = ["wsta_roam_init", "wsta_roam_pkt_init", "wsta_roam_db_init", "wsta_roam_sql_init",
         "balance_init", "balance_db_init", "uac_stats_init", "stats_pkt_init", "stats_db_init",
         "band_navigation_init", "band_navigation_db_init"]
POLICY = ["_wsta_roam_pkt_wtp_event_listener", "_wsta_roam_pkt_roaming_trigger_request",
          "_wsta_roam_pkt_roaming_by_rssi_low", "_roaming_nbr_select", "roam_nbr_select",
          "_roaming_nbr_packet_create", "_nbr_filter", "_rssi_sort_fun", "_quick_sort_impl",
          "wss_steer_candidate_rate_estimate", "estimate_rate_from_snr", "estimate_snr_from_rcpi",
          "estimate_snr_from_rssi", "_sta_caps_calculate", "_wlan_caps_calculate",
          "_steer_candidate_caps_calculate", "get_estimate_by_stat", "estimate_airtime",
          "_wsta_roam_pkt_pmk_request", "wsta_roam_db_pmk_add", "wsta_roam_db_pmk_get_by_mac",
          "wsta_roam_db_pmk_start_del_timer", "wsta_roam_db_pmk_expiretime_set",
          "wsta_roam_db_pmk_free", "_wsta_roam_pmk_idle_timer_handle", "_wsta_roam_idle_pmk_delete",
          "wsta_roam_sta_assoc_callback", "wsta_roam_start_delete_timer",
          "uac_wstation_assoc", "uac_wstation_free_sta_by_mac", "wsta_db_free_sta_by_mac_new",
          "_wsta_free_entry_new", "_uac_wsta_del_cb", "uac_wsta_pseudo_associate_check",
          "_uac_wsta_do_check", "_uac_wsta_pkt_associcate", "_uac_wsta_pkt_associcate_new",
          "balance_wsta_callback_balance_sta_check", "balance_db_dis_sta_check",
          "balance_wsta_callback_balance_sta_add", "balance_wsta_callback_balance_sta_del",
          "balance_db_sta_add", "balance_db_sta_delete", "_uac_wstation_do_event", "wsta_db_sta_assoc",
          "balance_roam_strategy_get", "wsta_roam_db_roam_strategy_register",
          "wsta_roam_db_roam_strategy_update", "wsta_roam_db_roam_strategy_get",
          "stats_db_sta_update", "stats_db_sta_get_nbr_set", "_stats_sta_support_cal",
          "cw_priv_sta_pmk_req_parse", "cw_priv_roaming_trigger_parse",
          "cw_priv_roaming_calculate_result_assemble"]
TARGETS = ["_wsta_roam_pkt_pmk_request", "_wsta_roam_pkt_roaming_trigger_request",
           "_wsta_roam_pkt_roaming_by_rssi_low", "_roaming_nbr_select", "roam_nbr_select",
           "_roaming_nbr_packet_create", "wss_steer_candidate_rate_estimate", "estimate_rate_from_snr",
           "uac_wsta_pseudo_associate_check", "get_estimate_by_stat", "estimate_airtime",
           "wsta_roam_db_roam_strategy_update", "FUN_00486664"]
EXTRA = {"v4": {"FUN_00486664": (0x486664, 0x64), "FUN_0040a270": (0x40a270, 0x50)}, "v6": {}}


def symbols(path):
    return {n: (int(a, 16), int(s, 16)) for a, s, _, n in
            (line.split() for line in path.read_text().splitlines())}


def owner(db, pc):
    return next((n for n, (a, s) in db.items() if a <= pc < a+s), "DATA")


def fingerprint(elf, db, name):
    a, s = db[name]
    return dict(name=name, address=f"0x{a:08x}", size=s,
                sha256=hashlib.sha256(elf.read(a, s)).hexdigest())


def direct_calls(elf, db):
    destinations = {db[n][0]: n for n in TARGETS if n in db}
    found = []
    for name, (a, s) in sorted(db.items(), key=lambda p: p[1][0]):
        for pc in range(a, a+s, 4):
            w = elf.u32(pc)
            if w >> 26 in (2, 3):
                target = ((pc+4) & 0xf0000000) | ((w & 0x3ffffff) << 2)
                if target in destinations:
                    found.append(dict(caller=name, target=destinations[target], site=f"0x{pc:08x}", instruction=f"0x{w:08x}"))
    return found


def references(path, elf, db):
    rows = []
    for line in path.read_text().splitlines():
        _, site, target, address = line.split("\t")
        pc = int(site, 16)
        assert db[target][0] == int(address, 16)
        rows.append(dict(root=owner(db, pc), target=target, address="0x"+address,
                         site="0x"+site, instruction=f"0x{elf.u32(pc):08x}"))
    return sorted(rows, key=lambda r: (r["site"], r["target"]))


def reverse_references(path, elf, db):
    rows, targets = [], []
    target = None
    for line in path.read_text().splitlines():
        match = re.search(r"FindCallers.java> TARGET (\S+) ([0-9a-f]+)", line)
        if match:
            a = int(match[2], 16)
            target = next(n for n, (pc, _) in db.items() if pc == a)
            targets.append(target)
        match = re.search(r"FindCallers.java> CALLER ([0-9a-f]+) ", line)
        if match:
            pc = int(match[1], 16)
            rows.append(dict(target=target, caller=owner(db, pc), site=f"0x{pc:08x}", instruction=f"0x{elf.u32(pc):08x}"))
    unique = {json.dumps(row, sort_keys=True): row for row in rows}
    return sorted(set(targets)), sorted(unique.values(), key=lambda r: (r["site"], r["target"]))


def extract(reference_dir):
    prior = json.loads((ROOT / "docs/roaming-entry-audit.json").read_text())
    classifications = {r["source"]["name"]: (r["classification"], r["contracts"], r["note"]) for r in prior["entries"]}
    classifications["balance_roam_strategy_get"] = ("configuration", ["cross-version-station-policy"], "V4新增策略消费者：balance开关改变private57的strategy；V6无此注册。")
    result = dict(meaning="Static branch/registration evidence, not exhaustive equivalence or a hardware oracle.", versions={},
                  v4_pmk_null_output_defect=[
                      dict(version="v4", address="0x004871ac", instruction="0x0c18c9c1", role="call uac_wstation_assoc"),
                      dict(version="v4", address="0x004871b0", instruction="0xafa00020", role="delay slot: ninth argument NULL"),
                      dict(version="v4", address="0x00632740", instruction="0x8fb500e8", role="load ninth argument: frame200+32"),
                      dict(version="v4", address="0x00632754", instruction="0x12a00018", role="NULL argument rejects association"),
                      dict(version="v6", address="0x004e4a14", instruction="0x27b80588", role="prepare valid local output address"),
                      dict(version="v6", address="0x004e4a24", instruction="0xafb80020", role="store valid ninth argument"),
                      dict(version="v6", address="0x004e4a30", instruction="0x0c1d99ad", role="call association with output pointer"),
                  ])
    for version, directory, digest, table, multipliers, timer, interval in [
        ("v4", "firmware", V4_SHA, 0x731550, 0x731500, 0x758cc0, 0x758cd4),
        ("v6", ".local/ac100/rootfs", UAC_SHA256, 0x8cc3e0, 0x8cc390, 0x8f5620, 0x8f5640),
    ]:
        root = ROOT / directory
        elf = ELF32BE(root / "usr/sbin/uac", digest)
        sym = root / "usr/sbin/uac_symbol_fun"
        db = symbols(sym) | EXTRA[version]
        refs = references(reference_dir / f"{version}-entries.tsv", elf, db)
        searched, reverse = reverse_references(reference_dir / f"{version}-reverse.log", elf, db)
        callbacks = []
        for name in sorted({r["target"] for r in refs}):
            kind, contracts, note = classifications[name]
            if version == "v4" and kind == "legacy-mode":
                kind, contracts, note = ("configuration", ["v4-fixed-high-performance-coordinator", "v4-automatic-mode-entries-and-redistribution"],
                                          "V4模式入口已实现；不能套用V6 Web禁用模式0/1的分类。")
            callbacks.append(dict(source=fingerprint(elf, db, name), classification=kind, contracts=contracts, note=note))
        timers = []
        for i in range(4):
            pc = elf.u32(timer+i*4)
            name = next(n for n, (a, _) in db.items() if pc == a)
            timers.append(dict(pointer=f"0x{timer+i*4:08x}", interval_address=f"0x{interval+i*4:08x}",
                               seconds=elf.u32(interval+i*4), source=fingerprint(elf, db, name),
                               classification="diagnostic"))
        calls = direct_calls(elf, db)
        wanted = set(POLICY+ROOTS) | set(EXTRA[version]) | {r["caller"] for r in calls}
        data = [dict(name=n, address=f"0x{a:08x}", size=s, sha256=hashlib.sha256(elf.read(a,s)).hexdigest())
                for n, a, s in [("snr_tables", table, 560), ("bandwidth_multipliers", multipliers, 80)]]
        result["versions"][version] = dict(binary_sha256=digest, symbol_file_sha256=hashlib.sha256(sym.read_bytes()).hexdigest(),
            roots=[n for n in ROOTS if n in db], absent_roots=[n for n in ROOTS if n not in db],
            functions=[fingerprint(elf, db, n) for n in sorted(wanted & db.keys())],
            absent_policy_symbols=[n for n in POLICY if n not in db], registrations=refs, callbacks=callbacks,
            statistics_timer_table=timers, direct_callers=calls, reverse_targets=searched, reverse_references=reverse, data=data)
    assert result["versions"]["v4"]["data"][0]["sha256"] == result["versions"]["v6"]["data"][0]["sha256"]
    assert result["versions"]["v4"]["data"][1]["sha256"] == result["versions"]["v6"]["data"][1]["sha256"]
    # Independent per-rule RRM selection does not change station policy.
    # Its V4 DCA/TPC branch is audited separately from V6's librrm SCA/TPC.
    v4 = ELF32BE(ROOT / "firmware/usr/sbin/uac", V4_SHA)
    db = symbols(ROOT / "firmware/usr/sbin/uac_symbol_fun")
    result["independent_rrm_boundary"] = dict(
        go_source="Per-rule strategy_version: V4 DCA/TPC or V6 SCA/TPC; independent of roaming mode_source; V4 common-channel ACS is a separate mode phase",
        v4_reference=[fingerprint(v4, db, n) for n in ["_rrm_task", "run_DCA", "dfs", "run_TPC", "run_smooth_TPC"]],
        v6_library_path="usr/lib/librrm_business.so",
        v6_library_sha256="62a9c14282900ac5bec5d09a69b97ed98b259243c883c4b41b845d63e24ab62e")
    return result


def verify(snapshot):
    report = {}
    boundary = snapshot["independent_rrm_boundary"]
    v4 = ELF32BE(ROOT / "firmware/usr/sbin/uac", V4_SHA)
    db = symbols(ROOT / "firmware/usr/sbin/uac_symbol_fun")
    for f in boundary["v4_reference"]:
        assert fingerprint(v4, db, f["name"]) == f
    assert hashlib.sha256((ROOT / ".local/ac100/rootfs" / boundary["v6_library_path"]).read_bytes()).hexdigest() == boundary["v6_library_sha256"]
    for version, directory in [("v4", "firmware"), ("v6", ".local/ac100/rootfs")]:
        row = snapshot["versions"][version]
        root = ROOT / directory
        elf = ELF32BE(root / "usr/sbin/uac", row["binary_sha256"])
        for anchor in snapshot["v4_pmk_null_output_defect"]:
            if anchor["version"] == version:
                assert elf.u32(int(anchor["address"],16)) == int(anchor["instruction"],16), anchor
        sym = root / "usr/sbin/uac_symbol_fun"
        assert hashlib.sha256(sym.read_bytes()).hexdigest() == row["symbol_file_sha256"]
        db = symbols(sym) | EXTRA[version]
        for f in row["functions"] + [c["source"] for c in row["callbacks"]] + [t["source"] for t in row["statistics_timer_table"]]:
            assert fingerprint(elf, db, f["name"]) == f, f
        assert direct_calls(elf, db) == row["direct_callers"], "Unreviewed direct entry"
        assert sorted(n for n in ROOTS if n in db) == sorted(row["roots"])
        for r in row["registrations"] + row["reverse_references"]:
            pc = int(r["site"], 16)
            assert elf.u32(pc) == int(r["instruction"],16), r
            assert owner(db, pc) == r.get("root", r.get("caller")), r
        for r in row["registrations"]:
            assert r["root"] in row["roots"] and db[r["target"]][0] == int(r["address"],16)
        for t in row["statistics_timer_table"]:
            assert elf.u32(int(t["pointer"],16)) == int(t["source"]["address"],16)
            assert elf.u32(int(t["interval_address"],16)) == t["seconds"]
        for d in row["data"]:
            assert hashlib.sha256(elf.read(int(d["address"],16),d["size"])).hexdigest() == d["sha256"]
        report[version] = dict(roots=len(row["roots"]), callbacks=len(row["callbacks"]),
            registrations=len(row["registrations"]), direct_branches=len(row["direct_callers"]),
            reverse_references=len(row["reverse_references"]), timer_slots=4)
    return report


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--write", action="store_true")
    p.add_argument("--reference-directory", type=Path, help="fresh Ghidra registration TSVs and reverse logs")
    args = p.parse_args()
    if args.write:
        if not args.reference_directory:
            p.error("--write needs fresh Ghidra evidence")
        DEST.write_text(json.dumps(extract(args.reference_directory), ensure_ascii=False, indent=2)+"\n")
    snapshot = json.loads(DEST.read_text())
    if args.reference_directory:
        assert extract(args.reference_directory) == snapshot, "Unclassified or stale Ghidra references"
    print(json.dumps(verify(snapshot), ensure_ascii=False))


if __name__ == "__main__":
    main()
