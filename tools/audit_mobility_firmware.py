#!/usr/bin/env python3
"""Extract version-pinned mobility evidence from the supplied AC firmware.

Read-only binary analysis. Does not run UAC, simulate an AP, send packets,
or infer the vendor algorithm from observations of a running device.
The manifest records binary facts, not implementation-completion claims.
"""
import argparse
import hashlib
import json
import pathlib
import subprocess
import struct

ROOT = pathlib.Path(__file__).resolve().parents[1]
UAC_SHA256 = "b12d1584fcafda2a71aa9038b41b7e1c5b893b350f3e6edf5105e445d024a912"
RRM_SHA256 = "62a9c14282900ac5bec5d09a69b97ed98b259243c883c4b41b845d63e24ab62e"


class ELF32BE:
    def __init__(self, path, expected):
        self.data = path.read_bytes()
        self.sha256 = hashlib.sha256(self.data).hexdigest()
        if self.sha256 != expected:
            raise ValueError(f"{path.name}: firmware hash differs; do not reuse this version's addresses")
        if self.data[:6] != b"\x7fELF\x01\x02":
            raise ValueError("Expected a 32-bit big-endian ELF")
        offset = struct.unpack_from(">I", self.data, 28)[0]
        size, count = struct.unpack_from(">HH", self.data, 42)
        self.segments = [struct.unpack_from(">8I", self.data, offset + i * size) for i in range(count)]

    def read(self, address, count):
        for kind, offset, virtual, _, file_size, memory_size, _, _ in self.segments:
            if kind == 1 and virtual <= address and address + count <= virtual + memory_size:
                start = address - virtual
                n = max(0, min(count, file_size - start))
                return self.data[offset + start:offset + start + n] + bytes(count - n)
        raise ValueError(f"Unmapped ELF address {address:#x}")

    def u32(self, address):
        return struct.unpack(">I", self.read(address, 4))[0]

    def dynamic_functions(self):
        dynamic = {}
        for kind, offset, _, _, size, _, _, _ in self.segments:
            if kind != 2:
                continue
            for i in range(0, size, 8):
                tag, value = struct.unpack_from(">2I", self.data, offset + i)
                if tag == 0:
                    break
                dynamic[tag] = value
        count = dynamic.get(0x70000011)  # DT_MIPS_SYMTABNO; no section headers required.
        if count is None:
            count = self.u32(dynamic[4] + 4)  # DT_HASH nchain.
        strings = self.read(dynamic[5], dynamic[10])
        functions = []
        for i in range(count):
            name, address, size, info, _, section = struct.unpack(
                ">3IBBH", self.read(dynamic[6] + i * 16, 16))
            if info & 15 == 2 and section and address and size:
                end = strings.index(b"\0", name)
                functions.append({"name": strings[name:end].decode(), "address": f"0x{address:08x}", "size": size})
        return sorted(functions, key=lambda f: f["address"])


