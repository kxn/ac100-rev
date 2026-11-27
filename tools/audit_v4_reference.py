#!/usr/bin/env python3
"""Pin the authorized V4 fallback reference without executing UAC or APs.

This verifies source identities/addresses, not completion of the Go port.
The V6 candidate-selection/PMK evidence remains a separate manifest.
"""
import argparse
import hashlib
import json
from pathlib import Path
from audit_mobility_firmware import ELF32BE

ROOT = Path(__file__).resolve().parents[1]
SHA = "ddc30fd8aa14e206eaa119e403a4ada64584bef84020c825b8c579bfa4153c68"
LIBC_SHA = "2017c1f29c966c2ccfc3f1b9bba58d447f53d760f8b9d2f36bc23fc73bbd2fe3"
FUNCTIONS = [
    "get_acs_timeout", "rdmngr_db_get_band_by_channel",
    "update_high_per_ap_chn_info", "check_cur_wireless_network_mode",
    "wireless_network_mode_change_handle",
    "wsta_intelligent_roam_manual_change_wireless_network_mode",
    "_wsta_intelligent_roam_ctl_pkt_send_cb",
    "_wsta_intelligent_roam_set_wireless_network_mode_send",
    "_wstat_roam_update_wireless_network_mode_to_ap",
    "_wsta_intelligent_roam_ctl_packet_create",
    "_wsta_intelligent_roam_set_rd_info", "_wsta_intelligent_roam_set_rd_cfg",
    "_wsta_roam_rd_chnl_changed_by_subdev", "_wsta_roam_rd_chnl_modify_by_manual",
    "_wsta_intelligent_roam_callback_wtp_leave",
    "_wsta_intelligent_roam_do_acs", "_wstat_roam_check_support_acs",
    "_wstat_roam_start_acs_to_ap", "_wsta_intelligent_roam_start_acs_send",
    "_wsta_roam_pkt_chnl_scan_report", "wsta_roam_chnl_handle",
    "wsta_roam_chnl_handle_thread", "_wsta_roam_collect_chnl_set_to_ap",
    "_uac_rdmngr_rd_chnl_bw_set", "_wsta_roam_pkt_wtp_event_listener",
    "wsta_roam_pkt_init", "_wsta_roam_read_config",
    "chnl_rrm_start", "rrm_acs_timeout", "rdmngr_callback_proc",
    "_wsta_intelligent_roam_sta_stats", "_wsta_intelligent_roam_sta_change_ap_info",
    "_wsta_intelligent_roam_set_rd_info_by_sta", "_wsta_intelligent_roam_check_sta_is_active",
    "_multi_link_status_switch", "apmngr_db_active_ap_inc", "wsta_db_sta_assoc",
    "_uac_wstation_do_event", "stats_db_sta_for_each_range_for_specify_ap",
    "stats_db_sta_update_cnt_target", "stats_db_sta_update",
    "stats_db_sta_start_del_timer_by_mac", "_stats_sta_idle_timer_handle",
    "_stats_sta_copy_to_list", "_stats_sta_assoc_cb", "_stats_sta_deassoc_cb",
    "uac_stats_init", "_uac_rdmngr_rd_chnl_set",
    "apmngr_db_active_ap_num_get", "wsta_db_get_total_num", "wsta_db_get_ap_sta_num",
    "get_high_per_ap_cnt", "get_high_per_sta_cnt", "apmngr_db_foreach_proc",
]

# Non-flow function references exported from the three registration roots.
REGISTRATIONS = [
    ('_wsta_intelligent_roam_sta_change_ap_info', 0x484d18, '_wsta_intelligent_roam_set_rd_info_by_sta'),
    ('wsta_roam_pkt_init', 0x489f3c, '_wsta_roam_pkt_wtp_event_listener'),
    ('wsta_roam_pkt_init', 0x489fc0, '_wsta_intelligent_roam_ctl_pkt_send_cb'),
    ('wsta_roam_pkt_init', 0x48a008, '_wsta_intelligent_roam_sta_stats'),
    ('wsta_roam_pkt_init', 0x48a03c, '_wsta_roam_rd_chnl_changed_by_subdev'),
    ('wsta_roam_pkt_init', 0x48a04c, '_wsta_roam_rd_chnl_modify_by_manual'),
    ('wsta_roam_pkt_init', 0x48a080, '_wsta_intelligent_roam_callback_wtp_leave'),
    ('uac_stats_init', 0x67329c, '_stats_sta_deassoc_cb'),
    ('uac_stats_init', 0x673304, '_stats_sta_assoc_cb'),
    ('uac_stats_init', 0x67337c, '_stats_ap_join_cb'),
    ('uac_stats_init', 0x673388, '_stats_ap_disconnect_cb'),
    ('uac_stats_init', 0x673398, '_stats_ap_del_cb'),
    ('uac_stats_init', 0x6733c8, '_stats_ap_online_cb'),
    ('uac_stats_init', 0x6733f4, '_stats_rd_enable_cb'),
    ('uac_stats_init', 0x673400, '_stats_rd_disable_cb'),
    ('uac_stats_init', 0x673454, '_stats_wlan_disable'),
    ('uac_stats_init', 0x673544, '_stats_wlan_enable'),
]


