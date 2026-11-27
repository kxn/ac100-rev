#!/usr/bin/env python3
"""Exercise capability-dependent admin forms using real and synthetic AP data.
Uses mocked HTTP writes so no lab AP configuration changes during UI checks.
Requires the optional local Playwright environment, not a runtime dependency.
Uses Playwright's Chromium, or AC100_CHROMIUM_PATH for an existing browser.
"""

import copy
import http.server
import json
import os
import pathlib
import threading
import urllib.request
from playwright.sync_api import sync_playwright

ROOT = pathlib.Path(__file__).resolve().parents[1]
OUT = ROOT / ".local/ac100/ui-check"
OUT.mkdir(parents=True, exist_ok=True)


fixture_path = os.environ.get("AC100_UI_FIXTURE")
fixture = json.loads(pathlib.Path(fixture_path).read_text()) if fixture_path else {}
api_reads = {}


def live(p):
    if fixture_path:
        value = fixture[p]
    else:
        url = os.environ.get("AC100_UI_API", "http://127.0.0.1:8090/api/")
        value = json.load(urllib.request.urlopen(url + p, timeout=3))
    api_reads[p] = copy.deepcopy(value)
    return value


aps = live("aps")
cfg = live("config")
defaults = live("radios/defaults?ap_id=" + aps[0]["id"] + "&radio_id=1")
clients = [
    {
        "mac": "02:03:04:05:06:07",
        "ap_id": aps[0]["id"],
        "radio_id": 2,
        "wlan_id": 1,
        "ssid": "GoAC-Lab",
        "state": "connected",
        "rssi_dbm": -52,
        "ip": "192.0.2.20",
        "connected_at": "2026-11-27T11:00:00Z",
        "last_seen": "2026-11-27T17:10:00Z",
        "statistics": {
            "negotiated_mbps": 1201,
            "upstream_kbps": 128,
            "downstream_kbps": 4096,
        },
    }
]
rates = live("rates")
mobility = live("mobility")
mobility["network_mode"] = 2
rrm = live("rrm")
upgrades = {
    "images": [
        {
            "id": "synthetic-image",
            "format": "tp-container",
            "model": aps[0]["model"],
            "version": "1.2.3 Build 20250317 Rel.43192",
            "size": 4096,
            "hardware_ids": [aps[0].get("hardware_id", "fixture-hardware")],
            "firmware_id": "test-firmware",
        }
    ],
    "jobs": {},
}
storm = {
    "defaults": {
        "enabled": False,
        "rate": 64,
        "custom": False,
        "arp_proxy": {"enabled": False, "scope": 3, "to_unicast": False},
        "nd_proxy": {"enabled": False, "scope": 3, "to_unicast": False},
        "mdns_proxy": {"enabled": False, "scope": 3, "to_unicast": False},
        "protocols": [{"enabled": False, "scope": 3, "rate": 64} for _ in range(8)],
    },
    "protocols": [
        "ARP",
        "ICMPv6 NS",
        "ICMPv6 RS",
        "DHCP",
        "DHCPv6",
        "IGMP",
        "其他广播",
        "其他组播",
    ],
}
edca_queues = [
    {"aifs": a, "cw_min": lo, "cw_max": hi, "txop": tx}
    for a, lo, hi, tx in [
        (1, 2, 3, 47),
        (1, 3, 4, 94),
        (2, 4, 6, 0),
        (3, 4, 10, 0),
        (2, 2, 3, 47),
        (2, 3, 4, 94),
        (2, 4, 10, 0),
        (3, 4, 10, 0),
    ]
]
edca = {
    "rules": [],
    "defaults": {
        "frequency_mask": 0,
        "wmm": True,
        "custom": True,
        "scene": 1,
        "configuration": {"enabled": True, "mode": 0, "queues": edca_queues},
    },
}
resources = live("controller/resources")
resource_values = resources["defaults"]
resources = {
    "settings": dict(resource_values),
    "defaults": dict(resource_values),
    "fields": resources["fields"],
}


# Read-only API snapshots can be replayed with no running controller.
(OUT / "api-fixture.json").write_text(json.dumps(api_reads, ensure_ascii=False))


class Handler(http.server.SimpleHTTPRequestHandler):
    def __init__(self, *a, **k):
        super().__init__(*a, directory=str(ROOT / "uacgo/admin/assets"), **k)

    def end_headers(self):
        self.send_header(
            "Content-Security-Policy",
            "default-src 'self'; img-src 'self' data:; style-src 'self'; script-src 'self'; frame-ancestors 'none'; base-uri 'none'",
        )
        super().end_headers()

    def log_message(self, *a):
        pass


server = http.server.ThreadingHTTPServer(("127.0.0.1", 0), Handler)
threading.Thread(target=server.serve_forever, daemon=True).start()