FUNCTIONS = {
    "balance_wsta_callback_balance_sta_add": 0x4ed3e4,
    "balance_wsta_callback_balance_sta_del": 0x4ed520,
    "_apdb_pkt_manage": 0x70cc34,
    "_apdb_ap_list_parse": 0x6f8780,
    "_apdb_parse_radio": 0x6f239c,
    "_apdb_radio_freq_string_to_enum": 0x6f1b54,
    "_apmngr_pkt_join_req_listen": 0x60b040,
    "_mesh_pkt_join_req_listen": 0x53c1a8,
    "mesh_db_ap_entry_add": 0x53196c,
    "mesh_db_ap_entry_get": 0x531eb8,
    "apmngr_db_role_str": 0x5b490c,
    "uac_wstation_free_sta_by_mac": 0x766fdc,
    "wsta_db_free_sta_by_mac_new": 0x754c74,
    "_wsta_free_entry_new": 0x75492c,
    "_uac_wsta_del_cb": 0x75efec,
    "rdmngr_db_sqlite_cb": 0x727f14,
    "_apmngr_jcs_ap_calibrate_load": 0x5f5ee0,
    "_uac_wserv_jcs_add": 0x6e3970,
    "_uac_wserv_jcs_set": 0x6e2fd4,
    "_uac_wserv_packet_send_callback": 0x6dbd74,
    "apmngr_db_sqlite_group_restore": 0x5b2e70,
    "band_navigation_wtp_packt_send": 0x633a60,
    "band_navigation_db_init": 0x633e60,
    "apmngr_switch_group_handle": 0x5da88c,
    "apmngr_update_group_by_ip_strategy": 0x5da518,
    "apmngr_switch_group_by_ip_strategy": 0x5f70f0,
    "_apmngr_jcs_group_add": 0x5f74bc,
    "_apmngr_jcs_group_set": 0x5f67dc,
    "apmngr_db_foreach_group_proc": 0x5b94d4,
    "apmngr_db_group_add": 0x5b96fc,
    "_uac_wsta_pkt_wtp_event_listener": 0x74a4b0,
    "_uac_wsta_do_check": 0x744b70,
    "_uac_wsta_pkt_associcate": 0x749290,
    "_uac_wsta_pkt_associcate_new": 0x7498c0,
    "wsta_db_sta_assoc": 0x758cf8,
    "_multi_link_status_switch": 0x7a4588,
    "_wsta_roam_read_config": 0x4ddc54,
    "_stats_sta_support_cal": 0x40f314,
    "_stats_pkt_sta_request": 0x7b4a30,
    "_stats_pkt_rssi_request": 0x7b51b4,
    "_stats_pkt_ap_request": 0x7b4ec4,
    "stats_db_sta_update_nbr": 0x7aecb8,
    "stats_db_radio_set_chload_and_nf": 0x7b0c18,
    "rrm_business_static_optimize_original_version_one": 0x527c70,
    "rrm_business_librrm_cfg_init": 0x527038,
    "rrm_business_librrm_rd_info_init": 0x527240,
    "rrm_business_librrm_rd_info_result_apply": 0x527498,
    "wsta_roam_pkt_init": 0x4e9b78,
    "_wsta_roam_pkt_wtp_event_listener": 0x4e89ac,
    "_wsta_roam_pkt_roaming_trigger_request": 0x4e8440,
    "_wsta_roam_pkt_roaming_by_rssi_low": 0x4e6564,
    "roam_nbr_select": 0x4e5638,
    "nbr_cmp": 0x4e0d40,
    "_roaming_nbr_select": 0x4e4b3c,
    "_rssi_sort_fun": 0x4e3c04,
    "_nbr_filter": 0x4e3af8,
    "wss_steer_candidate_rate_estimate": 0x4eb314,
    "estimate_rate_from_snr": 0x4eab48,
    "_sta_caps_calculate": 0x4ea640,
    "_wlan_caps_calculate": 0x4ea84c,
    "_steer_candidate_caps_calculate": 0x4ea4c0,
    "stats_db_sta_get_nbr_set": 0x7aef88,
    "_wsta_roam_pkt_pmk_request": 0x4e46c0,
    "cw_priv_sta_pmk_req_parse": 0x6b14d8,
    "cw_priv_roaming_trigger_dump": 0x6823fc,
    "balance_capwap_callback_wtp_event_request_listen": 0x4f0a04,
    "balance_sta_want_connect_wtp": 0x4f079c,
    "balance_wsta_callback_balance_sta_check": 0x4f0dfc,
    "balance_allow_sta_conect_wtp": 0x4f0adc,
    "balance_db_dis_sta_check": 0x4f6f54,
    "balance_cnt_wtp_entry_update": 0x4f2ed0,
    "balance_cnt_wtp_delete_timer_callback": 0x4f263c,
    "check_cur_wireless_network_mode": 0x4e42f8,
    "wireless_network_mode_change_handle": 0x4e2cd8,
    "_wsta_intelligent_roam_sta_change_ap_info": 0x4e2e78,
    "_wsta_intelligent_roam_set_rd_info_by_sta": 0x4e34ac,
    "_wsta_intelligent_roam_do_acs": 0x4e418c,
    "wsta_roam_chnl_handle": 0x4e43f4,
    "wsta_roam_chnl_handle_thread": 0x4e2668,
    "rrm_business_librrm_exec": 0x52763c,
    "rrm_business_intelligent_optimize": 0x527894,
    'rdmngr_db_rrst_matched_row_find': 0x73a788,
    'rdmngr_db_rrst_matched_row_pre_match': 0x73aa14,
    'rdmngr_db_rrst_matched_row_search_strategy': 0x73abf0,
    'rdmngr_db_get_radio_cfg_linked_strategy': 0x73b61c,
    'rdmngr_db_check_and_do_peer_radio_linked_modify': 0x72750c,
    'apmngr_get_linkage_chnl_bwMode': 0x5dd2d8,
    'rdmngr_db_init_comPara': 0x726b98,
    'apdb_get_default_bw_by_id': 0x701ee0,
    'apdb_get_default_chnl_by_id': 0x701d64,
    'uac_rdmngr_chnl_pwr_modify_by_rdid': 0x720e2c,
    'rdmngr_db_get_real_max_tx_pwr': 0x72de04,
    'rrm_ops_neigh_info_collect': 0x5231e4,
    'rrm_ops_pkt_ndp_recv': 0x51eccc,
    'rrm_ops_apply_all_result': 0x51fbbc,
    'rrm_ops_rd_info_ndp_collect_init': 0x51f4fc,
    'rrm_ops_algo_result_save': 0x51fdbc,
    'rrm_business_neighbor_collect_and_process': 0x5279e0,
    'rrm_ops_get_bw_mode_for_160m_bw_cfg': 0x51bef0,
    'band_navigation_packet_send': 0x633400,
    '_uac_wsta_pkt_sta_extra_info': 0x745f28,
    'cw_priv_sta_extra_info_parse': 0x68ea40,
    'cw_priv_sta_extra_info_dump': 0x68ddac,
    'uac_wstation_mlo_peer_assoc': 0x766458,
    '_uac_wsta_pkt_deassocicate': 0x7459fc,
    'wsta_db_get_rd_sta_num': 0x753844,
    '_uac_wsta_get_entry': 0x7670c8,
    '_stats_pkt_wtp_event_listener': 0x7b5694,

    '_stats_sta_assoc_cb': 0x7b4214,
    '_stats_sta_deassoc_cb': 0x7b42b4,
    '_stats_sta_idle_timer_handle': 0x7a9b48,
    'stats_db_sta_start_del_timer_by_mac': 0x7ae6b8,
    'stats_db_sta_update_cnt_target': 0x7ae310,
    'cw_priv_sta_statistics_dump': 0x6a1da4,
    'uac_wstation_recognition_handle': 0x76a7c8,
    'uac_wsta_recognition_match_handle': 0x76a43c,
    'wsta_db_recog_match_feature_value': 0x751738,
    'wsta_db_recognition_result_get': 0x751d24,
    'wsta_db_match_mac_oui_value': 0x74d704,
    'wsta_db_init_buttom_half': 0x74e474,
    'cw_priv_ac_msg_pull_parse': 0x6a0c24,
    '_stats_pkt_sta_or_bssid_update': 0x7b55ac,
    '_stats_pkt_bssid_update': 0x7b542c,
    'stats_db_bssid_update': 0x7b1190,
    'stats_db_ssid_update': 0x7b1e44,
    'rdmngr_db_init_11ax_feature': 0x7301dc,
    'rdmngr_db_check_11ax_feature': 0x7304f0,
    'rdmngr_capwap_callback_join_req_listen': 0x73d0f0,
    'rdmngr_multilink_callback_rdmngr_add': 0x742e24,
    'rdmngr_wtp_pkt_send': 0x73ea84,
    'edca_rule_to_ap': 0x74108c,
    'edca_rule_jcs_add': 0x711fb0,
    'edca_rule_jcs_set': 0x7129b4,
    'edca_rule_jcs_del': 0x710cc0,
    'check_edca_rule_bind_ap_or_group_conflict': 0x725b88,
    'edca_disable_with_no_rule_to_ap': 0x741dd0,
    'get_edca_default_value': 0x730ec4,
    'rdmngr_db_init_edca': 0x726b10,
    'get_virtual_freq_band_with_type': 0x729de0,
    'apdb_set_freq_band_idx_by_rf_mode': 0x6fa788,
    '_wsta_roam_sql_create_cfg_table': 0x4d8ca8,
    '_wsta_roam_sql_load_db': 0x4da7b4,
    'rrm_business_neighbor_collect': 0x527944,
    'rrm_ops_trigger_rrm_by_rule': 0x525590,
}