def extract(root):
    elf = ELF32BE(root / "usr/sbin/uac", SHA)
    symbols = {}
    for line in (root / "usr/sbin/uac_symbol_fun").read_text().splitlines():
        address, size, _, name = line.split()
        symbols[name] = (int(address, 16), int(size, 16))
    functions = []
    for name in dict.fromkeys(FUNCTIONS + [row[2] for row in REGISTRATIONS]):
        address, size = symbols[name]
        functions.append(dict(name=name, address=f"0x{address:08x}", size=size,
                              sha256=hashlib.sha256(elf.read(address, size)).hexdigest()))
    # Reverse all symbol-bounded J/JAL branches, including tail calls. The
    # callbacks themselves are registered in wsta_roam_pkt_init; those roots
    # are pinned above and their registration priorities are reviewed in the
    # reference document. This direct census does not claim to resolve every
    # possible computed pointer in the binary.
    targets = {symbols[name][0]: name for name in [
        "check_cur_wireless_network_mode", "wireless_network_mode_change_handle",
        "_wsta_intelligent_roam_sta_change_ap_info",
        "_wsta_intelligent_roam_set_rd_info_by_sta",
        "_wsta_intelligent_roam_ctl_pkt_send_cb", "_wsta_intelligent_roam_sta_stats",
    ]}
    callers = []
    for name, (address, size) in sorted(symbols.items(), key=lambda p: p[1][0]):
        for pc in range(address, address + size, 4):
            word = elf.u32(pc)
            if word >> 26 in (2, 3):
                target = ((pc + 4) & 0xf0000000) | ((word & 0x3ffffff) << 2)
                if target in targets:
                    callers.append(dict(caller=name, target=targets[target], site=f"0x{pc:08x}", instruction=f"0x{word:08x}"))
    registrations = [dict(root=owner, site=f"0x{pc:08x}", target=name, address=f"0x{symbols[name][0]:08x}", instruction=f"0x{elf.u32(pc):08x}")
                     for owner, pc, name in REGISTRATIONS]
    data = []
    for name, address, size in [("compatibility_channel_lookup", 0x697378, 12),
                                ("idle_station_seconds", 0x758ce4, 4)]:
        raw = elf.read(address, size)
        data.append(dict(name=name, address=f"0x{address:08x}", size=size,
                         hex=raw.hex(), sha256=hashlib.sha256(raw).hexdigest()))
    libc = ELF32BE(root / "lib/libuClibc-0.9.33.2.so", LIBC_SHA)
    library_functions = []
    for name, address, size in [("rand", 0x48920, 0x18), ("srand", 0x48940, 0x8c),
                                ("random", 0x48b20, 0x84), ("random_r", 0x48bb0, 0x84),
                                ("srandom_r", 0x48c34, 0x10c)]:
        library_functions.append(dict(name=name, address=f"0x{address:08x}", size=size,
                                      sha256=hashlib.sha256(libc.read(address, size)).hexdigest()))
    random_state = libc.read(0x672e8, 20)
    files = []
    for name in ["etc/apdb.bin", "lib/functions/config.sh",
                 "usr/lib/lua/luci/controller/admin/apmng_roam.lua",
                 "usr/lib/lua/luci/view/userrpm/apmng_roaming_wireless_mode.htm"]:
        files.append(dict(path=name, sha256=hashlib.sha256((root / name).read_bytes()).hexdigest()))
    return dict(reference_release="TL-AC100 V4.0 1.4.3 Build240715 Rel.80898n",
                requested_release="1.4.4 Build240911 Rel.65759n (not acquired)",
                source="https://resource.tp-link.com.cn/pc/docCenter/showDoc?id=1730963408141364",
                zip_sha256="f82338235732ec6e77910c663861dc54a0ac77539b69c77ee9754575b8d938aa",
                image_sha256="7a41be6adeb61b5a45815dd8dce6d7552b8c53ad8d46687f9cc7ff0f8db830fa",
                uac_sha256=elf.sha256, functions=functions, files=files, data=data,
                reverse_direct_targets=list(targets.values()), direct_callers=callers,
                registrations=registrations,
                libc=dict(path="lib/libuClibc-0.9.33.2.so", binary_sha256=LIBC_SHA,
                          functions=library_functions,
                          state=dict(address="0x000672e8", size=20, hex=random_state.hex(),
                                     sha256=hashlib.sha256(random_state).hexdigest(),
                                     type=random_state[12], degree=random_state[13], separation=random_state[14])))


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--rootfs", type=Path, default=ROOT / ".local/ac100/v4-review/rootfs")
    p.add_argument("--write", action="store_true")
    p.add_argument("--references", type=Path, help="ExportEntryReferences.java TSV for the three reviewed roots")
    args = p.parse_args()
    actual = extract(args.rootfs)
    if args.references:
        observed = sorted((line.split("\t")[1], line.split("\t")[2], line.split("\t")[3])
                          for line in args.references.read_text().splitlines())
        expected = sorted((r["site"][2:], r["target"], r["address"][2:]) for r in actual["registrations"])
        assert observed == expected, "Unreviewed or stale V4 registration reference"
    destination = ROOT / "docs/v4-high-performance-evidence.json"
    if args.write:
        destination.write_text(json.dumps(actual, ensure_ascii=False, indent=2) + "\n")
    elif json.loads(destination.read_text()) != actual:
        raise SystemExit("V4 reference differs; do not reuse version-specific addresses")
    print(f"Verified V4 1.4.3 reference: {len(actual['functions'])} UAC functions, {len(actual['libc']['functions'])} libc functions, {len(actual['direct_callers'])} reverse direct branches, {len(actual['files'])} source files; no UAC execution")


if __name__ == "__main__":
    main()