with sync_playwright() as p:
    browser = p.chromium.launch(
        headless=True, executable_path=os.environ.get("AC100_CHROMIUM_PATH")
    )
    errors = []
    console_errors = []
    writes = []
    signal_queries = []

    for full in (False, True):
        profile = copy.deepcopy(aps)
        conf = copy.deepcopy(cfg)
        rf_defaults = copy.deepcopy(defaults)
        conf["config"]["protection"] = {
            "servers": [{"id": "srv", "name": "Router", "address": "192.0.2.1"}],
            "bindings": [
                {
                    "id": "bind",
                    "name": "Client",
                    "ip": "192.0.2.2",
                    "mac": "02:03:04:05:06:07",
                    "description": "",
                }
            ],
            "rules": [],
        }
        conf["config"]["ap_defaults"]["radios"] = [
            {"radio_id": 8, "channel": 11, "advanced": {"rts": 2000}}
        ]
        conf["config"]["groups"] = [
            {"id": "floor", "name": "Floor", "options": {"echo_seconds": 30}}
        ]
        conf["config"]["templates"] = [
            {
                "id": "template",
                "name": "Model",
                "model": profile[0]["model"],
                "hardware_version": profile[0]["hardware_version"],
                "options": {},
            }
        ]
        conf["config"]["ap_profiles"] = [
            {
                "ap_id": profile[0]["id"],
                "group_id": "floor",
                "template_id": "template",
                "name": "",
                "location": "",
                "options": {},
            }
        ]
        if full:
            a = profile[0]
            a["general_capabilities"] = [4294967295] * 4
            a["features"] = {
                **a.get("features", {}),
                **{
                    k: True
                    for k in [
                        "rssi_control",
                        "channel_optimization",
                        "fragmentation",
                        "ssid_rate_limit",
                        "frame_rate_control",
                        "edca",
                        "edca_mode",
                        "wifi6_features",
                        "mlo",
                        "multicast",
                        "multicast_per_ssid",
                        "multicast_to_unicast",
                        "vlan_pool",
                        "band_steering",
                        "band_navigation",
                    ]
                },
            }
            conf["config"]["mesh"] = {
                "enabled": True,
                "auto_add": False,
                "ssid": "ExistingBackhaul",
                "members": [
                    {
                        "parent_ap_id": a["id"],
                        "mac": "02:00:00:00:00:09",
                        "allowed": False,
                        "at": "2026-11-26T12:00:00Z",
                    }
                ],
                "has_key": True,
                "has_token": True,
                "has_web_password": True,
                "backhaul_mode": 1,
            }
            a["features"]["mesh"] = True
            a["ports"] = [
                {"id": 12, "uplink": True},
                {"id": 103, "uplink": False, "lag": True},
                {"id": 104, "uplink": False, "lag": True},
            ]
            a["downlink_port_count"] = 2
            conf["config"]["ap_profiles"][0]["options"]["lag"] = {
                "enabled": True,
                "mode": 0,
                "ports": [103, 104],
            }
            a["radio_linkage"] = {
                "table_id": 1,
                "rows": [
                    {
                        "table_mask": 2,
                        "feature_mask": 1,
                        "regions": [0],
                        "radios": [
                            {
                                "radio_id": 1,
                                "channels": [0, 1, 6],
                                "bandwidths": [0, 2],
                                "status_mask": 3,
                            }
                        ],
                    }
                ],
            }
            a["radio_modes"] = [
                {"id": 7, "name": "Dual", "rf_mode": 16387, "radios": [1, 2]}
            ]
            a["radio_mode"] = {"enabled": False, "id": 7}
            rf_defaults["edca"] = {
                "enabled": False,
                "mode": 0,
                "queues": edca_queues,
            }
            for row in conf["config"]["radios"]:
                if row.get("advanced") is not None:
                    row["advanced"]["edca"] = copy.deepcopy(rf_defaults["edca"])
            a["edca_presets"] = {
                "version": 1,
                "scenes": [
                    {
                        "id": 2,
                        "name": "Office",
                        "description": "Other AP model",
                        "bands": [
                            {
                                "band_id": 1,
                                "queues": [
                                    {
                                        "aifs": 2,
                                        "cw_min": 3,
                                        "cw_max": 4,
                                        "txop": 47,
                                    }
                                ]
                                * 8,
                            }
                        ],
                    }
                ],
            }
            conf["config"]["vlan_pools"] = [
                {"id": 1, "name": "Guests", "vlans": "100-110"}
            ]

        group_service = copy.deepcopy(conf["config"]["services"][0])
        group_service.update(
            id="fixture-group-service",
            ssid="Group-only service",
            aps=[],
            groups=["floor"],
            bindings=[],
        )
        conf["config"]["services"].append(group_service)

        spare = copy.deepcopy(profile[0])
        spare.update(
            id="02:00:00:00:00:aa",
            mac="02:00:00:00:00:aa",
            name="Fixture spare",
            online=True,
            state="RUN",
        )
        offline = copy.deepcopy(spare)
        offline.update(
            id="02:00:00:00:00:ab",
            mac="02:00:00:00:00:ab",
            name="Fixture offline",
            online=False,
            state="OFFLINE",
        )
        profile.extend([spare, offline])

        reads = []
        page = browser.new_page(viewport={"width": 1440, "height": 960})
        page.on("pageerror", lambda e: errors.append(str(e)))
        page.on(
            "console",
            lambda m: console_errors.append(m.text) if m.type == "error" else None,
        )
        page.on("dialog", lambda d: d.accept())

        def route(r):
            path = r.request.url.split("/api/")[1]
            if r.request.method != "GET":
                writes.append({"path": path, "body": r.request.post_data_json})
                r.fulfill(
                    json={"updated": 1, "skipped": 0, "errors": []}
                    if path == "aps/names/import"
                    else {"status": "saved"}
                )
                return
            reads.append(path)
            if path.startswith("clients/") and "/history?" in path:
                signal_queries.append(path)
                r.fulfill(
                    json={
                        "samples": [
                            {
                                "at": "2026-11-26T12:00:00Z",
                                "ap_id": profile[0]["id"],
                                "radio_id": 1,
                                "wlan_id": 1,
                                "ssid": "GoAC-Lab",
                                "rssi_dbm": -60,
                            },
                            {
                                "at": "2026-11-26T12:00:30Z",
                                "ap_id": profile[0]["id"],
                                "radio_id": 1,
                                "wlan_id": 1,
                                "ssid": "GoAC-Lab",
                                "rssi_dbm": -48,
                            },
                        ]
                    }
                )
                return
            history_fixture = {
                "ap_counts": [
                    {
                        "at": "2026-11-26T12:00:00Z",
                        "online": 1,
                        "offline": 2,
                        "total": 3,
                    },
                    {
                        "at": "2026-11-26T12:01:00Z",
                        "online": 2,
                        "offline": 1,
                        "total": 3,
                    },
                ],
                "radios": [
                    {
                        "at": "2026-11-26T12:00:00Z",
                        "ap_id": profile[0]["id"],
                        "radio_id": 1,
                        "clients": 1,
                        "channel": 6,
                        "power_dbm": 15,
                        "metrics": {"channelUsage": 20},
                    },
                    {
                        "at": "2026-11-26T12:01:00Z",
                        "ap_id": profile[0]["id"],
                        "radio_id": 1,
                        "clients": 2,
                        "channel": 6,
                        "power_dbm": 15,
                        "metrics": {"channelUsage": 30},
                    },
                ],
                "events": [
                    {
                        "at": "2026-11-26T12:00:10Z",
                        "client_mac": "02:03:04:05:06:07",
                        "kind": "connected",
                        "ssid": "GoAC-Lab",
                        "ap_id": profile[0]["id"],
                        "radio_id": 2,
                        "source": "wireless_snapshot",
                    }
                ],
            }
            value = (
                resources
                if path == "controller/resources"
                else profile
                if path == "aps"
                else conf
                if path == "config"
                else clients
                if path == "clients"
                else [
                    row
                    for row in conf["config"]["radios"]
                    if row["ap_id"] == profile[0]["id"]
                ]
                if path.endswith("/effective-radios")
                else rf_defaults
                if path.startswith("radios/defaults")
                else rates
                if path == "rates"
                else mobility
                if path == "mobility"
                else edca
                if path == "edca"
                else rrm
                if path == "rrm"
                else upgrades
                if path == "upgrades"
                else {"config": conf["config"].get("mesh"), "jobs": {}}
                if path == "mesh"
                else {
                    "configured_mode": 2,
                    "actual_mode": 2,
                    "mode_writable": False,
                    "unsupported_aps": [],
                }
                if path == "mobility/status"
                else storm
                if path == "storm/defaults"
                else history_fixture
                if path.startswith("history?")
                else []
            )
            r.fulfill(json=value)

        page.route("**/api/**", route)
        page.goto("http://127.0.0.1:" + str(server.server_port))
        page.wait_for_function(
            '() => document.querySelector("#connection").textContent === "控制器已连接"'
        )

        def visit(view):
            page.evaluate("v => showTab(v)", view)
            page.wait_for_url("**/#" + view)
            page.wait_for_timeout(80)

        def expand(form):
            page.locator(form).wait_for(state="visible")
            # Open native disclosure controls so all editable fields can be exercised.
            for detail in page.locator(form + " details").all():
                if not detail.evaluate("e=>e.open"):
                    detail.locator("summary").first.click()

        def submit(form):
            before = len(writes)
            page.locator(form + ' [type="submit"]:not([value="run"])').click()
            page.wait_for_timeout(100)
            assert len(writes) > before, (
                form,
                page.locator(form).inner_text()
                if page.locator(form).count()
                else "form closed",
                errors,
            )
            return writes[-1]

        # Sidebar organization is the approved V4 hierarchy, including the
        # unusual original placement of roaming under AP management.
        assert page.url.endswith("#aps")
        assert page.locator("#navigation .nav-heading").all_text_contents() == [
            "运行状态⌄",
            "AP管理›",
            "射频管理›",
            "无线管理›",
            "易展设备管理›",
            "安全管理›",
        ]
        page.locator('[data-nav-group="ap"]').click()
        ap_links = page.locator(
            '[data-nav-group="ap"] + div button'
        ).all_text_contents()
        assert ap_links == [
            "AP设置",
            "AP升级",
            "负载均衡",
            "智能漫游",
            "无线网络模式",
            "组播管理",
        ]
        page.locator('#navigation [data-view="apsettings"]').click()
        assert page.url.endswith("#apsettings")
        for title in ["全局设置", "AP 分组", "AP列表"]:
            assert title in page.locator("#content").inner_text()
        assert not any(
            x in page.locator("#navigation").inner_text()
            for x in ["RADIUS", "Portal", "认证管理", "云管理", "网络运维", "蓝牙"]
        )

        views = [
            "aps",
            "clients",
            "apsettings",
            "templates",
            "apdefaults",
            "upgrades",
            "balance",
            "mobility",
            "networkmode",
            "multicast",
            "multicast-query",
            "multicast-list",
            "radios",
            "rrm",
            "edca",
            "rates",
            "band",
            "services",
            "pools",
            "mesh-topology",
            "mesh",
            "mesh-upgrades",
            "mesh-clients",
            "mesh-settings",
            "storm",
            "protection",
            "dhcp-servers",
            "arp",
            "arp-bindings",
            "history",
            "interfaces",
            "resources",
            "backup",
        ]
        for view in views:
            visit(view)
            assert page.locator("#content").inner_text().strip(), view
        assert not errors, errors

        # AP details expose backend facts and raw capability data, not invented
        # acknowledgements. Polling preserves the selected diagnostic tab.
        visit("aps")
        page.locator('[data-ap-diagnostic="' + profile[0]["id"] + '"]').first.click()
        assert (
            page.locator('#drawer-body [data-editor-tab="ap-cap"]').get_attribute(
                "class"
            )
            == "active"
        )
        assert "通用能力位" in page.locator("#drawer-body").inner_text()
        page.locator('#drawer-body [data-editor-tab="ap-raw"]').click()
        raw = json.loads(page.locator("#drawer-body pre.raw").inner_text())
        assert raw["general_capabilities"] == profile[0]["general_capabilities"]
        assert not any(
            k in raw
            for k in ["account", "key", "passphrase", "pmk", "wireless_telemetry"]
        )
        page.wait_for_timeout(4200)
        assert (
            page.locator('#drawer-body [data-editor-tab="ap-raw"]').get_attribute(
                "class"
            )
            == "active"
        )
        page.locator("#close-drawer").click()

        visit("apsettings")
        page.locator('[data-ap-settings="' + profile[0]["id"] + '"]').first.click()
        assert page.locator(
            '[data-editor-slot="management"] #management-form'
        ).is_visible()
        assert not page.locator("#editor").evaluate("e=>e.open")
        expand("#management-form")
        page.locator('#management-form [name="management_name"]').fill("V4 AP name")
        page.locator('#management-form [name="opt_echo_seconds"]').fill("25")
        page.locator('#management-form [name="opt_client_keep_alive"]').fill("45")
        page.wait_for_timeout(4200)
        assert (
            page.locator('#management-form [name="management_name"]').input_value()
            == "V4 AP name"
        )
        if full:
            assert (
                page.locator('#management-form [name="opt_port_103_vlan"]').count() == 1
            )
            assert page.locator('#management-form [name="opt_rf_mode_id"]').count() == 1
            page.locator('#management-form [name="opt_port_103_vlan"]').fill("120")
        result = submit("#management-form")
        assert result["path"].endswith("/settings")
        assert result["body"]["name"] == "V4 AP name"
        assert result["body"]["options"]["echo_seconds"] == 25
        assert result["body"]["options"]["client_keep_alive"] == 45
        assert not page.locator("#management-form").count()

        # The global schedule editor must not replace unrelated AP defaults.
        before_defaults = copy.deepcopy(conf["config"]["ap_defaults"])
        page.locator('#ap-global-form [name="reboot_state"]').select_option("off")
        result = submit("#ap-global-form")
        assert result["path"] == "ap-defaults"
        assert result["body"]["reboot_schedule"]["enabled"] is False
        for key, value in before_defaults.items():
            if key != "reboot_schedule":
                assert result["body"][key] == value

        # Group and template controls retain complete settings, at their V4 location.
        page.locator('[data-group-new="1"]').first.click()
        page.locator('#management-form [name="management_name"]').fill("UI group")
        page.locator('#management-form [name="group_start_ip"]').fill("192.0.2.10")
        page.locator('#management-form [name="group_end_ip"]').fill("192.0.2.20")
        assert submit("#management-form")["path"] == "groups"
        visit("templates")
        page.locator('[data-template-new="1"]').click()
        page.locator('#management-form [name="management_name"]').fill("UI template")
        assert submit("#management-form")["path"] == "templates"
        visit("apdefaults")
        expand("#management-form")
        assert submit("#management-form")["path"] == "ap-defaults"

        visit("services")
        group_row = page.locator("tr").filter(has_text="Group-only service")
        assert (
            "分组 Floor" in group_row.inner_text()
            and "全部 AP" not in group_row.inner_text()
        )
        page.locator("#new-service").click()
        assert page.locator('[data-editor-slot="service"] #service-form').is_visible()
        page.locator('#service-form [name="ssid"]').fill("UI-Parity")
        page.locator('#service-form [name="passphrase"]').fill("synthetic-ui-key")
        page.locator('#service-form [name="description"]').fill("V4 layout")
        expand("#service-form")
        assert not page.locator('#service-form [name="radius_ip"]').count()
        assert page.locator('#service-form [name="mc_global"]').is_visible() == full
        if full:
            page.locator('#service-form [name="vlan_pool"]').select_option("1")
        page.locator('#service-form [name="band_preset"]').select_option("custom")
        for box in page.locator('#service-form [name="auto_bind_frequencies"]').all():
            box.uncheck()
        page.locator(
            '#service-form [name="auto_bind_frequencies"][value="256"]'
        ).check()
        service_write = submit("#service-form")
        assert service_write["path"] == "services"
        assert service_write["body"]["auto_bind_frequencies"] == 256
        assert service_write["body"]["options"]["description"] == "V4 layout"
        assert service_write["body"]["options"]["encoding"] == "utf-8"
        assert not page.locator("#service-form").count()

        visit("radios")
        page.locator('[data-radio="1"]').first.click()
        expand("#radio-form")
        assert page.locator('[data-editor-slot="radio"] #radio-form').is_visible()
        original_mode = page.locator('#radio-form [name="mode"]').input_value()
        assert page.locator('#radio-form [name="wmm"]').is_disabled()
        page.locator('#radio-form [name="mode"]').select_option("1")
        assert page.locator('#radio-form [name="wmm"]').is_enabled()
        page.locator('#radio-form [name="mode"]').select_option(original_mode)
        assert page.locator('#radio-form [name="wmm"]').is_disabled()
        if full:
            assert page.locator('#radio-form [name="edca_7_txop"]').count() == 1
            page.locator('#radio-form [name="edca_preset"]').select_option("2")
        result = submit("#radio-form")
        assert result["path"] == "radios"
        assert result["body"]["advanced"]["mode"] == int(original_mode)
        assert result["body"]["advanced"]["wmm"] is True
        assert not page.locator("#radio-form").count()

        visit("mobility")
        expand("#roaming-default-form")
        page.locator('#roaming-default-form [name="11k"]').check()
        page.locator('#roaming-default-form [name="2g_rssi_trigger"]').fill("-77")
        page.locator('#roaming-default-form [data-editor-tab="roam-5g"]').click()
        page.locator('#roaming-default-form [name="5g_rssi_trigger"]').fill("-81")
        page.locator('#roaming-default-form [name="mode_source"]').select_option(
            "tl-ac100-v4-1.4.3"
        )
        old_balance = copy.deepcopy(mobility.get("balance", []))
        result = submit("#roaming-default-form")
        assert result["body"]["default_roaming"]["2g"]["rssi_trigger"] == -77
        assert result["body"]["default_roaming"]["5g"]["rssi_trigger"] == -81
        assert result["body"]["mode_source"] == "tl-ac100-v4-1.4.3"
        assert result["body"]["balance"] == old_balance
        assert not page.locator('[name="roam_sensitivity"]').count()

        visit("balance")
        page.locator('#balance-default-form [name="client_threshold"]').fill("27")
        page.locator('#balance-default-form [name="enabled"]').check()
        result = submit("#balance-default-form")
        assert result["path"] == "mobility"
        global_balance = [
            r
            for r in result["body"]["balance"]
            if not r.get("aps") and not r.get("groups")
        ][0]
        assert global_balance["client_threshold"] == 27
        assert result["body"]["default_roaming"] == mobility["default_roaming"]

        visit("networkmode")
        expand("#network-mode-form")
        assert submit("#network-mode-form")["path"] == "mobility"
        visit("band")
        page.locator('#band-navigation-form [name="band_enabled"]').check()
        page.locator('#band-navigation-form [name="band_threshold"]').fill("23")
        result = submit("#band-navigation-form")
        assert (
            result["path"] == "band-navigation" and result["body"]["threshold_5g"] == 23
        )

        visit("rrm")
        expand("#rrm-primary-form")
        page.locator('#rrm-primary-form [name="strategy_version"]').select_option("v4")
        page.locator('#rrm-primary-form [name="rrm_2g_channels"]').fill("1,6,11")
        page.locator('#rrm-primary-form [name="rrm_5g_channels"]').fill("36,44")
        page.locator('#rrm-primary-form [name="rrm_common_max_power_dbm"]').fill("28")
        page.locator('#rrm-primary-form [name="enabled"]').check()
        page.locator('#rrm-primary-form [name="rrmplan_day_0"]').fill("03:00-03:01")
        page.locator('#rrm-primary-form [name="rrmplan_dates"]').fill(
            "2026-12-01 ~ 2026-12-31"
        )
        assert not page.locator('#rrm-primary-form [name="rrmplan_state"]').count()
        result = submit("#rrm-primary-form")
        assert result["path"] == "rrm/rules"
        rule = result["body"][-1]
        assert rule["strategy_version"] == "v4"
        assert rule["enabled"] and rule["schedule"]["enabled"]
        assert rule["schedule"]["dates"] == [
            {"start": "2026-12-01", "end": "2026-12-31"}
        ]
        assert rule["2g"]["max_power_dbm"] == rule["5g"]["max_power_dbm"] == 28
        page.locator('[data-rrm-new="1"]').evaluate(
            "e => e.closest('details').open = true"
        )
        page.locator('[data-rrm-new="1"]').click()
        expand("#rrm-form")
        page.locator('#rrm-form [name="name"]').fill("UI scoped optimization")
        assert submit("#rrm-form")["path"] == "rrm/rules"

        visit("rates")
        assert page.locator("#rates-form [data-editor-tab]").count() == 0
        assert submit("#rates-form")["path"] == "rates"
        for view in ["multicast", "multicast-query"]:
            visit(view)
            if full:
                result = submit("#multicast-settings-form")
                assert result["path"] == "services"
                assert (
                    result["body"]["options"]["multicast"].get("query_interval")
                    is not None
                )
                assert result["body"]["ssid"] == conf["config"]["services"][0]["ssid"]
            else:
                assert not page.locator(
                    '#multicast-settings-form [type="submit"]'
                ).count()
        visit("multicast-list")
        page.locator('[data-multicast-new="1"]').click()
        page.locator('#multicast-item-form [name="ip"]').fill("239.1.2.3")
        assert submit("#multicast-item-form")["path"] == "multicast-groups"

        # DHCP and ARP editors share a backend rule but must preserve the part
        # managed on the other page, including when its selected list is empty.
        conf["config"]["protection"]["rules"] = [
            {
                "id": "shared-rule",
                "name": "Shared",
                "aps": [],
                "groups": [],
                "arp": True,
                "dhcp": True,
                "wired": True,
                "wireless": True,
                "filter": False,
                "servers": ["srv"],
                "bindings": ["bind"],
            }
        ]
        for view, changed, kept in [
            ("protection", "dhcp", "arp"),
            ("arp", "arp", "dhcp"),
        ]:
            visit(view)
            page.locator(
                '[data-defense-kind="rules"][data-defense-id="shared-rule"]'
            ).click()
            page.locator('#defense-form [name="' + changed + '"]').uncheck()
            result = submit("#defense-form")
            rule = result["body"]["rules"][0]
            assert rule[changed] is False and rule[kept] is True
            assert rule["servers"] == ["srv"] and rule["bindings"] == ["bind"]
        visit("storm")
        assert submit("#storm-form")["path"] == "storm"
        visit("mesh-settings")
        page.locator('#mesh-form [name="ssid"]').fill("UI mesh")
        page.locator('#mesh-form [name="key"]').fill("test-mesh-key")
        page.locator('#mesh-form [name="web_password"]').fill("test-admin")
        assert submit("#mesh-form")["path"] == "mesh"
        visit("clients")
        page.locator("[data-client-label]").first.click()
        page.locator('#client-label-form [name="name"]').fill("UI tablet")
        result = submit("#client-label-form")
        assert (
            result["path"].endswith("/label") and result["body"]["name"] == "UI tablet"
        )

        visit("edca")
        page.locator('[data-edca-new="1"]').click()
        page.locator('#edca-form [name="name"]').fill("UI EDCA")
        page.locator('#edca-form [name="frequency_mask"][value="1"]').check()
        assert submit("#edca-form")["path"] == "edca/rules"
        visit("pools")
        page.locator('[data-new-pool="1"]').click()
        page.locator('#pool-form [name="pool_name"]').fill("UI pool")
        page.locator('#pool-form [name="pool_vlans"]').fill("100-110")
        assert submit("#pool-form")["path"] == "vlan-pools"
        visit("resources")
        page.locator('#controller-resources-form [name="max_ap_sessions"]').fill("2048")
        result = submit("#controller-resources-form")
        assert (
            result["path"] == "controller/resources"
            and result["body"]["max_ap_sessions"] == 2048
        )

        visit("upgrades")
        page.locator('[data-upgrade-image="synthetic-image"]').click()
        page.locator('#upgrade-form input[type="checkbox"]').first.check()
        assert submit("#upgrade-form")["path"] == "upgrades"
        if full:
            visit("mesh")
            page.locator('[data-mesh-ap="' + spare["id"] + '"]').click()
            assert submit("#mesh-form")["path"].endswith("/mesh")

        visit("aps")
        page.locator('[data-ap="' + profile[0]["id"] + '"]').first.click()
        page.locator("[data-ap-copy]").click()
        page.locator('#management-copy-form [name="targets"]').first.check()
        assert submit("#management-copy-form")["path"].endswith("/copy")
        page.locator('[data-ap="' + offline["id"] + '"]').first.click()
        page.locator("[data-ap-replace]").click()
        page.locator('#management-replace-form [name="target"]').select_option(
            spare["id"]
        )
        assert submit("#management-replace-form")["path"].endswith("/replace")
        visit("apsettings")
        page.locator('[data-ap-batch-names="1"]').click()
        before = len(writes)
        page.locator("#ap-names-import").set_input_files(
            {
                "name": "names.csv",
                "mimeType": "text/csv",
                "buffer": ("MAC,Name\n" + profile[0]["mac"] + ",UI renamed\n").encode(),
            }
        )
        page.wait_for_timeout(120)
        assert len(writes) > before and writes[-1]["path"] == "aps/names/import"
        visit("backup")
        restore = {"version": 1, "services": [], "radios": [], "interface": ""}
        before = len(writes)
        page.locator("#management-import").set_input_files(
            {
                "name": "backup.json",
                "mimeType": "application/json",
                "buffer": json.dumps(restore).encode(),
            }
        )
        page.wait_for_timeout(120)
        assert len(writes) > before and writes[-1]["path"] == "restore"
        assert writes[-1]["body"] == restore

        # A failed save retains the input and exposes the server's error in the
        # same editor. A retry uses the same complete form.
        visit("services")
        page.locator("#new-service").click()
        page.locator('#service-form [name="ssid"]').fill("Retry service")
        page.locator('#service-form [name="passphrase"]').fill("retry-test-key")

        def fail_save(route):
            if route.request.method == "POST":
                route.fulfill(status=422, json={"error": "fixture save rejected"})
            else:
                route.fallback()

        page.route("**/api/services", fail_save)
        expected_errors = len(console_errors)
        page.locator('#service-form [type="submit"]').click()
        page.locator("#service-form .form-error").filter(
            has_text="fixture save rejected"
        ).wait_for()
        assert (
            page.locator('#service-form [name="ssid"]').input_value() == "Retry service"
        )
        assert page.locator('#service-form [type="submit"]').is_enabled()
        assert all("422" in message for message in console_errors[expected_errors:])
        del console_errors[expected_errors:]
        page.unroute("**/api/services", fail_save)
        assert submit("#service-form")["path"] == "services"

        # Clearing a date range must remove the saved restriction, not merge it
        # back from the old global schedule.
        old_defaults = copy.deepcopy(conf["config"]["ap_defaults"])
        conf["config"]["ap_defaults"]["reboot_schedule"] = {
            "enabled": True,
            "timezone": "UTC",
            "action": "on",
            "windows": [{"days": 127, "start_minute": 180, "end_minute": 181}],
            "dates": [{"start": "2026-12-01", "end": "2026-12-31"}],
        }
        visit("apsettings")
        expand("#ap-global-form")
        page.locator('#ap-global-form [name="reboot_full_dates"]').fill("")
        result = submit("#ap-global-form")
        assert not result["body"]["reboot_schedule"].get("dates")
        windows = result["body"]["reboot_schedule"]["windows"]
        assert sum(w["days"] for w in windows) == 127
        assert all(w["start_minute"] == 180 and w["end_minute"] == 181 for w in windows)
        conf["config"]["ap_defaults"] = old_defaults

        # An optimization request is tied to the button pressed this time.
        # Retrying a plain save after either failure must never start a run.
        visit("rrm")
        expand("#rrm-primary-form")

        def reject_rules(route):
            if route.request.method == "POST":
                route.fulfill(status=422, json={"error": "fixture rules rejected"})
            else:
                route.fallback()

        expected_errors = len(console_errors)
        page.route("**/api/rrm/rules", reject_rules)
        page.locator('#rrm-primary-form [value="run"]').click()
        page.locator("#rrm-primary-form .form-error").filter(
            has_text="fixture rules rejected"
        ).wait_for()
        page.wait_for_timeout(4200)
        assert (
            "fixture rules rejected"
            in page.locator("#rrm-primary-form .form-error").inner_text()
        )
        assert all("422" in message for message in console_errors[expected_errors:])
        del console_errors[expected_errors:]
        page.unroute("**/api/rrm/rules", reject_rules)
        before = len(writes)
        submit("#rrm-primary-form")
        assert [w["path"] for w in writes[before:]] == ["rrm/rules"]

        # Enter in a parameter field performs a plain save, never optimization.
        before = len(writes)
        expand("#rrm-primary-form")
        page.locator('#rrm-primary-form [name="name"]').press("Enter")
        page.wait_for_timeout(120)
        assert [w["path"] for w in writes[before:]] == ["rrm/rules"]

        old_rrm_rules = copy.deepcopy(rrm.get("rules", []))
        old_cfg_rrm = copy.deepcopy(conf["config"].get("rrm", []))

        def save_rules(route):
            if route.request.method == "POST":
                value = route.request.post_data_json
                writes.append({"path": "rrm/rules", "body": value})
                rrm["rules"] = copy.deepcopy(value)
                conf["config"]["rrm"] = copy.deepcopy(value)
                route.fulfill(json={"status": "saved"})
            else:
                route.fallback()

        def reject_run(route):
            route.fulfill(status=422, json={"error": "fixture run rejected"})

        page.route("**/api/rrm/rules", save_rules)
        page.route("**/api/rrm/run", reject_run)
        expected_errors = len(console_errors)
        page.locator('#rrm-primary-form [value="run"]').click()
        page.locator("#rrm-primary-form .form-error").filter(
            has_text="fixture run rejected"
        ).wait_for()
        saved_id = page.locator("#rrm-primary-form").get_attribute("data-rule-id")
        assert saved_id and any(r["id"] == saved_id for r in rrm["rules"])
        assert all("422" in message for message in console_errors[expected_errors:])
        del console_errors[expected_errors:]
        page.unroute("**/api/rrm/run", reject_run)
        before = len(writes)
        rule_count = len(rrm["rules"])
        submit("#rrm-primary-form")
        assert [w["path"] for w in writes[before:]] == ["rrm/rules"]
        assert len(rrm["rules"]) == rule_count and any(
            r["id"] == saved_id for r in rrm["rules"]
        )
        page.unroute("**/api/rrm/rules", save_rules)
        rrm["rules"] = old_rrm_rules
        conf["config"]["rrm"] = old_cfg_rrm

        # A delayed response from an abandoned save must not dismiss a newer
        # editor. Cover both in-page and modal presentations.
        for kind in ["service", "template"]:
            visit("services" if kind == "service" else "templates")
            new_button = (
                "#new-service" if kind == "service" else '[data-template-new="1"]'
            )
            form = "#service-form" if kind == "service" else "#management-form"
            name = "ssid" if kind == "service" else "management_name"
            endpoint = "services" if kind == "service" else "templates"
            page.locator(new_button).click()
            page.locator(f'{form} [name="{name}"]').fill("Old pending save")
            if kind == "service":
                page.locator('#service-form [name="passphrase"]').fill(
                    "pending-save-key"
                )
            pending = []

            def hold_save(route):
                if route.request.method == "POST":
                    pending.append(route)
                else:
                    route.fallback()

            page.route("**/api/" + endpoint, hold_save)
            page.locator(form + ' [type="submit"]').click()
            page.wait_for_timeout(100)
            assert len(pending) == 1
            if kind == "service":
                visit("services")
            else:
                page.locator("#close-dialog").click()
            page.locator(new_button).click()
            page.locator(f'{form} [name="{name}"]').fill("Keep this editor")
            pending.pop().fulfill(json={"status": "saved"})
            page.wait_for_timeout(150)
            assert (
                page.locator(f'{form} [name="{name}"]').input_value()
                == "Keep this editor"
            )
            page.unroute("**/api/" + endpoint, hold_save)
            page.evaluate("closeDialogs()")

        # A radio editor loading in the background must not appear after the
        # user has navigated to a different page and opened a new form.
        visit("radios")
        pending = []

        def hold_radio(route):
            pending.append(route)

        page.route("**/api/aps/*/effective-radios", hold_radio)
        page.locator('[data-radio="1"]').first.click()
        page.wait_for_timeout(100)
        assert len(pending) == 1
        visit("services")
        page.locator("#new-service").click()
        page.locator('#service-form [name="ssid"]').fill("Current service editor")
        pending.pop().fulfill(json=[])
        page.wait_for_timeout(150)
        assert (
            page.locator('#service-form [name="ssid"]').input_value()
            == "Current service editor"
        )
        assert not page.locator("#radio-form").count()
        page.unroute("**/api/aps/*/effective-radios", hold_radio)
        page.evaluate("closeDialogs()")

        # At desktop and mobile widths, long tables scroll within their own
        # container; menus and form controls must not widen the document.
        for width in [1440, 1024, 390]:
            page.set_viewport_size({"width": width, "height": 960})
            visit("services")
            page.locator("#new-service").click()
            page.locator('#service-form [name="ssid"]').fill("Unsaved name")
            page.wait_for_timeout(4200)
            assert (
                page.locator('#service-form [name="ssid"]').input_value()
                == "Unsaved name"
            )
            assert page.evaluate(
                "document.documentElement.scrollWidth <= document.documentElement.clientWidth"
            ), width
            page.screenshot(
                path=str(OUT / f"v4-{'full' if full else 'real'}-{width}.png"),
                full_page=True,
            )
        assert not errors, errors
        assert not console_errors, console_errors
        print(
            json.dumps(
                {
                    "profile": "full" if full else "reported",
                    "pages": len(views),
                    "writes": len(writes),
                    "script_errors": len(errors),
                },
                ensure_ascii=False,
            )
        )
        page.close()
    browser.close()
server.shutdown()