def extract(rootfs):
    uac = ELF32BE(rootfs / "usr/sbin/uac", UAC_SHA256)
    rrm = ELF32BE(rootfs / "usr/lib/librrm_business.so", RRM_SHA256)
    symbols = {}
    for line in (rootfs / "usr/sbin/uac_symbol_fun").read_text().splitlines():
        parts = line.split(maxsplit=3)
        if len(parts) == 4:
            symbols[parts[3]] = (int(parts[0], 16), int(parts[1], 16))
    functions = []
    for name, address in FUNCTIONS.items():
        actual, size = symbols[name]
        if actual != address:
            raise ValueError(f"Address-map mismatch for {name}")
        functions.append({"name": name, "address": f"0x{address:08x}", "size": size,
                          "bytes_sha256": hashlib.sha256(uac.read(address, size)).hexdigest()})

    callsite = 0x4e713c
    instruction = uac.u32(callsite)
    target = ((callsite + 4) & 0xf0000000) | ((instruction & 0x3ffffff) << 2)
    if instruction >> 26 != 3 or target != FUNCTIONS["roam_nbr_select"]:
        raise ValueError("Expected active JAL to roam_nbr_select is absent")

    constants = uac.read(0x8cc370, 0x1a)
    tables = {}
    for band, address in (("5g", 0x8cc3e0), ("2g", 0x8cc4f8)):
        tables[band] = [[list(struct.unpack(">BBH", uac.read(address + mode * 56 + i * 4, 4)))
                         for i in range(14)] for mode in range(5)]
    web_path = "usr/lib/lua/luci/controller/admin/apmng_roam.lua"
    migration_path = "etc/cfgsync.d/36_roam_cfg_sync.sh"
    web = (rootfs / web_path).read_text()
    migration = (rootfs / migration_path).read_text()
    if not __import__("re").search(r"function wireless_network_mode_set\([^)]*\)return [a-zA-Z_]+\.EFORBID", web):
        raise ValueError("V6 Web mode-write gate differs")
    for key in ("wireless_network_mode", "cur_wireless_network_mode"):
        if f'uci_r:set("apmng_roam", "wireless_network_mode", "{key}", "2")' not in migration:
            raise ValueError("V6 migration mode boundary differs")
    return {
        "v6_product_mode_boundary": {
            "configured_and_actual_mode_after_migration": 2,
            "web_mode_write": "EFORBID",
            "source_files": [{"path": p, "sha256": hashlib.sha256((rootfs / p).read_bytes()).hexdigest()}
                             for p in (web_path, migration_path)],
            "legacy_automatic_mode_count_order": "4e90e8 callback runs before 7a4588 increments active AP count",
        },
        "firmware": "TL-AC100 V6.0 1.0.3 Build 260817 Rel.68871n",
        "meaning": "Static binary facts. This is not a Go implementation-completion or device-test report.",
        "inputs": {"usr/sbin/uac": uac.sha256, "usr/lib/librrm_business.so": rrm.sha256},
        "uac_functions": functions,
        "active_candidate_call": {"instruction_address": f"0x{callsite:08x}",
                                  "instruction": f"0x{instruction:08x}", "target": f"0x{target:08x}",
                                  "function": "roam_nbr_select"},
        "compiled_defaults": {
            "base_address": "0x008cc370", "bytes": constants.hex(),
            "auto_high_performance_max_clients": uac.u32(0x8cc370),
            "auto_high_performance_max_aps": uac.u32(0x8cc374),
            "roaming_control_strategy": uac.u32(0x8cc378),
            "legacy_rssi_cross_band_adjustment": constants[0x14],
            "max_selected_neighbors": constants[0x15],
            "max_channel_load_5g": constants[0x16],
            "max_channel_load_2g": constants[0x17],
        },
        "station_retention": {"base_seconds_address": "0x008f5630", "base_seconds": uac.u32(0x8f5630), "disconnect_extra_seconds": 5, "sweep_seconds": 60},
        "ap_roles": {"pointer_table": "0x0082cb24", "names": [uac.read(uac.u32(0x82cb24+i*4),32).split(b"\0")[0].decode() for i in range(9)]},
        "edca_defaults": {"address": "0x008ec530", "queue_rows_aifs_cwmin_cwmax_txop": [[*uac.read(0x8ec530+i*6,3),struct.unpack(">H",uac.read(0x8ec530+i*6+4,2))[0]] for i in range(8)]},
        "additional_source_files": [{"path": p, "sha256":hashlib.sha256((rootfs/p).read_bytes()).hexdigest()} for p in (
            "etc/terminal_feature.json", "etc/macFactory.js", "usr/lib/lua/luci/controller/admin/time_mngt.lua", "usr/lib/lua/luci/torchlight/uac/ac_validator.lua", "usr/lib/lua/luci/controller/admin/apmng_rf.lua", "usr/lib/lua/luci/controller/admin/apmng_rrm.lua")],
        "rate_estimation": {
            "table_format": "[SNR threshold byte, padding byte, big-endian uint16 rate]; 5 PHY modes x 14 entries per band",
            "table_addresses": {"5g": "0x008cc3e0", "2g": "0x008cc4f8"},
            "bandwidth_multipliers_address": "0x008cc390",
            "bandwidth_multipliers": [list(struct.unpack(">4I", uac.read(0x8cc390 + i * 16, 16))) for i in range(5)],
            "tables": tables,
        },
        "unlisted_internal_entries": {"apdb_packet_parse_rrst": "0x0070b64c", "get_apdb_bandwidth_flag_bit": "0x006f9b3c", "_uac_rdmngr_linked_modify": "0x00714b9c"},
        "rrst_wire_tables": {
            "bandwidth_string_pointer_table": "0x00886484",
            "bandwidth_tokens_in_enum_order": [uac.read(uac.u32(0x886484+i*4),2).split(b"\0")[0].decode() for i in range(6)],
            "unknown_bandwidth_bit": 6,
            "legal_5g_channels_address": "0x00885110",
            "legal_5g_channels": list(struct.unpack(">25I",uac.read(0x885110,100))),
        },
        "rrm_radio_power_profile": {"address": "0x008edd28", "channel_power_pairs": [list(struct.unpack(">2I",uac.read(0x8edd28+i*8,8))) for i in range(40)]},
        "rrm_library_exports": rrm.dynamic_functions(),
        "rrm_active_got_targets": [
            {"got": f"0x{got:08x}", "target": f"0x{rrm.u32(got):08x}", "role": role}
            for got, role in ((0x25240, "static channel allocation"),
                              (0x25248, "transmit power control version one"))],
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rootfs", type=pathlib.Path, default=ROOT / ".local/ac100/rootfs")
    parser.add_argument("--output", type=pathlib.Path, default=ROOT / "docs/mobility-firmware-evidence.json")
    parser.add_argument("--go-output", type=pathlib.Path, help="Generate the pinned pure-Go policy tables")
    args = parser.parse_args()
    evidence = extract(args.rootfs)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(evidence, ensure_ascii=False, indent=2) + "\n")
    if args.go_output:
        args.go_output.parent.mkdir(parents=True, exist_ok=True)
        defaults = evidence["compiled_defaults"]
        text = '// Code generated by tools/audit_mobility_firmware.py; DO NOT EDIT.\n'
        text += '// Source UAC SHA256: ' + UAC_SHA256 + '\npackage mobility\n\n'
        for name, key in [("FirmwareStrategy", "roaming_control_strategy"), ("MaxCandidates", "max_selected_neighbors"), ("MaxLoad5G", "max_channel_load_5g"), ("MaxLoad2G", "max_channel_load_2g"), ("HighPerformanceAPs", "auto_high_performance_max_aps"), ("HighPerformanceClients", "auto_high_performance_max_clients")]:
            text += f'const {name} = {defaults[key]}\n'
        text += '\ntype snrRate struct { threshold, rate int }\nvar snrRates = [2][5][14]snrRate{\n'
        for band in ("2g", "5g"):
            text += '{\n'
            for mode in evidence["rate_estimation"]["tables"][band]:
                text += '{' + ','.join(f'{{{threshold},{rate}}}' for threshold, _, rate in mode) + '},\n'
            text += '},\n'
        text += '}\nvar bandwidthMultipliers = [5][4]int{\n'
        for row in evidence["rate_estimation"]["bandwidth_multipliers"]:
            text += '{' + ','.join(map(str, row)) + '},\n'
        text += '}\n'
        args.go_output.write_text(subprocess.check_output(["gofmt"], input=text, text=True))
    print(f"Extracted {len(evidence['uac_functions'])} function fingerprints, active JAL, compiled constants and rate tables; no devices exercised")


if __name__ == "__main__":
    main()
